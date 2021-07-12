.include "macro.inc"

.section .data

glabel D_E0200690
.word 0x1E6D3457

glabel D_E0200694
.word guRotateF

glabel D_E0200698
.word guTranslateF

glabel D_E020069C
.word guTranslate

glabel D_E02006A0
.word guScaleF

glabel D_E02006A4
.word guMtxCatF

glabel D_E02006A8
.word guMtxF2L

glabel D_E02006AC
.word guMtxL2F

glabel D_E02006B0
.word queue_render_task

glabel D_E02006B4
.word func_8005A2BC

glabel D_E02006B8
.word remove_effect

glabel D_E02006BC
.word general_heap_malloc

glabel D_E02006C0
.word mem_clear

glabel D_E02006C4
.word 0x00000000

glabel D_E02006C8
.word rand_int

glabel D_E02006CC
.word clamp_angle

glabel D_E02006D0
.word sin_deg

glabel D_E02006D4
.word cos_deg

glabel D_E02006D8
.word atan2

glabel D_E02006DC
.word npc_raycast_down_sides

glabel D_E02006E0
.word load_effect

glabel D_E02006E4
.word sqrtf

glabel D_E02006E8
.word mdl_draw_hidden_panel_surface

glabel D_E02006EC
.word func_8011CFBC

glabel D_E02006F0
.word guPerspectiveF

glabel D_E02006F4
.word guMtxIdentF

glabel D_E02006F8
.word transform_point

glabel D_E02006FC
.word guLookAtHiliteF

glabel D_E0200700
.word set_screen_overlay_params_back

glabel D_E0200704
.word set_screen_overlay_center

glabel D_E0200708
.word set_screen_overlay_center_worldpos

glabel D_E020070C
.word mdl_get_next_texture_address

glabel D_E0200710
.word guPositionF

glabel D_E0200714
.word guOrthoF

glabel D_E0200718
.word guFrustumF

glabel D_E020071C
.word func_80138D88

glabel D_E0200720
.word draw_box

glabel D_E0200724
.word draw_string

glabel D_E0200728
.word get_string_width

glabel D_E020072C
.word get_background_color_blend

glabel D_E0200730
.word sfx_play_sound_at_position

glabel D_E0200734
.word 0x100B2AF5, 0x45B59924, 0x35094B45, 0x4ABFA67A, 0x164F5371, 0x7B195845, 0x58562A56, 0x25733D41, 0x48008107, 0x0E004F28, 0x6963B8AD, 0x5B82AB71, 0x6BC1F51B, 0x3D947816, 0x39705175, 0x44409A59, 0x0ED99067, 0x5F70B6F8, 0x3225AEEE, 0x08B5E97C, 0x2CDE7594, 0x5E9E5B7D, 0x5B2A2888, 0x107F0F50, 0x58FBC53B, 0x65F69F19, 0x3AF6CEF3, 0x15C3894F, 0x4C931A2C, 0x39A897E9, 0x5945BB8C, 0x5C9E4521, 0x7F5E310D, 0x0E4F06D2, 0x275DEB9C, 0x15AD847F, 0x09685F17, 0x7FB415F2, 0x3B20C1C0, 0x5168E01E, 0x0DB4651A, 0x24847A6D, 0x2CEB8B8F, 0x79765A35, 0x6218F283, 0x665BDD04, 0x3DB6F48F, 0x70F282EB, 0x45CC93FC, 0x6FDCA37D, 0x79A86C67, 0x72AB0990, 0x4E7AFEFA, 0x54D294F0, 0x032A18E0, 0x2776C435, 0x3AC93409, 0x3E20E7D4, 0x3D3A4D85, 0x075C4E35, 0x77C97FBD, 0x16800911, 0x63FA9357, 0x7727B0CB, 0x24CF0FE3, 0x0B587EF3, 0x0CD5354A, 0x2E376EFA, 0x0B0C94E5, 0x47F5F70A, 0x7FA04F19, 0x18C0FA00, 0x6C7A7178, 0x2C8BDAA8, 0x12375435, 0x4E9363FB, 0x12E7B7AD, 0x4FEE48C4, 0x3F85E6E6, 0x58B44BA9, 0x3FCAEC41, 0x392E534E, 0x4B5F553A, 0x0E45EB3C, 0x0E00E83E, 0x4E896E1A, 0x35BCAF71, 0x48CA1C47, 0x0CAA55EE, 0x72F6FCF6, 0x50266A7D, 0x0473D5AC, 0x09770608, 0x3420FDD4, 0x7B9B8677, 0x2E4615EB, 0x3F797CC7, 0x0870BBC1, 0x5C7D84E6, 0x4A8611AC, 0x5066B2CB, 0x5C1DD3FF, 0x63470BAC, 0x3CE12443, 0x08A9AEA7, 0x757E5FE2, 0x0B74883F, 0x1B916654, 0x456CA8A6, 0x4AFA6F25, 0x7445B1FE, 0x053794E8, 0x0428C273, 0x3FA50738, 0x137D8024, 0x1229AAB1, 0x0E2E7552, 0x493A2F95, 0x5AF3C6F9, 0x1AD8CB41, 0x3C312C8C, 0x2B1A3176, 0x1F4CA0ED, 0x45A83294, 0x5F3B2F4A, 0x1AE82764, 0x73EE487F, 0x1EB4AC11, 0x00000000, 0x00000000, 0x00000000
