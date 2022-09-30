#include "kzn_20.h"
#include "effects.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_ShakingWorld);
extern NpcGroupList N(DefaultNPCs);

EntryList N(Entrances) = {
    [kzn_20_ENTRY_0]    { -182.0,    0.0,   36.0,   90.0 },
    [kzn_20_ENTRY_1]    {  164.0,  150.0,   20.0,  270.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
    .tattle = { MSG_MapTattle_kzn_20 },
};

EvtScript N(EVS_SetupMusic) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
        EVT_CALL(PlaySound, SOUND_8000006B)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
        EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA3)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_VOLCANO_ESCAPE, 0, 8)
        EVT_CALL(PlayAmbientSounds, AMBIENT_UNDER_SEA1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

//SPLIT? header//main

#include "world/common/atomic/TexturePan.inc.c"
#include "world/common/atomic/TexturePan.data.inc.c"

EvtScript N(EVS_ExitWalk_kzn_19_2) = EVT_EXIT_WALK(60, kzn_20_ENTRY_0, "kzn_19", kzn_19_ENTRY_2);
EvtScript N(EVS_ExitWalk_kzn_22_0) = EVT_EXIT_WALK(60, kzn_20_ENTRY_1, "kzn_22", kzn_22_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_19_2), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_22_0), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateTexPan_Lava) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(EnableTexPanning, MODEL_yu, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -700,  700,  200, -300)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o919, .pos = { -30.0, 125.0, -15.0 }},
    { .colliderID = COLLIDER_o870, .pos = {  30.0, 150.0,   0.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_DetermineLavaLevel) = {
    EVT_LOOP(0)
        EVT_IF_GE(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
            EVT_LABEL(1)
                EVT_IF_LT(MV_LavaPosOffset, 110)
                    EVT_SUBF(MV_WaveScaleOffset, EVT_FLOAT(0.01))
                    EVT_ADDF(MV_PosScaleCoeff, EVT_FLOAT(0.01))
                    EVT_LOOP(5)
                        EVT_ADDF(MV_LavaPosOffset, EVT_FLOAT(0.75))
                        EVT_WAIT(9)
                    EVT_END_LOOP
                EVT_ELSE
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_InterruptPartnersInLava) = {
    EVT_LOOP(0)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetModelCenter, MODEL_yu)
            EVT_CALL(GetPlayerPos, LVar0, LVar3, LVar2)
            EVT_IF_LT(LVar3, LVar1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_NE(LVar1, PARTNER_LAKILESTER)
            EVT_CALL(InterruptUsePartner)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_HIT_LAVA)
            EVT_WAIT(30)
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateLavaWaves) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_CALL(EnableModel, MODEL_yu, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_yu, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ParentColliderToModel, COLLIDER_yu, MODEL_yu)
    EVT_LABEL(0)
        EVT_IF_EQ(AF_KZN_0B, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(EnableModel, MODEL_yu, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS,  COLLIDER_yu, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yu, SURFACE_TYPE_LAVA)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        EVT_SETF(MV_LavaPosOffset, 35)
        EVT_SETF(MV_WaveScaleOffset, EVT_FLOAT(1.2))
        EVT_SETF(MV_PosScaleCoeff, EVT_FLOAT(-1.2))
    EVT_ELSE
        EVT_SETF(MV_LavaPosOffset, 110)
        EVT_SETF(MV_WaveScaleOffset, EVT_FLOAT(1.0))
        EVT_SETF(MV_PosScaleCoeff, EVT_FLOAT(-1.0))
    EVT_END_IF
    EVT_EXEC(N(EVS_DetermineLavaLevel))
    EVT_EXEC(N(EVS_InterruptPartnersInLava))
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 0, 260, 30, EASING_COS_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_SUBF(LVar0, MV_WaveScaleOffset)
            EVT_SETF(LVar3, MV_LavaPosOffset)
            EVT_SETF(LVar4, MV_LavaPosOffset)
            EVT_DIVF(LVar3, MV_PosScaleCoeff)
            EVT_MULF(LVar3, LVar0)
            EVT_ADDF(LVar4, LVar3) // = PosOffset + Scale * (PosOffset / PosScaleCoeff)
            EVT_CALL(TranslateModel, MODEL_yu, 0, LVar4, 0)
            EVT_CALL(ScaleModel, MODEL_yu, 1, LVar0, 1)
            EVT_CALL(TranslateModel, MODEL_yu, 0, MV_LavaPosOffset, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_yu)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 260, 0, 60, EASING_SIN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_SUBF(LVar0, MV_WaveScaleOffset)
            EVT_SETF(LVar3, MV_LavaPosOffset)
            EVT_SETF(LVar4, MV_LavaPosOffset)
            EVT_DIVF(LVar3, MV_PosScaleCoeff)
            EVT_MULF(LVar3, LVar0)
            EVT_ADDF(LVar4, LVar3)
            EVT_CALL(TranslateModel, MODEL_yu, 0, LVar4, 0)
            EVT_CALL(ScaleModel, MODEL_yu, 1, LVar0, 1)
            EVT_CALL(TranslateModel, MODEL_yu, 0, MV_LavaPosOffset, 0)
            EVT_CALL(UpdateColliderTransform, COLLIDER_yu)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

BombTrigger N(WeakWallBombTrigger) = {
    .pos = { 175.0, 150.0, 15.0 },
    .radius = 0.0
};

EvtScript N(EVS_OnBreakWall) = {
    EVT_CALL(PlayEffect, EFFECT_BOMBETTE_BREAKING, 0, 2, 2, 1, 10, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(EnableGroup, MODEL_bom_mae, FALSE)
    EVT_CALL(EnableGroup, MODEL_bom_ato, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_20)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_SET(LVar0, N(EVS_BindExitTriggers))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_ShakingWorld))
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        EVT_CALL(EnableGroup, MODEL_bom_ato, FALSE)
        EVT_BIND_TRIGGER(N(EVS_OnBreakWall), TRIGGER_POINT_BOMB, EVT_PTR(N(WeakWallBombTrigger)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_bom_mae, FALSE)
        EVT_CALL(ModifyColliderFlags, 0, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_UpdateLavaWaves))
    EVT_EXEC(N(EVS_UpdateTexPan_Lava))
    EVT_RETURN
    EVT_END
};
