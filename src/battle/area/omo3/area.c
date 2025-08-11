#include "area.h"

extern Stage A(omo_01);
extern Stage A(omo_02);
extern Stage A(omo_03);
extern Stage A(omo_03b);
extern Stage A(omo_04);
extern Stage A(omo_05);
extern Stage A(omo_05b);
extern Stage A(omo_06);
extern Stage A(omo_07);

extern ActorBlueprint A(big_lantern_ghost);
extern ActorBlueprint A(goomba);
extern ActorBlueprint A(clubba);
extern ActorBlueprint A(fuzzy);
extern ActorBlueprint A(hammer_bro);
extern ActorBlueprint A(pokey);
extern ActorBlueprint A(koopatrol);
extern ActorBlueprint A(red_shy_guy);

Vec3i A(big_lantern_ghost_pos) = { 30, 0, 10 };

Formation A(Formation_00) = {
    ACTOR_BY_POS(A(big_lantern_ghost), A(big_lantern_ghost_pos), 10),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(hammer_bro), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 10, 0, true),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_C,  9, 0, true),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(koopatrol), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(red_shy_guy), BTL_POS_GROUND_B, 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(omo_03), "ビッグカンテラくん"),
    BATTLE(A(Formation_01), A(omo_04), "クリボー（ピーチへん）"),
    BATTLE(A(Formation_02), A(omo_04), "クリボーx２（ピーチへん）"),
    BATTLE(A(Formation_03), A(omo_04), "ガボンへいx２（ピーチへん）"),
    BATTLE(A(Formation_04), A(omo_04), "チョロボンx２（ピーチへん）"),
    BATTLE(A(Formation_05), A(omo_04), "チョロボンx４（ピーチへん）"),
    BATTLE(A(Formation_06), A(omo_04), "ハンマーブロスx２（ピーチへん）"),
    BATTLE(A(Formation_07), A(omo_04), "ハンマーブロス（ピーチへん）"),
    BATTLE(A(Formation_08), A(omo_04), "サンボx２（ピーチへん）"),
    BATTLE(A(Formation_09), A(omo_04), "トゲノコx２（ピーチへん）"),
    BATTLE(A(Formation_0A), A(omo_01), "ヘイホー"),
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
