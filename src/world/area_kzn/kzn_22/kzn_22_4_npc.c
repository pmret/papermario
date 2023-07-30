#include "kzn_22.h"
#include "sprite/player.h"

API_CALLABLE(N(GetFloorCollider2)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gCollisionStatus.curFloor);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_8024036C_C9A56C)) {
    snd_ambient_mute(0, TRUE);
    return ApiStatus_DONE2;
}

#include "world/common/npc/Kolorado.inc.c"
#include "world/common/npc/StarSpirit.inc.c"

EvtScript N(EVS_ShakeScreen) = {
    EVT_LOOP(0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.5))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_EXEC(N(EVS_ShakeScreen))
    EVT_LABEL(0)
        // wait for player to reach top of stairs
        EVT_CALL(N(GetFloorCollider2), LVar0)
        EVT_IF_NE(LVar0, COLLIDER_o544)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    // start scene (but wait for player to stop being hurt if they fell in the lava)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPlayerAnimation, LVar0)
    EVT_IF_EQ(LVar0, ANIM_MarioW2_Thrown)
        EVT_WAIT(35)
    EVT_END_IF
    EVT_WAIT(10)
EVT_END_IF //@bug unmatched endif
    EVT_CALL(PlayerFaceNpc, NPC_Kolorado, FALSE)
    EVT_SET(AF_KZN23_SceneStarted, TRUE)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        // repeatedly jump for the treasure chest
        EVT_LABEL(1)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.0))
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
            EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15)
            EVT_IF_EQ(AF_KZN23_GrabbedKolorado, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-4.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(480.0), EVT_FLOAT(299.6))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, 250, 210, 0)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(ShowMessageAtWorldPos, MSG_CH5_0116, 440, 240, 165)
    EVT_WAIT(20)
    EVT_SET(AF_KZN23_MessageClosed, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
    EVT_RETURN
    EVT_END
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
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 400, 150, 200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 400, 150, 200)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(390.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_LABEL(10)
        EVT_WAIT(1)
        EVT_IF_EQ(AF_KZN23_GrabbedKolorado, FALSE)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 300, 150, 170)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.3))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_LABEL(20)
        EVT_WAIT(1)
        EVT_IF_EQ(AF_KZN22_FlewAway, FALSE)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 368, 310, 170)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetCharacterPositions) = {
    EVT_CALL(SetNpcPos, NPC_Misstar, LVar4, LVar2, LVar3)
    EVT_ADD(LVar4, 10)
    EVT_SUB(LVar3, 5)
    EVT_CALL(SetNpcPos, NPC_Kolorado, LVar4, LVar2, LVar3)
    EVT_IF_EQ(AF_KZN23_GrabbedPlayer, TRUE)
        EVT_SUB(LVar4, 20)
        EVT_ADD(LVar3, 10)
        EVT_CALL(SetPlayerPos, LVar4, LVar2, LVar3)
        EVT_ADD(LVar2, 20)
        EVT_ADD(LVar3, -5)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar4, LVar2, LVar3)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Misstar) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_NE(AF_KZN23_MessageClosed, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_EXEC(N(EVS_ControlCamera))
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(3.0))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
    EVT_WAIT(5)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(LoadPath, 35, EVT_PTR(N(FlightPath1)), ARRAY_COUNT(N(FlightPath1)), EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_SET(AF_KZN23_GrabbedKolorado, TRUE)
    EVT_CALL(SetNpcRotationPivot, NPC_Kolorado, 10)
    EVT_CALL(SetNpcRotation, NPC_Kolorado, 0, 0, 180)
    EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Panic)
    EVT_THREAD
        EVT_WAIT(32)
        EVT_CALL(SetPlayerJumpscale, 0)
        EVT_CALL(PlayerJump, 245, 171, 176, 8)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(32)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, 0)
        EVT_CALL(NpcJump0, NPC_PARTNER, 245, 191, 171, 8)
    EVT_END_THREAD
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_CALL(LoadPath, 40, EVT_PTR(N(FlightPath2)), ARRAY_COUNT(N(FlightPath2)), EASING_LINEAR)
    EVT_LABEL(20)
        EVT_CALL(GetNextPathPos)
        EVT_SET(LVar4, LVar1)
        EVT_EXEC_WAIT(N(EVS_SetCharacterPositions))
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_SET(AF_KZN23_GrabbedPlayer, TRUE)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Carried)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_SET(AF_KZN22_FlewAway, TRUE)
        EVT_CALL(N(func_8024036C_C9A56C))
    EVT_END_THREAD
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(LoadPath, 70, EVT_PTR(N(FlightPath3)), ARRAY_COUNT(N(FlightPath3)), EASING_LINEAR)
    EVT_LABEL(21)
        EVT_CALL(GetNextPathPos)
        EVT_SET(LVar4, LVar1)
        EVT_EXEC_WAIT(N(EVS_SetCharacterPositions))
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(21)
        EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(MakeLerp, 300, 500, 20, EASING_CUBIC_IN)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar5, LVar2, LVar6)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar4, LVar5)
        EVT_SET(LVar2, LVar0)
        EVT_SET(LVar3, LVar6)
        EVT_EXEC_WAIT(N(EVS_SetCharacterPositions))
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GotoMap, EVT_PTR("kzn_23"), kzn_23_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Misstar) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 300, 180, 80)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_IdleAngry)
    EVT_SET(AF_KZN23_SceneStarted, FALSE)
    EVT_SET(AF_KZN23_MessageClosed, FALSE)
    EVT_SET(AF_KZN23_GrabbedKolorado, FALSE)
    EVT_SET(AF_KZN23_GrabbedPlayer, FALSE)
    EVT_SET(AF_KZN22_FlewAway, FALSE)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_Misstar)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { 445.0f, 150.0f, 175.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
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
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
    .drops = NO_DROPS,
    .animations = MISSTAR_ANIMS,
    .tattle = MSG_NpcTattle_Misstar,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Misstar)),
    {}
};
