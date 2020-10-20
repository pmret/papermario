.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_930510
/* 930510 80240040 8C830148 */  lw        $v1, 0x148($a0)
/* 930514 80240044 24020003 */  addiu     $v0, $zero, 3
/* 930518 80240048 A06200B5 */  sb        $v0, 0xb5($v1)
/* 93051C 8024004C 03E00008 */  jr        $ra
/* 930520 80240050 24020002 */   addiu    $v0, $zero, 2
/* 930524 80240054 00000000 */  nop       
/* 930528 80240058 00000000 */  nop       
/* 93052C 8024005C 00000000 */  nop       
