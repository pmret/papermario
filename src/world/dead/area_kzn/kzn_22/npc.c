#include "kzn_22.h"
#include "sprite/player.h"

API_CALLABLE(N(GetFloorCollider2)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.curFloor);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_8024036C_C9A56C)) {
    snd_ambient_fade_out(0, true);
    return ApiStatus_DONE2;
}

#include "world/common/npc/Kolorado.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_ShakeScreen) = {
    Loop(0)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.5))
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    Exec(N(EVS_ShakeScreen))
    Label(0)
        // wait for player to reach top of stairs
        Call(N(GetFloorCollider2), LVar0)
        IfNe(LVar0, COLLIDER_o544)
            Wait(1)
            Goto(0)
        EndIf
    // start scene (but wait for player to stop being hurt if they fell in the lava)
    Call(DisablePlayerInput, true)
    Call(GetPlayerAnimation, LVar0)
    IfEq(LVar0, ANIM_MarioW2_Thrown)
        Wait(35)
    EndIf
    Wait(10)
EndIf //@bug unmatched endif
    Call(PlayerFaceNpc, NPC_Kolorado, false)
    Set(AF_KZN23_SceneStarted, true)
    Thread
        Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        // repeatedly jump for the treasure chest
        Label(1)
            Call(SetNpcJumpscale, NPC_SELF, Float(2.0))
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15)
            IfEq(AF_KZN23_GrabbedKolorado, false)
                Wait(1)
                Goto(1)
            EndIf
    EndThread
    Wait(10)
    Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-4.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(480.0), Float(299.6))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Call(SetPlayerSpeed, Float(3.0))
        Call(PlayerMoveTo, 250, 210, 0)
    EndThread
    Wait(20)
    Call(ShowMessageAtWorldPos, MSG_CH5_0116, 440, 240, 165)
    Wait(20)
    Set(AF_KZN23_MessageClosed, true)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado)))
    Return
    End
};

Vec3f N(FlightPath1)[] = {
    { 300.0, 178.0, 120.0 },
    { 320.0, 170.0, 165.0 },
    { 340.0, 162.0, 200.0 },
    { 385.0, 155.0, 240.0 },
    { 435.0, 160.0, 255.0 },
    { 450.0, 165.0, 225.0 },
    { 440.0, 172.0, 195.0 },
};

Vec3f N(FlightPath2)[] = {
    { 445.0, 180.00, 120.0 },
    { 405.0, 190.00,  80.0 },
    { 360.0, 195.00,  70.0 },
    { 340.0, 200.00,  90.0 },
    { 315.0, 190.00, 110.0 },
    { 295.0, 180.00, 180.0 },
    { 270.0, 175.00, 230.0 },
    { 255.0, 170.00, 210.0 },
};

Vec3f N(FlightPath3)[] = {
    { 255.0, 171.0, 175.0 },
    { 260.0, 173.0, 160.0 },
    { 270.0, 175.0, 150.0 },
    { 290.0, 178.0, 142.0 },
    { 304.0, 182.0, 135.0 },
    { 330.0, 185.0, 145.0 },
    { 350.0, 190.0, 155.0 },
    { 368.0, 235.0, 170.0 },
    { 368.0, 295.0, 170.0 },
};

EvtScript N(EVS_ControlCamera) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 400, 150, 200)
    Call(SetPanTarget, CAM_DEFAULT, 400, 150, 200)
    Call(SetCamDistance, CAM_DEFAULT, Float(390.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Label(10)
        Wait(1)
        IfEq(AF_KZN23_GrabbedKolorado, false)
            Goto(10)
        EndIf
    Call(SetPanTarget, CAM_DEFAULT, 300, 150, 170)
    Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.3))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Label(20)
        Wait(1)
        IfEq(AF_KZN22_FlewAway, false)
            Goto(20)
        EndIf
    Call(SetPanTarget, CAM_DEFAULT, 368, 310, 170)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.8))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_SetCharacterPositions) = {
    Call(SetNpcPos, NPC_Misstar, LVar4, LVar2, LVar3)
    Add(LVar4, 10)
    Sub(LVar3, 5)
    Call(SetNpcPos, NPC_Kolorado, LVar4, LVar2, LVar3)
    IfEq(AF_KZN23_GrabbedPlayer, true)
        Sub(LVar4, 20)
        Add(LVar3, 10)
        Call(SetPlayerPos, LVar4, LVar2, LVar3)
        Add(LVar2, 20)
        Add(LVar3, -5)
        Call(SetNpcPos, NPC_PARTNER, LVar4, LVar2, LVar3)
    EndIf
    Return
    End
};

EvtScript N(EVS_Scene_Misstar) = {
    Loop(0)
        Wait(1)
        IfNe(AF_KZN23_MessageClosed, false)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerPhysics, true)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Call(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Exec(N(EVS_ControlCamera))
    Call(SetNpcJumpscale, NPC_SELF, Float(3.0))
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
    Wait(5)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Call(LoadPath, 35, Ref(N(FlightPath1)), ARRAY_COUNT(N(FlightPath1)), EASING_LINEAR)
    Label(10)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(10)
        EndIf
    Set(AF_KZN23_GrabbedKolorado, true)
    Call(SetNpcRotationPivot, NPC_Kolorado, 10)
    Call(SetNpcRotation, NPC_Kolorado, 0, 0, 180)
    Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Panic)
    Thread
        Wait(32)
        Call(SetPlayerJumpscale, 0)
        Call(PlayerJump, 245, 171, 176, 8)
    EndThread
    Thread
        Wait(32)
        Call(SetNpcJumpscale, NPC_PARTNER, 0)
        Call(NpcJump0, NPC_PARTNER, 245, 191, 171, 8)
    EndThread
    Call(InterpNpcYaw, NPC_SELF, 270, 0)
    Call(LoadPath, 40, Ref(N(FlightPath2)), ARRAY_COUNT(N(FlightPath2)), EASING_LINEAR)
    Label(20)
        Call(GetNextPathPos)
        Set(LVar4, LVar1)
        ExecWait(N(EVS_SetCharacterPositions))
        IfEq(LVar0, 1)
            Goto(20)
        EndIf
    Set(AF_KZN23_GrabbedPlayer, true)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_MarioW2_Carried)
    Thread
        Wait(25)
        Set(AF_KZN22_FlewAway, true)
        Call(N(func_8024036C_C9A56C))
    EndThread
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Call(LoadPath, 70, Ref(N(FlightPath3)), ARRAY_COUNT(N(FlightPath3)), EASING_LINEAR)
    Label(21)
        Call(GetNextPathPos)
        Set(LVar4, LVar1)
        ExecWait(N(EVS_SetCharacterPositions))
        IfEq(LVar0, 1)
            Goto(21)
        EndIf
    Wait(1)
    Call(MakeLerp, 300, 500, 20, EASING_CUBIC_IN)
    Call(GetNpcPos, NPC_SELF, LVar5, LVar2, LVar6)
    Loop(0)
        Call(UpdateLerp)
        Set(LVar4, LVar5)
        Set(LVar2, LVar0)
        Set(LVar3, LVar6)
        ExecWait(N(EVS_SetCharacterPositions))
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(GotoMap, Ref("kzn_23"), kzn_23_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_NpcInit_Misstar) = {
    Call(SetNpcPos, NPC_SELF, 300, 180, 80)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_IdleAngry)
    Set(AF_KZN23_SceneStarted, false)
    Set(AF_KZN23_MessageClosed, false)
    Set(AF_KZN23_GrabbedKolorado, false)
    Set(AF_KZN23_GrabbedPlayer, false)
    Set(AF_KZN22_FlewAway, false)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_Misstar)))
    Return
    End
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { 445.0f, 150.0f, 175.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_RAYCAST_TO_INTERACT | ENEMY_FLAG_SKIP_BATTLE,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_Misstar) = {
    .id = NPC_Misstar,
    .pos = { 285.0f, 160.0f, 80.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Misstar),
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_RAYCAST_TO_INTERACT | ENEMY_FLAG_SKIP_BATTLE,
    .drops = NO_DROPS,
    .animations = MISSTAR_ANIMS,
    .tattle = MSG_NpcTattle_Misstar,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Misstar)),
    {}
};
