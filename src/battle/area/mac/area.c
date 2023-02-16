#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_mac

extern ActorBlueprint N(chan);
extern ActorBlueprint N(lee);
extern ActorBlueprint N(master1);
extern ActorBlueprint N(master2);
extern ActorBlueprint N(master3);

extern Stage N(mac_01);
extern Stage N(mac_02);

Formation N(Formation_00) = {
    { .actor = &N(chan), .home = { .index = 2 }, .priority = 10 },
};

Formation N(Formation_01) = {
    { .actor = &N(lee), .home = { .index = 2 }, .priority = 10 },
};

Formation N(Formation_02) = {
    { .actor = &N(master1), .home = { .index = 2 }, .priority = 10 },
};

Formation N(Formation_03) = {
    { .actor = &N(master2), .home = { .index = 2 }, .priority = 10 },
};

Formation N(Formation_04) = {
    { .actor = &N(master3), .home = { .index = 2 }, .priority = 10 },
};

BattleList N(Formations) = {
    BATTLE("チェン",         N(Formation_00), &N(mac_02)),
    BATTLE("リー",           N(Formation_01), &N(mac_02)),
    BATTLE("シショー その１", N(Formation_02), &N(mac_02)),
    BATTLE("シショー その２", N(Formation_03), &N(mac_02)),
    BATTLE("シショー その３", N(Formation_04), &N(mac_02)),
    {},
};

StageList N(Stages) = {
    { "mac_01", &N(mac_01) },
    { "mac_02", &N(mac_02) },
    {},
};
