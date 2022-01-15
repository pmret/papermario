#include "common.h"
#include "fio.h"

typedef struct SaveBlockData {
    char unk_0[4];
    s16 angle;
} SaveBlockData;

void entity_SaveBlock_setupGfx();

void entity_Shadow_init(Shadow* shadow) {
    shadow->scale.x = 0.1f;
    shadow->scale.y = 0.1f;
    shadow->scale.z = 0.1f;
}

s32 entity_can_collide_with_jumping_player(Entity* entity) {
    if ((entity->collisionFlags & 4) && (gPlayerStatus.flags & 2)) {
        return TRUE;
    }
    return FALSE;
}

INCLUDE_ASM(s32, "entity/SaveBlock", entity_SaveBlock_setupGfx);

void entity_SaveBlock_idle(Entity* entity) {
    SaveBlockData* data;

    data = (SaveBlockData*)entity->dataBuf;
    data->angle = clamp_angle(data->angle + 6);
    entity_base_block_idle(entity);
}

void entity_SaveBlock_pause_game(void) {
    set_time_freeze_mode(TIME_FREEZE_PARTIAL);
    disable_player_input();
    gPlayerStatusPtr->currentSpeed = 0.0f;
}

void entity_SaveBlock_resume_game(void) {
    set_time_freeze_mode(TIME_FREEZE_NORMAL);
    enable_player_input();
}

void entity_SaveBlock_save_data(void) {
    gGameStatusPtr->savedPos.x = gPlayerStatusPtr->position.x;
    gGameStatusPtr->savedPos.y = gPlayerStatusPtr->position.y;
    gGameStatusPtr->savedPos.z = gPlayerStatusPtr->position.z;
    fio_save_game(gGameStatusPtr->saveSlot);
}

void entity_SaveBlock_show_tutorial_message(Entity* entity) {
    if (!get_global_flag(EVT_SAVE_FLAG(95))) {
        SaveBlockTutorialMessagePrinterClosed = FALSE;
        msg_get_printer_for_msg(0x1D0000, &SaveBlockTutorialMessagePrinterClosed);
        set_global_flag(EVT_SAVE_FLAG(95));
        return;
    }

    exec_entity_commandlist(entity);
    exec_entity_commandlist(entity);
}

void entity_SaveBlock_wait_for_close_tutorial(Entity* entity) {
    if (SaveBlockTutorialMessagePrinterClosed) {
        exec_entity_commandlist(entity);
    }
}

void entity_SaveBlock_show_choice_message(void) {
    SaveBlockTutorialMessagePrinterClosed = FALSE;
    SaveBlockResultMessagePrinterClosed = FALSE;
    SaveBlockResultMessagePrinter = msg_get_printer_for_msg(0x1D0004, &SaveBlockResultMessagePrinterClosed);
    SaveBlockTutorialMessagePrinter = msg_get_printer_for_msg(0x1E000A, &SaveBlockTutorialMessagePrinterClosed);
}

void entity_SaveBlock_show_result_message(void) {
    msg_printer_load_msg(0x1D0005, SaveBlockResultMessagePrinter);
    sfx_play_sound(0x10);
}

void entity_SaveBlock_wait_for_close_result(Entity* entity) {
    if (SaveBlockResultMessagePrinterClosed) {
        exec_entity_commandlist(entity);
    }
}

void entity_SaveBlock_wait_for_close_choice(Entity* entity) {
    if (SaveBlockTutorialMessagePrinterClosed) {
        if (SaveBlockTutorialMessagePrinter->currentOption == 1) {
            set_entity_commandlist(entity, &D_802E99DC);
        } else {
            exec_entity_commandlist(entity);
        }
        close_message(SaveBlockResultMessagePrinter);
    }
}

void entity_SaveBlock_init(Entity* entity) {
    BlockEntityData* data = entity->dataBuf;

    entity_base_block_init(entity);
    entity->renderSetupFunc = entity_SaveBlock_setupGfx;
    data->coinsLeft = 8;
}
