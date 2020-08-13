.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802492B4
/* 13C5F4 802492B4 34422000 */  ori   $v0, $v0, 0x2000
/* 13C5F8 802492B8 00621024 */  and   $v0, $v1, $v0
/* 13C5FC 802492BC 10400022 */  beqz  $v0, .L80249348
/* 13C600 802492C0 3C020001 */   lui   $v0, 1
/* 13C604 802492C4 00621024 */  and   $v0, $v1, $v0
/* 13C608 802492C8 10400011 */  beqz  $v0, .L80249310
/* 13C60C 802492CC 24A5FFFF */   addiu $a1, $a1, -1
/* 13C610 802492D0 04A20001 */  bltzl $a1, .L802492D8
/* 13C614 802492D4 0000282D */   daddu $a1, $zero, $zero
.L802492D8:
/* 13C618 802492D8 3C048027 */  lui   $a0, 0x8027
/* 13C61C 802492DC 24840280 */  addiu $a0, $a0, 0x280
/* 13C620 802492E0 8C830000 */  lw    $v1, ($a0)
