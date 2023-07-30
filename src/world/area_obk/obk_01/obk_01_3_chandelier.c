#include "obk_01.h"
#include "model.h"
#include "sprite/player.h"

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"
#include "world/common/todo/SetCamera0MoveFlag1.inc.c"

extern EvtScript N(EVS_LaunchFromCouch_Crash);

s32 N(ItemList_BooWeight)[] = {
    ITEM_BOO_WEIGHT,
    ITEM_NONE
};

s32 N(ChandelierModels)[] = {
    MODEL_kusari_1,
    MODEL_kusari_2,
    MODEL_wa,
    MODEL_hi
};

API_CALLABLE(N(SetCameraVFOV)) {
    Bytecode* args = script->ptrReadPos;

    gCameras[CAM_DEFAULT].vfov = (s32) evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CheckForAPress)) {
    u32 pressedButtons = gGameStatusPtr->pressedButtons[0];
    s32 pressed;

    if (pressedButtons & BUTTON_A) {
        pressed = TRUE;
    } else {
        pressed = FALSE;
    }
    script->varTable[6] = pressed;
    return ApiStatus_DONE2;
}

typedef struct Chandelier {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 stateTimeLeft;
    /* 0x08 */ struct ChandelierControlData* controlData;
    /* 0x0C */ f32 swingPhase;
    /* 0x10 */ f32 dropDistance;
    /* 0x14 */ f32 swingAngle;
    /* 0x18 */ f32 swingMagnitude;
    /* 0x1C */ Matrix4f transformMtx;
    /* 0x5C */ Model* models[ARRAY_COUNT(N(ChandelierModels))];
} Chandelier; // size = 0x6C;

enum {
    CHANDELIER_FLAG_SWINGING        = 1,
    CHANDELIER_FLAG_TETHER_PLAYER   = 2,
    CHANDELIER_FLAG_RELEASED_PLAYER = 4,
};

enum {
    CHANDELIER_STATE_IDLE           = 0,    // wait in retracted position
    CHANDELIER_STATE_PRE_DROP       = 1,    // begin swing before dropping
    CHANDELIER_STATE_DROPPING       = 2,    // slowly drop down
    CHANDELIER_STATE_POST_DROP      = 3,    // after drop is complete, slow down swing
    CHANDELIER_STATE_DROPPED        = 4,    // wait in neutral dropped position
    CHANDELIER_STATE_PRE_RETRACT    = 10,   // wait before retracting
    CHANDELIER_STATE_RETRACTING     = 11,   // slowly retract
};

enum {
    CONTROL_STATE_WAITING       = 0,
    CONTROL_STATE_DROP          = 1,
    CONTROL_STATE_RETRACT       = 2,
    CONTROL_STATE_RETRACTING    = 3,
};

typedef struct ChandelierControlData {
    /* 0x00 */ Chandelier* chandelier;
    /* 0x04 */ s32 controlState;
    /* 0x08 */ s32 unk_08;
} ChandelierControlData; // size = 0xC;

// script array mapping for ChandelierControlData struct
enum {
    CONTROL_DATA_PTR    = ArrayVar(0),
    CONTROL_DATA_STATE  = ArrayVar(1),
    CONTROL_DATA_8      = ArrayVar(2),
};

API_CALLABLE(N(UpdateChandelier)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Chandelier* chandelier;
    Model* model;
    Matrix4f tempMtx;
    f32 lastDropDistance;
    f32 nextSwingAngle;
    s32 motionsDone;
    s32 cabinetPos;
    s32 i;

    if (isInitialCall) {
        script->functionTempPtr[1] = chandelier = heap_malloc(sizeof(*chandelier));
        chandelier->controlData = (ChandelierControlData*) evt_get_variable(script, *args++);
        chandelier->controlData->chandelier = chandelier;

        for (i = 0; i < ARRAY_COUNT(chandelier->models); i++) {
            s32 modelID = N(ChandelierModels)[i];
            s32 modelIndex = get_model_list_index_from_tree_index(modelID);
            chandelier->models[i] = get_model_from_list_index(modelIndex);
        }

        model = chandelier->models[0];
        copy_matrix(model->userTransformMtx, chandelier->transformMtx);

        lastDropDistance = 0.0f;
        chandelier->dropDistance = 0.0f;
        chandelier->swingAngle = 0.0f;
        chandelier->swingPhase = 180.0f;
        chandelier->swingMagnitude = 10.0f;
        chandelier->flags = 0;

        script->functionTemp[0] = CHANDELIER_STATE_IDLE;
        script->functionTemp[2] = FALSE;
        script->functionTemp[3] = FALSE;
    }

    chandelier = script->functionTempPtr[1];
    model = chandelier->models[0];
    lastDropDistance = chandelier->dropDistance;

    if (chandelier->controlData->controlState == CONTROL_STATE_RETRACT) {
        script->functionTemp[0] = CHANDELIER_STATE_PRE_RETRACT;
        chandelier->controlData->controlState = CONTROL_STATE_RETRACTING;
        chandelier->stateTimeLeft = 10;
    }

    switch (script->functionTemp[0]) {
        case CHANDELIER_STATE_IDLE:
            if (chandelier->controlData->controlState != CONTROL_STATE_WAITING) {
                lastDropDistance = 0.0f;
                chandelier->stateTimeLeft = 35;
                chandelier->dropDistance = 0.0f;
                chandelier->swingAngle = 0.0f;
                chandelier->swingMagnitude = 10.0f;
                chandelier->swingPhase = 180.0f;
                chandelier->flags |= CHANDELIER_FLAG_TETHER_PLAYER;
                chandelier->flags |= CHANDELIER_FLAG_SWINGING;
                script->functionTemp[0] = CHANDELIER_STATE_PRE_DROP;
            }
            break;
        case CHANDELIER_STATE_PRE_DROP:
            chandelier->stateTimeLeft--;
            if (chandelier->stateTimeLeft == -1) {
                script->functionTemp[0] = CHANDELIER_STATE_DROPPING;
            }
            break;
        case CHANDELIER_STATE_DROPPING:
            chandelier->dropDistance += -1.4666667f;
            if (chandelier->dropDistance < -220.0f) {
                chandelier->dropDistance = -220.0f;
                script->functionTemp[0] = CHANDELIER_STATE_POST_DROP;
            }
            break;
        case CHANDELIER_STATE_POST_DROP:
            chandelier->swingMagnitude -= 0.06666667f;
            if (chandelier->swingMagnitude < 0.0f) {
                chandelier->swingMagnitude = 0.0f;
                script->functionTemp[0] = CHANDELIER_STATE_DROPPED;
                chandelier->flags &= ~CHANDELIER_FLAG_SWINGING;
                chandelier->flags |= CHANDELIER_FLAG_RELEASED_PLAYER;
            }
            break;
        case CHANDELIER_STATE_PRE_RETRACT:
            chandelier->stateTimeLeft--;
            if (chandelier->stateTimeLeft == -1) {
                script->functionTemp[0] = CHANDELIER_STATE_RETRACTING;
            }
            break;
        case CHANDELIER_STATE_RETRACTING:
            motionsDone = 0;
            chandelier->flags &= ~CHANDELIER_FLAG_RELEASED_PLAYER;
            chandelier->dropDistance += 4.0f;
            if (chandelier->dropDistance >= 0.0f) {
                chandelier->dropDistance = 0.0f;
                motionsDone++;
            }
            chandelier->swingMagnitude -= 0.2f;
            if (chandelier->swingMagnitude < 0.0f) {
                chandelier->swingMagnitude = 0.0f;
                chandelier->flags &= ~CHANDELIER_FLAG_SWINGING;
                motionsDone++;
            }
            if (motionsDone == 2) {
                chandelier->controlData->controlState = CONTROL_STATE_WAITING;
                script->functionTemp[0] = CHANDELIER_STATE_IDLE;
            }
            break;
    }

    // manage swing status
    if (chandelier->flags & CHANDELIER_FLAG_SWINGING) {
        chandelier->swingPhase = clamp_angle(chandelier->swingPhase + 3.6f);
        nextSwingAngle = sin_deg(chandelier->swingPhase) * chandelier->swingMagnitude;
        if (chandelier->swingAngle == 0.0f) {
            chandelier->swingAngle = 1.0f;
        }
        // detect direction reversal
        if (nextSwingAngle * chandelier->swingAngle <= 0.0f) {
            sfx_play_sound_at_player(SOUND_9D, SOUND_SPACE_MODE_0);
        }
        chandelier->swingAngle = nextSwingAngle;
    }

    // chain lowering sounds
    if (!script->functionTemp[2]) {
        // is chain moving?
        if (chandelier->dropDistance != lastDropDistance) {
            sfx_play_sound_at_position(SOUND_8000000F, SOUND_SPACE_MODE_0, 440.0f, chandelier->dropDistance, 271.0f);
            script->functionTemp[2] = TRUE;
        }
    } else {
        // is chain done moving?
        if (chandelier->dropDistance == lastDropDistance) {
            sfx_stop_sound(SOUND_8000000F);
            script->functionTemp[2] = FALSE;
        }
    }

    // cabinet moving sounds
    cabinetPos = evt_get_variable(script, MV_CabinetPosOffset);
    if (!script->functionTemp[3]) {
         // is cabinet moving?
        if (cabinetPos != script->varTable[1]) {
            f32 x, y, z;

            get_collider_center(COLLIDER_o557, &x, &y, &z);
            sfx_play_sound_at_position(SOUND_80000010, SOUND_SPACE_MODE_0, x, y, z);
            script->functionTemp[3] = TRUE;
        }
    } else {
        // is cabinet done moving?
        if (cabinetPos == script->varTable[1]) {
            sfx_stop_sound(SOUND_80000010);
            script->functionTemp[3] = FALSE;
        }
    }

    script->varTable[1] = cabinetPos;
    guTranslateF(model->userTransformMtx, 0.0f, chandelier->dropDistance - 300.0f, 0.0f);
    guRotateF(tempMtx, chandelier->swingAngle, 0.0f, 0.0f, 1.0f);
    guMtxCatF(model->userTransformMtx, tempMtx, model->userTransformMtx);
    guTranslateF(tempMtx, 0.0f, 300.0f, 0.0f);
    guMtxCatF(model->userTransformMtx, tempMtx, model->userTransformMtx);
    guMtxCatF(chandelier->transformMtx, model->userTransformMtx, model->userTransformMtx);
    model->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;

    for (i = 1; i < ARRAY_COUNT(chandelier->models); i++) {
        copy_matrix(model->userTransformMtx, chandelier->models[i]->userTransformMtx);
        chandelier->models[i]->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;
    }

    if (chandelier->flags & CHANDELIER_FLAG_TETHER_PLAYER) {
        playerStatus->pos.x = (-sin_deg(chandelier->swingAngle) * (chandelier->dropDistance - 300.0f)) + 445.0f;
        playerStatus->pos.y = ((cos_deg(chandelier->swingAngle) * (chandelier->dropDistance - 300.0f)) - 135.0f) + 300.0f;
        playerStatus->pos.z = 279.0f;
    }
    return ApiStatus_BLOCK;
}

// unused
API_CALLABLE(N(ChandelierTryCancel)) {
    Bytecode* args = script->ptrReadPos;
    Chandelier* chandelier;

    if (isInitialCall) {
        ChandelierControlData* data = (ChandelierControlData*) evt_get_variable(script, *args++);
        script->functionTempPtr[1] = data->chandelier;
    }

    chandelier = script->functionTempPtr[1];
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        if (chandelier->flags & CHANDELIER_FLAG_RELEASED_PLAYER) {
            script->varTable[0] = TRUE;
        } else {
            script->varTable[0] = FALSE;
        }
        chandelier->flags &= ~CHANDELIER_FLAG_TETHER_PLAYER;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(ChandelierTryRelease)) {
    Bytecode* args = script->ptrReadPos;
    Chandelier* chandelier;

    if (isInitialCall) {
        ChandelierControlData* data = (ChandelierControlData*) evt_get_variable(script, *args++);
        script->functionTempPtr[1] = data->chandelier;
    }

    chandelier = script->functionTempPtr[1];
    if (chandelier->flags & CHANDELIER_FLAG_RELEASED_PLAYER) {
        chandelier->flags &= ~CHANDELIER_FLAG_TETHER_PLAYER;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_ManageChandelierPosition) = {
    EVT_CALL(N(UpdateChandelier), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageCabinetPosition) = {
    EVT_LABEL(10)
        EVT_IF_NE(AF_OBK01_CabinetMoved, FALSE)
            EVT_GOTO(30)
        EVT_END_IF
        EVT_SET(LVar0, MV_CabinetPosOffset)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_ADD(LVar0, 3)
        EVT_IF_LT(LVar0, 0)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_SET(LVar0, 0)
        EVT_LABEL(20)
        EVT_CALL(TranslateModel, MODEL_hon1, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_hon2, LVar0, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o557)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o556)
        EVT_SET(MV_CabinetPosOffset, LVar0)
        EVT_LABEL(30)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Couch_AnimateCushion) = {
    EVT_CALL(TranslateModel, LVar8, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(TranslateModel, LVar8, 0, -2, 0)
    EVT_WAIT(1)
    EVT_CALL(MakeLerp, 0, 20, 3, EASING_COS_FAST_OVERSHOOT)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, LVar8, -100, 0, 0)
        EVT_CALL(RotateModel, LVar8, LVar0, 0, 0, 1)
        EVT_CALL(TranslateModel, LVar8, 100, 0, 0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(MakeLerp, 20, 0, 10, EASING_QUADRATIC_OUT)
    EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, LVar8, -100, 0, 0)
        EVT_CALL(RotateModel, LVar8, LVar0, 0, 0, 1)
        EVT_CALL(TranslateModel, LVar8, 100, 0, 0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Couch_AnimateSpring) = {
    EVT_WAIT(2)
    EVT_CALL(MakeLerp, 10, 25, 3, EASING_COS_FAST_OVERSHOOT)
    EVT_LABEL(5)
        EVT_SET(LVar2, LVar0)
        EVT_SUB(LVar2, 10)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar3, LVar0)
        EVT_MULF(LVar3, EVT_FLOAT(0.1))
        EVT_CALL(ScaleModel, LVar8, EVT_FLOAT(1.0), LVar3, EVT_FLOAT(1.0))
        EVT_CALL(RotateModel, LVar8, LVar2, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(5)
        EVT_END_IF
    EVT_CALL(MakeLerp, 25, 10, 10, EASING_QUADRATIC_OUT)
    EVT_LABEL(6)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar2, LVar0)
        EVT_SUB(LVar2, 10)
        EVT_SET(LVar3, LVar0)
        EVT_MULF(LVar3, EVT_FLOAT(0.1))
        EVT_CALL(ScaleModel, LVar8, EVT_FLOAT(1.0), LVar3, EVT_FLOAT(1.0))
        EVT_CALL(RotateModel, LVar8, LVar2, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(6)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LaunchFromCouch_GrabChandelier) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(InterruptUsePartner)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerActionState, LVar8)
        EVT_IF_EQ(LVar8, ACTION_STATE_IDLE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_SET(LVarA, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_SET(CONTROL_DATA_8, FALSE)
    EVT_SET(LVar8, MODEL_tobu1)
    EVT_EXEC(N(EVS_Couch_AnimateCushion))
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o567, SOUND_2086, SOUND_SPACE_MODE_0)
    EVT_SET(LVar8, MODEL_bane1)
    EVT_EXEC(N(EVS_Couch_AnimateSpring))
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_CALL(N(UnsetCamera0MoveFlag1))
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_SUB(LVar3, 1)
    EVT_CALL(SetPlayerPos, LVar2, LVar3, LVar4)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 1)
    EVT_CALL(SetPlayerPos, LVar2, LVar3, LVar4)
    EVT_WAIT(1)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, -420, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(10.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_WAIT(1)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 750)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 455, -210, 279)
    EVT_END_THREAD
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.8))
    EVT_CALL(PlayerJump, 455, -135, 279, 30)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(SetPlayerPos, 445, -135, 279)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_HoldOnto)
    EVT_WAIT(1)
    EVT_SET(AF_OBK01_CabinetMoved, TRUE)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(MakeLerp, 0, -100, 100, EASING_LINEAR)
        EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_hon1, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_hon2, LVar0, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o557)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o556)
        EVT_SET(MV_CabinetPosOffset, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(AF_OBK01_CabinetMoved, FALSE)
            EVT_GOTO(15)
        EVT_END_IF
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_LABEL(15)
    EVT_END_THREAD
    EVT_SET(CONTROL_DATA_STATE, CONTROL_STATE_DROP)
    EVT_CHILD_THREAD
        EVT_WAIT(30)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 455, -420, 279)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(ChandelierTryRelease), LVarA)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(35)
    EVT_END_IF
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(40)
    EVT_END_IF
    EVT_LABEL(35)
    EVT_CALL(CloseChoicePopup)
    EVT_LABEL(39)
    EVT_SET(CONTROL_DATA_STATE, CONTROL_STATE_RETRACT)
    EVT_SET(CONTROL_DATA_8, TRUE)
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, -420, LVar2)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_SET(AF_OBK01_CabinetMoved, FALSE)
    EVT_END_THREAD
    EVT_RETURN
    EVT_LABEL(40)
    EVT_CALL(FindKeyItem, ITEM_BOO_WEIGHT, LVar1)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(MakeItemEntity, LVar0, 447, -350, 278, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(GB_StoryProgress, STORY_CH3_WEIGHED_DOWN_CHANDELIER)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_LaunchFromCouch_Crash)), TRIGGER_FLOOR_TOUCH, COLLIDER_o567, 1, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TetherCameraToPlayer) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LaunchFromCouch_Crash) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerActionState, LVar0)
        EVT_IF_EQ(LVar0, ACTION_STATE_IDLE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_SET(LVar8, MODEL_tobu1)
    EVT_EXEC(N(EVS_Couch_AnimateCushion))
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o567, SOUND_2086, SOUND_SPACE_MODE_0)
    EVT_SET(LVar8, MODEL_bane1)
    EVT_EXEC(N(EVS_Couch_AnimateSpring))
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_EXEC_GET_TID(N(EVS_TetherCameraToPlayer), LVarA)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_SUB(LVar3, 1)
    EVT_CALL(SetPlayerPos, LVar2, LVar3, LVar4)
    EVT_WAIT(1)
    EVT_SUB(LVar3, 1)
    EVT_CALL(SetPlayerPos, LVar2, LVar3, LVar4)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.4))
    EVT_CALL(PlayerJump, 51, -210, 87, 60)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtPlayer, SOUND_162, SOUND_SPACE_MODE_0)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Collapse)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_GetUp)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_DustOff)
    EVT_WAIT(7)
    EVT_CALL(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_MODE_0)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_MODE_0)
    EVT_WAIT(15)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupChandelier) = {
    EVT_MALLOC_ARRAY(3, LVarA)
    EVT_SET(CONTROL_DATA_PTR, NULL)
    EVT_SET(CONTROL_DATA_STATE, CONTROL_STATE_WAITING)
    EVT_SET(CONTROL_DATA_8, FALSE)
    EVT_CALL(ParentColliderToModel, COLLIDER_o557, MODEL_hon1)
    EVT_CALL(ParentColliderToModel, COLLIDER_o556, MODEL_hon2)
    EVT_CALL(ParentColliderToModel, COLLIDER_tobu_1_1, MODEL_tobu_1_1)
    EVT_CALL(ParentColliderToModel, COLLIDER_o567, MODEL_tobu1)
    EVT_CALL(ParentColliderToModel, COLLIDER_tabu_3_1, MODEL_tobu_3_1)
    EVT_IF_GE(GB_StoryProgress, STORY_CH3_WEIGHED_DOWN_CHANDELIER)
        EVT_SET(LVar0, -100)
        EVT_CALL(TranslateModel, MODEL_hon1, LVar0, 0, 0)
        EVT_CALL(TranslateModel, MODEL_hon2, LVar0, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o557)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o556)
        EVT_SET(LVar0, -220)
        EVT_CALL(TranslateModel, MODEL_kusari_1, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_kusari_2, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_wa, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_hi, 0, LVar0, 0)
        EVT_CALL(MakeItemEntity, ITEM_BOO_WEIGHT, 447, -350, 278, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_LaunchFromCouch_Crash)), TRIGGER_FLOOR_TOUCH, COLLIDER_o567, 1, 0)
    EVT_ELSE
        EVT_SET(MV_UnusedPosOffset, 0)
        EVT_SET(MV_CabinetPosOffset, 0)
        EVT_EXEC(N(EVS_ManageCabinetPosition))
        EVT_SET(LVar0, LVarA)
        EVT_EXEC(N(EVS_ManageChandelierPosition))
        EVT_SET(LVar0, LVarA)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_LaunchFromCouch_GrabChandelier)), TRIGGER_FLOOR_TOUCH, COLLIDER_o567, EVT_PTR(N(ItemList_BooWeight)), 0, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
