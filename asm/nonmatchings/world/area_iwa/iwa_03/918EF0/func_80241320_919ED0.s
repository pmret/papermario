.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241320_919ED0
/* 919ED0 80241320 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 919ED4 80241324 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 919ED8 80241328 8C430000 */  lw        $v1, ($v0)
/* 919EDC 8024132C 8C840084 */  lw        $a0, 0x84($a0)
/* 919EE0 80241330 34630010 */  ori       $v1, $v1, 0x10
/* 919EE4 80241334 AC4400D0 */  sw        $a0, 0xd0($v0)
/* 919EE8 80241338 AC430000 */  sw        $v1, ($v0)
/* 919EEC 8024133C 03E00008 */  jr        $ra
/* 919EF0 80241340 24020002 */   addiu    $v0, $zero, 2
/* 919EF4 80241344 00000000 */  nop       
/* 919EF8 80241348 00000000 */  nop       
/* 919EFC 8024134C 00000000 */  nop       
