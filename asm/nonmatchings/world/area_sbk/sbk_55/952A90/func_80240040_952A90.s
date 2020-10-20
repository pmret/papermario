.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_952A90
/* 952A90 80240040 8C830148 */  lw        $v1, 0x148($a0)
/* 952A94 80240044 24020003 */  addiu     $v0, $zero, 3
/* 952A98 80240048 A06200B5 */  sb        $v0, 0xb5($v1)
/* 952A9C 8024004C 03E00008 */  jr        $ra
/* 952AA0 80240050 24020002 */   addiu    $v0, $zero, 2
/* 952AA4 80240054 00000000 */  nop       
/* 952AA8 80240058 00000000 */  nop       
/* 952AAC 8024005C 00000000 */  nop       
