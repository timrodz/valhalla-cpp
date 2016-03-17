#ifndef __MENU_H__
#define __MENU_H__

#include "Screen.h"

class CMenu {

public:
	CMenu();
	~CMenu();

	// Virtual functions
	void DrawRectangle(const int _startX, const int _startY, const int _endX, const int _endY, const char _c);
	void DrawLine(const int _startX, const int _endX, const int _y);

private:
	const char* m_title;
	int m_x;
	int m_y;

};

#endif //__MENU_H__