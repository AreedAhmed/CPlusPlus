/*
*	Fantasy Game, A text based RPG
*
*	File Name: Item.h
*	Authors: Areed Ahmed A, Sachin, Danish Faraz, Kiran Jangamkote Srikanteshwara
*	Date: 02-Dec-2018
*/
#ifndef ITEM_H
#define ITEM_H

#include<iostream>
#include"Enemy.h"
using namespace std;

class Item:public Combat //Inherits Combat Class
{
	//variables to set the respective attributes of items
	public:
	string name,weapontype,armourtype,shieldtype;
	int weight;
	void setSword() //Attributes of Sword
	{
		weight=10;
		name="Sword";
		weapontype = "Weapon";
		itemIdentifier = "Present";
	}
	
	void setDagger() //Attributes of Dagger
	{
		weight=5;
		name="Dagger";
		weapontype = "Weapon";
		itemIdentifier = "Present";
	}

	void setPlateArmour() //Attributes of PlateArmour
	{
		weight=40;
		name="PlateArmour";
		armourtype = "Armour";
		itemIdentifier = "Present";
	}
	void setLeatherArmour() //Attributes of LeatherArmour
	{
		weight=20;
		name="LeatherArmour";
		armourtype = "Armour";
		itemIdentifier = "Present";
	}
	void setLargeShield() //Attributes of LargeShield
	{
		weight=30;
		name="LargeShield";
		shieldtype = "Shield";
		itemIdentifier = "Present";
	}
	void setSmallShield() //Attributes of SmallShield
	{
		weight=10;
		name="SmallShield";
		shieldtype = "Shield";
		itemIdentifier = "Present";
	}
	void setRingOfLife() //Attributes of  RingOfLife
	{
		health=0;
		weight=1;
		name="RingOfLife";
		itemIdentifier = "Present";
	}
	void setRingOfStrength() //Attributes of RingOfStrength
	{
		weight=1;
		name="RingOfStrength";
		itemIdentifier = "Present";
	}
	string getItemName(){return name;} //Returning the selected item name
	int getweight(){return weight;} //Returning the weight f the selected item
};
#endif