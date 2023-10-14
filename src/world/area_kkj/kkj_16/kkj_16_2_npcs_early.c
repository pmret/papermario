#include "kkj_16.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Early

#include "world/common/enemy/HammerBros.inc.c"
#include "world/common/enemy/Koopatrol_Stationary.inc.c"

#include "../common/Searchlights.inc.c"
#include "../common/ApproachPlayer50Units.inc.c"

EvtScript N(EVS_CapturePeach) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_WAIT(20)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_0174)
    EVT_CALL(N(ApproachPlayer50Units), -1, LVar3, LVar0, LVar2)
    EVT_IF_NE(LVar3, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim06)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_0175)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardSad)
    EVT_WAIT(20)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kkj_14"), kkj_14_ENTRY_B, TRANSITION_PEACH_CAPTURED)
    EVT_WAIT(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_02) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(N(UnkPhysicsFunc), LVar0, 85, 60, 38)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_CapturePeach)))
                EVT_RETURN
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(1.7))
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        EVT_WAIT(20)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 15)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        EVT_CALL(NpcMoveTo, NPC_SELF, 280, 50, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        EVT_WAIT(20)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 15)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        EVT_CALL(NpcMoveTo, NPC_SELF, 80, 50, 0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_03) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(N(UnkPhysicsFunc), LVar0, 85, 60, 38)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_CapturePeach)))
                EVT_RETURN
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -248, -80, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -84, -80, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -84, -15, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -88, -15, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -88, 50, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -252, 50, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -252, -15, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -248, -15, 0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_04) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(N(UnkPhysicsFunc), LVar0, 85, 60, 38)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_CapturePeach)))
                EVT_RETURN
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(1.7))
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 15)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        EVT_CALL(NpcMoveTo, NPC_SELF, -600, 50, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 15)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        EVT_CALL(NpcMoveTo, NPC_SELF, -420, 50, 0)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HammerBros) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_SELF, -700, 0, 50)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH2_BEGAN_PEACH_MISSION)
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_SELF, -740, 0, 50)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 180, 0, 50)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_03) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, -250, 0, -15)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_04) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -510, 0, 50)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_04)))
    EVT_RETURN
    EVT_END
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
