.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80248274
/* 13B5B4 80248274 44871000 */  mtc1  $a3, $f2
/* 13B5B8 80248278 00000000 */  nop   
/* 13B5BC 8024827C 468010A0 */  cvt.s.w $f2, $f2
/* 13B5C0 80248280 46041082 */  mul.s $f2, $f2, $f4
