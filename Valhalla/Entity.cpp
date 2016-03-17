#include "Entity.h"
#include <string>

CEntity::CEntity(
	const char* _name,		// Name  of the entity
	const char* _type,		// Type  of the entity
	const char* _class,		// Class of the entity
	const int   _level,		// Level of the entity
	const int   _armor,		// Armor of the entity
	TAttributes& _attr,		// Attributes of the entity
	TWeapon _weapon			// Type of Weapon
	) {

	// Name of the entity
	strncpy_s(m_name, _name, MAX_CHARS - 1);

	// Name of the type
	strncpy_s(m_type, _type, MAX_CHARS - 1);

	// Name of the class
	strncpy_s(m_class, _class, MAX_CHARS - 1);

	// These attributes will be calculated based on the entity's attributes
	m_iHealthPoints = (_attr.strength * 8) + (_attr.constitution * 9);
	m_iStamina = (_attr.constitution * 10) + (_attr.intelligence * 2);
	m_iManaPoints = (_attr.wisdom * 10) + (_attr.intelligence * 8);
	m_iAccuracy = (_attr.dexterity * 10) + (_attr.intelligence * 2);
	m_iCriticalChance = (_attr.luck * 10) + (_attr.intelligence * 2);

	// Name and damage range of the weapon
	strncpy_s(m_weapon.name, _weapon.name, MAX_CHARS - 1);
	m_weapon.damageRange.iHigh = _weapon.damageRange.iHigh;
	m_weapon.damageRange.iLow = _weapon.damageRange.iLow;

}

const char* CEntity::GetName() const {
	return (m_name);
}

const char* CEntity::GetType() const {
	return (m_type);
}

const char* CEntity::GetClass() const {
	return (m_class);
}

const TWeapon CEntity::GetWeapon() const {
	return (m_weapon);
}

const TAttributes CEntity::GetAttributes() const {
	return (m_attributes);
}

const int CEntity::GetLevel() const {
	return (m_iLevel);
}

const int CEntity::GetHealth() const {
	return (m_iHealthPoints);
}

const int CEntity::GetStamina() const {
	return (m_iStamina);
}

const int CEntity::GetMana() const {
	return (m_iManaPoints);
}

const int CEntity::GetAccuracy() const {
	return (m_iAccuracy);
}

const int CEntity::GetCritChance() const {
	return (m_iCriticalChance);
}

const int CEntity::GetArmor() const {
	return (m_iArmor);
}