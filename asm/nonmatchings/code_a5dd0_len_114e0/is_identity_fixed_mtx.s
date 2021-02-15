.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel is_identity_fixed_mtx
/* B2514 8011BE14 14800005 */  bnez      $a0, .L8011BE2C
/* B2518 8011BE18 0000282D */   daddu    $a1, $zero, $zero
/* B251C 8011BE1C 03E00008 */  jr        $ra
/* B2520 8011BE20 24020001 */   addiu    $v0, $zero, 1
.L8011BE24:
/* B2524 8011BE24 03E00008 */  jr        $ra
/* B2528 8011BE28 0000102D */   daddu    $v0, $zero, $zero
.L8011BE2C:
/* B252C 8011BE2C 3C068015 */  lui       $a2, %hi(D_8014B768)
/* B2530 8011BE30 24C6B768 */  addiu     $a2, $a2, %lo(D_8014B768)
.L8011BE34:
/* B2534 8011BE34 8C830000 */  lw        $v1, ($a0)
/* B2538 8011BE38 8CC20000 */  lw        $v0, ($a2)
/* B253C 8011BE3C 1462FFF9 */  bne       $v1, $v0, .L8011BE24
/* B2540 8011BE40 24A50001 */   addiu    $a1, $a1, 1
/* B2544 8011BE44 24840004 */  addiu     $a0, $a0, 4
/* B2548 8011BE48 28A20010 */  slti      $v0, $a1, 0x10
/* B254C 8011BE4C 1440FFF9 */  bnez      $v0, .L8011BE34
/* B2550 8011BE50 24C60004 */   addiu    $a2, $a2, 4
/* B2554 8011BE54 03E00008 */  jr        $ra
/* B2558 8011BE58 24020001 */   addiu    $v0, $zero, 1
