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
    { .actor = &N(lakitu), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(lakitu), .home = { .index = 6 }, .priority = 9, },
};

Formation N(Formation_01) = {
    { .actor = &N(lakitu), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(lakitu), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(lakitu), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_02) = {
    { .actor = &N(lakitu), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(ruff_puff), .home = { .index = 6 }, .priority = 9, },
};

Formation N(Formation_03) = {
    { .actor = &N(lakitu), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_04) = {
    { .actor = &N(lakitu), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(lakitu), .home = { .index = 6 }, .priority = 8, },
    { .actor = &N(bzzap), .home = { .index = 7 }, .priority = 7, },
};

Formation N(Formation_05) = {
    { .actor = &N(lakitu), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(crazee_dayzee), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_06) = {
    { .actor = &N(lakitu), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_07) = {
    { .actor = &N(lakitu), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(lakitu), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(spiny), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_08) = {
    { .actor = &N(lakitu), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(lakitu), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(lakitu), .home = { .index = 6 }, .priority = 8, },
    { .actor = &N(spiny), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_09) = {
    { .actor = &N(lakitu), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(lakitu), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(white_magikoopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_0A) = {
    { .actor = &N(lakitu), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(lakitu), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(red_magikoopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_0B) = {
    { .actor = &N(lakitu), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(lakitu), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(lakitu), .home = { .index = 6 }, .priority = 8, },
    { .actor = &N(yellow_magikoopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_0C) = {
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_0D) = {
    { .actor = &N(spiny), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_0E) = {
    { .actor = &N(spiny), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(crazee_dayzee), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_0F) = {
    { .actor = &N(crazee_dayzee), .home = { .index = 1 }, .priority = 10, },
};

Formation N(Formation_10) = {
    { .actor = &N(crazee_dayzee), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(crazee_dayzee), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_11) = {
    { .actor = &N(crazee_dayzee), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(crazee_dayzee), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(crazee_dayzee), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_12) = {
    { .actor = &N(crazee_dayzee), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(crazee_dayzee), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(crazee_dayzee), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(crazee_dayzee), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_13) = {
    { .actor = &N(crazee_dayzee), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 9, },
};

Formation N(Formation_14) = {
    { .actor = &N(crazee_dayzee), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_15) = {
    { .actor = &N(crazee_dayzee), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(crazee_dayzee), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_16) = {
    { .actor = &N(crazee_dayzee), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(crazee_dayzee), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(amazy_dayzee), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_17) = {
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 9, },
};

Formation N(Formation_18) = {
    { .actor = &N(bzzap), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_19) = {
    { .actor = &N(bzzap), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(green_magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_1A) = {
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(ruff_puff), .home = { .index = 6 }, .priority = 9, },
};

Formation N(Formation_1B) = {
    { .actor = &N(bzzap), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(ruff_puff), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_1C) = {
    { .actor = &N(amazy_dayzee), .home = { .index = 1 }, .priority = 10, },
};

Formation N(Formation_1D) = {
    { .actor = &N(amazy_dayzee), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_1E) = {
    { .actor = &N(amazy_dayzee), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(amazy_dayzee), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(amazy_dayzee), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(amazy_dayzee), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_1F) = {
    { .actor = &N(ruff_puff), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(ruff_puff), .home = { .index = 6 }, .priority = 9, },
};

Formation N(Formation_20) = {
    { .actor = &N(ruff_puff), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(ruff_puff), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(ruff_puff), .home = { .index = 6 }, .priority = 8, },
    { .actor = &N(ruff_puff), .home = { .index = 7 }, .priority = 7, },
};

Formation N(Formation_21) = {
    { .actor = &N(ruff_puff), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(lakitu), .home = { .index = 6 }, .priority = 9, },
};

Formation N(Formation_22) = {
    { .actor = &N(ruff_puff), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(ruff_puff), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_23) = {
    { .actor = &N(ruff_puff), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(ruff_puff), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(crazee_dayzee), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_24) = {
    { .actor = &N(ruff_puff), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(ruff_puff), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(yellow_magikoopa_flying), .home = { .index = 6 }, .priority = 8, },
};

BattleList N(Formations) = {
    BATTLE("ジュゲムx2", N(Formation_00), &N(flo_01)),
    BATTLE("ジュゲムx3", N(Formation_01), &N(flo_01)),
    BATTLE("ジュゲム,クモクモーン", N(Formation_02), &N(flo_01)),
    BATTLE("ジュゲム,ハッチーx２", N(Formation_03), &N(flo_01)),
    BATTLE("ジュゲム,ハッチー,ジュゲム,ハッチー", N(Formation_04), &N(flo_01)),
    BATTLE("ジュゲム,パンジー", N(Formation_05), &N(flo_01)),
    BATTLE("ジュゲム,トゲゾー", N(Formation_06), &N(flo_01)),
    BATTLE("ジュゲムx２,トゲゾーx２", N(Formation_07), &N(flo_01)),
    BATTLE("ジュゲムx３,トゲゾー", N(Formation_08), &N(flo_01)),
    BATTLE("ジュゲムx２,ホワイトカメック", N(Formation_09), &N(flo_01)),
    BATTLE("ジュゲムx２,レッドカメック", N(Formation_0A), &N(flo_01)),
    BATTLE("ジュゲムx３,イエローカメック", N(Formation_0B), &N(flo_01)),
    BATTLE("トゲゾーx2", N(Formation_0C), &N(flo_01)),
    BATTLE("トゲゾーx3", N(Formation_0D), &N(flo_01)),
    BATTLE("トゲゾー,パンジーさん,かいふくヘイホー", N(Formation_0E), &N(flo_01)),
    BATTLE("パンジーさん", N(Formation_0F), &N(flo_01)),
    BATTLE("パンジーさんx2", N(Formation_10), &N(flo_01)),
    BATTLE("パンジーさんx3", N(Formation_11), &N(flo_01)),
    BATTLE("パンジーさんx4", N(Formation_12), &N(flo_01)),
    BATTLE("パンジーさん,ハッチー", N(Formation_13), &N(flo_01)),
    BATTLE("パンジーさん,ハッチーx2", N(Formation_14), &N(flo_01)),
    BATTLE("パンジーさんx2,ハッチー", N(Formation_15), &N(flo_01)),
    BATTLE("パンジーさんx2,きらめくパンジーさん", N(Formation_16), &N(flo_01)),
    BATTLE("ハッチーx2", N(Formation_17), &N(flo_01)),
    BATTLE("ハッチーx3", N(Formation_18), &N(flo_01)),
    BATTLE("ハッチーx2,グリーンカメック（そら）", N(Formation_19), &N(flo_01)),
    BATTLE("ハッチー,クモクモーン", N(Formation_1A), &N(flo_01)),
    BATTLE("ハッチー,クモクモーン,ハッチー", N(Formation_1B), &N(flo_01)),
    BATTLE("きらめくパンジーさん", N(Formation_1C), &N(flo_01)),
    BATTLE("きらめくパンジーさん,ハッチーx2", N(Formation_1D), &N(flo_01)),
    BATTLE("きらめくパンジーさんx４", N(Formation_1E), &N(flo_01)),
    BATTLE("クモクモーンx2", N(Formation_1F), &N(flo_01)),
    BATTLE("クモクモーンx4", N(Formation_20), &N(flo_01)),
    BATTLE("クモクモーン,ジュゲム", N(Formation_21), &N(flo_01)),
    BATTLE("クモクモーンx２,ハッチー", N(Formation_22), &N(flo_01)),
    BATTLE("クモクモーンx２,パンジー", N(Formation_23), &N(flo_01)),
    BATTLE("クモクモーンx２,イエローカメック（そら）", N(Formation_24), &N(flo_01)),
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
