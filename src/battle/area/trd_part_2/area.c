#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_trd_part_2

extern ActorBlueprint N(green_ninja_koopa);
extern ActorBlueprint N(yellow_ninja_koopa);
extern ActorBlueprint N(blue_ninja_koopa);
extern ActorBlueprint N(red_ninja_koopa);
extern ActorBlueprint N(fake_bowser);

extern Stage N(trd_00);
extern Stage N(trd_01);
extern Stage N(trd_02);
extern Stage N(trd_02b);
extern Stage N(trd_03);
extern Stage N(trd_04);
extern Stage N(trd_05);
extern Stage N(trd_05b);
extern Stage N(trd_05c);
extern Stage N(trd_05d);
extern Stage N(trd_05e);
extern Stage N(trd_05f);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(green_ninja_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(yellow_ninja_koopa), BTL_POS_GROUND_A, 9),
    ACTOR_BY_IDX(N(blue_ninja_koopa), BTL_POS_GROUND_A, 8),
    ACTOR_BY_IDX(N(red_ninja_koopa), BTL_POS_GROUND_A, 7),
    ACTOR_BY_IDX(N(fake_bowser), BTL_POS_GROUND_D, 6),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(trd_00), "ノコブロス"),
    {},
};

StageList N(Stages) = {
    { "trd_00",  &N(trd_00) },
    { "trd_01",  &N(trd_01) },
    { "trd_02",  &N(trd_02) },
    STAGE("trd_02b", N(trd_02b)),
    { "trd_03",  &N(trd_03) },
    { "trd_04",  &N(trd_04) },
    { "trd_05",  &N(trd_05) },
    STAGE("trd_05b", N(trd_05b)),
    STAGE("trd_05c", N(trd_05c)),
    STAGE("trd_05d", N(trd_05d)),
    STAGE("trd_05e", N(trd_05e)),
    STAGE("trd_05f", N(trd_05f)),
    {},
};
