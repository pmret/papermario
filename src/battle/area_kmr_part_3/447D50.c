#include "common.h"

extern s32 D_80104A28;

#define NAMESPACE b_area_kmr_part_3

#define NAMESPACE dup_b_area_kmr_part_3
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_kmr_part_3

ApiStatus func_802189DC_447E1C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = get_float_variable(script, *args++);
    f32 posY = get_float_variable(script, *args++);
    HudElement* icon = create_hud_element(&D_80104A28);

    set_hud_element_render_pos(icon, posX, posY);
    set_hud_element_scale(icon, 1.5f);
    clear_hud_element_flags(icon, 0x200002);
    set_variable(script, *args++, icon);
    load_tattle_flags(0x8B);
    return ApiStatus_DONE2;
}

#include "common/FreeIcon.inc.c"

#define NAMESPACE dup2_b_area_kmr_part_3
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_kmr_part_3

#define NAMESPACE dup3_b_area_kmr_part_3
#include "common/BattleAreaAngleStuff.inc.c"
#define NAMESPACE b_area_kmr_part_3

#include "common/Dist3D.inc.c"

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"
