// ================================================== \\
// Discord RPC implemenatation
// Based on code from the Valve Dev Community wiki
//
// Jay - 2022
// ================================================== \\

/***
 * Modified from my initial Half-Life implementation to support Ricochet, this
 * is still a work in progress and seemingly does not work yet, though the cvars
 * are showing up in the console! Almost there!!
 * 
 * veeλnti - 2026
 * 
 ***/

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

// Default logo to use as a fallback
const char* defaultLogo = "ricochet";

// Map name to chapter mapping for Half-Life
struct MapChapter {
    const char* mapName;
    const char* chapterName;
};

const MapChapter mapChapters[] = {
    {"maps/rc_arena.bsp", "rc_arena"},
    {"maps/rc_deathmatch.bsp", "rc_deathmatch"},
    {"maps/rc_deathmatch2.bsp", "rc_deathmatch2"}
};

// Helper function to find chapter for a map
const char* FindChapterForMap(const char* mapName) {
    if (!mapName || mapName[0] == '\0') {
        return "";
    }

    int numChapters = sizeof(mapChapters) / sizeof(mapChapters[0]);
    for (int i = 0; i < numChapters; i++) {
        if (stricmp(mapName, mapChapters[i].mapName) == 0) {
            return mapChapters[i].chapterName;
        }
    }

    // Fallback for custom maps
    return "";
}

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

void DiscordMan_Startup(void)
{
    // Initialize Discord RPC
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

void DiscordMan_Update(void)
{
    if (g_pDiscordRPC)
    {
        // Run callbacks to process Discord events
        g_pDiscordRPC->FrameUpdate(0);

        // Get current map name
        const char* mapName = gEngfuncs.pfnGetLevelName();

        // Automatically set CVars based on map name
        const char* chapter = FindChapterForMap(mapName);
        const char* area = mapName; // Set area to map name
        const char* image = "ricochet"; // Default image

        // Update CVars if they don't match
        if (rpc_chapter && strcmp(rpc_chapter->string, chapter) != 0) {
            gEngfuncs.Cvar_Set("rpc_chapter", chapter);
        }
        if (rpc_area && strcmp(rpc_area->string, area) != 0) {
            gEngfuncs.Cvar_Set("rpc_area", area);
        }
        if (rpc_image && strcmp(rpc_image->string, image) != 0) {
            gEngfuncs.Cvar_Set("rpc_image", image);
        }

        // Create presence
        DiscordRichPresence presence;
        memset(&presence, 0, sizeof(presence));
        presence.state = area;
        if (strlen(chapter) > 0) {
            presence.details = chapter;
        } else {
            presence.details = "In menus or custom map...";
        }
        presence.largeImageKey = defaultLogo;
        presence.startTimestamp = time(0);

        // Update presence
        g_pDiscordRPC->UpdatePresence(presence);
    }
}

void DiscordMan_Kill(void)
{
    if (g_pDiscordRPC)
    {
        g_pDiscordRPC->Shutdown();
        delete g_pDiscordRPC;
        g_pDiscordRPC = nullptr;
    }
}
