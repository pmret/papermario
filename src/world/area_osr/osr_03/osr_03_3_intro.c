#include "osr_03.h"
#include "sprite/player.h"

API_CALLABLE(N(MakeCastleChainAngle)) {
    Bytecode* args = script->ptrReadPos;
    s32 angle = evt_get_variable(script, *args);

    evt_set_variable(script, *args++, sin_deg(angle) * 20.0f);
    return ApiStatus_DONE2;
}

Vec3f N(UnusedFallingPath1)[] = {
    { -100.0,    70.0,  873.0 },
    { -328.0,   -10.0,  900.0 },
    { -406.0,   -90.0,  958.0 },
    { -485.0,  -170.0, 1010.0 },
    { -618.0,  -230.0, 1075.0 },
};

EvtScript N(EVS_UnusedFalling1) = {
    EVT_CALL(LoadPath, 90, EVT_PTR(N(UnusedFallingPath1)), ARRAY_COUNT(N(UnusedFallingPath1)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_NE(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

Vec3f N(UnusedFallingPath2)[] = {
    { -1380.0,  -2950.0, 2300.0 },
    { -1325.0,  -3030.0, 2327.0 },
    { -1257.0,  -3050.0, 2306.0 },
    { -1225.0,  -3000.0, 2318.0 },
    { -1268.0,  -3000.0, 2306.0 },
    { -1325.0,  -3057.0, 2297.0 },
    { -1387.0,  -3134.0, 2324.0 },
    { -1433.0,  -3181.0, 2352.0 },
};

EvtScript N(EVS_UnusedFalling2) = {
    EVT_CALL(LoadPath, 135, EVT_PTR(N(UnusedFallingPath2)), ARRAY_COUNT(N(UnusedFallingPath2)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_NE(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
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
        EVT_CALL(MakeLerp, 45, -45, 60 * DT, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_wa, 0, MV_CastleLiftDist, 0)
            EVT_CALL(RotateGroup, MODEL_wa, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, -45, 45, 60 * DT, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_wa, 0, MV_CastleLiftDist, 0)
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

EvtScript N(EVS_AnimateCastle) = {
    EVT_SET(MV_CastleLiftDist, 0)
    EVT_EXEC(N(EVS_AnimateSwingingChains))
    EVT_EXEC(N(EVS_AnimateSpinningRing))
    EVT_CALL(MakeLerp, -800, 4500, 400 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(MV_CastleLiftDist, LVar0)
        EVT_CALL(TranslateGroup, MODEL_g439, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_kao, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_yoru, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80241190) = {
    EVT_CALL(MakeLerp, 0, -5000, 300, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o1464, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80241224) = {
    EVT_CALL(MakeLerp, 0, -5000, 300, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o1502, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802412B8) = {
    EVT_CALL(MakeLerp, 0, -5000, 300, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o1465, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024134C) = {
    EVT_CALL(MakeLerp, 0, -5000, 300, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o1503, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(MV_Scene_CastleAscending) = {
    EVT_CALL(SetMusicTrack, 0, SONG_BOWSER_ATTACKS, 0, 8)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, 0, 0, 2000)
    EVT_CALL(EnableGroup, MODEL_hiru, FALSE)
    EVT_CALL(EnableGroup, MODEL_niwa, FALSE)
    EVT_CALL(EnableGroup, MODEL_jimidori, FALSE)
    EVT_CALL(EnableGroup, MODEL_ki1, FALSE)
    EVT_CALL(EnableGroup, MODEL_jimen, FALSE)
    EVT_CALL(EnableGroup, MODEL_kemuri, FALSE)
    EVT_CALL(EnableGroup, MODEL_obj, FALSE)
    EVT_CALL(EnableGroup, MODEL_g277, FALSE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 80, 16, 4096)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, -1, 0)
    EVT_CALL(SetCamType, CAM_DEFAULT, 1, TRUE)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -150, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-13.0), EVT_FLOAT(18.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_EXEC(N(EVS_AnimateCastle))
    EVT_WAIT(1)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -50, 200, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(1000.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.75))
    EVT_WAIT(180 * DT)
    EVT_CALL(GotoMap, EVT_PTR("kkj_13"), kkj_13_ENTRY_2)
    EVT_WAIT(100 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

Vec3f N(FlightPath_TossedOut)[] = {
    { -300.0,     0.0,  300.0 },
    { -500.0,    25.0,  900.0 },
    { -720.0,  -650.0, 1500.0 },
};

EvtScript N(MV_Scene_PlayerTossedOut) = {
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_UsePower)
    EVT_CALL(EnableGroup, MODEL_hiru, FALSE)
    EVT_CALL(EnableGroup, MODEL_niwa, FALSE)
    EVT_CALL(EnableGroup, MODEL_jimidori, FALSE)
    EVT_CALL(EnableGroup, MODEL_kumo, FALSE)
    EVT_CALL(EnableGroup, MODEL_ki1, FALSE)
    EVT_CALL(EnableGroup, MODEL_jimen, FALSE)
    EVT_CALL(EnableGroup, MODEL_kemuri, FALSE)
    EVT_CALL(EnableGroup, MODEL_obj, FALSE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 80, 16, 4096)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, -1, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, -1, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-13.0), EVT_FLOAT(18.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_SET(MV_CastleLiftDist, 0)
    EVT_EXEC(N(EVS_AnimateSwingingChains))
    EVT_EXEC(N(EVS_AnimateSpinningRing))
    EVT_CHILD_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(0)
            EVT_ADD(LVar0, 45)
            EVT_CALL(InterpPlayerYaw, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(LoadPath, 90 * DT, EVT_PTR(N(FlightPath_TossedOut)), ARRAY_COUNT(N(FlightPath_TossedOut)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GotoMap, EVT_PTR("kkj_13"), kkj_13_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

// alternate scene for the player being tossed out the window, where they flutter down like a piece of paper
EvtScript N(EVS_Scene_UnusedTossOut) = {
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Hurt)
    EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, FALSE)
    EVT_CALL(EnableGroup, MODEL_hiru, FALSE)
    EVT_CALL(EnableGroup, MODEL_niwa, FALSE)
    EVT_CALL(EnableGroup, MODEL_jimidori, FALSE)
    EVT_CALL(EnableGroup, MODEL_kumo, FALSE)
    EVT_CALL(EnableGroup, MODEL_ki1, FALSE)
    EVT_CALL(EnableGroup, MODEL_jimen, FALSE)
    EVT_CALL(EnableGroup, MODEL_kemuri, FALSE)
    EVT_CALL(EnableGroup, MODEL_obj, FALSE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 6000)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -400, -1500, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(3500.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -300, -160)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 300, 80)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-30.0), EVT_FLOAT(0.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_WAIT(15)
    EVT_EXEC_WAIT(N(EVS_UnusedFalling2))
    EVT_WAIT(60)
    EVT_CALL(GotoMap, EVT_PTR("hos_10"), hos_10_ENTRY_5)
    EVT_WAIT(100)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
