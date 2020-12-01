.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011D8D0
/* B3FD0 8011D8D0 24040002 */  addiu     $a0, $zero, 2
/* B3FD4 8011D8D4 3C038015 */  lui       $v1, %hi(D_801533A8)
/* B3FD8 8011D8D8 246333A8 */  addiu     $v1, $v1, %lo(D_801533A8)
/* B3FDC 8011D8DC 3C02802C */  lui       $v0, %hi(D_802B9E00)
/* B3FE0 8011D8E0 24429E00 */  addiu     $v0, $v0, %lo(D_802B9E00)
.L8011D8E4:
/* B3FE4 8011D8E4 AC620000 */  sw        $v0, ($v1)
/* B3FE8 8011D8E8 2463FFFC */  addiu     $v1, $v1, -4
/* B3FEC 8011D8EC 2484FFFF */  addiu     $a0, $a0, -1
/* B3FF0 8011D8F0 0481FFFC */  bgez      $a0, .L8011D8E4
/* B3FF4 8011D8F4 2442F000 */   addiu    $v0, $v0, -0x1000
/* B3FF8 8011D8F8 3C018015 */  lui       $at, %hi(D_801533AC)
/* B3FFC 8011D8FC AC2033AC */  sw        $zero, %lo(D_801533AC)($at)
/* B4000 8011D900 3C018015 */  lui       $at, %hi(D_801533B0)
/* B4004 8011D904 AC2033B0 */  sw        $zero, %lo(D_801533B0)($at)
/* B4008 8011D908 03E00008 */  jr        $ra
/* B400C 8011D90C 00000000 */   nop      
