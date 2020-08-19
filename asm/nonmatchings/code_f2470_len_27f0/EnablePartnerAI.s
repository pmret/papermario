.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel EnablePartnerAI
/* 0F3EDC 802CF52C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F3EE0 802CF530 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F3EE4 802CF534 0C03BCCA */  jal   enable_partner_ai
/* 0F3EE8 802CF538 00000000 */   nop   
/* 0F3EEC 802CF53C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F3EF0 802CF540 24020002 */  addiu $v0, $zero, 2
/* 0F3EF4 802CF544 03E00008 */  jr    $ra
/* 0F3EF8 802CF548 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802CF54C
/* 0F3EFC 802CF54C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F3F00 802CF550 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F3F04 802CF554 0C03BD0F */  jal   func_800EF43C
/* 0F3F08 802CF558 00000000 */   nop   
/* 0F3F0C 802CF55C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F3F10 802CF560 24020002 */  addiu $v0, $zero, 2
/* 0F3F14 802CF564 03E00008 */  jr    $ra
/* 0F3F18 802CF568 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802CF56C
/* 0F3F1C 802CF56C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F3F20 802CF570 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F3F24 802CF574 8C82000C */  lw    $v0, 0xc($a0)
/* 0F3F28 802CF578 0C0B1EAF */  jal   get_variable
/* 0F3F2C 802CF57C 8C450000 */   lw    $a1, ($v0)
/* 0F3F30 802CF580 0040202D */  daddu $a0, $v0, $zero
/* 0F3F34 802CF584 24020002 */  addiu $v0, $zero, 2
/* 0F3F38 802CF588 14820005 */  bne   $a0, $v0, .L802CF5A0
/* 0F3F3C 802CF58C 00000000 */   nop   
/* 0F3F40 802CF590 0C03BCF9 */  jal   func_800EF3E4
/* 0F3F44 802CF594 00000000 */   nop   
/* 0F3F48 802CF598 080B3D6A */  j     .L802CF5A8
/* 0F3F4C 802CF59C 00000000 */   nop   

.L802CF5A0:
/* 0F3F50 802CF5A0 0C03BCF5 */  jal   func_800EF3D4
/* 0F3F54 802CF5A4 00000000 */   nop   
.L802CF5A8:
/* 0F3F58 802CF5A8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F3F5C 802CF5AC 24020002 */  addiu $v0, $zero, 2
/* 0F3F60 802CF5B0 03E00008 */  jr    $ra
/* 0F3F64 802CF5B4 27BD0018 */   addiu $sp, $sp, 0x18

