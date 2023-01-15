#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/omo_bt04_shape.h"

#define NAMESPACE b_area_dig_dig_04

extern Formation N(formation_slot_machine);
extern ActorBlueprint N(slot_machine_stop);
extern ActorBlueprint N(slot_machine_start);

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetTexPanner, 29, TEX_PANNER_A)
    EVT_THREAD
        EVT_SET(LVarE, 0)
        EVT_LOOP(0)
            EVT_ADD(LVarE, 32768)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_A, TEX_PANNER_MAIN, LVarE, 0)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_itigo, MODEL_kisya, MODEL_kusari, 0,
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt04_shape",
    .hit = "omo_bt04_hit",
    .bg = "omo_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
    .stageEnemyCount = 4,
    .stageFormation = &N(formation_slot_machine),
};

Vec3i N(slot_machine_pos1) = { -49, 56, -68 };
Vec3i N(slot_machine_pos2) = { -13, 56, -68 };
Vec3i N(slot_machine_pos3) = { 20, 56, -68 };
Vec3i N(slot_machine_pos4) = { 53, 56, -68 };

Formation N(formation_slot_machine) = {
    { .actor = &N(slot_machine_start), .home = { .vec = &N(slot_machine_pos1) }, .var0 = 0 },
    { .actor = &N(slot_machine_stop), .home = { .vec = &N(slot_machine_pos2) }, .var0 = 1 },
    { .actor = &N(slot_machine_stop), .home = { .vec = &N(slot_machine_pos3) }, .var0 = 2 },
    { .actor = &N(slot_machine_stop), .home = { .vec = &N(slot_machine_pos4) }, .var0 = 3 },
};

#include "battle/common/actor/slot_machine.inc.c"
