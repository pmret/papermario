#include "common.h"

EvtScript N(EVS_MarioSalute) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};
