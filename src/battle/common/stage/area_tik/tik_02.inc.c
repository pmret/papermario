#include "battle/battle.h"
#include "mapfs/tik_bt02_shape.h"

#define NAMESPACE A(tik_02)

#include "battle/common/stage/lib/TexturePanner.inc.c"

#define DROPLET_MODEL MODEL_o354
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
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, EVT_PTR(N(DripVolumes)))
    EVT_EXEC(N(EVS_CreateDripVolumes))
    EVT_SET(LVar0, MODEL_misu)
    EVT_SET(LVar1, TEX_PANNER_0)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, -500)
    EVT_EXEC(N(EVS_TexturePanMain))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "tik_tex",
    .shape = "tik_bt02_shape",
    .hit = "tik_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
