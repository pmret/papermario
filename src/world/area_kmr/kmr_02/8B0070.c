#include "kmr_02.h"
#include "effects.h"

static char* N(exit_str_0) = "kmr_05";
static char* N(exit_str_1) = "kmr_00";
static char* N(exit_str_2) = "kmr_09";
static char* N(exit_str_3) = "";

#define CHUCK_QUIZMO_NPC_ID 8

#include "world/common/atomic/Pipe.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802402E0_8B0350);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80240370_8B03E0);

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/enemy/StationaryAI.inc.c"

static char* N(exit_str_4) = "nok_02";
static char* N(exit_str_5) = "kmr_03";
static char* N(exit_str_6) = "\0\0\0\0";

#include "world/common/UnkFunc41.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242014_8B2084);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024226C_8B22DC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802422C0_8B2330);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802422F8_8B2368);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242394_8B2404);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242710_8B2780);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242734_8B27A4);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242788_8B27F8);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802427B0_8B2820);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802427CC_8B283C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_802427EC_8B285C);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024280C_8B287C);

#define UNK_NPC_POS_FUNC_NUM 7
#include "world/common/UnkNpcPosFunc.inc.c"

#include "world/common/SyncStatusMenu.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_8024295C_8B29CC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242BA8_8B2C18);

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

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F08_8B2F78);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F28_8B2F98);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80242F7C_8B2FEC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B0070", func_80243034_8B30A4);
