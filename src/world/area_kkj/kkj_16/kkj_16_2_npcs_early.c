#include "kkj_16.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Early

#include "world/common/enemy/HammerBros.inc.c"
#include "world/common/enemy/Koopatrol_Stationary.inc.c"

#include "../common/Searchlights.inc.c"
#include "../common/ApproachPlayer50Units.inc.c"

EvtScript N(EVS_CapturePeach) = {
    Call(DisablePlayerInput, TRUE)
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

EvtScript N(EVS_NpcIdle_Koopatrol_02) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
    Thread
        Loop(0)
            Call(N(UnkPhysicsFunc), LVar0, 85, 60, 38)
            IfEq(LVar0, 1)
                Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
                Return
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcSpeed, NPC_SELF, Float(1.7))
    Loop(0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        Wait(20)
        Call(InterpNpcYaw, NPC_SELF, 90, 15)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        Call(NpcMoveTo, NPC_SELF, 280, 50, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        Wait(20)
        Call(InterpNpcYaw, NPC_SELF, 270, 15)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        Call(NpcMoveTo, NPC_SELF, 80, 50, 0)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_03) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
    Thread
        Loop(0)
            Call(N(UnkPhysicsFunc), LVar0, 85, 60, 38)
            IfEq(LVar0, 1)
                Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
                Return
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, -248, -80, 0)
        Call(NpcMoveTo, NPC_SELF, -84, -80, 0)
        Call(NpcMoveTo, NPC_SELF, -84, -15, 0)
        Call(NpcMoveTo, NPC_SELF, -88, -15, 0)
        Call(NpcMoveTo, NPC_SELF, -88, 50, 0)
        Call(NpcMoveTo, NPC_SELF, -252, 50, 0)
        Call(NpcMoveTo, NPC_SELF, -252, -15, 0)
        Call(NpcMoveTo, NPC_SELF, -248, -15, 0)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Koopatrol_04) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
    Thread
        Loop(0)
            Call(N(UnkPhysicsFunc), LVar0, 85, 60, 38)
            IfEq(LVar0, 1)
                Call(BindNpcAI, NPC_SELF, Ref(N(EVS_CapturePeach)))
                Return
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Call(SetNpcSpeed, NPC_SELF, Float(1.7))
    Loop(0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        Wait(30)
        Call(InterpNpcYaw, NPC_SELF, 270, 15)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        Call(NpcMoveTo, NPC_SELF, -600, 50, 0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        Wait(30)
        Call(InterpNpcYaw, NPC_SELF, 90, 15)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        Call(NpcMoveTo, NPC_SELF, -420, 50, 0)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_HammerBros) = {
    IfNe(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(SetNpcPos, NPC_SELF, -700, 0, 50)
    Call(InterpNpcYaw, NPC_SELF, 270, 1)
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    IfNe(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(SetNpcPos, NPC_SELF, -740, 0, 50)
    Call(InterpNpcYaw, NPC_SELF, 90, 1)
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    Call(SetNpcPos, NPC_SELF, 180, 0, 50)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_03) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcPos, NPC_SELF, -250, 0, -15)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_03)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol_04) = {
    Call(SetNpcPos, NPC_SELF, -510, 0, 50)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Koopatrol_04)))
    Return
    End
};

AnimID N(ExtraAnims_HammerBros)[] = {
    ANIM_HammerBros_Anim00,
    ANIM_HammerBros_Anim02,
    ANIM_HammerBros_Anim04,
    ANIM_HammerBros_Anim08,
    ANIM_HammerBros_Anim0A,
    ANIM_HammerBros_Anim13,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Koopatrol)[] = {
    ANIM_WorldKoopatrol_Anim00,
    ANIM_WorldKoopatrol_Anim01,
    ANIM_WorldKoopatrol_Anim04,
    ANIM_WorldKoopatrol_Anim06,
    ANIM_WorldKoopatrol_Anim08,
    ANIM_WorldKoopatrol_Anim12,
    ANIM_WorldKoopatrol_Anim14,
    ANIM_LIST_END
};

NpcData N(NpcData_Minions)[] = {
    {
        .id = NPC_HammerBros,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_HammerBros),
        .settings = &N(NpcSettings_HammerBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = HAMMER_BROS_ANIMS,
        .extraAnimations = N(ExtraAnims_HammerBros),
    },
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
};

#define NAME_SUFFIX

NpcGroupList N(EarlyNPCs) = {
    NPC_GROUP(N(NpcData_Minions_Early)),
    {}
};
