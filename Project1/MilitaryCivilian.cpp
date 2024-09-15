#include "MilitaryCivilian.h"

#include <iostream>

void MilitaryCivilian::emergencyDrill() const
{
	std::cout << "Personal Number: " << personalNumber << " Name: " << name << "\nProtocol: " << " Hiding out of sight\n\n";
}

void MilitaryCivilian::printSoldier()
{
	std::cout << "\n/////////\n";
	Soldier::printSoldier();
	Worker::printWorker();
	std::cout << "/////////\n\n";
}

void MilitaryCivilian::updateRank(int flag)
{
	if (flag > 0)
	{
		if (rank < 14)
		{
			rank = static_cast<ranking>(rank + 1);
			std::cout << "Promotion successfull\n";
		}
		else
		{
			std::cout << "Soldier already at the highest rank possible for MilitaryCivilian soldier\n";
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
			std::cout << "Soldier already at the lowest rank possible for MilitaryCivilian soldier\n";
		}
	}
}

int MilitaryCivilian::getType() const
{
	return 4;
}
