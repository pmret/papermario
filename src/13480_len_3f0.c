#include "common.h"

void init_demo_data(void) {
    if (gGameStatusPtr->demoState == 0) {
        gGameStatusPtr->nextDemoScene = 0;
        gGameStatusPtr->demoState = 1;
    }

    gGameStatusPtr->demoButtonInput = 0;
    gGameStatusPtr->demoStickX = 0;
    gGameStatusPtr->demoStickY = 0;

    func_80056228();
    set_map_transition_effect(2);
    set_transition_stencil_zoom_0(0, 255.0f);
    clear_saved_variables();
    clear_script_list();
}

INCLUDE_ASM(s32, "13480_len_3f0", next_demo_scene);

void func_8003845C(void) {

}
