.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_89DAAC
/* 89DAAC 8024030C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 89DAB0 80240310 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 89DAB4 80240314 8C430004 */  lw        $v1, 4($v0)
/* 89DAB8 80240318 3C040010 */  lui       $a0, 0x10
/* 89DABC 8024031C 00641825 */  or        $v1, $v1, $a0
/* 89DAC0 80240320 AC430004 */  sw        $v1, 4($v0)
/* 89DAC4 80240324 03E00008 */  jr        $ra
/* 89DAC8 80240328 24020002 */   addiu    $v0, $zero, 2
