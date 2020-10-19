.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E70_9EEA60
/* 9EEA60 80240E70 24020001 */  addiu     $v0, $zero, 1
/* 9EEA64 80240E74 3C018024 */  lui       $at, 0x8024
/* 9EEA68 80240E78 AC223254 */  sw        $v0, 0x3254($at)
/* 9EEA6C 80240E7C 03E00008 */  jr        $ra
/* 9EEA70 80240E80 24020002 */   addiu    $v0, $zero, 2
/* 9EEA74 80240E84 00000000 */  nop       
/* 9EEA78 80240E88 00000000 */  nop       
/* 9EEA7C 80240E8C 00000000 */  nop       
