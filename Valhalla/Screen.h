//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
// 
// (c) 2005 - 2015 Media Design School
// 
// File name   : Screen.h
// Description : Setting styles for the console (color, size, etc.)
// Author      : Juan Rodriguez
// Mail        : juan.rod6618@mediadesignschool.com
// 

#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
#include <iostream>
#include <fstream>

#include "Gamepad.h"

// 16 Bit color palette (used in the 'setColor' function)
enum eColor {
	BLACK = 0,
	DBLUE = 1,
	DGREEN = 2,
	DTEAL = 3,
	DRED = 4,
	DPINK = 5,
	DYELLOW = 6,
	GRAY = 7,
	DGRAY = 8,
	BLUE = 9,
	GREEN = 10,
	TEAL = 11,
	RED = 12,
	PINK = 13,
	YELLOW = 14,
	WHITE = 15
};

// Setting the size of the window
void SetWindowSize(int _iWidth, int _iHeight);

// Setting the color for our screen
void SetColor(int _iColor);

// Going to a desired position in the screen
// Hiding the cursor is optional
void gotoxy(int _iX, int _iY, bool _bHideCursor);

// Clearing the console on the right side of the screen
void ClearScreen(int _startX, int _startY, int _endX, int _endY);

// String to Integer conversion, used in menu options
int GetChoice(
	const char* _rStrInput,
	const char* _strPhrase,
	int _iX,
	int _iY,
	int _iXoffset,
	int _iYoffset
);

// Receiving an input with limited characters
// Takes additional <x, y> values
std::string GetText(int _iX, int _iY, int _iLim);

// Receiving input directly from a keyboard or gamepad
int Cursor(int _iX, int _iY, int _iChoices, CGamepad* _gamepad);

// Prompts for confirmation
void ConfirmRETURN(int _iX, int _iY, CGamepad* _gamepad);

// Printing from a text file
// Must be written in lowercase
void PrintFromFile(int _iX, int _iY, int _iColor, std::string _file);

///////////////////////////////////////////////////////////////////////////
// Since the next functions are just for printing,                       //
// The arguments are the same through the overloads where they're found  //
// @param _iX the 'x' coordinate to print at                             //
// @param _iY the 'y' coordinate to print at                             //
// @param _iColor the color to set the text								 //
// @param _text the information of the text								 //
///////////////////////////////////////////////////////////////////////////

template<typename T>
void printAt(const int _iX, const int _iY, const int _iColor, const T& _text) {

	SetColor(_iColor);
	gotoxy(_iX, _iY, true);
	std::cout << _text;
	SetColor(WHITE);

}

template<typename T>
void printAt(const int _iX, const int _iY, const T& _text) {

	gotoxy(_iX, _iY, true);
	std::cout << _text;
	SetColor(WHITE);

}

template<typename T>
void print(const int _iColor, const T& _text) {

	SetColor(_iColor);
	std::cout << _text;
	SetColor(WHITE);

}

template<typename T>
void print(const T& _text) {

	std::cout << _text;

}

#endif //__SCREEN_H__