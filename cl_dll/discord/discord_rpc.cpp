/***
 *
 *	No copyrights. I wrote this using the Discord Game SDK examples
 *  and documentation as reference, feel free to use it however you like.
 *  The main thing is that with this codebase, only Half-Life is supported.
 *	I'm trying to figure out how to get Opposing Force, Blue Shift and
 *	any other GoldSrc mods to work with Discord RPC, but so far no luck.
 *	I've only tried rewriting necessary code here to support OpFor, it didn't
 *  exactly work but it'll take more time to figure it out.
 *  Blue Shift should be easier since it's basically just Half-Life with
 *  model swaps for stuff like the battery and HEV suit for armor and Barney's
 *  vest and helmet. (And the lack of HEV charger usage...)
 *  In any case, this replaces the "discord_register.h" file from the older
 *  RPC SDK. It was instructed by Jay! on the TWHL wiki to do so.
 * 
 *  veeλnti - 2026 
 * 
 ****/
 
#include "discord_rpc.h"
#include "hud.h"
#include "cl_util.h"
#include <time.h>
extern cl_enginefunc_t gEngfuncs;

// Global Discord RPC instance
CDiscordRPC *g_pDiscordRPC = nullptr;

// Discord SDK handle
HMODULE g_hDiscordModule = nullptr;
Discord_Initialize_t Discord_Initialize = nullptr;
Discord_Shutdown_t Discord_Shutdown = nullptr;
Discord_UpdatePresence_t Discord_UpdatePresence = nullptr;
Discord_ClearPresence_t Discord_ClearPresence = nullptr;
Discord_Respond_t Discord_Respond = nullptr;
Discord_RunCallbacks_t Discord_RunCallbacks = nullptr;

// Discord RPC instance
CDiscordRPC::CDiscordRPC() : m_bInitialized(false), m_bActive(false), m_iStartTimestamp(0),
    m_iPlayerHealth(0), m_iPlayerArmor(0), m_iPlayerCount(0), m_iMaxPlayers(0)
{
}

CDiscordRPC::~CDiscordRPC()
{
    Shutdown();
}

bool CDiscordRPC::Init(DiscordEventHandlers* handlers)
{
    if (m_bInitialized)
        return true;

    // Clear any existing module handle
    if (g_hDiscordModule)
    {
        FreeLibrary(g_hDiscordModule);
        g_hDiscordModule = nullptr;
    }

    // Load Discord RPC library
    char szPath[512];
    if (!gEngfuncs.COM_ExpandFilename("discord-rpc.dll", szPath, sizeof(szPath)))
    {
        gEngfuncs.Con_Printf("Failed to expand discord-rpc.dll path\n");
        return false;
    }

    g_hDiscordModule = LoadLibraryA(szPath);
    if (!g_hDiscordModule)
    {
        gEngfuncs.Con_Printf("Failed to load discord-rpc.dll\n");
        return false;
    }

    // Get function pointers
    Discord_Initialize = (Discord_Initialize_t)GetProcAddress(g_hDiscordModule, "Discord_Initialize");
    Discord_Shutdown = (Discord_Shutdown_t)GetProcAddress(g_hDiscordModule, "Discord_Shutdown");
    Discord_UpdatePresence = (Discord_UpdatePresence_t)GetProcAddress(g_hDiscordModule, "Discord_UpdatePresence");
    Discord_ClearPresence = (Discord_ClearPresence_t)GetProcAddress(g_hDiscordModule, "Discord_ClearPresence");
    Discord_Respond = (Discord_Respond_t)GetProcAddress(g_hDiscordModule, "Discord_Respond");
    Discord_RunCallbacks = (Discord_RunCallbacks_t)GetProcAddress(g_hDiscordModule, "Discord_RunCallbacks");

    if (!Discord_Initialize || !Discord_Shutdown || !Discord_UpdatePresence ||
        !Discord_ClearPresence || !Discord_Respond || !Discord_RunCallbacks)
    {
        gEngfuncs.Con_Printf("Failed to get Discord RPC function pointers\n");
        Shutdown();
        return false;
    }

    // Initialize Discord RPC
    Discord_Initialize("1461994411759239273", handlers, 1, nullptr);
    m_bInitialized = true;
    m_bActive = true;
    m_iStartTimestamp = (int64_t)time(nullptr);

    gEngfuncs.Con_Printf("Discord RPC initialized successfully\n");
    return true;
}

void CDiscordRPC::Shutdown()
{
    if (m_bInitialized)
    {
        Discord_ClearPresence();
        Discord_Shutdown();
        m_bInitialized = false;
        m_bActive = false;
    }

    if (g_hDiscordModule)
    {
        FreeLibrary(g_hDiscordModule);
        g_hDiscordModule = nullptr;
    }

    Discord_Initialize = nullptr;
    Discord_Shutdown = nullptr;
    Discord_UpdatePresence = nullptr;
    Discord_ClearPresence = nullptr;
    Discord_Respond = nullptr;
    Discord_RunCallbacks = nullptr;

    gEngfuncs.Con_Printf("Discord RPC shutdown\n");
}

void CDiscordRPC::UpdatePresence(const DiscordRichPresence &presence)
{
    if (!m_bInitialized)
        return;

    Discord_UpdatePresence(&presence);
}

void CDiscordRPC::ClearPresence()
{
    if (!m_bInitialized)
        return;

    Discord_ClearPresence();
}

void CDiscordRPC::UpdateGameState(const char *mapName, const char *gameMode, int playerCount, int maxPlayers)
{
    if (!m_bInitialized)
        return;

    m_strCurrentMap = mapName;
    m_strCurrentGameMode = gameMode;
    m_iPlayerCount = playerCount;
    m_iMaxPlayers = maxPlayers;

    UpdateInternal();
}

void CDiscordRPC::FrameUpdate(float flTime)
{
    if (!m_bInitialized)
        return;

    Discord_RunCallbacks();
}

void CDiscordRPC::SetPlayerInfo(const char *playerName, int health, int armor)
{
    m_strPlayerName = playerName;
    m_iPlayerHealth = health;
    m_iPlayerArmor = armor;
}

void CDiscordRPC::UpdateInternal()
{
    if (!m_bActive)
        return;

    DiscordRichPresence presence;
    memset(&presence, 0, sizeof(presence));
    presence.state = m_strCurrentMap.c_str();
    presence.details = m_strCurrentGameMode.c_str();
    presence.largeImageKey = "halflife";
    presence.startTimestamp = m_iStartTimestamp;
    presence.partyId = "half-life";
    presence.partySize = m_iPlayerCount;
    presence.partyMax = m_iMaxPlayers;

    Discord_UpdatePresence(&presence);
}
