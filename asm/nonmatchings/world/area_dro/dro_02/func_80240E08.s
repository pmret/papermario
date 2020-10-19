.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E08
/* 969FC8 80240E08 3C028025 */  lui       $v0, 0x8025
/* 969FCC 80240E0C 8C42EFC8 */  lw        $v0, -0x1038($v0)
/* 969FD0 80240E10 8C43000C */  lw        $v1, 0xc($v0)
/* 969FD4 80240E14 24020001 */  addiu     $v0, $zero, 1
/* 969FD8 80240E18 AC62001C */  sw        $v0, 0x1c($v1)
/* 969FDC 80240E1C 03E00008 */  jr        $ra
/* 969FE0 80240E20 24020002 */   addiu    $v0, $zero, 2
