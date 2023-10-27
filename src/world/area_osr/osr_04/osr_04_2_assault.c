#include "osr_04.h"

s32 N(map_init)(void) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_COMBINED_EPILOGUE;
    sprintf(wMapShapeName, "osr_03_shape");
    sprintf(wMapHitName, "osr_03_hit");
    return FALSE;
}

API_CALLABLE(N(MakeCastleChainAngle)) {
    Bytecode* args = script->ptrReadPos;
    s32 angle = evt_get_variable(script, *args);
    evt_set_variable(script, *args++, (sin_deg(angle) * 20.0f));
    return ApiStatus_DONE2;
}

s32 N(ThinTileSpawnPositions)[] = {
    -440, 1100,  30 * DT,
    -190, 1030,  40 * DT,
    -105, 1100,  30 * DT,
    -350,  600,  55 * DT,
    -230, 1200,  35 * DT,
    -500, 1050,  30 * DT,
    -410,  900,  35 * DT,
      79,  770,  55 * DT,
    -1,
};

EvtScript N(EVS_DropDebris_ThinTiles) = {
    EVT_USE_BUF(EVT_PTR(N(ThinTileSpawnPositions)))
    EVT_LOOP(0)
        EVT_BUF_READ3(LVar2, LVar3, LVar4)
        EVT_IF_EQ(LVar2, -1)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(MakeLerp, 500, 0, LVar4, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_o1, LVar2, LVar0, LVar3)
            EVT_CALL(RotateGroup, MODEL_o1, LVar4, 1, 1, 1)
            EVT_SUB(LVar4, 15)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(ThickTileSpawnPositions)[] = {
    -340,  960,  50 * DT,
    -410,  900,  55 * DT,
    -230, 1200,  45 * DT,
    -500,  940,  40 * DT,
    -230, 1010,  50 * DT,
    -500,  940,  40 * DT,
    -350,  600,  55 * DT,
    -1,
};

EvtScript N(EVS_DropDebris_ThickTiles) = {
    EVT_USE_BUF(EVT_PTR(N(ThickTileSpawnPositions)))
    EVT_LOOP(0)
        EVT_BUF_READ3(LVar2, LVar3, LVar4)
        EVT_IF_EQ(LVar2, -1)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(MakeLerp, 500, 0, LVar4, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_o2, LVar2, LVar0, LVar3)
            EVT_CALL(RotateGroup, MODEL_o2, LVar4, 1, 1, 1)
            EVT_ADD(LVar4, 15)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDebris_Flag) = {
    EVT_CALL(MakeLerp, 500, 0, 80, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_o3, -340, LVar0, 830)
        EVT_CALL(RotateGroup, MODEL_o3, LVar4, 1, 1, 1)
        EVT_SUB(LVar4, 30)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(LeafClumpSpawnPositions)[] = {
    -350,  600,  60 * DT,
    -230, 1200,  40 * DT,
    -340,  960,  40 * DT,
    -1,
};

EvtScript N(EVS_DropDebris_Leaves) = {
    EVT_USE_BUF(EVT_PTR(N(LeafClumpSpawnPositions)))
    EVT_LOOP(0)
        EVT_BUF_READ3(LVar2, LVar3, LVar4)
        EVT_IF_EQ(LVar2, -1)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(MakeLerp, 500, 0, LVar4, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_o4, LVar2, LVar0, LVar3)
            EVT_CALL(RotateGroup, MODEL_o4, LVar4, 1, 1, 1)
            EVT_ADD(LVar4, 15)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDebris_TreeTrunk) = {
    EVT_CALL(MakeLerp, 500, 0, 80, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_o5, -190, LVar0, 1030)
        EVT_CALL(RotateGroup, MODEL_o5, LVar4, 1, 1, 1)
        EVT_SUB(LVar4, 15)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(StoneBlockSpawnPositions)[] = {
    -500,  940,  20 * DT,
      80,  770,  60 * DT,
    -340,  960,  15 * DT,
    -340,  960,  45 * DT,
    -500, 1050,  15 * DT,
    -230, 1200,  35 * DT,
    -350,  600,  40 * DT,
    -1,
};

EvtScript N(EVS_DropDebris_StoneBlocks) = {
    EVT_USE_BUF(EVT_PTR(N(StoneBlockSpawnPositions)))
    EVT_LOOP(0)
        EVT_BUF_READ3(LVar2, LVar3, LVar4)
        EVT_IF_EQ(LVar2, -1)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(MakeLerp, 500, 0, LVar4, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_o6, LVar2, LVar0, LVar3)
            EVT_CALL(RotateGroup, MODEL_o6, LVar4, 1, 1, 1)
            EVT_ADD(LVar4, 15)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimateSwingingChains) = {
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 90, -90, 30 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            EVT_CALL(N(MakeCastleChainAngle), LVar0)
            EVT_CALL(RotateGroup, MODEL_ku_ta, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LOOP(2)
            EVT_CALL(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            EVT_CALL(RotateGroup, MODEL_ku_ta, -20, 0, 0, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(MakeLerp, -90, 90, 30 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            EVT_CALL(N(MakeCastleChainAngle), LVar0)
            EVT_CALL(RotateGroup, MODEL_ku_ta, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LOOP(2)
            EVT_CALL(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            EVT_CALL(RotateGroup, MODEL_ku_ta, 20, 0, 0, 1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimateSpinningRing) = {
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 45, -45, 60, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_wa, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, -45, 45, 60, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_wa, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LiftCastleUp) = {
    EVT_THREAD
        EVT_WAIT(120 * DT)
        EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_ATTACKS, 0, 8)
    EVT_END_THREAD
    EVT_SET(MV_CastleLiftDist, 0)
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(MakeLerp, 0, 2500, 450 * DT, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_CastleLiftDist, LVar0)
            EVT_CALL(TranslateGroup, MODEL_g439, 0, LVar0, 0)
            EVT_CALL(TranslateGroup, MODEL_kao, 0, LVar0, 0)
            EVT_CALL(TranslateGroup, MODEL_hiru, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC(N(EVS_AnimateSwingingChains))
    EVT_EXEC(N(EVS_AnimateSpinningRing))
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(MakeLerp, 10, -10, 40 * DT, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_ADD(MV_CastleLiftDist, LVar0)
                EVT_CALL(TranslateGroup, MODEL_wa, 0, MV_CastleLiftDist, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(MakeLerp, -10, 10, 40 * DT, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_ADD(MV_CastleLiftDist, LVar0)
                EVT_CALL(TranslateGroup, MODEL_wa, 0, MV_CastleLiftDist, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LABEL(22)
    EVT_IF_LT(MV_CastleLiftDist, 1000)
        EVT_WAIT(1)
        EVT_GOTO(22)
    EVT_END_IF
    EVT_THREAD
        EVT_LOOP(300)
            EVT_SUB(MV_SmokeVelY, 3)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LABEL(23)
    EVT_IF_LT(MV_CastleLiftDist, 1150)
        EVT_WAIT(1)
        EVT_GOTO(23)
    EVT_END_IF
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_DropDebris_ThinTiles))
    EVT_EXEC(N(EVS_DropDebris_ThickTiles))
    EVT_EXEC(N(EVS_DropDebris_StoneBlocks))
    EVT_WAIT(10 * DT)
    EVT_EXEC(N(EVS_DropDebris_Flag))
    EVT_EXEC(N(EVS_DropDebris_Leaves))
    EVT_EXEC(N(EVS_DropDebris_TreeTrunk))
    EVT_WAIT(150 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RaiseSmokeClouds) = {
    EVT_SET(MV_SmokeVelY, 0)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_OSR_SMOKE_RISING_1)
        EVT_CALL(MakeLerp, 0, 650, 40 * DT, EASING_CUBIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_ADD(LVar0, MV_SmokeVelY)
            EVT_CALL(TranslateGroup, MODEL_kem1, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_CALL(MakeLerp, 600, 650, 25 * DT, EASING_CUBIC_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_ADD(LVar0, MV_SmokeVelY)
                EVT_CALL(TranslateGroup, MODEL_kem1, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(MakeLerp, 650, 600, 35 * DT, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_ADD(LVar0, MV_SmokeVelY)
                EVT_CALL(TranslateGroup, MODEL_kem1, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(PlaySound, SOUND_OSR_SMOKE_RISING_2)
        EVT_CALL(MakeLerp, 0, 400, 30 * DT, EASING_CUBIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_kem2, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_CALL(MakeLerp, 350, 400, 12 * DT, EASING_CUBIC_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_ADD(LVar0, MV_SmokeVelY)
                EVT_CALL(TranslateGroup, MODEL_kem2, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(MakeLerp, 400, 350, 17 * DT, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_ADD(LVar0, MV_SmokeVelY)
                EVT_CALL(TranslateGroup, MODEL_kem2, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(40)
        EVT_CALL(PlaySound, SOUND_OSR_SMOKE_RISING_3)
        EVT_CALL(MakeLerp, 0, 200, 20 * DT, EASING_CUBIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_kem3, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LOOP(0)
            EVT_CALL(MakeLerp, 150, 200, 25 * DT, EASING_CUBIC_OUT)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_ADD(LVar0, MV_SmokeVelY)
                EVT_CALL(TranslateGroup, MODEL_kem3, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(MakeLerp, 200, 150, 35 * DT, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_ADD(LVar0, MV_SmokeVelY)
                EVT_CALL(TranslateGroup, MODEL_kem3, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BowsersAssault) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(EnableGroup, MODEL_yoru, FALSE)
    EVT_CALL(SetPlayerPos, 0, 0, 2000)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_LOOP_OSR_RUMBLING)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 450 * DT, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 100 * DT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(50 * DT)
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(MakeLerp, 0, 45, 30 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_ki1, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 0, 100, 30 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_ki1, 45, 0, 0, 1)
            EVT_CALL(RotateGroup, MODEL_ki1, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(EnableGroup, MODEL_ki1, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(45 * DT)
        EVT_CALL(MakeLerp, 0, 30, 30 * DT, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_ki2, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 0, 100, 100 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_ki2, 30, 0, 0, 1)
            EVT_CALL(RotateGroup, MODEL_ki2, LVar0, -1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(EnableGroup, MODEL_ki2, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(75 * DT)
        EVT_CALL(MakeLerp, 0, 100, 100 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_jime, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_OSR_GROUND_CRACKING)
        EVT_CALL(MakeLerp, 0, 30, 50 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_1, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(MakeLerp, 0, 40, 40 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_2, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 20, 50 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_3, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(MakeLerp, 0, 10, 35 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_4, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, -20, 50 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_5, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, -10, 50 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_6, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_RaiseSmokeClouds))
    EVT_EXEC_WAIT(N(EVS_LiftCastleUp))
    EVT_CALL(GotoMap, EVT_PTR("kkj_03"), kkj_03_ENTRY_1)
    EVT_WAIT(100 * DT)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
