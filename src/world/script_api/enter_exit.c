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
    EVT_CALL(ShortenPartnerTetherDistance)
    EVT_CALL(CheckUsingRideablePartner)
    EVT_CALL(UseEntryHeading, 60, 15)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(TeleportPartnerToPlayer)
        EVT_CALL(PlayerMoveTo, LVar1, LVar3, 15)
    EVT_ELSE
        EVT_SET(LVarF, LVar0)
        EVT_SET(LVar0, 0)
        EVT_SET(LVarC, 1)
        EVT_SET(LVar4, 15)
        EVT_EXEC_WAIT(LVarB)
        EVT_SET(LVar0, LVarF)
    EVT_END_IF
    EVT_EXEC(LVar0)
    EVT_CALL(func_802D2148)
    EVT_CALL(ResetPartnerTetherDistance)
    EVT_RETURN
    EVT_END
};

EvtScript EnterWalkShort = {
    EVT_CALL(ShortenPartnerTetherDistance)
    EVT_CALL(CheckUsingRideablePartner)
    EVT_CALL(UseEntryHeading, 40, 15)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(TeleportPartnerToPlayer)
        EVT_CALL(PlayerMoveTo, LVar1, LVar3, 15)
    EVT_ELSE
        EVT_SET(LVarF, LVar0)
        EVT_SET(LVar0, 0)
        EVT_SET(LVarC, 1)
        EVT_SET(LVar4, 15)
        EVT_EXEC_WAIT(LVarB)
        EVT_SET(LVar0, LVarF)
    EVT_END_IF
    EVT_EXEC(LVar0)
    EVT_CALL(func_802D2148)
    EVT_CALL(ResetPartnerTetherDistance)
    EVT_RETURN
    EVT_END
};

EvtScript EnterWalkCustom = {
    EVT_CALL(ShortenPartnerTetherDistance)
    EVT_CALL(CheckUsingRideablePartner)
    EVT_CALL(UseEntryHeading, LVar1, LVar4)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(TeleportPartnerToPlayer)
        EVT_CALL(PlayerMoveTo, LVar1, LVar3, LVar4)
    EVT_ELSE
        EVT_SET(LVarF, LVar0)
        EVT_SET(LVar0, 0)
        EVT_SET(LVarC, 1)
        EVT_EXEC_WAIT(LVarB)
        EVT_SET(LVar0, LVarF)
    EVT_END_IF
    EVT_EXEC(LVar0)
    EVT_CALL(func_802D2148)
    EVT_CALL(ResetPartnerTetherDistance)
    EVT_RETURN
    EVT_END
};

EvtScript EnterPostPipe = {
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ShortenPartnerTetherDistance)
    EVT_CALL(CheckUsingRideablePartner)
    EVT_CALL(EnterPlayerPostPipe)
    EVT_CALL(ResetPartnerTetherDistance)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript EnterSavePoint = {
    EVT_CALL(ShortenPartnerTetherDistance)
    EVT_CALL(SetPlayerPositionFromSaveData)
    EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
    EVT_CALL(ResetPartnerTetherDistance)
    EVT_RETURN
    EVT_END
};

EvtScript ExitWalk = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShortenPartnerTetherDistance)
    EVT_CALL(CheckUsingRideablePartner)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(PlayerMoveTo, LVar1, LVar3, 15)
    EVT_ELSE
        EVT_SET(LVar0, 0)
        EVT_SET(LVarC, 0)
        EVT_SET(LVar4, 15)
        EVT_EXEC_WAIT(LVarB)
    EVT_END_IF
    EVT_CALL(ResetPartnerTetherDistance)
    EVT_RETURN
    EVT_END
};

EvtScript ExitSingleDoor = {
    EVT_CALL(SetupSingleDoor)
    EVT_EXEC_WAIT(BaseExitDoor)
    EVT_RETURN
    EVT_END
};

EvtScript EnterSingleDoor = {
    EVT_CALL(SetupSingleDoor)
    EVT_EXEC_WAIT(BaseEnterDoor)
    EVT_RETURN
    EVT_END
};

EvtScript ExitSplitSingleDoor = {
    EVT_CALL(SetupSplitSingleDoor)
    EVT_EXEC_WAIT(BaseExitDoor)
    EVT_RETURN
    EVT_END
};

EvtScript EnterSplitSingleDoor = {
    EVT_CALL(SetupSplitSingleDoor)
    EVT_EXEC_WAIT(BaseEnterDoor)
    EVT_RETURN
    EVT_END
};

EvtScript ExitDoubleDoor = {
    EVT_CALL(SetupDoubleDoors)
    EVT_EXEC_WAIT(BaseExitDoor)
    EVT_RETURN
    EVT_END
};

EvtScript EnterDoubleDoor = {
    EVT_CALL(SetupDoubleDoors)
    EVT_EXEC_WAIT(BaseEnterDoor)
    EVT_RETURN
    EVT_END
};

EvtScript ExitSplitDoubleDoor = {
    EVT_CALL(SetupSplitDoubleDoors)
    EVT_EXEC_WAIT(BaseExitDoor)
    EVT_RETURN
    EVT_END
};

EvtScript EnterSplitDoubleDoor = {
    EVT_CALL(SetupSplitDoubleDoors)
    EVT_EXEC_WAIT(BaseEnterDoor)
    EVT_RETURN
    EVT_END
};

EvtScript BaseExitDoor = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ShortenPartnerTetherDistance)
    EVT_SET(LVar9, LVar0)
    EVT_CALL(GetEntryCoords, LVar0, LVarC, LVarD, LVarE, LVarB)
    EVT_ADD(LVarB, 180)
    EVT_CALL(InterpPlayerYaw, LVarB, 2)
    EVT_CALL(ModifyColliderFlags, 0, LVar1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAt, SOUND_DOOR_OPEN, SOUND_SPACE_DEFAULT, LVarC, LVarD, LVarE)
    EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_USE_BUF(LVar2)
    EVT_LOOP(0)
        EVT_BUF_READ1(LVarA)
        EVT_IF_EQ(LVarA, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(RotateModel, LVarA, LVar0, 0, 1, 0)
    EVT_END_LOOP
    EVT_USE_BUF(LVar3)
    EVT_LOOP(0)
        EVT_BUF_READ1(LVarA)
        EVT_IF_EQ(LVarA, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(RotateModel, LVarA, LVar0, 0, -1, 0)
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(UseExitHeading, 40, LVar9)
    EVT_CALL(CheckUsingRideablePartner)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(PlayerMoveTo, LVar1, LVar3, 15)
    EVT_ELSE
        EVT_SET(LVar0, 0)
        EVT_SET(LVarC, 0)
        EVT_SET(LVar4, 15)
        EVT_EXEC_WAIT(LVarB)
    EVT_END_IF
    EVT_CALL(ResetPartnerTetherDistance)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript BaseEnterDoor = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShortenPartnerTetherDistance)
    EVT_USE_BUF(LVar2)
    EVT_LOOP(0)
        EVT_BUF_READ1(LVarA)
        EVT_IF_EQ(LVarA, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(RotateModel, LVarA, -80, 0, 1, 0)
    EVT_END_LOOP
    EVT_USE_BUF(LVar3)
    EVT_LOOP(0)
        EVT_BUF_READ1(LVarA)
        EVT_IF_EQ(LVarA, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(RotateModel, LVarA, -80, 0, -1, 0)
    EVT_END_LOOP
    EVT_CALL(GetEntryCoords, LVar0, LVar7, LVar8, LVar9, LVarB)
    EVT_CALL(InterpPlayerYaw, LVarB, 2)
    EVT_CALL(CheckUsingRideablePartner)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(TeleportPartnerToPlayer)
        EVT_CALL(PlayerMoveToDoor, 10)
    EVT_ELSE
        EVT_SET(LVar0, 1)
        EVT_SET(LVarC, 1)
        EVT_SET(LVar4, 15)
        EVT_EXEC_WAIT(LVarB)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAt, SOUND_DOOR_CLOSE, SOUND_SPACE_DEFAULT, LVar7, LVar8, LVar9)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, -80, 0, 10, EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_USE_BUF(LVar2)
    EVT_LOOP(0)
        EVT_BUF_READ1(LVarA)
        EVT_IF_EQ(LVarA, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(RotateModel, LVarA, LVar0, 0, 1, 0)
    EVT_END_LOOP
    EVT_USE_BUF(LVar3)
    EVT_LOOP(0)
        EVT_BUF_READ1(LVarA)
        EVT_IF_EQ(LVarA, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(RotateModel, LVarA, LVar0, 0, -1, 0)
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(ResetPartnerTetherDistance)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

MATCHING_BSS(0x7AB0);
