#include "iwa_01.h"

MAP_RODATA_PAD(1,splash);

#include "world/area_iwa/iwa_01/splash.png.inc.c"
#include "world/area_iwa/iwa_01/splash.vtx.inc.c"
#include "world/area_iwa/iwa_01/splash.gfx.inc.c"

API_CALLABLE(N(func_80240398_90FA48));
void N(gfx_build_splash)(void);

INCLUDE_ASM(s32, "world/area_iwa/iwa_01/90F6B0", iwa_01_gfx_build_splash);
INCLUDE_ASM(s32, "world/area_iwa/iwa_01/90F6B0", iwa_01_func_80240398_90FA48);
MAP_DATA_SECTION_START;

EvtScript N(EVS_MakeSplashes) = {
    EVT_CALL(N(func_80240398_90FA48))
    EVT_CALL(SetCustomGfxBuilders, 0, 0, EVT_PTR(N(gfx_build_splash)))
    EVT_CALL(SetModelCustomGfx, MODEL_dummy_sprash2, 0, -1)
    EVT_RETURN
    EVT_END
};
