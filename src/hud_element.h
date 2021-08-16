#ifndef HUD_ELEMENT_H
#define HUD_ELEMENT_H

#include "common.h"

s32 load_hud_element();
s32 draw_rect_hud_element();
s32 clear_hud_element_cache();
s32 init_hud_element_list();
HudElement* create_hud_element(s32* iconIndex);
s32 update_hud_elements();
s32 hud_element_update();
s32 render_hud_elements_backUI();
s32 render_hud_elements_frontUI();
s32 render_hud_element();
s32 render_hud_elements_world();
s32 func_80143C48();
void func_80144218(s32 arg0);
void func_80144258(s32 arg0);
void func_80144278(s32 arg0);
s32 draw_hud_element();
void draw_hud_element_clipped(s32 arg0);
void draw_hud_element_2(s32 arg0);
void draw_icon_2(s32 iconID);
void set_hud_element_script(s32 arg0, s32 *arg1);
s32* get_hud_element_script(s32 arg0);
HudElement* get_hud_element(s32 arg0);
void free_hud_element(s32 arg0);
void set_hud_element_render_pos(s32 iconIndex, s32 posX, s32 posY);
void get_hud_element_render_pos(s32 iconIndex, s32* x, s32* y);
s32 set_hud_element_render_depth();
void set_hud_element_flags(s32 iconIndex, s32 flags);
void clear_hud_element_flags(s32 iconIndex, s32 flags);
s32 ALT_clear_hud_element_cache();
void set_hud_element_scale(s32 index, f32 scale);
void set_hud_element_size(s32 arg0, s8 arg1);
s32 func_80144E4C();
void func_80144E74(s32 iconIndex, s32 arg1);
void set_hud_element_alpha(s32 iconIndex, s32 opacity);
void set_hud_element_tint(s32 iconIndex, s32 tint1, s32 tint2, s32 tint3);
s32 create_hud_element_transform_A();
s32 create_hud_element_transform_B();
s32 create_hud_element_transform_C();
void free_hud_element_transform(s32 arg0);
s32 set_hud_element_transform_pos();
s32 set_hud_element_transform_scale();
s32 set_hud_element_transform_rotation();
s32 set_hud_element_transform_rotation_pivot();
s32 copy_world_hud_element_ref_to_battle();
s32 set_hud_element_nonworld_cache();

#endif
