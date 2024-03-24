#include "kkj_11.h"
#include "sprite/player.h"

#include "../common/Searchlights.inc.c"
#include "world/common/todo/GetPeachDisguise.inc.c"
#include "../common/PreventNextPeachDisguise.inc.c"
#include "../common/ApproachPlayer100Units.inc.c"

#include "world/common/enemy/Koopatrol_Stationary.inc.c"

AnimID N(ExtraAnims_Koopatrol)[] = {
    ANIM_WorldKoopatrol_Anim00,
    ANIM_WorldKoopatrol_Anim01,
    ANIM_WorldKoopatrol_Anim02,
    ANIM_WorldKoopatrol_Anim04,
    ANIM_WorldKoopatrol_Anim05,
    ANIM_WorldKoopatrol_Anim06,
    ANIM_WorldKoopatrol_Anim07,
    ANIM_WorldKoopatrol_Anim08,
    ANIM_WorldKoopatrol_Anim09,
    ANIM_WorldKoopatrol_Anim12,
    ANIM_WorldKoopatrol_Anim14,
    ANIM_WorldKoopatrol_Anim1B,
    ANIM_LIST_END
};

EvtScript N(EVS_CapturePeach) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(PreventNextPeachDisguise))
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(NpcFacePlayer, NPC_SELF, 5)
    Wait(20)
    Call(PlayerFaceNpc, NPC_SELF, FALSE)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_0174)
    Call(N(ApproachPlayer100Units), -1, LVar3, LVar0, LVar2)
    IfNe(LVar3, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim07)
        Call(SetNpcSpeed, NPC_SELF, Float(5.0))
        Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_0175)
    Call(SetPlayerAnimation, ANIM_Peach2_ForwardSad)
    Wait(20)
    Call(GotoMapSpecial, Ref("kkj_14"), kkj_14_ENTRY_B, TRANSITION_PEACH_CAPTURED)
    Wait(100)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Return
    End
};

EvtScript N(EVS_CheckForPeach_Koopatrol_01) = {
    Loop(0)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(GetPlayerPos, LVar3, LVar4, LVar5)
        IfEq(LVar1, LVar4)
            Call(N(GetPeachDisguise), LVar3)
            IfEq(LVar3, PEACH_DISGUISE_NONE)
                Call(IsPlayerWithin, LVar0, LVar2, 80, LVar0)
                IfEq(LVar0, 1)
                    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
                    Return
                EndIf
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_CheckForPeach_Koopatrol_02) = {
    Loop(0)
        Call(N(GetPeachDisguise), LVar0)
        IfEq(LVar0, PEACH_DISGUISE_NONE)
            Call(IsPlayerWithin, -275, -38, 30, LVar0)
            IfEq(LVar0, 1)
                Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
                Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
                Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
                Return
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_01) = {
    Exec(N(EVS_CheckForPeach_Koopatrol_01))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kkj_11_ENTRY_1)
        Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 1)
        Call(WaitForPlayerInputEnabled)
        Thread
            Call(DisablePlayerInput, TRUE)
            Call(SetPlayerSpeed, Float(2.0))
            Call(PlayerMoveTo, 70, -325, 0)
            Call(DisablePlayerInput, FALSE)
        EndThread
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        Call(SetNpcSpeed, NPC_SELF, Float(2.0))
        Call(NpcMoveTo, NPC_SELF, 0, -350, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        Call(InterpNpcYaw, NPC_SELF, 220, 5)
        Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 0)
    EndIf
    Loop(0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_04) = {
    Exec(N(EVS_CheckForPeach_Koopatrol_01))
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kkj_11_ENTRY_4)
        Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 1)
        Call(WaitForPlayerInputEnabled)
        Thread
            Call(DisablePlayerInput, TRUE)
            Call(SetPlayerSpeed, Float(2.0))
            Call(PlayerMoveTo, 70, -200, 0)
            Call(DisablePlayerInput, FALSE)
        EndThread
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        Call(SetNpcSpeed, NPC_SELF, Float(2.0))
        Call(NpcMoveTo, NPC_SELF, 0, -240, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        Call(InterpNpcYaw, NPC_SELF, 220, 5)
        Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 0)
    EndIf
    Loop(0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_02) = {
    Loop(0)
        Call(GetSelfVar, 1, LVar0)
        IfEq(LVar0, 0)
            Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim08)
            Call(SetSelfVar, 1, 1)
        Else
            Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim08)
            Call(SetSelfVar, 1, 0)
        EndIf
        Call(RandInt, 60, LVar0)
        Add(LVar0, 30)
        Wait(LVar0)
        Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
        Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
        Wait(10)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopatrol_01) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0135)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 1)
        Return
    EndIf
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim04)
    Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    IfGt(LVar0, 0)
        Add(LVar3, -50)
    Else
        Add(LVar3, 50)
    EndIf
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Call(NpcMoveTo, NPC_SELF, LVar3, LVar5, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    Call(InterpNpcYaw, NPC_SELF, 220, 5)
    Call(SetSelfVar, 0, 1)
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_12_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn, 1, 0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopatrol_04) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0135)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 1)
        Return
    EndIf
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
    Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    IfGt(LVar0, 0)
        Add(LVar3, -50)
    Else
        Add(LVar3, 50)
    EndIf
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Call(NpcMoveTo, NPC_SELF, LVar3, LVar5, 0)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    Call(InterpNpcYaw, NPC_SELF, 220, 5)
    Call(SetSelfVar, 0, 1)
    BindTrigger(Ref(N(EVS_ExitDoor_kkj_14_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn2, 1, 0)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopatrol_02) = {
    Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
    Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
    Wait(10)
    Call(N(GetPeachDisguise), LVar0)
    IfEq(LVar0, PEACH_DISGUISE_NONE)
        Call(NpcFacePlayer, NPC_SELF, 0)
        Wait(5)
        Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
        Return
    EndIf
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0131)
        Call(SetSelfVar, 0, 1)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0132)
        Call(SetSelfVar, 0, 0)
    EndIf
    Wait(10)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopatrol_03) = {
    Call(EnableNpcAI, NPC_Koopatrol_02, FALSE)
    Call(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
    Call(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
    Wait(10)
    Call(N(GetPeachDisguise), LVar0)
    IfEq(LVar0, PEACH_DISGUISE_NONE)
        Call(NpcFacePlayer, NPC_SELF, 0)
        Wait(5)
        Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
        Return
    EndIf
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0133)
        Call(SetSelfVar, 0, 1)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0134)
        Call(SetSelfVar, 0, 0)
    EndIf
    Wait(10)
    Call(EnableNpcAI, NPC_Koopatrol_02, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kkj_11_ENTRY_1)
        Call(SetNpcPos, NPC_SELF, -70, 100, -350)
        Call(SetNpcYaw, NPC_SELF, 90)
    Else
        Call(SetNpcPos, NPC_SELF, 0, 100, -350)
        Call(SetNpcYaw, NPC_SELF, 200)
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_01)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopatrol_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    Call(SetNpcPos, NPC_SELF, -295, 0, -30)
    Call(NpcFaceNpc, NPC_SELF, NPC_Koopatrol_03, 0)
    Exec(N(EVS_CheckForPeach_Koopatrol_02))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_02)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopatrol_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_03) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    Call(SetNpcPos, NPC_SELF, -255, 0, -55)
    Call(NpcFaceNpc, NPC_SELF, NPC_Koopatrol_02, 0)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopatrol_03)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_04) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kkj_11_ENTRY_4)
        Call(SetNpcPos, NPC_SELF, -40, 0, -220)
        Call(SetNpcYaw, NPC_SELF, 90)
    Else
        Call(SetNpcPos, NPC_SELF, 0, 0, -240)
        Call(SetNpcYaw, NPC_SELF, 220)
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_04)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopatrol_04)))
    Return
    End
};

NpcData N(NpcData_Minions_Later)[] = {
    {
        .id = NPC_Koopatrol_01,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Koopatrol_01),
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Koopatrol_02,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Koopatrol_02),
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Koopatrol_03,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Koopatrol_03),
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Koopatrol_04,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Koopatrol_04),
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
};

NpcGroupList N(LaterNPCs) = {
    NPC_GROUP(N(NpcData_Minions_Later)),
    {}
};
