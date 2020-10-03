.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FF70
/* 2B370 8004FF70 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B374 8004FF74 24030001 */  addiu     $v1, $zero, 1
/* 2B378 8004FF78 A0A30041 */  sb        $v1, 0x41($a1)
/* 2B37C 8004FF7C 3042007F */  andi      $v0, $v0, 0x7f
/* 2B380 8004FF80 03E00008 */  jr        $ra
/* 2B384 8004FF84 A0A20049 */   sb       $v0, 0x49($a1)
