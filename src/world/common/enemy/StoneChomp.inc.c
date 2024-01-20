
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
    Call(N(StoneChompFXA))
    Return
    End
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
    ChildThread
        Loop(0)
            Call(N(StoneChompFXB))
            Wait(1)
        EndLoop
    EndChildThread
    Call(GetSelfVar, 0, LVar0)
    Call(N(StoneChompAI_Main), Ref(N(AISettings_StoneChomp)))
    Return
    End
};

EvtScript N(EVS_NpcHit_StoneChomp) = {
    Call(SetBattleMusic, SONG_SPECIAL_BATTLE)
    Call(GetOwnerEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_NONE)
        CaseOrEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
            Call(GetSelfAnimationFromTable, ENEMY_ANIM_INDEX_HIT, LVar0)
            ExecWait(EVS_NpcHitRecoil)
        CaseEq(ENCOUNTER_TRIGGER_SPIN)
            Thread
                Call(func_800458CC, LVar0)
                IfEq(LVar0, 0)
                    Set(LVarA, 0)
                    Loop(30)
                        Add(LVarA, 40)
                        Call(SetNpcRotation, NPC_SELF, 0, LVarA, 0)
                        Wait(1)
                    EndLoop
                EndIf
            EndThread
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcDefeat_StoneChomp) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(N(StoneChompFXC))
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
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
