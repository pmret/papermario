#include "sam_11.h"
#include "entity.h"
#include "effects.h"

#include "model.h"

s32 N(D_80243CC0_D3E290) = 0;
s32 N(D_80243CC4_D3E294) = 0;
s32 N(D_80243CC8_D3E298) = 0;

API_CALLABLE(N(func_80240360_D3A930)) {
    u8 r, g, b, a;
    u8 alpha;
    s32 temp_a2;

    if (isInitialCall) {
        func_8011B950(script->varTable[1], -1, FOG_MODE_1, 1);
        script->functionTemp[0] = 0;
        get_background_color_blend(&r, &g, &b, &a);
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
    set_background_color_blend(0, 0, 0, a);
    temp_a2 = 255 - a;
    r = (N(D_80243CC0_D3E290) * temp_a2) / 255;
    g = (N(D_80243CC4_D3E294) * temp_a2) / 255;
    b = (N(D_80243CC8_D3E298) * temp_a2) / 255;
    gCameras[CAM_DEFAULT].bgColor[0] = r;
    gCameras[CAM_DEFAULT].bgColor[1] = g;
    gCameras[CAM_DEFAULT].bgColor[2] = b;
    if (script->functionTemp[0] >= 255) {
        if (script->varTable[0] == 1) {
            func_8011B950(script->varTable[1], -1, FOG_MODE_0, 1);
        }

        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_8024052C_D3AAFC)) {
    gEntityHideMode = 1;
    return ApiStatus_DONE2;
}

#define NAME_SUFFIX _Entity
ApiStatus N(Set80151310_2)(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 2;
    return ApiStatus_DONE2;
}

ApiStatus N(Set80151310_0)(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 0;
    return ApiStatus_DONE2;
}
#define NAME_SUFFIX

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/todo/SetCamera0MoveFlag1.inc.c"

API_CALLABLE(N(func_8024059C_D3AB6C)) {
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
    x = playerStatus->position.x + xComp;
    y = playerStatus->position.y + playerStatus->colliderHeight * 0.5f;
    z = playerStatus->position.z + zComp;
    hitDepth = 500.0f;

    if (npc_raycast_down_sides(0, &x, &y, &z, &hitDepth)) {
        if (hitDepth < 100.0f) {
            playerStatus->position.x = x;
            playerStatus->position.y = y;
            playerStatus->position.z = z;
            return ApiStatus_BLOCK;
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_8024072C_D3ACFC)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & (PS_FLAG_INPUT_DISABLED | PS_FLAG_NO_STATIC_COLLISION)) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240754_D3AD24)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->lastGoodPosition.y == 385) {
        evt_set_variable(script, MV_Unk_07, 0);
    }
    if (playerStatus->lastGoodPosition.y == 150) {
        evt_set_variable(script, MV_Unk_07, 1);
    }
    return ApiStatus_BLOCK;
}

EvtScript N(D_80243CCC_D3E29C) = {
    EVT_EXEC_WAIT(N(D_80243BC0_D3E190))
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 129)
    EVT_SET(LVar2, 90)
    EVT_CALL(N(func_80240360_D3A930))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243D24_D3E2F4) = {
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, 129)
    EVT_SET(LVar2, 32)
    EVT_CALL(N(func_80240360_D3A930))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243D70_D3E340) = {
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 82)
    EVT_SET(LVar2, 32)
    EVT_CALL(N(func_80240360_D3A930))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243DBC_D3E38C) = {
    EVT_CALL(N(func_8024052C_D3AAFC))
    EVT_WAIT(1)
    EVT_CALL(N(Set80151310_2_Entity))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243DFC_D3E3CC) = {
    EVT_CALL(N(Set80151310_0_Entity))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243E24_D3E3F4) = {
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

EvtScript N(D_80243EB4_D3E484) = {
    EVT_CALL(N(func_8024072C_D3ACFC))
    EVT_IF_EQ(LVar0, 1)
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1000B)
    EVT_CALL(SetZoneEnabled, ZONE_s, FALSE)
    EVT_WAIT(1)
    EVT_CALL(SetZoneEnabled, ZONE_gon, FALSE)
    EVT_CALL(SetZoneEnabled, ZONE_sou, FALSE)
    EVT_CALL(N(UnsetCamera0MoveFlag1))
    EVT_SET(LVar3, 500)
    EVT_EXEC_GET_TID(N(D_80243E24_D3E3F4), LVarA)
    EVT_CALL(PlaySoundAtPlayer, SOUND_167, 0)
    EVT_CALL(N(func_8024059C_D3AB6C))
    EVT_CALL(StopSound, SOUND_167)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.5))
    EVT_CALL(PlayerJump, -150, 325, -300, 40)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 1, 5, EVT_FLOAT(1.0))
    EVT_CALL(SetZoneEnabled, ZONE_s, TRUE)
    EVT_CALL(SetZoneEnabled, ZONE_gon, TRUE)
    EVT_CALL(SetZoneEnabled, ZONE_sou, TRUE)
    EVT_CALL(N(SetCamera0MoveFlag1))
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802440F8_D3E6C8) = {
    EVT_CALL(PlaySoundAtPlayer, SOUND_F5, 0)
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

EvtScript N(D_802442D8_D3E8A8) = {
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
    EVT_CALL(N(func_8024072C_D3ACFC))
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_1002B)
    EVT_WAIT(30)
    EVT_LOOP(10)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SUB(LVar1, 5)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPlayerPos, 0, -1000, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtPlayer, SOUND_162, 0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 1, 10, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -214, 150, -375)
    EVT_CALL(SetPlayerPos, -214, 150, -370)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_Charred)
    EVT_WAIT(10)
    EVT_EXEC(N(D_802440F8_D3E6C8))
    EVT_EXEC_WAIT(N(D_80243C40_D3E210))
    EVT_EXEC_WAIT(N(D_80243DBC_D3E38C))
    EVT_EXEC(N(D_80243D70_D3E340))
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
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244964_D3EF34) = {
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
    EVT_IF_EQ(MF_Unk_02, FALSE)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_EXEC_WAIT(N(D_80243DBC_D3E38C))
    EVT_EXEC(N(D_80243CCC_D3E29C))
    EVT_SET(MF_Unk_00, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244B14_D3F0E4) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_IF_EQ(MV_Unk_07, 1)
        EVT_SET(LVar3, 500)
        EVT_EXEC_GET_TID(N(D_80243E24_D3E3F4), LVarA)
        EVT_EXEC_WAIT(N(D_80243DFC_D3E3CC))
        EVT_SET(MF_Unk_02, FALSE)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.5))
        EVT_CALL(PlayerJump, 175, 385, -310, 35)
        EVT_SET(MF_Unk_02, TRUE)
        EVT_EXEC(N(D_80244964_D3EF34))
        EVT_EXEC_WAIT(N(D_80243D24_D3E2F4))
    EVT_ELSE
        EVT_SET(LVar3, 175)
        EVT_EXEC_GET_TID(N(D_80243E24_D3E3F4), LVarA)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
        EVT_CALL(PlayerJump, 160, 150, -310, 25)
    EVT_END_IF
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_KILL_THREAD(LVarA)
    EVT_WAIT(2)
    EVT_IF_EQ(MV_Unk_07, 1)
        EVT_EXEC_WAIT(N(D_80243B40_D3E110))
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244CBC_D3F28C) = {
    EVT_EXEC_WAIT(N(D_80243A38_D3E008))
    EVT_SET(GF_SAM11_UnlockedDoor, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_SAM11_UnlockedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 153, 8, -145, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(D_80244CBC_D3F28C)))
        EVT_SET(MV_Unk_06, LVar0)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(N(func_80240754_D3AD24))
    EVT_END_THREAD
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 224, 150, -328, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(D_80244B14_D3F0E4)))
    EVT_CALL(SetEntityCullMode, 1)
    EVT_SET(MF_Unk_00, FALSE)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80243EB4_D3E484)), TRIGGER_FLOOR_TOUCH, COLLIDER_o570, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_802442D8_D3E8A8)), TRIGGER_FLOOR_TOUCH, COLLIDER_g_yuki2, 1, 0)
    EVT_CALL(MakeItemEntity, ITEM_WAREHOUSE_KEY, 0, -60, 220, ITEM_SPAWN_MODE_KEY, GF_SAM11_Item_WarehouseKey)
    EVT_RETURN
    EVT_END
};
