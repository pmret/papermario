.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_05_Quizmo_UnkF
/* 853F80 80241E10 3C028025 */  lui       $v0, %hi(mac_05_Quizmo_VannaTEffect)
/* 853F84 80241E14 8C4229F8 */  lw        $v0, %lo(mac_05_Quizmo_VannaTEffect)($v0)
/* 853F88 80241E18 8C42000C */  lw        $v0, 0xc($v0)
/* 853F8C 80241E1C AC40001C */  sw        $zero, 0x1c($v0)
/* 853F90 80241E20 03E00008 */  jr        $ra
/* 853F94 80241E24 24020002 */   addiu    $v0, $zero, 2
