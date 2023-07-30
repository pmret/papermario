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
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_KoopaBros_01) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_KoopaBros_01) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerPos, -333, 0, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -363, 0, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -240, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -240, -170, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, -3)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -240, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -240, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.2 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, EVT_FLOAT(0.5), 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(PlaySound, SOUND_METAL_DOOR_OPEN)
    EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o192, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_o191, LVar0, 0, 1, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, -220, 0, 0)
    EVT_CALL(MakeLerp, -80, 0, 10, EASING_LINEAR)
    EVT_LABEL(11)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o192, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o191, LVar0, 0, -1, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_METAL_DOOR_CLOSE)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, -32, 0, 0)
    EVT_CALL(NpcMoveTo, NPC_KoopaBros_01, -88, 0, 15 * DT)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcImgFXParams, NPC_KoopaBros_01, IMGFX_SET_ANIM, IMGFX_ANIM_STARTLE, 2, 1, 0)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Shock)
    EVT_WAIT(12 * DT)
    EVT_CALL(SetNpcImgFXParams, NPC_KoopaBros_01, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Walk, ANIM_KoopaBros_Black_Idle, 0, MSG_CH1_00F4)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_02, -32, 0, 0)
    EVT_CALL(NpcMoveTo, NPC_KoopaBros_02, -64, 0, 10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Walk, ANIM_KoopaBros_Red_Idle, 0, MSG_CH1_00F5)
    EVT_CALL(NpcMoveTo, NPC_KoopaBros_02, 0, 0, 10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_01, -10, 4)
    EVT_CALL(NpcMoveTo, NPC_KoopaBros_01, 0, 0, 10 * DT)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_HAS_SHADOW, FALSE)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_02, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_03, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_04, NPC_DISPOSE_LOCATION)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00F6, 300, 100)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00F7, 300, 100)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00F8, 300, 100)
    EVT_CALL(PlaySoundAt, SOUND_1E2, SOUND_SPACE_MODE_0, 0, 0, 0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(1.0))
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00F9, 300, 100)
    EVT_WAIT(30 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00FA, 300, 100)
    EVT_WAIT(30 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00FB, 300, 100)
    EVT_WAIT(10 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00FC, 300, 100)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -160, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -160, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.2 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(AF_TRD_FakeBowserRevealed, TRUE)
    EVT_WAIT(60 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, -155, 0, 0)
    EVT_CALL(StartBossBattle, SONG_FAKE_BOWSER_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KoopaBros_01) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_KoopaBros_01) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_KoopaBros_01) = {
    EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_KoopaBros_01, NPC_FLAG_HAS_SHADOW, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_KOOPA_BROS_INTERLUDE, 0, 8)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(EnableGroup, MODEL_nise_koppa, FALSE)
            EVT_CALL(SetNpcPos, NPC_KoopaBros_01, -170, 30, -55)
            EVT_CALL(SetNpcPos, NPC_KoopaBros_02, -150, 30, 55)
            EVT_CALL(SetNpcPos, NPC_KoopaBros_03, -130, 30, -55)
            EVT_CALL(SetNpcPos, NPC_KoopaBros_04, -110, 30, 55)
            EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Black_Launched)
            EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Red_Launched)
            EVT_CALL(SetNpcAnimation, NPC_KoopaBros_03, ANIM_KoopaBros_Yellow_Launched)
            EVT_CALL(SetNpcAnimation, NPC_KoopaBros_04, ANIM_KoopaBros_Green_Launched)
            EVT_WAIT(1)
            EVT_THREAD
                EVT_WAIT(30 * DT)
                EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_010B, 160, 40)
            EVT_END_THREAD
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_01, EVT_FLOAT(0.3))
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_02, EVT_FLOAT(0.3))
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_03, EVT_FLOAT(0.3))
            EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_04, EVT_FLOAT(0.3))
            EVT_THREAD
                EVT_CALL(NpcJump0, NPC_KoopaBros_01, -170, -400, -200, 75)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(NpcJump0, NPC_KoopaBros_02, -150, -400, 200, 75)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(NpcJump0, NPC_KoopaBros_03, -130, -400, -200, 75)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(NpcJump0, NPC_KoopaBros_04, -110, -400, 200, 75)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(165 * DT)
                EVT_EXEC(N(EVS_BossDefeated))
                EVT_WAIT(1)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_END_THREAD
            EVT_WAIT(120)
            EVT_CALL(PlaySoundAt, SOUND_1E2, SOUND_SPACE_MODE_0, 0, 0, 0)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 15, EVT_FLOAT(0.5))
            EVT_WAIT(15)
            EVT_SET(GF_TRD10_Defeated_KoopaBros, TRUE)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_02) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_KoopaBros_02) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_KoopaBros_02) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KoopaBros_02) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_KoopaBros_02) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_KoopaBros_02) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_03) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_KoopaBros_03) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_KoopaBros_03) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KoopaBros_03) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_KoopaBros_03) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_KoopaBros_03) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_KoopaBros_04) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_DEFEATED_KOOPA_BROS)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_KoopaBros_04) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_KoopaBros_04) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_KoopaBros_04) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_KoopaBros_04) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_KoopaBros_04) = {
    EVT_RETURN
    EVT_END
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
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
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
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
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
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
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
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
};

NpcData N(NpcData_KoopaBros_01)[] = {
    {
        .id = NPC_KoopaBros_01,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_KoopaBros_01),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
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
