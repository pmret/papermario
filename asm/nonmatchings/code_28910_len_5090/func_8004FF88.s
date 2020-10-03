.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FF88
/* 2B388 8004FF88 808300D4 */  lb        $v1, 0xd4($a0)
/* 2B38C 8004FF8C 00031040 */  sll       $v0, $v1, 1
/* 2B390 8004FF90 00431021 */  addu      $v0, $v0, $v1
/* 2B394 8004FF94 000210C0 */  sll       $v0, $v0, 3
/* 2B398 8004FF98 00431021 */  addu      $v0, $v0, $v1
/* 2B39C 8004FF9C 00021080 */  sll       $v0, $v0, 2
/* 2B3A0 8004FFA0 03E00008 */  jr        $ra
/* 2B3A4 8004FFA4 A4A20046 */   sh       $v0, 0x46($a1)
