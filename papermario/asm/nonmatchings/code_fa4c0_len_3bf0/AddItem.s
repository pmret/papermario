.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddItem
/* 0FB448 802D6A98 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FB44C 802D6A9C AFB10014 */  sw    $s1, 0x14($sp)
/* 0FB450 802D6AA0 0080882D */  daddu $s1, $a0, $zero
/* 0FB454 802D6AA4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FB458 802D6AA8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB45C 802D6AAC 8E30000C */  lw    $s0, 0xc($s1)
/* 0FB460 802D6AB0 8E050000 */  lw    $a1, ($s0)
/* 0FB464 802D6AB4 0C0B1EAF */  jal   get_variable
/* 0FB468 802D6AB8 26100004 */   addiu $s0, $s0, 4
/* 0FB46C 802D6ABC 8E100000 */  lw    $s0, ($s0)
/* 0FB470 802D6AC0 0C039D5D */  jal   add_item
/* 0FB474 802D6AC4 0040202D */   daddu $a0, $v0, $zero
/* 0FB478 802D6AC8 0220202D */  daddu $a0, $s1, $zero
/* 0FB47C 802D6ACC 0040302D */  daddu $a2, $v0, $zero
/* 0FB480 802D6AD0 0C0B2026 */  jal   set_variable
/* 0FB484 802D6AD4 0200282D */   daddu $a1, $s0, $zero
/* 0FB488 802D6AD8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FB48C 802D6ADC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FB490 802D6AE0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FB494 802D6AE4 24020002 */  addiu $v0, $zero, 2
/* 0FB498 802D6AE8 03E00008 */  jr    $ra
/* 0FB49C 802D6AEC 27BD0020 */   addiu $sp, $sp, 0x20

glabel func_802D6AF0
/* 0FB4A0 802D6AF0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FB4A4 802D6AF4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FB4A8 802D6AF8 8C82000C */  lw    $v0, 0xc($a0)
/* 0FB4AC 802D6AFC 8C450000 */  lw    $a1, ($v0)
/* 0FB4B0 802D6B00 0C0B2026 */  jal   set_variable
/* 0FB4B4 802D6B04 0000302D */   daddu $a2, $zero, $zero
/* 0FB4B8 802D6B08 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FB4BC 802D6B0C 24020002 */  addiu $v0, $zero, 2
/* 0FB4C0 802D6B10 03E00008 */  jr    $ra
/* 0FB4C4 802D6B14 27BD0018 */   addiu $sp, $sp, 0x18

