#include "Worker.h"
#include <iostream>

void Worker::printWorker() const
{
	std::cout << "Employing company: " << employingCompany << "\n" << "Monthly salary: " << monthlySalary << "\n" << "Monthly work days: " << monthlyWorkDays << "\n" << "Vacation days: " << vacationDays << "\n";
}