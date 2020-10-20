.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_907A30
/* 907A30 80240000 03E00008 */  jr        $ra
/* 907A34 80240004 24020001 */   addiu    $v0, $zero, 1
/* 907A38 80240008 00000000 */  nop       
/* 907A3C 8024000C 00000000 */  nop       
