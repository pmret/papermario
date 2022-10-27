#include "flo_07.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/todo/SpawnSunEffect.inc.c"

ApiStatus func_80240344_EC74F4(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = fx_misc_particles(3, -272.0f, 80.0f, 20.0f, 200.0f, 120.0f, 4.0f, 8, 0);

    effect->data.miscParticles->innerColor.r = 240;
    effect->data.miscParticles->innerColor.g = 240;
    effect->data.miscParticles->innerColor.b = 240;
    effect->data.miscParticles->glowColor.r = 230;
    effect->data.miscParticles->glowColor.g = 230;
    effect->data.miscParticles->glowColor.b = 240;
    return ApiStatus_DONE2;
}
