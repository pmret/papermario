#include "hos_05.h"

void set_model_fog_color_parameters(u8 var2, u8 var3, u8 var4, u8 var5, u8 var6, u8 var7, u8 var8, s32 var9, s32 var10);

ApiStatus func_80240880_A2AAC0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 primR = evt_get_variable(script, *args++);
    s32 primG = evt_get_variable(script, *args++);
    s32 primB = evt_get_variable(script, *args++);
    s32 primA = evt_get_variable(script, *args++);
    s32 fogR = evt_get_variable(script, *args++);
    s32 fogG = evt_get_variable(script, *args++);
    s32 fogB = evt_get_variable(script, *args++);
    s32 fogStart = evt_get_variable(script, *args++);
    s32 fogEnd = evt_get_variable(script, *args++);

    set_model_fog_color_parameters(primR, primG, primB, primA, fogR, fogG, fogB, fogStart, fogEnd);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802409C4_A2AC04);

void func_80240D54_A2AF94(s32 camID, f32 fov) {
    Camera* camera = &gCameras[camID];
    camera->vfov = fov * 1.1;
}

ApiStatus func_80240DA0_A2AFE0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 camID = evt_get_variable(script, *args++);
    f32 fov = evt_get_float_variable(script, *args++);

    func_80240D54_A2AF94(camID, fov);
    return ApiStatus_DONE2;
}

ApiStatus func_80240DF8_A2B038(Evt* script, s32 isInitialCall) {
    GameStatus* gameStatus = gGameStatusPtr;
    if (gameStatus->creditsViewportMode < 5U) {
        gameStatus->creditsViewportMode++;
        state_init_intro();
    }
    return ApiStatus_DONE1;
}

ApiStatus func_80240E30_A2B070(Evt* script, s32 isInitialCall) {
    mdl_set_all_fog_mode(3);
    return ApiStatus_DONE2;
}

// adjusts properties of EmitterVolume:GoldShimmer2 effect
INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80240E50_A2B090);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80240F30_A2B170);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80240F88_A2B1C8);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80240FE0_A2B220);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80241044_A2B284);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802410E4_A2B324);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80241274_A2B4B4);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_8024146C_A2B6AC);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802416BC_A2B8FC);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80241850_A2BA90);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802419F4_A2BC34);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80241B40_A2BD80);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80241C54_A2BE94);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80241D08_A2BF48);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80241D7C_A2BFBC);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80241F54_A2C194);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", update_heroes_start_turn_A2C264);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802421E0_A2C420);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802422A0_A2C4E0);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802423D4_A2C614);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802425A0_A2C7E0);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80242704_A2C944);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802428C8_A2CB08);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80242F74_A2D1B4);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_8024301C_A2D25C);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80243100_A2D340);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80243164_A2D3A4);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_8024370C_A2D94C);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80243758_A2D998);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80243CC0_A2DF00);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80243ED0_A2E110);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80243FC4_A2E204);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802440D0_A2E310);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80244454_A2E694);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_802444E8_A2E728);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80244550_A2E790);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80244774_A2E9B4);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_8024486C_A2EAAC);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2AAC0", func_80244934_A2EB74);
