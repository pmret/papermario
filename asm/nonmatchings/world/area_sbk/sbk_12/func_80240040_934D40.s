.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_934D80
/* 934D80 80240040 8C830148 */  lw        $v1, 0x148($a0)
/* 934D84 80240044 24020003 */  addiu     $v0, $zero, 3
/* 934D88 80240048 A06200B5 */  sb        $v0, 0xb5($v1)
/* 934D8C 8024004C 03E00008 */  jr        $ra
/* 934D90 80240050 24020002 */   addiu    $v0, $zero, 2
/* 934D94 80240054 00000000 */  nop       
/* 934D98 80240058 00000000 */  nop       
/* 934D9C 8024005C 00000000 */  nop       
