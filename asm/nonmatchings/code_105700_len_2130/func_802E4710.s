.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802E4710
/* 105F90 802E4710 94820024 */  lhu   $v0, 0x24($a0)
/* 105F94 802E4714 00451023 */  subu  $v0, $v0, $a1
/* 105F98 802E4718 04420001 */  bltzl $v0, .L802E4720
/* 105F9C 802E471C 2442000A */   addiu $v0, $v0, 0xa
.L802E4720:
/* 105FA0 802E4720 00021080 */  sll   $v0, $v0, 2
/* 105FA4 802E4724 00821021 */  addu  $v0, $a0, $v0
/* 105FA8 802E4728 03E00008 */  jr    $ra
/* 105FAC 802E472C C4400028 */   lwc1  $f0, 0x28($v0)

