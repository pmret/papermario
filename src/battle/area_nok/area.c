#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_nok

extern ActorDesc N(goomba);
extern ActorDesc N(spiked_goomba);
extern ActorDesc N(paragoomba);
extern ActorDesc N(koopa_troopa);
extern ActorDesc N(paratroopa);
extern ActorDesc N(fuzzy);
extern ActorDesc N(kent_c_koopa);

extern Stage N(nok_01);
extern Stage N(nok_02);
extern Stage N(nok_03);
extern Stage N(nok_04);

Formation N(formation_00) = {
    { .actor = &N(goomba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_01) = {
    { .actor = &N(goomba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_02) = {
    { .actor = &N(paragoomba), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(paragoomba), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_03) = {
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(paragoomba), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_04) = {
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_05) = {
    { .actor = &N(spiked_goomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(goomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_06) = {
    { .actor = &N(spiked_goomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_07) = {
    { .actor = &N(spiked_goomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(spiked_goomba), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_08) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_09) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0A) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0B) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0C) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0D) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0E) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(paragoomba), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(paragoomba), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_0F) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spiked_goomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(paragoomba), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_10) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(paragoomba), .home = { .index = 7 }, .priority = 7 },
};

Formation N(formation_11) = {
    { .actor = &N(paratroopa), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(paratroopa), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_12) = {
    { .actor = &N(paratroopa), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_13) = {
    { .actor = &N(paratroopa), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_14) = {
    { .actor = &N(paratroopa), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(spiked_goomba), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_15) = {
    { .actor = &N(fuzzy), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_16) = {
    { .actor = &N(fuzzy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(fuzzy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_17) = {
    { .actor = &N(fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(fuzzy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(fuzzy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_18) = {
    { .actor = &N(kent_c_koopa), .home = { .index = 1 }, .priority = 10 },
};

BattleList N(formationTable) = {
    BATTLE("クリボーx２",                        N(formation_00), &N(nok_02)),
    BATTLE("クリボー,トゲクリボー",               N(formation_01), &N(nok_02)),
    BATTLE("パタクリボーx２",                     N(formation_02), &N(nok_02)),
    BATTLE("トゲクリボー、パタクリボー",           N(formation_03), &N(nok_02)),
    BATTLE("トゲクリボーx２",                     N(formation_04), &N(nok_02)),
    BATTLE("トゲクリボー、クリボーx2",             N(formation_05), &N(nok_02)),
    BATTLE("トゲクリボーx３",                     N(formation_06), &N(nok_02)),
    BATTLE("トゲクリボーx４",                     N(formation_07), &N(nok_02)),
    BATTLE("ノコノコ、クリボー",                   N(formation_08), &N(nok_02)),
    BATTLE("ノコノコx２",                         N(formation_09), &N(nok_02)),
    BATTLE("ノコノコx３",                         N(formation_0A), &N(nok_02)),
    BATTLE("ノコノコ、トゲクリボー",               N(formation_0B), &N(nok_02)),
    BATTLE("ノコノコx2、トゲクリ",                 N(formation_0C), &N(nok_02)),
    BATTLE("ノコノコ、トゲクリボーx2",             N(formation_0D), &N(nok_02)),
    BATTLE("ノコノコ、パタクリボーx2",             N(formation_0E), &N(nok_02)),
    BATTLE("ノコノコ、トゲクリボー,パタクリボー",   N(formation_0F), &N(nok_02)),
    BATTLE("ノコノコx2、トゲクリボー,パタクリボー", N(formation_10), &N(nok_02)),
    BATTLE("パタパタx2",                          N(formation_11), &N(nok_02)),
    BATTLE("パタパタ、ノコノコ",                   N(formation_12), &N(nok_02)),
    BATTLE("パタパタ、ノコノコ、トゲクリボー",      N(formation_13), &N(nok_02)),
    BATTLE("パタパタ、ノコノコ、トゲクリボーx2",    N(formation_14), &N(nok_02)),
    BATTLE("チョロボン",                          N(formation_15), &N(nok_02)),
    BATTLE("チョロボンx2",                        N(formation_16), &N(nok_02)),
    BATTLE("チョロボンx4",                        N(formation_17), &N(nok_02)),
    BATTLE("ゼニノコー",                          N(formation_18), &N(nok_02)),
    {},
};

StageList N(stageTable) = {
    { "nok_01", &N(nok_01) },
    { "nok_02", &N(nok_02) },
    { "nok_03", &N(nok_03) },
    { "nok_04", &N(nok_04) },
    {},
};
