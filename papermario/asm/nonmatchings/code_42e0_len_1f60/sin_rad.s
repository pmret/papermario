.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel sin_rad
/* 00556C 8002A16C 3C014622 */  lui   $at, 0x4622
/* 005570 8002A170 3421F983 */  ori   $at, $at, 0xf983
/* 005574 8002A174 44810000 */  mtc1  $at, $f0
/* 005578 8002A178 00000000 */  nop   
/* 00557C 8002A17C 46006302 */  mul.s $f12, $f12, $f0
/* 005580 8002A180 00000000 */  nop   
/* 005584 8002A184 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 005588 8002A188 AFBF0010 */  sw    $ra, 0x10($sp)
/* 00558C 8002A18C 0C00A80D */  jal   _wrap_trig_lookup_value
/* 005590 8002A190 00000000 */   nop   
/* 005594 8002A194 0C01917C */  jal   sins
/* 005598 8002A198 3044FFFF */   andi  $a0, $v0, 0xffff
/* 00559C 8002A19C 00021400 */  sll   $v0, $v0, 0x10
/* 0055A0 8002A1A0 00021403 */  sra   $v0, $v0, 0x10
/* 0055A4 8002A1A4 3C018009 */  lui   $at, 0x8009
/* 0055A8 8002A1A8 D4227D68 */  ldc1  $f2, 0x7d68($at)
/* 0055AC 8002A1AC 44820000 */  mtc1  $v0, $f0
/* 0055B0 8002A1B0 00000000 */  nop   
/* 0055B4 8002A1B4 46800021 */  cvt.d.w $f0, $f0
/* 0055B8 8002A1B8 46220002 */  mul.d $f0, $f0, $f2
/* 0055BC 8002A1BC 00000000 */  nop   
/* 0055C0 8002A1C0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0055C4 8002A1C4 46200020 */  cvt.s.d $f0, $f0
/* 0055C8 8002A1C8 03E00008 */  jr    $ra
/* 0055CC 8002A1CC 27BD0018 */   addiu $sp, $sp, 0x18

