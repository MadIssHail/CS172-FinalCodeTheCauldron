#include "Dungeon.h"

Dungeon::Dungeon()
{
}

void Dungeon::runGame() //This is the big function that once I call, it calls all the other functions I'm actually using
{
	cout << "Welcome to Cauldron! This is a puzzle RPG.  Please explore the board and when you find a puzzle, solve it!" << endl;
	cout << "Then, once there's nothing left to explore, head on over to the next room."<< endl;
	int roomNumber = 0;
	while (roomNumber <= dRooms.size())  
	{
		player1.move();														//Every time the player moves:
		dRooms[roomNumber].print(player1.getLocation());					//1. Print the screen
		dRooms[roomNumber].isPuzzle(player1.getLocation());					//2. Check for puzzles
		dRooms[roomNumber].isExit(player1.getLocation());					//3. Check for exits
		dRooms[roomNumber].accessPuzzle(player1.getLocation());				//4. Try to open the puzzle (if the player is standing on it)
		dRooms[roomNumber].activateExit(player1.getLocation());				//5. Try to exit (if the player stands on it and the puzzle is solved)
		dRooms[roomNumber].changeRoom(player1.getLocation(), roomNumber);	//6. If the exit is activated, switch rooms
	}
	cout << "game won" << endl;
}

void Dungeon::makeRoom(int room)  //Creates a dungeon of a certain size
{
	for (int i = 0; i < room; i++)
	{
		dRooms.push_back(Rooms());
	}
}