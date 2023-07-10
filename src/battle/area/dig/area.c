#include "area.h"

extern ActorBlueprint A(fuzzy);
extern ActorBlueprint A(monty_mole);
extern ActorBlueprint A(pokey);
extern ActorBlueprint A(bandit);
extern ActorBlueprint A(red_shy_guy);
extern ActorBlueprint A(tubba_blubba);

extern Stage A(nok_04);
extern Stage A(iwa_01b);
extern Stage A(sbk_02);
extern Stage A(omo_04);
extern Stage A(dgb_05);

extern EvtScript A(dig_01_script);
extern EvtScript A(dig_02_script);
extern EvtScript A(dig_03_script);
extern EvtScript A(dig_04_script);
extern EvtScript A(dig_05_script);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(fuzzy), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_C, 9),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_D, 8),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_C, 9),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_D, 8),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(red_shy_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(red_shy_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(red_shy_guy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(red_shy_guy), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(tubba_blubba), BTL_POS_GROUND_C, 10),
};

BattleList A(Formations) = {
    BATTLE_WITH_SCRIPT(A(Formation_00), A(nok_04), A(dig_01_script), "ダイジェスト０１"),
    BATTLE_WITH_SCRIPT(A(Formation_01), A(iwa_01b), A(dig_02_script), "ダイジェスト０２"),
    BATTLE_WITH_SCRIPT(A(Formation_02), A(sbk_02), A(dig_03_script), "ダイジェスト０３"),
    BATTLE_WITH_SCRIPT(A(Formation_03), A(omo_04), A(dig_04_script), "ダイジェスト０４"),
    BATTLE_WITH_SCRIPT(A(Formation_04), A(dgb_05), A(dig_05_script), "ダイジェスト０５"),
    {},
};

StageList A(Stages) = {
    STAGE("dig_01", A(nok_04)),
    STAGE("dig_02", A(iwa_01b)),
    STAGE("dig_03", A(sbk_02)),
    STAGE("dig_04", A(omo_04)),
    STAGE("dig_05", A(dgb_05)),
    {},
};
