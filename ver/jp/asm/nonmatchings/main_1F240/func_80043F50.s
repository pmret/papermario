.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80043F50
/* 1F350 80043F50 03E00008 */  jr        $ra
/* 1F354 80043F54 24020002 */   addiu    $v0, $zero, 2
