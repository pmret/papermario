#include "mim_02.h"

EvtScript N(EVS_Unused_DoNothing) = {
    Return
    End
};

#include "world/common/npc/Oaklie.inc.c"

#include "world/common/enemy/ForestFuzzy_Wander.inc.c"

s32 N(KeyList)[] = {
    ITEM_FOREST_PASS,
    ITEM_NONE
};

#include "world/common/complete/KeyItemChoice.inc.c"

EvtScript N(EVS_NpcInteract_Oaklie) = {
    IfLt(GB_StoryProgress, STORY_CH3_INVITED_TO_BOOS_MANSION)
        Call(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0006)
        Return
    EndIf
    Call(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0007)
    Call(SetNpcFlagBits, NPC_Oaklie, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Wait(5 * DT)
    Thread
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
        Wait(15 * DT)
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
    EndThread
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, -426, 58, -70)
        Call(SetCamPitch, CAM_DEFAULT, Float(6.0), Float(-6.0))
        Call(SetCamDistance, CAM_DEFAULT, 250)
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Call(PlaySoundAtNpc, NPC_Oaklie, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(SetNpcJumpscale, NPC_Oaklie, Float(1.0))
    Call(NpcJump0, NPC_Oaklie, -426, 58, -70, 20 * DT)
    Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    Wait(5 * DT)
    Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Idle)
    Call(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0008)
    Wait(5 * DT)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
        Wait(15 * DT)
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
    EndThread
    Call(PlaySoundAtNpc, NPC_Oaklie, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_Oaklie, -333, 0, -81, 20 * DT)
    Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    Wait(5 * DT)
    Thread
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
        Wait(15 * DT)
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
    EndThread
    Call(PlaySoundAtNpc, NPC_Oaklie, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_Oaklie, -300, 0, -170, 15 * DT)
    Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    Wait(5 * DT)
    Thread
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
        Wait(15 * DT)
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
    EndThread
    Call(PlaySoundAtNpc, NPC_Oaklie, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_Oaklie, -226, 0, -245, 15 * DT)
    Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    Wait(5 * DT)
    Thread
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
        Wait(15 * DT)
        Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
    EndThread
    Call(PlaySoundAtNpc, NPC_Oaklie, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_Oaklie, -160, 0, -296, 15 * DT)
    Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
    Wait(5 * DT)
    Call(SetNpcPos, NPC_Oaklie, NPC_DISPOSE_LOCATION)
    Set(GB_StoryProgress, STORY_CH3_ALLOWED_INTO_FOREVER_FOREST)
    ExecWait(N(EVS_EnableWestGate))
    Return
    End
};

EvtScript N(EVS_NpcIdle_Oaklie) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH3_ALLOWED_INTO_FOREVER_FOREST)
            Call(DisablePlayerInput, TRUE)
            Wait(25)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamPitch, CAM_DEFAULT, Float(6.0), Float(-6.0))
            Call(SetCamDistance, CAM_DEFAULT, 300)
            Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
            Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0003)
            Wait(10 * DT)
            Thread
                Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Jump)
                Wait(5 * DT)
                Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Fall)
            EndThread
            Thread
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
                Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
            EndThread
            Call(PlaySoundAtNpc, NPC_Oaklie, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
            Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
            Call(NpcJump0, NPC_SELF, -455, 0, 0, 20 * DT)
            Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Land)
            Wait(5 * DT)
            Call(SetNpcAnimation, NPC_Oaklie, ANIM_Oaklie_Idle)
            Wait(15 * DT)
            IfLt(GB_StoryProgress, STORY_CH1_RETURNED_TO_TOAD_TOWN)
                Call(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0004)
            Else
                Call(SpeakToPlayer, NPC_Oaklie, ANIM_Oaklie_Talk, ANIM_Oaklie_Idle, 0, MSG_CH3_0005)
            EndIf
            Call(DisablePlayerInput, FALSE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Oaklie) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Oaklie)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Oaklie)))
    Switch(GB_StoryProgress)
        CaseGe(STORY_CH3_ALLOWED_INTO_FOREVER_FOREST)
            Call(SetNpcPos, NPC_Oaklie, NPC_DISPOSE_LOCATION)
    EndSwitch
    Return
    End
};

NpcData N(NpcData_Oaklie) = {
    .id = NPC_Oaklie,
    .pos = { -426.0f, 58.0f, -70.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Oaklie),
    .settings = &N(NpcSettings_Oaklie),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = OAKLIE_ANIMS,
    .tattle = MSG_NpcTattle_Oaklie,
};

NpcData N(NpcData_Fuzzy_01) = {
    .id = NPC_Fuzzy_01,
    .pos = { 300.0f, 0.0f, 130.0f },
    .yaw = 0,
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
    .settings = &N(NpcSettings_ForestFuzzy_Wander),
    .flags = 0,
    .drops = FOREST_FUZZY_DROPS,
    .animations = FOREST_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Fuzzy_02) = {
    .id = NPC_Fuzzy_02,
    .pos = { -100.0f, 0.0f, -320.0f },
    .yaw = 0,
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
    .settings = &N(NpcSettings_ForestFuzzy_Wander),
    .flags = 0,
    .drops = FOREST_FUZZY_DROPS,
    .animations = FOREST_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Oaklie)),
    NPC_GROUP(N(NpcData_Fuzzy_01), BTL_MIM_FORMATION_00, BTL_MIM_STAGE_00),
    NPC_GROUP(N(NpcData_Fuzzy_02), BTL_MIM_FORMATION_01, BTL_MIM_STAGE_00),
    {}
};
