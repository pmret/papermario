.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B3C_9001AC
/* 9001AC 80240B3C 3C018025 */  lui       $at, %hi(D_802483D0)
/* 9001B0 80240B40 AC2083D0 */  sw        $zero, %lo(D_802483D0)($at)
/* 9001B4 80240B44 03E00008 */  jr        $ra
/* 9001B8 80240B48 24020002 */   addiu    $v0, $zero, 2
