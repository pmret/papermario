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
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(PreventNextPeachDisguise))
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 5)
    EVT_WAIT(20)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach2_Gasp)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 0, MSG_Peach_0174)
    EVT_CALL(N(ApproachPlayer100Units), -1, LVar3, LVar0, LVar2)
    EVT_IF_NE(LVar3, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim07)
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
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CheckForPeach_Koopatrol_01) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
        EVT_IF_EQ(LVar1, LVar4)
            EVT_CALL(N(GetPeachDisguise), LVar3)
            EVT_IF_EQ(LVar3, PEACH_DISGUISE_NONE)
                EVT_CALL(IsPlayerWithin, LVar0, LVar2, 80, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_CapturePeach)))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CheckForPeach_Koopatrol_02) = {
    EVT_LOOP(0)
        EVT_CALL(N(GetPeachDisguise), LVar0)
        EVT_IF_EQ(LVar0, PEACH_DISGUISE_NONE)
            EVT_CALL(IsPlayerWithin, -275, -38, 30, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
                EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
                EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_CapturePeach)))
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_01) = {
    EVT_EXEC(N(EVS_CheckForPeach_Koopatrol_01))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kkj_11_ENTRY_1)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 1)
        EVT_CALL(WaitForPlayerInputEnabled)
        EVT_THREAD
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
            EVT_CALL(PlayerMoveTo, 70, -325, 0)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, 0, -350, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 220, 5)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 0)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_04) = {
    EVT_EXEC(N(EVS_CheckForPeach_Koopatrol_01))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kkj_11_ENTRY_4)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 1)
        EVT_CALL(WaitForPlayerInputEnabled)
        EVT_THREAD
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
            EVT_CALL(PlayerMoveTo, 70, -200, 0)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, 0, -240, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 220, 5)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 0)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_02) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim08)
            EVT_CALL(SetSelfVar, 1, 1)
        EVT_ELSE
            EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim08)
            EVT_CALL(SetSelfVar, 1, 0)
        EVT_END_IF
        EVT_CALL(RandInt, 60, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_WAIT(LVar0)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopatrol_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0135)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_01, ANIM_WorldKoopatrol_Anim04)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, 0)
        EVT_ADD(LVar3, -50)
    EVT_ELSE
        EVT_ADD(LVar3, 50)
    EVT_END_IF
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar3, LVar5, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 220, 5)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_12_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopatrol_04) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0135)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim04)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, 0)
        EVT_ADD(LVar3, -50)
    EVT_ELSE
        EVT_ADD(LVar3, 50)
    EVT_END_IF
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar3, LVar5, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 220, 5)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kkj_14_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttn2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopatrol_02) = {
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
    EVT_WAIT(10)
    EVT_CALL(N(GetPeachDisguise), LVar0)
    EVT_IF_EQ(LVar0, PEACH_DISGUISE_NONE)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_WAIT(5)
        EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_CapturePeach)))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0131)
        EVT_CALL(SetSelfVar, 0, 1)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0132)
        EVT_CALL(SetSelfVar, 0, 0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopatrol_03) = {
    EVT_CALL(EnableNpcAI, NPC_Koopatrol_02, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(SetNpcAnimation, NPC_Koopatrol_03, ANIM_WorldKoopatrol_Anim01)
    EVT_WAIT(10)
    EVT_CALL(N(GetPeachDisguise), LVar0)
    EVT_IF_EQ(LVar0, PEACH_DISGUISE_NONE)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_WAIT(5)
        EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_CapturePeach)))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0133)
        EVT_CALL(SetSelfVar, 0, 1)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim08, ANIM_WorldKoopatrol_Anim01, 16, MSG_Peach_0134)
        EVT_CALL(SetSelfVar, 0, 0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(EnableNpcAI, NPC_Koopatrol_02, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kkj_11_ENTRY_1)
        EVT_CALL(SetNpcPos, NPC_SELF, -70, 100, -350)
        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, 100, -350)
        EVT_CALL(SetNpcYaw, NPC_SELF, 200)
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_01)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopatrol_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(SetNpcPos, NPC_SELF, -295, 0, -30)
    EVT_CALL(NpcFaceNpc, NPC_SELF, NPC_Koopatrol_03, 0)
    EVT_EXEC(N(EVS_CheckForPeach_Koopatrol_02))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_02)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopatrol_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_03) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim01)
    EVT_CALL(SetNpcPos, NPC_SELF, -255, 0, -55)
    EVT_CALL(NpcFaceNpc, NPC_SELF, NPC_Koopatrol_02, 0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopatrol_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_04) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kkj_11_ENTRY_4)
        EVT_CALL(SetNpcPos, NPC_SELF, -40, 0, -220)
        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, -240)
        EVT_CALL(SetNpcYaw, NPC_SELF, 220)
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_04)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopatrol_04)))
    EVT_RETURN
    EVT_END
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
