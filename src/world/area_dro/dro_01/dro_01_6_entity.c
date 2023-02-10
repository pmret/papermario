#include "dro_01.h"
#include "entity.h"

#define NAMESPACE dro_01_Entity
#include "world/common/entity/Pipe.inc.c"
#define NAMESPACE dro_01

EvtScript N(EVS_WarpPipeExit) = {
    EVT_SET(GF_DRO01_HeardHintAboutSpinningRoof, FALSE)
    EVT_CALL(GotoMap, EVT_PTR("tik_01"), tik_01_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -211, 60, -50, 30, MAKE_ENTITY_END)
    EVT_IF_EQ(GF_DRO01_WarpPipe, FALSE)
        EVT_IF_EQ(GF_TIK01_WarpPipes, TRUE)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_NE(LVar0, dro_01_ENTRY_2)
                EVT_SET(GF_DRO01_WarpPipe, TRUE)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueWarpPipe), 430, 0, -120, 0,
        dro_01_ENTRY_2, EVT_PTR(N(EVS_WarpPipeExit)),
        EVT_INDEX_OF_GAME_FLAG(GF_DRO01_WarpPipe), MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
