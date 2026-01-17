//
// items.h - Opposing Force item definitions
//

#ifndef ITEMS_H
#define ITEMS_H

#include "extdll.h"
#include "util.h"
#include "cbase.h"

// Item classes
class CItemNuclearBomb : public CBaseEntity
{
public:
	void Spawn(void);
	void Precache(void);
	void KeyValue(KeyValueData *pkvd);
	void Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value);
	void Think(void);
	void Detonate(void);
	void Explode(void);
	void Touch(CBaseEntity *pOther);
	int  Save(CSave &save);
	int  Restore(CRestore &restore);
	static TYPEDESCRIPTION m_pEntitySaveData[];
};

class CItemGeneric : public CBaseEntity
{
public:
	void Spawn(void);
	void Precache(void);
	void KeyValue(KeyValueData *pkvd);
	void Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value);
	void Touch(CBaseEntity *pOther);
	int  Save(CSave &save);
	int  Restore(CRestore &restore);
	static TYPEDESCRIPTION m_pEntitySaveData[];
};

void RegisterItems(void);

#endif // ITEMS_H