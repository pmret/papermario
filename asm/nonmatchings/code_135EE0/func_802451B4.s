.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802451B4
/* 1384F4 802451B4 00000000 */  nop   
/* 1384F8 802451B8 46800021 */  cvt.d.w $f0, $f0
/* 1384FC 802451BC 46220002 */  mul.d $f0, $f0, $f2
/* 138500 802451C0 00000000 */  nop   
/* 138504 802451C4 3C018027 */  lui   $at, 0x8027
/* 138508 802451C8 D422FFA8 */  ldc1  $f2, -0x58($at)
/* 13850C 802451CC 46201081 */  sub.d $f2, $f2, $f0
/* 138510 802451D0 8E040014 */  lw    $a0, 0x14($s0)
/* 138514 802451D4 4620110D */  trunc.w.d $f4, $f2
/* 138518 802451D8 44052000 */  mfc1  $a1, $f4
/* 13851C 802451DC 08091480 */  j     func_80245200
/* 138520 802451E0 00000000 */   nop   

.L802451E4:
/* 138524 802451E4 3C108027 */  lui   $s0, 0x8027
/* 138528 802451E8 26100130 */  addiu $s0, $s0, 0x130
/* 13852C 802451EC 8E040014 */  lw    $a0, 0x14($s0)
/* 138530 802451F0 0C05128B */  jal   clear_icon_flags
/* 138534 802451F4 24050020 */   addiu $a1, $zero, 0x20
/* 138538 802451F8 8E040014 */  lw    $a0, 0x14($s0)
/* 13853C 802451FC 240500FF */  addiu $a1, $zero, 0xff
