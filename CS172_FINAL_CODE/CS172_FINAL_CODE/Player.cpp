#include "Player.h"

void Player::setLocation(int xP, int yP)
{
	if ((xP <= 19) && (xP >= 0))  //Keeps the player inside the bounds of the walls
	{
		if ((yP <= 9) && (yP >= 0))
		{
			l.x = xP;
			l.y = yP;
		}
	}
}

location Player::getLocation()
{
	return l;
}

void Player::move()
{
	switch (_getch())  //From stank overflow. The case values are the ASCII values of the WASD keys as specified
	{
	case 119: //up - y-- W = 119
		setLocation(l.x, l.y - 1);
		break;
	case 115: //down - y++ S = 115
		setLocation(l.x, l.y + 1);
		break;
	case 97: //left - x-- A = 97
		setLocation(l.x - 1, l.y);
		break;
	case 100: //right - x++ D = 100
		setLocation(l.x + 1, l.y);
		break;
	default:  //do nothing}
		break;
	}
}