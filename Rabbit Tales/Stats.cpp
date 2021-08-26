#include "Stats.h"

Stats::Stats()
{
}

Stats::Stats(int answerfromuser)
{
	ElementalType = answerfromuser;
	if (ElementalType == 1)
	{
		ElementalName = "Water";
	}
	else if (ElementalType == 2)
	{
		ElementalName = "Fire";
	}
	else if (ElementalType == 3)
	{
		ElementalName = "Earth";
	}
	else if (ElementalType == 4)
	{
		ElementalName = "Air";
	}
}

Stats::~Stats()
{
}

void Stats::creationofenemies()
{
	int typeofenemy = rand() % 7 + 1;
	if (typeofenemy == 1)
	{
		entityname = "Slime";
		health = 150;
		atk = 30;
		mana = 60;
		def = 1;
		entitylooks = R"(
................................................................
................................................................
................................................................
................................................................
......................._, -''''''''''''-,_
................... , ''      (.)    (.)    -
.................../ //                       \
...................|  ! !    |           |     | 
...................|  ! j    \___________/     |
................... |                         | 
.....................'i                   _ /
.......................`''- ________ ---'`)";
	}
	else if (typeofenemy == 2)
	{
		entityname = "Knight";
		health = 160;
		atk = 60;
		mana = 40;
		def = 1;
		entitylooks = R"(
....................../\
......................||
......................||..........||
......................||...........--
......................||........./----\
......................||.........|====|
......................||.........|`::`| 
....................._||_ ....-;`\..../`;-.
....................../\\.../  |'''::'''|  \
......................|:'\.|   /'''::'''\   |
.......................\ /\;-,/\   ::   /\--;
........................\ <` >..>'_::_'<,<__>
.........................`""`../   ^^   \|  |)";
	}
	else if (typeofenemy == 3)
	{
		entityname = "Nymph";
		health = 130;
		atk = 50;
		mana = 80;
		def = 1;
		entitylooks = R"(
.................__...... __......... .--.
................(  ""--__(  ""-_....,' ,-,\........*
................ "-_ __  ""--__ "-_(  (^_^))....../
....................(  """--___""--__" )-'(....../
....................."-__      ""---/ ,(., )__o-/,  
........................."""----___(.'.   /--"--'
...................................("-_"/(..../
....................................\   \ \
.....................................`.  \ |
.......................................\  \/
.......................................||  \
.....................................,-'/`  \
.....................................) /...) \
.....................................|/....`--\
..............................................`\)";
	}
	else if (typeofenemy == 4)
	{
		entityname = "Bird";
		health = 160;
		atk = 50;
		mana = 50;
		def = 1;
		entitylooks = R"(
...................................//,
..................................///i
................................,/ )''i
.................................|   )-i
.................................|   )i
.................................'   )i
................................/    |-
..........................._--/--  /z_ 
............................`-  >__\ _ );i
............................./ `-'/`k-'`u)-'`
............................/    )-
......................,----'   ) '
...................../      )1`
................... ///v`-v\v
.................../v)";
	}
	else if (typeofenemy == 5)
	{
		entityname = "Golem";
		health = 150;
		atk = 30;
		mana = 60;
		def = 2;
		entitylooks = R"(
.................................----.__
.............................../---.__  \
............................../       `\ |
.............................| o     o  \|
............................/| .vvvvv.  |\
........................../ /| |     |  | \
.........................//'.| `^vvvv'  |/\\
.........................~...|          |..\\
.............................|          |...~
.............................|          /
.............................|    n    |
............................-|_/\/ `--.|)";
	}
	else if (typeofenemy == 6)
	{
		entityname = "Goblin";
		health = 160;
		atk = 30;
		mana = 50;
		def = 1;
		entitylooks = R"(
...........................--""""-
........................../       \
......................__ /   ---  -\
...................../  `\  /   \/  \
.....................|  _ \/   -==-==-
.....................| (   \  /____\__\
......................\ \      (_()(_()
.......................\ \            '---__
........................\                   \_
...................../\ |`       (__)________/
................... /  \|     /\___/
...................|    \     \||VV
...................|     \     \|"""",
...................|      \     ______)
...................\       \  /`)";
	}
	else if (typeofenemy == 7)
	{
		entityname = "Djinn";
		health = 170;
		atk = 50;
		mana = 80;
		def = 1;
		entitylooks = R"(
................................................................
................................................................
................................................................
................................................................
......................,....,..../\.../\.
...................../( /\ )\.._\ \_/ /_
.....................|\_||_/|.< \_   _/ >
.....................\______/..\|0   0|/
......................._\/_..._(_  ^  _)_
......................( () )./`\|V"""V|/`\
........................{}...\  \_____/  /
........................().../\   )=(   /\
........................{}../  \_/\=/\_/  \)";
	}
}

void Stats::finalboss(int user)
{
	entityname = "Final Boss";
	health = 700;
	atk = 150;
	mana = 200;
	def = 20;

	entitylooks = R"(
................./'     |...|    \
................/    /  |...| \   \
............../    /.|  |...|  \   \
.............(   /...|  """"   |\   \
.............| /.../ /^\    /^\  \  _|
..............~...| |   |  |   | |.~
..................| |___|__|___| |
................/~~      \/     ~~\
.............../   (      |      )  \
........._--_../,   \____/^\___/'   \  _--_
......./~    ~\ / -____-|_|_|-____-\ /~    ~\__
______/________|___/~~~~\___/~~~~\ __|________\___________
.................|     |   |     |
.................`^-^-^'   `^-^-^')";

	if (user == 1)
	{
		ElementalType = 4;
		ElementalName = "Air";
	}
	else if (user == 2)
	{
		ElementalType = 1;
		ElementalName = "Water";
	}
	else if (user == 3)
	{
		ElementalType = 2;
		ElementalName = "Fire";
	}
	else
	{
		ElementalType = 3;
		ElementalName = "Earth";
	}
}

string Stats::getenemyname()
{
	return entityname;
}

void Stats::statisticsforplayer()
{
	health = 100;
	atk = 80;
	mana = 80;
	def = 5;
}

float Stats::gethp()
{
	return float(health);
}

float Stats::getatk()
{
	return float(atk);
}

float Stats::getmana()
{
	return float(mana);
}

float Stats::getdef()
{
	return float(def);
}

void Stats::sethp(float change, float defensive, float adv, int attacker)
{
	if (attacker != 10 && adv != 1)
	{
		if (adv == 0.5)
		{
			adv = 1.5;
		}
		if (adv == 1.5)
		{
			adv = 0.5;
		}
	}
	health = int(health - (change * ((100 - defensive) / 100)) * adv);
}

void Stats::recoverhp(float recover, int level)
{
	health = int(health + (100 * 1.2 * level) * (recover - 1));
	if (health > (100 * 1.2 * level))
	{
		health = int(100 * 1.2 * level);
	}
}

void Stats::recovermana(float recover)
{
	mana = int(mana + recover);
}

void Stats::setatk(float change)
{
	atk = int(atk * change);
}

void Stats::setmana(float change)
{
	mana = int(mana - change);
}

void Stats::setdef(float change)
{
	def = int(def - (def * change));
	if (def > 90)
	{
		def = 90;
	}
}

void Stats::restorestats(int change, int level)
{
	if (health * 2 < 100 * level * 1.2)
	{
		health = health + int(50 * level * 1.2);
	}
	else if (health * 2 > 100 * level * 1.2)
	{
		health = int(100 * level * 1.2);
	}

	mana = 70 + (10 * level);
	def = 3 + (2 * level);
	atk = int(80 * 1.2 * (level));
}

int Stats::xpsystem(string enemy)
{
	int xpgain = 0;

	if (enemy == "Slime")
	{
		xpgain = 100;
	}
	else if (enemy == "Knight")
	{
		xpgain = 200;
	}
	else if (enemy == "Golem")
	{
		xpgain = 200;
	}
	else if (enemy == "Nymph")
	{
		xpgain = 300;
	}
	else if (enemy == "Bird")
	{
		xpgain = 250;
	}
	else if (enemy == "Goblin")
	{
		xpgain = 100;
	}
	else if (enemy == "Djinn")
	{
		xpgain = 400;
	}

	return xpgain;
}

void Stats::level(int xp)
{
	totalxp = totalxp + xp;

	while (totalxp > yourlevel * 100)
	{
		yourlevel += 1;
		totalxp = totalxp - yourlevel * 100;
	}
}

int Stats::getlevel()
{
	return yourlevel;
}

string Stats::getlooks()
{
	return entitylooks;
}

void Stats::scalestats(int level)
{
	health = int(health * level * 1.2);
	def = def + (level * 1);
	mana = mana + (10 * level);
	atk = int(atk * (1.3 * level));
}

void Stats::maxhp(int level)
{
	health = int(100 * level * 1.2);
}

void Stats::firstenemy()
{
	atk = 2;
}

int Stats::GetHalfHp()
{
	return int(65 * yourlevel * 1.2);
}

int Stats::maxedhp()
{
	int maxhp = int(100 * yourlevel * 1.2);
	if (yourlevel == 1)
	{
		maxhp = 100;
	}
	return maxhp;
}

int Stats::maxeddef()
{
	int maxdef = 3 + (yourlevel * 2);
	if (yourlevel == 1)
	{
		maxdef = 5;
	}
	return maxdef;
}

int Stats::maxedatk()
{
	int maxatk = int(80 * (1.3 * yourlevel));
	return maxatk;
}

int Stats::maxedmana()
{
	int maxmana = 80 + (10 * yourlevel);
	if (yourlevel == 1)
	{
		maxmana = 80;
	}
	return maxmana;
}

int Stats::getmoney()
{
	return money;
}

void Stats::addmoney() //leftover code
{
	money = money + 1;
}