#include "Enlisted.h"
#include "Officer.h"
#include "Vehicle.h"

#include <iostream>

void Enlisted::setCommandingOfficer(Officer* officer)
{
	if (commandingOfficer != nullptr) 
	{
		Officer* officerDup = commandingOfficer;
		commandingOfficer = officer;
		officerDup->removeSubject(this);
	}
	commandingOfficer = officer;
	if(officer!=nullptr)
		officer->addSubject(this);
}

void Enlisted::printSoldier()
{
	std::cout << "\n/////////\n";
	std::cout << "Type: " << "Enlisted\n";
	Soldier::printSoldier();
	std::cout << "Days untill discharge: " << daysUntillDischarge << "\n";

	if (currentVehicle != nullptr)
	{
		std::cout << "\nCurrent Vehicle:";
		currentVehicle->printVehicle();
	}
	else
	{
		std::cout << "No current vehicle\n";
	}

	if (commandingOfficer != nullptr) 
	{
		std::cout << "Commanding officer:" << commandingOfficer->getName() << "\n";
	}
	std::cout << "/////////\n\n";
}

void Enlisted::freeVehicle()
{
	currentVehicle->freeVehicle();
	currentVehicle = nullptr;
}

int Enlisted::getType() const
{
	return 1;
}

void Enlisted::updateRank(int flag) 
{
	if (flag > 0) 
	{
		if (rank < 3) 
		{
			rank = static_cast<ranking>(rank + 1);
			std::cout << "Promotion successfull\n";
		}
		else 
		{
			std::cout << "Soldier already at the highest rank possible for Enlisted soldier\n";
		}
	}
	else 
	{
		if (rank > 0) 
		{
			rank = static_cast<ranking>(rank - 1);
			std::cout << "Demotion successfull\n";
		}
		else 
		{
			std::cout << "Soldier already at the lowest rank possible for Enlisted soldier\n";
		}
	}
}

void Enlisted::emergencyDrill() const
{
	std::cout << "Personal Number: " << personalNumber << " Name: " << name << "\nProtocol: ";
	switch (rank)
	{
		case 0: 
		{
			std::cout << " Guarding civilians\n\n";
			break;
		}
		case 1: 
		{
			std::cout << " Guarding armory\n\n";
			break;
		}
		case 2:
		{
			std::cout << " Guarding inner gates\n\n";
			break;
		}
		case 3:
		{
			std::cout << " Guarding outter gates\n\n";
			break;
		}
		default:
			break;
	}
}
