.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_01_Quizmo_UnkF
/* CF8D60 802411F0 3C028025 */  lui       $v0, %hi(sam_01_Quizmo_VannaTEffect)
/* CF8D64 802411F4 8C42DF20 */  lw        $v0, %lo(sam_01_Quizmo_VannaTEffect)($v0)
/* CF8D68 802411F8 8C42000C */  lw        $v0, 0xc($v0)
/* CF8D6C 802411FC AC40001C */  sw        $zero, 0x1c($v0)
/* CF8D70 80241200 03E00008 */  jr        $ra
/* CF8D74 80241204 24020002 */   addiu    $v0, $zero, 2
