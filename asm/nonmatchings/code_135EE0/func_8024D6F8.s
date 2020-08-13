.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024D6F8
.L8024D6F8:
/* 140A38 8024D6F8 82020004 */  lb    $v0, 4($s0)
/* 140A3C 8024D6FC 82030005 */  lb    $v1, 5($s0)
/* 140A40 8024D700 00430018 */  mult  $v0, $v1
/* 140A44 8024D704 00002812 */  mflo  $a1
/* 140A48 8024D708 82020006 */  lb    $v0, 6($s0)
/* 140A4C 8024D70C 00000000 */  nop   
/* 140A50 8024D710 00A20018 */  mult  $a1, $v0
/* 140A54 8024D714 00002012 */  mflo  $a0
