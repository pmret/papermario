#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kpa2_kpa_03

#include "world/common/util/SetLightningBoltPurple.inc.c"

s32 N(lightningsSettings1)[] = {
    0xFFFFFFEA, 0x000000BE, 0xFFFFFFA5, 0xFFFFFFA8, 0x00000015, 0xFFFFFFA5, 0x0000003C,
    0xFFFFFFFF, 0x000000BE, 0xFFFFFFA5, 0x00000058, 0x00000018, 0xFFFFFFA5, 0x0000000A,
    0xFFFFFFBD, 0x000000BE, 0xFFFFFFA5, 0xFFFFFF86, 0x0000000A, 0xFFFFFFA5, 0x0000005A,
    0x00000039, 0x000000BE, 0xFFFFFFA5, 0xFFFFFFFC, 0x00000011, 0xFFFFFFA5, 0x0000003C,
};

EvtScript N(createLightnings1) = {
    EVT_LABEL(0)
    EVT_USE_BUF(N(lightningsSettings1))
    EVT_LOOP(4)
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

s32 N(lightningsSettings2)[] = {
    0xFFFFFF87, 0x00000021, 0xFFFFFF98, 0xFFFFFFE8, 0x00000029, 0xFFFFFF98, 0x00000005,
    0x00000024, 0x00000029, 0xFFFFFF98, 0x00000080, 0x00000022, 0xFFFFFF98, 0x0000001E,
    0x00000092, 0x00000001, 0x00000071, 0x00000026, 0xFFFFFFF1, 0x00000079, 0x00000005,
    0xFFFFFFBE, 0xFFFFFFF6, 0x00000073, 0xFFFFFF65, 0x00000001, 0x00000061, 0x0000005A,
};

EvtScript N(createLightnings2) = {
    EVT_LABEL(0)
    EVT_USE_BUF(N(lightningsSettings2))
    EVT_LOOP(4)
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
    EVT_EXEC(N(createLightnings1))
    EVT_EXEC(N(createLightnings2))
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
