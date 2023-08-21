#include "flo_00.h"

NpcSettings N(NpcSettings_Lakilester_Epilogue) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Parakarry.inc.c"

Vec3f N(D_80245E88_CA3DA8)[] = {
    { 266.0f,  20.0f, 322.0f },
    { 310.0f,  30.0f, 312.0f },
    { 346.0f,  90.0f, 300.0f },
    { 400.0f, 200.0f, 287.0f },
};

EvtScript N(EVS_Scene_Epilogue) = {
    EVT_CALL(SetPlayerPos, -400, 0, 200)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -380, 0, 200)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_VEC3I_SET(LVar0, 230, 0, 350)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(17.5), EVT_FLOAT(35.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, -50)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(70)
    EVT_CALL(InterpNpcYaw, NPC_Lakilester_Epilogue, 90, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Lakilester_Epilogue, ANIM_WorldLakilester_Talk)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_Lakilester_Epilogue, ANIM_WorldLakilester_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry_Epilogue, ANIM_WorldParakarry_Talk)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry_Epilogue, ANIM_WorldParakarry_Idle)
    EVT_CALL(InterpNpcYaw, NPC_Parakarry_Epilogue, 90, 0)
    EVT_CALL(NpcFlyTo, NPC_Parakarry_Epilogue, 400, 200, 287, 80, -5, EASING_LINEAR)
    EVT_CALL(InterpNpcYaw, NPC_Lakilester_Epilogue, 270, 0)
    EVT_WAIT(40)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_CALL(GotoMap, EVT_PTR("sam_11"), sam_11_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lakilester_Epilogue) = {
    EVT_CALL(SetPlayerPos, -400, 0, 200)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -380, 0, 200)
    EVT_CALL(SetNpcPos, NPC_Lakilester_Epilogue, 196, 20, 354)
    EVT_CALL(SetNpcYaw, NPC_Lakilester_Epilogue, 270)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lakilulu_Epilogue) = {
    EVT_CALL(SetNpcPos, NPC_Lakilulu_Epilogue, 163, 20, 370)
    EVT_CALL(SetNpcYaw, NPC_Lakilulu_Epilogue, 90)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Parakarry_Epilogue) = {
    EVT_CALL(SetNpcPos, NPC_Parakarry_Epilogue, 266, 20, 322)
    EVT_CALL(SetNpcYaw, NPC_Parakarry_Epilogue, 270)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Lakilester_Epilogue)[] = {
    {
        .id = NPC_Lakilester_Epilogue,
        .pos = { 144.0f, 0.0f, 374.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Lakilester_Epilogue),
        .settings = &N(NpcSettings_Lakilester_Epilogue),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldLakilester_Idle,
            .walk   = ANIM_WorldLakilester_Idle,
            .run    = ANIM_WorldLakilester_Idle,
            .chase  = ANIM_WorldLakilester_Idle,
            .anim_4 = ANIM_WorldLakilester_Idle,
            .anim_5 = ANIM_WorldLakilester_Idle,
            .death  = ANIM_WorldLakilester_Idle,
            .hit    = ANIM_WorldLakilester_Idle,
            .anim_8 = ANIM_WorldLakilester_Idle,
            .anim_9 = ANIM_WorldLakilester_Idle,
            .anim_A = ANIM_WorldLakilester_Idle,
            .anim_B = ANIM_WorldLakilester_Idle,
            .anim_C = ANIM_WorldLakilester_Idle,
            .anim_D = ANIM_WorldLakilester_Idle,
            .anim_E = ANIM_WorldLakilester_Idle,
            .anim_F = ANIM_WorldLakilester_Idle,
        },
    },
    {
        .id = NPC_Lakilulu_Epilogue,
        .pos = { 198.0f, 0.0f, 363.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Lakilulu_Epilogue),
        .settings = &N(NpcSettings_Lakilester_Epilogue),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Lakilulu_Idle,
            .walk   = ANIM_Lakilulu_Idle,
            .run    = ANIM_Lakilulu_Idle,
            .chase  = ANIM_Lakilulu_Idle,
            .anim_4 = ANIM_Lakilulu_Idle,
            .anim_5 = ANIM_Lakilulu_Idle,
            .death  = ANIM_Lakilulu_Idle,
            .hit    = ANIM_Lakilulu_Idle,
            .anim_8 = ANIM_Lakilulu_Idle,
            .anim_9 = ANIM_Lakilulu_Idle,
            .anim_A = ANIM_Lakilulu_Idle,
            .anim_B = ANIM_Lakilulu_Idle,
            .anim_C = ANIM_Lakilulu_Idle,
            .anim_D = ANIM_Lakilulu_Idle,
            .anim_E = ANIM_Lakilulu_Idle,
            .anim_F = ANIM_Lakilulu_Idle,
        },
    },
    {
        .id = NPC_Parakarry_Epilogue,
        .pos = { 266.0f, 0.0f, 322.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Parakarry_Epilogue),
        .settings = &N(NpcSettings_Parakarry),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = PARAKARRY_ANIMS,
    },
};

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Lakilester_Epilogue)),
    {}
};
