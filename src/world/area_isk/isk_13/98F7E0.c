#include "isk_13.h"
#include "sprite.h"
#include "sprite/npc/stone_chomp.h"

static char* N(exit_str_0) = "isk_12";
static char* N(exit_str_1) = "";

typedef struct StoneChompAmbushIsk13 {
    /* 0x00 */ s32 foldComponentID;
    /* 0x04 */ s32 workerID;
    /* 0x08 */ s32 spriteIndex;
    /* 0x0C */ s32 rasterIndex;
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ Vec3f scale;
    /* 0x34 */ f32 renderYaw;
    /* 0x38 */ f32 width;
    /* 0x3C */ f32 height;
} StoneChompAmbushIsk13; // size = 0x40

#include "world/common/enemy/StoneChompAI.inc.c"

ApiStatus N(UnkFunc53)(Evt* script, s32 isInitialCall) {
    NpcBlueprint bp;
    NpcBlueprint* bpPtr = &bp;
    NpcChompBlur* blurData;
    Npc* npc;
    Npc* newNpc;
    s32 i;

    npc = get_npc_safe(script->owner2.npcID);
    blurData = heap_malloc(8 * sizeof(*blurData));
    npc->blur.chomp = blurData;

    bp.flags = NPC_FLAG_8000 | NPC_FLAG_100 | NPC_FLAG_40
        | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_2;
    bp.initialAnim = NPC_ANIM_stone_chomp_Palette_00_Anim_2;
    bp.onUpdate = NULL;
    bp.onRender = NULL;

    for (i = 0; i < 8; i++, blurData++) {
        blurData->npc = newNpc = get_npc_by_index(_create_npc_basic(bpPtr));
        newNpc->pos.x = npc->pos.x;
        newNpc->pos.y = npc->pos.y;
        newNpc->pos.z = npc->pos.z;
        newNpc->yaw = npc->yaw;
        newNpc->verticalRenderOffset = 3;
        disable_npc_shadow(newNpc);
        blurData->offset.x = 0.0f;
        blurData->offset.y = 0.0f;
        blurData->offset.z = 0.0f;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802411F8_9909D8(Evt* script, s32 isInitialCall) {
    NpcChompBlur* blurData;
    Npc* ownerNpc;
    Npc* childNpc;
    f32 posX, posY, posZ;
    f32 nextX, nextY, nextZ;
    f32 invDist;
    f32 floorY;
    s32 i;

    floorY = (f32) script->owner1.enemy->varTable[0];
    ownerNpc = get_npc_safe(script->owner2.npcID);
    blurData = ownerNpc->blur.chomp;
    posX = ownerNpc->pos.x;
    posY = ownerNpc->pos.y + (ownerNpc->collisionHeight * 0.2f);
    posZ = ownerNpc->pos.z;
    add_vec2D_polar(&posX, &posZ, ownerNpc->collisionRadius * 0.3f, clamp_angle(ownerNpc->renderYaw + 180.0f));
    
    if (ownerNpc->flags & 2) {
        for (i = 0; i < 8; i++, blurData++) {
            childNpc = blurData->npc;
            childNpc->pos.x = posX;
            childNpc->pos.y = posY;
            childNpc->pos.z = posZ;
        }
        return ApiStatus_BLOCK;
    }
    
    for (i = 0; i < 8; i++, blurData++) {
        childNpc = blurData->npc;
        if (dist3D(childNpc->pos.x, childNpc->pos.y, childNpc->pos.z, posX, posY, posZ) >= 10.0) {
            invDist = 10.0 / dist3D(
                ((childNpc->pos.x - posX) * 0.8f) + posX, childNpc->pos.y, ((childNpc->pos.z - posZ) * 0.8f) + posZ,
                posX, posY,posZ);

            nextX = posX = ((childNpc->pos.x - posX) * 0.8f * invDist) + posX;
            nextY = posY = ((childNpc->pos.y - posY) * invDist) + posY;
            nextZ = posZ = ((childNpc->pos.z - posZ) * 0.8f * invDist) + posZ;

            blurData->offset.x = (nextX - childNpc->pos.x) * 0.7f;
            blurData->offset.y = (nextY - childNpc->pos.y) * 0.7f;
            blurData->offset.z = (nextZ - childNpc->pos.z) * 0.7f;
            
            childNpc->pos.x = nextX;
            childNpc->pos.y = nextY;
            childNpc->pos.z = nextZ;
            
            if (blurData->offset.y > 10.0f) {
                blurData->offset.y = 10.0f;
            }
        } else {
            blurData->offset.x = blurData->offset.x * 0.9f;
            blurData->offset.z = blurData->offset.z * 0.9f;
            childNpc->pos.x += blurData->offset.x;
            childNpc->pos.z += blurData->offset.z;
        }
        
        blurData->offset.y -= 1.0f;
        if (blurData->offset.y < -10.0f) {
            blurData->offset.y = -10.0f;
        }
        childNpc->pos.y += blurData->offset.y;
        if (childNpc->pos.y <= floorY) {
            childNpc->pos.y = floorY;
            blurData->offset.y = -blurData->offset.y * 0.5;
        }

        posX = childNpc->pos.x;
        posY = childNpc->pos.y;
        posZ = childNpc->pos.z;
        childNpc->flags = ownerNpc->flags;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802415C0_990DA0(Evt* script, s32 isInitialCall) {
    NpcChompBlur* blurData = get_npc_safe(script->owner2.npcID)->blur.chomp;
    s32 i;
    
    for (i = 0; i < 8; i++, blurData++) {
        free_npc(blurData->npc);
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_isk/isk_13/98F7E0", func_80241610_990DF0);

INCLUDE_ASM(s32, "world/area_isk/isk_13/98F7E0", func_80241BA8_991388);

INCLUDE_ASM(s32, "world/area_isk/isk_13/98F7E0", func_80241D08_9914E8);

INCLUDE_ASM(s32, "world/area_isk/isk_13/98F7E0", func_80241D38_991518);

INCLUDE_ASM(s32, "world/area_isk/isk_13/98F7E0", func_80241E34_991614);

INCLUDE_ASM(s32, "world/area_isk/isk_13/98F7E0", func_80241EF8_9916D8);

INCLUDE_ASM(s32, "world/area_isk/isk_13/98F7E0", func_80242044_991824);
