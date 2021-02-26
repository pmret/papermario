.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004F994
/* 2AD94 8004F994 808300D4 */  lb        $v1, 0xd4($a0)
/* 2AD98 8004F998 00031040 */  sll       $v0, $v1, 1
/* 2AD9C 8004F99C 00431021 */  addu      $v0, $v0, $v1
/* 2ADA0 8004F9A0 000210C0 */  sll       $v0, $v0, 3
/* 2ADA4 8004F9A4 00431021 */  addu      $v0, $v0, $v1
/* 2ADA8 8004F9A8 00021080 */  sll       $v0, $v0, 2
/* 2ADAC 8004F9AC 03E00008 */  jr        $ra
/* 2ADB0 8004F9B0 A482020C */   sh       $v0, 0x20c($a0)
