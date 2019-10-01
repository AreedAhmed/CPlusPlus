all:run

#setting name for final game
run: fantasyRPG
	./fantasyRPG

#Linking all object files of classes
fantasyRPG: Combat.o Enemy.o Item.o BoardGame.o main.cpp
	g++ -ggdb -Wall -o fantasyRPG Combat.o Enemy.o Item.o BoardGame.o main.cpp

#Creating the object files of classes
Combat.o: Combat.h Combat.cpp
	g++ -ggdb -Wall -c Combat.cpp
Enemy.o: Enemy.h Enemy.cpp
	g++ -ggdb -Wall -c Enemy.cpp
Item.o: Item.h Item.cpp
	g++ -ggdb -Wall -c Item.cpp
BoardGame.o: BoardGame.h BoardGame.cpp
	g++ -ggdb -Wall -c BoardGame.cpp

#cleaning .o extensions
clean:
	rm *.o *~
