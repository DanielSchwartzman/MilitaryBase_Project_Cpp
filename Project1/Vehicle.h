#ifndef VEHICLE_DEFINE
#define VEHICLE_DEFINE

#include "Soldier.h"
#include "Enlisted.h"

#include "string.h"

class Vehicle 
{
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Variables
private:

	char* type;
	char* color;
	char* licencePlateNumber;
	int mileage;
	Enlisted* currentlyAssignedTo;

/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Methods
public:


	/////////////////////////////////
	//Constructor/Destructor
	Vehicle(char* type, char* color, char* licencePlate) 
	{
		this->type = _strdup(type);
		this->color = _strdup(color);
		this->licencePlateNumber = _strdup(licencePlate);
		mileage = 0;
		currentlyAssignedTo = nullptr;
	}
	~Vehicle() 
	{
		if (type != nullptr)
			delete(type);
		if (color != nullptr)
			delete(color);
		if (licencePlateNumber != nullptr)
			delete(licencePlateNumber);
	}
	Vehicle(const Vehicle& other) = delete;
	/////////////////////////////////


	/////////////////////////////////
	//Inline methods
	char* getType() const
	{
		return type;
	}
	char* getColor() const
	{
		return color;
	}
	char* getLicencePlateNumber() const
	{
		return licencePlateNumber;
	}
	int getMileage() const
	{
		return mileage;
	}
	void setMileage(int mileage)
	{
		this->mileage = mileage;
	}
	void assignVehicleToSoldier(Enlisted* enlisted) 
	{
		this->currentlyAssignedTo = enlisted;
	}
	Enlisted* getCurrentlyAssignedSoldier()  const
	{
		return currentlyAssignedTo;
	}
	void freeVehicle() 
	{
		this->currentlyAssignedTo = nullptr;
	}
	/////////////////////////////////


	/////////////////////////////////
	//Non-Inline methods
	void printVehicle() const;
	/////////////////////////////////


	/////////////////////////////////
	//Operators
	void operator+(const int mileageIncrease) 
	{
		mileage += mileageIncrease;
	}
	void operator=(const Vehicle& other)
	{
		if (this != &other)
		{
			this->type = _strdup(other.type);
			this->color = _strdup(other.color);
			this->licencePlateNumber = _strdup(other.licencePlateNumber);
			this->mileage = other.mileage;
			this->currentlyAssignedTo = other.currentlyAssignedTo;
		}
	}
	/////////////////////////////////


/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
};
#endif