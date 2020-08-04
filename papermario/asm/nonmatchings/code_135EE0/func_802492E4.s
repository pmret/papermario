.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802492E4
/* 13C624 802492E4 00031040 */  sll   $v0, $v1, 1
/* 13C628 802492E8 00431021 */  addu  $v0, $v0, $v1
/* 13C62C 802492EC 00021080 */  sll   $v0, $v0, 2
/* 13C630 802492F0 3C018027 */  lui   $at, 0x8027
/* 13C634 802492F4 00220821 */  addu  $at, $at, $v0
/* 13C638 802492F8 90220289 */  lbu   $v0, 0x289($at)
/* 13C63C 802492FC 00A2102A */  slt   $v0, $a1, $v0
/* 13C640 80249300 10400011 */  beqz  $v0, .L80249348
/* 13C644 80249304 2462FFFF */   addiu $v0, $v1, -1
/* 13C648 80249308 080924D2 */  j     .L80249348
/* 13C64C 8024930C AC820000 */   sw    $v0, ($a0)

