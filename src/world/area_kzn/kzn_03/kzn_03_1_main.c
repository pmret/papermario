#include "kzn_03.h"
#include "entity.h"

#include "../common/SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_02_1) = EVT_EXIT_WALK(60, kzn_03_ENTRY_0, "kzn_02", kzn_02_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_04_0) = EVT_EXIT_WALK(60, kzn_03_ENTRY_1, "kzn_04", kzn_04_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_09_0) = EVT_EXIT_WALK(60, kzn_03_ENTRY_2, "kzn_09", kzn_09_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_05_1) = EVT_EXIT_WALK(60, kzn_03_ENTRY_3, "kzn_05", kzn_05_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_09_2) = EVT_EXIT_WALK(60, kzn_03_ENTRY_4, "kzn_09", kzn_09_ENTRY_2);

EvtScript N(EVS_BindTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_09_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_05_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili4, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_09_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili5, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartTexPanners_Lava) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(EnableTexPanning, MODEL_o112, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o151, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_toro, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_poko, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  400,    0,  800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(  300, -500,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        // animate lava bubbles (real ones, not the enemies)
        EVT_SET(LVar0, 0)
        EVT_LOOP(0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar0, 0)
            EVT_ADD(LVar0, 0x8000)
            EVT_WAIT(6)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_03)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindTriggers))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_1)
    EVT_EXEC(N(EVS_StartTexPanners_Lava))
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeLeft))
    EVT_SET(LVar0, MODEL_kem2)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeRight))
    EVT_EXEC_WAIT(N(EVS_SetupZiplines))
    EVT_RETURN
    EVT_END
};
