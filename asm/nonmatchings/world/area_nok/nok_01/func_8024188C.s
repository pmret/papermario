.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024188C
/* 9C6C6C 8024188C 3C028025 */  lui       $v0, 0x8025
/* 9C6C70 80241890 8C421C68 */  lw        $v0, 0x1c68($v0)
/* 9C6C74 80241894 8C43000C */  lw        $v1, 0xc($v0)
/* 9C6C78 80241898 24020002 */  addiu     $v0, $zero, 2
/* 9C6C7C 8024189C 03E00008 */  jr        $ra
/* 9C6C80 802418A0 AC62001C */   sw       $v0, 0x1c($v1)
