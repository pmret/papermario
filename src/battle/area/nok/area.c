#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_nok

extern ActorBlueprint N(goomba);
extern ActorBlueprint N(spiked_goomba);
extern ActorBlueprint N(paragoomba);
extern ActorBlueprint N(koopa_troopa);
extern ActorBlueprint N(paratroopa);
extern ActorBlueprint N(fuzzy);
extern ActorBlueprint N(kent_c_koopa);

extern Stage N(nok_01);
extern Stage N(nok_02);
extern Stage N(nok_03);
extern Stage N(nok_04);

Formation N(Formation_00) = {
    { .actor = &N(goomba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_01) = {
    { .actor = &N(goomba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_02) = {
    { .actor = &N(paragoomba), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(paragoomba), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_03) = {
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(paragoomba), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_04) = {
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_05) = {
    { .actor = &N(spiked_goomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(goomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_06) = {
    { .actor = &N(spiked_goomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_07) = {
    { .actor = &N(spiked_goomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(spiked_goomba), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_08) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_09) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0A) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0B) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0C) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0D) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0E) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(paragoomba), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(paragoomba), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_0F) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(paragoomba), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_10) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(paragoomba), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_11) = {
    { .actor = &N(paratroopa), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(paratroopa), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_12) = {
    { .actor = &N(paratroopa), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_13) = {
    { .actor = &N(paratroopa), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_14) = {
    { .actor = &N(paratroopa), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(spiked_goomba), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_15) = {
    { .actor = &N(fuzzy), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_16) = {
    { .actor = &N(fuzzy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(fuzzy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_17) = {
    { .actor = &N(fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(fuzzy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(fuzzy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_18) = {
    { .actor = &N(kent_c_koopa), .home = { .index = 1 }, .priority = 10 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(nok_02), "クリボーx２"),
    BATTLE(N(Formation_01), &N(nok_02), "クリボー,トゲクリボー"),
    BATTLE(N(Formation_02), &N(nok_02), "パタクリボーx２"),
    BATTLE(N(Formation_03), &N(nok_02), "トゲクリボー、パタクリボー"),
    BATTLE(N(Formation_04), &N(nok_02), "トゲクリボーx２"),
    BATTLE(N(Formation_05), &N(nok_02), "トゲクリボー、クリボーx2"),
    BATTLE(N(Formation_06), &N(nok_02), "トゲクリボーx３"),
    BATTLE(N(Formation_07), &N(nok_02), "トゲクリボーx４"),
    BATTLE(N(Formation_08), &N(nok_02), "ノコノコ、クリボー"),
    BATTLE(N(Formation_09), &N(nok_02), "ノコノコx２"),
    BATTLE(N(Formation_0A), &N(nok_02), "ノコノコx３"),
    BATTLE(N(Formation_0B), &N(nok_02), "ノコノコ、トゲクリボー"),
    BATTLE(N(Formation_0C), &N(nok_02), "ノコノコx2、トゲクリ"),
    BATTLE(N(Formation_0D), &N(nok_02), "ノコノコ、トゲクリボーx2"),
    BATTLE(N(Formation_0E), &N(nok_02), "ノコノコ、パタクリボーx2"),
    BATTLE(N(Formation_0F), &N(nok_02), "ノコノコ、トゲクリボー,パタクリボー"),
    BATTLE(N(Formation_10), &N(nok_02), "ノコノコx2、トゲクリボー,パタクリボー"),
    BATTLE(N(Formation_11), &N(nok_02), "パタパタx2"),
    BATTLE(N(Formation_12), &N(nok_02), "パタパタ、ノコノコ"),
    BATTLE(N(Formation_13), &N(nok_02), "パタパタ、ノコノコ、トゲクリボー"),
    BATTLE(N(Formation_14), &N(nok_02), "パタパタ、ノコノコ、トゲクリボーx2"),
    BATTLE(N(Formation_15), &N(nok_02), "チョロボン"),
    BATTLE(N(Formation_16), &N(nok_02), "チョロボンx2"),
    BATTLE(N(Formation_17), &N(nok_02), "チョロボンx4"),
    BATTLE(N(Formation_18), &N(nok_02), "ゼニノコー"),
    {},
};

StageList N(Stages) = {
    { "nok_01", &N(nok_01) },
    { "nok_02", &N(nok_02) },
    { "nok_03", &N(nok_03) },
    { "nok_04", &N(nok_04) },
    {},
};
