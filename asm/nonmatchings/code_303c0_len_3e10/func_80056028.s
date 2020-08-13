.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80056028
/* 031428 80056028 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03142C 8005602C AFBF0010 */  sw    $ra, 0x10($sp)
/* 031430 80056030 0C0141B2 */  jal   func_800506C8
/* 031434 80056034 30A500FF */   andi  $a1, $a1, 0xff
/* 031438 80056038 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03143C 8005603C 03E00008 */  jr    $ra
/* 031440 80056040 27BD0018 */   addiu $sp, $sp, 0x18

