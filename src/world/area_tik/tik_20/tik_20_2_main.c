#include "tik_20.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_tik_08_1) = EVT_EXIT_WALK(60, tik_20_ENTRY_0, "tik_08", tik_08_ENTRY_1);
EvtScript N(EVS_ExitWalk_tik_21_0) = EVT_EXIT_WALK(60, tik_20_ENTRY_1, "tik_21", tik_21_ENTRY_0);

EvtScript N(EVS_GotoMap_tik_23_1) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_23"), tik_23_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_tik_23_1) = EVT_EXIT_PIPE_VERTICAL(tik_20_ENTRY_2, COLLIDER_o109, N(EVS_GotoMap_tik_23_1));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_08_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_21_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_23_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_o109, 1, 0)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_yuka, .pos = { -190.0,   30.0,  -85.0 }},
    { .colliderID = COLLIDER_yuka2, .pos = {  200.0,   30.0,  -70.0 }},
    { .colliderID = -1 }
};

#define DROPLET_MODEL MODEL_sizuku
#include "../common/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 2,
    .volumes = {
        {
            .minPos = { -312,  -19 },
            .maxPos = {   52,   46 },
            .startY = 200,
            .endY   = -20,
            .duration = 60,
            .density  = 2,
        },
        {
            .minPos = {  460,  -50 },
            .maxPos = {   40,  185 },
            .startY = 200,
            .endY   = -20,
            .duration = 60,
            .density  = 1,
        }
    }
};

EvtScript N(EVS_SetupDrips) = {
    EVT_SET(LVar0, EVT_PTR(N(DripVolumes)))
    EVT_EXEC(N(EVS_CreateDripVolumes))
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1,unk);

#include "../common/Flotsam.inc.c"

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_TIK_20)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_toge, SURFACE_TYPE_SPIKES)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(PlaySound, SOUND_LOOP_TIK20_WATER)
    EVT_EXEC(N(EVS_SetupDrips))
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(   70,  100,  100,  130)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_nagare, 0)
    EVT_THREAD
        EVT_SET(LVar2, MODEL_bin)
        EVT_EXEC(N(EVS_Flotsam_Bobbing))
        EVT_WAIT(5)
        EVT_SET(LVar2, MODEL_kan1)
        EVT_EXEC(N(EVS_Flotsam_Bobbing))
        EVT_WAIT(5)
        EVT_SET(LVar2, MODEL_kan2)
        EVT_EXEC(N(EVS_Flotsam_Bobbing))
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(tik_20_ENTRY_0)
        EVT_CASE_OR_EQ(tik_20_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(tik_20_ENTRY_2)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
