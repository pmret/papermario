#include "tst_03.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);

EntryList N(Entrances) = {
    [tst_03_ENTRY_0]    {  -85.0,    0.0,   10.0,    0.0 },
    [tst_03_ENTRY_1]    { 1536.0,    0.0,   15.0,    0.0 },
    [tst_03_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_03_ENTRY_3]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_03_ENTRY_4]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_03_ENTRY_5]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_03_ENTRY_6]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_03_ENTRY_7]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_03_ENTRY_8]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_03_ENTRY_9]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_03_ENTRY_A]    {  354.0,    0.0,  294.0,  117.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

EvtScript N(EVS_GotoMap_tst_02_1) = {
    EVT_CALL(GotoMap, EVT_PTR("tst_02"), tst_02_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_tst_04_0) = {
    EVT_CALL(GotoMap, EVT_PTR("tst_04"), tst_04_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TESTING)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_GotoMap_tst_02_1)), TRIGGER_WALL_PUSH, COLLIDER_deilitw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_GotoMap_tst_04_0)), TRIGGER_WALL_PUSH, COLLIDER_deilite, 1, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_puku, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_pukut, SURFACE_TYPE_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_puku,  COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_pukut, COLLIDER_FLAG_DOCK_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o264, SURFACE_TYPE_WATER)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o265, SURFACE_TYPE_SPIKES)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o236, SURFACE_TYPE_LAVA)
    EVT_RETURN
    EVT_END
};
