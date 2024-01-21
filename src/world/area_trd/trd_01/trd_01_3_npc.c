#include "trd_01.h"

MAP_RODATA_PAD(1, pad);

extern EvtScript N(EVS_FocusCamOnLock);

#include "world/common/enemy/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/Bobomb_Guard.inc.c"

API_CALLABLE(N(SetNewWanderCenterPos)) {
    Enemy* owner1 = script->owner1.enemy;
    Npc* npc = get_npc_safe(script->owner2.npcID);

    owner1->territory->wander.centerPos.x = npc->pos.x;
    owner1->territory->wander.centerPos.y = npc->pos.y;
    owner1->territory->wander.centerPos.z = npc->pos.z;
    owner1->territory->wander.detectPos.x = npc->pos.x;
    owner1->territory->wander.detectPos.y = npc->pos.y;
    owner1->territory->wander.detectPos.z = npc->pos.z;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_KoopaTroopa_02) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(GetSelfNpcID, LVar0)
    IfEq(LVar0, 1)
        Call(SetNpcPos, NPC_SELF, 45, -30, 20)
    Else
        Call(SetNpcPos, NPC_SELF, -70, -30, -20)
    EndIf
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    Label(0)
    Call(MakeLerp, Float(-2.0), Float(2.0), 30, EASING_COS_IN_OUT)
    Label(10)
    IfEq(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
        Goto(100)
    EndIf
    Call(UpdateLerp)
    Set(LVar5, LVar3)
    Add(LVar5, LVar0)
    Call(SetNpcPos, NPC_SELF, LVar2, LVar5, LVar4)
    Wait(1)
    IfNe(LVar1, 0)
        Goto(10)
    EndIf
    Wait(5)
    Call(MakeLerp, Float(2.0), Float(-2.0), 30, EASING_COS_IN_OUT)
    Label(20)
    IfEq(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
        Goto(100)
    EndIf
    Call(UpdateLerp)
    Set(LVar5, LVar3)
    Add(LVar5, LVar0)
    Call(SetNpcPos, NPC_SELF, LVar2, LVar5, LVar4)
    Wait(1)
    IfNe(LVar1, 0)
        Goto(20)
    EndIf
    Wait(5)
    Goto(0)
    Call(EnableNpcShadow, NPC_SELF, TRUE)
    Label(100)
    Call(GetSelfNpcID, LVar0)
    IfEq(LVar0, 1)
        IfEq(NPC_KoopaTroopa_02_DonePanic, FALSE)
            Wait(1)
            Goto(100)
        EndIf
    Else
        IfEq(NPC_KoopaTroopa_03_DonePanic, FALSE)
            Wait(1)
            Goto(100)
        EndIf
    EndIf
    Wait(10)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, FALSE)
    Call(GetSelfNpcID, LVar0)
    IfEq(LVar0, 1)
        Call(SetNpcSpeed, NPC_SELF, Float(3.0))
        Call(NpcMoveTo, NPC_SELF, 190, 20, 0)
        Call(NpcMoveTo, NPC_SELF, 245, 75, 0)
    Else
        Call(SetNpcSpeed, NPC_SELF, Float(3.6))
        Call(NpcMoveTo, NPC_SELF, 210, -20, 0)
        Call(NpcMoveTo, NPC_SELF, 260, 25, 0)
    EndIf
    Call(SetNpcSpeed, NPC_SELF, Float(1.5))
    Call(N(SetNewWanderCenterPos))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_KoopaTroopa_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaTroopa_02) = {
    IfLt(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_KoopaTroopa_02)))
        Call(SetNpcAnimation, NPC_SELF, ANIM_KoopaTroopa_Floating)
    Else
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
        Call(GetSelfNpcID, LVar0)
        IfEq(LVar0, 1)
            Call(SetNpcPos, NPC_SELF, 240, 220, 130)
        Else
            Call(SetNpcPos, NPC_SELF, 80, 220, 265)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcDefeat_KoopaTroopa_01) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GF_TRD01_Defeated_KoopaGuard, TRUE)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
            Call(MakeItemEntity, ITEM_KOOPA_FORTRESS_KEY, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, GF_TRD01_Item_FortressKey)
            Exec(N(EVS_FocusCamOnLock))
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaTroopa_01) = {
    IfEq(GF_TRD01_Defeated_KoopaGuard, TRUE)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_KoopaTroopa_01)))
    Return
    End
};

NpcData N(NpcData_KoopaTroopa_01) = {
    .id = NPC_KoopaTroopa_01,
    .pos = { 260.0f, 0.0f, 30.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 260, 0, 40 },
            .wanderSize = { 30, 25 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 260, 0, 40 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_KoopaTroopa_01),
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_KoopaTroopa_02) = {
    .id = NPC_KoopaTroopa_02,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 240, 220, 130 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 240, 220, 130 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_KoopaTroopa_02),
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = KOOPA_TROOPA_TRD_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_KoopaTroopa_03) = {
    .id = NPC_KoopaTroopa_03,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 80, 220, 265 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 80, 220, 265 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_KoopaTroopa_02),
    .settings = &N(NpcSettings_KoopaTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = KOOPA_TROOPA_TRD_DROPS,
    .animations = KOOPA_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Bobomb) = {
    .id = NPC_Bobomb,
    .pos = { -255.0f, 640.0f, 35.0f },
    .yaw = 180,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -255, 640, 35 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -255, 640, 35 },
            .detectSize = { 100 },
        }
    },
    .settings = &N(NpcSettings_Bobomb_Guard),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = BOBOMB_DROPS,
    .animations = BOBOMB_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_KoopaTroopa_01), BTL_TRD_1_FORMATION_03, BTL_TRD_1_STAGE_02),
    NPC_GROUP(N(NpcData_KoopaTroopa_02), BTL_TRD_1_FORMATION_01, BTL_TRD_1_STAGE_07),
    NPC_GROUP(N(NpcData_KoopaTroopa_03), BTL_TRD_1_FORMATION_00, BTL_TRD_1_STAGE_07),
    NPC_GROUP(N(NpcData_Bobomb), BTL_TRD_1_FORMATION_10, BTL_TRD_1_STAGE_07),
    {}
};
