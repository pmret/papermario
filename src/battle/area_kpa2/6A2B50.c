#include "common.h"
#include "effects.h"
#include "sprite.h"
#include "effects.h"

#define NAMESPACE b_area_kpa2

typedef struct KpaStruct {
    /* 0x00 */ s32 unk_00[6];
} KpaStruct; // size = 0x14

extern KpaStruct D_80234810_6BBA10;

#include "common/StartRumbleWithParams.inc.c"

#ifdef NON_MATCHING
ApiStatus func_8021B9A8_6A2BA8(Evt* script, s32 isInitialCall) {
    static KpaStruct D_80234810_6BBA10 = {90, 135, 225, 270, 315, 405};

    Bytecode* args = script->ptrReadPos;
    KpaStruct numbers = D_80234810_6BBA10;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 temp_fp;
    s32 temp_s5;
    s32 temp_s6;
    f32 temp_f24;
    f32 temp_f20;
    s32 temp_s0_4;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_v0_2;
    s32 t1;
    EffectInstance* effect;
    s32 asdf;
    s32 i;

    if (actor == NULL) {
        return ApiStatus_DONE2;
    }

    temp_fp = evt_get_variable(script, *args++);
    temp_s5 = evt_get_variable(script, *args++);
    temp_s6 = evt_get_variable(script, *args++);
    temp_f24 = evt_get_float_variable(script, *args++);
    if (actor->debuff != 0xA) {
        temp_s5 += temp_f24 * 36.0f;
    } else {
        temp_s5 += temp_f24 * 14.4;
    }

    for (i = 0; i < ARRAY_COUNT(numbers.unk_00); i++) {
        temp_f20 = numbers.unk_00[i] + rand_int(30) - 15;
        temp_s0_4 = (sin_deg(temp_f20) * 200.0f) + temp_fp;
        t1 = (cos_deg(temp_f20) * 200.0f) + temp_s5;
        asdf = temp_s6 + 20;
        effect = fx_lightning_bolt(1, temp_fp, temp_s5, temp_s6, temp_s0_4, t1, asdf, temp_f24, 11);
        temp_s1 = rand_int(256);
        temp_s2 = rand_int(256);
        temp_v0_2 = rand_int(256);
        effect->data.lightning->unk_30 = temp_s1;
        effect->data.lightning->unk_34 = temp_s2;
        effect->data.lightning->unk_38 = temp_v0_2;
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021B9A8_6A2BA8);
#endif

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021BC60_6A2E60);

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnfadeBackgroundToBlack.inc.c"

#include "common/RemoveChillOut.inc.c"

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021C14C_6A334C);

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021C520_6A3720);

#include "common/GetJumpHammerCharge.inc.c"

#include "common/GetPlayerHpPercent.inc.c"

#include "common/ItemEntityJumpToPos.inc.c"

#define NAMESPACE dup2_b_area_kpa2
#include "common/GetItemEntityPosition.inc.c"
#define NAMESPACE b_area_kpa2

//#include "common/DisableRandomAbility.inc.c"
INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021CCFC_6A3EFC);

#include "common/CanPlayerLoseAction.inc.c"

#include "common/UnkFireBreathFXFunc.inc.c"

INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021CFC0_6A41C0);

//#include "common/UnkLightningFXFunc.inc.c"
INCLUDE_ASM(s32, "battle/area_kpa2/6A2B50", func_8021D290_6A4490);

// const char* D_80234880_6BBA80 = "kpa_bt01_hit";
// const char* D_80234890_6BBA90 = "kpa_bt01_shape";
// const char* D_802348A0_6BBAA0 = "kpa_tex";
// const char* D_802348A8_6BBAA8 = "kpa_bg";
// const char* D_802348B0_6BBAB0 = "kkj_bt01_hit";
// const char* D_802348C0_6BBAC0 = "kkj_bt01_shape";
// const char* D_802348D0_6BBAD0 = "kkj_tex";
// const char* D_802348D8_6BBAD8 = "kpa_bg";
// const char* D_802348E0_6BBAE0 = "kkj_bt02_hit";
// const char* D_802348F0_6BBAF0 = "kkj_bt02_shape";
// const char* D_80234900_6BBB00 = "kkj_tex";
// const char* D_80234908_6BBB08 = "クッパ(ラストバトル３)";
// const char* D_80234920_6BBB20 = "クッパ(ラストバトル２)";
// const char* D_80234938_6BBB38 = "クッパ(ラストバトル１)";
// const char* D_80234950_6BBB50 = "クッパ(オープニング)";
// const char* D_80234968_6BBB68 = "クッパ";
// const char* D_80234970_6BBB70 = "kpa_03";
// const char* D_80234978_6BBB78 = "kpa_02";
// const char* D_80234980_6BBB80 = "kpa_01";
