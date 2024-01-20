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
    Label(0)
        Call(N(GetSpotlightPos))
        Call(TranslateModel, MODEL_o36, LVar0, 0, LVar1)
        Call(RotateModel, MODEL_o37, LVar2, 1, 0, 0)
        Call(RotateModel, MODEL_o37, LVar3, 0, 0, 1)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(D_8024189C_E13FFC) = {
    Call(EnableModel, MODEL_o64, FALSE)
    Call(EnableModel, MODEL_o65, FALSE)
    Call(EnableModel, MODEL_o66, FALSE)
    Call(EnableModel, MODEL_o67, FALSE)
    Call(EnableModel, MODEL_o53, FALSE)
    Call(EnableModel, MODEL_o68, FALSE)
    Call(EnableModel, MODEL_o73, FALSE)
    Call(EnableModel, MODEL_o54, FALSE)
    Call(EnableModel, MODEL_o69, FALSE)
    Call(EnableModel, MODEL_o55, FALSE)
    Call(EnableModel, MODEL_o72, FALSE)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Call(SetSpriteShading, SHADING_ARN_09)
    SetUP_CAMERA_NO_LEAD()
    Call(SetRenderMode, MODEL_o36, RENDER_MODE_SURFACE_XLU_ZB_ZUPD)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_UpdateSpotlight))
    Exec(N(D_8024189C_E13FFC))
    Exec(N(EVS_802424A4))
    Return
    End
};
