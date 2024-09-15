#include <iostream>
#include "generalFunctions.h"


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Printing methods

void printMenu()
{
	std::cout << "\n\nPlease choose one of the following:\n1-Print base\n2-Add Soldier to unit\n3-Set new Unit for soldier\n4-Set new Address for soldier\n5-Set new Role for soldier\n6-Update soldier rank\n7-Add Unit\n8-Set soldier duty status\n9-Raise alarm\n10-Assign officer to a soldier\n11-Add Vehicle\n12-Assign Vehicle to Soldier\n13-Add Specialization to NCO\n14-Add Experience to NCO\n15-Reset vacation days\n16-Add hardcoded soldiers\n17-Exit\n";
}

/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Index methods

int getVehicleIndex(const Base* base)
{
	if (base->getNumOfVehicles() < 1) 
	{
		std::cout << "Currently no vehicles are assigned\n";
		return -1;
	}
	bool allowed = false;
	int VehicleIndex;
	while (!allowed)
	{
		base->printAllVehicles();
		std::cout << "Please enter vehicle index:\n";
		std::cin >> VehicleIndex;
		if ((VehicleIndex < 1) || (VehicleIndex > base->getNumOfVehicles()))
		{
			std::cout << "Invalid vehicle index\n";
		}
		else
		{
			allowed = true;
		}
	}
	return (VehicleIndex - 1);
}

int getUnitIndex(const Base* base)
{
	if (base->getNumOfUnits() < 1)
	{
		std::cout << "Currently no units are assigned\n";
		return -1;
	}
	bool allowed = false;
	int unitIndex;
	while (!allowed)
	{
		base->printAllUnits();
		std::cout << "Please enter unit index:\n";
		std::cin >> unitIndex;
		if ((unitIndex < 1) || (unitIndex > base->getNumOfUnits()))
		{
			std::cout << "Invalid unit index\n";
		}
		else
		{
			allowed = true;
		}
	}
	return (unitIndex - 1);
}

int getSoldierIndex(const Base* base, int& unitIndex)
{
	if (base->getUnit(unitIndex)->getNumOfSoldiers() < 1)
	{
		std::cout << "Unit has no soldiers\n";
		return -1;
	}
	base->getUnit(unitIndex)->printUnit();
	bool loop = true;
	int soldierIndex;
	while (loop)
	{
		std::cout << "Please enter Soldier Index:\n";
		std::cin >> soldierIndex;
		if (soldierIndex<1 || soldierIndex > base->getUnit(unitIndex)->getNumOfSoldiers())
		{
			std::cout << "Invalid index\n";
		}
		else
		{
			loop = false;
		}
	}
	return (soldierIndex - 1);
}
/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Building methods

Base* getBaseInfo()
{
	std::cout << "Please enter base Name:\n";
	char name[255];
	std::cin >> name;

	std::cout << "Please enter city name:\n";
	char city[255];
	std::cin >> city;

	std::cout << "Please enter street name:\n";
	char street[255];
	std::cin >> street;

	std::cout << "Please enter home number:\n";
	int homeNumber;
	std::cin >> homeNumber;

	std::cout << "Please enter postal code:\n";
	int postalCode;
	std::cin >> postalCode;

	return new Base(name, city, street, homeNumber, postalCode);
}

Unit* getUnitInfo(const Base* base)
{
	std::cout << "Please enter unit name:\n";
	char name[255];
	std::cin >> name;

	std::cout << "Please enter unit assignment:\n";
	char assignment[255];
	std::cin >> assignment;

	if (base->getNumOfUnits() < 10)
	{
		return new Unit(name, assignment);
	}
	else
	{
		std::cout << "Unable to add more units\n";
		return nullptr;
	}
}

Address* getAddressFromUser()
{
	std::cout << "Please enter city name:\n";
	char city[255];
	std::cin >> city;

	std::cout << "Please enter street name:\n";
	char street[255];
	std::cin >> street;

	std::cout << "Please enter home number:\n";
	int homeNumber;
	std::cin >> homeNumber;

	std::cout << "Please enter postal code:\n";
	int postalCode;
	std::cin >> postalCode;

	return new Address(city, street, homeNumber, postalCode);
}

Soldier* getSoldierFromUser(const Base* base, int* retIndex)
{
	if (base->getNumOfUnits() < 1)
	{
		std::cout << "Currently no units are assigned\n";
		return nullptr;
	}
	int unitIndex = getUnitIndex(base);
	bool loop = true;
	while (loop)
	{
		std::cout << "Please enter Soldier type(1-Enlisted,2-NCO,3-Officer,4-MilitaryCivilian):\n";
		int answer;
		std::cin >> answer;

		switch (answer)
		{
		case 1:
		{
			loop = false;
			*retIndex = unitIndex;
			return getEnlistedInfo(base, unitIndex);
			break;
		}
		case 2:
		{
			loop = false;
			*retIndex = unitIndex;
			return getNCOInfo(base, unitIndex);
			break;
		}
		case 3:
		{
			loop = false;
			*retIndex = unitIndex;
			return getOfficerInfo(base, unitIndex);
			break;
		}
		case 4:
		{
			loop = false;
			*retIndex = unitIndex;
			return getMilitaryCivilianInfo(base, unitIndex);
			break;
		}
		default:
		{
			std::cout << "Please enter valid index\n\n";
		}
		}
	}
	return nullptr;
}

MilitaryCivilian* getMilitaryCivilianInfo(const Base* base, int& unitIndex)
{
	Unit* unit = base->getUnit(unitIndex);
	Address* address = getAddressFromUser();

	std::cout << "Please enter Military civillian name:\n";
	char name[255];
	std::cin >> name;

	std::cout << "Please enter Military civillian Personal number:\n";
	int personalNum;
	std::cin >> personalNum;

	std::cout << "Please enter Military civillian role:\n";
	char role[255];
	std::cin >> role;

	char employingCompany[4] = "IDF";

	return new MilitaryCivilian(name, personalNum, role, unit, address, employingCompany);
}

Enlisted* getEnlistedInfo(const Base* base, int& unitIndex)
{
	Unit* unit = base->getUnit(unitIndex);
	Address* address = getAddressFromUser();

	std::cout << "Please enter Enlisted name:\n";
	char name[255];
	std::cin >> name;

	std::cout << "Please enter Enlisted Personal number:\n";
	int personalNum;
	std::cin >> personalNum;

	std::cout << "Please enter Enlisted role:\n";
	char role[255];
	std::cin >> role;

	return new Enlisted(name, personalNum, role, unit, address);
}

Officer* getOfficerInfo(const Base* base, int& unitIndex)
{
	Unit* unit = base->getUnit(unitIndex);
	Address* address = getAddressFromUser();

	std::cout << "Please enter Officer name:\n";
	char name[255];
	std::cin >> name;

	std::cout << "Please enter Officer Personal number:\n";
	int personalNum;
	std::cin >> personalNum;

	std::cout << "Please enter Officer role:\n";
	char role[255];
	std::cin >> role;

	return new Officer(name, personalNum, role, unit, address);
}

NCO* getNCOInfo(const Base* base, int& unitIndex)
{
	Unit* unit = base->getUnit(unitIndex);
	Address* address = getAddressFromUser();

	std::cout << "Please enter NCO name:\n";
	char name[255];
	std::cin >> name;

	std::cout << "Please enter NCO Personal number:\n";
	int personalNum;
	std::cin >> personalNum;

	std::cout << "Please enter NCO role:\n";
	char role[255];
	std::cin >> role;

	return new NCO(name, personalNum, role, unit, address);
}

Vehicle* getVehicleFromUser()
{
	std::cout << "Please enter vehicle type:\n";
	char name[255];
	std::cin >> name;

	std::cout << "Please enter vehicle licence plate:\n";
	char licencePlate[255];
	std::cin >> licencePlate;

	std::cout << "Please enter vehicle color:\n";
	char color[255];
	std::cin >> color;

	return new Vehicle(name, color, licencePlate);
}

/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////