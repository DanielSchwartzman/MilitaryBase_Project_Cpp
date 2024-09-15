#include "NCO.h"
#include <iostream>

void NCO::printSoldier() 
{
	std::cout << "\n/////////\n";
	std::cout << "Type: " << "NCO\n";
	Soldier::printSoldier();

	if (numOfSpecializations > 0)
	{
		std::cout << "\nSpecializations:\n";
		for (size_t i = 0; i < numOfSpecializations; i++)
		{
			std::cout << (i + 1) << "-" << specializations[i] << " | Experience:" << yearsOfExperience[i] << "\n";
		}
	}
	else
	{
		std::cout << "Currently, NCO has no specializations\n";
	}
	std::cout << "/////////\n\n";
}

int NCO::getType() const
{
	return 2;
}

void NCO::printSpecializations() const
{
	for (int i = 0; i < numOfSpecializations; i++)
	{
		std::cout << (i + 1) << "- " << specializations[i] << "\n";
	}
}

void NCO::updateRank(int flag)
{
	if (flag > 0)
	{
		if (rank < 8)
		{
			rank = static_cast<ranking>(rank + 1);
			std::cout << "Promotion successfull\n";
		}
		else 
		{
			std::cout << "Soldier already at the highest rank possible for NCO soldier\n";
		}
	}
	else
	{
		if (rank > 4)
		{
			rank = static_cast<ranking>(rank - 1);
			std::cout << "Demotion successfull\n";
		}
		else
		{
			std::cout << "Soldier already at the lowest rank possible for NCO soldier\n";
		}
	}
}

void NCO::emergencyDrill() const
{
	std::cout << "Personal Number: " << personalNumber << " Name: " << name << "\nProtocol: " << " Patrolling perimeter\n\n";
}
