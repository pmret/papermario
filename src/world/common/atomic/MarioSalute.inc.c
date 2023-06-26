#include "common.h"
#include "sprite/player.h"

EvtScript N(EVS_MarioSalute) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};
