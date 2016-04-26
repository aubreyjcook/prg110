#include <iostream>
#include <iomanip>

float getPatientCharge(int, float, float, float); // days spent in hospital, daily rate, medication charges, service charges
float getPatientCharge(double, double); // service charges, medication charges

int main()
{
    int patientType;

	int daysOfCare; // this variables are used in the case of an inpatient
	float dailyRate;
	float medicationChargesIn;
	float serviceChargesIn;

	double serviceChargesOut; // these variables are used in the case of an outpatient
	double medicationChargesOut;

	std::cout << "Enter the number 1 if the patient is an inpatient, enter 2 for outpatient: \n";
    std::cin >>  patientType;

    while (patientType != 1 && patientType != 2) {
        std::cout << "Enter the number 1 if the patient is an inpatient, enter 2 for outpatient: \n";
        std::cin >>  patientType;
    }

    if (patientType == 1) { // this if statement is for inpatients
        std::cout << "Please enter the following data: \n"
                  << "1. Number of days the patient spent in care.\n";
        std::cin  >> daysOfCare;

        std::cout << "2. The daily rate of charge for care. (in dollars eg. 1.00)\n";
        std::cin  >> dailyRate;

        std::cout << "3. The patient's medication charges. (in dollars eg. 1.00)\n";
        std::cin  >> medicationChargesIn;

        std::cout << "4. The patient's service charges. (in dollars eg. 1.00)\n";
        std::cin  >> serviceChargesIn;

        while (daysOfCare < 1 || dailyRate < 0.00 || medicationChargesIn < 0.00 || serviceChargesIn < 0.00) {
            std:: cout << "It looks like you entered some invalid data, please try again.\n\n"
                      << "Please enter the following data: \n"
                      << "1. Number of days the patient spent in care.\n";
            std::cin  >> daysOfCare;

            std::cout << "2. The daily rate of charge for care. (in dollars eg. 1.00)\n";
            std::cin  >> dailyRate;

            std::cout << "3. The patient's medication charges. (in dollars eg. 1.00)\n";
            std::cin  >> medicationChargesIn;

            std::cout << "4. The patient's service charges. (in dollars eg. 1.00)\n";
            std::cin  >> serviceChargesIn;
        }

        std::cout << "The total charges for the patient are: " << std::endl << std::fixed << std::showpoint << std::setprecision(2) <<
                  getPatientCharge(daysOfCare, dailyRate, medicationChargesIn, serviceChargesIn);
    } else { // this else statement is for outpatients
        std::cout << "Please enter the following data: \n"
                  << "1. The patient's medication charges. (in dollars eg. 1.00)\n";
        std::cin  >> medicationChargesOut;

        std::cout << "2. The patient's service charges. (in dollars eg. 1.00)\n";
        std::cin  >> serviceChargesOut;

        while ( medicationChargesOut < 0.00 || serviceChargesOut < 0.00) {
            std:: cout << "It looks like you entered some invalid data, please try again.\n\n"
                      << "Please enter the following data: \n"
                      << "1. The patient's medication charges. (in dollars eg. 1.00)\n";
            std::cin  >> medicationChargesOut;

            std::cout << "2. The patient's service charges. (in dollars eg. 1.00)\n";
            std::cin  >> serviceChargesOut;
        }

        std::cout << "The total charges for the patient are: " << std::endl << std::fixed << std::showpoint << std::setprecision(2) <<
                  getPatientCharge(serviceChargesOut, medicationChargesOut);
    }

	return 0;
}

float getPatientCharge(int daysOfCare, float dailyRate, float medicationChargesin, float serviceChargesIn) {
    return static_cast<float>(daysOfCare * dailyRate) + (medicationChargesin + serviceChargesIn);
}

float getPatientCharge(double serviceChargesOut, double medicationChargesOut) {
    return (serviceChargesOut + medicationChargesOut);
}
