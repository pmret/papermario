
#include "StoneChomp.h"

#include "world/common/enemy/ai/StoneChompAI.inc.c"

API_CALLABLE(N(StoneChompFXA)) {
    NpcBlueprint bp;
    NpcBlueprint* bpPtr = &bp;
    NpcChompBlur* blurData;
    Npc* npc;
    Npc* newNpc;
    s32 i;

    npc = get_npc_safe(script->owner2.npcID);
    blurData = heap_malloc(8 * sizeof(*blurData));
    npc->blur.chomp = blurData;

    bp.flags = NPC_FLAG_IGNORE_ENTITY_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_WORLD_COLLISION
        | NPC_FLAG_FLYING | NPC_FLAG_INVISIBLE;
    bp.initialAnim = ANIM_StoneChomp_Chain;
    bp.onUpdate = NULL;
    bp.onRender = NULL;

    for (i = 0; i < 8; i++, blurData++) {
        blurData->npc = newNpc = get_npc_by_index(create_basic_npc(bpPtr));
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

API_CALLABLE(N(StoneChompFXB)) {
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
    add_vec2D_polar(&posX, &posZ, ownerNpc->collisionDiameter * 0.3f, clamp_angle(ownerNpc->renderYaw + 180.0f));

    if (ownerNpc->flags & NPC_FLAG_INVISIBLE) {
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

API_CALLABLE(N(StoneChompFXC)) {
    NpcChompBlur* blurData = get_npc_safe(script->owner2.npcID)->blur.chomp;
    s32 i;

    for (i = 0; i < 8; i++, blurData++) {
        free_npc(blurData->npc);
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcAuxAI_StoneChomp) = {
    EVT_CALL(N(StoneChompFXA))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(AISettings_StoneChomp) = {
    .moveSpeed = 2.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 5.3f,
    .chaseTurnRate = 70,
    .chaseUpdateInterval = 10,
    .chaseRadius = 500.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_StoneChomp) = {
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(N(StoneChompFXB))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_CALL(N(StoneChompAI_Main), EVT_PTR(N(AISettings_StoneChomp)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_StoneChomp) = {
    EVT_CALL(SetBattleMusic, SONG_SPECIAL_BATTLE)
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_NONE)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(GetSelfAnimationFromTable, ENEMY_ANIM_INDEX_HIT, LVar0)
            EVT_EXEC_WAIT(EVS_NpcHitRecoil)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_SPIN)
            EVT_THREAD
                EVT_CALL(func_800458CC, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_SET(LVarA, 0)
                    EVT_LOOP(30)
                        EVT_ADD(LVarA, 40)
                        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVarA, 0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_StoneChomp) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(N(StoneChompFXC))
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_StoneChomp) = {
    .height = 32,
    .radius = 32,
    .level = ACTOR_LEVEL_STONE_CHOMP,
    .otherAI = &N(EVS_NpcAuxAI_StoneChomp),
    .ai = &N(EVS_NpcAI_StoneChomp),
    .onHit = &N(EVS_NpcHit_StoneChomp),
    .onDefeat = &N(EVS_NpcDefeat_StoneChomp),
};
