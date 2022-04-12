#include "mac_01.h"

#define CHUCK_QUIZMO_NPC_ID 5

extern u8 D_80258407_818C87;

#include "world/common/UnkMusicFunc.inc.c"

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

#include "world/common/UnkNpcAIMainFunc.inc.c"

static char* N(exit_str_0) = "flo_00";
static char* N(exit_str_1) = "kmr_22";

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80242FA4_803824);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243380_803C00);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243494_803D14);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243500_803D80);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802435C0_803E40);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243680_803F00);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243740_803FC0);

#include "world/common/atomic/ToadHouse.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243CD4_804554);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243D28_8045A8);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243D60_8045E0);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244078_8048F8);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802440BC_80493C);

#include "world/common/GetPlayerCoins.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802440FC_80497C);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802441EC_804A6C);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244308_804B88);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802443E0_804C60);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802446AC_804F2C);

#include "world/common/UnkPositionFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802447E0_805060);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244848_8050C8);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802448A0_805120);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244984_805204);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802449F8_805278);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", pause_tabs_draw_stats_805418);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", pause_tabs_draw_badges_805540);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244D68_8055E8);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244E10_805690);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244E90_805710);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244F5C_8057DC);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80245018_805898);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80245028_8058A8);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_8024522C_805AAC);

ApiStatus func_80245440_805CC0(Evt* script, s32 isInitialCall) {
    if (gPlayerData.currentPartner == script->varTable[10]) {
        script->varTable[1] = 0;
        return ApiStatus_DONE2;
    }

    switch_to_partner(script->varTable[10]);
    script->varTable[1] = 1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80245488_805D08);

void func_802454B4_805D34(void) {
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, 1, SHADE, 0, PRIMITIVE, 0, 0, 0, 0, 1, SHADE, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80258407_818C87);
}

ApiStatus func_80245504_805D84(Evt* script, s32 isInitialCall) {
    partner_set_tether_distance(20.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_8024552C_805DAC(Evt* script, s32 isInitialCall) {
    repartner_set_tether_distance();
    return ApiStatus_DONE2;
}
