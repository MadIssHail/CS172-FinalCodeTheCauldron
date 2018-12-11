#ifndef PLAYER_H_
#define PLAYER_H_
#include <conio.h>
using namespace std;

struct location
{
	int x;
	int y;
};

class Player
{
private:
	location l;
public:
	void setLocation(int xP, int yP);
	location getLocation();
	void move();
};

#endif