#include "common.h"
#include "ld_addrs.h"

typedef s32 TlbEntry[0x1000 / 4];
typedef TlbEntry TlbMappablePage[15];

extern TlbMappablePage D_80197000;
extern EffectTableEntry gEffectTable[135];

#define EFFECT_LOADED 1

extern void* D_80059C80;
extern EffectGraphics gEffectGraphicsData[15];
extern EffectInstance* gEffectInstances[96];
extern s32 D_801A6000;

#define FX_MAIN(name) void name(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 x, f32 y, f32 z);
#define FX_ENTRY(name, gfx_name) { fx_##name##_main, effect_##name##_ROM_START, effect_##name##_ROM_END, \
                                   effect_##name##_VRAM, gfx_name##_ROM_START, gfx_name##_ROM_END }
#define NULL_ENTRY { NULL, NULL, NULL, NULL, NULL, NULL }

FX_MAIN(fx_1_main);
FX_MAIN(fx_1_main);
FX_MAIN(fx_6_main);
FX_MAIN(fx_7_main);
FX_MAIN(fx_8_main);
FX_MAIN(fx_9_main);
FX_MAIN(fx_10_main);
FX_MAIN(fx_11_main);
FX_MAIN(fx_12_main);
FX_MAIN(fx_13_main);
FX_MAIN(fx_14_main);
FX_MAIN(fx_15_main);
FX_MAIN(fx_16_main);
FX_MAIN(fx_17_main);
FX_MAIN(fx_18_main);
FX_MAIN(fx_19_main);
FX_MAIN(fx_20_main);
FX_MAIN(fx_21_main);
FX_MAIN(fx_22_main);
FX_MAIN(fx_23_main);
FX_MAIN(fx_24_main);
FX_MAIN(fx_25_main);
FX_MAIN(fx_26_main);
FX_MAIN(fx_27_main);
FX_MAIN(fx_28_main);
FX_MAIN(fx_29_main);
FX_MAIN(fx_30_main);
FX_MAIN(fx_31_main);
FX_MAIN(fx_32_main);
FX_MAIN(fx_33_main);
FX_MAIN(fx_34_main);
FX_MAIN(fx_35_main);
FX_MAIN(fx_36_main);
FX_MAIN(fx_37_main);
FX_MAIN(fx_38_main);
FX_MAIN(fx_39_main);
FX_MAIN(fx_40_main);
FX_MAIN(fx_41_main);
FX_MAIN(fx_43_main);
FX_MAIN(fx_44_main);
FX_MAIN(fx_45_main);
FX_MAIN(fx_46_main);
FX_MAIN(fx_47_main);
FX_MAIN(fx_48_main);
FX_MAIN(fx_49_main);
FX_MAIN(fx_50_main);
FX_MAIN(fx_51_main);
FX_MAIN(fx_52_main);
FX_MAIN(fx_53_main);
FX_MAIN(fx_54_main);
FX_MAIN(fx_55_main);
FX_MAIN(fx_56_main);
FX_MAIN(fx_57_main);
FX_MAIN(fx_58_main);
FX_MAIN(fx_59_main);
FX_MAIN(fx_60_main);
FX_MAIN(fx_61_main);
FX_MAIN(fx_62_main);
FX_MAIN(fx_63_main);
FX_MAIN(fx_64_main);
FX_MAIN(fx_65_main);
FX_MAIN(fx_66_main);
FX_MAIN(fx_67_main);
FX_MAIN(fx_68_main);
FX_MAIN(fx_69_main);
FX_MAIN(fx_70_main);
FX_MAIN(fx_71_main);
FX_MAIN(fx_72_main);
FX_MAIN(fx_73_main);
FX_MAIN(fx_74_main);
FX_MAIN(fx_75_main);
FX_MAIN(fx_76_main);
FX_MAIN(fx_77_main);
FX_MAIN(fx_78_main);
FX_MAIN(fx_79_main);
FX_MAIN(fx_80_main);
FX_MAIN(fx_81_main);
FX_MAIN(fx_82_main);
FX_MAIN(fx_83_main);
FX_MAIN(fx_84_main);
FX_MAIN(fx_85_main);
FX_MAIN(fx_86_main);
FX_MAIN(fx_87_main);
FX_MAIN(fx_88_main);
FX_MAIN(fx_89_main);
FX_MAIN(fx_90_main);
FX_MAIN(fx_91_main);
FX_MAIN(fx_92_main);
FX_MAIN(fx_93_main);
FX_MAIN(fx_94_main);
FX_MAIN(fx_95_main);
FX_MAIN(fx_96_main);
FX_MAIN(fx_97_main);
FX_MAIN(fx_98_main);
FX_MAIN(fx_99_main);
FX_MAIN(fx_100_main);
FX_MAIN(fx_101_main);
FX_MAIN(fx_102_main);
FX_MAIN(fx_103_main);
FX_MAIN(fx_104_main);
FX_MAIN(fx_105_main);
FX_MAIN(fx_107_main);
FX_MAIN(fx_108_main);
FX_MAIN(fx_109_main);
FX_MAIN(fx_110_main);
FX_MAIN(fx_111_main);
FX_MAIN(fx_112_main);
FX_MAIN(fx_113_main);
FX_MAIN(fx_114_main);
FX_MAIN(fx_115_main);
FX_MAIN(fx_116_main);
FX_MAIN(fx_117_main);
FX_MAIN(fx_119_main);
FX_MAIN(fx_120_main);
FX_MAIN(fx_121_main);
FX_MAIN(fx_122_main);
FX_MAIN(fx_123_main);
FX_MAIN(fx_124_main);
FX_MAIN(fx_125_main);
FX_MAIN(fx_126_main);
FX_MAIN(fx_127_main);
FX_MAIN(fx_128_main);
FX_MAIN(fx_129_main);
FX_MAIN(fx_130_main);
FX_MAIN(fx_131_main);
FX_MAIN(fx_132_main);
FX_MAIN(fx_133_main);
FX_MAIN(fx_134_main);

EffectTableEntry gEffectTable[] = {
    NULL_ENTRY, // 0
    FX_ENTRY(1, _326410), // 1
    NULL_ENTRY, // 2
    NULL_ENTRY, // 3
    NULL_ENTRY, // 4
    NULL_ENTRY, // 5
    FX_ENTRY(6, _328EA0), // 6
    FX_ENTRY(7, _328EA0), // 7
    FX_ENTRY(8, _32CEC0), // 8
    FX_ENTRY(9, _32CEC0), // 9
    FX_ENTRY(10, _32EC50), // 10
    FX_ENTRY(11, _32EC50), // 11
    FX_ENTRY(12, _32FB50), // 12
    FX_ENTRY(13, _330460), // 13
    FX_ENTRY(14, _330F00), // 14
    FX_ENTRY(15, _3326A0), // 15
    FX_ENTRY(16, _334C70), // 16
    FX_ENTRY(17, _337FC0), // 17
    FX_ENTRY(18, _339F60), // 18
    FX_ENTRY(19, _33BBD0), // 19
    FX_ENTRY(20, _33D610), // 20
    FX_ENTRY(21, _33F000), // 21
    FX_ENTRY(22, _340880), // 22
    FX_ENTRY(23, _328EA0), // 23
    FX_ENTRY(24, _343040), // 24
    FX_ENTRY(25, _343F70), // 25
    FX_ENTRY(26, _3451E0), // 26
    FX_ENTRY(27, _345B40), // 27
    FX_ENTRY(28, _34E770), // 28
    FX_ENTRY(29, _328EA0), // 29
    FX_ENTRY(30, _350220), // 30
    FX_ENTRY(31, _352CE0), // 31
    FX_ENTRY(32, _353BB0), // 32
    FX_ENTRY(33, _343040), // 33
    FX_ENTRY(34, _337FC0), // 34
    FX_ENTRY(35, _356530), // 35
    FX_ENTRY(36, _3573A0), // 36
    FX_ENTRY(37, _3593B0), // 37
    FX_ENTRY(38, _35A5E0), // 38
    FX_ENTRY(39, _328EA0), // 39
    FX_ENTRY(40, _35C550), // 40
    FX_ENTRY(41, _35D510), // 41
    NULL_ENTRY, // 42
    FX_ENTRY(43, _33D610), // 43
    FX_ENTRY(44, _35F0E0), // 44
    FX_ENTRY(45, _360A30), // 45
    FX_ENTRY(46, _361670), // 46
    FX_ENTRY(47, _362C50), // 47
    FX_ENTRY(48, _3638C0), // 48
    FX_ENTRY(49, _364C00), // 49
    FX_ENTRY(50, _3659B0), // 50
    FX_ENTRY(51, _366D60), // 51
    FX_ENTRY(52, _36AEE0), // 52
    FX_ENTRY(53, _36DF90), // 53
    FX_ENTRY(54, _36ED60), // 54
    FX_ENTRY(55, _3733E0), // 55
    FX_ENTRY(56, _337FC0), // 56
    FX_ENTRY(57, _375510), // 57
    FX_ENTRY(58, _337FC0), // 58
    FX_ENTRY(59, _377F80), // 59
    FX_ENTRY(60, _37ADD0), // 60
    FX_ENTRY(61, _37D180), // 61
    FX_ENTRY(62, _37D9D0), // 62
    FX_ENTRY(63, _3803A0), // 63
    FX_ENTRY(64, _381E00), // 64
    FX_ENTRY(65, _3863B0), // 65
    FX_ENTRY(66, _37D9D0), // 66
    FX_ENTRY(67, _38A350), // 67
    FX_ENTRY(68, _38BBA0), // 68
    FX_ENTRY(69, _38D070), // 69
    FX_ENTRY(70, _38E990), // 70
    FX_ENTRY(71, _38F710), // 71
    {fx_72_main, effect_72_ROM_START, effect_72_ROM_END, effect_72_VRAM, 0x003903D0, 0x00391D30 }, // 72
    FX_ENTRY(73, _392440), // 73
    FX_ENTRY(74, _3930A0), // 74
    FX_ENTRY(75, _394670), // 75
    FX_ENTRY(76, _3960F0), // 76
    FX_ENTRY(77, _397040), // 77
    FX_ENTRY(78, _398BC0), // 78
    FX_ENTRY(79, _3A0D60), // 79
    FX_ENTRY(80, _3A2440), // 80
    FX_ENTRY(81, _3A33D0), // 81
    FX_ENTRY(82, _3A4320), // 82
    FX_ENTRY(83, _3A5BE0), // 83
    FX_ENTRY(84, _3A77A0), // 84
    FX_ENTRY(85, _3AB030), // 85
    FX_ENTRY(86, _3AF700), // 86
    FX_ENTRY(87, _3B2D90), // 87
    FX_ENTRY(88, _3B46A0), // 88
    FX_ENTRY(89, _3B5340), // 89
    FX_ENTRY(90, _3B6BF0), // 90
    FX_ENTRY(91, _3B78D0), // 91
    FX_ENTRY(92, _3B8860), // 92
    FX_ENTRY(93, _3B9A70), // 93
    FX_ENTRY(94, _3BAEA0), // 94
    FX_ENTRY(95, _3BCA90), // 95
    FX_ENTRY(96, _3BD9A0), // 96
    FX_ENTRY(97, _3C1BA0), // 97
    FX_ENTRY(98, _3CB890), // 98
    FX_ENTRY(99, _3CD6E0), // 99
    FX_ENTRY(100, _3CFAF0), // 100
    FX_ENTRY(101, _3D11E0), // 101
    FX_ENTRY(102, _3D2580), // 102
    FX_ENTRY(103, _3D3930), // 103
    FX_ENTRY(104, _3593B0), // 104
    FX_ENTRY(105, _3D4E90), // 105
    NULL_ENTRY, // 106
    FX_ENTRY(107, _3D5F30), // 107
    FX_ENTRY(108, _3D7040), // 108
    FX_ENTRY(109, _3D7770), // 109
    FX_ENTRY(110, _3D80C0), // 110
    FX_ENTRY(111, _3D9100), // 111
    FX_ENTRY(112, _3DBF40), // 112
    FX_ENTRY(113, _3DCD50), // 113
    FX_ENTRY(114, _3DEE60), // 114
    FX_ENTRY(115, _3E12D0), // 115
    FX_ENTRY(116, _3E1CD0), // 116
    FX_ENTRY(117, _3E2960), // 117
    NULL_ENTRY, // 118
    FX_ENTRY(119, _3E5350), // 119
    FX_ENTRY(120, _3E5F30), // 120
    { fx_121_main, effect_121_ROM_START, effect_121_ROM_END, effect_121_VRAM, 0x3EBE60, 0x3F83F0 }, // 121
    FX_ENTRY(122, _3F8CC0), // 122
    { fx_123_main, effect_123_ROM_START, effect_123_ROM_END, effect_123_VRAM, 0x3FA4B0, 0x3FEAE0 }, // 123
    FX_ENTRY(124, _3FF250), // 124
    { fx_125_main, effect_125_ROM_START, effect_125_ROM_END, effect_125_VRAM, 0x3FA4B0, 0x3FEAE0 }, // 125
    FX_ENTRY(126, _403BF0), // 126
    { fx_127_main, effect_127_ROM_START, effect_127_ROM_END, effect_127_VRAM, 0x404F40, 0x406B40 }, // 127
    FX_ENTRY(128, _407080), // 128
    FX_ENTRY(129, _40A1C0), // 129
    FX_ENTRY(130, _40BBA0), // 130
    FX_ENTRY(131, _40D290), // 131
    FX_ENTRY(132, _337FC0), // 132
    FX_ENTRY(133, _413FA0), // 133
    FX_ENTRY(134, _415060), // 134
};

s32 D_8007FEB8[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000008, 0x00000005, 0x00000003, 0x00000004,
    0x0000000D, 0x0000003C, 0x00000000, 0x00000200, 0x00000000, 0x00000000,
    0x00000003, 0x00000000,
};

/// Used for unbound function points in effect structs.
void stub_effect_delegate(EffectInstance* effectInst) {
}

void set_effect_pos_offset(EffectGraphics* effect, f32 x, f32 y, f32 z) {
    EffectInstanceData* instanceData = effect->freeDelay;

    instanceData->pos.x = x;
    instanceData->pos.y = y;
    instanceData->pos.z = z;
}

void clear_effect_data(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        gEffectGraphicsData[i].flags = 0;
    }

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        gEffectInstances[i] = 0;
    }

    osUnmapTLBAll();
    osMapTLB(0x10, NULL, _325AD0_VRAM, (s32)&D_801A6000 & 0xFFFFFF, -1, -1);
    dma_copy(_325AD0_ROM_START, _325AD0_ROM_END, _325AD0_VRAM);
}

void func_80059D48(void) {
}

// The third loop is doing some negative reference bs
#ifdef NON_MATCHING
void update_effects(void) {
    EffectGraphics* effectGraphics;
    s32 i;

    if (!(gOverrideFlags & 0xC00)) {
        for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
            effectGraphics = &gEffectGraphicsData[i];

            if (effectGraphics->flags & FX_GRAPHICS_ENABLED) {
                if (!(effectGraphics->flags & FX_GRAPHICS_2)) {
                    effectGraphics->flags |= FX_GRAPHICS_2;
                    effectGraphics->freeDelay = 3;
                }
            }
        }

        for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
            EffectInstance* effectInstance = gEffectInstances[i];

            if (effectInstance != NULL && (effectInstance->flags & 1)) {
                effectInstance->effect->flags &= ~0x2;

                if (gGameStatusPtr->isBattle) {
                    if (effectInstance->flags & 4) {
                        effectInstance->effect->update(effectInstance);
                        effectInstance->flags |= 8;
                    }
                } else {
                    if (!(effectInstance->flags & 4)) {
                        effectInstance->effect->update(effectInstance);
                        effectInstance->flags |= 8;
                    }
                }
            }
        }

        for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
            effectGraphics = &gEffectGraphicsData[i];

            if (effectGraphics->flags & FX_GRAPHICS_ENABLED) {
                if (effectGraphics->flags & FX_GRAPHICS_2) {
                    if (effectGraphics->freeDelay != 0) {
                        effectGraphics->freeDelay--;
                    } else {
                        if (effectGraphics->data[0] != NULL) {
                            general_heap_free(effectGraphics->data);
                            effectGraphics->data[0] = NULL;
                        }
                        effectGraphics->flags = FX_GRAPHICS_DISABLED;
                        osUnmapTLB(i);
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM(s32, "341d0", update_effects);
#endif

s32 render_effects_world(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] != NULL && gEffectInstances[i]->flags & 1 && gEffectInstances[i]->flags & 8) {
            if (gGameStatusPtr->isBattle) {
                if (gEffectInstances[i]->flags & 4) {
                    gEffectInstances[i]->effect->renderWorld(gEffectInstances[i]);
                }
            } else {
                if (!(gEffectInstances[i]->flags & 4)) {
                    gEffectInstances[i]->effect->renderWorld(gEffectInstances[i]);
                }
            }
        }
    }
}

void render_effects_UI(void) {
    s32 cond = TRUE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        EffectInstance* effectInstance = gEffectInstances[i];

        if (effectInstance != NULL) {
            if (effectInstance->flags & 1) {
                if (effectInstance->flags & 8) {
                    void (*renderUI)(EffectInstance* effectInst);

                    if (gGameStatusPtr->isBattle && !(effectInstance->flags & 4)) {
                        continue;
                    }

                    if (!gGameStatusPtr->isBattle && effectInstance->flags & 4) {
                        continue;
                    }

                    renderUI = effectInstance->effect->renderUI;
                    if (renderUI != stub_effect_delegate) {
                        if (cond) {
                            Camera* camera = &gCameras[gCurrentCameraID];

                            gDPPipeSync(gMasterGfxPos++);
                            gSPViewport(gMasterGfxPos++, &camera->viewport);
                            gSPClearGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG |
                                                G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD |
                                                G_SHADING_SMOOTH | G_CLIPPING | 0x40F9FA);
                            gSPSetGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
                            gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE,
                                              camera->viewportStartX,
                                              camera->viewportStartY,
                                              camera->viewportStartX + camera->viewportW,
                                              camera->viewportStartY + camera->viewportH);
                            gSPClipRatio(gMasterGfxPos++, FRUSTRATIO_2);

                            cond = FALSE;
                            if (!(camera->flags & 0x10)) {
                                gSPPerspNormalize(gMasterGfxPos++, camera->perspNorm);
                                gSPMatrix(gMasterGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCameraID],
                                          G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
                            }
                        }

                        renderUI(effectInstance);
                    }
                }
            }
        }
    }
}

EffectInstance* func_8005A2BC(EffectBlueprint* effectBp) {
    EffectInstance* newEffectInst;
    EffectGraphics* curEffect;
    s32 i;

    // Search for an unused instance
    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gEffectInstances));

    // Allocate space for the new instance
    gEffectInstances[i] = newEffectInst = general_heap_malloc(sizeof(EffectInstance));
    ASSERT(newEffectInst != NULL);

    curEffect = &gEffectGraphicsData[0];
    newEffectInst->effectIndex = effectBp->effectIndex;
    newEffectInst->flags = 1;

    // Look for a loaded effect of the proper index
    for (i = 0; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if ((curEffect->flags & EFFECT_LOADED) && (curEffect->effectIndex == effectBp->effectIndex)) {
            break;
        }
        curEffect++;
    }

    ASSERT(i < ARRAY_COUNT(gEffectGraphicsData));

    // If this is the first new instance of the effect, initialize the function pointers
    if (curEffect->instanceCounter == 0) {
        curEffect->update = effectBp->update;
        if (curEffect->update == NULL) {
            curEffect->renderWorld = stub_effect_delegate;
        }

        curEffect->renderWorld = effectBp->renderWorld;
        if (curEffect->renderUI == NULL) {
            curEffect->renderUI = stub_effect_delegate;
        }

        curEffect->renderUI = effectBp->unk_14;
        if (curEffect->renderUI == NULL) {
            curEffect->renderUI = stub_effect_delegate;
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

void remove_effect(EffectInstance* effectInstsance) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        if (gEffectInstances[i] == effectInstsance) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gEffectInstances));

    if (effectInstsance->data == NULL) {
        general_heap_free(effectInstsance);
        gEffectInstances[i] = NULL;
    } else {
        general_heap_free(effectInstsance->data);
        general_heap_free(effectInstsance);
        gEffectInstances[i] = NULL;
    }
}

void remove_all_effects(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gEffectInstances); i++) {
        EffectInstance* effect = gEffectInstances[i];

        if (effect != NULL && effect->flags & 4) {
            if (effect->data != NULL) {
                general_heap_free(effect->data);
            }
            general_heap_free(effect);
            gEffectInstances[i] = NULL;
        }
    }
}

s32 load_effect(s32 effectIndex) {
    EffectTableEntry* effectEntry = &gEffectTable[effectIndex];
    EffectGraphics* curEffect;
    TlbMappablePage* tlbMappablePages;
    s32 i;

    // Look for a loaded effect matching the desired index
    for (i = 0, curEffect = &gEffectGraphicsData[0]; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if (curEffect->flags & EFFECT_LOADED && curEffect->effectIndex == effectIndex) {
            break;
        }
        curEffect++;
    }

    // If an effect was found within the table, initialize it and return
    if (i < ARRAY_COUNT(gEffectGraphicsData)) {
        curEffect->effectIndex = effectIndex;
        curEffect->instanceCounter = 0;
        curEffect->flags = EFFECT_LOADED;
        return 1;
    }

    // If a loaded effect wasn't found, look for the first empty space
    for (i = 0, curEffect = &gEffectGraphicsData[0]; i < ARRAY_COUNT(gEffectGraphicsData); i++) {
        if (!(curEffect->flags & EFFECT_LOADED)) {
            break;
        }
        curEffect++;
    }

    // If no empty space was found, panic
    ASSERT(i < ARRAY_COUNT(gEffectGraphicsData));

    // Map space for the effect
    tlbMappablePages = &D_80197000;
    osMapTLB(i, 0, effectEntry->dmaDest, (s32)((*tlbMappablePages)[i]) & 0xFFFFFF, -1, -1);

    // Copy the effect into the newly mapped space
    dma_copy(effectEntry->dmaStart, effectEntry->dmaEnd, effectEntry->dmaDest);

    // If there's extra data the effect normally loads, allocate space and copy into the new space
    if (effectEntry->graphicsDmaStart != NULL) {
        void* effectDataBuf = general_heap_malloc(effectEntry->graphicsDmaEnd - effectEntry->graphicsDmaStart);
        curEffect->data = effectDataBuf;
        ASSERT(effectDataBuf != NULL);
        dma_copy(effectEntry->graphicsDmaStart, effectEntry->graphicsDmaEnd, curEffect->data);
    }

    // Initialize the newly loaded effect data
    curEffect->effectIndex = effectIndex;
    curEffect->instanceCounter = 0;
    curEffect->flags = EFFECT_LOADED;
    return 1;
}
