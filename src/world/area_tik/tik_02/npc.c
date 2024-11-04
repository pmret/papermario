#include "tik_02.h"

#include "world/common/enemy/Blooper.inc.c"

EvtScript N(EVS_NpcIdle_Blooper) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGt(LVar0, 65)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Exec(N(EVS_PlayBlooperSong))
    Call(ShowMessageAtScreenPos, MSG_MGM_0000, 160, 40)
    Thread
        Call(InterpPlayerYaw, 315, 0)
        Wait(50)
        Call(InterpPlayerYaw, 45, 0)
    EndThread
    Call(UseSettingsFrom, CAM_DEFAULT, -25, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, -25, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20)
    Thread
        Wait(10)
        Call(SetPanTarget, CAM_DEFAULT, 140, LVar1, LVar2)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_BLOOPER_MOVE, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    Call(SetNpcPos, NPC_SELF, -100, -300, -120)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Blooper_Anim01)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
    Call(NpcJump0, NPC_SELF, 175, 0, 0, 40)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Blooper_Anim0C)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    Wait(15)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Blooper) = {
    Wait(5)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_SELF, ANIM_Blooper_Anim04)
        Call(MakeLerp, 0, 6 * 360, 40, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            Call(PlayerFaceNpc, NPC_SELF, FALSE)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_BLOOPER_FALL, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
    Call(NpcJump0, NPC_SELF, -100, -300, -120, 40)
    Wait(1)
    IfEq(GF_TIK_DefeatedOneBlooper, FALSE)
        Set(GF_TIK_DefeatedOneBlooper, TRUE)
    Else
        Set(GF_TIK_DefeatedTwoBloopers, TRUE)
    EndIf
    Set(GF_TIK02_Defeated_Blooper, TRUE)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Exec(N(EVS_SetupMusic))
    Call(DisablePlayerInput, FALSE)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_Blooper) = {
    IfEq(GF_TIK02_Defeated_Blooper, FALSE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Blooper)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Blooper)))
        IfEq(GF_TIK_DefeatedOneBlooper, FALSE)
            Call(SetNpcScale, NPC_SELF, Float(0.75), Float(0.75), Float(0.75))
            Call(N(GetBlooperBattleID), 0)
        Else
            IfEq(GF_TIK_DefeatedTwoBloopers, FALSE)
                Call(SetNpcScale, NPC_SELF, Float(1.25), Float(1.25), Float(1.25))
                Call(N(GetBlooperBattleID), 1)
            Else
                Call(SetNpcScale, NPC_SELF, Float(2.0), Float(2.0), Float(2.0))
                Call(N(GetBlooperBattleID), 2)
            EndIf
        EndIf
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_Blooper) = {
    .id = NPC_Blooper,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Blooper),
    .settings = &N(NpcSettings_Blooper),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = BLOOPER_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Blooper), BTL_TIK2_FORMATION_00, BTL_TIK2_STAGE_00),
    {}
};
