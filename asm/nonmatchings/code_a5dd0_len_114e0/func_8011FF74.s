.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8011FF74
/* 0B6674 8011FF74 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0B6678 8011FF78 00A42821 */  addu  $a1, $a1, $a0
/* 0B667C 8011FF7C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0B6680 8011FF80 8C840010 */  lw    $a0, 0x10($a0)
/* 0B6684 8011FF84 0C047837 */  jal   func_8011E0DC
/* 0B6688 8011FF88 90A50014 */   lbu   $a1, 0x14($a1)
/* 0B668C 8011FF8C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0B6690 8011FF90 03E00008 */  jr    $ra
/* 0B6694 8011FF94 27BD0018 */   addiu $sp, $sp, 0x18

