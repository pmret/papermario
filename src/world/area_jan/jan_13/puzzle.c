#include "jan_13.h"
#include "entity.h"
#include "effects.h"
#include "sprite/player.h"

// geyser positions in grid coordinates
#define POS_0_I 28
#define POS_0_J 6
#define POS_1_I 25
#define POS_1_J 4
#define POS_2_I 21
#define POS_2_J 8
#define POS_3_I 4
#define POS_3_J 4
#define POS_4_I 14
#define POS_4_J 6

u16 N(GeyserAnimPhase) = 0;

void N(setup_gfx_geyser)(void) {
    f64 temp_f20 = ((sin_rad((f32) N(GeyserAnimPhase) * 0.02) + 1.0f) * 0.3) + 0.6;
    f64 temp_f21 = (sin_rad((f32) N(GeyserAnimPhase) * 0.1) + 1.0f) * 0.1;
    f32 scale = temp_f20 + temp_f21;

    guScale(&gDisplayContext->matrixStack[gMatrixListPos], (scale * 0.3) + 0.5, scale, (scale * 0.3) + 0.5);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    N(GeyserAnimPhase)++;
}

API_CALLABLE(N(GetRatioFromPercent)) {
    script->varTable[2] = Float_TO_FIXED(script->varTable[1] / 100.0f);
    script->varTable[3] = Float_TO_FIXED(script->varTable[1] / 100.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AdjustEnvSoundPosition)) {
    Bytecode* args = script->ptrReadPos;

    if (*args++ != 0) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        sfx_adjust_env_sound_pos(SOUND_LRAW_JAN_SMALL_GEYSER, SOUND_SPACE_DEFAULT, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetPlayerPosAfterPush)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 posX = script->varTable[0];
    s32 posZ = script->varTable[2];

    if (script->varTable[1] > -100) {
        f32 theta = (playerStatus->targetYaw / 180.0f) * 3.141592f;

        posX -= (s32) (sin_rad(theta) * 25.0f);
        posZ -= (s32) (-cos_rad(theta) * 25.0f);
    } else {
        posZ += 25;
    }
    script->varTable[0] = posX;
    script->varTable[2] = posZ;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ManageSmallGeyser) = {
    Set(LVarA, LVar0) // geyser model
    Set(LVarB, LVar1) // index in solution
    Set(LVarD, LVar2) // central collider
    Set(LVar0, 0)
    Set(LVar1, 0)
    Loop(0)
        // get percent delta
        IfEq(LVarB, MV_PuzzleProgress)
            Add(LVar0, 10)
        Else
            Add(LVar0, -10)
        EndIf
        // clamp delta to [-10, 10]
        IfLt(LVar0, -10)
            Set(LVar0, -10)
        EndIf
        IfGt(LVar0, 10)
            Set(LVar0, 10)
        EndIf
        Add(LVar1, LVar0)
        // clamp percent to [0, 100]
        IfLt(LVar1, 0)
            Set(LVar1, 0)
        EndIf
        IfGt(LVar1, 100)
            Set(LVar1, 100)
        EndIf
        // set geyser scale
        Call(N(GetRatioFromPercent))
        IfEq(LVar1, 0)
            IfNe(LVarD, 0)
            EndIf
            Call(EnableModel, LVarA, FALSE)
        Else
            IfNe(LVarD, 0)
            EndIf
            Call(EnableModel, LVarA, TRUE)
            Call(ScaleModel, LVarA, LVar3, LVar2, LVar3)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(SetLargeGeyserScale) = {
    Call(N(GetRatioFromPercent))
    IfLt(LVar3, Float(1.0))
        SetF(LVar4, LVar3)
    Else
        SetF(LVar4, Float(1.0))
    EndIf
    Call(ScaleModel, LVarA, LVar4, LVar2, LVar3)
    Return
    End
};

EvtScript N(EVS_ManageLargeGeyser) = {
    Set(LVarA, LVar0) // geyser model
    Set(LVarB, LVar1) // index in solution
    Set(LVarD, LVar2) // central collider
    Set(LVar0, 0)
    Set(LVar1, 0)
    IfEq(GF_JAN13_SolvedBlockPuzzle, TRUE)
        Goto(10)
    EndIf
    Loop(0)
        IfEq(MV_PuzzleProgress, 5)
            IfEq(AB_JAN_2, 1)
                Add(LVar0, 10)
            Else
                Add(LVar0, -10)
            EndIf
        Else
            Add(LVar0, -10)
        EndIf
        IfLt(LVar0, -10)
            Set(LVar0, -10)
        EndIf
        IfGt(LVar0, 10)
            Set(LVar0, 10)
        EndIf
        Add(LVar1, LVar0)
        IfLt(LVar1, 50)
            Set(LVar1, 50)
        EndIf
        IfGt(LVar1, 70)
            Set(LVar1, 70)
        EndIf
        IfEq(LVar1, 0)
            Call(EnableModel, LVarA, FALSE)
            Wait(1)
        Else
            Call(EnableModel, LVarA, TRUE)
            ExecWait(N(SetLargeGeyserScale))
        EndIf
        IfEq(AB_JAN_2, 2)
            BreakLoop
        EndIf
    EndLoop
    Set(LVar0, 10)
    Loop(0)
        IfEq(MV_PuzzleProgress, 5)
            Add(LVar1, LVar0)
            IfGt(LVar1, 300)
                Set(LVar1, 300)
            EndIf
            ExecWait(N(SetLargeGeyserScale))
        Else
            Wait(1)
        EndIf
        IfNe(GF_JAN13_SolvedBlockPuzzle, FALSE)
            BreakLoop
        EndIf
    EndLoop
    Set(LVar0, -7)
    Loop(28)
        Add(LVar1, LVar0)
        ExecWait(N(SetLargeGeyserScale))
    EndLoop
    Label(10)
    IfEq(MV_PuzzleProgress, 5)
        Add(LVar0, 10)
    Else
        Add(LVar0, -10)
    EndIf
    IfLt(LVar0, -10)
        Set(LVar0, -10)
    EndIf
    IfGt(LVar0, 10)
        Set(LVar0, 10)
    EndIf
    Add(LVar1, LVar0)
    IfLt(LVar1, 0)
        Set(LVar1, 0)
    EndIf
    IfGt(LVar1, 100)
        Set(LVar1, 100)
    EndIf
    IfEq(LVar1, 0)
        Call(EnableModel, LVarA, FALSE)
        Wait(1)
    Else
        Call(EnableModel, LVarA, TRUE)
        ExecWait(N(SetLargeGeyserScale))
    EndIf
    Goto(10)
    Return
    End
};

Vec3i N(GeyserSoundPositions)[] = {
    { -400 + POS_0_I * BLOCK_GRID_SIZE + (BLOCK_GRID_SIZE / 2), 0, -150 + POS_0_J * BLOCK_GRID_SIZE + (BLOCK_GRID_SIZE / 2) },
    { -400 + POS_1_I * BLOCK_GRID_SIZE + (BLOCK_GRID_SIZE / 2), 0, -150 + POS_1_J * BLOCK_GRID_SIZE + (BLOCK_GRID_SIZE / 2) },
    { -400 + POS_2_I * BLOCK_GRID_SIZE + (BLOCK_GRID_SIZE / 2), 0, -150 + POS_2_J * BLOCK_GRID_SIZE + (BLOCK_GRID_SIZE / 2) },
    { -400 + POS_3_I * BLOCK_GRID_SIZE + (BLOCK_GRID_SIZE / 2), 0, -150 + POS_3_J * BLOCK_GRID_SIZE + (BLOCK_GRID_SIZE / 2) },
    { -400 + POS_4_I * BLOCK_GRID_SIZE + (BLOCK_GRID_SIZE / 2), 0, -150 + POS_4_J * BLOCK_GRID_SIZE + (BLOCK_GRID_SIZE / 2) },
    {   37, 0, -138 },
};

EvtScript N(EVS_ManageGeyserSounds) = {
    IfNe(AB_JAN13_LastPuzzleProgress, MV_PuzzleProgress)
        Set(AB_JAN13_LastPuzzleProgress, MV_PuzzleProgress)
        Set(MF_GeyserSoundPlaying, FALSE)
        Call(StopSound, SOUND_LOOP_JAN_SMALL_GEYSER)
        Call(StopSound, SOUND_LOOP_JAN_LARGE_GEYSER)
        IfEq(MV_PuzzleProgress, 5)
            IfEq(GF_JAN13_SolvedBlockPuzzle, FALSE)
                Return
            EndIf
        Else
            IfEq(MV_PuzzleProgress, 6)
                Return
            EndIf
        EndIf
        Call(PlaySound, SOUND_LOOP_JAN_SMALL_GEYSER)
        Set(MF_GeyserSoundPlaying, TRUE)
        Set(LVar0, MV_PuzzleProgress)
        Add(LVar0, 1)
        UseBuf(Ref(N(GeyserSoundPositions)))
        Loop(LVar0)
            BufRead3(LVar1, LVar2, LVar3)
        EndLoop
        Call(N(AdjustEnvSoundPosition), MF_GeyserSoundPlaying, LVar1, LVar2, LVar3)
    EndIf
    Return
    End
};

EvtScript N(EVS_BoulderTremble) = {
    Call(PlaySoundAtCollider, COLLIDER_o33, SOUND_JAN_BOULDER_TREMBLE, 0)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.5))
    Return
    End
};

EvtScript N(EVS_ManagePuzzle) = {
    Set(LFlag0, FALSE)
    Set(AB_JAN_2, 0)
    Set(AB_JAN13_LastPuzzleProgress, -1)
    Exec(N(EVS_ManageGeyserSounds))
    Label(0)
        IfEq(GF_JAN13_SolvedBlockPuzzle, TRUE)
            IfEq(LFlag0, FALSE)
                Call(EnableModel, MODEL_o33, FALSE)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o33, COLLIDER_FLAGS_UPPER_MASK)
                Call(SetPushBlock, 0, 15, 0, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 16, 0, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 17, 0, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 18, 0, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 19, 0, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 15, 1, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 16, 1, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 17, 1, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 18, 1, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 19, 1, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 15, 2, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 16, 2, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 17, 2, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 18, 2, PUSH_GRID_EMPTY)
                Call(SetPushBlock, 0, 19, 2, PUSH_GRID_EMPTY)
                Set(LFlag0, TRUE)
            EndIf
        EndIf
        Call(GetPushBlock, 0, POS_0_I, POS_0_J, LVar0)
        IfEq(LVar0, 0)
            Set(MV_PuzzleProgress, 0)
            Goto(1)
        EndIf
        Call(GetPushBlock, 0, POS_1_I, POS_1_J, LVar0)
        IfEq(LVar0, 0)
            Set(MV_PuzzleProgress, 1)
            Goto(1)
        EndIf
        Call(GetPushBlock, 0, POS_2_I, POS_2_J, LVar0)
        IfEq(LVar0, 0)
            Set(MV_PuzzleProgress, 2)
            Goto(1)
        EndIf
        Call(GetPushBlock, 0, POS_3_I, POS_3_J, LVar0)
        IfEq(LVar0, 0)
            Set(MV_PuzzleProgress, 3)
            Goto(1)
        EndIf
        Call(GetPushBlock, 0, POS_4_I, POS_4_J, LVar0)
        IfEq(LVar0, 0)
            Set(MV_PuzzleProgress, 4)
            Goto(1)
        EndIf
        IfEq(GF_JAN13_SolvedBlockPuzzle, FALSE)
            Call(DisablePlayerInput, TRUE)
            Call(SetPushBlock, 0, 15, 0, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 16, 0, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 17, 0, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 18, 0, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 19, 0, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 15, 1, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 16, 1, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 17, 1, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 18, 1, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 19, 1, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 15, 2, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 16, 2, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 17, 2, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 18, 2, PUSH_GRID_EMPTY)
            Call(SetPushBlock, 0, 19, 2, PUSH_GRID_EMPTY)
            Set(MV_PuzzleProgress, 5)
            Wait(30)
            Loop(2)
                Exec(N(EVS_BoulderTremble))
                Call(RotateModel, MODEL_o33, 3, 0, Float(0.2), 1)
                Wait(8)
                Call(RotateModel, MODEL_o33, -3, 0, Float(0.2), 1)
                Wait(8)
            EndLoop
            Thread
                Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 20, EMOTER_PLAYER, 0, 0, 0, 0)
                Call(GetModelCenter, MODEL_o33)
                Call(FacePlayerTowardPoint, LVar0, LVar2, 4)
                Call(GetPlayerPos, LVar3, LVar1, LVar2)
                Set(LVar4, LVar0)
                Set(LVar5, LVar0)
                Sub(LVar4, 120)
                Add(LVar5, 120)
                Switch(LVar3)
                    CaseRange(LVar4, LVar5)
                        Add(LVar0, LVar3)
                        Div(LVar0, 2)
                EndSwitch
                Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                Call(SetCamDistance, CAM_DEFAULT, 400)
                Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
                Call(PanToTarget, CAM_DEFAULT, 0, 1)
            EndThread
            Loop(3)
                Exec(N(EVS_BoulderTremble))
                Call(RotateModel, MODEL_o33, 5, 0, Float(0.2), 1)
                Wait(5)
                Call(RotateModel, MODEL_o33, -5, 0, Float(0.2), 1)
                Wait(5)
            EndLoop
            Loop(7)
                Exec(N(EVS_BoulderTremble))
                Call(RotateModel, MODEL_o33, 7, 0, Float(0.2), 1)
                Wait(3)
                Call(RotateModel, MODEL_o33, -7, 0, Float(0.2), 1)
                Wait(3)
            EndLoop
            Loop(8)
                Call(RandInt, 2, LVar0)
                Switch(LVar0)
                    CaseEq(0)
                        PlayEffect(EFFECT_LANDING_DUST, 1, 8, 0, -82, 0)
                    CaseEq(1)
                        PlayEffect(EFFECT_LANDING_DUST, 1, 38, 0, -62, 0)
                    CaseEq(2)
                        PlayEffect(EFFECT_LANDING_DUST, 1, 78, 0, -77, 0)
                EndSwitch
                Exec(N(EVS_BoulderTremble))
                Call(RotateModel, MODEL_o33, 10, 0, Float(0.2), 1)
                Wait(3)
                Call(RotateModel, MODEL_o33, -10, 0, Float(0.2), 1)
                Wait(3)
            EndLoop
            Thread
                Call(ShakeCam, CAM_DEFAULT, 0, 15, Float(0.4))
            EndThread
            Call(PlaySoundAt, SOUND_LOOP_JAN_LARGE_GEYSER, SOUND_SPACE_DEFAULT, 37, 0, -138)
            Set(AB_JAN_2, 1)
            Thread
                Loop(200)
                    Call(RotateModel, MODEL_o33, 10, 0, Float(0.2), 1)
                    Wait(3)
                    Call(RotateModel, MODEL_o33, -10, 0, Float(0.2), 1)
                    Wait(3)
                EndLoop
            EndThread
            Set(LVar0, 0)
            Loop(18)
                Add(LVar0, 3)
                Call(TranslateModel, MODEL_o33, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Loop(60)
                Call(TranslateModel, MODEL_o33, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Set(AB_JAN_2, 2)
            Loop(25)
                Add(LVar0, 8)
                Call(TranslateModel, MODEL_o33, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Set(LVar0, 200)
            Set(LVar1, 0)
            Set(LVar2, 0)
            Loop(60)
                Add(LVar1, 1)
                Sub(LVar0, LVar1)
                Add(LVar2, 10)
                Add(LVar2, -10)
                Call(TranslateModel, MODEL_o33, -200, LVar0, -500)
                Call(RotateModel, MODEL_o33, LVar2, -1, Float(0.1), Float(0.1))
                Wait(1)
            EndLoop
            Call(EnableModel, MODEL_o33, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o33, COLLIDER_FLAGS_UPPER_MASK)
            Set(GF_JAN13_SolvedBlockPuzzle, TRUE)
            Set(LFlag0, TRUE)
            Call(ResetCam, CAM_DEFAULT, Float(5.0))
            Call(DisablePlayerInput, FALSE)
        Else
            Call(GetPushBlock, 0, 17, 0, LVar0)
            IfEq(LVar0, 0)
                Set(MV_PuzzleProgress, 5)
                Goto(1)
            EndIf
        EndIf
        Set(MV_PuzzleProgress, 6)
        Label(1)
            Exec(N(EVS_ManageGeyserSounds))
            Wait(1)
            Goto(0)
    Return
    End
};

EvtScript N(EVS_ManageGeyserPlayerPhysics) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(GetGridIndexFromPos, 0, LVar0, LVar1, LVar2, LVar3, LVar4)
        Set(LVar5, 0)
        IfEq(MV_PuzzleProgress, 0)
            IfEq(LVar3, POS_0_I)
                IfEq(LVar4, POS_0_J)
                    Set(LVar5, 1)
                EndIf
            EndIf
        EndIf
        IfEq(MV_PuzzleProgress, 1)
            IfEq(LVar3, POS_1_I)
                IfEq(LVar4, POS_1_J)
                    Set(LVar5, 1)
                EndIf
            EndIf
        EndIf
        IfEq(MV_PuzzleProgress, 2)
            IfEq(LVar3, POS_2_I)
                IfEq(LVar4, POS_2_J)
                    Set(LVar5, 1)
                EndIf
            EndIf
        EndIf
        IfEq(MV_PuzzleProgress, 3)
            IfEq(LVar3, POS_3_I)
                IfEq(LVar4, POS_3_J)
                    Set(LVar5, 1)
                EndIf
            EndIf
        EndIf
        IfEq(MV_PuzzleProgress, 4)
            IfEq(LVar3, POS_4_I)
                IfEq(LVar4, POS_4_J)
                    Set(LVar5, 1)
                EndIf
            EndIf
        EndIf
        IfEq(MV_PuzzleProgress, 5)
            IfEq(LVar3, 17)
                IfEq(LVar4, 0)
                    Set(LVar5, 1)
                EndIf
            EndIf
        EndIf
        IfEq(MV_PuzzleProgress, 5)
            IfEq(LVar3, 16)
                IfEq(LVar4, 0)
                    Set(LVar5, 1)
                EndIf
            EndIf
        EndIf
        IfEq(MV_PuzzleProgress, 5)
            IfEq(LVar3, 18)
                IfEq(LVar4, 0)
                    Set(LVar5, 1)
                EndIf
            EndIf
        EndIf
        IfEq(MV_PuzzleProgress, 5)
            IfEq(LVar3, 19)
                IfEq(LVar4, 0)
                    Set(LVar5, 1)
                EndIf
            EndIf
        EndIf
        // player is standing in a geyser
        IfEq(LVar5, 1)
            Call(DisablePlayerInput, TRUE)
            Call(N(GetPlayerPosAfterPush))
            Call(InterruptUsePartner)
            Loop(10)
                Call(GetPlayerPos, LVar3, LVar4, LVar5)
                IfLt(LVar4, 40)
                    AddF(LVar4, 6)
                EndIf
                MulF(LVar3, 10)
                MulF(LVar5, 10)
                AddF(LVar3, LVar0)
                AddF(LVar5, LVar2)
                DivF(LVar3, 11)
                DivF(LVar5, 11)
                Call(SetPlayerPos, LVar3, LVar4, LVar5)
                Call(SetPlayerAnimation, ANIM_Mario1_FallBack)
                Wait(1)
            EndLoop
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Call(DisablePlayerInput, FALSE)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetupPuzzle) = {
    Call(CreatePushBlockGrid, 0, 32, 12, -400, 0, -150, 0)
    Call(SetPushBlock, 0,  7, 5, PUSH_GRID_BLOCK)
    Call(SetPushBlock, 0, 13, 9, PUSH_GRID_BLOCK)
    Call(SetPushBlock, 0, 16, 5, PUSH_GRID_BLOCK)
    Call(SetPushBlock, 0, 21, 2, PUSH_GRID_BLOCK)
    Call(SetPushBlock, 0, 22, 4, PUSH_GRID_BLOCK)
    Call(SetPushBlock, 0, 26, 6, PUSH_GRID_BLOCK)
    Call(SetPushBlock, 0, 27, 7, PUSH_GRID_BLOCK)
    Call(SetPushBlock, 0, 15, 0, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 16, 0, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 17, 0, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 18, 0, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 19, 0, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 15, 1, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 16, 1, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 17, 1, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 18, 1, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 19, 1, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 15, 2, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 16, 2, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 17, 2, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 18, 2, PUSH_GRID_OBSTRUCTION)
    Call(SetPushBlock, 0, 19, 2, PUSH_GRID_OBSTRUCTION)
    // obstruct row 0
    Set(LVar0, 0)
    Loop(32)
        Call(SetPushBlock, 0, LVar0, 0, PUSH_GRID_OBSTRUCTION)
        Add(LVar0, 1)
    EndLoop
    // obstruct row 1 from 0 to 15
    Set(LVar0, 0)
    Loop(15)
        Call(SetPushBlock, 0, LVar0, 1, PUSH_GRID_OBSTRUCTION)
        Add(LVar0, 1)
    EndLoop
    // obstruct row 1 from 0 to 32
    Set(LVar0, 20)
    Loop(12)
        Call(SetPushBlock, 0, LVar0, 1, PUSH_GRID_OBSTRUCTION)
        Add(LVar0, 1)
    EndLoop
    // obstruct row 2 from 0 to 3
    Set(LVar0, 0)
    Loop(3)
        Call(SetPushBlock, 0, LVar0, 2, PUSH_GRID_OBSTRUCTION)
        Add(LVar0, 1)
    EndLoop
    // obstruct row 2 from 10 to 14
    Set(LVar0, 10)
    Loop(4)
        Call(SetPushBlock, 0, LVar0, 2, PUSH_GRID_OBSTRUCTION)
        Add(LVar0, 1)
    EndLoop
    // obstruct row 2 from 26 to 32
    Set(LVar0, 26)
    Loop(6)
        Call(SetPushBlock, 0, LVar0, 2, PUSH_GRID_OBSTRUCTION)
        Add(LVar0, 1)
    EndLoop
    // obstruct row 3 from 0 to 2
    Set(LVar0, 0)
    Loop(2)
        Call(SetPushBlock, 0, LVar0, 3, PUSH_GRID_OBSTRUCTION)
        Add(LVar0, 1)
    EndLoop
    // obstruct row 3 from 10 to 14
    Set(LVar0, 10)
    Loop(4)
        Call(SetPushBlock, 0, LVar0, 3, PUSH_GRID_OBSTRUCTION)
        Add(LVar0, 1)
    EndLoop
    Exec(N(EVS_ManagePuzzle))
    Set(LVar0, MODEL_o72)
    Set(LVar1, 0)
    Set(LVar2, COLLIDER_o50)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_ManageSmallGeyser))
    Set(LVar0, MODEL_o73)
    Set(LVar1, 1)
    Set(LVar2, COLLIDER_o51)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_ManageSmallGeyser))
    Set(LVar0, MODEL_o74)
    Set(LVar1, 2)
    Set(LVar2, COLLIDER_o52)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_ManageSmallGeyser))
    Set(LVar0, MODEL_o75)
    Set(LVar1, 3)
    Set(LVar2, COLLIDER_o53)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_ManageSmallGeyser))
    Set(LVar0, MODEL_o76)
    Set(LVar1, 4)
    Set(LVar2, COLLIDER_o49)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_ManageSmallGeyser))
    Set(LVar0, MODEL_o71)
    Set(LVar1, 5)
    Set(LVar2, COLLIDER_o76)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_ManageLargeGeyser))
    Exec(N(EVS_ManageGeyserPlayerPhysics))
    Call(EnableTexPanning, MODEL_o72, TRUE)
    Call(EnableTexPanning, MODEL_o73, TRUE)
    Call(EnableTexPanning, MODEL_o74, TRUE)
    Call(EnableTexPanning, MODEL_o75, TRUE)
    Call(EnableTexPanning, MODEL_o76, TRUE)
    Call(EnableTexPanning, MODEL_o71, TRUE)
    Call(SetModelCustomGfx, MODEL_o72, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o73, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o74, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o75, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o76, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o71, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_0, Ref(N(setup_gfx_geyser)), NULL)
    Set(LVar0, 0)
    Loop(0)
        Sub(LVar0, 2000)
        IfLt(LVar0, -0x10000)
            Add(LVar0, 0x10000)
        EndIf
        Call(SetTexPanOffset, TEX_PANNER_1, 0, 0, LVar0)
        Wait(1)
    EndLoop
    Return
    End
};
