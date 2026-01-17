//
// gearbox.cpp - Opposing Force server DLL implementation
//

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "weapons.h"
#include "monsters.h"
#include "game.h"

// Game DLL functions
int GetWeaponCount(void);
int GetAmmoCount(void);
int GetMonsterCount(void);

// Weapon definitions
int GetWeaponCount(void)
{
	return 22; // Number of weapons in Opposing Force
}

int GetAmmoCount(void)
{
	return 10; // Number of ammo types
}

int GetMonsterCount(void)
{
	return 26; // Number of monster types
}

// Game initialization
extern "C" void GameDLLInit(void)
{
	// Register weapons
	RegisterWeapons();
	
	// Register monsters
	RegisterMonsters();
	
	// Register items
	RegisterItems();
}

// Client connect
extern "C" void ClientConnect(edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[128])
{
	// Custom Opposing Force connection logic
}

// Client disconnect
extern "C" void ClientDisconnect(edict_t *pEntity)
{
	// Custom Opposing Force disconnect logic
}

// Client user info changed
extern "C" void ClientUserInfoChanged(edict_t *pEntity, char *infobuffer)
{
	// Custom Opposing Force user info logic
}

// Server activate
extern "C" void ServerActivate(edict_t *pEdictList, int edictCount, int clientMax)
{
	// Custom Opposing Force server activation
}

// Server deactivate
extern "C" void ServerDeactivate(void)
{
	// Custom Opposing Force server deactivation
}

// Entity API functions
extern "C" int GetEntityAPI(DLL_FUNCTIONS *pFunctionTable, int interfaceVersion)
{
	if (!pFunctionTable || interfaceVersion != INTERFACE_VERSION)
	{
		return FALSE;
	}
	
	// Copy the function table from cbase
	memcpy(pFunctionTable, &gFunctionTable, sizeof(DLL_FUNCTIONS));
	return TRUE;
}

extern "C" int GetEntityAPI2(DLL_FUNCTIONS *pFunctionTable, int *interfaceVersion)
{
	if (!pFunctionTable || *interfaceVersion != INTERFACE_VERSION)
	{
		// Tell engine what version we had, so it can figure out who is out of date.
		*interfaceVersion = INTERFACE_VERSION;
		return FALSE;
	}
	
	memcpy(pFunctionTable, &gFunctionTable, sizeof(DLL_FUNCTIONS));
	return TRUE;
}

extern "C" int GetNewDLLFunctions(NEW_DLL_FUNCTIONS *pFunctionTable, int *interfaceVersion)
{
	if (!pFunctionTable || *interfaceVersion != NEW_DLL_FUNCTIONS_VERSION)
	{
		*interfaceVersion = NEW_DLL_FUNCTIONS_VERSION;
		return FALSE;
	}
	
	// Initialize the new DLL functions structure
	memset(pFunctionTable, 0, sizeof(NEW_DLL_FUNCTIONS));
	
	return TRUE;
}
