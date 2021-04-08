.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011FF98
/* B6698 8011FF98 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B669C 8011FF9C AFBF0010 */  sw        $ra, 0x10($sp)
/* B66A0 8011FFA0 0C047854 */  jal       func_8011E150
/* B66A4 8011FFA4 8C840010 */   lw       $a0, 0x10($a0)
/* B66A8 8011FFA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* B66AC 8011FFAC 03E00008 */  jr        $ra
/* B66B0 8011FFB0 27BD0018 */   addiu    $sp, $sp, 0x18
