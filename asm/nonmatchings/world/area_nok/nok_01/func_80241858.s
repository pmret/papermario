.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241858
/* 9C6C38 80241858 3C028025 */  lui       $v0, 0x8025
/* 9C6C3C 8024185C 8C421C68 */  lw        $v0, 0x1c68($v0)
/* 9C6C40 80241860 8C42000C */  lw        $v0, 0xc($v0)
/* 9C6C44 80241864 AC40001C */  sw        $zero, 0x1c($v0)
/* 9C6C48 80241868 03E00008 */  jr        $ra
/* 9C6C4C 8024186C 24020002 */   addiu    $v0, $zero, 2
