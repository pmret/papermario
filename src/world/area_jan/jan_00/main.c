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
    BindTrigger(Ref(N(EVS_ExitWalk_jan_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_08_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Set(GF_MAP_JadeJungle, TRUE)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Call(EnableTexPanning, MODEL_o135, TRUE)
    Call(EnableTexPanning, MODEL_o142, TRUE)
    Call(EnableTexPanning, MODEL_o52, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0,  400,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP( -100,  200,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Exec(N(EVS_802467AC))
    Exec(N(EVS_80247A2C))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitne, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitse, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, jan_00_ENTRY_0)
        Exec(N(EVS_BindExitTriggers))
    Else
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    EndIf
    Call(func_8024030C_B2084C)
    ExecWait(N(EVS_80241C10))
    Call(PlaySound, SOUND_LOOP_JAN_BEACH_WAVES)
    Return
    End
};
