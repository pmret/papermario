.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_03_Quizmo_UnkF
/* 8327A0 80240FA0 3C028025 */  lui       $v0, %hi(mac_03_Quizmo_VannaTEffect)
/* 8327A4 80240FA4 8C4213F8 */  lw        $v0, %lo(mac_03_Quizmo_VannaTEffect)($v0)
/* 8327A8 80240FA8 8C42000C */  lw        $v0, 0xc($v0)
/* 8327AC 80240FAC AC40001C */  sw        $zero, 0x1c($v0)
/* 8327B0 80240FB0 03E00008 */  jr        $ra
/* 8327B4 80240FB4 24020002 */   addiu    $v0, $zero, 2
