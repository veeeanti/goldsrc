//
// items.cpp - Opposing Force item implementations
//

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "items.h"
#include "player.h"

// Item registration
void RegisterItems(void)
{
	// Register all items
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/nuclearbomb.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/generic_item.mdl");
	MESSAGE_END();
}

// Nuclear Bomb implementation
void CItemNuclearBomb::Spawn(void)
{
	Precache();
	
	SET_MODEL(ENT(pev), "models/nuclearbomb.mdl");
	pev->classname = MAKE_STRING("item_nuclearbomb");
	
	pev->solid = SOLID_TRIGGER;
	pev->movetype = MOVETYPE_TOSS;
	pev->effects = EF_GIB;
	pev->gravity = 0.5;
	pev->friction = 0.8;
	
	UTIL_SetSize(pev, Vector(-16, -16, 0), Vector(16, 16, 36));
	
	pev->nextthink = gpGlobals->time + 1.0;
}

void CItemNuclearBomb::Precache(void)
{
	PRECACHE_MODEL("models/nuclearbomb.mdl");
	PRECACHE_SOUND("items/nuclearbomb_beep1.wav");
	PRECACHE_SOUND("items/nuclearbomb_beep2.wav");
	PRECACHE_SOUND("items/nuclearbomb_detonate.wav");
}

void CItemNuclearBomb::KeyValue(KeyValueData *pkvd)
{
	if (FStrEq(pkvd->szKeyName, "initialstate"))
	{
		pev->iInitialState = atoi(pkvd->szValue);
	}
	else if (FStrEq(pkvd->szKeyName, "wait"))
	{
		pev->iWait = atoi(pkvd->szValue);
	}
	else
	{
		CBaseEntity::KeyValue(pkvd);
	}
}

void CItemNuclearBomb::Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value)
{
	// Use logic
}

void CItemNuclearBomb::Think(void)
{
	// Think logic - countdown timer
}

void CItemNuclearBomb::Detonate(void)
{
	// Detonate logic
}

void CItemNuclearBomb::Explode(void)
{
	// Explosion logic
}

void CItemNuclearBomb::Touch(CBaseEntity *pOther)
{
	// Touch logic
}

int CItemNuclearBomb::Save(CSave &save)
{
	// Save logic
	return 0;
}

int CItemNuclearBomb::Restore(CRestore &restore)
{
	// Restore logic
	return 0;
}

TYPEDESCRIPTION CItemNuclearBomb::m_pEntitySaveData[] = 
{
	// Save data descriptions
};

// Generic Item implementation
void CItemGeneric::Spawn(void)
{
	Precache();
	
	SET_MODEL(ENT(pev), "models/generic_item.mdl");
	pev->classname = MAKE_STRING("item_generic");
	
	pev->solid = SOLID_TRIGGER;
	pev->movetype = MOVETYPE_TOSS;
	pev->effects = EF_GIB;
	pev->gravity = 0.5;
	pev->friction = 0.8;
	
	UTIL_SetSize(pev, Vector(-16, -16, 0), Vector(16, 16, 36));
}

void CItemGeneric::Precache(void)
{
	PRECACHE_MODEL("models/generic_item.mdl");
}

void CItemGeneric::KeyValue(KeyValueData *pkvd)
{
	if (FStrEq(pkvd->szKeyName, "model"))
	{
		pev->model = MAKE_STRING(pkvd->szValue);
	}
	else if (FStrEq(pkvd->szKeyName, "sequencename"))
	{
		pev->sequence = atoi(pkvd->szValue);
	}
	else if (FStrEq(pkvd->szKeyName, "skin"))
	{
		pev->skin = atoi(pkvd->szValue);
	}
	else if (FStrEq(pkvd->szKeyName, "body"))
	{
		pev->body = atoi(pkvd->szValue);
	}
	else
	{
		CBaseEntity::KeyValue(pkvd);
	}
}

void CItemGeneric::Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value)
{
	// Use logic
}

void CItemGeneric::Touch(CBaseEntity *pOther)
{
	// Touch logic
}

int CItemGeneric::Save(CSave &save)
{
	// Save logic
	return 0;
}

int CItemGeneric::Restore(CRestore &restore)
{
	// Restore logic
	return 0;
}

TYPEDESCRIPTION CItemGeneric::m_pEntitySaveData[] = 
{
	// Save data descriptions
};