.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_957390
/* 957390 80240040 8C830148 */  lw        $v1, 0x148($a0)
/* 957394 80240044 24020003 */  addiu     $v0, $zero, 3
/* 957398 80240048 A06200B5 */  sb        $v0, 0xb5($v1)
/* 95739C 8024004C 03E00008 */  jr        $ra
/* 9573A0 80240050 24020002 */   addiu    $v0, $zero, 2
/* 9573A4 80240054 00000000 */  nop       
/* 9573A8 80240058 00000000 */  nop       
/* 9573AC 8024005C 00000000 */  nop       
