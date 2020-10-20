.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_8697BC
/* 8697BC 8024030C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8697C0 80240310 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8697C4 80240314 8C430004 */  lw        $v1, 4($v0)
/* 8697C8 80240318 3C040010 */  lui       $a0, 0x10
/* 8697CC 8024031C 00641825 */  or        $v1, $v1, $a0
/* 8697D0 80240320 AC430004 */  sw        $v1, 4($v0)
/* 8697D4 80240324 03E00008 */  jr        $ra
/* 8697D8 80240328 24020002 */   addiu    $v0, $zero, 2
