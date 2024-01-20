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
    Label(0)
        UseBuf(N(RandomBoltPositions))
        Loop(ARRAY_COUNT(N(RandomBoltPositions)))
            BufRead3(LVar0, LVar1, LVar2)
            BufRead3(LVar3, LVar4, LVar5)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 8, 0)
            Call(N(SetLightningBoltPurple))
            BufRead1(LVar0)
            Wait(LVar0)
        EndLoop
        Goto(0)
    Return
    End
};

s32 N(CirculatingBoltPositions)[][7] = {
    { -121, 33, -104, -24,  41, -104,  5 },
    {  36,  41, -104, 128,  34, -104, 30 },
    { 146,   1,  113,  38, -15,  121,  5 },
    { -66, -10,  115, -155,  1,   97, 90 },
};

EvtScript N(EVS_CirculatingBolts) = {
    Label(0)
        UseBuf(N(CirculatingBoltPositions))
        Loop(ARRAY_COUNT(N(CirculatingBoltPositions)))
            BufRead3(LVar0, LVar1, LVar2)
            BufRead3(LVar3, LVar4, LVar5)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 1, 5, 0)
            Call(N(SetLightningBoltPurple))
            BufRead1(LVar0)
            Wait(LVar0)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Exec(N(EVS_RandomBolts))
    Exec(N(EVS_CirculatingBolts))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "kkj_tex",
    .shape = "kkj_bt02_shape",
    .hit = "kkj_bt02_hit",
    .bg = "kpa_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
