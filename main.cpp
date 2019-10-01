/*
*	Fantasy Game, A text based RPG
*
*	File Name: main.cpp
*	Authors: Areed Ahmed A, Sachin, Danish Faraz, Kiran Jangamkote Srikanteshwara
*	Date: 02-Dec-2018
*/


#include<iostream>
#include"BoardGame.h"

using namespace std;

int main()
{
	int gridnumber,choice; //variables for assigning choice and value for grid selection
	try
	{
		//Taking input of grid number from the user
		cout<<"Enter the size of the game grid"<<endl;
		cin>>gridnumber;
		//checking whether the grid size is entered is less than 2 and throwing exception
		if(gridnumber<2)
		{
			throw 1;
		}
		BoardGame game; //creating object of BoardGame class
		game.setplayer(gridnumber); //initializing the player's position to start
		cout<<endl;
		do
		{
			//Taking choice input from the user
			cout<<"Select the player you want to choose:\n1.Human,\n2.Dwarf,\n3.Elf,\n4.Orc,\n5.Hobbit "<<endl;
			cout<<"Enter your choice: ";
			cin>>choice;
			//checking for invalid choices
			if(choice>0 && choice<6)
			{
				game.createplayer(choice); //Assigning the selected character to player
				break;
			}
			else
			{
				cout<<"\nInvalid choice, Please try again\n"<<endl;
			}
		}while(choice>=6);
		
		cout<<endl;
		game.direction(gridnumber); //Selecting the command player wishes to execute
		return 0;
	}
	//catching throwed exception
	catch(int throwValue)
	{
		if(throwValue==1)
			cout<<"Enter a grid size greater than 2\n";
	}
}