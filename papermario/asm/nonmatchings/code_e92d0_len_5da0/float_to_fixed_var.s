.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel float_to_fixed_var
/* 0E931C 802C496C 3C014480 */  lui   $at, 0x4480
/* 0E9320 802C4970 44810000 */  mtc1  $at, $f0
/* 0E9324 802C4974 00000000 */  nop   
/* 0E9328 802C4978 46006302 */  mul.s $f12, $f12, $f0
/* 0E932C 802C497C 00000000 */  nop   
/* 0E9330 802C4980 3C03F24A */  lui   $v1, 0xf24a
/* 0E9334 802C4984 34637A80 */  ori   $v1, $v1, 0x7a80
/* 0E9338 802C4988 4600608D */  trunc.w.s $f2, $f12
/* 0E933C 802C498C 44021000 */  mfc1  $v0, $f2
/* 0E9340 802C4990 03E00008 */  jr    $ra
/* 0E9344 802C4994 00431021 */   addu  $v0, $v0, $v1

