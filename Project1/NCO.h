#ifndef NCO_DEFINE
#define NCO_DEFINE

#include <iostream>
#include "Soldier.h"

class NCO : public Soldier
{
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Variables
private:

	char** specializations;
	int numOfSpecializations;
	int* yearsOfExperience;

/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Methods
public:


	/////////////////////////////////
	//Constructor/Destructor
	NCO(char* name, int personalNumber, char* role, Unit* unit, Address* address):Soldier(name,personalNumber,role,unit,address)
	{
		this->specializations =new char*[10];
		this->yearsOfExperience = new int[10];
		numOfSpecializations = 0;
		rank = ChiefSergeant;
	}
	~NCO() 
	{
		if (specializations != nullptr)
			delete(specializations);
		if (yearsOfExperience != nullptr)
			delete(yearsOfExperience);
	}
	/////////////////////////////////


	/////////////////////////////////
	//Inline methods
	char* getSpecialization(int index) const
	{
		return specializations[index];
	}
	void addSpecialization(char* specialization)
	{
		if (numOfSpecializations < 10) 
		{
			specializations[numOfSpecializations] = _strdup(specialization);
			yearsOfExperience[numOfSpecializations++] = 0;
			std::cout << "Specialization was added successfully\n";
		}
		else
		{
			std::cout << "Unable to add more specializations to given NCO\n";
		}
	}
	void addYearsOfExperience(int increase,int specializationIndex) 
	{
		yearsOfExperience[specializationIndex] += increase;
		std::cout << "Experience increased successfully\n";
	}
	int getNumOfSpecializations() const
	{
		return numOfSpecializations;
	}
	/////////////////////////////////


	/////////////////////////////////
	//Non-Inline methods
	void updateRank(int flag);
	void emergencyDrill() const;
	void printSoldier();
	int getType() const;
	void printSpecializations() const;
	/////////////////////////////////


/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
};
#endif