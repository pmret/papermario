#include "common.h"

extern s32 D_801512F4;
extern s16 D_80155C98;
extern s32 D_80155D88;
ItemEntity** D_801565A0;
extern s16 D_801565A4;
extern s16 D_801565A8;

void clear_character_set(void) {
    D_80155C98 = -1;
}

INCLUDE_ASM(s32, "code_B9D60", clear_printers);

INCLUDE_ASM(s32, "code_B9D60", load_font_data);

INCLUDE_ASM(s32, "code_B9D60", load_font);

INCLUDE_ASM(s32, "code_B9D60", update_messages);

INCLUDE_ASM(s32, "code_B9D60", _update_message);

INCLUDE_ASM(s32, "code_B9D60", render_messages);

INCLUDE_ASM(s32, "code_B9D60", func_80124434);

INCLUDE_ASM(s32, "code_B9D60", func_80124570);

INCLUDE_ASM(s32, "code_B9D60", initialize_printer);

INCLUDE_ASM(s32, "code_B9D60", dma_load_string);

INCLUDE_ASM(s32, "code_B9D60", load_message_to_buffer);

PrintContext* load_string(s32 stringID, s32* a1) {
    return _load_string(stringID, a1, 0);
}

INCLUDE_ASM(s32, "code_B9D60", _load_string);

INCLUDE_ASM(s32, "code_B9D60", load_message_to_printer);

INCLUDE_ASM(s32, "code_B9D60", clamp_printer_coords);

s32 cancel_message(PrintContext* printContext) {
    if ((printContext->stateFlags & 2) == 0) {
        return 0;
    }

    printContext->stateFlags |= 1;
    return 1;
}

void set_message_images(s32* images) {
    D_801512F4 = images;
}

INCLUDE_ASM(s32, "code_B9D60", set_message_string);

INCLUDE_ASM(s32, "code_B9D60", set_message_value);

void close_message(PrintContext* printContext) {
    printContext->stateFlags &= ~0x40;
}

INCLUDE_ASM(s32, "code_B9D60", func_80125C84);

INCLUDE_ASM(s32, "code_B9D60", get_char_width);

INCLUDE_ASM(s32, "code_B9D60", get_string_properties);

INCLUDE_ASM(s32, "code_B9D60", get_string_width);

INCLUDE_ASM(s32, "code_B9D60", func_801264B0);

INCLUDE_ASM(s32, "code_B9D60", draw_string);

INCLUDE_ASM(s32, "code_B9D60", func_80126790);

INCLUDE_ASM(s32, "code_B9D60", func_80126EAC);

INCLUDE_ASM(s32, "code_B9D60", func_80126F78);

INCLUDE_ASM(s32, "code_B9D60", draw_digit);

INCLUDE_ASM(s32, "code_B9D60", draw_number);

INCLUDE_ASM(s32, "code_B9D60", func_80127B70);

INCLUDE_ASM(s32, "code_B9D60", func_80127BA4);

INCLUDE_ASM(s32, "code_B9D60", func_80127D90);

INCLUDE_ASM(s32, "code_B9D60", func_8012C2E0);

INCLUDE_ASM(s32, "code_B9D60", func_8012C324);

INCLUDE_ASM(s32, "code_B9D60", func_8012C9A8);

INCLUDE_ASM(s32, "code_B9D60", func_8012CA08);

INCLUDE_ASM(s32, "code_B9D60", _draw_message_box);

INCLUDE_ASM(s32, "code_B9D60", func_8012D3DC);

INCLUDE_ASM(s32, "code_B9D60", func_8012DB58);

INCLUDE_ASM(s32, "code_B9D60", func_8012E8E0);

INCLUDE_ASM(s32, "code_B9D60", func_8012E9A0);

INCLUDE_ASM(s32, "code_B9D60", func_8012EC94);

INCLUDE_ASM(s32, "code_B9D60", func_8012F500);

INCLUDE_ASM(s32, "code_B9D60", func_8012FE10);

INCLUDE_ASM(s32, "code_B9D60", func_8012FE78);

INCLUDE_ASM(s32, "code_B9D60", func_801309F0);

INCLUDE_ASM(s32, "code_B9D60", func_80130A04);

INCLUDE_ASM(s32, "code_B9D60", func_80130ACC);

INCLUDE_ASM(s32, "code_B9D60", draw_coin_sparkles);

ItemEntity* get_item_entity(s32 itemEntityIndex) {
    return D_801565A0[itemEntityIndex];
}

INCLUDE_ASM(s32, "code_B9D60", func_80130F70);

INCLUDE_ASM(s32, "code_B9D60", func_80130FAC);

INCLUDE_ASM(s32, "code_B9D60", clear_item_entity_data);

INCLUDE_ASM(s32, "code_B9D60", init_item_entity_list);

INCLUDE_ASM(s32, "code_B9D60", func_80131128);

INCLUDE_ASM(s32, "code_B9D60", make_item_entity);

INCLUDE_ASM(s32, "code_B9D60", make_item_entity_nodelay, s32 itemID, f32 x, f32 y, f32 z,
            ItemSpawnMode itemSpawnMode, s32 pickupVar);

INCLUDE_ASM(void, "code_B9D60", make_item_entity_delayed, s32 itemID, f32 x, f32 y, f32 z, s32 unk1,
            s32 unk2,
            s32 unk3);

INCLUDE_ASM(s32, "code_B9D60", init_got_item);

INCLUDE_ASM(s32, "code_B9D60", func_80131DD4);

INCLUDE_ASM(s32, "code_B9D60", update_item_entities);

INCLUDE_ASM(s32, "code_B9D60", appendGfx_item_entity);

INCLUDE_ASM(s32, "code_B9D60", draw_item_entities);

INCLUDE_ASM(s32, "code_B9D60", func_80132D94);

INCLUDE_ASM(s32, "code_B9D60", render_item_entities);

INCLUDE_ASM(s32, "code_B9D60", remove_item_entity_by_reference);

INCLUDE_ASM(s32, "code_B9D60", remove_item_entity_by_index);

INCLUDE_ASM(s32, "code_B9D60", func_80133A94);

INCLUDE_ASM(s32, "code_B9D60", test_item_player_collision);

INCLUDE_ASM(s32, "code_B9D60", func_80133FC8);

INCLUDE_ASM(void, "code_B9D60", set_item_entity_flags, s32 itemEntityIndex, s32 flag);

INCLUDE_ASM(s32, "code_B9D60", clear_item_entity_flags);

INCLUDE_ASM(s32, "code_B9D60", func_801341B0);

s32 func_801341E8(void) {
    s32 ret = D_801565A8 != 0;

    if (D_801565A4 != 0) {
        ret = 1;
    }
    return ret;
}

void set_item_entity_position(s32 itemEntityIndex, f32 x, f32 y, f32 z) {
    ItemEntity* itemEntity = D_801565A0[itemEntityIndex];

    itemEntity->position.x = x;
    itemEntity->position.y = y;
    itemEntity->position.z = z;
}

void func_80134230(s32 arg0) {
    D_80155D88 = arg0;
}

s32 func_80134240(void) {
    return D_80155D88;
}

INCLUDE_ASM(s32, "code_B9D60", update_item_entity_collectable);

INCLUDE_ASM(s32, "code_B9D60", func_8013559C);

INCLUDE_ASM(s32, "code_B9D60", update_item_entity_static);

void func_801356C4(void) {
}

void func_801356CC(void) {
}

void func_801356D4(void) {
}

INCLUDE_ASM(s32, "code_B9D60", update_item_entity_temp);

INCLUDE_ASM(s32, "code_B9D60", func_801363A0);

INCLUDE_ASM(s32, "code_B9D60", func_8013673C);

INCLUDE_ASM(s32, "code_B9D60", func_801369D0);

INCLUDE_ASM(s32, "code_B9D60", func_80136A08);
