#include <iostream>
#include "generalFunctions.h"

///////////////////////////
void case1(const Base* base)
{
	base->printBase();
}
///////////////////////////


///////////////////////////
void case2(Base* base)
{
	int retIndex;
	Soldier* soldier = getSoldierFromUser(base, &retIndex);
	if (soldier != nullptr)
	{
		base->baseAddSoldierToUnit(soldier, retIndex);
	}
}
///////////////////////////


///////////////////////////
void case3(Base* base)
{
	std::cout << "Please choose from which unit would you like to remove the soldier:\n";
	int oldUnitIndex = getUnitIndex(base);
	if (oldUnitIndex != -1)
	{
		std::cout << "Please choose which soldier would you like to remove:\n";
		int soldierIndex = getSoldierIndex(base, oldUnitIndex);
		if (soldierIndex != -1)
		{
			std::cout << "Please choose new unit for the soldier\n";
			int newUnitIndex = getUnitIndex(base);
			base->baseSetNewUnitForSoldier(oldUnitIndex, newUnitIndex, soldierIndex);
		}
	}
}
///////////////////////////


///////////////////////////
void case4(Base* base)
{
	std::cout << "Please select Soldier unit:\n";
	int unitIndex = getUnitIndex(base);
	if (unitIndex != -1)
	{
		std::cout << "Please select Soldier:\n";
		int soldierIndex = getSoldierIndex(base, unitIndex);
		if (soldierIndex != -1)
		{
			Address* address = getAddressFromUser();
			base->baseSetNewAddressForSoldier(address, unitIndex, soldierIndex);
		}
	}
}
///////////////////////////


///////////////////////////
void case5(Base* base)
{
	std::cout << "Please select Soldier unit:\n";
	int unitIndex = getUnitIndex(base);
	if (unitIndex != -1)
	{
		std::cout << "Please select Soldier:\n";
		int soldierIndex = getSoldierIndex(base, unitIndex);
		if (soldierIndex != -1)
		{
			char role[255];
			std::cout << "Please enter new role:\n";
			std::cin >> role;
			base->baseSetNewRoleForSoldier(role, unitIndex, soldierIndex);
		}
	}
}
///////////////////////////


///////////////////////////
void case6(Base* base)
{
	std::cout << "Please select Soldier unit:\n";
	int unitIndex = getUnitIndex(base);
	if (unitIndex != -1)
	{
		std::cout << "Please select Soldier:\n";
		int soldierIndex = getSoldierIndex(base, unitIndex);
		if (soldierIndex != -1)
		{
			int flag;
			std::cout << "Please enter the type of update(0-Demotion,1-Promotion)\n";
			std::cin >> flag;
			base->baseUpdateRankForSoldier(flag, unitIndex, soldierIndex);
		}
	}
}
///////////////////////////


///////////////////////////
void case7(Base* base)
{
	base->baseAddUnit(getUnitInfo(base));
}
///////////////////////////


///////////////////////////
void case8(Base* base)
{
	std::cout << "Please select Soldier unit:\n";
	int unitIndex = getUnitIndex(base);
	if (unitIndex != -1)
	{
		std::cout << "Please select Soldier:\n";
		int soldierIndex = getSoldierIndex(base, unitIndex);
		if (soldierIndex != -1)
		{
			int flag;
			std::cout << "Please enter the type of update(0-Off duty,1-active)\n";
			std::cin >> flag;
			base->baseSetSoldierDutyStatus(flag, unitIndex, soldierIndex);
		}
	}
}
///////////////////////////


///////////////////////////
void case9(const Base* base)
{
	base->baseRaiseAlarm();
}
///////////////////////////


///////////////////////////
void case10(Base* base)
{
	int unitIndex = getUnitIndex(base);
	if (unitIndex != -1)
	{
		int soldierIndex = base->getUnit(unitIndex)->chooseEnlisted();
		if (soldierIndex != -1)
		{
			std::cout << "Please choose officer\n";
			int officerIndex = base->getUnit(unitIndex)->chooseOfficer();
			if (officerIndex != -1)
				base->baseAssignSoldierToOfficer(soldierIndex, officerIndex, unitIndex);
		}
	}
}
///////////////////////////


///////////////////////////
void case11(Base* base)
{
	base->baseAddVehicle(getVehicleFromUser());
}
///////////////////////////


///////////////////////////
void case12(Base* base)
{
	std::cout << "Please select Soldier unit:\n";
	int unitIndex = getUnitIndex(base);
	if (unitIndex != -1)
	{
		std::cout << "Please select Soldier:\n";
		int soldierIndex = base->getUnit(unitIndex)->chooseEnlisted();
		if (soldierIndex != -1)
		{
			std::cout << "Please select Vehicle\n";
			int vehicleIndex = getVehicleIndex(base);
			if(vehicleIndex!=-1)
				base->baseAssignVehicleToSoldier((Enlisted*)base->getUnit(unitIndex)->getSoldier(soldierIndex), vehicleIndex);
		}
	}
}
///////////////////////////


///////////////////////////
void case13(Base* base)
{
	std::cout << "Please select NCO unit:\n";
	int unitIndex = getUnitIndex(base);
	if (unitIndex != -1)
	{
		std::cout << "Please select NCO:\n";
		int soldierIndex = base->getUnit(unitIndex)->chooseNCO();
		if (soldierIndex != -1)
		{
			std::cout << "Please enter Specialization\n";
			char specialization[255];
			std::cin >> specialization;
			base->baseAddSpecializationToNCO(specialization,unitIndex,soldierIndex);
		}
	}
}
///////////////////////////


///////////////////////////
void case14(Base* base)
{
	std::cout << "Please select NCO unit:\n";
	int unitIndex = getUnitIndex(base);
	if (unitIndex != -1)
	{
		std::cout << "Please select NCO:\n";
		int soldierIndex = base->getUnit(unitIndex)->chooseNCO();
		if (soldierIndex != -1)
		{
			base->baseAddExperienceToNCOSpecialization(unitIndex,soldierIndex);
		}
	}
}
///////////////////////////


///////////////////////////
void case15(Base* base)
{
	base->baseResetVacationDays();
	std::cout << "Vacation days were reset for all Military civilians\n";
}
///////////////////////////



///////////////////////////
void case16(Base* base)
{
	for (int i = 0; i < 2; i++)
	{
		char unitName[6] = { "Unit" };
		unitName[strlen(unitName)] = i+49;
		char assignment[13] = { "Assaignment" };
		assignment[strlen(assignment)] = i+49;
		Unit* unit = new Unit(unitName,assignment);
		base->baseAddUnit(unit);
	}
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				char cityName[10] = { "city" };
				cityName[strlen(cityName)] = i + 49;
				char streetName[10] = { "street" };
				streetName[strlen(streetName)] = i + 49;
				Address* address = new Address(cityName,streetName,i,i);
				char name[10] = { "Enlisted" };
				name[strlen(name)] = i + 49;
				char role[10] = { "Role" };
				role[strlen(role)] = i + 49;
				Enlisted* enlisted = new Enlisted(name,i+j,role,base->getUnit(j),address);
				base->baseAddSoldierToUnit(enlisted,j);
			}
			else if (i == 1)
			{
				char cityName[10] = { "city" };
				cityName[strlen(cityName)] = i + 49;
				char streetName[10] = { "street" };
				streetName[strlen(streetName)] = i + 49;
				Address* address = new Address(cityName, streetName, i, i);
				char name[10] = { "NCO" };
				name[strlen(name)] = i + 49;
				char role[10] = { "Role" };
				role[strlen(role)] = i + 49;
				NCO* nco = new NCO(name, i+j, role, base->getUnit(j), address);
				base->baseAddSoldierToUnit(nco, j);
			}
			else
			{
				char cityName[10] = { "city" };
				cityName[strlen(cityName)] = i + 49;
				char streetName[10] = { "street" };
				streetName[strlen(streetName)] = i + 49;
				Address* address = new Address(cityName, streetName, i, i);
				char name[10] = { "Officer" };
				name[strlen(name)] = i + 49;
				char role[10] = { "Role" };
				role[strlen(role)] = i + 49;
				Officer* officer = new Officer(name, i+j, role, base->getUnit(j), address);
				base->baseAddSoldierToUnit(officer, j);
			}
		}
	}
}
///////////////////////////