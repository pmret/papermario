.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel cos_deg
/* 005750 8002A350 3C014336 */  lui   $at, 0x4336
/* 005754 8002A354 34210B61 */  ori   $at, $at, 0xb61
/* 005758 8002A358 44810000 */  mtc1  $at, $f0
/* 00575C 8002A35C 00000000 */  nop   
/* 005760 8002A360 46006302 */  mul.s $f12, $f12, $f0
/* 005764 8002A364 00000000 */  nop   
/* 005768 8002A368 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00576C 8002A36C AFBF0010 */  sw    $ra, 0x10($sp)
/* 005770 8002A370 0C00A80D */  jal   _wrap_trig_lookup_value
/* 005774 8002A374 00000000 */   nop   
/* 005778 8002A378 0C0187C0 */  jal   coss
/* 00577C 8002A37C 3044FFFF */   andi  $a0, $v0, 0xffff
/* 005780 8002A380 00021400 */  sll   $v0, $v0, 0x10
/* 005784 8002A384 00021403 */  sra   $v0, $v0, 0x10
/* 005788 8002A388 3C018009 */  lui   $at, 0x8009
/* 00578C 8002A38C D4227D88 */  ldc1  $f2, 0x7d88($at)
/* 005790 8002A390 44820000 */  mtc1  $v0, $f0
/* 005794 8002A394 00000000 */  nop   
/* 005798 8002A398 46800021 */  cvt.d.w $f0, $f0
/* 00579C 8002A39C 46220002 */  mul.d $f0, $f0, $f2
/* 0057A0 8002A3A0 00000000 */  nop   
/* 0057A4 8002A3A4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0057A8 8002A3A8 46200020 */  cvt.s.d $f0, $f0
/* 0057AC 8002A3AC 03E00008 */  jr    $ra
/* 0057B0 8002A3B0 27BD0018 */   addiu $sp, $sp, 0x18

