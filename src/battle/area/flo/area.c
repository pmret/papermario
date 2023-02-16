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
