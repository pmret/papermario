#include "kkj_11.h"
#include "sprite/player.h"

#define NAME_SUFFIX _Early

#include "../common/Searchlights.inc.c"
#include "../common/ApproachPlayer100Units.inc.c"

#include "world/common/enemy/Koopatrol_Stationary.inc.c"

EvtScript N(EVS_NpcAI_Koopatrol_01) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 5)
    EVT_WAIT(20)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim02)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0174)
    EVT_CALL(N(ApproachPlayer100Units), -1, LVar3, LVar0, LVar2)
    EVT_IF_NE(LVar3, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim07)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim02)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0175)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardSad)
    EVT_WAIT(20)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kkj_14"), kkj_14_ENTRY_B, TRANSITION_PEACH_CAPTURED)
    EVT_WAIT(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_01) = {
    EVT_THREAD
        EVT_SET(LVar1, 0)
        EVT_LOOP(0)
            EVT_CALL(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, 127, 0)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Koopatrol_01)))
                    EVT_SET(LVar1, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -130, -130, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, -130, -130, -180, -30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, -180, -30, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, -180, -30, 180, -30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 180, -30, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 180, -30, 130, -130)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 130, -130, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 130, -130, -130, -130)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_02) = {
    EVT_THREAD
        EVT_SET(LVar1, 0)
        EVT_LOOP(0)
            EVT_CALL(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, 128, 1)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Koopatrol_01)))
                    EVT_SET(LVar1, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -130, 180, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, -130, 180, -130, 230)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, -130, 230, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, -130, 230, -40, 230)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, -40, 230, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, -40, 230, -40, 80)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, -40, 80, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, -40, 80, -250, 80)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, -250, 80, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, -250, 80, -250, 180)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, -250, 180, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, -250, 180, -130, 180)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_03) = {
    EVT_THREAD
        EVT_SET(LVar1, 0)
        EVT_LOOP(0)
            EVT_CALL(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, 129, 2)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_EQ(LVar1, 0)
                    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Koopatrol_01)))
                    EVT_SET(LVar1, 1)
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, 130, 180, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 130, 180, 250, 180)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 250, 180, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 250, 180, 250, 80)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 250, 80, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 250, 80, 40, 80)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 40, 80, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 40, 80, 40, 230)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 40, 230, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 40, 230, 130, 230)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 130, 230, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 130, 230, 130, 180)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_04) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(AwaitPlayerApproach, LVar0, LVar2, 50)
        EVT_CALL(GetPlayerPos, LVar0, LVar3, LVar2)
        EVT_IF_EQ(LVar1, LVar3)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 5)
    EVT_WAIT(20)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_0174)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_0175)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_ForwardSad)
    EVT_WAIT(20)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kkj_14"), kkj_14_ENTRY_B, TRANSITION_PEACH_CAPTURED)
    EVT_WAIT(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    EVT_CALL(SetNpcPos, NPC_SELF, 130, 0, -130)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    EVT_CALL(SetNpcPos, NPC_SELF, -250, 0, 180)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_03) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    EVT_CALL(SetNpcPos, NPC_SELF, 130, 0, 230)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_04) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 0, 100, -350)
    EVT_CALL(SetNpcYaw, NPC_SELF, 220)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_05) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kkj_11_ENTRY_4)
        EVT_CALL(SetNpcPos, NPC_SELF, -40, 0, -220)
        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, -240)
        EVT_CALL(SetNpcYaw, NPC_SELF, 220)
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_04)))
    EVT_RETURN
    EVT_END
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
