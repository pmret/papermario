.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DA4_8ECBC4
/* 8ECBC4 80240DA4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ECBC8 80240DA8 0000202D */  daddu     $a0, $zero, $zero
/* 8ECBCC 80240DAC 240503E8 */  addiu     $a1, $zero, 0x3e8
/* 8ECBD0 80240DB0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8ECBD4 80240DB4 0C01559B */  jal       func_8005566C
/* 8ECBD8 80240DB8 24060001 */   addiu    $a2, $zero, 1
/* 8ECBDC 80240DBC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ECBE0 80240DC0 24020002 */  addiu     $v0, $zero, 2
/* 8ECBE4 80240DC4 03E00008 */  jr        $ra
/* 8ECBE8 80240DC8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8ECBEC 80240DCC 00000000 */  nop
