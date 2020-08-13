.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80112328
/* 0A8A28 80112328 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A8A2C 8011232C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0A8A30 80112330 0C044217 */  jal   func_8011085C
/* 0A8A34 80112334 00000000 */   nop   
/* 0A8A38 80112338 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0A8A3C 8011233C 03E00008 */  jr    $ra
/* 0A8A40 80112340 27BD0018 */   addiu $sp, $sp, 0x18

