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
void GameDLLInit(void)
{
	// Register weapons
	RegisterWeapons();
	
	// Register monsters
	RegisterMonsters();
	
	// Register items
	RegisterItems();
}

// Client connect
void ClientConnect(edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[128])
{
	// Custom Opposing Force connection logic
}

// Client disconnect
void ClientDisconnect(edict_t *pEntity)
{
	// Custom Opposing Force disconnect logic
}

// Client user info changed
void ClientUserInfoChanged(edict_t *pEntity, char *infobuffer)
{
	// Custom Opposing Force user info logic
}

// Server activate
void ServerActivate(edict_t *pEdictList, int edictCount, int clientMax)
{
	// Custom Opposing Force server activation
}

// Server deactivate
void ServerDeactivate(void)
{
	// Custom Opposing Force server deactivation
}