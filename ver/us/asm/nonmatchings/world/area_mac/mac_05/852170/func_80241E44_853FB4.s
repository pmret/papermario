.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E44_853FB4
/* 853FB4 80241E44 3C028025 */  lui       $v0, %hi(D_802529F8)
/* 853FB8 80241E48 8C4229F8 */  lw        $v0, %lo(D_802529F8)($v0)
/* 853FBC 80241E4C 8C43000C */  lw        $v1, 0xc($v0)
/* 853FC0 80241E50 24020002 */  addiu     $v0, $zero, 2
/* 853FC4 80241E54 03E00008 */  jr        $ra
/* 853FC8 80241E58 AC62001C */   sw       $v0, 0x1c($v1)
