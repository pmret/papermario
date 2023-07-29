#include "obk_04.h"
#include "effects.h"
#include "sprite/player.h"

// redundant, but useful for documentation
enum {
    KEEP_AWAY_BOO_0     = 0,
    KEEP_AWAY_BOO_1     = 1,
    KEEP_AWAY_BOO_2     = 2,
    KEEP_AWAY_BOO_3     = 3,
    KEEP_AWAY_BOO_4     = 4,
    KEEP_AWAY_BOO_5     = 5,
    KEEP_AWAY_BOO_6     = 6,
    KEEP_AWAY_BOO_7     = 7,
};

#include "world/common/complete/GiveReward.inc.c"

API_CALLABLE(N(GetKeepAwayCarrierYaw)) {
    Npc* npc1 = get_npc_unsafe(NPC_KeepAwayBoo1);
    Npc* npc2 = get_npc_unsafe(NPC_KeepAwayBoo2);
    Npc* npc3 = get_npc_unsafe(NPC_KeepAwayBoo3);
    Npc* npc4 = get_npc_unsafe(NPC_KeepAwayBoo4);
    Npc* npc5 = get_npc_unsafe(NPC_KeepAwayBoo5);
    Npc* npc6 = get_npc_unsafe(NPC_KeepAwayBoo6);
    Npc* npc7 = get_npc_unsafe(NPC_KeepAwayBoo7);
    Npc* npc8 = get_npc_unsafe(NPC_KeepAwayBoo8);

    switch (script->varTable[0]) {
        case KEEP_AWAY_BOO_0:
            script->varTable[0] = npc1->yaw;
            evt_set_variable(NULL, MV_ThrowTargetNpc, NPC_KeepAwayBoo1);
            break;
        case KEEP_AWAY_BOO_1:
            script->varTable[0] = npc2->yaw;
            evt_set_variable(NULL, MV_ThrowTargetNpc, NPC_KeepAwayBoo2);
            break;
        case KEEP_AWAY_BOO_2:
            script->varTable[0] = npc3->yaw;
            evt_set_variable(NULL, MV_ThrowTargetNpc, NPC_KeepAwayBoo3);
            break;
        case KEEP_AWAY_BOO_3:
            script->varTable[0] = npc4->yaw;
            evt_set_variable(NULL, MV_ThrowTargetNpc, NPC_KeepAwayBoo4);
            break;
        case KEEP_AWAY_BOO_4:
            script->varTable[0] = npc5->yaw;
            evt_set_variable(NULL, MV_ThrowTargetNpc, NPC_KeepAwayBoo5);
            break;
        case KEEP_AWAY_BOO_5:
            script->varTable[0] = npc6->yaw;
            evt_set_variable(NULL, MV_ThrowTargetNpc, NPC_KeepAwayBoo6);
            break;
        case KEEP_AWAY_BOO_6:
            script->varTable[0] = npc7->yaw;
            evt_set_variable(NULL, MV_ThrowTargetNpc, NPC_KeepAwayBoo7);
            break;
        case KEEP_AWAY_BOO_7:
            script->varTable[0] = npc8->yaw;
            evt_set_variable(NULL, MV_ThrowTargetNpc, NPC_KeepAwayBoo8);
            break;
    }
    script->varTable[0] += script->varTable[1];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetItemJumpDest)) {
    // create temporary NPC so we can use npc movement code to determine jump dest position
    Npc npc;

    npc.pos.x = 0.0f;
    npc.pos.y = 0.0f;
    npc.pos.z = 0.0f;
    npc.planarFlyDist = 125.0f;
    npc_move_heading(&npc, 125.0f, script->varTable[0]);
    script->varTable[0] = npc.pos.x;
    script->varTable[1] = npc.pos.y + 10.0f;
    script->varTable[2] = npc.pos.z + 20.0f;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetKeepAwayCarrierPos)) {
    Npc* npc = get_npc_unsafe(evt_get_variable(NULL, MV_ThrowTargetNpc));

    script->varTable[0] = npc->pos.x;
    script->varTable[1] = npc->pos.y;
    script->varTable[2] = npc->pos.z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpgradeBootsToSuper)) {
    gPlayerData.bootsLevel = 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetPlayerPosOutsideKeepAwayRing)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc npc;
    f32 dist = dist2D(playerStatus->pos.x, playerStatus->pos.z, 0.0f, 0.0f);
    f32 yaw;
    s32 gt, lt;

    if (!(dist > 90.0f)) {
        gt = FALSE;
    } else {
        gt = TRUE;
    }

    if (!(dist < 150.0f)) {
        lt = FALSE;
    } else {
        lt = TRUE;
    }

    if (gt | lt) {
        yaw = atan2(playerStatus->pos.x, playerStatus->pos.z, 0.0f, 0.0f) + 180.0f;
        npc.pos.x = 0.0f;
        npc.pos.y = 0.0f;
        npc.pos.z = 0.0f;
        npc_move_heading(&npc, 80.0f, yaw);
        script->varTable[0] = npc.pos.x;
        script->varTable[1] = npc.pos.y;
        script->varTable[2] = npc.pos.z;
        script->varTable[3] = 1;
    } else {
        script->varTable[0] = playerStatus->pos.x;
        script->varTable[1] = playerStatus->pos.y;
        script->varTable[2] = playerStatus->pos.z;
        script->varTable[3] = 0;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(WaitForFirstCarrier)) {
    if (get_npc_unsafe(NPC_KeepAwayBoo1)->duration == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_TetherItemToDummy) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_DummyBoo, LVar0, LVar1, LVar2)
        EVT_CALL(SetItemPos, MV_KeepAwayItem, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_IntroduceAndHideBoots) = {
    EVT_CALL(N(WaitForFirstCarrier))
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(MakeLerp, 255, 0, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetItemAlpha, MV_KeepAwayItem, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LOOP(20)
        EVT_CALL(GetNpcPos, NPC_KeepAwayBoo1, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_DummyBoo, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_DummyBoo, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

// useless
EvtScript N(EVS_DetermineCarrierNPC) = {
    EVT_SWITCH(MV_ThrowTargetNpc)
        EVT_CASE_EQ(NPC_Boo_01)
            EVT_SET(MV_ItemCarrierNpc, NPC_Boo_01)
        EVT_CASE_EQ(NPC_KeepAwayBoo1)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo1)
        EVT_CASE_EQ(NPC_KeepAwayBoo2)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo2)
        EVT_CASE_EQ(NPC_KeepAwayBoo3)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo3)
        EVT_CASE_EQ(NPC_KeepAwayBoo4)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo4)
        EVT_CASE_EQ(NPC_KeepAwayBoo5)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo5)
        EVT_CASE_EQ(NPC_KeepAwayBoo6)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo6)
        EVT_CASE_EQ(NPC_KeepAwayBoo7)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo7)
        EVT_CASE_EQ(NPC_KeepAwayBoo8)
            EVT_SET(MV_ItemCarrierNpc, NPC_KeepAwayBoo8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BooAppear) = {
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, 0, 255, 60, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, LVarA, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BooSpookAndVanish) = {
    EVT_CALL(SetNpcFlagBits, LVarA, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
    EVT_CALL(NpcFacePlayer, LVarA, 0)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, LVarA, ANIM_Boo_Spook)
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, 255, 0, 60, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, LVarA, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetNpcPos, LVarA, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowGotSuperBootsFX) = {
    EVT_THREAD
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(8.0), 0, EVT_FLOAT(300.0), EVT_FLOAT(17.5), EVT_FLOAT(-9.5))
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_Lift)
    EVT_CALL(GetPlayerPos, LVar5, LVar6, LVar7)
    EVT_ADD(LVar6, 40)
    EVT_CALL(MakeItemEntity, ITEM_SUPER_BOOTS, LVar5, LVar6, LVar7, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVarC, LVar0)
    EVT_ADD(LVar6, 16)
    EVT_PLAY_EFFECT(EFFECT_GOT_ITEM_OUTLINE, 0, LVar5, LVar6, LVar7, EVT_FLOAT(1.0), LVar8)
    EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 9, LVar5, LVar6, LVar7, EVT_FLOAT(1.0), 100)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
        EVT_ADD(LVar4, 50)
        EVT_ADD(LVar5, 2)
        EVT_ADD(LVar3, 8)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
        EVT_ADD(LVar3, -16)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MF_WaitForUpgradeDone, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DismissItemOutline, LVar8)
    EVT_CALL(RemoveItemEntity, LVarC)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_THREAD
        EVT_CALL(ResetCam, CAM_DEFAULT, 3)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BoosUnleashed) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_BOO_MINIGAME, 0, 8)
    EVT_EXEC(N(EVS_TetherItemToDummy))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_IntroduceAndHideBoots))
    EVT_SET(MV_KeepAwayStarted, TRUE)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(400.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_WAIT(60)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(325.0), EVT_FLOAT(13.0), EVT_FLOAT(-13.0))
    // have item appear with leader via dummy NPC
    EVT_CALL(SetNpcPos, NPC_LeaderBoo, 0, 45, 20)
    EVT_CALL(SetNpcPos, NPC_DummyBoo, 0, 65, 0)
    EVT_CALL(MakeLerp, 0, 255, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetItemAlpha, MV_KeepAwayItem, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    // explain the game
    EVT_CALL(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_003A)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(450.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_003B)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MV_Unk_02, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(MV_KeepAwayRound, 0)
    EVT_LABEL(100)
        EVT_ADD(MV_KeepAwayRound, 1)
        EVT_IF_GE(MV_KeepAwayRound, 10)
            EVT_SET(MV_KeepAwayRound, 10)
        EVT_END_IF
        EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(500.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
        EVT_WAIT(20)
        // first throw -- from leader
        // choose which boo will have the item next
        EVT_CALL(RandInt, KEEP_AWAY_BOO_7, LVar0)
        EVT_SET(MV_KeepAwayTarget, LVar0)
        // jump dummy to the location of that NPC
        EVT_SET(LVar1, 30)
        EVT_CALL(N(GetKeepAwayCarrierYaw))
        EVT_CALL(N(GetItemJumpDest))
        EVT_CALL(PlaySoundAtNpc, NPC_DummyBoo, SOUND_THROW, SOUND_SPACE_MODE_0)
        EVT_CALL(SetNpcJumpscale, NPC_DummyBoo, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_DummyBoo, LVar0, LVar1, LVar2, 14 * DT)
        EVT_CALL(SetNpcPos, NPC_DummyBoo, NPC_DISPOSE_LOCATION)
        EVT_WAIT(30 * DT)
        EVT_THREAD
            EVT_CALL(MakeLerp, 255, 0, 10, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        // throw between 4-10 times
        EVT_CALL(RandInt, 4, MV_KeepAwayThrows)
        EVT_ADD(MV_KeepAwayThrows, 6)
        EVT_LOOP(0)
            EVT_CALL(N(GetKeepAwayCarrierPos))
            // choose which boo will have the item next
            EVT_CALL(SetNpcPos, NPC_DummyBoo, LVar0, LVar1, LVar2)
            EVT_CALL(RandInt, KEEP_AWAY_BOO_7, LVar0)
            EVT_IF_EQ(MV_KeepAwayTarget, LVar0)
                EVT_ADD(LVar0, 4)
                EVT_IF_GE(LVar0, 8)
                    EVT_SUB(LVar0, 8)
                EVT_END_IF
            EVT_END_IF
            EVT_SET(MV_KeepAwayTarget, LVar0)
            // jump dummy to the location of that NPC
            EVT_SET(LVar1, 30)
            EVT_CALL(N(GetKeepAwayCarrierYaw))
            EVT_CALL(N(GetItemJumpDest))
            EVT_CALL(PlaySoundAtNpc, NPC_DummyBoo, SOUND_THROW, SOUND_SPACE_MODE_0)
            EVT_CALL(SetNpcJumpscale, NPC_DummyBoo, EVT_FLOAT(1.5))
            EVT_CALL(NpcJump0, NPC_DummyBoo, LVar0, LVar1, LVar2, 14 * DT)
            EVT_CALL(SetNpcPos, NPC_DummyBoo, NPC_DISPOSE_LOCATION)
            EVT_CALL(RandInt, 10 * DT, LVar0)
            EVT_ADD(LVar0, 5 * DT)
            EVT_WAIT(LVar0)
            EVT_ADD(MV_KeepAwayThrows, -1)
            EVT_IF_EQ(MV_KeepAwayThrows, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_SET(MV_KeepAwayMovement, KEEP_AWAY_SPIRAL)
        EVT_CALL(RandInt, 50, LVar0)
        EVT_ADD(LVar0, 100)
        EVT_WAIT(LVar0)
        EVT_CALL(MakeLerp, 0, 255, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 5, MSG_CH3_003C)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_IF_NE(MV_KeepAwayResult, KEEP_AWAY_WAITING)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_SET(MV_KeepAwayMovement, KEEP_AWAY_STOP)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_IF_EQ(MV_KeepAwayResult, KEEP_AWAY_WRONG)
            // player hit the wrong Boo, begin another round
            EVT_WAIT(20)
            EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(450.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
            EVT_WAIT(30)
            EVT_EXEC_WAIT(N(EVS_DetermineCarrierNPC))
            EVT_CALL(GetNpcPos, MV_ItemCarrierNpc, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcPos, NPC_DummyBoo, LVar0, LVar1, LVar2)
            EVT_CALL(GetNpcPos, NPC_DummyBoo, LVar3, LVar4, LVar5)
            EVT_SET(LVar6, 25)
            EVT_ADD(LVar6, LVar4)
            EVT_CALL(MakeLerp, LVar4, LVar6, 20, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcPos, NPC_DummyBoo, LVar3, LVar0, LVar5)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(SpeakToPlayer, MV_ItemCarrierNpc, ANIM_Boo_Talk, ANIM_Boo_Idle, 5, MSG_CH3_003E)
            EVT_CALL(PlaySoundAtNpc, NPC_DummyBoo, SOUND_THROW, SOUND_SPACE_MODE_0)
            EVT_CALL(SetNpcJumpscale, NPC_DummyBoo, EVT_FLOAT(2.0))
            EVT_CALL(NpcJump0, NPC_DummyBoo, 0, 65, 0, 10)
            EVT_CALL(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 5, MSG_CH3_003B)
            EVT_SET(MV_KeepAwayResult, KEEP_AWAY_WAITING)
            EVT_SET(MV_KeepAwayMovement, KEEP_AWAY_CLOCKWISE)
            EVT_CALL(N(GetPlayerPosOutsideKeepAwayRing))
            EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
            EVT_CALL(PlayerMoveTo, LVar0, LVar2, 0)
            EVT_WAIT(30)
            EVT_GOTO(100)
        EVT_END_IF
    EVT_LOOP(0)
        EVT_CALL(GetPlayerActionState, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, ACTION_STATE_IDLE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC_WAIT(N(EVS_DetermineCarrierNPC))
    EVT_CALL(GetNpcPos, MV_ItemCarrierNpc, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetNpcPos, NPC_DummyBoo, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_CALL(PlaySoundAtNpc, NPC_DummyBoo, SOUND_THROW, SOUND_SPACE_MODE_0)
    EVT_CALL(SetNpcJumpscale, NPC_DummyBoo, EVT_FLOAT(2.0))
    EVT_CALL(NpcJump0, NPC_DummyBoo, LVar0, LVar1, LVar2, 10)
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_DummyBoo, NPC_DISPOSE_LOCATION)
    EVT_WAIT(1)
    EVT_SET(MF_WaitForUpgradeDone, FALSE)
    EVT_EXEC(N(EVS_PlayUpgradeSong))
    EVT_EXEC(N(EVS_ShowGotSuperBootsFX))
    EVT_CALL(N(UpgradeBootsToSuper))
    EVT_WAIT(30)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0180, 160, 40)
    EVT_SET(MF_WaitForUpgradeDone, TRUE)
    EVT_WAIT(30)
    EVT_CALL(N(GetPlayerPosOutsideKeepAwayRing))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
    EVT_CALL(PlayerMoveTo, LVar0, LVar2, 0)
    EVT_WAIT(20)
    EVT_CALL(GetNpcPos, NPC_LeaderBoo, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_003D)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(PlaySound, SOUND_BOO_SPOOK)
    EVT_END_THREAD
    EVT_SET(LVarA, NPC_KeepAwayBoo1)
    EVT_EXEC(N(EVS_BooSpookAndVanish))
    EVT_SET(LVarA, NPC_KeepAwayBoo2)
    EVT_EXEC(N(EVS_BooSpookAndVanish))
    EVT_SET(LVarA, NPC_KeepAwayBoo3)
    EVT_EXEC(N(EVS_BooSpookAndVanish))
    EVT_SET(LVarA, NPC_KeepAwayBoo4)
    EVT_EXEC(N(EVS_BooSpookAndVanish))
    EVT_SET(LVarA, NPC_KeepAwayBoo5)
    EVT_EXEC(N(EVS_BooSpookAndVanish))
    EVT_SET(LVarA, NPC_KeepAwayBoo6)
    EVT_EXEC(N(EVS_BooSpookAndVanish))
    EVT_SET(LVarA, NPC_KeepAwayBoo7)
    EVT_EXEC(N(EVS_BooSpookAndVanish))
    EVT_SET(LVarA, NPC_KeepAwayBoo8)
    EVT_EXEC(N(EVS_BooSpookAndVanish))
    EVT_SET(LVarA, NPC_LeaderBoo)
    EVT_EXEC(N(EVS_BooSpookAndVanish))
    EVT_WAIT(60)
    EVT_CALL(SetNpcPos, NPC_TutorialBoo, -160, 10, -175)
    EVT_CALL(SetNpcImgFXParams, NPC_TutorialBoo, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    EVT_SET(LVarA, NPC_TutorialBoo)
    EVT_EXEC(N(EVS_BooAppear))
    EVT_WAIT(60)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_WAIT(20)
    EVT_SET(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
