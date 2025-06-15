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
    Loop(0)
        Call(GetNpcPos, NPC_DummyBoo, LVar0, LVar1, LVar2)
        Call(SetItemPos, MV_KeepAwayItem, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_IntroduceAndHideBoots) = {
    Call(N(WaitForFirstCarrier))
    Thread
        Wait(10)
        Call(MakeLerp, 255, 0, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetItemAlpha, MV_KeepAwayItem, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Loop(20)
        Call(GetNpcPos, NPC_KeepAwayBoo1, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_DummyBoo, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetNpcPos, NPC_DummyBoo, NPC_DISPOSE_LOCATION)
    Return
    End
};

// useless
EvtScript N(EVS_DetermineCarrierNPC) = {
    Switch(MV_ThrowTargetNpc)
        CaseEq(NPC_Boo_01)
            Set(MV_ItemCarrierNpc, NPC_Boo_01)
        CaseEq(NPC_KeepAwayBoo1)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo1)
        CaseEq(NPC_KeepAwayBoo2)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo2)
        CaseEq(NPC_KeepAwayBoo3)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo3)
        CaseEq(NPC_KeepAwayBoo4)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo4)
        CaseEq(NPC_KeepAwayBoo5)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo5)
        CaseEq(NPC_KeepAwayBoo6)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo6)
        CaseEq(NPC_KeepAwayBoo7)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo7)
        CaseEq(NPC_KeepAwayBoo8)
            Set(MV_ItemCarrierNpc, NPC_KeepAwayBoo8)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_BooAppear) = {
    Wait(10)
    Call(MakeLerp, 0, 255, 60, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, LVarA, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_BooSpookAndVanish) = {
    Call(SetNpcFlagBits, LVarA, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
    Call(NpcFacePlayer, LVarA, 0)
    Wait(5)
    Call(SetNpcAnimation, LVarA, ANIM_Boo_Spook)
    Wait(10)
    Call(MakeLerp, 255, 0, 60, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, LVarA, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(SetNpcPos, LVarA, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_SpawnGotSuperBootsFX) = {
    Thread
        Call(AdjustCam, CAM_DEFAULT, Float(8.0), 0, Float(300.0), Float(17.5), Float(-9.5))
    EndThread
    Call(SetPlayerAnimation, ANIM_MarioW1_Lift)
    Call(GetPlayerPos, LVar5, LVar6, LVar7)
    Add(LVar6, 40)
    Call(MakeItemEntity, ITEM_SUPER_BOOTS, LVar5, LVar6, LVar7, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(LVarC, LVar0)
    Add(LVar6, 16)
    PlayEffect(EFFECT_GOT_ITEM_OUTLINE, 0, LVar5, LVar6, LVar7, Float(1.0), LVar8)
    PlayEffect(EFFECT_RADIAL_SHIMMER, 9, LVar5, LVar6, LVar7, Float(1.0), 100)
    Thread
        Wait(4)
        Call(GetPlayerPos, LVar3, LVar4, LVar5)
        Add(LVar4, 50)
        Add(LVar5, 2)
        Add(LVar3, 8)
        PlayEffect(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
        Add(LVar3, -16)
        PlayEffect(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
    EndThread
    Loop(0)
        Wait(1)
        IfEq(MF_WaitForUpgradeDone, TRUE)
            BreakLoop
        EndIf
    EndLoop
    Call(DismissItemOutline, LVar8)
    Call(RemoveItemEntity, LVarC)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Thread
        Call(ResetCam, CAM_DEFAULT, 3)
    EndThread
    Return
    End
};

EvtScript N(EVS_Scene_BoosUnleashed) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetMusic, 0, SONG_BOO_MINIGAME, 0, VOL_LEVEL_FULL)
    Exec(N(EVS_TetherItemToDummy))
    Wait(1)
    Exec(N(EVS_IntroduceAndHideBoots))
    Set(MV_KeepAwayStarted, TRUE)
    Wait(30)
    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    Wait(20)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(InterpPlayerYaw, 270, 0)
    Call(SetCamProperties, CAM_DEFAULT, Float(2.0), 0, 0, 0, Float(400.0), Float(15.0), Float(-7.0))
    Wait(60)
    Call(SetCamProperties, CAM_DEFAULT, Float(2.0), 0, 0, 0, Float(325.0), Float(13.0), Float(-13.0))
    // have item appear with leader via dummy NPC
    Call(SetNpcPos, NPC_LeaderBoo, 0, 45, 20)
    Call(SetNpcPos, NPC_DummyBoo, 0, 65, 0)
    Call(MakeLerp, 0, 255, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Call(SetItemAlpha, MV_KeepAwayItem, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    // explain the game
    Call(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_003A)
    Call(SetCamProperties, CAM_DEFAULT, Float(2.0), 0, 0, 0, Float(450.0), Float(15.0), Float(-7.0))
    Call(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_003B)
    Loop(0)
        Wait(1)
        IfEq(MV_Unk_02, 1)
            BreakLoop
        EndIf
    EndLoop
    Set(MV_KeepAwayRound, 0)
    Label(100)
        Add(MV_KeepAwayRound, 1)
        IfGe(MV_KeepAwayRound, 10)
            Set(MV_KeepAwayRound, 10)
        EndIf
        Call(SetCamProperties, CAM_DEFAULT, Float(2.0), 0, 0, 0, Float(500.0), Float(15.0), Float(-7.0))
        Wait(20)
        // first throw -- from leader
        // choose which boo will have the item next
        Call(RandInt, KEEP_AWAY_BOO_7, LVar0)
        Set(MV_KeepAwayTarget, LVar0)
        // jump dummy to the location of that NPC
        Set(LVar1, 30)
        Call(N(GetKeepAwayCarrierYaw))
        Call(N(GetItemJumpDest))
        Call(PlaySoundAtNpc, NPC_DummyBoo, SOUND_THROW, SOUND_SPACE_DEFAULT)
        Call(SetNpcJumpscale, NPC_DummyBoo, Float(1.0))
        Call(NpcJump0, NPC_DummyBoo, LVar0, LVar1, LVar2, 14 * DT)
        Call(SetNpcPos, NPC_DummyBoo, NPC_DISPOSE_LOCATION)
        Wait(30 * DT)
        Thread
            Call(MakeLerp, 255, 0, 10, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndThread
        // throw between 4-10 times
        Call(RandInt, 4, MV_KeepAwayThrows)
        Add(MV_KeepAwayThrows, 6)
        Loop(0)
            Call(N(GetKeepAwayCarrierPos))
            // choose which boo will have the item next
            Call(SetNpcPos, NPC_DummyBoo, LVar0, LVar1, LVar2)
            Call(RandInt, KEEP_AWAY_BOO_7, LVar0)
            IfEq(MV_KeepAwayTarget, LVar0)
                Add(LVar0, 4)
                IfGe(LVar0, 8)
                    Sub(LVar0, 8)
                EndIf
            EndIf
            Set(MV_KeepAwayTarget, LVar0)
            // jump dummy to the location of that NPC
            Set(LVar1, 30)
            Call(N(GetKeepAwayCarrierYaw))
            Call(N(GetItemJumpDest))
            Call(PlaySoundAtNpc, NPC_DummyBoo, SOUND_THROW, SOUND_SPACE_DEFAULT)
            Call(SetNpcJumpscale, NPC_DummyBoo, Float(1.5))
            Call(NpcJump0, NPC_DummyBoo, LVar0, LVar1, LVar2, 14 * DT)
            Call(SetNpcPos, NPC_DummyBoo, NPC_DISPOSE_LOCATION)
            Call(RandInt, 10 * DT, LVar0)
            Add(LVar0, 5 * DT)
            Wait(LVar0)
            Add(MV_KeepAwayThrows, -1)
            IfEq(MV_KeepAwayThrows, 0)
                BreakLoop
            EndIf
        EndLoop
        Set(MV_KeepAwayMovement, KEEP_AWAY_SPIRAL)
        Call(RandInt, 50, LVar0)
        Add(LVar0, 100)
        Wait(LVar0)
        Call(MakeLerp, 0, 255, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcImgFXParams, NPC_LeaderBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 5, MSG_CH3_003C)
        Call(DisablePlayerInput, FALSE)
        Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
        Loop(0)
            Wait(1)
            IfNe(MV_KeepAwayResult, KEEP_AWAY_WAITING)
                BreakLoop
            EndIf
        EndLoop
        Set(MV_KeepAwayMovement, KEEP_AWAY_STOP)
        Call(DisablePlayerInput, TRUE)
        IfEq(MV_KeepAwayResult, KEEP_AWAY_WRONG)
            // player hit the wrong Boo, begin another round
            Wait(20)
            Call(SetCamProperties, CAM_DEFAULT, Float(2.0), 0, 0, 0, Float(450.0), Float(15.0), Float(-7.0))
            Wait(30)
            ExecWait(N(EVS_DetermineCarrierNPC))
            Call(GetNpcPos, MV_ItemCarrierNpc, LVar0, LVar1, LVar2)
            Call(SetNpcPos, NPC_DummyBoo, LVar0, LVar1, LVar2)
            Call(GetNpcPos, NPC_DummyBoo, LVar3, LVar4, LVar5)
            Set(LVar6, 25)
            Add(LVar6, LVar4)
            Call(MakeLerp, LVar4, LVar6, 20, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Call(SetNpcPos, NPC_DummyBoo, LVar3, LVar0, LVar5)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(SpeakToPlayer, MV_ItemCarrierNpc, ANIM_Boo_Talk, ANIM_Boo_Idle, 5, MSG_CH3_003E)
            Call(PlaySoundAtNpc, NPC_DummyBoo, SOUND_THROW, SOUND_SPACE_DEFAULT)
            Call(SetNpcJumpscale, NPC_DummyBoo, Float(2.0))
            Call(NpcJump0, NPC_DummyBoo, 0, 65, 0, 10)
            Call(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 5, MSG_CH3_003B)
            Set(MV_KeepAwayResult, KEEP_AWAY_WAITING)
            Set(MV_KeepAwayMovement, KEEP_AWAY_CLOCKWISE)
            Call(N(GetPlayerPosOutsideKeepAwayRing))
            Call(SetPlayerSpeed, Float(4.0))
            Call(PlayerMoveTo, LVar0, LVar2, 0)
            Wait(30)
            Goto(100)
        EndIf
    Loop(0)
        Call(GetPlayerActionState, LVar0)
        Wait(1)
        IfEq(LVar0, ACTION_STATE_IDLE)
            BreakLoop
        EndIf
    EndLoop
    ExecWait(N(EVS_DetermineCarrierNPC))
    Call(GetNpcPos, MV_ItemCarrierNpc, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(SetNpcPos, NPC_DummyBoo, LVar0, LVar1, LVar2)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 30)
    Call(PlaySoundAtNpc, NPC_DummyBoo, SOUND_THROW, SOUND_SPACE_DEFAULT)
    Call(SetNpcJumpscale, NPC_DummyBoo, Float(2.0))
    Call(NpcJump0, NPC_DummyBoo, LVar0, LVar1, LVar2, 10)
    Wait(10)
    Call(SetNpcPos, NPC_DummyBoo, NPC_DISPOSE_LOCATION)
    Wait(1)
    Set(MF_WaitForUpgradeDone, FALSE)
    Exec(N(EVS_PlayUpgradeSong))
    Exec(N(EVS_SpawnGotSuperBootsFX))
    Call(N(UpgradeBootsToSuper))
    Wait(30)
    Call(ShowMessageAtScreenPos, MSG_Menus_0180, 160, 40)
    Set(MF_WaitForUpgradeDone, TRUE)
    Wait(30)
    Call(N(GetPlayerPosOutsideKeepAwayRing))
    Call(SetPlayerSpeed, Float(4.0))
    Call(PlayerMoveTo, LVar0, LVar2, 0)
    Wait(20)
    Call(GetNpcPos, NPC_LeaderBoo, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_LeaderBoo, ANIM_Boo_Talk, ANIM_Boo_Idle, 0, MSG_CH3_003D)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20)
    Thread
        Wait(30)
        Call(PlaySound, SOUND_BOO_SPOOK)
    EndThread
    Set(LVarA, NPC_KeepAwayBoo1)
    Exec(N(EVS_BooSpookAndVanish))
    Set(LVarA, NPC_KeepAwayBoo2)
    Exec(N(EVS_BooSpookAndVanish))
    Set(LVarA, NPC_KeepAwayBoo3)
    Exec(N(EVS_BooSpookAndVanish))
    Set(LVarA, NPC_KeepAwayBoo4)
    Exec(N(EVS_BooSpookAndVanish))
    Set(LVarA, NPC_KeepAwayBoo5)
    Exec(N(EVS_BooSpookAndVanish))
    Set(LVarA, NPC_KeepAwayBoo6)
    Exec(N(EVS_BooSpookAndVanish))
    Set(LVarA, NPC_KeepAwayBoo7)
    Exec(N(EVS_BooSpookAndVanish))
    Set(LVarA, NPC_KeepAwayBoo8)
    Exec(N(EVS_BooSpookAndVanish))
    Set(LVarA, NPC_LeaderBoo)
    Exec(N(EVS_BooSpookAndVanish))
    Wait(60)
    Call(SetNpcPos, NPC_TutorialBoo, -160, 10, -175)
    Call(SetNpcImgFXParams, NPC_TutorialBoo, IMGFX_SET_ALPHA, 0, 0, 0, 0)
    Set(LVarA, NPC_TutorialBoo)
    Exec(N(EVS_BooAppear))
    Wait(60)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Wait(20)
    Set(GB_StoryProgress, STORY_CH3_GOT_SUPER_BOOTS)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
