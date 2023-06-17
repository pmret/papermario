#include "area.h"

extern ActorBlueprint A(lakitu);
extern ActorBlueprint A(ruff_puff);
extern ActorBlueprint A(bzzap);
extern ActorBlueprint A(crazee_dayzee);
extern ActorBlueprint A(spiny);
extern ActorBlueprint A(white_magikoopa);
extern ActorBlueprint A(red_magikoopa);
extern ActorBlueprint A(yellow_magikoopa);
extern ActorBlueprint A(medi_guy);
extern ActorBlueprint A(amazy_dayzee);
extern ActorBlueprint A(green_magikoopa_flying);
extern ActorBlueprint A(yellow_magikoopa_flying);

extern Stage A(flo_01);
extern Stage A(flo_01b);
extern Stage A(flo_01c);
extern Stage A(flo_02);
extern Stage A(flo_02b);
extern Stage A(flo_02c);
extern Stage A(flo_03);
extern Stage A(flo_04);
extern Stage A(flo_05);
extern Stage A(flo_06);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_C, 9),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_C, 8),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_C, 9),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_C, 8),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_D, 7),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(white_magikoopa), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(red_magikoopa), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0B) = {
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(yellow_magikoopa), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_0C) = {
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0D) = {
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0E) = {
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_0F) = {
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_10) = {
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_11) = {
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_12) = {
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_13) = {
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_C, 9),
};

Formation A(Formation_14) = {
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_C, 8),
};

Formation A(Formation_15) = {
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_C, 8),
};

Formation A(Formation_16) = {
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(amazy_dayzee), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_17) = {
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_C, 9),
};

Formation A(Formation_18) = {
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_C, 8),
};

Formation A(Formation_19) = {
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(green_magikoopa_flying), BTL_POS_AIR_C, 8),
};

Formation A(Formation_1A) = {
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_C, 9),
};

Formation A(Formation_1B) = {
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_C, 8),
};

Formation A(Formation_1C) = {
    ACTOR_BY_IDX(A(amazy_dayzee), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_1D) = {
    ACTOR_BY_IDX(A(amazy_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_C, 8),
};

Formation A(Formation_1E) = {
    ACTOR_BY_IDX(A(amazy_dayzee), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(amazy_dayzee), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(amazy_dayzee), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(amazy_dayzee), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_1F) = {
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_C, 9),
};

Formation A(Formation_20) = {
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_D, 7),
};

Formation A(Formation_21) = {
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(lakitu), BTL_POS_AIR_C, 9),
};

Formation A(Formation_22) = {
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(bzzap), BTL_POS_AIR_C, 8),
};

Formation A(Formation_23) = {
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(crazee_dayzee), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_24) = {
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(ruff_puff), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(yellow_magikoopa_flying), BTL_POS_AIR_C, 8),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(flo_01), "ジュゲムx2"),
    BATTLE(A(Formation_01), A(flo_01), "ジュゲムx3"),
    BATTLE(A(Formation_02), A(flo_01), "ジュゲム,クモクモーン"),
    BATTLE(A(Formation_03), A(flo_01), "ジュゲム,ハッチーx２"),
    BATTLE(A(Formation_04), A(flo_01), "ジュゲム,ハッチー,ジュゲム,ハッチー"),
    BATTLE(A(Formation_05), A(flo_01), "ジュゲム,パンジー"),
    BATTLE(A(Formation_06), A(flo_01), "ジュゲム,トゲゾー"),
    BATTLE(A(Formation_07), A(flo_01), "ジュゲムx２,トゲゾーx２"),
    BATTLE(A(Formation_08), A(flo_01), "ジュゲムx３,トゲゾー"),
    BATTLE(A(Formation_09), A(flo_01), "ジュゲムx２,ホワイトカメック"),
    BATTLE(A(Formation_0A), A(flo_01), "ジュゲムx２,レッドカメック"),
    BATTLE(A(Formation_0B), A(flo_01), "ジュゲムx３,イエローカメック"),
    BATTLE(A(Formation_0C), A(flo_01), "トゲゾーx2"),
    BATTLE(A(Formation_0D), A(flo_01), "トゲゾーx3"),
    BATTLE(A(Formation_0E), A(flo_01), "トゲゾー,パンジーさん,かいふくヘイホー"),
    BATTLE(A(Formation_0F), A(flo_01), "パンジーさん"),
    BATTLE(A(Formation_10), A(flo_01), "パンジーさんx2"),
    BATTLE(A(Formation_11), A(flo_01), "パンジーさんx3"),
    BATTLE(A(Formation_12), A(flo_01), "パンジーさんx4"),
    BATTLE(A(Formation_13), A(flo_01), "パンジーさん,ハッチー"),
    BATTLE(A(Formation_14), A(flo_01), "パンジーさん,ハッチーx2"),
    BATTLE(A(Formation_15), A(flo_01), "パンジーさんx2,ハッチー"),
    BATTLE(A(Formation_16), A(flo_01), "パンジーさんx2,きらめくパンジーさん"),
    BATTLE(A(Formation_17), A(flo_01), "ハッチーx2"),
    BATTLE(A(Formation_18), A(flo_01), "ハッチーx3"),
    BATTLE(A(Formation_19), A(flo_01), "ハッチーx2,グリーンカメック（そら）"),
    BATTLE(A(Formation_1A), A(flo_01), "ハッチー,クモクモーン"),
    BATTLE(A(Formation_1B), A(flo_01), "ハッチー,クモクモーン,ハッチー"),
    BATTLE(A(Formation_1C), A(flo_01), "きらめくパンジーさん"),
    BATTLE(A(Formation_1D), A(flo_01), "きらめくパンジーさん,ハッチーx2"),
    BATTLE(A(Formation_1E), A(flo_01), "きらめくパンジーさんx４"),
    BATTLE(A(Formation_1F), A(flo_01), "クモクモーンx2"),
    BATTLE(A(Formation_20), A(flo_01), "クモクモーンx4"),
    BATTLE(A(Formation_21), A(flo_01), "クモクモーン,ジュゲム"),
    BATTLE(A(Formation_22), A(flo_01), "クモクモーンx２,ハッチー"),
    BATTLE(A(Formation_23), A(flo_01), "クモクモーンx２,パンジー"),
    BATTLE(A(Formation_24), A(flo_01), "クモクモーンx２,イエローカメック（そら）"),
    {},
};

StageList A(Stages) = {
    STAGE("flo_01", A(flo_01)),
    STAGE("flo_01b", A(flo_01b)),
    STAGE("flo_01c", A(flo_01c)),
    STAGE("flo_02", A(flo_02)),
    STAGE("flo_02b", A(flo_02b)),
    STAGE("flo_02c", A(flo_02c)),
    STAGE("flo_03", A(flo_03)),
    STAGE("flo_04", A(flo_04)),
    STAGE("flo_05", A(flo_05)),
    STAGE("flo_06", A(flo_06)),
    {},
};
