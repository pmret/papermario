#include "flo_10.h"
#include "sprite/player.h"

#include "world/common/npc/Lily.inc.c"

EvtScript N(EVS_Scene_SunReturns) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcPos, NPC_Lily, 60, 0, 55)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Lily, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_00C6)
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR("flo_12"), flo_12_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(KeyList)[] = {
    ITEM_WATER_STONE,
    ITEM_NONE
};

EvtScript N(EVS_OnInteract_WaterStoneSocket) = {
    EVT_IF_EQ(GF_FLO10_ShowedLilyTheWaterStone, TRUE)
        EVT_CALL(GetPartnerInUse, LVarA)
        EVT_IF_NE(LVarA, 0)
            EVT_CALL(AwaitPlayerLeave, 0, 0, 19)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
        EVT_CALL(ShowKeyChoicePopup)
        EVT_SET(LVar2, LVar0)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(-1)
                EVT_CALL(CloseChoicePopup)
                EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
                EVT_WAIT(10 * DT)
                EVT_CALL(SpeakToPlayer, NPC_Lily, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0, MSG_CH6_0081)
            EVT_CASE_DEFAULT
                EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
                EVT_CALL(PlayerMoveTo, -17, -17, 20)
                EVT_CALL(func_802CF56C, 2)
                EVT_CALL(InterpPlayerYaw, 100, 1)
                EVT_WAIT(10 * DT)
                EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(1.0 / DT), 0, 450, EVT_FLOAT(25.0), EVT_FLOAT(-6.0))
                EVT_WAIT(10 * DT)
                EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_PlaceItem)
                EVT_CALL(RemoveKeyItemAt, LVar1)
                EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, 0, -60, 6, ITEM_SPAWN_MODE_DECORATION, 0)
                EVT_SET(LVarA, LVar0)
                EVT_CALL(CloseChoicePopup)
                EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
                EVT_EXEC_WAIT(N(EVS_Scene_ReleaseFountain))
        EVT_END_SWITCH
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(AwaitPlayerLeave, 0, 0, 19)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupWaterStoneSocket) = {
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_OnInteract_WaterStoneSocket)), TRIGGER_FLOOR_TOUCH, COLLIDER_o83, EVT_PTR(N(KeyList)), 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MovePlayerToTalk) = {
    EVT_WAIT(10 * DT)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_IF_LT(LVar5, LVar2)
        EVT_SET(LVar6, 30)
    EVT_ELSE
        EVT_SET(LVar6, 20)
    EVT_END_IF
    EVT_SET(LVar1, LVar0)
    EVT_SET(LVar4, LVar0)
    EVT_SUB(LVar1, LVar6)
    EVT_ADD(LVar4, LVar6)
    EVT_SWITCH(LVar3)
        EVT_CASE_RANGE(LVar1, LVar4)
            EVT_THREAD
                EVT_IF_LT(LVar3, LVar0)
                    EVT_SUB(LVar0, 40)
                EVT_ELSE
                    EVT_ADD(LVar0, 40)
                EVT_END_IF
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(PlayerMoveTo, LVar0, LVar5, 15 * DT)
                EVT_CALL(PlayerFaceNpc, NPC_Lily, TRUE)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_END_THREAD
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Lily) = {
    EVT_EXEC_WAIT(N(EVS_PushFlowerSong))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_EXEC(N(EVS_MovePlayerToTalk))
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 325)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(23.0), EVT_FLOAT(-9.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_WAIT(10 * DT)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 5, MSG_CH6_0078)
            EVT_CALL(EndSpeech, NPC_SELF, ANIM_Lily_DreadLoop, ANIM_Lily_Dread, 5)
        EVT_CASE_LT(STORY_CH6_GOT_WATER_STONE)
            EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, FALSE)
                EVT_EXEC(N(EVS_MovePlayerToTalk))
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, 325)
                EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(23.0), EVT_FLOAT(-9.0))
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_WAIT(10 * DT)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 5, MSG_CH6_0079)
                EVT_CALL(NpcFacePlayer, NPC_SELF, 1)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Lily_Idle)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 15, EMOTER_NPC, 0, 0, 0, 0)
                EVT_WAIT(15 * DT)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_Idle, ANIM_Lily_Idle, 0, MSG_CH6_007A)
                EVT_CALL(EndSpeech, NPC_SELF, ANIM_Lily_Dread, ANIM_Lily_Idle, 0)
                EVT_CALL(GetPlayerTargetYaw, LVar0)
                EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 1)
                EVT_WAIT(20 * DT)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 5, MSG_CH6_007B)
                EVT_CALL(NpcFacePlayer, NPC_SELF, 1)
                EVT_WAIT(20 * DT)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_007C)
                EVT_CALL(ShowChoice, MSG_Choice_0011)
                EVT_WAIT(10 * DT)
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(0)
                        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_007D)
                    EVT_CASE_EQ(1)
                        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0, MSG_CH6_007E)
                EVT_END_SWITCH
                EVT_WAIT(10 * DT)
                EVT_SET(GF_FLO10_LilyRequestedWaterStone, TRUE)
                EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 0)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 5, MSG_CH6_007F)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_FILLED_SPRING_WITH_WATER)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_0080)
            EVT_SET(GF_FLO10_ShowedLilyTheWaterStone, TRUE)
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0, MSG_CH6_0085)
            EVT_CALL(EndSpeech, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 0)
            EVT_CALL(EndSpeech, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0)
        EVT_CASE_LT(STORY_CH6_RETURNED_TO_TOAD_TOWN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_0086)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_0087)
    EVT_END_SWITCH
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_EXEC_WAIT(N(EVS_PopSong))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Lily) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Lily)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_GOT_WATER_STONE)
            EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, FALSE)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Lily_IdlePlead)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
                EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 1)
            EVT_END_IF
        EVT_CASE_EQ(STORY_CH6_GOT_WATER_STONE)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_CASE_GE(STORY_CH6_FILLED_SPRING_WITH_WATER)
            EVT_CALL(SetNpcPos, NPC_SELF, -67, -20, -105)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Lily) = {
    .id = NPC_Lily,
    .pos = { 80.0f, -60.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Lily),
    .settings = &N(NpcSettings_Lily),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = LILY_ANIMS,
    .tattle = MSG_NpcTattle_Lily,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Lily)),
    {}
};
