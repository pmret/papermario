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
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Set(LVar0, Ref(N(DripVolumes)))
    Exec(N(EVS_CreateDripVolumes))
    Set(LVar0, MODEL_misu)
    Set(LVar1, TEX_PANNER_0)
    Set(LVar2, 0)
    Set(LVar3, -500)
    Exec(N(EVS_TexturePanMain))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "tik_tex",
    .shape = "tik_bt02_shape",
    .hit = "tik_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
