.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FC38
/* 2B038 8004FC38 808300D4 */  lb        $v1, 0xd4($a0)
/* 2B03C 8004FC3C 00031040 */  sll       $v0, $v1, 1
/* 2B040 8004FC40 00431021 */  addu      $v0, $v0, $v1
/* 2B044 8004FC44 000210C0 */  sll       $v0, $v0, 3
/* 2B048 8004FC48 00431021 */  addu      $v0, $v0, $v1
/* 2B04C 8004FC4C 00021080 */  sll       $v0, $v0, 2
/* 2B050 8004FC50 03E00008 */  jr        $ra
/* 2B054 8004FC54 A4A20046 */   sh       $v0, 0x46($a1)
