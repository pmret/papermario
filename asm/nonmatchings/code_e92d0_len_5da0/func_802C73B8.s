.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802C73B8
/* 0EBD68 802C73B8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EBD6C 802C73BC AFB10014 */  sw    $s1, 0x14($sp)
/* 0EBD70 802C73C0 0080882D */  daddu $s1, $a0, $zero
/* 0EBD74 802C73C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EBD78 802C73C8 0000802D */  daddu $s0, $zero, $zero
/* 0EBD7C 802C73CC AFBF0018 */  sw    $ra, 0x18($sp)
.L802C73D0:
/* 0EBD80 802C73D0 0C0B11E4 */  jal   get_script_by_index
/* 0EBD84 802C73D4 0200202D */   daddu $a0, $s0, $zero
/* 0EBD88 802C73D8 12220004 */  beq   $s1, $v0, .L802C73EC
/* 0EBD8C 802C73DC 26100001 */   addiu $s0, $s0, 1
/* 0EBD90 802C73E0 2A020080 */  slti  $v0, $s0, 0x80
/* 0EBD94 802C73E4 1440FFFA */  bnez  $v0, .L802C73D0
/* 0EBD98 802C73E8 00000000 */   nop   
.L802C73EC:
/* 0EBD9C 802C73EC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EBDA0 802C73F0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EBDA4 802C73F4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EBDA8 802C73F8 24020001 */  addiu $v0, $zero, 1
/* 0EBDAC 802C73FC 03E00008 */  jr    $ra
/* 0EBDB0 802C7400 27BD0020 */   addiu $sp, $sp, 0x20

