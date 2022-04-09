.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_02_Quizmo_UnkH
/* D06D80 80241650 3C028025 */  lui       $v0, %hi(sam_02_Quizmo_VannaTEffect)
/* D06D84 80241654 8C42B9B8 */  lw        $v0, %lo(sam_02_Quizmo_VannaTEffect)($v0)
/* D06D88 80241658 8C43000C */  lw        $v1, 0xc($v0)
/* D06D8C 8024165C 24020002 */  addiu     $v0, $zero, 2
/* D06D90 80241660 03E00008 */  jr        $ra
/* D06D94 80241664 AC62001C */   sw       $v0, 0x1c($v1)
