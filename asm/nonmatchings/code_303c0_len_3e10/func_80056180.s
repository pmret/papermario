.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80056180
/* 031580 80056180 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 031584 80056184 AFBF0010 */  sw    $ra, 0x10($sp)
/* 031588 80056188 0C015B57 */  jal   func_80056D5C
/* 03158C 8005618C 0000202D */   daddu $a0, $zero, $zero
/* 031590 80056190 0C01536A */  jal   func_80054DA8
/* 031594 80056194 24040001 */   addiu $a0, $zero, 1
/* 031598 80056198 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03159C 8005619C 03E00008 */  jr    $ra
/* 0315A0 800561A0 27BD0018 */   addiu $sp, $sp, 0x18

