.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_set_float_buffer_ptr
/* 0EA60C 802C5C5C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EA610 802C5C60 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA614 802C5C64 0080802D */  daddu $s0, $a0, $zero
/* 0EA618 802C5C68 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EA61C 802C5C6C 8E02000C */  lw    $v0, 0xc($s0)
/* 0EA620 802C5C70 0C0B1EAF */  jal   get_variable
/* 0EA624 802C5C74 8C450000 */   lw    $a1, ($v0)
/* 0EA628 802C5C78 AE020138 */  sw    $v0, 0x138($s0)
/* 0EA62C 802C5C7C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EA630 802C5C80 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA634 802C5C84 24020002 */  addiu $v0, $zero, 2
/* 0EA638 802C5C88 03E00008 */  jr    $ra
/* 0EA63C 802C5C8C 27BD0018 */   addiu $sp, $sp, 0x18

