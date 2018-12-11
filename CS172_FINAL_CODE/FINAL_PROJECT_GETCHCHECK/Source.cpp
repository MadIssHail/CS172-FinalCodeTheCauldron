#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void move();

int main()
{
	while (true)
	{
		int ch;

		while ((ch = _getch()) != 27) /* 27 = Esc key */
		{
			printf("%d", ch);
			if (ch == 0 || ch == 224)
				printf(", %d", _getch());
			printf("\n");
		}

		printf("ESC %d\n", ch);

		return (0);
	}
}

void move()
{
	switch (_getch())
	{
	case 1: //up - y-- if(x >= dimension or y>= demension) based on what case you're in
		break;
	case 2: //down - y++
		break;
	case 3: //left - x--
		break;
	case 4: //right - x++
		break;
	default:  //do nothing
		break;
	}
}