#include "common.h"
#include "effects.h"

void N(Quizmo_UnkI)(void) {
    s32 var = evt_get_variable(NULL, N(Quizmo_WasCorrect));

    if (var == 1) {
        fx_quizmo_answer(0, 0, 0, 0);
    } else if (var == 2) {
        fx_quizmo_answer(1, 0, 0, 0);
    }
}
