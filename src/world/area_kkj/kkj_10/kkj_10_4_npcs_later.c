#include "kkj_10.h"

#define NAME_SUFFIX _Later
#include "world/common/enemy/Koopatrol_Stationary.inc.c"

s32 N(ExtraAnims_Koopatrol)[] = {
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
#include "../common/SetPeachFlag8.inc.c"
#include "../common/ApproachPlayer100Units.inc.c"

EvtScript N(EVS_CapturePeach) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(N(SetPeachFlag8))
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_262, 0)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, TRUE, 0, 0, 0, 0)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 5)
    EVT_WAIT(20)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach_C0005)
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
    EVT_CALL(SetPlayerAnimation, ANIM_Peach_C0017)
    EVT_WAIT(20)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kkj_14"), kkj_14_ENTRY_B, TRANSITION_13)
    EVT_WAIT(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_01) = {
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_LOOP(0)
            EVT_CALL(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, 130, 0)
            EVT_IF_EQ(LVar2, 0)
                EVT_CALL(N(GetPeachDisguise), LVar1)
                EVT_IF_EQ(LVar1, PEACH_DISGUISE_NONE)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_8000000, 1)
                    EVT_IF_NE(LVar0, 0)
                        EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_CapturePeach)))
                        EVT_SET(LVar2, 1)
                    EVT_END_IF
                EVT_ELSE
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_8000000, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -240, 240, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, -240, 240, 0, 240)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 0, 240, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 0, 240, -240, 240)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, -240, 240, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, -240, 240, -240, -50)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, -240, -50, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, -240, -50, -240, 240)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_02) = {
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_LOOP(0)
            EVT_CALL(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, 131, 1)
            EVT_IF_EQ(LVar2, 0)
                EVT_CALL(N(GetPeachDisguise), LVar1)
                EVT_IF_EQ(LVar1, PEACH_DISGUISE_NONE)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_8000000, 0)
                    EVT_IF_NE(LVar0, 0)
                        EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_CapturePeach)))
                        EVT_SET(LVar2, 1)
                    EVT_END_IF
                EVT_ELSE
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_8000000, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_LOOP(0)
        EVT_CALL(NpcMoveTo, NPC_SELF, 240, 240, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 240, 240, 240, -50)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 240, -50, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 240, -50, 240, 240)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 240, 240, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 240, 240, 0, 240)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 0, 240, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 0, 240, 240, 240)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};


EvtScript N(EVS_NpcInteract_Koopatrol_01) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 5, MSG_Peach_013C)
        EVT_CALL(SetSelfVar, 0, 1)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 5, MSG_Peach_013D)
        EVT_CALL(SetSelfVar, 0, 0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopatrol_02) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(GetPeachDisguise), LVar0)
    EVT_IF_EQ(LVar0, PEACH_DISGUISE_CLUBBA)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 5, MSG_Peach_0140)
    EVT_ELSE
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 5, MSG_Peach_013E)
            EVT_CALL(SetSelfVar, 0, 1)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 5, MSG_Peach_013F)
            EVT_CALL(SetSelfVar, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    EVT_CALL(SetNpcPos, NPC_SELF, -240, 0, -50)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_01)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopatrol_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, 240)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_02)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopatrol_02)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Koopatrol)[] = {
    {
        .id = NPC_Koopatrol_01,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Koopatrol_01),
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Koopatrol_02,
        .settings = &N(NpcSettings_Koopatrol_Stationary),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(EVS_NpcInit_Koopatrol_02),
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
