#include "common.h"

ApiStatus N(Quizmo_UnkJ)(Evt* script, s32 isInitialCall) {
    N(Quizmo_Worker) = create_generic_entity_frontUI(NULL, N(Quizmo_UnkI));
    return ApiStatus_DONE2;
}
