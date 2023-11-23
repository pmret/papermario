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
    EVT_EXEC_WAIT(N(EVS_RevealRightHouse))
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, MODEL_sou)
    EVT_SET(LVar2, 90)
    EVT_CALL(N(UpdateHouseShowHide))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnEnterRightHouse) = {
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, MODEL_sou)
    EVT_SET(LVar2, 32)
    EVT_CALL(N(UpdateHouseShowHide))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnEnterLeftHouse) = {
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, MODEL_gon)
    EVT_SET(LVar2, 32)
    EVT_CALL(N(UpdateHouseShowHide))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetEntityHideMode_LeftHouse) = {
    EVT_CALL(N(SetEntityHideMode1))
    EVT_WAIT(1)
    EVT_CALL(N(SetEntityHideMode2))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetEntityHideMode_Outside) = {
    EVT_CALL(N(SetEntityHideMode0))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TetherCamToPlayerCappedY) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GE(LVar1, LVar3)
            EVT_SET(LVar1, LVar3)
        EVT_END_IF
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TouchFloor_RightRoof) = {
    EVT_CALL(N(IsPlayerInputDisabled))
    EVT_IF_EQ(LVar0, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_SpinJump)
    EVT_CALL(SetZoneEnabled, ZONE_s, FALSE)
    EVT_WAIT(1)
    EVT_CALL(SetZoneEnabled, ZONE_gon, FALSE)
    EVT_CALL(SetZoneEnabled, ZONE_sou, FALSE)
    EVT_CALL(N(EnableCameraFollowPlayerY))
    EVT_SET(LVar3, 500)
    EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayerCappedY), LVarA)
    EVT_CALL(PlaySoundAtPlayer, SOUND_SLIDE, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(MovePlayerAlongRoofSlide))
    EVT_CALL(StopSound, SOUND_SLIDE)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.5))
    EVT_CALL(PlayerJump, -150, 325, -300, 40)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 1, 5, EVT_FLOAT(1.0))
    EVT_CALL(SetZoneEnabled, ZONE_s, TRUE)
    EVT_CALL(SetZoneEnabled, ZONE_gon, TRUE)
    EVT_CALL(SetZoneEnabled, ZONE_sou, TRUE)
    EVT_CALL(N(DisableCameraFollowPlayerY))
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpawnChimneySmokeAtPlayer) = {
    EVT_CALL(PlaySoundAtPlayer, SOUND_FIREPLACE_BURST, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar1, LVar2, LVar3, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar1, LVar2, LVar3, 20, 10, 0, 40)
    EVT_END_THREAD
    EVT_LOOP(7)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(RandInt, 30, LVar3)
        EVT_CALL(RandInt, 30, LVar4)
        EVT_ADD(LVar0, -15)
        EVT_ADD(LVar2, 10)
        EVT_ADD(LVar0, LVar3)
        EVT_ADD(LVar1, LVar4)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 20)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TouchFloor_LeftRoof) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, -215)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(LVar0, -205)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(LVar2, -390)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(LVar2, -375)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(IsPlayerInputDisabled))
    EVT_IF_EQ(LVar0, TRUE)
        EVT_RETURN
    EVT_END_IF
    // fall down the chimney
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_CALL(DisablePartnerAI, 0)
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerPos, -210, LVar1, -380)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
    EVT_WAIT(30)
    EVT_LOOP(10)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar1, 5)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtPlayer, SOUND_TRIP, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 1, 10, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -214, 150, -375)
    EVT_CALL(SetPlayerPos, -214, 150, -370)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Burnt)
    EVT_WAIT(10)
    EVT_EXEC(N(EVS_SpawnChimneySmokeAtPlayer))
    EVT_EXEC_WAIT(N(EVS_RevealLeftHouse))
    EVT_EXEC_WAIT(N(EVS_SetEntityHideMode_LeftHouse))
    EVT_EXEC(N(EVS_OnEnterLeftHouse))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(200.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-165.0), EVT_FLOAT(-140.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-12.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(40)
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(NpcFacePlayer, NPC_Herringway, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Herringway, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH7_00CC)
    EVT_CALL(GetNpcPos, NPC_Herringway, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(200.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-224.0), EVT_FLOAT(-132.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-127.0), EVT_FLOAT(-314.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_Herringway, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_CH7_00CD)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LandOnRightRoof) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_IF_EQ(MF_Unk_00, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MF_Unk_00, TRUE)
    EVT_LABEL(10)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(GetPlayerActionState, LVar3)
        EVT_WAIT(1)
        EVT_IF_LE(LVar0, 190)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_GE(LVar0, 230)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_LE(LVar1, 350)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_GE(LVar1, 373)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_LE(LVar2, -335)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_GE(LVar2, -303)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_EQ(MF_UsingSpring, FALSE)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetEntityHideMode_LeftHouse))
    EVT_EXEC(N(EVS_OnExitRightHouse))
    EVT_SET(MF_Unk_00, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSpring) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_IF_EQ(MV_CurrentFloor, 1)
        EVT_SET(LVar3, 500)
        EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayerCappedY), LVarA)
        EVT_EXEC_WAIT(N(EVS_SetEntityHideMode_Outside))
        EVT_SET(MF_UsingSpring, FALSE)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.5))
        EVT_CALL(PlayerJump, 175, 385, -310, 35)
        EVT_SET(MF_UsingSpring, TRUE)
        EVT_EXEC(N(EVS_LandOnRightRoof))
        EVT_EXEC_WAIT(N(EVS_OnEnterRightHouse))
    EVT_ELSE
        EVT_SET(LVar3, 175)
        EVT_EXEC_GET_TID(N(EVS_TetherCamToPlayerCappedY), LVarA)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
        EVT_CALL(PlayerJump, 160, 150, -310, 25)
    EVT_END_IF
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_KILL_THREAD(LVarA)
    EVT_WAIT(2)
    EVT_IF_EQ(MV_CurrentFloor, 1)
        EVT_EXEC_WAIT(N(EVS_HideRightHouse))
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_Padlock) = {
    EVT_EXEC_WAIT(N(EVS_SetupLockedHouse))
    EVT_SET(GF_SAM11_UnlockedDoor, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_SAM11_UnlockedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 153, 8, -145, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_Interact_Padlock)))
        EVT_SET(MV_PadlockEntityID, LVar0)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(N(MonitorCurrenFloor))
    EVT_END_THREAD
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 224, 150, -328, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_CALL(SetEntityCullMode, 1)
    EVT_SET(MF_Unk_00, FALSE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TouchFloor_RightRoof)), TRIGGER_FLOOR_TOUCH, COLLIDER_o570, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_TouchFloor_LeftRoof)), TRIGGER_FLOOR_TOUCH, COLLIDER_g_yuki2, 1, 0)
    EVT_CALL(MakeItemEntity, ITEM_WAREHOUSE_KEY, 0, -60, 220, ITEM_SPAWN_MODE_KEY, GF_SAM11_Item_WarehouseKey)
    EVT_RETURN
    EVT_END
};
