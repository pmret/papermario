.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_if_equal
/* 0E95F0 802C4C40 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E95F4 802C4C44 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E95F8 802C4C48 0080882D */  daddu $s1, $a0, $zero
/* 0E95FC 802C4C4C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E9600 802C4C50 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9604 802C4C54 8E30000C */  lw    $s0, 0xc($s1)
/* 0E9608 802C4C58 8E050000 */  lw    $a1, ($s0)
/* 0E960C 802C4C5C 0C0B1EAF */  jal   get_variable
/* 0E9610 802C4C60 26100004 */   addiu $s0, $s0, 4
/* 0E9614 802C4C64 0220202D */  daddu $a0, $s1, $zero
/* 0E9618 802C4C68 8E050000 */  lw    $a1, ($s0)
/* 0E961C 802C4C6C 0C0B1EAF */  jal   get_variable
/* 0E9620 802C4C70 0040802D */   daddu $s0, $v0, $zero
/* 0E9624 802C4C74 12020005 */  beq   $s0, $v0, .L802C4C8C
/* 0E9628 802C4C78 24020002 */   addiu $v0, $zero, 2
/* 0E962C 802C4C7C 0C0B223F */  jal   si_skip_if
/* 0E9630 802C4C80 0220202D */   daddu $a0, $s1, $zero
/* 0E9634 802C4C84 AE220008 */  sw    $v0, 8($s1)
/* 0E9638 802C4C88 24020002 */  addiu $v0, $zero, 2
.L802C4C8C:
/* 0E963C 802C4C8C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E9640 802C4C90 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E9644 802C4C94 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9648 802C4C98 03E00008 */  jr    $ra
/* 0E964C 802C4C9C 27BD0020 */   addiu $sp, $sp, 0x20

