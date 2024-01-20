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
    Call(N(LetterDelivery_Init),
        NPC_Franky, ANIM_Boo_Talk, ANIM_Boo_Idle,
        ITEM_LETTER_CHAIN_FRANKY, ITEM_LETTER_CHAIN_DANE_T_1,
        MSG_CH3_0067, MSG_CH3_0068, MSG_CH3_0069, MSG_CH3_006A,
        Ref(N(LetterList_Franky)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
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
    Call(N(UpdateTrafficBooMotion))
    Return
    End
};

EvtScript N(EVS_NpcAux_TrafficBoo) = {
    Set(LVar1, 0)
    Loop(0)
        Call(N(UpdateTrafficBooAlpha))
        Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_TrafficBoo1) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TrafficBoo)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_TrafficBoo)))
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_TrafficBoo2) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_TrafficBoo)))
    Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_TrafficBoo)))
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_UpstairsBoo) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0061)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0062)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0063)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Franky) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0064)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0065)
        CaseGe(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_0066)
    EndSwitch
    ExecWait(N(EVS_LetterPrompt_Franky))
    IfNe(LVarC, 0)
        Return
    EndIf
    IfEq(GB_KootFavor_Current, KOOT_FAVOR_CH5_3)
        IfEq(GF_OBK01_Gift_OldPhoto, FALSE)
            Set(GF_OBK01_Gift_OldPhoto, TRUE)
            ExecWait(N(EVS_MarioSalute))
            Call(SpeakToPlayer, NPC_SELF, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_006B)
            EVT_GIVE_KEY_REWARD(ITEM_KOOT_OLD_PHOTO)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_UpstairsBoo) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_UpstairsBoo)))
    IfLt(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Franky) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Franky)))
    IfLt(GB_StoryProgress, STORY_CH3_BOW_JOINED_PARTY)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

NpcData N(NpcData_JumpScareBoo) = {
    .id = NPC_JumpScareBoo,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_TrafficBoo1) = {
    .id = NPC_TrafficBoo1,
    .pos = { 523.0f, -139.0f, 193.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_TrafficBoo1),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_TrafficBoo2) = {
    .id = NPC_TrafficBoo2,
    .pos = { 473.0f, -122.0f, 247.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_TrafficBoo2),
    .settings = &N(NpcSettings_Boo),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = NORMAL_BOO_ANIMS,
};

NpcData N(NpcData_Boos)[] = {
    {
        .id = NPC_UpstairsBoo,
        .pos = { 422.0f, -200.0f, 112.0f },
        .yaw = 0,
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
        .init = &N(EVS_NpcInit_UpstairsBoo),
        .settings = &N(NpcSettings_Boo_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = NORMAL_BOO_ANIMS,
        .tattle = MSG_NpcTattle_OBK_BooA,
    },
    {
        .id = NPC_Franky,
        .pos = { 397.0f, -410.0f, 352.0f },
        .yaw = 0,
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
        .init = &N(EVS_NpcInit_Franky),
        .settings = &N(NpcSettings_Boo_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
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
