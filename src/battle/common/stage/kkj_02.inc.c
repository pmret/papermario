#include "battle/battle.h"
#include "mapfs/kkj_bt02_shape.h"

#define NAMESPACE A(kkj_02)

#include "world/common/util/SetLightningBoltPurple.inc.c"

s32 N(RandomBoltPositions)[][7] = {
    { -22, 190, -91,  -88, 21, -91, 60 },
    {  -1, 190, -91,   88, 24, -91, 10 },
    { -67, 190, -91, -122, 10, -91, 90 },
    {  57, 190, -91,   -4, 17, -91, 60 },
};

EvtScript N(EVS_RandomBolts) = {
    EVT_LABEL(0)
        EVT_USE_BUF(N(RandomBoltPositions))
        EVT_LOOP(ARRAY_COUNT(N(RandomBoltPositions)))
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
            EVT_BUF_READ3(LVar3, LVar4, LVar5)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 8, 0)
            EVT_CALL(N(SetLightningBoltPurple))
            EVT_BUF_READ1(LVar0)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(CirculatingBoltPositions)[][7] = {
    { -121, 33, -104, -24,  41, -104,  5 },
    {  36,  41, -104, 128,  34, -104, 30 },
    { 146,   1,  113,  38, -15,  121,  5 },
    { -66, -10,  115, -155,  1,   97, 90 },
};

EvtScript N(EVS_CirculatingBolts) = {
    EVT_LABEL(0)
        EVT_USE_BUF(N(CirculatingBoltPositions))
        EVT_LOOP(ARRAY_COUNT(N(CirculatingBoltPositions)))
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
            EVT_BUF_READ3(LVar3, LVar4, LVar5)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 5, 0)
            EVT_CALL(N(SetLightningBoltPurple))
            EVT_BUF_READ1(LVar0)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_EXEC(N(EVS_RandomBolts))
    EVT_EXEC(N(EVS_CirculatingBolts))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kkj_tex",
    .shape = "kkj_bt02_shape",
    .hit = "kkj_bt02_hit",
    .bg = "kpa_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
