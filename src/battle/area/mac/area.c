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
    ACTOR_BY_IDX(N(chan), BTL_POS_GROUND_C, 10),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(lee), BTL_POS_GROUND_C, 10),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(master1), BTL_POS_GROUND_C, 10),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(master2), BTL_POS_GROUND_C, 10),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(master3), BTL_POS_GROUND_C, 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(mac_02), "チェン"),
    BATTLE(N(Formation_01), N(mac_02), "リー"),
    BATTLE(N(Formation_02), N(mac_02), "シショー その１"),
    BATTLE(N(Formation_03), N(mac_02), "シショー その２"),
    BATTLE(N(Formation_04), N(mac_02), "シショー その３"),
    {},
};

StageList N(Stages) = {
    STAGE("mac_01", N(mac_01)),
    STAGE("mac_02", N(mac_02)),
    {},
};
