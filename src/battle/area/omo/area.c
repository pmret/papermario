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

Formation N(Formation_00) = {
    { .actor = &N(red_shy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(red_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_01) = {
    { .actor = &N(blue_shy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(blue_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_02) = {
    { .actor = &N(yellow_shy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(yellow_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_03) = {
    { .actor = &N(yellow_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(yellow_shy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(yellow_shy_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_04) = {
    { .actor = &N(pink_shy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pink_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_05) = {
    { .actor = &N(green_shy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(green_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_06) = {
    { .actor = &N(red_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(medi_guy), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_07) = {
    { .actor = &N(blue_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_08) = {
    { .actor = &N(yellow_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_09) = {
    { .actor = &N(yellow_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(green_shy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(red_shy_guy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(blue_shy_guy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_0A) = {
    { .actor = &N(pink_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_0B) = {
    { .actor = &N(pink_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_0C) = {
    { .actor = &N(green_shy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_0D) = {
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(sky_guy), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_0E) = {
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(yellow_shy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0F) = {
    { .actor = &N(sky_guy), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(yellow_shy_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_10) = {
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_11) = {
    { .actor = &N(sky_guy), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(sky_guy), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(spy_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_12) = {
    { .actor = &N(sky_guy), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(green_shy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_13) = {
    { .actor = &N(sky_guy), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(green_shy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_14) = {
    { .actor = &N(sky_guy), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_15) = {
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_16) = {
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_17) = {
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_18) = {
    { .actor = &N(spy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_19) = {
    { .actor = &N(spy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spy_guy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_1A) = {
    { .actor = &N(spy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spy_guy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(spy_guy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_1B) = {
    { .actor = &N(spy_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(groove_guy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_1C) = {
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_1D) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pyro_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_1E) = {
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_1F) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_20) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_21) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pyro_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_22) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(groove_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_23) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_24) = {
    { .actor = &N(pyro_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pyro_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spy_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_25) = {
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_26) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(groove_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_27) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(medi_guy), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_28) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_29) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(medi_guy), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_2A) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(groove_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pyro_guy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_2B) = {
    { .actor = &N(groove_guy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(blue_shy_guy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(sky_guy), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_2C) = {
    { .actor = &N(anti_guy), .home = { .index = 1 }, .priority = 10 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(omo_04), "あかx２"),
    BATTLE(N(Formation_01), &N(omo_04), "あおx２"),
    BATTLE(N(Formation_02), &N(omo_04), "きいろx２"),
    BATTLE(N(Formation_03), &N(omo_04), "きいろx３"),
    BATTLE(N(Formation_04), &N(omo_04), "ももx２"),
    BATTLE(N(Formation_05), &N(omo_04), "みどりx２"),
    BATTLE(N(Formation_06), &N(omo_04), "あか,かいふくx２"),
    BATTLE(N(Formation_07), &N(omo_04), "あお,ダンシング,かいふく"),
    BATTLE(N(Formation_08), &N(omo_04), "きいろ,コマンド,かいふく"),
    BATTLE(N(Formation_09), &N(omo_04), "きいろ,みどり,あか,あお"),
    BATTLE(N(Formation_0A), &N(omo_04), "もも,ファイア,かいふく"),
    BATTLE(N(Formation_0B), &N(omo_04), "もも,ダンシング,かいふくx２"),
    BATTLE(N(Formation_0C), &N(omo_04), "みどり,バルーン,かいふく"),
    BATTLE(N(Formation_0D), &N(omo_04), "バルーンx２"),
    BATTLE(N(Formation_0E), &N(omo_04), "バルーン,きいろ"),
    BATTLE(N(Formation_0F), &N(omo_04), "バルーンx２,きいろ"),
    BATTLE(N(Formation_10), &N(omo_04), "バルーン,かいふく"),
    BATTLE(N(Formation_11), &N(omo_04), "バルーンx２,コマンド"),
    BATTLE(N(Formation_12), &N(omo_04), "バルーン,みどり,かいふく"),
    BATTLE(N(Formation_13), &N(omo_04), "バルーン,みどり,かいふくx２"),
    BATTLE(N(Formation_14), &N(omo_04), "バルーン,ダンシング,かいふく"),
    BATTLE(N(Formation_15), &N(omo_04), "コマンドx２"),
    BATTLE(N(Formation_16), &N(omo_04), "コマンド,ファイア"),
    BATTLE(N(Formation_17), &N(omo_04), "コマンド,かいふく"),
    BATTLE(N(Formation_18), &N(omo_04), "コマンドx２,かいふく"),
    BATTLE(N(Formation_19), &N(omo_04), "コマンドx３,かいふく"),
    BATTLE(N(Formation_1A), &N(omo_04), "コマンドx４"),
    BATTLE(N(Formation_1B), &N(omo_04), "コマンド,ファイア,ダンシング,かいふく"),
    BATTLE(N(Formation_1C), &N(omo_04), "ファイアx２"),
    BATTLE(N(Formation_1D), &N(omo_04), "ファイアx３"),
    BATTLE(N(Formation_1E), &N(omo_04), "ファイア,かいふく"),
    BATTLE(N(Formation_1F), &N(omo_04), "ファイアx２,かいふく"),
    BATTLE(N(Formation_20), &N(omo_04), "ファイアx２,かいふくx２"),
    BATTLE(N(Formation_21), &N(omo_04), "ファイア,ダンシング,ファイア"),
    BATTLE(N(Formation_22), &N(omo_04), "ファイア,コマンド,ダンシング"),
    BATTLE(N(Formation_23), &N(omo_04), "ファイア,ダンシング,かいふくx2"),
    BATTLE(N(Formation_24), &N(omo_04), "ファイアx2,コマンド"),
    BATTLE(N(Formation_25), &N(omo_04), "ダンシングx２"),
    BATTLE(N(Formation_26), &N(omo_04), "ダンシングx３"),
    BATTLE(N(Formation_27), &N(omo_04), "ダンシング,かいふくx２"),
    BATTLE(N(Formation_28), &N(omo_04), "ダンシングx２,かいふく"),
    BATTLE(N(Formation_29), &N(omo_04), "ダンシングx２,かいふくx２"),
    BATTLE(N(Formation_2A), &N(omo_04), "ダンシングx２,ファイアー"),
    BATTLE(N(Formation_2B), &N(omo_04), "ダンシング,あお,バルーン"),
    BATTLE(N(Formation_2C), &N(omo_04), "ブラック"),
    {},
};

StageList N(Stages) = {
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
