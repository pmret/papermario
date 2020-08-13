.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_case_AND
/* 0E9E4C 802C549C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E9E50 802C54A0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9E54 802C54A4 0080802D */  daddu $s0, $a0, $zero
/* 0E9E58 802C54A8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E9E5C 802C54AC 82030007 */  lb    $v1, 7($s0)
/* 0E9E60 802C54B0 8E04000C */  lw    $a0, 0xc($s0)
/* 0E9E64 802C54B4 04610003 */  bgez  $v1, .L802C54C4
/* 0E9E68 802C54B8 00031080 */   sll   $v0, $v1, 2
.L802C54BC:
/* 0E9E6C 802C54BC 080B152F */  j     .L802C54BC
/* 0E9E70 802C54C0 00000000 */   nop   

.L802C54C4:
/* 0E9E74 802C54C4 02021021 */  addu  $v0, $s0, $v0
/* 0E9E78 802C54C8 02032821 */  addu  $a1, $s0, $v1
/* 0E9E7C 802C54CC 8C840000 */  lw    $a0, ($a0)
/* 0E9E80 802C54D0 80A30110 */  lb    $v1, 0x110($a1)
/* 0E9E84 802C54D4 8C420118 */  lw    $v0, 0x118($v0)
/* 0E9E88 802C54D8 1C600005 */  bgtz  $v1, .L802C54F0
/* 0E9E8C 802C54DC 00821024 */   and   $v0, $a0, $v0
/* 0E9E90 802C54E0 0C0B2279 */  jal   si_goto_end_case
/* 0E9E94 802C54E4 0200202D */   daddu $a0, $s0, $zero
/* 0E9E98 802C54E8 080B1541 */  j     .L802C5504
/* 0E9E9C 802C54EC AE020008 */   sw    $v0, 8($s0)

.L802C54F0:
/* 0E9EA0 802C54F0 54400004 */  bnel  $v0, $zero, .L802C5504
/* 0E9EA4 802C54F4 A0A00110 */   sb    $zero, 0x110($a1)
/* 0E9EA8 802C54F8 0C0B2298 */  jal   si_goto_next_case
/* 0E9EAC 802C54FC 0200202D */   daddu $a0, $s0, $zero
/* 0E9EB0 802C5500 AE020008 */  sw    $v0, 8($s0)
.L802C5504:
/* 0E9EB4 802C5504 24020002 */  addiu $v0, $zero, 2
/* 0E9EB8 802C5508 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E9EBC 802C550C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9EC0 802C5510 03E00008 */  jr    $ra
/* 0E9EC4 802C5514 27BD0018 */   addiu $sp, $sp, 0x18

