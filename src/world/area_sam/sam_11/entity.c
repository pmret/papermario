#include "sam_11.h"
#include "entity.h"
#include "effects.h"
#include "model.h"
#include "sprite/player.h"

s32 N(TargetBackgroundColR) = 0;
s32 N(TargetBackgroundColG) = 0;
s32 N(TargetBackgroundColB) = 0;

API_CALLABLE(N(UpdateHouseShowHide)) {
    u8 r, g, b, a;
    u8 alpha;
    s32 temp_a2;

    if (isInitialCall) {
        mdl_group_set_custom_gfx(script->varTable[1], CUSTOM_GFX_NONE, ENV_TINT_SHROUD, TRUE);
        script->functionTemp[0] = 0;
        mdl_get_shroud_tint_params(&r, &g, &b, &a);
        if ((script->varTable[0] == 0 && a == 255) || (script->varTable[0] == 1 && a == 0)) {
            return ApiStatus_DONE2;
        }
    }

    script->functionTemp[0] += script->varTable[2];
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }
    if (script->varTable[0] == 0) {
        alpha = script->functionTemp[0];
    } else {
        alpha = ~script->functionTemp[0];
    }
    a = alpha;
    mdl_set_shroud_tint_params(0, 0, 0, a);
    r = (N(TargetBackgroundColR) * (255 - a)) / 255;
    g = (N(TargetBackgroundColG) * (255 - a)) / 255;
    b = (N(TargetBackgroundColB) * (255 - a)) / 255;
    gCameras[CAM_DEFAULT].bgColor[0] = r;
    gCameras[CAM_DEFAULT].bgColor[1] = g;
    gCameras[CAM_DEFAULT].bgColor[2] = b;
    if (script->functionTemp[0] >= 255) {
        if (script->varTable[0] == 1) {
            mdl_group_set_custom_gfx(script->varTable[1], CUSTOM_GFX_NONE, ENV_TINT_NONE, TRUE);
        }

        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(SetEntityHideMode1)) {
    gEntityHideMode = ENTITY_HIDE_MODE_1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetEntityHideMode2)) {
    gEntityHideMode = ENTITY_HIDE_MODE_2;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetEntityHideMode0)) {
    gEntityHideMode = ENTITY_HIDE_MODE_0;
    return ApiStatus_DONE2;
}

#include "world/common/EnableCameraFollowPlayerY.inc.c"
#include "world/common/DisableCameraFollowPlayerY.inc.c"

API_CALLABLE(N(MovePlayerAlongRoofSlide)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 xComp, zComp;
    f32 x, y, z;
    f32 hitDepth;

    if (isInitialCall) {
        script->functionTemp[1] = 10;
    }
    playerStatus->targetYaw = 270.0f;
    script->functionTemp[1] += 4;
    xComp = (script->functionTemp[1] / 10) * sin_deg(playerStatus->targetYaw);
    zComp = (script->functionTemp[1] / 10) * -cos_deg(playerStatus->targetYaw);
    x = playerStatus->pos.x + xComp;
    y = playerStatus->pos.y + playerStatus->colliderHeight * 0.5f;
    z = playerStatus->pos.z + zComp;
    hitDepth = 500.0f;

    if (npc_raycast_down_sides(0, &x, &y, &z, &hitDepth)) {
        if (hitDepth < 100.0f) {
            playerStatus->pos.x = x;
            playerStatus->pos.y = y;
            playerStatus->pos.z = z;
            return ApiStatus_BLOCK;
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(IsPlayerInputDisabled)) {
    if (gPlayerStatus.flags & (PS_FLAG_INPUT_DISABLED | PS_FLAG_NO_STATIC_COLLISION)) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(MonitorCurrenFloor)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->lastGoodPos.y == 385) {
        evt_set_variable(script, MV_CurrentFloor, 0);
    }
    if (playerStatus->lastGoodPos.y == 150) {
        evt_set_variable(script, MV_CurrentFloor, 1);
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_OnExitRightHouse) = {
    ExecWait(N(EVS_RevealRightHouse))
    Set(LVar0, 0)
    Set(LVar1, MODEL_sou)
    Set(LVar2, 90)
    Call(N(UpdateHouseShowHide))
    Return
    End
};

EvtScript N(EVS_OnEnterRightHouse) = {
    Set(LVar0, 1)
    Set(LVar1, MODEL_sou)
    Set(LVar2, 32)
    Call(N(UpdateHouseShowHide))
    Return
    End
};

EvtScript N(EVS_OnEnterLeftHouse) = {
    Set(LVar0, 0)
    Set(LVar1, MODEL_gon)
    Set(LVar2, 32)
    Call(N(UpdateHouseShowHide))
    Return
    End
};

EvtScript N(EVS_SetEntityHideMode_LeftHouse) = {
    Call(N(SetEntityHideMode1))
    Wait(1)
    Call(N(SetEntityHideMode2))
    Wait(1)
    Return
    End
};

EvtScript N(EVS_SetEntityHideMode_Outside) = {
    Call(N(SetEntityHideMode0))
    Wait(1)
    Return
    End
};

EvtScript N(EVS_TetherCamToPlayerCappedY) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfGe(LVar1, LVar3)
            Set(LVar1, LVar3)
        EndIf
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_TouchFloor_RightRoof) = {
    Call(N(IsPlayerInputDisabled))
    IfEq(LVar0, TRUE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(InterruptUsePartner)
        Wait(20)
    EndIf
    Wait(1)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_Mario1_SpinJump)
    Call(SetZoneEnabled, ZONE_s, FALSE)
    Wait(1)
    Call(SetZoneEnabled, ZONE_gon, FALSE)
    Call(SetZoneEnabled, ZONE_sou, FALSE)
    Call(N(EnableCameraFollowPlayerY))
    Set(LVar3, 500)
    ExecGetTID(N(EVS_TetherCamToPlayerCappedY), LVarA)
    Call(PlaySoundAtPlayer, SOUND_SLIDE, SOUND_SPACE_DEFAULT)
    Call(N(MovePlayerAlongRoofSlide))
    Call(StopSound, SOUND_SLIDE)
    Call(SetPlayerJumpscale, Float(0.5))
    Call(PlayerJump, -150, 325, -300, 40)
    Call(ShakeCam, CAM_DEFAULT, 1, 5, Float(1.0))
    Call(SetZoneEnabled, ZONE_s, TRUE)
    Call(SetZoneEnabled, ZONE_gon, TRUE)
    Call(SetZoneEnabled, ZONE_sou, TRUE)
    Call(N(DisableCameraFollowPlayerY))
    KillThread(LVarA)
    Call(DisablePlayerInput, FALSE)
    Call(DisablePlayerPhysics, FALSE)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Return
    End
};

EvtScript N(EVS_SpawnChimneySmokeAtPlayer) = {
    Call(PlaySoundAtPlayer, SOUND_FIREPLACE_BURST, SOUND_SPACE_DEFAULT)
    Thread
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        PlayEffect(EFFECT_LANDING_DUST, 4, LVar1, LVar2, LVar3, 0)
    EndThread
    Thread
        Call(GetPlayerPos, LVar1, LVar2, LVar3)
        PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar1, LVar2, LVar3, 20, 10, 0, 40)
    EndThread
    Loop(7)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(RandInt, 30, LVar3)
        Call(RandInt, 30, LVar4)
        Add(LVar0, -15)
        Add(LVar2, 10)
        Add(LVar0, LVar3)
        Add(LVar1, LVar4)
        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 20)
        Wait(6)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TouchFloor_LeftRoof) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, -215)
        Return
    EndIf
    IfGt(LVar0, -205)
        Return
    EndIf
    IfLt(LVar2, -390)
        Return
    EndIf
    IfGt(LVar2, -375)
        Return
    EndIf
    Call(N(IsPlayerInputDisabled))
    IfEq(LVar0, TRUE)
        Return
    EndIf
    // fall down the chimney
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(InterruptUsePartner)
        Wait(20)
    EndIf
    Call(DisablePartnerAI, 0)
    Wait(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerPos, -210, LVar1, -380)
    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    Wait(30)
    Loop(10)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar1, 5)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetPlayerPos, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    Wait(20)
    Call(PlaySoundAtPlayer, SOUND_TRIP, SOUND_SPACE_DEFAULT)
    Call(ShakeCam, CAM_DEFAULT, 1, 10, Float(1.0))
    Wait(10)
    Call(SetNpcPos, NPC_PARTNER, -214, 150, -375)
    Call(SetPlayerPos, -214, 150, -370)
    Call(SetPlayerAnimation, ANIM_Mario1_Burnt)
    Wait(10)
    Exec(N(EVS_SpawnChimneySmokeAtPlayer))
    ExecWait(N(EVS_RevealLeftHouse))
    ExecWait(N(EVS_SetEntityHideMode_LeftHouse))
    Exec(N(EVS_OnEnterLeftHouse))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(200.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(-165.0), Float(-140.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-12.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(40)
    IfGe(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
        Call(DisablePlayerPhysics, FALSE)
        Call(DisablePlayerInput, FALSE)
        Call(EnablePartnerAI)
        Return
    EndIf
    Call(NpcFacePlayer, NPC_Herringway, 0)
    Wait(10)
    Call(SpeakToPlayer, NPC_Herringway, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH7_00CC)
    Call(GetNpcPos, NPC_Herringway, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(200.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(-224.0), Float(-132.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(-127.0), Float(-314.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Herringway, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH7_00CD)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(DisablePlayerPhysics, FALSE)
    Call(EnablePartnerAI)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Return
    End
};

EvtScript N(EVS_LandOnRightRoof) = {
    SetGroup(EVT_GROUP_00)
    IfEq(MF_Unk_00, TRUE)
        Return
    EndIf
    Set(MF_Unk_00, TRUE)
    Label(10)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(GetPlayerActionState, LVar3)
        Wait(1)
        IfLe(LVar0, 190)
            Goto(10)
        EndIf
        IfGe(LVar0, 230)
            Goto(10)
        EndIf
        IfLe(LVar1, 350)
            Goto(10)
        EndIf
        IfGe(LVar1, 373)
            Goto(10)
        EndIf
        IfLe(LVar2, -335)
            Goto(10)
        EndIf
        IfGe(LVar2, -303)
            Goto(10)
        EndIf
        IfEq(MF_UsingSpring, FALSE)
            Goto(10)
        EndIf
    ExecWait(N(EVS_SetEntityHideMode_LeftHouse))
    Exec(N(EVS_OnExitRightHouse))
    Set(MF_Unk_00, FALSE)
    Return
    End
};

EvtScript N(EVS_UseSpring) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    IfEq(MV_CurrentFloor, 1)
        Set(LVar3, 500)
        ExecGetTID(N(EVS_TetherCamToPlayerCappedY), LVarA)
        ExecWait(N(EVS_SetEntityHideMode_Outside))
        Set(MF_UsingSpring, FALSE)
        Call(SetPlayerJumpscale, Float(0.5))
        Call(PlayerJump, 175, 385, -310, 35)
        Set(MF_UsingSpring, TRUE)
        Exec(N(EVS_LandOnRightRoof))
        ExecWait(N(EVS_OnEnterRightHouse))
    Else
        Set(LVar3, 175)
        ExecGetTID(N(EVS_TetherCamToPlayerCappedY), LVarA)
        Call(SetPlayerJumpscale, Float(0.7))
        Call(PlayerJump, 160, 150, -310, 25)
    EndIf
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    KillThread(LVarA)
    Wait(2)
    IfEq(MV_CurrentFloor, 1)
        ExecWait(N(EVS_HideRightHouse))
    EndIf
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Interact_Padlock) = {
    ExecWait(N(EVS_SetupLockedHouse))
    Set(GF_SAM11_UnlockedDoor, TRUE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_SAM11_UnlockedDoor, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), 153, 8, -145, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_Interact_Padlock)))
        Set(MV_PadlockEntityID, LVar0)
    EndIf
    Thread
        Call(N(MonitorCurrenFloor))
    EndThread
    Call(MakeEntity, Ref(Entity_ScriptSpring), 224, 150, -328, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpring)))
    Call(SetEntityCullMode, 1)
    Set(MF_Unk_00, FALSE)
    BindTrigger(Ref(N(EVS_TouchFloor_RightRoof)), TRIGGER_FLOOR_TOUCH, COLLIDER_o570, 1, 0)
    BindTrigger(Ref(N(EVS_TouchFloor_LeftRoof)), TRIGGER_FLOOR_TOUCH, COLLIDER_g_yuki2, 1, 0)
    Call(MakeItemEntity, ITEM_WAREHOUSE_KEY, 0, -60, 220, ITEM_SPAWN_MODE_KEY, GF_SAM11_Item_WarehouseKey)
    Return
    End
};
