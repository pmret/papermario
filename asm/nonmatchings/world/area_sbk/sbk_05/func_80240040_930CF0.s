.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_930D30
/* 930D30 80240040 8C830148 */  lw        $v1, 0x148($a0)
/* 930D34 80240044 24020003 */  addiu     $v0, $zero, 3
/* 930D38 80240048 A06200B5 */  sb        $v0, 0xb5($v1)
/* 930D3C 8024004C 03E00008 */  jr        $ra
/* 930D40 80240050 24020002 */   addiu    $v0, $zero, 2
/* 930D44 80240054 00000000 */  nop       
/* 930D48 80240058 00000000 */  nop       
/* 930D4C 8024005C 00000000 */  nop       
