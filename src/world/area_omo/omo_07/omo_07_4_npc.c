#include "omo_07.h"

#include "world/common/enemy/ShyGuy_Wander.inc.c"
#include "world/common/enemy/ShyGuy_Patrol.inc.c"
#include "world/common/enemy/SkyGuy.inc.c"

NpcSettings N(NpcSettings_Fuzzy) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(NpcSettings_HammerBros) = {
    .height = 36,
    .radius = 24,
    .level = ACTOR_LEVEL_HAMMER_BROS,
};

#include "world/common/enemy/Kammy_Flying.inc.c"
#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"

// an 'unlimited' number of shy guys walk along the path and emerge from the playhouse
// they are drawn from a pool of 4 NPCs, with their lifecycle tracked via these states
enum {
    // Get/SetSelfVar
    SHYGUY_VAR_STATE            = 0,
    SHYGUY_VAR_WAIT_TIME        = 1,
    // states
    SHYGUY_STATE_FREE           = 0,
    SHYGUY_STATE_RUN_TO_DOOR    = 1,
    SHYGUY_STATE_WAIT_AT_DOOR   = 2,
    SHYGUY_STATE_OPEN_DOOR      = 3,
    SHYGUY_STATE_ACTIVE         = 4,
    SHYGUY_STATE_RECYCLE        = 10,
    SHYGUY_STATE_FORCE_RECYCLE  = 11, // unused, recycles NPC immediately
};

API_CALLABLE(N(SetShyGuyPoolState)) {
    Bytecode* args = script->ptrReadPos;
    s32 base;
    s32 npcID;
    s32 value;

    base = AF_OMO07_NpcPool0;
    do {
        npcID = evt_get_variable(script, *(args++));
    } while (0); // TODO required to match
    npcID += base;
    value = evt_get_variable(script, *args++);

    evt_set_variable(script, npcID, value);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Push_SecretDoor) = {
    EVT_IF_EQ(AF_OMO07_DoorOpening, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar2, -50)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(LVar0, 15)
        EVT_IF_LT(LVar0, 35)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(AF_OMO07_DoorOpening, TRUE)
    EVT_CALL(PlaySoundAt, SOUND_OMO_DOOR_FLIP, SOUND_SPACE_DEFAULT, 25, 0, -55)
    EVT_THREAD
        EVT_IF_LT(LVar0, 25)
            EVT_CALL(MakeLerp, 0, 180, 30, EASING_COS_IN_OUT)
            EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_k, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(MakeLerp, 180, 0, 30, EASING_COS_IN_OUT)
            EVT_LABEL(11)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_k, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(11)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(UpdateColliderTransform, COLLIDER_tt1)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 60)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, LVar0, LVar2, 0)
    EVT_SET(AF_OMO07_DoorOpening, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupShyGuyPool) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_tt1, MODEL_k)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Push_SecretDoor)), TRIGGER_WALL_PUSH, COLLIDER_tt1, 1, 0)
    EVT_SET(AF_OMO07_NpcPool0, FALSE)
    EVT_SET(AF_OMO07_NpcPool1, FALSE)
    EVT_SET(AF_OMO07_NpcPool2, FALSE)
    EVT_SET(AF_OMO07_NpcPool3, FALSE)
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_LT(LVar0, 400)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_LABEL(1)
        EVT_SET(LVar4, -1)
        EVT_IF_EQ(AF_OMO07_NpcPool3, FALSE)
            EVT_SET(LVar4, NPC_ShyGuy_03)
        EVT_END_IF
        EVT_IF_EQ(AF_OMO07_NpcPool2, FALSE)
            EVT_SET(LVar4, NPC_ShyGuy_02)
        EVT_END_IF
        EVT_IF_EQ(AF_OMO07_NpcPool1, FALSE)
            EVT_SET(LVar4, NPC_ShyGuy_01)
        EVT_END_IF
        EVT_IF_EQ(LVar4, -1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_IF_EQ(AF_OMO07_NpcPool0, FALSE)
            EVT_SET(AF_OMO07_NpcPool0, TRUE)
        EVT_ELSE
            EVT_WAIT(40)
        EVT_END_IF
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar2, -85)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_IF_LT(LVar0, -50)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_IF_GT(LVar0, 600)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(N(SetShyGuyPoolState), LVar4, TRUE)
        EVT_CALL(SetNpcVar, LVar4, SHYGUY_VAR_STATE, SHYGUY_STATE_RUN_TO_DOOR)
        EVT_WAIT(1)
        EVT_LABEL(2)
            EVT_CALL(GetNpcVar, LVar4, SHYGUY_VAR_STATE, LVar3)
            EVT_IF_EQ(LVar3, SHYGUY_STATE_RUN_TO_DOOR)
                EVT_WAIT(1)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_GOTO(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_ShyGuy) = {
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, SHYGUY_VAR_STATE, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(SHYGUY_STATE_FREE)
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CASE_EQ(SHYGUY_STATE_RUN_TO_DOOR)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
                EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_PASSIVE, 0)
                EVT_CALL(SetNpcPos, NPC_SELF, 800, 0, 75)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
                EVT_CALL(NpcMoveTo, NPC_SELF, 665, 75, 0)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
                EVT_CALL(NpcMoveTo, NPC_SELF, 635, -107, 0)
                EVT_CALL(NpcMoveTo, NPC_SELF, 100, -107, 0)
                EVT_CALL(NpcMoveTo, NPC_SELF, -10, -107, 0)
                EVT_CALL(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_WAIT_AT_DOOR)
                EVT_CALL(SetSelfVar, SHYGUY_VAR_WAIT_TIME, 0)
            EVT_CASE_EQ(SHYGUY_STATE_WAIT_AT_DOOR)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_IF_LT(LVar0, 130)
                    EVT_WAIT(40)
                    EVT_CALL(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_OPEN_DOOR)
                EVT_END_IF
                EVT_CALL(GetSelfVar, SHYGUY_VAR_WAIT_TIME, LVar0)
                EVT_ADD(LVar0, 1)
                EVT_CALL(SetSelfVar, SHYGUY_VAR_WAIT_TIME, LVar0)
                EVT_IF_GT(LVar0, 180)
                    EVT_WAIT(40)
                    EVT_CALL(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_OPEN_DOOR)
                    EVT_CALL(SetSelfVar, SHYGUY_VAR_WAIT_TIME, 0)
                EVT_END_IF
            EVT_CASE_EQ(SHYGUY_STATE_OPEN_DOOR)
                EVT_CALL(PlaySoundAt, SOUND_OMO_DOOR_FLIP, SOUND_SPACE_DEFAULT, 25, 0, -55)
                EVT_THREAD
                    EVT_SET(AF_OMO07_DoorOpening, TRUE)
                    EVT_SET(LVar2, MV_SecretDoorAngle)
                    EVT_ADD(LVar2, 180)
                    EVT_CALL(MakeLerp, MV_SecretDoorAngle, LVar2, 30, EASING_COS_IN_OUT)
                    EVT_LABEL(10)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(RotateModel, MODEL_k, LVar0, 0, 1, 0)
                    EVT_CALL(UpdateColliderTransform, COLLIDER_tt1)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_GOTO(10)
                    EVT_END_IF
                    EVT_SET(MV_SecretDoorAngle, LVar2)
                    EVT_MOD(MV_SecretDoorAngle, 360)
                    EVT_SET(AF_OMO07_DoorOpening, FALSE)
                    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                EVT_END_THREAD
                EVT_WAIT(10)
                EVT_CALL(NpcMoveTo, NPC_SELF, -10, 50, 0)
                EVT_CALL(GetSelfVar, SHYGUY_VAR_STATE, LVar0)
                EVT_IF_EQ(LVar0, SHYGUY_STATE_OPEN_DOOR)
                    EVT_CALL(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_ACTIVE)
                EVT_END_IF
            EVT_CASE_EQ(SHYGUY_STATE_ACTIVE)
                EVT_WAIT(1)
                EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy_Patrol)))
                EVT_WAIT(10)
            EVT_CASE_EQ(SHYGUY_STATE_RECYCLE)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_LOOP(30)
                    EVT_CALL(GetSelfNpcID, LVar0)
                    EVT_CALL(N(SetShyGuyPoolState), LVar0, FALSE)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                EVT_CALL(DisablePlayerInput, FALSE)
                EVT_CALL(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_FREE)
            EVT_CASE_EQ(SHYGUY_STATE_FORCE_RECYCLE)
                EVT_CALL(GetSelfNpcID, LVar0)
                EVT_CALL(N(SetShyGuyPoolState), LVar0, FALSE)
                EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                EVT_CALL(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_FREE)
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_ShyGuy) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_PASSIVE, 1)
            EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
            EVT_CALL(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_RECYCLE)
            EVT_WAIT(1)
            EVT_CALL(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_RECYCLE)
            EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy)))
            EVT_CALL(DoNpcDefeat)
            EVT_WAIT(1)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_ShyGuy)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_ShyGuy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Fuzzy) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, 990)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(DisableCameraLeadingPlayer))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(5.0), LVar0, LVar1, LVar2, 300, EVT_FLOAT(13.0), EVT_FLOAT(-9.5))
    EVT_IF_EQ(GB_OMO_PeachChoice2, 0)
        EVT_CALL(SpeakToPlayer, NPC_Fuzzy, ANIM_Fuzzy_Anim0B, ANIM_Fuzzy_Idle, 0, MSG_CH4_003C)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_CH4_003D)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(N(EnableCameraLeadingPlayer))
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_END_THREAD
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Fuzzy) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_OMO07_Item_ThunderRage, TRUE)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Fuzzy) = {
    EVT_IF_EQ(GB_OMO_PeachChoice2, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Fuzzy)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Fuzzy)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_HammerBros) = {
    EVT_IF_EQ(GB_OMO_PeachChoice2, 1)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Fuzzy)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Fuzzy)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kammy) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kammy)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_ShyGuy) = {
    .id = NPC_ShyGuy_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 6,
            .points  = {
                { 30, 0, 50 },
                { 50, 0, 100 },
                { 100, 0, 100 },
                { 120, 0, 50 },
                { 100, 0, 0 },
                { 50, 0, 0 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 75, 0, 50 },
            .detectSize = { 100 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy),
    .settings = &N(NpcSettings_ShyGuy_Patrol),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_02) = {
    .id = NPC_ShyGuy_02,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 6,
            .points  = {
                { 30, 0, 50 },
                { 50, 0, 100 },
                { 100, 0, 100 },
                { 120, 0, 50 },
                { 100, 0, 0 },
                { 50, 0, 0 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 75, 0, 50 },
            .detectSize = { 100 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy),
    .settings = &N(NpcSettings_ShyGuy_Patrol),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_03) = {
    .id = NPC_ShyGuy_03,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 6,
            .points  = {
                { 30, 0, 50 },
                { 50, 0, 100 },
                { 100, 0, 100 },
                { 120, 0, 50 },
                { 100, 0, 0 },
                { 50, 0, 0 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 75, 0, 50 },
            .detectSize = { 100 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy),
    .settings = &N(NpcSettings_ShyGuy_Patrol),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_ShyGuy_04) = {
    .id = NPC_ShyGuy_04,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 6,
            .points  = {
                { 30, 0, 50 },
                { 50, 0, 100 },
                { 100, 0, 100 },
                { 120, 0, 50 },
                { 100, 0, 0 },
                { 50, 0, 0 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 75, 0, 50 },
            .detectSize = { 100 },
        }
    },
    .init = &N(EVS_NpcInit_ShyGuy),
    .settings = &N(NpcSettings_ShyGuy_Patrol),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
};

NpcData N(NpcData_Fuzzy) = {
    .id = NPC_Fuzzy,
    .pos = { 1050.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Fuzzy),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_Fuzzy_Walk,
        .walk   = ANIM_Fuzzy_Walk,
        .run    = ANIM_Fuzzy_Run,
        .chase  = ANIM_Fuzzy_Run,
        .anim_4 = ANIM_Fuzzy_Idle,
        .anim_5 = ANIM_Fuzzy_Idle,
        .death  = ANIM_Fuzzy_Hurt,
        .hit    = ANIM_Fuzzy_Hurt,
        .anim_8 = ANIM_Fuzzy_Run,
        .anim_9 = ANIM_Fuzzy_Run,
        .anim_A = ANIM_Fuzzy_Run,
        .anim_B = ANIM_Fuzzy_Run,
        .anim_C = ANIM_Fuzzy_Run,
        .anim_D = ANIM_Fuzzy_Run,
        .anim_E = ANIM_Fuzzy_Run,
        .anim_F = ANIM_Fuzzy_Run,
    },
};

NpcData N(NpcData_HammerBros) = {
    .id = NPC_HammerBros,
    .pos = { 1050.0f, 0.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_HammerBros),
    .settings = &N(NpcSettings_HammerBros),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_HammerBros_Anim02,
        .walk   = ANIM_HammerBros_Anim04,
        .run    = ANIM_HammerBros_Anim07,
        .chase  = ANIM_HammerBros_Anim07,
        .anim_4 = ANIM_HammerBros_Anim02,
        .anim_5 = ANIM_HammerBros_Anim02,
        .death  = ANIM_HammerBros_Anim0E,
        .hit    = ANIM_HammerBros_Anim0E,
        .anim_8 = ANIM_HammerBros_Anim18,
        .anim_9 = ANIM_HammerBros_Anim19,
        .anim_A = ANIM_HammerBros_Anim02,
        .anim_B = ANIM_HammerBros_Anim02,
        .anim_C = ANIM_HammerBros_Anim02,
        .anim_D = ANIM_HammerBros_Anim02,
        .anim_E = ANIM_HammerBros_Anim02,
        .anim_F = ANIM_HammerBros_Anim02,
    },
};

NpcData N(NpcData_SkyGuy_01) = {
    .id = NPC_SkyGuy_01,
    .pos = { -650.0f, 140.0f, -105.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -650, 140, -105 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -650, 140, -105 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_SkyGuy),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SKY_GUY_DROPS,
    .animations = SKY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_SkyGuy_02) = {
    .id = NPC_SkyGuy_02,
    .pos = { -550.0f, 60.0f, 70.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -550, 60, 70 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -550, 60, 70 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_SkyGuy),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SKY_GUY_DROPS,
    .animations = SKY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim0E,
    ANIM_WorldKammy_Anim0F,
    ANIM_WorldKammy_Anim10,
    ANIM_WorldKammy_Anim13,
    ANIM_WorldKammy_Anim15,
    ANIM_WorldKammy_Anim16,
    ANIM_LIST_END
};

NpcData N(NpcData_Kammy) = {
    .id = NPC_Kammy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kammy),
    .settings = &N(NpcSettings_Kammy_Flying),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = KAMMY_ANIMS,
    .extraAnimations = N(ExtraAnims_Kammy),
};

NpcGroupList N(FuzzyAmbushNPCs) = {
    NPC_GROUP(N(NpcData_ShyGuy), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_ShyGuy_02), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_ShyGuy_03), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_ShyGuy_04), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_SkyGuy_01), BTL_OMO_FORMATION_14, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SkyGuy_02), BTL_OMO_FORMATION_12, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_Fuzzy), BTL_OMO3_FORMATION_05, BTL_OMO3_STAGE_05),
    {}
};

NpcGroupList N(HammerBrosAmbushNPCs) = {
    NPC_GROUP(N(NpcData_ShyGuy), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_ShyGuy_02), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_ShyGuy_03), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_ShyGuy_04), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_SkyGuy_01), BTL_OMO_FORMATION_14, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SkyGuy_02), BTL_OMO_FORMATION_12, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_HammerBros), BTL_OMO3_FORMATION_07, BTL_OMO3_STAGE_05),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_ShyGuy), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_ShyGuy_02), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_ShyGuy_03), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_ShyGuy_04), BTL_OMO3_FORMATION_0A, BTL_OMO3_STAGE_01),
    NPC_GROUP(N(NpcData_SkyGuy_01), BTL_OMO_FORMATION_14, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_SkyGuy_02), BTL_OMO_FORMATION_12, BTL_OMO_STAGE_00),
    {}
};

NpcGroupList N(KammySceneNPCs) = {
    NPC_GROUP(N(NpcData_Kammy)),
    NPC_GROUP(N(NpcData_Fuzzy), BTL_OMO3_FORMATION_05, BTL_OMO3_STAGE_05),
    NPC_GROUP(N(NpcData_HammerBros), BTL_OMO3_FORMATION_07, BTL_OMO3_STAGE_05),
    {}
};
