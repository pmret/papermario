.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_801451D4
/* 0DB8D4 801451D4 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DB8D8 801451D8 00822024 */  and   $a0, $a0, $v0
/* 0DB8DC 801451DC 00042080 */  sll   $a0, $a0, 2
/* 0DB8E0 801451E0 3C030001 */  lui   $v1, 1
/* 0DB8E4 801451E4 3C028015 */  lui   $v0, 0x8015
/* 0DB8E8 801451E8 8C427960 */  lw    $v0, 0x7960($v0)
/* 0DB8EC 801451EC 44850000 */  mtc1  $a1, $f0
/* 0DB8F0 801451F0 00822021 */  addu  $a0, $a0, $v0
/* 0DB8F4 801451F4 8C840000 */  lw    $a0, ($a0)
/* 0DB8F8 801451F8 44861000 */  mtc1  $a2, $f2
/* 0DB8FC 801451FC 8C820000 */  lw    $v0, ($a0)
/* 0DB900 80145200 44872000 */  mtc1  $a3, $f4
/* 0DB904 80145204 00431024 */  and   $v0, $v0, $v1
/* 0DB908 80145208 10400004 */  beqz  $v0, .L8014521C
/* 0DB90C 8014520C 8C83001C */   lw    $v1, 0x1c($a0)
/* 0DB910 80145210 E460001C */  swc1  $f0, 0x1c($v1)
/* 0DB914 80145214 E4620020 */  swc1  $f2, 0x20($v1)
/* 0DB918 80145218 E4640024 */  swc1  $f4, 0x24($v1)
.L8014521C:
/* 0DB91C 8014521C 03E00008 */  jr    $ra
/* 0DB920 80145220 00000000 */   nop   

