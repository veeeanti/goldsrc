/***
 *
 *	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
 *	
 *	This product contains software technology licensed from Id 
 *	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
 *	All Rights Reserved.
 *	
 *  Use, distribution, and modification of this source code and/or resulting
 *  object code is restricted to non-commercial enhancements to products from
 *  Valve LLC.  All other use, distribution, or modification is prohibited
 *  without written permission from Valve LLC.
 *
 ***/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "player.h"
#include "weapons.h"
#include "gamerules.h"
#include "game.h"

//=========================================================
// COpposingForceRules - rules for the Opposing Force game.
//=========================================================
class COpposingForceRules : public CHalfLifeRules
{
public:
	COpposingForceRules ( void );

	// Override to return Opposing Force game description
	virtual const char *GetGameDescription( void ) { return "Opposing Force"; }
	
	// Player spawn - can be customized for Opposing Force
	virtual void PlayerSpawn( CBasePlayer *pPlayer );
};

COpposingForceRules::COpposingForceRules( void )
{
	// Initialize Opposing Force specific game rules
}

void COpposingForceRules::PlayerSpawn( CBasePlayer *pPlayer )
{
	// Call base class spawn
	CHalfLifeRules::PlayerSpawn( pPlayer );
	
	// Opposing Force specific spawn logic can go here
	// For now, just use standard Half-Life spawn behavior
}

// Function to install Opposing Force game rules
// This can be called from game.cpp or other initialization code
CGameRules *InstallOpposingForceRules( void )
{
	return new COpposingForceRules();
}
