.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011E400
/* B4B00 8011E400 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B4B04 8011E404 AFB00010 */  sw        $s0, 0x10($sp)
/* B4B08 8011E408 0080802D */  daddu     $s0, $a0, $zero
/* B4B0C 8011E40C AFBF0014 */  sw        $ra, 0x14($sp)
/* B4B10 8011E410 8E040010 */  lw        $a0, 0x10($s0)
/* B4B14 8011E414 10800004 */  beqz      $a0, .L8011E428
/* B4B18 8011E418 A2000014 */   sb       $zero, 0x14($s0)
/* B4B1C 8011E41C 0C0478E6 */  jal       func_8011E398
/* B4B20 8011E420 00000000 */   nop      
/* B4B24 8011E424 AE000010 */  sw        $zero, 0x10($s0)
.L8011E428:
/* B4B28 8011E428 8FBF0014 */  lw        $ra, 0x14($sp)
/* B4B2C 8011E42C 8FB00010 */  lw        $s0, 0x10($sp)
/* B4B30 8011E430 03E00008 */  jr        $ra
/* B4B34 8011E434 27BD0018 */   addiu    $sp, $sp, 0x18
