.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8232C0
/* 8232C0 80240000 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8232C4 80240004 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8232C8 80240008 8C430004 */  lw        $v1, 4($v0)
/* 8232CC 8024000C 3C040010 */  lui       $a0, 0x10
/* 8232D0 80240010 00641825 */  or        $v1, $v1, $a0
/* 8232D4 80240014 AC430004 */  sw        $v1, 4($v0)
/* 8232D8 80240018 03E00008 */  jr        $ra
/* 8232DC 8024001C 24020002 */   addiu    $v0, $zero, 2
