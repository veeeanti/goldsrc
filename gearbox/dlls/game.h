//
// game.h - Opposing Force game definitions
//

#ifndef GAME_H
#define GAME_H

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "gamerules.h"

// Game rules
class COpposingForceGame : public CGameRules
{
public:
	COpposingForceGame();
	virtual ~COpposingForceGame();
	
	// Game state management
	virtual void RefreshSkill(void);
	virtual int IPointsForKill(CBasePlayer *pAttacker, CBasePlayer *pKilled);
	virtual BOOL FAllowFlashlight(void);
	virtual BOOL FAllowMonsters(void);
	virtual BOOL IsMultiplayer(void);
	virtual void CheckMapConditions(void);
	virtual void ClientUserInfoChanged(CBasePlayer *pPlayer, char *infobuffer);
	virtual void Serverdeactivate(void);
	virtual void Think(void);
	
	// Player management
	virtual BOOL FPlayerCanTakeDamage(CBasePlayer *pPlayer, CBaseEntity *pAttacker);
	virtual void PlayerKilled(CBasePlayer *pVictim, entvars_t *pKiller, entvars_t *pInflictor);
	virtual void DeathNotice(CBasePlayer *pVictim, entvars_t *pKiller);
	
	// Team management
	virtual const char *GetTeamID(CBaseEntity *pEntity);
	virtual int GetTeamIndex(const char *pTeamName);
	virtual const char *GetIndexedTeamName(int teamIndex);
	virtual int GetTeamCount(void);
	
	// Weapon restrictions
	virtual BOOL CanHavePlayerItem(CBasePlayer *pPlayer, CBasePlayerItem *pItem);
	virtual void CleanUpMap(void);
	
	// Game mode specific
	virtual BOOL IsCoOp(void);
	virtual BOOL IsDeathmatch(void);
	virtual BOOL FShouldSwitchWeapon(CBasePlayer *pPlayer, CBasePlayerItem *pWeapon);
	
	// Save/load
	virtual int Save(CSave &save);
	virtual int Restore(CRestore &restore);
	static TYPEDESCRIPTION m_pEntitySaveData[];
};

// Game interface
void GameDLLInit(void);
void ClientConnect(edict_t *pEntity, const char *pszName, const char *pszAddress, char szRejectReason[128]);
void ClientDisconnect(edict_t *pEntity);
void ClientUserInfoChanged(edict_t *pEntity, char *infobuffer);
void ServerActivate(edict_t *pEdictList, int edictCount, int clientMax);
void ServerDeactivate(void);

#endif // GAME_H