//
// monsters.cpp - Opposing Force monster implementations
//

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "monsters.h"
#include "weapons.h"
#include "player.h"

// Monster registration
void RegisterMonsters(void)
{
	// Register all monsters
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/maleassassin.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/shocktrooper.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/human_medic_ally.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/human_torch_ally.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/drillsergeant.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/otis.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/recruit.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/cleansuit_scientist.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/sitting_cleansuit_scientist.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/gonome.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/voltigore.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/baby_voltigore.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/pitworm.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/pitworm_up.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/pitdrone.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/geneworm.mdl");
	MESSAGE_END();
	
	MESSAGE_BEGIN(MSG_ALL, SVC_PRECACHE);
		WRITE_STRING("models/shockroach.mdl");
	MESSAGE_END();
}

// Male Assassin implementation
void CMaleAssassin::Spawn(void)
{
	Precache();
	
	SET_MODEL(ENT(pev), "models/maleassassin.mdl");
	pev->classname = MAKE_STRING("monster_male_assassin");
	
	pev->health = 100;
	pev->view_ofs = Vector(0, 0, 64);
	
	MonsterInit();
	SetYawSpeed();
	
	// Weapon setup
	pev->weapons = 0;
	pev->currentweapon = 0;
}

void CMaleAssassin::Precache(void)
{
	PRECACHE_MODEL("models/maleassassin.mdl");
	PRECACHE_SOUND("maleassassin/death1.wav");
	PRECACHE_SOUND("maleassassin/death2.wav");
	PRECACHE_SOUND("maleassassin/pain1.wav");
	PRECACHE_SOUND("maleassassin/pain2.wav");
	PRECACHE_SOUND("maleassassin/alert1.wav");
	PRECACHE_SOUND("maleassassin/alert2.wav");
	PRECACHE_SOUND("maleassassin/idle1.wav");
	PRECACHE_SOUND("maleassassin/idle2.wav");
}

void CMaleAssassin::SetYawSpeed(void)
{
	pev->yaw_speed = 40;
}

int CMaleAssassin::Classify(void)
{
	return CLASS_HUMAN_MILITARY;
}

void CMaleAssassin::HandleAnimEvent(MonsterEvent_t *pEvent)
{
	// Handle animation events
}

void CMaleAssassin::StartTask(Task_t *pTask)
{
	// Start task logic
}

void CMaleAssassin::RunTask(Task_t *pTask)
{
	// Run task logic
}

void CMaleAssassin::DeathSound(void)
{
	EMIT_SOUND(ENT(pev), CHAN_VOICE, "maleassassin/death1.wav", 1, ATTN_NORM);
}

void CMaleAssassin::PainSound(void)
{
	EMIT_SOUND(ENT(pev), CHAN_VOICE, "maleassassin/pain1.wav", 1, ATTN_NORM);
}

void CMaleAssassin::IdleSound(void)
{
	EMIT_SOUND(ENT(pev), CHAN_VOICE, "maleassassin/idle1.wav", 1, ATTN_NORM);
}

void CMaleAssassin::AlertSound(void)
{
	EMIT_SOUND(ENT(pev), CHAN_VOICE, "maleassassin/alert1.wav", 1, ATTN_NORM);
}

void CMaleAssassin::PrescheduleThink(void)
{
	// Pre-schedule think logic
}

void CMaleAssassin::Schedule(void)
{
	// Schedule logic
}

// Additional monster implementations would go here...
// Each monster would have similar Spawn, Precache, HandleAnimEvent, etc. methods