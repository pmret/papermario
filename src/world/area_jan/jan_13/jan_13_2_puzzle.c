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
    script->varTable[2] = EVT_FLOAT_TO_FIXED(script->varTable[1] / 100.0f);
    script->varTable[3] = EVT_FLOAT_TO_FIXED(script->varTable[1] / 100.0f);
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
    EVT_SET(LVarA, LVar0) // geyser model
    EVT_SET(LVarB, LVar1) // index in solution
    EVT_SET(LVarD, LVar2) // central collider
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        // get percent delta
        EVT_IF_EQ(LVarB, MV_PuzzleProgress)
            EVT_ADD(LVar0, 10)
        EVT_ELSE
            EVT_ADD(LVar0, -10)
        EVT_END_IF
        // clamp delta to [-10, 10]
        EVT_IF_LT(LVar0, -10)
            EVT_SET(LVar0, -10)
        EVT_END_IF
        EVT_IF_GT(LVar0, 10)
            EVT_SET(LVar0, 10)
        EVT_END_IF
        EVT_ADD(LVar1, LVar0)
        // clamp percent to [0, 100]
        EVT_IF_LT(LVar1, 0)
            EVT_SET(LVar1, 0)
        EVT_END_IF
        EVT_IF_GT(LVar1, 100)
            EVT_SET(LVar1, 100)
        EVT_END_IF
        // set geyser scale
        EVT_CALL(N(GetRatioFromPercent))
        EVT_IF_EQ(LVar1, 0)
            EVT_IF_NE(LVarD, 0)
            EVT_END_IF
            EVT_CALL(EnableModel, LVarA, FALSE)
        EVT_ELSE
            EVT_IF_NE(LVarD, 0)
            EVT_END_IF
            EVT_CALL(EnableModel, LVarA, TRUE)
            EVT_CALL(ScaleModel, LVarA, LVar3, LVar2, LVar3)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(SetLargeGeyserScale) = {
    EVT_CALL(N(GetRatioFromPercent))
    EVT_IF_LT(LVar3, EVT_FLOAT(1.0))
        EVT_SETF(LVar4, LVar3)
    EVT_ELSE
        EVT_SETF(LVar4, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(ScaleModel, LVarA, LVar4, LVar2, LVar3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageLargeGeyser) = {
    EVT_SET(LVarA, LVar0) // geyser model
    EVT_SET(LVarB, LVar1) // index in solution
    EVT_SET(LVarD, LVar2) // central collider
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_IF_EQ(GF_JAN13_SolvedBlockPuzzle, TRUE)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_IF_EQ(MV_PuzzleProgress, 5)
            EVT_IF_EQ(AB_JAN_2, 1)
                EVT_ADD(LVar0, 10)
            EVT_ELSE
                EVT_ADD(LVar0, -10)
            EVT_END_IF
        EVT_ELSE
            EVT_ADD(LVar0, -10)
        EVT_END_IF
        EVT_IF_LT(LVar0, -10)
            EVT_SET(LVar0, -10)
        EVT_END_IF
        EVT_IF_GT(LVar0, 10)
            EVT_SET(LVar0, 10)
        EVT_END_IF
        EVT_ADD(LVar1, LVar0)
        EVT_IF_LT(LVar1, 50)
            EVT_SET(LVar1, 50)
        EVT_END_IF
        EVT_IF_GT(LVar1, 70)
            EVT_SET(LVar1, 70)
        EVT_END_IF
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(EnableModel, LVarA, FALSE)
            EVT_WAIT(1)
        EVT_ELSE
            EVT_CALL(EnableModel, LVarA, TRUE)
            EVT_EXEC_WAIT(N(SetLargeGeyserScale))
        EVT_END_IF
        EVT_IF_EQ(AB_JAN_2, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LVar0, 10)
    EVT_LOOP(0)
        EVT_IF_EQ(MV_PuzzleProgress, 5)
            EVT_ADD(LVar1, LVar0)
            EVT_IF_GT(LVar1, 300)
                EVT_SET(LVar1, 300)
            EVT_END_IF
            EVT_EXEC_WAIT(N(SetLargeGeyserScale))
        EVT_ELSE
            EVT_WAIT(1)
        EVT_END_IF
        EVT_IF_NE(GF_JAN13_SolvedBlockPuzzle, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LVar0, -7)
    EVT_LOOP(28)
        EVT_ADD(LVar1, LVar0)
        EVT_EXEC_WAIT(N(SetLargeGeyserScale))
    EVT_END_LOOP
    EVT_LABEL(10)
    EVT_IF_EQ(MV_PuzzleProgress, 5)
        EVT_ADD(LVar0, 10)
    EVT_ELSE
        EVT_ADD(LVar0, -10)
    EVT_END_IF
    EVT_IF_LT(LVar0, -10)
        EVT_SET(LVar0, -10)
    EVT_END_IF
    EVT_IF_GT(LVar0, 10)
        EVT_SET(LVar0, 10)
    EVT_END_IF
    EVT_ADD(LVar1, LVar0)
    EVT_IF_LT(LVar1, 0)
        EVT_SET(LVar1, 0)
    EVT_END_IF
    EVT_IF_GT(LVar1, 100)
        EVT_SET(LVar1, 100)
    EVT_END_IF
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(EnableModel, LVarA, FALSE)
        EVT_WAIT(1)
    EVT_ELSE
        EVT_CALL(EnableModel, LVarA, TRUE)
        EVT_EXEC_WAIT(N(SetLargeGeyserScale))
    EVT_END_IF
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
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
    EVT_IF_NE(AB_JAN13_LastPuzzleProgress, MV_PuzzleProgress)
        EVT_SET(AB_JAN13_LastPuzzleProgress, MV_PuzzleProgress)
        EVT_SET(MF_GeyserSoundPlaying, FALSE)
        EVT_CALL(StopSound, SOUND_LOOP_JAN_SMALL_GEYSER)
        EVT_CALL(StopSound, SOUND_LOOP_JAN_LARGE_GEYSER)
        EVT_IF_EQ(MV_PuzzleProgress, 5)
            EVT_IF_EQ(GF_JAN13_SolvedBlockPuzzle, FALSE)
                EVT_RETURN
            EVT_END_IF
        EVT_ELSE
            EVT_IF_EQ(MV_PuzzleProgress, 6)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(PlaySound, SOUND_LOOP_JAN_SMALL_GEYSER)
        EVT_SET(MF_GeyserSoundPlaying, TRUE)
        EVT_SET(LVar0, MV_PuzzleProgress)
        EVT_ADD(LVar0, 1)
        EVT_USE_BUF(EVT_PTR(N(GeyserSoundPositions)))
        EVT_LOOP(LVar0)
            EVT_BUF_READ3(LVar1, LVar2, LVar3)
        EVT_END_LOOP
        EVT_CALL(N(AdjustEnvSoundPosition), MF_GeyserSoundPlaying, LVar1, LVar2, LVar3)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BoulderTremble) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o33, SOUND_JAN_BOULDER_TREMBLE, 0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.5))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManagePuzzle) = {
    EVT_SET(LFlag0, FALSE)
    EVT_SET(AB_JAN_2, 0)
    EVT_SET(AB_JAN13_LastPuzzleProgress, -1)
    EVT_EXEC(N(EVS_ManageGeyserSounds))
    EVT_LABEL(0)
        EVT_IF_EQ(GF_JAN13_SolvedBlockPuzzle, TRUE)
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(EnableModel, MODEL_o33, FALSE)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o33, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(SetPushBlock, 0, 15, 0, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 16, 0, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 17, 0, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 18, 0, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 19, 0, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 15, 1, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 16, 1, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 17, 1, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 18, 1, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 19, 1, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 15, 2, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 16, 2, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 17, 2, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 18, 2, PUSH_GRID_EMPTY)
                EVT_CALL(SetPushBlock, 0, 19, 2, PUSH_GRID_EMPTY)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(GetPushBlock, 0, POS_0_I, POS_0_J, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(MV_PuzzleProgress, 0)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetPushBlock, 0, POS_1_I, POS_1_J, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(MV_PuzzleProgress, 1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetPushBlock, 0, POS_2_I, POS_2_J, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(MV_PuzzleProgress, 2)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetPushBlock, 0, POS_3_I, POS_3_J, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(MV_PuzzleProgress, 3)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetPushBlock, 0, POS_4_I, POS_4_J, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(MV_PuzzleProgress, 4)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_IF_EQ(GF_JAN13_SolvedBlockPuzzle, FALSE)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetPushBlock, 0, 15, 0, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 16, 0, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 17, 0, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 18, 0, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 19, 0, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 15, 1, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 16, 1, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 17, 1, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 18, 1, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 19, 1, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 15, 2, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 16, 2, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 17, 2, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 18, 2, PUSH_GRID_EMPTY)
            EVT_CALL(SetPushBlock, 0, 19, 2, PUSH_GRID_EMPTY)
            EVT_SET(MV_PuzzleProgress, 5)
            EVT_WAIT(30)
            EVT_LOOP(2)
                EVT_EXEC(N(EVS_BoulderTremble))
                EVT_CALL(RotateModel, MODEL_o33, 3, 0, EVT_FLOAT(0.2), 1)
                EVT_WAIT(8)
                EVT_CALL(RotateModel, MODEL_o33, -3, 0, EVT_FLOAT(0.2), 1)
                EVT_WAIT(8)
            EVT_END_LOOP
            EVT_THREAD
                EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 20, EMOTER_PLAYER, 0, 0, 0, 0)
                EVT_CALL(GetModelCenter, MODEL_o33)
                EVT_CALL(FacePlayerTowardPoint, LVar0, LVar2, 4)
                EVT_CALL(GetPlayerPos, LVar3, LVar1, LVar2)
                EVT_SET(LVar4, LVar0)
                EVT_SET(LVar5, LVar0)
                EVT_SUB(LVar4, 120)
                EVT_ADD(LVar5, 120)
                EVT_SWITCH(LVar3)
                    EVT_CASE_RANGE(LVar4, LVar5)
                        EVT_ADD(LVar0, LVar3)
                        EVT_DIV(LVar0, 2)
                EVT_END_SWITCH
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_END_THREAD
            EVT_LOOP(3)
                EVT_EXEC(N(EVS_BoulderTremble))
                EVT_CALL(RotateModel, MODEL_o33, 5, 0, EVT_FLOAT(0.2), 1)
                EVT_WAIT(5)
                EVT_CALL(RotateModel, MODEL_o33, -5, 0, EVT_FLOAT(0.2), 1)
                EVT_WAIT(5)
            EVT_END_LOOP
            EVT_LOOP(7)
                EVT_EXEC(N(EVS_BoulderTremble))
                EVT_CALL(RotateModel, MODEL_o33, 7, 0, EVT_FLOAT(0.2), 1)
                EVT_WAIT(3)
                EVT_CALL(RotateModel, MODEL_o33, -7, 0, EVT_FLOAT(0.2), 1)
                EVT_WAIT(3)
            EVT_END_LOOP
            EVT_LOOP(8)
                EVT_CALL(RandInt, 2, LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(0)
                        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 8, 0, -82, 0)
                    EVT_CASE_EQ(1)
                        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 38, 0, -62, 0)
                    EVT_CASE_EQ(2)
                        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, 78, 0, -77, 0)
                EVT_END_SWITCH
                EVT_EXEC(N(EVS_BoulderTremble))
                EVT_CALL(RotateModel, MODEL_o33, 10, 0, EVT_FLOAT(0.2), 1)
                EVT_WAIT(3)
                EVT_CALL(RotateModel, MODEL_o33, -10, 0, EVT_FLOAT(0.2), 1)
                EVT_WAIT(3)
            EVT_END_LOOP
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 15, EVT_FLOAT(0.4))
            EVT_END_THREAD
            EVT_CALL(PlaySoundAt, SOUND_LOOP_JAN_LARGE_GEYSER, SOUND_SPACE_DEFAULT, 37, 0, -138)
            EVT_SET(AB_JAN_2, 1)
            EVT_THREAD
                EVT_LOOP(200)
                    EVT_CALL(RotateModel, MODEL_o33, 10, 0, EVT_FLOAT(0.2), 1)
                    EVT_WAIT(3)
                    EVT_CALL(RotateModel, MODEL_o33, -10, 0, EVT_FLOAT(0.2), 1)
                    EVT_WAIT(3)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_SET(LVar0, 0)
            EVT_LOOP(18)
                EVT_ADD(LVar0, 3)
                EVT_CALL(TranslateModel, MODEL_o33, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(60)
                EVT_CALL(TranslateModel, MODEL_o33, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_SET(AB_JAN_2, 2)
            EVT_LOOP(25)
                EVT_ADD(LVar0, 8)
                EVT_CALL(TranslateModel, MODEL_o33, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_SET(LVar0, 200)
            EVT_SET(LVar1, 0)
            EVT_SET(LVar2, 0)
            EVT_LOOP(60)
                EVT_ADD(LVar1, 1)
                EVT_SUB(LVar0, LVar1)
                EVT_ADD(LVar2, 10)
                EVT_ADD(LVar2, -10)
                EVT_CALL(TranslateModel, MODEL_o33, -200, LVar0, -500)
                EVT_CALL(RotateModel, MODEL_o33, LVar2, -1, EVT_FLOAT(0.1), EVT_FLOAT(0.1))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(EnableModel, MODEL_o33, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o33, COLLIDER_FLAGS_UPPER_MASK)
            EVT_SET(GF_JAN13_SolvedBlockPuzzle, TRUE)
            EVT_SET(LFlag0, TRUE)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_ELSE
            EVT_CALL(GetPushBlock, 0, 17, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(MV_PuzzleProgress, 5)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_END_IF
        EVT_SET(MV_PuzzleProgress, 6)
        EVT_LABEL(1)
            EVT_EXEC(N(EVS_ManageGeyserSounds))
            EVT_WAIT(1)
            EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageGeyserPlayerPhysics) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(GetGridIndexFromPos, 0, LVar0, LVar1, LVar2, LVar3, LVar4)
        EVT_SET(LVar5, 0)
        EVT_IF_EQ(MV_PuzzleProgress, 0)
            EVT_IF_EQ(LVar3, POS_0_I)
                EVT_IF_EQ(LVar4, POS_0_J)
                    EVT_SET(LVar5, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(MV_PuzzleProgress, 1)
            EVT_IF_EQ(LVar3, POS_1_I)
                EVT_IF_EQ(LVar4, POS_1_J)
                    EVT_SET(LVar5, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(MV_PuzzleProgress, 2)
            EVT_IF_EQ(LVar3, POS_2_I)
                EVT_IF_EQ(LVar4, POS_2_J)
                    EVT_SET(LVar5, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(MV_PuzzleProgress, 3)
            EVT_IF_EQ(LVar3, POS_3_I)
                EVT_IF_EQ(LVar4, POS_3_J)
                    EVT_SET(LVar5, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(MV_PuzzleProgress, 4)
            EVT_IF_EQ(LVar3, POS_4_I)
                EVT_IF_EQ(LVar4, POS_4_J)
                    EVT_SET(LVar5, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(MV_PuzzleProgress, 5)
            EVT_IF_EQ(LVar3, 17)
                EVT_IF_EQ(LVar4, 0)
                    EVT_SET(LVar5, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(MV_PuzzleProgress, 5)
            EVT_IF_EQ(LVar3, 16)
                EVT_IF_EQ(LVar4, 0)
                    EVT_SET(LVar5, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(MV_PuzzleProgress, 5)
            EVT_IF_EQ(LVar3, 18)
                EVT_IF_EQ(LVar4, 0)
                    EVT_SET(LVar5, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(MV_PuzzleProgress, 5)
            EVT_IF_EQ(LVar3, 19)
                EVT_IF_EQ(LVar4, 0)
                    EVT_SET(LVar5, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        // player is standing in a geyser
        EVT_IF_EQ(LVar5, 1)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(N(GetPlayerPosAfterPush))
            EVT_CALL(InterruptUsePartner)
            EVT_LOOP(10)
                EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
                EVT_IF_LT(LVar4, 40)
                    EVT_ADDF(LVar4, 6)
                EVT_END_IF
                EVT_MULF(LVar3, 10)
                EVT_MULF(LVar5, 10)
                EVT_ADDF(LVar3, LVar0)
                EVT_ADDF(LVar5, LVar2)
                EVT_DIVF(LVar3, 11)
                EVT_DIVF(LVar5, 11)
                EVT_CALL(SetPlayerPos, LVar3, LVar4, LVar5)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_FallBack)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupPuzzle) = {
    EVT_CALL(CreatePushBlockGrid, 0, 32, 12, -400, 0, -150, 0)
    EVT_CALL(SetPushBlock, 0,  7, 5, PUSH_GRID_BLOCK)
    EVT_CALL(SetPushBlock, 0, 13, 9, PUSH_GRID_BLOCK)
    EVT_CALL(SetPushBlock, 0, 16, 5, PUSH_GRID_BLOCK)
    EVT_CALL(SetPushBlock, 0, 21, 2, PUSH_GRID_BLOCK)
    EVT_CALL(SetPushBlock, 0, 22, 4, PUSH_GRID_BLOCK)
    EVT_CALL(SetPushBlock, 0, 26, 6, PUSH_GRID_BLOCK)
    EVT_CALL(SetPushBlock, 0, 27, 7, PUSH_GRID_BLOCK)
    EVT_CALL(SetPushBlock, 0, 15, 0, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 16, 0, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 17, 0, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 18, 0, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 19, 0, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 15, 1, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 16, 1, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 17, 1, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 18, 1, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 19, 1, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 15, 2, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 16, 2, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 17, 2, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 18, 2, PUSH_GRID_OBSTRUCTION)
    EVT_CALL(SetPushBlock, 0, 19, 2, PUSH_GRID_OBSTRUCTION)
    // obstruct row 0
    EVT_SET(LVar0, 0)
    EVT_LOOP(32)
        EVT_CALL(SetPushBlock, 0, LVar0, 0, PUSH_GRID_OBSTRUCTION)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    // obstruct row 1 from 0 to 15
    EVT_SET(LVar0, 0)
    EVT_LOOP(15)
        EVT_CALL(SetPushBlock, 0, LVar0, 1, PUSH_GRID_OBSTRUCTION)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    // obstruct row 1 from 0 to 32
    EVT_SET(LVar0, 20)
    EVT_LOOP(12)
        EVT_CALL(SetPushBlock, 0, LVar0, 1, PUSH_GRID_OBSTRUCTION)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    // obstruct row 2 from 0 to 3
    EVT_SET(LVar0, 0)
    EVT_LOOP(3)
        EVT_CALL(SetPushBlock, 0, LVar0, 2, PUSH_GRID_OBSTRUCTION)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    // obstruct row 2 from 10 to 14
    EVT_SET(LVar0, 10)
    EVT_LOOP(4)
        EVT_CALL(SetPushBlock, 0, LVar0, 2, PUSH_GRID_OBSTRUCTION)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    // obstruct row 2 from 26 to 32
    EVT_SET(LVar0, 26)
    EVT_LOOP(6)
        EVT_CALL(SetPushBlock, 0, LVar0, 2, PUSH_GRID_OBSTRUCTION)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    // obstruct row 3 from 0 to 2
    EVT_SET(LVar0, 0)
    EVT_LOOP(2)
        EVT_CALL(SetPushBlock, 0, LVar0, 3, PUSH_GRID_OBSTRUCTION)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    // obstruct row 3 from 10 to 14
    EVT_SET(LVar0, 10)
    EVT_LOOP(4)
        EVT_CALL(SetPushBlock, 0, LVar0, 3, PUSH_GRID_OBSTRUCTION)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ManagePuzzle))
    EVT_SET(LVar0, MODEL_o72)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, COLLIDER_o50)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_ManageSmallGeyser))
    EVT_SET(LVar0, MODEL_o73)
    EVT_SET(LVar1, 1)
    EVT_SET(LVar2, COLLIDER_o51)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_ManageSmallGeyser))
    EVT_SET(LVar0, MODEL_o74)
    EVT_SET(LVar1, 2)
    EVT_SET(LVar2, COLLIDER_o52)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_ManageSmallGeyser))
    EVT_SET(LVar0, MODEL_o75)
    EVT_SET(LVar1, 3)
    EVT_SET(LVar2, COLLIDER_o53)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_ManageSmallGeyser))
    EVT_SET(LVar0, MODEL_o76)
    EVT_SET(LVar1, 4)
    EVT_SET(LVar2, COLLIDER_o49)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_ManageSmallGeyser))
    EVT_SET(LVar0, MODEL_o71)
    EVT_SET(LVar1, 5)
    EVT_SET(LVar2, COLLIDER_o76)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_ManageLargeGeyser))
    EVT_EXEC(N(EVS_ManageGeyserPlayerPhysics))
    EVT_CALL(EnableTexPanning, MODEL_o72, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o73, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o74, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o75, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o76, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o71, TRUE)
    EVT_CALL(SetModelCustomGfx, MODEL_o72, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o73, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o74, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o75, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o76, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o71, CUSTOM_GFX_0, ENV_TINT_UNCHANGED)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_0, EVT_PTR(N(setup_gfx_geyser)), NULL)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_SUB(LVar0, 2000)
        EVT_IF_LT(LVar0, -0x10000)
            EVT_ADD(LVar0, 0x10000)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, 0, 0, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
