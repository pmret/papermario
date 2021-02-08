#include "common.h"

extern Gfx D_8014C500[];
extern s32 D_801512F4; // message images?
extern s16 D_80155C98;

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

INCLUDE_ASM(s32, "code_B9D60", get_msg_lines);

INCLUDE_ASM(s32, "code_B9D60", draw_string);

INCLUDE_ASM(s32, "code_B9D60", func_80126790);

INCLUDE_ASM(s32, "code_B9D60", func_80126EAC);

INCLUDE_ASM(s32, "code_B9D60", func_80126F78);

INCLUDE_ASM(s32, "code_B9D60", draw_digit);

INCLUDE_ASM(s32, "code_B9D60", draw_number);

void func_80127B70(s32 arg0) {
    func_80127D90(arg0, 0, 0, 0, 0, 4, 0);
}

INCLUDE_ASM(s32, "code_B9D60", func_80127BA4);

INCLUDE_ASM(s32, "code_B9D60", func_80127D90);


void func_8012C2E0(void) {
    gDPPipeSync(gMasterGfxPos++);
    gSPDisplayList(gMasterGfxPos++, D_8014C500);
}

INCLUDE_ASM(s32, "code_B9D60", func_8012C324);

INCLUDE_ASM(s32, "code_B9D60", func_8012C9A8);

INCLUDE_ASM(s32, "code_B9D60", func_8012CA08);

INCLUDE_ASM(s32, "code_B9D60", _draw_message_box);

INCLUDE_ASM(s32, "code_B9D60", func_8012D3DC);

INCLUDE_ASM(s32, "code_B9D60", func_8012DB58);

INCLUDE_ASM(s32, "code_B9D60", func_8012E8E0);
