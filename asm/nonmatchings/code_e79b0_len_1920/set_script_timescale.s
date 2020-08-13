.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_script_timescale
/* 0E8B90 802C41E0 3C01802E */  lui   $at, 0x802e
/* 0E8B94 802C41E4 C4209CA8 */  lwc1  $f0, -0x6358($at)
/* 0E8B98 802C41E8 44851000 */  mtc1  $a1, $f2
/* 0E8B9C 802C41EC 00000000 */  nop   
/* 0E8BA0 802C41F0 46001002 */  mul.s $f0, $f2, $f0
/* 0E8BA4 802C41F4 00000000 */  nop   
/* 0E8BA8 802C41F8 03E00008 */  jr    $ra
/* 0E8BAC 802C41FC E4800150 */   swc1  $f0, 0x150($a0)

