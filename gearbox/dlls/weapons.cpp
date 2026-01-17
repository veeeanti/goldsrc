//
// weapons.cpp - Opposing Force weapon implementations
//

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monsters.h"
#include "weapons.h"
#include "player.h"

// Weapon registration
void RegisterWeapons(void)
{
	// Register all weapons
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_crowbar.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_9mmhandgun.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_9mmAR.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_shotgun.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_crossbow.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_357.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_rpg.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_gauss.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_egon.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_hornetgun.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_tripmine.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_satchel.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_handgrenade.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_snark.mdl");
	MESSAGE_END();
	
	// Opposing Force specific weapons
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_displacer.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_eagle.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_grapple.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_knife.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_m249.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_pipewrench.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_shockrifle.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_sniperrifle.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/v_sporelauncher.mdl");
	MESSAGE_END();
}

// Crowbar implementation
void CWeaponCrowbar::Spawn(void)
{
	Precache();
	SET_MODEL(ENT(pev), "models/v_crowbar.mdl");
	
	pev->classname = MAKE_STRING("weapon_crowbar");
	pev->solid = SOLID_TRIGGER;
	pev->movetype = MOVETYPE_TOSS;
	pev->effects = EF_GIB;
	pev->gravity = 0.7;
	pev->friction = 0.8;
	
	UTIL_SetSize(pev, Vector(0, 0, 0), Vector(0, 0, 0));
}

void CWeaponCrowbar::Precache(void)
{
	PRECACHE_MODEL("models/v_crowbar.mdl");
	PRECACHE_MODEL("models/w_crowbar.mdl");
	PRECACHE_SOUND("weapons/cbar_hit1.wav");
	PRECACHE_SOUND("weapons/cbar_hit2.wav");
	PRECACHE_SOUND("weapons/cbar_hitbod1.wav");
	PRECACHE_SOUND("weapons/cbar_hitbod2.wav");
	PRECACHE_SOUND("weapons/cbar_hitbod3.wav");
	PRECACHE_SOUND("weapons/cbar_miss1.wav");
	PRECACHE_SOUND("weapons/cbar_swing1.wav");
}

int CWeaponCrowbar::GetMaxAmmo(void)
{
	return 0;
}

int CWeaponCrowbar::AddToPlayer(CBasePlayer *pPlayer)
{
	if (CBasePlayerItem::AddToPlayer(pPlayer))
	{
		MESSAGE_BEGIN(MSG_ONE, gmsgWeapPickup, NULL, pPlayer->pev);
			WRITE_BYTE(m_iId);
		MESSAGE_END();
		return TRUE;
	}
	return FALSE;
}

int CWeaponCrowbar::AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry)
{
	return 0;
}

int CWeaponCrowbar::AddSecondaryAmmo(int iCount, int iMaxClip, int iMaxCarry)
{
	return 0;
}

void CWeaponCrowbar::PrimaryAttack(void)
{
	// Crowbar attack logic
}

void CWeaponCrowbar::SecondaryAttack(void)
{
	// No secondary attack
}

void CWeaponCrowbar::Reload(void)
{
	// No reload needed
}

void CWeaponCrowbar::WeaponIdle(void)
{
	// Idle animation
}

// Additional weapon implementations would go here...
// Each weapon would have similar Spawn, Precache, PrimaryAttack, etc. methods