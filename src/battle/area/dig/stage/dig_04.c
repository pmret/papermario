#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/omo_bt04_shape.h"

#define NAMESPACE b_area_dig_dig_04

extern Formation N(Formation_SlotMachine);
extern ActorBlueprint N(slot_machine_stop);
extern ActorBlueprint N(slot_machine_start);

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetTexPanner, 29, TEX_PANNER_A)
    EVT_THREAD
        EVT_SET(LVarE, 0)
        EVT_LOOP(0)
            EVT_ADD(LVarE, 0x8000)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_A, TEX_PANNER_MAIN, LVarE, 0)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_itigo,
    MODEL_kisya,
    MODEL_kusari,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt04_shape",
    .hit = "omo_bt04_hit",
    .bg = "omo_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
    .stageEnemyCount = 4,
    .stageFormation = &N(Formation_SlotMachine),
};

Vec3i N(slot_machine_pos1) = { -49, 56, -68 };
Vec3i N(slot_machine_pos2) = { -13, 56, -68 };
Vec3i N(slot_machine_pos3) = { 20, 56, -68 };
Vec3i N(slot_machine_pos4) = { 53, 56, -68 };

Formation N(Formation_SlotMachine) = {
    { .actor = &N(slot_machine_start), .home = { .vec = &N(slot_machine_pos1) }, .var0 = 0 },
    { .actor = &N(slot_machine_stop), .home = { .vec = &N(slot_machine_pos2) }, .var0 = 1 },
    { .actor = &N(slot_machine_stop), .home = { .vec = &N(slot_machine_pos3) }, .var0 = 2 },
    { .actor = &N(slot_machine_stop), .home = { .vec = &N(slot_machine_pos4) }, .var0 = 3 },
};

#include "battle/common/actor/slot_machine.inc.c"
