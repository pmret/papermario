.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_02_Quizmo_UnkF
/* 825570 802422B0 3C028025 */  lui       $v0, %hi(mac_02_Quizmo_VannaTEffect)
/* 825574 802422B4 8C42E568 */  lw        $v0, %lo(mac_02_Quizmo_VannaTEffect)($v0)
/* 825578 802422B8 8C42000C */  lw        $v0, 0xc($v0)
/* 82557C 802422BC AC40001C */  sw        $zero, 0x1c($v0)
/* 825580 802422C0 03E00008 */  jr        $ra
/* 825584 802422C4 24020002 */   addiu    $v0, $zero, 2
