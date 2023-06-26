#include "kpa_14.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(GetActingPartner)) {
    if (gPartnerStatus.partnerActionState != 0) {
        script->varTable[9] = gPartnerStatus.actingPartner;
    } else {
        script->varTable[9] = -1;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_kpa_13_1) = EVT_EXIT_WALK(60, kpa_14_ENTRY_0, "kpa_13", kpa_13_ENTRY_1);

EvtScript N(EVS_ExitDoor_kpa_01_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, kpa_14_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilitte)
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_SET(LVar2, MODEL_o1035)
    EVT_ELSE
        EVT_SET(LVar2, MODEL_o1036)
    EVT_END_IF
    EVT_SET(LVar3, DOOR_SWING_OUT)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kpa_01"), kpa_01_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kpa_16_0) = EVT_EXIT_WALK(60, kpa_14_ENTRY_2, "kpa_16", kpa_16_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_16_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_14_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(kpa_14_ENTRY_1)
            EVT_SET(LVar0, kpa_14_ENTRY_1)
            EVT_SET(LVar1, COLLIDER_deilitte)
            EVT_SET(LVar2, MODEL_o1035)
            EVT_SET(LVar3, DOOR_SWING_OUT)
            EVT_EXEC(EnterSingleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_14_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Lava) = {
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(-1000,    0,-2000,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o631, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o625, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o776, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o777, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o778, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_o779, TEX_PANNER_1)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o202, .pos = {  110.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o201, .pos = {  345.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o196, .pos = {  550.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o197, .pos = {  800.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o195, .pos = { 1045.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o198, .pos = { 1400.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o200, .pos = { 1590.0,   30.0,  -90.0 }},
    { .colliderID = COLLIDER_o199, .pos = { 1940.0,   30.0, -135.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Touch_LeftOfLavaFall) = {
    EVT_SET(MV_LastFloorBeforeLavaFall, COLLIDER_o195)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Touch_RightOfLavaFall) = {
    EVT_SET(MV_LastFloorBeforeLavaFall, COLLIDER_o198)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeSmokeEffects) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 10)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupLavaFall) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_LOOP(0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o854, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(N(GetActingPartner))
        EVT_SWITCH(LVar9)
            EVT_CASE_EQ(8)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o854, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CASE_EQ(9)
            EVT_CASE_DEFAULT
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_IF_LT(LVar1, 120)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_RANGE(1200, 1245)
                            EVT_CALL(DisablePlayerInput, TRUE)
                            EVT_CALL(DisablePlayerPhysics, TRUE)
                            EVT_SET(MV_TakingLavaFallDamage, TRUE)
                            EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
                            EVT_EXEC_GET_TID(N(EVS_MakeSmokeEffects), LVar9)
                            EVT_IF_EQ(MV_LastFloorBeforeLavaFall, COLLIDER_o195)
                                EVT_SET(LVar5, 1045)
                            EVT_ELSE
                                EVT_SET(LVar5, 1400)
                            EVT_END_IF
                            EVT_WAIT(1)
                            EVT_CALL(InterruptUsePartner)
                            EVT_CALL(SetPlayerActionState, ACTION_STATE_HIT_LAVA)
                            EVT_WAIT(10)
                            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar5, 30, -135)
                            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar5, 30, -135)
                            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
                            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                            EVT_CALL(MakeLerp, LVar0, LVar5, 30, EASING_LINEAR)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_CALL(SetPlayerPos, LVar0, 250, -135)
                                EVT_WAIT(1)
                                EVT_IF_EQ(LVar1, 0)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                            EVT_CALL(MakeLerp, 250, 30, 20, EASING_QUADRATIC_IN)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_CALL(SetPlayerPos, LVar5, LVar0, -135)
                                EVT_WAIT(1)
                                EVT_IF_EQ(LVar1, 0)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Thrown)
                            EVT_CALL(MakeLerp, 30, 60, 5, EASING_QUADRATIC_IN)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_CALL(SetPlayerPos, LVar5, LVar0, -135)
                                EVT_WAIT(1)
                                EVT_IF_EQ(LVar1, 0)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                            EVT_KILL_THREAD(LVar9)
                            EVT_CALL(MakeLerp, 60, 30, 5, EASING_QUADRATIC_IN)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_CALL(SetPlayerPos, LVar5, LVar0, -135)
                                EVT_WAIT(1)
                                EVT_IF_EQ(LVar1, 0)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                            EVT_WAIT(5)
                            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                            EVT_CALL(DisablePlayerPhysics, FALSE)
                            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
                            EVT_CALL(DisablePlayerInput, FALSE)
                            EVT_WAIT(1)
                            EVT_SET(MV_TakingLavaFallDamage, FALSE)
                    EVT_END_SWITCH
                EVT_END_IF
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(EnableGroup, MODEL_after, FALSE)
        EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_before, FALSE)
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_EXEC(N(EVS_SetupPlatforms))
    EVT_END_IF
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_THREAD
            EVT_WAIT(2)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o625, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o776, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o818, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o819, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o820, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o821, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o822, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o823, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o824, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o825, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o826, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o827, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o828, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o829, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o830, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o857, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o858, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilin, SURFACE_TYPE_LAVA)
            EVT_THREAD
                EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
            EVT_END_THREAD
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Touch_LeftOfLavaFall)), TRIGGER_FLOOR_TOUCH, COLLIDER_o195, 1, 0)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Touch_RightOfLavaFall)), TRIGGER_FLOOR_TOUCH, COLLIDER_o198, 1, 0)
            EVT_EXEC(N(EVS_SetupLavaFall))
        EVT_END_THREAD
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o854, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
