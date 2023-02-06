#include "mim_02.h"

EvtScript N(EVS_Unused_DoNothing) = {
    EVT_RETURN
    EVT_END
};

#include "world/common/npc/Oaklie.inc.c"

#include "world/common/enemy/complete/ForestFuzzy_Wander.inc.c"

s32 N(KeyList)[] = {
    ITEM_FOREST_PASS,
    ITEM_NONE
};

#include "world/common/complete/KeyItemChoice.inc.c"

EvtScript N(EVS_NpcInteract_Oaklie) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_INVITED_TO_BOOS_MANSION)
        EVT_CALL(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0006)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0007)
    EVT_CALL(SetNpcFlagBits, NPC_Oaklie, NPC_FLAG_100, TRUE)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
        EVT_WAIT(15)
        EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -426, 58, -70)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(6.0), EVT_FLOAT(-6.0))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_Oaklie, SOUND_32C, SOUND_SPACE_MODE_0)
    EVT_CALL(SetNpcJumpscale, NPC_Oaklie, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_Oaklie, -426, 58, -70, 20)
    EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0008)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
        EVT_WAIT(15)
        EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_Oaklie, SOUND_32C, SOUND_SPACE_MODE_0)
    EVT_CALL(NpcJump0, NPC_Oaklie, -333, 0, -81, 20)
    EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
        EVT_WAIT(15)
        EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_Oaklie, SOUND_32C, SOUND_SPACE_MODE_0)
    EVT_CALL(NpcJump0, NPC_Oaklie, -300, 0, -170, 15)
    EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
        EVT_WAIT(15)
        EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_Oaklie, SOUND_32C, SOUND_SPACE_MODE_0)
    EVT_CALL(NpcJump0, NPC_Oaklie, -226, 0, -245, 15)
    EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
        EVT_WAIT(15)
        EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_Oaklie, SOUND_32C, SOUND_SPACE_MODE_0)
    EVT_CALL(NpcJump0, NPC_Oaklie, -160, 0, -296, 15)
    EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    EVT_WAIT(5)
    EVT_CALL(SetNpcPos, NPC_Oaklie, NPC_DISPOSE_LOCATION)
    EVT_SET(GB_StoryProgress, STORY_CH3_ALLOWED_INTO_FOREVER_FOREST)
    EVT_EXEC_WAIT(N(EVS_EnableWestGate))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Oaklie) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_ALLOWED_INTO_FOREVER_FOREST)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_WAIT(25)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(6.0), EVT_FLOAT(-6.0))
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_CALL(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0003)
            EVT_WAIT(10)
            EVT_THREAD
                EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
                EVT_WAIT(5)
                EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
            EVT_END_THREAD
            EVT_CALL(PlaySoundAtNpc, NPC_Oaklie, SOUND_32C, SOUND_SPACE_MODE_0)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
            EVT_CALL(NpcJump0, NPC_SELF, -455, 0, 0, 20)
            EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Idle)
            EVT_WAIT(15)
            EVT_IF_LT(GB_StoryProgress, STORY_CH1_RETURNED_TO_TOAD_TOWN)
                EVT_CALL(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0004)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0005)
            EVT_END_IF
            EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Oaklie) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Oaklie)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Oaklie)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_GE(STORY_CH3_ALLOWED_INTO_FOREVER_FOREST)
            EVT_CALL(SetNpcPos, NPC_Oaklie, NPC_DISPOSE_LOCATION)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Oaklie) = {
    .id = NPC_Oaklie,
    .settings = &N(NpcSettings_Oaklie),
    .pos = { -426.0f, 58.0f, -70.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
    .init = &N(EVS_NpcInit_Oaklie),
    .drops = OAKLIE_DROPS,
    .animations = OAKLIE_ANIMS,
    .tattle = MSG_NpcTattle_Oaklie,
};

StaticNpc N(NpcData_Fuzzy_01) = {
    .id = NPC_Fuzzy_01,
    .settings = &N(NpcSettings_ForestFuzzy_Wander),
    .pos = { 300.0f, 0.0f, 130.0f },
    .yaw = 0,
    .flags = 0,
    .drops = FOREST_FUZZY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 400 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 400 },
        }
    },
    .animations = FOREST_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Fuzzy_02) = {
    .id = NPC_Fuzzy_02,
    .settings = &N(NpcSettings_ForestFuzzy_Wander),
    .pos = { -100.0f, 0.0f, -320.0f },
    .yaw = 0,
    .flags = 0,
    .drops = FOREST_FUZZY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, 0 },
            .wanderSize = { 400 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 400 },
        }
    },
    .animations = FOREST_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Oaklie)),
    NPC_GROUP(N(NpcData_Fuzzy_01), BTL_MIM_FORMATION_00, BTL_MIM_STAGE_00),
    NPC_GROUP(N(NpcData_Fuzzy_02), BTL_MIM_FORMATION_01, BTL_MIM_STAGE_00),
    {}
};
