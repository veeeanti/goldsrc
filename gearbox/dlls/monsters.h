//
// monsters.h - Opposing Force monster definitions
//

#ifndef MONSTERS_H
#define MONSTERS_H

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monster.h"

// Monster classes
class CMaleAssassin : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CShockTrooper : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CHumanMedicAlly : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CHumanTorchAlly : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CDrillSergeant : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class COtis : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CRecruit : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CCleansuitScientist : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CSittingCleansuitScientist : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CGonome : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CVoltigore : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CBabyVoltigore : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CPitworm : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CPitwormUp : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CPitdrone : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CGeneworm : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

class CShockroach : public CBaseMonster
{
public:
	void Spawn(void);
	void Precache(void);
	void SetYawSpeed(void);
	int  Classify(void);
	void HandleAnimEvent(MonsterEvent_t *pEvent);
	void StartTask(Task_t *pTask);
	void RunTask(Task_t *pTask);
	void DeathSound(void);
	void PainSound(void);
	void IdleSound(void);
	void AlertSound(void);
	void PrescheduleThink(void);
	void Schedule(void);
};

void RegisterMonsters(void);

#endif // MONSTERS_H