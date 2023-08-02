#include "kgr_01.h"

#define TONGUE_WIGGLE_RATE 10
#define TONGUE_COPY_MODEL_ID 10000

// tongue wiggle rate
u16 N(TongueWiggleTime) = 0;

void N(add_tongue_deformation)(Vtx* src, Vtx* dest, s32 numVertices, s32 time) {
    PlayerStatus* player = &gPlayerStatus;
    Vtx_t* vs;
    Vtx_t* vd;
    s32 dx;
    s32 dz;
    s32 offset;
    s32 pct;
    s32 i;

    for (i = 0; i < numVertices; i++) {
        vs = &src[i].v;
        vd = &dest[i].v;

        // base y-offset goes from 0-5 based on radial distance to player,
        // with 0 at the closest and 5 when distance squared > 1000.
        // this creates the depression of the tongue where the player is standing.
        dx = vd->ob[0] - player->pos.x;
        dz = vd->ob[2] - player->pos.z;
        offset = ((dx * dx) + (dz * dz)) / 100;
        if (offset > 10) {
          offset = 10;
        }
        offset /= 2;

        // space-based and time-based undulations are the second componet of the y-offset
        // reuse of the pct variable is not ideal, but required to match
        pct = 2.0f + 2.0f * sin_rad(
            (f32)vd->ob[0] * 0.06 +
            (f32)vd->ob[2] * 0.03f +
            time * 0.01f);
        offset += pct;

        // modulate y-offset based on vertex x-position
        // this anchors the tongue in the back of the throat and makes the unudulations
        // more prominent closer toward the tip of the tongue
        pct = 200 - vd->ob[0];
        if (pct < 0) {
          pct = 0;
        }
        if (pct > 100) {
          pct = 100;
        }
        offset = offset * pct / 100;

        vd->ob[1] = vs->ob[1] + offset;
    }
}

// conforms to ModelCustomGfxBuilderFunc
void N(make_tongue_gfx)(s32 index) {
    Vtx* vtxSrc;
    Vtx* vtxCopy;
    s32 numCopied;

    mdl_get_copied_vertices(VTX_COPY_1, &vtxSrc, &vtxCopy, &numCopied);
    N(add_tongue_deformation)(vtxSrc, vtxCopy, numCopied, N(TongueWiggleTime));
    gSPDisplayList(gMainGfxPos++, mdl_get_copied_gfx(VTX_COPY_1));

    N(TongueWiggleTime) += TONGUE_WIGGLE_RATE;
}

// stores the effective height offset of the tongue at a point given by Var0/Var1/Var2
// in Var0. this value is the offset from a neutral position used for collision,
// ignoring minor undulations and deformation imposed by the player.
API_CALLABLE(N(GetEffectiveTongueOffset)) {
    f32 amplitude = 2.0f * sin_rad(
        (f32)script->varTable[0] * 0.06 +
        (f32)script->varTable[2] * 0.03f +
        (f32)N(TongueWiggleTime) * 0.01f);

    f32 percent = 200.0f - (f32)script->varTable[0];
    if (percent < 0.0f){
        percent = 0.0f;
    }
    if (percent > 100.0f){
        percent = 100.0f;
    }
    amplitude = (amplitude * percent) / 100.0f;
    script->varTable[0] = EVT_FLOAT_TO_FIXED(amplitude);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_WiggleTongue) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(N(GetEffectiveTongueOffset))
        EVT_CALL(TranslateModel, TONGUE_COPY_MODEL_ID, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_sita)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartTongueWiggle) = {
    EVT_CALL(CloneModel, MODEL_sita, TONGUE_COPY_MODEL_ID)
    EVT_CALL(ParentColliderToModel, COLLIDER_sita, TONGUE_COPY_MODEL_ID)
    EVT_CALL(EnableModel, TONGUE_COPY_MODEL_ID, FALSE)
    EVT_EXEC(N(EVS_WiggleTongue))
    EVT_CALL(MakeLocalVertexCopy, VTX_COPY_1, MODEL_sita, TRUE)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(make_tongue_gfx)), NULL)
    EVT_CALL(SetModelCustomGfx, MODEL_sita, CUSTOM_GFX_1, -1)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_RETURN
    EVT_END
};
