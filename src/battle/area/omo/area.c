#include "area.h"

extern ActorBlueprint A(red_shy_guy);
extern ActorBlueprint A(blue_shy_guy);
extern ActorBlueprint A(yellow_shy_guy);
extern ActorBlueprint A(pink_shy_guy);
extern ActorBlueprint A(green_shy_guy);
extern ActorBlueprint A(anti_guy);
extern ActorBlueprint A(medi_guy);
extern ActorBlueprint A(groove_guy);
extern ActorBlueprint A(spy_guy);
extern ActorBlueprint A(sky_guy);
extern ActorBlueprint A(pyro_guy);

extern Stage A(omo_01);
extern Stage A(omo_02);
extern Stage A(omo_03);
extern Stage A(omo_03b);
extern Stage A(omo_04);
extern Stage A(omo_05);
extern Stage A(omo_05b);
extern Stage A(omo_06);
extern Stage A(omo_07);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(red_shy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(red_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(blue_shy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(blue_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(yellow_shy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(yellow_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(yellow_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(yellow_shy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(yellow_shy_guy), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(pink_shy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(pink_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(green_shy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(green_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(red_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(blue_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(yellow_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(yellow_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(green_shy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(red_shy_guy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(blue_shy_guy), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(pink_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_0B) = {
    ACTOR_BY_IDX(A(pink_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_D, 7),
};

Formation A(Formation_0C) = {
    ACTOR_BY_IDX(A(green_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_0D) = {
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_C, 9),
};

Formation A(Formation_0E) = {
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(yellow_shy_guy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0F) = {
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(yellow_shy_guy), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_10) = {
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 9),
};

Formation A(Formation_11) = {
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_12) = {
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(green_shy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_13) = {
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(green_shy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_D, 7),
};

Formation A(Formation_14) = {
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_15) = {
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_16) = {
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_17) = {
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 9),
};

Formation A(Formation_18) = {
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_19) = {
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_D, 7),
};

Formation A(Formation_1A) = {
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_1B) = {
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_D, 7),
};

Formation A(Formation_1C) = {
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_1D) = {
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_1E) = {
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 9),
};

Formation A(Formation_1F) = {
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_20) = {
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_D, 7),
};

Formation A(Formation_21) = {
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_22) = {
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_23) = {
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_D, 7),
};

Formation A(Formation_24) = {
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spy_guy), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_25) = {
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_26) = {
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_27) = {
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_28) = {
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_29) = {
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(medi_guy), BTL_POS_AIR_D, 7),
};

Formation A(Formation_2A) = {
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(pyro_guy), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_2B) = {
    ACTOR_BY_IDX(A(groove_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(blue_shy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(sky_guy), BTL_POS_AIR_C, 8),
};

Formation A(Formation_2C) = {
    ACTOR_BY_IDX(A(anti_guy), BTL_POS_GROUND_B, 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(omo_04), "あかx２"),
    BATTLE(A(Formation_01), A(omo_04), "あおx２"),
    BATTLE(A(Formation_02), A(omo_04), "きいろx２"),
    BATTLE(A(Formation_03), A(omo_04), "きいろx３"),
    BATTLE(A(Formation_04), A(omo_04), "ももx２"),
    BATTLE(A(Formation_05), A(omo_04), "みどりx２"),
    BATTLE(A(Formation_06), A(omo_04), "あか,かいふくx２"),
    BATTLE(A(Formation_07), A(omo_04), "あお,ダンシング,かいふく"),
    BATTLE(A(Formation_08), A(omo_04), "きいろ,コマンド,かいふく"),
    BATTLE(A(Formation_09), A(omo_04), "きいろ,みどり,あか,あお"),
    BATTLE(A(Formation_0A), A(omo_04), "もも,ファイア,かいふく"),
    BATTLE(A(Formation_0B), A(omo_04), "もも,ダンシング,かいふくx２"),
    BATTLE(A(Formation_0C), A(omo_04), "みどり,バルーン,かいふく"),
    BATTLE(A(Formation_0D), A(omo_04), "バルーンx２"),
    BATTLE(A(Formation_0E), A(omo_04), "バルーン,きいろ"),
    BATTLE(A(Formation_0F), A(omo_04), "バルーンx２,きいろ"),
    BATTLE(A(Formation_10), A(omo_04), "バルーン,かいふく"),
    BATTLE(A(Formation_11), A(omo_04), "バルーンx２,コマンド"),
    BATTLE(A(Formation_12), A(omo_04), "バルーン,みどり,かいふく"),
    BATTLE(A(Formation_13), A(omo_04), "バルーン,みどり,かいふくx２"),
    BATTLE(A(Formation_14), A(omo_04), "バルーン,ダンシング,かいふく"),
    BATTLE(A(Formation_15), A(omo_04), "コマンドx２"),
    BATTLE(A(Formation_16), A(omo_04), "コマンド,ファイア"),
    BATTLE(A(Formation_17), A(omo_04), "コマンド,かいふく"),
    BATTLE(A(Formation_18), A(omo_04), "コマンドx２,かいふく"),
    BATTLE(A(Formation_19), A(omo_04), "コマンドx３,かいふく"),
    BATTLE(A(Formation_1A), A(omo_04), "コマンドx４"),
    BATTLE(A(Formation_1B), A(omo_04), "コマンド,ファイア,ダンシング,かいふく"),
    BATTLE(A(Formation_1C), A(omo_04), "ファイアx２"),
    BATTLE(A(Formation_1D), A(omo_04), "ファイアx３"),
    BATTLE(A(Formation_1E), A(omo_04), "ファイア,かいふく"),
    BATTLE(A(Formation_1F), A(omo_04), "ファイアx２,かいふく"),
    BATTLE(A(Formation_20), A(omo_04), "ファイアx２,かいふくx２"),
    BATTLE(A(Formation_21), A(omo_04), "ファイア,ダンシング,ファイア"),
    BATTLE(A(Formation_22), A(omo_04), "ファイア,コマンド,ダンシング"),
    BATTLE(A(Formation_23), A(omo_04), "ファイア,ダンシング,かいふくx2"),
    BATTLE(A(Formation_24), A(omo_04), "ファイアx2,コマンド"),
    BATTLE(A(Formation_25), A(omo_04), "ダンシングx２"),
    BATTLE(A(Formation_26), A(omo_04), "ダンシングx３"),
    BATTLE(A(Formation_27), A(omo_04), "ダンシング,かいふくx２"),
    BATTLE(A(Formation_28), A(omo_04), "ダンシングx２,かいふく"),
    BATTLE(A(Formation_29), A(omo_04), "ダンシングx２,かいふくx２"),
    BATTLE(A(Formation_2A), A(omo_04), "ダンシングx２,ファイアー"),
    BATTLE(A(Formation_2B), A(omo_04), "ダンシング,あお,バルーン"),
    BATTLE(A(Formation_2C), A(omo_04), "ブラック"),
    {},
};

StageList A(Stages) = {
    STAGE("omo_01", A(omo_01)),
    STAGE("omo_02", A(omo_02)),
    STAGE("omo_03", A(omo_03)),
    STAGE("omo_03b", A(omo_03b)),
    STAGE("omo_04", A(omo_04)),
    STAGE("omo_05", A(omo_05)),
    STAGE("omo_05b", A(omo_05b)),
    STAGE("omo_06", A(omo_06)),
    STAGE("omo_07", A(omo_07)),
    {},
};
