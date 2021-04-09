#include "common.h"
#include "map.h"

extern s16 D_8009A634;

void N(UnkFunc28)(ScriptInstance *script, s32 isInitialCall) {
    Camera* camera = CAM2(D_8009A634);

    if (*((s32*)script->labelPositions[0]) & 1) {
        clamp_angle(-camera->currentYaw);
    }
}
