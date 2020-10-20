.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B3C
/* 9001AC 80240B3C 3C018025 */  lui       $at, 0x8025
/* 9001B0 80240B40 AC2083D0 */  sw        $zero, -0x7c30($at)
/* 9001B4 80240B44 03E00008 */  jr        $ra
/* 9001B8 80240B48 24020002 */   addiu    $v0, $zero, 2
