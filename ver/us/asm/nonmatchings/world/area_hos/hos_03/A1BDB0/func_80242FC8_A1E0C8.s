.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel hos_03_Quizmo_UnkH
/* A1E0C8 80242FC8 3C028025 */  lui       $v0, %hi(hos_03_Quizmo_VannaTEffect)
/* A1E0CC 80242FCC 8C42BDF8 */  lw        $v0, %lo(hos_03_Quizmo_VannaTEffect)($v0)
/* A1E0D0 80242FD0 8C43000C */  lw        $v1, 0xc($v0)
/* A1E0D4 80242FD4 24020002 */  addiu     $v0, $zero, 2
/* A1E0D8 80242FD8 03E00008 */  jr        $ra
/* A1E0DC 80242FDC AC62001C */   sw       $v0, 0x1c($v1)
