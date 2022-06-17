#include "common.h"
#include "ld_addrs.h"

void entity_ScriptSpring_idle(Entity*);
void entity_SimpleSpring_idle(Entity*);
void entity_SimpleSpring_set_jump_params(Entity*);
void entity_SimpleSpring_enable_player_input(Entity*);
void entity_ScriptSpring_init(Entity*);
void entity_SimpleSpring_init(Entity*);

s32 D_802EA9A0[] = {
    0x00000003, 0x00000000, entity_ScriptSpring_idle, 0x00000003, 0x0000000A, 0x00000000, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802EA9C4[] = {
    0x00000003, 0x00000000, entity_SimpleSpring_idle, 0x00000003, 0x00000002, 0x00000000, 0x00000002, entity_SimpleSpring_set_jump_params, 0x00000003
};
s32 D_802EA9E8[] = {
    0x00000003, 0x00000000, 0x00000002, entity_SimpleSpring_enable_player_input, 0x00000003, 0x0000000A, 0x00000000, 0x00000004, 0x00000000, 0x00000000
};
s32 D_802EAA10[] = {
    0x00E657A0, 0x00E67120, 0x00E67120, 0x00E68580
};
s32 D_802EAA20[] = {
    0x00E68580, 0x00E69D50, 0x00E69D50, 0x00E6B1B0
};
EntityBlueprint Entity_D_802EAA30 = {
    0x2008, 0x0000, 0x0000131C, 0x000001B8, entity_ScriptSpring_init, D_802EA9A0, 0x00000000, D_802EAA10, 0x00000000, ENTITY_TYPE_SCRIPT_SPRING, {40, 25, 40}
};
EntityBlueprint Entity_D_802EAA54 = {
    0x2008, 0x0004, 0x0000131C, 0x000001B8, entity_SimpleSpring_init, D_802EA9C4, 0x00000000, D_802EAA20, 0x00000000, ENTITY_TYPE_SIMPLE_SPRING, {40, 25, 40}
};
