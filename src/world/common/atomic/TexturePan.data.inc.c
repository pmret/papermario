#include "common.h"
#include "TexturePan.h"

//extern API_CALLABLE(N(UpdateTexturePanSmooth));
//extern API_CALLABLE(N(UpdateTexturePanStepped));

EvtScript N(EVS_UpdateTexturePan) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_IF_EQ(LVar5, 1)
        EVT_IF_EQ(LVar6, 1)
            EVT_IF_EQ(LVar7, 1)
                EVT_IF_EQ(LVar8, 1)
                    EVT_CALL(N(UpdateTexturePanSmooth))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(UpdateTexturePanStepped))
    EVT_RETURN
    EVT_END
};
