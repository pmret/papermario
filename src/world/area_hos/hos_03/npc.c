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
    Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_HOS_005F)
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_StarKid_01)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_StarKid_02) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_HOS_0060)
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_StarKid_02)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_StarKid_03) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_HOS_0061)
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_StarKid_03)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_StarKid_04) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_HOS_0062)
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_StarKid_04)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_StarKid_05) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_StarMan_Talk, ANIM_StarMan_Idle, 0, MSG_HOS_0063)
    Return
    End
};

EvtScript N(EVS_NpcInit_StarKid_05) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_StarKid_05)))
    Return
    End
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    Exec(N(EVS_PlayRestingSong))
    Thread
        Wait(20)
        Call(N(ToadHouse_CamSetFOV), 0, 40)
        Call(SetCamType, CAM_DEFAULT, 4, false)
        Call(SetCamPitch, CAM_DEFAULT, 34, -8)
        Call(SetCamDistance, CAM_DEFAULT, 220)
        Call(SetCamPosA, CAM_DEFAULT, Float(448.0), Float(180.0))
        Call(SetCamPosB, CAM_DEFAULT, Float(410.0), Float(150.0))
        Call(SetCamPosC, CAM_DEFAULT, 0, 25)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
    EndThread
    Call(func_802D1270, 442, 140, Float(3.0))
    Call(InterpPlayerYaw, 191, 1)
    Wait(5)
    Call(InterpPlayerYaw, 204, 1)
    Call(HidePlayerShadow, true)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    Wait(61)
    Call(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    Thread
        Wait(70)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Call(PanToTarget, CAM_DEFAULT, 0, false)
    EndThread
    Return
    End
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    Exec(N(EVS_SetupMusic))
    Call(N(ToadHouse_CamSetFOV), 0, 25)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetPlayerPos, 445, 25, 185)
    Call(PlayerMoveTo, 440, 215, 20)
    Return
    End
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    Set(LVar0, MSG_HOS_0064)
    Set(LVar8, MSG_HOS_0065)
    Set(LVar1, MSG_HOS_0066)
    Set(LVar2, MSG_HOS_0067)
    Set(LVar3, MSG_HOS_0068)
    Return
    End
};

EvtScript N(EVS_NpcInit_ToadHouseKeeper) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadHouseKeeper)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_ShopOwner) = {
    ExecWait(EVS_ShopOwnerDialog)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShopOwner) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ShopOwner)))
    Return
    End
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
                .isFlying = true,
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
                .isFlying = true,
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
