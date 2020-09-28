.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EA524
/* 839D4 800EA524 03E00008 */  jr        $ra
/* 839D8 800EA528 24020001 */   addiu    $v0, $zero, 1
