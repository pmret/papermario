.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_876EE0
/* 876EE0 80240000 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 876EE4 80240004 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 876EE8 80240008 8C430004 */  lw        $v1, 4($v0)
/* 876EEC 8024000C 3C040010 */  lui       $a0, 0x10
/* 876EF0 80240010 00641825 */  or        $v1, $v1, $a0
/* 876EF4 80240014 AC430004 */  sw        $v1, 4($v0)
/* 876EF8 80240018 03E00008 */  jr        $ra
/* 876EFC 8024001C 24020002 */   addiu    $v0, $zero, 2
