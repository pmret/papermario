#include "common.h"
#include "effects.h"
#include "hud_element.h"

extern s32* D_80284188[];
extern s32 D_802841B0;

extern s32 D_8029FA80[];
extern s32 D_8029FB60;
extern s32 D_8029FB64;
extern s32 D_8029FB68;
extern s32 D_8029FB78;

s32* virtual_entity_get_by_index(s32);

ApiStatus func_8025DEB0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = (s8)gBattleStatus.totalStarPoints;
    return ApiStatus_DONE2;
}

s32 func_8025DEC4(Evt* script, s32 isInitialCall) {
    s32 levelUp = FALSE;

    script->varTable[10] = gBattleStatus.totalStarPoints / 100; // star points in hundreds (levels to gain)
    script->varTable[11] = (gBattleStatus.totalStarPoints % 100) / 10; // star points in tens
    script->varTable[12] = gBattleStatus.totalStarPoints % 10; // star points in ones

    if (script->varTable[10] > 0) {
        script->varTable[10] = (s32) D_80284188[script->varTable[10]];
        levelUp = TRUE;
    } else {
        script->varTable[10] = D_802841B0;
    }

    if ((script->varTable[11] > 0) || levelUp) {
        script->varTable[11] = (s32) D_80284188[script->varTable[11]];
    } else {
        script->varTable[11] = D_802841B0;
    }

    script->varTable[12] = (s32) D_80284188[script->varTable[12]];
    return ApiStatus_DONE2;
}

ApiStatus func_8025E030(Evt* script, s32 isInitialCall) {
    return D_8029FB78 != 0 ? ApiStatus_DONE2 : ApiStatus_BLOCK;
}

ApiStatus func_8025E044(Evt* script, s32 isInitialCall) {
    EntityModel* model;

    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[6]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[7]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[8]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[9]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;

    return ApiStatus_DONE2;
}

ApiStatus func_8025E108(Evt* script, s32 isInitialCall) {
    EntityModel* model = get_entity_model(*virtual_entity_get_by_index(script->varTable[9]));
    model->flags &= ~(MODEL_FLAGS_USES_CUSTOM_GFX | MODEL_FLAGS_FLAG_20 | MODEL_FLAGS_FLAG_40
        | MODEL_FLAGS_HAS_LOCAL_VERTEX_COPY | MODEL_FLAGS_USE_CAMERA_UNK_MATRIX | MODEL_FLAGS_FLAG_200
        | MODEL_FLAGS_HAS_TRANSFORM_APPLIED | MODEL_FLAGS_HAS_TEX_PANNER | MODEL_FLAGS_USES_TRANSFORM_MATRIX
        | MODEL_FLAGS_FLAG_2000 | MODEL_FLAGS_FLAG_4000 | MODEL_FLAGS_FLAG_8000);
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;

    return ApiStatus_DONE2;
}

ApiStatus func_8025E14C(Evt* script, s32 isInitialCall) {
    fx_confetti(3, 0.0f, 100.0f, 0.0f, 1.0f, 120);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "18C790", btl_state_update_celebration);

// d1, d2, d3 hell
#ifdef NON_MATCHING
void btl_draw_upgrade_windows(s32 arg0) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 x;
    s32 y;
    s32 d1;
    s32 d2;
    s32 d3;

    switch (arg0) {
        case 1:
            if (battleStatus->currentSubmenu != 0) {
                if (battleStatus->currentSubmenu == arg0) {
                    d1 = 0;
                    d2 = 0;
                    d3 = 100;
                } else {
                    d1 = 0;
                    d2 = 100;
                    d3 = 0;
                }
            } else {
                d1 = 0;
                d2 = 100;
                d3 = 100;
            }
            break;
        default:
        case 0:
            d1 = 100;
            d2 = 100;
            d3 = 100;
            break;
    }

    get_hud_element_render_pos(D_8029FA80[0], &x, &y);
    draw_box(0, 0xF, x - 22, y - 22, 0, 44, 44, 0xFF, d1, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    get_hud_element_render_pos(D_8029FA80[3], &x, &y);
    draw_box(0, 0xF, x - 22, y - 22, 0, 44, 44, 0xFF, d2, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    get_hud_element_render_pos(D_8029FA80[2], &x, &y);
    draw_box(0, 0xF, x - 22, y - 22, 0, 44, 44, 0xFF, d3, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
}
#else
INCLUDE_ASM(s32, "18C790", btl_draw_upgrade_windows);
#endif

INCLUDE_ASM(s32, "18C790", btl_state_draw_celebration);

void func_80260948(s32 arg0, s32 posX, s32 posY) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 xOffset;
    s32 msgID;

    switch (gBattleState2) {
        case BATTLE_STATES2_UNK_8:
        case BATTLE_STATES2_UNK_F:
        case BATTLE_STATES2_UNK_10:
            switch (battleStatus->currentSubmenu) {
                case 0:
                    if (D_8029FB60 == 0) {
                        msgID = 0x1D00A5;
                    } else {
                        msgID = 0x1D00A8;
                    }
                    xOffset = 9;
                    break;
                case 1:
                    if (D_8029FB64 == 0) {
                        msgID = 0x1D00A6;
                    } else {
                        msgID = 0x1D00A9;
                    }
                    xOffset = 9;
                    break;
                default:
                    if (D_8029FB68 == 0) {
                        msgID = 0x1D00A7;
                    } else {
                        msgID = 0x1D00AA;
                    }
                    xOffset = 9;
                    break;
            }
            draw_msg(msgID, posX + xOffset + 0x11, posY, 255, 0xA, 0);
            break;
    }
}

// TODO type is almost definitely incorrect
void func_80260A20(s64 posX, s32 posY) {
    draw_msg(0x1D00AB, posX + 11, posY + 6, 255, 0xF, 0);
}
