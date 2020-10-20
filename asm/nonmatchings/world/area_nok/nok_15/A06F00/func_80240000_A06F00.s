.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A06F00
/* A06F00 80240000 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A06F04 80240004 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A06F08 80240008 8C430004 */  lw        $v1, 4($v0)
/* A06F0C 8024000C 3C040010 */  lui       $a0, 0x10
/* A06F10 80240010 00641825 */  or        $v1, $v1, $a0
/* A06F14 80240014 AC430004 */  sw        $v1, 4($v0)
/* A06F18 80240018 03E00008 */  jr        $ra
/* A06F1C 8024001C 24020002 */   addiu    $v0, $zero, 2
