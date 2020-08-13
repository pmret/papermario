.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_get_2_word
/* 0EA674 802C5CC4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA678 802C5CC8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA67C 802C5CCC 0080802D */  daddu $s0, $a0, $zero
/* 0EA680 802C5CD0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EA684 802C5CD4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA688 802C5CD8 8E11000C */  lw    $s1, 0xc($s0)
/* 0EA68C 802C5CDC 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA690 802C5CE0 8E250000 */  lw    $a1, ($s1)
/* 0EA694 802C5CE4 26310004 */  addiu $s1, $s1, 4
/* 0EA698 802C5CE8 8C460000 */  lw    $a2, ($v0)
/* 0EA69C 802C5CEC 24420004 */  addiu $v0, $v0, 4
/* 0EA6A0 802C5CF0 0C0B2026 */  jal   set_variable
/* 0EA6A4 802C5CF4 AE020138 */   sw    $v0, 0x138($s0)
/* 0EA6A8 802C5CF8 0200202D */  daddu $a0, $s0, $zero
/* 0EA6AC 802C5CFC 8C820138 */  lw    $v0, 0x138($a0)
/* 0EA6B0 802C5D00 8E250000 */  lw    $a1, ($s1)
/* 0EA6B4 802C5D04 8C460000 */  lw    $a2, ($v0)
/* 0EA6B8 802C5D08 24420004 */  addiu $v0, $v0, 4
/* 0EA6BC 802C5D0C 0C0B2026 */  jal   set_variable
/* 0EA6C0 802C5D10 AC820138 */   sw    $v0, 0x138($a0)
/* 0EA6C4 802C5D14 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EA6C8 802C5D18 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA6CC 802C5D1C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA6D0 802C5D20 24020002 */  addiu $v0, $zero, 2
/* 0EA6D4 802C5D24 03E00008 */  jr    $ra
/* 0EA6D8 802C5D28 27BD0020 */   addiu $sp, $sp, 0x20

