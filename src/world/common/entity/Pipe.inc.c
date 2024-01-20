#include "common.h"
#include "npc.h"
#include "sprite/player.h"

// ----------------------------------------------------------------
// User macros

#define EVT_EXIT_PIPE_HORIZONTAL(entry, collider, script) \
{ \
    SetGroup(EVT_GROUP_1B) \
    Set(LVarA, entry) \
    Set(LVarB, collider) \
    Set(LVarC, Ref(script)) \
    ExecWait(N(EVS_Pipe_ExitHorizontal)) \
    Return \
    End \
}

#define EVT_EXIT_PIPE_VERTICAL(entry, collider, script) \
{ \
    SetGroup(EVT_GROUP_1B) \
    Set(LVarA, entry) \
    Set(LVarB, collider) \
    Set(LVarC, Ref(script)) \
    ExecWait(N(EVS_Pipe_ExitVertical)) \
    Return \
    End \
}

#define EVT_ENTER_PIPE_HORIZONTAL(collider, bindExitsScript) \
    Set(LVarA, Ref(bindExitsScript)) \
    Set(LVarB, collider) \
    Exec(N(EVS_Pipe_EnterHorizontal))

#define EVT_ENTER_PIPE_VERTICAL(bindExitsScript) \
    Set(LVarA, Ref(bindExitsScript)) \
    Exec(N(EVS_Pipe_EnterVertical))

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
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(HidePlayerShadow, TRUE)
    Call(SetPlayerAnimation, ANIM_Mario1_Still)
    Call(GetCurrentPartnerID, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(EnableNpcShadow, NPC_PARTNER, FALSE)
        Call(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    EndIf
    Call(GetEntryID, LVar0)
    Call(N(Pipe_GetEntryPos))
    Sub(LVar2, 40)
    Call(SetPlayerPos, LVar1, LVar2, LVar3)
    Call(InterpPlayerYaw, LVar4, 0)
    Call(PlaySound, SOUND_ENTER_PIPE)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_REVERSE_ANIM)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Still, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Loop(40)
        Add(LVar1, 1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Wait(3)
    Call(GetCurrentPartnerID, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Thread
            Call(DisablePartnerAI, 0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Sub(LVar2, 3)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_INVISIBLE, FALSE)
            Call(EnablePartnerAI)
            Call(EnableNpcShadow, NPC_PARTNER, TRUE)
        EndThread
    EndIf
    Wait(2)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Still, IMGFX_CLEAR, 0, 0, 0, 0)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Call(HidePlayerShadow, FALSE)
    Label(0)
    Call(N(Pipe_GetCurrentFloor))
    Wait(1)
    IfNe(LVar0, -1)
        Goto(0)
    EndIf
    Exec(LVarA)
    Return
    End
};

EvtScript N(EVS_Pipe_EnterHorizontal) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(HidePlayerShadow, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVarB, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetEntryID, LVar0)
    Call(N(Pipe_GetEntryPos))
    Set(LVar5, LVar1)
    Set(LVar6, LVar2)
    Set(LVar7, LVar3)
    Add(LVar2, 2)
    Call(SetPlayerPos, LVar1, LVar2, LVar3)
    Call(InterpPlayerYaw, LVar4, 0)
    IfEq(LVar4, 90)
        Add(LVar5, 40)
    Else
        Sub(LVar5, 40)
    EndIf
    Call(UseSettingsFrom, CAM_DEFAULT, LVar5, LVar6, LVar7)
    Call(SetPanTarget, CAM_DEFAULT, LVar5, LVar6, LVar7)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(GetCurrentPartnerID, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(DisablePartnerAI, 0)
        Call(EnableNpcShadow, NPC_PARTNER, FALSE)
        Call(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
        Call(InterpNpcYaw, NPC_PARTNER, LVar0, 0)
    EndIf
    Wait(1)
    Call(PlaySound, SOUND_ENTER_PIPE)
    Thread
        Wait(25)
        Call(HidePlayerShadow, FALSE)
    EndThread
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_REVERSE_ANIM | IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_HORIZONTAL_PIPE_CURL, 1, 1, 0)
    Loop(40)
        Call(N(Pipe_GetPointAheadOfPlayer), Float(1.0))
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(GetCurrentPartnerID, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Thread
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Sub(LVar2, 3)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            Call(EnableNpcShadow, NPC_PARTNER, TRUE)
            Call(EnablePartnerAI)
        EndThread
    EndIf
    Wait(5)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(ModifyColliderFlags, 1, LVarB, COLLIDER_FLAGS_UPPER_MASK)
    Call(DisablePlayerInput, FALSE)
    Call(DisablePlayerPhysics, FALSE)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Exec(LVarA)
    Return
    End
};

EvtScript N(EVS_Pipe_ExitVertical) = {
    Call(N(Pipe_AwaitDownInput))
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(GetCurrentPartnerID, LVar1)
        IfNe(LVar1, PARTNER_WATT)
            Return
        Else
            Call(InterruptUsePartner)
            Call(DisablePlayerInput, TRUE)
        EndIf
    Else
        Call(DisablePlayerInput, TRUE)
    EndIf
    ExecWait(N(EVS_Pipe_ExitVertical_Impl))
    Return
    End
};

EvtScript N(EVS_Pipe_ExitVertical_Impl) = {
    Call(N(Pipe_SetAnimFlag))
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerPhysics, TRUE)
    Call(HidePlayerShadow, TRUE)
    Set(LVar0, LVarA)
    Call(N(Pipe_GetEntryPos))
    Call(PlayerMoveTo, LVar1, LVar3, 3)
    Set(LVar0, LVarA)
    Call(N(Pipe_GetEntryPos))
    Call(SetPlayerPos, LVar1, LVar2, LVar3)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    Call(N(Pipe_GetCameraYaw))
    Call(InterpPlayerYaw, LVar0, 0)
    Wait(2)
    Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    Call(PlaySound, SOUND_ENTER_PIPE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Thread
        Wait(4)
        Loop(40)
            Sub(LVar1, 1)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    Wait(25)
    ExecWait(LVarC)
    Return
    End
};

EvtScript N(EVS_Pipe_ExitHorizontal) = {
    Call(IsPlayerOnValidFloor, LVar0)
    IfEq(LVar0, FALSE)
        Return
    EndIf
    Call(GetPlayerActionState, LVar0)
    IfEq(LVar0, ACTION_STATE_SPIN)
        Return
    EndIf
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(GetCurrentPartnerID, LVar1)
        IfNe(LVar1, PARTNER_WATT)
            Return
        Else
            Call(InterruptUsePartner)
            Call(DisablePlayerInput, TRUE)
        EndIf
    Else
        Call(DisablePlayerInput, TRUE)
    EndIf
    SetGroup(EVT_GROUP_1B)
    Call(N(Pipe_SetAnimFlag))
    Call(DisablePlayerPhysics, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVarB, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, LVarA)
    Call(N(Pipe_GetEntryPos))
    Set(LVar5, LVar1)
    Set(LVar6, LVar2)
    Add(LVar6, 2)
    Set(LVar7, LVar3)
    Set(LVar8, LVar4)
    Add(LVar8, 180)
    IfGe(LVar4, 360)
        Sub(LVar4, 360)
    EndIf
    Call(InterpPlayerYaw, LVar8, 1)
    Wait(1)
    Call(PlaySound, SOUND_ENTER_PIPE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerPos, LVar0, LVar6, LVar7)
    Call(SetPlayerAnimation, ANIM_Mario1_Still)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Still, IMGFX_SET_ANIM, IMGFX_ANIM_HORIZONTAL_PIPE_CURL, 1, 1, 0)
    Thread
        Wait(8)
        Call(HidePlayerShadow, TRUE)
    EndThread
    Thread
        Wait(3)
        Loop(40)
            Call(N(Pipe_GetPointAheadOfPlayer), Float(1.0))
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Wait(25)
    ExecWait(LVarC)
    Return
    End
};
