#include "flo_19.h"

// -----------------------------------------------------------
// begin header

EntryList N(Entrances) = {
    {    0.0,    0.0,  100.0,   90.0 },
    {  460.0,    0.0,    0.0,  270.0 },
    {    0.0, -500.0,    0.0,    0.0 },
    {},
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .background = &gBackgroundImage,
    .tattle = { MSG_MapTattle_flo_19 },
};

// -----------------------------------------------------------
// begin music

EvtScript N(EVS_SetupMusic) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(flo_19_ENTRY_0)
        EVT_CASE_OR_EQ(flo_19_ENTRY_1)
            EVT_CALL(SetMusicTrack, 0, SONG_CLOUDY_CLIMB, 0, 8)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(flo_19_ENTRY_2)
        EVT_CASE_OR_EQ(7)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(flo_19_ENTRY_3)
            EVT_IF_NE(AF_FLO_RidingBeanstalk, FALSE)
            EVT_ELSE
                EVT_CALL(FadeOutMusic, 1, 3000)
                EVT_CALL(FadeInMusic, 0, SONG_CLOUDY_CLIMB, 0, 3000, 0, 127)
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 split_pad_entity[] = {
	0x00000000
};

// -----------------------------------------------------------
// begin entity

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_S_JUMP_CHG, -200, 160, -213, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO19_Item_SJumpChg)
    EVT_RETURN
    EVT_END
};

s32 split_pad_main[] = {
	0x00000000, 0x00000000, 0x00000000,
};

// -----------------------------------------------------------
// begin main

#include "world/common/atomic/TexturePan.inc.c"

#include "effects.h"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_21_0) = {
	EVT_SET_GROUP(EVT_GROUP_1B)
	EVT_CALL(UseExitHeading, 60, flo_19_ENTRY_1)
	EVT_EXEC(ExitWalk)
	EVT_CALL(GotoMap, 0x80243000, flo_21_ENTRY_0) // raw pointer to missing string "flo_21"
	EVT_WAIT(100)
	EVT_RETURN
	EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_21_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_CLOUDY_CLIMB)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(GF_MAP_CloudyClimb, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(ParentColliderToModel, COLLIDER_o117, MODEL_o142)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_EXEC(0x80242FD0) // raw pointer to missing N(EVS_SetupBeanstalk)
    EVT_EXEC(0x80241780) // raw pointer to missing N(EVS_SetupClouds)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o122, SURFACE_TYPE_CLOUD)
    EVT_CALL(EnableTexPanning, MODEL_o59, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o60, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -120,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(  -90,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, flo_19_ENTRY_3)
        EVT_SET(AF_FLO_RidingBeanstalk, FALSE)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(flo_19_ENTRY_0)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(flo_19_ENTRY_1)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(flo_19_ENTRY_2)
            EVT_EXEC(0x80242A2C) // raw pointer to missing N(EVS_Scene_BeanstalkGrowing)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(flo_19_ENTRY_3)
            EVT_EXEC(0x80241CC4) // raw pointer to missing N(EVS_Enter_Beanstalk)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 split_pad_clouds[] = {    	
	0x00000000, 0x00000000, 0x00000000,
};

// -----------------------------------------------------------
// begin clouds

API_CALLABLE(N(CosInterpAbsMinMax)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVarTime = *args++;
    s32 time = evt_get_variable(script, outVarTime);
    s32 outValue = *args++;
    f32 min = evt_get_float_variable(script, *args++);
    f32 max = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    s32 onlyOnce = evt_get_variable(script, *args++);
    f32 phaseOffset = (evt_get_float_variable(script, *args++) / 180.0f) * PI;
    f32 delta = fabsf(max - min) / 2; // fabsf here is the only difference between this and CosInterpMinMax

    if (onlyOnce && duration < time) {
        time = duration;
        evt_set_variable(script, outVarTime, duration);
    }

    evt_set_float_variable(script, outValue,
        (min + delta) // average value
        - (delta * cos_rad(((time * PI) / duration) + phaseOffset))); // perturbation

    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimatePlatforms) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_SET(LVarF, 0)
    EVT_LABEL(0)
        EVT_SETF(LVar0, EVT_FLOAT(-215.4375))
        EVT_SETF(LVar1, EVT_FLOAT(128.593))
        EVT_SETF(LVar2, EVT_FLOAT(-200.0))
        EVT_ADDF(LVar1, MV_Distortion_Platform_01)
        EVT_CALL(TranslateGroup, MODEL_g17, LVar0, LVar1, LVar2)
        EVT_SETF(LVar0, EVT_FLOAT(-79.86))
        EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar1, EVT_FLOAT(5.0), EVT_FLOAT(136.765), 300, 0, 0)
        EVT_SETF(LVar2, EVT_FLOAT(-200.0))
        EVT_ADDF(LVar1, MV_Distortion_Platform_02)
        EVT_CALL(TranslateGroup, MODEL_g21, LVar0, LVar1, LVar2)
        EVT_SETF(LVar0, EVT_FLOAT(-364.265625))
        EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar1, EVT_FLOAT(5.0), EVT_FLOAT(106.765), 300, 0, 0)
        EVT_SETF(LVar2, EVT_FLOAT(10.0))
        EVT_ADDF(LVar1, MV_Distortion_Platform_03)
        EVT_CALL(TranslateGroup, MODEL_g22, LVar0, LVar1, LVar2)
        EVT_SETF(LVar0, EVT_FLOAT(295.734))
        EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar1, EVT_FLOAT(65.0), EVT_FLOAT(86.984), 200, 0, 0)
        EVT_SETF(LVar2, EVT_FLOAT(-80.0))
        EVT_ADDF(LVar1, MV_Distortion_Platform_04)
        EVT_CALL(TranslateGroup, MODEL_g23, LVar0, LVar1, LVar2)
        EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar2, EVT_FLOAT(0.968), EVT_FLOAT(1.031), 15, 0, 0)
        EVT_CALL(N(CosInterpAbsMinMax), LVarF, LVar3, EVT_FLOAT(1.031), EVT_FLOAT(0.968), 15, 0, 0)
        EVT_SETF(LVar0, MV_Distortion_Platform_01)
        EVT_SETF(LVar1, MV_Distortion_Platform_01)
        EVT_MULF(LVar0, EVT_FLOAT(-0.02))
        EVT_MULF(LVar1, EVT_FLOAT(0.04))
        EVT_ADDF(LVar0, LVar2)
        EVT_ADDF(LVar1, LVar3)
        EVT_CALL(ScaleGroup, MODEL_g17, LVar0, LVar1, 1)
        EVT_SETF(LVar0, MV_Distortion_Platform_02)
        EVT_SETF(LVar1, MV_Distortion_Platform_02)
        EVT_MULF(LVar0, EVT_FLOAT(-0.02))
        EVT_MULF(LVar1, EVT_FLOAT(0.04))
        EVT_ADDF(LVar0, LVar2)
        EVT_ADDF(LVar1, LVar3)
        EVT_CALL(ScaleGroup, MODEL_g21, LVar0, LVar1, 1)
        EVT_SETF(LVar0, MV_Distortion_Platform_03)
        EVT_SETF(LVar1, MV_Distortion_Platform_03)
        EVT_MULF(LVar0, EVT_FLOAT(-0.02))
        EVT_MULF(LVar1, EVT_FLOAT(0.04))
        EVT_ADDF(LVar0, LVar2)
        EVT_ADDF(LVar1, LVar3)
        EVT_CALL(ScaleGroup, MODEL_g22, LVar0, LVar1, 1)
        EVT_SETF(LVar0, MV_Distortion_Platform_04)
        EVT_SETF(LVar1, MV_Distortion_Platform_04)
        EVT_MULF(LVar0, EVT_FLOAT(-0.02))
        EVT_MULF(LVar1, EVT_FLOAT(0.04))
        EVT_ADDF(LVar0, LVar2)
        EVT_ADDF(LVar1, LVar3)
        EVT_CALL(ScaleGroup, MODEL_g23, LVar0, LVar1, 1)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o77)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o78)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o76)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o79)
        EVT_ADD(LVarF, 1)
        EVT_IF_GE(LVarF, 1200)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_SETF(LVar0, LVarA)
		// the rest of the script is cut off halfway through the next EVT_SETF cmd
	/*
        EVT_SETF(LVar1, LVarB)
        EVT_SETF(LVar2, LVarC)
        EVT_SETF(LVar3, LVarD)
        EVT_MULF(LVar0, EVT_FLOAT(-0.046875))
        EVT_MULF(LVar1, EVT_FLOAT(-0.09375))
        EVT_MULF(LVar2, EVT_FLOAT(-0.09375))
        EVT_MULF(LVar3, EVT_FLOAT(-0.09375))
        EVT_ADDF(MV_Distortion_Platform_01, LVar0)
        EVT_ADDF(MV_Distortion_Platform_02, LVar1)
        EVT_ADDF(MV_Distortion_Platform_03, LVar2)
        EVT_ADDF(MV_Distortion_Platform_04, LVar3)
        EVT_MULF(MV_Distortion_Platform_01, EVT_FLOAT(0.843))
        EVT_MULF(MV_Distortion_Platform_02, EVT_FLOAT(0.843))
        EVT_MULF(MV_Distortion_Platform_03, EVT_FLOAT(0.843))
        EVT_MULF(MV_Distortion_Platform_04, EVT_FLOAT(0.843))
        EVT_ADDF(LVarA, MV_Distortion_Platform_01)
        EVT_ADDF(LVarB, MV_Distortion_Platform_02)
        EVT_ADDF(LVarC, MV_Distortion_Platform_03)
        EVT_ADDF(LVarD, MV_Distortion_Platform_04)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
	*/
};

// half of EVT_SETF(LVar1, LVarB)
s32 N(EVS_AnimatePlatforms_Fragment)[] = {    	
	EVT_OP_SETF, 2,
};

// -----------------------------------------------------------
// begin beanstalks

API_CALLABLE(N(GetPlayerAngles)) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;
    s32 var2 = *args++;

    evt_set_variable(script, var1, gPlayerStatus.spriteFacingAngle);
    evt_set_variable(script, var2, gPlayerStatus.targetYaw);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PlayerRideBeanstalk)) {
    f32 temp = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(0.0f, 0.0f, script->varTable[9], script->varTable[11]);
    f32 angle = atan2(0.0f, 0.0f, script->varTable[9], script->varTable[11]);
    f32 clamped = clamp_angle(angle - temp);

    temp = sin_deg(clamped);
    gPlayerStatus.position.x = (dist * temp) + 0.0f;
    gPlayerStatus.position.y = evt_get_variable(NULL, script->varTable[10]) + evt_get_variable(NULL, script->varTable[3]);
    temp = cos_deg(clamped);
    gPlayerStatus.position.z = 0.0f - (dist * temp);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PartnerRideBeanstalk)) {
    Npc* npc = get_npc_by_index(NPC_Dummy_Partner);
    f32 temp = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(0.0f, 0.0f, script->varTable[12], script->varTable[14]);
    f32 angle = atan2(0.0f, 0.0f, script->varTable[12], script->varTable[14]);
    f32 clamped = clamp_angle(angle - temp);

    temp = sin_deg(clamped);
    npc->pos.x = (dist * temp) + 0.0f;
    npc->pos.y = evt_get_variable(NULL, script->varTable[13]) + evt_get_variable(NULL, script->varTable[3]);
    temp = cos_deg(clamped);
    npc->pos.z = 0.0f - (dist * temp);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetScreenFadeAmount)) {
    set_screen_overlay_params_back(1, script->varTable[0]);
    return ApiStatus_DONE2;
}

#include "common/CosInterpMinMax.inc.c"

// all beanstalk data is missing
