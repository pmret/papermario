#include "mgm_01.h"

ApiStatus func_80240000_E12760(Evt* script, s32 isInitialCall) {
    SpriteShadingProfile* shading;
    f32 posX, posZ;
    f32 shearX;
    f32 shearZ;

    posX = gPlayerStatusPtr->position.x;
    if (posX < -95.0) {
        posX = -95.0;
    }
    if (posX > 95.0) {
        posX = 95.0;
    }
    posZ = gPlayerStatusPtr->position.z;
    if (posZ < -80.0) {
        posZ = -80.0;
    }
    if (posZ > 80.0) {
        posZ = 80.0;
    }

    shearX = posZ * -0.35 * 0.3;
    shearZ = posX * 0.35;
    
    evt_set_float_variable(script, LW(0), posX);
    evt_set_float_variable(script, LW(1), posZ);
    evt_set_float_variable(script, LW(2), shearX);
    evt_set_float_variable(script, LW(3), shearZ);
    
    shading = D_80151328;
    shading->sources[0].pos.x = gPlayerStatusPtr->position.x * 0.8;
    shading->sources[0].pos.y = 80.0f;
    shading->sources[0].pos.z = gPlayerStatusPtr->position.z + 50.0f;

    return ApiStatus_DONE2;
}
