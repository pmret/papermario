.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetPlayerCollisionSize
/* 0F5960 802D0FB0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F5964 802D0FB4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F5968 802D0FB8 0080882D */  daddu $s1, $a0, $zero
/* 0F596C 802D0FBC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F5970 802D0FC0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F5974 802D0FC4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F5978 802D0FC8 8E050000 */  lw    $a1, ($s0)
/* 0F597C 802D0FCC 0C0B1EAF */  jal   get_variable
/* 0F5980 802D0FD0 26100004 */   addiu $s0, $s0, 4
/* 0F5984 802D0FD4 0220202D */  daddu $a0, $s1, $zero
/* 0F5988 802D0FD8 8E050000 */  lw    $a1, ($s0)
/* 0F598C 802D0FDC 0C0B1EAF */  jal   get_variable
/* 0F5990 802D0FE0 0040802D */   daddu $s0, $v0, $zero
/* 0F5994 802D0FE4 3C03802E */  lui   $v1, 0x802e
/* 0F5998 802D0FE8 8C639D20 */  lw    $v1, -0x62e0($v1)
/* 0F599C 802D0FEC 3C048011 */  lui   $a0, 0x8011
/* 0F59A0 802D0FF0 2484EFC8 */  addiu $a0, $a0, -0x1038
/* 0F59A4 802D0FF4 A47000A8 */  sh    $s0, 0xa8($v1)
/* 0F59A8 802D0FF8 A46200A6 */  sh    $v0, 0xa6($v1)
/* 0F59AC 802D0FFC 0200102D */  daddu $v0, $s0, $zero
/* 0F59B0 802D1000 A48200B0 */  sh    $v0, 0xb0($a0)
/* 0F59B4 802D1004 946300A6 */  lhu   $v1, 0xa6($v1)
/* 0F59B8 802D1008 A48300B2 */  sh    $v1, 0xb2($a0)
/* 0F59BC 802D100C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F59C0 802D1010 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F59C4 802D1014 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F59C8 802D1018 24020002 */  addiu $v0, $zero, 2
/* 0F59CC 802D101C 03E00008 */  jr    $ra
/* 0F59D0 802D1020 27BD0020 */   addiu $sp, $sp, 0x20

