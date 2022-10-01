#include "mac_01.h"

#define CHUCK_QUIZMO_NPC_ID 5

extern s32 D_8024D944_80E1C4;
extern s32 D_8024D948_80E1C8;
extern s32 D_80258404_818C84;
extern s32 D_80262F68;

#include "world/common/atomic/MonitorMusicProximityTrigger.inc.c"

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

static char* N(exit_str_0) = "flo_00";
static char* N(exit_str_1) = "kmr_22";

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/UnkFoldFunc.inc.c"

ApiStatus func_80243380_803C00(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 spriteIndex = evt_get_variable(script, *args++);
    s32 rasterIndex = evt_get_variable(script, *args++);
    UnkEntityStruct* temp_v0 = heap_malloc(sizeof(*temp_v0));

    temp_v0->spriteIndex = spriteIndex;
    temp_v0->rasterIndex = rasterIndex;
    temp_v0->unk_34 = gPlayerStatus.colliderHeight;
    temp_v0->unk_38 = gPlayerStatus.colliderDiameter;
    temp_v0->pos.x = gPlayerStatus.position.x;
    temp_v0->pos.y = gPlayerStatus.position.y;
    temp_v0->pos.z = gPlayerStatus.position.z;
    temp_v0->rot.x = 0.0f;
    temp_v0->rot.y = 0.0f;
    temp_v0->rot.z = 0.0f;
    temp_v0->scale.x = SPRITE_WORLD_SCALE_F;
    temp_v0->scale.y = SPRITE_WORLD_SCALE_F;
    temp_v0->scale.z = SPRITE_WORLD_SCALE_F;
    temp_v0->foldID = func_8013A704(1);
    temp_v0->entityID = create_generic_entity_world(NULL, mac_01_UnkFoldFunc);
    evt_set_variable(script, MapVar(10), (s32) temp_v0);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243494_803D14);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243500_803D80);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802435C0_803E40);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243680_803F00);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243740_803FC0);

#include "world/common/atomic/ToadHouse.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243CD4_804554);

ApiStatus func_80243D28_8045A8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_8024D948_80E1C8 = evt_get_variable(script, *args++);
    D_8024D944_80E1C4 = 1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80243D60_8045E0);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

#include "world/common/GetPlayerCoins.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802440FC_80497C);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802441EC_804A6C);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244308_804B88);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802443E0_804C60);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802446AC_804F2C);

#include "world/common/UnkPositionFunc.inc.c"

ApiStatus func_802447E0_805060(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    script->functionTemp[1] += 10;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(0, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_80244848_8050C8(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    script->functionTemp[1] -= 10;
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
        return ApiStatus_DONE2;
    }

    set_screen_overlay_params_front(0, script->functionTemp[1]);
    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802448A0_805120);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244984_805204);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_802449F8_805278);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", pause_tabs_draw_stats_805418);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", pause_tabs_draw_badges_805540);

#include "world/common/UnkMachiFunc.inc.c"

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244E10_805690);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244E90_805710);

INCLUDE_ASM(s32, "world/area_mac/mac_01/8017D0", func_80244F5C_8057DC);

ApiStatus func_80245018_805898(Evt* script, s32 isInitialCall) {
    D_80262F68 = 0;
    return ApiStatus_DONE2;
}

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

ApiStatus func_80245488_805D08(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80258404_818C84 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void func_802454B4_805D34(void) {
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, 1, SHADE, 0, PRIMITIVE, 0, 0, 0, 0, 1, SHADE, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80258404_818C84 & 0xFF);
}

ApiStatus func_80245504_805D84(Evt* script, s32 isInitialCall) {
    partner_set_tether_distance(20.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_8024552C_805DAC(Evt* script, s32 isInitialCall) {
    repartner_set_tether_distance();
    return ApiStatus_DONE2;
}
