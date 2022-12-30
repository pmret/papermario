#include "kmr_20.h"
#include "hud_element.h"
#include "ld_addrs.h"

extern HudScript HES_Item_Unused_08B;
extern HudScript HES_Item_Unused_08B_disabled;
extern HudScript HES_Item_Unused_08C;
extern HudScript HES_Item_Unused_08C_disabled;

BSS PopupMenu D_80253060;
BSS u8 D_80253390[0x3D86];
BSS u16 D_80257118[0x100];
BSS char D_80257318[0x8]; // padding
BSS u8 D_80257320[0x3D86];
BSS u16 D_8025B0A8[0x100];
BSS s32 D_8025B2A8; // worker ID
BSS s32 D_8025B2AC; // opacity
BSS MessageImageData D_8025B2B0[2];

#define NAME_SUFFIX _Unused
#include "common/foliage.inc.c"
#define NAME_SUFFIX

void N(func_802405BC_8EC3DC)(void) {
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

API_CALLABLE(N(func_802406BC_8EC4DC)){
    script->functionTemp[3] = 0;
    return ApiStatus_DONE2;
}

s32 N(LetterStoryRequirements)[] = {
    -128, -1, -77, -55, -15, -15, 5, -2, 
    41, 59, -3, 87, 
};

s32 N(LetterSenderStringIDs)[] = {
    0x00200001, 0x00200003, 0x00200005, 0x00200007, 0x00200009, 0x0020000B, 0x0020000D, 0x0020000F, 
    0x00200011, 0x00200013, 0x00200015, 0x00200017, 
};

s32 N(LetterBodyStringIDs)[] = {
    0x00200000, 0x00200002, 0x00200004, 0x00200006, 0x00200008, 0x0020000A, 0x0020000C, 0x0020000E, 
    0x00200010, 0x00200012, 0x00200014, 0x00200016, 
};

s32 N(LetterDmaOffsets)[] = {
    0x0000B290, 0x0000D158, 0x0000D178, 0x0000EB78, 0x0000ED78, 0x00010778, 0x00010978, 0x00012378, 
    0x00012578, 0x00013F78, 0x00014178, 0x00015B78, 0x00015D78, 0x00017778, 0x00017978, 0x00019378, 
    0x00019578, 0x0001AF78, 0x0001B178, 0x0001CB78, 0x0001CD78, 0x0001E778, 0x0001E978, 0x00020378, 
    0x00020578, 0x00021F78, 
};

API_CALLABLE(N(func_802406C8_8EC4E8)){
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

            for (i = 0; i < ARRAY_COUNT(N(LetterStoryRequirements)); i++) {
                cond = FALSE;
                temp_s0 = N(LetterStoryRequirements)[i];
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
                    menu->nameMsg[numEntries] = N(LetterSenderStringIDs)[i];
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
                script->varTable[0] = N(LetterBodyStringIDs)[userIndex];
                temp_s1 = (userIndex / 8) + 14;
                set_global_byte(temp_s1, get_global_byte(temp_s1) | (1 << (userIndex % 8)));
                if (userIndex == 3) {
                    evt_set_variable(NULL, GameFlag(103), 1);
                }

                dma_copy(charset_ROM_START + N(LetterDmaOffsets)[0],
                         charset_ROM_START + N(LetterDmaOffsets)[0] + sizeof(D_80253390),
                         D_80253390);
                dma_copy(charset_ROM_START + N(LetterDmaOffsets)[1],
                         charset_ROM_START + N(LetterDmaOffsets)[1] + sizeof(D_80257118),
                         D_80257118);
                D_8025B2B0[0].width = 150;
                D_8025B2B0[0].palette = D_80257118;
                D_8025B2B0[0].height = 105;
                D_8025B2B0[0].raster = D_80253390;
                D_8025B2B0[0].format = G_IM_FMT_CI;
                D_8025B2B0[0].bitDepth = 0;

                dma_copy(charset_ROM_START + N(LetterDmaOffsets)[(userIndex * 2) + 2],
                         charset_ROM_START + N(LetterDmaOffsets)[(userIndex * 2) + 2] + sizeof(D_80257320),
                         D_80257320);
                dma_copy(charset_ROM_START + N(LetterDmaOffsets)[(userIndex * 2) + 3],
                         charset_ROM_START + N(LetterDmaOffsets)[(userIndex * 2) + 3] + sizeof(D_8025B0A8),
                         D_8025B0A8);
                D_8025B2B0[1].width = 70;
                D_8025B2B0[1].raster = D_80257320;
                D_8025B2B0[1].palette = D_8025B0A8;
                D_8025B2B0[1].height = 95;
                D_8025B2B0[1].format = G_IM_FMT_CI;
                D_8025B2B0[1].bitDepth = 1;

                D_8025B2A8 = create_worker_frontUI(NULL, N(func_802405BC_8EC3DC));
                D_8025B2AC = 0;
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80240B20_8EC940)){
    free_worker(D_8025B2A8);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240B48_8EC968)){
    script->functionTemp[3] = 0;
    return ApiStatus_DONE2;
}

EvtScript N(D_80244E1C_8F0C3C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_SET(GF_KMR20_CheckedDeskForMail, TRUE)
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH0_0102, 160, 40)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_ELSE
        EVT_IF_EQ(GF_KMR20_CheckedDeskForMail, FALSE)
            EVT_SET(GF_KMR20_CheckedDeskForMail, TRUE)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH0_0101, 160, 40)
            EVT_WAIT(5)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(func_802406BC_8EC4DC))
    EVT_LABEL(0)
    EVT_CALL(N(func_802406C8_8EC4E8))
    EVT_IF_EQ(LVar0, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(ShowMessageAtScreenPos, LVar0, 160, 40)
    EVT_CALL(N(func_80240B20_8EC940))
    EVT_GOTO(0)
    EVT_LABEL(10)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(DiaryStoryRequirements)[] = {
    -40, -40, 7, 7, 40, 40, 60, 60, 
    89, 89, 96, 96, 
};

s32 N(DiaryEntryStringIDs)[] = {
    0x00200051, 0x00200052, 0x00200053, 0x00200054, 0x00200055, 0x00200056, 0x00200057, 0x00200058, 
    0x00200059, 0x0020005A, 0x0020005B, 0x0020005C, 
};

API_CALLABLE(N(func_80240B54_8EC974)){
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
            for (i = 0; i < ARRAY_COUNT(N(DiaryStoryRequirements)); i++) {
                if (evt_get_variable(NULL, GameByte(0)) >= N(DiaryStoryRequirements)[i]) {
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
                script->varTable[0] = N(DiaryEntryStringIDs)[userIndex];
                a1 = get_global_byte((userIndex / 8) + 12) | (1 << (userIndex % 8));
                set_global_byte((userIndex / 8) + 12, a1);
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80240DA4_8ECBC4)){
    au_ambience_set_volume(0, 1000, 1);
    return ApiStatus_DONE2;
}

EvtScript N(D_80245000_8F0E20) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
        EVT_IF_EQ(AF_KMR_0C, TRUE)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH0_00EC, 160, 40)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(GF_KMR20_FoundLuigisDiary, FALSE)
        EVT_SET(GF_KMR20_FoundLuigisDiary, TRUE)
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH0_0100, 160, 40)
        EVT_WAIT(5)
    EVT_END_IF
    EVT_CALL(N(func_80240B48_8EC968))
    EVT_LABEL(0)
    EVT_CALL(N(func_80240B54_8EC974))
    EVT_IF_EQ(LVar0, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(ShowMessageAtScreenPos, LVar0, 160, 40)
    EVT_GOTO(0)
    EVT_LABEL(10)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245178_8F0F98) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o305, SOUND_E0, 0)
    EVT_CALL(TranslateModel, MODEL_o222, 2, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o223, 3, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o224, 1, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(TranslateModel, MODEL_o222, -3, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o223, -3, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o224, -2, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(TranslateModel, MODEL_o222, 2, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o223, 3, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o224, 1, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(TranslateModel, MODEL_o222, -2, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o223, -3, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o224, -1, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(TranslateModel, MODEL_o222, 0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o223, 0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o224, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245374_8F1194) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o252, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o252, SOUND_20AB, 0)
    EVT_CALL(MakeLerp, 0, 0x00000870, 60, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g61, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o252, SOUND_20AC, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o252, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024546C_8F128C) = {
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_NE(LVar0, ACTION_STATE_SPIN_POUND)
        EVT_IF_NE(LVar0, ACTION_STATE_TORNADO_POUND)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(func_80240DA4_8ECBC4))
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
        EVT_IF_EQ(AF_KMR_0C, TRUE)
            EVT_CALL(EnableModel, MODEL_o200, FALSE)
        EVT_END_IF
    EVT_END_IF
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerActionState, LVar0)
        EVT_IF_EQ(LVar0, ACTION_STATE_IDLE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(D_80245374_8F1194))
    EVT_WAIT(1)
    EVT_CALL(SetPlayerPos, -150, 30, -35)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerActionState, LVar0)
        EVT_IF_EQ(LVar0, ACTION_STATE_IDLE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(MF_Unk_0D, TRUE)
        EVT_SET(MF_Unk_0D, FALSE)
        EVT_EXEC(N(EVS_8024BD40))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80245638) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80244E1C_8F0C3C)), TRIGGER_WALL_PRESS_A, COLLIDER_o251, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80245000_8F0E20)), TRIGGER_WALL_PRESS_A, COLLIDER_o240, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80245178_8F0F98)), TRIGGER_WALL_PRESS_A, COLLIDER_o305, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_8024546C_8F128C)), TRIGGER_FLOOR_TOUCH, COLLIDER_o252, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_80252E8C)), TRIGGER_WALL_PRESS_A, COLLIDER_o355, 1, 0)
    EVT_RETURN
    EVT_END
};
