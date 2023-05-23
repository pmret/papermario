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
    ACTOR_BY_IDX(N(red_shy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(red_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(blue_shy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(blue_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(yellow_shy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(yellow_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(yellow_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(yellow_shy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(yellow_shy_guy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(pink_shy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(pink_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(green_shy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(green_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(red_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(blue_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(yellow_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(yellow_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(green_shy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(red_shy_guy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(blue_shy_guy), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(pink_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(pink_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_D, 7),
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(green_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_C, 9),
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(yellow_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0F) = {
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(yellow_shy_guy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_10) = {
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 9),
};

Formation N(Formation_11) = {
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_12) = {
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(green_shy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_13) = {
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(green_shy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_D, 7),
};

Formation N(Formation_14) = {
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_15) = {
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_16) = {
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_17) = {
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 9),
};

Formation N(Formation_18) = {
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_19) = {
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_D, 7),
};

Formation N(Formation_1A) = {
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_1B) = {
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_D, 7),
};

Formation N(Formation_1C) = {
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_1D) = {
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_1E) = {
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 9),
};

Formation N(Formation_1F) = {
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_20) = {
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_D, 7),
};

Formation N(Formation_21) = {
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_22) = {
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_23) = {
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_D, 7),
};

Formation N(Formation_24) = {
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spy_guy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_25) = {
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_26) = {
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_27) = {
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_28) = {
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_29) = {
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_D, 7),
};

Formation N(Formation_2A) = {
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(pyro_guy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_2B) = {
    ACTOR_BY_IDX(N(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(blue_shy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(sky_guy), BTL_POS_AIR_C, 8),
};

Formation N(Formation_2C) = {
    ACTOR_BY_IDX(N(anti_guy), BTL_POS_GROUND_B, 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(omo_04), "あかx２"),
    BATTLE(N(Formation_01), N(omo_04), "あおx２"),
    BATTLE(N(Formation_02), N(omo_04), "きいろx２"),
    BATTLE(N(Formation_03), N(omo_04), "きいろx３"),
    BATTLE(N(Formation_04), N(omo_04), "ももx２"),
    BATTLE(N(Formation_05), N(omo_04), "みどりx２"),
    BATTLE(N(Formation_06), N(omo_04), "あか,かいふくx２"),
    BATTLE(N(Formation_07), N(omo_04), "あお,ダンシング,かいふく"),
    BATTLE(N(Formation_08), N(omo_04), "きいろ,コマンド,かいふく"),
    BATTLE(N(Formation_09), N(omo_04), "きいろ,みどり,あか,あお"),
    BATTLE(N(Formation_0A), N(omo_04), "もも,ファイア,かいふく"),
    BATTLE(N(Formation_0B), N(omo_04), "もも,ダンシング,かいふくx２"),
    BATTLE(N(Formation_0C), N(omo_04), "みどり,バルーン,かいふく"),
    BATTLE(N(Formation_0D), N(omo_04), "バルーンx２"),
    BATTLE(N(Formation_0E), N(omo_04), "バルーン,きいろ"),
    BATTLE(N(Formation_0F), N(omo_04), "バルーンx２,きいろ"),
    BATTLE(N(Formation_10), N(omo_04), "バルーン,かいふく"),
    BATTLE(N(Formation_11), N(omo_04), "バルーンx２,コマンド"),
    BATTLE(N(Formation_12), N(omo_04), "バルーン,みどり,かいふく"),
    BATTLE(N(Formation_13), N(omo_04), "バルーン,みどり,かいふくx２"),
    BATTLE(N(Formation_14), N(omo_04), "バルーン,ダンシング,かいふく"),
    BATTLE(N(Formation_15), N(omo_04), "コマンドx２"),
    BATTLE(N(Formation_16), N(omo_04), "コマンド,ファイア"),
    BATTLE(N(Formation_17), N(omo_04), "コマンド,かいふく"),
    BATTLE(N(Formation_18), N(omo_04), "コマンドx２,かいふく"),
    BATTLE(N(Formation_19), N(omo_04), "コマンドx３,かいふく"),
    BATTLE(N(Formation_1A), N(omo_04), "コマンドx４"),
    BATTLE(N(Formation_1B), N(omo_04), "コマンド,ファイア,ダンシング,かいふく"),
    BATTLE(N(Formation_1C), N(omo_04), "ファイアx２"),
    BATTLE(N(Formation_1D), N(omo_04), "ファイアx３"),
    BATTLE(N(Formation_1E), N(omo_04), "ファイア,かいふく"),
    BATTLE(N(Formation_1F), N(omo_04), "ファイアx２,かいふく"),
    BATTLE(N(Formation_20), N(omo_04), "ファイアx２,かいふくx２"),
    BATTLE(N(Formation_21), N(omo_04), "ファイア,ダンシング,ファイア"),
    BATTLE(N(Formation_22), N(omo_04), "ファイア,コマンド,ダンシング"),
    BATTLE(N(Formation_23), N(omo_04), "ファイア,ダンシング,かいふくx2"),
    BATTLE(N(Formation_24), N(omo_04), "ファイアx2,コマンド"),
    BATTLE(N(Formation_25), N(omo_04), "ダンシングx２"),
    BATTLE(N(Formation_26), N(omo_04), "ダンシングx３"),
    BATTLE(N(Formation_27), N(omo_04), "ダンシング,かいふくx２"),
    BATTLE(N(Formation_28), N(omo_04), "ダンシングx２,かいふく"),
    BATTLE(N(Formation_29), N(omo_04), "ダンシングx２,かいふくx２"),
    BATTLE(N(Formation_2A), N(omo_04), "ダンシングx２,ファイアー"),
    BATTLE(N(Formation_2B), N(omo_04), "ダンシング,あお,バルーン"),
    BATTLE(N(Formation_2C), N(omo_04), "ブラック"),
    {},
};

StageList N(Stages) = {
    STAGE("omo_01", N(omo_01)),
    STAGE("omo_02", N(omo_02)),
    STAGE("omo_03", N(omo_03)),
    STAGE("omo_03b", N(omo_03b)),
    STAGE("omo_04", N(omo_04)),
    STAGE("omo_05", N(omo_05)),
    STAGE("omo_05b", N(omo_05b)),
    STAGE("omo_06", N(omo_06)),
    STAGE("omo_07", N(omo_07)),
    {},
};
