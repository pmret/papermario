#include "kmr_20.h"
#include "hud_element.h"
#include "ld_addrs.h"

extern HudScript HES_Item_Unused_08B;
extern HudScript HES_Item_Unused_08B_disabled;
extern HudScript HES_Item_Unused_08C;
extern HudScript HES_Item_Unused_08C_disabled;

extern s32 D_80244D24_8F0B44[];
extern s32 D_80244D54_8F0B74[];
extern s32 D_80244D84_8F0BA4[];
extern s32 D_80244DB4_8F0BD4[];
extern s32 D_80244FA0_8F0DC0[];
extern s32 D_80244FD0_8F0DF0[];

BSS PopupMenu D_80253060;
BSS char D_80253390[0x3D86];
BSS char D_80257118[0x200];
BSS char D_80257318[0x8]; // padding
BSS char D_80257320[0x3D86];
BSS char D_8025B0A8[0x200];
BSS s32 D_8025B2A8; // worker ID
BSS s32 D_8025B2AC; // opacity
BSS MessageImageData D_8025B2B0[2];

#include "world/common/entity/Pipe.inc.c"

ApiStatus func_80240310_8EC130(Evt* script, s32 isInitialCall) {
    set_map_transition_effect(4);
    return ApiStatus_DONE2;
}

ApiStatus func_80240330_8EC150(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 63);
    return ApiStatus_DONE2;
}

ApiStatus func_80240358_8EC178(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 127);
    return ApiStatus_DONE2;
}

#include "common/foliage.inc.c"

void func_802405BC_8EC3DC(void) {
    D_8025B2AC += 20;
    if (D_8025B2AC > 255) {
        D_8025B2AC = 255;
    }

    draw_ci_image_with_clipping(D_8025B2B0[0].raster, D_8025B2B0[0].width, D_8025B2B0[0].height, D_8025B2B0[0].format,
                                D_8025B2B0[0].bitDepth, D_8025B2B0[0].palette, 85, 97, 0, 0,
                                SCREEN_WIDTH, SCREEN_HEIGHT, D_8025B2AC);
    draw_ci_image_with_clipping(D_8025B2B0[1].raster, D_8025B2B0[1].width, D_8025B2B0[1].height, D_8025B2B0[1].format,
                                D_8025B2B0[1].bitDepth, D_8025B2B0[1].palette, 160, 102, 0, 0,
                                SCREEN_WIDTH, SCREEN_HEIGHT, D_8025B2AC);
}

ApiStatus func_802406BC_8EC4DC(Evt* script, s32 isInitialCall) {
    script->functionTemp[3] = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802406C8_8EC4E8(Evt* script, s32 isInitialCall) {
    PopupMenu* menu = &D_80253060;
    s32 temp;
    s32 userIndex;
    s32 temp_s0;
    s32 temp_s1;
    s32 cond;
    s32 numEntries;
    s32 gb;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            numEntries = 0;

            for (i = 0; i < 12; i++) {
                cond = FALSE;
                temp_s0 = D_80244D24_8F0B44[i];
                switch (temp_s0) {
                    case -1:
                        if (gPlayerData.quizzesCorrect != 0) {
                            cond = TRUE;
                        }
                        break;
                    case -2:
                        if (evt_get_variable(NULL, GameFlag(282)) != 0) {
                            cond = TRUE;
                        }
                        break;
                    case -3:
                        temp = FALSE;
                        if (evt_get_variable(NULL, GameByte(0)) >= 6) {
                            temp = (evt_get_variable(NULL, GameFlag(368)) != 0);
                        }
                        if (temp) {
                            cond = TRUE;
                        }
                        break;
                    default:
                        if (evt_get_variable(NULL, GameByte(0)) >= temp_s0) {
                            cond = TRUE;
                        }
                        break;
                }

                if (cond) {
                    menu->ptrIcon[numEntries] = &HES_Item_Unused_08B;
                    menu->userIndex[numEntries] = i;
                    menu->enabled[numEntries] = TRUE;
                    menu->nameMsg[numEntries] = D_80244D54_8F0B74[i];
                    menu->descMsg[numEntries] = 0;
                    temp = get_global_byte((i / 8) + 14) & (1 << (i % 8));
                    gb = temp;
                    menu->value[numEntries] = 0;
                    if (gb) {
                        menu->value[numEntries] = 1;
                        menu->ptrIcon[numEntries] = &HES_Item_Unused_08B_disabled;
                    }
                    numEntries++;
                }
            }

            if (numEntries == 0) {
                script->varTable[0] = 0;
                return ApiStatus_DONE2;
            }
            menu->popupType = POPUP_MENU_READ_POSTCARD;
            menu->numEntries = numEntries;
            menu->initialPos = script->functionTemp[3];
            create_popup_menu(menu);
            status_menu_respond_to_changes();
            close_status_menu();
            script->functionTemp[1] = 0;
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (script->functionTemp[1] == 0) {
                script->functionTemp[2] = menu->result;
                if (script->functionTemp[2] != 0) {
                    hide_popup_menu();
                } else {
                    break;
                }
            }

            script->functionTemp[1]++;
            if (script->functionTemp[1] >= 15) {
                destroy_popup_menu();
                if (script->functionTemp[2] == 0xFF) {
                    script->varTable[0] = -1;
                    return ApiStatus_DONE2;
                }
                script->functionTemp[3] = script->functionTemp[2] - 1;
                userIndex = menu->userIndex[script->functionTemp[2] - 1];
                script->varTable[0] = D_80244D84_8F0BA4[userIndex];
                temp_s1 = (userIndex / 8) + 14;
                set_global_byte(temp_s1, get_global_byte(temp_s1) | (1 << (userIndex % 8)));
                if (userIndex == 3) {
                    evt_set_variable(NULL, GameFlag(103), 1);
                }

                dma_copy(charset_ROM_START + D_80244DB4_8F0BD4[0],
                         charset_ROM_START + D_80244DB4_8F0BD4[0] + sizeof(D_80253390),
                         D_80253390);
                dma_copy(charset_ROM_START + D_80244DB4_8F0BD4[1],
                         charset_ROM_START + D_80244DB4_8F0BD4[1] + sizeof(D_80257118),
                         D_80257118);
                D_8025B2B0[0].width = 150;
                D_8025B2B0[0].palette = D_80257118;
                D_8025B2B0[0].height = 105;
                D_8025B2B0[0].raster = D_80253390;
                D_8025B2B0[0].format = G_IM_FMT_CI;
                D_8025B2B0[0].bitDepth = 0;

                dma_copy(charset_ROM_START + D_80244DB4_8F0BD4[(userIndex * 2) + 2],
                         charset_ROM_START + D_80244DB4_8F0BD4[(userIndex * 2) + 2] + sizeof(D_80257320),
                         D_80257320);
                dma_copy(charset_ROM_START + D_80244DB4_8F0BD4[(userIndex * 2) + 3],
                         charset_ROM_START + D_80244DB4_8F0BD4[(userIndex * 2) + 3] + sizeof(D_8025B0A8),
                         D_8025B0A8);
                D_8025B2B0[1].width = 70;
                D_8025B2B0[1].raster = D_80257320;
                D_8025B2B0[1].palette = D_8025B0A8;
                D_8025B2B0[1].height = 95;
                D_8025B2B0[1].format = G_IM_FMT_CI;
                D_8025B2B0[1].bitDepth = 1;

                D_8025B2A8 = create_worker_frontUI(NULL, func_802405BC_8EC3DC);
                D_8025B2AC = 0;
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80240B20_8EC940(Evt* script, s32 isInitialCall) {
    free_worker(D_8025B2A8);
    return ApiStatus_DONE2;
}

ApiStatus func_80240B48_8EC968(Evt* script, s32 isInitialCall) {
    script->functionTemp[3] = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80240B54_8EC974(Evt* script, s32 isInitialCall) {
    PopupMenu* menu = &D_80253060;
    s32 userIndex;
    s32 numEntries;
    s32 gb;
    s32 a1;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            numEntries = 0;
            for (i = 0; i < 12; i++) {
                if (evt_get_variable(NULL, GameByte(0)) >= D_80244FA0_8F0DC0[i]) {
                    menu->ptrIcon[numEntries] = &HES_Item_Unused_08C;
                    menu->userIndex[numEntries] = i;
                    menu->enabled[numEntries] = TRUE;
                    menu->nameMsg[numEntries] = 0;
                    menu->descMsg[numEntries] = 0;
                    gb = get_global_byte((i / 8) + 12);
                    menu->value[numEntries] = 0;
                    a1 = gb & (1 << (i % 8));
                    if (a1) {
                        menu->value[numEntries] = 1;
                        menu->ptrIcon[numEntries] = &HES_Item_Unused_08C_disabled;
                    }
                    numEntries++;
                }
            }

            if (numEntries == 0) {
                script->varTable[0] = 0;
                return ApiStatus_DONE2;
            }
            menu->popupType = POPUP_MENU_READ_DIARY_PAGE;
            menu->numEntries = numEntries;
            menu->initialPos = script->functionTemp[3];
            create_popup_menu(menu);
            status_menu_respond_to_changes();
            close_status_menu();
            script->functionTemp[1] = 0;
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (script->functionTemp[1] == 0) {
                script->functionTemp[2] = menu->result;
                if (script->functionTemp[2] != 0) {
                    hide_popup_menu();
                } else {
                    break;
                }
            }
            script->functionTemp[1]++;
            if (script->functionTemp[1] >= 15) {
                destroy_popup_menu();
                if (script->functionTemp[2] == 0xFF) {
                    script->varTable[0] = -1;
                    return ApiStatus_DONE2;
                }
                script->functionTemp[3] = script->functionTemp[2] - 1;
                userIndex = menu->userIndex[script->functionTemp[2] - 1];
                script->varTable[0] = D_80244FD0_8F0DF0[userIndex];
                a1 = get_global_byte((userIndex / 8) + 12) | (1 << (userIndex % 8));
                set_global_byte((userIndex / 8) + 12, a1);
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80240DA4_8ECBC4(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 1);
    return ApiStatus_DONE2;
}
