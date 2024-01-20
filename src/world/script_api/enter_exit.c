#include "common.h"
#include "../partners.h"

extern s32 DoorModelsSwingCCW[3];
extern s32 DoorModelsSwingCW[3];

API_CALLABLE(CheckUsingRideablePartner) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    script->varTable[10] = 0;
    if (partner_get_enter_map_script() != NULL) {
        if (gPartnerStatus.partnerActionState == ACTION_STATE_IDLE) {
            script->varTable[10] = 0;
        } else {
            script->varTable[10] = 1;
            script->varTablePtr[11] = partner_get_enter_map_script();
            script->varTable[13] = playerStatus->targetYaw;
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(TeleportPartnerToPlayer) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* partner;

    if (gPlayerData.curPartner == PARTNER_NONE) {
        return ApiStatus_DONE2;
    }

    partner = get_npc_unsafe(NPC_PARTNER);
    partner->pos.x = playerStatus->pos.x;
    partner->pos.z = playerStatus->pos.z;

    if (partner_is_flying()) {
        partner->pos.y = playerStatus->pos.y;
    }

    set_npc_yaw(partner, playerStatus->targetYaw);
    partner_clear_player_tracking(partner);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetPlayerPositionFromSaveData) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 currentPartner = gPlayerData.curPartner;

    playerStatus->pos.x = gGameStatusPtr->savedPos.x;
    playerStatus->pos.y = gGameStatusPtr->savedPos.y;
    playerStatus->pos.z = gGameStatusPtr->savedPos.z;

    if (currentPartner != PARTNER_NONE) {
        Npc* partner = get_npc_unsafe(NPC_PARTNER);
        f32 angle = clamp_angle((playerStatus->spriteFacingAngle < 180.0f) ? (90.0f) : (-90.0f));

        partner->pos.x = playerStatus->pos.x;
        partner->pos.y = playerStatus->pos.y;
        partner->pos.z = playerStatus->pos.z;
        add_vec2D_polar(&partner->pos.x, &partner->pos.z, playerStatus->colliderDiameter + 5, angle);
        enable_partner_ai();
    }

    camera->isChangingMap = TRUE;
    return ApiStatus_DONE2;
}

API_CALLABLE(EnterPlayerPostPipe) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    MapSettings* mapSettings = get_current_map_settings();
    ApiStatus ret = ApiStatus_BLOCK;

    if (isInitialCall) {
        playerStatus->pos.x = (*mapSettings->entryList)[gGameStatusPtr->entryID].x;
        playerStatus->pos.z = (*mapSettings->entryList)[gGameStatusPtr->entryID].z;
        script->varTable[2] = (*mapSettings->entryList)[gGameStatusPtr->entryID].y;
        playerStatus->pos.y = script->varTable[2] - 40;
        playerStatus->flags |= PS_FLAG_CAMERA_DOESNT_FOLLOW;
    } else {
        do {
            playerStatus->pos.y += 1.0f;
            if (!(playerStatus->pos.y < script->varTable[2])) {
                playerStatus->pos.y = script->varTable[2];
                playerStatus->flags &= ~PS_FLAG_CAMERA_DOESNT_FOLLOW;
                ret = ApiStatus_DONE2;
            }
        } while (0); // todo required to match
    }
    gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
    gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
    gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;
    return ret;
}

API_CALLABLE(ShortenPartnerTetherDistance) {
    partner_set_tether_distance(20.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(ResetPartnerTetherDistance) {
    partner_reset_tether_distance();
    return ApiStatus_DONE2;
}

API_CALLABLE(PlayerMoveToDoor) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        move_player(script->functionTemp[0], playerStatus->targetYaw, playerStatus->runSpeed);
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] < 0) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(GetEntryCoords) {
    Bytecode* args = script->ptrReadPos;
    MapSettings* mapSettings = get_current_map_settings();
    Vec4f* entryList = (Vec4f*)mapSettings->entryList;
    s32 index = evt_get_variable(script, *args++);

    evt_set_variable(script, *args++, entryList[index].x);
    evt_set_variable(script, *args++, entryList[index].y);
    evt_set_variable(script, *args++, entryList[index].z);
    evt_set_variable(script, *args++, entryList[index].yaw);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetupSingleDoor) {
    if (script->varTable[3] >= 0) {
        DoorModelsSwingCCW[0] = script->varTable[2];
        DoorModelsSwingCCW[1] = -1;
        DoorModelsSwingCW[0] = -1;
    } else {
        DoorModelsSwingCW[0] = script->varTable[2];
        DoorModelsSwingCW[1] = -1;
        DoorModelsSwingCCW[0] = -1;
    }

    script->varTablePtr[2] = &DoorModelsSwingCCW;
    script->varTablePtr[3] = &DoorModelsSwingCW;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetupSplitSingleDoor) {
    if (script->varTable[3] >= 0) {
        DoorModelsSwingCCW[0] = script->varTable[2];
        DoorModelsSwingCCW[1] = script->varTable[4];
        DoorModelsSwingCCW[2] = -1;
        DoorModelsSwingCW[0] = -1;
    } else {
        DoorModelsSwingCW[0] = script->varTable[2];
        DoorModelsSwingCW[1] = script->varTable[4];
        DoorModelsSwingCW[2] = -1;
        DoorModelsSwingCCW[0] = -1;
    }

    script->varTablePtr[2] = &DoorModelsSwingCCW;
    script->varTablePtr[3] = &DoorModelsSwingCW;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetupDoubleDoors) {
    DoorModelsSwingCCW[0] = script->varTable[2];
    DoorModelsSwingCCW[1] = -1;

    DoorModelsSwingCW[0] = script->varTable[3];
    DoorModelsSwingCW[1] = -1;

    script->varTablePtr[3] = &DoorModelsSwingCW;
    script->varTablePtr[2] = &DoorModelsSwingCCW;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetupSplitDoubleDoors) {
    DoorModelsSwingCCW[0] = script->varTable[2];
    DoorModelsSwingCCW[1] = script->varTable[4];
    DoorModelsSwingCCW[2] = -1;

    DoorModelsSwingCW[0] = script->varTable[3];
    DoorModelsSwingCW[1] = script->varTable[5];
    DoorModelsSwingCW[2] = -1;

    script->varTablePtr[3] = &DoorModelsSwingCW;
    script->varTablePtr[2] = &DoorModelsSwingCCW;

    return ApiStatus_DONE2;
}

EvtScript EnterWalk = {
    Call(ShortenPartnerTetherDistance)
    Call(CheckUsingRideablePartner)
    Call(UseEntryHeading, 60, 15)
    IfEq(LVarA, 0)
        Call(TeleportPartnerToPlayer)
        Call(PlayerMoveTo, LVar1, LVar3, 15)
    Else
        Set(LVarF, LVar0)
        Set(LVar0, 0)
        Set(LVarC, 1)
        Set(LVar4, 15)
        ExecWait(LVarB)
        Set(LVar0, LVarF)
    EndIf
    Exec(LVar0)
    Call(func_802D2148)
    Call(ResetPartnerTetherDistance)
    Return
    End
};

EvtScript EnterWalkShort = {
    Call(ShortenPartnerTetherDistance)
    Call(CheckUsingRideablePartner)
    Call(UseEntryHeading, 40, 15)
    IfEq(LVarA, 0)
        Call(TeleportPartnerToPlayer)
        Call(PlayerMoveTo, LVar1, LVar3, 15)
    Else
        Set(LVarF, LVar0)
        Set(LVar0, 0)
        Set(LVarC, 1)
        Set(LVar4, 15)
        ExecWait(LVarB)
        Set(LVar0, LVarF)
    EndIf
    Exec(LVar0)
    Call(func_802D2148)
    Call(ResetPartnerTetherDistance)
    Return
    End
};

EvtScript EnterWalkCustom = {
    Call(ShortenPartnerTetherDistance)
    Call(CheckUsingRideablePartner)
    Call(UseEntryHeading, LVar1, LVar4)
    IfEq(LVarA, 0)
        Call(TeleportPartnerToPlayer)
        Call(PlayerMoveTo, LVar1, LVar3, LVar4)
    Else
        Set(LVarF, LVar0)
        Set(LVar0, 0)
        Set(LVarC, 1)
        ExecWait(LVarB)
        Set(LVar0, LVarF)
    EndIf
    Exec(LVar0)
    Call(func_802D2148)
    Call(ResetPartnerTetherDistance)
    Return
    End
};

EvtScript EnterPostPipe = {
    Call(DisablePlayerPhysics, TRUE)
    Call(ShortenPartnerTetherDistance)
    Call(CheckUsingRideablePartner)
    Call(EnterPlayerPostPipe)
    Call(ResetPartnerTetherDistance)
    Call(DisablePlayerPhysics, FALSE)
    Return
    End
};

EvtScript EnterSavePoint = {
    Call(ShortenPartnerTetherDistance)
    Call(SetPlayerPositionFromSaveData)
    Call(ClearPartnerMoveHistory, NPC_PARTNER)
    Call(ResetPartnerTetherDistance)
    Return
    End
};

EvtScript ExitWalk = {
    Call(DisablePlayerInput, TRUE)
    Call(ShortenPartnerTetherDistance)
    Call(CheckUsingRideablePartner)
    IfEq(LVarA, 0)
        Call(PlayerMoveTo, LVar1, LVar3, 15)
    Else
        Set(LVar0, 0)
        Set(LVarC, 0)
        Set(LVar4, 15)
        ExecWait(LVarB)
    EndIf
    Call(ResetPartnerTetherDistance)
    Return
    End
};

EvtScript ExitSingleDoor = {
    Call(SetupSingleDoor)
    ExecWait(BaseExitDoor)
    Return
    End
};

EvtScript EnterSingleDoor = {
    Call(SetupSingleDoor)
    ExecWait(BaseEnterDoor)
    Return
    End
};

EvtScript ExitSplitSingleDoor = {
    Call(SetupSplitSingleDoor)
    ExecWait(BaseExitDoor)
    Return
    End
};

EvtScript EnterSplitSingleDoor = {
    Call(SetupSplitSingleDoor)
    ExecWait(BaseEnterDoor)
    Return
    End
};

EvtScript ExitDoubleDoor = {
    Call(SetupDoubleDoors)
    ExecWait(BaseExitDoor)
    Return
    End
};

EvtScript EnterDoubleDoor = {
    Call(SetupDoubleDoors)
    ExecWait(BaseEnterDoor)
    Return
    End
};

EvtScript ExitSplitDoubleDoor = {
    Call(SetupSplitDoubleDoors)
    ExecWait(BaseExitDoor)
    Return
    End
};

EvtScript EnterSplitDoubleDoor = {
    Call(SetupSplitDoubleDoors)
    ExecWait(BaseEnterDoor)
    Return
    End
};

EvtScript BaseExitDoor = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(ShortenPartnerTetherDistance)
    Set(LVar9, LVar0)
    Call(GetEntryCoords, LVar0, LVarC, LVarD, LVarE, LVarB)
    Add(LVarB, 180)
    Call(InterpPlayerYaw, LVarB, 2)
    Call(ModifyColliderFlags, 0, LVar1, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAt, SOUND_DOOR_OPEN, SOUND_SPACE_DEFAULT, LVarC, LVarD, LVarE)
    Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
    Label(0)
    Call(UpdateLerp)
    UseBuf(LVar2)
    Loop(0)
        BufRead1(LVarA)
        IfEq(LVarA, -1)
            BreakLoop
        EndIf
        Call(RotateModel, LVarA, LVar0, 0, 1, 0)
    EndLoop
    UseBuf(LVar3)
    Loop(0)
        BufRead1(LVarA)
        IfEq(LVarA, -1)
            BreakLoop
        EndIf
        Call(RotateModel, LVarA, LVar0, 0, -1, 0)
    EndLoop
    Wait(1)
    IfNe(LVar1, 0)
        Goto(0)
    EndIf
    Call(UseExitHeading, 40, LVar9)
    Call(CheckUsingRideablePartner)
    IfEq(LVarA, 0)
        Call(PlayerMoveTo, LVar1, LVar3, 15)
    Else
        Set(LVar0, 0)
        Set(LVarC, 0)
        Set(LVar4, 15)
        ExecWait(LVarB)
    EndIf
    Call(ResetPartnerTetherDistance)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript BaseEnterDoor = {
    Call(DisablePlayerInput, TRUE)
    Call(ShortenPartnerTetherDistance)
    UseBuf(LVar2)
    Loop(0)
        BufRead1(LVarA)
        IfEq(LVarA, -1)
            BreakLoop
        EndIf
        Call(RotateModel, LVarA, -80, 0, 1, 0)
    EndLoop
    UseBuf(LVar3)
    Loop(0)
        BufRead1(LVarA)
        IfEq(LVarA, -1)
            BreakLoop
        EndIf
        Call(RotateModel, LVarA, -80, 0, -1, 0)
    EndLoop
    Call(GetEntryCoords, LVar0, LVar7, LVar8, LVar9, LVarB)
    Call(InterpPlayerYaw, LVarB, 2)
    Call(CheckUsingRideablePartner)
    IfEq(LVarA, 0)
        Call(TeleportPartnerToPlayer)
        Call(PlayerMoveToDoor, 10)
    Else
        Set(LVar0, 1)
        Set(LVarC, 1)
        Set(LVar4, 15)
        ExecWait(LVarB)
    EndIf
    Thread
        Wait(8)
        Call(PlaySoundAt, SOUND_DOOR_CLOSE, SOUND_SPACE_DEFAULT, LVar7, LVar8, LVar9)
    EndThread
    Call(MakeLerp, -80, 0, 10, EASING_LINEAR)
    Label(0)
    Call(UpdateLerp)
    UseBuf(LVar2)
    Loop(0)
        BufRead1(LVarA)
        IfEq(LVarA, -1)
            BreakLoop
        EndIf
        Call(RotateModel, LVarA, LVar0, 0, 1, 0)
    EndLoop
    UseBuf(LVar3)
    Loop(0)
        BufRead1(LVarA)
        IfEq(LVarA, -1)
            BreakLoop
        EndIf
        Call(RotateModel, LVarA, LVar0, 0, -1, 0)
    EndLoop
    Wait(1)
    IfNe(LVar1, 0)
        Goto(0)
    EndIf
    Call(ResetPartnerTetherDistance)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

MATCHING_BSS(0x7AB0);
