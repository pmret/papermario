#include "common.h"
#include "effects_internal.h"

void ice_pillar_init(EffectInstance* effect);
void ice_pillar_update(EffectInstance* effect);
void ice_pillar_render(EffectInstance* effect);
void ice_pillar_appendGfx(void* effect);

extern Gfx D_09001000_40B1C0[];
extern Gfx D_090011A8_40B368[];
extern Gfx D_090011C8_40B388[];
extern Gfx D_090011E8_40B3A8[];
extern Gfx D_09001208_40B3C8[];

Gfx* D_E011E7F0[] = { D_090011A8_40B368, D_090011C8_40B388, D_090011E8_40B3A8, D_09001208_40B3C8 };
Gfx* D_E011E800[] = { D_09001000_40B1C0 };

EffectInstance* ice_pillar_main(s32 arg0, f32 x, f32 y, f32 z, f32 scale, s32 arg5) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    IcePillarFXData* data;
    s32 numParts = 1;

    effectBp.init = ice_pillar_init;
    effectBp.update = ice_pillar_update;
    effectBp.renderWorld = ice_pillar_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_ICE_PILLAR;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.icePillar = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = arg0;
    data->lifeTime = 0;
    if (arg5 <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = arg5;
    }

    data->prim.a = 255;
    data->pos.x = x;
    data->pos.y = y;
    data->pos.z = z;
    data->scale = scale;
    data->prim.r = 255;
    data->prim.g = 255;
    data->prim.b = 255;
    data->env.r = 240;
    data->env.g = 255;
    data->env.b = 255;
    data->env.a = 255;
    data->unk_24 = data->unk_25 = 0;

    shim_load_effect(EFFECT_MISC_PARTICLES);
    data->miscParticles = misc_particles_main(1, x, y + 10.0f, z, 32.0f, 30.0f, scale, 4, 0);

    shim_load_effect(EFFECT_COLD_BREATH);
    return effect;
}

void ice_pillar_init(EffectInstance* effect) {
}

void ice_pillar_update(EffectInstance* effect) {
    IcePillarFXData* data = effect->data.icePillar;
    s32 timeLeft;
    s32 lifeTime;
    s32 i;
    
    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->timeLeft = 16;
    }

    if (data->timeLeft < 1000) {
        data->timeLeft--;
    }

    data->lifeTime++;

    if (data->timeLeft < 0) {
        shim_load_effect(EFFECT_ICE_SHARD);
        
        for (i = 0; i < 20; i++) {
            EffectInstance* iceShard;

            iceShard = ice_shard_main(
                (i - ((i / 2) * 2)) + 2, 
                (data->pos.x + shim_rand_int(20)) - 10.0f, 
                data->pos.y + (shim_rand_int(40) * data->scale), 
                data->pos.z + 3.0f, 
                (data->scale * ((shim_rand_int(10) * 0.7 * 0.1) + 0.3)), 
                i + 30
            );
            iceShard->data.iceShard->animFrame = shim_rand_int(10) * 0.1;
            iceShard->data.iceShard->animRate = (shim_rand_int(30) * 0.01) + 0.1;
            iceShard->data.iceShard->rotation = shim_rand_int(359);
            iceShard->data.iceShard->angularVel = shim_rand_int(20);
            iceShard->data.iceShard->vel.x = shim_rand_int(10) - 5;
            iceShard->data.iceShard->vel.y = shim_rand_int(10) - 5;
            iceShard->data.iceShard->vel.z = 0;
            iceShard->data.iceShard->gravAccel = -0.1f;
        }
        shim_remove_effect(data->miscParticles);
        shim_remove_effect(effect);
        return;
    }

    timeLeft = data->timeLeft;
    lifeTime = data->lifeTime;

    data->unk_25--;
    if (data->unk_25 < 0) {
        data->unk_25 = shim_rand_int(60) + 8;
    }

    if (data->unk_25 < 8) {
        data->unk_24 = data->unk_25 / 2;
    } else {
        data->unk_24 = 0;
    }

    if (timeLeft > 16 && (lifeTime % 16) == 0) {
        shim_load_effect(EFFECT_COLD_BREATH);
        cold_breath_main(2, data->pos.x, data->pos.y + (data->scale * 40.0f), data->pos.z, data->scale, 30);
    }
    data->miscParticles->data.miscParticles->pos.x = data->pos.x;
    data->miscParticles->data.miscParticles->pos.y = data->pos.y + 10.0f;
    data->miscParticles->data.miscParticles->pos.z = data->pos.z;
}

void ice_pillar_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = ice_pillar_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 5;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_REFLECT_FLOOR;
}

void ice_pillar_appendGfx(void* effect) {
    IcePillarFXData* data = ((EffectInstance*)effect)->data.icePillar;
    s32 alpha = data->prim.a;
    Matrix4f sp10, sp50;
    Camera* camera;
    
    gDPPipeSync(gMasterGfxPos++);
    gSPSegment(gMasterGfxPos++, 0x09, VIRTUAL_TO_PHYSICAL(((EffectInstance*)effect)->graphics->data));

    camera = &gCameras[gCurrentCameraID];
    shim_guTranslateF(sp10, data->pos.x, data->pos.y, data->pos.z);
    shim_guScaleF(sp50, data->scale, data->scale, data->scale);
    shim_guMtxCatF(sp50, sp10, sp10);
    shim_guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], 
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gMasterGfxPos++, camera->unkMatrix, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, data->prim.r, data->prim.g, data->prim.b, alpha);
    gDPSetEnvColor(gMasterGfxPos++, data->env.r, data->env.g, data->env.b, data->env.a);
    gSPDisplayList(gMasterGfxPos++, D_E011E800[0]);
    gSPDisplayList(gMasterGfxPos++, D_E011E7F0[data->unk_24]);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
