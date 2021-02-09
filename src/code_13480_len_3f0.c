#include "common.h"

void init_demo_data(void) {
    GameStatus* gameStatus;
    GameStatus* gameStatus2;

    if (GAME_STATUS->demoState == 0) {
        GAME_STATUS->nextDemoScene = 0;
        GAME_STATUS->demoState = 1;
    }

    gameStatus = GAME_STATUS;
    GAME_STATUS->demoStickX = 0;
    gameStatus2 = GAME_STATUS;
    gameStatus->demoButtonInput = 0;
    gameStatus2->demoStickY = 0;

    func_80056228();
    set_map_transition_effect(2);
    set_transition_stencil_zoom_0(0, 255.0f);
    clear_saved_variables();
    clear_script_list();
}

INCLUDE_ASM(s32, "code_13480_len_3f0", next_demo_scene);

void func_8003845C(void) {

}
