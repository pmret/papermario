#include "machi.h"

API_CALLABLE(N(CheckGameVarRanges)) {
    GameVarRange* bytes;
    GameVarRange* flags;

    bytes = N(GameByteTable);
    while (TRUE) {
        if (bytes->name == 0) {
            break;
        }
        // release version does nothing
        bytes++;
    }

    flags = N(GameFlagTable);
    while (TRUE) {
        if (flags->name == 0) {
            break;
        }
        // release version does nothing
        flags++;
    }

    return 2;
}

EvtScript N(EVS_GotoMap_kmr_09_1) = {
    EVT_CALL(GotoMap, EVT_PTR("kmr_09"), kmr_09_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_nok_10_0) = {
    EVT_CALL(GotoMap, EVT_PTR("nok_10"), nok_10_ENTRY_0) //@bug map does not exist!
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_iwa_00_0) = {
    EVT_CALL(GotoMap, EVT_PTR("iwa_00"), iwa_00_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_tst_01_0) = {
    EVT_CALL(GotoMap, EVT_PTR("tst_01"), tst_01_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_jan_00_0) = {
    EVT_CALL(GotoMap, EVT_PTR("jan_00"), jan_00_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_CALL(N(CheckGameVarRanges))
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_GotoMap_kmr_09_1)), TRIGGER_WALL_PUSH, COLLIDER_deilitn, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_GotoMap_nok_10_0)), TRIGGER_WALL_PUSH, COLLIDER_deilitne, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_GotoMap_iwa_00_0)), TRIGGER_WALL_PUSH, COLLIDER_deilite, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_GotoMap_tst_01_0)), TRIGGER_WALL_PUSH, COLLIDER_deilitnw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_GotoMap_jan_00_0)), TRIGGER_WALL_PUSH, COLLIDER_deilitsw, 1, 0)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_GoombaKing_Init))
    EVT_EXEC(N(EVS_FlyPartnerAround))
    EVT_RETURN
    EVT_END
};
