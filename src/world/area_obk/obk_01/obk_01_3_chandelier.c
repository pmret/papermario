#include "obk_01.h"

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"
#include "world/common/todo/SetCamera0MoveFlag1.inc.c"

extern EvtScript N(EVS_LaunchFromCouch_Crash);

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

API_CALLABLE(func_80240098_BBD238);
INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD1A0", func_80240098_BBD238);

// unused
API_CALLABLE(N(func_802406AC_BBD84C)) {
    Bytecode* args = script->ptrReadPos;
    s32* var; // TODO what is this?

    if (isInitialCall) {
        var = (s32*) evt_get_variable(script, *args++);
        script->functionTemp[1] = *var;
    }

    var = script->functionTempPtr[1];
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        if (*var & 4) {
            script->varTable[0] = 1;
        } else {
            script->varTable[0] = 0;
        }
        *var &= ~2;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80240730_BBD8D0)) {
    Bytecode* args = script->ptrReadPos;
    s32* var; // TODO what is this?

    if (isInitialCall) {
        var = (s32*) evt_get_variable(script, *args++);
        script->functionTemp[1] = *var;
    }

    var = script->functionTempPtr[1];
    if (*var & 4) {
        *var &= ~2;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

s32 N(ItemList_BooWeight)[] = {
    ITEM_BOO_WEIGHT,
    ITEM_NONE
};

s32 D_80241C58_BBEDF8[] = {
    MODEL_kusari_1,
    MODEL_kusari_2,
    MODEL_wa,
    MODEL_hi 
};

EvtScript N(EVS_ManageChandelierPosition) = {
    EVT_CALL(func_80240098_BBD238, LVar0)
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
    EVT_SET(ArrayVar(2), 0)
    EVT_SET(LVar8, MODEL_tobu1)
    EVT_EXEC(N(EVS_Couch_AnimateCushion))
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o567, SOUND_2086, 0)
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_8000D)
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
    EVT_SET(ArrayVar(1), 1)
    EVT_CHILD_THREAD
        EVT_WAIT(30)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 455, -420, 279)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(func_80240730_BBD8D0), LVarA)
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
    EVT_SET(ArrayVar(1), 2)
    EVT_SET(ArrayVar(2), 1)
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
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o567, SOUND_2086, 0)
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
    EVT_CALL(PlaySoundAtPlayer, SOUND_162, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80003)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_GetUp)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_DustOff)
    EVT_WAIT(7)
    EVT_CALL(PlaySoundAtPlayer, SOUND_DUST_OFF, 0)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtPlayer, SOUND_DUST_OFF, 0)
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
    EVT_SET(ArrayVar(0), 0)
    EVT_SET(ArrayVar(1), 0)
    EVT_SET(ArrayVar(2), 0)
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
