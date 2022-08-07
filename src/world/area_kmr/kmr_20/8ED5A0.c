#include "kmr_20.h"

#define NAMESPACE dup_kmr_20
#include "world/common/atomic/Pipe.inc.c"
#define NAMESPACE kmr_20

#define NAMESPACE dup3_kmr_20
#include "common/foliage.inc.c"
#define NAMESPACE kmr_20

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8ED5A0", func_80241C9C_8EDABC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_20/8ED5A0", func_80241CF0_8EDB10);

ApiStatus func_80241D1C_8EDB3C(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 0x3F);
    return ApiStatus_DONE2;
}
