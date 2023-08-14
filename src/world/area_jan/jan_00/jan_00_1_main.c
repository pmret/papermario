#include "jan_00.h"
#include "npc.h"
#include "effects.h"
#include "entity.h"

extern EvtScript N(EVS_80241C10);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_MakeEntities);

extern EvtScript N(EVS_802467AC);
extern EvtScript N(EVS_80247A2C);

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(func_8024030C_B2084C) {
    fx_sun_undeclared(FX_SUN_FROM_LEFT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_jan_01_0) = EVT_EXIT_WALK(60, jan_00_ENTRY_1, "jan_01", jan_01_ENTRY_0);
EvtScript N(EVS_ExitWalk_jan_08_0) = EVT_EXIT_WALK(60, jan_00_ENTRY_2, "jan_08", jan_08_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_08_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SET(GF_MAP_JadeJungle, TRUE)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(EnableTexPanning, MODEL_o135, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o142, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o52, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,  400,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP( -100,  200,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_802467AC))
    EVT_EXEC(N(EVS_80247A2C))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitse, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, jan_00_ENTRY_0)
        EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_CALL(func_8024030C_B2084C)
    EVT_EXEC_WAIT(N(EVS_80241C10))
    EVT_CALL(PlaySound, SOUND_LOOP_JAN_BEACH_WAVES)
    EVT_RETURN
    EVT_END
};
