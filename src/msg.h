#ifndef _MSG_H_
#define _MSG_H_

#include "common.h"

typedef struct UnkMsgStruct8;

s32 MessagePlural;

s16 MessageSingular;

void load_font_data(Addr offset, u16 size, void* dest);

void load_font(s32 font);

s32 _update_message(MessagePrintState*);

void appendGfx_message(MessagePrintState*, s16, s16, u16, u16, u16, u8);

void appendGfx_msg_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 ulX, u16 ulY, u16 lrX, u16 lrY);

void get_msg_properties(s32 msgID, s32* height, s32* width, s32* maxLineChars, s32* numLines,
                           s32* maxLinesPerPage, s32* arg6, s32 charset);

void clear_character_set(void);

void clear_printers(void);

void update_messages(void);

void render_messages(void);

void msg_play_speech_sound(MessagePrintState* printer, u8 character);

//msg_copy_to_print_buffer;

//_update_message;

void initialize_printer(MessagePrintState* printer, s32 arg1, s32 arg2);

void dma_load_msg(u32 msgID, void* dest);

s32* load_message_to_buffer(s32 msgID);

//_msg_get_printer_for_msg;

void msg_printer_set_origin_pos(MessagePrintState* msgPrintState, s16 x, s16 y);

s32 cancel_message(MessagePrintState* msgPrintState);

void set_message_msg(s32 msgID, s32 index);

void set_message_value(s32 value, s32 index);

void close_message(MessagePrintState* msgPrintState);

s32 msg_get_print_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u8 flags);

//s32 msg_get_draw_char_width;

//get_msg_properties;

s32 get_msg_width(s32 msgID, u16 charset);

s32 get_msg_lines(s32 msgID);

void draw_msg(s32 msgID, s32 posX, s32 posY, s32 opacity, s32 palette, u8 style);

//msg_update_rewind_arrow;

void msg_draw_rewind_arrow(s32 printerIndex);

//msg_draw_choice_pointer;

//draw_digit;

//draw_number;

void drawbox_message_delegate(MessagePrintState* printer);

void draw_message_window(MessagePrintState* printer);

//appendGfx_message;

void msg_reset_gfx_state(void);

//msg_draw_char;

void msg_draw_prim_rect(u8 r, u8 g, u8 b, u8 a, s32 posX, s32 posY, s32 sizeX, s32 sizeY);

//msg_draw_speech_bubble;

//msg_draw_speech_arrow;

//msg_draw_frame;

void msg_get_glyph(s32 font, s32 variation, s32 charIndex, s32 palette, MesasgeFontGlyphData* out);

#endif
