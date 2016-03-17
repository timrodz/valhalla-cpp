#include "Menu.h"

CMenu::CMenu(void) {



}

CMenu::~CMenu(void) {



}

void CMenu::DrawRectangle(const int _startX, const int _startY, const int _endX, const int _endY, const char _c) {

	for (int i = _startX; i < _endX; i++) {

		for (int j = _startY; j < _endY; j++) {

			if (i == _startX || i == _endX - 1) {

				printAt(i, j, GRAY, _c);

			}
			else if (j == _startY || j == _endY - 1) {

				printAt(i, j, GRAY, _c);

			}

		}

	}

}

void CMenu::DrawLine(const int _startX, const int _endX, const int _y) {

	for (int i = _startX; i < _endX; i++) {

		if (i == _startX) 
			printAt(i, _y, GRAY, '+');
		else if (i > _startX && i < _endX - 1) 
			printAt(i, _y, GRAY, '=');
		else
			printAt(i, _y, GRAY, '+');

	}

}