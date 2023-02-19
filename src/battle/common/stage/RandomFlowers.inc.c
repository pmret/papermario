#include "common.h"
#include "effects.h"

EvtScript N(EVS_RandomFlowers_Background) = {
    EVT_LABEL(0)
        // posX range: 125 to 375
        EVT_CALL(RandInt, 250, LVar0)
        EVT_SUB(LVar0, 125)
        // posY: 0
        EVT_SET(LVar1, 0)
        // posZ range: -100 to -60
        EVT_CALL(RandInt, 40, LVar2)
        EVT_SUB(LVar2, 100)
        EVT_CALL(RandInt, 30, LVar3)
        EVT_ADD(LVar3, 90)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, LVar0, LVar1, LVar2, LVar3, 0, 0)
        EVT_CALL(RandInt, 20, LVar0)
        EVT_ADD(LVar0, 20)
        EVT_WAIT(LVar0)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RandomFlowers_Foreground) = {
    EVT_LABEL(0)
        // posX range: 125 to 375
        EVT_CALL(RandInt, 250, LVar0)
        EVT_SUB(LVar0, 125)
        // posY: 0
        EVT_SET(LVar1, 0)
        // posZ range: 71 to 121
        EVT_CALL(RandInt, 50, LVar2)
        EVT_ADD(LVar2, 71)
        EVT_CALL(RandInt, 30, LVar3)
        EVT_ADD(LVar3, 90)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, LVar0, LVar1, LVar2, LVar3, 0, 0)
        EVT_CALL(RandInt, 30, LVar0)
        EVT_ADD(LVar0, 20)
        EVT_WAIT(LVar0)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RandomFlowers_FarBack) = {
    EVT_LABEL(0)
        // posX range: 125 to 375
        EVT_CALL(RandInt, 250, LVar0)
        EVT_SUB(LVar0, 125)
        // posY: 50
        EVT_SET(LVar1, 50)
        // posZ range: -124 to -84
        EVT_CALL(RandInt, 40, LVar2)
        EVT_ADD(LVar2, -124)
        EVT_CALL(RandInt, 30, LVar3)
        EVT_ADD(LVar3, 90)
        EVT_PLAY_EFFECT(EFFECT_FLOATING_FLOWER, LVar0, LVar1, LVar2, LVar3, 0, 0)
        EVT_CALL(RandInt, 30, LVar0)
        EVT_ADD(LVar0, 20)
        EVT_WAIT(LVar0)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};
