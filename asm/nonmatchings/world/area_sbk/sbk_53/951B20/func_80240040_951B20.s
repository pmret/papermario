.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_951B20
/* 951B20 80240040 8C830148 */  lw        $v1, 0x148($a0)
/* 951B24 80240044 24020003 */  addiu     $v0, $zero, 3
/* 951B28 80240048 A06200B5 */  sb        $v0, 0xb5($v1)
/* 951B2C 8024004C 03E00008 */  jr        $ra
/* 951B30 80240050 24020002 */   addiu    $v0, $zero, 2
/* 951B34 80240054 00000000 */  nop       
/* 951B38 80240058 00000000 */  nop       
/* 951B3C 8024005C 00000000 */  nop       
