#include "trd_05.h"
#include "effects.h"

extern EvtScript N(EVS_StartKoopaBrosTheme);
extern EvtScript N(EVS_EndKoopaBrosTheme);
extern EvtScript N(EVS_EnterMap);

API_CALLABLE(N(MakeHammerDust)) {
    fx_walking_dust(2, script->varTable[0], script->varTable[1], script->varTable[2], 0, 0);
    return ApiStatus_DONE2;
}

NpcSettings N(NpcSettings_KoopaBros) = {
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_KoopaBros_SetTrap) = {
    EVT_EXEC(N(EVS_StartKoopaBrosTheme))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerPos, -350, 0, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -350, 0, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -70, 240, -10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -70, 240, -10)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    EVT_THREAD
        EVT_LOOP(8)
            EVT_CALL(SetNpcImgFXParams, NPC_KoopaBros_01, IMGFX_SET_ALPHA, 0, 0, 0, 0)
            EVT_CALL(SetNpcImgFXParams, NPC_KoopaBros_02, IMGFX_SET_ALPHA, 255, 0, 0, 0)
            EVT_WAIT(6 * DT)
            EVT_CALL(SetNpcImgFXParams, NPC_KoopaBros_01, IMGFX_SET_ALPHA, 255, 0, 0, 0)
            EVT_CALL(SetNpcImgFXParams, NPC_KoopaBros_02, IMGFX_SET_ALPHA, 0, 0, 0, 0)
            EVT_WAIT(6 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(8)
            EVT_WAIT(5 * DT)
            EVT_CALL(GetNpcPos, NPC_KoopaBros_02, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 8)
            EVT_CALL(N(MakeHammerDust))
            EVT_WAIT(5 * DT)
            EVT_CALL(GetNpcPos, NPC_KoopaBros_01, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 8)
            EVT_CALL(N(MakeHammerDust))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_TRD_POUNDING_HIGH)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_02, -100, 240, 30)
        EVT_CALL(SetNpcYaw, NPC_KoopaBros_02, 90)
        EVT_WAIT(15 * DT)
        EVT_CALL(PlaySound, SOUND_TRD_POUNDING_LOW)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_02, -35, 240, -75)
        EVT_CALL(SetNpcYaw, NPC_KoopaBros_02, 270)
        EVT_WAIT(15 * DT)
        EVT_CALL(PlaySound, SOUND_TRD_POUNDING_HIGH)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_02, -40, 240, 10)
        EVT_CALL(SetNpcYaw, NPC_KoopaBros_02, 270)
        EVT_WAIT(15 * DT)
        EVT_CALL(PlaySound, SOUND_TRD_POUNDING_LOW)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_02, -110, 240, -20)
        EVT_CALL(SetNpcYaw, NPC_KoopaBros_02, 90)
        EVT_WAIT(15 * DT)
        EVT_CALL(PlaySound, SOUND_TRD_POUNDING_HIGH)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_02, -90, 240, 30)
        EVT_CALL(SetNpcYaw, NPC_KoopaBros_02, 90)
        EVT_WAIT(15 * DT)
        EVT_CALL(PlaySound, SOUND_TRD_POUNDING_LOW)
        EVT_CALL(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_02, -30, 240, -50)
        EVT_CALL(SetNpcYaw, NPC_KoopaBros_02, 270)
        EVT_WAIT(15 * DT)
        EVT_CALL(SetNpcPos, NPC_KoopaBros_02, 0, -500, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, -45, 240, -30)
    EVT_CALL(SetNpcYaw, NPC_KoopaBros_01, 270)
    EVT_WAIT(1)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_01, EVT_FLOAT(1.6))
    EVT_CALL(NpcJump0, NPC_KoopaBros_01, -45, 240, -30, 6 * DT)
    EVT_CALL(NpcJump0, NPC_KoopaBros_01, -45, 240, -30, 6 * DT)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, -120, 240, 20)
    EVT_CALL(SetNpcYaw, NPC_KoopaBros_01, 90)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_PointForward)
    EVT_WAIT(15 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, -110, 240, -70)
    EVT_CALL(SetNpcYaw, NPC_KoopaBros_01, 90)
    EVT_WAIT(1)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_01, EVT_FLOAT(1.6))
    EVT_CALL(NpcJump0, NPC_KoopaBros_01, -110, 240, -70, 6 * DT)
    EVT_CALL(NpcJump0, NPC_KoopaBros_01, -110, 240, -70, 6 * DT)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, -35, 240, -51)
    EVT_CALL(SetNpcYaw, NPC_KoopaBros_01, 270)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_PointForward)
    EVT_WAIT(14 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, -45, 240, -25)
    EVT_CALL(SetNpcYaw, NPC_KoopaBros_01, 270)
    EVT_WAIT(1)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_01, EVT_FLOAT(1.6))
    EVT_CALL(NpcJump0, NPC_KoopaBros_01, -45, 240, -25, 6 * DT)
    EVT_CALL(NpcJump0, NPC_KoopaBros_01, -45, 240, -25, 6 * DT)
    EVT_WAIT(1)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, -120, 240, 20)
    EVT_CALL(SetNpcYaw, NPC_KoopaBros_01, 90)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_PointForward)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, -120, 240, 20)
    EVT_CALL(SetNpcYaw, NPC_KoopaBros_01, 90)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_ThumbsUp)
    EVT_WAIT(26 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Walk)
    EVT_CALL(SetNpcSpeed, NPC_KoopaBros_01, EVT_FLOAT(4.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_KoopaBros_01, -25, -15, 0)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_01, 270, 4)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_IdleCrouch)
    EVT_WAIT(25 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Walk)
    EVT_CALL(SetNpcSpeed, NPC_KoopaBros_01, EVT_FLOAT(4.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_KoopaBros_01, -122, -15, 0)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    EVT_WAIT(3 * DT)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_01, 90, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Talk, ANIM_KoopaBros_Yellow_Idle, 5, MSG_CH1_00D5)
    EVT_CALL(GetNpcPos, NPC_KoopaBros_01, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtNpc, NPC_KoopaBros_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_KoopaBros_01, EMOTE_EXCLAMATION, 0, 25, EMOTER_POS, LVar0, LVar1, LVar2, 40)
    EVT_WAIT(25 * DT)
    EVT_CALL(InterpNpcYaw, NPC_KoopaBros_01, 270, 2)
    EVT_WAIT(7 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_IdleCrouch)
    EVT_WAIT(25 * DT)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    EVT_CALL(GetNpcPos, NPC_KoopaBros_01, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_01, EVT_FLOAT(3.0))
    EVT_CALL(NpcJump0, NPC_KoopaBros_01, LVar0, LVar1, LVar2, 5 * DT)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Talk, ANIM_KoopaBros_Yellow_Idle, 0, MSG_CH1_00D6)
    EVT_CALL(PlaySound, SOUND_RUN_AWAY_BUILDUP)
    EVT_CALL(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Run)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaBros_01, EVT_FLOAT(0.8))
    EVT_CALL(GetNpcPos, NPC_KoopaBros_01, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_KoopaBros_01, LVar0, LVar1, LVar2, 8 * DT)
    EVT_WAIT(8 * DT)
    EVT_CALL(PlaySound, SOUND_RUN_AWAY)
    EVT_CALL(SetNpcSpeed, NPC_KoopaBros_01, EVT_FLOAT(8.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_KoopaBros_01, -400, -10, 0)
    EVT_EXEC(N(EVS_EndKoopaBrosTheme))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -270, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -270, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcPos, NPC_KoopaBros_01, NPC_DISPOSE_LOCATION)
    EVT_CALL(PlaySound, SOUND_METAL_DOOR_OPEN)
    EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_doa2, LVar0, 0, -1, 0)
    EVT_CALL(RotateModel, MODEL_doa1, LVar0, 0, 1, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetPlayerPos, -310, 0, 0)
    EVT_EXEC_WAIT(N(EVS_EnterMap))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(GB_StoryProgress, STORY_CH1_KOOPA_BROS_SET_TRAP)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaBros) = {
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_MARIO_ACTIVATED_TRAP)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_KoopaBros)[] = {
    {
        .id = NPC_KoopaBros_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopaBros),
        .settings = &N(NpcSettings_KoopaBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
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
        .id = NPC_KoopaBros_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopaBros),
        .settings = &N(NpcSettings_KoopaBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
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
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaBros)),
    {}
};
