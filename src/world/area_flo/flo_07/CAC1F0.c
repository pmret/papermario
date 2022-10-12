#include "flo_07.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/todo/SpawnSunEffect.inc.c"

ApiStatus N(func_80240344_CAC534)(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = fx_misc_particles(3, -272.0f, 80.0f, 20.0f, 200.0f, 120.0f, 4.0f, 8, 0);

    effect->data.miscParticles->unk_38 = 240;
    effect->data.miscParticles->unk_3C = 240;
    effect->data.miscParticles->unk_40 = 240;
    effect->data.miscParticles->unk_48 = 230;
    effect->data.miscParticles->unk_4C = 230;
    effect->data.miscParticles->unk_50 = 240;
    return ApiStatus_DONE2;
}
