#include <iostream>
#include "Unit.h"
#include "Soldier.h"
#include "Officer.h"
#include "Enlisted.h"
#include "NCO.h"
#include "MilitaryCivilian.h"

void Unit::printUnit() 
{
	std::cout << "\n////////////////////////////////\n";
	std::cout << "Name: " << name << "\n" << "Assignment: " << assignment << "\n";
	if (numOfSoldiers>0)
	{
		std::cout << "\n/////////////////////\n//All Soldiers:\n\n";
		for (size_t i = 0; i<numOfSoldiers; i++)
		{
			std::cout << (i + 1) << ":";
			allSoldiers[i]->printSoldier();
		}
		std::cout << "/////////////////////\n\n";
	}
	std::cout << "////////////////////////////////\n\n";
}

void Unit::addSoldierToUnit(Soldier* soldier)
{
	if (numOfSoldiers < 30) 
	{
		allSoldiers[numOfSoldiers++] = soldier;
		soldier->setNewUnit(this);
		std::cout << "Soldier added Successfully\n";
	}
	else
	{
		std::cout << "Unable to add more Soldiers\n";
	}
}

Soldier* Unit::removeSoldierFromUnit(int soldierIndex)
{
	Soldier* soldier=allSoldiers[soldierIndex];
	if (soldier->getType() == 1)
	{
		((Enlisted*)soldier)->setCommandingOfficer(nullptr);
	}
	else if (soldier->getType() == 3)
	{
		((Officer*)soldier)->removeAllSubjects();
	}
	for (size_t i = soldierIndex; i < 30; i++)
	{
		allSoldiers[i] = allSoldiers[i + 1];
	}
	numOfSoldiers--;
	return soldier;
}

void Unit::setNewAddressForSoldier(Address* address,int soldierIndex)
{
	allSoldiers[soldierIndex]->setNewAddress(address);
}

void Unit::setNewRoleForSoldier(char* role,int soldierIndex)
{
	allSoldiers[soldierIndex]->setNewRole(role);
}

void Unit::updateRankForSoldier(int flag,int soldierIndex)
{
	allSoldiers[soldierIndex]->updateRank(flag);
}

void Unit::raiseAlarm() const
{
	for (int i = 0; i < numOfSoldiers; i++)
	{
		allSoldiers[i]->emergencyDrill();
	}
}

void Unit::unitSetSoldierDutyStatus(int status,int soldierIndex)
{
	allSoldiers[soldierIndex]->setCurrentlyOnDuty(status);
}

void Unit::addSpecializationToNCO(char* specialization,int soldierIndex)
{
	((NCO*)allSoldiers[soldierIndex])->addSpecialization(specialization);
}

void Unit::addExperienceToNCOSpecialization(int soldierIndex)
{
	if (((NCO*)allSoldiers[soldierIndex])->getNumOfSpecializations() < 1) 
	{
		std::cout << "Unable to add add experience,NCO has no specializations\n";
		return;
	}
	((NCO*)allSoldiers[soldierIndex])->printSpecializations();
	bool loop = true;
	int specializationIndex;
	while (loop) 
	{
		std::cout << "Please enter specialization index:\n";
		std::cin >> specializationIndex;
		if (specializationIndex<0 || specializationIndex >((NCO*)allSoldiers[soldierIndex])->getNumOfSpecializations()) 
		{
			std::cout << "invalid index\n";
		}
		else
		{
			loop = false;
		}
	}

	std::cout << "Please enter experience increase\n";
	int increase;
	std::cin >> increase;

	((NCO*)allSoldiers[soldierIndex])->addYearsOfExperience(increase,specializationIndex-1);
}

void Unit::assignEnlistedToOfficer(int enlistedIndex, int officerIndex)
{
	((Enlisted*)allSoldiers[enlistedIndex])->setCommandingOfficer((Officer*)allSoldiers[officerIndex]);
}

void Unit::resetVacationDays()
{
	for (int i = 0; i < numOfSoldiers; i++)
	{
		if (allSoldiers[i]->getType() == 4) 
		{
			((MilitaryCivilian*)allSoldiers[i])->resetVacationDays();
		}
	}
}

Soldier* Unit::getSoldier(int soldierIndex) 
{
	return allSoldiers[soldierIndex];
}

int Unit::chooseEnlisted() 
{
	int allIndexes[30] = { 0 };
	int numOfIndexes = 0;
	std::cout << "\nEnlisted soldiers list:\n";
	for (int i = 0; i < numOfSoldiers; i++)
	{
		if (allSoldiers[i]->getType() == 1)
		{
			std::cout << (i + 1) << "- " << "Name: " << allSoldiers[i]->getName() << "| Personal number: " << allSoldiers[i]->getPersonalNumber() << "\n";
			allIndexes[numOfIndexes++] = i+1;
		}
	}
	if (numOfIndexes < 1) 
	{
		std::cout << "No enlisted soldiers in unit\n";
		return -1;
	}
	bool loop = true;
	int choice;
	while (loop)
	{
		std::cout << "Please enter chosen index:\n";
		std::cin >> choice;
		for (int i = 0; i < 30; i++)
		{
			if (allIndexes[i] == choice)
			{
				loop = false;
				break;
			}
		}
		if (loop) 
		{
			std::cout << "Invalid index\n";
		}
	}
	return (choice-1);
}

int Unit::chooseNCO()
{
	int allIndexes[30] = { 0 };
	int numOfIndexes = 0;
	std::cout << "\nNCO soldiers list:\n";
	for (int i = 0; i < numOfSoldiers; i++)
	{
		if (allSoldiers[i]->getType() == 2)
		{
			std::cout << (i + 1) << "- " << "Name: " << allSoldiers[i]->getName() << "| Personal number: " << allSoldiers[i]->getPersonalNumber() << "\n";
			allIndexes[numOfIndexes++] = i+1;
		}
	}
	if (numOfIndexes < 1)
	{
		std::cout << "No NCO soldiers in unit\n";
		return -1;
	}
	bool loop = true;
	int choice;
	while (loop)
	{
		std::cout << "Please enter chosen index:\n";
		std::cin >> choice;
		for (int i = 0; i < 30; i++)
		{
			if (allIndexes[i] == choice)
			{
				loop = false;
				break;
			}
		}
		if (loop)
		{
			std::cout << "Invalid index\n";
		}
	}
	return (choice-1);
}

int Unit::chooseOfficer()
{
	int allIndexes[30] = { 0 };
	int numOfIndexes = 0;
	std::cout << "\nOfficer soldiers list:\n";
	for (int i = 0; i < numOfSoldiers; i++)
	{
		if (allSoldiers[i]->getType() == 3)
		{
			std::cout << (i + 1) << "- " << "Name: " << allSoldiers[i]->getName() << "| Personal number: " << allSoldiers[i]->getPersonalNumber() << "\n";
			allIndexes[numOfIndexes++] = i+1;
		}
	}
	if (numOfIndexes < 1)
	{
		std::cout << "No Officer soldiers in unit\n";
		return -1;
	}
	bool loop = true;
	int choice;
	while (loop)
	{
		std::cout << "Please enter chosen index:\n";
		std::cin >> choice;
		for (int i = 0; i < 30; i++)
		{
			if (allIndexes[i] == choice)
			{
				loop = false;
				break;
			}
		}
		if (loop)
		{
			std::cout << "Invalid index\n";
		}
	}
	return (choice-1);
}