#include "common.h"
#include "npc.h"

INCLUDE_ASM(s32, "entity/WoodenCrate", entity_WoodenCrate_init_fragments);

void entity_WoodenCrate_init(Entity* entity) {
    WoodenCrateData* data = entity->dataBuf.crate;

    entity->scale.y = 0.85714287f;
    data->itemID = CreateEntityVarArgBuffer[0];
    data->globalFlagIndex = 0xFFFF;
}

void entity_WoodenCrate_reset_fragments(Entity* entity) {
    WoodenCrateData* data = entity->dataBuf.crate;

    data->basePosY = entity->position.y;
    entity_WoodenCrate_init_fragments(entity, &D_0A004350, &D_0A0026F0);
}

INCLUDE_ASM(s32, "entity/WoodenCrate", entity_WoodenCrate_update_fragments);

INCLUDE_ASM(s32, "entity/WoodenCrate", entity_WoodenCrate_setupGfx);

s32 entity_WoodenCrate_idle(Entity* entity) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 shouldBreak = FALSE;

    if (entity->collisionFlags & 1) {
        if ((playerStatus->actionState == ACTION_STATE_GROUND_POUND)
            || (playerStatus->actionState == ACTION_STATE_ULTRA_POUND)) {
            set_action_state(ACTION_STATE_FALLING);
            shouldBreak = TRUE;
        }
    }

    if (shouldBreak) {
        entity_WoodenCrate_reset_fragments(entity);
        entity_set_render_script(entity, &D_802EAE7C);
        entity_start_script(entity);
        exec_entity_commandlist(entity);
        sfx_play_sound(0x20AE);
    }
}

f32 player_get_camera_facing_angle(void);

void entity_WoodenCrate_shatter(Entity* entity, f32 arg1) {
    WoodenCrateData* data = entity->dataBuf.crate;

    if (data->itemID != -1) {
        s32 flag = FALSE;

        // can't do || here, or gcc realizes it can reuse the temp->unk_04 load
        if (data->globalFlagIndex == 0xFFFF) {
            flag = TRUE;
        } else if (!get_global_flag(data->globalFlagIndex)) {
            flag = TRUE;
        }

        if (flag) {
            make_item_entity(data->itemID, entity->position.x, entity->position.y + 33.0, entity->position.z, 0xA, 0,
                             player_get_camera_facing_angle(), data->globalFlagIndex);
        }
    }
}
