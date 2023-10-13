#include "flo_07.h"

#include "world/common/npc/Posie.inc.c"

#include "common/foliage.inc.c"

#include "world/common/complete/GiveReward.inc.c"

EvtScript N(EVS_Scene_SunReturns) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GetNpcPos, NPC_Posie, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(11.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Posie, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_00C5)
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR("flo_10"), flo_10_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShakeGround) = {
    EVT_LABEL(0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 1, EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeCrystalBerry) = {
    EVT_IF_EQ(AF_FLO_MadeCrystalBerry, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Posie, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0068)
    EVT_THREAD
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.0), EVT_FLOAT(-7.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_LOOP_RUMBLE)
    EVT_EXEC_GET_TID(N(EVS_ShakeGround), MV_GroundShakingScript)
    EVT_CALL(SpeakToPlayer, NPC_Posie, ANIM_Posie_Strain, ANIM_Posie_Strain, 0, MSG_CH6_0069)
    EVT_KILL_THREAD(MV_GroundShakingScript)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.0), EVT_FLOAT(-7.5))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(8.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, LVar2)
    EVT_IF_LT(LVar0, -250)
        EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -225, 100, -25, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_FLO07_Item_CrystalBerry)
    EVT_ELSE
        EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -265, 100, 54, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_FLO07_Item_CrystalBerry)
        EVT_SET(GF_FLO07_CrystalBerryFellOnLeftSide, TRUE)
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_LRAW_RUMBLE | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_CALL(StopTrackingSoundPos, SOUND_LRAW_RUMBLE)
    EVT_SET(AF_FLO_MadeCrystalBerry, TRUE)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Posie, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_006A)
    EVT_SET(GB_StoryProgress, STORY_CH6_GOT_CRYSTAL_BERRY)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Posie) = {
    EVT_EXEC_WAIT(N(EVS_PushFlowerSong))
    EVT_CALL(NpcFacePlayer, NPC_SELF, 1)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_IF_EQ(AF_FLO_PoiseHintDialogue, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0070)
                EVT_SET(AF_FLO_PoiseHintDialogue, TRUE)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0071)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_GOT_FERTILE_SOIL)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), 0, EVT_FLOAT(350.0), EVT_FLOAT(18.0), EVT_FLOAT(-7.5))
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0065)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Posie_GiveItem)
            EVT_WAIT(20)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Posie_Still)
            EVT_GIVE_KEY_REWARD(ITEM_FERTILE_SOIL)
            EVT_SET(GB_StoryProgress, STORY_CH6_GOT_FERTILE_SOIL)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0066)
            EVT_IF_EQ(GF_FLO12_RosieRequestedSomethingBeautiful, TRUE)
                EVT_EXEC_WAIT(N(EVS_MakeCrystalBerry))
            EVT_END_IF
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
        EVT_CASE_LT(STORY_CH6_GOT_CRYSTAL_BERRY)
            EVT_IF_EQ(GF_FLO12_RosieRequestedSomethingBeautiful, TRUE)
                EVT_IF_EQ(AF_FLO_MadeCrystalBerry, FALSE)
                    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), 0, EVT_FLOAT(350.0), EVT_FLOAT(18.0), EVT_FLOAT(-7.5))
                    EVT_EXEC_WAIT(N(EVS_MakeCrystalBerry))
                    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0072)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0072)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_IF_EQ(GF_FLO07_Item_CrystalBerry, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0072)
            EVT_ELSE
                EVT_IF_LT(GB_StoryProgress, STORY_CH6_GOT_WATER_STONE)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0073)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0074)
                EVT_END_IF
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0075)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_RETURNED_TO_TOAD_TOWN)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0076)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_0077)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_PopSong))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Posie) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH6_GOT_CRYSTAL_BERRY)
        EVT_IF_EQ(GF_FLO07_Item_CrystalBerry, FALSE)
            EVT_IF_EQ(GF_FLO07_CrystalBerryFellOnLeftSide, FALSE)
                EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -225, 0, -25, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO07_Item_CrystalBerry)
            EVT_ELSE
                EVT_CALL(MakeItemEntity, ITEM_CRYSTAL_BERRY, -265, 0, 54, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO07_Item_CrystalBerry)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_SET(AF_FLO_PoiseHintDialogue, FALSE)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Posie)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TryKickingPlayerOut) = {
    EVT_IF_NE(AB_FLO_PoiseKickedOutCount, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(10)
        EVT_IF_LT(AB_FLO_PoiseKickedOutCount, 5)
            EVT_CALL(SpeakToPlayer, NPC_Posie, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_006E)
            EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
            EVT_CALL(PlayerMoveTo, 410, LVar3, 10)
            EVT_ADD(AB_FLO_PoiseKickedOutCount, 1)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_Posie, ANIM_Posie_Talk, ANIM_Posie_Idle, 0, MSG_CH6_006F)
            EVT_SET(AB_FLO_PoiseKickedOutCount, 0)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnHit_CrystalTree) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_GOT_CRYSTAL_BERRY)
        EVT_CALL(NpcFacePlayer, NPC_Posie, 1)
        EVT_WAIT(10)
        EVT_CALL(SpeakToPlayer, NPC_Posie, ANIM_Posie_Confused, ANIM_Posie_Idle, 0, MSG_CH6_0067)
        EVT_IF_EQ(GB_StoryProgress, STORY_CH6_GOT_FERTILE_SOIL)
            EVT_IF_EQ(GF_FLO12_RosieRequestedSomethingBeautiful, TRUE)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -250, 0, 0)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, -250, 0, 0)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_EXEC_WAIT(N(EVS_MakeCrystalBerry))
                EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_IF_EQ(GF_FLO07_Item_CrystalBerry, FALSE)
            EVT_CALL(NpcFacePlayer, NPC_Posie, 1)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Posie, ANIM_Posie_Confused, ANIM_Posie_Idle, 0, MSG_CH6_0067)
        EVT_ELSE
            EVT_ADD(AB_FLO_CrystalTreeHitCount, 1)
            EVT_SWITCH(AB_FLO_CrystalTreeHitCount)
                EVT_CASE_LT(2)
                    EVT_CALL(SpeakToPlayer, NPC_Posie, ANIM_Posie_TalkAngry, ANIM_Posie_Idle, 0, MSG_CH6_006B)
                EVT_CASE_LT(5)
                    EVT_CALL(SpeakToPlayer, NPC_Posie, ANIM_Posie_TalkAngry, ANIM_Posie_Idle, 0, MSG_CH6_006C)
                EVT_CASE_GE(5)
                    EVT_CALL(SpeakToPlayer, NPC_Posie, ANIM_Posie_TalkAngry, ANIM_Posie_Idle, 0, MSG_CH6_006D)
                    EVT_SET(AB_FLO_PoiseKickedOutCount, 1)
                    EVT_CALL(GotoMap, EVT_PTR("flo_25"), flo_25_ENTRY_1)
                    EVT_WAIT(100)
            EVT_END_SWITCH
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

FoliageModelList N(CrystalTree_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o6, MODEL_o7, MODEL_o8);
FoliageModelList N(CrystalTree_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o5);

ShakeTreeConfig N(ShakeTree_CrystalTree) = {
    .leaves = &N(CrystalTree_LeafModels),
    .trunk = &N(CrystalTree_TrunkModels),
    .callback = &N(EVS_OnHit_CrystalTree),
};

BombTrigger N(BombPos_CrystalTree) = {
    .pos = { -309.0f, 0.0f, 31.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_CrystalTree)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o5, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_CrystalTree)), 1, 0)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Posie) = {
    .id = NPC_Posie,
    .pos = { -260.0f, 0.0f, 0.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Posie),
    .settings = &N(NpcSettings_Posie),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = POSIE_ANIMS,
    .tattle = MSG_NpcTattle_Posie,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Posie)),
    {}
};
