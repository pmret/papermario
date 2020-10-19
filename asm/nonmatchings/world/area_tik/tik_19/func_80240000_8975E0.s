.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8975E0
/* 8975E0 80240000 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8975E4 80240004 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8975E8 80240008 8C430004 */  lw        $v1, 4($v0)
/* 8975EC 8024000C 3C040010 */  lui       $a0, 0x10
/* 8975F0 80240010 00641825 */  or        $v1, $v1, $a0
/* 8975F4 80240014 AC430004 */  sw        $v1, 4($v0)
/* 8975F8 80240018 03E00008 */  jr        $ra
/* 8975FC 8024001C 24020002 */   addiu    $v0, $zero, 2
