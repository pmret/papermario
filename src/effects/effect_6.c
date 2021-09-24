#include "common.h"
#include "effects_internal.h"

void fx_6_update(EffectInstance* effect);
void fx_6_renderWorld(EffectInstance* effect);

s32 D_E000CC10[] = { 0x09002B20, 0x09002B40, 0x09002B60, 0x09002B60, 0x09002B60 };

s32 D_E000CC24[] = { 0x09002780, 0x09002868, 0x09002950, 0x09002A38, 0x09002A38 };

s32 D_E000CC38[] = { 0x0001021A, 0x031B041C, 0x05153546, 0x4646FF00 };

s32 D_E000CC48[] = { 0x0001021A, 0x031B041C, 0x051D0616, 0x26475767, 0xFF000000 };

s32 D_E000CC5C[] = { 0x00081018, 0x20283038, 0x01091119, 0x21293139, 0x02020A0A, 0x12121A1A, 0x22222A2A, 0x32323A3A,
                     0x03030B0B, 0x13131B1B, 0x23232B2B, 0x33333B3B, 0x04040C0C, 0x14141C1C, 0x24242C2C, 0x34343C3C,
                     0x05050D0D, 0x15151D1D, 0x25252D2D, 0x35353D3D, 0x0606060E, 0x0E0E1616, 0x161E1E1E, 0x2626262E,
                     0x2E2E3636, 0x363E3E3E, 0x4747474F, 0x4F4F5757, 0x575F5F5F, 0x6767676F, 0x6F6F7777, 0x777F7F7F,
                     0xFF000000 };

s32 D_E000CCE0[] = { 0x00102030, 0x01112131, 0x020A121A, 0x222A323A, 0x030B131B, 0x232B333B, 0x040C141C, 0x242C343C,
                     0x050D151D, 0x252D353D, 0x06060E16, 0x161E2626, 0x2E36363E, 0x47474F57, 0x575F6767, 0x6F77777F,
                     0xFF000000 };

s32 D_E000CD24[] = { &D_E000CC38, &D_E000CC48, &D_E000CC5C, &D_E000CCE0, 0x00000000, 0x00000000, 0x00000000 };

INCLUDE_ASM(s32, "effects/effect_6", func_E000C000);

INCLUDE_ASM(s32, "effects/effect_6", func_E000C094);

INCLUDE_ASM(s32, "effects/effect_6", func_E000C0C8);

INCLUDE_ASM(s32, "effects/effect_6", fx_6_main);
// void fx_6_main(s32 arg0, f32 x, f32 y, f32 z, f32 arg4) {
//     EffectBlueprint bp;
//     EffectInstance* temp_s0;
//     EffectInstanceData* temp_s1;
//     EffectInstanceData* temp_v0;
//     f32 temp_f0;
//     f32 temp_f0_2;
//     f32 temp_f0_3;
//     f32 temp_f0_4;
//     f32 temp_f0_5;
//     f32 temp_f0_6;
//     f32 temp_f0_7;
//     f32 temp_f20;
//     f32 temp_f20_2;
//     s32 temp_s2;
//     s32 temp_s2_2;
//     s32 temp_v1;
//     s32 phi_s3;
//     s32 phi_v0;
//     s8* phi_s0;
//     s32 phi_s1;
//     s32 phi_s2;
//     s32 phi_s2_2;
//     s8* phi_s0_2;
//     f32 phi_f2;
//     f32 phi_f0;
//     s32 phi_s2_3;
//     s8* phi_s0_3;
//     s32 phi_s1_2;
//     s32 phi_s2_4;

//     phi_v0 = 3;

//     switch (arg0) {
//         case 3:
//             phi_s3 = 4;
//             break;
//         case 2:
//             phi_s3 = 1;
//             break;
//         case 4:
//             phi_s3 = 9;
//             break;
//         default:
//             phi_s3 = 3;

//     }

//     bp.init = fx_6_init;
//     bp.update = fx_6_update;
//     bp.renderWorld = fx_6_renderWorld;
//     bp.unk_00 = 0;
//     bp.unk_14 = NULL;
//     bp.effectIndex = 6;

//     temp_s0 = shim_create_effect_instance(&bp);
//     temp_s0->numParts = phi_s3;
//     temp_v0 = shim_general_heap_malloc(phi_s3 * 0x44);
//     temp_s1 = temp_v0;
//     temp_s0->data = temp_s1;
//     if (temp_s1 == 0) {
// loop_10:
//         goto loop_10;
//     }
//     shim_mem_clear((s8* ) temp_s1, phi_s3 * 0x44);
//     switch (arg0) { // switch 1
//     case 0: // switch 1
//     case 1: // switch 1
//         temp_s1->unk38 = 0;
//         break;
//     case 3: // switch 1
//         phi_v0 = 2;
// block_16:
//         temp_s1->unk38 = phi_v0;
//         break;
//     case 2: // switch 1
//     case 4: // switch 1
//         goto block_16;
//     }
//     temp_s1->unk3C = 0;
//     temp_s1->unk_00 = (s16) arg0;
//     temp_s1->pos.x = x;
//     temp_s1->pos.y = y;
//     temp_s1->pos.z = z;

//     switch (arg0) { // switch 2
//         case 0: // switch 2
//         case 1: // switch 2
//             phi_s0 = &temp_s1->unk_34[0x44];
//             phi_s2 = 1;
//             if (phi_s3 > 1) {
//                 phi_s1 = 0x5A;
//                 do {
//                     phi_s0->unk-24 = -3.0f;
//                     phi_s0->unk-20 = 0.29999998f;
//                     phi_s0->unk-1C = 0;
//                     phi_s0->unk-18 = 0;
//                     phi_s0->unk-14 = 1.75f;
//                     phi_s0->unk-10 = -0.16f;
//                     phi_s0->unk-C = 0;
//                     phi_s0->unk-8 = 0;
//                     phi_s0->unk-30 = 0;
//                     phi_s0->unk-2C = 0;
//                     phi_s0->unk-28 = 4.0f;
//                     temp_f20 = shim_clamp_angle((f32) phi_s1);
//                     phi_s0->unk-4 = shim_sin_deg(temp_f20);
//                     temp_s2 = phi_s2 + 1;
//                     phi_s0->unk0 = shim_cos_deg(temp_f20);
//                     phi_s0 += 0x44;
//                     phi_s1 += 0xB4;
//                     phi_s2 = temp_s2;
//                 } while (temp_s2 < phi_s3);
//                 return;
//             }
//         default: // switch 2
//             return;
//         case 3: // switch 2
//             phi_s2_2 = 1;
//             phi_s0_2 = &temp_s1->unk_34[0x44];
//             if (phi_s3 > 1) {
//                 do {
//                     temp_v1 = phi_s2_2 - 1;
//                     if (temp_v1 != 1) {
//                         if (temp_v1 < 2) {
//                             if (temp_v1 != 0) {
//                                 phi_s2_3 = phi_s2_2 + 1;
//                             } else {
//                                 temp_f0 = -shim_sin_deg(135.0f) * 25.0f;
//                                 phi_s0_2->unk-2C = 0;
//                                 phi_s0_2->unk-30 = temp_f0;
//                                 temp_f0_2 = -shim_cos_deg(135.0f) * 25.0f;
//                                 phi_s0_2->unk-10 = -0.04f;
//                                 phi_f2 = 0.95f;
//                                 phi_f0 = temp_f0_2;
//                                 goto block_34;
//                             }
//                         } else if (temp_v1 != 2) {
//                             phi_s2_3 = phi_s2_2 + 1;
//                         } else {
//                             temp_f0_3 = -shim_sin_deg(20.0f) * 25.0f;
//                             phi_s0_2->unk-2C = 0x41200000;
//                             phi_s0_2->unk-30 = temp_f0_3;
//                             temp_f0_4 = -shim_cos_deg(20.0f) * 25.0f;
//                             phi_s0_2->unk-10 = -0.04f;
//                             phi_f2 = 0.75f;
//                             phi_f0 = temp_f0_4;
//                             goto block_34;
//                         }
//                     } else {
//                         temp_f0_5 = -shim_sin_deg(-135.0f) * 25.0f;
//                         phi_s0_2->unk-2C = 0x40800000;
//                         phi_s0_2->unk-30 = temp_f0_5;
//                         temp_f0_6 = -shim_cos_deg(-135.0f) * 25.0f;
//                         phi_s0_2->unk-10 = -0.04f;
//                         phi_f2 = 0.84999996f;
//                         phi_f0 = temp_f0_6;
//     block_34:
//                         phi_s0_2->unk-C = 0.94f;
//                         phi_s0_2->unk-14 = phi_f2;
//                         phi_s0_2->unk-28 = phi_f0;
//                         phi_s2_3 = phi_s2_2 + 1;
//                     }
//                     phi_s0_2->unk-4 = 0;
//                     phi_s0_2->unk0 = 0;
//                     phi_s2_2 = phi_s2_3;
//                     phi_s0_2 += 0x44;
//                 } while (phi_s2_3 < phi_s3);
//                 return;
//             }
//             // Duplicate return node #40. Try simplifying control flow for better match
//             return;
//         case 4: // switch 2
//             phi_s2_4 = 1;
//             if (phi_s3 > 1) {
//                 phi_s0_3 = &temp_s1->unk_34[0x44];
//                 phi_s1_2 = 0;
//                 do {
//                     phi_s0_3->unk-24 = -3.0f;
//                     phi_s0_3->unk-20 = 0.93f;
//                     phi_s0_3->unk-14 = 0;
//                     phi_s0_3->unk-10 = 0.099999994f;
//                     temp_f20_2 = arg4 + (f32) (phi_s1_2 / (s32) (phi_s3 - 1));
//                     phi_s0_3->unk-C = 0.94f;
//                     phi_s0_3->unk-8 = 0.94f;
//                     temp_f0_7 = -shim_sin_deg(temp_f20_2) * 10.0f;
//                     phi_s0_3->unk-2C = 0;
//                     phi_s0_3->unk-30 = temp_f0_7;
//                     temp_s2_2 = phi_s2_4 + 1;
//                     phi_s0_3->unk-28 = (f32) (-shim_cos_deg(temp_f20_2) * 10.0f);
//                     phi_s0_3->unk-4 = shim_sin_deg(temp_f20_2);
//                     phi_s0_3->unk0 = shim_cos_deg(temp_f20_2);
//                     phi_s0_3 += 0x44;
//                     phi_s1_2 += 0x168;
//                     phi_s2_4 = temp_s2_2;
//                 } while (temp_s2_2 < phi_s3);
//             }
//             // Duplicate return node #40. Try simplifying control flow for better match
//             return;
//     }
// }

void fx_6_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/effect_6", fx_6_update);

INCLUDE_ASM(s32, "effects/effect_6", fx_6_renderWorld);

INCLUDE_ASM(s32, "effects/effect_6", func_E000C798);
