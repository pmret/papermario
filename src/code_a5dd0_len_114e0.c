#include "common.h"
#include "ld_addrs.h"

typedef struct Fog {
    /* 0x00 */ s32 enabled;
    /* 0x04 */ s32 r;
    /* 0x08 */ s32 g;
    /* 0x0C */ s32 b;
    /* 0x10 */ s32 a;
    /* 0x14 */ s32 startDistance;
    /* 0x18 */ s32 endDistance;
} Fog; // size = 0x1C

typedef struct RenderTaskEntry {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ struct Model* model;
    /* 0x0C */ UNK_FUN_PTR(fpBuildDL); /* function for making display list for model */
} RenderTaskEntry; // size = 0x10

typedef Model* SmallModelList[4];
extern SmallModelList* D_801512E0;

extern s32 D_8015132C;
extern Fog* wFog;

extern s32 D_801533B0; // num render task entries?
extern s32 D_801533AC;
extern s32 D_8014C188[]; // render mode -> distance map?
extern RenderTaskEntry* D_801533A0[];

extern s32 texPannerMainU[MAX_TEX_PANNERS];
extern s32 texPannerMainV[MAX_TEX_PANNERS];
extern s32 texPannerAuxU[MAX_TEX_PANNERS];
extern s32 texPannerAuxV[MAX_TEX_PANNERS];
extern s32 D_8014AFB0;

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", update_entities);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", update_shadows);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", set_entity_updatecmd);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", step_entity_updatecmd);

INCLUDE_ASM(void, "code_a5dd0_len_114e0", exec_entity_updatecmd, Entity* entity);

void func_8010FD98(s32 arg0, s32 alpha) {
    if (alpha >= 255) {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        gDPSetCombineMode(gMasterGfxPos++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    } else {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0x00, 0x00, 0x00, alpha);
    }
}

void func_8010FE44(s32 arg0) {
    func_8010FD98(arg0, D_8014AFB0);
}

void entity_model_set_shadow_color(s32 alpha) {
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, 0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, 0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0x00, 0x00, 0x00, alpha);
}

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", render_entities);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", render_shadows);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", update_entity_transform_matrix);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", update_shadow_transform_matrix);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", update_entity_inverse_rotation_matrix);

Entity* get_entity_by_index(s32 index) {
    return (*gCurrentEntityListPtr)[index & 0xFFF];
}

Shadow* get_shadow_by_index(s32 index) {
    return (*gCurrentShadowListPtr)[index & 0xFFF];
}

EntityList* get_entity_list(void) {
    EntityList* ret;

    if (!gGameStatusPtr->isBattle) {
        ret = &gWorldEntityList;
    } else {
        ret = &gBattleEntityList;
    }
    return ret;
}

ShadowList* get_shadow_list(void) {
    ShadowList* ret;

    if (!gGameStatusPtr->isBattle) {
        ret = &gWorldShadowList;
    } else {
        ret = &gBattleShadowList;
    }
    return ret;
}

s32 func_80110678(Npc *npc) {
    if (npc->currentAnim != 0) {
        npc->flags |= 0x1000000;
        return 1;
    }
    return 0;
}

u32 get_entity_type(s32 index) {
    Entity* entity = get_entity_by_index(index);

    if (entity == NULL) {
        return -1;
    } else {
        return entity->staticData->entityType;
    }
}

void delete_entity(s32 entityIndex) {
    Entity* entity;
    Shadow* shadow;
    EntityList** currentEntityListPtrTemp;

    entity = get_entity_by_index(entityIndex);
    if (entity->dataBuf != NULL) {
        heap_free(entity->dataBuf);
    }

    if (!(entity->flags & 8)) {
        free_entity_model_by_index(entity->virtualModelIndex);
    } else {
        func_8011E438(get_anim_mesh(entity->virtualModelIndex));
    }

    if (entity->shadowIndex >= 0) {
        shadow = get_shadow_by_index(entity->shadowIndex);
        shadow->flags |= 0x10000000;
    }

    currentEntityListPtrTemp = &gCurrentEntityListPtr;
    heap_free((**currentEntityListPtrTemp)[entityIndex]);
    (**currentEntityListPtrTemp)[entityIndex] = NULL;
}

s32 delete_entity_and_unload_data(s32 entityIndex) {
    Entity* entity;
    Shadow* shadow;
    EntityList** currentEntityListPtrTemp;

    entity = get_entity_by_index(entityIndex);
    if (entity->dataBuf != NULL) {
        heap_free(entity->dataBuf);
    }

    if (!(entity->flags & 8)) {
        free_entity_model_by_index(entity->virtualModelIndex);
    } else {
        func_8011E438(get_anim_mesh(entity->virtualModelIndex));
    }
    func_801117DC(entity->staticData);

    if (entity->shadowIndex >= 0) {
        shadow = get_shadow_by_index(entity->shadowIndex);
        shadow->flags |= 0x10000000;
    }

    currentEntityListPtrTemp = &gCurrentEntityListPtr;
    heap_free((**currentEntityListPtrTemp)[entityIndex]);
    (**currentEntityListPtrTemp)[entityIndex] = NULL;
}

//INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011085C);
s32 func_8011085C(s32 entityIndex) {
    s32 temp_s0;
    s32 temp_v0;
    Shadow* shadow;
    ShadowList** currentShadowListPtr = &gCurrentShadowListPtr;

    shadow = get_shadow_by_index(entityIndex);
    free_entity_model_by_index(shadow->unk_08);
    heap_free((**currentShadowListPtr)[entityIndex]);
    (**currentShadowListPtr)[entityIndex] = NULL;
}

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", entity_get_collision_flags);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_801109DC);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", test_player_entity_aabb);

s32 is_player_action_state(ActionState actionState) {
    return actionState == gPlayerActionState;
}

void func_80110BCC(Entity *entity) {
    if (!(entity->flags & 8)) {
        func_80122D7C(entity->virtualModelIndex);
    }
}

void func_80110BF8(Entity *entity) {
    entity->unk_07 = 0;
    entity->flags &= ~0x00010000;
}

#ifdef NON_MATCHING
#define AREA_SPECIFIC_ENTITY_VRAM &entity_default_VRAM
#else
#define AREA_SPECIFIC_ENTITY_VRAM 0x802BAE00
#endif

void load_area_specific_entity_data(void) {
    if (D_8015132C == 0) {
        if (gGameStatusPtr->areaID == AREA_JAN || gGameStatusPtr->areaID == AREA_IWA) {
            dma_copy(&entity_jan_iwa_ROM_START, &entity_jan_iwa_ROM_END, AREA_SPECIFIC_ENTITY_VRAM);
        } else if (gGameStatusPtr->areaID == AREA_SBK || gGameStatusPtr->areaID == AREA_OMO) {
            dma_copy(&entity_sbk_omo_ROM_START, &entity_sbk_omo_ROM_END, AREA_SPECIFIC_ENTITY_VRAM);
        } else {
            dma_copy(&entity_default_ROM_START, &entity_default_ROM_END, AREA_SPECIFIC_ENTITY_VRAM);
        }

        D_8015132C = 1;
    }
}

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", clear_entity_data);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80110E58);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80110F10);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_801110B4);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", is_entity_data_loaded);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", load_simple_entity_data);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", load_split_entity_data);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80111790);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_801117DC);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", create_entity, StaticEntityData* data, s32 x, s32 y, s32 z, s32 arg4,
            s32 flags);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", create_shadow_from_data);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", MakeEntity, ScriptInstance* script, s32 isInitialCall);


INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80111E9C);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", UseDynamicShadow);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", AssignScript, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", AssignAreaFlag, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", AssignBlockFlag, ScriptInstance* script, s32 isInitialCall);

ApiStatus AssignFlag(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Trigger* trigger;

    if (isInitialCall == TRUE) {
        trigger = (Trigger*)get_entity_by_index(gLastCreatedEntityIndex)->dataBuf;
        trigger->flags.bytes.genericFlagIndex = get_variable_index(script, *args);
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE1;
}

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", AssignPanelFlag, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", AssignCrateFlag, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", create_entity_shadow);

INCLUDE_ASM(Shadow*, "code_a5dd0_len_114e0", create_shadow_type, s32 type, f32 x, f32 y, f32 z);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112328);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112344);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_801125E8);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", set_standard_shadow_scale);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", set_npc_shadow_scale);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", set_peach_shadow_scale);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112B20);

void NOP_state(void) {
}

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112B98);

typedef struct GameMode {
    /* 0x00 */ u16 flags;
    /* 0x04 */ void (*init)(void);
    /* 0x08 */ void (*step)(struct GameMode*);
    /* 0x0C */ UNK_FUN_PTR(unk_0C);
    /* 0x10 */ void (*render)(void);
    /* 0x14 */ void (*renderAux)(void); ///< @see func_80112FC4
} GameMode; // size = 0x18

extern GameMode gMainGameState[2]; // TODO rename

// regalloc?
#ifndef NON_MATCHING
INCLUDE_ASM(s32, "code_a5dd0_len_114e0", set_next_game_mode);
#else
GameMode* set_next_game_mode(GameMode* arg0) {
    GameMode* gameMode;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameState); i++) {
        gameMode = &gMainGameState[i];
        if (gameMode->flags == 0) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gMainGameState));

    gameMode->flags = 1 | 2;
    gameMode->init = arg0->init;
    gameMode->unk_08 = arg0->unk_08;
    gameMode->render = arg0->render;
    gameMode->unk_0C = NULL;
    if (gameMode->init == NULL) gameMode->init = &NOP_state;
    if (gameMode->step == NULL) gameMode->step = &NOP_state;
    if (gameMode->unk_0C == NULL) gameMode->unk_0C = &NOP_state;
    if (gameMode->render == NULL) gameMode->render = &NOP_state;

    gameMode->renderAux = &NOP_state;
    gameMode->init();

    return gameMode;
}
#endif

GameMode* set_game_mode_slot(s32 i, GameMode* arg0) {
    GameMode* gameModes = &gMainGameState;
    GameMode* gameMode = &gameModes[i];

    ASSERT(i < ARRAY_COUNT(gMainGameState));

    gameMode->flags = 1 | 2;
    gameMode->init = arg0->init;
    gameMode->step = arg0->step;
    gameMode->render = arg0->render;
    gameMode->unk_0C = NULL;
    if (gameMode->init == NULL) gameMode->init = &NOP_state;
    if (gameMode->step == NULL) gameMode->step = &NOP_state;
    if (gameMode->unk_0C == NULL) gameMode->unk_0C = &NOP_state;
    if (gameMode->render == NULL) gameMode->render = &NOP_state;

    gameMode->renderAux = &NOP_state;
    gameMode->init();

    return gameMode;
}

void func_80112D84(s32 i, void (*fn)(void)) {
    GameMode* gameModes = &gMainGameState;
    GameMode* gameMode = &gameModes[i];

    ASSERT(i < ARRAY_COUNT(gMainGameState));

    gameMode->renderAux = fn;
    gameMode->flags |= 0x20;
    if (fn == NULL) {
        gameMode->renderAux = &NOP_state;
    }
}

void func_80112DD4(s32 i) {
    GameMode* gameModes = &gMainGameState;
    GameMode* gameMode = &gameModes[i];

    gameMode->flags |= 4;
}

void func_80112DFC(s32 i) {
    GameMode* gameModes = &gMainGameState;
    GameMode* gameMode = &gameModes[i];

    gameMode->flags |= 8;
}

void func_80112E24(s32 i) {
    GameMode* gameModes = &gMainGameState;
    GameMode* gameMode = &gameModes[i];

    gameMode->flags &= ~0x1C;
}

void func_80112E4C(s32 i) {
    GameMode* gameModes = &gMainGameState;
    GameMode* gameMode = &gameModes[i];

    gameMode->flags &= ~0x0C;
    gameMode->flags |= 0x10;
}

#ifndef NON_MATCHING
INCLUDE_ASM(s32, "code_a5dd0_len_114e0", step_current_game_mode);
#else
void step_current_game_mode(void) {
    GameMode* gameMode;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameState); i++) {
        gameMode = &gMainGameState[i];
        if (gameMode->flags != 0 && !(gameMode->flags & 4) && !(gameMode->flags & 8)) {
            gameMode->flags &= ~2;
            gameMode->step(gameMode);
        }
    }

    //return i;
}
#endif

// similar to step_current_game_mode, but calls unk_0C
INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112EEC);

// similar to step_current_game_mode, but calls render
INCLUDE_ASM(s32, "code_a5dd0_len_114e0", render_ui);

// calls renderAux and render
INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112FC4);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", appendGfx_model);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80114B58);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", load_tile_header);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80115498);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", get_model_property);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", _load_model_textures);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", load_model_textures);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", mdl_get_child_count);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", clear_model_data);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", init_model_data);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", calculate_model_sizes);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", mdl_create_model);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80116674);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80116698);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", render_models);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", appendGfx_model_group);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80117D00);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80117E74);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011800C);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_801180E8);

Model* get_model_from_list_index(s32 listIndex) {
    return (*gCurrentModelListPtr)[listIndex];
}

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", load_data_for_models);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", load_model_transforms);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", get_model_list_index_from_tree_index, s32 treeIndex);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011B090);

INCLUDE_ASM(void, "code_a5dd0_len_114e0", get_model_center_and_size, s32 modelID, f32* centerX, f32* centerY,
            f32* centerZ, f32* sizeX, f32* sizeY, f32* sizeZ);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011B1C0);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011B1D8);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011B37C);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011B5D0);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011B660);

void clone_model(u16 srcModelID, u16 newModelID) {
    ModelList** modelList = &gCurrentModelListPtr;
    Model* srcModel = get_model_from_list_index(get_model_list_index_from_tree_index(srcModelID));
    Model* newModel;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(**modelList); i++) {
        Model* model = (**modelList)[i];

        if (model == NULL) {
            break;
        }
    }

    (**modelList)[i] = newModel = heap_malloc(sizeof(Model));
    *newModel = *srcModel;
    newModel->modelID = newModelID;
}

INCLUDE_ASM(void, "code_a5dd0_len_114e0", func_8011B7C0, u16 arg0, s32 arg1, s32 arg2);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011B950);

void func_8011BAE8(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentModelListPtr); i++) {
        Model* model = (*gCurrentModelListPtr)[i];

        if (model != NULL) {
            model->flags &= ~0x0400;
        }
    }

    for (i = 0; i < ARRAY_COUNT(*D_801512E0); i++) {
        Model* model = (*D_801512E0)[i];

        if (model != NULL) {
            model->flags &= ~0x0400;
        }
    }
}

void enable_world_fog(void) {
    wFog->enabled = TRUE;
}

void disable_world_fog(void) {
    wFog->enabled = FALSE;
}

void set_world_fog_dist(s32 start, s32 end) {
    wFog->startDistance = start;
    wFog->endDistance = end;
}

void set_world_fog_color(s32 r, s32 g, s32 b, s32 a) {
    wFog->r = r;
    wFog->g = g;
    wFog->b = b;
    wFog->a = a;
}

s32 is_world_fog_enabled(void) {
    return wFog->enabled;
}

void get_world_fog_distance(s32* start, s32* end) {
    Fog** fog = &wFog;

    *start = (*fog)->startDistance;
    *end = (*fog)->endDistance;
}

void get_world_fog_color(s32* r, s32* g, s32* b, s32* a) {
    Fog** fog = &wFog;

    *r = (*fog)->r;
    *g = (*fog)->g;
    *b = (*fog)->b;
    *a = (*fog)->a;
}

void set_tex_panner(Model* model, s8 texPannerID) {
    model->texPannerID = texPannerID;
}

void set_main_pan_u(s32 texPannerID, s32 value) {
    texPannerMainU[texPannerID] = value;
}

void set_main_pan_v(s32 texPannerID, s32 value) {
    texPannerMainV[texPannerID] = value;
}

void set_aux_pan_u(s32 texPannerID, s32 value) {
    texPannerAuxU[texPannerID] = value;
}

void set_aux_pan_v(s32 texPannerID, s32 value) {
    texPannerAuxV[texPannerID] = value;
}

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011BC7C);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011BCB4);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011BCD0);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011BCEC);

/// @returns TRUE if mtx is NULL or identity.
INCLUDE_ASM(s32, "code_a5dd0_len_114e0", is_identity_fixed_mtx);

INCLUDE_ASM(void, "code_a5dd0_len_114e0", set_background_color_blend, u8 r, u8 g, u8 b, u8 a);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", get_background_color_blend);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011BEB4);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011BF14);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011BF98);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011BFD4);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011C028);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011C0DC);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011C130);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011C164);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011C2B0);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011C2EC);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011C32C);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011C80C);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011CFBC);

void func_8011D72C(Gfx** arg0, u16 treeIndex) {
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));
    Model copied = *model;
    Gfx** gfxPos = &gMasterGfxPos;
    Gfx* oldGfxPos;
    s32 flag;

    if (*arg0 == *gfxPos) {
        flag = 1;
    }

    oldGfxPos = *gfxPos;
    *gfxPos = *arg0;

    copied.flags = 0x81;
    appendGfx_model(&copied);

    *arg0 = *gfxPos;

    if (flag == 0) {
        *gfxPos = oldGfxPos;
    }
}

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011D7E4);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011D82C);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011D890);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011D8D0);

RenderTaskEntry* queue_render_task(RenderTask* task) {
    RenderTaskEntry* entry = D_801533A0[D_801533AC];

    ASSERT(D_801533B0 < 0x100);

    entry = &entry[D_801533B0++];

    entry->unk_00 = 1;
    if (task->renderMode == 0x2D) {
        entry->unk_00 = 0x21;
    }

    entry->model = task->model;
    entry->fpBuildDL = task->fpBuildDL;
    entry->unk_04 = D_8014C188[task->renderMode] - task->distance;

    return entry;
}

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011D9B8);
