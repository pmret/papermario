#include "common.h"
#include "battle/battle.h"
#include "mapfs/flo_bt02_shape.h"
#include "effects.h"

#define NAMESPACE b_area_flo2_flo_02b

EvtScript N(802320E0) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 250, LVar0)
    EVT_SUB(LVar0, 125)
    EVT_SET(LVar1, 0)
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

EvtScript N(802321F8) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 250, LVar0)
    EVT_SUB(LVar0, 125)
    EVT_SET(LVar1, 0)
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

EvtScript N(80232310) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 250, LVar0)
    EVT_SUB(LVar0, 125)
    EVT_SET(LVar1, 50)
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

#include "common/MakeSun.inc.c"

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 35, 0)
    EVT_CALL(SetGroupEnabled, 47, 1)
    EVT_CALL(SetGroupEnabled, 22, 0)
    EVT_EXEC(N(80232310))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, 0, SURFACE_TYPE_FLOWERS)
    EVT_EXEC_WAIT(N(MakeSun))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    -1, MODEL_8hana4, MODEL_8hana5, MODEL_8hana6, MODEL_8hana1, MODEL_8hana1, MODEL_8hana3, 0,
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt02_shape",
    .hit = "flo_bt02_hit",
    .bg = "fla_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
