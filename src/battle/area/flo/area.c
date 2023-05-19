#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_flo

extern ActorBlueprint N(lakitu);
extern ActorBlueprint N(ruff_puff);
extern ActorBlueprint N(bzzap);
extern ActorBlueprint N(crazee_dayzee);
extern ActorBlueprint N(spiny);
extern ActorBlueprint N(white_magikoopa);
extern ActorBlueprint N(red_magikoopa);
extern ActorBlueprint N(yellow_magikoopa);
extern ActorBlueprint N(medi_guy);
extern ActorBlueprint N(amazy_dayzee);
extern ActorBlueprint N(green_magikoopa_flying);
extern ActorBlueprint N(yellow_magikoopa_flying);

extern Stage N(flo_01);
extern Stage N(flo_01b);
extern Stage N(flo_01c);
extern Stage N(flo_02);
extern Stage N(flo_02b);
extern Stage N(flo_02c);
extern Stage N(flo_03);
extern Stage N(flo_04);
extern Stage N(flo_05);
extern Stage N(flo_06);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_C, 9),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_C, 8),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_C, 9),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_C, 8),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_D, 7),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(white_magikoopa), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(red_magikoopa), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(yellow_magikoopa), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_0F) = {
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_10) = {
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_11) = {
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_12) = {
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_13) = {
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_C, 9),
};

Formation N(Formation_14) = {
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_C, 8),
};

Formation N(Formation_15) = {
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_C, 8),
};

Formation N(Formation_16) = {
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(amazy_dayzee), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_17) = {
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_C, 9),
};

Formation N(Formation_18) = {
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_C, 8),
};

Formation N(Formation_19) = {
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(green_magikoopa_flying), BTL_POS_AIR_C, 8),
};

Formation N(Formation_1A) = {
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_C, 9),
};

Formation N(Formation_1B) = {
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_C, 8),
};

Formation N(Formation_1C) = {
    ACTOR_BY_IDX(N(amazy_dayzee), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_1D) = {
    ACTOR_BY_IDX(N(amazy_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_C, 8),
};

Formation N(Formation_1E) = {
    ACTOR_BY_IDX(N(amazy_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(amazy_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(amazy_dayzee), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(amazy_dayzee), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_1F) = {
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_C, 9),
};

Formation N(Formation_20) = {
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_D, 7),
};

Formation N(Formation_21) = {
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(lakitu), BTL_POS_AIR_C, 9),
};

Formation N(Formation_22) = {
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_C, 8),
};

Formation N(Formation_23) = {
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(crazee_dayzee), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_24) = {
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(ruff_puff), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(yellow_magikoopa_flying), BTL_POS_AIR_C, 8),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(flo_01), "ジュゲムx2"),
    BATTLE(N(Formation_01), &N(flo_01), "ジュゲムx3"),
    BATTLE(N(Formation_02), &N(flo_01), "ジュゲム,クモクモーン"),
    BATTLE(N(Formation_03), &N(flo_01), "ジュゲム,ハッチーx２"),
    BATTLE(N(Formation_04), &N(flo_01), "ジュゲム,ハッチー,ジュゲム,ハッチー"),
    BATTLE(N(Formation_05), &N(flo_01), "ジュゲム,パンジー"),
    BATTLE(N(Formation_06), &N(flo_01), "ジュゲム,トゲゾー"),
    BATTLE(N(Formation_07), &N(flo_01), "ジュゲムx２,トゲゾーx２"),
    BATTLE(N(Formation_08), &N(flo_01), "ジュゲムx３,トゲゾー"),
    BATTLE(N(Formation_09), &N(flo_01), "ジュゲムx２,ホワイトカメック"),
    BATTLE(N(Formation_0A), &N(flo_01), "ジュゲムx２,レッドカメック"),
    BATTLE(N(Formation_0B), &N(flo_01), "ジュゲムx３,イエローカメック"),
    BATTLE(N(Formation_0C), &N(flo_01), "トゲゾーx2"),
    BATTLE(N(Formation_0D), &N(flo_01), "トゲゾーx3"),
    BATTLE(N(Formation_0E), &N(flo_01), "トゲゾー,パンジーさん,かいふくヘイホー"),
    BATTLE(N(Formation_0F), &N(flo_01), "パンジーさん"),
    BATTLE(N(Formation_10), &N(flo_01), "パンジーさんx2"),
    BATTLE(N(Formation_11), &N(flo_01), "パンジーさんx3"),
    BATTLE(N(Formation_12), &N(flo_01), "パンジーさんx4"),
    BATTLE(N(Formation_13), &N(flo_01), "パンジーさん,ハッチー"),
    BATTLE(N(Formation_14), &N(flo_01), "パンジーさん,ハッチーx2"),
    BATTLE(N(Formation_15), &N(flo_01), "パンジーさんx2,ハッチー"),
    BATTLE(N(Formation_16), &N(flo_01), "パンジーさんx2,きらめくパンジーさん"),
    BATTLE(N(Formation_17), &N(flo_01), "ハッチーx2"),
    BATTLE(N(Formation_18), &N(flo_01), "ハッチーx3"),
    BATTLE(N(Formation_19), &N(flo_01), "ハッチーx2,グリーンカメック（そら）"),
    BATTLE(N(Formation_1A), &N(flo_01), "ハッチー,クモクモーン"),
    BATTLE(N(Formation_1B), &N(flo_01), "ハッチー,クモクモーン,ハッチー"),
    BATTLE(N(Formation_1C), &N(flo_01), "きらめくパンジーさん"),
    BATTLE(N(Formation_1D), &N(flo_01), "きらめくパンジーさん,ハッチーx2"),
    BATTLE(N(Formation_1E), &N(flo_01), "きらめくパンジーさんx４"),
    BATTLE(N(Formation_1F), &N(flo_01), "クモクモーンx2"),
    BATTLE(N(Formation_20), &N(flo_01), "クモクモーンx4"),
    BATTLE(N(Formation_21), &N(flo_01), "クモクモーン,ジュゲム"),
    BATTLE(N(Formation_22), &N(flo_01), "クモクモーンx２,ハッチー"),
    BATTLE(N(Formation_23), &N(flo_01), "クモクモーンx２,パンジー"),
    BATTLE(N(Formation_24), &N(flo_01), "クモクモーンx２,イエローカメック（そら）"),
    {},
};

StageList N(Stages) = {
    { "flo_01", &N(flo_01) },
    { "flo_01b", &N(flo_01b) },
    { "flo_01c", &N(flo_01c) },
    { "flo_02", &N(flo_02) },
    { "flo_02b", &N(flo_02b) },
    { "flo_02c", &N(flo_02c) },
    { "flo_03", &N(flo_03) },
    { "flo_04", &N(flo_04) },
    { "flo_05", &N(flo_05) },
    { "flo_06", &N(flo_06) },
    {},
};
