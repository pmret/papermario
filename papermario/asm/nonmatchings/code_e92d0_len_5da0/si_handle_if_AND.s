.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_if_AND
/* 0E9840 802C4E90 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E9844 802C4E94 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E9848 802C4E98 0080882D */  daddu $s1, $a0, $zero
/* 0E984C 802C4E9C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E9850 802C4EA0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9854 802C4EA4 8E30000C */  lw    $s0, 0xc($s1)
/* 0E9858 802C4EA8 8E050000 */  lw    $a1, ($s0)
/* 0E985C 802C4EAC 0C0B1EAF */  jal   get_variable
/* 0E9860 802C4EB0 26100004 */   addiu $s0, $s0, 4
/* 0E9864 802C4EB4 8E030000 */  lw    $v1, ($s0)
/* 0E9868 802C4EB8 00431024 */  and   $v0, $v0, $v1
/* 0E986C 802C4EBC 14400005 */  bnez  $v0, .L802C4ED4
/* 0E9870 802C4EC0 24020002 */   addiu $v0, $zero, 2
/* 0E9874 802C4EC4 0C0B223F */  jal   si_skip_if
/* 0E9878 802C4EC8 0220202D */   daddu $a0, $s1, $zero
/* 0E987C 802C4ECC AE220008 */  sw    $v0, 8($s1)
/* 0E9880 802C4ED0 24020002 */  addiu $v0, $zero, 2
.L802C4ED4:
/* 0E9884 802C4ED4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E9888 802C4ED8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E988C 802C4EDC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9890 802C4EE0 03E00008 */  jr    $ra
/* 0E9894 802C4EE4 27BD0020 */   addiu $sp, $sp, 0x20

