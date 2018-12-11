#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h> 
#include <Wincon.h>
#include "Player.h"
#include "Rooms.h"
#include "Dungeon.h"
#include "Puzzle.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Dungeon d1;
	d1.makeRoom(4);
	d1.runGame();
	system("pause");
}