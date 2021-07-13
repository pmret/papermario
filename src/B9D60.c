#include "common.h"

#define MSG_ROM_START 0x1B83000

extern Gfx D_8014C500[];
extern s32 D_801512F4; // message images?
extern s16 D_80155C98;

void clear_character_set(void) {
    D_80155C98 = -1;
}

INCLUDE_ASM(s32, "B9D60", clear_printers);

INCLUDE_ASM(s32, "B9D60", load_font_data);

INCLUDE_ASM(s32, "B9D60", load_font);

INCLUDE_ASM(s32, "B9D60", update_messages);

INCLUDE_ASM(s32, "B9D60", _update_message);

INCLUDE_ASM(s32, "B9D60", render_messages);

INCLUDE_ASM(s32, "B9D60", msg_play_speech_sound);

INCLUDE_ASM(s32, "B9D60", msg_copy_to_print_buffer);

INCLUDE_ASM(s32, "B9D60", initialize_printer);

void dma_load_string(u32 msgID, void* dest) {
    u32 addr = MSG_ROM_START + (msgID >> 14); // (msgID >> 16) * 4
    u32 offset[2]; // start, end

    dma_copy(addr, addr + 4, &offset[0]); // Load section offset

    addr = MSG_ROM_START + offset[0] + (msgID & 0xFFFF) * 4;
    dma_copy(addr, addr + 8, &offset); // Load message start and end offsets

    // Load the msg data
    dma_copy(MSG_ROM_START + offset[0], MSG_ROM_START + offset[1], dest);
}

INCLUDE_ASM(s32, "B9D60", load_message_to_buffer);

PrintContext* msg_get_printer_for_string(s32 stringID, s32* a1) {
    return _msg_get_printer_for_string(stringID, a1, 0);
}

INCLUDE_ASM(s32, "B9D60", _get_printer_for_string);

INCLUDE_ASM(s32, "B9D60", msg_printer_load_string);

INCLUDE_ASM(s32, "B9D60", msg_printer_set_origin_pos);

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

INCLUDE_ASM(s32, "B9D60", set_message_string);

INCLUDE_ASM(s32, "B9D60", set_message_value);

void close_message(PrintContext* printContext) {
    printContext->stateFlags &= ~0x40;
}

INCLUDE_ASM(s32, "B9D60", msg_get_print_char_width);

INCLUDE_ASM(s32, "B9D60", msg_get_draw_char_width);

INCLUDE_ASM(s32, "B9D60", get_string_properties);

INCLUDE_ASM(s32, "B9D60", get_string_width);

INCLUDE_ASM(s32, "B9D60", get_string_lines);

INCLUDE_ASM(s32, "B9D60", draw_string);

INCLUDE_ASM(s32, "B9D60", msg_update_rewind_arrow);

INCLUDE_ASM(s32, "B9D60", msg_draw_rewind_arrow);

INCLUDE_ASM(s32, "B9D60", msg_draw_choice_pointer);

INCLUDE_ASM(s32, "B9D60", draw_digit);

INCLUDE_ASM(void, "B9D60", draw_number, s32 value, s32 x, s32 y, s32 arg3, s32 palette, s32 opacity, s32 style);

void drawbox_message_delegate(s32 arg0) {
    appendGfx_message(arg0, 0, 0, 0, 0, 4, 0);
}

INCLUDE_ASM(s32, "B9D60", draw_message_window);

INCLUDE_ASM(s32, "B9D60", appendGfx_message);


void msg_reset_gfx_state(void) {
    gDPPipeSync(gMasterGfxPos++);
    gSPDisplayList(gMasterGfxPos++, D_8014C500);
}

INCLUDE_ASM(s32, "B9D60", msg_draw_char);

INCLUDE_ASM(s32, "B9D60", msg_draw_prim_rect);

INCLUDE_ASM(s32, "B9D60", appendGfx_msg_prim_rect);

INCLUDE_ASM(s32, "B9D60", msg_draw_speech_bubble);

INCLUDE_ASM(s32, "B9D60", msg_draw_speech_arrow);

INCLUDE_ASM(s32, "B9D60", msg_draw_frame);

INCLUDE_ASM(s32, "B9D60", msg_get_glyph);
