.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9228_425D78
/* 425D78 802A9228 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 425D7C 802A922C AFB10014 */  sw        $s1, 0x14($sp)
/* 425D80 802A9230 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 425D84 802A9234 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 425D88 802A9238 AFBF0018 */  sw        $ra, 0x18($sp)
/* 425D8C 802A923C AFB00010 */  sw        $s0, 0x10($sp)
/* 425D90 802A9240 8623004C */  lh        $v1, 0x4c($s1)
/* 425D94 802A9244 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 425D98 802A9248 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 425D9C 802A924C 2C62000D */  sltiu     $v0, $v1, 0xd
/* 425DA0 802A9250 1040009C */  beqz      $v0, L802A94C4_426014
/* 425DA4 802A9254 00031080 */   sll      $v0, $v1, 2
/* 425DA8 802A9258 3C01802B */  lui       $at, %hi(jtbl_802A95E0_426130)
/* 425DAC 802A925C 00220821 */  addu      $at, $at, $v0
/* 425DB0 802A9260 8C2295E0 */  lw        $v0, %lo(jtbl_802A95E0_426130)($at)
/* 425DB4 802A9264 00400008 */  jr        $v0
/* 425DB8 802A9268 00000000 */   nop
glabel L802A926C_425DBC
/* 425DBC 802A926C 0C093EB1 */  jal       btl_set_popup_duration
/* 425DC0 802A9270 24040063 */   addiu    $a0, $zero, 0x63
/* 425DC4 802A9274 82220061 */  lb        $v0, 0x61($s1)
/* 425DC8 802A9278 8E300004 */  lw        $s0, 4($s1)
/* 425DCC 802A927C 10400004 */  beqz      $v0, .L802A9290
/* 425DD0 802A9280 0200202D */   daddu    $a0, $s0, $zero
/* 425DD4 802A9284 0C05128B */  jal       clear_hud_element_flags
/* 425DD8 802A9288 24050002 */   addiu    $a1, $zero, 2
/* 425DDC 802A928C 0200202D */  daddu     $a0, $s0, $zero
.L802A9290:
/* 425DE0 802A9290 0C0513AC */  jal       set_hud_element_alpha
/* 425DE4 802A9294 240500FF */   addiu    $a1, $zero, 0xff
/* 425DE8 802A9298 8E300008 */  lw        $s0, 8($s1)
/* 425DEC 802A929C 240500FF */  addiu     $a1, $zero, 0xff
/* 425DF0 802A92A0 0C0513AC */  jal       set_hud_element_alpha
/* 425DF4 802A92A4 0200202D */   daddu    $a0, $s0, $zero
/* 425DF8 802A92A8 82220061 */  lb        $v0, 0x61($s1)
/* 425DFC 802A92AC 10400003 */  beqz      $v0, .L802A92BC
/* 425E00 802A92B0 0200202D */   daddu    $a0, $s0, $zero
/* 425E04 802A92B4 0C05128B */  jal       clear_hud_element_flags
/* 425E08 802A92B8 24050002 */   addiu    $a1, $zero, 2
.L802A92BC:
/* 425E0C 802A92BC 8E30000C */  lw        $s0, 0xc($s1)
/* 425E10 802A92C0 240500FF */  addiu     $a1, $zero, 0xff
/* 425E14 802A92C4 0C0513AC */  jal       set_hud_element_alpha
/* 425E18 802A92C8 0200202D */   daddu    $a0, $s0, $zero
/* 425E1C 802A92CC 82220061 */  lb        $v0, 0x61($s1)
/* 425E20 802A92D0 10400003 */  beqz      $v0, .L802A92E0
/* 425E24 802A92D4 0200202D */   daddu    $a0, $s0, $zero
/* 425E28 802A92D8 0C05128B */  jal       clear_hud_element_flags
/* 425E2C 802A92DC 24050002 */   addiu    $a1, $zero, 2
.L802A92E0:
/* 425E30 802A92E0 24020001 */  addiu     $v0, $zero, 1
/* 425E34 802A92E4 080AA531 */  j         L802A94C4_426014
/* 425E38 802A92E8 A622004C */   sh       $v0, 0x4c($s1)
glabel L802A92EC_425E3C
/* 425E3C 802A92EC 0C093EB1 */  jal       btl_set_popup_duration
/* 425E40 802A92F0 24040063 */   addiu    $a0, $zero, 0x63
/* 425E44 802A92F4 96220056 */  lhu       $v0, 0x56($s1)
/* 425E48 802A92F8 24420014 */  addiu     $v0, $v0, 0x14
/* 425E4C 802A92FC A6220056 */  sh        $v0, 0x56($s1)
/* 425E50 802A9300 00021400 */  sll       $v0, $v0, 0x10
/* 425E54 802A9304 00021403 */  sra       $v0, $v0, 0x10
/* 425E58 802A9308 28420033 */  slti      $v0, $v0, 0x33
/* 425E5C 802A930C 14400002 */  bnez      $v0, .L802A9318
/* 425E60 802A9310 24020032 */   addiu    $v0, $zero, 0x32
/* 425E64 802A9314 A6220056 */  sh        $v0, 0x56($s1)
.L802A9318:
/* 425E68 802A9318 8E240004 */  lw        $a0, 4($s1)
/* 425E6C 802A931C 86250056 */  lh        $a1, 0x56($s1)
/* 425E70 802A9320 0C051261 */  jal       set_hud_element_render_pos
/* 425E74 802A9324 86260058 */   lh       $a2, 0x58($s1)
/* 425E78 802A9328 8E240008 */  lw        $a0, 8($s1)
/* 425E7C 802A932C 86260058 */  lh        $a2, 0x58($s1)
/* 425E80 802A9330 86250056 */  lh        $a1, 0x56($s1)
/* 425E84 802A9334 0C051261 */  jal       set_hud_element_render_pos
/* 425E88 802A9338 24C6001C */   addiu    $a2, $a2, 0x1c
/* 425E8C 802A933C 8E24000C */  lw        $a0, 0xc($s1)
/* 425E90 802A9340 86250056 */  lh        $a1, 0x56($s1)
/* 425E94 802A9344 86260058 */  lh        $a2, 0x58($s1)
/* 425E98 802A9348 24A5001F */  addiu     $a1, $a1, 0x1f
/* 425E9C 802A934C 0C051261 */  jal       set_hud_element_render_pos
/* 425EA0 802A9350 24C6000E */   addiu    $a2, $a2, 0xe
/* 425EA4 802A9354 080AA531 */  j         L802A94C4_426014
/* 425EA8 802A9358 00000000 */   nop
glabel L802A935C_425EAC
/* 425EAC 802A935C 0C093EB1 */  jal       btl_set_popup_duration
/* 425EB0 802A9360 24040063 */   addiu    $a0, $zero, 0x63
/* 425EB4 802A9364 8622004E */  lh        $v0, 0x4e($s1)
/* 425EB8 802A9368 9623004E */  lhu       $v1, 0x4e($s1)
/* 425EBC 802A936C 10400003 */  beqz      $v0, .L802A937C
/* 425EC0 802A9370 2462FFFF */   addiu    $v0, $v1, -1
/* 425EC4 802A9374 080AA531 */  j         L802A94C4_426014
/* 425EC8 802A9378 A622004E */   sh       $v0, 0x4e($s1)
.L802A937C:
/* 425ECC 802A937C 8E240004 */  lw        $a0, 4($s1)
/* 425ED0 802A9380 3C058011 */  lui       $a1, %hi(D_80108B80)
/* 425ED4 802A9384 24A58B80 */  addiu     $a1, $a1, %lo(D_80108B80)
/* 425ED8 802A9388 0C0511FF */  jal       set_hud_element_script
/* 425EDC 802A938C 00000000 */   nop
/* 425EE0 802A9390 A2000081 */  sb        $zero, 0x81($s0)
/* 425EE4 802A9394 96230052 */  lhu       $v1, 0x52($s1)
/* 425EE8 802A9398 24020001 */  addiu     $v0, $zero, 1
/* 425EEC 802A939C 3C01802B */  lui       $at, %hi(D_802A9620)
/* 425EF0 802A93A0 AC229620 */  sw        $v0, %lo(D_802A9620)($at)
/* 425EF4 802A93A4 2402000B */  addiu     $v0, $zero, 0xb
/* 425EF8 802A93A8 A220005D */  sb        $zero, 0x5d($s1)
/* 425EFC 802A93AC A622004C */  sh        $v0, 0x4c($s1)
/* 425F00 802A93B0 A6230054 */  sh        $v1, 0x54($s1)
glabel L802A93B4_425F04
/* 425F04 802A93B4 0C093EB1 */  jal       btl_set_popup_duration
/* 425F08 802A93B8 24040063 */   addiu    $a0, $zero, 0x63
/* 425F0C 802A93BC 8E020214 */  lw        $v0, 0x214($s0)
/* 425F10 802A93C0 30428000 */  andi      $v0, $v0, 0x8000
/* 425F14 802A93C4 1040000E */  beqz      $v0, .L802A9400
/* 425F18 802A93C8 00000000 */   nop
/* 425F1C 802A93CC 86220050 */  lh        $v0, 0x50($s1)
/* 425F20 802A93D0 8E030434 */  lw        $v1, 0x434($s0)
/* 425F24 802A93D4 00021080 */  sll       $v0, $v0, 2
/* 425F28 802A93D8 00431021 */  addu      $v0, $v0, $v1
/* 425F2C 802A93DC 8C430000 */  lw        $v1, ($v0)
/* 425F30 802A93E0 00031040 */  sll       $v0, $v1, 1
/* 425F34 802A93E4 00431021 */  addu      $v0, $v0, $v1
/* 425F38 802A93E8 8223005D */  lb        $v1, 0x5d($s1)
/* 425F3C 802A93EC 14600004 */  bnez      $v1, .L802A9400
/* 425F40 802A93F0 00022040 */   sll      $a0, $v0, 1
/* 425F44 802A93F4 96220044 */  lhu       $v0, 0x44($s1)
/* 425F48 802A93F8 00441021 */  addu      $v0, $v0, $a0
/* 425F4C 802A93FC A6220044 */  sh        $v0, 0x44($s1)
.L802A9400:
/* 425F50 802A9400 86220044 */  lh        $v0, 0x44($s1)
/* 425F54 802A9404 28422711 */  slti      $v0, $v0, 0x2711
/* 425F58 802A9408 14400004 */  bnez      $v0, .L802A941C
/* 425F5C 802A940C 24022710 */   addiu    $v0, $zero, 0x2710
/* 425F60 802A9410 A6220044 */  sh        $v0, 0x44($s1)
/* 425F64 802A9414 24020003 */  addiu     $v0, $zero, 3
/* 425F68 802A9418 A222005D */  sb        $v0, 0x5d($s1)
.L802A941C:
/* 425F6C 802A941C 8222005D */  lb        $v0, 0x5d($s1)
/* 425F70 802A9420 9223005D */  lbu       $v1, 0x5d($s1)
/* 425F74 802A9424 10400009 */  beqz      $v0, .L802A944C
/* 425F78 802A9428 2462FFFF */   addiu    $v0, $v1, -1
/* 425F7C 802A942C A222005D */  sb        $v0, 0x5d($s1)
/* 425F80 802A9430 00021600 */  sll       $v0, $v0, 0x18
/* 425F84 802A9434 14400006 */  bnez      $v0, .L802A9450
/* 425F88 802A9438 3C0451EB */   lui      $a0, 0x51eb
/* 425F8C 802A943C 92020081 */  lbu       $v0, 0x81($s0)
/* 425F90 802A9440 A6200044 */  sh        $zero, 0x44($s1)
/* 425F94 802A9444 24420001 */  addiu     $v0, $v0, 1
/* 425F98 802A9448 A2020081 */  sb        $v0, 0x81($s0)
.L802A944C:
/* 425F9C 802A944C 3C0451EB */  lui       $a0, 0x51eb
.L802A9450:
/* 425FA0 802A9450 96230044 */  lhu       $v1, 0x44($s1)
/* 425FA4 802A9454 3484851F */  ori       $a0, $a0, 0x851f
/* 425FA8 802A9458 00031C00 */  sll       $v1, $v1, 0x10
/* 425FAC 802A945C 00031403 */  sra       $v0, $v1, 0x10
/* 425FB0 802A9460 00440018 */  mult      $v0, $a0
/* 425FB4 802A9464 00031FC3 */  sra       $v1, $v1, 0x1f
/* 425FB8 802A9468 00003810 */  mfhi      $a3
/* 425FBC 802A946C 00071143 */  sra       $v0, $a3, 5
/* 425FC0 802A9470 00431023 */  subu      $v0, $v0, $v1
/* 425FC4 802A9474 A2020084 */  sb        $v0, 0x84($s0)
/* 425FC8 802A9478 86220054 */  lh        $v0, 0x54($s1)
/* 425FCC 802A947C 96230054 */  lhu       $v1, 0x54($s1)
/* 425FD0 802A9480 1440000C */  bnez      $v0, .L802A94B4
/* 425FD4 802A9484 2462FFFF */   addiu    $v0, $v1, -1
/* 425FD8 802A9488 0C093EB1 */  jal       btl_set_popup_duration
/* 425FDC 802A948C 0000202D */   daddu    $a0, $zero, $zero
/* 425FE0 802A9490 24020005 */  addiu     $v0, $zero, 5
/* 425FE4 802A9494 A6220054 */  sh        $v0, 0x54($s1)
/* 425FE8 802A9498 2402000C */  addiu     $v0, $zero, 0xc
/* 425FEC 802A949C 080AA531 */  j         L802A94C4_426014
/* 425FF0 802A94A0 A622004C */   sh       $v0, 0x4c($s1)
glabel L802A94A4_425FF4
/* 425FF4 802A94A4 86220054 */  lh        $v0, 0x54($s1)
/* 425FF8 802A94A8 96230054 */  lhu       $v1, 0x54($s1)
/* 425FFC 802A94AC 10400003 */  beqz      $v0, .L802A94BC
/* 426000 802A94B0 2462FFFF */   addiu    $v0, $v1, -1
.L802A94B4:
/* 426004 802A94B4 080AA531 */  j         L802A94C4_426014
/* 426008 802A94B8 A6220054 */   sh       $v0, 0x54($s1)
.L802A94BC:
/* 42600C 802A94BC 0C09A327 */  jal       func_80268C9C
/* 426010 802A94C0 00000000 */   nop
glabel L802A94C4_426014
/* 426014 802A94C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 426018 802A94C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 42601C 802A94CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 426020 802A94D0 03E00008 */  jr        $ra
/* 426024 802A94D4 27BD0020 */   addiu    $sp, $sp, 0x20
