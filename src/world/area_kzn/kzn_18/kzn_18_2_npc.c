#include "kzn_18.h"

#include "world/common/npc/Kolorado.inc.c"
#include "world/common/enemy/PutridPiranhaSentinel.inc.c"

#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"
#include "world/common/todo/GetFloorCollider.inc.c"

EvtScript N(EVS_NpcIdle_Kolorado) = {
    IfLt(GB_StoryProgress, STORY_CH5_KOLORADO_RAN_AHEAD)
        Label(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            IfLt(LVar0, -125)
                Wait(1)
                Goto(0)
            EndIf
        Set(GB_StoryProgress, STORY_CH5_KOLORADO_RAN_AHEAD)
        Call(SetNpcPos, NPC_SELF, -280, 250, -360)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar2, -340)
            Set(LVar2, -320)
        Else
            Set(LVar2, -360)
        EndIf
        Call(SetNpcSpeed, NPC_SELF, Float(10.0 / DT))
        Call(NpcMoveTo, NPC_SELF, 185, LVar2, 0)
        Call(NpcFacePlayer, NPC_SELF, 4)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    Else
        Call(SetNpcPos, NPC_SELF, 185, 250, -340)
        Call(SetNpcYaw, NPC_SELF, 270)
    EndIf
    Loop(0)
        Wait(1)
        Call(N(GetFloorCollider), LVar0)
        IfEq(LVar0, COLLIDER_o442)
            BreakLoop
        EndIf
        IfEq(LVar0, COLLIDER_o405)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00FD)
    Wait(15 * DT)
    Set(MV_KoloradoJumpDone, FALSE)
    Thread
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(SetNpcJumpscale, NPC_SELF, Float(2.0))
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10 * DT)
        Call(SetNpcYaw, NPC_SELF, 90)
        Set(MV_KoloradoJumpDone, TRUE)
    EndThread
    Call(ContinueSpeech, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00FE)
    Loop(0)
        Wait(1)
        IfEq(MV_KoloradoJumpDone, TRUE)
            BreakLoop
        EndIf
    EndLoop
    Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetPanTarget, CAM_DEFAULT, 420, 250, -350)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    Call(SetNpcSpeed, NPC_SELF, Float(5.0 / DT))
    Call(NpcMoveTo, NPC_SELF, 530, -360, 0)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Wait(15 * DT)
    Call(ResetCam, CAM_DEFAULT, Float(3.0 / DT))
    Set(GB_StoryProgress, STORY_CH5_KOLORADO_IN_TREASURE_ROOM)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    IfLt(GB_StoryProgress, STORY_CH5_KOLORADO_IN_TREASURE_ROOM)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcIdle_Piranha) = {
    Label(0)
        Wait(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGt(LVar1, 100)
            Goto(0)
        EndIf
        IfLt(LVar0, 100)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Call(N(DisableCameraLeadingPlayer))
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, 285, 25, 35)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SetNpcPos, NPC_SELF, 285, 25, 35)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim17)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim01)
    Call(SpeakToPlayer, NPC_SELF, ANIM_LargePiranha_Putrid_Anim04, ANIM_LargePiranha_Putrid_Anim01, 0, MSG_CH5_00FF)
    Wait(10 * DT)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_DIG, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim18)
    Wait(25 * DT)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(N(EnableCameraLeadingPlayer))
    Call(ResetCam, CAM_DEFAULT, Float(3.0 / DT))
    Set(GF_KZN18_IntruderAlert, TRUE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Piranha) = {
    IfEq(GF_KZN18_IntruderAlert, FALSE)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Piranha)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
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
