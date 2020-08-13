.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_set_int_buffer_ptr
/* 0EA5D8 802C5C28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EA5DC 802C5C2C AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA5E0 802C5C30 0080802D */  daddu $s0, $a0, $zero
/* 0EA5E4 802C5C34 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EA5E8 802C5C38 8E02000C */  lw    $v0, 0xc($s0)
/* 0EA5EC 802C5C3C 0C0B1EAF */  jal   get_variable
/* 0EA5F0 802C5C40 8C450000 */   lw    $a1, ($v0)
/* 0EA5F4 802C5C44 AE020138 */  sw    $v0, 0x138($s0)
/* 0EA5F8 802C5C48 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EA5FC 802C5C4C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA600 802C5C50 24020002 */  addiu $v0, $zero, 2
/* 0EA604 802C5C54 03E00008 */  jr    $ra
/* 0EA608 802C5C58 27BD0018 */   addiu $sp, $sp, 0x18

