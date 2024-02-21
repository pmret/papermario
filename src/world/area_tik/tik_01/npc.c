#include "tik_01.h"

#include "world/common/enemy/Blooper.inc.c"

EvtScript N(EVS_NpcIdle_Blooper) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 200)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Exec(N(EVS_PlayBlooperSong))
    Call(ShowMessageAtScreenPos, MSG_MGM_0000, 160, 40)
    Wait(20)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Blooper_Anim01)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -75)
    Call(SetNpcPos, NPC_SELF, LVar0, 150, 0)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_BLOOPER_MOVE, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcFlyTo, NPC_SELF, LVar0, 0, 0, 10, 0, EASING_QUADRATIC_IN)
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
        Call(SetNpcAnimation, NPC_SELF, ANIM_Blooper_Anim04)
        Call(MakeLerp, 0, 6 * 360, 40, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_BLOOPER_FALL, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_LARGE_ACTOR_JUMP, SOUND_SPACE_DEFAULT)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(NpcFlyTo, NPC_SELF, LVar0, 150, 0, 15, 0, EASING_QUADRATIC_IN)
    Wait(5)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Wait(15)
    ExecWait(N(EVS_SpawnSwitch))
    IfEq(GF_TIK_DefeatedOneBlooper, FALSE)
        Set(GF_TIK_DefeatedOneBlooper, TRUE)
    Else
        Set(GF_TIK_DefeatedTwoBloopers, TRUE)
    EndIf
    Set(GF_TIK01_Defeated_Blooper, TRUE)
    Exec(N(EVS_SetupMusic))
    Call(DisablePlayerInput, FALSE)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_Blooper) = {
    IfEq(GF_TIK01_Defeated_Blooper, FALSE)
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
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = BLOOPER_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Blooper), BTL_TIK2_FORMATION_00, BTL_TIK2_STAGE_00),
    {}
};
