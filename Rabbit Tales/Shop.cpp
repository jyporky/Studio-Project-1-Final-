#include "Shop.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <thread>

using namespace std;

Shop::Shop()
{
	CarrotAmount = 0;
	for (int i = 0; i < 9; i++)
	{
		ItemAmt[i] = 0;
	}

}

Shop::~Shop()
{

}

void Shop::TheShop(bool& SkillsBought, std::string ElementalType, int& CarrotAmt, std::string& Inv,
	int ItemAmount[9], std::string TheItemName[9], bool EnterShopYet)
{
	CarrotAmount = CarrotAmt;
	Inventory = Inv;
	for (int i = 0; i < 9; i++)
	{
		ItemAmt[i] = ItemAmount[i];
		TheItemNames[i] = TheItemName[i];
	}
	ElementType = ElementalType;

	bool InShop = true;
	// FIrst visit to the Item and Skill shop for this current shop
	bool EnteredShop = EnterShopYet;
	bool FirstSkill;
	// If User bought skill before, Skill will not be purchasable
	if (SkillsBought == true)
	{
		FirstSkill = true;
	}
	else
	{
		FirstSkill = false;
	}
	std::string ItemDescription[5] = { " ", " ", " ", " ", " " };
	std::string ItemName[5] = { " ", " "," "," "," " };
	std::string SkillName[2] = { "Sold Out", "Sold Out" };
	std::string SkillDescription[2] = { " ", " " };
	int SkillPrice[2] = { 0,0 };
	// To create animation value
	int HeadMoving = 1;

	// Print out the rabbit and the base
	PrintHead();
	PrintBottom();

	// Print out the Inv First
	Inv = PrintInventory(Inv);
	gotoxy(0, 29, "Inventory: ");
	gotoxy(0, 30, Inv);
	// The Main While loop for the Shop program
	while (InShop == true)
	{
		// Bunch of variables
		bool ValidOption = false;
		std::string WhatOption;
		std::string OptionType;
		std::string BuyingWhat;
		int CurrentArrow = 1;

		// Print out the text
		gotoxy(16, 15, "Welcome to the Shop!");
		gotoxy(11, 16, "Please feel free to look around!");
		gotoxy(0, 18, "What would you like to buy?");
		gotoxy(0, 19, "-----------------------------------------------------------");
		gotoxy(2, 21, "Skill");
		gotoxy(2, 22, "Items");
		gotoxy(2, 23, "Gacha");
		gotoxy(2, 24, "Exit");


		gotoxy(0, 34, "Use the w,a,s,d key to move the arrow. Press Enter to select");
		// A while loop for the Interacting of Shop
		while (ValidOption == false)
		{
			// Check where CurrentArrow is and print the arrow accordingly
			if (CurrentArrow == 1)
			{
				gotoxy(0, 21, ">");
			}
			else if (CurrentArrow == 2)
			{
				gotoxy(0, 22, ">");
			}
			else if (CurrentArrow == 3)
			{
				gotoxy(0, 23, ">");
			}
			else if (CurrentArrow == 4)
			{
				gotoxy(0, 24, ">");
			}

			// This is to "animate" the shopkeeper
			MoveHead(HeadMoving);
			// Wait for user to key in any keys
			WhatOption = _getch();

			// Check for what user key in and do the checking below
			if ((WhatOption == "w") && ((CurrentArrow - 1) != 0))
			{
				gotoxy(0, 20 + CurrentArrow, " ");
				CurrentArrow--;
			}

			else if ((WhatOption == "s") && ((CurrentArrow + 1 != 5)))
			{
				gotoxy(0, 20 + CurrentArrow, " ");
				CurrentArrow++;
			}

			else if (WhatOption == "\r")
			{
				ValidOption = true;
				for (int i = 15; i < 25; i++)
				{
					gotoxy(0, i, "                                                          ");
				}
			}
		}
		// Print out the Shop Interface
		std::string YourCarrots = "Your Carrots: " + std::to_string(CarrotAmount);

		gotoxy(35, 15, YourCarrots);
		gotoxy(0, 16, "-----------------------------------------------------------");

		// If User select Skill Shop, enter skill shop
		if (CurrentArrow == 1)
		{
			// Enter the Skill Shop
			gotoxy(0, 15, "Skill Shop ");
			// Fire skill: Flamey Sword, Fireboom
			// Water skill: Tsunami, Flood
			// Air skill: Storm, Thunder bolt
			// Earth skill: Thorns, Full defense

			// If User enter Skill Shop first time for this shop and user has yet to get a purchasable skill
			if (FirstSkill == false)
			{
				// This will run this time, but will not run anymore for this shop.
				FirstSkill = true;
				// Set the Shop accordingly
				if (ElementType == "Fire")
				{
					SkillName[0] = "Flamey Sword";
					SkillDescription[0] = "Mana Cost: 70 \n Deals 210% Fire Damage to an enemy\n and decrease"
						" their defense by 5% for the rest of the game \n Sword be burning  Cost: 300C";
					SkillPrice[0] = 300;
					SkillName[1] = "Fireboom";
					SkillDescription[1] = "Mana Cost: 100 \n Place a mine on the enemy that explodes \n"
						" , dealing 350% fire damage \n Explode in Fire  Cost: 700C";
					SkillPrice[1] = 700;
				}

				else if (ElementType == "Water")
				{
					SkillName[0] = "Tsunami";
					SkillDescription[0] = "Mana Cost: 60 \n Deals 220% Water Damage to an enemy \n"
						"Peace is never an option \n Cost: 400C";
					SkillPrice[0] = 400;
					SkillName[1] = "Flood";
					SkillDescription[1] = "Mana Cost: 20 \n Deals 130% Water Damage to an enemy \n"
						"U become the sea \n Cost: 160C";
					SkillPrice[1] = 160;
				}

				else if (ElementType == "Air")
				{
					SkillName[0] = "Storm";
					SkillDescription[0] = "Mana Cost: 40 \n Deals 170% Air Damage to an enemy \n"
						"(recover 10% hp) You will never sleep \n Cost : 400C";
					SkillPrice[0] = 400;
					SkillName[1] = "Thunderbolt";
					SkillDescription[1] = "Mana Cost: 60 \n Deals 200% Air Damage to an enemy \n"
						"AND THEN IT ALL CAME ZEUS! HE HURLED HIS THUNDERBOLT \n Cost: 300C";
					SkillPrice[1] = 300;
				}

				else if (ElementType == "Earth")
				{
					SkillName[0] = "Thorns";
					SkillDescription[0] = "Strangle an enemy and deal 140% Earth Damage \n"
						"You become cactus \n Cost: 100C";
					SkillPrice[0] = 100;
					SkillName[1] = "Full defense";
					SkillDescription[1] = "Become Immune to damage for this turn \n"
						"When HARDENING is not enough *Insert Lenny Face* \n Cost: 650C";
					SkillPrice[1] = 650;
				}
			}




			bool ValidSkill = false;
			CurrentArrow = 1;
			while (ValidSkill == false)
			{
				gotoxy(2, 18, SkillName[0]);
				gotoxy(22, 18, SkillName[1]);
				gotoxy(42, 18, "Exit");
				if (CurrentArrow == 1)
				{
					gotoxy(0, 18, ">");
					gotoxy(0, 22, SkillDescription[0]);
				}
				else if (CurrentArrow == 2)
				{
					gotoxy(20, 18, ">");
					gotoxy(0, 22, SkillDescription[1]);
				}

				else if (CurrentArrow == 3)
				{
					gotoxy(40, 18, ">");
					gotoxy(0, 22, "Go Back?");

				}

				bool CanBuy = true;
				if (CurrentArrow != 3)
				{
					if (CarrotAmount < SkillPrice[CurrentArrow - 1])
					{
						gotoxy(0, 26, "Insufficient carrot!, unable to purchase this item", 4);
						CanBuy = false;
					}
					else if (SkillPrice[CurrentArrow - 1] == 0)
					{
						gotoxy(0, 26, "You have already purchased a skill.", 4);
						CanBuy = false;
					}
				}
				else if (CurrentArrow == 3)
				{
					CanBuy = false;
				}


				MoveHead(HeadMoving);
				BuyingWhat = _getch();
				bool PurchaseMenu = false;

				if ((BuyingWhat == "a") && (CurrentArrow != 1))
				{
					gotoxy(20 * (CurrentArrow - 1), 18, " ");
					CurrentArrow--;
				}
				else if ((BuyingWhat == "d") && (CurrentArrow != 3))
				{
					gotoxy(20 * (CurrentArrow - 1), 18, " ");
					CurrentArrow++;
				}

				else if ((BuyingWhat == "\r") && (CanBuy == true))
				{
					PurchaseMenu = true;
				}

				else if ((BuyingWhat == "\r") && (CurrentArrow == 3))
				{
					ValidSkill = true;
				}

				int ThisArrow = 1;
				if (PurchaseMenu == true)
				{
					for (int i = 16; i < 28; i++)
					{
						gotoxy(0, i, "                                                          ");
					}
					std::string TheString = "You are about to purchase " + SkillName[CurrentArrow - 1] +
						" for " + std::to_string(SkillPrice[CurrentArrow - 1]) + "C";
					gotoxy(0, 18, TheString);
					gotoxy(0, 19, "Are you Sure?");
					gotoxy(2, 21, "Yes");
					gotoxy(2, 22, "No");

					bool GotInput = false;
					while (GotInput == false)
					{
						MoveHead(HeadMoving);
						if (ThisArrow == 1)
						{
							gotoxy(0, 21, ">");
							gotoxy(0, 22, " ");
						}
						else if (ThisArrow == 2)
						{
							gotoxy(0, 22, ">");
							gotoxy(0, 21, " ");
						}

						BuyingWhat = _getch();
						if ((BuyingWhat == "w") && (ThisArrow == 2))
						{
							ThisArrow--;
						}
						else if ((BuyingWhat == "s") && (ThisArrow == 1))
						{
							ThisArrow++;
						}

						else if (BuyingWhat == "\r")
						{
							if (ThisArrow == 1)
							{
								for (int i = 15; i < 23; i++)
								{
									gotoxy(0, i, "                                                          ");
								}
								CarrotAmount = CarrotAmount - SkillPrice[CurrentArrow - 1];
								gotoxy(0, 15, "Item Shop ");
								YourCarrots = "Your Carrots: " + std::to_string(CarrotAmount);
								gotoxy(35, 15, YourCarrots);
								TheString = "You have purchased " + SkillName[CurrentArrow - 1];
								fourthskill = SkillName[CurrentArrow - 1];
								// Insert getting the item code here



								SkillPrice[0] = 0; SkillPrice[1] = 0;
								SkillName[0] = "Sold Out"; SkillName[1] = "Sold Out";
								SkillDescription[0] = " "; SkillDescription[1] = " ";
								gotoxy(0, 18, TheString);
								// Press any key to continue
								gotoxy(0, 19, "Press any key to continue");
								Beep(500, 40);
								Beep(700, 60);
								Beep(1000, 50);
								TheString = _getch();
								SkillsBought = true;
								ValidSkill = true;
							}
							GotInput = true;
							for (int i = 16; i < 29; i++)
							{
								gotoxy(0, i, "                                                          ");
							}
						}
					}
				}

				for (int i = 18; i < 29; i++)
				{
					gotoxy(0, i, "                                                          ");

				}


			}
		}

		else if (CurrentArrow == 2)
		{
			if (EnteredShop == false)
			{
				for (int i = 0; i < 5; i++)
				{
					ShopItems[i] = rand() % 9 + 1;
				}
				EnteredShop = true;
			}

			bool InItemShop = true;
			while (InItemShop == true)
			{
				// Enter the Item Shop
				gotoxy(0, 15, "Items Shop ");

				for (int i = 0; i < 5; i++)
				{
					if (ShopItems[i] == 1)
					{
						// Small Hp pot
						ItemPrice[i] = 80;
						ItemName[i] = "Small Hp Potion";
						ItemDescription[i] = "Small Hp Potion\n Heal 20% Hp\n "
							"The Most basic potion use to heal small wounds \n Cost: 80C";
					}

					else if (ShopItems[i] == 2)
					{
						// Medium Hp pot
						ItemPrice[i] = 150;
						ItemName[i] = "Medium Hp Potion";
						ItemDescription[i] = "Medium Hp Potion\n Heal 50% Hp\n "
							"A better potion use to heal some big wounds\n Cost: 150C";
					}

					else if (ShopItems[i] == 3)
					{
						// Large Hp pot
						ItemPrice[i] = 240;
						ItemName[i] = "Large Hp Potion";
						ItemDescription[i] = "Large Hp Potion\n Heal 100% Hp\n "
							"A potion used to treat very serious injuries\n Cost: 240C";
					}

					else if (ShopItems[i] == 4)
					{
						// Small mana pot
						ItemPrice[i] = 80;
						ItemName[i] = "Tiny Mana Potion";
						ItemDescription[i] = "Tiny Mana Potion\n Restore 40 mana\n "
							"A potion to get some point of mana\n Cost: 80C";
					}

					else if (ShopItems[i] == 5)
					{
						// Large mana pot
						ItemPrice[i] = 200;
						ItemName[i] = "Huge Mana Potion";
						ItemDescription[i] = "Huge Mana Potion\n Restore 120 mana\n "
							"A potion to get a good number of mana\n Cost: 200C";
					}

					else if (ShopItems[i] == 6)
					{
						// Magical Bread
						ItemPrice[i] = 200;
						ItemName[i] = "Magical Bread";
						ItemDescription[i] = "Magical Bread\n Heal 50% Hp and restore 60 mana\n "
							"Juicy delicious bread that every skill caster wants\n Cost: 200C";
					}

					else if (ShopItems[i] == 7)
					{
						// Stun Bomb
						ItemPrice[i] = 200;
						ItemName[i] = "Stun Bomb";
						ItemDescription[i] = "Stun Bomb\n Reduces opponenet attack by 50%\n Cost: 200C";
					}

					else if (ShopItems[i] == 8)
					{
						// Sabo Bomb
						ItemPrice[i] = 260;
						ItemName[i] = "Sabo Bomb";
						ItemDescription[i] = "Sabo Bomb\n Drain Out all of Opponent's mana\n "
							"If you buy and use this item, well done. You cheated!\n Cost: 260C";
					}

					else if (ShopItems[i] == 9)
					{
						// Magical Rice
						ItemPrice[i] = 300;
						ItemName[i] = "Magical Rice";
						ItemDescription[i] = "Magical Rice\n Restore Hp and mana to Max\n "
							" A Singapore style dish. 500 years of cultivation have\n run into the rice,"
							"it fills you with determination\n Cost: 300C";
					}

					else if (ShopItems[i] == 0)
					{
						// Sold Out
						ItemPrice[i] = 0;
						ItemName[i] = "Sold Out";
						ItemDescription[i] = "Sold Out!";
					}

				}

				bool ValidBuy = false;
				CurrentArrow = 1;
				while (ValidBuy == false)
				{
					gotoxy(2, 18, ItemName[0]); gotoxy(22, 18, ItemName[1]); gotoxy(42, 18, ItemName[2]);
					gotoxy(2, 20, ItemName[3]); gotoxy(22, 20, ItemName[4]); gotoxy(42, 20, "Back");
					if (CurrentArrow == 1)
					{
						gotoxy(0, 18, ">");
						gotoxy(0, 22, ItemDescription[0]);
					}
					else if (CurrentArrow == 2)
					{
						gotoxy(20, 18, ">");
						gotoxy(0, 22, ItemDescription[1]);
					}
					else if (CurrentArrow == 3)
					{
						gotoxy(40, 18, ">");
						gotoxy(0, 22, ItemDescription[2]);
					}
					else if (CurrentArrow == 4)
					{
						gotoxy(0, 20, ">");
						gotoxy(0, 22, ItemDescription[3]);
					}
					else if (CurrentArrow == 5)
					{
						gotoxy(20, 20, ">");
						gotoxy(0, 22, ItemDescription[4]);
					}
					else if (CurrentArrow == 6)
					{
						gotoxy(40, 20, ">");
						gotoxy(0, 22, "Go Back?");
					}

					bool CanBuy = true;
					if (CurrentArrow != 6)
					{
						if (CarrotAmount < ItemPrice[CurrentArrow - 1])
						{
							gotoxy(0, 28, "~Insufficient Carrots, unable to purchase this item.", 4);
							CanBuy = false;
						}
						else if (ItemPrice[CurrentArrow - 1] == 0)
						{
							CanBuy = false;
						}
					}
					else if (CurrentArrow == 6)
					{
						CanBuy = false;
					}

					MoveHead(HeadMoving);
					bool PurchaseMenu = false;
					BuyingWhat = _getch();
					if ((BuyingWhat == "w") && (CurrentArrow >= 4))
					{
						gotoxy(20 * (CurrentArrow - 4), 20, " ");
						CurrentArrow = CurrentArrow - 3;
					}
					else if ((BuyingWhat == "s") && (CurrentArrow <= 3))
					{
						gotoxy(20 * (CurrentArrow - 1), 18, " ");
						CurrentArrow = CurrentArrow + 3;
					}
					else if ((BuyingWhat == "a") && (CurrentArrow != 1) && (CurrentArrow != 4))
					{
						if ((CurrentArrow == 2) || (CurrentArrow == 3))
						{
							gotoxy(20 * (CurrentArrow - 1), 18, " ");
						}
						else if ((CurrentArrow == 5) || (CurrentArrow == 6))
						{
							gotoxy(20 * (CurrentArrow - 4), 20, " ");
						}
						CurrentArrow--;
					}
					else if ((BuyingWhat == "d") && (CurrentArrow != 3) && (CurrentArrow != 6))
					{
						if ((CurrentArrow == 1) || (CurrentArrow == 2))
						{
							gotoxy(20 * (CurrentArrow - 1), 18, " ");
						}
						else if ((CurrentArrow == 4) || (CurrentArrow == 5))
						{
							gotoxy(20 * (CurrentArrow - 4), 20, " ");
						}
						CurrentArrow++;
					}

					else if ((BuyingWhat == "\r") && (CurrentArrow == 6))
					{
						ValidBuy = true;
						InItemShop = false;
					}


					else if ((BuyingWhat == "\r") && (CanBuy == true))
					{
						PurchaseMenu = true;
					}

					for (int i = 22; i < 29; i++)
					{
						gotoxy(0, i, "                                                          ");

					}


					int ThisArrow = 1;
					if (PurchaseMenu == true)
					{
						ThisArrow = 1;
						for (int i = 16; i < 22; i++)
						{
							gotoxy(0, i, "                                                          ");
						}
						std::string TheString = "You are about to purchase " + ItemName[CurrentArrow - 1] +
							" for " + std::to_string(ItemPrice[CurrentArrow - 1]) + "C";
						gotoxy(0, 18, TheString);
						gotoxy(0, 19, "Are you Sure?");
						gotoxy(2, 21, "Yes");
						gotoxy(2, 22, "No");

						bool GotInput = false;
						while (GotInput == false)
						{
							MoveHead(HeadMoving);
							if (ThisArrow == 1)
							{
								gotoxy(0, 21, ">");
								gotoxy(0, 22, " ");
							}
							else if (ThisArrow == 2)
							{
								gotoxy(0, 22, ">");
								gotoxy(0, 21, " ");
							}

							BuyingWhat = _getch();
							if ((BuyingWhat == "w") && (ThisArrow == 2))
							{
								ThisArrow--;
							}
							else if ((BuyingWhat == "s") && (ThisArrow == 1))
							{
								ThisArrow++;
							}

							else if (BuyingWhat == "\r")
							{
								if (ThisArrow == 1)
								{
									for (int i = 15; i < 34; i++)
									{
										gotoxy(0, i, "                                                                   ");
									}
									CarrotAmount = CarrotAmount - ItemPrice[CurrentArrow - 1];
									gotoxy(0, 15, "Skill Shop ");
									YourCarrots = "Your Carrots: " + std::to_string(CarrotAmount);
									gotoxy(35, 15, YourCarrots);
									TheString = "You have purchased " + ItemName[CurrentArrow - 1];
									// Insert getting the item code here


									for (int i = 0; i < 9; i++)
									{
										if (ItemName[CurrentArrow - 1] == TheItemName[i])
										{
											ItemAmt[i]++;
											Inv = "";
											Inv = PrintInventory(Inv);
											gotoxy(0, 29, "Inv: ");
											gotoxy(0, 30, Inv);
											break;
										}
									}


									ShopItems[CurrentArrow - 1] = 0;
									gotoxy(0, 18, TheString);
									// Press any key to continue
									gotoxy(0, 19, "Press any key to continue");
									Beep(500, 40);
									Beep(700, 60);
									Beep(1000, 50);
									TheString = _getch();
									ValidBuy = true;
								}
								GotInput = true;
								for (int i = 16; i < 29; i++)
								{
									gotoxy(0, i, "                                                          ");
								}

							}
						}


					}



				}



			}
		}

		else if (CurrentArrow == 3)
		{
			char goagain = 'y';
			string userinput;
			int choice = 1;



			while (goagain == 'y' || goagain == 'Y')
			{
				for (int i = 21; i < 25; i++)
				{
					gotoxy(0, i, "                         ");
				}
				gotoxy(0, 16, "");
				std::cout << "\nyou have " << money << " coins" << endl;
				std::cout << "how many box would you like to open 1 or 3?" << endl;
				gotoxy(2, 19, "1");
				gotoxy(2, 20, "3");
				if (choice == 1)
				{
					gotoxy(0, 19, ">");
				}
				userinput = _getch();
				if (userinput == "w")
				{
					choice = 1;
					gotoxy(0, 19, ">");
					gotoxy(0, 20, " ");
				}
				else if (userinput == "s")
				{
					choice = 2;
					gotoxy(0, 20, ">");
					gotoxy(0, 19, " ");
				}

				if (userinput == "\r")
				{
					gotoxy(0, 21);
					if (choice == 1)
					{
						if (money >= 1)
						{
							srand((unsigned)time(NULL));

							int ranum = (rand() % 1240) + 1;

							//std::cout << (ranum) << endl;

							if (ranum < 20)
							{
								int Exrare = (rand() % 2) + 1;
								switch (Exrare)
								{
								case 1:
									std::cout << ("Diamond 1") << endl;
									break;
								case 2:
									std::cout << ("Diamond 2") << endl;
									break;
								}
								cosmetics = "diamond";
							}

							if (ranum > 20 && ranum < 60)
							{
								int Vrare = (rand() % 3) + 1;
								switch (Vrare)
								{
								case 1:
									std::cout << ("Platinum 1") << endl;
									break;
								case 2:
									std::cout << ("Platinum 2") << endl;
									break;
								case 3:
									std::cout << ("Platinum 3") << endl;
									break;
								}

								cosmetics = "platinum";
							}

							if (ranum > 60 && ranum < 140)
							{
								int rare = (rand() % 3) + 1;
								switch (rare)
								{
								case 1:
									std::cout << ("gold 1") << endl;
									break;
								case 2:
									std::cout << ("gold 2") << endl;
									break;
								case 3:
									std::cout << ("gold 3") << endl;
									break;
								}

								cosmetics = "gold";
							}

							if (ranum > 140 && ranum < 300)
							{
								int uncommon = (rand() % 6) + 1;
								switch (uncommon)
								{
								case 1:
									std::cout << ("silver 1") << endl;
									break;
								case 2:
									std::cout << ("silver 2") << endl;
									break;
								case 3:
									std::cout << ("silver 3") << endl;
									break;
								case 4:
									std::cout << ("silver 4") << endl;
									break;
								case 5:
									std::cout << ("silver 5") << endl;
									break;
								case 6:
									std::cout << ("silver 6") << endl;
									break;
								}
								cosmetics = "silver";
							}

							if (ranum > 300 && ranum < 620)
							{
								int common = (rand() % 7) + 1;
								switch (common)
								{
								case 1:
									std::cout << ("bronze 1") << endl;
									break;
								case 2:
									std::cout << ("bronze 2") << endl;
									break;
								case 3:
									std::cout << ("bronze 3") << endl;
									break;
								case 4:
									std::cout << ("bronze 4") << endl;
									break;
								case 5:
									std::cout << ("bronze 5") << endl;
									break;
								case 6:
									std::cout << ("bronze 6") << endl;
									break;
								case 7:
									std::cout << ("bronze 7") << endl;
									break;
								}

								cosmetics = "bronze";
							}

							if (ranum > 620 && ranum < 1260)
							{
								int common = (rand() % 7) + 1;
								switch (common)
								{
								case 1:
									std::cout << ("bronze 1") << endl;
									break;
								case 2:
									std::cout << ("bronze 2") << endl;
									break;
								case 3:
									std::cout << ("bronze 3") << endl;
									break;
								case 4:
									std::cout << ("bronze 4") << endl;
									break;
								case 5:
									std::cout << ("bronze 5") << endl;
									break;
								case 6:
									std::cout << ("bronze 6") << endl;
									break;
								case 7:
									std::cout << ("bronze 7") << endl;
									break;
								}

								cosmetics = "bronze";
							}

							std::cout << "Would u like to go again?" << endl;
							std::cout << "> Yes" << endl;;
							std::cout << "  No";

							char inputuser = _getch();
							int choice2 = 1;
							inputuser = 'd';
							while (inputuser != '\r')
							{
								if (inputuser == 'w')
								{
									choice2 = 1;
									gotoxy(0, 23, ">");
									gotoxy(0, 24, " ");
								}
								else if (inputuser == 's')
								{
									choice2 = 2;
									gotoxy(0, 24, ">");
									gotoxy(0, 23, " ");
								}
								inputuser = _getch();
							}
							money = money - 1;
							if (choice2 == 1)
							{
								goagain = 'y';
								userinput = "d";
							}
							else if (choice2 == 2)
							{
								goagain = 'n';
								break;
							}
						}


						else if (money < 1)
						{
							std::cout << "You will need more money" << endl;
							char inputlol = _getch();
							goagain = 'n';
							break;
						}
					}

					if (choice == 2)
					{
						if (money >= 3)
						{

							srand((unsigned)time(NULL));

							int ranum1 = (rand() % 1240) + 1;
							int ranum2 = (rand() % 1240) + 1;
							int ranum3 = (rand() % 1240) + 1;

							//std::cout << (ranum1) << endl;

							if (ranum1 < 20)
							{
								int Exrare = (rand() % 2) + 1;
								switch (Exrare)
								{
								case 1:
									std::cout << ("Diamond 1") << endl;
									break;
								case 2:
									std::cout << ("Diamond 2") << endl;
									break;
								}
								cosmetics = "diamond";
							}

							if (ranum1 > 20 && ranum1 < 60)
							{
								int Vrare = (rand() % 3) + 1;
								switch (Vrare)
								{
								case 1:
									std::cout << ("Platinum 1") << endl;
									break;
								case 2:
									std::cout << ("Platinum 2") << endl;
									break;
								case 3:
									std::cout << ("Platinum 3") << endl;
									break;
								}

								cosmetics = "platinum";
							}

							if (ranum1 > 60 && ranum1 < 140)
							{
								int rare = (rand() % 3) + 1;
								switch (rare)
								{
								case 1:
									std::cout << ("gold 1") << endl;
									break;
								case 2:
									std::cout << ("gold 2") << endl;
									break;
								case 3:
									std::cout << ("gold 3") << endl;
									break;
								}

								cosmetics = "gold";
							}

							if (ranum1 > 140 && ranum1 < 300)
							{
								int uncommon = (rand() % 6) + 1;
								switch (uncommon)
								{
								case 1:
									std::cout << ("silver 1") << endl;
									break;
								case 2:
									std::cout << ("silver 2") << endl;
									break;
								case 3:
									std::cout << ("silver 3") << endl;
									break;
								case 4:
									std::cout << ("silver 4") << endl;
									break;
								case 5:
									std::cout << ("silver 5") << endl;
									break;
								case 6:
									std::cout << ("silver 6") << endl;
									break;
								}
								cosmetics = "silver";
							}

							if (ranum1 > 300 && ranum1 < 620)
							{
								int common = (rand() % 7) + 1;
								switch (common)
								{
								case 1:
									std::cout << ("bronze 1") << endl;
									break;
								case 2:
									std::cout << ("bronze 2") << endl;
									break;
								case 3:
									std::cout << ("bronze 3") << endl;
									break;
								case 4:
									std::cout << ("bronze 4") << endl;
									break;
								case 5:
									std::cout << ("bronze 5") << endl;
									break;
								case 6:
									std::cout << ("bronze 6") << endl;
									break;
								case 7:
									std::cout << ("bronze 7") << endl;
									break;
								}

								cosmetics = "bronze";
							}

							if (ranum1 > 620 && ranum1 < 1240)
							{
								int common = (rand() % 7) + 1;
								switch (common)
								{
								case 1:
									std::cout << ("bronze 1") << endl;
									break;
								case 2:
									std::cout << ("bronze 2") << endl;
									break;
								case 3:
									std::cout << ("bronze 3") << endl;
									break;
								case 4:
									std::cout << ("bronze 4") << endl;
									break;
								case 5:
									std::cout << ("bronze 5") << endl;
									break;
								case 6:
									std::cout << ("bronze 6") << endl;
									break;
								case 7:
									std::cout << ("bronze 7") << endl;
									break;
								}

								cosmetics = "bronze";
							}

							//std::cout << (ranum2) << endl;

							if (ranum2 < 20)
							{
								int Exrare = (rand() % 2) + 1;
								switch (Exrare)
								{
								case 1:
									std::cout << ("Diamond 1") << endl;
									break;
								case 2:
									std::cout << ("Diamond 2") << endl;
									break;
								}
								cosmetics = "diamond";
							}

							if (ranum2 > 20 && ranum2 < 60)
							{
								int Vrare = (rand() % 3) + 1;
								switch (Vrare)
								{
								case 1:
									std::cout << ("Platinum 1") << endl;
									break;
								case 2:
									std::cout << ("Platinum 2") << endl;
									break;
								case 3:
									std::cout << ("Platinum 3") << endl;
									break;
								}

								cosmetics = "platinum";
							}

							if (ranum2 > 60 && ranum2 < 140)
							{
								int rare = (rand() % 3) + 1;
								switch (rare)
								{
								case 1:
									std::cout << ("gold 1") << endl;
									break;
								case 2:
									std::cout << ("gold 2") << endl;
									break;
								case 3:
									std::cout << ("gold 3") << endl;
									break;
								}

								cosmetics = "gold";
							}

							if (ranum2 > 140 && ranum2 < 300)
							{
								int uncommon = (rand() % 6) + 1;
								switch (uncommon)
								{
								case 1:
									std::cout << ("silver 1") << endl;
									break;
								case 2:
									std::cout << ("silver 2") << endl;
									break;
								case 3:
									std::cout << ("silver 3") << endl;
									break;
								case 4:
									std::cout << ("silver 4") << endl;
									break;
								case 5:
									std::cout << ("silver 5") << endl;
									break;
								case 6:
									std::cout << ("silver 6") << endl;
									break;
								}
								cosmetics = "silver";
							}

							if (ranum2 > 300 && ranum2 < 620)
							{
								int common = (rand() % 7) + 1;
								switch (common)
								{
								case 1:
									std::cout << ("bronze 1") << endl;
									break;
								case 2:
									std::cout << ("bronze 2") << endl;
									break;
								case 3:
									std::cout << ("bronze 3") << endl;
									break;
								case 4:
									std::cout << ("bronze 4") << endl;
									break;
								case 5:
									std::cout << ("bronze 5") << endl;
									break;
								case 6:
									std::cout << ("bronze 6") << endl;
									break;
								case 7:
									std::cout << ("bronze 7") << endl;
									break;
								}

								cosmetics = "bronze";
							}

							if (ranum2 > 620 && ranum2 < 1240)
							{
								int common = (rand() % 7) + 1;
								switch (common)
								{
								case 1:
									std::cout << ("bronze 1") << endl;
									break;
								case 2:
									std::cout << ("bronze 2") << endl;
									break;
								case 3:
									std::cout << ("bronze 3") << endl;
									break;
								case 4:
									std::cout << ("bronze 4") << endl;
									break;
								case 5:
									std::cout << ("bronze 5") << endl;
									break;
								case 6:
									std::cout << ("bronze 6") << endl;
									break;
								case 7:
									std::cout << ("bronze 7") << endl;
									break;
								}

								cosmetics = "bronze";
							}

							//std::cout << (ranum3) << endl;

							if (ranum3 < 20)
							{
								int Exrare = (rand() % 2) + 1;
								switch (Exrare)
								{
								case 1:
									std::cout << ("Diamond 1") << endl;
									break;
								case 2:
									std::cout << ("Diamond 2") << endl;
									break;
								}
								cosmetics = "diamond";
							}

							if (ranum3 > 20 && ranum3 < 60)
							{
								int Vrare = (rand() % 3) + 1;
								switch (Vrare)
								{
								case 1:
									std::cout << ("Platinum 1") << endl;
									break;
								case 2:
									std::cout << ("Platinum 2") << endl;
									break;
								case 3:
									std::cout << ("Platinum 3") << endl;
									break;
								}

								cosmetics = "platinum";
							}

							if (ranum3 > 60 && ranum3 < 140)
							{
								int rare = (rand() % 3) + 1;
								switch (rare)
								{
								case 1:
									std::cout << ("gold 1") << endl;
									break;
								case 2:
									std::cout << ("gold 2") << endl;
									break;
								case 3:
									std::cout << ("gold 3") << endl;
									break;
								}

								cosmetics = "gold";
							}

							if (ranum3 > 140 && ranum3 < 300)
							{
								int uncommon = (rand() % 6) + 1;
								switch (uncommon)
								{
								case 1:
									std::cout << ("silver 1") << endl;
									break;
								case 2:
									std::cout << ("silver 2") << endl;
									break;
								case 3:
									std::cout << ("silver 3") << endl;
									break;
								case 4:
									std::cout << ("silver 4") << endl;
									break;
								case 5:
									std::cout << ("silver 5") << endl;
									break;
								case 6:
									std::cout << ("silver 6") << endl;
									break;
								}
								cosmetics = "silver";
							}

							if (ranum3 > 300 && ranum3 < 620)
							{
								int common = (rand() % 7) + 1;
								switch (common)
								{
								case 1:
									std::cout << ("bronze 1") << endl;
									break;
								case 2:
									std::cout << ("bronze 2") << endl;
									break;
								case 3:
									std::cout << ("bronze 3") << endl;
									break;
								case 4:
									std::cout << ("bronze 4") << endl;
									break;
								case 5:
									std::cout << ("bronze 5") << endl;
									break;
								case 6:
									std::cout << ("bronze 6") << endl;
									break;
								case 7:
									std::cout << ("bronze 7") << endl;
									break;
								}

								cosmetics = "bronze";
							}

							if (ranum3 > 620 && ranum3 < 1240)
							{
								int common = (rand() % 7) + 1;
								switch (common)
								{
								case 1:
									std::cout << ("bronze 1") << endl;
									break;
								case 2:
									std::cout << ("bronze 2") << endl;
									break;
								case 3:
									std::cout << ("bronze 3") << endl;
									break;
								case 4:
									std::cout << ("bronze 4") << endl;
									break;
								case 5:
									std::cout << ("bronze 5") << endl;
									break;
								case 6:
									std::cout << ("bronze 6") << endl;
									break;
								case 7:
									std::cout << ("bronze 7") << endl;
									break;
								}

								cosmetics = "bronze";
							}

							std::cout << "Would u like to go again?" << endl;
							std::cout << "> Yes" << endl;;
							std::cout << "  No";

							char inputuser = _getch();
							int choice2 = 1;
							inputuser = 'd';
							while (inputuser != '\r')
							{
								if (inputuser == 'w')
								{
									choice2 = 1;
									gotoxy(0, 25, ">");
									gotoxy(0, 26, " ");
								}
								else if (inputuser == 's')
								{
									choice2 = 2;
									gotoxy(0, 26, ">");
									gotoxy(0, 25, " ");
								}
								inputuser = _getch();
							}
							money = money - 3;
							if (choice2 == 1)
							{
								goagain = 'y';
								userinput = "d";
							}
							else if (choice2 == 2)
							{
								goagain = 'n';
								break;
							}
						}


						else
						{
							std::cout << "You will need more money" << endl;
							char inputlol = _getch();
							goagain = 'n';
							break;
						}
					}
				}


			}
			if (goagain == 'n' || goagain == 'N')
			{
				std::cout << "bye" << endl;
				break;
			}
		}

		else if (CurrentArrow == 4)
		{
			system("CLS");
			break;
		}

		for (int i = 15; i < 30; i++)
		{
			gotoxy(0, i, "                                                          ");
		}
	}

	CarrotAmt = CarrotAmount;
	Inv = Inventory;
	for (int i = 0; i < 9; i++)
	{
		ItemAmount[i] = ItemAmt[i];
		TheItemName[i] = TheItemNames[i];
	}

}

void Shop::gotoxy(int x, int y, std::string String, int ColorType)
{
	COORD screen;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	screen.X = x; screen.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, screen);
	SetConsoleTextAttribute(hConsoleOutput, ColorType);
	std::cout << String;
	SetConsoleTextAttribute(hConsoleOutput, 0);
	std::cout << 'F';
	SetConsoleTextAttribute(hConsoleOutput, 7);
}

void Shop::gotoxy(int x, int y)
{
	COORD screen;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	screen.X = x; screen.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, screen);
	SetConsoleTextAttribute(hConsoleOutput, 9);
}

void Shop::PrintHead1()
{
	gotoxy(23, 7, "O", 9);
	gotoxy(28, 7, "O", 9);
}

void Shop::PrintHead2()
{
	gotoxy(23, 7, "=", 9);
	gotoxy(28, 7, "=", 9);
}

void Shop::PrintHead()
{
	gotoxy(0, 0);
	std::cout << R"(
      		  /'     |   |    \
                /    /  |   | \   \
              /    / |  |   |  \   \
             (   /   |  """"   |\   \       
             | /   / /^\    /^\  \  _|           
              ~   | |   |  |   | | ~
                  | |__O|__|O__| |
                /~~      \/     ~~\
               /   (      |      )  \
         _--_  /,   \____/^\___/'   \  _--_
       /~    ~\ / -____-|_|_|-____-\ /~    ~\__
______/________|___/~~~~\___/~~~~\ __|________\___________
                 |     |   |     |       
                 `^-^-^'   `^-^-^')" << '\n';
}

void Shop::Printhead3()
{
	gotoxy(23, 7, "O", 0);
	gotoxy(28, 7, "O", 0);
	Beep(700, 500);
}

void Shop::PrintHead4()
{
	COORD screen;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	screen.X = 0; screen.Y = 0;
	SetConsoleCursorPosition(hConsoleOutput, screen);
	SetConsoleTextAttribute(hConsoleOutput, 4);
	std::cout << R"(
      		  /'     |   |    \
                /    /  |   | \   \
              /    / |  |   |  \   \
             (   /   |  """"   |\   \       
             | /   / /^\    /^\  \  _|           
              ~   | |   |  |   | | ~
                  | |__O|__|O__| |
                /~~      \/     ~~\
               /   (      |      )  \
         _--_  /,   \____/^\___/'   \  _--_
       /~    ~\ / -____-|_|_|-____-\ /~    ~\__
______/________|___/~~~~\___/~~~~\ __|________\___________
                 |     |   |     |       
                 `^-^-^'   `^-^-^')" << '\n';
}

void Shop::Printhead5()
{
	gotoxy(23, 7, "=", 9);
	gotoxy(28, 7, "=", 9);
	Beep(700, 500);
}

void Shop::Printhead6()
{
	int random = rand() % 9 + 1;
	COORD screen;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	screen.X = 0; screen.Y = 0;
	SetConsoleCursorPosition(hConsoleOutput, screen);
	SetConsoleTextAttribute(hConsoleOutput, random);
	std::cout << R"(
      		  /'     |   |    \
                /    /  |   | \   \
              /    / |  |   |  \   \
             (   /   |  """"   |\   \       
             | /   / /^\    /^\  \  _|           
              ~   | |   |  |   | | ~
                  | |__O|__|O__| |
                /~~      \/     ~~\
               /   (      |      )  \
         _--_  /,   \____/^\___/'   \  _--_
       /~    ~\ / -____-|_|_|-____-\ /~    ~\__
______/________|___/~~~~\___/~~~~\ __|________\___________
                 |     |   |     |       
                 `^-^-^'   `^-^-^')" << '\n';
}

void Shop::Printhead7(int time)
{
	int random = rand() % 9 + 1;
	gotoxy(23, 7, "=", random);
	gotoxy(28, 7, "=", random);
	Beep(700, time);
}

void Shop::Printhead8(int time)
{
	int random = rand() % 9 + 1;
	gotoxy(23, 7, "O", random);
	gotoxy(28, 7, "O", random);
	Beep(700, time);
}

void Shop::MoveHead(int& i)
{
	Sleep(100);
	if (i == 1)
	{
		PrintHead1();
		i++;
	}
	else if (i == 2)
	{
		PrintHead2();
		i--;
	}

}

void Shop::PrintBottom()
{
	gotoxy(0, 35);
	std::cout << "__________________________________________________________" << std::endl;
}

std::string Shop::PrintInventory(std::string TheInv)
{
	for (int i = 0; i < 9; i++)
	{
		std::string End;
		if (i == 8)
		{
			End = ")";
		}
		else
		{
			End = "), ";
		}
		TheInv = TheInv + TheItemNames[i] + " (x" + std::to_string(ItemAmt[i]) + End;
		if ((i + 1) % 3 == 0)
		{
			TheInv = TheInv + "\n";
		}
	}
	return TheInv;
}

std::string Shop::getfourthskill()
{
	return fourthskill;
}

int Shop::getequipmenttype()
{
	int colortype = 7;

	if (cosmetics == "gold")
	{
		colortype = 6;
	}
	else if (cosmetics == "platinum")
	{
		colortype = 8;
	}
	else if (cosmetics == "diamond")
	{
		colortype = 1;
	}
	else if (cosmetics == "silver")
	{
		colortype = 8;
	}
	else if (cosmetics == "bronze")
	{
		colortype = 4;
	}

	return colortype;
}

void Shop::addmoney()
{
	money = money + 1;
}