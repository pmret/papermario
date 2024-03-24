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
    IfEq(AF_OMO07_DoorOpening, TRUE)
        Return
    EndIf
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfGt(LVar2, -50)
        Return
    EndIf
    IfGt(LVar0, 15)
        IfLt(LVar0, 35)
            Return
        EndIf
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    Set(AF_OMO07_DoorOpening, TRUE)
    Call(PlaySoundAt, SOUND_OMO_DOOR_FLIP, SOUND_SPACE_DEFAULT, 25, 0, -55)
    Thread
        IfLt(LVar0, 25)
            Call(MakeLerp, 0, 180, 30, EASING_COS_IN_OUT)
            Label(10)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_k, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(10)
            EndIf
        Else
            Call(MakeLerp, 180, 0, 30, EASING_COS_IN_OUT)
            Label(11)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_k, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(11)
            EndIf
        EndIf
        Call(UpdateColliderTransform, COLLIDER_tt1)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar2, 60)
    Wait(10)
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, LVar0, LVar2, 0)
    Set(AF_OMO07_DoorOpening, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupShyGuyPool) = {
    Call(ParentColliderToModel, COLLIDER_tt1, MODEL_k)
    BindTrigger(Ref(N(EVS_Push_SecretDoor)), TRIGGER_WALL_PUSH, COLLIDER_tt1, 1, 0)
    Set(AF_OMO07_NpcPool0, FALSE)
    Set(AF_OMO07_NpcPool1, FALSE)
    Set(AF_OMO07_NpcPool2, FALSE)
    Set(AF_OMO07_NpcPool3, FALSE)
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfLt(LVar0, 400)
            Goto(0)
        EndIf
    Label(1)
        Set(LVar4, -1)
        IfEq(AF_OMO07_NpcPool3, FALSE)
            Set(LVar4, NPC_ShyGuy_03)
        EndIf
        IfEq(AF_OMO07_NpcPool2, FALSE)
            Set(LVar4, NPC_ShyGuy_02)
        EndIf
        IfEq(AF_OMO07_NpcPool1, FALSE)
            Set(LVar4, NPC_ShyGuy_01)
        EndIf
        IfEq(LVar4, -1)
            Wait(1)
            Goto(1)
        EndIf
        IfEq(AF_OMO07_NpcPool0, FALSE)
            Set(AF_OMO07_NpcPool0, TRUE)
        Else
            Wait(40)
        EndIf
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar2, -85)
            Goto(1)
        EndIf
        IfLt(LVar0, -50)
            Goto(1)
        EndIf
        IfGt(LVar0, 600)
            Goto(1)
        EndIf
        Call(N(SetShyGuyPoolState), LVar4, TRUE)
        Call(SetNpcVar, LVar4, SHYGUY_VAR_STATE, SHYGUY_STATE_RUN_TO_DOOR)
        Wait(1)
        Label(2)
            Call(GetNpcVar, LVar4, SHYGUY_VAR_STATE, LVar3)
            IfEq(LVar3, SHYGUY_STATE_RUN_TO_DOOR)
                Wait(1)
                Goto(2)
            EndIf
        Goto(1)
    Return
    End
};

EvtScript N(EVS_NpcAI_ShyGuy) = {
    Label(0)
        Call(GetSelfVar, SHYGUY_VAR_STATE, LVar0)
        Switch(LVar0)
            CaseEq(SHYGUY_STATE_FREE)
                Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            CaseEq(SHYGUY_STATE_RUN_TO_DOOR)
                Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
                Call(EnableNpcShadow, NPC_SELF, TRUE)
                Call(SetSelfEnemyFlagBits, ENEMY_FLAG_PASSIVE, 0)
                Call(SetNpcPos, NPC_SELF, 800, 0, 75)
                Call(SetNpcSpeed, NPC_SELF, Float(4.0))
                Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
                Call(SetNpcSpeed, NPC_SELF, Float(5.0))
                Call(NpcMoveTo, NPC_SELF, 665, 75, 0)
                Call(SetNpcSpeed, NPC_SELF, Float(4.0))
                Call(NpcMoveTo, NPC_SELF, 635, -107, 0)
                Call(NpcMoveTo, NPC_SELF, 100, -107, 0)
                Call(NpcMoveTo, NPC_SELF, -10, -107, 0)
                Call(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_WAIT_AT_DOOR)
                Call(SetSelfVar, SHYGUY_VAR_WAIT_TIME, 0)
            CaseEq(SHYGUY_STATE_WAIT_AT_DOOR)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                IfLt(LVar0, 130)
                    Wait(40)
                    Call(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_OPEN_DOOR)
                EndIf
                Call(GetSelfVar, SHYGUY_VAR_WAIT_TIME, LVar0)
                Add(LVar0, 1)
                Call(SetSelfVar, SHYGUY_VAR_WAIT_TIME, LVar0)
                IfGt(LVar0, 180)
                    Wait(40)
                    Call(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_OPEN_DOOR)
                    Call(SetSelfVar, SHYGUY_VAR_WAIT_TIME, 0)
                EndIf
            CaseEq(SHYGUY_STATE_OPEN_DOOR)
                Call(PlaySoundAt, SOUND_OMO_DOOR_FLIP, SOUND_SPACE_DEFAULT, 25, 0, -55)
                Thread
                    Set(AF_OMO07_DoorOpening, TRUE)
                    Set(LVar2, MV_SecretDoorAngle)
                    Add(LVar2, 180)
                    Call(MakeLerp, MV_SecretDoorAngle, LVar2, 30, EASING_COS_IN_OUT)
                    Label(10)
                    Call(UpdateLerp)
                    Call(RotateModel, MODEL_k, LVar0, 0, 1, 0)
                    Call(UpdateColliderTransform, COLLIDER_tt1)
                    Wait(1)
                    IfEq(LVar1, 1)
                        Goto(10)
                    EndIf
                    Set(MV_SecretDoorAngle, LVar2)
                    Mod(MV_SecretDoorAngle, 360)
                    Set(AF_OMO07_DoorOpening, FALSE)
                    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                EndThread
                Wait(10)
                Call(NpcMoveTo, NPC_SELF, -10, 50, 0)
                Call(GetSelfVar, SHYGUY_VAR_STATE, LVar0)
                IfEq(LVar0, SHYGUY_STATE_OPEN_DOOR)
                    Call(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_ACTIVE)
                EndIf
            CaseEq(SHYGUY_STATE_ACTIVE)
                Wait(1)
                Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_ShyGuy_Patrol)))
                Wait(10)
            CaseEq(SHYGUY_STATE_RECYCLE)
                Call(DisablePlayerInput, TRUE)
                Loop(30)
                    Call(GetSelfNpcID, LVar0)
                    Call(N(SetShyGuyPoolState), LVar0, FALSE)
                    Wait(1)
                EndLoop
                Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                Call(DisablePlayerInput, FALSE)
                Call(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_FREE)
            CaseEq(SHYGUY_STATE_FORCE_RECYCLE)
                Call(GetSelfNpcID, LVar0)
                Call(N(SetShyGuyPoolState), LVar0, FALSE)
                Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                Call(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_FREE)
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_ShyGuy) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(SetSelfEnemyFlagBits, ENEMY_FLAG_PASSIVE, 1)
            Call(EnableNpcShadow, NPC_SELF, FALSE)
            Call(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_RECYCLE)
            Wait(1)
            Call(SetSelfVar, SHYGUY_VAR_STATE, SHYGUY_STATE_RECYCLE)
            Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_ShyGuy)))
            Call(DoNpcDefeat)
            Wait(1)
        CaseEq(OUTCOME_PLAYER_LOST)
            Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcAI_ShyGuy)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_ShyGuy)))
    Return
    End
};

EvtScript N(EVS_NpcIdle_Fuzzy) = {
    Label(0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, 990)
        Wait(1)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(N(DisableCameraLeadingPlayer))
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetCamProperties, CAM_DEFAULT, Float(5.0), LVar0, LVar1, LVar2, 300, Float(13.0), Float(-9.5))
    IfEq(GB_OMO_PeachChoice2, 0)
        Call(SpeakToPlayer, NPC_Fuzzy, ANIM_Fuzzy_Anim0B, ANIM_Fuzzy_Idle, 0, MSG_CH4_003C)
    Else
        Call(SpeakToPlayer, NPC_HammerBros, ANIM_HammerBros_Anim0A, ANIM_HammerBros_Anim02, 0, MSG_CH4_003D)
    EndIf
    Thread
        Call(N(EnableCameraLeadingPlayer))
        Call(ResetCam, CAM_DEFAULT, Float(4.0))
    EndThread
    Call(DisablePlayerInput, FALSE)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Fuzzy) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GF_OMO07_Item_ThunderRage, TRUE)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Fuzzy) = {
    IfEq(GB_OMO_PeachChoice2, 0)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Fuzzy)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Fuzzy)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_HammerBros) = {
    IfEq(GB_OMO_PeachChoice2, 1)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Fuzzy)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Fuzzy)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Kammy) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kammy)))
    Return
    End
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
