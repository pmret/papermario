.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024A4DC
/* 13D81C 8024A4DC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 13D820 8024A4E0 AFB00010 */  sw    $s0, 0x10($sp)
/* 13D824 8024A4E4 3C038011 */  lui   $v1, 0x8011
/* 13D828 8024A4E8 2463F290 */  addiu $v1, $v1, -0xd70
/* 13D82C 8024A4EC 24020001 */  addiu $v0, $zero, 1
/* 13D830 8024A4F0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 13D834 8024A4F4 3C018027 */  lui   $at, 0x8027
/* 13D838 8024A4F8 AC2005D0 */  sw    $zero, 0x5d0($at)
/* 13D83C 8024A4FC 14820011 */  bne   $a0, $v0, .L8024A544
/* 13D840 8024A500 0000802D */   daddu $s0, $zero, $zero
/* 13D844 8024A504 0200202D */  daddu $a0, $s0, $zero
/* 13D848 8024A508 0060302D */  daddu $a2, $v1, $zero
/* 13D84C 8024A50C 3C058027 */  lui   $a1, 0x8027
/* 13D850 8024A510 24A50400 */  addiu $a1, $a1, 0x400
.L8024A514:
/* 13D854 8024A514 84C201B4 */  lh    $v0, 0x1b4($a2)
/* 13D858 8024A518 94C301B4 */  lhu   $v1, 0x1b4($a2)
/* 13D85C 8024A51C 10400004 */  beqz  $v0, .L8024A530
/* 13D860 8024A520 24840001 */   addiu $a0, $a0, 1
/* 13D864 8024A524 A4A30000 */  sh    $v1, ($a1)
/* 13D868 8024A528 24A50002 */  addiu $a1, $a1, 2
/* 13D86C 8024A52C 26100001 */  addiu $s0, $s0, 1
.L8024A530:
/* 13D870 8024A530 2882000A */  slti  $v0, $a0, 0xa
/* 13D874 8024A534 1440FFF7 */  bnez  $v0, .L8024A514
/* 13D878 8024A538 24C60002 */   addiu $a2, $a2, 2
/* 13D87C 8024A53C 0809295F */  j     func_8024A57C
/* 13D880 8024A540 00000000 */   nop   

.L8024A544:
/* 13D884 8024A544 0000202D */  daddu $a0, $zero, $zero
/* 13D888 8024A548 0060302D */  daddu $a2, $v1, $zero
/* 13D88C 8024A54C 3C058027 */  lui   $a1, 0x8027
/* 13D890 8024A550 24A50400 */  addiu $a1, $a1, 0x400
.L8024A554:
/* 13D894 8024A554 84C20074 */  lh    $v0, 0x74($a2)
/* 13D898 8024A558 94C30074 */  lhu   $v1, 0x74($a2)
/* 13D89C 8024A55C 10400004 */  beqz  $v0, .L8024A570
/* 13D8A0 8024A560 24840001 */   addiu $a0, $a0, 1
/* 13D8A4 8024A564 A4A30000 */  sh    $v1, ($a1)
/* 13D8A8 8024A568 24A50002 */  addiu $a1, $a1, 2
/* 13D8AC 8024A56C 26100001 */  addiu $s0, $s0, 1
.L8024A570:
/* 13D8B0 8024A570 28820020 */  slti  $v0, $a0, 0x20
/* 13D8B4 8024A574 1440FFF7 */  bnez  $v0, .L8024A554
/* 13D8B8 8024A578 24C60002 */   addiu $a2, $a2, 2
