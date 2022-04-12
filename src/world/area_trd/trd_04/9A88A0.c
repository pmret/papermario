#include "trd_04.h"

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

#include "world/common/UnkNpcAIMainFunc5.inc.c"

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

#include "world/common/UnkNpcAIMainFunc.inc.c"

#include "world/common/UnkNpcAIMainFunc8.inc.c"

#include "world/common/UnkNpcAIFunc23.inc.c"

#include "world/common/UnkNpcAIFunc35.inc.c"

#include "world/common/UnkNpcAIFunc1_copy.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

#include "world/common/SixFloatsFunc.inc.c"

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

#include "world/common/UnkNpcAIMainFunc9.inc.c"

// todo remove when below are decompiled
static const f32 padding = 0.0f;

void func_80243310_9AB700(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 yawTemp;

    npc->currentAnim.w = enemy->animList[9];
    npc->jumpVelocity = -5.0f;
    npc->jumpScale = 0.15f;
    npc->collisionHeight = enemy->varTable[8] / 2;

    dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    npc->moveSpeed = 7.0f;
    enemy->unk_10.x = npc->pos.x;
    enemy->unk_10.y = npc->pos.y;
    enemy->unk_10.z = npc->pos.z;
    enemy->unk_07 = 1;

    ai_enemy_play_sound(npc, 0x2C1, 0);
    yawTemp = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    npc->duration = 0xC;
    npc->yaw = yawTemp;
    script->functionTemp[0] = 0xD;
}

void func_80243438_9AB828(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->jumpVelocity += npc->jumpScale;
    npc->pos.y += npc->jumpVelocity;
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    npc->duration--;

    if (npc->duration <= 0) {
        enemy->unk_07 = 0;
        npc->jumpScale = 0.3f;
        npc->jumpVelocity = 0.0f;
        npc->moveSpeed = 3.0f;
        npc->currentAnim.w = enemy->animList[10];
        script->functionTemp[0] = 0xE;
    }
}

INCLUDE_ASM(s32, "world/area_trd/trd_04/9A88A0", func_802434F4_9AB8E4);

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_04/9A88A0", func_80243650_9ABA40);
