#include "common.h"
#include "ld_addrs.h"

void entity_WoodenCrate_idle(Entity*);
void entity_WoodenCrate_shatter(Entity*);
void entity_WoodenCrate_update_fragments(Entity*);
void entity_WoodenCrate_init(Entity*);

extern Gfx D_802E9828[];

s32 D_802EAE60[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A004338, 0x00000002, 0x00000000
};
s32 D_802EAE7C[] = {
    0x00000004, 0x00000011, 0x00000001, 0x0000003C, D_802E9828, 0x00000002, 0x00000000
};
s32 D_802EAE98[] = {
    0x00000003, 0x00000000, entity_WoodenCrate_idle, 0x00000007, 0x00000020, 0x00000002,
    entity_WoodenCrate_shatter, 0x00000003, 0x00000000, entity_WoodenCrate_update_fragments,
    0x00000007, 0x00000001, 0x00000007, 0x20000000, 0x00000000,
};
EntityBlueprint D_802EAED4 = {
    0x4200, 0x0394, D_802EAE60, 0x00000000, entity_WoodenCrate_init, D_802EAE98, 0x00000000, E51640_ROM_START, E51640_ROM_END, ENTITY_TYPE_WOODEN_CRATE, { 35, 30, 35 }
};
