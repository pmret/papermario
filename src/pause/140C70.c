#include "common.h"

#define pause_map_tab_places_desc_string_id 0x1D00F2

typedef struct Pause8024D930 {
    /* 0x00 */ s16 xPos;
    /* 0x02 */ s16 yPos;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x2];
    /* 0x08 */ Vec2b* unk_08;
} Pause8024D930; // Similar to PauseMapSpaces

void func_8024D930(Pause8024D930* arg0) {
    Vec2b* unk_08 = arg0->unk_08;
    s32 limit = arg0->unk_05;
    s32 x1 = D_802502B8[arg0->unk_04].xPos;
    s32 y1 = D_802502B8[arg0->unk_04].yPos;
    s32 x2 = arg0->xPos;
    s32 y2 = arg0->yPos;
    s32 xThingPrev = 0;
    s32 yThingPrev = 0;
    s32 i;

    for (i = 0; i < limit; i++) {
        s32 xThing = ((x1 - x2) * (i + 1)) / (limit + 1);
        s32 yThing = ((y1 - y2) * (i + 1)) / (limit + 1);

        unk_08[i].x = xThing - xThingPrev;
        unk_08[i].y = yThing - yThingPrev;
        xThingPrev = xThing;
        yThingPrev = yThing;
    }
}

void pause_map_draw_border_arrows(s32 imageIndex, s32 x, s32 y) {
    s32 size = 16;

    switch (imageIndex) {
        case 0:
            pause_draw_rect(x * 4, y * 4, (x + size) * 4, (y + size) * 4, 0, 0, 0, 0x400, 0x400);
            break;
        case 1:
            pause_draw_rect(x * 4, y * 4, (x + size) * 4, (y + size) * 4, 0, 0, 0x200, 0x400, 0x400);
            break;
        case 2:
            pause_draw_rect(x * 4, y * 4, (x + size) * 4, (y + size) * 4, 0, 0, 0x400, 0x400, 0x400);
            break;
        default:
            pause_draw_rect(x * 4, y * 4, (x + size) * 4, (y + size) * 4, 0, 0, 0x600, 0x400, 0x400);
            break;
    }
}

INCLUDE_ASM(s32, "pause/140C70", pause_map_draw_contents);

// extern s32 D_80250560;
// extern s32 D_802510B0;
// extern s32 D_8026F118;
// extern s32 D_8026F1B8;
// extern s32 D_8026F2A0;
// extern s32 D_8026FEE8;

// void pause_map_draw_contents(MenuPanel* tab, s32 baseX, s32 baseY, s32 width, s32 height, u8 opacity, u8 darkening);
// void pause_map_draw_contents(MenuPanel* tab, s32 baseX, s32 baseY, s32 width, s32 height, u8 opacity, u8 darkening) {
//     Gfx** sp68;
//     s32 sp64;
//     s32 sp60;
//     PauseMapSpace* sp5C;
//     s32 sp58;
//     s32 sp54;
//     s32 sp50;
//     Gfx* temp_a0_2;
//     Gfx* temp_a0_5;
//     Gfx* temp_a1;
//     Gfx* temp_a1_2;
//     Gfx* temp_a3_4;
//     Gfx* temp_t1_2;
//     Gfx* temp_v0_2;
//     Gfx* temp_v0_4;
//     Gfx* temp_v1_4;
//     Gfx* temp_v1_5;
//     Gfx* temp_v1_6;
//     Gfx* temp_v1_7;
//     s16 temp_s0;
//     s16 temp_s1;
//     s32 temp_a0_3;
//     s32 temp_a0_4;
//     s32 temp_a2;
//     s32 temp_a3;
//     s32 temp_a3_2;
//     s32 temp_a3_3;
//     s32 temp_a3_5;
//     s32 temp_hi;
//     s32 temp_s0_4;
//     s32 temp_s0_5;
//     s32 temp_s1_2;
//     s32 temp_s1_3;
//     s32 temp_s2;
//     s32 temp_s2_2;
//     s32 temp_s2_3;
//     s32 temp_s3;
//     s32 temp_s3_2;
//     s32 temp_s4;
//     s32 temp_s5;
//     s32 temp_s6;
//     s32 temp_s7;
//     s32 temp_s7_2;
//     s32 temp_t0_2;
//     s32 temp_t0_3;
//     s32 temp_t1;
//     s32 temp_t2;
//     s32 temp_t3;
//     s32 temp_v0_3;
//     s32 temp_v1_3;
//     s8 temp_s0_3;
//     u16 temp_v1_8;
//     u32 temp_hi_2;
//     u8 temp_s6_2;
//     void* temp_s0_2;
//     s32 phi_s2;
//     s32 phi_s0;
//     s32 phi_t5;
//     s32 phi_s3;
//     s32 phi_s7;
//     s32 phi_a0;
//     s32 phi_v1;
//     s32 phi_a2;
//     s32 phi_a3;
//     s32 phi_s7_2;
//     s8** phi_fp;
//     Gfx** phi_t0_2;
//     s32 phi_s3_2;
//     void* phi_s0_2;
//     s32 phi_s2_2;
//     s32 phi_s1;
//     s32 phi_a1;
//     s32 phi_s2_3;
//     s32 phi_s3_3;
//     s32 phi_s1_2;
//     s32 phi_a3_2;
//     s32 phi_t0_3;
//     s32 phi_t2;
//     s32 phi_t3;

//     temp_s6 = baseX + 0x104;
//     sp54 = (s32) pause_map_cameraY;
//     sp50 = (s32) pause_map_cameraX;
//     sp58 = sp50 * -0x20;

//     gSPDisplayList(gMasterGfxPos++, D_8026F118);

//     phi_s2 = 4;
//     phi_s0 = 0;
//     phi_s3 = 0x16;
//     phi_s7 = 0;
//     phi_s7_2 = 0;
// loop_1:
//     phi_t5 = 4;
//     if (phi_s2 >= 0x6F) {
//         phi_t5 = 0x6F - phi_s0;
//     }

//     temp_a3 = baseY + phi_s3;

//     gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 320, D_802510B0);
//     gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 40, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP,
//                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPLoadSync(gMasterGfxPos++);
//     gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, ((phi_s0 - sp54) * 4), 0x04FC, (((phi_s0 + phi_t5) - (sp54 + 1)) * 4));
//     gDPPipeSync(gMasterGfxPos++);
//     gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 40, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
//     gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 0x04FC, 0);

//     pause_draw_rect((baseX + 0x1A) * 4, temp_a3 * 4, temp_s6 * 4, (temp_a3 + phi_t5) * 4, 0, sp58, (phi_s0 - sp54) << 5, 0x400, 0x400);
//     gDPPipeSync(gMasterGfxPos++);

//     if (phi_s2 < 0x6E) {
//         temp_s7 = phi_s7 + 1;
//         phi_s2 += 4;
//         phi_s0 += 4;
//         phi_s3 += 4;
//         phi_s7 = temp_s7;
//         if (temp_s7 >= 0x3C) {

//         } else {
//             goto loop_1;
//         }
//     }


//     gMasterGfxPos = temp_a1_2 + 8;
//     temp_a1_2->words.w0 = 0xDE000000;
//     temp_a1_2->words.w1 = (u32) &D_8026F1B8;
//     temp_v1_3 = baseY + 0x16;
//     temp_a3_2 = baseY + 0x84;
//     phi_a0 = baseX + 0x1A;
//     phi_v1 = temp_v1_3;
//     phi_a2 = temp_s6;
//     phi_a3 = temp_a3_2;
//     if ((baseX + 0x1A) <= 0) {
//         phi_a0 = 1;
//     }
//     if (temp_v1_3 <= 0) {
//         phi_v1 = 1;
//     }
//     if ((temp_s6 > 0) && (temp_a3_2 > 0) && (phi_a0 < 0x13F) && (phi_v1 < 0xEF)) {
//         if (temp_s6 >= 0x13F) {
//             phi_a2 = 0x13F;
//         }
//         if (temp_a3_2 >= 0xEF) {
//             phi_a3 = 0xEF;
//         }
//         sp5C = D_802502B8;
//         sp60 = sp50 + baseX;
//         sp64 = sp54 + baseY;

//         gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, phi_a0, phi_v1, phi_a2, phi_a3);

//         phi_fp = &sp5C->areaDescription;
//         do {
//             temp_s1 = phi_fp->unk-6;
//             temp_s0 = sp5C->xPos;

//             if (evt_get_variable(NULL, phi_s7_2 + 0xF840632A) != 0) {
//                 if (phi_s7_2 != pause_map_cursorCurrentOption) {

//                     temp_a0_2->words.w0 = 0xFA000000;
//                     temp_a0_2->words.w1 = 0xDC501EFF;
//                 } else {
//                     temp_v1_5->words.w0 = 0xFA000000;
//                     temp_a0_3 = gGameStatusPtr->frameCounter * 0xA;
//                     temp_hi = MULT_HI(temp_a0_3, 0x88888889);

//                     temp_a0_4 = temp_a0_3 - ((((s32) (temp_hi + temp_a0_3) >> 6) - (temp_a0_3 >> 0x1F)) * 0x78);
//                     temp_v0_3 = (temp_a0_4 + 0x78) & 0xFF;
//                     temp_v1_5->words.w1 = (temp_v0_3 << 0x18) | (temp_v0_3 << 0x10) | ((temp_a0_4 & 0xFF) << 8) | 0xFF;
//                 }
//                 temp_s5 = sp60 + (temp_s0 + 0x1A);
//                 temp_s4 = sp64 + (temp_s1 + 0x16);
//                 pause_draw_rect((temp_s5 - 8) * 4, (temp_s4 - 8) * 4, (temp_s5 + 8) * 4, (temp_s4 + 8) * 4, 0, 0, 0, 0x400, 0x400);

//                 gDPPipeSync(gMasterGfxPos++);
//                 gDPSetPrimColor(gMasterGfxPos++, 0, 0, 230, 190, 180, 255);
//                 temp_s0_2 = phi_fp->unk0;

//                 temp_s6_2 = phi_fp->unk-3;
//                 phi_s0_2 = temp_s0_2;
//                 if (temp_s0_2 != 0) {
//                     phi_s3_2 = 0;
//                     phi_s2_2 = 0;
//                     if (temp_s6_2 != 0) {
//                         phi_s1 = 1;
//                         do {
//                             temp_s3 = phi_s3_2 + phi_s0_2->unk0;
//                             temp_s2 = phi_s2_2 + phi_s0_2->unk1;
//                             temp_a2 = temp_s5 + temp_s3;
//                             temp_a3_3 = temp_s4 + temp_s2;
//                             pause_draw_rect((temp_a2 - 8) * 4, (temp_a3_3 - 8) * 4, (temp_a2 + 8) * 4, (temp_a3_3 + 8) * 4, 1, 0, 0, 0x400, 0x400);
//                             phi_s3_2 = temp_s3;
//                             phi_s0_2 += 2;
//                             phi_s2_2 = temp_s2;
//                             phi_s1 += 1;
//                         } while (phi_s1 < (s32) temp_s6_2);
//                     }
//                 }
//             }
//             temp_s7_2 = phi_s7_2 + 1;
//             sp5C += 0x14;
//             phi_s7_2 = temp_s7_2;
//             phi_fp += 0x14;
//         } while (temp_s7_2 < 0x22);

//         temp_s2_2 = baseX + (sp50 + 0x1A);
//         temp_s1_2 = baseY + (sp54 + 0x16);
//         set_hud_element_render_pos(*D_80270700, temp_s2_2 + pause_map_marioX, (temp_s1_2 + pause_map_marioY) - 7);
//         draw_hud_element_3(*D_80270700);
//         temp_s0_3 = gPauseMenuCurrentTab;
//         if (temp_s0_3 == 6) {
//             func_80242D04(0x29, (s32) (((f32) temp_s2_2 + pause_map_cursorX) - 8.0f), (s32) ((f32) temp_s1_2 + pause_map_cursorY));
//             if (gPauseMenuCurrentTab == temp_s0_3) {
//                 temp_v1_8 = gGameStatusPtr->frameCounter;
//                 temp_hi_2 = MULTU_HI(temp_v1_8, 0xAAAAAAAB);

//                 temp_s1_3 = *(&D_80250560 + (((temp_v1_8 - ((temp_hi_2 >> 3) * 0xC)) & 0xFFFF) * 4));
//                 temp_a3_4->words.w0 = 0xDE000000;
//                 temp_a3_4->words.w1 = (u32) &D_8026F2A0;
//                 temp_s2_3 = temp_s1_3;
//                 temp_s3_2 = temp_s1_3;
//                 phi_a1 = temp_s1_3;
//                 phi_s2_3 = temp_s2_3;
//                 phi_s3_3 = temp_s3_2;
//                 phi_s1_2 = temp_s1_3;
//                 if (!(pause_map_cameraX < 0.0f)) {
//                     phi_a1 = 0;
//                 }
//                 temp_s0_4 = (baseY + ((s32) (height + ((u32) height >> 0x1F)) >> 1)) - 8;
//                 pause_map_draw_border_arrows(0, baseX - (phi_a1 - 0x1A), temp_s0_4);
//                 if (!(pause_map_cameraX > -86.0f)) {
//                     phi_s2_3 = 0;
//                 }
//                 pause_map_draw_border_arrows(1, baseX + width + (phi_s2_3 - 0x32), temp_s0_4);
//                 if (!(pause_map_cameraY < 0.0f)) {
//                     phi_s3_3 = 0;
//                 }
//                 temp_s0_5 = (baseX + (width / 2)) - 8;
//                 pause_map_draw_border_arrows(2, temp_s0_5, baseY - (phi_s3_3 - 0x18));
//                 if (!(pause_map_cameraY > -210.0f)) {
//                     phi_s1_2 = 0;
//                 }
//                 pause_map_draw_border_arrows(3, temp_s0_5, baseY + height + (phi_s1_2 - 0x2C));
//             }
//         }
//         temp_a3_5 = baseX + 0x12;
//         temp_t0_3 = baseY + 0xE;
//         temp_t2 = baseX + 0x10C;
//         temp_t3 = baseY + 0x8C;
//         phi_a3_2 = temp_a3_5;
//         phi_t0_3 = temp_t0_3;
//         phi_t2 = temp_t2;
//         phi_t3 = temp_t3;
//         if (temp_a3_5 <= 0) {
//             phi_a3_2 = 1;
//         }
//         if (temp_t0_3 <= 0) {
//             phi_t0_3 = 1;
//         }
//         if ((temp_t2 > 0) && (temp_t3 > 0) && (phi_a3_2 < 0x13F) && (phi_t0_3 < 0xEF)) {
//             if (temp_t2 >= 0x13F) {
//                 phi_t2 = 0x13F;
//             }
//             if (temp_t3 >= 0xEF) {
//                 phi_t3 = 0xEF;
//             }
//             temp_t1_2 = temp_v0_4;
//             temp_t1_2->words.w0 = (((s32) ((f32) phi_a3_2 * 4.0f) & 0xFFF) << 0xC) | (((s32) ((f32) phi_t0_3 * 4.0f) & 0xFFF) | 0xED000000);
//             temp_t1_2->words.w1 = (((s32) ((f32) phi_t2 * 4.0f) & 0xFFF) << 0xC) | ((s32) ((f32) phi_t3 * 4.0f) & 0xFFF);
//             draw_box(0, (s32) &D_8026FEE8, baseX + 0x12, baseY + 0xE, 0, 0xFA, 0x7E, (s32) opacity, (s32) darkening, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, 0, NULL, width, height, NULL);
//         }
//     }
// }

void pause_map_draw_title(s32* arg1, s32 arg2, s32 textOffsetY, s32 textOffsetX) {
    s32 stringWidth;
    s32 stringID;

    if (gPauseMenuCurrentTab == 6) {
        if (pause_map_cursorCurrentOption != -1) {
            stringWidth = get_string_width(pause_map_tab_places_desc_string_id + (pause_map_cursorCurrentOption * 3), 0);
            stringID = pause_map_tab_places_desc_string_id + (pause_map_cursorCurrentOption * 3);
            draw_string(stringID, arg2 + ((textOffsetX - stringWidth) >> 1), textOffsetY + 1, 255, 0, 0);
        }
    }
}

void pause_map_init(MenuPanel* tab) {
    s32 tempVar;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80270700); i++) {
        D_80270700[i] = create_hud_element(D_8024FA30[i]);
        set_hud_element_flags(D_80270700[i], 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(pause_map_windowBlueprints); i++) {
        pause_map_windowBlueprints[i].tab = tab;
    }

    setup_pause_menu_tab(pause_map_windowBlueprints, ARRAY_COUNT(pause_map_windowBlueprints));
    pause_map_cursorCurrentOption = -1;
    D_80270724 = 0;
    pause_map_cursorCurrentOptionCopy = -1;
    tempVar = evt_get_variable(0, EVT_SAVE_VAR(425));

    for (i = 0; i < EVT_SAVE_FLAG_PLACES_VISITED_TOTAL; i++) {
        if (D_802502B8[i].id == tempVar) {
            break;
        }
    }

    if (i < EVT_SAVE_FLAG_PLACES_VISITED_TOTAL) {
        pause_map_marioX = D_802502B8[i].xPos;
        pause_map_marioY = D_802502B8[i].yPos;
    } else {
        pause_map_marioX = 0;
        pause_map_marioY = 0;
    }
    pause_map_cursorX = pause_map_marioX;
    pause_map_cursorY = pause_map_marioY;

    pause_map_cameraX = 0.0f;
    pause_map_cameraY = 0.0f;
    pause_map_cameraX -= (s32)(pause_map_cursorX + pause_map_cameraX - D_80270080);
    pause_map_cameraY -= (s32)(pause_map_cursorY + pause_map_cameraY - D_80270088);

    if (pause_map_cameraX > 0)  {
        pause_map_cameraX = 0;
    }
    if (pause_map_cameraY > 0) {
        pause_map_cameraY = 0;
    }

    if (pause_map_cameraX <= -86.0f) {
        pause_map_cameraX = -85.0f;
    }
    if (pause_map_cameraY <= -210.0f) {
        pause_map_cameraY = -209.0f;
    }

    tab->initialized = 1;
}

void pause_map_handle_input(void) {
    f32 xMovement = gGameStatusPtr->stickX * 0.05f;
    f32 yMovement = -gGameStatusPtr->stickY * 0.05f;
    f32 pause_map_cursorYPosTemp = pause_map_cursorY;
    f32 pause_map_cursorXPosTemp = pause_map_cursorX;
    s32 xTemp;
    s32 yTemp;

    if (xMovement == 0.0f && yMovement == 0.0f && pause_map_cursorCurrentOption != -1) {
        PauseMapSpace* mapSpace = &D_802502B8[pause_map_cursorCurrentOption];

        xMovement = mapSpace->xPos - pause_map_cursorXPosTemp;
        yMovement = mapSpace->yPos - pause_map_cursorYPosTemp;

        xMovement *= D_80270090;
        yMovement *= D_80270090;
    }

    pause_map_cursorX += xMovement;
    pause_map_cursorY += yMovement;

    if (pause_map_cursorX < 16.0f) {
        pause_map_cursorX = 16.0f;
    }

    if (pause_map_cursorY < 8.0f) {
        pause_map_cursorY = 8.0f;
    }

    if (pause_map_cursorX >= 316.0f) {
        pause_map_cursorX = 315.0f;
    }

    if (pause_map_cursorY >= 308.0f) {
        pause_map_cursorY = 307.0f;
    }

    xTemp = pause_map_cursorX + pause_map_cameraX - D_80270098;
    yTemp = pause_map_cursorY + pause_map_cameraY - D_802700A0;

    if (D_802700A8 <= xTemp) {
        pause_map_cameraX = pause_map_cameraX - (xTemp - D_802700A8);
    }

    if (D_802700B0 >= xTemp) {
        pause_map_cameraX = pause_map_cameraX - (xTemp + D_802700B8);
    }

    if (yTemp >= 15.0) {
        pause_map_cameraY -= yTemp - 15.0;
    }

    if (yTemp <= -15.0) {
        pause_map_cameraY -= yTemp + 15.0;
    }

    if (pause_map_cameraX > 0.0f) {
        pause_map_cameraX = 0.0f;
    }

    if (pause_map_cameraY > 0.0f) {
        pause_map_cameraY = 0.0f;
    }

    if (pause_map_cameraX < -86.0f) {
        pause_map_cameraX = -86.0f;
    }

    if (pause_map_cameraY < -210.0f) {
        pause_map_cameraY = -210.0f;
    }

    if (gPauseMenuPressedButtons & B_BUTTON) {
        sfx_play_sound(0xCA);
        gPauseMenuCurrentTab = 0;
        return;
    }

    gPauseMenuCurrentDescIconScript = 0;
    if (pause_map_cursorCurrentOption == -1) {
        gPauseMenuCurrentDescString = 0;
        return;
    }

    gPauseMenuCurrentDescString = pause_map_tab_places_desc_string_id + 1 + (pause_map_cursorCurrentOption * 3);
    if (evt_get_variable(0, EVT_STORY_PROGRESS) >= D_802502B8[pause_map_cursorCurrentOption].description) {
        gPauseMenuCurrentDescString++;
    }
}

void pause_map_update(void) {
    PauseMapSpace* mapSpace = &D_802502B8[0];
    f32 lowestSqSum = 10000.0f;
    f32 cursorOption = -1.0f;
    s32 i;

    pause_map_cursorCurrentOption = -1;
    D_80270724 = 0;

    for (i = 0; i < EVT_SAVE_FLAG_PLACES_VISITED_TOTAL; i++, mapSpace++) {
        if (evt_get_variable(0, EVT_SAVE_FLAG_PLACES_VISITED + i) != 0) {
            f32 deltaX = pause_map_cursorX - mapSpace->xPos;
            f32 deltaY = pause_map_cursorY - mapSpace->yPos;
            f32 sqSum = SQ(deltaX) + SQ(deltaY);

            if (sqSum < 400.0f) {
                D_80270724++;
            }

            if (sqSum < lowestSqSum && sqSum < 200.0f) {
                lowestSqSum = sqSum;
                cursorOption = i;
            }
        }
    }

    pause_map_cursorCurrentOption = cursorOption;
    pause_map_cursorCurrentOptionCopy = cursorOption;
}

void pause_map_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80270700); i++) {
        free_hud_element(D_80270700[i]);
    }
}
