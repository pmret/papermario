#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "message_ids.h"

#define NAMESPACE b_area_mac

extern ActorBlueprint N(chan);
extern ActorBlueprint N(lee);
extern ActorBlueprint N(master1);
extern ActorBlueprint N(master2);
extern ActorBlueprint N(master3);

extern Stage N(mac_01);
extern Stage N(mac_02);

Formation N(formation_00) = {
    { .actor = &N(chan), .home = { .index = 2 }, .priority = 10 },
};

Formation N(formation_01) = {
    { .actor = &N(lee), .home = { .index = 2 }, .priority = 10 },
};

Formation N(formation_02) = {
    { .actor = &N(master1), .home = { .index = 2 }, .priority = 10 },
};

Formation N(formation_03) = {
    { .actor = &N(master2), .home = { .index = 2 }, .priority = 10 },
};

Formation N(formation_04) = {
    { .actor = &N(master3), .home = { .index = 2 }, .priority = 10 },
};

BattleList N(formationTable) = {
    BATTLE("チェン",         N(formation_00), &N(mac_02)),
    BATTLE("リー",           N(formation_01), &N(mac_02)),
    BATTLE("シショー その１", N(formation_02), &N(mac_02)),
    BATTLE("シショー その２", N(formation_03), &N(mac_02)),
    BATTLE("シショー その３", N(formation_04), &N(mac_02)),
    {},
};

StageList N(stageTable) = {
    { "mac_01", &N(mac_01) },
    { "mac_02", &N(mac_02) },
    {},
};
