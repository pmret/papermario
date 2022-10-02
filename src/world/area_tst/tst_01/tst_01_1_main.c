
#include "tst_01.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);

EntryList N(Entrances) = {
    [tst_01_ENTRY_0]    {  -35.0,    0.0,   17.0,    0.0 },
    [tst_01_ENTRY_1]    {  338.0,    0.0,    5.0,    0.0 },
    [tst_01_ENTRY_2]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_01_ENTRY_3]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_01_ENTRY_4]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_01_ENTRY_5]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_01_ENTRY_6]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_01_ENTRY_7]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_01_ENTRY_8]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_01_ENTRY_9]    {    0.0,    0.0,    0.0,    0.0 },
    [tst_01_ENTRY_A]    {  354.0,    0.0,  294.0,  117.0 },
};

MapSettings N(settings) = {
    .main = &N(EVS_Main),
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

EvtScript N(EVS_GotoMap_machi_7) = {
    EVT_CALL(GotoMap, EVT_PTR("machi"), machi_ENTRY_7)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_tst_02_0) = {
    EVT_CALL(GotoMap, EVT_PTR("tst_02"), tst_02_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TESTING)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_GotoMap_machi_7)), TRIGGER_WALL_PUSH, COLLIDER_deilitw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_GotoMap_tst_02_0)), TRIGGER_WALL_PUSH, COLLIDER_deilite, 1, 0)
    EVT_RETURN
    EVT_END
};
