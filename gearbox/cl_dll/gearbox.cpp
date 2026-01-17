//
// gearbox.cpp - Opposing Force client DLL implementation
//

#include "gearbox.h"
#include "hud.h"
#include "cl_util.h"
#include "parsemsg.h"

CHudGearbox::CHudGearbox(void)
{
}

int CHudGearbox::Init(void)
{
	HOOK_MESSAGE(GearboxMessage);
	return 1;
}

int CHudGearbox::Draw(float flTime)
{
	return 1;
}

int CHudGearbox::VidInit(void)
{
	return 1;
}

void CHudGearbox::Reset(void)
{
}

DECLARE_MESSAGE(m_Gearbox, GearboxMessage)

int CHudGearbox::MsgFunc_GearboxMessage(const char *pszName, int iSize, void *pbuf)
{
	BEGIN_READ(pbuf, iSize);
	// Handle GearboxMessage here
	return 1;
}
