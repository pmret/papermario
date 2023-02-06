#include "obk_01.h"

#include "world/common/npc/Boo_Wander.inc.c"
#include "world/common/npc/Boo.inc.c"

#include "world/common/atomic/MarioSalute.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_Franky)[] = {
    ITEM_LETTER_CHAIN_FRANKY,
    ITEM_NONE 
};

EvtScript N(EVS_LetterPrompt_Franky) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Franky, ANIM_Boo_Talk, ANIM_Boo_Idle,
        ITEM_LETTER_CHAIN_FRANKY, ITEM_LETTER_CHAIN_DANE_T_1,
        MSG_CH3_0067, MSG_CH3_0068, MSG_CH3_0069, MSG_CH3_006A,
        EVT_PTR(N(LetterList_Franky)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

enum {
    TRAFFIC_BOO_INIT    = 0,
    TRAFFIC_BOO_MOVE    = 1,
};

s16 N(TrafficBooAlphas)[] = {
    50, 60, 200, 240
};

API_CALLABLE(N(UpdateTrafficBooMotion)) {
    Npc* npc = get_npc_safe(script->owner2.npcID);

    if (isInitialCall) {
        script->functionTemp[1] = TRAFFIC_BOO_INIT;
    }

    switch (script->functionTemp[1]) {
        case TRAFFIC_BOO_INIT:
            // choose random position offset
            npc->pos.z = rand_int(100) + 180;
            npc->pos.y = rand_int(100) - 200;
            // choose random speed
            npc->moveSpeed = (2.0f * rand_float()) + 2.0f;
            // chose random direction
            if (rand_int(100) < 50) {
                npc->pos.x = 920.0f;
                npc->yaw = 270.0f;
            } else {
                npc->pos.x = -20.0f;
                npc->yaw = 90.0f;
            }
            // begin moving
            script->functionTemp[1] = TRAFFIC_BOO_MOVE;
            break;
        case TRAFFIC_BOO_MOVE:
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (npc->pos.x < -30.0f || npc->pos.x > 930.0f) {
                script->functionTemp[1] = TRAFFIC_BOO_INIT;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(UpdateTrafficBooAlpha)) {
    s32 alpha = script->varTable[0];
    s32 nextChangeTime = script->varTable[1];
    s32 targetAlpha;

    if (nextChangeTime == 0) {
        // choose a new target alpha and schedule a time for the next update
        script->functionTemp[2] = N(TrafficBooAlphas)[rand_int(ARRAY_COUNT(N(TrafficBooAlphas)) - 1)];
        nextChangeTime = rand_int(50) + 30;
    }
    nextChangeTime--;

    targetAlpha = script->functionTemp[2];
    if (alpha < targetAlpha) {
        alpha += 10;
        if (targetAlpha < alpha) {
            alpha = targetAlpha;
        }
    }
    if (targetAlpha < alpha) {
        alpha -= 10;
        if (alpha < targetAlpha) {
            alpha = targetAlpha;
        }
    }

    script->varTable[0] = alpha;
    script->varTable[1] = nextChangeTime;
    return ApiStatus_DONE2;
}


EvtScript N(EVS_NpcIdle_TrafficBoo) = {
    EVT_CALL(N(UpdateTrafficBooMotion))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_TrafficBoo) = {
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_CALL(N(UpdateTrafficBooAlpha))
        EVT_CALL(func_802CFD30, -1, 7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrafficBoo1) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TrafficBoo)))
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_TrafficBoo)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_TrafficBoo2) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_TrafficBoo)))
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_TrafficBoo)))
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_UpstairsBoo) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0061)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0062)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0063)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Franky) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0064)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0065)
        EVT_CASE_GE(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0066)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Franky))
    EVT_IF_NE(LVarC, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GB_KootFavor_Current, KOOT_FAVOR_CH5_3)
        EVT_IF_EQ(GF_OBK01_Gift_OldPhoto, FALSE)
            EVT_SET(GF_OBK01_Gift_OldPhoto, TRUE)
            EVT_EXEC_WAIT(N(EVS_MarioSalute))
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_006B)
            EVT_GIVE_KEY_REWARD(ITEM_KOOT_OLD_PHOTO)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_UpstairsBoo) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_UpstairsBoo)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Franky) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Franky)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_JumpScareBoo) = {
    .id = NPC_JumpScareBoo,
    .settings = &N(NpcSettings_Boo),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_200 | ENEMY_FLAG_800,
    .drops = BOO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

StaticNpc N(NpcData_TrafficBoo1) = {
    .id = NPC_TrafficBoo1,
    .settings = &N(NpcSettings_Boo),
    .pos = { 523.0f, -139.0f, 193.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_TrafficBoo1),
    .drops = BOO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

StaticNpc N(NpcData_TrafficBoo2) = {
    .id = NPC_TrafficBoo2,
    .settings = &N(NpcSettings_Boo),
    .pos = { 473.0f, -122.0f, 247.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800,
    .init = &N(EVS_NpcInit_TrafficBoo2),
    .drops = BOO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

StaticNpc N(NpcData_Boos)[] = {
    {
        .id = NPC_UpstairsBoo,
        .settings = &N(NpcSettings_Boo_Wander),
        .pos = { 422.0f, -200.0f, 112.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_UpstairsBoo),
        .drops = BOO_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 422, -200, 112 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 422, -200, 112 },
                .detectSize = { 30 },
            }
        },
        .animations = NORMAL_BOO_ANIMS,
        .tattle = MSG_NpcTattle_OBK_BooA,
    },
    {
        .id = NPC_Franky,
        .settings = &N(NpcSettings_Boo_Wander),
        .pos = { 397.0f, -410.0f, 352.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Franky),
        .drops = BOO_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 397, -410, 352 },
                .wanderSize = { 80 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 397, -410, 352 },
                .detectSize = { 80 },
            }
        },
        .animations = NORMAL_BOO_ANIMS,
        .tattle = MSG_NpcTattle_OBK_BooB,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_JumpScareBoo)),
    NPC_GROUP(N(NpcData_TrafficBoo1)),
    NPC_GROUP(N(NpcData_TrafficBoo2)),
    NPC_GROUP(N(NpcData_Boos)),
    {}
};
