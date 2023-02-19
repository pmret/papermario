#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3_mac_01

#include "common/UnkModelStuff2.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LVar0, 44)
        EVT_EXEC(N(EVS_AnimateWaveModel))
        EVT_WAIT(5)
        EVT_SET(LVar0, 47)
        EVT_EXEC(N(EVS_AnimateWaveModel))
        EVT_WAIT(5)
        EVT_SET(LVar0, 46)
        EVT_EXEC(N(EVS_AnimateWaveModel))
        EVT_WAIT(5)
        EVT_SET(LVar0, 45)
        EVT_EXEC(N(EVS_AnimateWaveModel))
    EVT_END_THREAD
    EVT_SET(LVar0, 40)
    EVT_EXEC(N(EVS_AnimateFishModel))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "mac_tex",
    .shape = "mac_bt01_shape",
    .hit = "mac_bt01_hit",
    .bg = "nok_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
