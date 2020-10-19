.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_92F8F0
/* 92F8F0 80240040 8C830148 */  lw        $v1, 0x148($a0)
/* 92F8F4 80240044 24020003 */  addiu     $v0, $zero, 3
/* 92F8F8 80240048 A06200B5 */  sb        $v0, 0xb5($v1)
/* 92F8FC 8024004C 03E00008 */  jr        $ra
/* 92F900 80240050 24020002 */   addiu    $v0, $zero, 2
/* 92F904 80240054 00000000 */  nop       
/* 92F908 80240058 00000000 */  nop       
/* 92F90C 8024005C 00000000 */  nop       
