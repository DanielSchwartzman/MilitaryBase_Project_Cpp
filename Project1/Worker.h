#ifndef WORKER_DEFINE
#define WORKER_DEFINE

#include "string.h"

class Worker 
{
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Variables
protected:

	int monthlySalary;
	int monthlyWorkDays;
	int vacationDays;
	char* employingCompany;


	/////////////////////////////////
	//Constructor/Destructor
	Worker(int monthlySalary, int monthlyWorkDays, int vacationDays, char* employingCompany)
	{
		this->monthlySalary = monthlySalary;
		this->monthlyWorkDays = monthlyWorkDays;
		this->vacationDays = vacationDays;
		this->employingCompany = _strdup(employingCompany);
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
	~Worker() 
	{
		if (employingCompany != nullptr)
			delete(employingCompany);
	}
	/////////////////////////////////


	/////////////////////////////////
	//Inline methods
	void setSalary(int newSalary) 
	{
		this->monthlySalary = newSalary;
	}
	void setNumberOfWorkDays(int newMonthlyWorkDays) 
	{
		this->monthlyWorkDays = newMonthlyWorkDays;
	}
	virtual void resetVacationDays() 
	{
		this->vacationDays = 15;
	}
	void setEmployingCompany(char* newEmployingCompany) 
	{
		this->employingCompany = newEmployingCompany;
	}
	int getMonthlySalary() const
	{
		return monthlySalary;
	}
	int getMonthlyWorkDays() const
	{
		return monthlyWorkDays;
	}
	int getVacationDays() const
	{
		return vacationDays;
	}
	char* getEmployingCompany() const
	{
		return employingCompany;
	}
	/////////////////////////////////


	/////////////////////////////////
	//Non-Inline methods
	void printWorker() const;
	/////////////////////////////////


	/////////////////////////////////
	//Operators
	void operator+(int salaryIncrease) 
	{
		monthlySalary += salaryIncrease;
	}
	bool operator=(Worker& other) 
	{
		if (this != &other) 
		{
			this->employingCompany = _strdup(other.employingCompany);
			this->monthlySalary = other.monthlySalary;
			this->monthlyWorkDays = other.monthlyWorkDays;
			this->vacationDays = other.vacationDays;
		}
	}
	/////////////////////////////////


/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
};
#endif