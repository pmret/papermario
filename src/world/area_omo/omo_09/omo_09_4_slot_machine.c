#include "omo_09.h"
#include "model.h"

enum SlotMatchResult {
    SLOT_MATCH_NONE     = 0,
    SLOT_MATCH_TWO      = 2,
    SLOT_MATCH_THREE    = 3,
};

enum SlotSymbol {
    SYM_SHYGUY          = 1,
    SYM_COIN            = 2,
    SYM_STAR            = 3,
};

enum SlotMachineProgress {
    SLOT_PROGRESS_HIT_ONE       = 2,
    SLOT_PROGRESS_HIT_TWO       = 4,
    SLOT_PROGRESS_HIT_THREE     = 6,
    SLOT_PROGRESS_DISPENSE      = 7,
};

EvtScript N(EVS_SetCam_ViewReels) = {
    EVT_WAIT(8)
    EVT_CALL(N(SetCamera0Flag1000))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 535, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 535, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetCam_ViewPayout) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 535, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 535, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(275.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-30.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

s32 N(HitBlockRecoilOffsets)[] = {
    3, 0, -3, 0,
    2, 0, -2, 0,
    1, 0, -1, 0,
};

EvtScript N(EVS_HitBlockRecoil) = {
    EVT_USE_BUF(EVT_PTR(N(HitBlockRecoilOffsets)))
    EVT_LOOP(12)
        EVT_BUF_READ1(LVar1)
        EVT_CALL(TranslateModel, LVar0, 0, LVar1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitBlock_SlotStart) = {
    EVT_IF_EQ(MF_HitStartBlock, FALSE)
        EVT_THREAD
            EVT_WAIT(15)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_s1, SOUND_80000015, SOUND_SPACE_MODE_0)
        EVT_END_THREAD
        EVT_SET(MF_HitStartBlock, TRUE)
        EVT_SET(AF_OMO09_StartBlock_DontBlink, TRUE)
        EVT_CALL(EnableModel, MODEL_s1, TRUE)
        EVT_CALL(EnableModel, MODEL_s2, FALSE)
        EVT_SET(LVar0, MODEL_s1)
        EVT_EXEC_WAIT(N(EVS_HitBlockRecoil))
        EVT_CALL(EnableModel, MODEL_s1, FALSE)
        EVT_CALL(EnableModel, MODEL_s2, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitBlock_SlotWheel1) = {
    EVT_IF_EQ(MF_Block1_Hit, FALSE)
        EVT_SET(MF_Block1_Hit, TRUE)
        EVT_ADD(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
        EVT_SET(MV_ProgressOnHitBlock1, MV_SlotMachineProgress)
        EVT_IF_EQ(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_THREE)
            EVT_EXEC(N(EVS_SetCam_ViewReels))
            EVT_SET(MV_SlotMachineProgress, SLOT_PROGRESS_DISPENSE)
        EVT_END_IF
        EVT_SET(AF_OMO09_Block1_DontBlink, TRUE)
        EVT_CALL(EnableModel, MODEL_h1, TRUE)
        EVT_CALL(EnableModel, MODEL_h1_a, FALSE)
        EVT_SET(LVar0, MODEL_h1)
        EVT_EXEC_WAIT(N(EVS_HitBlockRecoil))
        EVT_CALL(EnableModel, MODEL_h1, FALSE)
        EVT_CALL(EnableModel, MODEL_h1_a, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitBlock_SlotWheel2) = {
    EVT_IF_EQ(MF_Block2_Hit, FALSE)
        EVT_SET(MF_Block2_Hit, TRUE)
        EVT_ADD(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
        EVT_SET(MV_ProgressOnHitBlock2, MV_SlotMachineProgress)
        EVT_IF_EQ(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_THREE)
            EVT_EXEC(N(EVS_SetCam_ViewReels))
            EVT_SET(MV_SlotMachineProgress, SLOT_PROGRESS_DISPENSE)
        EVT_END_IF
        EVT_SET(AF_OMO09_Block2_DontBlink, TRUE)
        EVT_CALL(EnableModel, MODEL_h2, TRUE)
        EVT_CALL(EnableModel, MODEL_h2_a, FALSE)
        EVT_SET(LVar0, MODEL_h2)
        EVT_EXEC_WAIT(N(EVS_HitBlockRecoil))
        EVT_CALL(EnableModel, MODEL_h2, FALSE)
        EVT_CALL(EnableModel, MODEL_h2_a, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HitBlock_SlotWheel3) = {
    EVT_IF_EQ(MF_Block3_Hit, FALSE)
        EVT_SET(MF_Block3_Hit, TRUE)
        EVT_ADD(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
        EVT_SET(MV_ProgressOnHitBlock3, MV_SlotMachineProgress)
        EVT_IF_EQ(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_THREE)
            EVT_EXEC(N(EVS_SetCam_ViewReels))
            EVT_SET(MV_SlotMachineProgress, SLOT_PROGRESS_DISPENSE)
        EVT_END_IF
        EVT_SET(AF_OMO09_Block3_DontBlink, TRUE)
        EVT_CALL(EnableModel, MODEL_h3, TRUE)
        EVT_CALL(EnableModel, MODEL_h3_a, FALSE)
        EVT_SET(LVar0, MODEL_h3)
        EVT_EXEC_WAIT(N(EVS_HitBlockRecoil))
        EVT_CALL(EnableModel, MODEL_h3, FALSE)
        EVT_CALL(EnableModel, MODEL_h3_a, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateActiveBlock1) = {
    EVT_SET(MF_Block1_Active, TRUE)
    EVT_SET(LVar2, MV_SlotWheel1_Angle)
    EVT_ADD(LVar2, 360)
    EVT_SET(LVar5, 0)
    EVT_SET(LVar9, 0)
    EVT_CALL(MakeLerp, MV_SlotWheel1_Angle, LVar2, 50, EASING_QUADRATIC_IN)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o864, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o865, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o866, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o867, LVar0, 1, 0, 0)
        EVT_SET(LVar8, LVar0)
        EVT_SUB(LVar8, LVar9)
        EVT_SET(LVar9, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(RandInt, 7, LVar7)
    EVT_MUL(LVar7, 45)
    EVT_ADD(LVar7, 2520)
    EVT_SET(LVar6, LVar7)
    EVT_DIV(LVar6, LVar8)
    EVT_SET(LVar3, LVar2)
    EVT_ADD(LVar3, LVar7)
    EVT_CALL(MakeLerp, LVar2, LVar3, LVar6, EASING_LINEAR)
    EVT_LABEL(5)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o864, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o865, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o866, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o867, LVar0, 1, 0, 0)
        EVT_IF_EQ(MF_Block1_Hit, TRUE)
            EVT_SET(LVar9, LVar0)
            EVT_MOD(LVar9, 45)
            EVT_IF_EQ(LVar9, 0)
                EVT_SUB(MV_ProgressOnHitBlock1, 1)
                EVT_IF_EQ(MV_ProgressOnHitBlock1, 0)
                    EVT_GOTO(10)
                EVT_END_IF
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                EVT_SET(MF_Block1_Hit, TRUE)
                EVT_ADD(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
                EVT_SET(MV_ProgressOnHitBlock1, MV_SlotMachineProgress)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(5)
    EVT_LABEL(10)
    EVT_IF_EQ(MF_Block1_Hit, TRUE)
        EVT_SET(LVar3, LVar0)
    EVT_END_IF
    EVT_SET(LVar4, LVar3)
    EVT_ADD(LVar4, 1080)
    EVT_CALL(MakeLerp, LVar3, LVar4, 40, EASING_QUADRATIC_OUT)
    EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o864, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o865, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o866, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o867, LVar0, 1, 0, 0)
        EVT_IF_NE(LVar3, LVar0)
            EVT_WAIT(1)
        EVT_END_IF
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_SET(MF_Block1_Hit, TRUE)
    EVT_SET(MF_Block1_Active, FALSE)
    EVT_SET(MV_SlotWheel1_Angle, LVar4)
    EVT_IF_EQ(AB_OMO09_IsPlayerNearSlotMachine, TRUE)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_h1, SOUND_3F3, SOUND_SPACE_MODE_0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateActiveBlock2) = {
    EVT_SET(MF_Block2_Active, TRUE)
    EVT_SET(LVar2, MV_SlotWheel2_Angle)
    EVT_ADD(LVar2, 360)
    EVT_SET(LVar5, 0)
    EVT_SET(LVar9, 0)
    EVT_CALL(MakeLerp, MV_SlotWheel2_Angle, LVar2, 50, EASING_QUADRATIC_IN)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o868, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o869, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o870, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o871, LVar0, 1, 0, 0)
        EVT_SET(LVar8, LVar0)
        EVT_SUB(LVar8, LVar9)
        EVT_SET(LVar9, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(RandInt, 7, LVar7)
    EVT_MUL(LVar7, 45)
    EVT_ADD(LVar7, 3240)
    EVT_SET(LVar6, LVar7)
    EVT_DIV(LVar6, LVar8)
    EVT_SET(LVar3, LVar2)
    EVT_ADD(LVar3, LVar7)
    EVT_CALL(MakeLerp, LVar2, LVar3, LVar6, EASING_LINEAR)
    EVT_LABEL(5)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o868, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o869, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o870, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o871, LVar0, 1, 0, 0)
        EVT_IF_EQ(MF_Block2_Hit, TRUE)
            EVT_SET(LVar9, LVar0)
            EVT_MOD(LVar9, 45)
            EVT_IF_EQ(LVar9, 0)
                EVT_SUB(MV_ProgressOnHitBlock2, 1)
                EVT_IF_EQ(MV_ProgressOnHitBlock2, 0)
                    EVT_GOTO(10)
                EVT_END_IF
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                EVT_SET(MF_Block2_Hit, TRUE)
                EVT_ADD(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
                EVT_SET(MV_ProgressOnHitBlock2, MV_SlotMachineProgress)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(5)
    EVT_LABEL(10)
    EVT_IF_EQ(MF_Block2_Hit, TRUE)
        EVT_SET(LVar3, LVar0)
    EVT_END_IF
    EVT_SET(LVar4, LVar3)
    EVT_ADD(LVar4, 1080)
    EVT_CALL(MakeLerp, LVar3, LVar4, 40, EASING_QUADRATIC_OUT)
    EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o868, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o869, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o870, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o871, LVar0, 1, 0, 0)
        EVT_IF_NE(LVar3, LVar0)
            EVT_WAIT(1)
        EVT_END_IF
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_SET(MF_Block2_Hit, TRUE)
    EVT_SET(MF_Block2_Active, FALSE)
    EVT_SET(MV_SlotWheel2_Angle, LVar4)
    EVT_IF_EQ(AB_OMO09_IsPlayerNearSlotMachine, TRUE)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_h2, SOUND_3F3, SOUND_SPACE_MODE_0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateActiveBlock3) = {
    EVT_SET(MF_Block3_Active, TRUE)
    EVT_SET(LVar2, MV_SlotWheel3_Angle)
    EVT_ADD(LVar2, 360)
    EVT_SET(LVar5, 0)
    EVT_SET(LVar9, 0)
    EVT_CALL(MakeLerp, MV_SlotWheel3_Angle, LVar2, 50, EASING_QUADRATIC_IN)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o872, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o873, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o874, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o875, LVar0, 1, 0, 0)
        EVT_SET(LVar8, LVar0)
        EVT_SUB(LVar8, LVar9)
        EVT_SET(LVar9, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(RandInt, 7, LVar7)
    EVT_MUL(LVar7, 45)
    EVT_ADD(LVar7, 3960)
    EVT_SET(LVar6, LVar7)
    EVT_DIV(LVar6, LVar8)
    EVT_SET(LVar3, LVar2)
    EVT_ADD(LVar3, LVar7)
    EVT_CALL(MakeLerp, LVar2, LVar3, LVar6, EASING_LINEAR)
    EVT_LABEL(5)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o872, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o873, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o874, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o875, LVar0, 1, 0, 0)
        EVT_IF_EQ(MF_Block3_Hit, TRUE)
            EVT_SET(LVar9, LVar0)
            EVT_MOD(LVar9, 45)
            EVT_IF_EQ(LVar9, 0)
                EVT_SUB(MV_ProgressOnHitBlock3, 1)
                EVT_IF_EQ(MV_ProgressOnHitBlock3, 0)
                    EVT_GOTO(10)
                EVT_END_IF
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                EVT_SET(MF_Block3_Hit, TRUE)
                EVT_ADD(MV_SlotMachineProgress, SLOT_PROGRESS_HIT_ONE)
                EVT_SET(MV_ProgressOnHitBlock3, MV_SlotMachineProgress)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(5)
    EVT_LABEL(10)
    EVT_IF_EQ(MF_Block3_Hit, TRUE)
        EVT_SET(LVar3, LVar0)
    EVT_END_IF
    EVT_SET(LVar4, LVar3)
    EVT_ADD(LVar4, 1080)
    EVT_CALL(MakeLerp, LVar3, LVar4, 40, EASING_QUADRATIC_OUT)
    EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o872, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o873, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o874, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o875, LVar0, 1, 0, 0)
        EVT_IF_NE(LVar3, LVar0)
            EVT_WAIT(1)
        EVT_END_IF
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_SET(MF_Block3_Hit, TRUE)
    EVT_SET(MF_Block3_Active, FALSE)
    EVT_SET(MV_SlotWheel3_Angle, LVar4)
    EVT_IF_EQ(AB_OMO09_IsPlayerNearSlotMachine, TRUE)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_h3, SOUND_3F3, SOUND_SPACE_MODE_0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

//TODO these should be a 3x8 array
s32 N(ReelContents)[] = {
    SYM_SHYGUY, SYM_STAR, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN,
    SYM_SHYGUY, SYM_STAR, SYM_SHYGUY, SYM_COIN, SYM_STAR,   SYM_COIN, SYM_SHYGUY, SYM_COIN,
    SYM_SHYGUY, SYM_STAR, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN, SYM_SHYGUY, SYM_COIN,
};

// returns the SlotMatchResult on LVarA and SlotSymbol on LVarB (only valid if SlotMatchResult != SLOT_MATCH_NONE)
API_CALLABLE(N(CheckSlotsResult)) {
    Bytecode* args = script->ptrReadPos;
    s32 angleReel1 = evt_get_variable(script, *args++);
    s32 angleReel2 = evt_get_variable(script, *args++);
    s32 angleReel3 = evt_get_variable(script, *args++);
    s32 results[3];
    s32 a, b;
    s32 i, j;

    // get results from completed reels
    if (angleReel1 != -1) {
        results[0] = N(ReelContents)[(angleReel1 % 360) / 45];
    } else {
        results[0] = 0;
    }
    if (angleReel2 != -1) {
        results[1] = N(ReelContents)[((angleReel2 % 360) / 45) + 8];
    } else {
        results[1] = 0;
    }
    if (angleReel3 != -1) {
        results[2] = N(ReelContents)[((angleReel3 % 360) / 45) + 16];
    } else {
        results[2] = 0;
    }

    // sort and categorize resulting matches
    for (i = 0; i < ARRAY_COUNT(results) - 1; i++) {
        for (j = 1; j < ARRAY_COUNT(results); j++) {
            a = results[i];
            b = results[j];
            if (b < a) {
                results[i] = b;
                results[j] = a;
            }
        }
    }
    if (results[1] == results[0]) {
        if (results[1] == results[2]) {
            script->varTable[10] = SLOT_MATCH_THREE;
        } else {
            script->varTable[10] = SLOT_MATCH_TWO;
        }
    } else if (results[1] == results[2]) {
        script->varTable[10] = SLOT_MATCH_TWO;
    } else {
        script->varTable[10] = SLOT_MATCH_NONE;
    }
    script->varTable[11] = results[1];
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Block1_UpdateBlinking) = {
    EVT_SET(AF_OMO09_Block1_DontBlink, FALSE)
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(EnableModel, MODEL_h1, TRUE)
            EVT_CALL(EnableModel, MODEL_h1_a, FALSE)
            EVT_SET(LVar0, 1)
        EVT_ELSE
            EVT_CALL(EnableModel, MODEL_h1, FALSE)
            EVT_CALL(EnableModel, MODEL_h1_a, TRUE)
            EVT_SET(LVar0, 0)
        EVT_END_IF
        EVT_LOOP(10)
            EVT_WAIT(1)
            EVT_IF_EQ(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                EVT_SET(AF_OMO09_Block1_DontBlink, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_IF_EQ(AF_OMO09_Block1_DontBlink, FALSE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Block2_UpdateBlinking) = {
    EVT_SET(AF_OMO09_Block2_DontBlink, FALSE)
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(EnableModel, MODEL_h2, TRUE)
            EVT_CALL(EnableModel, MODEL_h2_a, FALSE)
            EVT_SET(LVar0, 1)
        EVT_ELSE
            EVT_CALL(EnableModel, MODEL_h2, FALSE)
            EVT_CALL(EnableModel, MODEL_h2_a, TRUE)
            EVT_SET(LVar0, 0)
        EVT_END_IF
        EVT_LOOP(10)
            EVT_WAIT(1)
            EVT_IF_EQ(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                EVT_SET(AF_OMO09_Block2_DontBlink, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_IF_EQ(AF_OMO09_Block2_DontBlink, FALSE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Block3_UpdateBlinking) = {
    EVT_SET(AF_OMO09_Block3_DontBlink, FALSE)
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(EnableModel, MODEL_h3, TRUE)
            EVT_CALL(EnableModel, MODEL_h3_a, FALSE)
            EVT_SET(LVar0, 1)
        EVT_ELSE
            EVT_CALL(EnableModel, MODEL_h3, FALSE)
            EVT_CALL(EnableModel, MODEL_h3_a, TRUE)
            EVT_SET(LVar0, 0)
        EVT_END_IF
        EVT_LOOP(10)
            EVT_WAIT(1)
            EVT_IF_EQ(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
                EVT_SET(AF_OMO09_Block3_DontBlink, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_IF_EQ(AF_OMO09_Block3_DontBlink, FALSE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartBlock_UpdateBlinking) = {
    EVT_SET(AF_OMO09_StartBlock_DontBlink, FALSE)
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(EnableModel, MODEL_s1, TRUE)
            EVT_CALL(EnableModel, MODEL_s2, FALSE)
            EVT_SET(LVar0, 1)
        EVT_ELSE
            EVT_CALL(EnableModel, MODEL_s1, FALSE)
            EVT_CALL(EnableModel, MODEL_s2, TRUE)
            EVT_SET(LVar0, 0)
        EVT_END_IF
        EVT_WAIT(10)
        EVT_IF_EQ(AF_OMO09_StartBlock_DontBlink, FALSE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_SET(AB_OMO09_IsPlayerNearSlotMachine, TRUE)
    EVT_EXEC(N(EVS_Block1_UpdateBlinking))
    EVT_EXEC(N(EVS_Block2_UpdateBlinking))
    EVT_EXEC(N(EVS_Block3_UpdateBlinking))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SlotMachine_MainUpdate) = {
    EVT_LABEL(0)
    EVT_SET(MF_AnimateSlotLights, FALSE)
    EVT_LABEL(1)
        EVT_WAIT(1)
        EVT_IF_EQ(MF_HitStartBlock, FALSE)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_SET(MF_Block1_Hit, FALSE)
    EVT_SET(MF_Block2_Hit, FALSE)
    EVT_SET(MF_Block3_Hit, FALSE)
    EVT_SET(MV_ProgressOnHitBlock1, 0)
    EVT_SET(MV_ProgressOnHitBlock2, 0)
    EVT_SET(MV_ProgressOnHitBlock3, 0)
    EVT_SET(MV_SlotMachineProgress, 0)
    EVT_EXEC(N(EVS_UpdateActiveBlock1))
    EVT_EXEC(N(EVS_UpdateActiveBlock2))
    EVT_EXEC(N(EVS_UpdateActiveBlock3))
    EVT_WAIT(3)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar2, 0)
    EVT_LABEL(2)
        EVT_CALL(IsPlayerWithin, 525, 0, 500, AB_OMO09_IsPlayerNearSlotMachine)
        EVT_IF_EQ(AB_OMO09_IsPlayerNearSlotMachine, FALSE)
            EVT_CALL(StopSound, SOUND_80000015)
            EVT_WAIT(100)
            EVT_GOTO(99)
        EVT_END_IF
        // how many blocks have been hit?
        EVT_SET(LVar1, MF_Block1_Active)
        EVT_ADD(LVar1, MF_Block2_Active)
        EVT_ADD(LVar1, MF_Block3_Active)
        EVT_IF_EQ(LVar2, 0)
            EVT_SET(LVarA, SLOT_MATCH_NONE)
            EVT_IF_EQ(MF_Block1_Active, FALSE)
                EVT_IF_EQ(MF_Block2_Active, FALSE)
                    EVT_SET(LVar2, 1)
                    EVT_CALL(N(CheckSlotsResult), MV_SlotWheel1_Angle, MV_SlotWheel2_Angle, -1)
                EVT_END_IF
                EVT_IF_EQ(MF_Block3_Active, FALSE)
                    EVT_SET(LVar2, 1)
                    EVT_CALL(N(CheckSlotsResult), MV_SlotWheel1_Angle, -1, MV_SlotWheel3_Angle)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(MF_Block2_Active, FALSE)
                EVT_IF_EQ(MF_Block3_Active, FALSE)
                    EVT_SET(LVar2, 1)
                    EVT_CALL(N(CheckSlotsResult), -1, MV_SlotWheel2_Angle, MV_SlotWheel3_Angle)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_NE(LVarA, SLOT_MATCH_NONE)
                // partial match after two blocks hit
                EVT_SET(MF_AnimateSlotLights, TRUE)
                EVT_CALL(PlaySoundAtCollider, COLLIDER_o881, SOUND_388 | SOUND_ID_TRIGGER_CHANGE_VOLUME, SOUND_SPACE_MODE_0)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
        // wait until all blocks are hit
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(StopSound, SOUND_80000015)
    EVT_WAIT(20)
    EVT_CALL(N(CheckSlotsResult), MV_SlotWheel1_Angle, MV_SlotWheel2_Angle, MV_SlotWheel3_Angle)
    EVT_IF_NE(LVarA, 0)
        EVT_SET(MF_AnimateSlotLights, TRUE)
    EVT_END_IF
    EVT_SET(MV_ResetCamSpeed, EVT_FLOAT(90.0))
    // dispense rewards
    EVT_SWITCH(LVarB)
        EVT_CASE_EQ(SYM_SHYGUY)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(SLOT_MATCH_THREE)
                    EVT_EXEC_WAIT(N(EVS_SetCam_ViewPayout))
                    EVT_THREAD
                        EVT_CALL(SetNpcPos, NPC_ShyGuy_Jackpot1, 485, 130, -50)
                        EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_Jackpot1, EVT_FLOAT(0.8))
                        EVT_CALL(NpcJump0, NPC_ShyGuy_Jackpot1, 460, 0, 50, 30)
                        EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_Jackpot1, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EVT_END_THREAD
                    EVT_THREAD
                        EVT_CALL(SetNpcPos, NPC_ShyGuy_Jackpot2, 510, 130, -50)
                        EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_Jackpot2, EVT_FLOAT(0.8))
                        EVT_CALL(NpcJump0, NPC_ShyGuy_Jackpot2, 497, 0, 50, 30)
                        EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_Jackpot2, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EVT_END_THREAD
                    EVT_THREAD
                        EVT_CALL(SetNpcPos, NPC_ShyGuy_Jackpot3, 535, 130, -50)
                        EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_Jackpot3, EVT_FLOAT(0.8))
                        EVT_CALL(NpcJump0, NPC_ShyGuy_Jackpot3, 535, 0, 50, 30)
                        EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_Jackpot3, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EVT_END_THREAD
                    EVT_THREAD
                        EVT_CALL(SetNpcPos, NPC_ShyGuy_Jackpot4, 560, 130, -50)
                        EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_Jackpot4, EVT_FLOAT(0.8))
                        EVT_CALL(NpcJump0, NPC_ShyGuy_Jackpot4, 573, 0, 50, 30)
                        EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_Jackpot4, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EVT_END_THREAD
                    EVT_THREAD
                        EVT_CALL(SetNpcPos, NPC_ShyGuy_Jackpot5, 585, 130, -50)
                        EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_Jackpot5, EVT_FLOAT(0.8))
                        EVT_CALL(NpcJump0, NPC_ShyGuy_Jackpot5, 610, 0, 50, 30)
                        EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_Jackpot5, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EVT_END_THREAD
                    EVT_WAIT(20)
                EVT_CASE_EQ(SLOT_MATCH_TWO)
                    EVT_EXEC_WAIT(N(EVS_SetCam_ViewPayout))
                    EVT_THREAD
                        EVT_CALL(SetNpcPos, NPC_ShyGuy_Jackpot2, 510, 130, -50)
                        EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_Jackpot2, EVT_FLOAT(0.8))
                        EVT_CALL(NpcJump0, NPC_ShyGuy_Jackpot2, 497, 0, 50, 30)
                        EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_Jackpot2, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EVT_END_THREAD
                    EVT_THREAD
                        EVT_CALL(SetNpcPos, NPC_ShyGuy_Jackpot4, 560, 130, -50)
                        EVT_CALL(SetNpcJumpscale, NPC_ShyGuy_Jackpot4, EVT_FLOAT(0.8))
                        EVT_CALL(NpcJump0, NPC_ShyGuy_Jackpot4, 573, 0, 50, 30)
                        EVT_CALL(SetNpcFlagBits, NPC_ShyGuy_Jackpot4, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
                    EVT_END_THREAD
                    EVT_WAIT(20)
                EVT_CASE_DEFAULT
                    EVT_SET(MV_ResetCamSpeed, EVT_FLOAT(2.0))
            EVT_END_SWITCH
        EVT_CASE_EQ(SYM_COIN)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(SLOT_MATCH_THREE)
                    EVT_EXEC_WAIT(N(EVS_SetCam_ViewPayout))
                    EVT_THREAD
                        EVT_LOOP(2)
                            EVT_SET(LVar1, 480)
                            EVT_LOOP(5)
                                EVT_ADD(LVar1, 20)
                                EVT_CALL(MakeItemEntity, ITEM_COIN, LVar1, 150, 50, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
                                EVT_WAIT(3)
                            EVT_END_LOOP
                        EVT_END_LOOP
                    EVT_END_THREAD
                    EVT_WAIT(30)
                EVT_CASE_EQ(SLOT_MATCH_TWO)
                    EVT_EXEC_WAIT(N(EVS_SetCam_ViewPayout))
                    EVT_CALL(MakeItemEntity, ITEM_COIN, 535, 150, 50, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
                    EVT_WAIT(30)
                EVT_CASE_DEFAULT
                    EVT_SET(MV_ResetCamSpeed, EVT_FLOAT(2.0))
            EVT_END_SWITCH
        EVT_CASE_EQ(SYM_STAR)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(SLOT_MATCH_THREE)
                    EVT_EXEC_WAIT(N(EVS_SetCam_ViewPayout))
                    EVT_THREAD
                        EVT_LOOP(2)
                            EVT_SET(LVar1, 480)
                            EVT_LOOP(5)
                                EVT_ADD(LVar1, 20)
                                EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, LVar1, 150, 50, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
                                EVT_WAIT(3)
                            EVT_END_LOOP
                        EVT_END_LOOP
                    EVT_END_THREAD
                    EVT_WAIT(30)
                EVT_CASE_EQ(SLOT_MATCH_TWO)
                    EVT_EXEC_WAIT(N(EVS_SetCam_ViewPayout))
                    EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, 535, 150, 50, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
                    EVT_WAIT(30)
                EVT_CASE_DEFAULT
                    EVT_SET(MV_ResetCamSpeed, EVT_FLOAT(2.0))
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_CALL(N(UnsetCamera0Flag1000))
    EVT_CALL(ResetCam, CAM_DEFAULT, MV_ResetCamSpeed)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_LOOP(0)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar4, -1)
        EVT_LOOP(5)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_IF_GE(LVar2, 0)
                EVT_SET(LVar4, 0)
            EVT_END_IF
            EVT_ADD(LVar0, 1)
        EVT_END_LOOP
        EVT_IF_NE(LVar4, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(50)
    EVT_LABEL(99)
    EVT_SET(MF_HitStartBlock, FALSE)
    EVT_SET(MF_Block1_Hit, TRUE)
    EVT_SET(MF_Block2_Hit, TRUE)
    EVT_SET(MF_Block3_Hit, TRUE)
    EVT_SET(MF_Block1_Active, FALSE)
    EVT_SET(MF_Block2_Active, FALSE)
    EVT_SET(MF_Block3_Active, FALSE)
    EVT_SET(MF_AnimateSlotLights, FALSE)
    EVT_SET(AF_OMO09_Block1_DontBlink, FALSE)
    EVT_SET(AF_OMO09_Block2_DontBlink, FALSE)
    EVT_SET(AF_OMO09_Block3_DontBlink, FALSE)
    EVT_CALL(EnableModel, MODEL_s1, TRUE)
    EVT_CALL(EnableModel, MODEL_s2, FALSE)
    EVT_EXEC(N(EVS_StartBlock_UpdateBlinking))
    EVT_CALL(EnableModel, MODEL_h1, TRUE)
    EVT_CALL(EnableModel, MODEL_h1_a, FALSE)
    EVT_CALL(EnableModel, MODEL_h2, TRUE)
    EVT_CALL(EnableModel, MODEL_h2_a, FALSE)
    EVT_CALL(EnableModel, MODEL_h3, TRUE)
    EVT_CALL(EnableModel, MODEL_h3_a, FALSE)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(SlotMachineBlocks)[] = {
    MODEL_s1,
    MODEL_h1,
    MODEL_h2,
    MODEL_h3,
};

API_CALLABLE(N(UpdateSlotMachineBlockShadows)) {
    s32 (*shadowIDs)[4];
    Shadow* shadow;
    Model* model;
    f32 x, y, z;
    f32 rotX, rotZ;
    f32 scale;
    u32 i;

    if (isInitialCall) {

        script->functionTempPtr[0] = shadowIDs = heap_malloc(sizeof(*shadowIDs));
        for (i = 0; i < ARRAY_COUNT(N(SlotMachineBlocks)); i++) {
            model = get_model_from_list_index(get_model_list_index_from_tree_index(N(SlotMachineBlocks)[i]));
            (*shadowIDs)[i] = create_shadow_type(1, model->center.x, model->center.y - 100.0f, model->center.z);
        }
    }

    shadowIDs = script->functionTempPtr[0];
    for (i = 0; i < ARRAY_COUNT(N(SlotMachineBlocks)); i++) {
        shadow = get_shadow_by_index((*shadowIDs)[i]);
        model = get_model_from_list_index(get_model_list_index_from_tree_index(N(SlotMachineBlocks)[i]));
        x = model->center.x;
        y = model->center.y;
        z = model->center.z;
        scale = 1000.0f;
        entity_raycast_down(&x, &y, &z, &rotX, &rotZ, &scale);
        set_standard_shadow_scale(shadow, scale);
        shadow->pos.x = x;
        shadow->pos.y = y;
        shadow->pos.z = z;
        shadow->rot.x = rotX;
        shadow->rot.y = 0.0f;
        shadow->rot.z = rotZ;
        shadow->scale.x *= 1.3f;
        shadow->scale.z *= 1.3f;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_SetupSlotMachine) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_s1, MODEL_s1)
    EVT_CALL(ParentColliderToModel, COLLIDER_h1, MODEL_h1)
    EVT_CALL(ParentColliderToModel, COLLIDER_h2, MODEL_h2)
    EVT_CALL(ParentColliderToModel, COLLIDER_h3, MODEL_h3)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBlock_SlotStart)), TRIGGER_CEILING_TOUCH, COLLIDER_s1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBlock_SlotWheel1)), TRIGGER_CEILING_TOUCH, COLLIDER_h1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBlock_SlotWheel2)), TRIGGER_CEILING_TOUCH, COLLIDER_h2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_HitBlock_SlotWheel3)), TRIGGER_CEILING_TOUCH, COLLIDER_h3, 1, 0)
    EVT_CALL(RandInt, 7, MV_SlotWheel1_Angle)
    EVT_MUL(MV_SlotWheel1_Angle, 45)
    EVT_CALL(RotateModel, MODEL_o864, MV_SlotWheel1_Angle, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o865, MV_SlotWheel1_Angle, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o866, MV_SlotWheel1_Angle, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o867, MV_SlotWheel1_Angle, 1, 0, 0)
    EVT_CALL(RandInt, 7, MV_SlotWheel2_Angle)
    EVT_MUL(MV_SlotWheel2_Angle, 45)
    EVT_CALL(RotateModel, MODEL_o868, MV_SlotWheel2_Angle, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o869, MV_SlotWheel2_Angle, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o870, MV_SlotWheel2_Angle, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o871, MV_SlotWheel2_Angle, 1, 0, 0)
    EVT_CALL(RandInt, 7, MV_SlotWheel3_Angle)
    EVT_MUL(MV_SlotWheel3_Angle, 45)
    EVT_CALL(RotateModel, MODEL_o872, MV_SlotWheel3_Angle, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o873, MV_SlotWheel3_Angle, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o874, MV_SlotWheel3_Angle, 1, 0, 0)
    EVT_CALL(RotateModel, MODEL_o875, MV_SlotWheel3_Angle, 1, 0, 0)
    EVT_SET(MF_HitStartBlock, FALSE)
    EVT_SET(MF_Block1_Hit, TRUE)
    EVT_SET(MF_Block2_Hit, TRUE)
    EVT_SET(MF_Block3_Hit, TRUE)
    EVT_SET(MF_Block1_Active, FALSE)
    EVT_SET(MF_Block2_Active, FALSE)
    EVT_SET(MF_Block3_Active, FALSE)
    EVT_SET(MF_AnimateSlotLights, FALSE)
    EVT_CALL(EnableTexPanning, MODEL_o888, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o876, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o884, TRUE)
    EVT_THREAD
        EVT_SET(LVar1, 0)
        EVT_LOOP(0)
            EVT_IF_EQ(MF_AnimateSlotLights, TRUE)
                EVT_ADD(LVar1, -1110)
            EVT_END_IF
            EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, LVar1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(UpdateSlotMachineBlockShadows))
    EVT_END_THREAD
    EVT_CALL(EnableModel, MODEL_s1, TRUE)
    EVT_CALL(EnableModel, MODEL_s2, FALSE)
    EVT_EXEC(N(EVS_StartBlock_UpdateBlinking))
    EVT_CALL(EnableModel, MODEL_h1, TRUE)
    EVT_CALL(EnableModel, MODEL_h1_a, FALSE)
    EVT_CALL(EnableModel, MODEL_h2, TRUE)
    EVT_CALL(EnableModel, MODEL_h2_a, FALSE)
    EVT_CALL(EnableModel, MODEL_h3, TRUE)
    EVT_CALL(EnableModel, MODEL_h3_a, FALSE)
    EVT_EXEC(N(EVS_SlotMachine_MainUpdate))
    EVT_RETURN
    EVT_END
};
