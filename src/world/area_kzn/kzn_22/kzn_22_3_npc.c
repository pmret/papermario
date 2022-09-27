#include "kzn_22.h"

ApiStatus N(GetFloorCollider2)(Evt* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    evt_set_variable(script, *script->ptrReadPos, collisionStatus->currentFloor);
    return ApiStatus_DONE2;
}

ApiStatus N(func_8024036C_C9A56C)(Evt* script, s32 isInitialCall) {
    snd_ambient_80055618(0, 1);
    return ApiStatus_DONE2;
}

NpcSettings N(D_80240F20_C9B120) = {
    .height = 40,
    .radius = 24,
    .level = 99,
};

NpcSettings N(D_80240F4C_C9B14C) = {
    .height = 26,
    .radius = 24,
    .level = 99,
};

NpcSettings N(80240F78) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

NpcSettings N(80240FA4) = {
    .height = 22,
    .radius = 24,
    .level = 99,
};

EvtScript N(D_80240FD0_C9B1D0) = {
    EVT_LOOP(0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.5))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241010_C9B210) = {
    EVT_EXEC(N(D_80240FD0_C9B1D0))
    EVT_LABEL(0)
        EVT_CALL(N(GetFloorCollider2), LVar0)
        EVT_IF_NE(LVar0, 14)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPlayerAnimation, LVar0)
    EVT_IF_EQ(LVar0, ANIM_Mario_8001A)
        EVT_WAIT(35)
    EVT_END_IF
    EVT_WAIT(10)
EVT_END_IF //@bug unmatched endif
    EVT_CALL(PlayerFaceNpc, NPC_Kolorado, FALSE)
    EVT_SET(AF_KZN_0C, TRUE)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_LABEL(1)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.0))
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
            EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15)
            EVT_IF_EQ(AF_KZN_0E, FALSE)
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
    EVT_SET(AF_KZN_0D, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024131C_C9B51C) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, N(D_80241010_C9B210))
    EVT_RETURN
    EVT_END
};

Vec3f N(D_80241340_C9B540)[] = {
    { 300.0, 178.0, 120.0 },
    { 320.0, 170.0, 165.0 },
    { 340.0, 162.0, 200.0 },
    { 385.0, 155.0, 240.0 },
    { 435.0, 160.0, 255.0 },
    { 450.0, 165.0, 225.0 },
    { 440.0, 172.0, 195.0 },
};

Vec3f N(D_80241394_C9B594)[] = {
    { 445.0, 180.00, 120.0 },
    { 405.0, 190.00,  80.0 },
    { 360.0, 195.00,  70.0 },
    { 340.0, 200.00,  90.0 },
    { 315.0, 190.00, 110.0 },
    { 295.0, 180.00, 180.0 },
    { 270.0, 175.00, 230.0 },
    { 255.0, 170.00, 210.0 },
};

Vec3f N(D_802413F4_C9B5F4)[] = {
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

EvtScript N(D_80241460_C9B660) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 400, 150, 200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 400, 150, 200)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(390.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_IF_EQ(AF_KZN_0E, FALSE)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 300, 150, 170)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.3))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_LABEL(20)
    EVT_WAIT(1)
    EVT_IF_EQ(AF_KZN_10, FALSE)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 368, 310, 170)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241648_C9B848) = {
    EVT_CALL(SetNpcPos, NPC_Misstar, LVar4, LVar2, LVar3)
    EVT_ADD(LVar4, 10)
    EVT_SUB(LVar3, 5)
    EVT_CALL(SetNpcPos, NPC_Kolorado, LVar4, LVar2, LVar3)
    EVT_IF_EQ(AF_KZN_0F, TRUE)
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

EvtScript N(D_8024173C_C9B93C) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_NE(AF_KZN_0D, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, 512, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, 256, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Kolorado, 256, TRUE)
    EVT_EXEC(N(D_80241460_C9B660))
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(3.0))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
    EVT_WAIT(5)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(LoadPath, 35, N(D_80241340_C9B540), 7, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(GetNextPathPos)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(AF_KZN_0E, TRUE)
    EVT_CALL(func_802CDE68, 0, 10)
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
    EVT_CALL(LoadPath, 40, N(D_80241394_C9B594), 8, EASING_LINEAR)
    EVT_LABEL(20)
    EVT_CALL(GetNextPathPos)
    EVT_SET(LVar4, LVar1)
    EVT_EXEC_WAIT(N(D_80241648_C9B848))
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_SET(AF_KZN_0F, TRUE)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80000)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_SET(AF_KZN_10, TRUE)
        EVT_CALL(N(func_8024036C_C9A56C))
    EVT_END_THREAD
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(LoadPath, 70, N(D_802413F4_C9B5F4), 9, EASING_LINEAR)
    EVT_LABEL(21)
    EVT_CALL(GetNextPathPos)
    EVT_SET(LVar4, LVar1)
    EVT_EXEC_WAIT(N(D_80241648_C9B848))
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
        EVT_EXEC_WAIT(N(D_80241648_C9B848))
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GotoMap, "kzn_23", kzn_23_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241C3C_C9BE3C) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 300, 180, 80)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldMisstar_IdleAngry)
    EVT_SET(AF_KZN_0C, FALSE)
    EVT_SET(AF_KZN_0D, FALSE)
    EVT_SET(AF_KZN_0E, FALSE)
    EVT_SET(AF_KZN_0F, FALSE)
    EVT_SET(AF_KZN_10, FALSE)
    EVT_CALL(BindNpcIdle, NPC_SELF, N(D_8024173C_C9B93C))
    EVT_RETURN
    EVT_END
};

StaticNpc N(D_80241CE0_C9BEE0) = {
    .id = NPC_Kolorado,
    .settings = &N(D_80240F20_C9B120),
    .pos = { 445.0f, 150.0f, 175.0f },
    .yaw = 90,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_MOTION_BLUR,
    .init = &N(D_8024131C_C9B51C),
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

StaticNpc N(D_80241ED0_C9C0D0) = {
    .id = NPC_Misstar,
    .settings = &N(D_80240F4C_C9B14C),
    .pos = { 285.0f, 160.0f, 80.0f },
    .yaw = 270,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_MOTION_BLUR,
    .init = &N(D_80241C3C_C9BE3C),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldMisstar_Idle,
        .walk   = ANIM_WorldMisstar_Idle,
        .run    = ANIM_WorldMisstar_Idle,
        .chase  = ANIM_WorldMisstar_Idle,
        .anim_4 = ANIM_WorldMisstar_Idle,
        .anim_5 = ANIM_WorldMisstar_Idle,
        .death  = ANIM_WorldMisstar_Idle,
        .hit    = ANIM_WorldMisstar_Idle,
        .anim_8 = ANIM_WorldMisstar_Still,
        .anim_9 = ANIM_WorldMisstar_Idle,
        .anim_A = ANIM_WorldMisstar_Idle,
        .anim_B = ANIM_WorldMisstar_Idle,
        .anim_C = ANIM_WorldMisstar_Idle,
        .anim_D = ANIM_WorldMisstar_Idle,
        .anim_E = ANIM_WorldMisstar_Idle,
        .anim_F = ANIM_WorldMisstar_Idle,
    },
    .tattle = MSG_NpcTattle_Misstar,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(D_80241CE0_C9BEE0)),
    NPC_GROUP(N(D_80241ED0_C9C0D0)),
    {}
};
