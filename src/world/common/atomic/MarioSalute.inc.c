#include "common.h"
#include "sprite/player.h"

EvtScript N(EVS_MarioSalute) = {
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(1)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(20)
    Return
    End
};
