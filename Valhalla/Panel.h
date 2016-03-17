#ifndef __PANEL_H__
#define __PANEL_H__

#include "Screen.h"

class CPanel {

public:
	virtual void DrawBorders(const int _startX, const int _startY, const int _endX, const int _endY, const char _c) = 0;
	virtual void DrawLine(const int _startX, const int _endX, const int _y) = 0;

};

#endif //__PANEL_H__