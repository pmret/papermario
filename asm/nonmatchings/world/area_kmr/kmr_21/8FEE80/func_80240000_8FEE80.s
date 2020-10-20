.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8FEE80
/* 8FEE80 80240000 03E00008 */  jr        $ra
/* 8FEE84 80240004 24020001 */   addiu    $v0, $zero, 1
/* 8FEE88 80240008 00000000 */  nop       
/* 8FEE8C 8024000C 00000000 */  nop       
