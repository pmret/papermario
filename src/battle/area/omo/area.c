#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_omo

extern ActorBlueprint N(red_shy_guy);
extern ActorBlueprint N(blue_shy_guy);
extern ActorBlueprint N(yellow_shy_guy);
extern ActorBlueprint N(pink_shy_guy);
extern ActorBlueprint N(green_shy_guy);
extern ActorBlueprint N(anti_guy);
extern ActorBlueprint N(medi_guy);
extern ActorBlueprint N(groove_guy);
extern ActorBlueprint N(spy_guy);
extern ActorBlueprint N(sky_guy);
extern ActorBlueprint N(pyro_guy);

extern Stage N(omo_01);
extern Stage N(omo_02);
extern Stage N(omo_03);
extern Stage N(omo_03b);
extern Stage N(omo_04);
extern Stage N(omo_05);
extern Stage N(omo_05b);
extern Stage N(omo_06);
extern Stage N(omo_07);

Formation N(formation_00) = {
    { .actor = &N(red_shy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(red_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_01) = {
    { .actor = &N(blue_shy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(blue_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_02) = {
    { .actor = &N(yellow_shy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(yellow_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_03) = {
    { .actor = &N(yellow_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(yellow_shy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(yellow_shy_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_04) = {
    { .actor = &N(pink_shy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pink_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_05) = {
    { .actor = &N(green_shy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(green_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_06) = {
    { .actor = &N(red_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(medi_guy), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_07) = {
    { .actor = &N(blue_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_08) = {
    { .actor = &N(yellow_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_09) = {
    { .actor = &N(yellow_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(green_shy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(red_shy_guy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(blue_shy_guy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_0A) = {
    { .actor = &N(pink_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_0B) = {
    { .actor = &N(pink_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(formation_0C) = {
    { .actor = &N(green_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_0D) = {
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(sky_guy), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_0E) = {
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(yellow_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0F) = {
    { .actor = &N(sky_guy), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(yellow_shy_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_10) = {
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_11) = {
    { .actor = &N(sky_guy), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(spy_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_12) = {
    { .actor = &N(sky_guy), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(green_shy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_13) = {
    { .actor = &N(sky_guy), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(green_shy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(formation_14) = {
    { .actor = &N(sky_guy), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_15) = {
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_16) = {
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_17) = {
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_18) = {
    { .actor = &N(spy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_19) = {
    { .actor = &N(spy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spy_guy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(formation_1A) = {
    { .actor = &N(spy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spy_guy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(spy_guy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_1B) = {
    { .actor = &N(spy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(groove_guy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(formation_1C) = {
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_1D) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pyro_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_1E) = {
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_1F) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_20) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(formation_21) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pyro_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_22) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(groove_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_23) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(formation_24) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spy_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_25) = {
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_26) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(groove_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_27) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(medi_guy), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_28) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_29) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(formation_2A) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pyro_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_2B) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(blue_shy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(sky_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_2C) = {
    { .actor = &N(anti_guy), .home = { .index = 1 }, .priority = 10 },
};

BattleList N(formationTable) = {
    BATTLE("あかx２", N(formation_00), &N(omo_04)),
    BATTLE("あおx２", N(formation_01), &N(omo_04)),
    BATTLE("きいろx２", N(formation_02), &N(omo_04)),
    BATTLE("きいろx３", N(formation_03), &N(omo_04)),
    BATTLE("ももx２", N(formation_04), &N(omo_04)),
    BATTLE("みどりx２", N(formation_05), &N(omo_04)),
    BATTLE("あか,かいふくx２", N(formation_06), &N(omo_04)),
    BATTLE("あお,ダンシング,かいふく", N(formation_07), &N(omo_04)),
    BATTLE("きいろ,コマンド,かいふく", N(formation_08), &N(omo_04)),
    BATTLE("きいろ,みどり,あか,あお", N(formation_09), &N(omo_04)),
    BATTLE("もも,ファイア,かいふく", N(formation_0A), &N(omo_04)),
    BATTLE("もも,ダンシング,かいふくx２", N(formation_0B), &N(omo_04)),
    BATTLE("みどり,バルーン,かいふく", N(formation_0C), &N(omo_04)),
    BATTLE("バルーンx２", N(formation_0D), &N(omo_04)),
    BATTLE("バルーン,きいろ", N(formation_0E), &N(omo_04)),
    BATTLE("バルーンx２,きいろ", N(formation_0F), &N(omo_04)),
    BATTLE("バルーン,かいふく", N(formation_10), &N(omo_04)),
    BATTLE("バルーンx２,コマンド", N(formation_11), &N(omo_04)),
    BATTLE("バルーン,みどり,かいふく", N(formation_12), &N(omo_04)),
    BATTLE("バルーン,みどり,かいふくx２", N(formation_13), &N(omo_04)),
    BATTLE("バルーン,ダンシング,かいふく", N(formation_14), &N(omo_04)),
    BATTLE("コマンドx２", N(formation_15), &N(omo_04)),
    BATTLE("コマンド,ファイア", N(formation_16), &N(omo_04)),
    BATTLE("コマンド,かいふく", N(formation_17), &N(omo_04)),
    BATTLE("コマンドx２,かいふく", N(formation_18), &N(omo_04)),
    BATTLE("コマンドx３,かいふく", N(formation_19), &N(omo_04)),
    BATTLE("コマンドx４", N(formation_1A), &N(omo_04)),
    BATTLE("コマンド,ファイア,ダンシング,かいふく", N(formation_1B), &N(omo_04)),
    BATTLE("ファイアx２", N(formation_1C), &N(omo_04)),
    BATTLE("ファイアx３", N(formation_1D), &N(omo_04)),
    BATTLE("ファイア,かいふく", N(formation_1E), &N(omo_04)),
    BATTLE("ファイアx２,かいふく", N(formation_1F), &N(omo_04)),
    BATTLE("ファイアx２,かいふくx２", N(formation_20), &N(omo_04)),
    BATTLE("ファイア,ダンシング,ファイア", N(formation_21), &N(omo_04)),
    BATTLE("ファイア,コマンド,ダンシング", N(formation_22), &N(omo_04)),
    BATTLE("ファイア,ダンシング,かいふくx2", N(formation_23), &N(omo_04)),
    BATTLE("ファイアx2,コマンド", N(formation_24), &N(omo_04)),
    BATTLE("ダンシングx２", N(formation_25), &N(omo_04)),
    BATTLE("ダンシングx３", N(formation_26), &N(omo_04)),
    BATTLE("ダンシング,かいふくx２", N(formation_27), &N(omo_04)),
    BATTLE("ダンシングx２,かいふく", N(formation_28), &N(omo_04)),
    BATTLE("ダンシングx２,かいふくx２", N(formation_29), &N(omo_04)),
    BATTLE("ダンシングx２,ファイアー", N(formation_2A), &N(omo_04)),
    BATTLE("ダンシング,あお,バルーン", N(formation_2B), &N(omo_04)),
    BATTLE("ブラック", N(formation_2C), &N(omo_04)),
    {},
};

StageList N(stageTable) = {
    { "omo_01",  &N(omo_01) },
    { "omo_02",  &N(omo_02) },
    { "omo_03",  &N(omo_03) },
    { "omo_03b", &N(omo_03b) },
    { "omo_04",  &N(omo_04) },
    { "omo_05",  &N(omo_05) },
    { "omo_05b", &N(omo_05b) },
    { "omo_06",  &N(omo_06) },
    { "omo_07",  &N(omo_07) },
    {},
};
