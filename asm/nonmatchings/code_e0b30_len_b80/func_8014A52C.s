.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8014A52C
/* 0E0C2C 8014A52C 24020008 */  addiu $v0, $zero, 8
/* 0E0C30 8014A530 3C018016 */  lui   $at, 0x8016
/* 0E0C34 8014A534 A4229AE2 */  sh    $v0, -0x651e($at)
/* 0E0C38 8014A538 3C018016 */  lui   $at, 0x8016
/* 0E0C3C 8014A53C A4229AE4 */  sh    $v0, -0x651c($at)
/* 0E0C40 8014A540 03E00008 */  jr    $ra
/* 0E0C44 8014A544 00000000 */   nop   

