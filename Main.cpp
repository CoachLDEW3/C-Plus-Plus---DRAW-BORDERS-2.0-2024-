/************************************************************************************************
	Name:		Larry D Emory
	Date:		07.24.2024
	Purpose:	This is an updated version of my first Draw Borders program.  Now it the program
				accepts parameters.  All that is necessary is to make a function call and enter
				the desired width and height
*************************************************************************************************/

#include <iostream>			//This library contains standard input and output processes
#include <conio.h>			//This library contains the function to detect keypresses
#include <Windows.h>		//This library contains the function to control the cursor position
#include <random>			//This library is part of the pseudo-random number generation
#include <list>				//This library contains the functions for lists


using namespace std;


//Function to hide the cursor
void HideCursor()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);		//Get the ID of the console window
	//Data Structure that controls the apearance of the cursor.  It has two attributes dwSize and bVisible
	CONSOLE_CURSOR_INFO cursor;
	//This attribute changes the size of the cursor. Here it is set at 100%
	cursor.dwSize = 100;
	//This Boolean attribute sets the cursor to visible or invisible.  False is invisible
	cursor.bVisible = false;

	//Manipulates the characteristics it takes two parameters.  The ID of the console window and a data structure that
	//handles the appearance of the cursor
	//You have to pass the cursor variable by reference so that it can make changes to the actual object
	SetConsoleCursorInfo(hCon, &cursor);
}//End HideCursor()


void GoToXY(double x, double y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);		//Get the ID of the console window

	COORD coord;								//Variable of type COORD that holds the X and Y position
	coord.X = x;
	coord.Y = y;

	//Takes two parameters.  The ID of the console window and Structure of the type COORD which are the coordinates where
	//we want to position the cursor.	
	SetConsoleCursorPosition(hCon, coord);
}//End GoToXY


void DrawBorders(int width, int height)
{
	int tAndB = 205;			//Character code for top and bottom borders
	int lAndR = 186;			//Character code for left and right borders
	int topLeft = 201;			//Character code for top left corner
	int botLeft = 200;			//Character code for bottom left corner
	int topRight = 187;			//Character code for top right corner
	int botRight = 188;			//Character code for bottom right corner

	//Top & Bottom Borders
	for (int i = 2; i < width - 1; i++)
	{
		GoToXY(i, 3);
		cout << (char)tAndB;

		GoToXY(i, (height - 2));
		cout << (char)tAndB;
	}

	//Left & Right Borders
	for (int j = 4; j < (height - 2); j++)
	{
		GoToXY(2, j);
		cout << (char)lAndR;

		GoToXY((width - 1), j);
		cout << (char)lAndR;
	}

	//Corners
	//Top Left
	GoToXY(2, 3);
	cout << (char)topLeft;

	//Bottom Left
	GoToXY(2, (height - 2));
	cout << (char)botLeft;

	//Top Right
	GoToXY((width - 1), 3);
	cout << (char)topRight;

	//Bottom Right
	GoToXY((width - 1), (height - 2));
	cout << (char)botRight;
}//End DrawBorders()


int main()
{
	//Change Console Title 
	SetConsoleTitle(L"Draw Borders");
	//Hides the cursor
	HideCursor();
	//Draws the borders
	DrawBorders(30, 30);




	bool gameOver = false;

	//Game Loop.  While the game is not over do...
	while (!gameOver)
	{
		//Hit the escape key to end the program
		if (GetAsyncKeyState(VK_ESCAPE)) gameOver = true;		
	}
	return 0;
}