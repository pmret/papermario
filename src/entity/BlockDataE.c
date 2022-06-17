#include "common.h"
#include "ld_addrs.h"

void entity_Signpost_idle(Entity*);

s32 D_802EAFB0[] = {
    0x00000003, 0x00000000, entity_Signpost_idle, 0x00000000
};

s32 D_802EAFC0[] = {
    0x00000004, 0x00000001, 0x00000001, 0x0000003C, 0x0A000A68, 0x00000002, 0x00000000
};

EntityBlueprint D_802EAFDC = {
    0x0E00, 0x0008, D_802EAFC0, 0x00000000, 0x00000000, D_802EAFB0, 0x00000000, E59480_ROM_START, E59480_ROM_END, ENTITY_TYPE_SIGNPOST, { 40, 50, 20 }
};
