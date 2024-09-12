#include "common.h"
#include "fio.h"
#include "ld_addrs.h"
#include "entity.h"
#include "message_ids.h"

extern Mtx Entity_SaveBlock_Mtx;
extern Gfx Entity_SaveBlock_RenderContent[];
extern Gfx Entity_SaveBlock_RenderBlock[];
extern Gfx Entity_SaveBlock_RenderNone[];

extern s32 Entity_SaveBlock_ScriptResume[];

BSS s32 SaveBlockTutorialPrinterClosed;
BSS s32 SaveBlockResultPrinterClosed;
BSS MessagePrintState* SaveBlockTutorialPrinter;
BSS MessagePrintState* SaveBlockResultPrinter;

#if VERSION_PAL
extern Gfx Entity_SaveBlock_RenderBlock_es[];
extern s32 gCurrentLanguage;
#endif

void entity_SaveBlock_setupGfx(s32 index) {
    Gfx* gfxPos = gMainGfxPos;
    Gfx* dlist = Entity_SaveBlock_RenderContent;
    Entity* entity = get_entity_by_index(index);
    SaveBlockData* blockData = entity->dataBuf.saveBlock;
    s32 alpha = 128;
    Matrix4f sp18;
    Matrix4f sp58;

    guMtxL2F(sp18, ENTITY_ADDR(entity, Mtx*, &Entity_SaveBlock_Mtx));
    sp18[3][1] += 12.5f;
    guRotateF(sp58, blockData->angle, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp58);
    guMtxF2L(sp58, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gfxPos++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
    gDPSetCombineMode(gfxPos++, PM_CC_01, PM_CC_02);
    gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, alpha);
    gSPDisplayList(gfxPos++, dlist);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);

#if VERSION_PAL
    switch (gCurrentLanguage) {
        default:
            dlist = ENTITY_ADDR(entity, Gfx*, Entity_SaveBlock_RenderBlock);
            break;

        case LANGUAGE_ES:
            dlist = ENTITY_ADDR(entity, Gfx*, Entity_SaveBlock_RenderBlock_es);
            break;
    }
#else
    dlist = ENTITY_ADDR(entity, Gfx*, Entity_SaveBlock_RenderBlock);
#endif
    guMtxL2F(sp58, ENTITY_ADDR(entity, Mtx*, &Entity_SaveBlock_Mtx));
    sp58[3][1] += 12.5f;
    gDPPipeSync(gfxPos++);
    guMtxF2L(sp58, &gDisplayContext->matrixStack[gMatrixListPos]);

    gSPMatrix(gfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPSetRenderMode(gfxPos++, G_RM_AA_XLU_SURF | Z_CMP, G_RM_AA_XLU_SURF2 | Z_CMP);
    gDPSetCombineMode(gfxPos++, PM_CC_01, PM_CC_02);
    gDPSetPrimColor(gfxPos++, 0, 0, 0, 0, 0, alpha);
    gSPDisplayList(gfxPos++, dlist);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);

    gMainGfxPos = gfxPos;
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
    gPlayerStatusPtr->curSpeed = 0.0f;
}

void entity_SaveBlock_resume_game(void) {
    set_time_freeze_mode(TIME_FREEZE_NORMAL);
    enable_player_input();
}

void entity_SaveBlock_save_data(void) {
    gGameStatusPtr->savedPos.x = gPlayerStatusPtr->pos.x;
    gGameStatusPtr->savedPos.y = gPlayerStatusPtr->pos.y;
    gGameStatusPtr->savedPos.z = gPlayerStatusPtr->pos.z;
    fio_save_game(gGameStatusPtr->saveSlot);
}

void entity_SaveBlock_show_tutorial_message(Entity* entity) {
    if (!get_global_flag(GF_Tutorial_SaveBlock)) {
        SaveBlockTutorialPrinterClosed = FALSE;
        msg_get_printer_for_msg(MSG_Menus_Tutorial_SaveBlock, &SaveBlockTutorialPrinterClosed);
        set_global_flag(GF_Tutorial_SaveBlock);
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
    SaveBlockResultPrinter = msg_get_printer_for_msg(MSG_Menus_SavePrompt, &SaveBlockResultPrinterClosed);
    SaveBlockTutorialPrinter = msg_get_printer_for_msg(MSG_Choice_000A, &SaveBlockTutorialPrinterClosed);
}

void entity_SaveBlock_show_result_message(void) {
    msg_printer_load_msg(MSG_Menus_SaveComplete, SaveBlockResultPrinter);
    sfx_play_sound(SOUND_SAVE_CONFIRM);
}

void entity_SaveBlock_wait_for_close_result(Entity* entity) {
    if (SaveBlockResultPrinterClosed) {
        exec_entity_commandlist(entity);
    }
}

void entity_SaveBlock_wait_for_close_choice(Entity* entity) {
    if (SaveBlockTutorialPrinterClosed) {
        if (SaveBlockTutorialPrinter->curOption == 1) {
            set_entity_commandlist(entity, Entity_SaveBlock_ScriptResume);
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

EntityScript Entity_SaveBlock_Script = {
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

EntityScript Entity_SaveBlock_ScriptResume = {
    es_Call(entity_SaveBlock_resume_game)
    es_SetCallback(NULL, 2)
    es_Jump(Entity_SaveBlock_Script)
    es_End
};

EntityModelScript Entity_SaveBlock_RenderScript = STANDARD_ENTITY_MODEL_SCRIPT(Entity_SaveBlock_RenderNone, RENDER_MODE_SURFACE_XLU_LAYER3);

EntityBlueprint Entity_SavePoint = {
    .flags = ENTITY_FLAG_4000 | ENTITY_FLAG_FIXED_SHADOW_SIZE,
    .typeDataSize = sizeof(SaveBlockData),
    .renderCommandList = Entity_SaveBlock_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_SaveBlock_init,
    .updateEntityScript = Entity_SaveBlock_Script,
    .fpHandleCollision = entity_block_handle_collision,
    { .dma = ENTITY_ROM(SaveBlock) },
    .entityType = ENTITY_TYPE_SAVE_POINT,
    .aabbSize = { 25, 25, 25 }
};
