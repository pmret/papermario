.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel cos_rad
/* 0055D0 8002A1D0 3C014622 */  lui   $at, 0x4622
/* 0055D4 8002A1D4 3421F983 */  ori   $at, $at, 0xf983
/* 0055D8 8002A1D8 44810000 */  mtc1  $at, $f0
/* 0055DC 8002A1DC 00000000 */  nop   
/* 0055E0 8002A1E0 46006302 */  mul.s $f12, $f12, $f0
/* 0055E4 8002A1E4 00000000 */  nop   
/* 0055E8 8002A1E8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0055EC 8002A1EC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0055F0 8002A1F0 0C00A80D */  jal   _wrap_trig_lookup_value
/* 0055F4 8002A1F4 00000000 */   nop   
/* 0055F8 8002A1F8 0C0187C0 */  jal   coss
/* 0055FC 8002A1FC 3044FFFF */   andi  $a0, $v0, 0xffff
/* 005600 8002A200 00021400 */  sll   $v0, $v0, 0x10
/* 005604 8002A204 00021403 */  sra   $v0, $v0, 0x10
/* 005608 8002A208 3C018009 */  lui   $at, 0x8009
/* 00560C 8002A20C D4227D70 */  ldc1  $f2, 0x7d70($at)
/* 005610 8002A210 44820000 */  mtc1  $v0, $f0
/* 005614 8002A214 00000000 */  nop   
/* 005618 8002A218 46800021 */  cvt.d.w $f0, $f0
/* 00561C 8002A21C 46220002 */  mul.d $f0, $f0, $f2
/* 005620 8002A220 00000000 */  nop   
/* 005624 8002A224 8FBF0010 */  lw    $ra, 0x10($sp)
/* 005628 8002A228 46200020 */  cvt.s.d $f0, $f0
/* 00562C 8002A22C 03E00008 */  jr    $ra
/* 005630 8002A230 27BD0018 */   addiu $sp, $sp, 0x18

