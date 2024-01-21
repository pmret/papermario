#include "battle/battle.h"
#include "mapfs/tik_bt03_shape.h"

#define NAMESPACE A(tik_03)

#define DROPLET_MODEL MODEL_o371
#include "battle/common/stage/lib/DripVolumes.inc.c"

DripVolumeList N(DripVolumes) = {
    .count = 1,
    .volumes = {
        {
            .minPos = { -100,  -50 },
            .maxPos = {  200,  100 },
            .startY = 200,
            .endY   = 0,
            .duration = 60,
            .density  = 4,
        }
    }
};

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Set(LVar0, Ref(N(DripVolumes)))
    Exec(N(EVS_CreateDripVolumes))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "tik_tex",
    .shape = "tik_bt03_shape",
    .hit = "tik_bt03_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};

