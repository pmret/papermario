#include "hos_03.h"
#include "sprite/player.h"

#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/StarSpirit_Wander.inc.c"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouseHos.data.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

EvtScript N(EVS_NpcInteract_StarKid_01) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_HOS_005F)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid_01) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_StarKid_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_StarKid_02) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_HOS_0060)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_StarKid_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_StarKid_03) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_HOS_0061)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_StarKid_03)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_StarKid_04) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_HOS_0062)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_StarKid_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_StarKid_05) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_HOS_0063)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_StarKid_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_StarKid_05)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_EXEC(N(EVS_PlayRestingSong))
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 34, -8)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 220)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(448.0), EVT_FLOAT(180.0))
        EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(410.0), EVT_FLOAT(150.0))
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 25)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(func_802D1270, 442, 140, EVT_FLOAT(3.0))
    EVT_CALL(InterpPlayerYaw, 191, 1)
    EVT_WAIT(5)
    EVT_CALL(InterpPlayerYaw, 204, 1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    EVT_WAIT(61)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EVT_THREAD
        EVT_WAIT(70)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(N(ToadHouse_CamSetFOV), 0, 25)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetPlayerPos, 445, 25, 185)
    EVT_CALL(PlayerMoveTo, 440, 215, 20)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    EVT_SET(LVar0, MSG_HOS_0064)
    EVT_SET(LVar8, MSG_HOS_0065)
    EVT_SET(LVar1, MSG_HOS_0066)
    EVT_SET(LVar2, MSG_HOS_0067)
    EVT_SET(LVar3, MSG_HOS_0068)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ToadHouseKeeper) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ToadHouseKeeper)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_ShopOwner) = {
    EVT_EXEC_WAIT(EVS_ShopOwnerDialog)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShopOwner) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_ShopOwner)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Townsfolk)[] = {
    {
        .id = NPC_StarMan_01,
        .pos = { -463.0f, 10.0f, 400.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_StarKid_01),
        .settings = &N(NpcSettings_StarMan),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = STAR_MAN_ANIMS,
        .tattle = MSG_NpcTattle_HOS_StarKidA,
    },
    {
        .id = NPC_StarMan_02,
        .pos = { -325.0f, 10.0f, 600.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_StarKid_02),
        .settings = &N(NpcSettings_StarMan),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = STAR_MAN_ANIMS,
        .tattle = MSG_NpcTattle_HOS_StarKidB,
    },
    {
        .id = NPC_StarMan_03,
        .pos = { 0.0f, 10.0f, 300.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 10, 300 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 10, 300 },
                .detectSize = { 30 },
            }
        },
        .init = &N(EVS_NpcInit_StarKid_03),
        .settings = &N(NpcSettings_StarMan_Wander),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = STAR_MAN_ANIMS,
        .tattle = MSG_NpcTattle_HOS_StarKidC,
    },
    {
        .id = NPC_StarMan_04,
        .pos = { 250.0f, 10.0f, 500.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 250, 10, 500 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 250, 10, 500 },
                .detectSize = { 30 },
            }
        },
        .init = &N(EVS_NpcInit_StarKid_04),
        .settings = &N(NpcSettings_StarMan_Wander),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = STAR_MAN_ANIMS,
        .tattle = MSG_NpcTattle_HOS_StarKidD,
    },
    {
        .id = NPC_StarMan_05,
        .pos = { -485.0f, 335.0f, -100.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_StarKid_05),
        .settings = &N(NpcSettings_StarMan),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = STAR_MAN_ANIMS,
        .tattle = MSG_NpcTattle_HOS_StarKidE,
    },
    {
        .id = NPC_StarMan_ToadHouse,
        .pos = { 458.0f, 35.0f, 233.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ToadHouseKeeper),
        .settings = &N(NpcSettings_StarMan),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = STAR_MAN_ANIMS,
        .tattle = MSG_NpcTattle_HOS_ToadHouseStarKid,
    },
    {
        .id = NPC_StarMan_ShopOwner,
        .pos = { 140.0f, 285.0f, -315.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShopOwner),
        .settings = &N(NpcSettings_StarMan),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = STAR_MAN_ANIMS,
        .tattle = MSG_NpcTattle_HOS_ShopOwner,
    },
    {
        .id = NPC_ChuckQuizmo,
        .pos = { -200.0f, 0.0f, 400.0f },
        .yaw = 90,
        .initVarCount = 1,
        .initVar = { .bytes = { 0, QUIZ_AREA_HOS, QUIZ_COUNT_HOS, QUIZ_MAP_HOS_03 }},
        .settings = &N(NpcSettings_ChuckQuizmo),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = QUIZMO_ANIMS,
        .tattle = MSG_NpcTattle_ChuckQuizmo,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Townsfolk)),
    {}
};
