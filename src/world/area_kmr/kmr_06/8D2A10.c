#include "kmr_06.h"

INCLUDE_ASM(s32, "world/area_kmr/kmr_06/8D2A10", func_80241500_8D2A10);

INCLUDE_ASM(s32, "world/area_kmr/kmr_06/8D2A10", func_802417A8_8D2CB8);

INCLUDE_ASM(s32, "world/area_kmr/kmr_06/8D2A10", func_802417E0_8D2CF0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_06/8D2A10", func_80241950_8D2E60);

INCLUDE_ASM(s32, "world/area_kmr/kmr_06/8D2A10", func_802419EC_8D2EFC);

INCLUDE_ASM(s32, "world/area_kmr/kmr_06/8D2A10", func_80241A68_8D2F78);

INCLUDE_ASM(s32, "world/area_kmr/kmr_06/8D2A10", func_80241C78_8D3188);

ApiStatus func_80241CC8_8D31D8(ScriptInstance* script, s32 isInitialCall) {
    // todo use correct types
    s32* mapVar10 = get_variable(script, SI_MAP_VAR(10));
    s32 mapVar11 = get_variable(script, SI_MAP_VAR(11));
    s32 mapVar12 = get_variable(script, SI_MAP_VAR(12));

    func_801235C0(mapVar10[1]);

    heap_free(mapVar10);
    heap_free(mapVar11);
    heap_free(mapVar12);

    set_variable(script, SI_MAP_VAR(10), NULL);
    set_variable(script, SI_MAP_VAR(11), NULL);
    set_variable(script, SI_MAP_VAR(12), NULL);

    return ApiStatus_DONE2;
}
