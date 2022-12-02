#include "mac_04.h"

#define NAME_SUFFIX _Wish
#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/GoombaFamily.inc.c"
#include "world/common/npc/StarSpirit.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_Scene_WishingToadKid) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -100, 0, 200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -100, 0, 200)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(-400.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(6.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_WishingToadKid, ANIM_ToadKid_Red_Talk, ANIM_ToadKid_Red_Disappointed, 0, MSG_HOS_0070)
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR("hos_20"), hos_20_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_WishingToadKid) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -100, 0, 200)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_WishSceneToads)[] = {
    {
        .id = NPC_WishingToadKid,
        .settings = &N(NpcSettings_Toad_Stationary_Wish),
        .pos = { 350.0f, 0.0f, -20.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000 | ENEMY_FLAGS_400000,
        .init = &N(EVS_NpcInit_WishingToadKid),
        .drops = TOAD_KID_DROPS,
        .animations = TOAD_KID_RED_ANIMS,
    },
    {
        .id = NPC_Toad_04,
        .settings = &N(NpcSettings_Toad_Stationary_Wish),
        .pos = { -245.0f, 20.0f, 100.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8,
        .drops = TOAD_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioA,
    },
    {
        .id = NPC_Toad_05,
        .settings = &N(NpcSettings_Toad_Stationary_Wish),
        .pos = { -25.0f, 0.0f, 170.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8,
        .drops = TOAD_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioB,
    },
    {
        .id = NPC_Toad_06,
        .settings = &N(NpcSettings_Toad_Stationary_Wish),
        .pos = { -100.0f, 0.0f, 305.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_8,
        .drops = TOAD_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioC,
    },
};

NpcGroupList N(WishSceneNPCs) = {
    NPC_GROUP(N(NpcData_WishSceneToads)),
    {}
};
