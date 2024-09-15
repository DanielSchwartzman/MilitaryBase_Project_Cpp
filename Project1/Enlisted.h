#pragma once
#ifndef ENLISTED_DEFINE
#define ENLISTED_DEFINE

#include "Soldier.h"
class Vehicle;
class Officer;

class Enlisted : public Soldier
{
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Variables
private:

	int daysUntillDischarge;
	Vehicle* currentVehicle;
	Officer* commandingOfficer;

/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Methods
public:


	/////////////////////////////////
	//Constructor/Destructor
	Enlisted(char* name, int personalNumber, char* role, Unit* unit, Address* address, Officer* commandingOfficer=nullptr, int daysUntillDischarge = 1095):Soldier(name,personalNumber,role,unit,address)
	{
		this->daysUntillDischarge = daysUntillDischarge;
		this->currentVehicle = nullptr;
		this->commandingOfficer = commandingOfficer;
	}
	~Enlisted() 
	{
		if (currentVehicle != nullptr)
			freeVehicle();
		if (commandingOfficer != nullptr)
			setCommandingOfficer(nullptr);
	}
	/////////////////////////////////


	/////////////////////////////////
	//Inline methods
	void setDaysUntillDischarge(int daysUntillDischarge) 
	{
		this->daysUntillDischarge = daysUntillDischarge;
	}
	void setCurrentVehicle(Vehicle* vehicle)
	{
		currentVehicle = vehicle;
	}
	Officer* getCommandingOfficer() const
	{
		return commandingOfficer;
	}
	/////////////////////////////////


	/////////////////////////////////
	//Non-Inline methods
	void updateRank(int flag);
	void emergencyDrill() const;
	void setCommandingOfficer(Officer* officer);
	void printSoldier();
	void freeVehicle();
	int getType() const;
	/////////////////////////////////


	/////////////////////////////////
	//Operators
	void operator-(int decrease) 
	{
		daysUntillDischarge -= decrease;
	}
	void operator+(int increase)
	{
		daysUntillDischarge += increase;
	}
	/////////////////////////////////


/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
};
#endif