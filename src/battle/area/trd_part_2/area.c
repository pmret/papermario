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
    { .actor = &N(green_ninja_koopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(yellow_ninja_koopa), .home = { .index = 0 }, .priority = 9 },
    { .actor = &N(blue_ninja_koopa), .home = { .index = 0 }, .priority = 8 },
    { .actor = &N(red_ninja_koopa), .home = { .index = 0 }, .priority = 7 },
    { .actor = &N(fake_bowser), .home = { .index = 3 }, .priority = 6 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(trd_00), "ノコブロス"),
    {},
};

StageList N(Stages) = {
    { "trd_00",  &N(trd_00) },
    { "trd_01",  &N(trd_01) },
    { "trd_02",  &N(trd_02) },
    { "trd_02b", &N(trd_02b) },
    { "trd_03",  &N(trd_03) },
    { "trd_04",  &N(trd_04) },
    { "trd_05",  &N(trd_05) },
    { "trd_05b", &N(trd_05b) },
    { "trd_05c", &N(trd_05c) },
    { "trd_05d", &N(trd_05d) },
    { "trd_05e", &N(trd_05e) },
    { "trd_05f", &N(trd_05f) },
    {},
};
