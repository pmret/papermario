.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011C130
/* B2830 8011C130 00052900 */  sll       $a1, $a1, 4
/* B2834 8011C134 10A00009 */  beqz      $a1, .L8011C15C
/* B2838 8011C138 0000382D */   daddu    $a3, $zero, $zero
/* B283C 8011C13C 00C71821 */  addu      $v1, $a2, $a3
.L8011C140:
/* B2840 8011C140 00871021 */  addu      $v0, $a0, $a3
/* B2844 8011C144 90420000 */  lbu       $v0, ($v0)
/* B2848 8011C148 24E70001 */  addiu     $a3, $a3, 1
/* B284C 8011C14C A0620000 */  sb        $v0, ($v1)
/* B2850 8011C150 00E5102B */  sltu      $v0, $a3, $a1
/* B2854 8011C154 1440FFFA */  bnez      $v0, .L8011C140
/* B2858 8011C158 00C71821 */   addu     $v1, $a2, $a3
.L8011C15C:
/* B285C 8011C15C 03E00008 */  jr        $ra
/* B2860 8011C160 00000000 */   nop
