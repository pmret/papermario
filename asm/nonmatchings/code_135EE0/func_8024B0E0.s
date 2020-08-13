.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024B0E0
/* 13E420 8024B0E0 0006000D */  break 6
.L8024B0E4:
/* 13E424 8024B0E4 00001012 */  mflo  $v0
/* 13E428 8024B0E8 3C018027 */  lui   $at, 0x8027
/* 13E42C 8024B0EC C42006A8 */  lwc1  $f0, 0x6a8($at)
/* 13E430 8024B0F0 44826000 */  mtc1  $v0, $f12
/* 13E434 8024B0F4 00000000 */  nop   
/* 13E438 8024B0F8 46806320 */  cvt.s.w $f12, $f12
/* 13E43C 8024B0FC 0C00A8D4 */  jal   cos_deg
/* 13E440 8024B100 46006301 */   sub.s $f12, $f12, $f0
/* 13E444 8024B104 46160002 */  mul.s $f0, $f0, $f22
/* 13E448 8024B108 00000000 */  nop   
/* 13E44C 8024B10C 0000882D */  daddu $s1, $zero, $zero
/* 13E450 8024B110 1A00000B */  blez  $s0, .L8024B140
/* 13E454 8024B114 46140080 */   add.s $f2, $f0, $f20
/* 13E458 8024B118 0240182D */  daddu $v1, $s2, $zero
.L8024B11C:
/* 13E45C 8024B11C C4600000 */  lwc1  $f0, ($v1)
/* 13E460 8024B120 4600103C */  c.lt.s $f2, $f0
/* 13E464 8024B124 00000000 */  nop   
