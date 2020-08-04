.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004C268
/* 027668 8004C268 30A20C00 */  andi  $v0, $a1, 0xc00
/* 02766C 8004C26C 00024282 */  srl   $t0, $v0, 0xa
/* 027670 8004C270 0000382D */  daddu $a3, $zero, $zero
/* 027674 8004C274 30A523FF */  andi  $a1, $a1, 0x23ff
/* 027678 8004C278 2406016C */  addiu $a2, $zero, 0x16c
.L8004C27C:
/* 02767C 8004C27C 00861821 */  addu  $v1, $a0, $a2
/* 027680 8004C280 94620096 */  lhu   $v0, 0x96($v1)
/* 027684 8004C284 50450001 */  beql  $v0, $a1, .L8004C28C
/* 027688 8004C288 A0680085 */   sb    $t0, 0x85($v1)
.L8004C28C:
/* 02768C 8004C28C 24E70001 */  addiu $a3, $a3, 1
/* 027690 8004C290 28E20008 */  slti  $v0, $a3, 8
/* 027694 8004C294 1440FFF9 */  bnez  $v0, .L8004C27C
/* 027698 8004C298 24C600AC */   addiu $a2, $a2, 0xac
/* 02769C 8004C29C 03E00008 */  jr    $ra
/* 0276A0 8004C2A0 00000000 */   nop   

