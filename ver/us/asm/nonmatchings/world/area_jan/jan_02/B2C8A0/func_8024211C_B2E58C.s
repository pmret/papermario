.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_02_Quizmo_UnkG
/* B2E58C 8024211C 3C028025 */  lui       $v0, %hi(jan_02_Quizmo_VannaTEffect)
/* B2E590 80242120 8C428948 */  lw        $v0, %lo(jan_02_Quizmo_VannaTEffect)($v0)
/* B2E594 80242124 8C43000C */  lw        $v1, 0xc($v0)
/* B2E598 80242128 24020001 */  addiu     $v0, $zero, 1
/* B2E59C 8024212C AC62001C */  sw        $v0, 0x1c($v1)
/* B2E5A0 80242130 03E00008 */  jr        $ra
/* B2E5A4 80242134 24020002 */   addiu    $v0, $zero, 2
