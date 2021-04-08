.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011C2B0
/* B29B0 8011C2B0 3C028015 */  lui       $v0, %hi(D_80152210)
/* B29B4 8011C2B4 8C422210 */  lw        $v0, %lo(D_80152210)($v0)
/* B29B8 8011C2B8 00042080 */  sll       $a0, $a0, 2
/* B29BC 8011C2BC 00822021 */  addu      $a0, $a0, $v0
/* B29C0 8011C2C0 8C830000 */  lw        $v1, ($a0)
/* B29C4 8011C2C4 8C620018 */  lw        $v0, 0x18($v1)
/* B29C8 8011C2C8 8C640004 */  lw        $a0, 4($v1)
/* B29CC 8011C2CC 00021080 */  sll       $v0, $v0, 2
/* B29D0 8011C2D0 00621021 */  addu      $v0, $v1, $v0
/* B29D4 8011C2D4 ACA40000 */  sw        $a0, ($a1)
/* B29D8 8011C2D8 8C420010 */  lw        $v0, 0x10($v0)
/* B29DC 8011C2DC ACC20000 */  sw        $v0, ($a2)
/* B29E0 8011C2E0 8C620000 */  lw        $v0, ($v1)
/* B29E4 8011C2E4 03E00008 */  jr        $ra
/* B29E8 8011C2E8 ACE20000 */   sw       $v0, ($a3)
