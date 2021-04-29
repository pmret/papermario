#include "common.h"
#include "map.h"

void func_8011B950(u16, s32, s32, s32);

ApiStatus N(UnkFunc27)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 testS2 = get_variable(script, *args++);
    s32 testS0 = get_variable(script, *args++);
    s32 testS1 = get_variable(script, *args++);
    s32* temp_s0_3 = testS0;
    s32 temp_s1 = testS1;
    s32 temp_s2 = testS2;

    if (temp_s0_3 == -1) {
        func_8011D82C(temp_s1);
        return ApiStatus_DONE2;
    }

    switch (temp_s2) {
        case 0:
            temp_s2 = 0xFFFF;
            while (TRUE) {
                if (*temp_s0_3 == temp_s2) {
                    break;
                }
                func_8011BC7C(get_model_from_list_index(get_model_list_index_from_tree_index(*temp_s0_3)), -1, temp_s1);
                temp_s0_3++;
            };
            break;

        case 1:
            temp_s2 = 0xFFFF;
            while (TRUE) {
                if (*temp_s0_3 == temp_s2) {
                    break;
                }
                func_8011B950(*temp_s0_3, -1, temp_s1, 0);
                temp_s0_3++;
            };
            break;

        case 2:
            *D_801512F0 = temp_s1;
            break;

    }
    return ApiStatus_DONE2;
}
