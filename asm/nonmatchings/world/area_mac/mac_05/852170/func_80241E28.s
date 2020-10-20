.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E28
/* 853F98 80241E28 3C028025 */  lui       $v0, 0x8025
/* 853F9C 80241E2C 8C4229F8 */  lw        $v0, 0x29f8($v0)
/* 853FA0 80241E30 8C43000C */  lw        $v1, 0xc($v0)
/* 853FA4 80241E34 24020001 */  addiu     $v0, $zero, 1
/* 853FA8 80241E38 AC62001C */  sw        $v0, 0x1c($v1)
/* 853FAC 80241E3C 03E00008 */  jr        $ra
/* 853FB0 80241E40 24020002 */   addiu    $v0, $zero, 2
