.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_888BD0
/* 888BD0 80240000 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 888BD4 80240004 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 888BD8 80240008 8C430004 */  lw        $v1, 4($v0)
/* 888BDC 8024000C 3C040010 */  lui       $a0, 0x10
/* 888BE0 80240010 00641825 */  or        $v1, $v1, $a0
/* 888BE4 80240014 AC430004 */  sw        $v1, 4($v0)
/* 888BE8 80240018 03E00008 */  jr        $ra
/* 888BEC 8024001C 24020002 */   addiu    $v0, $zero, 2
