#include "common.h"
#include "ld_addrs.h"

typedef s32 TlbEntry[0x1000 / 4];
typedef TlbEntry TlbMappablePage[15];

extern TlbMappablePage D_80197000;
extern EffectTableEntry gEffectTable[135];

#define EFFECT_LOADED 1

extern void* D_80059C80;
extern Effect D_800A4000[15];
extern EffectInstance* D_800B4398[96]; //effectInstanceList
extern s32 D_801A6000;

INCLUDE_ASM(s32, "341d0", func_80058DD0);

INCLUDE_ASM(s32, "341d0", func_80058E84);

INCLUDE_ASM(s32, "341d0", func_80058F88);

INCLUDE_ASM(s32, "341d0", func_80059008);

INCLUDE_ASM(s32, "341d0", func_8005904C);

INCLUDE_ASM(s32, "341d0", func_80059310);

INCLUDE_ASM(s32, "341d0", func_800598A0);

INCLUDE_ASM(s32, "341d0", func_80059AB8);

INCLUDE_ASM(s32, "341d0", func_80059BD4);

/// Used for unbound function points in effect structs.
void stub_effect_delegate(EffectInstance* effectInst) {
}

void set_effect_pos_offset(Effect* effect, f32 x, f32 y, f32 z) {
    EffectInstanceData* instanceData = effect->instanceData;

    instanceData->pos.x = x;
    instanceData->pos.y = y;
    instanceData->pos.z = z;
}

void clear_effect_data(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800A4000); i++) {
        D_800A4000[i].flags = 0;
    }

    for (i = 0; i < ARRAY_COUNT(D_800B4398); i++) {
        D_800B4398[i] = 0;
    }

    osUnmapTLBAll();
    osMapTLB(0x10, NULL, _325AD0_VRAM, (s32)&D_801A6000 & 0xFFFFFF, -1, -1);
    dma_copy(_325AD0_ROM_START, _325AD0_ROM_END, _325AD0_VRAM);
}

void func_80059D48(void) {
}

INCLUDE_ASM(s32, "341d0", update_effects);

s32 render_effects_world(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800B4398); i++) {
        if ((D_800B4398[i] != NULL) && (D_800B4398[i]->flags & 1) && (D_800B4398[i]->flags & 8)) {
            if (gGameStatusPtr->isBattle) {
                if (D_800B4398[i]->flags & 4) {
                    D_800B4398[i]->effect->renderWorld(D_800B4398[i]);
                }
            } else if (!(D_800B4398[i]->flags & 4)) {
                D_800B4398[i]->effect->renderWorld(D_800B4398[i]);
            }
        }
    }
}

INCLUDE_ASM(s32, "341d0", render_effects_UI);

EffectInstance* func_8005A2BC(EffectBlueprint* effectBp) {
    EffectInstance* newEffectInst;
    Effect* curEffect;
    s32 i;

    // Search for an unused instance
    for (i = 0; i < ARRAY_COUNT(D_800B4398); i++) {
        if (D_800B4398[i] == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(D_800B4398));

    // Allocate space for the new instance
    D_800B4398[i] = newEffectInst = general_heap_malloc(sizeof(EffectInstance));
    ASSERT(newEffectInst != NULL);

    curEffect = &D_800A4000[0];
    newEffectInst->effectIndex = effectBp->effectIndex;
    newEffectInst->flags = 1;

    // Look for a loaded effect of the proper index
    for (i = 0; i < ARRAY_COUNT(D_800A4000); i++) {
        if ((curEffect->flags & EFFECT_LOADED) && (curEffect->effectIndex == effectBp->effectIndex)) {
            break;
        }
        curEffect++;
    }

    ASSERT(i < ARRAY_COUNT(D_800A4000));

    // If this is the first new instance of the effect, initialize the function pointers
    if (curEffect->instanceCounter == 0) {
        curEffect->update = effectBp->update;
        if (curEffect->update == NULL) {
            curEffect->renderWorld = stub_effect_delegate;
        }

        curEffect->renderWorld = effectBp->renderWorld;
        if (curEffect->unk_18 == NULL) {
            curEffect->unk_18 = stub_effect_delegate;
        }

        curEffect->unk_18 = effectBp->unk_14;
        if (curEffect->unk_18 == NULL) {
            curEffect->unk_18 = stub_effect_delegate;
        }
    }

    curEffect->instanceCounter++;
    newEffectInst->effect = curEffect;

    if (effectBp->init != NULL) {
        effectBp->init(newEffectInst);
    }

    if (gGameStatusPtr->isBattle) {
        newEffectInst->flags |= 4;
    }
    return newEffectInst;
}

void remove_effect(EffectInstance* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800B4398); i++) {
        if (D_800B4398[i] == arg0) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(D_800B4398));

    if (arg0->data == NULL) {
        general_heap_free(arg0);
        D_800B4398[i] = NULL;
        return;
    }

    general_heap_free(arg0->data);
    general_heap_free(arg0);
    D_800B4398[i] = NULL;
}

void remove_all_effects(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800B4398); i++) {
        EffectInstance* temp2 = D_800B4398[i];

        if (temp2 != NULL && temp2->flags & 4) {
            if (temp2->data != NULL) {
                general_heap_free(temp2->data);
            }
            general_heap_free(temp2);
            D_800B4398[i] = NULL;
        }
    }
}

s32 load_effect(s32 effectIndex) {
    EffectTableEntry* effectTable = &gEffectTable[0];
    EffectTableEntry* effectEntry;
    Effect* curEffect;
    TlbMappablePage* tlbMappablePages;
    s32 i;

    effectEntry = &effectTable[effectIndex];

    // Look for a loaded effect matching the desired index
    for (i = 0, curEffect = &D_800A4000[0]; i < ARRAY_COUNT(D_800A4000); i++) {
        if ((curEffect->flags & EFFECT_LOADED) && (curEffect->effectIndex == effectIndex)) {
            break;
        }
        curEffect++;
    }

    // If an effect was found within the table, initialize it and return
    if (i < ARRAY_COUNT(D_800A4000)) {
        curEffect->effectIndex = effectIndex;
        curEffect->instanceCounter = 0;
        curEffect->flags = EFFECT_LOADED;
        return 1;
    }

    // If a loaded effect wasn't found, look for the first empty space
    for (i = 0, curEffect = &D_800A4000[0]; i < ARRAY_COUNT(D_800A4000); i++) {
        if (!(curEffect->flags & EFFECT_LOADED)) {
            break;
        }
        curEffect++;
    }

    // If no empty space was found, panic
    ASSERT(i < ARRAY_COUNT(D_800A4000));

    // Map space for the effect
    tlbMappablePages = &D_80197000;
    osMapTLB(i, 0, effectEntry->dmaDest, (s32)((*tlbMappablePages)[i]) & 0xFFFFFF, -1, -1);

    // Copy the effect into the newly mapped space
    dma_copy(effectEntry->dmaStart, effectEntry->dmaEnd, effectEntry->dmaDest);

    // If there's extra data the effect normally loads, allocate space and copy into the new space
    if (effectEntry->unkStartRom != NULL) {
        void* effectDataBuf = general_heap_malloc(effectEntry->unkEndRom - effectEntry->unkStartRom);
        curEffect->unk_1C = effectDataBuf;
        ASSERT(effectDataBuf != NULL);
        dma_copy(effectEntry->unkStartRom, effectEntry->unkEndRom, curEffect->unk_1C);
    }

    // Initialize the newly loaded effect data
    curEffect->effectIndex = effectIndex;
    curEffect->instanceCounter = 0;
    curEffect->flags = EFFECT_LOADED;
    return 1;
}
