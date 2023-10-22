#include "mim_11.h"

void increment_max_star_power(void);

NpcSettings N(NpcSettings_Bootler) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_Skolar) = {
    .height = 26,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_Unused1) = {
    .height = 20,
    .radius = 20,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_Unused2) = {
    .height = 22,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

API_CALLABLE(N(IncreaseMaxSP)) {
    increment_max_star_power();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AnimateStarSpiritBobbing)) {
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = 0;
        script->functionTempPtr[2] = get_npc_safe(script->owner2.npcID);
    }

    npc = script->functionTempPtr[2];
    npc->verticalRenderOffset = sin_deg(script->functionTempF[1]) * 6.0f;
    script->functionTempF[1] = clamp_angle(script->functionTempF[1] + 18.0f);
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_NpcAux_Skolar) = {
    EVT_CALL(N(AnimateStarSpiritBobbing))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Skolar) = {
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_Skolar)))
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, -100)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_IF_NE(GB_StoryProgress, STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bootler) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_OPENED_BOOS_MANSION_GATE)
            EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
            EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ALPHA, 0, 0, 0, 0)
        EVT_CASE_DEFAULT
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Bootler)[] = {
    {
        .id = NPC_Bootler,
        .pos = { 68.0f, 60.0f, -145.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bootler),
        .settings = &N(NpcSettings_Bootler),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Bootler_Idle,
            .walk   = ANIM_Bootler_Walk,
            .run    = ANIM_Bootler_Run,
            .chase  = ANIM_Bootler_Run,
            .anim_4 = ANIM_Bootler_Idle,
            .anim_5 = ANIM_Bootler_Idle,
            .death  = ANIM_Bootler_Still,
            .hit    = ANIM_Bootler_Still,
            .anim_8 = ANIM_Bootler_Shock,
            .anim_9 = ANIM_Bootler_Panic,
            .anim_A = ANIM_Bootler_Dejected,
            .anim_B = ANIM_Bootler_Quaver,
            .anim_C = ANIM_Bootler_Shock,
            .anim_D = ANIM_Bootler_Panic,
            .anim_E = ANIM_Bootler_Dejected,
            .anim_F = ANIM_Bootler_Quaver,
        },
    },
    {
        .id = NPC_Skolar,
        .pos = { 68.0f, 60.0f, -145.0f },
        .yaw = 135,
        .init = &N(EVS_NpcInit_Skolar),
        .settings = &N(NpcSettings_Skolar),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldSkolar_Idle,
            .walk   = ANIM_WorldSkolar_Idle,
            .run    = ANIM_WorldSkolar_Idle,
            .chase  = ANIM_WorldSkolar_Idle,
            .anim_4 = ANIM_WorldSkolar_Idle,
            .anim_5 = ANIM_WorldSkolar_Idle,
            .death  = ANIM_WorldSkolar_Idle,
            .hit    = ANIM_WorldSkolar_Idle,
            .anim_8 = ANIM_WorldSkolar_Still,
            .anim_9 = ANIM_WorldSkolar_Idle,
            .anim_A = ANIM_WorldSkolar_Idle,
            .anim_B = ANIM_WorldSkolar_Idle,
            .anim_C = ANIM_WorldSkolar_Idle,
            .anim_D = ANIM_WorldSkolar_Idle,
            .anim_E = ANIM_WorldSkolar_Idle,
            .anim_F = ANIM_WorldSkolar_Idle,
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Bootler)),
    {}
};
