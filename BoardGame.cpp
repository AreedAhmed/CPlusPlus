/*
*	Fantasy Game, A text based RPG
*
*	File Name: BoardGame.cpp
*	Authors: Areed Ahmed A
*	Date: 02-Dec-2018
*/

#include<iostream>
#include<string>
#include"Item.h"
using namespace std;

class BoardGame
{
	Enemy *player; //Creating an object of the player
	//Enemy *health; //Creating an object for health of the player
	Combat *arr[10][10]; //creating a grid for calss combat

	public:
	//attributes used for several calculations
	int randv,counter1=0,counter2=0,counter3=0,counter4=0,counter5=0;
	//flag value used to exit the game
	int playerDie=0;
	//to add the items to the inventory
	string Items = "";

	public:
	//function used to randomly shuflle and enemies, items along with empty spaces
	void setplayer(int gridnumber)
	{
		srand(time(NULL)); //seeding random value
		int i,j;
		//setting the grid locations  with enemies, items and empty spaces
		for(i=0;i<gridnumber;i++) 
		{
			for(j=0;j<gridnumber;j++)
			{
				
				randv=(rand() % 14 + 1); //getting a random value from 1 to 14
				if(randv==1)
				{
					//setting the human on the grid as an enemy
					arr[i][j]= new Enemy();
					arr[i][j]->setHuman();
				}
				else if(randv==2)
				{
					//setting the elf on the grid as an enemy
					arr[i][j]= new Enemy();
					arr[i][j]->setElf();
				}
				else if(randv==3)
				{
					//setting the orc on the grid as an enemy
					arr[i][j]= new Enemy();
					arr[i][j]->setOrcDay();
				}
				else if(randv==4)
				{
					//setting the dwarf on the grid as an enemy
					arr[i][j]= new Enemy();
					arr[i][j]->setDwarf();
				}
				else if(randv==5)
				{
					//setting the hobbit on the grid as an enemy
					arr[i][j]= new Enemy();
					arr[i][j]->setHobbit();
				}
				else if(randv==6)
				{
					//setting the sword on the grid
					arr[i][j]= new Item();
					arr[i][j]->setSword();
				}
				else if(randv==7)
				{
					//setting the dagger on the grid
					arr[i][j]= new Item();
					arr[i][j]->setDagger();
				}
				else if(randv==8)
				{
					//setting the plate armour on the grid
					arr[i][j]= new Item();
					arr[i][j]->setPlateArmour();
				}
				else if(randv==9)
				{
					//setting the leather armour on the grid
					arr[i][j]= new Item();
					arr[i][j]->setLeatherArmour();
				}
				else if(randv==10)
				{
					//setting the large shield on the grid
					arr[i][j]= new Item();
					arr[i][j]->setLargeShield();
				}
				else if(randv==11)
				{
					//setting the small shield on the grid
					arr[i][j]= new Item();
					arr[i][j]->setSmallShield();
				}
				else if(randv==12)
				{
					//setting the ring of life on the grid
					arr[i][j]= new Item();
					arr[i][j]->setRingOfLife();
				}
				else if(randv==13)
				{
					//setting the ring of strength on the grid
					arr[i][j]= new Item();
					arr[i][j]->setRingOfStrength();
				}
				else 
				{
					//setting the empty space on the grid
					arr[i][j]= new Enemy();
					arr[i][j]->setEmpty();
				}		
			}		
		}
	}

	//function to select the character as the player
	void createplayer(int choice)
	{
		player = new Enemy(); //creating an object of enemy class
		switch(choice)
		{

			case 1: player->setHuman();showplayer();break;
			case 2: player->setDwarf();showplayer();break;
			case 3: player->setElf();showplayer();break;
			case 4: player->setOrcDay();showplayer();break;
			case 5: player->setHobbit();showplayer();break;
			default:break;
		}
	}
	//displaying the player attributes
	void showplayer()
	{
		cout<<"Player: "<<player->getIdentifier()<<"; Attack: "<<player->getAttack()<<", Defence: "<<player->getDefence()<<", Health: "<<player->getHealth()<<", Strength: "<<player->getStrength()<<"\n"<<endl;
	}
	//function used for command selection which includes navigation and performing actions
	void direction(int gridnumber)
	{
		char dir; //variable to hold the navigation/command selection of the player 
		int count=1; //varable for calculating day and noight
		int row=0,col=0,nrow,ncol; //navigation variables
		currentPosition(row,col); //responsible for fetching the current location of player

		do{
			daynight(row,col,count); //calculation of day or night
			showplayer(); //displays player details
			//getting the command for navigation or action to be performed by the user
			cout<<"Select the position you want to move, (N)orth,(S)outh,(E)ast,(W)est\nChoose commands,(A)ttack,(P)ickup,(D)rop,(L)ook,(I)nventory or E(X)it"<<endl;
			cin>>dir;
			string itempresent = arr[row][col]->getItemIdentifier();
			//cases to perform navigations and actions
			switch(dir){
				case 'N':
					if(row>0&&col>=0)
					{
						//calculation for moving up/north
						nrow=row-1;row=nrow;
						currentPosition(nrow,col);
						checkLook('N',gridnumber,nrow,col); //displays the details of grid location
					}
					break;
				case 'S':
					if(row<(gridnumber-1)&&col>=0)
					{
						//calculation for moving down/south
						nrow=row+1;
						row=nrow;
						currentPosition(nrow,col);
						checkLook('S',gridnumber,nrow,col); //displays the details of grid location
					}
					break;
				case 'E':
					if(row>=0&&col<(gridnumber-1))
					{
						//calculation for moving right/east
						ncol=col+1;
						col=ncol;
						currentPosition(row,ncol);
						checkLook('E',gridnumber,row,ncol); //displays the details of grid location
					}
					break;
				case 'W':
					if(row>=0&&col>0)
					{
						//calculation for moving left/west
						ncol=col-1;
						col=ncol;
						currentPosition(row,ncol);
						checkLook('W',gridnumber,row,ncol); //displays the details of grid location
					}
					break;
				case 'L':currentPosition(row,col);break; //fetch the current location of the player
				case 'P':pickUp(row,col);break; //fuction to pick up the items present on the grid
				case 'D':drop(gridnumber,row,col);break; //function to drop the items in an empty space
				case 'I':inventory();break; //displaying the inventory of the player containing items picked up
				case 'A':
					if(itempresent!="Present") //condition to check if there is enemy on the grid
					{
						attack(row,col); //to perform the attack of characters
					}
					else
					{
						cout<<"\nNo Enemy Present"<<endl;
					}
					break;
				case 'X':
					//exiting the game
					playerDie=1;
					cout<<"\nYou have exited the game!\n";
					break;
				default: cout<<"Invalid Input\n";break;
			}
		count++;
		}while(playerDie==0); //checking the flag condition to exit
	}
	//fetch attack and defence probabilities for characters
	int getProbability(int max,int min) 
	{
		int *probValue=new int[max];
		for(int i=0;i<max;i++) //probability values set for attack and defence for a character
		{
			if(i<min) probValue[i]=1;
			else probValue[i]=0;
		}
		//random allocation of value to implement probability
		int index=rand()% max;
		int value=probValue[index];
		return value;
	}
	//function to perform attacks on characters
	void attack(int row,int col)
	{
		//attributes to retrieve the character info
		string playercheck = "";
		string enemycheck = "";
		//get the respective max and min attributes of attack and defence of a character
		enemycheck = arr[row][col]->getIdentifier();
		playercheck = player->getIdentifier();
		int attackmax = player->getAttackMax();
		int attackmin = player->getAttackMin();
		int defencemax = player->getDefenceMax();
		int defencemin = player->getDefenceMin();
		int attackmax2 = arr[row][col]->getAttackMax();
		int attackmin2 = arr[row][col]->getAttackMin();
		int defencemax2 = arr[row][col]->getDefenceMax();
		int defencemin2 = arr[row][col]->getDefenceMin();
		int attackProb1=getProbability(attackmax,attackmin);
		int defenceProb1=getProbability(defencemax,defencemin);
		int attackProb2=getProbability(attackmax2,attackmin2);
		int defenceProb2=getProbability(defencemax2,defencemin2);
		//getting the type of orc based on night or day
		string orctypeplayer = player->getOrcType();
		string orctypeenemy = arr[row][col]->getOrcType();

		//condition when attack of player is successful and enemy's defence is also success
		if(attackProb1==1 && defenceProb2==1)
		{
			cout<<"Player "<<playercheck<<" has successfully attacked Enemy "<<enemycheck<<endl;
			
			if(enemycheck.compare("Human")==0) //condition to check if enemy is human
			{
				cout<<"Enemy "<<enemycheck<<" does not take any damage"<<endl;
			}
			else if(enemycheck.compare("Elf")==0) //condition to check if enemy is elf
			{
				arr[row][col]->setHealth(1);	//incrementing the health by 1 on successful defence
				cout<<"Enemy "<<enemycheck<<" health increases by 1"<<endl;
			}
			else if(enemycheck.compare("Dwarf")==0) //condition to check if enemy is dwarf
			{
				cout<<"Enemy "<<enemycheck<<" does not take any damage"<<endl;
			}
			else if(enemycheck.compare("Hobbit")==0) //condition to check if enemy is hobbit
			{
				srand(time(NULL));
				int hobitrand = rand()%5; //value to fetch random values from 0-5
				cout<<"Enemy "<<enemycheck<<"'s health reduced by "<<hobitrand<<endl;
				arr[row][col]->setHealth(-hobitrand); //reducing the health of hobbit by the random value generated
			}
			else if(orctypeenemy.compare("Night")==0) //condition to check if enemy is Orc and if night
			{
				arr[row][col]->setHealth(1); //incrementing the health by 1 on successful defence
				cout<<"Enemy "<<enemycheck<<" health increased by 1"<<endl;
			}
			else if(orctypeenemy.compare("Day")==0) //condition to check if enemy is Orc and if day
			{
				int defhealth = 0.25*(player->getAttack()-arr[row][col]->getDefence()); //calculating the enemy's health
				cout<<"Enemy "<<enemycheck<<" health reduced by "<<defhealth<<endl;
				arr[row][col]->setHealth(-defhealth); //reduce health by earlier calculated value
			}
			cout<<"Enemy "<<enemycheck<<" defended successfully from Player "<<playercheck<<endl;
		}
		//condition if the player attack is success and enemy's defence fails
		else if(attackProb1==1 && defenceProb2==0)
		{
			cout<<"Player "<<playercheck<<" has successfully attacked Enemy "<<enemycheck<<endl;
			cout<<"Enemy "<<enemycheck<<" has failed to defend against Player "<<playercheck<<endl;
			//calculating the health to be reduced on failed defence
			int defenderfinalhealth = player->getAttack()-arr[row][col]->getDefence();
			arr[row][col]->setHealth(-defenderfinalhealth); //reducing the health by the calculated value
		}
		//condition if the player attack fails
		else
		{
			cout<<"Player "<<playercheck<<" attack failed against Enemy "<<enemycheck<<endl;

		}

		//condition if the enemy's attack is successful and the player's defence is successful
		//same comments as the earlier condition for the inner conditions present
		if(attackProb2==1 && defenceProb1==1)
		{
			cout<<"Enemy "<<enemycheck<<" has successfully attacked Player "<<playercheck<<endl;
			
			if(enemycheck.compare("Human")==0) 
			{
				cout<<"Player "<<playercheck<<" does not take any damage"<<endl;
			}
			else if(playercheck.compare("Elf")==0) 
			{
				player->setHealth(1);	
				cout<<"Player "<<playercheck<<" health increases by 1"<<endl;
			}
			else if(playercheck.compare("Dwarf")==0) 
			{
				cout<<"Player "<<playercheck<<" does not take any damage"<<endl;
			}
			else if(playercheck.compare("Hobbit")==0) 
			{
				srand(time(NULL));
				int hobitrand = rand()%5;
				cout<<"Player "<<playercheck<<" takes a health damage of "<<hobitrand<<endl;
				player->setHealth(-hobitrand);
			}
			else if(orctypeplayer.compare("Night")==0)
			{
				player->setHealth(1);
				cout<<"Player "<<playercheck<<" health increases by 1"<<endl;
			}
			else if(orctypeplayer.compare("Day")==0)
			{
				int defhealth = 0.25*(arr[row][col]->getAttack()-player->getDefence());
				cout<<"Player "<<playercheck<<" health reduces by "<<defhealth<<endl;
				player->setHealth(-defhealth);
			}
			cout<<"Player "<<playercheck<<" has successfully defended against Enemy "<<enemycheck<<endl;	
		}
		else if(attackProb2==1 && defenceProb1==0)
		{
			cout<<"Enemy: "<<enemycheck<<" has successfully attacked Player "<<playercheck<<endl;
			cout<<"Player "<<playercheck<<" has failed to defend against Enemy "<<enemycheck<<endl;
			int defenderfinalhealth = arr[row][col]->getAttack()-player->getDefence();
			player->setHealth(-defenderfinalhealth);
		}
		else
		{
			cout<<"Enemy "<<enemycheck<<" attack failed against Player "<<playercheck<<endl;
		}

		//Successfully killed the enemy
		if((arr[row][col]->getHealth()<=0) && (arr[row][col]->getIdentifier()!="Empty"))
		{
			cout<<"\nCongrats you killed "<<enemycheck<<endl;
			cout<<arr[row][col]->getDefence()<<" gold coins earned!\n"<<endl; //gold coins earned is equivalent to the defence value of the enemy
			player->setGold(arr[row][col]->getDefence()); //adding the equivalent gold to the player
			arr[row][col]->setEmpty();	//setting the grid to empty space
		}
		//condition to display the enemy info if player's health is not 0
		if(arr[row][col]->getHealth()!=0)
		{
			cout<<"\nEnemy: "<<arr[row][col]->getIdentifier()<<"; Attack: "<<arr[row][col]->getAttack()<<", Defence: "<<arr[row][col]->getDefence()<<", Health: "<<arr[row][col]->getHealth()<<", Strength: "<<arr[row][col]->getStrength()<<"\n"<<endl;
		}
		//condition checking player's health and displaying the game over message
		if(player->getHealth()<=0)
		{
			cout<<"\nYou died in combat!\n";
			cout<<"Gold Coins earned: "<<player->getGold()<<endl;
			playerDie = 1; //setting flag to exit
		}
	}
	//inventory to display all items picked up by player
	void inventory()
	{
		cout<<"The player bag has the following:"<<endl;
		cout<<"Items: "<<Items<<endl;
		cout<<"Number of RingOfStrength: "<<counter4<<endl;
		cout<<"Number of RingOfLife: "<<counter5<<endl;
		cout<<"Gold Coins: "<<player->getGold()<<endl;
	}
	//function to drop items in the grid in an empty space
	void drop(int gridnumber,int row,int col)
	{
		//attributes for checking if the location is empty
		string checkEmpty="";
		string option;
		string checkitemempty = ",";
		checkEmpty= arr[row][col]->getIdentifier();
		//displaying the inventory before player decision
		inventory();
		//getting the input from player for the item to be dropped
		cout<<"\nPlease enter the complete name of the item you wish to drop (Case Sensitive)"<<endl;
		cin>> option;
		int checkitem = Items.find(option); //checking if item is present in inventory
		//condition to check if the item entered is present in the inventory
		if(checkitem>-1 || option == "RingOfLife" || option == "RingOfStrength")
		{
			if(checkEmpty=="Empty") //checking if the grid is empty 
			{
				//dropping the sword from inventory and modifying player's attributes 
				if(option=="Sword")
				{
					arr[row][col]= new Item();
					arr[row][col]->setSword();
					player->setAttack(-10);
					player->setStrength(-10);
					//updating the inventory
					Items.replace(Items.find(option),option.length(),"");
					Items.replace(Items.find(checkitemempty),checkitemempty.length(),"");
					cout<<"\nThe Object dropped at location ["<<row<<"]"<<"["<<col<<"]: "<<option<<endl;
					counter1--;	
				}
				//dropping the dagger from inventory and modifying player's attributes 
				else if(option == "Dagger")
				{
					arr[row][col]= new Item();
					arr[row][col]->setDagger();
					player->setAttack(-5);
					player->setStrength(-5);	
					//updating the inventory
					Items.replace(Items.find(option),option.length(),"");
					Items.replace(Items.find(checkitemempty),checkitemempty.length(),"");
					cout<<"\nThe Object dropped at location ["<<row<<"]"<<"["<<col<<"]: "<<option<<endl;
					counter1--;
				}
				//dropping the platearmour from inventory and modifying player's attributes 
				else if(option == "PlateArmour")
				{
					arr[row][col]= new Item();
					arr[row][col]->setPlateArmour();
					player->setAttack(5);
					player->setDefence(-10);
					player->setStrength(-40);	
					//updating the inventory
					Items.replace(Items.find(option),option.length(),"");
					Items.replace(Items.find(checkitemempty),checkitemempty.length(),"");
					cout<<"\nThe Object dropped at location ["<<row<<"]"<<"["<<col<<"]: "<<option<<endl;
					counter2--;	
				}
				//dropping the leather armour and modifying player's attributes 
				else if(option == "LeatherArmour")
				{
					arr[row][col]= new Item();
					arr[row][col]->setLeatherArmour();
					player->setDefence(-5);
					player->setStrength(-20);
					//updating the inventory
					Items.replace(Items.find(option),option.length(),"");
					Items.replace(Items.find(checkitemempty),checkitemempty.length(),"");
					cout<<"\nThe Object dropped at location ["<<row<<"]"<<"["<<col<<"]: "<<option<<endl;
					counter2--;	
				}
				//dropping the large shield and modifying player's attributes 
				else if(option == "LargeShield")
				{
					arr[row][col]= new Item();
					arr[row][col]->setLargeShield();
					player->setAttack(5);
					player->setDefence(-10);
					player->setStrength(-30);
					//updating the inventory
					Items.replace(Items.find(option),option.length(),"");
					Items.replace(Items.find(checkitemempty),checkitemempty.length(),"");
					cout<<"\nThe Object dropped at location ["<<row<<"]"<<"["<<col<<"]: "<<option<<endl;
					counter3--;		
				}
				//dropping the small shield and modifying player's attributes 
				else if(option == "SmallShield")
				{
					arr[row][col]= new Item();
					arr[row][col]->setSmallShield();
					player->setDefence(-5);
					player->setStrength(-10);
					//updating the inventory
					Items.replace(Items.find(option),option.length(),"");
					Items.replace(Items.find(checkitemempty),checkitemempty.length(),"");
					cout<<"\nThe Object dropped at location ["<<row<<"]"<<"["<<col<<"]: "<<option<<endl;
					counter3--;		
				}	
				//dropping the ring of strength from inventory and modifying player's attributes 
				else if(option == "RingOfStrength")
				{
					arr[row][col]= new Item();
					arr[row][col]->setRingOfStrength();
					player->setHealth(10);
					player->setStrength(40);
					cout<<"\nThe Object dropped at location ["<<row<<"]"<<"["<<col<<"]: "<<option<<endl;
					counter4--;	
				}	
				//dropping the ring of life from inventory and modifying player's attributes 
				else if(option == "RingOfLife")
				{
					arr[row][col]= new Item();
					arr[row][col]->setRingOfLife();
					player->setHealth(-10);
					player->setStrength(-1);	
					cout<<"\nThe Object dropped at location ["<<row<<"]"<<"["<<col<<"]: "<<option<<endl;
					counter5--;	
				}
			}
		}
		//condition to check the item is present in inventory
		else
		{
			cout<<"Item not present in the Inventory"<<endl;
		}
		
	}
	//condition to pickup the items present in the grid
	void pickUp(int row,int col)
	{
		string itemname = "";
		itemname = arr[row][col]->getItemName();
			//adding the sword to inventory modifying player's attributes 
			if(itemname == "Sword" && counter1<1)
			{
				arr[row][col]= new Enemy();
				arr[row][col]->setEmpty();
				player->setAttack(10);
				player->setStrength(10);
				Items=Items + itemname + ",";	
				counter1++;	
			}
			//adding the dagger to inventory modifying player's attributes 
			else if(itemname == "Dagger" && counter1<1)
			{
				arr[row][col]= new Enemy();
				arr[row][col]->setEmpty();
				player->setAttack(5);
				player->setStrength(5);	
				Items=Items + itemname + ",";
				counter1++;
			}
			//adding the plate armour to inventory modifying player's attributes 
			else if(itemname == "PlateArmour" && counter2<1)
			{
				arr[row][col]= new Enemy();
				arr[row][col]->setEmpty();
				player->setAttack(-5);
				player->setDefence(10);
				player->setStrength(40);	
				Items=Items + itemname + ",";
				counter2++;	
			}
			//adding the leather armour to inventory modifying player's attributes 
			else if(itemname == "LeatherArmour" && counter2<1)
			{
				arr[row][col]= new Enemy();
				arr[row][col]->setEmpty();
				player->setDefence(5);
				player->setStrength(20);
				Items=Items + itemname + ",";	
				counter2++;	
			}
			//adding the large shield to inventory modifying player's attributes 
			else if(itemname == "LargeShield" && counter3<1)
			{
				arr[row][col]= new Enemy();
				arr[row][col]->setEmpty();
				player->setAttack(-5);
				player->setDefence(10);
				player->setStrength(30);
				Items=Items + itemname + ",";
				counter3++;		
			}
			//adding the small shield to inventory modifying player's attributes 
			else if(itemname == "SmallShield" && counter3<1)
			{
				arr[row][col]= new Enemy();
				arr[row][col]->setEmpty();
				player->setDefence(5);
				player->setStrength(10);
				Items=Items + itemname+ ",";
				counter3++;		
			}	
			//adding the ring of strength to inventory modifying player's attributes 
			else if(itemname == "RingOfStrength")
			{
				arr[row][col]= new Enemy();
				arr[row][col]->setEmpty();
				player->setHealth(-10);
				player->setStrength(-40);
				counter4++;	
			}
			//adding the ring of life to inventory modifying player's attributes 	
			else if(itemname == "RingOfLife")
			{
				arr[row][col]= new Enemy();
				arr[row][col]->setEmpty();
				player->setHealth(10);
				player->setStrength(1);	
				counter5++;	
			}
	}
	//function used to calculate if day or night and setting orc attributes accordingly
	void daynight(int row,int col,int count)
	{
		//attributes responsible to calculate day and night and setting orc's attributes
		int daynightresult=0;
		string orcdaynight="";
		string orcdaynightenemyType="";
		string orcdaynightenemy="";
		orcdaynight = player->getIdentifier();
		orcdaynightenemy = arr[row][col]->getIdentifier();
		daynightresult = count/5;
		//condition used to check if day or night based on counter value
		if(daynightresult%2!=0)
		{	
			cout<<"Its Night ("<<count<<")"<<endl;
			//setting the attributes for player orc at night
			if(orcdaynight=="Orc")
			{
				player->attack = 45;
				player->defence = 25;
				player->attackmax = 1;
				player->attackmin = 1;
				player->defencemax = 2 ;
				player->defencemin = 1;			
				player->orctype = "Night";
			}
			//setting the attributes for enemy orc at night
			if(orcdaynightenemy == "Orc")
			{
				arr[row][col]->attack= 45;
				arr[row][col]->defence = 25;
				arr[row][col]->orctype = "Night";
				arr[row][col]->attackmax = 1;
				arr[row][col]->attackmin = 1;
				arr[row][col]->defencemax = 2 ;
				arr[row][col]->defencemin = 1;
			}		
		}	
		else
		{
			cout<<"Its Morning ("<<count<<")"<<endl;
			//setting the attributes for player orc at day
			if(orcdaynight=="Orc")
			{
				player->attack = 25;
				player->defence = 10;
				player->orctype = "Day";
				player->attackmax = 4;
				player->attackmin = 1;
				player->defencemax = 4 ;
				player->defencemin = 1;	
			}
			//setting the attributes for enemy orc at day
			if(orcdaynightenemy =="Orc")
			{
				arr[row][col]->attack= 25;
				arr[row][col]->defence = 10;
				arr[row][col]->orctype = "Day";
				arr[row][col]->attackmax = 4;
				arr[row][col]->attackmin = 1;
				arr[row][col]->defencemax = 4 ;
				arr[row][col]->defencemin = 1;
			}
		}	
	}
	//fetching the current position of the player based on row and column
	void currentPosition(int row,int col)
	{
		cout<<"The current position of the player is at: ["<<row<<"]"<<"["<<col<<"]"<<endl;;
	}
	//fetching the details of the enemy encounter based on location
	void showEnemy(int row,int col)
	{
		cout<<"Enemy: "<<arr[row][col]->getIdentifier()<<"; Attack: "<<arr[row][col]->getAttack()<<", Defence: "<<arr[row][col]->getDefence()<<", Health: "<<arr[row][col]->getHealth()<<", Strength: "<<arr[row][col]->getStrength()<<endl;
	}
	//used for checking the contents of grid location
	void checkLook(char pos, int size,int row,int col)
	{
		if(((pos=='N')&&(row>=0)) || ((pos=='S')&&(row<size)) || ((pos=='E')&&(col<size)) || ((pos=='W')&&(col>=0)))
		{
			string player="",item="";
			player=arr[row][col]->getIdentifier();
			item=arr[row][col]->getItemName();
			//checking if enemy present and empty space
			if(player!="" && player!="Empty")
			{
				cout<<"\n\nThere is an enemy in this space: "<<player<<endl;
				showEnemy(row,col);
			}
			//checking if the location contains an item
			else if (item!="")
			{ 
				cout<<"\n\nThere is an Item in this space: "<<item<<endl;
				cout<<"The weight of the Item present is: "<<arr[row][col]->getweight()<<endl;
			}
			//location contains empty space
			else
			{
				cout<<"\n\nThis box is empty"<<endl;
			}
		}
	}
};
