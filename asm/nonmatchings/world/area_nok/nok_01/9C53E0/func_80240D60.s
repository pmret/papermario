.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D60
/* 9C6140 80240D60 03E00008 */  jr        $ra
/* 9C6144 80240D64 24020002 */   addiu    $v0, $zero, 2
