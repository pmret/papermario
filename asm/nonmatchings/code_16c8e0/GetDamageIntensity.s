.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetDamageIntensity
/* 1AF120 80280840 3C03800E */  lui   $v1, 0x800e
/* 1AF124 80280844 8463C1F0 */  lh    $v1, -0x3e10($v1)
/* 1AF128 80280848 28620004 */  slti  $v0, $v1, 4
/* 1AF12C 8028084C 10400003 */  beqz  $v0, .L8028085C
/* 1AF130 80280850 28620007 */   slti  $v0, $v1, 7
/* 1AF134 80280854 080A021E */  j     .L80280878
/* 1AF138 80280858 AC800084 */   sw    $zero, 0x84($a0)

.L8028085C:
/* 1AF13C 8028085C 14400005 */  bnez  $v0, .L80280874
/* 1AF140 80280860 24020001 */   addiu $v0, $zero, 1
/* 1AF144 80280864 2862000A */  slti  $v0, $v1, 0xa
/* 1AF148 80280868 50400002 */  beql  $v0, $zero, .L80280874
/* 1AF14C 8028086C 24020003 */   addiu $v0, $zero, 3
/* 1AF150 80280870 24020002 */  addiu $v0, $zero, 2
.L80280874:
/* 1AF154 80280874 AC820084 */  sw    $v0, 0x84($a0)
.L80280878:
/* 1AF158 80280878 03E00008 */  jr    $ra
/* 1AF15C 8028087C 24020002 */   addiu $v0, $zero, 2

