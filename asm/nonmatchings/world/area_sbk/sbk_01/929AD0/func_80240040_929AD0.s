.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_929AD0
/* 929AD0 80240040 8C830148 */  lw        $v1, 0x148($a0)
/* 929AD4 80240044 24020003 */  addiu     $v0, $zero, 3
/* 929AD8 80240048 A06200B5 */  sb        $v0, 0xb5($v1)
/* 929ADC 8024004C 03E00008 */  jr        $ra
/* 929AE0 80240050 24020002 */   addiu    $v0, $zero, 2
/* 929AE4 80240054 00000000 */  nop       
/* 929AE8 80240058 00000000 */  nop       
/* 929AEC 8024005C 00000000 */  nop       
