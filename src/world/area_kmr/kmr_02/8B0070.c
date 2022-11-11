#include "kmr_02.h"
#include "effects.h"
#include "model.h"

static char* N(exit_str_0) = "kmr_05";
static char* N(exit_str_1) = "kmr_00";
static char* N(exit_str_2) = "kmr_09";
static char* N(exit_str_3) = "";

#define CHUCK_QUIZMO_NPC_ID 8

#include "world/common/entity/Pipe.inc.c"

extern s32 D_80244B2C_8B4B9C[];

// reg swap & data migration
#ifdef NON_MATCHING
ApiStatus func_802402E0_8B0350(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32* var_s0 = D_80244B2C_8B4B9C[evt_get_variable(script, *args++)];
    Enemy* enemy = get_enemy(npcID);
    s32 i;

    for (i = 0; i < 14; i++) {
        enemy->territory->temp[i] = *var_s0++;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802402E0_8B0350);
#endif

ApiStatus func_80240370_8B03E0(Evt* script, s32 isInitialCall) {
    set_map_change_fade_rate(1);
    return ApiStatus_DONE2;
}

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/enemy/ai/StationaryAI.inc.c"

static char* N(exit_str_4) = "nok_02";
static char* N(exit_str_5) = "kmr_03";
static char* N(exit_str_6) = "\0\0\0\0";

#include "world/common/util/ChangeNpcToPartner.inc.c"

ApiStatus func_80242014_8B2084(Evt* script, s32 isInitialCall) {
    if (get_npc_unsafe(NPC_PARTNER)->flags & NPC_FLAG_1000) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024226C_8B22DC);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 kmr_02_D_80257F58[];

ApiStatus func_802422F8_8B2368(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            kmr_02_D_80257F58[i] = ptr[i];
        }
        kmr_02_D_80257F58[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            kmr_02_D_80257F58[i] = i + 16;
            kmr_02_D_80257F58[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

// duplicate of func_802402E0_8B0350
INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242394_8B2404);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

ApiStatus func_80242710_8B2780(Evt* script, s32 isInitialCall) {
    script->varTable[0] = gPlayerData.curHP == gPlayerData.curMaxHP;
    return ApiStatus_DONE2;
}

extern u8 D_80257B00_8C7B70;
extern u16 D_80257D00_8C7D70;
extern MessageImageData D_80258120;

ApiStatus func_80242734_8B27A4(void) {
    D_80258120.raster = &D_80257B00_8C7B70; // TODO extract image
    D_80258120.palette = &D_80257D00_8C7D70; // TODO extract pal
    D_80258120.width = 32; // TOOD image header define
    D_80258120.height = 32; // TOOD image header define
    D_80258120.format = G_IM_FMT_CI;
    D_80258120.bitDepth = 0;
    set_message_images(&D_80258120);
    return ApiStatus_DONE1;
}

ApiStatus func_80242788_8B27F8(Evt* script, s32 isInitialCall) {
    gPlayerData.partners[PARTNER_GOOMPA].enabled = FALSE;
    func_800EB2A4(0);
    return ApiStatus_DONE1;
}

ApiStatus func_802427B0_8B2820(Evt* script, s32 isInitialCall) {
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_START) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_802427CC_8B283C(Evt* script, s32 isInitialCall) {
    set_game_mode(GAME_MODE_PAUSE);
    return ApiStatus_DONE1;
}

ApiStatus func_802427EC_8B285C(Evt* script, s32 isInitialCall) {
    close_status_menu();
    return ApiStatus_DONE2;
}

ApiStatus func_8024280C_8B287C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = resolve_npc(script, 0);

    npc->renderYaw += evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

#define UNK_NPC_POS_FUNC_NUM 7
#include "world/common/todo/UnkNpcPosFunc.inc.c"

#include "world/common/todo/SyncStatusMenu.inc.c"

#ifdef NON_EQUIVALENT
extern u8 D_80257F20;
extern u8 D_80257F21;
extern u8 D_80257F22;
extern u8 D_80257F23;

// control flow + data migration
ApiStatus func_8024295C_8B29CC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 r = evt_get_variable(script, *args++);
    s32 g = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 a = evt_get_variable(script, *args++);
    s32 temp_s0_5 = evt_get_variable(script, *args++);

    if (isInitialCall) {
        get_background_color_blend(&D_80257F20, &D_80257F21, &D_80257F22, &D_80257F23);
        script->functionTemp[0] = 0;
    }

    if (temp_s0_5 > 0) {
        set_background_color_blend(
            D_80257F20 + (((r - D_80257F20) * script->functionTemp[0]) / temp_s0_5),
            D_80257F21 + (((g - D_80257F21) * script->functionTemp[0]) / temp_s0_5),
            D_80257F22 + (((b - D_80257F22) * script->functionTemp[0]) / temp_s0_5),
            D_80257F23 + (((a - D_80257F23) * script->functionTemp[0]) / temp_s0_5)
        );

        script->functionTemp[0]++;
        if (temp_s0_5 < script->functionTemp[0]) {
            return ApiStatus_BLOCK;
        }
    } else {
        set_background_color_blend(r, g, b, a);
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024295C_8B29CC);
#endif

ApiStatus func_80242BA8_8B2C18(Evt* script, s32 isInitialCall) {
    *gBgRenderTypePtr = 1;
    return ApiStatus_DONE2;
}

// will match when preceding bss is worked out
#ifdef NON_MATCHING
s32 func_80242BC0_8B2C30(Evt* script, s32 isInitialCall) {
    Bytecode* args;

    static u8 oldPrimR, oldPrimG, oldPrimB;
    static u8 oldEnvR, oldEnvG, oldEnvB;

    s32 newEnvR, newEnvB, newEnvG;
    s32 newPrimR, newPrimG, newPrimB;
    s32 duration;

    args = script->ptrReadPos;
    newPrimR = evt_get_variable(script, *args++);
    newPrimG = evt_get_variable(script, *args++);
    newPrimB = evt_get_variable(script, *args++);
    newEnvR = evt_get_variable(script, *args++);
    newEnvG = evt_get_variable(script, *args++);
    newEnvB = evt_get_variable(script, *args++);
    duration = evt_get_variable(script, *args++);
    if (isInitialCall) {
        get_model_env_color_parameters(&oldPrimR, &oldPrimG, &oldPrimB, &oldEnvR, &oldEnvG, &oldEnvB);
        script->functionTemp[0] = 0;
    }
    if (duration > 0) {
        set_model_env_color_parameters(
            oldPrimR + ((newPrimR - oldPrimR) * script->functionTemp[0]) / duration,
            oldPrimG + ((newPrimG - oldPrimG) * script->functionTemp[0]) / duration,
            oldPrimB + ((newPrimB - oldPrimB) * script->functionTemp[0]) / duration,
            oldEnvR  + ( (newEnvR - oldEnvR) * script->functionTemp[0]) / duration,
            oldEnvG  + ( (newEnvG - oldEnvG) * script->functionTemp[0]) / duration,
            oldEnvB  + ( (newEnvB - oldEnvB) * script->functionTemp[0]) / duration);
            script->functionTemp[0]++;
        if (duration < script->functionTemp[0]) {
            return 2;
        }
    } else {
        set_model_env_color_parameters(newPrimR, newPrimG, newPrimB, newEnvR, newEnvG, newEnvB);
        return 2;
    }
    return 0;
}
#else
INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242BC0_8B2C30);
#endif

ApiStatus func_80242F08_8B2F78(Evt* script, s32 isInitialCall) {
    mdl_set_all_fog_mode(3);
    return ApiStatus_DONE2;
}

ApiStatus func_80242F28_8B2F98(Evt* script, s32 isInitialCall) {
    func_8011B950(0x9C, -1, 1, 1);
    set_background_color_blend(0, 0, 0, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    return ApiStatus_DONE2;
}

extern s16 D_8024E538_8BE5A8[];

ApiStatus func_80242F7C_8B2FEC(Evt* script, s32 isInitialCall) {
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = 0.0f;
        script->functionTempPtr[2] = get_npc_safe(script->owner2.npcID);
        script->functionTemp[3] = D_8024E538_8BE5A8[script->owner2.npcID];
    }

    if (script->functionTemp[3] != 0) {
        script->functionTemp[3]--;
        return ApiStatus_BLOCK;
    }
    npc = script->functionTempPtr[2];
    npc->verticalRenderOffset = sin_deg(script->functionTempF[1]) * 1.5f;
    script->functionTempF[1] = clamp_angle(script->functionTempF[1] + 18.0f);
    return ApiStatus_BLOCK;
}

ApiStatus func_80243034_8B30A4(Evt* script, s32 isInitialCall) {
    get_item_entity(script->varTable[0])->scale = 0.6f;
    return ApiStatus_DONE2;
}
