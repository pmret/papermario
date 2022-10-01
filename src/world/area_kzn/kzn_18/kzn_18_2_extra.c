#include "kzn_18.h"
#include "entity.h"

#include "world/common/SetCamera0Flag1000.inc.c"

#include "world/common/UnsetCamera0Flag1000.inc.c"

#include "world/common/GetFloorCollider.inc.c"

NpcSettings N(NpcSettings_Kolorado) = {
    .height = 40,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Piranha) = {
    .height = 30,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Unused1) = {
    .height = 23,
    .radius = 19,
    .level = 99,
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_KOLORADO_RAN_AHEAD)
        EVT_LABEL(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar0, -125)
                EVT_WAIT(1)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_SET(GB_StoryProgress, STORY_CH5_KOLORADO_RAN_AHEAD)
        EVT_CALL(SetNpcPos, NPC_SELF, -280, 250, -360)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar2, -340)
            EVT_SET(LVar2, -320)
        EVT_ELSE
            EVT_SET(LVar2, -360)
        EVT_END_IF
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(10.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, 185, LVar2, 0)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 4)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 185, 250, -340)
        EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(N(GetFloorCollider), LVar0)
        EVT_IF_EQ(LVar0, COLLIDER_o442)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_IF_EQ(LVar0, COLLIDER_o405)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00FD)
    EVT_WAIT(15)
    EVT_SET(MV_KoloradoJumpDone, FALSE)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
        EVT_CALL(SetNpcYaw, NPC_SELF, 90)
        EVT_SET(MV_KoloradoJumpDone, TRUE)
    EVT_END_THREAD
    EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00FE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MV_KoloradoJumpDone, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 420, 250, -350)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 530, -360, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_WAIT(15)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_SET(GB_StoryProgress, STORY_CH5_KOLORADO_IN_TREASURE_ROOM)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_KOLORADO_IN_TREASURE_ROOM)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Piranha) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar1, 100)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_IF_LT(LVar0, 100)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(SetCamera0Flag1000))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 285, 25, 35)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_SELF, 285, 25, 35)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim17)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim01)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LargePiranha_Putrid_Anim04, ANIM_LargePiranha_Putrid_Anim01, 0, MSG_CH5_00FF)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_DIG, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim18)
    EVT_WAIT(25)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(N(UnsetCamera0Flag1000))
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_SET(GF_KZN18_IntruderAlert, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Piranha) = {
    EVT_IF_EQ(GF_KZN18_IntruderAlert, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Piranha)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .settings = &N(NpcSettings_Kolorado),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_MOTION_BLUR,
    .init = &N(EVS_NpcInit_Kolorado),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Kolorado_Idle,
        .walk   = ANIM_Kolorado_Walk,
        .run    = ANIM_Kolorado_Run,
        .chase  = ANIM_Kolorado_Run,
        .anim_4 = ANIM_Kolorado_Idle,
        .anim_5 = ANIM_Kolorado_Idle,
        .death  = ANIM_Kolorado_Idle,
        .hit    = ANIM_Kolorado_Idle,
        .anim_8 = ANIM_Kolorado_Idle,
        .anim_9 = ANIM_Kolorado_Idle,
        .anim_A = ANIM_Kolorado_Idle,
        .anim_B = ANIM_Kolorado_Idle,
        .anim_C = ANIM_Kolorado_Idle,
        .anim_D = ANIM_Kolorado_Idle,
        .anim_E = ANIM_Kolorado_Idle,
        .anim_F = ANIM_Kolorado_Idle,
    },
    .tattle = MSG_NpcTattle_Kolorado,
};

StaticNpc N(NpcData_Piranha) = {
    .id = NPC_PutridPiranha,
    .settings = &N(NpcSettings_Piranha),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = NPC_FLAG_4 | NPC_FLAG_200000,
    .init = &N(EVS_NpcInit_Piranha),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_FIRE_FLOWER, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(3),
        .minCoinBonus = 0,
        .maxCoinBonus = 2,
    },
    .animations = {
        .idle   = ANIM_LargePiranha_Putrid_Anim01,
        .walk   = ANIM_LargePiranha_Putrid_Anim02,
        .run    = ANIM_LargePiranha_Putrid_Anim03,
        .chase  = ANIM_LargePiranha_Putrid_Anim03,
        .anim_4 = ANIM_LargePiranha_Putrid_Anim01,
        .anim_5 = ANIM_LargePiranha_Putrid_Anim01,
        .death  = ANIM_LargePiranha_Putrid_Anim0E,
        .hit    = ANIM_LargePiranha_Putrid_Anim0E,
        .anim_8 = ANIM_LargePiranha_Putrid_Anim18,
        .anim_9 = ANIM_LargePiranha_Putrid_Anim17,
        .anim_A = ANIM_LargePiranha_Putrid_Anim05,
        .anim_B = ANIM_LargePiranha_Putrid_Anim06,
        .anim_C = ANIM_LargePiranha_Putrid_Anim07,
        .anim_D = ANIM_LargePiranha_Putrid_Anim01,
        .anim_E = ANIM_LargePiranha_Putrid_Anim01,
        .anim_F = ANIM_LargePiranha_Putrid_Anim01,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Piranha)),
    {}
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 250, 250, -225, 0, MODEL_o380, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_KZN18_HiddenPanel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -420, 85, -80, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 350, 310, -250, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
