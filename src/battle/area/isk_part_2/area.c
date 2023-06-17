#include "area.h"

extern ActorBlueprint A(tutankoopa);

extern Stage A(isk_00);
extern Stage A(isk_01);
extern Stage A(isk_02);
extern Stage A(isk_02b);
extern Stage A(isk_02c);
extern Stage A(isk_03);
extern Stage A(isk_03b);
extern Stage A(isk_04);
extern Stage A(isk_05);
extern Stage A(isk_06);
extern Stage A(isk_06b);
extern Stage A(isk_07);

Vec3i A(BossPos) = { 97, 70, 17 };

Formation A(Formation_00) = {
    ACTOR_BY_POS(A(tutankoopa), A(BossPos), 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(isk_01), "カーメン　ワンワン"),
    {},
};

StageList A(Stages) = {
    STAGE("isk_00", A(isk_00)),
    STAGE("isk_01", A(isk_01)),
    STAGE("isk_02", A(isk_02)),
    STAGE("isk_02b", A(isk_02b)),
    STAGE("isk_02c", A(isk_02c)),
    STAGE("isk_03", A(isk_03)),
    STAGE("isk_03b", A(isk_03b)),
    STAGE("isk_04", A(isk_04)),
    STAGE("isk_05", A(isk_05)),
    STAGE("isk_06", A(isk_06)),
    STAGE("isk_06b", A(isk_06b)),
    STAGE("isk_07", A(isk_07)),
    {},
};
