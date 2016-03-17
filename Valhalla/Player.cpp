#include "Player.h"

CPlayer::CPlayer(
	const char* _name,		// Name of the entity
	const char* _type,		// Type of the entity
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

CPlayer::~CPlayer() {



}

void CPlayer::Draw() {



}

void CPlayer::Attack() {



}

bool CPlayer::IsDead() {



	return false;

}
