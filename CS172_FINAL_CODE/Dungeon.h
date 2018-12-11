#ifndef DUNGEON_H_
#define DUNGEON_H_
#include "Rooms.h"
#include "Player.h"
#include <vector>
#include "Puzzle.h"
#include "Rooms.h"
using namespace std;
class Dungeon
{
private:
	vector<Rooms> dRooms;
	Player player1;
public:
	Dungeon();
	void runGame();
	void makeRoom(int room);
};

#endif

