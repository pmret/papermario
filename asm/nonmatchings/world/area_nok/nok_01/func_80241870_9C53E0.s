.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241870_9C6C50
/* 9C6C50 80241870 3C028025 */  lui       $v0, 0x8025
/* 9C6C54 80241874 8C421C68 */  lw        $v0, 0x1c68($v0)
/* 9C6C58 80241878 8C43000C */  lw        $v1, 0xc($v0)
/* 9C6C5C 8024187C 24020001 */  addiu     $v0, $zero, 1
/* 9C6C60 80241880 AC62001C */  sw        $v0, 0x1c($v1)
/* 9C6C64 80241884 03E00008 */  jr        $ra
/* 9C6C68 80241888 24020002 */   addiu    $v0, $zero, 2
