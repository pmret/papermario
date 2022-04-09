.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_01_Quizmo_UnkG
/* CF8D78 80241208 3C028025 */  lui       $v0, %hi(sam_01_Quizmo_VannaTEffect)
/* CF8D7C 8024120C 8C42DF20 */  lw        $v0, %lo(sam_01_Quizmo_VannaTEffect)($v0)
/* CF8D80 80241210 8C43000C */  lw        $v1, 0xc($v0)
/* CF8D84 80241214 24020001 */  addiu     $v0, $zero, 1
/* CF8D88 80241218 AC62001C */  sw        $v0, 0x1c($v1)
/* CF8D8C 8024121C 03E00008 */  jr        $ra
/* CF8D90 80241220 24020002 */   addiu    $v0, $zero, 2
