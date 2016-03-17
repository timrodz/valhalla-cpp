#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "Entity.h"

class CMonster : public CEntity {

public:
	CMonster(
		const char* _name,		// Name  of the entity
		const char* _type,		// Type  of the entity
		const char* _class,		// Class of the entity
		const int   _level,		// Level of the entity
		const int   _armor,		// Armor of the entity
		TAttributes& _attr,		// Attributes of the entity
		TWeapon _weapon			// Type of Weapon
	);
	virtual ~CMonster();



	// Virtual functions
	void Draw();
	void Attack();
	bool IsDead();

private:

};

#endif //__MONSTER_H__