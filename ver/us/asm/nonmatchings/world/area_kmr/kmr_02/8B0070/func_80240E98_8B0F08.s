.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kmr_02_Quizmo_UnkG
/* 8B0F08 80240E98 3C028025 */  lui       $v0, %hi(kmr_02_Quizmo_VannaTEffect)
/* 8B0F0C 80240E9C 8C427F50 */  lw        $v0, %lo(kmr_02_Quizmo_VannaTEffect)($v0)
/* 8B0F10 80240EA0 8C43000C */  lw        $v1, 0xc($v0)
/* 8B0F14 80240EA4 24020001 */  addiu     $v0, $zero, 1
/* 8B0F18 80240EA8 AC62001C */  sw        $v0, 0x1c($v1)
/* 8B0F1C 80240EAC 03E00008 */  jr        $ra
/* 8B0F20 80240EB0 24020002 */   addiu    $v0, $zero, 2
