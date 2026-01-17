/***
 *
 *	Copyright (c) 2024, Valve LLC. All rights reserved.
 *	
 *	This product contains software technology licensed from Id 
 *	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
 *	All Rights Reserved.
 *	
 *   Use, distribution, and modification of this source code and/or resulting
 *   object code is restricted to non-commercial enhancements to products from
 *   Valve LLC.  All other use, distribution, or modification is prohibited
 *   without written permission from Valve LLC.
 *
 ****/
 //
 //  discord_rpc.h
 //
 // Discord Rich Presence implementation for Half-Life
 //

#ifndef DISCORD_RPC_H
#define DISCORD_RPC_H

#ifdef _WIN32
#include <windows.h>
#endif

#include <string>

// Discord RPC application ID
#define DISCORD_APP_ID 1461994411759239273

// Forward declarations
class CDiscordRPC;

// Discord user structure
struct DiscordUser
{
    const char* userId;
    const char* username;
    const char* discriminator;
    const char* avatar;
};

// Discord event handlers structure
struct DiscordEventHandlers
{
    void (*ready)(const DiscordUser* request);
    void (*disconnected)(int errorCode, const char* message);
    void (*errored)(int errorCode, const char* message);
    void (*joinGame)(const char* joinSecret);
    void (*spectateGame)(const char* spectateSecret);
    void (*joinRequest)(const DiscordUser* request);
};

// Global Discord RPC instance
extern CDiscordRPC *g_pDiscordRPC;

// Discord RPC state structure
struct DiscordRichPresence
{
    const char *state;       // e.g., "Playing on [map]"
    const char *details;     // e.g., "Half-Life"
    int64_t startTimestamp;
    int64_t endTimestamp;
    const char *largeImageKey;
    const char *largeImageText;
    const char *smallImageKey;
    const char *smallImageText;
    const char *partyId;
    int partySize;
    int partyMax;
    const char *matchSecret;
    const char *joinSecret;
    const char *spectateSecret;
    int8_t instance;
};

// Discord SDK function pointers
typedef void (*Discord_Initialize_t)(const char* applicationId, DiscordEventHandlers* handlers, int autoRegister, const char* optionalSteamId);
typedef void (*Discord_Shutdown_t)(void);
typedef void (*Discord_UpdatePresence_t)(const DiscordRichPresence*);
typedef void (*Discord_ClearPresence_t)(void);
typedef void (*Discord_Respond_t)(const char*, int);
typedef void (*Discord_RunCallbacks_t)(void);

// Discord SDK handle
extern HMODULE g_hDiscordModule;
extern Discord_Initialize_t Discord_Initialize;
extern Discord_Shutdown_t Discord_Shutdown;
extern Discord_UpdatePresence_t Discord_UpdatePresence;
extern Discord_ClearPresence_t Discord_ClearPresence;
extern Discord_Respond_t Discord_Respond;
extern Discord_RunCallbacks_t Discord_RunCallbacks;

// Main Discord RPC class
class CDiscordRPC
{
public:
    CDiscordRPC();
    ~CDiscordRPC();

    // Initialize Discord RPC
    bool Init(DiscordEventHandlers* handlers = nullptr);

    // Shutdown Discord RPC
    void Shutdown();

    // Update rich presence
    void UpdatePresence(const DiscordRichPresence &presence);

    // Clear rich presence
    void ClearPresence();

    // Update with current game state
    void UpdateGameState(const char *mapName, const char *gameMode, int playerCount, int maxPlayers);

    // Frame update - called every frame
    void FrameUpdate(float flTime);

    // Set player info
    void SetPlayerInfo(const char *playerName, int health, int armor);

private:
    bool m_bInitialized;
    bool m_bActive;
    int64_t m_iStartTimestamp;
    std::string m_strCurrentMap;
    std::string m_strCurrentGameMode;
    std::string m_strPlayerName;
    int m_iPlayerHealth;
    int m_iPlayerArmor;
    int m_iPlayerCount;
    int m_iMaxPlayers;

    // Internal update function
    void UpdateInternal();
};

#endif // DISCORD_RPC_H
