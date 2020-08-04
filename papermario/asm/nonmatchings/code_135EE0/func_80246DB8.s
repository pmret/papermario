.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80246DB8
.L80246DB8:
/* 13A0F8 80246DB8 82020004 */  lb    $v0, 4($s0)
/* 13A0FC 80246DBC 82030005 */  lb    $v1, 5($s0)
/* 13A100 80246DC0 00430018 */  mult  $v0, $v1
/* 13A104 80246DC4 00003012 */  mflo  $a2
/* 13A108 80246DC8 82020006 */  lb    $v0, 6($s0)
/* 13A10C 80246DCC 00000000 */  nop   
/* 13A110 80246DD0 00C20018 */  mult  $a2, $v0
/* 13A114 80246DD4 00002012 */  mflo  $a0
/* 13A118 80246DD8 82020002 */  lb    $v0, 2($s0)
/* 13A11C 80246DDC 00000000 */  nop   
/* 13A120 80246DE0 00620018 */  mult  $v1, $v0
/* 13A124 80246DE4 00001812 */  mflo  $v1
/* 13A128 80246DE8 00831821 */  addu  $v1, $a0, $v1
