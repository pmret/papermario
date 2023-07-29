#include "common.h"
#include "npc.h"
#include "sprite/player.h"

// ----------------------------------------------------------------
// User macros

#define EVT_EXIT_PIPE_HORIZONTAL(entry, collider, script) \
{ \
    EVT_SET_GROUP(EVT_GROUP_1B) \
    EVT_SET(LVarA, entry) \
    EVT_SET(LVarB, collider) \
    EVT_SET(LVarC, EVT_PTR(script)) \
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitHorizontal)) \
    EVT_RETURN \
    EVT_END \
}

#define EVT_EXIT_PIPE_VERTICAL(entry, collider, script) \
{ \
    EVT_SET_GROUP(EVT_GROUP_1B) \
    EVT_SET(LVarA, entry) \
    EVT_SET(LVarB, collider) \
    EVT_SET(LVarC, EVT_PTR(script)) \
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitVertical)) \
    EVT_RETURN \
    EVT_END \
}

#define EVT_ENTER_PIPE_HORIZONTAL(collider, bindExitsScript) \
    EVT_SET(LVarA, EVT_PTR(bindExitsScript)) \
    EVT_SET(LVarB, collider) \
    EVT_EXEC(N(EVS_Pipe_EnterHorizontal))

#define EVT_ENTER_PIPE_VERTICAL(bindExitsScript) \
    EVT_SET(LVarA, EVT_PTR(bindExitsScript)) \
    EVT_EXEC(N(EVS_Pipe_EnterVertical))

// ----------------------------------------------------------------
// Implementation

API_CALLABLE(N(Pipe_SetAnimFlag)) {
    gPlayerStatusPtr->animFlags |= PA_FLAG_CHANGING_MAP;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Pipe_GetCurrentFloor)) {
    script->varTable[0] = gCollisionStatus.curFloor;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Pipe_AwaitDownInput)) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 stickX, stickY;

    if (collisionStatus->curFloor != script->varTable[11]) {
        script->varTable[0] = FALSE;
        return ApiStatus_DONE2;
    }

    stickX = abs(gGameStatusPtr->stickX[0]);
    stickY = gGameStatusPtr->stickY[0];

    if (stickX != 0 || stickY != 0) {
        if (atan2(0.0f, 0.0f, stickX, stickY) < 60.0f) {
            script->varTable[0] = TRUE;
            return ApiStatus_DONE2;
        }
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(Pipe_GetEntryPos)) {
    MapSettings* mapSettings = get_current_map_settings();
    s32 index = evt_get_variable(script, LVar0);

    evt_set_variable(script, LVar1, ((Vec4f*)*mapSettings->entryList)[index].x);
    evt_set_variable(script, LVar2, ((Vec4f*)*mapSettings->entryList)[index].y);
    evt_set_variable(script, LVar3, ((Vec4f*)*mapSettings->entryList)[index].z);
    evt_set_variable(script, LVar4, ((Vec4f*)*mapSettings->entryList)[index].yaw);
    #ifdef _DEAD_H_
    osSyncPrintf("[%d] dokan get pos  (no=%d)  pos=%d, %d, %d,  dir=%d\n",
                 gGameStatusPtr->frameCounter, script->varTable[0], script->varTable[1], script->varTable[2],
                 script->varTable[3], script->varTable[4]);
    #endif
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Pipe_GetCameraYaw)) {
    script->varTable[0] = clamp_angle(gCameras[gCurrentCameraID].curYaw + 180.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(Pipe_GetPointAheadOfPlayer)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 r = evt_get_float_variable(script, *script->ptrReadPos);
    f32 x = playerStatus->pos.x;
    f32 y = playerStatus->pos.y;
    f32 z = playerStatus->pos.z;

    add_vec2D_polar(&x, &z, r, playerStatus->targetYaw);
    evt_set_float_variable(script, LVar0, x);
    evt_set_float_variable(script, LVar1, y);
    evt_set_float_variable(script, LVar2, z);

    return ApiStatus_DONE2;
}

// ----------------------------------------------------------------
// Scripts

extern EvtScript N(EVS_Pipe_ExitVertical_Impl);

EvtScript N(EVS_Pipe_EnterVertical) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SUB(LVar2, 40)
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(InterpPlayerYaw, LVar4, 0)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_REVERSE_ANIM)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Still, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_LOOP(40)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(3)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE, FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Still, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_LABEL(0)
    EVT_CALL(N(Pipe_GetCurrentFloor))
    EVT_WAIT(1)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_EXEC(LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Pipe_EnterHorizontal) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVarB, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SET(LVar5, LVar1)
    EVT_SET(LVar6, LVar2)
    EVT_SET(LVar7, LVar3)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(InterpPlayerYaw, LVar4, 0)
    EVT_IF_EQ(LVar4, 90)
        EVT_ADD(LVar5, 40)
    EVT_ELSE
        EVT_SUB(LVar5, 40)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar5, LVar6, LVar7)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar5, LVar6, LVar7)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVar0, 0)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(HidePlayerShadow, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_REVERSE_ANIM | IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_HORIZONTAL_PIPE_CURL, 1, 1, 0)
    EVT_LOOP(40)
        EVT_CALL(N(Pipe_GetPointAheadOfPlayer), EVT_FLOAT(1.0))
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, 1, LVarB, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_EXEC(LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Pipe_ExitVertical) = {
    EVT_CALL(N(Pipe_AwaitDownInput))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_NE(LVar1, PARTNER_WATT)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(InterruptUsePartner)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_Pipe_ExitVertical_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Pipe_ExitVertical_Impl) = {
    EVT_CALL(N(Pipe_SetAnimFlag))
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_CALL(PlayerMoveTo, LVar1, LVar3, 3)
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    EVT_CALL(N(Pipe_GetCameraYaw))
    EVT_CALL(InterpPlayerYaw, LVar0, 0)
    EVT_WAIT(2)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_LOOP(40)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    EVT_WAIT(25)
    EVT_EXEC_WAIT(LVarC)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Pipe_ExitHorizontal) = {
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_EQ(LVar0, ACTION_STATE_SPIN)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_NE(LVar1, PARTNER_WATT)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(InterruptUsePartner)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(N(Pipe_SetAnimFlag))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVarB, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SET(LVar5, LVar1)
    EVT_SET(LVar6, LVar2)
    EVT_ADD(LVar6, 2)
    EVT_SET(LVar7, LVar3)
    EVT_SET(LVar8, LVar4)
    EVT_ADD(LVar8, 180)
    EVT_IF_GE(LVar4, 360)
        EVT_SUB(LVar4, 360)
    EVT_END_IF
    EVT_CALL(InterpPlayerYaw, LVar8, 1)
    EVT_WAIT(1)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerPos, LVar0, LVar6, LVar7)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Still, IMGFX_SET_ANIM, IMGFX_ANIM_HORIZONTAL_PIPE_CURL, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(HidePlayerShadow, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(3)
        EVT_LOOP(40)
            EVT_CALL(N(Pipe_GetPointAheadOfPlayer), EVT_FLOAT(1.0))
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(25)
    EVT_EXEC_WAIT(LVarC)
    EVT_RETURN
    EVT_END
};
