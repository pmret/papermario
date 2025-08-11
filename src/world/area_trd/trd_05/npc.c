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
    Exec(N(EVS_StartKoopaBrosTheme))
    Call(DisablePlayerInput, true)
    Call(DisablePartnerAI, 0)
    Call(SetPlayerPos, -350, 0, 0)
    Call(SetNpcPos, NPC_PARTNER, -350, 0, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, -70, 240, -10)
    Call(SetPanTarget, CAM_DEFAULT, -70, 240, -10)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    Thread
        Loop(8)
            Call(SetNpcImgFXParams, NPC_KoopaBros_01, IMGFX_SET_ALPHA, 0, 0, 0, 0)
            Call(SetNpcImgFXParams, NPC_KoopaBros_02, IMGFX_SET_ALPHA, 255, 0, 0, 0)
            Wait(6 * DT)
            Call(SetNpcImgFXParams, NPC_KoopaBros_01, IMGFX_SET_ALPHA, 255, 0, 0, 0)
            Call(SetNpcImgFXParams, NPC_KoopaBros_02, IMGFX_SET_ALPHA, 0, 0, 0, 0)
            Wait(6 * DT)
        EndLoop
    EndThread
    Thread
        Loop(8)
            Wait(5 * DT)
            Call(GetNpcPos, NPC_KoopaBros_02, LVar0, LVar1, LVar2)
            Add(LVar1, 8)
            Call(N(MakeHammerDust))
            Wait(5 * DT)
            Call(GetNpcPos, NPC_KoopaBros_01, LVar0, LVar1, LVar2)
            Add(LVar1, 8)
            Call(N(MakeHammerDust))
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(PlaySound, SOUND_TRD_POUNDING_HIGH)
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        Call(SetNpcPos, NPC_KoopaBros_02, -100, 240, 30)
        Call(SetNpcYaw, NPC_KoopaBros_02, 90)
        Wait(15 * DT)
        Call(PlaySound, SOUND_TRD_POUNDING_LOW)
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        Call(SetNpcPos, NPC_KoopaBros_02, -35, 240, -75)
        Call(SetNpcYaw, NPC_KoopaBros_02, 270)
        Wait(15 * DT)
        Call(PlaySound, SOUND_TRD_POUNDING_HIGH)
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        Call(SetNpcPos, NPC_KoopaBros_02, -40, 240, 10)
        Call(SetNpcYaw, NPC_KoopaBros_02, 270)
        Wait(15 * DT)
        Call(PlaySound, SOUND_TRD_POUNDING_LOW)
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        Call(SetNpcPos, NPC_KoopaBros_02, -110, 240, -20)
        Call(SetNpcYaw, NPC_KoopaBros_02, 90)
        Wait(15 * DT)
        Call(PlaySound, SOUND_TRD_POUNDING_HIGH)
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        Call(SetNpcPos, NPC_KoopaBros_02, -90, 240, 30)
        Call(SetNpcYaw, NPC_KoopaBros_02, 90)
        Wait(15 * DT)
        Call(PlaySound, SOUND_TRD_POUNDING_LOW)
        Call(SetNpcAnimation, NPC_KoopaBros_02, ANIM_KoopaBros_Yellow_Hammering)
        Call(SetNpcPos, NPC_KoopaBros_02, -30, 240, -50)
        Call(SetNpcYaw, NPC_KoopaBros_02, 270)
        Wait(15 * DT)
        Call(SetNpcPos, NPC_KoopaBros_02, 0, -500, 0)
    EndThread
    Call(SetNpcPos, NPC_KoopaBros_01, -45, 240, -30)
    Call(SetNpcYaw, NPC_KoopaBros_01, 270)
    Wait(1)
    Call(SetNpcJumpscale, NPC_KoopaBros_01, Float(1.6))
    Call(NpcJump0, NPC_KoopaBros_01, -45, 240, -30, 6 * DT)
    Call(NpcJump0, NPC_KoopaBros_01, -45, 240, -30, 6 * DT)
    Call(SetNpcPos, NPC_KoopaBros_01, -120, 240, 20)
    Call(SetNpcYaw, NPC_KoopaBros_01, 90)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_PointForward)
    Wait(15 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    Call(SetNpcPos, NPC_KoopaBros_01, -110, 240, -70)
    Call(SetNpcYaw, NPC_KoopaBros_01, 90)
    Wait(1)
    Call(SetNpcJumpscale, NPC_KoopaBros_01, Float(1.6))
    Call(NpcJump0, NPC_KoopaBros_01, -110, 240, -70, 6 * DT)
    Call(NpcJump0, NPC_KoopaBros_01, -110, 240, -70, 6 * DT)
    Call(SetNpcPos, NPC_KoopaBros_01, -35, 240, -51)
    Call(SetNpcYaw, NPC_KoopaBros_01, 270)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_PointForward)
    Wait(14 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    Call(SetNpcPos, NPC_KoopaBros_01, -45, 240, -25)
    Call(SetNpcYaw, NPC_KoopaBros_01, 270)
    Wait(1)
    Call(SetNpcJumpscale, NPC_KoopaBros_01, Float(1.6))
    Call(NpcJump0, NPC_KoopaBros_01, -45, 240, -25, 6 * DT)
    Call(NpcJump0, NPC_KoopaBros_01, -45, 240, -25, 6 * DT)
    Wait(1)
    Call(SetNpcPos, NPC_KoopaBros_01, -120, 240, 20)
    Call(SetNpcYaw, NPC_KoopaBros_01, 90)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_PointForward)
    Wait(20 * DT)
    Call(SetNpcPos, NPC_KoopaBros_01, -120, 240, 20)
    Call(SetNpcYaw, NPC_KoopaBros_01, 90)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_ThumbsUp)
    Wait(26 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Walk)
    Call(SetNpcSpeed, NPC_KoopaBros_01, Float(4.0 / DT))
    Call(NpcMoveTo, NPC_KoopaBros_01, -25, -15, 0)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    Wait(10 * DT)
    Call(InterpNpcYaw, NPC_KoopaBros_01, 270, 4)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_IdleCrouch)
    Wait(25 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Walk)
    Call(SetNpcSpeed, NPC_KoopaBros_01, Float(4.0 / DT))
    Call(NpcMoveTo, NPC_KoopaBros_01, -122, -15, 0)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    Wait(3 * DT)
    Call(InterpNpcYaw, NPC_KoopaBros_01, 90, 5)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Talk, ANIM_KoopaBros_Yellow_Idle, 5, MSG_CH1_00D5)
    Call(GetNpcPos, NPC_KoopaBros_01, LVar0, LVar1, LVar2)
    Call(PlaySoundAtNpc, NPC_KoopaBros_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_KoopaBros_01, EMOTE_EXCLAMATION, 0, 25, EMOTER_POS, LVar0, LVar1, LVar2, 40)
    Wait(25 * DT)
    Call(InterpNpcYaw, NPC_KoopaBros_01, 270, 2)
    Wait(7 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_IdleCrouch)
    Wait(25 * DT)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Idle)
    Call(GetNpcPos, NPC_KoopaBros_01, LVar0, LVar1, LVar2)
    Call(SetNpcJumpscale, NPC_KoopaBros_01, Float(3.0))
    Call(NpcJump0, NPC_KoopaBros_01, LVar0, LVar1, LVar2, 5 * DT)
    Call(SpeakToPlayer, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Talk, ANIM_KoopaBros_Yellow_Idle, 0, MSG_CH1_00D6)
    Call(PlaySound, SOUND_RUN_AWAY_BUILDUP)
    Call(SetNpcAnimation, NPC_KoopaBros_01, ANIM_KoopaBros_Yellow_Run)
    Call(SetNpcJumpscale, NPC_KoopaBros_01, Float(0.8))
    Call(GetNpcPos, NPC_KoopaBros_01, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_KoopaBros_01, LVar0, LVar1, LVar2, 8 * DT)
    Wait(8 * DT)
    Call(PlaySound, SOUND_RUN_AWAY)
    Call(SetNpcSpeed, NPC_KoopaBros_01, Float(8.0 / DT))
    Call(NpcMoveTo, NPC_KoopaBros_01, -400, -10, 0)
    Exec(N(EVS_EndKoopaBrosTheme))
    Call(UseSettingsFrom, CAM_DEFAULT, -270, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -270, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcPos, NPC_KoopaBros_01, NPC_DISPOSE_LOCATION)
    Call(PlaySound, SOUND_METAL_DOOR_OPEN)
    Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
    Label(10)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_doa2, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_doa1, LVar0, 0, 1, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(DisablePlayerInput, false)
    Call(EnablePartnerAI)
    Call(SetPlayerPos, -310, 0, 0)
    ExecWait(N(EVS_EnterMap))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Set(GB_StoryProgress, STORY_CH1_KOOPA_BROS_SET_TRAP)
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaBros) = {
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    IfGe(GB_StoryProgress, STORY_CH1_MARIO_ACTIVATED_TRAP)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_KoopaBros)[] = {
    {
        .id = NPC_KoopaBros_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopaBros),
        .settings = &N(NpcSettings_KoopaBros),
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
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
        .flags = BASE_PASSIVE_FLAGS | ENEMY_FLAG_IGNORE_PLAYER_COLLISION,
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
