.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80053A98
/* 02EE98 80053A98 30A5FFFF */  andi  $a1, $a1, 0xffff
/* 02EE9C 80053A9C 00A60018 */  mult  $a1, $a2
/* 02EEA0 80053AA0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 02EEA4 80053AA4 308400FF */  andi  $a0, $a0, 0xff
/* 02EEA8 80053AA8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 02EEAC 80053AAC 00001012 */  mflo  $v0
/* 02EEB0 80053AB0 00022BC2 */  srl   $a1, $v0, 0xf
/* 02EEB4 80053AB4 0C015B5E */  jal   func_80056D78
/* 02EEB8 80053AB8 30A5FFFF */   andi  $a1, $a1, 0xffff
/* 02EEBC 80053ABC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 02EEC0 80053AC0 03E00008 */  jr    $ra
/* 02EEC4 80053AC4 27BD0018 */   addiu $sp, $sp, 0x18

