.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_02_Quizmo_UnkH
/* 8255A4 802422E4 3C028025 */  lui       $v0, %hi(mac_02_Quizmo_VannaTEffect)
/* 8255A8 802422E8 8C42E568 */  lw        $v0, %lo(mac_02_Quizmo_VannaTEffect)($v0)
/* 8255AC 802422EC 8C43000C */  lw        $v1, 0xc($v0)
/* 8255B0 802422F0 24020002 */  addiu     $v0, $zero, 2
/* 8255B4 802422F4 03E00008 */  jr        $ra
/* 8255B8 802422F8 AC62001C */   sw       $v0, 0x1c($v1)
