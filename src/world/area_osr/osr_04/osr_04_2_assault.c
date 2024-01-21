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
    UseBuf(Ref(N(ThinTileSpawnPositions)))
    Loop(0)
        BufRead3(LVar2, LVar3, LVar4)
        IfEq(LVar2, -1)
            Return
        EndIf
        Call(MakeLerp, 500, 0, LVar4, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_o1, LVar2, LVar0, LVar3)
            Call(RotateGroup, MODEL_o1, LVar4, 1, 1, 1)
            Sub(LVar4, 15)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(1)
    EndLoop
    Return
    End
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
    UseBuf(Ref(N(ThickTileSpawnPositions)))
    Loop(0)
        BufRead3(LVar2, LVar3, LVar4)
        IfEq(LVar2, -1)
            Return
        EndIf
        Call(MakeLerp, 500, 0, LVar4, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_o2, LVar2, LVar0, LVar3)
            Call(RotateGroup, MODEL_o2, LVar4, 1, 1, 1)
            Add(LVar4, 15)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_DropDebris_Flag) = {
    Call(MakeLerp, 500, 0, 80, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_o3, -340, LVar0, 830)
        Call(RotateGroup, MODEL_o3, LVar4, 1, 1, 1)
        Sub(LVar4, 30)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

s32 N(LeafClumpSpawnPositions)[] = {
    -350,  600,  60 * DT,
    -230, 1200,  40 * DT,
    -340,  960,  40 * DT,
    -1,
};

EvtScript N(EVS_DropDebris_Leaves) = {
    UseBuf(Ref(N(LeafClumpSpawnPositions)))
    Loop(0)
        BufRead3(LVar2, LVar3, LVar4)
        IfEq(LVar2, -1)
            Return
        EndIf
        Call(MakeLerp, 500, 0, LVar4, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_o4, LVar2, LVar0, LVar3)
            Call(RotateGroup, MODEL_o4, LVar4, 1, 1, 1)
            Add(LVar4, 15)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_DropDebris_TreeTrunk) = {
    Call(MakeLerp, 500, 0, 80, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_o5, -190, LVar0, 1030)
        Call(RotateGroup, MODEL_o5, LVar4, 1, 1, 1)
        Sub(LVar4, 15)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
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
    UseBuf(Ref(N(StoneBlockSpawnPositions)))
    Loop(0)
        BufRead3(LVar2, LVar3, LVar4)
        IfEq(LVar2, -1)
            Return
        EndIf
        Call(MakeLerp, 500, 0, LVar4, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_o6, LVar2, LVar0, LVar3)
            Call(RotateGroup, MODEL_o6, LVar4, 1, 1, 1)
            Add(LVar4, 15)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_AnimateSwingingChains) = {
    Loop(0)
        Call(MakeLerp, 90, -90, 30 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            Call(N(MakeCastleChainAngle), LVar0)
            Call(RotateGroup, MODEL_ku_ta, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(2)
            Call(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            Call(RotateGroup, MODEL_ku_ta, -20, 0, 0, 1)
            Wait(1)
        EndLoop
        Call(MakeLerp, -90, 90, 30 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            Call(N(MakeCastleChainAngle), LVar0)
            Call(RotateGroup, MODEL_ku_ta, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(2)
            Call(TranslateGroup, MODEL_ku_ta, 0, MV_CastleLiftDist, 0)
            Call(RotateGroup, MODEL_ku_ta, 20, 0, 0, 1)
            Wait(1)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_AnimateSpinningRing) = {
    Loop(0)
        Call(MakeLerp, 45, -45, 60, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_wa, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, -45, 45, 60, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_wa, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_LiftCastleUp) = {
    Thread
        Wait(120 * DT)
        Call(SetMusicTrack, 0, SONG_BOWSER_ATTACKS, 0, 8)
    EndThread
    Set(MV_CastleLiftDist, 0)
    Thread
        Wait(20 * DT)
        Call(MakeLerp, 0, 2500, 450 * DT, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Set(MV_CastleLiftDist, LVar0)
            Call(TranslateGroup, MODEL_g439, 0, LVar0, 0)
            Call(TranslateGroup, MODEL_kao, 0, LVar0, 0)
            Call(TranslateGroup, MODEL_hiru, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Exec(N(EVS_AnimateSwingingChains))
    Exec(N(EVS_AnimateSpinningRing))
    Thread
        Loop(0)
            Call(MakeLerp, 10, -10, 40 * DT, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Add(MV_CastleLiftDist, LVar0)
                Call(TranslateGroup, MODEL_wa, 0, MV_CastleLiftDist, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(MakeLerp, -10, 10, 40 * DT, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Add(MV_CastleLiftDist, LVar0)
                Call(TranslateGroup, MODEL_wa, 0, MV_CastleLiftDist, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndThread
    Label(22)
    IfLt(MV_CastleLiftDist, 1000)
        Wait(1)
        Goto(22)
    EndIf
    Thread
        Loop(300)
            Sub(MV_SmokeVelY, 3)
            Wait(1)
        EndLoop
    EndThread
    Label(23)
    IfLt(MV_CastleLiftDist, 1150)
        Wait(1)
        Goto(23)
    EndIf
    Set(LVar3, 0)
    Exec(N(EVS_DropDebris_ThinTiles))
    Exec(N(EVS_DropDebris_ThickTiles))
    Exec(N(EVS_DropDebris_StoneBlocks))
    Wait(10 * DT)
    Exec(N(EVS_DropDebris_Flag))
    Exec(N(EVS_DropDebris_Leaves))
    Exec(N(EVS_DropDebris_TreeTrunk))
    Wait(150 * DT)
    Return
    End
};

EvtScript N(EVS_RaiseSmokeClouds) = {
    Set(MV_SmokeVelY, 0)
    Thread
        Call(PlaySound, SOUND_OSR_SMOKE_RISING_1)
        Call(MakeLerp, 0, 650, 40 * DT, EASING_CUBIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Add(LVar0, MV_SmokeVelY)
            Call(TranslateGroup, MODEL_kem1, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(0)
            Call(MakeLerp, 600, 650, 25 * DT, EASING_CUBIC_OUT)
            Loop(0)
                Call(UpdateLerp)
                Add(LVar0, MV_SmokeVelY)
                Call(TranslateGroup, MODEL_kem1, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(MakeLerp, 650, 600, 35 * DT, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Add(LVar0, MV_SmokeVelY)
                Call(TranslateGroup, MODEL_kem1, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndThread
    Thread
        Wait(20 * DT)
        Call(PlaySound, SOUND_OSR_SMOKE_RISING_2)
        Call(MakeLerp, 0, 400, 30 * DT, EASING_CUBIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_kem2, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(0)
            Call(MakeLerp, 350, 400, 12 * DT, EASING_CUBIC_OUT)
            Loop(0)
                Call(UpdateLerp)
                Add(LVar0, MV_SmokeVelY)
                Call(TranslateGroup, MODEL_kem2, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(MakeLerp, 400, 350, 17 * DT, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Add(LVar0, MV_SmokeVelY)
                Call(TranslateGroup, MODEL_kem2, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndThread
    Thread
        Wait(40)
        Call(PlaySound, SOUND_OSR_SMOKE_RISING_3)
        Call(MakeLerp, 0, 200, 20 * DT, EASING_CUBIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_kem3, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(0)
            Call(MakeLerp, 150, 200, 25 * DT, EASING_CUBIC_OUT)
            Loop(0)
                Call(UpdateLerp)
                Add(LVar0, MV_SmokeVelY)
                Call(TranslateGroup, MODEL_kem3, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Call(MakeLerp, 200, 150, 35 * DT, EASING_LINEAR)
            Loop(0)
                Call(UpdateLerp)
                Add(LVar0, MV_SmokeVelY)
                Call(TranslateGroup, MODEL_kem3, 0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_Scene_BowsersAssault) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(EnableGroup, MODEL_yoru, FALSE)
    Call(SetPlayerPos, 0, 0, 2000)
    Thread
        Call(PlaySound, SOUND_LOOP_OSR_RUMBLING)
        Call(ShakeCam, CAM_DEFAULT, 0, 450 * DT, Float(2.0))
        Call(ShakeCam, CAM_DEFAULT, 0, 100 * DT, Float(1.0))
    EndThread
    Wait(50 * DT)
    Thread
        Wait(30 * DT)
        Call(MakeLerp, 0, 45, 30 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_ki1, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 0, 100, 30 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_ki1, 45, 0, 0, 1)
            Call(RotateGroup, MODEL_ki1, LVar0, 1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(EnableGroup, MODEL_ki1, FALSE)
    EndThread
    Thread
        Wait(45 * DT)
        Call(MakeLerp, 0, 30, 30 * DT, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_ki2, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 0, 100, 100 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_ki2, 30, 0, 0, 1)
            Call(RotateGroup, MODEL_ki2, LVar0, -1, 0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(EnableGroup, MODEL_ki2, FALSE)
    EndThread
    Thread
        Wait(75 * DT)
        Call(MakeLerp, 0, 100, 100 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_jime, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(PlaySound, SOUND_OSR_GROUND_CRACKING)
        Call(MakeLerp, 0, 30, 50 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_1, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Wait(10 * DT)
        Call(MakeLerp, 0, 40, 40 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_2, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 0, 20, 50 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_3, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Wait(15 * DT)
        Call(MakeLerp, 0, 10, 35 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_4, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 0, -20, 50 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_5, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(MakeLerp, 0, -10, 50 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_6, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_RaiseSmokeClouds))
    ExecWait(N(EVS_LiftCastleUp))
    Call(GotoMap, Ref("kkj_03"), kkj_03_ENTRY_1)
    Wait(100 * DT)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
