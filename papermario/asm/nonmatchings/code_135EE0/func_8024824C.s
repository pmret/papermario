.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024824C
/* 13B58C 8024824C 46041082 */  mul.s $f2, $f2, $f4
/* 13B590 80248250 00000000 */  nop   
/* 13B594 80248254 AD220000 */  sw    $v0, ($t1)
/* 13B598 80248258 4600018D */  trunc.w.s $f6, $f0
/* 13B59C 8024825C 44023000 */  mfc1  $v0, $f6
/* 13B5A0 80248260 00000000 */  nop   
/* 13B5A4 80248264 30420FFF */  andi  $v0, $v0, 0xfff
/* 13B5A8 80248268 00021300 */  sll   $v0, $v0, 0xc
/* 13B5AC 8024826C 4600118D */  trunc.w.s $f6, $f2
/* 13B5B0 80248270 44033000 */  mfc1  $v1, $f6
