#ifndef _MSG_H_
#define _MSG_H_

#include "common.h"

typedef struct UnkMsgStruct8;

extern s32 D_802EF0D0;

s32 D_8014C280[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000, };

s32 MessagePlural = 0x53FD0000;

s16 MessageSingular = 0xF0FD;

s16 gNextMessageBuffer = 0;

s32 D_8014C298[] = { 0xFFF00009, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00100009, 0x00000000, 0x04000000, 0xFFFFFFFF, 0xFFF0FFF7, 0x00000000, 0x00000240, 0xFFFFFFFF, 0x0010FFF7, 0x00000000, 0x04000240, 0xFFFFFFFF, };

extern Gfx D_8014C2D8[];

extern Gfx D_8014C368[];

s32 D_8014C3C0[] = { 0x00010000, 0x00000000, 0x00000000, 0xFFFFF8FF, 0x00200000, 0x00000000, 0x04000000, 0xFFFFF8FF, 0x0001FFC0, 0x00000000, 0x00000800, 0xBFB8B0FF, 0x0020FFC0, 0x00000000, 0x04000800, 0xBFB8B0FF, };

s32 D_8014C400[] = { 0x00200000, 0x00000000, 0x00000000, 0xFFFFF8FF, 0x00E10000, 0x00000000, 0x01000000, 0xFFFFF8FF, 0x0020FFC0, 0x00000000, 0x00000800, 0xBFB8B0FF, 0x00E1FFC0, 0x00000000, 0x01000800, 0xBFB8B0FF, };

s32 D_8014C440[] = { 0x00E10000, 0x00000000, 0x00000000, 0xFFFFF8FF, 0x01000000, 0x00000000, 0x04000000, 0xFFFFF8FF, 0x00E1FFC0, 0x00000000, 0x00000800, 0xBFB8B0FF, 0x0100FFC0, 0x00000000, 0x04000800, 0xBFB8B0FF, };

s32 D_8014C480[] = { 0xFFF1001E, 0x00000000, 0x00000000, 0xBFB8B0FF, 0x000F001E, 0x00000000, 0x01E00000, 0xBFB8B0FF, 0xFFFF0000, 0x00000000, 0x000001E0, 0xBFB8B0FF, 0x00010000, 0x00000000, 0x01E001E0, 0xBFB8B0FF, };

s32 D_8014C4C0[] = { 0xFFF1001E, 0x00000000, 0x00000000, 0xBFB8B0FF, 0x000F001E, 0x00000000, 0x01E00000, 0xBFB8B0FF, 0xFFFF0000, 0x00000000, 0x000001E0, 0xBFB8B0FF, 0x00010000, 0x00000000, 0x01E001E0, 0xBFB8B0FF, };

extern Gfx D_8014C500[];

u8 D_8014C580[] = { 50, 80, 100, 105, 100, 0, 0, 0 };

u8 D_8014C588[] = { 105, 100, 77, 57, 40, 27, 16, 8, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// BSS
extern s32 gMsgBGScrollAmtX;
extern u16 gMsgGlobalWaveCounter;
extern s32 gMsgVarImages; // message images?
extern s32 gMsgBGScrollAmtY;
extern s32 D_80151338;
extern char gMessageBuffers[][1024];
extern u8 gMessageMsgVars[3][32];
extern s16 D_80155C98;
extern Matrix4s gMessageWindowProjMatrix[2];
extern MessageDrawState* gMessageDrawStatePtr;

// another file?

extern s32 D_802ED550;

extern s32 D_802ED670;

extern s32 D_802ED970;

extern s32 D_802EE8D0;

extern MessageCharset* gMsgCharsets[5];

extern s32 D_802F39D0;

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
