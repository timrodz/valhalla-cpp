//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// 
// (c) 2005 - 2015 Media Design School
// 
// File name   : Screen.cpp
// Description : Functions for the window
// Author      : Juan Rodriguez
// Mail        : juan.rod6618@mediadesignschool.com
// 

// Library includes
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

// C/C++ libraries
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// Local includes
#include "Screen.h"

// Defining our console handle, cursor position and coordinates to position the cursor to
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cursor;
XButtonIDs g_button;
COORD coord;

// Prompts for confirmation
// @param _iWidth  the width  of the screen
// @param _iHeight the height of the screen
// @return void
void SetWindowSize(int _iWidth, int _iHeight) {

	SMALL_RECT rect;
	COORD coord = {
		(short)_iWidth,
		(short)_iHeight
	};

	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (!GetConsoleScreenBufferInfo(consoleHandle, &csbi)) {

		throw std::runtime_error("Fatal error.");

	}

	rect.Left = 0;
	rect.Top = 0;
	rect.Right = _iWidth - 1;
	rect.Bottom = _iHeight - 1;
	// Non resizable
	SetConsoleWindowInfo(consoleHandle, TRUE, &rect);
	// Set the size after that
	SetConsoleScreenBufferSize(consoleHandle, coord);

}

// Setting the color for text
// @param _iColor the color code
// @return void
void SetColor(int _iColor) {

	SetConsoleTextAttribute(consoleHandle, _iColor);

}

// Going to a desired position in the screen and hiding the cursor if desired
// @param _iX the 'x' coordinate to print at
// @param _iY the 'y' coordinate to print at
// @param _bHideCursor true for hiding, false for showing
// @return void
void gotoxy(int _iX, int _iY, bool _bHideCursor) {

	if (_bHideCursor == true) {

		cursor.bVisible = false;
		cursor.dwSize = 1;

	}
	else {

		cursor.bVisible = true;
		cursor.dwSize = 20;

	}

	std::cout.flush();
	coord.X = _iX;
	coord.Y = _iY;
	SetConsoleCursorInfo(consoleHandle, &cursor);
	SetConsoleCursorPosition(consoleHandle, coord);

}

// Clearing the console on a specific part of the screen
// @param _startX the first position of x
// @param _startY the first position of y
// @param _endX the last position of x
// @param _endY the last position of y
// @return void
void ClearScreen(int _startX, int _startY, int _endX, int _endY) {

	for (int i = _startX; i < _endX; ++i) {

		for (int j = _startY; j <= _endY; ++j) {

			printAt(i, j, " ");

		}

	}

}

// Receiving an input with limited characters
// @param _iX the 'x' coordinate to print at
// @param _iY the 'y' coordinate to print at
// @param _iLim the limit of characters that can be input
// @return const char*
std::string GetText(int _iX, int _iY, int _iLim) {

	// String index
	int stringIndex = 0;
	// Our string to return
	std::string stringToAppend;
	// Our character that we'll append to 's'
	char charToRead;
	// Current and previous color
	int currentColor = PINK;
	int prevColor = currentColor;

	while (true) {

		gotoxy(_iX, _iY, false);
		charToRead = _getch();

		// We make sure we've more than 0 letters 
		// (otherwise we'll be popping a null object)
		if ((charToRead == 8) && (stringIndex > 0)) {

			// Pop the last element of our list
			stringToAppend.pop_back();
			// Iterate back to our last position
			stringIndex--;
			_iX--;
			printAt(_iX, _iY, " ");

		}
		else if ((charToRead == 8) && (stringIndex == 0)) {
			// Nothing happens (on purpose)
		}
		else {
			// This limits the amount of characters that
			// our input can receive (change 1 to desired limit)
			if (stringIndex != _iLim) {

				// we push our character into our stack
				stringToAppend.push_back(charToRead);
				stringIndex++;
				_iX++;
				// Uppercase conversion
				// We do this for every non-digit using the isdigit(std::string) function
				// index - 1 because arrays are counted starting from 0, otherwise we can just use 'index'
				if (!(isdigit(stringToAppend[stringIndex]))) {

					stringToAppend[stringIndex - 1] = toupper(stringToAppend[stringIndex - 1]);

				}

			}

		}

		gotoxy(_iX - 1, _iY, false);
		if (stringIndex - 1 != -1) {

			SetColor(currentColor);
			std::cout << stringToAppend[stringIndex - 1];

		}

		if (charToRead == 13) {

			/*std::cout << std::endl;
			std::cout.flush();*/
			return stringToAppend;
			//return stringToAppend.c_str();

		}
		else if (charToRead == 27) {

			return "~/.";

		}

		// Whenever the player deletes every letter, change the following colors
		if (stringIndex == 0) {

			// Randomly change the colors
			currentColor = (rand() % 15 + 1);
			// Making sure they don't repeat
			while (currentColor == prevColor) { currentColor = (rand() % 14 + 1); }
			// After a new color's been set, asign it to the previous
			prevColor = currentColor;
			srand(static_cast<unsigned int>(time(NULL)));

		}

	}

}

// Receiving input directly from a keyboard or gamepad
int Cursor(int _iX, int _iY, int _iChoices, CGamepad* _gamepad) {

	SetColor(WHITE);

	int iLastY = _iY;
	int tempY = _iY;
	int iChoice = 1;

	char cKey;

	bool hasPressedAKey = false;

	printAt(_iX, _iY, ">");

	while (true) {

		// Gamepad control
		if ((_gamepad->IsConnected()) && (_gamepad->IsActive())) {

			_gamepad->Update();

			// Go up
			if ((_gamepad->LeftStick_Y() > 0.5f) || (_gamepad->IsButtonDown(g_button.DPad_Up))) {

				printAt(_iX, iLastY, " ");
				_iY--;
				iLastY = _iY;
				printAt(_iX, _iY, ">");
				iChoice--;
				hasPressedAKey = true;

			}
			// Go down
			else if ((_gamepad->LeftStick_Y() < -0.5f) || (_gamepad->IsButtonDown(g_button.DPad_Down))) {

				printAt(_iX, iLastY, " ");
				_iY++;
				iLastY = _iY;
				printAt(_iX, _iY, ">");
				iChoice++;
				hasPressedAKey = true;

			}

			if (_gamepad->IsButtonDown(g_button.A)) {

				_gamepad->Update();
				_gamepad->RefreshState();
				return iChoice;

			}

			_gamepad->RefreshState();

		}
		// Keyboard control
		// Character codes
		// 72 = UP
		// 80 = DOWN
		// 13 = ENTER
		else {

			cKey = _getch();

			// Up
			if (cKey == 72) {

				printAt(_iX, iLastY, " ");
				_iY--;
				iLastY = _iY;
				printAt(_iX, _iY, ">");
				iChoice--;
				hasPressedAKey = true;

			}
			else if (cKey == 80) {

				printAt(_iX, iLastY, " ");
				_iY++;
				iLastY = _iY;
				printAt(_iX, _iY, ">");
				iChoice++;
				hasPressedAKey = true;

			}
			else if (cKey == 13) {

				return iChoice;

			}

		}

		// Go back to the last option
		if (_iY == tempY - 1) {

			printAt(_iX, _iY, " ");
			iChoice = 4;
			_iY = tempY + _iChoices - 1;
			iLastY = _iY;
			printAt(_iX, _iY, ">");

		}
		// Go back to the first option
		else if (_iY == tempY + _iChoices) {

			printAt(_iX, _iY, " ");
			iChoice = 1;
			_iY = tempY;
			iLastY = _iY;
			printAt(_iX, _iY, ">");

		}

		if (hasPressedAKey == true) {

			hasPressedAKey = false;
			Sleep(150);

		}

	}

}

/// Reading strings
// String to Int with Comparison
// @param _rStrInput the string to read
// @param _strPhrase the phrase to display if an error occurs
// @param _iX the 'x' coordinate to print at
// @param _iY the 'y' coordinate to print at
// @param _iXoffset the 'x' offset to clear the previous text
// @param _iYoffset the 'y' offset to display the error text (_strPhrase)
int GetChoice(const char* _rStrInput, const char* _strPhrase, int _iX, int _iY, int _iXoffset, int _iYoffset) {

	int iNumber;

	while (true) {
		// Accessing the string value of a stringstream is done by calling the 'str' method
		std::stringstream stream(GetText(_iX, _iY, 1));
		SetColor(WHITE);
		if (stream.str() == "~/.") {

			return NULL;

		}
		// string stream to integer shift
		if (stream >> iNumber) {

			return iNumber;
			printAt(_iX, _iY, " ");

		}
		else {

			printAt(_iX, _iY, " ");
			printAt(_iX - _iXoffset, _iY + _iYoffset, _strPhrase);

		}

	} // while end

}

void PrintFromFile(int _iX, int _iY, int _iColor, std::string _fileName) {

	std::string sLineToRead;
	std::ifstream file;
	file.open("../TextFiles/" + _fileName + ".txt");

	if (file.is_open()) {

		while (getline(file, sLineToRead)) {

			gotoxy(_iX, _iY, true);
			SetColor(_iColor);
			std::cout << sLineToRead;
			_iY++;

		}

	}
	else {

		gotoxy(0, 40, true);
		std::cout << "File " << _fileName << "not found!";

	}

}

// Prompts for confirmation
// @param _iX the 'x' coordinate to print at
// @param _iY the 'y' coordinate to print at
// @return void
void ConfirmRETURN(int _iX, int _iY, CGamepad* _gamepad) {

	printAt(_iX, _iY, WHITE, "Press ");
	print(GREEN, "ENTER");
	print(WHITE, " / ");
	print(GREEN, "(A)");
	print(WHITE, " to continue");

	while (true) {

		// Gamepad
		if ((_gamepad->IsConnected()) && (_gamepad->IsActive())) {

			_gamepad->Update();

			if (_gamepad->IsButtonDown(g_button.A)) {
				break;
			}

			_gamepad->RefreshState();

		}
		// Keyboard
		else {

			printAt(_iX, _iY, WHITE, "Press ");
			print(RED, "ENTER / RETURN");
			print(WHITE, " to continue> ");

			while (_getch() != 13) {
				break;
			}

		}

	}



}