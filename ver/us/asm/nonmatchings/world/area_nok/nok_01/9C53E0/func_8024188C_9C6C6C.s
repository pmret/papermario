.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nok_01_Quizmo_UnkH
/* 9C6C6C 8024188C 3C028025 */  lui       $v0, %hi(nok_01_Quizmo_VannaTEffect)
/* 9C6C70 80241890 8C421C68 */  lw        $v0, %lo(nok_01_Quizmo_VannaTEffect)($v0)
/* 9C6C74 80241894 8C43000C */  lw        $v1, 0xc($v0)
/* 9C6C78 80241898 24020002 */  addiu     $v0, $zero, 2
/* 9C6C7C 8024189C 03E00008 */  jr        $ra
/* 9C6C80 802418A0 AC62001C */   sw       $v0, 0x1c($v1)
