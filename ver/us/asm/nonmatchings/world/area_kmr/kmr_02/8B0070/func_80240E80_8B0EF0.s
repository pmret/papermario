.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kmr_02_Quizmo_UnkF
/* 8B0EF0 80240E80 3C028025 */  lui       $v0, %hi(kmr_02_Quizmo_VannaTEffect)
/* 8B0EF4 80240E84 8C427F50 */  lw        $v0, %lo(kmr_02_Quizmo_VannaTEffect)($v0)
/* 8B0EF8 80240E88 8C42000C */  lw        $v0, 0xc($v0)
/* 8B0EFC 80240E8C AC40001C */  sw        $zero, 0x1c($v0)
/* 8B0F00 80240E90 03E00008 */  jr        $ra
/* 8B0F04 80240E94 24020002 */   addiu    $v0, $zero, 2
