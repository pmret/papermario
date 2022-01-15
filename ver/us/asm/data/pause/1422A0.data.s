.include "macro.inc"

.section .data

dlabel D_8024F020
.word 0x00008000, 0x00080000, 0x00008000, 0x00008000, 0x00008000, 0x00008000, 0x00001000

dlabel D_8024F03C
.word 0x00000009, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F

dlabel D_8024F058
.word 0x00000010, 0x00000011, 0x00000012, 0x00000013, 0x00000014, 0x00000015, 0x00000016, 0x00000002, 0x00000003, 0x00000004, 0x00000005, 0x00000006, 0x00000007, 0x00000008

dlabel D_8024F090
.word 0x00000005, 0x00000004, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000006

dlabel gPauseMenuTextScrollInterpEasingLUT
.byte 0x00, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08

dlabel gPauseMenuPageScrollInterpEasingLUT
.byte 0x00, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08

dlabel D_8024F0CC
.word 0x009E0000, 0x009E0001, 0x009E000B, 0xFFFFFFFF, 0x00010000, 0x00010001, 0x00010008, 0xFFFFFFFF, 0x009D0000, 0x009D0001, 0x009D0008, 0xFFFFFFFF, 0x00000000

dlabel D_8024F100
.word 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000

dlabel D_8024F110
.word 0x00000000

dlabel D_8024F114
.word 0x1600000C, 0x00140128, 0x00C80000, func_80243568, 0x00000000, 0xFF000000, 0x00000001, 0x40000000, 0x8026F900, 0x18000000, 0x008A0128, 0x003F0000, pause_tutorial_draw_contents, 0x00000000, 0x16000000, 0x00000002, 0x00000000, 0x8026F970, 0x17000014, 0x00A40100, 0x00200000, pause_textbox_draw_contents, 0x00000000, 0x16000000, basic_window_update, 0x00000000, 0x8026F938, 0x2C000000, 0x00000140, 0x00F00000, pause_update_cursor, 0x00000000, 0xFF000000, 0x00000001, 0x00000000, 0x8026F900, 0x00000000, 0x00000000, 0x00000000
#next file here
dlabel D_8024F1B0
.word func_80241FE8_D3C5B8, func_80242014_8B2084, func_80242040_8B20B0, func_8024206C_83386C, 0x80242098, sam_06_PartnerSuspendAbilityScript

dlabel D_8024F1C8
.word 0x00010203, 0x04050000

dlabel D_8024F1D0
.byte 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00, 0x00

dlabel D_8024F1D8
.byte 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x00, 0x00

dlabel D_8024F1E0
.byte 0x1F, 0x20, 0x21, 0x22, 0x27, 0x29, 0x00, 0x00

dlabel D_8024F1E8
.word 0x19000000, 0x0007002B, 0x000F4000, pause_tabs_draw_stats, 0x00000000, 0x16000000, 0x00000001, 0x00000000, 0x8026F9A8, 0x1A000000, 0x0007002B, 0x000F0000, pause_tabs_draw_badges, 0x00000000, 0x16000000, func_80242F90, 0x00000000, 0x8026F9E0, 0x1B000000, 0x0007002B, 0x000F0000, pause_tabs_draw_items, 0x00000000, 0x16000000, func_80242F90, 0x00000000, 0x8026FA18, 0x1C000000, 0x0007002B, 0x000F0000, pause_tabs_draw_party, 0x00000000, 0x16000000, func_80242F90, 0x00000000, 0x8026FA50, 0x1D000000, 0x0007002B, 0x000F0000, pause_tabs_draw_spirits, 0x00000000, 0x16000000, func_80242F90, 0x00000000, 0x8026FA88, 0x1E000000, 0x0007002B, 0x000F0000, pause_tabs_draw_map, 0x00000000, 0x16000000, func_80242F90, 0x00000000, 0x8026FAC0

dlabel D_8024F2C0
.word 0x2B000008, 0x00080010, 0x00104000, pause_tabs_draw_invis, 0x00000000, 0xFF000000, 0x00000001, 0x00000000, 0x8026FAF8

dlabel D_8024F2E4
.word 0x00000000

dlabel D_8024F2E8
.word 0x0000001B, 0x0000001C, 0x0000001D, 0x0000001E, 0x0000001F, 0x00000020

dlabel D_8024F300
.byte 0x00, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08

dlabel D_8024F310
.word 0x00000001

dlabel D_8024F314
.word 0x00000000, 0x00060100, D_8024F1C8, pause_tabs_init, pause_tabs_handle_input, pause_tabs_update, pause_tabs_cleanup

dlabel gStatsMenuElements
.word arn_03_802429D4, flo_00_npcAISettings_8024286C, 0x8024290C, HudScript_StatusCoin, HudScript_StatusStarPoint, dgb_18_idle_80242A24, 0x802429FC, HudScript_StatusHeart, func_80242AD4_825D94, 0x802429AC, HudScript_StatusStar1, 0x80242B24

dlabel D_8024F360
.word flo_00_npcAISettings_8024286C, mac_05_UnkYawFunc, flo_00_npcSettings_802428BC, 0x802428E4

dlabel D_8024F370
.word 0x8024290C, func_80242934_C63644, func_8024295C_8B29CC, 0x80242984

dlabel D_8024F380
.word 0x0000003B, 0x0000003C, 0x0000003D, 0x0000003E

dlabel D_8024F390
.word 0x0000003F, 0x00000040, 0x00000041, 0x00000042

dlabel D_8024F3A0
.word 0x00040105, 0x01060207, 0x02080309, 0x030A0000

dlabel gStatsMenuEntries
.word 0x00000009, 0x00000014

dlabel D_8024F3B8
.word 0x00000021, 0x00000011, 0x00000037, 0x00000022, 0x00000011, 0x0000005A, 0x00000023, 0x00000011, 0x0000007C, 0x00000024, 0x0000008A, 0x0000001C, 0x00000025, 0x0000008A, 0x00000035, 0x00000028, 0x00000084, 0x0000004C, 0x0000002C, 0x0000007D, 0x0000005B, 0x0000002D, 0x0000007D, 0x0000006A, 0x0000002E, 0x0000007D, 0x00000079, 0x0000002F, 0x0000007D, 0x0000008A, 0x00000031

dlabel D_8024F434
.word 0x80108298, 0x801082E8, 0x801082C0, 0x80108310, 0x80108338, 0x80108360, 0x80108388

dlabel D_8024F450
.word HudScript_StatusStar1, HudScript_StatusStar3, HudScript_StatusStar2, HudScript_StatusStar4, HudScript_StatusStar5, HudScript_StatusStar6, HudScript_StatusStar7

dlabel D_8024F46C
.word 0xFFFFFFFF

dlabel D_8024F470
.word 0x00000001

dlabel D_8024F474
.word 0x00000002

dlabel D_8024F478
.word 0x00000004

dlabel D_8024F47C
.word 0x00000005

dlabel D_8024F480
.word 0x00000007

dlabel D_8024F484
.word 0x00000008

dlabel gStatsMenuWindowBPs
.word 0x1F000003, 0x00100121, 0x009A0000, pause_stats_draw_contents, 0x00000000, 0x16000000, 0x00000002, 0x00000000, 0x8026FBA0

dlabel D_8024F4AC
.word 0x00000000, 0x00020700, D_8024F3A0, pause_stats_init, pause_stats_handle_input, 0x00000000, pause_stats_cleanup, 0x00000000, 0x00000000

dlabel gBadgeMenuElements
.word 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, func_802426A0_8B2710, 0x802426CC, 0x802427A8, jan_02_TransformFoliage, HudScript_StatusStar1

dlabel gBadgeMenuWindowBPs
.word 0x20000003, 0x00100121, 0x009A0100, pause_badges_draw_contents, 0x00000000, 0x16000000, 0x00000002, 0x00000000, 0x8026FC80

dlabel D_8024F54C
.word 0x00000000, 0x00000000, 0x00000000, pause_badges_init, pause_badges_handle_input, pause_badges_update, pause_badges_cleanup, 0x00000000, 0x00000000

dlabel D_8024F570
.word 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, 0x802429AC, func_802426A0_8B2710, 0x802426CC, 0x802427A8, HudScript_StatusStar1

dlabel D_8024F5C0
.word 0x21000003, 0x00100121, 0x009A0100, pause_items_draw_contents, 0x00000000, 0x16000000, 0x00000002, 0x00000000, 0x8026FD28

dlabel D_8024F5E4
.word 0x00000000, 0x00000000, 0x00000000, pause_items_init, pause_items_handle_input, pause_items_update, pause_items_cleanup

dlabel D_8024F600
.word HudScript_FPCost, func_80242AD4_825D94, 0x80242B4C, 0x80242B4C, 0x80109338, 0x80109360, 0x80109388, 0x801093B0

dlabel D_8024F620
.word 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000

dlabel D_8024F630
.word 0x00010000, 0x00010002, 0x00010008, 0xFFFFFFFF, 0x00020000, 0x00020004, 0x0002000D, 0xFFFFFFFF, 0x00030000, 0x00030005, 0x0003000E, 0xFFFFFFFF, 0x00040000, 0x00040002, 0x00040006, 0xFFFFFFFF, 0x00050000, 0x00050002, 0x00050004, 0xFFFFFFFF, 0x00060000, 0x00060002, 0x00060004, 0xFFFFFFFF, 0x00070000, 0x00070002, 0x00070004, 0xFFFFFFFF, 0x00080000, 0x00080005, 0x00080009, 0xFFFFFFFF

dlabel D_8024F6B0
.word 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000009, 0x00000006, 0x00000007, 0x00000008

dlabel D_8024F6D0
.word 0x00280006, 0x00280013, 0x00280020, 0x0028002D, 0x0028003A, 0x00280047, 0x00280054, 0x00280061

dlabel D_8024F6F0
.word 0x00000083, 0x00000089, 0x0000008F, 0x00000095, 0x000000B3, 0x000000A1, 0x000000A7, 0x000000AD

dlabel D_8024F710
.word 0x04050607, 0x00010203

dlabel D_8024F718
.word 0x80270030, 0x80270020, 0x80270014, 0x80270004, 0x8026FFF8, 0x8026FFEC, 0x8026FFE0, 0x8026FFD0, 0x8026FFC0

dlabel D_8024F73C
.word 0x80270930, 0x802748B8

dlabel D_8024F744
.word 0x80270730

dlabel D_8024F748
.word 0x802746B8, 0x00000000

dlabel D_8024F750
.word 0xE7000000, 0x00000000, 0xD7000002, 0xFFFFFFFF, 0xE3000A01, 0x00000000, 0xE3000C00, 0x00000000, 0xE3000D01, 0x00000000, 0xE3000F00, 0x00000000, 0xE3001001, 0x00008000, 0xE3001201, 0x00000000, 0xE3001402, 0x00000C00, 0xE200001C, 0x0F0A4000, 0xFCFFFFFF, 0xFFFCFC7E, 0xD9FDFFFF, 0x00000000, 0xD9FFFFFF, 0x00200404, 0xDF000000, 0x00000000

dlabel D_8024F7C0
.word 0xFFFFFFFF

dlabel D_8024F7C4
.word 0xFFFFFFFF

dlabel D_8024F7C8
.word 0x22000003, 0x00100121, 0x009A0100, pause_partners_draw_contents, 0x00000000, 0x16000000, 0x00000002, 0x00000000, 0x8026FD60, 0x23000008, 0x00670070, 0x00140000, pause_partners_draw_title, 0x00000000, 0x22000000, 0x00000001, 0x00000000, 0x8026FDD0, 0x24000085, 0x0024008C, 0x00500000, pause_partners_draw_movelist, 0x00000000, 0x22000000, 0x00000002, 0x00000000, 0xFFFFFFFF, 0x2500000C, 0xFFFA0050, 0x00100000, pause_partners_draw_movelist_title, 0x00000000, 0x24000000, 0x00000001, 0x00000000, 0xFFFFFFFF

dlabel D_8024F858
.word 0x26000066, 0xFFF40020, 0x00200000, pause_partners_draw_movelist_flower, 0x00000000, 0x24000000, 0x00000001, 0x00000000, 0xFFFFFFFF

dlabel D_8024F87C
.byte 0x00, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08

dlabel D_8024F88C
.word 0x00000100, 0x00040200, D_8024F710, pause_partners_init, pause_partners_handle_input, pause_partners_update, pause_partners_cleanup, 0x00000000, 0x00000000

dlabel D_8024F8B0
.word 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000

dlabel D_8024F8C0
.word 0x00120000, 0x00120001, 0x00120002, 0xFFFFFFFF, 0x00130000, 0x00130001, 0x00130002, 0xFFFFFFFF, 0x00140000, 0x00140001, 0x00140002, 0xFFFFFFFF, 0x00150000, 0x00150001, 0x00150002, 0xFFFFFFFF, 0x00160000, 0x00160001, 0x00160002, 0xFFFFFFFF, 0x00170000, 0x00170001, 0x00170003, 0xFFFFFFFF, 0x00180000, 0x00180001, 0x00180002, 0xFFFFFFFF

dlabel D_8024F930
.word 0x05060001, 0x02050404, 0x03020000

dlabel D_8024F93C
.word 0x00000078, 0xFFFFFFFB, 0x000000B3, 0xFFFFFFFE, 0x000000DE, 0x0000001C, 0x000000A5, 0x0000002D, 0x0000004C, 0x0000002D, 0x00000011, 0x0000001C, 0x0000003B, 0xFFFFFFFE

dlabel D_8024F974
.word 0x00000006, 0x00000000, 0x00000001, 0x00000005, 0x00000002, 0x00000004, 0x00000003

dlabel D_8024F990
.word 0x00000078, 0x00000032, 0x000000B4, 0x00000037, 0x000000DC, 0x0000005A, 0x000000A5, 0x0000006E, 0x0000004B, 0x0000006E, 0x00000014, 0x0000005A, 0x0000003C, 0x00000037

dlabel D_8024F9C8
.word 0x27000003, 0x00100121, 0x009A0100, pause_spirits_draw_contents, 0x00000000, 0x16000000, 0x00000002, 0x00000000, 0x8026FE08

dlabel D_8024F9EC
.word 0x28000056, 0x007C0078, 0x00140000, pause_spirits_draw_title, 0x00000000, 0x27000000, 0x00000001, 0x00000000, 0x8026FE40

dlabel D_8024FA10
.word 0x00020000, 0x00050200, D_8024F930, pause_spirits_init, pause_spirits_handle_input, pause_spirits_update, pause_spirits_cleanup, 0x00000000

dlabel D_8024FA30
.word 0x80242644, 0xFFFFFFFF

dlabel D_8024FA38
.word 0x01F601F8, 0xF7FEF800, 0xF800F9FD, 0xFBFD0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FA78
.word 0xFF1801F8, 0x02F90000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FAB8
.word 0xFD07F904, 0xF8020000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FAF8
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FB38
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FB78
.word 0xF8FDF900, 0xF801F902, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FBB8
.word 0xF700FAFF, 0xF900F801, 0xFF080000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FBF8
.word 0x0106FD06, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FC38
.word 0xF901F903, 0xF903F903, 0xF901F902, 0xF9000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FC78
.word 0xF703F800, 0xF800F7FE, 0xF9FCF9FC, 0xFAFBFBFA, 0xFFF9FDFA, 0xFDFAF9FC, 0xF900F800, 0xF800F800, 0xF80000FA, 0x00FA0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FCB8
.word 0xFA05FA03, 0xF800F8FC, 0xFBFBF8FD, 0xF801FB05, 0xFE070207, 0x05050605, 0x06030000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FCF8
.word 0xFE06FC04, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FD38
.word 0x04060405, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FD78
.word 0xF8FFF6FE, 0xF8FEF7FF, 0xF8FFF600, 0xF7000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FDB8
.word 0x08060000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FDF8
.word 0xF904F905, 0xF904F905, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FE38
.word 0xF802F803, 0xF803F803, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FE78
.word 0x0AFF0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FEB8
.word 0x06060606, 0x080207FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FEF8
.word 0x0B020B00, 0x0BFE0AFD, 0x07F903F8, 0x00F7FCF9, 0xF7FDF6FE, 0xF7FEF9FA, 0xFEF701F7, 0x00F7F8FB, 0xF7FE01F8, 0x09FE09FE, 0x08FB0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FF38
.word 0xF703FB05, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FF78
.word 0xFB06FE09, 0x02080706, 0x07040000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FFB8
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8024FFF8
.word 0xFD060007, 0x05060107, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80250038
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80250078
.word 0xF7FE0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802500B8
.word 0xF501F7FE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802500F8
.word 0xF903FA05, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80250138
.word 0x00070000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80250178
.word 0xF703F801, 0xF901F904, 0x02060803, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802501B8
.word 0xFD060206, 0x08030605, 0xFE06FA03, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802501F8
.word 0xFA05FE07, 0x02070606, 0x08030800, 0x08FD08FB, 0x06FB07FC, 0x08FF0803, 0x02080000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80250238
.word 0xFD070006, 0x04070000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80250278
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel pause_map_spaces
.word 0x007400B9, 0x00070000, D_8024FA38, 0x00000060, 0x00000001, 0x00760097, 0x00030000, D_8024FA78, 0x00000060, 0x00000019, 0x008F0086, 0x01030000, D_8024FAB8, 0xFFFFFF97, 0x0000001B, 0x006400AE, 0x00000000, D_8024FAF8, 0x00000061, 0x00000002, 0x0024009D, 0x05000000, D_8024FB38, 0xFFFFFF8D, 0x0000001E, 0x004A009A, 0x00040000, D_8024FB78, 0xFFFFFF95, 0x0000001F, 0x009400A7, 0x00050000, D_8024FBB8, 0xFFFFFFB5, 0x00000020, 0x009A0094, 0x06020000, D_8024FBF8, 0xFFFFFFA4, 0x00000021, 0x00CD0098, 0x06070000, D_8024FC38, 0xFFFFFFB5, 0x00000007, 0x00E300F3, 0x00130000, D_8024FC78, 0x00000061, 0x00000008, 0x010A00CE, 0x090D0000, D_8024FCB8, 0xFFFFFFC2, 0x0000000A, 0x011800BF, 0x0A020000, D_8024FCF8, 0x00000061, 0x00000009, 0x00FC00BC, 0x0A020000, D_8024FD38, 0xFFFFFFCA, 0x0000000B, 0x00BB00C1, 0x00070000, D_8024FD78, 0xFFFFFFD0, 0x0000000C, 0x00AA00B4, 0x0D010000, D_8024FDB8, 0xFFFFFFDD, 0x0000000D, 0x00DF00AA, 0x0D040000, D_8024FDF8, 0xFFFFFFF2, 0x00000022, 0x0107009C, 0x0F040000, D_8024FE38, 0xFFFFFFF2, 0x0000000F, 0x00CB00AB, 0x0F010000, D_8024FE78, 0xFFFFFFF2, 0x00000023, 0x004F00AD, 0x00040000, D_8024FEB8, 0x00000007, 0x00000010, 0x00420121, 0x00150000, D_8024FEF8, 0x00000018, 0x00000024, 0x00540112, 0x13020000, D_8024FF38, 0x00000061, 0x00000025, 0x002F00FC, 0x13050000, D_8024FF78, 0x00000026, 0x00000012, 0x003B007E, 0x00000000, D_8024FFB8, 0x0000003A, 0x00000026, 0x003A005C, 0x16040000, D_8024FFF8, 0x0000003A, 0x00000027, 0x00B7007D, 0x03000000, D_80250038, 0x00000043, 0x00000028, 0x00CB007E, 0x18010000, D_80250078, 0x00000045, 0x00000029, 0x00EA0080, 0x19020000, D_802500B8, 0x00000048, 0x0000002A, 0x00DC0070, 0x19020000, D_802500F8, 0x00000059, 0x0000002B, 0x00DF0063, 0x1B010000, D_80250138, 0x00000059, 0x00000015, 0x009E006E, 0x02060000, D_80250178, 0x00000061, 0x0000001C, 0x00A3004E, 0x1D060000, D_802501B8, 0x00000061, 0x0000001D, 0x00600031, 0x1E0D0000, D_802501F8, 0x00000060, 0x00000016, 0x00580016, 0x1F030000, D_80250238, 0x00000060, 0x0000001A, 0x00620093, 0x00000000, D_80250278, 0x00000061, 0x0000002C

dlabel D_80250560
.word 0x00000000, 0x00000002, 0x00000003, 0x00000003, 0x00000004, 0x00000004, 0x00000004, 0x00000004, 0x00000003, 0x00000002, 0x00000001, 0x00000000

dlabel pause_map_windowBlueprints
.word 0x29000003, 0x00100121, 0x009A0100, pause_map_draw_contents, 0x00000000, 0x16000000, 0x00000002, 0x00000000, 0x8026FEB0, 0x2A000038, 0x007C00B4, 0x00140000, pause_map_draw_title, 0x00000000, 0x29000000, 0x00000001, 0x00000000, 0x8026FF20, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_8025068C
.word 0x00000000, 0x00000000, 0x00000000, pause_map_init, pause_map_handle_input, pause_map_update, pause_map_cleanup, 0x00000000, 0x00000000, 0x7070B0E0, 0xF0F7FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80C0F0F7, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0F0F7FF, 0xFFFFEFCF, 0xAFAFAFAF, 0xAFAF9F9F, 0xF0F7FFFF, 0xFFDFAF7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xF0FFFFFF, 0xCF8F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xF7FFFFEF, 0x8F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xFFFFEFCF, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xFFFFDF9F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFF7F0, 0xF0E08070, 0xFFEFEFEF, 0xEFEFEFFF, 0xFFFFFFFF, 0xF7F0A080, 0x9F9F9FAF, 0xAFAFAFAF, 0xBFCFEFEF, 0xEFD7B0A0, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F9FAF, 0xBFAFA790, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F60, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F5F37, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F6F4F2F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F6F3F2F, 0xFFFFCF9F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xFFEFCF9F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xD7DFBF9F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xA0AF9F9F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xA0877F8F, 0x6F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0xA070474F, 0x3F4F5F5F, 0x5F5F5F5F, 0x5F5F5F5F, 0x80603027, 0x1F1F1F2F, 0x2F2F3F3F, 0x3F3F3F3F, 0x70605020, 0x10070F0F, 0x0F0F1F1F, 0x1F0F0F0F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F7F, 0x6F4F2F1F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F6F, 0x5F3F1F0F, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F7F6F, 0x4F2F1F07, 0x7F7F7F7F, 0x7F7F7F7F, 0x7F7F6F4F, 0x3F1F0F00, 0x7F7F7F7F, 0x7F7F7F7F, 0x6F5F4F3F, 0x1F0F0710, 0x5F5F5F5F, 0x5F5F5F4F, 0x3F2F1F1F, 0x0F071030, 0x2F2F2F2F, 0x2F1F1F1F, 0x0F0F0F0F, 0x07002040, 0x0F0F0F0F, 0x0F0F0F0F, 0x0F0F0700, 0x00203040, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xE4E9FDFF, 0x00000000, 0x00000000, 0x0000E5FD, 0xEFBF9F8F, 0x00000000, 0x00000000, 0x00F9EFAF, 0x8F7F6F6F, 0x00000000, 0x00000000, 0xFACF8F7F, 0x6F6F6F6F, 0x00000000, 0x000000F9, 0xCF8F6F6F, 0x6F6F6F6F, 0x00000000, 0x0000E5DF, 0x8F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x0000FD9F, 0x7F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x00E4CF7F, 0x6F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x00E9AF7F, 0x6F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x00CD8F6F, 0x6F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x00AF8F6F, 0x6F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFEFEDE9, 0xC4000000, 0x00000000, 0x00000000, 0x8F8F9FAF, 0xBFBD9500, 0x00000000, 0x00000000, 0x6F6F7F7F, 0x8F9F9F89, 0x00000000, 0x00000000, 0x6F6F6F6F, 0x6F7F7F8F, 0x7A000000, 0x00000000, 0x6F6F6F6F, 0x6F6F6F7F, 0x6F690000, 0x00000000, 0x6F6F6F6F, 0x6F6F6F6F, 0x6F5F7500, 0x00000000, 0x6F6F6F6F, 0x6F6F6F6F, 0x6F5F4D00, 0x00000000, 0x6F6F6F6F, 0x6F6F6F6F, 0x6F5F3F74, 0x00000000, 0x6F6F6F6F, 0x6F6F6F6F, 0x6F5F3F69, 0x00000000, 0x6F6F6F6F, 0x6F6F6F6F, 0x6F5F2F3D, 0x00000000, 0x6F6F6F6F, 0x6F6F6F6F, 0x6F5F3F2F, 0x00000000, 0x00000000, 0x009F7F6F, 0x6F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x009F7F6F, 0x6F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x008D7F6F, 0x6F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x00796F6F, 0x6F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x00646F6F, 0x6F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x00005D5F, 0x6F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x0000554F, 0x5F6F6F6F, 0x6F6F6F6F, 0x00000000, 0x00000049, 0x3F4F5F6F, 0x6F6F6F6F, 0x00000000, 0x00000000, 0x3A2F3F5F, 0x6F6F6F6F, 0x00000000, 0x00000000, 0x00392F2F, 0x3F4F4F4F, 0x00000000, 0x00000000, 0x0000652D, 0x1F1F1F1F, 0x00000000, 0x00000000, 0x00000000, 0x74693D2F, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x6F6F6F6F, 0x6F6F6F6F, 0x6F5F2F2F, 0x00000000, 0x6F6F6F6F, 0x6F6F6F6F, 0x6F5F2F2F, 0x00000000, 0x6F6F6F6F, 0x6F6F6F6F, 0x6F4F1F4D, 0x00000000, 0x6F6F6F6F, 0x6F6F6F6F, 0x5F2F1F79, 0x00000000, 0x6F6F6F6F, 0x6F6F6F6F, 0x4F1F2F74, 0x00000000, 0x6F6F6F6F, 0x6F6F6F5F, 0x2F1F6D00, 0x00000000, 0x6F6F6F6F, 0x6F6F5F3F, 0x0F2F7500, 0x00000000, 0x6F6F6F6F, 0x6F5F3F1F, 0x2F790000, 0x00000000, 0x6F6F6F5F, 0x4F2F0F1F, 0x7A000000, 0x00000000, 0x4F4F3F2F, 0x1F1F2F79, 0x00000000, 0x00000000, 0x1F1F1F1F, 0x2F6D7500, 0x00000000, 0x00000000, 0x1F2F6D79, 0x74000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80808080, 0x80FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x808080FF, 0xFFFFFFFF, 0xFFFFFFEF, 0xEFFFFFFF, 0x8080FFFF, 0xFFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0x80FFFFFF, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0x80FFFFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xFFFFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xFFFFEFEF, 0xEFEFEFEF, 0xEFDFCFCF, 0xCFCFCFCF, 0xFFEFEFEF, 0xEFEFEFEF, 0xCFBF8F8F, 0x7F8F7F7F, 0xFFEFEFEF, 0xEFEFEFCF, 0xBF8F7F05, 0x05050505, 0xFFEFEFEF, 0xEFEFDFBF, 0x8F7F0505, 0x05050505, 0xFFEFEFEF, 0xEFEFCF9F, 0x7F050505, 0x05050505, 0xFFEFEFEF, 0xEFEFCF8F, 0x05050505, 0x05050505, 0xFFEFEFEF, 0xEFEFCF7F, 0x05050505, 0x05058080, 0xFFEFEFEF, 0xEFEFBF7F, 0x05050505, 0x05808080, 0xFFEFEFEF, 0xEFEFBF7F, 0x05050505, 0x80808080, 0xFFEFEFEF, 0xEFEFCF8F, 0x05050505, 0x80808080, 0xFFFFFFFF, 0xFFFFFF80, 0x80808080, 0x80808080, 0xFFFFFFFF, 0xFFEFFFFF, 0xDF808080, 0x80808080, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFCF8080, 0x80808080, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFDFCF80, 0x80808080, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFBF80, 0x80808080, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFBF7F, 0x05808080, 0xCFEFEFEF, 0xEFEFEFEF, 0xEFEFBF6F, 0x05058080, 0x7FEFEFEF, 0xEFEFEFEF, 0xEFEFBF6F, 0x05050580, 0x05BFEFEF, 0xEFEFEFEF, 0xEFEFBF6F, 0x05050580, 0x0505EFEF, 0xEFEFEFEF, 0xEFEFBF6F, 0x05050505, 0x050505EF, 0xEFEFEFEF, 0xEFEFBF6F, 0x05050505, 0x05050505, 0xEFEFEFEF, 0xEFEFBF7F, 0x05050505, 0x80808080, 0xEFEFEFEF, 0xEFEFBF7F, 0x05050505, 0x80808080, 0xEFEFEFEF, 0xEFEFCF7F, 0x05050505, 0x80808080, 0xEFEFEFEF, 0xEFEFCF7F, 0x05050505, 0x80808080, 0xEFEFEFEF, 0xEFEFCF7F, 0x05050505, 0xFFEFEFEF, 0xEFEFCF8F, 0x05050505, 0x80808080, 0xFFEFEFEF, 0xEFEFDFBF, 0xBF050505, 0x80808080, 0xFFEFEFEF, 0xEFEFEFEF, 0xCFDF0505, 0x80808080, 0xFFEFEFEF, 0xEFEFEFEF, 0xEFEFEF05, 0x80808080, 0xFFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xFFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xFFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0x80EFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0x80EFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0x8080DFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFEFEF, 0x808080AF, 0xAFAFAFAF, 0xBFBFBFAF, 0xBFBFBFBF, 0x80808080, 0x808F8F8F, 0x8F8F8F8F, 0x8F8F8F8F, 0x80808080, 0x80050505, 0x05050505, 0x05050505, 0x80808080, 0x80800505, 0x05050505, 0x05050505, 0x80808080, 0x80808005, 0x05050505, 0x05050505, 0x80808080, 0x80808080, 0x80050505, 0x05050505, 0x80808080, 0xEFEFEFEF, 0xEFEFCF7F, 0x05050505, 0x808080EF, 0xEFEFEFEF, 0xEFEFCF8F, 0x05050505, 0x8080EFEF, 0xEFEFEFEF, 0xEFEFCF8F, 0x05050505, 0x80EFEFEF, 0xEFEFEFEF, 0xEFEFCF7F, 0x05050505, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFEFBF7F, 0x05050505, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFDFAF7F, 0x05050505, 0xEFEFEFEF, 0xEFEFEFEF, 0xEFCF9F6F, 0x05050505, 0xEFEFEFEF, 0xEFEFEFEF, 0xDFAF8F05, 0x05050505, 0xEFEFEFEF, 0xEFEFEFEF, 0xBF8F6F05, 0x05050505, 0xEFEFEFEF, 0xEFEFEFBF, 0x9F6F0505, 0x05050505, 0xBFBFBFBF, 0xBFBFAF8F, 0x6F050505, 0x05050505, 0x8F8F8F8F, 0x8F8F7F05, 0x05050505, 0x05050580, 0x05050505, 0x05050505, 0x05050505, 0x05050580, 0x05050505, 0x05050505, 0x05050505, 0x05058080, 0x05050505, 0x05050505, 0x05050505, 0x05808080, 0x05050505, 0x05050505, 0x05050580, 0x80808080
