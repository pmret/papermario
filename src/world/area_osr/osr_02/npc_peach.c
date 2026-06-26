#include "osr_02.h"

#include "world/common/todo/GetPeachDisguise.inc.c"

#include "world/common/enemy/Clubba.inc.c"

AnimID N(ExtraAnims_Clubba)[] = {
    ANIM_WorldClubba_Still,
    ANIM_WorldClubba_Idle,
    ANIM_WorldClubba_Walk,
    ANIM_WorldClubba_Run,
    ANIM_WorldClubba_Talk,
    ANIM_WorldClubba_WakeUp,
    ANIM_WorldClubba_Sleep,
    ANIM_WorldClubba_IdleMini,
    ANIM_WorldClubba_GotItem,
    ANIM_LIST_END
};

EvtScript N(EVS_NpcInteract_Clubba) = {
    Call(DisablePlayerInput, true)
    Call(CancelMessage)
    Wait(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_WakeUp)
    Wait(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Idle)
    Call(N(GetPeachDisguise), LVar0)
    Switch(LVar0)
        CaseEq(0)
            Set(LVar1, MSG_Peach_014A)
        CaseEq(3)
            Set(LVar1, MSG_Peach_014B)
        CaseDefault
            Set(LVar1, MSG_Peach_014C)
    EndSwitch
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Talk, ANIM_WorldClubba_Idle, 16, LVar1)
    Wait(10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Sleep)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Clubba) = {
    Call(SetSelfVar, 0, 0)
    Call(GetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
    Loop(0)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            Call(AwaitPlayerApproach, LVar1, LVar3, 85)
            Thread
                Call(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Sleep, ANIM_WorldClubba_Sleep, 5, MSG_Peach_0149)
            EndThread
            Call(SetSelfVar, 0, 1)
        Else
            Call(AwaitPlayerLeave, LVar1, LVar3, 90)
            Call(CancelMessage)
            Call(SetSelfVar, 0, 0)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Clubba) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldClubba_Sleep)
    Call(SetNpcPos, NPC_SELF, -40, 20, -170)
    Call(SetNpcYaw, NPC_SELF, 200)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Clubba)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Clubba)))
    Return
    End
};

NpcData N(NpcData_Clubba) = {
    .id = NPC_Clubba,
    .pos = { -70.0f, 0.0f, -100.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Clubba),
    .settings = &N(NpcSettings_Clubba),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = CLUBBA_ANIMS,
    .extraAnimations = N(ExtraAnims_Clubba),
};

NpcGroupList N(PeachNPCs) = {
    NPC_GROUP(N(NpcData_Clubba)),
    {}
};
