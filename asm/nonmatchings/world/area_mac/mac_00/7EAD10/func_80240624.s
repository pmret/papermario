.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240624
/* 7EB334 80240624 03E00008 */  jr        $ra
/* 7EB338 80240628 24020002 */   addiu    $v0, $zero, 2
/* 7EB33C 8024062C 00000000 */  nop       
