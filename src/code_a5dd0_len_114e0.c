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

extern s32 D_8015132C;
extern Fog* wFog;

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

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8010FE44);

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

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80110678);

INCLUDE_ASM(u32, "code_a5dd0_len_114e0", get_entity_type, s32 arg0);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", delete_entity);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", delete_entity_and_unload_data);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011085C);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", entity_get_collision_flags);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_801109DC);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", test_player_entity_aabb);

s32 is_player_action_state(ActionState actionState) {
    return actionState == gPlayerActionState;
}

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80110BCC);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80110BF8);

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

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", set_next_game_mode);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", _set_game_mode);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112D84);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112DD4);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112DFC);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112E24);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112E4C);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", step_current_game_mode);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_80112EEC);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", render_ui);

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

INCLUDE_ASM(void, "code_a5dd0_len_114e0", clone_model, u16 srcModelID, u16 newModelID);

INCLUDE_ASM(void, "code_a5dd0_len_114e0", func_8011B7C0, u16 arg0, s32 arg1, s32 arg2);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011B950);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011BAE8);

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

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", set_main_pan_u);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", set_main_pan_v);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", set_aux_pan_u);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", set_aux_pan_v);

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

void func_8011D72C(Gfx** arg0, s32 treeIndex) {
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex & 0xFFFF));
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

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", queue_render_task);

INCLUDE_ASM(s32, "code_a5dd0_len_114e0", func_8011D9B8);
