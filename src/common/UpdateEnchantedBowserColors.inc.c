#include "common.h"
#include "sprite.h"

#ifndef BOWSER_LARGE
#define BOWSER_FLAG_TOCHECK ACTOR_EVENT_FLAG_ENCHANTED
#else
#define BOWSER_FLAG_TOCHECK ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED
#endif

API_CALLABLE(N(UpdateEnchantedBowserColors)) {
    Actor* actor = get_actor(script->owner1.actorID);
    ActorPart* part;
    s32 i, j;
    u8 colR[20];
    u8 colG[20];
    u8 colB[20];
    s32 colorRGBA;
    s32 temp;
    s32 lol;

    if (actor == NULL) {
        return ApiStatus_DONE2;
    }

    part = get_actor_part(actor, 1);

    if (isInitialCall) {
        script->functionTemp[1] = 0;
        script->functionTemp[2] = 0;
        script->functionTemp[0] = 0;

        for (i = 0; i < 10; i++) {
            set_npc_imgfx_comp(part->spriteInstanceID, i, IMGFX_ALLOC_COLOR_BUF, 20, 0, 0, 255, 0);
        }
    }

    script->functionTemp[1] += 10;
    if (script->functionTemp[1] >= 360) {
        script->functionTemp[1] %= 360;
    }

    for (j = 0; j < 20; j++) {
        colR[j] = (cosine(script->functionTemp[1] + j * 25 + 120) + 1.0) * 56.0;
        colG[j] = (cosine(script->functionTemp[1] + j * 25 + 60) + 1.0) * 56.0;
        colB[j] = (cosine(script->functionTemp[1] + j * 25 + 180) + 1.0) * 56.0;
    }

    if (part->eventFlags & BOWSER_FLAG_TOCHECK) {

        for (j = 0; j < 20; j++) {
            colorRGBA = colR[j] << 0x18 | colG[j] << 0x10 | colB[j] << 8 | 0xFF;
            for (i = 0; i < 10; i++) {
                set_npc_imgfx_comp(part->spriteInstanceID, i, IMGFX_COLOR_BUF_SET_MODULATE, j, colorRGBA, 0, 255, 0);
            }
        }
        return ApiStatus_BLOCK;
    } else {
        s32 opacity = 255;
        for (j = 0; j < 20; j++) {
            colorRGBA = 255;
            for (i = 0; i < 10; i++) {
                // TODO find better match for opacity
                set_npc_imgfx_comp(part->spriteInstanceID, i, IMGFX_COLOR_BUF_SET_MODULATE, j, colorRGBA, 0, opacity & 0xFFFF, 0);
            }
        }
        script->functionTemp[1] = 0;
        script->functionTemp[2] = 0;
        script->functionTemp[0] = 0;
        return ApiStatus_BLOCK;
    }
}
