.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_871D3C
/* 871D3C 8024030C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 871D40 80240310 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 871D44 80240314 8C430004 */  lw        $v1, 4($v0)
/* 871D48 80240318 3C040010 */  lui       $a0, 0x10
/* 871D4C 8024031C 00641825 */  or        $v1, $v1, $a0
/* 871D50 80240320 AC430004 */  sw        $v1, 4($v0)
/* 871D54 80240324 03E00008 */  jr        $ra
/* 871D58 80240328 24020002 */   addiu    $v0, $zero, 2
