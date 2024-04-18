#include "obk_01.h"
#include "model.h"
#include "sprite/player.h"

#include "world/common/EnableCameraFollowPlayerY.inc.c"
#include "world/common/DisableCameraFollowPlayerY.inc.c"

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
            sfx_play_sound_at_player(SOUND_OBK_CHANDELIER_SWING, SOUND_SPACE_DEFAULT);
        }
        chandelier->swingAngle = nextSwingAngle;
    }

    // chain lowering sounds
    if (!script->functionTemp[2]) {
        // is chain moving?
        if (chandelier->dropDistance != lastDropDistance) {
            sfx_play_sound_at_position(SOUND_LOOP_OBK_LOWER_CHAIN, SOUND_SPACE_DEFAULT, 440.0f, chandelier->dropDistance, 271.0f);
            script->functionTemp[2] = TRUE;
        }
    } else {
        // is chain done moving?
        if (chandelier->dropDistance == lastDropDistance) {
            sfx_stop_sound(SOUND_LOOP_OBK_LOWER_CHAIN);
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
            sfx_play_sound_at_position(SOUND_LOOP_MOVE_STATUE, SOUND_SPACE_DEFAULT, x, y, z);
            script->functionTemp[3] = TRUE;
        }
    } else {
        // is cabinet done moving?
        if (cabinetPos == script->varTable[1]) {
            sfx_stop_sound(SOUND_LOOP_MOVE_STATUE);
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
    Call(N(UpdateChandelier), LVar0)
    Return
    End
};

EvtScript N(EVS_ManageCabinetPosition) = {
    Label(10)
        IfNe(AF_OBK01_CabinetMoved, FALSE)
            Goto(30)
        EndIf
        Set(LVar0, MV_CabinetPosOffset)
        IfEq(LVar0, 0)
            Goto(20)
        EndIf
        Add(LVar0, 3)
        IfLt(LVar0, 0)
            Goto(20)
        EndIf
        Set(LVar0, 0)
        Label(20)
        Call(TranslateModel, MODEL_hon1, LVar0, 0, 0)
        Call(TranslateModel, MODEL_hon2, LVar0, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o557)
        Call(UpdateColliderTransform, COLLIDER_o556)
        Set(MV_CabinetPosOffset, LVar0)
        Label(30)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_Couch_AnimateCushion) = {
    Call(TranslateModel, LVar8, 0, -1, 0)
    Wait(1)
    Call(TranslateModel, LVar8, 0, -2, 0)
    Wait(1)
    Call(MakeLerp, 0, 20, 3, EASING_COS_FAST_OVERSHOOT)
    Label(1)
        Call(UpdateLerp)
        Call(TranslateModel, LVar8, -100, 0, 0)
        Call(RotateModel, LVar8, LVar0, 0, 0, 1)
        Call(TranslateModel, LVar8, 100, 0, 0)
        Wait(1)
        IfNe(LVar1, 0)
            Goto(1)
        EndIf
    Call(MakeLerp, 20, 0, 10, EASING_QUADRATIC_OUT)
    Label(2)
        Call(UpdateLerp)
        Call(TranslateModel, LVar8, -100, 0, 0)
        Call(RotateModel, LVar8, LVar0, 0, 0, 1)
        Call(TranslateModel, LVar8, 100, 0, 0)
        Wait(1)
        IfNe(LVar1, 0)
            Goto(2)
        EndIf
    Return
    End
};

EvtScript N(EVS_Couch_AnimateSpring) = {
    Wait(2)
    Call(MakeLerp, 10, 25, 3, EASING_COS_FAST_OVERSHOOT)
    Label(5)
        Set(LVar2, LVar0)
        Sub(LVar2, 10)
        Call(UpdateLerp)
        Set(LVar3, LVar0)
        MulF(LVar3, Float(0.1))
        Call(ScaleModel, LVar8, Float(1.0), LVar3, Float(1.0))
        Call(RotateModel, LVar8, LVar2, 0, 0, 1)
        Wait(1)
        IfNe(LVar1, 0)
            Goto(5)
        EndIf
    Call(MakeLerp, 25, 10, 10, EASING_QUADRATIC_OUT)
    Label(6)
        Call(UpdateLerp)
        Set(LVar2, LVar0)
        Sub(LVar2, 10)
        Set(LVar3, LVar0)
        MulF(LVar3, Float(0.1))
        Call(ScaleModel, LVar8, Float(1.0), LVar3, Float(1.0))
        Call(RotateModel, LVar8, LVar2, 0, 0, 1)
        Wait(1)
        IfNe(LVar1, 0)
            Goto(6)
        EndIf
    Return
    End
};

EvtScript N(EVS_LaunchFromCouch_GrabChandelier) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(InterruptUsePartner)
    Loop(0)
        Wait(1)
        Call(GetPlayerActionState, LVar8)
        IfEq(LVar8, ACTION_STATE_IDLE)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerPhysics, TRUE)
    Set(LVarA, LVar0)
    UseArray(LVar0)
    Set(CONTROL_DATA_8, FALSE)
    Set(LVar8, MODEL_tobu1)
    Exec(N(EVS_Couch_AnimateCushion))
    Call(PlaySoundAtCollider, COLLIDER_o567, SOUND_SPRING, SOUND_SPACE_DEFAULT)
    Set(LVar8, MODEL_bane1)
    Exec(N(EVS_Couch_AnimateSpring))
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    Wait(1)
    Call(N(EnableCameraFollowPlayerY))
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Sub(LVar3, 1)
    Call(SetPlayerPos, LVar2, LVar3, LVar4)
    Wait(1)
    Sub(LVar3, 1)
    Call(SetPlayerPos, LVar2, LVar3, LVar4)
    Wait(1)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, -420, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(10.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Wait(1)
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
        Call(SetCamDistance, CAM_DEFAULT, 750)
        Call(SetPanTarget, CAM_DEFAULT, 455, -210, 279)
    EndThread
    Call(SetPlayerJumpscale, Float(0.8))
    Call(PlayerJump, 455, -135, 279, 30)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(SetPlayerPos, 445, -135, 279)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_MarioW2_HoldOnto)
    Wait(1)
    Set(AF_OBK01_CabinetMoved, TRUE)
    Thread
        Wait(60)
        Call(MakeLerp, 0, -100, 100, EASING_LINEAR)
        Label(10)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_hon1, LVar0, 0, 0)
        Call(TranslateModel, MODEL_hon2, LVar0, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o557)
        Call(UpdateColliderTransform, COLLIDER_o556)
        Set(MV_CabinetPosOffset, LVar0)
        Wait(1)
        IfEq(AF_OBK01_CabinetMoved, FALSE)
            Goto(15)
        EndIf
        IfNe(LVar1, 0)
            Goto(10)
        EndIf
        Label(15)
    EndThread
    Set(CONTROL_DATA_STATE, CONTROL_STATE_DROP)
    ChildThread
        Wait(30)
        Call(SetCamDistance, CAM_DEFAULT, 450)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
        Call(SetPanTarget, CAM_DEFAULT, 455, -420, 279)
    EndChildThread
    Call(N(ChandelierTryRelease), LVarA)
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Goto(35)
    EndIf
    IfNe(LVar0, -1)
        Goto(40)
    EndIf
    Label(35)
    Call(CloseChoicePopup)
    Label(39)
    Set(CONTROL_DATA_STATE, CONTROL_STATE_RETRACT)
    Set(CONTROL_DATA_8, TRUE)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
        Call(SetPanTarget, CAM_DEFAULT, LVar0, -420, LVar2)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Thread
        Wait(30)
        Set(AF_OBK01_CabinetMoved, FALSE)
    EndThread
    Return
    Label(40)
    Call(FindKeyItem, ITEM_BOO_WEIGHT, LVar1)
    Call(RemoveKeyItemAt, LVar1)
    Call(MakeItemEntity, LVar0, 447, -350, 278, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(GB_StoryProgress, STORY_CH3_WEIGHED_DOWN_CHANDELIER)
    Call(CloseChoicePopup)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    BindTrigger(Ref(N(EVS_LaunchFromCouch_Crash)), TRIGGER_FLOOR_TOUCH, COLLIDER_o567, 1, 0)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

EvtScript N(EVS_TetherCameraToPlayer) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_LaunchFromCouch_Crash) = {
    Call(DisablePlayerInput, TRUE)
    Call(InterruptUsePartner)
    Call(DisablePartnerAI, 0)
    Loop(0)
        Wait(1)
        Call(GetPlayerActionState, LVar0)
        IfEq(LVar0, ACTION_STATE_IDLE)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerPhysics, TRUE)
    Set(LVar8, MODEL_tobu1)
    Exec(N(EVS_Couch_AnimateCushion))
    Call(PlaySoundAtCollider, COLLIDER_o567, SOUND_SPRING, SOUND_SPACE_DEFAULT)
    Set(LVar8, MODEL_bane1)
    Exec(N(EVS_Couch_AnimateSpring))
    Call(SetPlayerActionState, ACTION_STATE_JUMP)
    ExecGetTID(N(EVS_TetherCameraToPlayer), LVarA)
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Sub(LVar3, 1)
    Call(SetPlayerPos, LVar2, LVar3, LVar4)
    Wait(1)
    Sub(LVar3, 1)
    Call(SetPlayerPos, LVar2, LVar3, LVar4)
    Wait(1)
    Call(SetPlayerJumpscale, Float(0.4))
    Call(PlayerJump, 51, -210, 87, 60)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    Call(PlaySoundAtPlayer, SOUND_TRIP, SOUND_SPACE_DEFAULT)
    Call(SetPlayerAnimation, ANIM_MarioW2_Collapse)
    Wait(30)
    Call(SetPlayerAnimation, ANIM_Mario1_GetUp)
    Wait(20)
    Call(SetPlayerAnimation, ANIM_Mario1_DustOff)
    Wait(7)
    Call(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
    Wait(8)
    Call(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
    Wait(15)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    KillThread(LVarA)
    Call(DisablePlayerPhysics, FALSE)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Wait(1)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupChandelier) = {
    MallocArray(3, LVarA)
    Set(CONTROL_DATA_PTR, NULL)
    Set(CONTROL_DATA_STATE, CONTROL_STATE_WAITING)
    Set(CONTROL_DATA_8, FALSE)
    Call(ParentColliderToModel, COLLIDER_o557, MODEL_hon1)
    Call(ParentColliderToModel, COLLIDER_o556, MODEL_hon2)
    Call(ParentColliderToModel, COLLIDER_tobu_1_1, MODEL_tobu_1_1)
    Call(ParentColliderToModel, COLLIDER_o567, MODEL_tobu1)
    Call(ParentColliderToModel, COLLIDER_tabu_3_1, MODEL_tobu_3_1)
    IfGe(GB_StoryProgress, STORY_CH3_WEIGHED_DOWN_CHANDELIER)
        Set(LVar0, -100)
        Call(TranslateModel, MODEL_hon1, LVar0, 0, 0)
        Call(TranslateModel, MODEL_hon2, LVar0, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o557)
        Call(UpdateColliderTransform, COLLIDER_o556)
        Set(LVar0, -220)
        Call(TranslateModel, MODEL_kusari_1, 0, LVar0, 0)
        Call(TranslateModel, MODEL_kusari_2, 0, LVar0, 0)
        Call(TranslateModel, MODEL_wa, 0, LVar0, 0)
        Call(TranslateModel, MODEL_hi, 0, LVar0, 0)
        Call(MakeItemEntity, ITEM_BOO_WEIGHT, 447, -350, 278, ITEM_SPAWN_MODE_DECORATION, 0)
        BindTrigger(Ref(N(EVS_LaunchFromCouch_Crash)), TRIGGER_FLOOR_TOUCH, COLLIDER_o567, 1, 0)
    Else
        Set(MV_UnusedPosOffset, 0)
        Set(MV_CabinetPosOffset, 0)
        Exec(N(EVS_ManageCabinetPosition))
        Set(LVar0, LVarA)
        Exec(N(EVS_ManageChandelierPosition))
        Set(LVar0, LVarA)
        BindPadlock(Ref(N(EVS_LaunchFromCouch_GrabChandelier)), TRIGGER_FLOOR_TOUCH, COLLIDER_o567, Ref(N(ItemList_BooWeight)), 0, 1)
    EndIf
    Return
    End
};
