.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel StartBattleWith
/* 01FC60 80044860 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01FC64 80044864 AFB00010 */  sw    $s0, 0x10($sp)
/* 01FC68 80044868 0080802D */  daddu $s0, $a0, $zero
/* 01FC6C 8004486C AFBF0014 */  sw    $ra, 0x14($sp)
/* 01FC70 80044870 8E02000C */  lw    $v0, 0xc($s0)
/* 01FC74 80044874 0C0B1EAF */  jal   get_variable
/* 01FC78 80044878 8C450000 */   lw    $a1, ($v0)
/* 01FC7C 8004487C 0200202D */  daddu $a0, $s0, $zero
/* 01FC80 80044880 0C0111AD */  jal   start_battle
/* 01FC84 80044884 0040282D */   daddu $a1, $v0, $zero
/* 01FC88 80044888 8FBF0014 */  lw    $ra, 0x14($sp)
/* 01FC8C 8004488C 8FB00010 */  lw    $s0, 0x10($sp)
/* 01FC90 80044890 24020001 */  addiu $v0, $zero, 1
/* 01FC94 80044894 03E00008 */  jr    $ra
/* 01FC98 80044898 27BD0018 */   addiu $sp, $sp, 0x18

