#include "trd_10.h"

extern EvtScript N(EVS_BossDefeated);

API_CALLABLE(N(IsPartnerBombette)) {
    if (gPlayerData.curPartner == PARTNER_BOMBETTE) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcAuxAI_KoopaBros_01) = {
    IfGe(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAux_KoopaBros_01) = {
    Return
    End
};

EvtScript N(EVS_NpcAI_KoopaBros_01) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerPos, -333, 0, 0)
    Call(SetNpcPos, NPC_PARTNER, -363, 0, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, -240, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -240, -170, 0)
    Call(SetCamPitch, CAM_DEFAULT, 18, -3)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(UseSettingsFrom, CAM_DEFAULT, -240, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -240, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.2 / DT))
    Call(PanToTarget, CAM_DEFAULT, Float(0.5), 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(PlaySound, SOUND_METAL_DOOR_OPEN)
    Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
    Label(10)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_o192, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_o191, LVar0, 0, 1, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, -220, 0, 0)
    Call(MakeLerp, -80, 0, 10, EASING_LINEAR)
    Label(11)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_o192, LVar0, 0, 1, 0)
    Call(RotateModel, MODEL_o191, LVar0, 0, -1, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(11)
    EndIf
    Call(PlaySound, SOUND_METAL_DOOR_CLOSE)
    Call(SetNpcPos, NPC_KoopaBros_01, -32, 0, 0)
    Call(NpcMoveTo, NPC_KoopaBros_01, -88, 0, 15 * DT)
    Wait(10 * DT)
    Call(SetNpcImgFXParams, NPC_KoopaBros_01, IMGFX_SET_ANIM, IMGFX_ANIM_STARTLE, 2, 1, 0)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Shock)
    Wait(12 * DT)
    Call(SetNpcImgFXParams, NPC_KoopaBros_01, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Idle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Walk, ANIM_KoopaBros_Black_Idle, 0, MSG_CH1_00F4)
    Call(SetNpcPos, NPC_KoopaBros_02, -32, 0, 0)
    Call(NpcMoveTo, NPC_KoopaBros_02, -64, 0, 10 * DT)
    Call(SpeakToPlayer, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Walk, ANIM_KoopaBros_Red_Idle, 0, MSG_CH1_00F5)
    Call(NpcMoveTo, NPC_KoopaBros_02, 0, 0, 10 * DT)
    Call(InterpNpcYaw, NPC_KoopaBros_01, -10, 4)
    Call(NpcMoveTo, NPC_KoopaBros_01, 0, 0, 10 * DT)
    Wait(30 * DT)
    Call(SetNpcPos, NPC_KoopaBros_01, NPC_DISPOSE_LOCATION)
    Call(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_INVISIBLE, TRUE)
    Call(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_HAS_SHADOW, FALSE)
    Call(SetNpcPos, NPC_KoopaBros_02, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_KoopaBros_03, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_KoopaBros_04, NPC_DISPOSE_LOCATION)
    Call(ShowMessageAtScreenPos, MSG_CH1_00F6, 300, 100)
    Call(ShowMessageAtScreenPos, MSG_CH1_00F7, 300, 100)
    Call(ShowMessageAtScreenPos, MSG_CH1_00F8, 300, 100)
    Call(PlaySoundAt, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT, 0, 0, 0)
    Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(1.0))
    Call(ShowMessageAtScreenPos, MSG_CH1_00F9, 300, 100)
    Wait(30 * DT)
    Call(ShowMessageAtScreenPos, MSG_CH1_00FA, 300, 100)
    Wait(30 * DT)
    Call(ShowMessageAtScreenPos, MSG_CH1_00FB, 300, 100)
    Wait(10 * DT)
    Call(ShowMessageAtScreenPos, MSG_CH1_00FC, 300, 100)
    Call(UseSettingsFrom, CAM_DEFAULT, -160, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -160, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.2 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Set(AF_TRD_FakeBowserRevealed, TRUE)
    Wait(60 * DT)
    Call(DisablePlayerInput, FALSE)
    Call(SetNpcPos, NPC_KoopaBros_01, -155, 0, 0)
    Call(StartBossBattle, SONG_FAKE_BOWSER_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcHit_KoopaBros_01) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_KoopaBros_01) = {
    Return
    End
};

EvtScript N(EVS_NpcDefeat_KoopaBros_01) = {
    Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcPos, NPC_KoopaBros_01, NPC_DISPOSE_LOCATION)
    Call(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_INVISIBLE, FALSE)
    Call(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_HAS_SHADOW, TRUE)
    Call(SetMusicTrack, 0, SONG_KOOPA_BROS_INTERLUDE, 0, 8)
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(PanToTarget, CAM_DEFAULT, 0, 0)
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(EnableGroup, MODEL_nise_koppa, FALSE)
            Call(SetNpcPos, NPC_KoopaBros_01, -170, 30, -55)
            Call(SetNpcPos, NPC_KoopaBros_02, -150, 30, 55)
            Call(SetNpcPos, NPC_KoopaBros_03, -130, 30, -55)
            Call(SetNpcPos, NPC_KoopaBros_04, -110, 30, 55)
            Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Launched)
            Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Launched)
            Call(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Launched)
            Call(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Launched)
            Wait(1)
            Thread
                Wait(30 * DT)
                Call(ShowMessageAtScreenPos, MSG_CH1_010B, 160, 40)
            EndThread
            Call(SetNpcJumpscale, NPC_KoopaBros_01, Float(0.3))
            Call(SetNpcJumpscale, NPC_KoopaBros_02, Float(0.3))
            Call(SetNpcJumpscale, NPC_KoopaBros_03, Float(0.3))
            Call(SetNpcJumpscale, NPC_KoopaBros_04, Float(0.3))
            Thread
                Call(NpcJump0, NPC_KoopaBros_01, -170, -400, -200, 75)
            EndThread
            Thread
                Call(NpcJump0, NPC_KoopaBros_02, -150, -400, 200, 75)
            EndThread
            Thread
                Call(NpcJump0, NPC_KoopaBros_03, -130, -400, -200, 75)
            EndThread
            Thread
                Call(NpcJump0, NPC_KoopaBros_04, -110, -400, 200, 75)
            EndThread
            Thread
                Wait(165 * DT)
                Exec(N(EVS_BossDefeated))
                Wait(1)
                Call(DisablePlayerInput, FALSE)
            EndThread
            Wait(120)
            Call(PlaySoundAt, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT, 0, 0, 0)
            Call(ShakeCam, CAM_DEFAULT, 0, 15, Float(0.5))
            Wait(15)
            Set(GF_TRD10_Defeated_KoopaBros, TRUE)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_02) = {
    IfGe(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAux_KoopaBros_02) = {
    Return
    End
};

EvtScript N(EVS_NpcAI_KoopaBros_02) = {
    Return
    End
};

EvtScript N(EVS_NpcHit_KoopaBros_02) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_KoopaBros_02) = {
    Return
    End
};

EvtScript N(EVS_NpcDefeat_KoopaBros_02) = {
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_03) = {
    IfGe(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAux_KoopaBros_03) = {
    Return
    End
};

EvtScript N(EVS_NpcAI_KoopaBros_03) = {
    Return
    End
};

EvtScript N(EVS_NpcHit_KoopaBros_03) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_KoopaBros_03) = {
    Return
    End
};

EvtScript N(EVS_NpcDefeat_KoopaBros_03) = {
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_04) = {
    IfGe(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAux_KoopaBros_04) = {
    Return
    End
};

EvtScript N(EVS_NpcAI_KoopaBros_04) = {
    Return
    End
};

EvtScript N(EVS_NpcHit_KoopaBros_04) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_KoopaBros_04) = {
    Return
    End
};

EvtScript N(EVS_NpcDefeat_KoopaBros_04) = {
    Return
    End
};

NpcSettings N(NpcSettings_KoopaBros_01) = {
    .defaultAnim = ANIM_KoopaBros_Black_Walk,
    .height = 34,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_KoopaBros_01),
    .onInteract = &N(EVS_NpcInteract_KoopaBros_01),
    .ai = &N(EVS_NpcAI_KoopaBros_01),
    .onHit = &N(EVS_NpcHit_KoopaBros_01),
    .aux = &N(EVS_NpcAux_KoopaBros_01),
    .onDefeat = &N(EVS_NpcDefeat_KoopaBros_01),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};

NpcSettings N(NpcSettings_KoopaBros_02) = {
    .defaultAnim = ANIM_KoopaBros_Red_Walk,
    .height = 34,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_KoopaBros_02),
    .onInteract = &N(EVS_NpcInteract_KoopaBros_02),
    .ai = &N(EVS_NpcAI_KoopaBros_02),
    .onHit = &N(EVS_NpcHit_KoopaBros_02),
    .aux = &N(EVS_NpcAux_KoopaBros_02),
    .onDefeat = &N(EVS_NpcDefeat_KoopaBros_02),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};

NpcSettings N(NpcSettings_KoopaBros_03) = {
    .defaultAnim = ANIM_KoopaBros_Yellow_Walk,
    .height = 34,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_KoopaBros_03),
    .onInteract = &N(EVS_NpcInteract_KoopaBros_03),
    .ai = &N(EVS_NpcAI_KoopaBros_03),
    .onHit = &N(EVS_NpcHit_KoopaBros_03),
    .aux = &N(EVS_NpcAux_KoopaBros_03),
    .onDefeat = &N(EVS_NpcDefeat_KoopaBros_03),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};

NpcSettings N(NpcSettings_KoopaBros_04) = {
    .defaultAnim = ANIM_KoopaBros_Green_Walk,
    .height = 34,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_KoopaBros_04),
    .onInteract = &N(EVS_NpcInteract_KoopaBros_04),
    .ai = &N(EVS_NpcAI_KoopaBros_04),
    .onHit = &N(EVS_NpcHit_KoopaBros_04),
    .aux = &N(EVS_NpcAux_KoopaBros_04),
    .onDefeat = &N(EVS_NpcDefeat_KoopaBros_04),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};

NpcData N(NpcData_KoopaBros_01)[] = {
    {
        .id = NPC_KoopaBros_01,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_KoopaBros_01),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_KoopaBros_Black_Idle,
            .walk   = ANIM_KoopaBros_Black_Walk,
            .run    = ANIM_KoopaBros_Black_Run,
            .chase  = ANIM_KoopaBros_Black_Run,
            .anim_4 = ANIM_KoopaBros_Black_Idle,
            .anim_5 = ANIM_KoopaBros_Black_Idle,
            .death  = ANIM_KoopaBros_Black_HurtStill,
            .hit    = ANIM_KoopaBros_Black_HurtStill,
            .anim_8 = ANIM_KoopaBros_Black_Run,
            .anim_9 = ANIM_KoopaBros_Black_Run,
            .anim_A = ANIM_KoopaBros_Black_Run,
            .anim_B = ANIM_KoopaBros_Black_Run,
            .anim_C = ANIM_KoopaBros_Black_Run,
            .anim_D = ANIM_KoopaBros_Black_Run,
            .anim_E = ANIM_KoopaBros_Black_Run,
            .anim_F = ANIM_KoopaBros_Black_Run,
        },
    },
    {
        .id = NPC_KoopaBros_02,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_KoopaBros_02),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_KoopaBros_Red_Idle,
            .walk   = ANIM_KoopaBros_Red_Walk,
            .run    = ANIM_KoopaBros_Red_Run,
            .chase  = ANIM_KoopaBros_Red_Run,
            .anim_4 = ANIM_KoopaBros_Red_Idle,
            .anim_5 = ANIM_KoopaBros_Red_Idle,
            .death  = ANIM_KoopaBros_Red_HurtStill,
            .hit    = ANIM_KoopaBros_Red_HurtStill,
            .anim_8 = ANIM_KoopaBros_Red_Run,
            .anim_9 = ANIM_KoopaBros_Red_Run,
            .anim_A = ANIM_KoopaBros_Red_Run,
            .anim_B = ANIM_KoopaBros_Red_Run,
            .anim_C = ANIM_KoopaBros_Red_Run,
            .anim_D = ANIM_KoopaBros_Red_Run,
            .anim_E = ANIM_KoopaBros_Red_Run,
            .anim_F = ANIM_KoopaBros_Red_Run,
        },
    },
    {
        .id = NPC_KoopaBros_03,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_KoopaBros_03),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_KoopaBros_Yellow_Idle,
            .walk   = ANIM_KoopaBros_Yellow_Walk,
            .run    = ANIM_KoopaBros_Yellow_Run,
            .chase  = ANIM_KoopaBros_Yellow_Run,
            .anim_4 = ANIM_KoopaBros_Yellow_Idle,
            .anim_5 = ANIM_KoopaBros_Yellow_Idle,
            .death  = ANIM_KoopaBros_Yellow_HurtStill,
            .hit    = ANIM_KoopaBros_Yellow_HurtStill,
            .anim_8 = ANIM_KoopaBros_Yellow_Run,
            .anim_9 = ANIM_KoopaBros_Yellow_Run,
            .anim_A = ANIM_KoopaBros_Yellow_Run,
            .anim_B = ANIM_KoopaBros_Yellow_Run,
            .anim_C = ANIM_KoopaBros_Yellow_Run,
            .anim_D = ANIM_KoopaBros_Yellow_Run,
            .anim_E = ANIM_KoopaBros_Yellow_Run,
            .anim_F = ANIM_KoopaBros_Yellow_Run,
        },
    },
    {
        .id = NPC_KoopaBros_04,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_KoopaBros_04),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_KoopaBros_Green_Idle,
            .walk   = ANIM_KoopaBros_Green_Walk,
            .run    = ANIM_KoopaBros_Green_Run,
            .chase  = ANIM_KoopaBros_Green_Run,
            .anim_4 = ANIM_KoopaBros_Green_Idle,
            .anim_5 = ANIM_KoopaBros_Green_Idle,
            .death  = ANIM_KoopaBros_Green_HurtStill,
            .hit    = ANIM_KoopaBros_Green_HurtStill,
            .anim_8 = ANIM_KoopaBros_Green_Run,
            .anim_9 = ANIM_KoopaBros_Green_Run,
            .anim_A = ANIM_KoopaBros_Green_Run,
            .anim_B = ANIM_KoopaBros_Green_Run,
            .anim_C = ANIM_KoopaBros_Green_Run,
            .anim_D = ANIM_KoopaBros_Green_Run,
            .anim_E = ANIM_KoopaBros_Green_Run,
            .anim_F = ANIM_KoopaBros_Green_Run,
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaBros_01), BTL_TRD_2_FORMATION_00),
    {}
};
