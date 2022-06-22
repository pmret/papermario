#include "common.h"
#include "fio.h"
#include "ld_addrs.h"
#include "entity_script.h"

extern s32 D_802E99DC[];

extern s32 D_0A003260;
extern Gfx D_0A0034E0[];
extern s32 D_0A0034F0;
extern UNK_TYPE D_0A003508;

void entity_SaveBlock_setupGfx(s32 index) {
    Gfx* gfxPos = gMasterGfxPos;
    Entity* entity = get_entity_by_index(index);
    SaveBlockData* blockData = entity->dataBuf.saveBlock;
    Matrix4f sp18;
    Matrix4f sp58;
    u16 s4;
    s32 s2;
    u16 v0;

    s4 = (s32)(&D_0A003260);
    guMtxL2F(sp18, (Mtx*)((s32)entity->vertexData + s4));
    sp18[3][1] += 12.5f;
    guRotateF(sp58, blockData->angle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp58);
    guMtxF2L(sp58, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gfxPos++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
    gDPSetCombineLERP(gfxPos++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, 128);
    gSPDisplayList(gfxPos++, D_0A0034E0);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);

    v0 = (s32)(&D_0A0034F0);
    s2 = (s32)entity->vertexData + v0;
    guMtxL2F(sp58, (Mtx*)((s32)entity->vertexData + s4));
    sp58[3][1] += 12.5f;
    gDPPipeSync(gfxPos++);
    guMtxF2L(sp58, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gfxPos++, G_RM_AA_XLU_SURF | Z_CMP, G_RM_AA_XLU_SURF2 | Z_CMP);
    gDPSetCombineLERP(gfxPos++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, 128);
    gSPDisplayList(gfxPos++, s2);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);

    gMasterGfxPos = gfxPos;
}

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

EntityScript D_802E9930 = {
    es_SetCallback(entity_SaveBlock_idle, 0)
    es_PlaySound(SOUND_HIT_BLOCK)
    es_Call(entity_SaveBlock_pause_game)
    es_Call(entity_block_hit_init_scale)
    es_SetCallback(entity_block_hit_animate_scale, 6)
    es_SetCallback(NULL, 2)
    es_Call(entity_SaveBlock_show_tutorial_message)
    es_SetCallback(entity_SaveBlock_wait_for_close_tutorial, 0)
    es_SetCallback(NULL, 14)
    es_Call(entity_SaveBlock_show_choice_message)
    es_SetCallback(entity_SaveBlock_wait_for_close_choice, 0)
    es_Call(entity_SaveBlock_save_data)
    es_Call(entity_SaveBlock_show_result_message)
    es_SetCallback(entity_SaveBlock_wait_for_close_result, 0)
    es_Call(entity_SaveBlock_resume_game)
    es_SetCallback(NULL, 12)
    es_Restart
    es_End
};
s32 D_802E99DC[8] = {
    0x00000002,(s32)entity_SaveBlock_resume_game, 0x00000003, 0x00000002, 0x00000000,
    0x00000001, (s32)D_802E9930, 0x00000000,
};

s32 D_802E99FC[7] = {
    0x00000004, 0x00000022, 0x00000001, 0x0000003C,
    &D_0A003508, 0x00000002, 0x00000000,
};

EntityBlueprint Entity_SavePoint = {
    0x4200, 0x0020, &D_802E99FC, {0, 0, 0, 0}, entity_SaveBlock_init, D_802E9930, entity_block_handle_collision, E4B2E0_ROM_START, E4B2E0_ROM_END, ENTITY_TYPE_SAVE_POINT, { 25, 25, 25 }
};
