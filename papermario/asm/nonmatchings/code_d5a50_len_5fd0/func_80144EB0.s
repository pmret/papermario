.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80144EB0
/* 0DB5B0 80144EB0 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DB5B4 80144EB4 00822024 */  and   $a0, $a0, $v0
/* 0DB5B8 80144EB8 3C028015 */  lui   $v0, 0x8015
/* 0DB5BC 80144EBC 8C427960 */  lw    $v0, 0x7960($v0)
/* 0DB5C0 80144EC0 00042080 */  sll   $a0, $a0, 2
/* 0DB5C4 80144EC4 00822021 */  addu  $a0, $a0, $v0
/* 0DB5C8 80144EC8 8C840000 */  lw    $a0, ($a0)
/* 0DB5CC 80144ECC 8C820000 */  lw    $v0, ($a0)
/* 0DB5D0 80144ED0 A085004A */  sb    $a1, 0x4a($a0)
/* 0DB5D4 80144ED4 34420020 */  ori   $v0, $v0, 0x20
/* 0DB5D8 80144ED8 AC820000 */  sw    $v0, ($a0)
/* 0DB5DC 80144EDC 240200FF */  addiu $v0, $zero, 0xff
/* 0DB5E0 80144EE0 14A20004 */  bne   $a1, $v0, .L80144EF4
/* 0DB5E4 80144EE4 2403FFDF */   addiu $v1, $zero, -0x21
/* 0DB5E8 80144EE8 8C820000 */  lw    $v0, ($a0)
/* 0DB5EC 80144EEC 00431024 */  and   $v0, $v0, $v1
/* 0DB5F0 80144EF0 AC820000 */  sw    $v0, ($a0)
.L80144EF4:
/* 0DB5F4 80144EF4 03E00008 */  jr    $ra
/* 0DB5F8 80144EF8 00000000 */   nop   

