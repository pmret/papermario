.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_render_tasks
/* B3F90 8011D890 24040002 */  addiu     $a0, $zero, 2
/* B3F94 8011D894 3C038015 */  lui       $v1, %hi(D_801533A8)
/* B3F98 8011D898 246333A8 */  addiu     $v1, $v1, %lo(D_801533A8)
/* B3F9C 8011D89C 3C02802C */  lui       $v0, %hi(mdl_renderTasks2)
/* B3FA0 8011D8A0 24429E00 */  addiu     $v0, $v0, %lo(mdl_renderTasks2)
.L8011D8A4:
/* B3FA4 8011D8A4 AC620000 */  sw        $v0, ($v1)
/* B3FA8 8011D8A8 2463FFFC */  addiu     $v1, $v1, -4
/* B3FAC 8011D8AC 2484FFFF */  addiu     $a0, $a0, -1
/* B3FB0 8011D8B0 0481FFFC */  bgez      $a0, .L8011D8A4
/* B3FB4 8011D8B4 2442F000 */   addiu    $v0, $v0, -0x1000
/* B3FB8 8011D8B8 3C018015 */  lui       $at, %hi(mdl_renderTaskMode)
/* B3FBC 8011D8BC AC2033AC */  sw        $zero, %lo(mdl_renderTaskMode)($at)
/* B3FC0 8011D8C0 3C018015 */  lui       $at, %hi(mdl_renderTaskCount)
/* B3FC4 8011D8C4 AC2033B0 */  sw        $zero, %lo(mdl_renderTaskCount)($at)
/* B3FC8 8011D8C8 03E00008 */  jr        $ra
/* B3FCC 8011D8CC 00000000 */   nop
