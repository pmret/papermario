#include "obk_04.h"
#include "effects.h"

#include "world/common/complete/GiveReward.inc.c"

API_CALLABLE(N(func_80240A58_BC88B8)) {
    Npc* npc1 = get_npc_unsafe(NPC_Boo_02);
    Npc* npc2 = get_npc_unsafe(NPC_Boo_03);
    Npc* npc3 = get_npc_unsafe(NPC_Boo_04);
    Npc* npc4 = get_npc_unsafe(NPC_Boo_05);
    Npc* npc5 = get_npc_unsafe(NPC_Boo_06);
    Npc* npc6 = get_npc_unsafe(NPC_Boo_07);
    Npc* npc7 = get_npc_unsafe(NPC_Boo_08);
    Npc* npc8 = get_npc_unsafe(NPC_Boo_09);

    switch (script->varTable[0]) {
        case 0:
            script->varTable[0] = npc1->yaw;
            evt_set_variable(NULL, MV_Unk_05, NPC_Boo_02);
            break;
        case 1:
            script->varTable[0] = npc2->yaw;
            evt_set_variable(NULL, MV_Unk_05, NPC_Boo_03);
            break;
        case 2:
            script->varTable[0] = npc3->yaw;
            evt_set_variable(NULL, MV_Unk_05, NPC_Boo_04);
            break;
        case 3:
            script->varTable[0] = npc4->yaw;
            evt_set_variable(NULL, MV_Unk_05, NPC_Boo_05);
            break;
        case 4:
            script->varTable[0] = npc5->yaw;
            evt_set_variable(NULL, MV_Unk_05, NPC_Boo_06);
            break;
        case 5:
            script->varTable[0] = npc6->yaw;
            evt_set_variable(NULL, MV_Unk_05, NPC_Boo_07);
            break;
        case 6:
            script->varTable[0] = npc7->yaw;
            evt_set_variable(NULL, MV_Unk_05, NPC_Boo_08);
            break;
        case 7:
            script->varTable[0] = npc8->yaw;
            evt_set_variable(NULL, MV_Unk_05, NPC_Boo_09);
            break;
    }
    script->varTable[0] += script->varTable[1];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240C10_BC8A70)) {
    Npc npc;

    npc.pos.x = 0;
    npc.pos.y = 0.0f;
    npc.pos.z = 0.0f;
    npc.planarFlyDist = 125.0f;
    npc_move_heading(&npc, 125.0f, script->varTable[0]);
    script->varTable[0] = npc.pos.x;
    script->varTable[1] = npc.pos.y + 10.0f;
    script->varTable[2] = npc.pos.z + 20.0f;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240CA0_BC8B00)) {
    Npc* npc = get_npc_unsafe(evt_get_variable(NULL, MV_Unk_05));

    script->varTable[0] = npc->pos.x;
    script->varTable[1] = npc->pos.y;
    script->varTable[2] = npc->pos.z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240D00_BC8B60)) {
    gPlayerData.bootsLevel = 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240D14_BC8B74)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc npc;
    f32 dist = dist2D(playerStatus->position.x, playerStatus->position.z, 0.0f, 0.0f);
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

    if ((gt | lt) != 0) {
        yaw = atan2(playerStatus->position.x, playerStatus->position.z, 0.0f, 0.0f) + 180.0f;
        npc.pos.x = 0.0f;
        npc.pos.y = 0.0f;
        npc.pos.z = 0.0f;
        npc_move_heading(&npc, 80.0f, yaw);
        script->varTable[0] = npc.pos.x;
        script->varTable[1] = npc.pos.y;
        script->varTable[2] = npc.pos.z;
        script->varTable[3] = 1;
    } else {
        script->varTable[0] = playerStatus->position.x;
        script->varTable[1] = playerStatus->position.y;
        script->varTable[2] = playerStatus->position.z;
        script->varTable[3] = 0;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240E58_BC8CB8)) {
    if (get_npc_unsafe(NPC_Boo_02)->duration == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(D_80243A74_BCB8D4) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Boo_11, LVar0, LVar1, LVar2)
        EVT_CALL(SetItemPos, MV_Unk_00, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243ADC_BCB93C) = {
    EVT_CALL(N(func_80240E58_BC8CB8))
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(MakeLerp, 255, 0, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetItemAlpha, MV_Unk_00, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LOOP(20)
        EVT_CALL(GetNpcPos, NPC_Boo_02, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_Boo_11, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Boo_11, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243C04_BCBA64) = {
    EVT_SWITCH(MV_Unk_05)
        EVT_CASE_EQ(0)
            EVT_SET(MV_Unk_07, 0)
        EVT_CASE_EQ(1)
            EVT_SET(MV_Unk_07, 1)
        EVT_CASE_EQ(2)
            EVT_SET(MV_Unk_07, 2)
        EVT_CASE_EQ(3)
            EVT_SET(MV_Unk_07, 3)
        EVT_CASE_EQ(4)
            EVT_SET(MV_Unk_07, 4)
        EVT_CASE_EQ(5)
            EVT_SET(MV_Unk_07, 5)
        EVT_CASE_EQ(6)
            EVT_SET(MV_Unk_07, 6)
        EVT_CASE_EQ(7)
            EVT_SET(MV_Unk_07, 7)
        EVT_CASE_EQ(8)
            EVT_SET(MV_Unk_07, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243D24_BCBB84) = {
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, 0, 255, 60, EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(func_802CFD30, LVarA, 7, LVar0, 0, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243DC8_BCBC28) = {
    EVT_CALL(SetNpcFlagBits, LVarA, NPC_FLAG_40000, FALSE)
    EVT_CALL(NpcFacePlayer, LVarA, 0)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, LVarA, ANIM_Boo_Spook)
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, 255, 0, 60, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CFD30, LVarA, 7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetNpcPos, LVarA, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243ED4_BCBD34) = {
    EVT_THREAD
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(8.0), 0, EVT_FLOAT(300.0), EVT_FLOAT(17.5), EVT_FLOAT(-9.5))
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_6000C)
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
        EVT_IF_EQ(MF_Unk_0A, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(func_802D7B44, LVar8)
    EVT_CALL(RemoveItemEntity, LVarC)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_THREAD
        EVT_CALL(ResetCam, CAM_DEFAULT, 3)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BoosUnleashed) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_BOO_MINIGAME, 0, 8)
    EVT_EXEC(N(D_80243A74_BCB8D4))
    EVT_WAIT(1)
    EVT_EXEC(N(D_80243ADC_BCB93C))
    EVT_SET(MV_Unk_01, 1)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002B)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(400.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_WAIT(60)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(325.0), EVT_FLOAT(13.0), EVT_FLOAT(-13.0))
    EVT_CALL(SetNpcPos, NPC_Boo_10, 0, 45, 20)
    EVT_CALL(SetNpcPos, NPC_Boo_11, 0, 65, 0)
    EVT_CALL(MakeLerp, 0, 255, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CFD30, 9, 7, LVar0, 0, 0, 0)
        EVT_CALL(SetItemAlpha, MV_Unk_00, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SpeakToPlayer, NPC_Boo_10, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_003A)
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(450.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(SpeakToPlayer, NPC_Boo_10, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_003B)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MV_Unk_02, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(MV_Unk_09, 0)
    EVT_LABEL(100)
    EVT_ADD(MV_Unk_09, 1)
    EVT_IF_GE(MV_Unk_09, 10)
        EVT_SET(MV_Unk_09, 10)
    EVT_END_IF
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(500.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_WAIT(20)
    // choose which boo will have the boots
    EVT_CALL(RandInt, 7, LVar0)
    EVT_SET(MV_Unk_04, LVar0)
    EVT_SET(LVar1, 30)
    EVT_CALL(N(func_80240A58_BC88B8))
    EVT_CALL(N(func_80240C10_BC8A70))
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_11, SOUND_THROW, 0)
    EVT_CALL(SetNpcJumpscale, NPC_Boo_11, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_Boo_11, LVar0, LVar1, LVar2, 14)
    EVT_CALL(SetNpcPos, NPC_Boo_11, NPC_DISPOSE_LOCATION)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(MakeLerp, 255, 0, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CFD30, 9, 7, LVar0, 0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(RandInt, 4, MV_Unk_08)
    EVT_ADD(MV_Unk_08, 6)
    EVT_LOOP(0)
        EVT_CALL(N(func_80240CA0_BC8B00))
        EVT_CALL(SetNpcPos, NPC_Boo_11, LVar0, LVar1, LVar2)
        EVT_CALL(RandInt, 7, LVar0)
        EVT_IF_EQ(MV_Unk_04, LVar0)
            EVT_ADD(LVar0, 4)
            EVT_IF_GE(LVar0, 8)
                EVT_SUB(LVar0, 8)
            EVT_END_IF
        EVT_END_IF
        EVT_SET(MV_Unk_04, LVar0)
        EVT_SET(LVar1, 30)
        EVT_CALL(N(func_80240A58_BC88B8))
        EVT_CALL(N(func_80240C10_BC8A70))
        EVT_CALL(PlaySoundAtNpc, NPC_Boo_11, SOUND_THROW, 0)
        EVT_CALL(SetNpcJumpscale, NPC_Boo_11, EVT_FLOAT(1.5))
        EVT_CALL(NpcJump0, NPC_Boo_11, LVar0, LVar1, LVar2, 14)
        EVT_CALL(SetNpcPos, NPC_Boo_11, NPC_DISPOSE_LOCATION)
        EVT_CALL(RandInt, 10, LVar0)
        EVT_ADD(LVar0, 5)
        EVT_WAIT(LVar0)
        EVT_ADD(MV_Unk_08, -1)
        EVT_IF_EQ(MV_Unk_08, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(MV_Unk_03, 3)
    EVT_CALL(RandInt, 50, LVar0)
    EVT_ADD(LVar0, 100)
    EVT_WAIT(LVar0)
    EVT_CALL(MakeLerp, 0, 255, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(func_802CFD30, 9, 7, LVar0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SpeakToPlayer, NPC_Boo_10, ANIM_Boo_Talk, ANIM_Boo_Idle, 5, MSG_CH3_003C)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_NE(MV_Unk_06, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(MV_Unk_03, 1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(MV_Unk_06, 2)
        EVT_WAIT(20)
        EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(2.0), 0, 0, 0, EVT_FLOAT(450.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
        EVT_WAIT(30)
        EVT_EXEC_WAIT(N(D_80243C04_BCBA64))
        EVT_CALL(GetNpcPos, MV_Unk_07, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_Boo_11, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcPos, NPC_Boo_11, LVar3, LVar4, LVar5)
        EVT_SET(LVar6, 25)
        EVT_ADD(LVar6, LVar4)
        EVT_CALL(MakeLerp, LVar4, LVar6, 20, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_Boo_11, LVar3, LVar0, LVar5)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SpeakToPlayer, MV_Unk_07, ANIM_Boo_Talk, ANIM_Boo_Idle, 5, MSG_CH3_003E)
        EVT_CALL(PlaySoundAtNpc, NPC_Boo_11, SOUND_THROW, 0)
        EVT_CALL(SetNpcJumpscale, NPC_Boo_11, EVT_FLOAT(2.0))
        EVT_CALL(NpcJump0, NPC_Boo_11, 0, 65, 0, 10)
        EVT_CALL(SpeakToPlayer, NPC_Boo_10, ANIM_Boo_Talk, ANIM_Boo_Idle, 5, MSG_CH3_003B)
        EVT_SET(MV_Unk_06, 0)
        EVT_SET(MV_Unk_03, 0)
        EVT_CALL(N(func_80240D14_BC8B74))
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
    EVT_EXEC_WAIT(N(D_80243C04_BCBA64))
    EVT_CALL(GetNpcPos, MV_Unk_07, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetNpcPos, NPC_Boo_11, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_CALL(PlaySoundAtNpc, NPC_Boo_11, SOUND_THROW, 0)
    EVT_CALL(SetNpcJumpscale, NPC_Boo_11, EVT_FLOAT(2.0))
    EVT_CALL(NpcJump0, NPC_Boo_11, LVar0, LVar1, LVar2, 10)
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_Boo_11, NPC_DISPOSE_LOCATION)
    EVT_WAIT(1)
    EVT_SET(MF_Unk_0A, FALSE)
    EVT_EXEC(N(EVS_PlayUpgradeSong))
    EVT_EXEC(N(D_80243ED4_BCBD34))
    EVT_CALL(N(func_80240D00_BC8B60))
    EVT_WAIT(30)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0180, 160, 40)
    EVT_SET(MF_Unk_0A, TRUE)
    EVT_WAIT(30)
    EVT_CALL(N(func_80240D14_BC8B74))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
    EVT_CALL(PlayerMoveTo, LVar0, LVar2, 0)
    EVT_WAIT(20)
    EVT_CALL(GetNpcPos, NPC_Boo_10, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Boo_10, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_003D)
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
    EVT_SET(LVarA, 1)
    EVT_EXEC(N(D_80243DC8_BCBC28))
    EVT_SET(LVarA, 2)
    EVT_EXEC(N(D_80243DC8_BCBC28))
    EVT_SET(LVarA, 3)
    EVT_EXEC(N(D_80243DC8_BCBC28))
    EVT_SET(LVarA, 4)
    EVT_EXEC(N(D_80243DC8_BCBC28))
    EVT_SET(LVarA, 5)
    EVT_EXEC(N(D_80243DC8_BCBC28))
    EVT_SET(LVarA, 6)
    EVT_EXEC(N(D_80243DC8_BCBC28))
    EVT_SET(LVarA, 7)
    EVT_EXEC(N(D_80243DC8_BCBC28))
    EVT_SET(LVarA, 8)
    EVT_EXEC(N(D_80243DC8_BCBC28))
    EVT_SET(LVarA, 9)
    EVT_EXEC(N(D_80243DC8_BCBC28))
    EVT_WAIT(60)
    EVT_CALL(SetNpcPos, NPC_Boo_12, -160, 10, -175)
    EVT_CALL(func_802CFD30, 11, 7, 0, 0, 0, 0)
    EVT_SET(LVarA, 11)
    EVT_EXEC(N(D_80243D24_BCBB84))
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
