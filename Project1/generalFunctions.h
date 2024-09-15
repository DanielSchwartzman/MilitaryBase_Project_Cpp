#pragma once
#include "Base.h"
#include "Enlisted.h"
#include "Officer.h"
#include "NCO.h"
#include "MilitaryCivilian.h"

void printMenu();
Base* getBaseInfo();
Unit* getUnitInfo(const Base* base);
Soldier* getSoldierFromUser(const Base* base, int* retIndex);
Vehicle* getVehicleFromUser();
int getVehicleIndex(const Base* base);
int getUnitIndex(const Base* base);
Enlisted* getEnlistedInfo(const Base* base, int& unitIndex);
Officer* getOfficerInfo(const Base* base, int& unitIndex);
NCO* getNCOInfo(const Base* base, int& unitIndex);
MilitaryCivilian* getMilitaryCivilianInfo(const Base* base, int& unitIndex);
Address* getAddressFromUser();
int getSoldierIndex(const Base* base, int& unitIndex);