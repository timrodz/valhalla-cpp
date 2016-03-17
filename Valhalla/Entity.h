#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Attributes.h"
#include "Weapon.h"

class CEntity {
public:
	// Entity Constructor
	CEntity(
		const char* _name,		// Name  of the entity
		const char* _type,		// Type  of the entity
		const char* _class,		// Class of the entity
		const int   _level,		// Level of the entity
		const int   _armor,		// Armor of the entity
		TAttributes& _attr,		// Attributes of the entity
		TWeapon _weapon			// Type of Weapon
	);
	
	// Multi-purpose
	virtual void Draw()   = 0;
	virtual void Attack() = 0;
	virtual bool IsDead() = 0;

	// Getters
	const char* GetName() const;
	const char* GetType() const;
	const char* GetClass() const;
	const TWeapon GetWeapon() const;
	const TAttributes GetAttributes() const;
	const int GetLevel() const;
	const int GetHealth() const;
	const int GetStamina() const;
	const int GetMana() const;
	const int GetAccuracy() const;
	const int GetCritChance() const;
	const int GetArmor() const;

private:

	// Name and type of weapon
	char m_name[MAX_CHARS];
	char m_type[MAX_CHARS];
	char m_class[MAX_CHARS];
	TWeapon m_weapon;

	// Attributes and stats
	TAttributes m_attributes;
	int m_iLevel;
	int m_iHealthPoints;
	int m_iStamina;
	int m_iManaPoints;
	int m_iAccuracy;
	int m_iCriticalChance;
	int m_iArmor;

};

#endif //__ENTITY_H__