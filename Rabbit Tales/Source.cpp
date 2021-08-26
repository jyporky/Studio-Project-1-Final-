#include "map.h"
#include "Person.h"
#include "Shop.h"
#include "Elements.h"
#include "Stats.h"
#include <Windows.h>
#include <cstdlib>
#include "MainMenu.h"

using namespace std;


void eliminatecursor();
void gotoxys(int x, int y);
void gotoxy(int x, int y, string print, int clearfrom, int clearto);
void gotoxy2(int x, int y, string print);
void makingenemies();
void getelement();
void getelementname();
void printelement();
void printelement();
void compareelements(int element);
float compareonelement(int element, int otherelement);
int selectionforencounter(int Arrowlocation);
int selectionforatk(int Arrowlocation);
int selectionforatk2(int Arrowlocation, string fourthskill);
int selectionforcc(int Arrowlocation);
void creation_of_player();
string Enemyusingskill(int attacking, int defender, float adv);
string usingskill(int abilitynumber, int defender, float adv);
string usingskill2(string fourthskill, int defender, float adv);
void battlestart(int x, float adv, string fourthskill);
void makefinalboss(int user);
void PrintMob(string mobname, int num);
void usingofitems(string itemname, int x);
void FullScreen();
void ChangeSize();
void beeping(int oneortwo);
void interactions(int x);
void interactions2(int x);
void printmob2(string mobname);


Shop Shopping;

int gelements[10];

string gelementname[10];

Elements* ptr[11] = { nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };

// If user bought a skill before, set this as true
bool SkillBoughtBefore = false;


// To edit the Carrot Amount here:
int CarrotAmount = 100;

// Ur items and the name
string Inventory;

int ItemAmt[9] = { 0,0,0,0,0,0,0,0,0 };
std::string TheItemName[9] = { "Small Hp Potion", "Medium Hp Potion", "Large Hp Potion", "Tiny Mana Potion",
"Huge Mana Potion", "Magical Bread", "Stun Bomb", "Sabo Bomb", "Magical Rice" };

string ItemDescription[9] =
{ "Small Hp Potion\n|  Heal 20% Hp\n|  The Most basic potion\n|  use to heal small wounds",
"Medium Hp Potion\n|  Heal 50% Hp\n|  A better potion use\n|  to heal some big wounds",
"Large Hp Potion\n|  Heal 100% Hp\n|  A potion used to treat\n|  very serious injuries",
"Tiny Mana Potion\n|  Restore 40 mana\n|  A potion to get some\n|  point of mana",
"Huge Mana Potion\n|  Restore 120 mana\n|  A potion to get a good\n|  number of mana",
"Magical Bread\n|  Heal 50% Hp and\n|  restore 60 mana\n|  Juicy delicious bread\n|  that every skill\n|  caster wants",
"Stun Bomb\n|  reduces enemy attack\n|  by 50%",
"Sabo Bomb\n|  Drain Out all of\n|  Opponent's mana\n|  If you buy and\n|  use this\n|  item, well done.\n|  You cheated!",
"Magical Rice\n|  Restore Hp and\n|  mana to Max\n|  A Singapore style dish.\n|  500 years of cultivation\n|  have run into the rice,\n| "
"it fills you with\n|  determination"
};

int main(void)
{
	FullScreen();
	ChangeSize();
	eliminatecursor();
	MainMenu M;
	srand(unsigned(time(0)));
	map P;
	Person person;
	string ElementType;
	// Restore Shop
	bool EnterShopYet = false;
	int EnemyDefeated = 0;

	M.TheMainMenu();

	if (M.getQuit() == true)
	{
		exit(1);
	}

	M.Instruction();

	std::system("CLS");

	cout << "once there was a boy , meh thatss boring. You know the normal stuff, his lover was kidnapped by an evil person \nwhich then he has to defeat to get her back blah blah blah \nLets just cut to him" << endl;

	char fhaeufhwi = _getch();

	std::system("CLS");

	makingenemies(); //creation of enemies

	creation_of_player(); //creating the player

	makefinalboss(ptr[10]->getelement());

	// Insert the elemental type here
	// Fire, Water, Air, Earth
	ElementType = ptr[10]->getelementname();

	std::system("CLS");

	gotoxys(0, 0);

	std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

	gotoxys(24, 2);

	cout << "I am an honored knight\n\t\t\t";
	beeping(1);
	cout << "and I will - ";

	fhaeufhwi = _getch();

	gotoxys(0, 0);

	std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

	gotoxys(24, 2);

	cout << "Yeah yeah yeah just\n\t\t\tbuy something already,";
	beeping(2);
	cout << "\n\t\t\thurry up and save princess";

	fhaeufhwi = _getch();

	while (EnemyDefeated < 7)
	{
		P.pmap(person.getmmap());

		person.Print(Shopping.getequipmenttype());
		PrintMob(ptr[person.GetStageClear()]->getenemyname(), person.GetStageClear());

		person.Movement();

		if (person.getEnterShop() == true)
		{
			// Enter Shop
			std::system("CLS");
			Shopping.TheShop(SkillBoughtBefore, ElementType, CarrotAmount, Inventory, ItemAmt, TheItemName, EnterShopYet);
			EnterShopYet = true;
		}
		person.SetEnterShop(false);


		if (person.getFightingEnemy() == true)
		{
			std::system("CLS");

			interactions(EnemyDefeated);

			float adv = 1;

			eliminatecursor(); //eliminates the cursor

			getelement(); //gets all the elements of enemies

			getelementname(); //gets their names

			adv = compareonelement(ptr[10]->getelement(), EnemyDefeated); //comparing user's element to an enemy's element


			battlestart(EnemyDefeated, adv, Shopping.getfourthskill());

			if (ptr[10]->gethp() <= 0)
			{
				cout << R"(
  ________                        ________                      
 /  _____/_____    _____   ____   \_____  \___  __ ___________
/   \  ___\__  \  /     \_/ __ \   /   |   \  \/ // __ \_  __ \
\    \_\  \/ __ \|  Y Y  \  ___/  /    |    \   /\  ___/|  | \/ 
 \______  (____  /__|_|  /\___  > \_______  /\_/  \___  >__| 
        \/     \/      \/     \/          \/          \/)";
				break;
			}

			interactions2(EnemyDefeated);

			//Restore shop
			EnterShopYet = false;

			EnemyDefeated++;

			std::system("CLS");
		}

		person.SetFightingEnemy(false);
	}

	while (ptr[10]->gethp() > 0)
	{
		person.setmap();

		P.pmap(3);

		person.Print(Shopping.getequipmenttype());

		person.Movement();

		if (person.getEnterShop() == true)
		{
			interactions2(9);
			// Enter Shop
			std::system("CLS");
			for (int i = 0; i < 2; i++)
			{
				Shopping.Printhead6();
				Shopping.Printhead7(500);
				Shopping.Printhead6();
				Shopping.Printhead8(500);
			}
			for (int i = 0; i < 3; i++)
			{
				Shopping.Printhead6();
				Shopping.Printhead7(200);
				Shopping.Printhead6();
				Shopping.Printhead8(200);
			}
			for (int i = 0; i < 5; i++)
			{
				Shopping.Printhead6();
				Shopping.Printhead7(100);
				Shopping.Printhead6();
				Shopping.Printhead8(100);
			}

			Shopping.PrintHead4();
			Shopping.Printhead3();
			HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsoleOutput, 4);

			cout << "\nWhere ";
			Beep(350, 400);
			cout << "are ";
			Beep(300, 400);
			cout << "my ";
			Beep(300, 800);
			cout << "carrots?";
			Beep(150, 400);
			Beep(50, 50);

			char wait = _getch();

			std::system("CLS");
			float adv = compareonelement(ptr[10]->getelement(), 9);
			battlestart(9, adv, Shopping.getfourthskill());
			person.SetEnterShop(false);
			break;
		}
	}

	if (ptr[10]->gethp() <= 0)
	{
		std::system("CLS");
		cout << R"(
  ________                        ________                      
 /  _____/_____    _____   ____   \_____  \___  __ ___________
/   \  ___\__  \  /     \_/ __ \   /   |   \  \/ // __ \_  __ \
\    \_\  \/ __ \|  Y Y  \  ___/  /    |    \   /\  ___/|  | \/ 
 \______  (____  /__|_|  /\___  > \_______  /\_/  \___  >__| 
        \/     \/      \/     \/          \/          \/)";
	}
	else
	{
		HANDLE tcolor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(tcolor, 7);
		std::system("CLS");
		cout << "You won! Claiming your lover, you both reunite with one another and feel at peace once again" << endl;
		cout << R"( 
'/ /_\(()))
L( '}{' ())
) (   )_ (()
(_   \ (   (_)
 (__'__\_) |
\___|_(}==/ \
|    |  |    |
|_/\_|  |    |
 |  |   |    |
  ) )\  |    |
_/| |/  |    \
( ,\ |_  '~~~~/7
\_(___)  _/Y)" << '\n';
		char UserInput = _getch();
		SetConsoleTextAttribute(tcolor, 4);
		cout << "But was it worth it?";
		UserInput = _getch();
	}
}

void makefinalboss(int user)
{
	ptr[9] = new Stats;
	ptr[9]->finalboss(user);
}

void eliminatecursor()
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hConsoleOutput, &cursorInfo);
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(hConsoleOutput, &cursorInfo);
}

void gotoxys(int x, int y)
{
	COORD scrn;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = x; scrn.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, scrn);
}

void gotoxy(int x, int y, string print, int clearfrom, int clearto)
{
	int clearing = clearfrom;
	COORD scrn;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = clearfrom; i < clearto; i++)
	{
		scrn.X = 0; scrn.Y = i;
		SetConsoleCursorPosition(hConsoleOutput, scrn);
		cout << ' ';
	}
	scrn.X = x; scrn.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, scrn);
	cout << print;
}

void gotoxy2(int x, int y, string print)
{
	COORD scrn;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = x; scrn.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, scrn);
	cout << print;
}

void makingenemies()
{
	for (int x = 0; x < 9; x++)
	{
		ptr[x] = new Stats;
		ptr[x]->creationofenemies();
	}
}

void getelement()
{
	std::system("CLS");
	for (int x = 0; x < 10; x++)
	{
		gelements[x] = ptr[x]->getelement();
	}
}

void getelementname()
{
	for (int x = 0; x < 10; x++)
	{
		gelementname[x] = ptr[x]->getelementname();
	}
}

void printelement()
{
	for (int x = 0; x < 10; x++)
	{
		if (gelements[x] == 1)
		{
			cout << x << " is water" << endl;
		}
		else if (gelements[x] == 2)
		{
			cout << x << " is fire" << endl;
		}
		else if (gelements[x] == 3)
		{
			cout << x << " is earth" << endl;
		}
		else if (gelements[x] == 4)
		{
			cout << x << " is air" << endl;
		}
	}
}

void compareelements(int element)
{
	for (int x = 0; x < 10; x++)
	{
		if (element - gelements[x] == 1 && element != 1)
		{
			cout << x << " win against Player" << endl;
		}
		else if (element == 1 && gelements[x] == 4)
		{
			cout << x << " win against Player" << endl;
		}
	}
}

float compareonelement(int element, int otherelement)
{
	float advantage = 1;
	if (element - gelements[otherelement] == 1 && element != 1)
	{
		cout << "You will be nerfed, as you are facing " << gelementname[otherelement] << endl;
		advantage = 0.5;
	}
	else if (element == 1 && gelements[otherelement] == 4)
	{
		cout << "You will be nerfed, as you are facing " << gelementname[otherelement] << endl;
		advantage = 0.5;
	}
	else if (gelements[otherelement] - element == 1 && gelements[otherelement] != 1)
	{
		cout << "You get a dmg bonus, as you are facing " << gelementname[otherelement] << endl;
		advantage = 1.5;
	}
	else if (gelements[otherelement] == 1 && element == 4)
	{
		cout << "You get a dmg bonus, as you are facing " << gelementname[otherelement] << endl;
		advantage = 1.5;
	}
	else
	{
		cout << "No buffs no nerfs, as you are facing " << gelementname[otherelement] << endl;
	}
	return advantage;
}

int selectionforencounter(int Arrowlocation)
{
	bool userselection = false;
	while (userselection == false)
	{
		char input = _getch();

		if (input == 'w')
		{
			if (Arrowlocation > 1)
			{
				Arrowlocation--;
			}
			else
			{
				Arrowlocation = 3;
			}
		}
		else if (input == 's')
		{
			if (Arrowlocation < 3)
			{
				Arrowlocation++;
			}
			else
			{
				Arrowlocation = 1;
			}
		}
		else if (input == '\r')
		{
			break;
		}

		if (Arrowlocation == 1)
		{
			gotoxys(31, 22);
			cout << " ";
			gotoxys(31, 24);
			cout << " ";
			gotoxys(31, 20);
			cout << '>';
		}
		else if (Arrowlocation == 2)
		{
			gotoxys(31, 24);
			cout << " ";
			gotoxys(31, 20);
			cout << " ";
			gotoxys(31, 22);
			cout << '>';
		}
		else if (Arrowlocation == 3)
		{
			gotoxys(31, 20);
			cout << " ";
			gotoxys(31, 22);
			cout << " ";
			gotoxys(31, 24);
			cout << '>';
		}
	}
	return Arrowlocation;
}

int selectionforatk(int Arrowlocation)
{
	bool userselection = false;

	gotoxy2(31, 19, ">");
	gotoxy2(31, 21, " ");
	gotoxy2(31, 23, " ");
	gotoxy2(1, 19, ptr[10]->abilitydescription(1));

	while (userselection == false)
	{
		char input = _getch();

		gotoxy2(1, 25, "                  ");

		if (input == 'w')
		{
			if (Arrowlocation > 1)
			{
				Arrowlocation--;
			}
			else
			{
				Arrowlocation = 3;
			}
		}
		else if (input == 's')
		{
			if (Arrowlocation < 3)
			{
				Arrowlocation++;
			}
			else
			{
				Arrowlocation = 1;
			}
		}
		else if (input == '\r')
		{
			int currentmana = int(ptr[10]->getmana());
			int manacost = ptr[10]->abilitymanacost(Arrowlocation);
			int toomuchcost = currentmana - manacost;
			if (toomuchcost < 0)
			{
				gotoxys(1, 28);
				cout << " Insufficient mana";
			}
			else
			{
				break;
			}
		}

		for (int i = 19; i < 25; i++)
		{
			gotoxy2(1, i, "                             |");
		}

		if (Arrowlocation == 1)
		{
			gotoxy2(31, 19, ">");
			gotoxy2(31, 21, " ");
			gotoxy2(31, 23, " ");
			gotoxy2(1, 19, ptr[10]->abilitydescription(1));
		}
		else if (Arrowlocation == 2)
		{
			gotoxy2(31, 19, " ");
			gotoxy2(31, 21, ">");
			gotoxy2(31, 23, " ");
			gotoxy2(1, 19, ptr[10]->abilitydescription(2));
		}
		else if (Arrowlocation == 3)
		{
			gotoxy2(31, 19, " ");
			gotoxy2(31, 21, " ");
			gotoxy2(31, 23, ">");
			gotoxy2(1, 19, ptr[10]->abilitydescription(3));
		}
	}
	return Arrowlocation;
}

int selectionforatk2(int Arrowlocation, string fourthskill)
{
	bool userselection = false;

	gotoxy2(31, 19, ">");
	gotoxy2(31, 21, " ");
	gotoxy2(31, 23, " ");
	gotoxy2(31, 25, " ");
	gotoxy2(1, 19, ptr[10]->abilitydescription(1));

	while (userselection == false)
	{
		char input = _getch();

		if (input == 'w')
		{
			if (Arrowlocation > 1)
			{
				Arrowlocation--;
			}
			else
			{
				Arrowlocation = 4;
			}
		}
		else if (input == 's')
		{
			if (Arrowlocation < 4)
			{
				Arrowlocation++;
			}
			else
			{
				Arrowlocation = 1;
			}
		}
		else if (input == '\r')
		{
			int currentmana = int(ptr[10]->getmana());
			int manacost = ptr[10]->abilitymanacost(Arrowlocation);
			int toomuchcost = currentmana - manacost;
			if (toomuchcost < 0)
			{
				gotoxys(0, 14);
				cout << "insufficient mana";
			}
			else
			{
				break;
			}
		}

		for (int i = 19; i < 25; i++)
		{
			gotoxy2(1, i, "                             |");
		}

		if (Arrowlocation == 1)
		{
			gotoxy2(31, 19, ">");
			gotoxy2(31, 21, " ");
			gotoxy2(31, 23, " ");
			gotoxy2(31, 25, " ");
			gotoxy2(1, 19, ptr[10]->abilitydescription(1));
		}
		else if (Arrowlocation == 2)
		{
			gotoxy2(31, 19, " ");
			gotoxy2(31, 21, ">");
			gotoxy2(31, 23, " ");
			gotoxy2(31, 25, " ");
			gotoxy2(1, 19, ptr[10]->abilitydescription(2));
		}
		else if (Arrowlocation == 3)
		{
			gotoxy2(31, 19, " ");
			gotoxy2(31, 21, " ");
			gotoxy2(31, 23, ">");
			gotoxy2(31, 25, " ");
			gotoxy2(1, 19, ptr[10]->abilitydescription(3));
		}
		else if (Arrowlocation == 4)
		{
			gotoxy2(31, 19, " ");
			gotoxy2(31, 21, " ");
			gotoxy2(31, 23, " ");
			gotoxy2(31, 25, ">");
			gotoxy2(1, 19, ptr[10]->abilitydescription2(fourthskill));
		}
	}
	return Arrowlocation;
}

int selectionforcc(int Arrowlocation) //character creation
{
	bool userselection = false;
	while (userselection == false)
	{
		char input = _getch();

		if (input == 'w')
		{
			if (Arrowlocation > 1)
			{
				Arrowlocation--;
			}
			else
			{
				Arrowlocation = 4;
			}
		}
		else if (input == 's')
		{
			if (Arrowlocation < 4)
			{
				Arrowlocation++;
			}
			else
			{
				Arrowlocation = 1;
			}
		}
		else if (input == '\r')
		{
			break;
		}

		if (Arrowlocation == 1)
		{
			gotoxy(0, 1, ">", 1, 5);
		}
		else if (Arrowlocation == 2)
		{
			gotoxy(0, 2, ">", 1, 5);
		}
		else if (Arrowlocation == 3)
		{
			gotoxy(0, 3, ">", 1, 5);
		}
		else if (Arrowlocation == 4)
		{
			gotoxy(0, 4, ">", 1, 5);
		}
	}
	return Arrowlocation;
}

void creation_of_player()
{
	int Arrowlocation = 1;
	cout << "Which is your prefered element type? \n>Water \n Fire \n Earth \n Air " << endl;
	Arrowlocation = selectionforcc(Arrowlocation);
	ptr[10] = new Stats(Arrowlocation);
	ptr[10]->statisticsforplayer();
}

string Enemyusingskill(int attacking, int defender, float adv) //skill used for enemy
{
	bool go_on = false;
	string skillused;
	while (go_on == false)
	{
		bool priority = false;
		int abilitynum = 0;

		if ((ptr[attacking]->ElementalType == 1) && (ptr[attacking]->gethp() < ptr[attacking]->GetHalfHp())
			&& (priority == false) && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(3))
		{
			priority = true;
			abilitynum = 3;

		}
		else if ((ptr[attacking]->ElementalType == 2) && (ptr[attacking]->gethp() < ptr[attacking]->GetHalfHp())
			&& (priority == false) && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(3))
		{
			priority = true;
			abilitynum = 3;
		}
		else if ((ptr[attacking]->ElementalType == 3) && (ptr[attacking]->gethp() > ptr[attacking]->GetHalfHp())
			&& (priority == false))
		{
			priority = true;
			abilitynum = 3;
		}

		if (priority == false)
		{
			abilitynum = rand() % 2 + 1;;
		}

		int abilitynumber = abilitynum + ((ptr[attacking]->ElementalType - 1) * 3);

		if (ptr[attacking]->getmana() <= ptr[attacking]->abilitymanacost(1) && ptr[attacking]->getmana() <= ptr[attacking]->abilitymanacost(2) && ptr[attacking]->getmana() <= ptr[attacking]->abilitymanacost(3))
		{
			skillused = " Enemy did not have\n\n\t\t\t\tenough mana";
			go_on = true;
		}
		else if (abilitynumber == 1 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy used Water Slap";
			ptr[attacking]->setmana(20);
			ptr[defender]->sethp((ptr[attacking]->getatk() * 1.1f), ptr[defender]->getdef(), adv, attacking);
			go_on = true;
		}
		else if (abilitynumber == 2 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy used\n\n\t\t\t\tYellow liquid";
			ptr[attacking]->setmana(40);
			ptr[defender]->setdef(0.1f);
			ptr[defender]->sethp((ptr[attacking]->getatk() * 1.3f), ptr[defender]->getdef(), adv, attacking);
			go_on = true;
		}
		else if (abilitynumber == 3 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy used Meditate";
			ptr[attacking]->setmana(30);
			ptr[attacking]->recoverhp(1.30f, ptr[10]->getlevel());
			priority = false;
			go_on = true;
		}
		else if (abilitynumber == 4 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy used Volcano";
			ptr[attacking]->setmana(60);
			ptr[defender]->setdef(0.5);
			ptr[attacking]->setdef(-0.2f);
			go_on = true;
		}
		else if (abilitynumber == 5 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy use Fury";
			ptr[attacking]->setmana(10);
			ptr[defender]->sethp((ptr[attacking]->getatk() * 1.1f), ptr[defender]->getdef(), adv, attacking);
			go_on = true;
		}
		else if (abilitynumber == 6 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy used Revenge";
			ptr[attacking]->setmana(20);
			ptr[attacking]->setdef(-0.2f);
			ptr[defender]->sethp((ptr[attacking]->getatk() * 1.2f), ptr[defender]->getdef(), adv, attacking);
			go_on = true;
		}
		else if (abilitynumber == 7 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy use Quake";
			ptr[attacking]->setmana(20);
			ptr[defender]->sethp((ptr[attacking]->getatk() * 1.3f), ptr[defender]->getdef(), adv, attacking);
			go_on = true;
		}
		else if (abilitynumber == 8 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy used\n\n\t\t\t\tTectonic Smash";
			ptr[attacking]->setmana(60);
			ptr[defender]->sethp((ptr[attacking]->getatk() * 1.5f), ptr[defender]->getdef(), adv, attacking);
			ptr[attacking]->setdef(-0.2f);
			go_on = true;
		}
		else if (abilitynumber == 9 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy use Hardening";
			ptr[attacking]->setmana(50);
			ptr[attacking]->setdef(-0.3f);
			ptr[attacking]->recoverhp(1.20f, ptr[10]->getlevel());
			priority = false;
			go_on = true;
		}
		else if (abilitynumber == 10 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy use Gale Blade";
			ptr[attacking]->setmana(20);
			ptr[defender]->sethp((ptr[attacking]->getatk() * 1.2f), ptr[defender]->getdef(), adv, attacking);
			ptr[attacking]->recoverhp(1.05f, ptr[10]->getlevel());
			go_on = true;
		}
		else if (abilitynumber == 11 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy use Breeze";
			ptr[attacking]->setmana(20);
			ptr[attacking]->setatk(1.05f);
			ptr[attacking]->recoverhp(1.05f, ptr[10]->getlevel());
			go_on = true;
		}
		else if (abilitynumber == 12 && ptr[attacking]->getmana() > ptr[attacking]->abilitymanacost(abilitynum))
		{
			skillused = " Enemy use Hurricane";
			ptr[attacking]->setmana(30);
			ptr[defender]->sethp((ptr[attacking]->getatk() * 1.4f), ptr[defender]->getdef(), adv, attacking);
			priority = false;
			go_on = true;
		}
	}
	return skillused;
}

string usingskill(int abilitynumber, int defender, float adv) //determines the skill used by user
{
	string skillused;
	abilitynumber = abilitynumber + ((ptr[10]->ElementalType - 1) * 3);
	if (abilitynumber == 1)
	{
		skillused = " PIAK!\n| You used Water Slap";
		ptr[10]->setmana(20);
		ptr[defender]->sethp((ptr[10]->getatk() * 1.1f), ptr[defender]->getdef(), adv, 10);
	}
	else if (abilitynumber == 2)
	{
		skillused = " *Insert water\n| sounds* You used\n| Yellow liquid";
		ptr[10]->setmana(40);
		ptr[defender]->setdef(0.1f);
		ptr[defender]->sethp((ptr[10]->getatk() * 1.3f), ptr[defender]->getdef(), adv, 10);
	}
	else if (abilitynumber == 3)
	{
		skillused = " You use Meditate";
		ptr[10]->setmana(30);
		ptr[10]->recoverhp(1.30f, ptr[10]->getlevel());
	}
	else if (abilitynumber == 4)
	{
		skillused = " KABOOM!\n\n| You used Volcano";
		ptr[10]->setmana(60);
		ptr[defender]->setdef(0.5);
		ptr[10]->setdef(-0.2f);
	}
	else if (abilitynumber == 5)
	{
		skillused = " REEEEEEEE HAHAHA\n\n| You use Fury";
		ptr[10]->setmana(10);
		ptr[defender]->sethp((ptr[10]->getatk() * 1.1f), ptr[defender]->getdef(), adv, 10);
	}
	else if (abilitynumber == 6)
	{
		skillused = " Feeling satisfied?\n\n| You used Revenge";
		ptr[10]->setmana(30);
		ptr[10]->setdef(-0.2f);
		ptr[defender]->sethp((ptr[10]->getatk() * 1.2f), ptr[defender]->getdef(), adv, 10);
	}
	else if (abilitynumber == 7)
	{
		skillused = " You use Quake";
		ptr[10]->setmana(20);
		ptr[defender]->sethp((ptr[10]->getatk() * 1.3f), ptr[defender]->getdef(), adv, 10);
	}
	else if (abilitynumber == 8)
	{
		skillused = " You use\n\n| Tectonic Smash";
		ptr[10]->setmana(60);
		ptr[defender]->sethp((ptr[10]->getatk() * 1.5f), ptr[defender]->getdef(), adv, 10);
		ptr[10]->setdef(-0.2f);
	}
	else if (abilitynumber == 9)
	{
		skillused = " You use Hardening";
		ptr[10]->setmana(50);
		ptr[10]->setdef(-0.3f);
		ptr[10]->recoverhp(1.20f, ptr[10]->getlevel());
	}
	else if (abilitynumber == 10)
	{
		skillused = " You use Gale Blade";
		ptr[10]->setmana(20);
		ptr[defender]->sethp((ptr[10]->gethp() * 1.2f), ptr[defender]->getdef(), adv, 10);
		ptr[10]->recoverhp(1.05f, ptr[10]->getlevel());
	}
	else if (abilitynumber == 11)
	{
		skillused = " You use Breeze";
		ptr[10]->setmana(20);
		ptr[10]->setatk(1.05f);
		ptr[10]->recoverhp(1.10f, ptr[10]->getlevel());
	}
	else if (abilitynumber == 12)
	{
		skillused = " You use hurricane";
		ptr[10]->setmana(30);
		ptr[defender]->sethp((ptr[10]->getatk() * 1.4f), ptr[defender]->getdef(), adv, 10);
	}
	return skillused;
}

string usingskill2(string fourthskill, int defender, float adv)
{
	string skillused;
	if (fourthskill == "Flamey Sword")
	{
		skillused = " The heat of the sword compels you\n| You used flameing sword";
		ptr[10]->setmana(70);
		ptr[defender]->sethp((ptr[10]->getatk() * 2.1f), ptr[defender]->getdef(), adv, 10);
		ptr[defender]->setdef(0.05f);
	}
	else if (fourthskill == "Fireboom")
	{
		skillused = " Bigger kaboom\n| You used Fireboom";
		ptr[10]->setmana(100);
		ptr[defender]->sethp((ptr[10]->getatk() * 3.5f), ptr[defender]->getdef(), adv, 10);
	}
	else if (fourthskill == "Tsunami")
	{
		skillused = " Water, is unstoppable\n| You used Tsunami";
		ptr[10]->setmana(60);
		ptr[defender]->sethp((ptr[10]->getatk() * 2.2f), ptr[defender]->getdef(), adv, 10);
	}
	else if (fourthskill == "Flood")
	{
		skillused = "Water, is destructive\n| You used Flood";
		ptr[10]->setmana(20);
		ptr[defender]->sethp((ptr[10]->getatk() * 1.3f), ptr[defender]->getdef(), adv, 10);
	}
	else if (fourthskill == "Storm")
	{
		skillused = " The storm after the calm\n| You used Storm";
		ptr[10]->setmana(40);
		ptr[defender]->sethp((ptr[10]->getatk() * 1.7f), ptr[defender]->getdef(), adv, 10);
		ptr[10]->recoverhp(1.10f, ptr[10]->getlevel());
	}
	else if (fourthskill == "Thunderbolt")
	{
		skillused = " Zeus' Thunderbolt has been thrown\n| You used Thunderbolt";
		ptr[10]->setmana(60);
		ptr[defender]->sethp((ptr[10]->getatk() * 2), ptr[defender]->getdef(), adv, 10);
	}
	else if (fourthskill == "Thorns")
	{
		skillused = " Such a prick\n| You used Thorns";
		ptr[10]->setmana(20);
		ptr[defender]->sethp((ptr[10]->getatk() * 1.4f), ptr[defender]->getdef(), adv, 10);
	}
	else if (fourthskill == "Full defense")
	{
		skillused = " Harder than hard\n| You used Full Defense";
		ptr[10]->setmana(100);
		ptr[10]->setdef(-100);
	}
	return skillused;
}

void battlestart(int x, float adv, string fourthskill) //here is where the battle starts, duh
{
	HANDLE tcolor = GetStdHandle(STD_OUTPUT_HANDLE);
	if (x != 9)
	{
		ptr[x]->scalestats(ptr[10]->getlevel());
	}
	int enemyhp = int(ptr[x]->gethp());
	int yourhp = int(ptr[10]->gethp());

	if (x == 0)
	{
		ptr[x]->firstenemy();
	}
	while (enemyhp > 0)
	{
		gotoxys(0, 27);
		cout << "                            ";
		int selection = 1;
		int Arrowlocation = 1;
		gotoxys(0, 1);
		std::cout << R"(
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
________________________________________________________________
|                             |                                |
|                             |                                |
|  The                        |>Skills                         |
|                             |                                |
|  Has Appeared               | Stats                          |
|                             |                                |
|                             | Items                          |
|                             |                                |
|_____________________________|________________________________|)" << '\n';


		gotoxys(0, 1);
		cout << ptr[x]->getlooks();
		gotoxys(7, 20);
		if (x == 0)
		{
			cout << "Weakened ";
		}
		cout << gelementname[x] << " " << ptr[x]->getenemyname();

		selection = selectionforencounter(Arrowlocation);

		if (selection == 1) //for equipment, its 2 and for items, its 3
		{
			int enemyhp = int(ptr[x]->gethp());
			int yourhp = int(ptr[10]->gethp());

			Arrowlocation = 1;
			std::system("CLS");
			gotoxys(0, 1);
			cout << R"(
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
________________________________________________________________
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|_____________________________|________________________________|)" << "\n";
			gotoxys(0, 1);
			cout << ptr[x]->getlooks();

			gotoxys(49, 20);
			cout << "HP: " << ptr[10]->gethp() << "/" << ptr[10]->maxedhp();
			if (ptr[10]->gethp() < (ptr[10]->gethp() / 3))
			{
				cout << "!!! Low Health";
			}
			gotoxys(49, 22);
			cout << "Mana: " << ptr[10]->getmana() << "/" << ptr[10]->maxedmana();
			gotoxys(49, 24);
			cout << "Def: " << ptr[10]->getdef() << "/" << ptr[10]->maxeddef();

			string enemyskillused;
			string skillused;

			if (fourthskill == " ")
			{
				if (ptr[10]->getmana() > 20)
				{
					gotoxys(31, 19);
					ptr[10]->printoutskill();
					Arrowlocation = selectionforatk(Arrowlocation);
					skillused = usingskill(Arrowlocation, x, adv);
				}
				else
				{
					skillused = "You don't have enough mana";
				}
			}
			else if (fourthskill != " ")
			{
				if (ptr[10]->getmana() > 20)
				{
					gotoxys(31, 19);
					ptr[10]->printoutskill();
					gotoxys(32, 25);
					cout << fourthskill;
					Arrowlocation = selectionforatk2(Arrowlocation, fourthskill);
					if (Arrowlocation == 4)
					{
						skillused = usingskill2(fourthskill, x, adv);
					}
					else if (Arrowlocation != 4)
					{
						skillused = usingskill(Arrowlocation, x, adv);
					}
				}
				else
				{
					skillused = "You don't have enough mana";
				}
			}

			gotoxys(0, 1);
			cout << R"(
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
________________________________________________________________
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|_____________________________|________________________________|)" << "\n";
			gotoxys(0, 1);
			cout << ptr[x]->getlooks();

			gotoxys(1, 19);
			cout << skillused;



			int healthenemy = int(ptr[x]->gethp());
			if (ptr[x]->gethp() < 0)
			{
				healthenemy = 0;
			}

			gotoxys(2, 23);
			cout << "HP: " << ptr[10]->gethp() << "/" << ptr[10]->maxedhp();
			if (ptr[10]->gethp() < ptr[10]->gethp() / 3)
			{
				cout << "!!! Low Health";
			}
			gotoxys(2, 24);
			cout << "Mana: " << ptr[10]->getmana() << "/" << ptr[10]->maxedmana();
			gotoxys(2, 25);
			cout << "Def: " << ptr[10]->getdef() << "/" << ptr[10]->maxeddef();
			gotoxys(32, 23);
			cout << "HP: " << healthenemy;
			gotoxys(32, 24);
			cout << "Mana: " << ptr[x]->getmana();
			gotoxys(32, 25);
			cout << "Def: " << ptr[x]->getdef();

			gotoxys(0, 27);
			cout << "Your turn is now over, its the enemy's turn to attack";
			char VarName = _getch();
			gotoxys(0, 27);
			cout << "                                                     ";


			if (ptr[x]->gethp() > 0)
			{
				for (int i = 19; i < 26; i++)
				{
					gotoxys(1, i);
					cout << "                             ";
				}
				enemyskillused = Enemyusingskill(x, 10, adv);
				gotoxys(31, 19);
				cout << enemyskillused;


				int healthenemy = int(ptr[x]->gethp());
				if (ptr[x]->gethp() < 0)
				{
					healthenemy = 0;
				}

				gotoxys(2, 24);
				cout << "Mana: " << ptr[10]->getmana() << "/" << ptr[10]->maxedmana();
				gotoxys(2, 25);
				cout << "Def: " << ptr[10]->getdef() << "/" << ptr[10]->maxeddef();
				gotoxys(32, 23);
				cout << "HP: " << healthenemy;
				gotoxys(32, 24);
				cout << "Mana: " << ptr[x]->getmana();
				gotoxys(32, 25);
				cout << "Def: " << ptr[x]->getdef();

				yourhp = int(ptr[10]->gethp());
				if (yourhp <= 0)
				{
					gotoxys(2, 23);
					cout << "HP: 0" << "/" << ptr[10]->maxedhp();
					char VarName = _getch();
					break;
				}
				else
				{
					gotoxys(2, 23);
					cout << "HP: " << ptr[10]->gethp() << "/" << ptr[10]->maxedhp();
					if (ptr[10]->gethp() < ptr[10]->gethp() / 3)
					{
						cout << "!!! Low Health";
					}
				}
			}


			gotoxys(0, 27);
			cout << "Press any button to continue";
			VarName = _getch();
			ptr[10]->setmana(-10);
			ptr[x]->setmana(-10);

			if ((ptr[10]->gethp() > 0) && (healthenemy <= 0))
			{
				int blevel = ptr[10]->getlevel();
				int xpgained = ptr[10]->xpsystem(ptr[x]->getenemyname());
				ptr[10]->level(xpgained);
				int level = ptr[10]->getlevel();
				ptr[10]->restorestats(2, level);
				SetConsoleTextAttribute(tcolor, 7);
				cout << "\nYou got ";
				SetConsoleTextAttribute(tcolor, 11);
				cout << xpgained;
				SetConsoleTextAttribute(tcolor, 7);
				cout << " EXP";
				Shopping.addmoney();
				if (blevel < level)
				{
					cout << ". You leveled up! You are now ";
					SetConsoleTextAttribute(tcolor, 14);
					cout << ptr[10]->getlevel();
					SetConsoleTextAttribute(tcolor, 7);
					cout << " and will be healed by 50%";
					ptr[10]->recoverhp(1.5, level);
				}

				// Add carrot amount
				int random = (rand() % 51 + 150) + (20 * x);
				CarrotAmount = CarrotAmount + random;
				cout << "\nYou got ";
				SetConsoleTextAttribute(tcolor, 14);
				cout << random;
				SetConsoleTextAttribute(tcolor, 7);
				cout << " Carrots";
				cout << "\nYou have ";
				SetConsoleTextAttribute(tcolor, 14);
				cout << CarrotAmount;
				SetConsoleTextAttribute(tcolor, 7);
				cout << " Carrots in total";


				char VarName = _getch();
				break;
			}
		}
		else if (selection == 2)
		{
			gotoxys(0, 1);
			cout << R"(
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
................................................................
________________________________________________________________
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|_____________________________|________________________________|)" << "\n";
			gotoxys(0, 1);
			cout << ptr[x]->getlooks();


			gotoxys(2, 18);
			cout << "Your Stats";
			gotoxys(2, 21);
			cout << "Level: " << ptr[10]->getlevel() << ", " << ptr[10]->getelementname();
			gotoxys(2, 22);
			SetConsoleTextAttribute(tcolor, 12);
			cout << "HP: " << ptr[10]->gethp() << "/" << ptr[10]->maxedhp();
			if (ptr[10]->gethp() < (ptr[10]->gethp() / 3))
			{
				cout << "!!! Low Health";
			}
			SetConsoleTextAttribute(tcolor, 14);
			gotoxys(2, 23);
			cout << "Atk: " << ptr[10]->getatk();
			SetConsoleTextAttribute(tcolor, 3);
			gotoxys(2, 24);
			cout << "Mana: " << ptr[10]->getmana() << "/" << ptr[10]->maxedmana();
			SetConsoleTextAttribute(tcolor, 2);
			gotoxys(2, 25);
			cout << "Def: " << ptr[x]->getdef() << "/" << ptr[10]->maxeddef();
			SetConsoleTextAttribute(tcolor, 7);

			gotoxys(32, 18);
			cout << "Enemy Stats";
			gotoxys(32, 21);
			cout << "Element Type: " << ptr[x]->getelementname();
			SetConsoleTextAttribute(tcolor, 12);
			gotoxys(32, 22);
			cout << "HP: " << ptr[x]->gethp();
			SetConsoleTextAttribute(tcolor, 14);
			gotoxys(32, 23);
			cout << "Atk: " << ptr[x]->getatk();
			SetConsoleTextAttribute(tcolor, 3);
			gotoxys(32, 24);
			cout << "Mana: " << ptr[x]->getmana();
			SetConsoleTextAttribute(tcolor, 2);
			gotoxys(32, 25);
			cout << "Def: " << ptr[x]->getdef();
			SetConsoleTextAttribute(tcolor, 7);
			char VarName = _getch();
		}
		else if (selection == 3)
		{

			std::system("CLS");
			bool ChoosingItem = true;
			Arrowlocation = 1;
			cout << R"(
________________________________________________________________
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|                             |                                |
|_____________________________|________________________________|)" << "\n";

			bool SelectingItem = true;
			while (SelectingItem == true)
			{
				// Printing of Item Name and Amount
				gotoxys(32, 5);
				for (int i = 0; i < 9; i++)
				{
					cout << TheItemName[i] << ": " << ItemAmt[i] << "\n\n\t\t\t\t";
				}
				gotoxy2(32, 23, "Back");

				// Printing of Item Description
				if (Arrowlocation == 1)
				{
					gotoxy2(31, 5, ">");
					gotoxy2(3, 5, ItemDescription[0]);
				}
				else if (Arrowlocation == 2)
				{
					gotoxy2(31, 7, ">");
					gotoxy2(3, 5, ItemDescription[1]);
				}
				else if (Arrowlocation == 3)
				{
					gotoxy2(31, 9, ">");
					gotoxy2(3, 5, ItemDescription[2]);
				}
				else if (Arrowlocation == 4)
				{
					gotoxy2(31, 11, ">");
					gotoxy2(3, 5, ItemDescription[3]);
				}
				else if (Arrowlocation == 5)
				{
					gotoxy2(31, 13, ">");
					gotoxy2(3, 5, ItemDescription[4]);
				}
				else if (Arrowlocation == 6)
				{
					gotoxy2(31, 15, ">");
					gotoxy2(3, 5, ItemDescription[5]);
				}
				else if (Arrowlocation == 7)
				{
					gotoxy2(31, 17, ">");
					gotoxy2(3, 5, ItemDescription[6]);
				}
				else if (Arrowlocation == 8)
				{
					gotoxy2(31, 19, ">");
					gotoxy2(3, 5, ItemDescription[7]);
				}
				else if (Arrowlocation == 9)
				{
					gotoxy2(31, 21, ">");
					gotoxy2(3, 5, ItemDescription[8]);
				}
				else if (Arrowlocation == 10)
				{
					gotoxy2(31, 23, ">");
					gotoxy2(3, 5, "Go Back");
				}


				bool CanUseItem = true;
				if (Arrowlocation == 10)
				{
					CanUseItem = false;
				}
				else if (ItemAmt[Arrowlocation - 1] <= 0)
				{
					CanUseItem = false;
					gotoxy2(3, 15, "Cannot use this item\n|  as you do not have any");
				}
				else
				{
					gotoxy2(3, 15, "Press Enter to use\n|  this item.");
				}

				string UserInput;


				UserInput = _getch();

				if (UserInput == "w")
				{
					if (Arrowlocation > 1)
					{
						Arrowlocation--;

					}
					else
					{
						Arrowlocation = 10;
					}
				}

				else if (UserInput == "s")
				{
					Arrowlocation++;
					if (Arrowlocation == 11)
					{
						Arrowlocation = 1;
					}
				}

				if ((UserInput == "\r") && (CanUseItem == true))
				{
					for (int i = 3; i < 25; i++)
					{
						gotoxy2(1, i, "                            ");
						gotoxy2(31, i, "                             ");
					}
					if (Arrowlocation != 10)
					{
						ItemAmt[Arrowlocation - 1]--;
						gotoxy2(3, 5, "You have used");
						gotoxy2(3, 6, TheItemName[Arrowlocation - 1]);
						usingofitems(TheItemName[Arrowlocation - 1], x);
						gotoxy2(3, 7, "Press any keys to continue");
						string temp;
						temp = _getch();
						SelectingItem = false;
					}

				}

				if ((UserInput == "\r") && Arrowlocation == 10)
				{
					break;
				}

				for (int i = 3; i < 25; i++)
				{
					gotoxy2(1, i, "                            ");
					gotoxy2(31, i, "                             ");
				}

			}
			// Insert adding the stats to player here


		}
	}
}

void PrintMob(string MobType, int num)
{
	// 8 - 13 (y)   
	if (ptr[num]->gethp() > 0)
	{
		if (MobType == "Slime")
		{
			/*	 _______
				/       \
			   |  o  o   |
			   |   ~     |
				\_______/
			*/
			gotoxys(69, 8);
			cout << "_______";
			gotoxys(68, 9);
			cout << R"(/       \)";
			gotoxys(67, 10);
			cout << "|  o  o   |";
			gotoxys(67, 11);
			cout << "|   ~     |";
			gotoxys(68, 12);
			cout << R"(\_______/)";

		}
		else if (MobType == "Knight")
		{
			/*
			^
			|  0  _
			- \|/| |
			|  /\\_/

			*/
			gotoxys(67, 9);
			cout << "^";
			gotoxys(67, 10);
			cout << "|  0  _";
			gotoxys(67, 11);
			cout << R"(- \|/| |)";
			gotoxys(67, 12);
			cout << R"(|  /\\_/)";
		}
		else if (MobType == "Nymph")
		{
			/*
				M *
				O |
			   \|/|
				/\
			*/
			gotoxys(68, 9);
			cout << "M *";
			gotoxys(68, 10);
			cout << "O |";
			gotoxys(67, 11);
			cout << R"(\|/|)";
			gotoxys(68, 12);
			cout << R"(/\)";
		}
		else if (MobType == "Bird")
		{
			/*
   \\        //
   (o>      <o)
\\_//)      (\\_//
 \_/_)      (_\_/
  _|_)       _|_
			*/
			gotoxys(68, 8);
			cout << R"(//)";
			gotoxys(67, 9);
			cout << "<o)";
			gotoxys(67, 10);
			cout << R"((\\_//)";
			gotoxys(67, 11);
			cout << R"((_\_/)";
			gotoxys(68, 12);
			cout << "_|_";
		}
		else if (MobType == "Golem")
		{
			/*
	 ____
	/    \
	|o o |
	| _  |
	|____|
			*/
			gotoxys(68, 8);
			cout << "____";
			gotoxys(67, 9);
			cout << R"(/    \)";
			gotoxys(67, 10);
			cout << "|o o |";
			gotoxys(67, 11);
			cout << "| _  |";
			gotoxys(67, 12);
			cout << "|____|";
		}
		else if (MobType == "Goblin")
		{
			/*
			  ____
			^/    \^
			| 0  0 |
			| _<_  |
			| V_V  |
			 \____/
			*/

			gotoxys(69, 8);
			cout << "____";
			gotoxys(67, 9);
			cout << R"(^/    \^)";
			gotoxys(67, 10);
			cout << "| 0  0 |";
			gotoxys(67, 11);
			cout << "| _<_  |";
			gotoxys(67, 12);
			cout << "| V_V  |";
			gotoxys(68, 13);
			cout << R"(\____/)";
		}
		else if (MobType == "Djinn")
		{
			/*
 |_|_|  /\_/\
   |   < 0 0 >
   |    (v"v)
   |   /\   /\)
			*/

			gotoxys(67, 8);
			cout << R"(|_|_|  /\_/\)";
			gotoxys(69, 9);
			cout << "|   < 0 0 >";
			gotoxys(69, 10);
			cout << R"(|    (v"v))";
			gotoxys(69, 11);
			cout << R"(|   /\   /\)";
		}
	}
}

void usingofitems(string itemname, int x)
{
	if (itemname == "Small Hp Potion")
	{
		ptr[10]->recoverhp(1.20f, ptr[10]->getlevel());
	}
	else if (itemname == "Medium Hp Potion")
	{
		ptr[10]->recoverhp(1.50, ptr[10]->getlevel());
	}
	else if (itemname == "Large Hp Potion")
	{
		ptr[10]->recoverhp(2, ptr[10]->getlevel());
	}
	else if (itemname == "Tiny Mana Potion")
	{
		ptr[10]->recovermana(40);
	}
	else if (itemname == "Huge Mana Potion")
	{
		ptr[10]->recovermana(120);
	}
	else if (itemname == "Magical Bread")
	{
		ptr[10]->recoverhp(1.50, ptr[10]->getlevel());
		ptr[10]->recovermana(60);
	}
	else if (itemname == "Stun Bomb")
	{
		ptr[x]->setatk(0.5);
	}
	else if (itemname == "Sabo Bomb")
	{
		ptr[x]->setmana(ptr[x]->getmana());
	}
	else if (itemname == "Magical Rice")
	{
		ptr[10]->maxhp(ptr[10]->getlevel());
		ptr[10]->setmana(float(ptr[10]->maxedmana()));
	}
}

void FullScreen()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1920, 1080, TRUE); // 800 width, 100 height
}

void ChangeSize()
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX font = { sizeof(font) };
	GetCurrentConsoleFontEx(hConsoleOutput, false, &font);
	font.dwFontSize.X = 20;
	font.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(hConsoleOutput, false, &font);
}

void beeping(int oneortwo)
{
	if (oneortwo == 1)
	{
		Beep(350, 200);
		Beep(300, 300);
		Beep(400, 200);
		Beep(350, 150);
		Beep(300, 100);
	}
	else
	{
		Beep(500, 200);
		Beep(250, 300);
		Beep(450, 200);
		Beep(300, 150);
		Beep(300, 100);
	}
}

void printmob2(string mobname)
{
	if (mobname == "Slime")
	{
		/*	 _______
			/       \
		   |  o  o   |
		   |   ~     |
			\_______/
		*/
		gotoxys(5, 2);
		cout << "_______";
		gotoxys(4, 3);
		cout << R"(/       \)";
		gotoxys(3, 4);
		cout << "|  o  o   |";
		gotoxys(3, 5);
		cout << "|   ~     |";
		gotoxys(4, 6);
		cout << R"(\_______/)";

	}
	else if (mobname == "Knight")
	{
		/*
		^
		|  0  _
		- \|/| |
		|  /\\_/

		*/
		gotoxys(3, 2);
		cout << "^";
		gotoxys(3, 3);
		cout << "|  0  _";
		gotoxys(3, 4);
		cout << R"(- \|/| |)";
		gotoxys(3, 5);
		cout << R"(|  /\\_/)";
	}
	else if (mobname == "Nymph")
	{
		/*
			M *
			O |
		   \|/|
			/\
		*/
		gotoxys(4, 2);
		cout << "M *";
		gotoxys(4, 3);
		cout << "O |";
		gotoxys(3, 4);
		cout << R"(\|/|)";
		gotoxys(4, 5);
		cout << R"(/\)";
	}
	else if (mobname == "Bird")
	{
		/*
\\        //
(o>      <o)
\\_//)      (\\_//
 \_/_)      (_\_/
  _|_)       _|_
			*/
		gotoxys(4, 2);
		cout << R"(//)";
		gotoxys(3, 3);
		cout << "<o)";
		gotoxys(3, 4);
		cout << R"((\\_//)";
		gotoxys(3, 5);
		cout << R"((_\_/)";
		gotoxys(4, 6);
		cout << "_|_";
	}
	else if (mobname == "Golem")
	{
		/*
 ____
/    \
|o o |
| _  |
|____|
		*/
		gotoxys(4, 2);
		cout << "____";
		gotoxys(3, 3);
		cout << R"(/    \)";
		gotoxys(3, 4);
		cout << "|o o |";
		gotoxys(3, 5);
		cout << "| _  |";
		gotoxys(3, 6);
		cout << "|____|";
	}
	else if (mobname == "Goblin")
	{
		/*
		  ____
		^/    \^
		| 0  0 |
		| _<_  |
		| V_V  |
		 \____/
		*/

		gotoxys(5, 2);
		cout << "____";
		gotoxys(3, 3);
		cout << R"(^/    \^)";
		gotoxys(3, 4);
		cout << "| 0  0 |";
		gotoxys(3, 5);
		cout << "| _<_  |";
		gotoxys(3, 6);
		cout << "| V_V  |";
		gotoxys(4, 7);
		cout << R"(\____/)";
	}
	else if (mobname == "Djinn")
	{
		/*
|_|_|  /\_/\
  |   < 0 0 >
  |    (v"v)
  |   /\   /\)
		   */

		gotoxys(3, 2);
		cout << R"(|_|_|  /\_/\)";
		gotoxys(5, 3);
		cout << "|   < 0 0 >";
		gotoxys(5, 4);
		cout << R"(|    (v"v))";
		gotoxys(5, 5);
		cout << R"(|   /\   /\)";
	}
}

void interactions(int x)
{
	char ehefhqyf = _getch();
	if (x == 0)
	{
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Get out of my way";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		cout << R"(
 ___________________________________________________
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;
		printmob2(ptr[x]->getenemyname());
		gotoxys(24, 2);
		cout << "*Monster noises*";
		beeping(2);
		ehefhqyf = _getch();


	}
	else if (x == 1)
	{
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Another one???";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		cout << R"(
 ___________________________________________________
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;
		printmob2(ptr[x]->getenemyname());
		gotoxys(24, 2);
		cout << "...";
		ehefhqyf = _getch();
	}
	else if (x == 2)
	{
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Are you guys protecting\n\t\t\tthe boss?";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		cout << R"(
 ___________________________________________________
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;
		printmob2(ptr[x]->getenemyname());
		gotoxys(24, 2);
		cout << "*Refuses to answer*";
		ehefhqyf = _getch();
	}
	else if (x == 3)
	{
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Y'all are getting more\n\t\t\tannoying";
		beeping(1);
		ehefhqyf = _getch();
	}
	else if (x == 4)
	{
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Lets get this over with";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		cout << R"(
 ___________________________________________________
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;
		printmob2(ptr[x]->getenemyname());
		gotoxys(24, 2);
		cout << "???";
		ehefhqyf = _getch();
	}
	else if (x == 5)
	{
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(22, 2);
		cout << "How many more of\n\t\t\tyou are there?";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		cout << R"(
 ___________________________________________________
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;
		printmob2(ptr[x]->getenemyname());
		gotoxys(24, 2);
		cout << "... A few...";
		beeping(2);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Did u just...";
		beeping(1);
		ehefhqyf = _getch();
	}
	else if (x == 6)
	{
		std::cout << R"( 
___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(22, 2);
		cout << "Where's your leader";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		cout << R"(
 ___________________________________________________
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;
		printmob2(ptr[x]->getenemyname());
		gotoxys(24, 2);
		cout << "Close, closer\n\t\t\tthan you'd expect";
		beeping(2);
		ehefhqyf = _getch();
	}
}

void interactions2(int x)
{
	char ehefhqyf = _getch();
	if (x == 0)
	{
		system("CLS");
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "I warned you...";
		beeping(1);
		gotoxys(0, 0);
		cout << R"(
 ___________________________________________________
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;
		printmob2(ptr[x]->getenemyname());
		gotoxys(24, 2);
		cout << "*Dying Monster Noises*";
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Yeah he heard it just\n\t\t\tbuy something\n\t\t\tfrom me already";
		beeping(2);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Bruh, why are you\n\t\t\tfollowing me";
		beeping(1);
		gotoxys(0, 0);
		ehefhqyf = _getch();
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "My Business, none of yours";
		beeping(2);
		ehefhqyf = _getch();
	}
	else if (x == 1)
	{
		system("CLS");
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "That was painful";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "So you gonna buy something?";
		beeping(2);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Why are so impatient?";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Time is money\n\t\t\tUnless you can buy me time?";
		beeping(2);
		ehefhqyf = _getch();
	}
	else if (x == 2)
	{
		system("CLS");
		gotoxys(0, 0);
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "You know the drill";
		beeping(2);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Yeah Yeah Yeah";
		beeping(1);
		ehefhqyf = _getch();

	}
	else if (x == 3)
	{
		system("CLS");
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;
		gotoxys(24, 2);
		cout << "Why are your shop\n\t\t\tprices so expensive";
		beeping(2);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;
		gotoxys(24, 2);
		cout << ";)";
		beeping(1);
		ehefhqyf = _getch();
	}
	else if (x == 4)
	{
		system("CLS");
		gotoxys(0, 0);
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Hm? want something?";
		beeping(2);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "I want to fight you";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Wait h-how";
		beeping(2);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Just kidding";
		beeping(1);
		ehefhqyf = _getch();
	}
	else if (x == 5)
	{
		system("CLS");
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "How many more are\n\t\t\tthere";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "few...";
		beeping(2);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "How did u know";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Well you've beaten\n\t\t\tquite a few...";
		beeping(2);
		ehefhqyf = _getch();
	}
	else if (x == 6)
	{
		system("CLS");
		gotoxys(0, 0);
		cout << R"(
 ___________________________________________________
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;
		printmob2(ptr[x]->getenemyname());
		gotoxys(24, 2);
		cout << "So you've been helping\n\t\t\thim master...";
		beeping(2);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Master?";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Ah... ";
		beeping(2);
		cout << "So the cat is\n\t\t\tout of the bag\n\t\t\t";
		beeping(2);
		cout << "Meet me at my shop\n\t\t\tlike always\n\t\t\t";
		beeping(2);
		cout << "Everything shall be\n\t\t\texplained";
		ehefhqyf = _getch();
	}
	else if (x == 9)
	{
		system("CLS");
		gotoxys(0, 0);
		std::cout << R"( 
 ___________________________________________________
|Player:            |                               |
|                   |                               |
|       {\_/}       |                               |
|       (•.•)       |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "Give me back my princess";
		beeping(1);
		ehefhqyf = _getch();
		gotoxys(0, 0);
		std::cout << R"(
 ___________________________________________________
|Merchant:          |                               |
|       _   _       |                               |
|      / \_/ \      |                               |
|     |_(•.•)_|     |                               |
|       /^ ^\       |                               |
|                   |                               |
|___________________|_______________________________|)" << std::endl;

		gotoxys(24, 2);
		cout << "If you can beat me :)\n\t\t\t";
		beeping(2);
		cout << "You're gonna need it";
		beeping(1);
		ehefhqyf = _getch();
	}
}