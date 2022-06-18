#include "common.h"
#include "fio.h"

extern s32 D_802E99DC[];

void entity_SaveBlock_setupGfx();

INCLUDE_ASM(s32, "entity/SaveBlock", entity_SaveBlock_setupGfx);

void entity_SaveBlock_idle(Entity* entity) {
    SaveBlockData* data;

    data = entity->dataBuf.saveBlock;
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
        SaveBlockTutorialPrinterClosed = FALSE;
        msg_get_printer_for_msg(MESSAGE_ID(0x1D, 0x0), &SaveBlockTutorialPrinterClosed);
        set_global_flag(EVT_SAVE_FLAG(95));
        return;
    }

    exec_entity_commandlist(entity);
    exec_entity_commandlist(entity);
}

void entity_SaveBlock_wait_for_close_tutorial(Entity* entity) {
    if (SaveBlockTutorialPrinterClosed) {
        exec_entity_commandlist(entity);
    }
}

void entity_SaveBlock_show_choice_message(void) {
    SaveBlockTutorialPrinterClosed = FALSE;
    SaveBlockResultPrinterClosed = FALSE;
    SaveBlockResultPrinter = msg_get_printer_for_msg(MESSAGE_ID(0x1D, 0x4), &SaveBlockResultPrinterClosed);
    SaveBlockTutorialPrinter = msg_get_printer_for_msg(MESSAGE_ID(0x1E, 0xA), &SaveBlockTutorialPrinterClosed);
}

void entity_SaveBlock_show_result_message(void) {
    msg_printer_load_msg(MESSAGE_ID(0x1D, 0x5), SaveBlockResultPrinter);
    sfx_play_sound(SOUND_10);
}

void entity_SaveBlock_wait_for_close_result(Entity* entity) {
    if (SaveBlockResultPrinterClosed) {
        exec_entity_commandlist(entity);
    }
}

void entity_SaveBlock_wait_for_close_choice(Entity* entity) {
    if (SaveBlockTutorialPrinterClosed) {
        if (SaveBlockTutorialPrinter->currentOption == 1) {
            set_entity_commandlist(entity, D_802E99DC);
        } else {
            exec_entity_commandlist(entity);
        }
        close_message(SaveBlockResultPrinter);
    }
}

void entity_SaveBlock_init(Entity* entity) {
    SaveBlockData* data = entity->dataBuf.saveBlock;

    entity_base_block_init(entity);
    entity->renderSetupFunc = entity_SaveBlock_setupGfx;
    data->angle = 8;
}
