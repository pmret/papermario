.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_936D10
/* 936D10 80240040 8C830148 */  lw        $v1, 0x148($a0)
/* 936D14 80240044 24020003 */  addiu     $v0, $zero, 3
/* 936D18 80240048 A06200B5 */  sb        $v0, 0xb5($v1)
/* 936D1C 8024004C 03E00008 */  jr        $ra
/* 936D20 80240050 24020002 */   addiu    $v0, $zero, 2
/* 936D24 80240054 00000000 */  nop       
/* 936D28 80240058 00000000 */  nop       
/* 936D2C 8024005C 00000000 */  nop       
