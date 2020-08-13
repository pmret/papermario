.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetStatusTable
/* 1AB3E8 8027CB08 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1AB3EC 8027CB0C AFB20018 */  sw    $s2, 0x18($sp)
/* 1AB3F0 8027CB10 0080902D */  daddu $s2, $a0, $zero
/* 1AB3F4 8027CB14 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1AB3F8 8027CB18 AFB10014 */  sw    $s1, 0x14($sp)
/* 1AB3FC 8027CB1C AFB00010 */  sw    $s0, 0x10($sp)
/* 1AB400 8027CB20 8E51000C */  lw    $s1, 0xc($s2)
/* 1AB404 8027CB24 8E250000 */  lw    $a1, ($s1)
/* 1AB408 8027CB28 0C0B1EAF */  jal   get_variable
/* 1AB40C 8027CB2C 26310004 */   addiu $s1, $s1, 4
/* 1AB410 8027CB30 0040802D */  daddu $s0, $v0, $zero
/* 1AB414 8027CB34 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AB418 8027CB38 16020002 */  bne   $s0, $v0, .L8027CB44
/* 1AB41C 8027CB3C 00000000 */   nop   
/* 1AB420 8027CB40 8E500148 */  lw    $s0, 0x148($s2)
.L8027CB44:
/* 1AB424 8027CB44 8E250000 */  lw    $a1, ($s1)
/* 1AB428 8027CB48 0C0B1EAF */  jal   get_variable
/* 1AB42C 8027CB4C 0240202D */   daddu $a0, $s2, $zero
/* 1AB430 8027CB50 0200202D */  daddu $a0, $s0, $zero
/* 1AB434 8027CB54 0C09A75B */  jal   get_actor
/* 1AB438 8027CB58 0040802D */   daddu $s0, $v0, $zero
/* 1AB43C 8027CB5C AC50020C */  sw    $s0, 0x20c($v0)
/* 1AB440 8027CB60 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1AB444 8027CB64 8FB20018 */  lw    $s2, 0x18($sp)
/* 1AB448 8027CB68 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AB44C 8027CB6C 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AB450 8027CB70 24020002 */  addiu $v0, $zero, 2
/* 1AB454 8027CB74 03E00008 */  jr    $ra
/* 1AB458 8027CB78 27BD0020 */   addiu $sp, $sp, 0x20

