.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240030
/* 7E73D0 80240030 03E00008 */  jr        $ra
/* 7E73D4 80240034 24020002 */   addiu    $v0, $zero, 2
