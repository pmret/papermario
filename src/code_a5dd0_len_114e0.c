#include "common.h"

INCLUDE_ASM("code_a5dd0_len_114e0", update_entities);

INCLUDE_ASM("code_a5dd0_len_114e0", update_shadows);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8010FBC0);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8010FBD8);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8010FD68);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8010FD98);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8010FEB4);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801100CC);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011022C);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80110374);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801104A4);

Entity* get_entity_by_index(s32 index) {
    return (*gCurrentEntityListPtr)[index & 0xFFF];
}

Shadow* get_shadow_by_index(s32 index) {
    return (*gCurrentShadowListPtr)[index & 0xFFF];
}

Entity** get_entity_list(void) {
    Entity** ret;

    if (!GAME_STATUS->isBattle) {
        ret = gWorldEntityList;
    } else {
        ret = gBattleEntityList;
    }
    return ret;
}

Shadow** get_shadow_list(void) {
    Shadow** ret;

    if (!GAME_STATUS->isBattle) {
        ret = gWorldShadowList;
    } else {
        ret = gBattleShadowList;
    }
    return ret;
}


INCLUDE_ASM("code_a5dd0_len_114e0", func_80110678);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801106A4);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801106D0);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80110790);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011085C);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801108B8);

INCLUDE_ASM("code_a5dd0_len_114e0", test_player_entity_aabb);

s32 is_player_action_state(ActionState actionState) {
    return actionState == gPlayerActionState;
}

INCLUDE_ASM("code_a5dd0_len_114e0", func_80110BCC);

INCLUDE_ASM("code_a5dd0_len_114e0", load_entity_data);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80110CB8);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80110E58);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80110F10);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801110B4);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011115C);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801112A4);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80111408);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80111790);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801117DC);

INCLUDE_ASM("code_a5dd0_len_114e0", create_entity);

INCLUDE_ASM("code_a5dd0_len_114e0", create_shadow_from_data);

INCLUDE_API_ASM("code_a5dd0_len_114e0", MakeEntity);

INCLUDE_API_ASM("code_a5dd0_len_114e0", AssignScript);

INCLUDE_API_ASM("code_a5dd0_len_114e0", AssignAreaFlag);

INCLUDE_API_ASM("code_a5dd0_len_114e0", AssignBlockFlag);

INCLUDE_API_ASM("code_a5dd0_len_114e0", AssignFlag);

INCLUDE_API_ASM("code_a5dd0_len_114e0", AssignPanelFlag);

INCLUDE_API_ASM("code_a5dd0_len_114e0", AssignCrateFlag);

INCLUDE_ASM("code_a5dd0_len_114e0", create_entity_shadow);

INCLUDE_ASM("code_a5dd0_len_114e0", create_shadow_type);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80112328);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80112344);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801125E8);

INCLUDE_ASM("code_a5dd0_len_114e0", set_standard_shadow_scale);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80112900);

INCLUDE_ASM("code_a5dd0_len_114e0", set_shadow_scale_peach);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80112B20);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80112B98);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80112CA8);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80112D84);

INCLUDE_ASM("code_a5dd0_len_114e0", step_current_game_mode);

INCLUDE_ASM("code_a5dd0_len_114e0", render_ui);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80112FC4);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80113090);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80114B58);

INCLUDE_ASM("code_a5dd0_len_114e0", load_tile_header);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80115498);

INCLUDE_ASM("code_a5dd0_len_114e0", get_model_property);

INCLUDE_ASM("code_a5dd0_len_114e0", _load_model_textures);

INCLUDE_ASM("code_a5dd0_len_114e0", load_model_textures);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80115CA8);

INCLUDE_ASM("code_a5dd0_len_114e0", clear_model_data);

INCLUDE_ASM("code_a5dd0_len_114e0", init_model_data);

INCLUDE_ASM("code_a5dd0_len_114e0", calculate_model_sizes);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011620C);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80116674);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80116698);

INCLUDE_ASM("code_a5dd0_len_114e0", render_models);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80117C94);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80117D00);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80117E74);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801180E8);

Model* get_model_from_list_index(s32 listIndex) {
    return (*gCurrentModelListPtr)[listIndex];
}

INCLUDE_ASM("code_a5dd0_len_114e0", load_data_for_models);

INCLUDE_ASM("code_a5dd0_len_114e0", load_model_transforms);

INCLUDE_ASM("code_a5dd0_len_114e0", get_model_list_index_from_tree_index);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011B090);

INCLUDE_ASM("code_a5dd0_len_114e0", get_model_center_and_size);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011B1C0);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011B1D8);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011B37C);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011B5D0);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011B660);

void INCLUDE_ASM("code_a5dd0_len_114e0", clone_model, u16 srcModelID, u16 newModelID);

void INCLUDE_ASM("code_a5dd0_len_114e0", func_8011B7C0, u16 arg0, s32 arg1, s32 arg2);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011B950);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011BAE8);

INCLUDE_ASM("code_a5dd0_len_114e0", set_world_fog_color);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011BBA4);

INCLUDE_ASM("code_a5dd0_len_114e0", get_fog_color);

void set_tex_panner(Model* model, s8 texPannerID) {
    model->texPannerID = texPannerID;
}

INCLUDE_ASM("code_a5dd0_len_114e0", set_main_pan_u);

INCLUDE_ASM("code_a5dd0_len_114e0", set_main_pan_v);

INCLUDE_ASM("code_a5dd0_len_114e0", set_aux_pan_u);

INCLUDE_ASM("code_a5dd0_len_114e0", set_aux_pan_v);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011BC7C);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011BCB4);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011BCD0);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011BCEC);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011BE14);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011BE5C);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011BE80);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011BFD4);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011C028);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011C0DC);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011C130);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011C164);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011C32C);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011D72C);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011D7E4);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011D82C);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011D890);

INCLUDE_ASM("code_a5dd0_len_114e0", queue_render_task);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011D9B8);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011DE80);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011DFD0);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E014);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E058);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E09C);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E0DC);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E150);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E1C4);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E224);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E310);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E398);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E400);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E438);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E4B8);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E5E0);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E718);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011E8BC);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011EA54);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011EBF0);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011F058);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011F118);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011F304);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011F3E8);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011FA54);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011FF74);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011FF98);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011FFB4);

INCLUDE_ASM("code_a5dd0_len_114e0", func_8011FFE0);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80120000);

INCLUDE_ASM("code_a5dd0_len_114e0", play_model_animation);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80120198);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80120234);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801203AC);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80120420);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80120474);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80120530);

INCLUDE_ASM("code_a5dd0_len_114e0", func_80120678);

INCLUDE_ASM("code_a5dd0_len_114e0", func_801206F8);
