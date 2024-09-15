#ifndef MILITARYCIVILIAN_DEFINE
#define MILITARYCIVILIAN_DEFINE

#include "Soldier.h"
#include "Worker.h"

class MilitaryCivilian :public Soldier, public Worker
{
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Overriding methods
public:

	/////////////////////////////////
	//Constructor/Destructor
	MilitaryCivilian(char* name, int personalNumber, char* role, Unit* unit, Address* address,char* employingCompany, int monthlySalary = 6500, int monthlyWorkDays = 24, int vacationDays = 14)
		:Worker(monthlySalary,monthlyWorkDays,vacationDays,employingCompany),Soldier(name,personalNumber,role,unit,address)
	{
		rank = ChiefSergeant;
	}
	/////////////////////////////////


	/////////////////////////////////
	//Non-Inline methods
	void resetVacationDays() 
	{
		vacationDays = 24;
	}
	void emergencyDrill() const;
	void printSoldier();
	void updateRank(int flag);
	int getType() const;
	/////////////////////////////////


/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
};
#endif