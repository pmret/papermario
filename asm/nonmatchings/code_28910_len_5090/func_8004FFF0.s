.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FFF0
/* 2B3F0 8004FFF0 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B3F4 8004FFF4 03E00008 */  jr        $ra
/* 2B3F8 8004FFF8 A0A20056 */   sb       $v0, 0x56($a1)
