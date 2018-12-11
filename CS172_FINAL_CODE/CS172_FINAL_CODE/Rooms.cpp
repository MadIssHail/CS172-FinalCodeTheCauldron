#include "Rooms.h"

#include <ctime>



Rooms::Rooms()
{
	puzzle.x = (rand() % 20); //Place the puzzle inside the bounds of the wall
	puzzle.y = (rand() % 10);
	exit.x = 19; //Place the exit somewhere along the right wall
	exit.y = (rand() % 10);
}

void Rooms::print(location p1)  //Display function. The compiler runs through every space on the screen to find where
{								//the player, the exit, the puzzle, the walls, and the floor all go
	NumberPuzzle np1;
	Riddle r1;
	system("cls");
	for (int y = -1; y <= 10; y++)
	{
		for (int x = -1; x <= 20; x++)
		{
			if ((p1.x == x) && (p1.y == y))
			{
				cout << playerChar;
			}
			else if ((puzzle.x == x) && (puzzle.y == y))
			{
				if (roomPuzzle == 0)
				{
					if (rand1 == 1)
						np1.shape();
					else
						r1.shape();
				}
				else cout << " ";
			}
			else if ((exit.x == x) && (exit.y == y))
			{
				cout << exitChar;
			}
			else if ((x == -1) || (x == 20) || (y == -1) || (y == 10))
			{
				cout << wallChar;
			}
			else
				cout << floorChar;
		}
		cout << endl;
	}
}

bool Rooms::activateExit(location p1)
{
	if (roomPuzzle == true)  //If the puzzle has been solved
	{
		if (isExit(p1) == true)  //An the player is standing on the exit
		{
			return true;
		}
	}
	return false;
}

void Rooms::changeRoom(location p1, int roomCount)
{
	if (activateExit(p1) == true)
	{
		roomPuzzle = false; //Set the visibility of the puzzle in the new room
		rand1 = rand() % 2; //Pick a new puzzle type
		puzzle.x = (rand() % 19) + 1; //Change the location of the puzzle
		puzzle.y = (rand() % 9) + 1;
		roomCount++;  //Move through the rooms in the dungeon
	}
}

bool Rooms::isExit(location p1) //True if the player is standing on the exit
{
	return ((p1.x == exit.x) && (p1.y == exit.y));
}

bool Rooms::isPuzzle(location p1) //True if the player is standing on the puzzle
{
	return ((p1.x == puzzle.x) && (p1.y == puzzle.y));
}

void Rooms::accessPuzzle(location p1)
{
	string userAnswerR;
	int userAnswerN;
	int rand2;  //Use random numbers to access the different puzzles in the vector
	rand2 = (rand() % 2);
	if (isPuzzle(p1) == true)
	{
		if (rand1 == 1)   //Number Puzzle 
		{
			if (rand2 == 0)  //Number Puzzle #1
			{
				ifstream fin;
				string file;
				fin.open("C:/Users/Madi/Desktop/School/CS172/CS172_FINAL_PROJECT/CS172_FINAL_CODE/NumberPuzzle1.txt");
				while (getline(fin, file))
				{
					cout << file;
				}
				cin >> userAnswerN;
				if (userAnswerN == 34)
				{
					cout << "that's correct!";
					roomPuzzle = 1;
				}

			}
			else if (rand2 == 1) //Number Puzzle #2
			{
				ifstream fin;
				string file;
				fin.open("C:/Users/Madi/Desktop/School/CS172/CS172_FINAL_PROJECT/CS172_FINAL_CODE/NumberPuzzle2.txt");
				while (getline(fin, file))
				{
					cout << file;
				}
				cin >> userAnswerN;
				if (userAnswerN == 12)
				{
					cout << "that's correct!";
					roomPuzzle = 1;
				}
			}
		}
		else if (rand1 == 0)  //Riddle
		{
			if (rand2 == 0)  //Riddle #1
			{
				ifstream fin;
				string file;
				fin.open("C:/Users/Madi/Desktop/School/CS172/CS172_FINAL_PROJECT/CS172_FINAL_CODE/Riddle1.txt");
				while (getline(fin, file))
				{
					cout << file;
				}
				cin >> userAnswerR;
				if ((userAnswerR == "a towel") || (userAnswerR == "towel")) //Accepts answer with player nuance
				{
					cout << "that's correct!";
					roomPuzzle = 1;
				}
			}
			else if (rand2 == 1)  //Riddle #2
			{
				ifstream fin;
				string file;
				fin.open("C:/Users/Madi/Desktop/School/CS172/CS172_FINAL_PROJECT/CS172_FINAL_CODE/Riddle2.txt");
				while (getline(fin, file))
				{
					cout << file;
				}
				cin >> userAnswerR;
				if ((userAnswerR == "a river") || (userAnswerR == "river"))
				{
					cout << "that's correct!";
					roomPuzzle = 1;
				}
			}
		}
	}
}