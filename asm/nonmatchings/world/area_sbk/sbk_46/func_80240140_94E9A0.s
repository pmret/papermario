.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240140_94EAE0
/* 94EAE0 80240140 8C830148 */  lw        $v1, 0x148($a0)
/* 94EAE4 80240144 24020003 */  addiu     $v0, $zero, 3
/* 94EAE8 80240148 A06200B5 */  sb        $v0, 0xb5($v1)
/* 94EAEC 8024014C 03E00008 */  jr        $ra
/* 94EAF0 80240150 24020002 */   addiu    $v0, $zero, 2
/* 94EAF4 80240154 00000000 */  nop       
/* 94EAF8 80240158 00000000 */  nop       
/* 94EAFC 8024015C 00000000 */  nop       
