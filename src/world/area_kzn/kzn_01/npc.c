#include "kzn_01.h"

#include "world/common/enemy/PutridPiranhaSentinel.inc.c"

EvtScript N(EVS_NpcIdle_PutridPiranha) = {
    Label(0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, 225)
        Wait(1)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, true)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, 270, -200, 0)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SetNpcPos, NPC_SELF, 320, -220, 0)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim17)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim01)
    Call(SpeakToPlayer, NPC_SELF, ANIM_LargePiranha_Putrid_Anim04, ANIM_LargePiranha_Putrid_Anim01, 0, MSG_CH5_00ED)
    Wait(10 * DT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_DIG, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim18)
    Wait(25 * DT)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(ResetCam, CAM_DEFAULT, Float(3.0 / DT))
    Set(GF_KZN01_IntruderAlert, true)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_NpcInit_PutridPiranha) = {
    IfEq(GF_KZN01_IntruderAlert, false)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_PutridPiranha)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcPutridPiranha) = {
    .id = NPC_PutridPiranha,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_PutridPiranha),
    .settings = &N(NpcSettings_PutridPiranhaSentinel),
    .flags = ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = PIRANHA_NO_DROPS,
    .animations = PIRANHA_SENTINEL_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcPutridPiranha)),
    {}
};
