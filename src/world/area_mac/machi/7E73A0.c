#include "machi.h"

static char* STR01 = "GSW MAP";
static char* STR02 = "GSW DOKAN";
static char* STR03 = "GSW FBTL";
static char* STR04 = "GSW BTL";
static char* STR05 = "GSW NPC";
static char* STR06 = "GSW BAT";
static char* STR07 = "GSW OSR";
static char* STR08 = "GSW END";
static char* STR09 = "GSW KPA";
static char* STR10 = "GSW PRA";
static char* STR11 = "GSW SAM";
static char* STR12 = "GSW FLO";
static char* STR13 = "GSW KZN";
static char* STR14 = "GSW JAN";
static char* STR15 = "GSW OMO";
static char* STR16 = "GSW DGB";
static char* STR17 = "GSW ARN";
static char* STR18 = "GSW OBK";
static char* STR19 = "GSW MIM";
static char* STR20 = "GSW ISK";
static char* STR21 = "GSW SBK";
static char* STR22 = "GSW DRO";
static char* STR23 = "GSW IWA";
static char* STR24 = "GSW TRD";
static char* STR25 = "GSW NOK";
static char* STR26 = "GSW HOS";
static char* STR27 = "GSW KKJ";
static char* STR28 = "GSW KGR";
static char* STR29 = "GSW TIK";
static char* STR30 = "GSW MAC";
static char* STR31 = "GSW KMR";
static char* STR32 = "GSW EVT";
static char* STR33 = "GSWF MAP";
static char* STR34 = "GSWF DOKAN";
static char* STR35 = "GSWF FBTL";
static char* STR36 = "GSWF BTL";
static char* STR37 = "GSWF NPC";
static char* STR38 = "GSWF BAT";
static char* STR39 = "GSWF OSR";
static char* STR40 = "GSWF END";
static char* STR41 = "GSWF KPA";
static char* STR42 = "GSWF PRA";
static char* STR43 = "GSWF SAM";
static char* STR44 = "GSWF FLO";
static char* STR45 = "GSWF KZN";
static char* STR46 = "GSWF JAN";
static char* STR47 = "GSWF OMO";
static char* STR48 = "GSWF DGB";
static char* STR49 = "GSWF ARN";
static char* STR50 = "GSWF OBK";
static char* STR51 = "GSWF MIM";
static char* STR52 = "GSWF ISK";
static char* STR53 = "GSWF SBK";
static char* STR54 = "GSWF DRO";
static char* STR55 = "GSWF IWA";
static char* STR56 = "GSWF TRD";
static char* STR57 = "GSWF NOK";
static char* STR58 = "GSWF HOS";
static char* STR59 = "GSWF KKJ";
static char* STR60 = "GSWF KGR";
static char* STR61 = "GSWF TIK";
static char* STR62 = "GSWF MAC";
static char* STR63 = "GSWF KMR";
static char* STR64 = "GSWF EVT";

static char* N(exit_str_0) = "kmr_09";
static char* N(exit_str_1) = "nok_10";
static char* N(exit_str_2) = "iwa_00";
static char* N(exit_str_3) = "tst_01";
static char* N(exit_str_4) = "jan_00";

INCLUDE_ASM(s32, "world/area_mac/machi/7E73A0", func_80240000_7E73A0);

ApiStatus N(80240030_7E73D0)(Evt* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus func_80240038_7E73D8(Evt* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus func_80240040_7E73E0(Evt* script, s32 isInitialCall) {
    return ApiStatus_BLOCK;
}

ApiStatus func_80240048_7E73E8(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 0;
        gOverrideFlags |= GLOBAL_OVERRIDES_10;
    }

    set_screen_overlay_params_front(0, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] += 10;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    return ApiStatus_BLOCK;
}


ApiStatus func_802400C8_7E7468(Evt* script, s32 isInitialCall) {
    gPlayerData.partners[script->varTable[0] + 1].level++;
    script->varTable[0] = PARTNER_NONE;
    if (gPlayerData.partners[PARTNER_GOOMBARIO].level > 2) {
        gPlayerData.partners[PARTNER_GOOMBARIO].level = 2;
        script->varTable[0] = PARTNER_GOOMBARIO;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80240114_7E74B4(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 255;
        gOverrideFlags |= GLOBAL_OVERRIDES_10;
    }

    set_screen_overlay_params_front(0, script->functionTemp[1]);

    if (script->functionTemp[1] == 0) {
        gOverrideFlags &= ~GLOBAL_OVERRIDES_10;
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] -= 10;
    if (script->functionTemp[1] < 0) {
        script->functionTemp[1] = 0;
    }

    return ApiStatus_BLOCK;
}
