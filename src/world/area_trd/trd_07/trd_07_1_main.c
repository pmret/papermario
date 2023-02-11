#include "trd_07.h"

extern EvtScript N(EVS_SetupMagicDoors);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_trd_08_0) = EVT_EXIT_WALK(60, trd_07_ENTRY_1, "trd_08", trd_08_ENTRY_0);
EvtScript N(EVS_ExitWalk_trd_04_4) = EVT_EXIT_WALK(60, trd_07_ENTRY_0, "trd_04", trd_04_ENTRY_4);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_trd_08_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_trd_04_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_tte, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_1) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, 0)
        EVT_ADD(LVar0, 100)
        EVT_SUB(LVar1, 100)
        EVT_WAIT(1)
        EVT_GOTO(10)
        EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_TexPan_1))
    EVT_EXEC_WAIT(N(EVS_SetupMagicDoors))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC_GET_TID(EnterWalk, MV_EnterWalkScriptID)
    EVT_WAIT(1)
    EVT_CALL(EnableTexPanning, MODEL_suimen2, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,   90,  -60,  -70)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
