#include "common.h"
#include "ld_addrs.h"

void entity_HiddenPanel_set_ispy_notification(Entity*);
void entity_HiddenPanel_hide(Entity*);
void entity_HiddenPanel_idle(Entity*);
void entity_HiddenPanel_flip_over(Entity*);
void entity_HiddenPanel_init(Entity*);

s32 D_802EAA80[] = {
    0x00000002, entity_HiddenPanel_set_ispy_notification, 0x00000005, 0x00000001, 0x00000002, entity_HiddenPanel_hide, 0x00000003, 0x00000000, entity_HiddenPanel_idle, 0x00000003, 0x00000000, entity_HiddenPanel_flip_over, 0x00000004, 0x00000001, 0x00000000
};
s32 D_802EAABC[] = {
    0x00000004, 0x00000001, 0x00000005, 0x00010000, 0x00000001, 0x0000003C, 0x0A000280, 0x00000002, 0x00000000
};
s32 D_802EAAE0[] = {
    0x00000004, 0x00000001, 0x00000005, 0x00010000, 0x00000001, 0x0000003C, 0x0A0002A0, 0x00000002, 0x00000000,
};
EntityBlueprint D_802EAB04 = {
    0x0001, 0x007C, D_802EAABC, 0x00000000, entity_HiddenPanel_init, D_802EAA80, 0x00000000, E56BA0_ROM_START, E56BA0_ROM_END, ENTITY_TYPE_HIDDEN_PANEL, { 60, 0, 60}
};
