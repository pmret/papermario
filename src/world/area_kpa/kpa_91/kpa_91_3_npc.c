#include "kpa_91.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Dryite_Stationary.inc.c"
#include "world/common/enemy/Koopatrol_Patrol.inc.c"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    EVT_SET(LVar0, MSG_CH8_0044)
    EVT_SET(LVar8, MSG_CH8_0045)
    EVT_SET(LVar1, MSG_CH8_0046)
    EVT_SET(LVar2, MSG_CH8_0047)
    EVT_SET(LVar3, MSG_CH8_0048)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_CALL(SetMusicTrack, 0, SONG_TAKING_REST, 0, 8)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 34, -8)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 220)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-3.0), EVT_FLOAT(-240.0))
        EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-150.0), EVT_FLOAT(-56.0))
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 1, 10)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -180, -100, 0)
    EVT_CALL(InterpPlayerYaw, 191, 1)
    EVT_CALL(SetPlayerPos, -160, 22, -123)
    EVT_WAIT(5)
    EVT_CALL(InterpPlayerYaw, 114, 1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_2000 | IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    EVT_WAIT(61)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EVT_THREAD
        EVT_WAIT(63)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    EVT_CALL(N(ToadHouse_CamSetFOV), 0, 25)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, MV_LastPlayerPosX, MV_LastPlayerPosY, MV_LastPlayerPosZ)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, MV_LastPlayerPosX, MV_LastPlayerPosY, MV_LastPlayerPosZ)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(SetPlayerPos, -139, 0, -90)
    EVT_CALL(PlayerMoveTo, -102, -130, 20)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_01) = {
    EVT_CALL(GetPlayerPos, MV_LastPlayerPosX, MV_LastPlayerPosY, MV_LastPlayerPosZ)
    EVT_EXEC_WAIT(N(EVS_NpcInteract_ToadHouseKeeper))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toad_02) = {
    EVT_SWITCH(AB_KPA91_Toad2_Dialogue)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_CH8_0049)
            EVT_SET(AB_KPA91_Toad2_Dialogue, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Toad_Yellow_Talk, ANIM_Toad_Yellow_Idle, 0, MSG_CH8_004A)
            EVT_SET(AB_KPA91_Toad2_Dialogue, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ToadGuard) = {
    EVT_SWITCH(AB_KPA91_Toad3_Dialogue)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Blue_Talk, ANIM_ToadGuard_Blue_Idle, 0, MSG_CH8_004B)
            EVT_SET(AB_KPA91_Toad3_Dialogue, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ToadGuard_Blue_Talk, ANIM_ToadGuard_Blue_Idle, 0, MSG_CH8_004C)
            EVT_SET(AB_KPA91_Toad3_Dialogue, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Dryite) = {
    EVT_SWITCH(AB_KPA91_Dryite_Dialogue)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH8_004D)
            EVT_SET(AB_KPA91_Dryite_Dialogue, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Dryite_Green_Talk, ANIM_Dryite_Green_Idle, 0, MSG_CH8_004E)
            EVT_SET(AB_KPA91_Dryite_Dialogue, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_01)))
    EVT_CALL(SetNpcPos, NPC_SELF, -70, 0, -140)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toad_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toad_02)))
    EVT_CALL(SetNpcPos, NPC_SELF, 110, 0, -130)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Toad_Yellow_Idle)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadGuard) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadGuard)))
    EVT_CALL(SetNpcPos, NPC_SELF, 10, 0, -180)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ToadGuard_Blue_Idle)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Dryite) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Dryite)))
    EVT_CALL(SetNpcPos, NPC_SELF, 175, 0, -65)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Prisoners)[] = {
    {
        .id = NPC_Toad_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Toad_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_KPA_ToadHouseToadA,
    },
    {
        .id = NPC_Toad_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Toad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadC,
    },
    {
        .id = NPC_ToadGuard,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_ToadGuard),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = TOAD_GUARD_RED_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveSoldierB,
    },
    {
        .id = NPC_Dryite,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Dryite),
        .settings = &N(NpcSettings_Dryite),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = DRYITE_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveDryite,
    },
};

EvtScript N(EVS_NpcDefeat_Koopatrol) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_KPA91_Defeated_Guard, TRUE)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(MakeItemEntity, ITEM_PRISON_KEY1, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, GF_KPA91_Item_PrisonKey1)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_SET(GF_KPA91_Defeated_Guard, TRUE)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(MakeItemEntity, ITEM_PRISON_KEY1, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, GF_KPA91_Item_PrisonKey1)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol) = {
    EVT_IF_EQ(GF_KPA91_Defeated_Guard, FALSE)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Koopatrol)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Koopatrol) = {
    .id = NPC_Koopatrol,
    .pos = { 60.0f, 0.0f, 55.0f },
    .yaw = 270,
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 60, 0, 55 },
                { 140, 0, 55 },
            },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 60, 0, 55 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_Koopatrol),
    .settings = &N(NpcSettings_Koopatrol_Patrol),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = KOOPATROL_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Prisoners)),
    NPC_GROUP(N(NpcData_Koopatrol), BTL_KPA_FORMATION_17, BTL_KPA_STAGE_0D),
    {}
};
