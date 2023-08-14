#include "kzn_01.h"

#include "world/common/enemy/PutridPiranhaSentinel.inc.c"

EvtScript N(EVS_NpcIdle_PutridPiranha) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, 225)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 270, -200, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_SELF, 320, -220, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim17)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim01)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LargePiranha_Putrid_Anim04, ANIM_LargePiranha_Putrid_Anim01, 0, MSG_CH5_00ED)
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_DIG, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim18)
    EVT_WAIT(25 * DT)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_SET(GF_KZN01_IntruderAlert, TRUE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_PutridPiranha) = {
    EVT_IF_EQ(GF_KZN01_IntruderAlert, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_PutridPiranha)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcPutridPiranha) = {
    .id = NPC_PutridPiranha,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_PutridPiranha),
    .settings = &N(NpcSettings_PutridPiranhaSentinel),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = PIRANHA_NO_DROPS,
    .animations = PIRANHA_SENTINEL_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcPutridPiranha)),
    {}
};
