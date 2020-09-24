.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_stats_draw_contents
/* 138CC0 80245980 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 138CC4 80245984 AFBE0078 */  sw        $fp, 0x78($sp)
/* 138CC8 80245988 00C0F02D */  daddu     $fp, $a2, $zero
/* 138CCC 8024598C AFA50084 */  sw        $a1, 0x84($sp)
/* 138CD0 80245990 24A8008F */  addiu     $t0, $a1, 0x8f
/* 138CD4 80245994 0100282D */  daddu     $a1, $t0, $zero
/* 138CD8 80245998 AFB1005C */  sw        $s1, 0x5c($sp)
/* 138CDC 8024599C 3C118027 */  lui       $s1, 0x8027
/* 138CE0 802459A0 26310150 */  addiu     $s1, $s1, 0x150
/* 138CE4 802459A4 AFBF007C */  sw        $ra, 0x7c($sp)
/* 138CE8 802459A8 AFB70074 */  sw        $s7, 0x74($sp)
/* 138CEC 802459AC AFB60070 */  sw        $s6, 0x70($sp)
/* 138CF0 802459B0 AFB5006C */  sw        $s5, 0x6c($sp)
/* 138CF4 802459B4 AFB40068 */  sw        $s4, 0x68($sp)
/* 138CF8 802459B8 AFB30064 */  sw        $s3, 0x64($sp)
/* 138CFC 802459BC AFB20060 */  sw        $s2, 0x60($sp)
/* 138D00 802459C0 AFB00058 */  sw        $s0, 0x58($sp)
/* 138D04 802459C4 AFA40080 */  sw        $a0, 0x80($sp)
/* 138D08 802459C8 AFA80050 */  sw        $t0, 0x50($sp)
/* 138D0C 802459CC 8E24000C */  lw        $a0, 0xc($s1)
/* 138D10 802459D0 0C051261 */  jal       set_icon_render_pos
/* 138D14 802459D4 27C6006D */   addiu    $a2, $fp, 0x6d
/* 138D18 802459D8 8E24000C */  lw        $a0, 0xc($s1)
/* 138D1C 802459DC 0C0511F8 */  jal       draw_icon_2
/* 138D20 802459E0 27D00065 */   addiu    $s0, $fp, 0x65
/* 138D24 802459E4 0C093BA0 */  jal       pause_get_menu_string
/* 138D28 802459E8 24040032 */   addiu    $a0, $zero, 0x32
/* 138D2C 802459EC 0040202D */  daddu     $a0, $v0, $zero
/* 138D30 802459F0 0200302D */  daddu     $a2, $s0, $zero
/* 138D34 802459F4 8FA80084 */  lw        $t0, 0x84($sp)
/* 138D38 802459F8 240700FF */  addiu     $a3, $zero, 0xff
/* 138D3C 802459FC 2508009B */  addiu     $t0, $t0, 0x9b
/* 138D40 80245A00 0100282D */  daddu     $a1, $t0, $zero
/* 138D44 80245A04 AFA80054 */  sw        $t0, 0x54($sp)
/* 138D48 80245A08 2408000A */  addiu     $t0, $zero, 0xa
/* 138D4C 80245A0C AFA80010 */  sw        $t0, 0x10($sp)
/* 138D50 80245A10 24080001 */  addiu     $t0, $zero, 1
/* 138D54 80245A14 0C04993B */  jal       draw_string
/* 138D58 80245A18 AFA80014 */   sw       $t0, 0x14($sp)
/* 138D5C 80245A1C 0200302D */  daddu     $a2, $s0, $zero
/* 138D60 80245A20 24070001 */  addiu     $a3, $zero, 1
/* 138D64 80245A24 8FA80084 */  lw        $t0, 0x84($sp)
/* 138D68 80245A28 3C048011 */  lui       $a0, 0x8011
/* 138D6C 80245A2C 8484F29C */  lh        $a0, -0xd64($a0)
/* 138D70 80245A30 24120003 */  addiu     $s2, $zero, 3
/* 138D74 80245A34 AFB20018 */  sw        $s2, 0x18($sp)
/* 138D78 80245A38 25140119 */  addiu     $s4, $t0, 0x119
/* 138D7C 80245A3C 0280282D */  daddu     $a1, $s4, $zero
/* 138D80 80245A40 2408000A */  addiu     $t0, $zero, 0xa
/* 138D84 80245A44 AFA80010 */  sw        $t0, 0x10($sp)
/* 138D88 80245A48 240800FF */  addiu     $t0, $zero, 0xff
/* 138D8C 80245A4C 0C049DA7 */  jal       draw_number
/* 138D90 80245A50 AFA80014 */   sw       $t0, 0x14($sp)
/* 138D94 80245A54 27C6006C */  addiu     $a2, $fp, 0x6c
/* 138D98 80245A58 8FA80084 */  lw        $t0, 0x84($sp)
/* 138D9C 80245A5C 8E24002C */  lw        $a0, 0x2c($s1)
/* 138DA0 80245A60 251300F8 */  addiu     $s3, $t0, 0xf8
/* 138DA4 80245A64 0C051261 */  jal       set_icon_render_pos
/* 138DA8 80245A68 0260282D */   daddu    $a1, $s3, $zero
/* 138DAC 80245A6C 8E24002C */  lw        $a0, 0x2c($s1)
/* 138DB0 80245A70 0C0511F8 */  jal       draw_icon_2
/* 138DB4 80245A74 27D00056 */   addiu    $s0, $fp, 0x56
/* 138DB8 80245A78 8FA50050 */  lw        $a1, 0x50($sp)
/* 138DBC 80245A7C 8E240010 */  lw        $a0, 0x10($s1)
/* 138DC0 80245A80 0C051261 */  jal       set_icon_render_pos
/* 138DC4 80245A84 27C6005E */   addiu    $a2, $fp, 0x5e
/* 138DC8 80245A88 8E240010 */  lw        $a0, 0x10($s1)
/* 138DCC 80245A8C 0C0511F8 */  jal       draw_icon_2
/* 138DD0 80245A90 27D5007B */   addiu    $s5, $fp, 0x7b
/* 138DD4 80245A94 0C093BA0 */  jal       pause_get_menu_string
/* 138DD8 80245A98 24040033 */   addiu    $a0, $zero, 0x33
/* 138DDC 80245A9C 0040202D */  daddu     $a0, $v0, $zero
/* 138DE0 80245AA0 0200302D */  daddu     $a2, $s0, $zero
/* 138DE4 80245AA4 240700FF */  addiu     $a3, $zero, 0xff
/* 138DE8 80245AA8 8FA50054 */  lw        $a1, 0x54($sp)
/* 138DEC 80245AAC 2408000A */  addiu     $t0, $zero, 0xa
/* 138DF0 80245AB0 AFA80010 */  sw        $t0, 0x10($sp)
/* 138DF4 80245AB4 24080001 */  addiu     $t0, $zero, 1
/* 138DF8 80245AB8 0C04993B */  jal       draw_string
/* 138DFC 80245ABC AFA80014 */   sw       $t0, 0x14($sp)
/* 138E00 80245AC0 0280282D */  daddu     $a1, $s4, $zero
/* 138E04 80245AC4 0200302D */  daddu     $a2, $s0, $zero
/* 138E08 80245AC8 24070001 */  addiu     $a3, $zero, 1
/* 138E0C 80245ACC 3C048011 */  lui       $a0, 0x8011
/* 138E10 80245AD0 8084F2A0 */  lb        $a0, -0xd60($a0)
/* 138E14 80245AD4 2408000A */  addiu     $t0, $zero, 0xa
/* 138E18 80245AD8 AFA80010 */  sw        $t0, 0x10($sp)
/* 138E1C 80245ADC 240800FF */  addiu     $t0, $zero, 0xff
/* 138E20 80245AE0 AFA80014 */  sw        $t0, 0x14($sp)
/* 138E24 80245AE4 0C049DA7 */  jal       draw_number
/* 138E28 80245AE8 AFB20018 */   sw       $s2, 0x18($sp)
/* 138E2C 80245AEC 0260282D */  daddu     $a1, $s3, $zero
/* 138E30 80245AF0 8E24002C */  lw        $a0, 0x2c($s1)
/* 138E34 80245AF4 0C051261 */  jal       set_icon_render_pos
/* 138E38 80245AF8 27C6005D */   addiu    $a2, $fp, 0x5d
/* 138E3C 80245AFC 8E24002C */  lw        $a0, 0x2c($s1)
/* 138E40 80245B00 0C0511F8 */  jal       draw_icon_2
/* 138E44 80245B04 27D00074 */   addiu    $s0, $fp, 0x74
/* 138E48 80245B08 8FA50050 */  lw        $a1, 0x50($sp)
/* 138E4C 80245B0C 8E240014 */  lw        $a0, 0x14($s1)
/* 138E50 80245B10 0C051261 */  jal       set_icon_render_pos
/* 138E54 80245B14 02A0302D */   daddu    $a2, $s5, $zero
/* 138E58 80245B18 8E240014 */  lw        $a0, 0x14($s1)
/* 138E5C 80245B1C 0C0511F8 */  jal       draw_icon_2
/* 138E60 80245B20 00000000 */   nop      
/* 138E64 80245B24 0C093BA0 */  jal       pause_get_menu_string
/* 138E68 80245B28 24040034 */   addiu    $a0, $zero, 0x34
/* 138E6C 80245B2C 0040202D */  daddu     $a0, $v0, $zero
/* 138E70 80245B30 0200302D */  daddu     $a2, $s0, $zero
/* 138E74 80245B34 240700FF */  addiu     $a3, $zero, 0xff
/* 138E78 80245B38 8FA50054 */  lw        $a1, 0x54($sp)
/* 138E7C 80245B3C 2408000A */  addiu     $t0, $zero, 0xa
/* 138E80 80245B40 AFA80010 */  sw        $t0, 0x10($sp)
/* 138E84 80245B44 24080001 */  addiu     $t0, $zero, 1
/* 138E88 80245B48 0C04993B */  jal       draw_string
/* 138E8C 80245B4C AFA80014 */   sw       $t0, 0x14($sp)
/* 138E90 80245B50 0280282D */  daddu     $a1, $s4, $zero
/* 138E94 80245B54 0200302D */  daddu     $a2, $s0, $zero
/* 138E98 80245B58 24070001 */  addiu     $a3, $zero, 1
/* 138E9C 80245B5C 3C048011 */  lui       $a0, 0x8011
/* 138EA0 80245B60 9084F29F */  lbu       $a0, -0xd61($a0)
/* 138EA4 80245B64 2408000A */  addiu     $t0, $zero, 0xa
/* 138EA8 80245B68 AFA80010 */  sw        $t0, 0x10($sp)
/* 138EAC 80245B6C 240800FF */  addiu     $t0, $zero, 0xff
/* 138EB0 80245B70 AFA80014 */  sw        $t0, 0x14($sp)
/* 138EB4 80245B74 0C049DA7 */  jal       draw_number
/* 138EB8 80245B78 AFB20018 */   sw       $s2, 0x18($sp)
/* 138EBC 80245B7C 0260282D */  daddu     $a1, $s3, $zero
/* 138EC0 80245B80 8E24002C */  lw        $a0, 0x2c($s1)
/* 138EC4 80245B84 0C051261 */  jal       set_icon_render_pos
/* 138EC8 80245B88 02A0302D */   daddu    $a2, $s5, $zero
/* 138ECC 80245B8C 8E24002C */  lw        $a0, 0x2c($s1)
/* 138ED0 80245B90 0C0511F8 */  jal       draw_icon_2
/* 138ED4 80245B94 27D00033 */   addiu    $s0, $fp, 0x33
/* 138ED8 80245B98 0000202D */  daddu     $a0, $zero, $zero
/* 138EDC 80245B9C 8FA80084 */  lw        $t0, 0x84($sp)
/* 138EE0 80245BA0 27C60023 */  addiu     $a2, $fp, 0x23
/* 138EE4 80245BA4 25160015 */  addiu     $s6, $t0, 0x15
/* 138EE8 80245BA8 0C093BA5 */  jal       pause_draw_menu_label
/* 138EEC 80245BAC 02C0282D */   daddu    $a1, $s6, $zero
/* 138EF0 80245BB0 27C60039 */  addiu     $a2, $fp, 0x39
/* 138EF4 80245BB4 8FA80084 */  lw        $t0, 0x84($sp)
/* 138EF8 80245BB8 8E24001C */  lw        $a0, 0x1c($s1)
/* 138EFC 80245BBC 25150034 */  addiu     $s5, $t0, 0x34
/* 138F00 80245BC0 0C051261 */  jal       set_icon_render_pos
/* 138F04 80245BC4 02A0282D */   daddu    $a1, $s5, $zero
/* 138F08 80245BC8 8E24001C */  lw        $a0, 0x1c($s1)
/* 138F0C 80245BCC 0C0511F8 */  jal       draw_icon_2
/* 138F10 80245BD0 00000000 */   nop      
/* 138F14 80245BD4 0C093BA0 */  jal       pause_get_menu_string
/* 138F18 80245BD8 24040036 */   addiu    $a0, $zero, 0x36
/* 138F1C 80245BDC 0040202D */  daddu     $a0, $v0, $zero
/* 138F20 80245BE0 0200302D */  daddu     $a2, $s0, $zero
/* 138F24 80245BE4 8FA80084 */  lw        $t0, 0x84($sp)
/* 138F28 80245BE8 240700FF */  addiu     $a3, $zero, 0xff
/* 138F2C 80245BEC AFA00010 */  sw        $zero, 0x10($sp)
/* 138F30 80245BF0 25140019 */  addiu     $s4, $t0, 0x19
/* 138F34 80245BF4 0280282D */  daddu     $a1, $s4, $zero
/* 138F38 80245BF8 24080001 */  addiu     $t0, $zero, 1
/* 138F3C 80245BFC 0C04993B */  jal       draw_string
/* 138F40 80245C00 AFA80014 */   sw       $t0, 0x14($sp)
/* 138F44 80245C04 0200302D */  daddu     $a2, $s0, $zero
/* 138F48 80245C08 8FA80084 */  lw        $t0, 0x84($sp)
/* 138F4C 80245C0C 3C048011 */  lui       $a0, 0x8011
/* 138F50 80245C10 8084F292 */  lb        $a0, -0xd6e($a0)
/* 138F54 80245C14 24070001 */  addiu     $a3, $zero, 1
/* 138F58 80245C18 AFA00010 */  sw        $zero, 0x10($sp)
/* 138F5C 80245C1C AFB20018 */  sw        $s2, 0x18($sp)
/* 138F60 80245C20 2513004E */  addiu     $s3, $t0, 0x4e
/* 138F64 80245C24 0260282D */  daddu     $a1, $s3, $zero
/* 138F68 80245C28 240800FF */  addiu     $t0, $zero, 0xff
/* 138F6C 80245C2C 0C049DA7 */  jal       draw_number
/* 138F70 80245C30 AFA80014 */   sw       $t0, 0x14($sp)
/* 138F74 80245C34 0C093BA0 */  jal       pause_get_menu_string
/* 138F78 80245C38 24040039 */   addiu    $a0, $zero, 0x39
/* 138F7C 80245C3C 0040202D */  daddu     $a0, $v0, $zero
/* 138F80 80245C40 0260282D */  daddu     $a1, $s3, $zero
/* 138F84 80245C44 0200302D */  daddu     $a2, $s0, $zero
/* 138F88 80245C48 240700FF */  addiu     $a3, $zero, 0xff
/* 138F8C 80245C4C 24080001 */  addiu     $t0, $zero, 1
/* 138F90 80245C50 AFA00010 */  sw        $zero, 0x10($sp)
/* 138F94 80245C54 0C04993B */  jal       draw_string
/* 138F98 80245C58 AFA80014 */   sw       $t0, 0x14($sp)
/* 138F9C 80245C5C 0200302D */  daddu     $a2, $s0, $zero
/* 138FA0 80245C60 8FA80084 */  lw        $t0, 0x84($sp)
/* 138FA4 80245C64 3C048011 */  lui       $a0, 0x8011
/* 138FA8 80245C68 8084F293 */  lb        $a0, -0xd6d($a0)
/* 138FAC 80245C6C 24070001 */  addiu     $a3, $zero, 1
/* 138FB0 80245C70 AFA00010 */  sw        $zero, 0x10($sp)
/* 138FB4 80245C74 AFB20018 */  sw        $s2, 0x18($sp)
/* 138FB8 80245C78 25170069 */  addiu     $s7, $t0, 0x69
/* 138FBC 80245C7C 02E0282D */  daddu     $a1, $s7, $zero
/* 138FC0 80245C80 240800FF */  addiu     $t0, $zero, 0xff
/* 138FC4 80245C84 0C049DA7 */  jal       draw_number
/* 138FC8 80245C88 AFA80014 */   sw       $t0, 0x14($sp)
/* 138FCC 80245C8C 24040001 */  addiu     $a0, $zero, 1
/* 138FD0 80245C90 02C0282D */  daddu     $a1, $s6, $zero
/* 138FD4 80245C94 0C093BA5 */  jal       pause_draw_menu_label
/* 138FD8 80245C98 27C60045 */   addiu    $a2, $fp, 0x45
/* 138FDC 80245C9C 02A0282D */  daddu     $a1, $s5, $zero
/* 138FE0 80245CA0 8E240020 */  lw        $a0, 0x20($s1)
/* 138FE4 80245CA4 0C051261 */  jal       set_icon_render_pos
/* 138FE8 80245CA8 27C6005C */   addiu    $a2, $fp, 0x5c
/* 138FEC 80245CAC 8E240020 */  lw        $a0, 0x20($s1)
/* 138FF0 80245CB0 0C0511F8 */  jal       draw_icon_2
/* 138FF4 80245CB4 27D00055 */   addiu    $s0, $fp, 0x55
/* 138FF8 80245CB8 0C093BA0 */  jal       pause_get_menu_string
/* 138FFC 80245CBC 24040037 */   addiu    $a0, $zero, 0x37
/* 139000 80245CC0 0040202D */  daddu     $a0, $v0, $zero
/* 139004 80245CC4 0280282D */  daddu     $a1, $s4, $zero
/* 139008 80245CC8 0200302D */  daddu     $a2, $s0, $zero
/* 13900C 80245CCC 240700FF */  addiu     $a3, $zero, 0xff
/* 139010 80245CD0 24080001 */  addiu     $t0, $zero, 1
/* 139014 80245CD4 AFA00010 */  sw        $zero, 0x10($sp)
/* 139018 80245CD8 0C04993B */  jal       draw_string
/* 13901C 80245CDC AFA80014 */   sw       $t0, 0x14($sp)
/* 139020 80245CE0 0260282D */  daddu     $a1, $s3, $zero
/* 139024 80245CE4 0200302D */  daddu     $a2, $s0, $zero
/* 139028 80245CE8 24070001 */  addiu     $a3, $zero, 1
/* 13902C 80245CEC 3C048011 */  lui       $a0, 0x8011
/* 139030 80245CF0 8084F295 */  lb        $a0, -0xd6b($a0)
/* 139034 80245CF4 240800FF */  addiu     $t0, $zero, 0xff
/* 139038 80245CF8 AFA00010 */  sw        $zero, 0x10($sp)
/* 13903C 80245CFC AFA80014 */  sw        $t0, 0x14($sp)
/* 139040 80245D00 0C049DA7 */  jal       draw_number
/* 139044 80245D04 AFB20018 */   sw       $s2, 0x18($sp)
/* 139048 80245D08 0C093BA0 */  jal       pause_get_menu_string
/* 13904C 80245D0C 24040039 */   addiu    $a0, $zero, 0x39
/* 139050 80245D10 0040202D */  daddu     $a0, $v0, $zero
/* 139054 80245D14 0260282D */  daddu     $a1, $s3, $zero
/* 139058 80245D18 0200302D */  daddu     $a2, $s0, $zero
/* 13905C 80245D1C 240700FF */  addiu     $a3, $zero, 0xff
/* 139060 80245D20 24080001 */  addiu     $t0, $zero, 1
/* 139064 80245D24 AFA00010 */  sw        $zero, 0x10($sp)
/* 139068 80245D28 0C04993B */  jal       draw_string
/* 13906C 80245D2C AFA80014 */   sw       $t0, 0x14($sp)
/* 139070 80245D30 02E0282D */  daddu     $a1, $s7, $zero
/* 139074 80245D34 0200302D */  daddu     $a2, $s0, $zero
/* 139078 80245D38 24070001 */  addiu     $a3, $zero, 1
/* 13907C 80245D3C 3C048011 */  lui       $a0, 0x8011
/* 139080 80245D40 8084F296 */  lb        $a0, -0xd6a($a0)
/* 139084 80245D44 240800FF */  addiu     $t0, $zero, 0xff
/* 139088 80245D48 AFA00010 */  sw        $zero, 0x10($sp)
/* 13908C 80245D4C AFA80014 */  sw        $t0, 0x14($sp)
/* 139090 80245D50 0C049DA7 */  jal       draw_number
/* 139094 80245D54 AFB20018 */   sw       $s2, 0x18($sp)
/* 139098 80245D58 24040002 */  addiu     $a0, $zero, 2
/* 13909C 80245D5C 02C0282D */  daddu     $a1, $s6, $zero
/* 1390A0 80245D60 0C093BA5 */  jal       pause_draw_menu_label
/* 1390A4 80245D64 27C60067 */   addiu    $a2, $fp, 0x67
/* 1390A8 80245D68 02A0282D */  daddu     $a1, $s5, $zero
/* 1390AC 80245D6C 8E240024 */  lw        $a0, 0x24($s1)
/* 1390B0 80245D70 0C051261 */  jal       set_icon_render_pos
/* 1390B4 80245D74 27C6007E */   addiu    $a2, $fp, 0x7e
/* 1390B8 80245D78 8E240024 */  lw        $a0, 0x24($s1)
/* 1390BC 80245D7C 0C0511F8 */  jal       draw_icon_2
/* 1390C0 80245D80 27D00077 */   addiu    $s0, $fp, 0x77
/* 1390C4 80245D84 0C093BA0 */  jal       pause_get_menu_string
/* 1390C8 80245D88 24040038 */   addiu    $a0, $zero, 0x38
/* 1390CC 80245D8C 0040202D */  daddu     $a0, $v0, $zero
/* 1390D0 80245D90 0280282D */  daddu     $a1, $s4, $zero
/* 1390D4 80245D94 0200302D */  daddu     $a2, $s0, $zero
/* 1390D8 80245D98 240700FF */  addiu     $a3, $zero, 0xff
/* 1390DC 80245D9C 24080001 */  addiu     $t0, $zero, 1
/* 1390E0 80245DA0 AFA00010 */  sw        $zero, 0x10($sp)
/* 1390E4 80245DA4 0C04993B */  jal       draw_string
/* 1390E8 80245DA8 AFA80014 */   sw       $t0, 0x14($sp)
/* 1390EC 80245DAC 0260282D */  daddu     $a1, $s3, $zero
/* 1390F0 80245DB0 0200302D */  daddu     $a2, $s0, $zero
/* 1390F4 80245DB4 24070001 */  addiu     $a3, $zero, 1
/* 1390F8 80245DB8 3C048011 */  lui       $a0, 0x8011
/* 1390FC 80245DBC 8084F298 */  lb        $a0, -0xd68($a0)
/* 139100 80245DC0 240800FF */  addiu     $t0, $zero, 0xff
/* 139104 80245DC4 AFA00010 */  sw        $zero, 0x10($sp)
/* 139108 80245DC8 AFA80014 */  sw        $t0, 0x14($sp)
/* 13910C 80245DCC 0C049DA7 */  jal       draw_number
/* 139110 80245DD0 AFB20018 */   sw       $s2, 0x18($sp)
/* 139114 80245DD4 8FA50050 */  lw        $a1, 0x50($sp)
/* 139118 80245DD8 8E240018 */  lw        $a0, 0x18($s1)
/* 13911C 80245DDC 0C051261 */  jal       set_icon_render_pos
/* 139120 80245DE0 27C6008C */   addiu    $a2, $fp, 0x8c
/* 139124 80245DE4 8E240018 */  lw        $a0, 0x18($s1)
/* 139128 80245DE8 0C0511F8 */  jal       draw_icon_2
/* 13912C 80245DEC 27D50085 */   addiu    $s5, $fp, 0x85
/* 139130 80245DF0 0C093BA0 */  jal       pause_get_menu_string
/* 139134 80245DF4 24040035 */   addiu    $a0, $zero, 0x35
/* 139138 80245DF8 0040202D */  daddu     $a0, $v0, $zero
/* 13913C 80245DFC 02A0302D */  daddu     $a2, $s5, $zero
/* 139140 80245E00 240700FF */  addiu     $a3, $zero, 0xff
/* 139144 80245E04 8FA50054 */  lw        $a1, 0x54($sp)
/* 139148 80245E08 2408000A */  addiu     $t0, $zero, 0xa
/* 13914C 80245E0C AFA80010 */  sw        $t0, 0x10($sp)
/* 139150 80245E10 24080001 */  addiu     $t0, $zero, 1
/* 139154 80245E14 0C04993B */  jal       draw_string
/* 139158 80245E18 AFA80014 */   sw       $t0, 0x14($sp)
/* 13915C 80245E1C 3C020149 */  lui       $v0, 0x149
/* 139160 80245E20 3C148011 */  lui       $s4, 0x8011
/* 139164 80245E24 8E94F54C */  lw        $s4, -0xab4($s4)
/* 139168 80245E28 344296FF */  ori       $v0, $v0, 0x96ff
/* 13916C 80245E2C 0054102A */  slt       $v0, $v0, $s4
/* 139170 80245E30 10400003 */  beqz      $v0, .L80245E40
/* 139174 80245E34 3C021F11 */   lui      $v0, 0x1f11
/* 139178 80245E38 3C140149 */  lui       $s4, 0x149
/* 13917C 80245E3C 369496FF */  ori       $s4, $s4, 0x96ff
.L80245E40:
/* 139180 80245E40 3442A4A5 */  ori       $v0, $v0, 0xa4a5
/* 139184 80245E44 3C036666 */  lui       $v1, 0x6666
/* 139188 80245E48 34636667 */  ori       $v1, $v1, 0x6667
/* 13918C 80245E4C 02A0302D */  daddu     $a2, $s5, $zero
/* 139190 80245E50 24070001 */  addiu     $a3, $zero, 1
/* 139194 80245E54 00149FC3 */  sra       $s3, $s4, 0x1f
/* 139198 80245E58 02820018 */  mult      $s4, $v0
/* 13919C 80245E5C 8FA80084 */  lw        $t0, 0x84($sp)
/* 1391A0 80245E60 24120002 */  addiu     $s2, $zero, 2
/* 1391A4 80245E64 AFB20018 */  sw        $s2, 0x18($sp)
/* 1391A8 80245E68 250500ED */  addiu     $a1, $t0, 0xed
/* 1391AC 80245E6C 00004010 */  mfhi      $t0
/* 1391B0 80245E70 00088483 */  sra       $s0, $t0, 0x12
/* 1391B4 80245E74 02138023 */  subu      $s0, $s0, $s3
/* 1391B8 80245E78 2408000A */  addiu     $t0, $zero, 0xa
/* 1391BC 80245E7C 02030018 */  mult      $s0, $v1
/* 1391C0 80245E80 AFA80010 */  sw        $t0, 0x10($sp)
/* 1391C4 80245E84 240800FF */  addiu     $t0, $zero, 0xff
/* 1391C8 80245E88 00101FC3 */  sra       $v1, $s0, 0x1f
/* 1391CC 80245E8C AFA80014 */  sw        $t0, 0x14($sp)
/* 1391D0 80245E90 00004010 */  mfhi      $t0
/* 1391D4 80245E94 02481007 */  srav      $v0, $t0, $s2
/* 1391D8 80245E98 00431023 */  subu      $v0, $v0, $v1
/* 1391DC 80245E9C 02422004 */  sllv      $a0, $v0, $s2
/* 1391E0 80245EA0 00822021 */  addu      $a0, $a0, $v0
/* 1391E4 80245EA4 00E42004 */  sllv      $a0, $a0, $a3
/* 1391E8 80245EA8 0C049DA7 */  jal       draw_number
/* 1391EC 80245EAC 02042023 */   subu     $a0, $s0, $a0
/* 1391F0 80245EB0 3C029B58 */  lui       $v0, 0x9b58
/* 1391F4 80245EB4 34423739 */  ori       $v0, $v0, 0x3739
/* 1391F8 80245EB8 02A0302D */  daddu     $a2, $s5, $zero
/* 1391FC 80245EBC 24070001 */  addiu     $a3, $zero, 1
/* 139200 80245EC0 02502004 */  sllv      $a0, $s0, $s2
/* 139204 80245EC4 00902021 */  addu      $a0, $a0, $s0
/* 139208 80245EC8 00E42004 */  sllv      $a0, $a0, $a3
/* 13920C 80245ECC 8FA80084 */  lw        $t0, 0x84($sp)
/* 139210 80245ED0 02820018 */  mult      $s4, $v0
/* 139214 80245ED4 AFB20018 */  sw        $s2, 0x18($sp)
/* 139218 80245ED8 250500F6 */  addiu     $a1, $t0, 0xf6
/* 13921C 80245EDC 2408000A */  addiu     $t0, $zero, 0xa
/* 139220 80245EE0 AFA80010 */  sw        $t0, 0x10($sp)
/* 139224 80245EE4 240800FF */  addiu     $t0, $zero, 0xff
/* 139228 80245EE8 AFA80014 */  sw        $t0, 0x14($sp)
/* 13922C 80245EEC 00004010 */  mfhi      $t0
/* 139230 80245EF0 01148821 */  addu      $s1, $t0, $s4
/* 139234 80245EF4 00118C43 */  sra       $s1, $s1, 0x11
/* 139238 80245EF8 02338823 */  subu      $s1, $s1, $s3
/* 13923C 80245EFC 0C049DA7 */  jal       draw_number
/* 139240 80245F00 02242023 */   subu     $a0, $s1, $a0
/* 139244 80245F04 0C093BA0 */  jal       pause_get_menu_string
/* 139248 80245F08 2404003A */   addiu    $a0, $zero, 0x3a
/* 13924C 80245F0C 0040202D */  daddu     $a0, $v0, $zero
/* 139250 80245F10 27C60084 */  addiu     $a2, $fp, 0x84
/* 139254 80245F14 8FA80084 */  lw        $t0, 0x84($sp)
/* 139258 80245F18 240700FF */  addiu     $a3, $zero, 0xff
/* 13925C 80245F1C 25100101 */  addiu     $s0, $t0, 0x101
/* 139260 80245F20 0200282D */  daddu     $a1, $s0, $zero
/* 139264 80245F24 2408000A */  addiu     $t0, $zero, 0xa
/* 139268 80245F28 AFA80010 */  sw        $t0, 0x10($sp)
/* 13926C 80245F2C 24080001 */  addiu     $t0, $zero, 1
/* 139270 80245F30 0C04993B */  jal       draw_string
/* 139274 80245F34 AFA80014 */   sw       $t0, 0x14($sp)
/* 139278 80245F38 0C093BA0 */  jal       pause_get_menu_string
/* 13927C 80245F3C 2404003A */   addiu    $a0, $zero, 0x3a
/* 139280 80245F40 0040202D */  daddu     $a0, $v0, $zero
/* 139284 80245F44 0200282D */  daddu     $a1, $s0, $zero
/* 139288 80245F48 27C6007F */  addiu     $a2, $fp, 0x7f
/* 13928C 80245F4C 240700FF */  addiu     $a3, $zero, 0xff
/* 139290 80245F50 2408000A */  addiu     $t0, $zero, 0xa
/* 139294 80245F54 AFA80010 */  sw        $t0, 0x10($sp)
/* 139298 80245F58 24080001 */  addiu     $t0, $zero, 1
/* 13929C 80245F5C 0C04993B */  jal       draw_string
/* 1392A0 80245F60 AFA80014 */   sw       $t0, 0x14($sp)
/* 1392A4 80245F64 3C027482 */  lui       $v0, 0x7482
/* 1392A8 80245F68 3442296B */  ori       $v0, $v0, 0x296b
/* 1392AC 80245F6C 02A0302D */  daddu     $a2, $s5, $zero
/* 1392B0 80245F70 24070001 */  addiu     $a3, $zero, 1
/* 1392B4 80245F74 00F12004 */  sllv      $a0, $s1, $a3
/* 1392B8 80245F78 00912021 */  addu      $a0, $a0, $s1
/* 1392BC 80245F7C 00E42004 */  sllv      $a0, $a0, $a3
/* 1392C0 80245F80 8FA80084 */  lw        $t0, 0x84($sp)
/* 1392C4 80245F84 02820018 */  mult      $s4, $v0
/* 1392C8 80245F88 AFB20018 */  sw        $s2, 0x18($sp)
/* 1392CC 80245F8C 25050108 */  addiu     $a1, $t0, 0x108
/* 1392D0 80245F90 2408000A */  addiu     $t0, $zero, 0xa
/* 1392D4 80245F94 AFA80010 */  sw        $t0, 0x10($sp)
/* 1392D8 80245F98 240800FF */  addiu     $t0, $zero, 0xff
/* 1392DC 80245F9C AFA80014 */  sw        $t0, 0x14($sp)
/* 1392E0 80245FA0 00004010 */  mfhi      $t0
/* 1392E4 80245FA4 00088383 */  sra       $s0, $t0, 0xe
/* 1392E8 80245FA8 02138023 */  subu      $s0, $s0, $s3
/* 1392EC 80245FAC 0C049DA7 */  jal       draw_number
/* 1392F0 80245FB0 02042023 */   subu     $a0, $s0, $a0
/* 1392F4 80245FB4 3C0291A2 */  lui       $v0, 0x91a2
/* 1392F8 80245FB8 3442B3C5 */  ori       $v0, $v0, 0xb3c5
/* 1392FC 80245FBC 02A0302D */  daddu     $a2, $s5, $zero
/* 139300 80245FC0 24070001 */  addiu     $a3, $zero, 1
/* 139304 80245FC4 02502004 */  sllv      $a0, $s0, $s2
/* 139308 80245FC8 00902021 */  addu      $a0, $a0, $s0
/* 13930C 80245FCC 00E42004 */  sllv      $a0, $a0, $a3
/* 139310 80245FD0 8FA80084 */  lw        $t0, 0x84($sp)
/* 139314 80245FD4 02820018 */  mult      $s4, $v0
/* 139318 80245FD8 AFB20018 */  sw        $s2, 0x18($sp)
/* 13931C 80245FDC 25050111 */  addiu     $a1, $t0, 0x111
/* 139320 80245FE0 2408000A */  addiu     $t0, $zero, 0xa
/* 139324 80245FE4 AFA80010 */  sw        $t0, 0x10($sp)
/* 139328 80245FE8 240800FF */  addiu     $t0, $zero, 0xff
/* 13932C 80245FEC AFA80014 */  sw        $t0, 0x14($sp)
/* 139330 80245FF0 00004010 */  mfhi      $t0
/* 139334 80245FF4 01141021 */  addu      $v0, $t0, $s4
/* 139338 80245FF8 000212C3 */  sra       $v0, $v0, 0xb
/* 13933C 80245FFC 00531023 */  subu      $v0, $v0, $s3
/* 139340 80246000 0C049DA7 */  jal       draw_number
/* 139344 80246004 00442023 */   subu     $a0, $v0, $a0
/* 139348 80246008 3C028011 */  lui       $v0, 0x8011
/* 13934C 8024600C 9042F290 */  lbu       $v0, -0xd70($v0)
/* 139350 80246010 3C038011 */  lui       $v1, 0x8011
/* 139354 80246014 9063F291 */  lbu       $v1, -0xd6f($v1)
/* 139358 80246018 8FA80084 */  lw        $t0, 0x84($sp)
/* 13935C 8024601C 27C7000C */  addiu     $a3, $fp, 0xc
/* 139360 80246020 AFA00010 */  sw        $zero, 0x10($sp)
/* 139364 80246024 00021600 */  sll       $v0, $v0, 0x18
/* 139368 80246028 00029603 */  sra       $s2, $v0, 0x18
/* 13936C 8024602C 00031E00 */  sll       $v1, $v1, 0x18
/* 139370 80246030 00039E03 */  sra       $s3, $v1, 0x18
/* 139374 80246034 3C028011 */  lui       $v0, 0x8011
/* 139378 80246038 9042F299 */  lbu       $v0, -0xd67($v0)
/* 13937C 8024603C 00021600 */  sll       $v0, $v0, 0x18
/* 139380 80246040 0002A603 */  sra       $s4, $v0, 0x18
/* 139384 80246044 0280102D */  daddu     $v0, $s4, $zero
/* 139388 80246048 2842000A */  slti      $v0, $v0, 0xa
/* 13938C 8024604C 14400003 */  bnez      $v0, .L8024605C
/* 139390 80246050 25060007 */   addiu    $a2, $t0, 7
/* 139394 80246054 08091818 */  j         .L80246060
/* 139398 80246058 24020079 */   addiu    $v0, $zero, 0x79
.L8024605C:
/* 13939C 8024605C 24020071 */  addiu     $v0, $zero, 0x71
.L80246060:
/* 1393A0 80246060 AFA20014 */  sw        $v0, 0x14($sp)
/* 1393A4 80246064 24040004 */  addiu     $a0, $zero, 4
/* 1393A8 80246068 3C058027 */  lui       $a1, 0x8027
/* 1393AC 8024606C 24A5FB30 */  addiu     $a1, $a1, -0x4d0
/* 1393B0 80246070 24020011 */  addiu     $v0, $zero, 0x11
/* 1393B4 80246074 241100FF */  addiu     $s1, $zero, 0xff
/* 1393B8 80246078 AFA20018 */  sw        $v0, 0x18($sp)
/* 1393BC 8024607C 24020140 */  addiu     $v0, $zero, 0x140
/* 1393C0 80246080 AFA20044 */  sw        $v0, 0x44($sp)
/* 1393C4 80246084 240200F0 */  addiu     $v0, $zero, 0xf0
/* 1393C8 80246088 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1393CC 8024608C AFA00020 */  sw        $zero, 0x20($sp)
/* 1393D0 80246090 AFA00024 */  sw        $zero, 0x24($sp)
/* 1393D4 80246094 AFA00028 */  sw        $zero, 0x28($sp)
/* 1393D8 80246098 AFA0002C */  sw        $zero, 0x2c($sp)
/* 1393DC 8024609C AFA00030 */  sw        $zero, 0x30($sp)
/* 1393E0 802460A0 AFA00034 */  sw        $zero, 0x34($sp)
/* 1393E4 802460A4 AFA00038 */  sw        $zero, 0x38($sp)
/* 1393E8 802460A8 AFA0003C */  sw        $zero, 0x3c($sp)
/* 1393EC 802460AC AFA00040 */  sw        $zero, 0x40($sp)
/* 1393F0 802460B0 AFA20048 */  sw        $v0, 0x48($sp)
/* 1393F4 802460B4 0C03D4B8 */  jal       draw_box
/* 1393F8 802460B8 AFA0004C */   sw       $zero, 0x4c($sp)
/* 1393FC 802460BC 3C168027 */  lui       $s6, 0x8027
/* 139400 802460C0 26D60150 */  addiu     $s6, $s6, 0x150
/* 139404 802460C4 27C60015 */  addiu     $a2, $fp, 0x15
/* 139408 802460C8 8FA80084 */  lw        $t0, 0x84($sp)
/* 13940C 802460CC 8EC40000 */  lw        $a0, ($s6)
/* 139410 802460D0 0C051261 */  jal       set_icon_render_pos
/* 139414 802460D4 2505003D */   addiu    $a1, $t0, 0x3d
/* 139418 802460D8 8EC40000 */  lw        $a0, ($s6)
/* 13941C 802460DC 0C0511F8 */  jal       draw_icon_2
/* 139420 802460E0 27D0000E */   addiu    $s0, $fp, 0xe
/* 139424 802460E4 0C093BA0 */  jal       pause_get_menu_string
/* 139428 802460E8 24040043 */   addiu    $a0, $zero, 0x43
/* 13942C 802460EC 0040202D */  daddu     $a0, $v0, $zero
/* 139430 802460F0 0200302D */  daddu     $a2, $s0, $zero
/* 139434 802460F4 0220382D */  daddu     $a3, $s1, $zero
/* 139438 802460F8 8FA80084 */  lw        $t0, 0x84($sp)
/* 13943C 802460FC 24170001 */  addiu     $s7, $zero, 1
/* 139440 80246100 AFA00010 */  sw        $zero, 0x10($sp)
/* 139444 80246104 AFB70014 */  sw        $s7, 0x14($sp)
/* 139448 80246108 0C04993B */  jal       draw_string
/* 13944C 8024610C 25050010 */   addiu    $a1, $t0, 0x10
/* 139450 80246110 0C093BA0 */  jal       pause_get_menu_string
/* 139454 80246114 24040044 */   addiu    $a0, $zero, 0x44
/* 139458 80246118 0040202D */  daddu     $a0, $v0, $zero
/* 13945C 8024611C 0200302D */  daddu     $a2, $s0, $zero
/* 139460 80246120 8FA80084 */  lw        $t0, 0x84($sp)
/* 139464 80246124 0220382D */  daddu     $a3, $s1, $zero
/* 139468 80246128 AFA00010 */  sw        $zero, 0x10($sp)
/* 13946C 8024612C AFB70014 */  sw        $s7, 0x14($sp)
/* 139470 80246130 0C04993B */  jal       draw_string
/* 139474 80246134 25050043 */   addiu    $a1, $t0, 0x43
/* 139478 80246138 00142400 */  sll       $a0, $s4, 0x10
/* 13947C 8024613C 00042403 */  sra       $a0, $a0, 0x10
/* 139480 80246140 0200302D */  daddu     $a2, $s0, $zero
/* 139484 80246144 02E0382D */  daddu     $a3, $s7, $zero
/* 139488 80246148 8FA80084 */  lw        $t0, 0x84($sp)
/* 13948C 8024614C 24020002 */  addiu     $v0, $zero, 2
/* 139490 80246150 AFA00010 */  sw        $zero, 0x10($sp)
/* 139494 80246154 AFB10014 */  sw        $s1, 0x14($sp)
/* 139498 80246158 AFA20018 */  sw        $v0, 0x18($sp)
/* 13949C 8024615C 0C049DA7 */  jal       draw_number
/* 1394A0 80246160 2505006A */   addiu    $a1, $t0, 0x6a
/* 1394A4 80246164 02571021 */  addu      $v0, $s2, $s7
/* 1394A8 80246168 0040902D */  daddu     $s2, $v0, $zero
/* 1394AC 8024616C 00021400 */  sll       $v0, $v0, 0x10
/* 1394B0 80246170 04420001 */  bltzl     $v0, .L80246178
/* 1394B4 80246174 0000902D */   daddu    $s2, $zero, $zero
.L80246178:
/* 1394B8 80246178 00121400 */  sll       $v0, $s2, 0x10
/* 1394BC 8024617C 00021403 */  sra       $v0, $v0, 0x10
/* 1394C0 80246180 28420004 */  slti      $v0, $v0, 4
/* 1394C4 80246184 50400001 */  beql      $v0, $zero, .L8024618C
/* 1394C8 80246188 24120003 */   addiu    $s2, $zero, 3
.L8024618C:
/* 1394CC 8024618C 26620001 */  addiu     $v0, $s3, 1
/* 1394D0 80246190 0040982D */  daddu     $s3, $v0, $zero
/* 1394D4 80246194 00021400 */  sll       $v0, $v0, 0x10
/* 1394D8 80246198 04420001 */  bltzl     $v0, .L802461A0
/* 1394DC 8024619C 0000982D */   daddu    $s3, $zero, $zero
.L802461A0:
/* 1394E0 802461A0 00131400 */  sll       $v0, $s3, 0x10
/* 1394E4 802461A4 00021403 */  sra       $v0, $v0, 0x10
/* 1394E8 802461A8 28420004 */  slti      $v0, $v0, 4
/* 1394EC 802461AC 50400001 */  beql      $v0, $zero, .L802461B4
/* 1394F0 802461B0 24130003 */   addiu    $s3, $zero, 3
.L802461B4:
/* 1394F4 802461B4 24040003 */  addiu     $a0, $zero, 3
/* 1394F8 802461B8 8FA80084 */  lw        $t0, 0x84($sp)
/* 1394FC 802461BC 27C6000A */  addiu     $a2, $fp, 0xa
/* 139500 802461C0 25100089 */  addiu     $s0, $t0, 0x89
/* 139504 802461C4 0C093BA5 */  jal       pause_draw_menu_label
/* 139508 802461C8 0200282D */   daddu    $a1, $s0, $zero
/* 13950C 802461CC 24040004 */  addiu     $a0, $zero, 4
/* 139510 802461D0 0200282D */  daddu     $a1, $s0, $zero
/* 139514 802461D4 0C093BA5 */  jal       pause_draw_menu_label
/* 139518 802461D8 27C60023 */   addiu    $a2, $fp, 0x23
/* 13951C 802461DC 00128400 */  sll       $s0, $s2, 0x10
/* 139520 802461E0 00108383 */  sra       $s0, $s0, 0xe
/* 139524 802461E4 8EC40004 */  lw        $a0, 4($s6)
/* 139528 802461E8 3C058025 */  lui       $a1, 0x8025
/* 13952C 802461EC 00B02821 */  addu      $a1, $a1, $s0
/* 139530 802461F0 8CA5F360 */  lw        $a1, -0xca0($a1)
/* 139534 802461F4 0C0511FF */  jal       set_menu_icon_script
/* 139538 802461F8 24140001 */   addiu    $s4, $zero, 1
/* 13953C 802461FC 27C6001D */  addiu     $a2, $fp, 0x1d
/* 139540 80246200 8FA80084 */  lw        $t0, 0x84($sp)
/* 139544 80246204 8EC40004 */  lw        $a0, 4($s6)
/* 139548 80246208 251100A3 */  addiu     $s1, $t0, 0xa3
/* 13954C 8024620C 0C051261 */  jal       set_icon_render_pos
/* 139550 80246210 0220282D */   daddu    $a1, $s1, $zero
/* 139554 80246214 8EC40004 */  lw        $a0, 4($s6)
/* 139558 80246218 0C0511F8 */  jal       draw_icon_2
/* 13955C 8024621C 00000000 */   nop      
/* 139560 80246220 3C048025 */  lui       $a0, 0x8025
/* 139564 80246224 00902021 */  addu      $a0, $a0, $s0
/* 139568 80246228 8C84F380 */  lw        $a0, -0xc80($a0)
/* 13956C 8024622C 0C093BA0 */  jal       pause_get_menu_string
/* 139570 80246230 00138400 */   sll      $s0, $s3, 0x10
/* 139574 80246234 0040202D */  daddu     $a0, $v0, $zero
/* 139578 80246238 27C60017 */  addiu     $a2, $fp, 0x17
/* 13957C 8024623C 8FA80084 */  lw        $t0, 0x84($sp)
/* 139580 80246240 240700FF */  addiu     $a3, $zero, 0xff
/* 139584 80246244 AFA00010 */  sw        $zero, 0x10($sp)
/* 139588 80246248 AFB70014 */  sw        $s7, 0x14($sp)
/* 13958C 8024624C 251200B0 */  addiu     $s2, $t0, 0xb0
/* 139590 80246250 0C04993B */  jal       draw_string
/* 139594 80246254 0240282D */   daddu    $a1, $s2, $zero
/* 139598 80246258 00108383 */  sra       $s0, $s0, 0xe
/* 13959C 8024625C 8EC40008 */  lw        $a0, 8($s6)
/* 1395A0 80246260 3C058025 */  lui       $a1, 0x8025
/* 1395A4 80246264 00B02821 */  addu      $a1, $a1, $s0
/* 1395A8 80246268 8CA5F370 */  lw        $a1, -0xc90($a1)
/* 1395AC 8024626C 0C0511FF */  jal       set_menu_icon_script
/* 1395B0 80246270 0000982D */   daddu    $s3, $zero, $zero
/* 1395B4 80246274 0220282D */  daddu     $a1, $s1, $zero
/* 1395B8 80246278 8EC40008 */  lw        $a0, 8($s6)
/* 1395BC 8024627C 0C051261 */  jal       set_icon_render_pos
/* 1395C0 80246280 27C60036 */   addiu    $a2, $fp, 0x36
/* 1395C4 80246284 8EC40008 */  lw        $a0, 8($s6)
/* 1395C8 80246288 0C0511F8 */  jal       draw_icon_2
/* 1395CC 8024628C 0260A82D */   daddu    $s5, $s3, $zero
/* 1395D0 80246290 3C048025 */  lui       $a0, 0x8025
/* 1395D4 80246294 00902021 */  addu      $a0, $a0, $s0
/* 1395D8 80246298 0C093BA0 */  jal       pause_get_menu_string
/* 1395DC 8024629C 8C84F390 */   lw       $a0, -0xc70($a0)
/* 1395E0 802462A0 0040202D */  daddu     $a0, $v0, $zero
/* 1395E4 802462A4 0240282D */  daddu     $a1, $s2, $zero
/* 1395E8 802462A8 27C60030 */  addiu     $a2, $fp, 0x30
/* 1395EC 802462AC 240700FF */  addiu     $a3, $zero, 0xff
/* 1395F0 802462B0 AFA00010 */  sw        $zero, 0x10($sp)
/* 1395F4 802462B4 0C04993B */  jal       draw_string
/* 1395F8 802462B8 AFB70014 */   sw       $s7, 0x14($sp)
/* 1395FC 802462BC 24040006 */  addiu     $a0, $zero, 6
/* 139600 802462C0 8FA80084 */  lw        $t0, 0x84($sp)
/* 139604 802462C4 27C60045 */  addiu     $a2, $fp, 0x45
/* 139608 802462C8 0C093BA5 */  jal       pause_draw_menu_label
/* 13960C 802462CC 25050082 */   addiu    $a1, $t0, 0x82
/* 139610 802462D0 24040005 */  addiu     $a0, $zero, 5
/* 139614 802462D4 8FA80084 */  lw        $t0, 0x84($sp)
/* 139618 802462D8 27C6003C */  addiu     $a2, $fp, 0x3c
/* 13961C 802462DC 0C093BA5 */  jal       pause_draw_menu_label
/* 139620 802462E0 2505008A */   addiu    $a1, $t0, 0x8a
/* 139624 802462E4 3C178011 */  lui       $s7, 0x8011
/* 139628 802462E8 26F7F290 */  addiu     $s7, $s7, -0xd70
/* 13962C 802462EC 0260902D */  daddu     $s2, $s3, $zero
/* 139630 802462F0 86E30290 */  lh        $v1, 0x290($s7)
/* 139634 802462F4 8ED10028 */  lw        $s1, 0x28($s6)
/* 139638 802462F8 04610002 */  bgez      $v1, .L80246304
/* 13963C 802462FC 0060102D */   daddu    $v0, $v1, $zero
/* 139640 80246300 246200FF */  addiu     $v0, $v1, 0xff
.L80246304:
/* 139644 80246304 00021203 */  sra       $v0, $v0, 8
/* 139648 80246308 0040202D */  daddu     $a0, $v0, $zero
/* 13964C 8024630C 00041200 */  sll       $v0, $a0, 8
/* 139650 80246310 00621023 */  subu      $v0, $v1, $v0
/* 139654 80246314 00021400 */  sll       $v0, $v0, 0x10
/* 139658 80246318 0002B403 */  sra       $s6, $v0, 0x10
/* 13965C 8024631C 06C10002 */  bgez      $s6, .L80246328
/* 139660 80246320 02C0102D */   daddu    $v0, $s6, $zero
/* 139664 80246324 26C2001F */  addiu     $v0, $s6, 0x1f
.L80246328:
/* 139668 80246328 0002B143 */  sra       $s6, $v0, 5
/* 13966C 8024632C 000410C0 */  sll       $v0, $a0, 3
/* 139670 80246330 02C2B021 */  addu      $s6, $s6, $v0
/* 139674 80246334 02B6102A */  slt       $v0, $s5, $s6
/* 139678 80246338 104000E7 */  beqz      $v0, .L802466D8
/* 13967C 8024633C 00000000 */   nop      
.L80246340:
/* 139680 80246340 26730001 */  addiu     $s3, $s3, 1
/* 139684 80246344 00158080 */  sll       $s0, $s5, 2
/* 139688 80246348 3C058025 */  lui       $a1, 0x8025
/* 13968C 8024634C 00B02821 */  addu      $a1, $a1, $s0
/* 139690 80246350 8CA5F434 */  lw        $a1, -0xbcc($a1)
/* 139694 80246354 0C0511FF */  jal       set_menu_icon_script
/* 139698 80246358 0220202D */   daddu    $a0, $s1, $zero
/* 13969C 8024635C 0220202D */  daddu     $a0, $s1, $zero
/* 1396A0 80246360 27C6004B */  addiu     $a2, $fp, 0x4b
/* 1396A4 80246364 02158021 */  addu      $s0, $s0, $s5
/* 1396A8 80246368 00108080 */  sll       $s0, $s0, 2
/* 1396AC 8024636C 2610008C */  addiu     $s0, $s0, 0x8c
/* 1396B0 80246370 8FA80084 */  lw        $t0, 0x84($sp)
/* 1396B4 80246374 3C058025 */  lui       $a1, 0x8025
/* 1396B8 80246378 8CA5F46C */  lw        $a1, -0xb94($a1)
/* 1396BC 8024637C 01108021 */  addu      $s0, $t0, $s0
/* 1396C0 80246380 0C051261 */  jal       set_icon_render_pos
/* 1396C4 80246384 02052821 */   addu     $a1, $s0, $a1
/* 1396C8 80246388 12800005 */  beqz      $s4, .L802463A0
/* 1396CC 8024638C 00000000 */   nop      
/* 1396D0 80246390 0C0511F8 */  jal       draw_icon_2
/* 1396D4 80246394 0220202D */   daddu    $a0, $s1, $zero
/* 1396D8 80246398 080918EA */  j         .L802463A8
/* 1396DC 8024639C 0000A02D */   daddu    $s4, $zero, $zero
.L802463A0:
/* 1396E0 802463A0 0C0511F1 */  jal       draw_icon_1
/* 1396E4 802463A4 0220202D */   daddu    $a0, $s1, $zero
.L802463A8:
/* 1396E8 802463A8 0276102A */  slt       $v0, $s3, $s6
/* 1396EC 802463AC 104000CA */  beqz      $v0, .L802466D8
/* 1396F0 802463B0 26520001 */   addiu    $s2, $s2, 1
/* 1396F4 802463B4 26730001 */  addiu     $s3, $s3, 1
/* 1396F8 802463B8 00158080 */  sll       $s0, $s5, 2
/* 1396FC 802463BC 3C058025 */  lui       $a1, 0x8025
/* 139700 802463C0 00B02821 */  addu      $a1, $a1, $s0
/* 139704 802463C4 8CA5F434 */  lw        $a1, -0xbcc($a1)
/* 139708 802463C8 0C0511FF */  jal       set_menu_icon_script
/* 13970C 802463CC 0220202D */   daddu    $a0, $s1, $zero
/* 139710 802463D0 0220202D */  daddu     $a0, $s1, $zero
/* 139714 802463D4 27C6004B */  addiu     $a2, $fp, 0x4b
/* 139718 802463D8 02158021 */  addu      $s0, $s0, $s5
/* 13971C 802463DC 00108080 */  sll       $s0, $s0, 2
/* 139720 802463E0 2610008C */  addiu     $s0, $s0, 0x8c
/* 139724 802463E4 8FA80084 */  lw        $t0, 0x84($sp)
/* 139728 802463E8 3C058025 */  lui       $a1, 0x8025
/* 13972C 802463EC 8CA5F470 */  lw        $a1, -0xb90($a1)
/* 139730 802463F0 01108021 */  addu      $s0, $t0, $s0
/* 139734 802463F4 0C051261 */  jal       set_icon_render_pos
/* 139738 802463F8 02052821 */   addu     $a1, $s0, $a1
/* 13973C 802463FC 12800005 */  beqz      $s4, .L80246414
/* 139740 80246400 00000000 */   nop      
/* 139744 80246404 0C0511F8 */  jal       draw_icon_2
/* 139748 80246408 0220202D */   daddu    $a0, $s1, $zero
/* 13974C 8024640C 08091907 */  j         .L8024641C
/* 139750 80246410 0000A02D */   daddu    $s4, $zero, $zero
.L80246414:
/* 139754 80246414 0C0511F1 */  jal       draw_icon_1
/* 139758 80246418 0220202D */   daddu    $a0, $s1, $zero
.L8024641C:
/* 13975C 8024641C 0276102A */  slt       $v0, $s3, $s6
/* 139760 80246420 104000AD */  beqz      $v0, .L802466D8
/* 139764 80246424 26520001 */   addiu    $s2, $s2, 1
/* 139768 80246428 26730001 */  addiu     $s3, $s3, 1
/* 13976C 8024642C 00158080 */  sll       $s0, $s5, 2
/* 139770 80246430 3C058025 */  lui       $a1, 0x8025
/* 139774 80246434 00B02821 */  addu      $a1, $a1, $s0
/* 139778 80246438 8CA5F434 */  lw        $a1, -0xbcc($a1)
/* 13977C 8024643C 0C0511FF */  jal       set_menu_icon_script
/* 139780 80246440 0220202D */   daddu    $a0, $s1, $zero
/* 139784 80246444 0220202D */  daddu     $a0, $s1, $zero
/* 139788 80246448 27C6004B */  addiu     $a2, $fp, 0x4b
/* 13978C 8024644C 02158021 */  addu      $s0, $s0, $s5
/* 139790 80246450 00108080 */  sll       $s0, $s0, 2
/* 139794 80246454 2610008C */  addiu     $s0, $s0, 0x8c
/* 139798 80246458 8FA80084 */  lw        $t0, 0x84($sp)
/* 13979C 8024645C 3C058025 */  lui       $a1, 0x8025
/* 1397A0 80246460 8CA5F474 */  lw        $a1, -0xb8c($a1)
/* 1397A4 80246464 01108021 */  addu      $s0, $t0, $s0
/* 1397A8 80246468 0C051261 */  jal       set_icon_render_pos
/* 1397AC 8024646C 02052821 */   addu     $a1, $s0, $a1
/* 1397B0 80246470 12800005 */  beqz      $s4, .L80246488
/* 1397B4 80246474 00000000 */   nop      
/* 1397B8 80246478 0C0511F8 */  jal       draw_icon_2
/* 1397BC 8024647C 0220202D */   daddu    $a0, $s1, $zero
/* 1397C0 80246480 08091924 */  j         .L80246490
/* 1397C4 80246484 0000A02D */   daddu    $s4, $zero, $zero
.L80246488:
/* 1397C8 80246488 0C0511F1 */  jal       draw_icon_1
/* 1397CC 8024648C 0220202D */   daddu    $a0, $s1, $zero
.L80246490:
/* 1397D0 80246490 0276102A */  slt       $v0, $s3, $s6
/* 1397D4 80246494 10400090 */  beqz      $v0, .L802466D8
/* 1397D8 80246498 26520001 */   addiu    $s2, $s2, 1
/* 1397DC 8024649C 26730001 */  addiu     $s3, $s3, 1
/* 1397E0 802464A0 00158080 */  sll       $s0, $s5, 2
/* 1397E4 802464A4 3C058025 */  lui       $a1, 0x8025
/* 1397E8 802464A8 00B02821 */  addu      $a1, $a1, $s0
/* 1397EC 802464AC 8CA5F434 */  lw        $a1, -0xbcc($a1)
/* 1397F0 802464B0 0C0511FF */  jal       set_menu_icon_script
/* 1397F4 802464B4 0220202D */   daddu    $a0, $s1, $zero
/* 1397F8 802464B8 0220202D */  daddu     $a0, $s1, $zero
/* 1397FC 802464BC 27C6004B */  addiu     $a2, $fp, 0x4b
/* 139800 802464C0 02158021 */  addu      $s0, $s0, $s5
/* 139804 802464C4 00108080 */  sll       $s0, $s0, 2
/* 139808 802464C8 2610008C */  addiu     $s0, $s0, 0x8c
/* 13980C 802464CC 8FA80084 */  lw        $t0, 0x84($sp)
/* 139810 802464D0 3C058025 */  lui       $a1, 0x8025
/* 139814 802464D4 8CA5F478 */  lw        $a1, -0xb88($a1)
/* 139818 802464D8 01108021 */  addu      $s0, $t0, $s0
/* 13981C 802464DC 0C051261 */  jal       set_icon_render_pos
/* 139820 802464E0 02052821 */   addu     $a1, $s0, $a1
/* 139824 802464E4 12800005 */  beqz      $s4, .L802464FC
/* 139828 802464E8 00000000 */   nop      
/* 13982C 802464EC 0C0511F8 */  jal       draw_icon_2
/* 139830 802464F0 0220202D */   daddu    $a0, $s1, $zero
/* 139834 802464F4 08091941 */  j         .L80246504
/* 139838 802464F8 0000A02D */   daddu    $s4, $zero, $zero
.L802464FC:
/* 13983C 802464FC 0C0511F1 */  jal       draw_icon_1
/* 139840 80246500 0220202D */   daddu    $a0, $s1, $zero
.L80246504:
/* 139844 80246504 0276102A */  slt       $v0, $s3, $s6
/* 139848 80246508 10400073 */  beqz      $v0, .L802466D8
/* 13984C 8024650C 26520001 */   addiu    $s2, $s2, 1
/* 139850 80246510 26730001 */  addiu     $s3, $s3, 1
/* 139854 80246514 00158080 */  sll       $s0, $s5, 2
/* 139858 80246518 3C058025 */  lui       $a1, 0x8025
/* 13985C 8024651C 00B02821 */  addu      $a1, $a1, $s0
/* 139860 80246520 8CA5F434 */  lw        $a1, -0xbcc($a1)
/* 139864 80246524 0C0511FF */  jal       set_menu_icon_script
/* 139868 80246528 0220202D */   daddu    $a0, $s1, $zero
/* 13986C 8024652C 0220202D */  daddu     $a0, $s1, $zero
/* 139870 80246530 27C6004B */  addiu     $a2, $fp, 0x4b
/* 139874 80246534 02158021 */  addu      $s0, $s0, $s5
/* 139878 80246538 00108080 */  sll       $s0, $s0, 2
/* 13987C 8024653C 2610008C */  addiu     $s0, $s0, 0x8c
/* 139880 80246540 8FA80084 */  lw        $t0, 0x84($sp)
/* 139884 80246544 3C058025 */  lui       $a1, 0x8025
/* 139888 80246548 8CA5F47C */  lw        $a1, -0xb84($a1)
/* 13988C 8024654C 01108021 */  addu      $s0, $t0, $s0
/* 139890 80246550 0C051261 */  jal       set_icon_render_pos
/* 139894 80246554 02052821 */   addu     $a1, $s0, $a1
/* 139898 80246558 12800005 */  beqz      $s4, .L80246570
/* 13989C 8024655C 00000000 */   nop      
/* 1398A0 80246560 0C0511F8 */  jal       draw_icon_2
/* 1398A4 80246564 0220202D */   daddu    $a0, $s1, $zero
/* 1398A8 80246568 0809195E */  j         .L80246578
/* 1398AC 8024656C 0000A02D */   daddu    $s4, $zero, $zero
.L80246570:
/* 1398B0 80246570 0C0511F1 */  jal       draw_icon_1
/* 1398B4 80246574 0220202D */   daddu    $a0, $s1, $zero
.L80246578:
/* 1398B8 80246578 0276102A */  slt       $v0, $s3, $s6
/* 1398BC 8024657C 10400056 */  beqz      $v0, .L802466D8
/* 1398C0 80246580 26520001 */   addiu    $s2, $s2, 1
/* 1398C4 80246584 26730001 */  addiu     $s3, $s3, 1
/* 1398C8 80246588 00158080 */  sll       $s0, $s5, 2
/* 1398CC 8024658C 3C058025 */  lui       $a1, 0x8025
/* 1398D0 80246590 00B02821 */  addu      $a1, $a1, $s0
/* 1398D4 80246594 8CA5F434 */  lw        $a1, -0xbcc($a1)
/* 1398D8 80246598 0C0511FF */  jal       set_menu_icon_script
/* 1398DC 8024659C 0220202D */   daddu    $a0, $s1, $zero
/* 1398E0 802465A0 0220202D */  daddu     $a0, $s1, $zero
/* 1398E4 802465A4 27C6004B */  addiu     $a2, $fp, 0x4b
/* 1398E8 802465A8 02158021 */  addu      $s0, $s0, $s5
/* 1398EC 802465AC 00108080 */  sll       $s0, $s0, 2
/* 1398F0 802465B0 2610008C */  addiu     $s0, $s0, 0x8c
/* 1398F4 802465B4 8FA80084 */  lw        $t0, 0x84($sp)
/* 1398F8 802465B8 3C058025 */  lui       $a1, 0x8025
/* 1398FC 802465BC 8CA5F480 */  lw        $a1, -0xb80($a1)
/* 139900 802465C0 01108021 */  addu      $s0, $t0, $s0
/* 139904 802465C4 0C051261 */  jal       set_icon_render_pos
/* 139908 802465C8 02052821 */   addu     $a1, $s0, $a1
/* 13990C 802465CC 12800005 */  beqz      $s4, .L802465E4
/* 139910 802465D0 00000000 */   nop      
/* 139914 802465D4 0C0511F8 */  jal       draw_icon_2
/* 139918 802465D8 0220202D */   daddu    $a0, $s1, $zero
/* 13991C 802465DC 0809197B */  j         .L802465EC
/* 139920 802465E0 0000A02D */   daddu    $s4, $zero, $zero
.L802465E4:
/* 139924 802465E4 0C0511F1 */  jal       draw_icon_1
/* 139928 802465E8 0220202D */   daddu    $a0, $s1, $zero
.L802465EC:
/* 13992C 802465EC 0276102A */  slt       $v0, $s3, $s6
/* 139930 802465F0 10400039 */  beqz      $v0, .L802466D8
/* 139934 802465F4 26520001 */   addiu    $s2, $s2, 1
/* 139938 802465F8 26730001 */  addiu     $s3, $s3, 1
/* 13993C 802465FC 00158080 */  sll       $s0, $s5, 2
/* 139940 80246600 3C058025 */  lui       $a1, 0x8025
/* 139944 80246604 00B02821 */  addu      $a1, $a1, $s0
/* 139948 80246608 8CA5F434 */  lw        $a1, -0xbcc($a1)
/* 13994C 8024660C 0C0511FF */  jal       set_menu_icon_script
/* 139950 80246610 0220202D */   daddu    $a0, $s1, $zero
/* 139954 80246614 0220202D */  daddu     $a0, $s1, $zero
/* 139958 80246618 27C6004B */  addiu     $a2, $fp, 0x4b
/* 13995C 8024661C 02158021 */  addu      $s0, $s0, $s5
/* 139960 80246620 00108080 */  sll       $s0, $s0, 2
/* 139964 80246624 2610008C */  addiu     $s0, $s0, 0x8c
/* 139968 80246628 8FA80084 */  lw        $t0, 0x84($sp)
/* 13996C 8024662C 3C058025 */  lui       $a1, 0x8025
/* 139970 80246630 8CA5F484 */  lw        $a1, -0xb7c($a1)
/* 139974 80246634 01108021 */  addu      $s0, $t0, $s0
/* 139978 80246638 0C051261 */  jal       set_icon_render_pos
/* 13997C 8024663C 02052821 */   addu     $a1, $s0, $a1
/* 139980 80246640 12800005 */  beqz      $s4, .L80246658
/* 139984 80246644 00000000 */   nop      
/* 139988 80246648 0C0511F8 */  jal       draw_icon_2
/* 13998C 8024664C 0220202D */   daddu    $a0, $s1, $zero
/* 139990 80246650 08091998 */  j         .L80246660
/* 139994 80246654 0000A02D */   daddu    $s4, $zero, $zero
.L80246658:
/* 139998 80246658 0C0511F1 */  jal       draw_icon_1
/* 13999C 8024665C 0220202D */   daddu    $a0, $s1, $zero
.L80246660:
/* 1399A0 80246660 0276102A */  slt       $v0, $s3, $s6
/* 1399A4 80246664 1040001C */  beqz      $v0, .L802466D8
/* 1399A8 80246668 26520001 */   addiu    $s2, $s2, 1
/* 1399AC 8024666C 26730001 */  addiu     $s3, $s3, 1
/* 1399B0 80246670 00158080 */  sll       $s0, $s5, 2
/* 1399B4 80246674 3C058025 */  lui       $a1, 0x8025
/* 1399B8 80246678 00B02821 */  addu      $a1, $a1, $s0
/* 1399BC 8024667C 8CA5F450 */  lw        $a1, -0xbb0($a1)
/* 1399C0 80246680 0C0511FF */  jal       set_menu_icon_script
/* 1399C4 80246684 0220202D */   daddu    $a0, $s1, $zero
/* 1399C8 80246688 0220202D */  daddu     $a0, $s1, $zero
/* 1399CC 8024668C 02158021 */  addu      $s0, $s0, $s5
/* 1399D0 80246690 00108080 */  sll       $s0, $s0, 2
/* 1399D4 80246694 26100098 */  addiu     $s0, $s0, 0x98
/* 1399D8 80246698 8FA80084 */  lw        $t0, 0x84($sp)
/* 1399DC 8024669C 27C6004D */  addiu     $a2, $fp, 0x4d
/* 1399E0 802466A0 0C051261 */  jal       set_icon_render_pos
/* 1399E4 802466A4 01102821 */   addu     $a1, $t0, $s0
/* 1399E8 802466A8 12800005 */  beqz      $s4, .L802466C0
/* 1399EC 802466AC 00000000 */   nop      
/* 1399F0 802466B0 0C0511F8 */  jal       draw_icon_2
/* 1399F4 802466B4 0220202D */   daddu    $a0, $s1, $zero
/* 1399F8 802466B8 080919B2 */  j         .L802466C8
/* 1399FC 802466BC 0000A02D */   daddu    $s4, $zero, $zero
.L802466C0:
/* 139A00 802466C0 0C0511F1 */  jal       draw_icon_1
/* 139A04 802466C4 0220202D */   daddu    $a0, $s1, $zero
.L802466C8:
/* 139A08 802466C8 0000902D */  daddu     $s2, $zero, $zero
/* 139A0C 802466CC 0276102A */  slt       $v0, $s3, $s6
/* 139A10 802466D0 1440FF1B */  bnez      $v0, .L80246340
/* 139A14 802466D4 26B50001 */   addiu    $s5, $s5, 1
.L802466D8:
/* 139A18 802466D8 82E4028E */  lb        $a0, 0x28e($s7)
/* 139A1C 802466DC 3C178025 */  lui       $s7, 0x8025
/* 139A20 802466E0 26F7F46C */  addiu     $s7, $s7, -0xb94
/* 139A24 802466E4 00151080 */  sll       $v0, $s5, 2
/* 139A28 802466E8 00551021 */  addu      $v0, $v0, $s5
/* 139A2C 802466EC 00021080 */  sll       $v0, $v0, 2
/* 139A30 802466F0 24550098 */  addiu     $s5, $v0, 0x98
/* 139A34 802466F4 2450008C */  addiu     $s0, $v0, 0x8c
/* 139A38 802466F8 0004B0C0 */  sll       $s6, $a0, 3
.L802466FC:
/* 139A3C 802466FC 0276102A */  slt       $v0, $s3, $s6
/* 139A40 80246700 104000D2 */  beqz      $v0, .L80246A4C
/* 139A44 80246704 00000000 */   nop      
/* 139A48 80246708 1640001A */  bnez      $s2, .L80246774
/* 139A4C 8024670C 24020001 */   addiu    $v0, $zero, 1
/* 139A50 80246710 26730001 */  addiu     $s3, $s3, 1
/* 139A54 80246714 3C058011 */  lui       $a1, 0x8011
/* 139A58 80246718 24A583B0 */  addiu     $a1, $a1, -0x7c50
/* 139A5C 8024671C 0C0511FF */  jal       set_menu_icon_script
/* 139A60 80246720 0220202D */   daddu    $a0, $s1, $zero
/* 139A64 80246724 0220202D */  daddu     $a0, $s1, $zero
/* 139A68 80246728 27C6004B */  addiu     $a2, $fp, 0x4b
/* 139A6C 8024672C 8FA80084 */  lw        $t0, 0x84($sp)
/* 139A70 80246730 3C028025 */  lui       $v0, 0x8025
/* 139A74 80246734 8C42F46C */  lw        $v0, -0xb94($v0)
/* 139A78 80246738 01102821 */  addu      $a1, $t0, $s0
/* 139A7C 8024673C 0C051261 */  jal       set_icon_render_pos
/* 139A80 80246740 00A22821 */   addu     $a1, $a1, $v0
/* 139A84 80246744 12800005 */  beqz      $s4, .L8024675C
/* 139A88 80246748 00000000 */   nop      
/* 139A8C 8024674C 0C0511F8 */  jal       draw_icon_2
/* 139A90 80246750 0220202D */   daddu    $a0, $s1, $zero
/* 139A94 80246754 080919D9 */  j         .L80246764
/* 139A98 80246758 0000A02D */   daddu    $s4, $zero, $zero
.L8024675C:
/* 139A9C 8024675C 0C0511F1 */  jal       draw_icon_1
/* 139AA0 80246760 0220202D */   daddu    $a0, $s1, $zero
.L80246764:
/* 139AA4 80246764 0276102A */  slt       $v0, $s3, $s6
/* 139AA8 80246768 104000B8 */  beqz      $v0, .L80246A4C
/* 139AAC 8024676C 26520001 */   addiu    $s2, $s2, 1
/* 139AB0 80246770 24020001 */  addiu     $v0, $zero, 1
.L80246774:
/* 139AB4 80246774 56420019 */  bnel      $s2, $v0, .L802467DC
/* 139AB8 80246778 24020002 */   addiu    $v0, $zero, 2
/* 139ABC 8024677C 02629821 */  addu      $s3, $s3, $v0
/* 139AC0 80246780 3C058011 */  lui       $a1, 0x8011
/* 139AC4 80246784 24A583B0 */  addiu     $a1, $a1, -0x7c50
/* 139AC8 80246788 0C0511FF */  jal       set_menu_icon_script
/* 139ACC 8024678C 0220202D */   daddu    $a0, $s1, $zero
/* 139AD0 80246790 0220202D */  daddu     $a0, $s1, $zero
/* 139AD4 80246794 27C6004B */  addiu     $a2, $fp, 0x4b
/* 139AD8 80246798 8FA80084 */  lw        $t0, 0x84($sp)
/* 139ADC 8024679C 8EE20004 */  lw        $v0, 4($s7)
/* 139AE0 802467A0 01102821 */  addu      $a1, $t0, $s0
/* 139AE4 802467A4 0C051261 */  jal       set_icon_render_pos
/* 139AE8 802467A8 00A22821 */   addu     $a1, $a1, $v0
/* 139AEC 802467AC 12800005 */  beqz      $s4, .L802467C4
/* 139AF0 802467B0 00000000 */   nop      
/* 139AF4 802467B4 0C0511F8 */  jal       draw_icon_2
/* 139AF8 802467B8 0220202D */   daddu    $a0, $s1, $zero
/* 139AFC 802467BC 080919F3 */  j         .L802467CC
/* 139B00 802467C0 0000A02D */   daddu    $s4, $zero, $zero
.L802467C4:
/* 139B04 802467C4 0C0511F1 */  jal       draw_icon_1
/* 139B08 802467C8 0220202D */   daddu    $a0, $s1, $zero
.L802467CC:
/* 139B0C 802467CC 0276102A */  slt       $v0, $s3, $s6
/* 139B10 802467D0 1040009E */  beqz      $v0, .L80246A4C
/* 139B14 802467D4 26520001 */   addiu    $s2, $s2, 1
/* 139B18 802467D8 24020002 */  addiu     $v0, $zero, 2
.L802467DC:
/* 139B1C 802467DC 16420019 */  bne       $s2, $v0, .L80246844
/* 139B20 802467E0 24020003 */   addiu    $v0, $zero, 3
/* 139B24 802467E4 26730001 */  addiu     $s3, $s3, 1
/* 139B28 802467E8 3C058011 */  lui       $a1, 0x8011
/* 139B2C 802467EC 24A583B0 */  addiu     $a1, $a1, -0x7c50
/* 139B30 802467F0 0C0511FF */  jal       set_menu_icon_script
/* 139B34 802467F4 0220202D */   daddu    $a0, $s1, $zero
/* 139B38 802467F8 0220202D */  daddu     $a0, $s1, $zero
/* 139B3C 802467FC 27C6004B */  addiu     $a2, $fp, 0x4b
/* 139B40 80246800 8FA80084 */  lw        $t0, 0x84($sp)
/* 139B44 80246804 8EE20008 */  lw        $v0, 8($s7)
/* 139B48 80246808 01102821 */  addu      $a1, $t0, $s0
/* 139B4C 8024680C 0C051261 */  jal       set_icon_render_pos
/* 139B50 80246810 00A22821 */   addu     $a1, $a1, $v0
/* 139B54 80246814 12800005 */  beqz      $s4, .L8024682C
/* 139B58 80246818 00000000 */   nop      
/* 139B5C 8024681C 0C0511F8 */  jal       draw_icon_2
/* 139B60 80246820 0220202D */   daddu    $a0, $s1, $zero
/* 139B64 80246824 08091A0D */  j         .L80246834
/* 139B68 80246828 0000A02D */   daddu    $s4, $zero, $zero
.L8024682C:
/* 139B6C 8024682C 0C0511F1 */  jal       draw_icon_1
/* 139B70 80246830 0220202D */   daddu    $a0, $s1, $zero
.L80246834:
/* 139B74 80246834 0276102A */  slt       $v0, $s3, $s6
/* 139B78 80246838 10400084 */  beqz      $v0, .L80246A4C
/* 139B7C 8024683C 26520001 */   addiu    $s2, $s2, 1
/* 139B80 80246840 24020003 */  addiu     $v0, $zero, 3
.L80246844:
/* 139B84 80246844 16420019 */  bne       $s2, $v0, .L802468AC
/* 139B88 80246848 24020004 */   addiu    $v0, $zero, 4
/* 139B8C 8024684C 26730001 */  addiu     $s3, $s3, 1
/* 139B90 80246850 3C058011 */  lui       $a1, 0x8011
/* 139B94 80246854 24A583B0 */  addiu     $a1, $a1, -0x7c50
/* 139B98 80246858 0C0511FF */  jal       set_menu_icon_script
/* 139B9C 8024685C 0220202D */   daddu    $a0, $s1, $zero
/* 139BA0 80246860 0220202D */  daddu     $a0, $s1, $zero
/* 139BA4 80246864 27C6004B */  addiu     $a2, $fp, 0x4b
/* 139BA8 80246868 8FA80084 */  lw        $t0, 0x84($sp)
/* 139BAC 8024686C 8EE2000C */  lw        $v0, 0xc($s7)
/* 139BB0 80246870 01102821 */  addu      $a1, $t0, $s0
/* 139BB4 80246874 0C051261 */  jal       set_icon_render_pos
/* 139BB8 80246878 00A22821 */   addu     $a1, $a1, $v0
/* 139BBC 8024687C 12800005 */  beqz      $s4, .L80246894
/* 139BC0 80246880 00000000 */   nop      
/* 139BC4 80246884 0C0511F8 */  jal       draw_icon_2
/* 139BC8 80246888 0220202D */   daddu    $a0, $s1, $zero
/* 139BCC 8024688C 08091A27 */  j         .L8024689C
/* 139BD0 80246890 0000A02D */   daddu    $s4, $zero, $zero
.L80246894:
/* 139BD4 80246894 0C0511F1 */  jal       draw_icon_1
/* 139BD8 80246898 0220202D */   daddu    $a0, $s1, $zero
.L8024689C:
/* 139BDC 8024689C 0276102A */  slt       $v0, $s3, $s6
/* 139BE0 802468A0 1040006A */  beqz      $v0, .L80246A4C
/* 139BE4 802468A4 26520001 */   addiu    $s2, $s2, 1
/* 139BE8 802468A8 24020004 */  addiu     $v0, $zero, 4
.L802468AC:
/* 139BEC 802468AC 16420019 */  bne       $s2, $v0, .L80246914
/* 139BF0 802468B0 24020005 */   addiu    $v0, $zero, 5
/* 139BF4 802468B4 26730001 */  addiu     $s3, $s3, 1
/* 139BF8 802468B8 3C058011 */  lui       $a1, 0x8011
/* 139BFC 802468BC 24A583B0 */  addiu     $a1, $a1, -0x7c50
/* 139C00 802468C0 0C0511FF */  jal       set_menu_icon_script
/* 139C04 802468C4 0220202D */   daddu    $a0, $s1, $zero
/* 139C08 802468C8 0220202D */  daddu     $a0, $s1, $zero
/* 139C0C 802468CC 27C6004B */  addiu     $a2, $fp, 0x4b
/* 139C10 802468D0 8FA80084 */  lw        $t0, 0x84($sp)
/* 139C14 802468D4 8EE20010 */  lw        $v0, 0x10($s7)
/* 139C18 802468D8 01102821 */  addu      $a1, $t0, $s0
/* 139C1C 802468DC 0C051261 */  jal       set_icon_render_pos
/* 139C20 802468E0 00A22821 */   addu     $a1, $a1, $v0
/* 139C24 802468E4 12800005 */  beqz      $s4, .L802468FC
/* 139C28 802468E8 00000000 */   nop      
/* 139C2C 802468EC 0C0511F8 */  jal       draw_icon_2
/* 139C30 802468F0 0220202D */   daddu    $a0, $s1, $zero
/* 139C34 802468F4 08091A41 */  j         .L80246904
/* 139C38 802468F8 0000A02D */   daddu    $s4, $zero, $zero
.L802468FC:
/* 139C3C 802468FC 0C0511F1 */  jal       draw_icon_1
/* 139C40 80246900 0220202D */   daddu    $a0, $s1, $zero
.L80246904:
/* 139C44 80246904 0276102A */  slt       $v0, $s3, $s6
/* 139C48 80246908 10400050 */  beqz      $v0, .L80246A4C
/* 139C4C 8024690C 26520001 */   addiu    $s2, $s2, 1
/* 139C50 80246910 24020005 */  addiu     $v0, $zero, 5
.L80246914:
/* 139C54 80246914 16420019 */  bne       $s2, $v0, .L8024697C
/* 139C58 80246918 24020006 */   addiu    $v0, $zero, 6
/* 139C5C 8024691C 26730001 */  addiu     $s3, $s3, 1
/* 139C60 80246920 3C058011 */  lui       $a1, 0x8011
/* 139C64 80246924 24A583B0 */  addiu     $a1, $a1, -0x7c50
/* 139C68 80246928 0C0511FF */  jal       set_menu_icon_script
/* 139C6C 8024692C 0220202D */   daddu    $a0, $s1, $zero
/* 139C70 80246930 0220202D */  daddu     $a0, $s1, $zero
/* 139C74 80246934 27C6004B */  addiu     $a2, $fp, 0x4b
/* 139C78 80246938 8FA80084 */  lw        $t0, 0x84($sp)
/* 139C7C 8024693C 8EE20014 */  lw        $v0, 0x14($s7)
/* 139C80 80246940 01102821 */  addu      $a1, $t0, $s0
/* 139C84 80246944 0C051261 */  jal       set_icon_render_pos
/* 139C88 80246948 00A22821 */   addu     $a1, $a1, $v0
/* 139C8C 8024694C 12800005 */  beqz      $s4, .L80246964
/* 139C90 80246950 00000000 */   nop      
/* 139C94 80246954 0C0511F8 */  jal       draw_icon_2
/* 139C98 80246958 0220202D */   daddu    $a0, $s1, $zero
/* 139C9C 8024695C 08091A5B */  j         .L8024696C
/* 139CA0 80246960 0000A02D */   daddu    $s4, $zero, $zero
.L80246964:
/* 139CA4 80246964 0C0511F1 */  jal       draw_icon_1
/* 139CA8 80246968 0220202D */   daddu    $a0, $s1, $zero
.L8024696C:
/* 139CAC 8024696C 0276102A */  slt       $v0, $s3, $s6
/* 139CB0 80246970 10400036 */  beqz      $v0, .L80246A4C
/* 139CB4 80246974 26520001 */   addiu    $s2, $s2, 1
/* 139CB8 80246978 24020006 */  addiu     $v0, $zero, 6
.L8024697C:
/* 139CBC 8024697C 16420019 */  bne       $s2, $v0, .L802469E4
/* 139CC0 80246980 24020007 */   addiu    $v0, $zero, 7
/* 139CC4 80246984 26730001 */  addiu     $s3, $s3, 1
/* 139CC8 80246988 3C058011 */  lui       $a1, 0x8011
/* 139CCC 8024698C 24A583B0 */  addiu     $a1, $a1, -0x7c50
/* 139CD0 80246990 0C0511FF */  jal       set_menu_icon_script
/* 139CD4 80246994 0220202D */   daddu    $a0, $s1, $zero
/* 139CD8 80246998 0220202D */  daddu     $a0, $s1, $zero
/* 139CDC 8024699C 27C6004B */  addiu     $a2, $fp, 0x4b
/* 139CE0 802469A0 8FA80084 */  lw        $t0, 0x84($sp)
/* 139CE4 802469A4 8EE20018 */  lw        $v0, 0x18($s7)
/* 139CE8 802469A8 01102821 */  addu      $a1, $t0, $s0
/* 139CEC 802469AC 0C051261 */  jal       set_icon_render_pos
/* 139CF0 802469B0 00A22821 */   addu     $a1, $a1, $v0
/* 139CF4 802469B4 12800005 */  beqz      $s4, .L802469CC
/* 139CF8 802469B8 00000000 */   nop      
/* 139CFC 802469BC 0C0511F8 */  jal       draw_icon_2
/* 139D00 802469C0 0220202D */   daddu    $a0, $s1, $zero
/* 139D04 802469C4 08091A75 */  j         .L802469D4
/* 139D08 802469C8 0000A02D */   daddu    $s4, $zero, $zero
.L802469CC:
/* 139D0C 802469CC 0C0511F1 */  jal       draw_icon_1
/* 139D10 802469D0 0220202D */   daddu    $a0, $s1, $zero
.L802469D4:
/* 139D14 802469D4 0276102A */  slt       $v0, $s3, $s6
/* 139D18 802469D8 1040001C */  beqz      $v0, .L80246A4C
/* 139D1C 802469DC 26520001 */   addiu    $s2, $s2, 1
/* 139D20 802469E0 24020007 */  addiu     $v0, $zero, 7
.L802469E4:
/* 139D24 802469E4 56420016 */  bnel      $s2, $v0, .L80246A40
/* 139D28 802469E8 0000902D */   daddu    $s2, $zero, $zero
/* 139D2C 802469EC 26730001 */  addiu     $s3, $s3, 1
/* 139D30 802469F0 3C058011 */  lui       $a1, 0x8011
/* 139D34 802469F4 24A584F0 */  addiu     $a1, $a1, -0x7b10
/* 139D38 802469F8 0C0511FF */  jal       set_menu_icon_script
/* 139D3C 802469FC 0220202D */   daddu    $a0, $s1, $zero
/* 139D40 80246A00 0220202D */  daddu     $a0, $s1, $zero
/* 139D44 80246A04 8FA80084 */  lw        $t0, 0x84($sp)
/* 139D48 80246A08 27C6004D */  addiu     $a2, $fp, 0x4d
/* 139D4C 80246A0C 0C051261 */  jal       set_icon_render_pos
/* 139D50 80246A10 01152821 */   addu     $a1, $t0, $s5
/* 139D54 80246A14 12800005 */  beqz      $s4, .L80246A2C
/* 139D58 80246A18 00000000 */   nop      
/* 139D5C 80246A1C 0C0511F8 */  jal       draw_icon_2
/* 139D60 80246A20 0220202D */   daddu    $a0, $s1, $zero
/* 139D64 80246A24 08091A8D */  j         .L80246A34
/* 139D68 80246A28 0000A02D */   daddu    $s4, $zero, $zero
.L80246A2C:
/* 139D6C 80246A2C 0C0511F1 */  jal       draw_icon_1
/* 139D70 80246A30 0220202D */   daddu    $a0, $s1, $zero
.L80246A34:
/* 139D74 80246A34 0276102A */  slt       $v0, $s3, $s6
/* 139D78 80246A38 10400004 */  beqz      $v0, .L80246A4C
/* 139D7C 80246A3C 0000902D */   daddu    $s2, $zero, $zero
.L80246A40:
/* 139D80 80246A40 26B50014 */  addiu     $s5, $s5, 0x14
/* 139D84 80246A44 080919BF */  j         .L802466FC
/* 139D88 80246A48 26100014 */   addiu    $s0, $s0, 0x14
.L80246A4C:
/* 139D8C 80246A4C 3C038027 */  lui       $v1, 0x8027
/* 139D90 80246A50 806300D4 */  lb        $v1, 0xd4($v1)
/* 139D94 80246A54 24020001 */  addiu     $v0, $zero, 1
/* 139D98 80246A58 1462000F */  bne       $v1, $v0, .L80246A98
/* 139D9C 80246A5C 2404001F */   addiu    $a0, $zero, 0x1f
/* 139DA0 80246A60 8FA80080 */  lw        $t0, 0x80($sp)
/* 139DA4 80246A64 3C058025 */  lui       $a1, 0x8025
/* 139DA8 80246A68 24A5F3B0 */  addiu     $a1, $a1, -0xc50
/* 139DAC 80246A6C 91030003 */  lbu       $v1, 3($t0)
/* 139DB0 80246A70 8FA80084 */  lw        $t0, 0x84($sp)
/* 139DB4 80246A74 00431004 */  sllv      $v0, $v1, $v0
/* 139DB8 80246A78 00431021 */  addu      $v0, $v0, $v1
/* 139DBC 80246A7C 00021080 */  sll       $v0, $v0, 2
/* 139DC0 80246A80 00451021 */  addu      $v0, $v0, $a1
/* 139DC4 80246A84 8C450000 */  lw        $a1, ($v0)
/* 139DC8 80246A88 8C460004 */  lw        $a2, 4($v0)
/* 139DCC 80246A8C 01052821 */  addu      $a1, $t0, $a1
/* 139DD0 80246A90 0C090B41 */  jal       func_80242D04
/* 139DD4 80246A94 03C63021 */   addu     $a2, $fp, $a2
.L80246A98:
/* 139DD8 80246A98 8FBF007C */  lw        $ra, 0x7c($sp)
/* 139DDC 80246A9C 8FBE0078 */  lw        $fp, 0x78($sp)
/* 139DE0 80246AA0 8FB70074 */  lw        $s7, 0x74($sp)
/* 139DE4 80246AA4 8FB60070 */  lw        $s6, 0x70($sp)
/* 139DE8 80246AA8 8FB5006C */  lw        $s5, 0x6c($sp)
/* 139DEC 80246AAC 8FB40068 */  lw        $s4, 0x68($sp)
/* 139DF0 80246AB0 8FB30064 */  lw        $s3, 0x64($sp)
/* 139DF4 80246AB4 8FB20060 */  lw        $s2, 0x60($sp)
/* 139DF8 80246AB8 8FB1005C */  lw        $s1, 0x5c($sp)
/* 139DFC 80246ABC 8FB00058 */  lw        $s0, 0x58($sp)
/* 139E00 80246AC0 03E00008 */  jr        $ra
/* 139E04 80246AC4 27BD0080 */   addiu    $sp, $sp, 0x80
