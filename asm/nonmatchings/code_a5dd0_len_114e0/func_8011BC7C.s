.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011BC7C
/* B237C 8011BC7C 2403FFFF */  addiu     $v1, $zero, -1
/* B2380 8011BC80 14A30003 */  bne       $a1, $v1, .L8011BC90
/* B2384 8011BC84 00000000 */   nop      
/* B2388 8011BC88 908200A5 */  lbu       $v0, 0xa5($a0)
/* B238C 8011BC8C 3045000F */  andi      $a1, $v0, 0xf
.L8011BC90:
/* B2390 8011BC90 14C30003 */  bne       $a2, $v1, .L8011BCA0
/* B2394 8011BC94 30A3000F */   andi     $v1, $a1, 0xf
/* B2398 8011BC98 908200A5 */  lbu       $v0, 0xa5($a0)
/* B239C 8011BC9C 00023102 */  srl       $a2, $v0, 4
.L8011BCA0:
/* B23A0 8011BCA0 30C2000F */  andi      $v0, $a2, 0xf
/* B23A4 8011BCA4 00021100 */  sll       $v0, $v0, 4
/* B23A8 8011BCA8 00621821 */  addu      $v1, $v1, $v0
/* B23AC 8011BCAC 03E00008 */  jr        $ra
/* B23B0 8011BCB0 A08300A5 */   sb       $v1, 0xa5($a0)
