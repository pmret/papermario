.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel create_popup
/* 17D848 8024EF68 0000202D */  daddu $a0, $zero, $zero
/* 17D84C 8024EF6C 24050001 */  addiu $a1, $zero, 1
/* 17D850 8024EF70 3C03802A */  lui   $v1, 0x802a
/* 17D854 8024EF74 2463F2C0 */  addiu $v1, $v1, -0xd40
.L8024EF78:
/* 17D858 8024EF78 84620010 */  lh    $v0, 0x10($v1)
/* 17D85C 8024EF7C 14400004 */  bnez  $v0, .L8024EF90
/* 17D860 8024EF80 24840001 */   addiu $a0, $a0, 1
/* 17D864 8024EF84 A4650010 */  sh    $a1, 0x10($v1)
/* 17D868 8024EF88 03E00008 */  jr    $ra
/* 17D86C 8024EF8C 0060102D */   daddu $v0, $v1, $zero

.L8024EF90:
/* 17D870 8024EF90 28820020 */  slti  $v0, $a0, 0x20
/* 17D874 8024EF94 1440FFF8 */  bnez  $v0, .L8024EF78
/* 17D878 8024EF98 2463001C */   addiu $v1, $v1, 0x1c
/* 17D87C 8024EF9C 03E00008 */  jr    $ra
/* 17D880 8024EFA0 0000102D */   daddu $v0, $zero, $zero

