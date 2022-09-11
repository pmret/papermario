.include "macro.inc"

.section .data

dlabel filemenu_hudElemScripts
.word 0x802423DC, nok_02_Quizmo_SetVannaAnim_Wave, 0x8024248C, 0x802424E4, D_8024253C_AB46AC, 0x80242594, dgb_16_npcGroup_802425EC, 0x80242408, flo_14_updateTexturePan_80242460, 0x802424B8, 0x80242510, D_80242568_filemenu, 0x802425C0, D_80242618_9800E8, 0x802422D4, 0x80242300, mac_02_Quizmo_SetCamVfov, omo_09_ProjectileHitbox_GetUsableProjectileID, func_80242384_833B84, D_802423B0

dlabel D_80249E70
.word 0x00000102, 0x02030405, 0x06000001, 0x02020306, 0x06060000, 0x01020203, 0x06060600, 0x00010202, 0x03060606, 0x00000102, 0x02030606, 0x06000000

dlabel filemenu_windowBPs
.word 0x2D000000, 0x00000000, 0x00000000, filemenu_draw_contents_title, 0x00000000, 0x2C000000, filemenu_update_show_title, 0x00000000, D_8024BB08, 0x3300FFFE, 0x00060044, 0x00140000, filemenu_draw_contents_stereo, 0x00000000, 0x2C000000, filemenu_update_show_options_left, 0x00000000, D_8024BAD0, 0x340000DD, 0x00060044, 0x00140000, filemenu_draw_contents_mono, 0x00000000, 0x2C000000, filemenu_update_show_options_right, 0x00000000, D_8024BAD0, 0x35000005, 0x00AB0058, 0x00100000, filemenu_draw_contents_option_left, 0x00000000, 0x2C000000, filemenu_update_show_options_bottom, 0x00000000, D_8024BB40, 0x36000000, 0x00AB0058, 0x00100000, filemenu_draw_contents_option_center, 0x00000000, 0x2C000000, filemenu_update_show_options_bottom, 0x00000000, D_8024BB78, 0x370000C3, 0x00AB0058, 0x00100000, filemenu_draw_contents_option_right, 0x00000000, 0x2C000000, filemenu_update_show_options_bottom, 0x00000000, D_8024BBB0, 0x3A000009, 0x006E0082, 0x00360000, filemenu_draw_contents_file_2_info, 0x00000000, 0x2C000000, filemenu_update_show_options_left, 0x00000000, D_8024BC58, 0x3E000003, 0xFFF8007C, 0x000F0000, filemenu_draw_contents_file_2_title, 0x00000000, 0x3A000000, 0x00000001, 0x00000000, D_8024BD38, 0x3B000095, 0x006E0082, 0x00360000, filemenu_draw_contents_file_3_info, 0x00000000, 0x2C000000, filemenu_update_show_options_right, 0x00000000, D_8024BC90, 0x3F000003, 0xFFF8007C, 0x000F0000, filemenu_draw_contents_file_3_title, 0x00000000, 0x3B000000, 0x00000001, 0x00000000, D_8024BD70, 0x38000009, 0x00290082, 0x00360000, filemenu_draw_contents_file_0_info, 0x00000000, 0x2C000000, filemenu_update_show_options_left, 0x00000000, D_8024BBE8, 0x3C000003, 0xFFF8007C, 0x000F0000, filemenu_draw_contents_file_0_title, 0x00000000, 0x38000000, 0x00000001, 0x00000000, D_8024BCC8, 0x39000095, 0x00290082, 0x00360000, filemenu_draw_contents_file_1_info, 0x00000000, 0x2C000000, filemenu_update_show_options_right, 0x00000000, D_8024BC20, 0x3D000003, 0xFFF8007C, 0x000F0000, filemenu_draw_contents_file_1_title, 0x00000000, 0x39000000, 0x00000001, 0x00000000, D_8024BD00

dlabel D_8024A098
.word 0x00000000, 0x00030300, D_80249E70, filemenu_main_init, filemenu_main_handle_input, filemenu_main_update, filemenu_main_cleanup, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024A0C0
.word 0x00010001, 0x00010001, 0x00010000

dlabel D_8024A0CC
.word 0x32000000, 0x00000000, 0x00004000, filemenu_yesno_draw_options_contents, 0x00000000, 0xFF000000, 0x00000002, 0x00000000, D_8024BE88

dlabel D_8024A0F0
.word 0x2E000000, 0x00000000, 0x00000000, filemenu_yesno_draw_prompt_contents, 0x00000000, 0x32000000, 0x00000001, 0x00000000, D_8024BE88

dlabel D_8024A114
.word 0x00000000, 0x00010200, D_8024A0C0, filemenu_yesno_init, filemenu_yesno_handle_input, filemenu_yesno_update, filemenu_yesno_cleanup

dlabel D_8024A130
.word 0x00000000

dlabel D_8024A134
.word 0x2F000000, 0x00000000, 0x00004000, filemenu_info_draw_message_contents, 0x00000000, 0xFF000000, 0x00000002, 0x00000000, D_8024BEC0

dlabel D_8024A158
.word 0x00000000, 0x00010100, D_8024A130, filemenu_info_init, filemenu_info_handle_input, filemenu_info_update, filemenu_info_cleanup, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024A180
.word dgb_00_init_80241F70, some_80241FBC, kzn_09_UnkNpcAIFunc12

dlabel D_8024A18C
.word 0xFFFFFFFC

dlabel D_8024A190
.word 0x30000044, 0x000A00A4, 0x002E4000, filemenu_draw_contents_file_create_header, 0x00000000, 0x2C000000, 0x00000002, 0x00000000, D_8024BEF8

dlabel D_8024A1B4
.word 0x3100000C, 0x00430106, 0x00714000, filemenu_draw_contents_choose_name, 0x00000000, 0x2C000000, 0x00000002, 0x00000000, D_8024BF30

dlabel D_8024A1D8
.word 0x00000000, 0x000D0600, D_8024B978, filemenu_choose_name_init, filemenu_choose_name_handle_input, filemenu_choose_name_update, filemenu_choose_name_cleanup, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024A200
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x10000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x11000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x11100000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x11110000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x1F111000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x1FF11100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x1FFF1110, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x1FFFF111, 0x00000000, 0x11111111, 0x11111111, 0x11111111, 0x11111111, 0x11111111, 0x11111111, 0x1FFFFF11, 0x10000000, 0x11111111, 0x11111111, 0x11111111, 0x11111111, 0x11111111, 0x11111111, 0x1FFFFFF1, 0x11000000, 0x11FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x11100000, 0x11FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF1110000, 0x11FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFF111000, 0x11FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFF11100

dlabel D_8024A400
.word 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x987F1B20, 0xB09E297B, 0xC3B634C6, 0xD0C73AFF, 0xCEC538FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0x90751600, 0x987F1A20, 0xBDAF30B0, 0xCFC639FF, 0xC7BE33FF, 0xC0B72CFF, 0xBCB329FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0x90751600, 0xB09F288C, 0xCAC135FF, 0xCBBB38FF, 0xBFAD2CFF, 0xB29D24FF, 0xA78F20FF, 0xA2881EFF, 0xA1861DFF, 0xA0851DFF, 0xA0851DFF, 0xA0851DFF, 0xA0851DFF, 0xA0851DFF, 0xA0851DFF, 0xA0851DFF, 0x90751600, 0xBDB22CE1, 0xBEB52BFF, 0xBCAA29FF, 0x9F841CFF, 0x876413FF, 0x78500CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x90751600, 0xBDB42AFF, 0xB4AA22FF, 0xA1871DFF, 0x7D570FFE, 0x4F3408D0, 0x20150399, 0x04020077, 0x02010075, 0x02010075, 0x02010075, 0x02010075, 0x02010075, 0x02010075, 0x02010075, 0x02010075, 0x90751600, 0xBBB128FF, 0xADA31BFF, 0x8C6B15FF, 0x4D3308CF, 0x0604017A, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x866212FF, 0x150E028C, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xA99F19FF, 0x876413FF, 0x02010075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x896713FF, 0x02010075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x8A6814FF, 0x02020075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x8A6814FF, 0x02020075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x8A6814FF, 0x02020075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x8A6814FF, 0x02020075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x896713FF, 0x02020075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x896713FF, 0x02020075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCDC438FF, 0xCCC337FF, 0xC8BF34F8, 0xBAAD2CC6, 0xA794207B, 0x957C1820, 0x90751600, 0x90751600, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB228FF, 0xBCB229FF, 0xB8AF26FF, 0xA6971CB0, 0x937A1620, 0x90751600, 0xA0851DFF, 0xA0851DFF, 0xA0851DFF, 0xA0851DFF, 0xA0851DFF, 0xA0851DFF, 0xA0851DFF, 0xA1871DFF, 0xA58C1FFF, 0xAD9622FF, 0xB6A226FF, 0xBDAB2AFF, 0xAFA51DFF, 0xA69A18FF, 0x947F158C, 0x90751600, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x764E0CFF, 0x79510DFF, 0x886513FF, 0x9D811BFF, 0xB09A23FF, 0xA99F19FF, 0x9F9116FF, 0x8B7311E1, 0x90751600, 0x02010075, 0x02010075, 0x02010075, 0x02010075, 0x02010075, 0x02010075, 0x02010075, 0x02010075, 0x0604017A, 0x22180499, 0x5F490FD0, 0xA38A1FFE, 0xA49817FF, 0x9C8D15FF, 0x82680DFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x0807017A, 0x6F6016CF, 0xA69A18FF, 0x9C8D15FF, 0x7E630CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x221E078C, 0xAEA41DFF, 0xA19316FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x03030175, 0xB6AC23FF, 0xA69B18FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x02020175, 0xB9B026FF, 0xA99F19FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x03030175, 0xBAB127FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x03030175, 0xBAB127FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x03030175, 0xBAB127FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x03030175, 0xBAB127FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x03030175, 0xBAB127FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x03030175, 0xBAB027FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x896713FF, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x8A6814FF, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x8A6814FF, 0x02020075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x8A6814FF, 0x02020075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x8A6814FF, 0x02020075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xAAA019FF, 0x8A6814FF, 0x02020075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xABA11AFF, 0x8B6914FF, 0x02010075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xADA31BFF, 0x927217FF, 0x02020075, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xBAB127FF, 0xB1A71FFF, 0xA2881EFF, 0x1D18058C, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xB9B026FF, 0xB3AA21FF, 0xB4A025FF, 0x756818CF, 0x0A09027A, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x90751600, 0xB7AD24FF, 0xB2A820FF, 0xBCAB2AFF, 0xBEAD2DFE, 0x847923D0, 0x39351099, 0x07060277, 0x03030175, 0x03030175, 0x03030175, 0x03030175, 0x03030175, 0x03030175, 0x03030175, 0x03030175, 0x90751600, 0xACA01DE1, 0xACA21BFF, 0xBCAA29FF, 0xC0AE2DFF, 0xC6B634FF, 0xCEBF3CFF, 0xD4C641FF, 0xD6C944FF, 0xD7C945FF, 0xD7C945FF, 0xD7C945FF, 0xD7C945FF, 0xD7C945FF, 0xD7C945FF, 0xD7C945FF, 0x90751600, 0x9A87178C, 0x9E8F16FF, 0x9F9116FF, 0xA79C18FF, 0xAEA41CFF, 0xB3AA21FF, 0xB8AE25FF, 0xBAB127FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0x90751600, 0x91781620, 0x8E7613B0, 0x87700FFF, 0x8B7510FF, 0x8F7B11FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x90751600, 0x90751600, 0x8F751520, 0x8468117B, 0x76560BC6, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0xBAB127FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0xBAB127FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x03030175, 0xBAB127FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x03030175, 0xBAB127FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x03030175, 0xBAB127FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x03030175, 0xBAB127FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x02020175, 0xBBB128FF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x06060277, 0xBEB52BFF, 0xAAA019FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x38341198, 0xC2B92FFF, 0xA99F19FF, 0x7D620CFF, 0x90751600, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x00000073, 0x0C0B047B, 0x90872ED1, 0xC2B92FFF, 0xA49717FF, 0x7C600CFF, 0x90751600, 0x03030175, 0x03030175, 0x03030175, 0x03030175, 0x03030175, 0x03030175, 0x03030175, 0x03030175, 0x03030175, 0x29270E8D, 0x8F8630CE, 0xD2C542FD, 0xB9B026FF, 0x978614FF, 0x775A0AFF, 0x90751600, 0xD7C945FF, 0xD7C945FF, 0xD7C945FF, 0xD7C945FF, 0xD7C945FF, 0xD7C945FF, 0xD7C945FF, 0xD7CA45FF, 0xD8CB46FF, 0xD8CB46FF, 0xD3C541FF, 0xCABA37FF, 0xA89D18FF, 0x876F0FFF, 0x77580BC6, 0x90751600, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBBB128FF, 0xBAB127FF, 0xB8AE25FF, 0xB2A820FF, 0xA69A18FF, 0x8E7911FF, 0x725309FF, 0x7F600F7B, 0x90751600, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917E12FF, 0x917D12FF, 0x8C7610FF, 0x7F640DFF, 0x6D4C07FF, 0x77570CB0, 0x8C701420, 0x90751600, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x6C4A07FF, 0x704F09E1, 0x7C5D0E8C, 0x8B701420, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600, 0x90751600

dlabel D_8024B400
.word 0x7070B0E0, 0xF0F7FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80C0F0F7, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0F0F7FF, 0xFFFFEFCF, 0xAFAFAFAF, 0xAFAF9F9F, 0xF0F7FFFF, 0xFFDFAF7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xF0FFFFFF, 0xCF8F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xF7FFFFEF, 0x8F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xFFFFEFCF, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xFFFFDF9F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFF7F0, 0xF0E08070, 0xFFEFEFEF, 0xEFEFEFFF, 0xFFFFFFFF, 0xF7F0A080, 0x9F9F9FAF, 0xAFAFAFAF, 0xBFCFEFEF, 0xEFD7B0A0, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F9FAF, 0xBFAFA790, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F60, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F5F37, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F6F4F2F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F6F3F2F, 0xFFFFCF9F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xFFEFCF9F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xD7DFBF9F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xA0AF9F9F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xA0877F8F, 0x6F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xA070474F, 0x3F4F5F5F, 0x5F5F5F5F, 0x5F5F5F5F, 0x80603027, 0x1F1F1F2F, 0x2F2F3F3F, 0x3F3F3F3F, 0x70605020, 0x10070F0F, 0x0F0F1F1F, 0x1F0F0F0F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0x6F4F2F1F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F6F, 0x5F3F1F0F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F6F, 0x4F2F1F07, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F6F4F, 0x3F1F0F00, 0x7F7F7F7F, 0x7F7F7F7F, 0x6F5F4F3F, 0x1F0F0710, 0x5F5F5F5F, 0x5F5F5F4F, 0x3F2F1F1F, 0x0F071030, 0x2F2F2F2F, 0x2F1F1F1F, 0x0F0F0F0F, 0x07002040, 0x0F0F0F0F, 0x0F0F0F0F, 0x0F0F0700, 0x00203040

dlabel D_8024B600
.word 0xE7000000, 0x00000000, 0xD7000002, 0xFFFFFFFF, 0xE3000A01, 0x00100000, 0xE3000C00, 0x00000000, 0xE3000D01, 0x00000000, 0xE3000F00, 0x00000000, 0xE3001001, 0x00000000, 0xE3001201, 0x00002000, 0xE3001402, 0x00000C00, 0xE200001C, 0x0C184340, 0xFCFFFEA0, 0xF30CF2FF, 0xE3001001, 0x00000000, 0xFD68001F, D_8024A200, 0xF5680800, 0x07050260, 0xE6000000, 0x00000000, 0xF4000000, 0x0707E03C, 0xE7000000, 0x00000000, 0xF5600800, 0x00050260, 0xF2000000, 0x000FC03C, 0xD9000000, 0x00000000, 0xD9FFFFFF, 0x00200004, 0xDF000000, 0x00000000

dlabel D_8024B6B0
.word 0xFFF8FFF0, 0x00000000, 0x00000000, 0x00000000, 0xFFF80010, 0x00000000, 0x00000800, 0x00000000

dlabel D_8024B6D0
.word 0x00380010, 0x00000000, 0x10000800, 0x000000FF, 0x0038FFF0, 0x00000000, 0x10000000, 0x000000FF

dlabel D_8024B6F0
.word 0x01002004, D_8024B6B0, 0xE7000000, 0x00000000, 0xDF000000, 0x00000000

dlabel D_8024B708
.word 0x01002008, D_8024B6D0, 0x06000204, 0x00000406, 0xE7000000, 0x00000000, 0xDF000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024B730
.word 0x33302123, 0x25FD0000

dlabel D_8024B738
.word 0xFD000000

dlabel D_8024B73C
.word 0xFD000000

dlabel D_8024B740
.word 0x2221232B, 0xFD000000

dlabel D_8024B748
.word 0x252E24FD

dlabel D_8024B74C
.word D_8024B730, D_8024B738, D_8024B73C, D_8024B740, D_8024B748

dlabel D_8024B760
.word 0xE7000000, 0x00000000, 0xD7000002, 0xFFFFFFFF, 0xE3000A01, 0x00000000, 0xE3000C00, 0x00000000, 0xE3000D01, 0x00000000, 0xE3000F00, 0x00000000, 0xE3001201, 0x00000000, 0xE3001001, 0x00008000, 0xE3001402, 0x00000C00, 0xE200001C, 0x0F0A7008, 0xFCFFFFFF, 0xFFFCF279, 0xFA000000, 0x28282848, 0xDF000000, 0x00000000

dlabel D_8024B7C8
.word 0x00000000

dlabel D_8024B7CC
.word 0x00000000

dlabel D_8024B7D0
.word 0x00000000

dlabel D_8024B7D4
.word 0xFFFFFFFF

dlabel D_8024B7D8
.word 0x33454C45, 0x4354F746, 0x494C45F7, 0x544FF753, 0x54415254, 0x1AFD0000

dlabel D_8024B7F0
.word 0x33454C45, 0x4354F746, 0x494C45F7, 0x544FF744, 0x454C4554, 0x451AFD00

dlabel D_8024B808
.word 0x33454C45, 0x4354F746, 0x494C45F7, 0x544FF753, 0x415645FD

dlabel D_8024B81C
.word 0x234F5059, 0xF7574849, 0x4348F746, 0x494C451F, 0xFD000000

dlabel D_8024B830
.word 0x234F5059, 0xF7544FF7, 0x57484943, 0x48F74649, 0x4C451FFD

dlabel D_8024B844
.word 0x2E2537FD

dlabel D_8024B848
.word 0x2C455645, 0x4CFD0000

dlabel D_8024B850
.word 0x304C4159, 0xF734494D, 0x45FD0000

dlabel D_8024B85C
.word 0x24454C45, 0x5445F726, 0x494C45FD

dlabel D_8024B868
.word 0x23414E43, 0x454CFD00

dlabel D_8024B870
.word 0x234F5059, 0xF726494C, 0x45FD0000

dlabel D_8024B87C
.word 0x26495253, 0x54F7304C, 0x4159FD00

dlabel D_8024B888
.word 0x0EFD0000

dlabel D_8024B88C
.word 0x394553FD

dlabel D_8024B890
.word 0x2E4FFD00

dlabel D_8024B894
.word 0x24454C45, 0x5445FD00

dlabel D_8024B89C
.word 0x2F564552, 0x52494445, 0xF7544FF7, 0x2E4557F7, 0x24415441, 0xFD000000

dlabel D_8024B8B4
.word 0x33415645, 0xF72F2B1F, 0xFD000000

dlabel D_8024B8C0
.word 0x26494C45, 0xF74E414D, 0x45F74953, 0xF71AFD00

dlabel D_8024B8D0
.word 0x0EFD0000

dlabel D_8024B8D4
.word 0x2F2B1FFD

dlabel D_8024B8D8
.word 0x26494C45, 0xFD000000

dlabel D_8024B8E0
.word 0x57494C4C, 0xF74245F7, 0x44454C45, 0x5445440E, 0xFD000000

dlabel D_8024B8F4
.word 0x2F2BF754, 0x4FF7434F, 0x5059F754, 0x4FF75448, 0x4953F746, 0x494C451F, 0xFD000000

dlabel D_8024B910
.word 0x33544152, 0x54F74741, 0x4D45F757, 0x495448FD

dlabel D_8024B920
.word 0x26494C45, 0xFD000000

dlabel D_8024B928
.word 0x484153F7, 0x4245454E, 0xF744454C, 0x45544544, 0x0EFD0000

dlabel D_8024B93C
.word 0xFD000000

dlabel D_8024B940
.word 0x234F5059, 0xF746524F, 0x4DFD0000

dlabel D_8024B94C
.word 0x544FFD00

dlabel D_8024B950
.word 0x484153F7, 0x4245454E, 0xF7435245, 0x41544544, 0x0EFD0000

dlabel D_8024B964
.word 0x254E5445, 0x52F741F7, 0x46494C45, 0xF74E414D, 0x4501FD00

dlabel D_8024B978
.word 0x21222324, 0x25262728, 0x292A2B2C, 0x2D2E2F30, 0x31323334, 0x35363738, 0x393A4142, 0x43444546, 0x4748494A, 0x4B4C4D4E, 0x4F505152, 0x53545556, 0x5758595A, 0x11121314, 0x15161718, 0x19100E0D, 0xF7009091, 0x20C6F7F7, 0xC9F7F7CA, 0xF7F70000

dlabel D_8024B9C8
.word 0x1FFD0000

dlabel D_8024B9CC
.word 0x0EFD0000

dlabel gFileMenuMessages
.word 0x00000000, D_8024B7D8, D_8024B7F0, D_8024B808, D_8024B81C, D_8024B830, D_8024B844, D_8024B848, D_8024B850, D_8024B85C, D_8024B868, D_8024B870, D_8024B87C, D_8024B888, D_8024B88C, D_8024B890, D_8024B894, D_8024B89C, D_8024B8B4, D_8024B8C0, D_8024B8D0, D_8024B8D4, D_8024B8D8, D_8024B8E0, D_8024B8F4, D_8024B910, D_8024B920, D_8024B928, D_8024B93C, D_8024B940, D_8024B94C, D_8024B950, D_8024B964, D_8024B9C8, D_8024B9CC, 0x00000000

dlabel D_8024BA60
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFC30FFFF, 0x5FFEFC38, 0xFC30FFFF, 0x5FFEF638, 0x405CF6FF, 0x00000000

dlabel D_8024BA98
.word 0x00000000, 0x40101000, 0x00000080, 0x00000000, 0x31080808, 0x08080808, 0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00FF0000, 0x00000000

dlabel D_8024BAD0
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024BB08
.word 0x00000000, 0x00000000, 0x00000000, D_8024A400, 0x03101010, 0x10101010, 0x10000000, 0x00000000, 0xFCFFFFFF, 0xFFFD7438, 0xFCFFB5FF, 0xFFFD7E38, 0x000000FF, 0x00000000

dlabel D_8024BB40
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0xD78C96FF, 0x7D2D23FF

dlabel D_8024BB78
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0xD78C96FF, 0x7D2D23FF

dlabel D_8024BBB0
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0xD78C96FF, 0x7D2D23FF

dlabel D_8024BBE8
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0xC8C8C8FF, 0x828265FF

dlabel D_8024BC20
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0xC8C8C8FF, 0x828265FF

dlabel D_8024BC58
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0xC8C8C8FF, 0x828265FF

dlabel D_8024BC90
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0xC8C8C8FF, 0x828265FF

dlabel D_8024BCC8
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0x585C44FF, 0x988F82FF

dlabel D_8024BD00
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0x585C44FF, 0x988F82FF

dlabel D_8024BD38
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0x585C44FF, 0x988F82FF

dlabel D_8024BD70
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0x585C44FF, 0x988F82FF

dlabel D_8024BDA8
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0xC8C8C8FF, 0x828265FF

dlabel D_8024BDE0
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0xFFFFFFFF, 0xC8C8AAFF

dlabel D_8024BE18
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0x585C44FF, 0x988F82FF

dlabel D_8024BE50
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0xFFEE6AFF, 0x92641AFF

dlabel D_8024BE88
.word 0x00000000, 0x00000000, 0x00000000, D_8024A400, 0x03101010, 0x10101010, 0x10000000, 0x00000000, 0xFCFFFFFF, 0xFFFD7438, 0xFCFFB5FF, 0xFFFD7E38, 0x000000FF, 0x00000000

dlabel D_8024BEC0
.word 0x00000000, 0x00000000, 0x00000000, D_8024A400, 0x03101010, 0x10101010, 0x10000000, 0x00000000, 0xFCFFFFFF, 0xFFFD7438, 0xFCFFB5FF, 0xFFFD7E38, 0x000000FF, 0x00000000

dlabel D_8024BEF8
.word 0x00000000, 0x00000000, 0x00000000, D_8024A400, 0x03101010, 0x10101010, 0x10000000, 0x00000000, 0xFCFFFFFF, 0xFFFD7438, 0xFCFFB5FF, 0xFFFD7E38, 0x000000FF, 0x00000000

dlabel D_8024BF30
.word 0x00000000, 0x00000000, 0x00000000, D_8024B400, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC317FFF, 0x5FFEF438, 0xFC3135FF, 0x5FFEFE38, 0xFFFFFFFF, 0xC8C8AAFF, 0x00000000, 0x00000000
