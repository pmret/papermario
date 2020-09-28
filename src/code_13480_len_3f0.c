#include "common.h"

#ifdef NON_MATCHING
void init_demo_data(void) {
    if (GAME_STATUS->demoState == 0) {
        GAME_STATUS->nextDemoScene = 0;
        GAME_STATUS->demoState = 1;
    }

    GAME_STATUS->demoStickX = 0;
    GAME_STATUS->demoButtonInput = 0;
    GAME_STATUS->demoStickY = 0;

    func_80056228();
    set_map_transition_effect(2);
    func_80137D88(0, 255.0f);
    clear_saved_variables();
    clear_script_list();
}
#else
INCLUDE_ASM(s32, "code_13480_len_3f0", init_demo_data);
#endif

INCLUDE_ASM(s32, "code_13480_len_3f0", next_demo_scene);

void func_8003845C(void) {

}
