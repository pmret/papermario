.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_01_Quizmo_UnkH
/* CF8D94 80241224 3C028025 */  lui       $v0, %hi(sam_01_Quizmo_VannaTEffect)
/* CF8D98 80241228 8C42DF20 */  lw        $v0, %lo(sam_01_Quizmo_VannaTEffect)($v0)
/* CF8D9C 8024122C 8C43000C */  lw        $v1, 0xc($v0)
/* CF8DA0 80241230 24020002 */  addiu     $v0, $zero, 2
/* CF8DA4 80241234 03E00008 */  jr        $ra
/* CF8DA8 80241238 AC62001C */   sw       $v0, 0x1c($v1)
