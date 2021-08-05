.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802A95D0_421FC0
.word L802A927C_421C6C, L802A92A0_421C90, L802A952C_421F1C, L802A952C_421F1C, L802A952C_421F1C, L802A952C_421F1C, L802A952C_421F1C, L802A952C_421F1C, L802A952C_421F1C, L802A952C_421F1C, L802A9344_421D34, L802A9404_421DF4, L802A950C_421EFC, 0, 0, 0

.section .text

glabel func_802A9234_421C24
/* 421C24 802A9234 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 421C28 802A9238 AFB10014 */  sw        $s1, 0x14($sp)
/* 421C2C 802A923C 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 421C30 802A9240 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 421C34 802A9244 AFBF001C */  sw        $ra, 0x1c($sp)
/* 421C38 802A9248 AFB20018 */  sw        $s2, 0x18($sp)
/* 421C3C 802A924C AFB00010 */  sw        $s0, 0x10($sp)
/* 421C40 802A9250 8623004C */  lh        $v1, 0x4c($s1)
/* 421C44 802A9254 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 421C48 802A9258 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 421C4C 802A925C 2C62000D */  sltiu     $v0, $v1, 0xd
/* 421C50 802A9260 104000B2 */  beqz      $v0, L802A952C_421F1C
/* 421C54 802A9264 00031080 */   sll      $v0, $v1, 2
/* 421C58 802A9268 3C01802B */  lui       $at, %hi(jtbl_802A95D0_421FC0)
/* 421C5C 802A926C 00220821 */  addu      $at, $at, $v0
/* 421C60 802A9270 8C2295D0 */  lw        $v0, %lo(jtbl_802A95D0_421FC0)($at)
/* 421C64 802A9274 00400008 */  jr        $v0
/* 421C68 802A9278 00000000 */   nop
glabel L802A927C_421C6C
/* 421C6C 802A927C 82430083 */  lb        $v1, 0x83($s2)
/* 421C70 802A9280 24020002 */  addiu     $v0, $zero, 2
/* 421C74 802A9284 14620004 */  bne       $v1, $v0, .L802A9298
/* 421C78 802A9288 24020001 */   addiu    $v0, $zero, 1
/* 421C7C 802A928C 0C093EB1 */  jal       btl_set_popup_duration
/* 421C80 802A9290 24040063 */   addiu    $a0, $zero, 0x63
/* 421C84 802A9294 24020001 */  addiu     $v0, $zero, 1
.L802A9298:
/* 421C88 802A9298 080AA54B */  j         L802A952C_421F1C
/* 421C8C 802A929C A622004C */   sh       $v0, 0x4c($s1)
glabel L802A92A0_421C90
/* 421C90 802A92A0 82430083 */  lb        $v1, 0x83($s2)
/* 421C94 802A92A4 24020002 */  addiu     $v0, $zero, 2
/* 421C98 802A92A8 14620003 */  bne       $v1, $v0, .L802A92B8
/* 421C9C 802A92AC 00000000 */   nop
/* 421CA0 802A92B0 0C093EB1 */  jal       btl_set_popup_duration
/* 421CA4 802A92B4 24040063 */   addiu    $a0, $zero, 0x63
.L802A92B8:
/* 421CA8 802A92B8 96220056 */  lhu       $v0, 0x56($s1)
/* 421CAC 802A92BC 24420014 */  addiu     $v0, $v0, 0x14
/* 421CB0 802A92C0 A6220056 */  sh        $v0, 0x56($s1)
/* 421CB4 802A92C4 00021400 */  sll       $v0, $v0, 0x10
/* 421CB8 802A92C8 00021403 */  sra       $v0, $v0, 0x10
/* 421CBC 802A92CC 28420033 */  slti      $v0, $v0, 0x33
/* 421CC0 802A92D0 14400002 */  bnez      $v0, .L802A92DC
/* 421CC4 802A92D4 24020032 */   addiu    $v0, $zero, 0x32
/* 421CC8 802A92D8 A6220056 */  sh        $v0, 0x56($s1)
.L802A92DC:
/* 421CCC 802A92DC 8E300004 */  lw        $s0, 4($s1)
/* 421CD0 802A92E0 86250056 */  lh        $a1, 0x56($s1)
/* 421CD4 802A92E4 86260058 */  lh        $a2, 0x58($s1)
/* 421CD8 802A92E8 0C051261 */  jal       set_hud_element_render_pos
/* 421CDC 802A92EC 0200202D */   daddu    $a0, $s0, $zero
/* 421CE0 802A92F0 82220061 */  lb        $v0, 0x61($s1)
/* 421CE4 802A92F4 10400003 */  beqz      $v0, .L802A9304
/* 421CE8 802A92F8 0200202D */   daddu    $a0, $s0, $zero
/* 421CEC 802A92FC 0C05128B */  jal       clear_hud_element_flags
/* 421CF0 802A9300 24050002 */   addiu    $a1, $zero, 2
.L802A9304:
/* 421CF4 802A9304 8222005E */  lb        $v0, 0x5e($s1)
/* 421CF8 802A9308 10400088 */  beqz      $v0, L802A952C_421F1C
/* 421CFC 802A930C 00000000 */   nop
/* 421D00 802A9310 8E300008 */  lw        $s0, 8($s1)
/* 421D04 802A9314 86260058 */  lh        $a2, 0x58($s1)
/* 421D08 802A9318 86250056 */  lh        $a1, 0x56($s1)
/* 421D0C 802A931C 0200202D */  daddu     $a0, $s0, $zero
/* 421D10 802A9320 0C051261 */  jal       set_hud_element_render_pos
/* 421D14 802A9324 24A50032 */   addiu    $a1, $a1, 0x32
/* 421D18 802A9328 82220061 */  lb        $v0, 0x61($s1)
/* 421D1C 802A932C 1040007F */  beqz      $v0, L802A952C_421F1C
/* 421D20 802A9330 0200202D */   daddu    $a0, $s0, $zero
/* 421D24 802A9334 0C05128B */  jal       clear_hud_element_flags
/* 421D28 802A9338 24050002 */   addiu    $a1, $zero, 2
/* 421D2C 802A933C 080AA54B */  j         L802A952C_421F1C
/* 421D30 802A9340 00000000 */   nop
glabel L802A9344_421D34
/* 421D34 802A9344 82430083 */  lb        $v1, 0x83($s2)
/* 421D38 802A9348 24020002 */  addiu     $v0, $zero, 2
/* 421D3C 802A934C 14620003 */  bne       $v1, $v0, .L802A935C
/* 421D40 802A9350 00000000 */   nop
/* 421D44 802A9354 0C093EB1 */  jal       btl_set_popup_duration
/* 421D48 802A9358 24040063 */   addiu    $a0, $zero, 0x63
.L802A935C:
/* 421D4C 802A935C 86220050 */  lh        $v0, 0x50($s1)
/* 421D50 802A9360 8E430434 */  lw        $v1, 0x434($s2)
/* 421D54 802A9364 00021080 */  sll       $v0, $v0, 2
/* 421D58 802A9368 00431021 */  addu      $v0, $v0, $v1
/* 421D5C 802A936C 8C500000 */  lw        $s0, ($v0)
/* 421D60 802A9370 8622004E */  lh        $v0, 0x4e($s1)
/* 421D64 802A9374 00501023 */  subu      $v0, $v0, $s0
/* 421D68 802A9378 2442FFFE */  addiu     $v0, $v0, -2
/* 421D6C 802A937C 1C400006 */  bgtz      $v0, .L802A9398
/* 421D70 802A9380 00000000 */   nop
/* 421D74 802A9384 8E240004 */  lw        $a0, 4($s1)
/* 421D78 802A9388 3C058011 */  lui       $a1, %hi(D_80108B54)
/* 421D7C 802A938C 24A58B54 */  addiu     $a1, $a1, %lo(D_80108B54)
/* 421D80 802A9390 0C0511FF */  jal       set_hud_element_script
/* 421D84 802A9394 00000000 */   nop
.L802A9398:
/* 421D88 802A9398 8E420214 */  lw        $v0, 0x214($s2)
/* 421D8C 802A939C 30428000 */  andi      $v0, $v0, 0x8000
/* 421D90 802A93A0 10400007 */  beqz      $v0, .L802A93C0
/* 421D94 802A93A4 00000000 */   nop
/* 421D98 802A93A8 8222005E */  lb        $v0, 0x5e($s1)
/* 421D9C 802A93AC 14400004 */  bnez      $v0, .L802A93C0
/* 421DA0 802A93B0 24020001 */   addiu    $v0, $zero, 1
/* 421DA4 802A93B4 A2220060 */  sb        $v0, 0x60($s1)
/* 421DA8 802A93B8 2402FFFF */  addiu     $v0, $zero, -1
/* 421DAC 802A93BC A2420086 */  sb        $v0, 0x86($s2)
.L802A93C0:
/* 421DB0 802A93C0 8622004E */  lh        $v0, 0x4e($s1)
/* 421DB4 802A93C4 9623004E */  lhu       $v1, 0x4e($s1)
/* 421DB8 802A93C8 00501023 */  subu      $v0, $v0, $s0
/* 421DBC 802A93CC 18400003 */  blez      $v0, .L802A93DC
/* 421DC0 802A93D0 2462FFFF */   addiu    $v0, $v1, -1
/* 421DC4 802A93D4 080AA54B */  j         L802A952C_421F1C
/* 421DC8 802A93D8 A622004E */   sh       $v0, 0x4e($s1)
.L802A93DC:
/* 421DCC 802A93DC 86220050 */  lh        $v0, 0x50($s1)
/* 421DD0 802A93E0 8E430434 */  lw        $v1, 0x434($s2)
/* 421DD4 802A93E4 00021080 */  sll       $v0, $v0, 2
/* 421DD8 802A93E8 00431021 */  addu      $v0, $v0, $v1
/* 421DDC 802A93EC 94430002 */  lhu       $v1, 2($v0)
/* 421DE0 802A93F0 2402FFFF */  addiu     $v0, $zero, -1
/* 421DE4 802A93F4 A2420081 */  sb        $v0, 0x81($s2)
/* 421DE8 802A93F8 2402000B */  addiu     $v0, $zero, 0xb
/* 421DEC 802A93FC A622004C */  sh        $v0, 0x4c($s1)
/* 421DF0 802A9400 A6230054 */  sh        $v1, 0x54($s1)
glabel L802A9404_421DF4
/* 421DF4 802A9404 82430083 */  lb        $v1, 0x83($s2)
/* 421DF8 802A9408 24020002 */  addiu     $v0, $zero, 2
/* 421DFC 802A940C 14620003 */  bne       $v1, $v0, .L802A941C
/* 421E00 802A9410 00000000 */   nop
/* 421E04 802A9414 0C093EB1 */  jal       btl_set_popup_duration
/* 421E08 802A9418 24040063 */   addiu    $a0, $zero, 0x63
.L802A941C:
/* 421E0C 802A941C 82420083 */  lb        $v0, 0x83($s2)
/* 421E10 802A9420 28420002 */  slti      $v0, $v0, 2
/* 421E14 802A9424 14400006 */  bnez      $v0, .L802A9440
/* 421E18 802A9428 00000000 */   nop
/* 421E1C 802A942C 86220054 */  lh        $v0, 0x54($s1)
/* 421E20 802A9430 1040003E */  beqz      $v0, L802A952C_421F1C
/* 421E24 802A9434 00000000 */   nop
/* 421E28 802A9438 080AA519 */  j         .L802A9464
/* 421E2C 802A943C 00000000 */   nop
.L802A9440:
/* 421E30 802A9440 82420081 */  lb        $v0, 0x81($s2)
/* 421E34 802A9444 0440000A */  bltz      $v0, .L802A9470
/* 421E38 802A9448 00000000 */   nop
/* 421E3C 802A944C 82220061 */  lb        $v0, 0x61($s1)
/* 421E40 802A9450 8E300004 */  lw        $s0, 4($s1)
/* 421E44 802A9454 10400003 */  beqz      $v0, .L802A9464
/* 421E48 802A9458 0200202D */   daddu    $a0, $s0, $zero
/* 421E4C 802A945C 0C051280 */  jal       set_hud_element_flags
/* 421E50 802A9460 24050002 */   addiu    $a1, $zero, 2
.L802A9464:
/* 421E54 802A9464 82420081 */  lb        $v0, 0x81($s2)
/* 421E58 802A9468 04410013 */  bgez      $v0, .L802A94B8
/* 421E5C 802A946C 00000000 */   nop
.L802A9470:
/* 421E60 802A9470 8E420214 */  lw        $v0, 0x214($s2)
/* 421E64 802A9474 30428000 */  andi      $v0, $v0, 0x8000
/* 421E68 802A9478 10400004 */  beqz      $v0, .L802A948C
/* 421E6C 802A947C 00000000 */   nop
/* 421E70 802A9480 82220060 */  lb        $v0, 0x60($s1)
/* 421E74 802A9484 10400004 */  beqz      $v0, .L802A9498
/* 421E78 802A9488 00000000 */   nop
.L802A948C:
/* 421E7C 802A948C 8222005E */  lb        $v0, 0x5e($s1)
/* 421E80 802A9490 10400009 */  beqz      $v0, .L802A94B8
/* 421E84 802A9494 00000000 */   nop
.L802A9498:
/* 421E88 802A9498 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 421E8C 802A949C 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 421E90 802A94A0 8C430000 */  lw        $v1, ($v0)
/* 421E94 802A94A4 24040001 */  addiu     $a0, $zero, 1
/* 421E98 802A94A8 A2440081 */  sb        $a0, 0x81($s2)
/* 421E9C 802A94AC A2440086 */  sb        $a0, 0x86($s2)
/* 421EA0 802A94B0 34632000 */  ori       $v1, $v1, 0x2000
/* 421EA4 802A94B4 AC430000 */  sw        $v1, ($v0)
.L802A94B8:
/* 421EA8 802A94B8 86220054 */  lh        $v0, 0x54($s1)
/* 421EAC 802A94BC 96230054 */  lhu       $v1, 0x54($s1)
/* 421EB0 802A94C0 14400016 */  bnez      $v0, .L802A951C
/* 421EB4 802A94C4 2462FFFF */   addiu    $v0, $v1, -1
/* 421EB8 802A94C8 82430081 */  lb        $v1, 0x81($s2)
/* 421EBC 802A94CC 24020001 */  addiu     $v0, $zero, 1
/* 421EC0 802A94D0 14620003 */  bne       $v1, $v0, .L802A94E0
/* 421EC4 802A94D4 00000000 */   nop
/* 421EC8 802A94D8 0C09A458 */  jal       func_80269160
/* 421ECC 802A94DC 00000000 */   nop
.L802A94E0:
/* 421ED0 802A94E0 82430083 */  lb        $v1, 0x83($s2)
/* 421ED4 802A94E4 24020002 */  addiu     $v0, $zero, 2
/* 421ED8 802A94E8 14620004 */  bne       $v1, $v0, .L802A94FC
/* 421EDC 802A94EC 24020005 */   addiu    $v0, $zero, 5
/* 421EE0 802A94F0 0C093EB1 */  jal       btl_set_popup_duration
/* 421EE4 802A94F4 0000202D */   daddu    $a0, $zero, $zero
/* 421EE8 802A94F8 24020005 */  addiu     $v0, $zero, 5
.L802A94FC:
/* 421EEC 802A94FC A6220054 */  sh        $v0, 0x54($s1)
/* 421EF0 802A9500 2402000C */  addiu     $v0, $zero, 0xc
/* 421EF4 802A9504 080AA54B */  j         L802A952C_421F1C
/* 421EF8 802A9508 A622004C */   sh       $v0, 0x4c($s1)
glabel L802A950C_421EFC
/* 421EFC 802A950C 86220054 */  lh        $v0, 0x54($s1)
/* 421F00 802A9510 96230054 */  lhu       $v1, 0x54($s1)
/* 421F04 802A9514 10400003 */  beqz      $v0, .L802A9524
/* 421F08 802A9518 2462FFFF */   addiu    $v0, $v1, -1
.L802A951C:
/* 421F0C 802A951C 080AA54B */  j         L802A952C_421F1C
/* 421F10 802A9520 A6220054 */   sh       $v0, 0x54($s1)
.L802A9524:
/* 421F14 802A9524 0C09A327 */  jal       func_80268C9C
/* 421F18 802A9528 00000000 */   nop
glabel L802A952C_421F1C
/* 421F1C 802A952C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 421F20 802A9530 8FB20018 */  lw        $s2, 0x18($sp)
/* 421F24 802A9534 8FB10014 */  lw        $s1, 0x14($sp)
/* 421F28 802A9538 8FB00010 */  lw        $s0, 0x10($sp)
/* 421F2C 802A953C 03E00008 */  jr        $ra
/* 421F30 802A9540 27BD0020 */   addiu    $sp, $sp, 0x20
