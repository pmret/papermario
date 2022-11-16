#include "sam_05.h"
#include "sprite.h"

static char* N(exit_str_0) = "sam_04";
static char* N(exit_str_1) = "sam_06";

#include "world/common/enemy/ai/PiranhaPlantAI.inc.c"

extern s32 D_80242F90_D1B770;

ApiStatus func_802419A4_D1A184(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    u8 sp20[20];
    u8 sp38[20];
    u8 sp50[20];
    u8 sp68[20];
    s32 i;

    if (isInitialCall) {
        npc->duration = 0;
        script->functionTemp[0] = 0;
    }

    if (enemy->varTable[3] == 0) {
        func_802DE780(npc->spriteInstanceID, 1, 7, 255, 255, 255, 0, 0);
        return ApiStatus_BLOCK;
    }

    func_802DE780(npc->spriteInstanceID, 0, 0x11, 0x14, 0, 0, 255, 0);
    script->functionTemp[0] += 10;
    if (script->functionTemp[0] >= 360) {
        script->functionTemp[0] %= 360;
    }

    for (i = 0; i < 20; i++) {
        sp20[i] = (cosine(script->functionTemp[0] + (i * 25)) + 1.0) * 56.0;
        sp38[i] = (cosine(script->functionTemp[0] + (i * 25) + 45) + 1.0) * 56.0;
        sp50[i] = (cosine(script->functionTemp[0] + (i * 25) + 90) + 1.0) * 56.0;
        sp68[i] = enemy->varTable[3];

        func_802DE780(npc->spriteInstanceID, 0, 0xC, i, (sp20[i] << 24) | (sp38[i] << 16) | (sp50[i] << 8) | sp68[i], 0, 255, 0);
    }

    if (enemy->varTable[3] == 255) {
        s32 vt3 = enemy->varTable[3]; // todo required to match

        npc->renderMode = 0xD;
        func_802DE780(npc->spriteInstanceID, 1, 0xF, (s32) &D_80242F90_D1B770, vt3, 0, vt3, 0);
    } else {
        npc->renderMode = 0x16;
        func_802DE780(npc->spriteInstanceID, 1, 0xF, (s32) &D_80242F90_D1B770, enemy->varTable[3], 0, enemy->varTable[3], 0);
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80241D20_D1A500(Evt* script, s32 isInitialCall) {
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
