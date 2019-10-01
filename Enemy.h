/*
*	Fantasy Game, A text based RPG
*
*	File Name: Enemy.h
*	Authors: Areed Ahmed A, Sachin, Danish Faraz, Kiran Jangamkote Srikanteshwara
*	Date: 02-Dec-2018
*/

#ifndef ENEMY_H
#define ENEMY_H

#include<iostream>
#include<string>
#include"Combat.h"
using namespace std;

class Enemy:public Combat //Inherits Combat Class
{
	//Variable to store the amount of gold for the character
	public:
	int gold;
	//Variable used to store the type of enemy
	string identifier;

	void setAttack(int value) //Setting the attack based on the parameter
	{
		attack=attack+value;
	}

	void setStrength(int value) //Setting the strength based on the parameter
	{
		strengt=strengt-value;
	}

	void setDefence(int value) //Setting the defence based on the parameter
	{
		defence=defence+value;
	}

	void setHealth(int value) //Setting the health based on the parameter
	{
		health=health+value;
	}
	void setGold(int value) //Setting the gold based on the parameter
	{
		gold=gold+value;
	}
	void setHuman() //used to set the attributes of Human to the player
	{
		attack=30;
		defence=20;
		strengt=100;
		health=60;
		identifier="Human";
		attackmax = 3;
		attackmin = 1;
		defencemax = 2 ;
		defencemin = 1;
		gold = 0;
		itemIdentifier = "NotPresent";
	}

	void setElf()  //used to set the attributes of Elf to the player
	{
		attack=40;
		defence=10;
		strengt=70;
		health=40;
		identifier="Elf";
		attackmax = 1;
		attackmin = 1;
		defencemax = 4 ;
		defencemin = 1;
		gold = 0;
		itemIdentifier = "NotPresent";
	}
	void setOrcDay()  //used to set the attributes of Orc to the player
	{
		attack=25;
		defence=10;
		strengt=130;
		health=50;
		identifier="Orc";
		orctype = "Day";
		gold = 0;
		itemIdentifier = "NotPresent";
	}

	void setDwarf()  //used to set the attributes of Dwarf to the player
	{
		attack=30;
		defence=20;
		strengt=130;
		health=50;
		identifier="Dwarf";
		attackmax = 3;
		attackmin = 2;
		defencemax = 3 ;
		defencemin = 2;
		gold = 0;
		itemIdentifier = "NotPresent";
	}
	void setHobbit()  //used to set the attributes of Hobbit to the player
	{	
		attack=25;
		defence=20;
		strengt=85;
		health=70;
		identifier="Hobbit";
		attackmax = 3;
		attackmin = 1;
		defencemax = 3 ;
		defencemin = 2;
		gold = 0;
		itemIdentifier = "NotPresent";
	}

	void setEmpty() //used to set empty space with null values on the grid
	{
		attack=0;
		defence=0;
		strengt=0;
		health=0;
		identifier="Empty";
		itemIdentifier = "Present";
	}

	string getIdentifier(){return identifier;} //returning the type of enemy
	int getHealth(){return health;} //returning the health of the selected character
	int getAttack(){return attack;} //returning the attack of the selected character
	int getDefence(){return defence;} //returning the defence of the selected character
	int getStrength(){return strengt;} //returning the strength of the selected character
	int getGold(){return gold;} //returning the gold of the selected character
	string getOrcType(){return orctype;} //returning the type of Orc based on night or orning
	int getAttackMax(){return attackmax;} //returning the max attack value of the selected player
	int getAttackMin(){return attackmin;} //returning the min attack value of the selected player
	int getDefenceMax(){return defencemax;} //returning the max defence value of the selected player
	int getDefenceMin(){return defencemin;} ////returning the min defence value of the selected player
};
#endif