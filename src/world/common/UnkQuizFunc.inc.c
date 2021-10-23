#include "common.h"
#include "map.h"

extern QuizRequirements N(quizRequirements)[];

ApiStatus N(UnkQuizFunc)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemyID;
    u16 phi_s0 = evt_get_variable(script, EVT_SAVE_FLAG(1768));
    u16 phi_s7 = evt_get_variable(script, EVT_SAVE_FLAG(1769));
    u16 temp_s6 = evt_get_variable(script, EVT_SAVE_VAR(350));
    u16 phi_s5 = evt_get_variable(script, EVT_SAVE_VAR(351));
    s32 var;
    s32 i;

    s32 test2;
    u16 temp_s3 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 sp_10 = (enemy->varTable[0] & 0xFF0000) >> 16;
    u16 temp_s2 = (enemy->varTable[0] & 0xFF00) >> 8;
    u16 sp_1e = (enemy->varTable[0] & 0xFF) >> 0;
    s32 temp_v0;
    s32 temp_s0_2;

    if (temp_s3 != temp_s6) {
        phi_s7 = 0;
        phi_s0 = 0;
    }

    if (phi_s0 == 0) {
        if (rand_int(100) < 30) {
            phi_s5 = rand_int(temp_s2 - 1);
            temp_s6 = temp_s3;
            evt_set_variable(script, EVT_SAVE_VAR(350), temp_s6);
            evt_set_variable(script, EVT_SAVE_VAR(351), phi_s5);
            phi_s0 = 1;
        }
    }

    evt_set_variable(script, EVT_SAVE_FLAG(1768), phi_s0);
    evt_set_variable(script, EVT_SAVE_FLAG(1769), phi_s7);
    temp_s0_2 = evt_get_variable(NULL, EVT_SAVE_VAR(352));
    temp_v0 = evt_get_variable(NULL, EVT_STORY_PROGRESS);

    for (i = 0; i < 8; i++) {
        if (temp_v0 < (*(N(quizRequirements) + i)).unk_00) {
            break;
        }
    }

    temp_v0 = temp_s0_2 < (*(N(quizRequirements) + i)).unk_04;
    test2 = var = temp_v0;

    if ((((sp_10 == temp_s6) && (sp_1e == phi_s5) && (phi_s7 == 0) && test2)) ||
        ((gGameStatusPtr->debugQuizmo != 0) && var)) {
        script->varTable[0] = 1;
    } else {
        kill_enemy(enemy);
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}
