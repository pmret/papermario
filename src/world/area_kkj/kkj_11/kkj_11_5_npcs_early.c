#include "kkj_11.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Early

#include "../common/Searchlights.inc.c"
#include "../common/ApproachPlayer100Units.inc.c"

#include "world/common/enemy/Koopatrol_Stationary.inc.c"

EvtScript N(EVS_NpcAI_Koopatrol_01) = {
    Call(DisablePlayerInput, TRUE)
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
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
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_01) = {
    Thread
        Set(LVar1, 0)
        Loop(0)
            Call(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, 127, 0)
            IfNe(LVar0, 0)
                IfEq(LVar1, 0)
                    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Koopatrol_01)))
                    Set(LVar1, 1)
                EndIf
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, -130, -130, 0)
        Call(N(GetAngleBetweenPoints), LVar0, -130, -130, -180, -30)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, -180, -30, 0)
        Call(N(GetAngleBetweenPoints), LVar0, -180, -30, 180, -30)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 180, -30, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 180, -30, 130, -130)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 130, -130, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 130, -130, -130, -130)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_02) = {
    Thread
        Set(LVar1, 0)
        Loop(0)
            Call(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, 128, 1)
            IfNe(LVar0, 0)
                IfEq(LVar1, 0)
                    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Koopatrol_01)))
                    Set(LVar1, 1)
                EndIf
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, -130, 180, 0)
        Call(N(GetAngleBetweenPoints), LVar0, -130, 180, -130, 230)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, -130, 230, 0)
        Call(N(GetAngleBetweenPoints), LVar0, -130, 230, -40, 230)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, -40, 230, 0)
        Call(N(GetAngleBetweenPoints), LVar0, -40, 230, -40, 80)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, -40, 80, 0)
        Call(N(GetAngleBetweenPoints), LVar0, -40, 80, -250, 80)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, -250, 80, 0)
        Call(N(GetAngleBetweenPoints), LVar0, -250, 80, -250, 180)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, -250, 180, 0)
        Call(N(GetAngleBetweenPoints), LVar0, -250, 180, -130, 180)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_03) = {
    Thread
        Set(LVar1, 0)
        Loop(0)
            Call(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, 129, 2)
            IfNe(LVar0, 0)
                IfEq(LVar1, 0)
                    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Koopatrol_01)))
                    Set(LVar1, 1)
                EndIf
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, 130, 180, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 130, 180, 250, 180)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 250, 180, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 250, 180, 250, 80)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 250, 80, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 250, 80, 40, 80)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 40, 80, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 40, 80, 40, 230)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 40, 230, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 40, 230, 130, 230)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
        Call(NpcMoveTo, NPC_SELF, 130, 230, 0)
        Call(N(GetAngleBetweenPoints), LVar0, 130, 230, 130, 180)
        Call(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_04) = {
    Loop(0)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(AwaitPlayerApproach, LVar0, LVar2, 50)
        Call(GetPlayerPos, LVar0, LVar3, LVar2)
        IfEq(LVar1, LVar3)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(DisablePlayerInput, TRUE)
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(NpcFacePlayer, NPC_SELF, 5)
    Wait(20)
    Call(PlayerFaceNpc, NPC_SELF, FALSE)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_0174)
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

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    Call(SetNpcPos, NPC_SELF, 130, 0, -130)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    Call(SetNpcPos, NPC_SELF, -250, 0, 180)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_03) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    Call(SetNpcPos, NPC_SELF, 130, 0, 230)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_03)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_04) = {
    Call(SetNpcPos, NPC_SELF, 0, 100, -350)
    Call(SetNpcYaw, NPC_SELF, 220)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_04)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_05) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kkj_11_ENTRY_4)
        Call(SetNpcPos, NPC_SELF, -40, 0, -220)
        Call(SetNpcYaw, NPC_SELF, 90)
    Else
        Call(SetNpcPos, NPC_SELF, 0, 0, -240)
        Call(SetNpcYaw, NPC_SELF, 220)
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_04)))
    Return
    End
};

AnimID N(ExtraAnims_Koopatrol)[] = {
    ANIM_WorldKoopatrol_Anim01,
    ANIM_WorldKoopatrol_Anim04,
    ANIM_WorldKoopatrol_Anim06,
    ANIM_WorldKoopatrol_Anim08,
    ANIM_WorldKoopatrol_Anim02,
    ANIM_WorldKoopatrol_Anim05,
    ANIM_WorldKoopatrol_Anim07,
    ANIM_WorldKoopatrol_Anim09,
    ANIM_LIST_END
};

NpcData N(NpcData_Minions)[] = {
    {
        .id = NPC_Koopatrol_01,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Koopatrol_01),
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Koopatrol_05,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Koopatrol_05),
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
};

#define NAME_SUFFIX

NpcGroupList N(EarlyNPCs) = {
    NPC_GROUP(N(NpcData_Minions_Early)),
    {}
};
