#include <iostream>
#include "switchCases.h"

void freeAll(Base* base);

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////
//Main
int main()
{
	Base* base = getBaseInfo();

	bool loop = true;
	while (loop)
	{
		int answer;
		printMenu();
		std::cin.clear();
		std::cin >> answer;
		std::cin.clear();
		switch (answer)
		{
		case 1:
		{
			case1(base);
			break;
		}
		case 2:
		{
			case2(base);
			break;
		}
		case 3:
		{
			case3(base);
			break;
		}
		case 4:
		{
			case4(base);
			break;
		}
		case 5:
		{
			case5(base);
			break;
		}
		case 6:
		{
			case6(base);
			break;
		}
		case 7:
		{
			case7(base);
			break;
		}
		case 8:
		{
			case8(base);
			break;
		}
		case 9:
		{
			case9(base);
			break;
		}
		case 10:
		{
			case10(base);
			break;
		}
		case 11:
		{
			case11(base);
			break;
		}
		case 12:
		{
			case12(base);
			break;
		}
		case 13:
		{
			case13(base);
			break;
		}
		case 14:
		{
			case14(base);
			break;
		}
		case 15: 
		{
			case15(base);
			break;
		}
		case 16:
		{
			case16(base);
			break;
		}
		case 17: 
		{
			loop = false;
			freeAll(base);
			break;
		}
		default:
		{
			std::cout << "Please enter valid number\n";
		}
		}
	}
}
/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


void freeAll(Base* base) 
{
	delete(base);
}