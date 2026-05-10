// ================================================== \\
// Ricochet Discord RPC implementation
// Shows match status, KDA, and map info
//
// veeλnti - 2026
// ================================================== \\

#include "hud.h"
#include "discord_manager.h"
#include <string.h>
#include "discord/discord_rpc.h"
#include <time.h>
#include "../common/cvardef.h"

// External references to CVars
extern cvar_t *rpc_chapter;
extern cvar_t *rpc_area;
extern cvar_t *rpc_image;

// Discord event handlers
void Discord_Ready(const DiscordUser* request) {
    gEngfuncs.Con_Printf("Discord RPC: Ready - %s#%s\n", request->username, request->discriminator);
}

void Discord_Disconnected(int errorCode, const char* message) {
    gEngfuncs.Con_Printf("Discord RPC: Disconnected - %d: %s\n", errorCode, message);
}

void Discord_Errored(int errorCode, const char* message) {
    gEngfuncs.Con_Printf("Discord RPC: Error - %d: %s\n", errorCode, message);
}

void DiscordMan_Startup(void) {
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));
    handlers.ready = Discord_Ready;
    handlers.disconnected = Discord_Disconnected;
    handlers.errored = Discord_Errored;

    if (g_pDiscordRPC == nullptr)
    {
        g_pDiscordRPC = new CDiscordRPC();
    }

    if (g_pDiscordRPC->Init(&handlers))
    {
        gEngfuncs.Con_Printf("Discord RPC initialized\n");
    }
    else
    {
        gEngfuncs.Con_Printf("Failed to initialize Discord RPC\n");
        delete g_pDiscordRPC;
        g_pDiscordRPC = nullptr;
    }
}

void DiscordMan_Update(void) {
    if (g_pDiscordRPC)
    {
        g_pDiscordRPC->FrameUpdate(0);
        g_pDiscordRPC->UpdateRicochetStats(g_PlayerExtraInfo[0].frags, g_PlayerExtraInfo[0].deaths, g_iUser1 == 2);
        g_pDiscordRPC->UpdateInternal();
    }
}

void DiscordMan_Kill(void) {
    if (g_pDiscordRPC)
    {
        g_pDiscordRPC->Shutdown();
        delete g_pDiscordRPC;
        g_pDiscordRPC = nullptr;
    }
}
