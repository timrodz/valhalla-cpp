#include "Monster.h"



CMonster::CMonster(
	const char* _name,		// Name  of the entity
	const char* _type,		// Type  of the entity
	const char* _class,		// Class of the entity
	const int   _level,		// Level of the entity
	const int   _armor,		// Armor of the entity
	TAttributes& _attr,		// Attributes of the entity
	TWeapon _weapon			// Type of Weapon
	)
	// Create our player using the entity constructor
	: CEntity(_name, _type, _class, 1, _armor, _attr, _weapon)
{



}

CMonster::~CMonster() {



}

void CMonster::Draw() {



}

void CMonster::Attack() {



}

bool CMonster::IsDead() {



	return false;

}