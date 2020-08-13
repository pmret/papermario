.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetEnemyMaxHP
/* 1AB028 8027C748 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1AB02C 8027C74C AFB10014 */  sw    $s1, 0x14($sp)
/* 1AB030 8027C750 0080882D */  daddu $s1, $a0, $zero
/* 1AB034 8027C754 AFBF0018 */  sw    $ra, 0x18($sp)
/* 1AB038 8027C758 AFB00010 */  sw    $s0, 0x10($sp)
/* 1AB03C 8027C75C 8E30000C */  lw    $s0, 0xc($s1)
/* 1AB040 8027C760 8E050000 */  lw    $a1, ($s0)
/* 1AB044 8027C764 0C0B1EAF */  jal   get_variable
/* 1AB048 8027C768 26100004 */   addiu $s0, $s0, 4
/* 1AB04C 8027C76C 0040202D */  daddu $a0, $v0, $zero
/* 1AB050 8027C770 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AB054 8027C774 14820002 */  bne   $a0, $v0, .L8027C780
/* 1AB058 8027C778 00000000 */   nop   
/* 1AB05C 8027C77C 8E240148 */  lw    $a0, 0x148($s1)
.L8027C780:
/* 1AB060 8027C780 0C09A75B */  jal   get_actor
/* 1AB064 8027C784 8E100000 */   lw    $s0, ($s0)
/* 1AB068 8027C788 0220202D */  daddu $a0, $s1, $zero
/* 1AB06C 8027C78C 804601B9 */  lb    $a2, 0x1b9($v0)
/* 1AB070 8027C790 0C0B2026 */  jal   set_variable
/* 1AB074 8027C794 0200282D */   daddu $a1, $s0, $zero
/* 1AB078 8027C798 8FBF0018 */  lw    $ra, 0x18($sp)
/* 1AB07C 8027C79C 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AB080 8027C7A0 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AB084 8027C7A4 24020002 */  addiu $v0, $zero, 2
/* 1AB088 8027C7A8 03E00008 */  jr    $ra
/* 1AB08C 8027C7AC 27BD0020 */   addiu $sp, $sp, 0x20

