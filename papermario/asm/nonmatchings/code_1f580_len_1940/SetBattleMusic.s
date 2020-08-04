.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetBattleMusic
/* 01FE38 80044A38 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01FE3C 80044A3C AFBF0010 */  sw    $ra, 0x10($sp)
/* 01FE40 80044A40 8C82000C */  lw    $v0, 0xc($a0)
/* 01FE44 80044A44 0C0B1EAF */  jal   get_variable
/* 01FE48 80044A48 8C450000 */   lw    $a1, ($v0)
/* 01FE4C 80044A4C 3C04800B */  lui   $a0, 0x800b
/* 01FE50 80044A50 24840F10 */  addiu $a0, $a0, 0xf10
/* 01FE54 80044A54 24030001 */  addiu $v1, $zero, 1
/* 01FE58 80044A58 A0830011 */  sb    $v1, 0x11($a0)
/* 01FE5C 80044A5C 2403FFFF */  addiu $v1, $zero, -1
/* 01FE60 80044A60 AC820014 */  sw    $v0, 0x14($a0)
/* 01FE64 80044A64 AC830018 */  sw    $v1, 0x18($a0)
/* 01FE68 80044A68 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01FE6C 80044A6C 24020002 */  addiu $v0, $zero, 2
/* 01FE70 80044A70 03E00008 */  jr    $ra
/* 01FE74 80044A74 27BD0018 */   addiu $sp, $sp, 0x18

