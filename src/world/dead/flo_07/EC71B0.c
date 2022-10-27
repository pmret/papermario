#include "flo_07.h"

#include "world/common/atomic/TexturePan.inc.c"

#include "world/common/todo/SpawnSunEffect.inc.c"

ApiStatus func_80240344_EC74F4(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = fx_misc_particles(3, -272.0f, 80.0f, 20.0f, 200.0f, 120.0f, 4.0f, 8, 0);

    effect->data.miscParticles->innerColor.x = 240;
    effect->data.miscParticles->innerColor.y = 240;
    effect->data.miscParticles->innerColor.z = 240;
    effect->data.miscParticles->glowColor.x = 230;
    effect->data.miscParticles->glowColor.y = 230;
    effect->data.miscParticles->glowColor.z = 240;
    return ApiStatus_DONE2;
}
