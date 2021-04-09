#include "gv_01.h"

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

#include "world/common/UnkFunc25.inc.c"

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

ApiStatus func_802405EC_E1EA4C(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        set_curtain_scale_goal(1.0);
        set_curtain_fade(0);
    }

    script->functionTemp[0].s += 5;
    if (script->functionTemp[0].s > 255) {
        script->functionTemp[0].s = 255;
    }

    set_transition_stencil_color(1, 208, 208, 208);
    set_transition_stencil_zoom_1(0, script->functionTemp[0].s);
    set_transition_stencil_alpha(1, 0);
    return script->functionTemp[0].s == 255;
}

INCLUDE_ASM(s32, "world/area_gv/gv_01/E1E460", func_80240688_E1EAE8);
