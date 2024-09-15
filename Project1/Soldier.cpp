#include <iostream>
#include "Soldier.h"
#include "Unit.h"

void Soldier::updateRank(int flag){}
void Soldier::emergencyDrill() const{}
int Soldier::getType() const{return 0;}

void Soldier::printSoldier()
{
	std::cout << "Rank: " << rankNames[rank] << "\n" << "Name: " << name << "\n" << "Personal number: " << personalNumber << "\n" << "Role: " << role << "\n" << "Unit: " << unit->getName() << "\n" << "Address: ";
	address->printAddress();
	std::cout << "Duty status: " << (isCurrentlyOnDuty() ? "Active\n" : "Reserve\n");
}