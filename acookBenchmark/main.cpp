#include <iostream>
#include <cstdlib>  // random function
#include <ctime>  // get clock ticks & time() for seed
#include <windows.h>  // required for Windows based nanosecond timer

using namespace std;

int linearSearch(const long[], int, long);
int binarySearch(const long[], int, long);
void bubbleSort(long[], int);
void selectionSort(long[], int);
void StartCounter();
double GetCounter();

// required for Windows based nanosecond timer
double PCFreq = 0.0;
__int64 CounterStart = 0;

int main()
{
    const long ARR_SIZE = 90000;
    long arrayA[ARR_SIZE], arrayB[ARR_SIZE];
    long searchValue, temp, random;

    // fill the array with unique values
    for (int i=0; i<ARR_SIZE; i++)
    {
        arrayA[i] = i;
    }
    srand(time(0)); // seed the random generator with time(0)
    // randomly change the order of the values
    for (int i=0; i< ARR_SIZE-1; i++)
    {
        random = rand() % (ARR_SIZE-1); // get a random location
        temp = arrayA[i];
        arrayA[i] = arrayA[random]; // swap current with random
        arrayA[random] = temp;
    }
    // copy array A to array B
    for (int i=0; i<ARR_SIZE; i++)
    {
        arrayB[i] = arrayA[i];  // same number for B
    }

    // arrayA and arrayB now have identical values
    //searchValue = arrayA[rand() % (ARR_SIZE-1)];
    searchValue = arrayA[ARR_SIZE-1];

    cout << "Benchmark for searching and sorting using "
         << ARR_SIZE << " elements." << endl
         << "Desired element is the last element in the array."
         << endl << endl;

    linearSearch(arrayA,ARR_SIZE,searchValue);
    bubbleSort(arrayA,ARR_SIZE);
    selectionSort(arrayB,ARR_SIZE);
    binarySearch(arrayA,ARR_SIZE,searchValue);

    cout << endl << endl;
    return 0;
}

int linearSearch(const long array[], int size, long value)
{
    StartCounter();

    int index = 0;
    int position = -1;
    bool found = false;

    while (index < size && !found){
        if (array[index] == value) {
            found = true;
            position = index;
        }
        index++;
    }

    cout << "Linear Search found the item at " << position <<
         " using " << GetCounter() << " milliseconds." << endl;

    return position;
}

int binarySearch(const long array[], int size, long value)
{
    StartCounter();

    int first = 0,
        last = size - 1,
        middle,
        position = -1;
    bool found = false;

    while(!found && first <= last)
    {
        middle = (first + last) / 2;
        if (array[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }

    cout << "Binary Search found the item at " << position <<
         " using " << GetCounter() << " milliseconds." << endl;

    return position;
}

void bubbleSort(long array[], int size)
{
    unsigned long long nSwaps = 0;
    StartCounter();

    bool swap;
    long temp;

    do {
        swap = false;
        for (int i = 0; i < (size - 1); i++) {
            if (array[i] > array[i + 1]){
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);

    cout << "Bubble sort complete after " << GetCounter() <<
         " milliseconds using " << nSwaps << " swaps." << endl;

}

void selectionSort(long array[], int size)
{
    unsigned long long nSwaps = 0;
    StartCounter();

    int startScan, minIndex, minValue;

    for(startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if(array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }

    cout << "Selection sort complete after " << GetCounter() <<
         " milliseconds using " << nSwaps << " swaps." << endl;
}

// this function taken from example at:
// http://stackoverflow.com/questions/1739259/how-to-use-queryperformancecounter
void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

// this function taken from example at:
// http://stackoverflow.com/questions/1739259/how-to-use-queryperformancecounter
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
