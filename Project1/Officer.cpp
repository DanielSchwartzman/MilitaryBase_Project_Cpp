#include "Officer.h"
#include "Enlisted.h"
#include <iostream>

void Officer::removeSubject(Enlisted* soldier)
{
	int i = 0;
	for (; i < numOfSubjects; i++)
	{
		if (allSubjects[i] == soldier) 
		{
			if (((Enlisted*)allSubjects[i])->getCommandingOfficer() != nullptr) 
			{
				((Enlisted*)allSubjects[i])->setCommandingOfficer(nullptr);
			}
			break;
		}
	}
	for (; i < 10; i++)
	{
		allSubjects[i] = allSubjects[i + 1];
	}
	numOfSubjects--;
}

void Officer::removeAllSubjects()
{
	for (int i = 0; i < numOfSubjects; i++)
	{
		removeSubject(allSubjects[i]);
	}
	numOfSubjects = 0;
}

void Officer::printSoldier()
{
	std::cout << "\n/////////\n";
	std::cout << "Type: " << "Officer\n";
	Soldier::printSoldier();
	if (numOfSubjects > 0) 
	{
		std::cout << "\nAll subjects:\n";
		for (int i = 0; i < numOfSubjects; i++)
		{
			std::cout << i+1 << "-" << allSubjects[i]->getName() << "\n";
		}
	}
	else 
	{
		std::cout << "Currently no subjects are assigned\n";
	}
	std::cout << "/////////\n\n";
}

int Officer::getType() const
{
	return 3;
}

void Officer::updateRank(int flag)
{
	if (flag > 0)
	{
		if (rank < 17)
		{
			rank = static_cast<ranking>(rank + 1);
			std::cout << "Promotion successfull\n";
		}
		else
		{
			std::cout << "Soldier already at the highest rank possible for Officer soldier\n";
		}
	}
	else
	{
		if (rank > 9)
		{
			rank = static_cast<ranking>(rank - 1);
			std::cout << "Demotion successfull\n";
		}
		else
		{
			std::cout << "Soldier already at the lowest rank possible for Officer soldier\n";
		}
	}
}

void Officer::emergencyDrill() const
{
	std::cout << "Personal Number: " << personalNumber << " Name: " << name << "\nProtocol: ";
	switch (rank)
	{
	case 9:
	{
		std::cout << " Patrolling perimeter\n\n";
		break;
	}
	case 10:
	{
		std::cout << " Patrolling perimeter\n\n";
		break;
	}
	case 11:
	{
		std::cout << " Patrolling perimeter\n\n";
		break;
	}
	case 12:
	{
		std::cout << " Operating commanding outpost\n\n";
		break;
	}
	case 13:
	{
		std::cout << " Operating commanding outpost\n\n";
		break;
	}
	case 14:
	{
		std::cout << " Operating commanding center\n\n";
		break;
	}
	case 15:
	{
		std::cout << " Operating commanding center\n\n";
		break;
	}
	case 16:
	{
		std::cout << " Operating commanding center\n\n";
		break;
	}
	case 17:
	{
		std::cout << " Planning next move\n\n";
		break;
	}
	default:
		break;
	}
}
