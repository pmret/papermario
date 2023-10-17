#include "kzn_18.h"

#include "world/common/npc/Kolorado.inc.c"
#include "world/common/enemy/PutridPiranhaSentinel.inc.c"

#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"
#include "world/common/todo/GetFloorCollider.inc.c"

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
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(10.0 / DT))
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
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00FD)
    EVT_WAIT(15 * DT)
    EVT_SET(MV_KoloradoJumpDone, FALSE)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10 * DT)
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
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_SELF, 530, -360, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_WAIT(15 * DT)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
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
    EVT_CALL(N(DisableCameraLeadingPlayer))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 285, 25, 35)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_SELF, 285, 25, 35)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim17)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim01)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LargePiranha_Putrid_Anim04, ANIM_LargePiranha_Putrid_Anim01, 0, MSG_CH5_00FF)
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_DIG, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim18)
    EVT_WAIT(25 * DT)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(N(EnableCameraLeadingPlayer))
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
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

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_Piranha) = {
    .id = NPC_PutridPiranha,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Piranha),
    .settings = &N(NpcSettings_PutridPiranhaSentinel),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = PIRANHA_NO_DROPS,
    .animations = PIRANHA_SENTINEL_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Piranha)),
    {}
};
