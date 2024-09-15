#ifndef ADDRESS_DEFINE
#define ADDRESS_DEFINE

#include "string.h"

class Address
{
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Variables
private:

	char* city;
	char* street;
	int homeNumber;
	int postalCode;

/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Methods
public:


	/////////////////////////////////
	//Constructor/Destructor
	Address(char* city, char* street, int homeNumber, int postalCode)
	{
		this->city = _strdup(city);
		this->street = _strdup(street);
		this->homeNumber = homeNumber;
		this->postalCode = postalCode;
	}
	~Address() 
	{
		if (city != nullptr)
			delete(city);
		if (street != nullptr)
			delete(street);
	}
	Address(const Address& other) = delete;
	/////////////////////////////////


	/////////////////////////////////
	//Inline methods
	char* getCity() const
	{
		return city;
	}
	char* getStreet() const
	{
		return street;
	}
	int getHomeNumber() const
	{
		return homeNumber;
	}
	int getPostalCode() const
	{
		return postalCode;
	}
	/////////////////////////////////


	/////////////////////////////////
	//Non-Inline methods
	void printAddress() const;
	/////////////////////////////////
	

	/////////////////////////////////
	//Operators
	bool operator==(Address& other) 
	{
		if (this != &other) 
		{
			this->city = _strdup(other.city);
			this->street = _strdup(other.street);
			this->homeNumber = other.homeNumber;
			this->postalCode = other.postalCode;
		}
	}
	/////////////////////////////////


/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
};
#endif