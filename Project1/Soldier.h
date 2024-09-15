#ifndef SOLDIER_DEFINE
#define SOLDIER_DEFINE

class Unit;
#include "Address.h"

//Abstract Class
class Soldier
{
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Variables
protected:

	//Enlisted 0-3
	//NCO 4-8
	//Officer 9-17
	enum ranking{Private,ChiefPrivate,Sergeant,FirstSeargent,ChiefSergeant,FirstChiefSergeant
	,ChiefAdvancedSergeant,ChiefSeniorSergeant,ChiefNonCommisionedOfficer,SecondLieutenant,Lieutenant,Captain,Major,LieutenantColonel,Colonel,BrigadierGeneral,MajorGeneral,LieutenantGeneral};
	ranking rank;
	const char* rankNames[17]={ "Private","ChiefPrivate","Sergeant","FirstSeargent","ChiefSergeant","FirstChiefSergeant"
	,"ChiefAdvancedSergeant","ChiefSeniorSergeant","ChiefNonCommisionedOfficer","SecondLieutenant","Lieutenant,Captain,Major","LieutenantColonel","Colonel","BrigadierGeneral","MajorGeneral","LieutenantGeneral"};
	char* name;
	int personalNumber;
	char* role;
	Unit* unit;
	Address* address;
	bool currentlyOnDuty;


	/////////////////////////////////
	//Constructor/Destructor
	Soldier(char* name, int& personalNumber, char* role, Unit* unit, Address* address, bool currentlyOnDuty = true)
	{
		this->name = _strdup(name);
		this->personalNumber = personalNumber;
		this->unit = unit;
		this->address = address;
		this->currentlyOnDuty = currentlyOnDuty;
		rank = Private;
		this->role = _strdup(role);
	}
	/////////////////////////////////


/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Methods
public:


	/////////////////////////////////
	//Constructor/Destructor
	~Soldier()
	{
		if (name != nullptr)
			delete(name);
		if (role != nullptr)
			delete(role);
	}
	/////////////////////////////////


	/////////////////////////////////
	//Inline methods
	void setNewUnit(Unit* unit) 
	{
		this->unit = unit;
	}
	void setNewAddress(Address* address) 
	{
		delete(this->address);
		this->address = address;
	}
	void setNewRole(char* role)
	{
		delete(this->role);
		this->role = _strdup(role);
	}
	void setCurrentlyOnDuty(int status) 
	{
		if (status == 0)
			currentlyOnDuty = false;
		else
			currentlyOnDuty = true;
	}
	char* getName() const
	{
		return name;
	}
	int getPersonalNumber() const
	{
		return personalNumber;
	}
	char* getRole() const
	{
		return role;
	}
	Unit* getUnit() const
	{
		return unit;
	}
	Address* getAddress() const
	{
		return address;
	}
	bool isCurrentlyOnDuty() const
	{
		return currentlyOnDuty;
	}
	/////////////////////////////////


	/////////////////////////////////
	//Non-Inline methods
	virtual void updateRank(int flag);
	virtual void emergencyDrill() const;
	virtual void printSoldier();
	virtual int getType() const;
	/////////////////////////////////


	/////////////////////////////////
	//Operators
	bool operator=(Soldier& other) 
	{
		if (this != &other) 
		{
			this->rank = other.rank;
			this->name = _strdup(other.name);
			this->role = _strdup(other.role);
			this->personalNumber =other.personalNumber;
			this->address = other.address;
			this->unit = other.unit;
			this->currentlyOnDuty = other.currentlyOnDuty;
		}
	}
	/////////////////////////////////


/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
};
#endif