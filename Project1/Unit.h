#ifndef UNIT_DEFINE
#define UNIT_DEFINE

#include "Soldier.h"

#include "stdlib.h"
#include "string.h"
#include "Address.h"

class Unit 
{
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Variables
private:

	char* name;
	char* assignment;
	Soldier** allSoldiers;
	int numOfSoldiers;

/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Methods
public:


	/////////////////////////////////
	//Constructor/Destructor
	Unit(char* name, char* assignment)
	{
		this->name = _strdup(name);
		this->assignment = _strdup(assignment);
		allSoldiers = new Soldier*[30];
		numOfSoldiers = 0;
	}
	~Unit() 
	{
		if (name != nullptr)
			delete(name);
		if (assignment != nullptr)
			delete(assignment);
		if (allSoldiers != nullptr)
		{
			for (int i = 0; i < numOfSoldiers; i++)
			{
				delete(allSoldiers[i]);
			}
			delete(allSoldiers);
		}
	}
	Unit(const Unit& other) = delete;
	/////////////////////////////////


	/////////////////////////////////
	//Non-Inline methods
	void printUnit();
	void addSoldierToUnit(Soldier* soldier);
	Soldier* removeSoldierFromUnit(int soldierIndex);
	void setNewAddressForSoldier(Address* address, int soldierIndex);
	void setNewRoleForSoldier(char* role, int soldierIndex);
	void updateRankForSoldier(int flag, int soldierIndex);
	void raiseAlarm() const;
	void unitSetSoldierDutyStatus(int status, int soldierIndex);
	void addSpecializationToNCO(char* specialization, int soldierIndex);
	void addExperienceToNCOSpecialization(int soldierIndex);
	void assignEnlistedToOfficer(int enlistedIndex,int officerIndex);
	void resetVacationDays();
	Soldier* getSoldier(int soldierIndex);
	int chooseEnlisted();
	int chooseNCO();
	int chooseOfficer();
	/////////////////////////////////


	/////////////////////////////////
	//Inline methods
	char* getName() const
	{
		return name;
	}
	int getNumOfSoldiers() const
	{
		return numOfSoldiers;
	}
	/////////////////////////////////


/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
};
#endif