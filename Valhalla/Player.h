#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"

class CPlayer : public CEntity {

public:
	CPlayer(
		const char* _name,		// Name  of the entity
		const char* _type,		// Type  of the entity
		const char* _class,		// Class of the entity
		const int   _level,		// Level of the entity
		const int   _armor,		// Armor of the entity
		TAttributes& _attr,		// Attributes of the entity
		TWeapon _weapon			// Type of Weapon
	);
	virtual ~CPlayer();



	// Virtual functions
	void Draw();
	void Attack();
	bool IsDead();

private:

};

#endif //__PLAYER_H__