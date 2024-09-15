#include "Base.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Print methods

void Base::printAllUnits() const
{
	std::cout << "////////////////////\nAll Units:\n";
	for (size_t i = 0; i < numOfUnits; i++)
	{
		std::cout << (i + 1) << "- " << (Base::allUnits[i])->getName() << "\n";
	}
	std::cout << "////////////////////\n";
}

void Base::printAllVehicles() const
{
	for (int i = 0; i < numOfVehicles; i++)
	{
		std::cout << "\n" << i + 1 << "-";
		allVehicles[i]->Vehicle::printVehicle();
	}
}

void Base::printBase() const
{
	std::cout << "///////////////////////////////////////////////////////////////////////////////////////\n//Base info\n";
	std::cout << "Base name:" << baseName << "\n" << "Base Address:\n\n";
	address.printAddress();
	std::cout << "/////////////////////////////////////////////////////////////////\n//Units:\n";
	if (numOfUnits > 0)
	{
		for (size_t i = 0; i < numOfUnits; i++)
		{
			allUnits[i]->Unit::printUnit();
		}
	}
	else
	{
		std::cout << "Currently, no units exist\n";
	}
	std::cout << "/////////////////////////////////////////////////////////////////\n\n\n\n";


	std::cout << "/////////////////////////////////////////////////////////////////\n//Vehicles:\n";
	if (numOfVehicles > 0)
	{
		printAllVehicles();
	}
	else
	{
		std::cout << "Currently, no Vehicles exist\n";
	}
	std::cout << "/////////////////////////////////////////////////////////////////\n\n";


	std::cout << "///////////////////////////////////////////////////////////////////////////////////////\n";
}

void Base::baseRaiseAlarm() const
{
	for (size_t i = 0; i < numOfUnits; i++)
	{
		allUnits[i]->raiseAlarm();
	}
}

/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Add methods

void Base::baseAddSoldierToUnit(Soldier* soldier, int unitIndex)
{
	allUnits[unitIndex]->addSoldierToUnit(soldier);
}

void Base::baseAddUnit(Unit* unit)
{
	if (numOfUnits < 10)
	{
		allUnits[numOfUnits++] = unit;
		std::cout << "Unit added successfully\n";
	}
	else
	{
		std::cout << "Unable to add more Units\n";
	}
}

void Base::baseAddVehicle(Vehicle* vehicle)
{
	if (numOfVehicles < 10) 
	{
		allVehicles[numOfVehicles++] = vehicle;
		std::cout << "Vehicle added successfully\n";
	}
	else 
	{
		std::cout << "Unable to add more Vehicles\n";
	}
}

/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Change methods

void Base::baseSetNewUnitForSoldier(int oldUnitIndex,int newUnitIndex,int soldierIndex)
{
	Soldier* soldier = allUnits[oldUnitIndex]->removeSoldierFromUnit(soldierIndex);
	if (soldier->getType() == 1) 
	{
		((Enlisted*)soldier)->setCommandingOfficer(nullptr);
	}
	allUnits[newUnitIndex]->addSoldierToUnit(soldier);
	std::cout << "Soldier's units changed successfully\n";
}

void Base::baseSetNewAddressForSoldier(Address* address,int unitIndex,int soldierIndex)
{
	allUnits[unitIndex]->setNewAddressForSoldier(address, soldierIndex);
	std::cout << "Address changed successfully\n";
}

void Base::baseSetNewRoleForSoldier(char* role, int unitIndex, int soldierIndex)
{
	allUnits[unitIndex]->setNewRoleForSoldier(role, soldierIndex);
	std::cout << "Role changed successfully\n";
}

void Base::baseUpdateRankForSoldier(int flag,int unitIndex,int soldierIndex)
{
	allUnits[unitIndex]->updateRankForSoldier(flag, soldierIndex);
}

void Base::baseSetSoldierDutyStatus(int status,int unitIndex,int soldierIndex)
{
	allUnits[unitIndex]->unitSetSoldierDutyStatus(status, soldierIndex);
	std::cout << "Soldier duty status changed successfully\n";
}

void Base::baseResetVacationDays()
{
	for (int i = 0; i < numOfUnits; i++)
	{
		allUnits[i]->resetVacationDays();
	}
}

void Base::baseAssignVehicleToSoldier(Enlisted* soldier,int vehicleIndex)
{
	allVehicles[vehicleIndex]->assignVehicleToSoldier(soldier);
	assignedVehicles[vehicleIndex] = allVehicles[vehicleIndex];
	soldier->setCurrentVehicle(allVehicles[vehicleIndex]);
	std::cout << "Vehicle was assigned to Soldier successfully\n";
}

void Base::baseFreeVehicle(int vehicleIndex)
{
	allVehicles[vehicleIndex]->getCurrentlyAssignedSoldier()->setCurrentVehicle(nullptr);
	allVehicles[vehicleIndex]->assignVehicleToSoldier(nullptr);
	assignedVehicles[vehicleIndex] = nullptr;
}

void Base::baseAddSpecializationToNCO(char* specialization,int unitIndex,int soldierIndex)
{
	allUnits[unitIndex]->addSpecializationToNCO(specialization, soldierIndex);
}

void Base::baseAddExperienceToNCOSpecialization(int unitIndex, int soldierIndex)
{
	allUnits[unitIndex]->addExperienceToNCOSpecialization(soldierIndex);
}

void Base::baseAssignSoldierToOfficer(int enlistedIndex, int officerIndex, int unitIndex)
{
	allUnits[unitIndex]->assignEnlistedToOfficer(enlistedIndex, officerIndex);
	std::cout << "Soldier was assigned to Officer successfully\n";
}

/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////