#include "kkj_10.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Later
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

#include "../common/Searchlights.inc.c"
#include "world/common/todo/GetPeachDisguise.inc.c"
#include "../common/PreventNextPeachDisguise.inc.c"
#include "../common/ApproachPlayer100Units.inc.c"

EvtScript N(EVS_CapturePeach) = {
    Call(DisablePlayerInput, TRUE)
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(N(PreventNextPeachDisguise))
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(NpcFacePlayer, NPC_SELF, 5)
    Wait(20)
    Call(PlayerFaceNpc, NPC_SELF, FALSE)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim02)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0174)
    Call(N(ApproachPlayer100Units), -1, LVar3, LVar0, LVar2)
    IfNe(LVar3, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim07)
        Call(SetNpcSpeed, NPC_SELF, Float(5.0))
        Call(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim02)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0175)
    Call(SetPlayerAnimation, ANIM_Peach2_ForwardSad)
    Wait(20)
    Call(GotoMapSpecial, Ref("kkj_14"), kkj_14_ENTRY_B, TRANSITION_PEACH_CAPTURED)
    Wait(100)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_01) = {
    Thread
        Set(LVar2, 0)
        Loop(0)
            Call(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, 130, 0)
            IfEq(LVar2, 0)
                Call(N(GetPeachDisguise), LVar1)
                IfEq(LVar1, PEACH_DISGUISE_NONE)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, TRUE)
                    IfNe(LVar0, 0)
                        Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
                        Set(LVar2, 1)
                    EndIf
                Else
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, FALSE)
                EndIf
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, -240, 240, 0)
        Call(N(GetAngleBetweenPoints), LVar0, -240, 240, 0, 240)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 0, 240, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 0, 240, -240, 240)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, -240, 240, 0)
        Call(N(GetAngleBetweenPoints), LVar0, -240, 240, -240, -50)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, -240, -50, 0)
        Call(N(GetAngleBetweenPoints), LVar0, -240, -50, -240, 240)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_02) = {
    Thread
        Set(LVar2, 0)
        Loop(0)
            Call(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, 131, 1)
            IfEq(LVar2, 0)
                Call(N(GetPeachDisguise), LVar1)
                IfEq(LVar1, PEACH_DISGUISE_NONE)
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, FALSE)
                    IfNe(LVar0, 0)
                        Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
                        Set(LVar2, 1)
                    EndIf
                Else
                    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, FALSE)
                EndIf
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, 240, 240, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 240, 240, 240, -50)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 240, -50, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 240, -50, 240, 240)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 240, 240, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 240, 240, 0, 240)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 0, 240, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 0, 240, 240, 240)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EndLoop
    Return
    End
};


EvtScript N(EVS_NpcInteract_Koopatrol_01) = {
    Call(DisablePlayerInput, TRUE)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 5, MSG_Peach_013C)
        Call(SetSelfVar, 0, 1)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 5, MSG_Peach_013D)
        Call(SetSelfVar, 0, 0)
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Koopatrol_02) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(GetPeachDisguise), LVar0)
    IfEq(LVar0, PEACH_DISGUISE_CLUBBA)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 5, MSG_Peach_0140)
    Else
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 5, MSG_Peach_013E)
            Call(SetSelfVar, 0, 1)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 5, MSG_Peach_013F)
            Call(SetSelfVar, 0, 0)
        EndIf
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    Call(SetNpcPos, NPC_SELF, -240, 0, -50)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_01)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopatrol_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    Call(SetNpcPos, NPC_SELF, 0, 0, 240)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_02)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopatrol_02)))
    Return
    End
};

NpcData N(NpcData_Koopatrol)[] = {
    {
        .id = NPC_Koopatrol_01,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Koopatrol_01),
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
};

#define NAME_SUFFIX

NpcGroupList N(LaterNPCs) = {
    NPC_GROUP(N(NpcData_Koopatrol_Later)),
    {}
};
