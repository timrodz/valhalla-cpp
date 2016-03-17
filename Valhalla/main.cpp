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

			// Initializing main menu variables
			iMenuChoice = 0;
			iMenuX = 4;
			iMenuY = INV_HEIGHT + 2;
			iMenuCursorX = iMenuX - 2;
			iMenuCursorY = iMenuY;

			ClearScreen(1, 1, WIDTH - 1, HEIGHT - 2);

			Menu->DrawLine(1, WIDTH, iMenuY - 2);

			PrintFromFile(4, 4, RED, "menu");

			// Choices
			printAt(iMenuX, iMenuY, RED, "1"); print(") Play the game"); iMenuY++;
			printAt(iMenuX, iMenuY, RED, "2"); print(") Options"); iMenuY++;
			printAt(iMenuX, iMenuY, RED, "3"); print(") Credits"); iMenuY++;
			printAt(iMenuX, iMenuY, RED, "4"); print(") Exit");

			iMenuChoice = Cursor(iMenuCursorX, iMenuCursorY, 4, Gamepad);

			// Start game
			if (iMenuChoice == 1) {

				CGame* game = new CGame;
				game->start();

				ConfirmRETURN(23, HEIGHT - 3, Gamepad);

			}
			// Options
			else if (iMenuChoice == 2) {

				// Initializing options menu variables
				iOptionChoice = 0;
				iOptionX = 4;
				iOptionY = 14;
				iOptionCursorX = iOptionX - 2;
				iOptionCursorY = iOptionY;

				ClearScreen(1, 1, WIDTH - 1, HEIGHT - 2);
				Menu->DrawLine(1, WIDTH - 1, iOptionY - 2);
				Menu->DrawLine(1, WIDTH - 1, iOptionY + 4);

				PrintFromFile(4, 4, TEAL, "options");
				//printAt(iOptionX, iOptionY, RED, "1"); print(") Enable tutorial"); iOptionY++;
				printAt(iOptionX, iOptionY, RED, "1"); print(") Toggle gamepad"); iOptionY++;
				printAt(iOptionX, iOptionY, RED, "2"); print(") Back to main menu");

				// Choices
				while (true) {

					// Print gamepad state
					if (Gamepad->IsConnected()) {

						printAt(50, iOptionY - 1, WHITE, "[");

						if (Gamepad->IsActive()) {
							printAt(iOptionCursorX, iOptionCursorY + 1, " ");
							printAt(51, iOptionY - 1, GREEN, "ON ");
							printAt(53, iOptionY - 1, WHITE, "] ");
						}
						else {
							printAt(iOptionCursorX, iOptionCursorY + 1, " ");
							printAt(51, iOptionY - 1, RED, "OFF");
							printAt(54, iOptionY - 1, WHITE, "]");
						}

					}
					else {
						print(RED, "NOT FOUND");
					}

					iOptionChoice = Cursor(iOptionCursorX, iOptionCursorY, 2, Gamepad);

					if (iOptionChoice == 1) {

						// Gamepad found
						if (Gamepad->IsConnected()) {

							if (Gamepad->IsActive()) {
								Gamepad->SetIsActive(false);
							}
							else {
								Gamepad->SetIsActive(true);
							}

						}
						// Gamepad not found
						else {
							printAt(iOptionX, iOptionY + 1, "Gamepad not found! Try again.");
						}

					}
					else {
						break;
					}

					iOptionChoice = 0;

				}

				break;

			}
			// Credits
			else if (iMenuChoice == 3) {

				ClearScreen(1, 1, WIDTH - 1, HEIGHT - 2);
				PrintFromFile(4, 8, RED, "credits_1");
				PrintFromFile(4, 20, WHITE, "credits_2");
				ConfirmRETURN(25, HEIGHT - 3, Gamepad);
				ClearScreen(1, 1, WIDTH - 1, HEIGHT - 2);
				break;

			}
			// Exit
			else if (iMenuChoice == 4) {

				ClearScreen(1, 1, WIDTH - 1, HEIGHT - 2);
				PrintFromFile(4, 10, RED, "exit");
				ConfirmRETURN(25, HEIGHT - 3, Gamepad);
				ClearScreen(1, 1, WIDTH - 1, HEIGHT - 2);
				bIsRunning = false;
				break;

			}

		}

	}

	return (0);

}