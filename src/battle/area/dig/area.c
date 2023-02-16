#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_dig

extern ActorBlueprint N(fuzzy);
extern ActorBlueprint N(monty_mole);
extern ActorBlueprint N(pokey);
extern ActorBlueprint N(bandit);
extern ActorBlueprint N(red_shy_guy);
extern ActorBlueprint N(tubba_blubba);

extern Stage N(dig_01);
extern Stage N(dig_02);
extern Stage N(dig_03);
extern Stage N(dig_04);
extern Stage N(dig_05);

extern EvtScript N(dig_01_script);
extern EvtScript N(dig_02_script);
extern EvtScript N(dig_03_script);
extern EvtScript N(dig_04_script);
extern EvtScript N(dig_05_script);

Formation N(Formation_00) = {
    { .actor = &N(fuzzy), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(fuzzy), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(fuzzy), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(fuzzy), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_01) = {
    { .actor = &N(monty_mole), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(monty_mole), .home = { .index = 2 }, .priority = 9, },
    { .actor = &N(monty_mole), .home = { .index = 3 }, .priority = 8, },
};

Formation N(Formation_02) = {
    { .actor = &N(pokey), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 9, },
    { .actor = &N(pokey), .home = { .index = 3 }, .priority = 8, },
};

Formation N(Formation_03) = {
    { .actor = &N(red_shy_guy), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(red_shy_guy), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(red_shy_guy), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(red_shy_guy), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_04) = {
    { .actor = &N(tubba_blubba), .home = { .index = 2 }, .priority = 10, },
};

BattleList N(Formations) = {
    BATTLE_WITH_SCRIPT(N(Formation_00), &N(dig_01), &N(dig_01_script), "ダイジェスト０１"),
    BATTLE_WITH_SCRIPT(N(Formation_01), &N(dig_02), &N(dig_02_script), "ダイジェスト０２"),
    BATTLE_WITH_SCRIPT(N(Formation_02), &N(dig_03), &N(dig_03_script), "ダイジェスト０３"),
    BATTLE_WITH_SCRIPT(N(Formation_03), &N(dig_04), &N(dig_04_script), "ダイジェスト０４"),
    BATTLE_WITH_SCRIPT(N(Formation_04), &N(dig_05), &N(dig_05_script), "ダイジェスト０５"),
    {},
};

StageList N(Stages) = {
    { "dig_01", &N(dig_01) },
    { "dig_02", &N(dig_02) },
    { "dig_03", &N(dig_03) },
    { "dig_04", &N(dig_04) },
    { "dig_05", &N(dig_05) },
    {},
};
