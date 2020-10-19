.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_90B240
/* 90B240 80240000 03E00008 */  jr        $ra
/* 90B244 80240004 24020001 */   addiu    $v0, $zero, 1
/* 90B248 80240008 00000000 */  nop       
/* 90B24C 8024000C 00000000 */  nop       
