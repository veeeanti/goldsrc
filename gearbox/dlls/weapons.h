//
// weapons.h - Opposing Force weapon definitions
//

#ifndef WEAPONS_H
#define WEAPONS_H

#include "extdll.h"
#include "util.h"
#include "cbase.h"

// Weapon classes
class CWeaponCrowbar : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 0; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	int AddSecondaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeapon9MMHandgun : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 1; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeapon9MMAR : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 2; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponShotgun : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 3; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponCrossbow : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 4; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeapon357 : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 5; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponRPG : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 6; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponGauss : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 7; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponEgon : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 8; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponHornetgun : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 9; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponTripmine : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 10; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponSatchel : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 11; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponHandgrenade : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 12; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponSnark : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 13; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

// Opposing Force specific weapons
class CWeaponDisplacer : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 14; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponEagle : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 15; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponGrapple : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 16; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponKnife : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 17; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponM249 : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 18; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponPipewrench : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 19; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponShockrifle : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 20; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponSniperrifle : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 21; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

class CWeaponSporelauncher : public CBasePlayerWeapon
{
public:
	void Spawn(void);
	void Precache(void);
	int iItemSlot(void) { return 22; }
	int GetMaxAmmo(void);
	int AddToPlayer(CBasePlayer *pPlayer);
	int AddPrimaryAmmo(int iCount, int iMaxClip, int iMaxCarry);
	void PrimaryAttack(void);
	void SecondaryAttack(void);
	void Reload(void);
	void WeaponIdle(void);
};

void RegisterWeapons(void);

#endif // WEAPONS_H