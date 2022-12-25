#include "obk_04.h"
#include "effects.h"

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(obk_04_ENTRY_0)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
                EVT_CALL(PlayerMoveTo, -150, LVar2, 0)
            EVT_END_THREAD
            EVT_CALL(EnableModel, MODEL_door_off1, FALSE)
            EVT_CALL(EnableModel, MODEL_door_off2, FALSE)
            EVT_SET(LVar2, MODEL_door1)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
            EVT_CALL(EnableModel, MODEL_door_off1, TRUE)
            EVT_CALL(EnableModel, MODEL_door_off2, TRUE)
            EVT_WAIT(20)
            EVT_CALL(MakeLerp, 0, -90, 15, EASING_QUADRATIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateModel, MODEL_door1, LVar0, 0, 0, 1)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, -215, 0, 25, 0)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, -215, 0, -25, 0)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, -200, 0, 25, 0)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, -200, 0, -25, 0)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, -185, 0, 25, 0)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, -185, 0, -25, 0)
            EVT_WAIT(20)
            EVT_CALL(EnableModel, MODEL_door1, FALSE)
            EVT_CALL(MakeLerp, 0, 10, 15, EASING_LINEAR)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateModel, MODEL_door_off1, LVar0, 0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(EnableModel, MODEL_door_off3, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Fog) = {
    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_m1, TEX_PANNER_0)
        EVT_CALL(SetTexPanner, MODEL_m2, TEX_PANNER_0)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_LABEL(20)
        EVT_ADD(LVar0, 300)
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOOS_MANSION)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_ManageHole))
    EVT_EXEC(N(EVS_TexPan_Fog))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hip1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
