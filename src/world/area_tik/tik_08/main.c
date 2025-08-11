#include "tik_08.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_tik_09_1) = EVT_EXIT_WALK(60, tik_08_ENTRY_0, "tik_09", tik_09_ENTRY_1);
EvtScript N(EVS_ExitWalk_tik_20_0) = EVT_EXIT_WALK(60, tik_08_ENTRY_1, "tik_20", tik_20_ENTRY_0);

EvtScript N(EVS_GotoMap_tik_06_2) = {
    Call(GotoMap, Ref("tik_06"), tik_06_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_tik_06_2) = EVT_EXIT_PIPE_HORIZONTAL(tik_06_ENTRY_3, COLLIDER_ttd, N(EVS_GotoMap_tik_06_2));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_tik_09_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_tik_20_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ttd, COLLIDER_FLAGS_UPPER_MASK)
    BindTrigger(Ref(N(EVS_ExitPipe_tik_06_2)), TRIGGER_WALL_PUSH, COLLIDER_ttd, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    Call(SetSpriteShading, SHADING_TIK_08)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Call(PlaySound, SOUND_LOOP_TIK08_WATER)
    Call(PlaySoundAtF, SOUND_LOOP_TIK08_FLOW1, SOUND_SPACE_WITH_DEPTH, -30, -30, -85)
    Exec(N(EVS_SetupDrips))
    Call(EnableTexPanning, MODEL_nagare1, true)
    Call(EnableTexPanning, MODEL_o92, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   70,  100,  100,  130)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(EnableTexPanning, MODEL_taki, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(  -50, -900,  -70,-1200)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(EnableTexPanning, MODEL_takib, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(    0,-1400,-2600,  -60)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o77, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o75, SURFACE_TYPE_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o77, COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o75, COLLIDER_FLAG_DOCK_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_suimen, SURFACE_TYPE_WATER)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_ttd, COLLIDER_FLAGS_UPPER_MASK)
    Wait(1)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(tik_08_ENTRY_2)
            ExecWait(N(EVS_BindExitTriggers))
        CaseEq(tik_08_ENTRY_4)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
        CaseEq(tik_08_ENTRY_3)
            EVT_ENTER_PIPE_HORIZONTAL(COLLIDER_ttd, N(EVS_BindExitTriggers))
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Wait(1)
    Return
    End
};
