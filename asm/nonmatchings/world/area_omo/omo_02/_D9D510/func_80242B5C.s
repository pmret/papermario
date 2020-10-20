.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B5C
/* DA002C 80242B5C 8C830148 */  lw        $v1, 0x148($a0)
/* DA0030 80242B60 24020003 */  addiu     $v0, $zero, 3
/* DA0034 80242B64 A06200B5 */  sb        $v0, 0xb5($v1)
/* DA0038 80242B68 03E00008 */  jr        $ra
/* DA003C 80242B6C 24020002 */   addiu    $v0, $zero, 2
