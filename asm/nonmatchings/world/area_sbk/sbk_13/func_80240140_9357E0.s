.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240140_935920
/* 935920 80240140 8C830148 */  lw        $v1, 0x148($a0)
/* 935924 80240144 24020003 */  addiu     $v0, $zero, 3
/* 935928 80240148 A06200B5 */  sb        $v0, 0xb5($v1)
/* 93592C 8024014C 03E00008 */  jr        $ra
/* 935930 80240150 24020002 */   addiu    $v0, $zero, 2
/* 935934 80240154 00000000 */  nop       
/* 935938 80240158 00000000 */  nop       
/* 93593C 8024015C 00000000 */  nop       
