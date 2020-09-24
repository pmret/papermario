.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DF3FC
/* 788AC 800DF3FC 44863000 */  mtc1      $a2, $f6
/* 788B0 800DF400 C7A40010 */  lwc1      $f4, 0x10($sp)
/* 788B4 800DF404 46043082 */  mul.s     $f2, $f6, $f4
/* 788B8 800DF408 00000000 */  nop       
/* 788BC 800DF40C 44874000 */  mtc1      $a3, $f8
/* 788C0 800DF410 C7AA0014 */  lwc1      $f10, 0x14($sp)
/* 788C4 800DF414 460A4002 */  mul.s     $f0, $f8, $f10
/* 788C8 800DF418 00000000 */  nop       
/* 788CC 800DF41C 46001080 */  add.s     $f2, $f2, $f0
/* 788D0 800DF420 46041102 */  mul.s     $f4, $f2, $f4
/* 788D4 800DF424 00000000 */  nop       
/* 788D8 800DF428 460A1082 */  mul.s     $f2, $f2, $f10
/* 788DC 800DF42C 00000000 */  nop       
/* 788E0 800DF430 46043181 */  sub.s     $f6, $f6, $f4
/* 788E4 800DF434 3C013F00 */  lui       $at, 0x3f00
/* 788E8 800DF438 44810000 */  mtc1      $at, $f0
/* 788EC 800DF43C 00000000 */  nop       
/* 788F0 800DF440 46003182 */  mul.s     $f6, $f6, $f0
/* 788F4 800DF444 00000000 */  nop       
/* 788F8 800DF448 46024201 */  sub.s     $f8, $f8, $f2
/* 788FC 800DF44C 46004202 */  mul.s     $f8, $f8, $f0
/* 78900 800DF450 00000000 */  nop       
/* 78904 800DF454 E4860000 */  swc1      $f6, ($a0)
/* 78908 800DF458 03E00008 */  jr        $ra
/* 7890C 800DF45C E4A80000 */   swc1     $f8, ($a1)
