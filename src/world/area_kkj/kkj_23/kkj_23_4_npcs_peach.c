#include "kkj_23.h"
#include "sprite/player.h"

#include "../common/Searchlights.inc.c"

#include "world/common/todo/GetPeachDisguise.inc.c"
#include "../common/PreventNextPeachDisguise.inc.c"
#include "../common/ApproachPlayer50Units.inc.c"

#include "world/common/enemy/Kammy.inc.c"
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

EvtScript N(EVS_NpcInteract_Koopatrol_01) = {
    Call(DisablePlayerInput, TRUE)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_014D)
        Call(SetSelfVar, 0, 1)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_014E)
        Call(SetSelfVar, 0, 0)
    EndIf
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_CapturePeach) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(PreventNextPeachDisguise))
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Wait(20)
    Call(PlayerFaceNpc, NPC_SELF, FALSE)
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    Call(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_0174)
    Call(N(ApproachPlayer50Units), -1, LVar3, LVar0, LVar2)
    IfNe(LVar3, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim06)
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
    Return
    End
};

EvtScript N(EVS_Koopatrol_WatchForPeach) = {
    Loop(0)
        Call(N(GetPeachDisguise), LVar1)
        IfEq(LVar1, PEACH_DISGUISE_NONE)
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 1)
            Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
            Return
        Else
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 0)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_01) = {
    ExecGetTID(N(EVS_Koopatrol_WatchForPeach), LVarA)
    Call(SetSelfVar, 1, 1)
    Loop(0)
        Wait(1)
        Call(GetSelfVar, 1, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVarA)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 1)
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    Call(SetNpcPos, NPC_SELF, 140, 0, -80)
    Call(SetNpcYaw, NPC_SELF, 90)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_01)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Koopatrol_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    Call(SetNpcPos, NPC_SELF, 40, 0, -80)
    Call(SetNpcYaw, NPC_SELF, 90)
    Return
    End
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim01,
    ANIM_WorldKammy_Anim02,
    ANIM_WorldKammy_Anim04,
    ANIM_WorldKammy_Anim05,
    ANIM_LIST_END
};

NpcData N(NpcData_Kammy)[] = {
    {
        .id = NPC_Kammy,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_Kammy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KAMMY_ANIMS,
        .extraAnimations = N(ExtraAnims_Kammy),
    },
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
};

NpcGroupList N(PeachNPCs) = {
    NPC_GROUP(N(NpcData_Kammy)),
    {}
};
