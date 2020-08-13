.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_skip_else
/* 0ED328 802C8978 0000282D */  daddu $a1, $zero, $zero
/* 0ED32C 802C897C 8C840008 */  lw    $a0, 8($a0)
/* 0ED330 802C8980 3C06802E */  lui   $a2, 0x802e
/* 0ED334 802C8984 24C6A0F0 */  addiu $a2, $a2, -0x5f10
.L802C8988:
/* 0ED338 802C8988 8C820000 */  lw    $v0, ($a0)
/* 0ED33C 802C898C 24840004 */  addiu $a0, $a0, 4
/* 0ED340 802C8990 8C830000 */  lw    $v1, ($a0)
/* 0ED344 802C8994 24840004 */  addiu $a0, $a0, 4
/* 0ED348 802C8998 00031880 */  sll   $v1, $v1, 2
/* 0ED34C 802C899C 00832021 */  addu  $a0, $a0, $v1
/* 0ED350 802C89A0 2443FFFF */  addiu $v1, $v0, -1
/* 0ED354 802C89A4 2C620013 */  sltiu $v0, $v1, 0x13
/* 0ED358 802C89A8 1040FFF7 */  beqz  $v0, .L802C8988
/* 0ED35C 802C89AC 00031080 */   sll   $v0, $v1, 2
/* 0ED360 802C89B0 00461021 */  addu  $v0, $v0, $a2
/* 0ED364 802C89B4 8C420000 */  lw    $v0, ($v0)
/* 0ED368 802C89B8 00400008 */  jr    $v0
/* 0ED36C 802C89BC 00000000 */   nop   
.L802C89C0:
/* 0ED370 802C89C0 080B2270 */  j     .L802C89C0
/* 0ED374 802C89C4 00000000 */   nop   

/* 0ED378 802C89C8 24A5FFFF */  addiu $a1, $a1, -1
/* 0ED37C 802C89CC 04A1FFEE */  bgez  $a1, .L802C8988
/* 0ED380 802C89D0 0080102D */   daddu $v0, $a0, $zero
/* 0ED384 802C89D4 03E00008 */  jr    $ra
/* 0ED388 802C89D8 00000000 */   nop   

/* 0ED38C 802C89DC 080B2262 */  j     .L802C8988
/* 0ED390 802C89E0 24A50001 */   addiu $a1, $a1, 1

