.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_02_Quizmo_UnkH
/* B2E5A8 80242138 3C028025 */  lui       $v0, %hi(jan_02_Quizmo_VannaTEffect)
/* B2E5AC 8024213C 8C428948 */  lw        $v0, %lo(jan_02_Quizmo_VannaTEffect)($v0)
/* B2E5B0 80242140 8C43000C */  lw        $v1, 0xc($v0)
/* B2E5B4 80242144 24020002 */  addiu     $v0, $zero, 2
/* B2E5B8 80242148 03E00008 */  jr        $ra
/* B2E5BC 8024214C AC62001C */   sw       $v0, 0x1c($v1)
