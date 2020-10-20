.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240140_939A70
/* 939A70 80240140 8C830148 */  lw        $v1, 0x148($a0)
/* 939A74 80240144 24020003 */  addiu     $v0, $zero, 3
/* 939A78 80240148 A06200B5 */  sb        $v0, 0xb5($v1)
/* 939A7C 8024014C 03E00008 */  jr        $ra
/* 939A80 80240150 24020002 */   addiu    $v0, $zero, 2
/* 939A84 80240154 00000000 */  nop       
/* 939A88 80240158 00000000 */  nop       
/* 939A8C 8024015C 00000000 */  nop       
