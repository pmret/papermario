.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_BGMCmd_E8_TrackOverridePatch
/* 2B26C 8004FE6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2B270 8004FE70 0080102D */  daddu     $v0, $a0, $zero
/* 2B274 8004FE74 AFB00010 */  sw        $s0, 0x10($sp)
/* 2B278 8004FE78 00A0802D */  daddu     $s0, $a1, $zero
/* 2B27C 8004FE7C AFBF0014 */  sw        $ra, 0x14($sp)
/* 2B280 8004FE80 904300D5 */  lbu       $v1, 0xd5($v0)
/* 2B284 8004FE84 26070010 */  addiu     $a3, $s0, 0x10
/* 2B288 8004FE88 A6030044 */  sh        $v1, 0x44($s0)
/* 2B28C 8004FE8C 8C440000 */  lw        $a0, ($v0)
/* 2B290 8004FE90 904500D4 */  lbu       $a1, 0xd4($v0)
/* 2B294 8004FE94 0C014EFA */  jal       func_80053BE8
/* 2B298 8004FE98 3066FFFF */   andi     $a2, $v1, 0xffff
/* 2B29C 8004FE9C AE02000C */  sw        $v0, 0xc($s0)
/* 2B2A0 8004FEA0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 2B2A4 8004FEA4 8FB00010 */  lw        $s0, 0x10($sp)
/* 2B2A8 8004FEA8 03E00008 */  jr        $ra
/* 2B2AC 8004FEAC 27BD0018 */   addiu    $sp, $sp, 0x18
