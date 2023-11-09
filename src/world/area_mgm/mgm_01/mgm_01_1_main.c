#include "mgm_01.h"

API_CALLABLE(N(GetSpotlightPos)) {
    SpriteShadingProfile* shading;
    f32 spotLightPosX, spotLightPosZ;
    f32 lightBeamRotX, lightBeamRotZ;

    spotLightPosX = gPlayerStatusPtr->pos.x;
    if (spotLightPosX < -95.0) {
        spotLightPosX = -95.0;
    }
    if (spotLightPosX > 95.0) {
        spotLightPosX = 95.0;
    }
    spotLightPosZ = gPlayerStatusPtr->pos.z;
    if (spotLightPosZ < -80.0) {
        spotLightPosZ = -80.0;
    }
    if (spotLightPosZ > 80.0) {
        spotLightPosZ = 80.0;
    }

    lightBeamRotX = spotLightPosZ * -0.35 * 0.3;
    lightBeamRotZ = spotLightPosX * 0.35;

    evt_set_float_variable(script, LVar0, spotLightPosX);
    evt_set_float_variable(script, LVar1, spotLightPosZ);
    evt_set_float_variable(script, LVar2, lightBeamRotX);
    evt_set_float_variable(script, LVar3, lightBeamRotZ);

    shading = gSpriteShadingProfile;
    shading->sources[0].pos.x = gPlayerStatusPtr->pos.x * 0.8;
    shading->sources[0].pos.y = 80.0f;
    shading->sources[0].pos.z = gPlayerStatusPtr->pos.z + 50.0f;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdateSpotlight) = {
    EVT_LABEL(0)
        EVT_CALL(N(GetSpotlightPos))
        EVT_CALL(TranslateModel, MODEL_o36, LVar0, 0, LVar1)
        EVT_CALL(RotateModel, MODEL_o37, LVar2, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o37, LVar3, 0, 0, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024189C_E13FFC) = {
    EVT_CALL(EnableModel, MODEL_o64, FALSE)
    EVT_CALL(EnableModel, MODEL_o65, FALSE)
    EVT_CALL(EnableModel, MODEL_o66, FALSE)
    EVT_CALL(EnableModel, MODEL_o67, FALSE)
    EVT_CALL(EnableModel, MODEL_o53, FALSE)
    EVT_CALL(EnableModel, MODEL_o68, FALSE)
    EVT_CALL(EnableModel, MODEL_o73, FALSE)
    EVT_CALL(EnableModel, MODEL_o54, FALSE)
    EVT_CALL(EnableModel, MODEL_o69, FALSE)
    EVT_CALL(EnableModel, MODEL_o55, FALSE)
    EVT_CALL(EnableModel, MODEL_o72, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_CALL(SetSpriteShading, SHADING_ARN_09)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(SetRenderMode, MODEL_o36, RENDER_MODE_SURFACE_XLU_ZB_ZUPD)
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_UpdateSpotlight))
    EVT_EXEC(N(D_8024189C_E13FFC))
    EVT_EXEC(N(EVS_802424A4))
    EVT_RETURN
    EVT_END
};
