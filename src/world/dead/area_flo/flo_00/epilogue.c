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
    Call(SetPlayerPos, -400, 0, 200)
    Call(SetNpcPos, NPC_PARTNER, -380, 0, 200)
    Call(func_802CF56C, 2)
    Call(DisablePartnerAI, 0)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    EVT_VEC3I_SET(LVar0, 230, 0, 350)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-10.0))
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamPosA, CAM_DEFAULT, Float(17.5), Float(35.0))
    Call(SetCamPosB, CAM_DEFAULT, 0, -50)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(70)
    Call(InterpNpcYaw, NPC_Lakilester_Epilogue, 90, 0)
    Wait(10)
    Call(SetNpcAnimation, NPC_Lakilester_Epilogue, ANIM_WorldLakilester_Talk)
    Wait(40)
    Call(SetNpcAnimation, NPC_Lakilester_Epilogue, ANIM_WorldLakilester_Idle)
    Call(SetNpcAnimation, NPC_Parakarry_Epilogue, ANIM_WorldParakarry_Talk)
    Wait(40)
    Call(SetNpcAnimation, NPC_Parakarry_Epilogue, ANIM_WorldParakarry_Idle)
    Call(InterpNpcYaw, NPC_Parakarry_Epilogue, 90, 0)
    Call(NpcFlyTo, NPC_Parakarry_Epilogue, 400, 200, 287, 80, -5, EASING_LINEAR)
    Call(InterpNpcYaw, NPC_Lakilester_Epilogue, 270, 0)
    Wait(40)
    Call(FadeOutMusic, 0, 1000)
    Call(GotoMap, Ref("sam_11"), sam_11_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakilester_Epilogue) = {
    Call(SetPlayerPos, -400, 0, 200)
    Call(SetNpcPos, NPC_PARTNER, -380, 0, 200)
    Call(SetNpcPos, NPC_Lakilester_Epilogue, 196, 20, 354)
    Call(SetNpcYaw, NPC_Lakilester_Epilogue, 270)
    Return
    End
};

EvtScript N(EVS_NpcInit_Lakilulu_Epilogue) = {
    Call(SetNpcPos, NPC_Lakilulu_Epilogue, 163, 20, 370)
    Call(SetNpcYaw, NPC_Lakilulu_Epilogue, 90)
    Return
    End
};

EvtScript N(EVS_NpcInit_Parakarry_Epilogue) = {
    Call(SetNpcPos, NPC_Parakarry_Epilogue, 266, 20, 322)
    Call(SetNpcYaw, NPC_Parakarry_Epilogue, 270)
    Return
    End
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
