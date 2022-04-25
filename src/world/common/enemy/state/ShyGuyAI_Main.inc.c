#include "common.h"
#include "npc.h"

ApiStatus N(ShyGuyAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    Bytecode* args = script->ptrReadPos;
    NpcAISettings* aiSettings = (NpcAISettings*) evt_get_variable(script, *args++);
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 hitDepth;
    
    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 65.0f;
    territory.unk_1C = 0;
    
   if (isInitialCall || enemy->aiFlags & 4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
        
        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }
       
        if (enemy->aiFlags & 4) {
            script->functionTemp[0] = 0x63;
            script->functionTemp[1] = 0;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0] = 0xC;
        }
        enemy->aiFlags &= ~4;
        enemy->flags &= ~0x40000000;

        hitDepth = 100.0f;
        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &hitDepth)) {
            npc->pos.y = posY;
        }
    }
    
    switch (script->functionTemp[0]) {
        case 0x0:
            basic_ai_wander_init(script, aiSettings, territoryPtr);
            // fallthrough
        case 0x1:
            basic_ai_wander(script, aiSettings, territoryPtr);
            break;
        case 0x2:
            basic_ai_loiter_init(script, aiSettings, territoryPtr);
            // fallthrough
        case 0x3:
            basic_ai_loiter(script, aiSettings, territoryPtr);
            break;
        case 0xA:
            basic_ai_found_player_jump_init(script, aiSettings, territoryPtr);
            // fallthrough
        case 0xB:
            basic_ai_found_player_jump(script, aiSettings, territoryPtr);
            break;
        case 0xC:
            basic_ai_chase_init(script, aiSettings, territoryPtr);
            // fallthrough
        case 0xD:
            basic_ai_chase(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0xE) {
                break;
            }
           // fallthrough
        case 0xE:
            N(ShyGuyAI_14)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0xF) {
                break;
            }
           // fallthrough
        case 0xF:
            N(ShyGuyAI_15)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0x10) {
                break;
            }
            // fallthrough
        case 0x10:
            N(ShyGuyAI_16)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 0x11) {
                break;
            }
            // fallthrough
        case 0x11:
            N(UnkNpcDurationAnimationFunc)(script, aiSettings, territoryPtr);
            break;
        case 0x63:
            basic_ai_suspend(script);
            break;
    }

    return ApiStatus_BLOCK;
}
