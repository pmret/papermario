#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_omo3

extern Stage N(omo_01);
extern Stage N(omo_02);
extern Stage N(omo_03);
extern Stage N(omo_03b);
extern Stage N(omo_04);
extern Stage N(omo_05);
extern Stage N(omo_05b);
extern Stage N(omo_06);
extern Stage N(omo_07);

extern ActorBlueprint N(big_lantern_ghost);
extern ActorBlueprint N(goomba);
extern ActorBlueprint N(clubba);
extern ActorBlueprint N(fuzzy);
extern ActorBlueprint N(hammer_bro);
extern ActorBlueprint N(pokey);
extern ActorBlueprint N(koopatrol);
extern ActorBlueprint N(red_shy_guy);

Vec3i N(big_lantern_ghost_pos) = { 30, 0, 10 };

Formation N(Formation_00) = {
    ACTOR_BY_POS(N(big_lantern_ghost), N(big_lantern_ghost_pos), 10),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(goomba), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(goomba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(fuzzy), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(hammer_bro), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(hammer_bro), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(hammer_bro), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_08) = {
    { .actor = &N(pokey), .home = { .index = BTL_POS_GROUND_B }, .priority = 10, .var1 = 1 },
    { .actor = &N(pokey), .home = { .index = BTL_POS_GROUND_C }, .priority = 9, .var1 = 1 },
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(koopatrol), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(koopatrol), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(red_shy_guy), BTL_POS_GROUND_B, 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(omo_03), "ビッグカンテラくん"),
    BATTLE(N(Formation_01), N(omo_04), "クリボー（ピーチへん）"),
    BATTLE(N(Formation_02), N(omo_04), "クリボーx２（ピーチへん）"),
    BATTLE(N(Formation_03), N(omo_04), "ガボンへいx２（ピーチへん）"),
    BATTLE(N(Formation_04), N(omo_04), "チョロボンx２（ピーチへん）"),
    BATTLE(N(Formation_05), N(omo_04), "チョロボンx４（ピーチへん）"),
    BATTLE(N(Formation_06), N(omo_04), "ハンマーブロスx２（ピーチへん）"),
    BATTLE(N(Formation_07), N(omo_04), "ハンマーブロス（ピーチへん）"),
    BATTLE(N(Formation_08), N(omo_04), "サンボx２（ピーチへん）"),
    BATTLE(N(Formation_09), N(omo_04), "トゲノコx２（ピーチへん）"),
    BATTLE(N(Formation_0A), N(omo_01), "ヘイホー"),
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
