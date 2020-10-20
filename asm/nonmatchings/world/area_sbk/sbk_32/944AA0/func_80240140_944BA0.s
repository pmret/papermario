.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240140_944BA0
/* 944BA0 80240140 8C830148 */  lw        $v1, 0x148($a0)
/* 944BA4 80240144 24020003 */  addiu     $v0, $zero, 3
/* 944BA8 80240148 A06200B5 */  sb        $v0, 0xb5($v1)
/* 944BAC 8024014C 03E00008 */  jr        $ra
/* 944BB0 80240150 24020002 */   addiu    $v0, $zero, 2
/* 944BB4 80240154 00000000 */  nop       
/* 944BB8 80240158 00000000 */  nop       
/* 944BBC 8024015C 00000000 */  nop       
