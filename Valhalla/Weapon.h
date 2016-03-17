#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "range.h"

const int MAX_CHARS = 20;

struct TWeapon {

	char name[MAX_CHARS];
	TRange damageRange;

};

#endif // __WEAPON_H__