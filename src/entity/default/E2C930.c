#include "common.h"
#include "effects.h"

INCLUDE_ASM(s32, "entity/default/E2C930", func_802BC200_E2C930);

INCLUDE_ASM(s32, "entity/default/E2C930", func_802BC3A8_E2CAD8);

INCLUDE_ASM(s32, "entity/default/E2C930", func_802BC3DC_E2CB0C);

INCLUDE_ASM(s32, "entity/default/E2C930", func_802BC974_E2D0A4);

void func_802BCC80_E2D3B0(Entity* entity) {
    if ((entity->collisionFlags & 0x80) != 0) {
        entity_start_script(entity);
        exec_entity_commandlist(entity);
        playFX_01(entity->position.x, entity->position.y + 25.0f, entity->position.z);
    }
}
