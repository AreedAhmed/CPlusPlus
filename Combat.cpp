/*
*	Fantasy Game, A text based RPG
*
*	File Name: Combat.h
*	Authors: Areed Ahmed A, Sachin, Danish Faraz, Kiran Jangamkote Srikanteshwara
*	Date: 02-Dec-2018
*/

#include<iostream>
#include<string>
using namespace std;

class Combat
{
	//defining variables defining attributes of player and enemy
	public:
	int attack,defence,strengt,health,attackmax ,attackmin,	defencemax ,defencemin;
	string orctype,itemIdentifier;

	public:
	virtual void setHuman(){}; //Initializing the player as Human
	virtual void setElf(){}; //Initializing the player as Elf
	virtual void setOrcDay(){}; //Initializing the player as Orc
	virtual void setDwarf(){}; //Initializing the player as Dwarf
	virtual void setHobbit(){}; //Initializing the player as Hobbit
	virtual void setEmpty(){}; //Assigning empty spaces on the grid
	virtual void setSword(){}; //Assigning Sword on the grid
	virtual void setDagger(){}; //Assigning Dagger on the grid
	virtual void setPlateArmour(){}; //Assigning PlateArmour on the grid
	virtual void setLeatherArmour(){}; //Assigning LeatherArmour on the grid
	virtual void setLargeShield(){}; //Assigning LargeShield on the grid
	virtual void setSmallShield(){}; //Assigning SmallShield on the grid
	virtual void setRingOfLife(){}; //Assigning RingOfLife on the grid
	virtual void setRingOfStrength(){}; //Assigning RingOfStrength on the grid
	virtual void setAttack(int ){}; //Setting the attack values of the character
	virtual void setStrength(int ){}; //Setting the strength values of the character
	virtual void setDefence(int ){}; //Setting the defence values of the character
	virtual void setHealth(int ){}; //Setting the health values of the character
	virtual void setGold(int ){}; //Setting the gold values of the character
	virtual string getIdentifier(){return "";}; //Fetch identity of the player
	virtual int getweight(){return 0;} //Retrieving weight of items
	virtual int getAttack(){return 0;}; //Retrieving the attack attribute of characters
	virtual int getDefence(){return 0;}; //Retrieving the defence attribute of characters
	virtual int getStrength(){return 0;}; //Retrieving the strength attribute of characters
	virtual int getHealth(){return 0;}; //Retrieving the health attribute of characters
	virtual int getGold(){return 0;}; //Retrieving the gold attribute of characters
	virtual string getItemName(){return "";} //Retrieves the item name from the grid location
	virtual int getAttackMax(){return 0;} //Max attack probabilty of the character, used in checking race condition
	virtual int getAttackMin(){return 0;} //Min attack probabilty of the character, used in checking race condition
	virtual int getDefenceMax(){return 0;} //Max defence probabilty of the character, used in checking race condition
	virtual int getDefenceMin(){return 0;} //Min defence probabilty of the character, used in checking race condition
	virtual string getOrcType(){return "";} //Getting the type of Orc based on night or morning
	string getItemIdentifier(){return itemIdentifier;}; //Used to check whether an item is present on the grid, also used while implementing attack
};