// ================================================== \\
// Discord RPC implemenatation
// Based on code from the Valve Dev Community wiki
//
// Jay - 2022
// ================================================== \\

/***
 * 
 * I rewrote certain parts of this to use the Discord Game SDK
 * functions and structures, as the older Discord RPC SDK is 
 * seemingly incompatible with the current Discord client.
 * I also added heavily onto the maps and chapter details for
 * the RPC to show. Only the main Half-Life campaign, Hazard Course, and 
 * Uplink demo are supported. Multiplayer is not yet supported.
 * Not the maps nor the whole MP functionality is implemented. Yet.
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
const char* defaultLogo = "hl_logo";

// Map name to chapter mapping for Half-Life
struct MapChapter {
    const char* mapName;
    const char* chapterName;
};

const MapChapter mapChapters[] = {
    {"maps/c0a0.bsp", "Black Mesa Inbound"},
    {"maps/c0a0a.bsp", "Black Mesa Inbound"},
    {"maps/c0a0b.bsp", "Black Mesa Inbound"},
    {"maps/c0a0c.bsp", "Black Mesa Inbound"},
    {"maps/c0a0d.bsp", "Black Mesa Inbound"},
    {"maps/c0a0e.bsp", "Black Mesa Inbound"},
    {"maps/c1a0.bsp", "Anomalous Materials"},
    {"maps/c1a0a.bsp", "Anomalous Materials"},
    {"maps/c1a0b.bsp", "Anomalous Materials"},
    {"maps/c1a0c.bsp", "Anomalous Materials"},
    {"maps/c1a0d.bsp", "Anomalous Materials"},
    {"maps/c1a0e.bsp", "Anomalous Materials"},
    {"maps/c1a1.bsp", "Unforeseen Consequences"},
    {"maps/c1a1a.bsp", "Unforeseen Consequences"},
    {"maps/c1a1b.bsp", "Unforeseen Consequences"},
    {"maps/c1a1c.bsp", "Unforeseen Consequences"},
    {"maps/c1a1d.bsp", "Unforeseen Consequences"},
    {"maps/c1a1f.bsp", "Unforeseen Consequences"},
    {"maps/c1a2.bsp", "Office Complex"},
    {"maps/c1a2a.bsp", "Office Complex"},
    {"maps/c1a2b.bsp", "Office Complex"},
    {"maps/c1a2c.bsp", "Office Complex"},
    {"maps/c1a2d.bsp", "Office Complex"},
    {"maps/c1a3.bsp", "\"We've Got Hostiles\""},
    {"maps/c1a3a.bsp", "\"We've Got Hostiles\""},
    {"maps/c1a3b.bsp", "\"We've Got Hostiles\""},
    {"maps/c1a3c.bsp", "\"We've Got Hostiles\""},
    {"maps/c1a3d.bsp", "\"We've Got Hostiles\""},
    {"maps/c1a4.bsp", "Blast Pit"},
    {"maps/c1a4b.bsp", "Blast Pit"},
    {"maps/c1a4d.bsp", "Blast Pit"},
    {"maps/c1a4e.bsp", "Blast Pit"},
    {"maps/c1a4f.bsp", "Blast Pit"},
    {"maps/c1a4g.bsp", "Blast Pit"},
    {"maps/c1a4i.bsp", "Blast Pit"},
    {"maps/c1a4j.bsp", "Blast Pit"},
    {"maps/c1a4k.bsp", "Blast Pit"},
    {"maps/c2a1.bsp", "Power Up"},
    {"maps/c2a1a.bsp", "Power Up"},
    {"maps/c2a1b.bsp", "Power Up"},
    {"maps/c2a2.bsp", "On A Rail"},
    {"maps/c2a2a.bsp", "On A Rail"},
    {"maps/c2a2b1.bsp", "On A Rail"},
    {"maps/c2a2b2.bsp", "On A Rail"},
    {"maps/c2a2c.bsp", "On A Rail"},
    {"maps/c2a2d.bsp", "On A Rail"},
    {"maps/c2a2e.bsp", "On A Rail"},
    {"maps/c2a2f.bsp", "On A Rail"},
    {"maps/c2a2g.bsp", "On A Rail"},
    {"maps/c2a2h.bsp", "On A Rail"},
    {"maps/c2a3.bsp", "Apprehension"},
    {"maps/c2a3a.bsp", "Apprehension"},
    {"maps/c2a3b.bsp", "Apprehension"},
    {"maps/c2a3c.bsp", "Apprehension"},
    {"maps/c2a3d.bsp", "Apprehension"},
    {"maps/c2a3e.bsp", "Apprehension"},
    {"maps/c2a4.bsp", "Residue Processing"},
    {"maps/c2a4a.bsp", "Residue Processing"},
    {"maps/c2a4b.bsp", "Residue Processing"},
    {"maps/c2a4c.bsp", "Residue Processing"},
    {"maps/c2a4d.bsp", "Questionable Ethics"},
    {"maps/c2a4e.bsp", "Questionable Ethics"},
    {"maps/c2a4f.bsp", "Questionable Ethics"},
    {"maps/c2a4g.bsp", "Questionable Ethics"},
    {"maps/c2a5.bsp", "Surface Tension"},
    {"maps/c2a5a.bsp", "Surface Tension"},
    {"maps/c2a5b.bsp", "Surface Tension"},
    {"maps/c2a5c.bsp", "Surface Tension"},
    {"maps/c2a5d.bsp", "Surface Tension"},
    {"maps/c2a5e.bsp", "Surface Tension"},
    {"maps/c2a5f.bsp", "Surface Tension"},
    {"maps/c2a5g.bsp", "Surface Tension"},
    {"maps/c2a5w.bsp", "Surface Tension"},
    {"maps/c2a5x.bsp", "Surface Tension"},
    {"maps/c3a1.bsp", "\"Forget About Freeman!\""},
    {"maps/c3a1a.bsp", "\"Forget About Freeman!\""},
    {"maps/c3a1b.bsp", "\"Forget About Freeman!\""},
    {"maps/c3a2.bsp", "Lambda Core"},
    {"maps/c3a2a.bsp", "Lambda Core"},
    {"maps/c3a2b.bsp", "Lambda Core"},
    {"maps/c3a2c.bsp", "Lambda Core"},
    {"maps/c3a2d.bsp", "Lambda Core"},
    {"maps/c3a2e.bsp", "Lambda Core"},
    {"maps/c3a2f.bsp", "Lambda Core"},
    {"maps/c4a1.bsp", "Xen"},
    {"maps/c4a1a.bsp", "Xen"},
    {"maps/c4a1b.bsp", "Xen"},
    {"maps/c4a1c.bsp", "Xen"},
    {"maps/c4a1d.bsp", "Xen"},
    {"maps/c4a1e.bsp", "Xen"},
    {"maps/c4a1f.bsp", "Xen"},
    {"maps/c4a2.bsp", "Gonarch's Lair"},
    {"maps/c4a2a.bsp", "Gonarch's Lair"},
    {"maps/c4a2b.bsp", "Interloper"},
    {"maps/c4a3.bsp", "Nihilanth"},
    {"maps/c5a1.bsp", "Endgame"},
    {"maps/t0a0.bsp", "Hazard Course"},
    {"maps/t0a0a.bsp", "Hazard Course"},
    {"maps/t0a0b.bsp", "Hazard Course"},
    {"maps/t0a0b1.bsp", "Hazard Course"},
    {"maps/t0a0b2.bsp", "Hazard Course"},
    {"maps/t0a0c.bsp", "Hazard Course"},
    {"maps/t0a0d.bsp", "Hazard Course"},
    {"maps/hldemo1.bsp", "Half-Life: Uplink"},
    {"maps/hldemo2.bsp", "Half-Life: Uplink"},
    {"maps/hldemo3.bsp", "Half-Life: Uplink"}
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
        const char* image = "hl_logo"; // Default image

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
