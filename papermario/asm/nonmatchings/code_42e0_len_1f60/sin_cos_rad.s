.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel sin_cos_rad
/* 0054B4 8002A0B4 3C014622 */  lui   $at, 0x4622
/* 0054B8 8002A0B8 3421F983 */  ori   $at, $at, 0xf983
/* 0054BC 8002A0BC 44810000 */  mtc1  $at, $f0
/* 0054C0 8002A0C0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0054C4 8002A0C4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0054C8 8002A0C8 00A0882D */  daddu $s1, $a1, $zero
/* 0054CC 8002A0CC AFB20018 */  sw    $s2, 0x18($sp)
/* 0054D0 8002A0D0 46006302 */  mul.s $f12, $f12, $f0
/* 0054D4 8002A0D4 00000000 */  nop   
/* 0054D8 8002A0D8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0054DC 8002A0DC AFB00010 */  sw    $s0, 0x10($sp)
/* 0054E0 8002A0E0 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0054E4 8002A0E4 0C00A80D */  jal   _wrap_trig_lookup_value
/* 0054E8 8002A0E8 00C0902D */   daddu $s2, $a2, $zero
/* 0054EC 8002A0EC 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0054F0 8002A0F0 0C01917C */  jal   sins
/* 0054F4 8002A0F4 0200202D */   daddu $a0, $s0, $zero
/* 0054F8 8002A0F8 00021400 */  sll   $v0, $v0, 0x10
/* 0054FC 8002A0FC 00021403 */  sra   $v0, $v0, 0x10
/* 005500 8002A100 3C018009 */  lui   $at, 0x8009
/* 005504 8002A104 D4347D60 */  ldc1  $f20, 0x7d60($at)
/* 005508 8002A108 44820000 */  mtc1  $v0, $f0
/* 00550C 8002A10C 00000000 */  nop   
/* 005510 8002A110 46800021 */  cvt.d.w $f0, $f0
/* 005514 8002A114 46340002 */  mul.d $f0, $f0, $f20
/* 005518 8002A118 00000000 */  nop   
/* 00551C 8002A11C 0200202D */  daddu $a0, $s0, $zero
/* 005520 8002A120 46200020 */  cvt.s.d $f0, $f0
/* 005524 8002A124 0C0187C0 */  jal   coss
/* 005528 8002A128 E6200000 */   swc1  $f0, ($s1)
/* 00552C 8002A12C 00021400 */  sll   $v0, $v0, 0x10
/* 005530 8002A130 00021403 */  sra   $v0, $v0, 0x10
/* 005534 8002A134 44820000 */  mtc1  $v0, $f0
/* 005538 8002A138 00000000 */  nop   
/* 00553C 8002A13C 46800021 */  cvt.d.w $f0, $f0
/* 005540 8002A140 46340002 */  mul.d $f0, $f0, $f20
/* 005544 8002A144 00000000 */  nop   
/* 005548 8002A148 46200020 */  cvt.s.d $f0, $f0
/* 00554C 8002A14C E6400000 */  swc1  $f0, ($s2)
/* 005550 8002A150 8FBF001C */  lw    $ra, 0x1c($sp)
/* 005554 8002A154 8FB20018 */  lw    $s2, 0x18($sp)
/* 005558 8002A158 8FB10014 */  lw    $s1, 0x14($sp)
/* 00555C 8002A15C 8FB00010 */  lw    $s0, 0x10($sp)
/* 005560 8002A160 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 005564 8002A164 03E00008 */  jr    $ra
/* 005568 8002A168 27BD0028 */   addiu $sp, $sp, 0x28

