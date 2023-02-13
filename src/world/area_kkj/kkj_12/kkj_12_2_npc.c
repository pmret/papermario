#include "kkj_12.h"

#include "../common/Searchlights.inc.c"

#include "world/common/todo/GetPeachDisguise.inc.c"
#include "../common/SetPeachFlag8.inc.c"
#include "../common/ApproachPlayer100Units.inc.c"

API_CALLABLE(N(DisableLightSource1)) {
    D_80151328->sources[1].flags = LIGHT_SOURCE_DISABLED;
    return ApiStatus_DONE2;
}

#include "world/common/enemy/Clubba.h"
#include "world/common/enemy/Koopatrol_Stationary.inc.c"
#include "world/common/npc/Dummy.inc.c"

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
    -1
};

s32 N(ExtraAnims_Clubba)[] = {
    ANIM_WorldClubba_Anim00,
    ANIM_WorldClubba_Anim02,
    ANIM_WorldClubba_Anim03,
    ANIM_WorldClubba_Anim04,
    ANIM_WorldClubba_Anim05,
    ANIM_WorldClubba_Anim08,
    ANIM_WorldClubba_Anim07,
    ANIM_WorldClubba_Anim13,
    ANIM_WorldClubba_Anim14,
    -1
};

EvtScript N(EVS_NpcInteract_Koopatrol_01) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(GetPeachDisguise), LVar0)
    EVT_IF_EQ(LVar0, PEACH_DISGUISE_CLUBBA)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0143)
    EVT_ELSE
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0141)
            EVT_CALL(SetSelfVar, 0, 1)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0142)
            EVT_CALL(SetSelfVar, 0, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Koopatrol_02) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(GetPeachDisguise), LVar0)
    EVT_IF_EQ(LVar0, PEACH_DISGUISE_CLUBBA)
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0), 0, EVT_FLOAT(350.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0147)
        EVT_THREAD
            EVT_LOOP(0)
                EVT_CALL(PlayerFaceNpc, NPC_Koopatrol_02, FALSE)
                EVT_WAIT(1)
                EVT_IF_EQ(GF_KKJ12_TrickedGuard, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, 1050, 0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0148)
        EVT_CALL(NpcMoveTo, NPC_SELF, 900, 0, 0)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -500, 0)
        EVT_SET(GF_KKJ12_TrickedGuard, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_13_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit2, 1, 0)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_KKJ11_TrickedGuard, FALSE)
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0), 0, EVT_FLOAT(350.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0144)
        EVT_WAIT(10)
        EVT_SET(LVar0, ITEM_PEACH_KEY1)
        EVT_CALL(ShowGotItem, LVar0, TRUE, 0)
        EVT_CALL(AddKeyItem, LVar0)
        EVT_SET(GF_KKJ11_TrickedGuard, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0145)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 16, MSG_Peach_0146)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CapturePeach) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(SetPeachFlag8))
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_262, 0)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, TRUE, 0, 0, 0, 0)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 5)
    EVT_WAIT(20)
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach_C0005)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim02)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldKoopatrol_Anim09, ANIM_WorldKoopatrol_Anim02, 0, MSG_Peach_0174)
    EVT_CALL(N(ApproachPlayer100Units), NPC_SELF, LVar3, LVar0, LVar2)
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
            EVT_CALL(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, MODEL_o694, 0)
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
        EVT_CALL(NpcMoveTo, NPC_SELF, 900, 0, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 900, 0, 800, 0)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
        EVT_CALL(NpcMoveTo, NPC_SELF, 800, 0, 0)
        EVT_CALL(N(GetAngleBetweenPoints), LVar0, 800, 0, 900, 0)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Koopatrol_02) = {
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_LOOP(0)
            EVT_CALL(N(UpdateSearchlight), LVar0, 100, 90, 0, 40, MODEL_o695, 1)
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
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_01) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim05)
    EVT_CALL(SetNpcPos, NPC_SELF, 800, 110, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_01)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopatrol_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol_02) = {
    EVT_IF_NE(GF_KKJ12_TrickedGuard, FALSE)
        EVT_CALL(EnableModel, MODEL_o695, FALSE)
        EVT_CALL(N(DisableLightSource1))
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKoopatrol_Anim02)
    EVT_CALL(SetNpcPos, NPC_SELF, 1170, 110, 0)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Koopatrol_02)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Koopatrol_02)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Koopatrol_01)[] = {
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .init = &N(EVS_NpcInit_Koopatrol_02),
        .drops = NO_DROPS,
        .animations = KOOPATROL_ANIMS,
        .extraAnimations = N(ExtraAnims_Koopatrol),
    },
    {
        .id = NPC_Clubba,
        .settings = &N(NpcSettings_Dummy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = NO_DROPS,
        .animations = CLUBBA_ANIMS,
        .extraAnimations = N(ExtraAnims_Clubba),
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Koopatrol_01)),
    {}
};
