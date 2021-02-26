.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FCA0
/* 2B0A0 8004FCA0 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B0A4 8004FCA4 03E00008 */  jr        $ra
/* 2B0A8 8004FCA8 A0A20056 */   sb       $v0, 0x56($a1)
