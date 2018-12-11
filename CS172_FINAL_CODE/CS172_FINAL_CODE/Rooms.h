#ifndef ROOMS_H_
#define ROOMS_H_
#include "Player.h"
#include "Puzzle.h"
#include <fstream>
#include <ctime>
using namespace std;

class Rooms
{
private:
	location exit, puzzle;
	char playerChar = 'x';
	char wallChar = '|';
	char floorChar = ' ';
	char exitChar = '}';
	bool roomPuzzle = false;
public:
	Rooms();
	int rand1 = (rand() % 2);
	void print(location p1);

	//returns true if at the exit and puzzle is solved. Else false.
	bool activateExit(location p1);

	void changeRoom(location p1, int roomCount);

	bool isExit(location p1);

	bool isPuzzle(location p1);

	void accessPuzzle(location p1);
};


#endif