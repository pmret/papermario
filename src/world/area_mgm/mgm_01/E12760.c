#include "mgm_01.h"

/* N(GetSpotlightPos) */
ApiStatus func_80240000_E12760(Evt* script, s32 isInitialCall) {
    SpriteShadingProfile* shading;
    f32 spotLightPosX, spotLightPosZ;
    f32 lightBeamRotX, lightBeamRotZ;

    spotLightPosX = gPlayerStatusPtr->position.x;
    if (spotLightPosX < -95.0) {
        spotLightPosX = -95.0;
    }
    if (spotLightPosX > 95.0) {
        spotLightPosX = 95.0;
    }
    spotLightPosZ = gPlayerStatusPtr->position.z;
    if (spotLightPosZ < -80.0) {
        spotLightPosZ = -80.0;
    }
    if (spotLightPosZ > 80.0) {
        spotLightPosZ = 80.0;
    }

    lightBeamRotX = spotLightPosZ * -0.35 * 0.3;
    lightBeamRotZ = spotLightPosX * 0.35;
    
    evt_set_float_variable(script, LW(0), spotLightPosX);
    evt_set_float_variable(script, LW(1), spotLightPosZ);
    evt_set_float_variable(script, LW(2), lightBeamRotX);
    evt_set_float_variable(script, LW(3), lightBeamRotZ);
    
    shading = D_80151328;
    shading->sources[0].pos.x = gPlayerStatusPtr->position.x * 0.8;
    shading->sources[0].pos.y = 80.0f;
    shading->sources[0].pos.z = gPlayerStatusPtr->position.z + 50.0f;

    return ApiStatus_DONE2;
}
