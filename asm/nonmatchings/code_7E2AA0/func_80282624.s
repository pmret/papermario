.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80282624
/* 7E34A4 80282624 3C018015 */  lui       $at, 0x8015
/* 7E34A8 80282628 AC201310 */  sw        $zero, 0x1310($at)
/* 7E34AC 8028262C 03E00008 */  jr        $ra
/* 7E34B0 80282630 24020002 */   addiu    $v0, $zero, 2
