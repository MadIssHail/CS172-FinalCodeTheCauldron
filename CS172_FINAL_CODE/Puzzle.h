#ifndef PUZZLE_H_
#define PUZZLE_H_
#include <iostream>
#include <string>
using namespace std;

class Puzzle
{
protected:
public:
	Puzzle()
	{
	}
	virtual void shape() = 0; //Make it so the player knows whether they're solving a riddle or a puzzle
};

class Riddle : public Puzzle
{
private:
	char riddleChar = 'R';
public:

	void shape()
	{
		cout << riddleChar;
	}
};

class NumberPuzzle : public Puzzle
{
private:
	char NPuzzleChar = 'P';
public:

	void shape()
	{
		cout << NPuzzleChar;
	}
};

#endif