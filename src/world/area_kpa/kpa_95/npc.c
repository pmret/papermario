#include "kpa_95.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Penguin.inc.c"

#include "world/common/enemy/Koopatrol_Patrol.inc.c"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    Set(LVar0, MSG_CH8_0064)
    Set(LVar8, MSG_CH8_0065)
    Set(LVar1, MSG_CH8_0066)
    Set(LVar2, MSG_CH8_0067)
    Set(LVar3, MSG_CH8_0068)
    Return
    End
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    Call(SetMusic, 0, SONG_TAKING_REST, 0, VOL_LEVEL_FULL)
    Thread
        Wait(20)
        Call(N(ToadHouse_CamSetFOV), 0, 40)
        Call(SetCamType, CAM_DEFAULT, 4, false)
        Call(SetCamPitch, CAM_DEFAULT, 34, -8)
        Call(SetCamDistance, CAM_DEFAULT, 220)
        Call(SetCamPosA, CAM_DEFAULT, Float(-3.0), Float(-240.0))
        Call(SetCamPosB, CAM_DEFAULT, Float(-150.0), Float(-56.0))
        Call(SetCamPosC, CAM_DEFAULT, 1, 10)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, -180, -100, 0)
    Call(InterpPlayerYaw, 191, 1)
    Call(SetPlayerPos, -160, 22, -123)
    Wait(5)
    Call(InterpPlayerYaw, 114, 1)
    Call(HidePlayerShadow, true)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_2000 | IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    Wait(61)
    Call(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    Thread
        Wait(63)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Return
    End
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    Call(N(ToadHouse_CamSetFOV), 0, 25)
    Call(UseSettingsFrom, CAM_DEFAULT, MV_LastPlayerPosX, MV_LastPlayerPosY, MV_LastPlayerPosZ)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetPanTarget, CAM_DEFAULT, MV_LastPlayerPosX, MV_LastPlayerPosY, MV_LastPlayerPosZ)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(HidePlayerShadow, false)
    Call(SetPlayerPos, -139, 0, -90)
    Call(PlayerMoveTo, -102, -130, 20)
    Exec(N(EVS_SetupMusic))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    Call(GetPlayerPos, MV_LastPlayerPosX, MV_LastPlayerPosY, MV_LastPlayerPosZ)
    ExecWait(N(EVS_NpcInteract_ToadHouseKeeper))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    Switch(AB_KPA95_Toad2_Dialogue)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_CH8_0069)
            Set(AB_KPA95_Toad2_Dialogue, 1)
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Blue_Talk, ANIM_Toad_Blue_Idle, 0, MSG_CH8_006A)
            Set(AB_KPA95_Toad2_Dialogue, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_ToadGuard) = {
    Switch(AB_KPA95_Toad3_Dialogue)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Green_Talk, ANIM_ToadGuard_Green_Idle, 0, MSG_CH8_006B)
            Set(AB_KPA95_Toad3_Dialogue, 1)
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Green_Talk, ANIM_ToadGuard_Green_Idle, 0, MSG_CH8_006C)
            Set(AB_KPA95_Toad3_Dialogue, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin) = {
    Switch(AB_KPA95_Penguin_Dialogue)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH8_006D)
            Set(AB_KPA95_Penguin_Dialogue, 1)
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH8_006E)
            Set(AB_KPA95_Penguin_Dialogue, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_01)))
    Call(SetNpcPos, NPC_SELF, -70, 0, -140)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad_02)))
    Call(SetNpcPos, NPC_SELF, 100, 0, -90)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Toad_Blue_Idle)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadGuard) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadGuard)))
    Call(SetNpcPos, NPC_SELF, 30, 0, -170)
    Call(SetNpcAnimation, NPC_SELF, ANIM_ToadGuard_Green_Idle)
    Call(InterpNpcYaw, NPC_SELF, 270, 0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin)))
    Call(SetNpcPos, NPC_SELF, 170, 0, -180)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Return
    End
};

NpcData N(NpcData_Prisoners)[] = {
    {
        .id = NPC_Toad_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Toad_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = BASE_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_KPA_ToadHouseToadB,
    },
    {
        .id = NPC_Toad_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Toad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = BASE_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadD,
    },
    {
        .id = NPC_ToadGuard,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_ToadGuard),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = BASE_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_RED_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveSoldierC,
    },
    {
        .id = NPC_Penguin,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Penguin),
        .settings = &N(NpcSettings_Penguin),
        .flags = BASE_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptivePenguin,
    },
};

EvtScript N(EVS_NpcDefeat_Koopatrol) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GF_KPA95_Defeated_Guard, true)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(MakeItemEntity, ITEM_PRISON_KEY, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, GF_KPA95_Item_PrisonKey1)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_FLED)
        CaseEq(OUTCOME_ENEMY_FLED)
            Set(GF_KPA95_Defeated_Guard, true)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Call(MakeItemEntity, ITEM_PRISON_KEY, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, GF_KPA95_Item_PrisonKey1)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, true)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Koopatrol) = {
    IfEq(GF_KPA95_Defeated_Guard, false)
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Koopatrol)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_Koopatrol) = {
    .id = NPC_Koopatrol,
    .pos = { -70.0f, 0.0f, 55.0f },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { -70, 0, 55 },
                { -140, 0, 55 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -70, 0, 55 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_Koopatrol),
    .settings = &N(NpcSettings_Koopatrol_Patrol),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = KOOPATROL_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Prisoners)),
    NPC_GROUP(N(NpcData_Koopatrol), BTL_KPA_FORMATION_17, BTL_KPA_STAGE_0D),
    {}
};
