#include "sam_01.h"
#include "effects.h"

#define CHUCK_QUIZMO_NPC_ID 14

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_8024053C_CF80AC);

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240590_CF8100);

extern s32 D_8024DBC0[];

ApiStatus func_802405C8_CF8138(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_8024DBC0[i] = ptr[i];
        }
        D_8024DBC0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_8024DBC0[i] = i + 16;
            D_8024DBC0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_sam/sam_01/CF7E80", func_80240664_CF81D4);

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

#include "common/GetItemEntityPosition.inc.c"

#include "world/common/UnkTrigFunc001.inc.c"

#define NAMESPACE dup_sam_01
#include "world/common/StashVars.inc.c"
#define NAMESPACE sam_01

#define NAMESPACE dup_sam_01
#include "world/common/GetItemName.inc.c"
#define NAMESPACE sam_01

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"
