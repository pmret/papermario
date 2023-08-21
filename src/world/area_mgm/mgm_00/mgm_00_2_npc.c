#include "mgm_00.h"

#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

API_CALLABLE(N(GetAvailableGamesCount)) {
    s32 numGames = 0;

    if (find_item(ITEM_GOLD_CREDIT) >= 0) {
        numGames = 2;
    } else if (find_item(ITEM_SILVER_CREDIT) >= 0) {
        numGames = 1;
    }

    evt_set_variable(script, LVar5, numGames);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_RaisePipe_JumpAttack) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -25, 0, -155)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -25, 0, -155)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.2))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(5)
    EVT_CALL(PlaySoundWithVolume, SOUND_GROW, 0)
    EVT_CALL(EnableModel, MODEL_o5, TRUE)
    EVT_SET(LVar0, -30)
    EVT_LOOP(30)
        EVT_ADD(LVar0, 1)
        EVT_CALL(TranslateModel, MODEL_o5, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(TranslateModel, MODEL_o5, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o5, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deili2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnEnterPipe_JumpAttack)), TRIGGER_FLOOR_TOUCH, COLLIDER_deili2, 1, 0)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RaisePipe_SmashAttack) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 95, 0, -155)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 95, 0, -155)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.2))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(5)
    EVT_CALL(PlaySoundWithVolume, SOUND_GROW, 0)
    EVT_CALL(EnableModel, MODEL_o9, TRUE)
    EVT_SET(LVar0, -30)
    EVT_LOOP(30)
        EVT_ADD(LVar0, 1)
        EVT_CALL(TranslateModel, MODEL_o9, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(TranslateModel, MODEL_o9, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o9, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deili3, COLLIDER_FLAGS_UPPER_MASK)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnEnterPipe_SmashAttack)), TRIGGER_FLOOR_TOUCH, COLLIDER_deili3, 1, 0)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetCamera_RaisePipe) = {
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.2))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_RedToad) = {
    EVT_CALL(N(GetAvailableGamesCount))
    EVT_SET(LVar6, 0)
    EVT_SET(LVar7, 0)
    EVT_IF_EQ(GF_MGM_Unlocked_JumpAttack, FALSE)
        EVT_SWITCH(LVar5)
            EVT_CASE_EQ(0)
            EVT_CASE_EQ(1)
                EVT_SET(LVar6, 1)
                EVT_SET(LVar7, 1)
            EVT_CASE_EQ(2)
                EVT_SET(LVar6, 1)
                EVT_SET(LVar7, 3)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_IF_EQ(GF_MGM_Unlocked_SmashAttack, FALSE)
            EVT_IF_LE(LVar5, 1)
                EVT_SET(LVar6, 2)
            EVT_ELSE
                EVT_SET(LVar6, 3)
                EVT_SET(LVar7, 2)
            EVT_END_IF
        EVT_ELSE
            EVT_SET(LVar6, 4)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(GF_MGM00_Met_Receptionist, FALSE)
        EVT_SET(GF_MGM00_Met_Receptionist, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0012)
    EVT_ELSE
        EVT_SWITCH(LVar6)
            EVT_CASE_EQ(0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0013)
                EVT_RETURN
            EVT_CASE_EQ(1)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0014)
            EVT_CASE_EQ(2)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0015)
                EVT_RETURN
            EVT_CASE_EQ(3)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0016)
            EVT_CASE_EQ(4)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0017)
                EVT_RETURN
        EVT_END_SWITCH
    EVT_END_IF
    EVT_SWITCH(LVar7)
        EVT_CASE_EQ(0)
            EVT_CALL(EndSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 5)
        EVT_CASE_EQ(1)
            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0018)
        EVT_CASE_EQ(2)
            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0019)
        EVT_CASE_EQ(3)
            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_001A)
    EVT_END_SWITCH
    EVT_SWITCH(LVar7)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(1)
            EVT_SET(GF_MGM_Unlocked_JumpAttack, TRUE)
            EVT_EXEC_WAIT(N(EVS_RaisePipe_JumpAttack))
            EVT_EXEC_WAIT(N(EVS_SetCamera_RaisePipe))
        EVT_CASE_EQ(2)
            EVT_SET(GF_MGM_Unlocked_SmashAttack, TRUE)
            EVT_EXEC_WAIT(N(EVS_RaisePipe_SmashAttack))
            EVT_EXEC_WAIT(N(EVS_SetCamera_RaisePipe))
        EVT_CASE_EQ(3)
            EVT_SET(GF_MGM_Unlocked_JumpAttack, TRUE)
            EVT_SET(GF_MGM_Unlocked_SmashAttack, TRUE)
            EVT_EXEC_WAIT(N(EVS_RaisePipe_JumpAttack))
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(EVS_RaisePipe_SmashAttack))
            EVT_EXEC_WAIT(N(EVS_SetCamera_RaisePipe))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_RedToad) = {
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 32, 75)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_RedToad)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_RedToad) = {
    .id = NPC_RedToad,
    .pos = { -213.0f, 12.0f, -180.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_RedToad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
    .tattle = MSG_NpcTattle_MGM_PlayroomReceptionist,
};

EvtScript N(EVS_NpcInteract_GreenToad) = {
    EVT_CALL(N(GetAvailableGamesCount))
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, MSG_MGM_0025)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, MSG_MGM_0026)
        EVT_CASE_DEFAULT
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, MSG_MGM_0027)
                EVT_CALL(SetSelfVar, 0, 1)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Green_Talk, ANIM_Toad_Green_Idle, 0, MSG_MGM_0028)
                EVT_CALL(SetSelfVar, 0, 0)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GreenToad) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_GreenToad)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_GreenToad) = {
    .id = NPC_GreenToad,
    .pos = { -88.0f, 0.0f, -95.0f },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points = {
                { -100, 0, -95 },
                { -70, 0, -95 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_GreenToad),
    .settings = &N(NpcSettings_Toad_Patrol),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = TOAD_GREEN_ANIMS,
    .tattle = MSG_NpcTattle_MGM_PlayroomCustomer,
};

EvtScript N(EVS_NpcInteract_BlueToad) = {
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(25)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_MGM_0029)
        EVT_CASE_LT(50)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_MGM_002A)
        EVT_CASE_LT(75)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_MGM_002B)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_MGM_002C)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BlueToad) = {
    EVT_CALL(RandInt, 100, LVar0)
    EVT_CALL(SetSelfVar, 0, LVar0)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_BlueToad)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_BlueToad) = {
    .id = NPC_BlueToad,
    .pos = { 46.0f, 0.0f, -205.0f },
    .yaw = 90,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points = {
                { 25, 0, -205 },
                { 75, 0, -205 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 0 },
        }
    },
    .init = &N(EVS_NpcInit_BlueToad),
    .settings = &N(NpcSettings_Toad_Patrol),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = TOAD_BLUE_ANIMS,
    .tattle = MSG_NpcTattle_MGM_BestPlayroomCustomer,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_RedToad)),
    NPC_GROUP(N(NpcData_GreenToad)),
    NPC_GROUP(N(NpcData_BlueToad)),
    {}
};
