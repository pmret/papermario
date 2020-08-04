.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8005BDD8
/* 0371D8 8005BDD8 000410C0 */  sll   $v0, $a0, 3
/* 0371DC 8005BDDC 00441023 */  subu  $v0, $v0, $a0
/* 0371E0 8005BDE0 3C03800B */  lui   $v1, 0x800b
/* 0371E4 8005BDE4 8C6342E4 */  lw    $v1, 0x42e4($v1)
/* 0371E8 8005BDE8 00021080 */  sll   $v0, $v0, 2
/* 0371EC 8005BDEC 00431021 */  addu  $v0, $v0, $v1
/* 0371F0 8005BDF0 8C42000C */  lw    $v0, 0xc($v0)
/* 0371F4 8005BDF4 C4400030 */  lwc1  $f0, 0x30($v0)
/* 0371F8 8005BDF8 E4A00000 */  swc1  $f0, ($a1)
/* 0371FC 8005BDFC C4400034 */  lwc1  $f0, 0x34($v0)
/* 037200 8005BE00 E4C00000 */  swc1  $f0, ($a2)
/* 037204 8005BE04 C4400038 */  lwc1  $f0, 0x38($v0)
/* 037208 8005BE08 03E00008 */  jr    $ra
/* 03720C 8005BE0C E4E00000 */   swc1  $f0, ($a3)

