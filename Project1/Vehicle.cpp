#include <iostream>
#include "Vehicle.h"

void Vehicle::printVehicle() const
{
	std::cout << "\n/////////////////////\n";
	std::cout << "Type: " << type << "\n" << "Color - " << color << "\n" << "Licence plate - " << licencePlateNumber << "\n" << "Mileage - " << mileage << "\n";
	if (currentlyAssignedTo != nullptr) 
	{
		std::cout << "Assigned to - " << currentlyAssignedTo->getName() << " P.N - " << currentlyAssignedTo->getPersonalNumber() << "\n";
	}
	else 
	{
		std::cout << "Not currently assigned\n";
	}
	std::cout << "/////////////////////\n\n";
}