// Libraries
#include <iostream>
#include <string>

// Framework
#include "Gamepad.h"
#include "Screen.h"
#include "Game.h"
#include "Menu.h"

// Entities
#include "Monster.h"
#include "Player.h"

// Entity - Data


// Namespaces
using std::cout;
using std::endl;

// Constants
const int WIDTH = 80;
const int HEIGHT = 40;
const int INV_HEIGHT = HEIGHT - (HEIGHT / 3) + 1;

int main() {

	// Global variables
	bool bIsRunning = true;

	// Menu variables //
	CMenu* Menu;
	// Choice of the menu
	int iMenuChoice;
	int iMenuX;
	int iMenuY;
	int iMenuCursorX;
	int iMenuCursorY;

	// Game variables //
	// Gamepad input for the player
	CGamepad* Gamepad;

	// Option variables //
	int iOptionChoice;
	int iOptionX;
	int iOptionY;
	int iOptionCursorX;
	int iOptionCursorY;

	// Setting up the size of the screen before starting the game
	SetWindowSize(WIDTH, HEIGHT + 1);

	while (bIsRunning == true) {

		Menu = new CMenu;
		Gamepad = new CGamepad(1);
		// Drawing the menu
		Menu->DrawRectangle(0, 0, WIDTH, HEIGHT, '#');

		// Initializing main menu variables
		iMenuX = 4;
		iMenuY = INV_HEIGHT + 2;
		iMenuCursorX = iMenuX - 2;
		iMenuCursorY = iMenuY;

		// Initializing options menu variables
		iOptionX = 4;
		iOptionY = INV_HEIGHT + 2;
		iOptionCursorX = iOptionX - 2;
		iOptionCursorY = iOptionY;

		while (true) {

			// - MAIN MENU - //
			PrintFromFile(3, 4, RED, "menu");
			Menu->DrawLine(0, WIDTH, INV_HEIGHT);
			printAt(iMenuX, iMenuY, TEAL, "1"); print(") Play the game"); iMenuY++;
			printAt(iMenuX, iMenuY, TEAL, "2"); print(") Options"); iMenuY++;
			printAt(iMenuX, iMenuY, TEAL, "3"); print(") Credits"); iMenuY++;
			printAt(iMenuX, iMenuY, TEAL, "4"); print(") Exit"); iMenuY++;
			
			iMenuChoice = Cursor(iMenuCursorX, iMenuCursorY, 4, Gamepad);
			
			//printAt(iMenuX, iMenuY, "> ");

			//iMenuChoice = GetChoice(" ", "Try again", iMenuX + 2, iMenuY, iMenuX, 1);

			// Start game
			if (iMenuChoice == 1) {

				CGame* game = new CGame;
				game->Start();
				Menu->DrawRectangle(40, 2, WIDTH - 3, 14, '$');
				Menu->DrawRectangle(3, 15, 39, INV_HEIGHT - 1, '@');

				ConfirmRETURN(23, HEIGHT - 3, Gamepad);

			}
			// Options
			else if (iMenuChoice == 2) {

				ClearScreen(1, 1, WIDTH - 1, HEIGHT - 2);
				PrintFromFile(5, 4, TEAL, "options");
				iOptionChoice = Cursor(iOptionCursorX, iOptionCursorY, 4, Gamepad);
				break;

			}
			// Credits
			else if (iMenuChoice == 3) {

				ClearScreen(1, 1, WIDTH - 1, HEIGHT - 2);
				PrintFromFile(5, 8, TEAL , "credits_1");
				PrintFromFile(5, 20, WHITE, "credits_2");
				ConfirmRETURN(23, HEIGHT - 3, Gamepad);
				ClearScreen(1, 1, WIDTH - 1, HEIGHT - 2);
				break;

			}
			// Exit
			else if (iMenuChoice == 4) {

				ClearScreen(1, 1, WIDTH - 1, HEIGHT - 2);
				PrintFromFile(5, 4, RED, "exit");
				ConfirmRETURN(23, HEIGHT - 3, Gamepad);
				ClearScreen(1, 1, WIDTH - 1, HEIGHT - 2);
				bIsRunning = false;
				break;

			}
			else {

				printAt(iMenuX + 2, iMenuY, " ");

			}

		}

	}

	return (0);

}