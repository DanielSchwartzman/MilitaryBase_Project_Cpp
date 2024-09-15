#ifndef BASE_DEFINE
#define BASE_DEFINE
#include "Vehicle.h"
#include "Address.h"
#include "Unit.h"

#include "stdlib.h"
#include "string.h"

class Base 
{
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Variables
private:

	char* baseName;
	Vehicle** allVehicles;
	int numOfVehicles;
	Address address;
	Unit** allUnits;
	int numOfUnits;
	Vehicle** assignedVehicles;
	int numOfAssignedVehicles;

/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Methods
public:


	/////////////////////////////////
	//Constructor/Destructor
	Base(char* baseName, char* city, char* street, int& homeNumber, int& postalCode):address(city, street, homeNumber, postalCode)
	{
		this->baseName = _strdup(baseName);
		allVehicles = new Vehicle*[10];
		assignedVehicles = new Vehicle * [10];
		allUnits = new Unit*[10];
		numOfVehicles = 0;
		numOfUnits = 0;
		numOfAssignedVehicles = 0;
	}
	~Base() 
	{
		if (baseName != nullptr)
			delete(baseName);
		if (allVehicles != nullptr)
		{
			for (int i = 0; i < numOfVehicles; i++)
			{
				delete(allVehicles[i]);
			}
			delete(allVehicles);
		}
		if (allUnits != nullptr) 
		{
			for (int i = 0; i < numOfUnits; i++)
			{
				delete(allUnits[i]);
			}
			delete(allUnits);
		}
		if (assignedVehicles != nullptr)
			delete(assignedVehicles);
	}
	Base(const Base& other) = delete;
	/////////////////////////////////


	/////////////////////////////////
	//Inline methods
	int getNumOfVehicles() const
	{
		return numOfVehicles;
	}
	int getNumOfUnits() const
	{
		return numOfUnits;
	}
	Unit* getUnit(int unitIndex) const
	{
		return allUnits[unitIndex];
	}
	/////////////////////////////////


	/////////////////////////////////
	//Non-Inline methods
	void baseAddSoldierToUnit(Soldier* soldier, int unitIndex);
	void baseSetNewUnitForSoldier(int oldUnitIndex, int newUnitIndex, int soldierIndex);
	void baseSetNewAddressForSoldier(Address* address, int unitIndex, int soldierIndex);
	void baseSetNewRoleForSoldier(char* role, int unitIndex, int soldierIndex);
	void baseUpdateRankForSoldier(int flag, int unitIndex, int soldierIndex);
	void baseAddUnit(Unit* unit);
	void baseSetSoldierDutyStatus(int status, int unitIndex, int soldierIndex);
	void baseAddVehicle(Vehicle* vehicle);
	void baseAssignVehicleToSoldier(Enlisted* soldier, int vehicleIndex);
	void baseFreeVehicle(int vehicleIndex);
	void baseAddSpecializationToNCO(char* specialization, int unitIndex, int soldierIndex);
	void baseAddExperienceToNCOSpecialization(int unitIndex, int soldierIndex);
	void baseAssignSoldierToOfficer(int enlistedIndex,int officerIndex,int unitIndex);
	void baseRaiseAlarm() const;
	void baseResetVacationDays();
	void printAllVehicles() const;
	void printBase() const;
	void printAllUnits() const;
	/////////////////////////////////


	/////////////////////////////////
	//Operators
	void operator+(Unit* other) 
	{
		baseAddUnit(other);
	}
	void operator+(Vehicle* other) 
	{
		baseAddVehicle(other);
	}
	/////////////////////////////////


/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
};
#endif