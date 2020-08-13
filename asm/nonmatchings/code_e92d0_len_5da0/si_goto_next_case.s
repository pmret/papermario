.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_goto_next_case
/* 0ED410 802C8A60 24050001 */  addiu $a1, $zero, 1
/* 0ED414 802C8A64 8C860008 */  lw    $a2, 8($a0)
/* 0ED418 802C8A68 3C08802E */  lui   $t0, 0x802e
/* 0ED41C 802C8A6C 2508A140 */  addiu $t0, $t0, -0x5ec0
/* 0ED420 802C8A70 00A0382D */  daddu $a3, $a1, $zero
.L802C8A74:
/* 0ED424 802C8A74 00C0202D */  daddu $a0, $a2, $zero
.L802C8A78:
/* 0ED428 802C8A78 24860008 */  addiu $a2, $a0, 8
/* 0ED42C 802C8A7C 8C820004 */  lw    $v0, 4($a0)
/* 0ED430 802C8A80 8C830000 */  lw    $v1, ($a0)
/* 0ED434 802C8A84 00021080 */  sll   $v0, $v0, 2
/* 0ED438 802C8A88 00C23021 */  addu  $a2, $a2, $v0
/* 0ED43C 802C8A8C 2463FFFF */  addiu $v1, $v1, -1
/* 0ED440 802C8A90 2C620023 */  sltiu $v0, $v1, 0x23
/* 0ED444 802C8A94 5040FFF8 */  beql  $v0, $zero, .L802C8A78
/* 0ED448 802C8A98 00C0202D */   daddu $a0, $a2, $zero
/* 0ED44C 802C8A9C 00031080 */  sll   $v0, $v1, 2
/* 0ED450 802C8AA0 00481021 */  addu  $v0, $v0, $t0
/* 0ED454 802C8AA4 8C420000 */  lw    $v0, ($v0)
/* 0ED458 802C8AA8 00400008 */  jr    $v0
/* 0ED45C 802C8AAC 00000000 */   nop   
.L802C8AB0:
/* 0ED460 802C8AB0 080B22AC */  j     .L802C8AB0
/* 0ED464 802C8AB4 00000000 */   nop   

/* 0ED468 802C8AB8 080B229D */  j     .L802C8A74
/* 0ED46C 802C8ABC 24A50001 */   addiu $a1, $a1, 1

/* 0ED470 802C8AC0 24A5FFFF */  addiu $a1, $a1, -1
/* 0ED474 802C8AC4 54A0FFEC */  bnel  $a1, $zero, .L802C8A78
/* 0ED478 802C8AC8 00C0202D */   daddu $a0, $a2, $zero
/* 0ED47C 802C8ACC 03E00008 */  jr    $ra
/* 0ED480 802C8AD0 0080102D */   daddu $v0, $a0, $zero

/* 0ED484 802C8AD4 54A7FFE8 */  bnel  $a1, $a3, .L802C8A78
/* 0ED488 802C8AD8 00C0202D */   daddu $a0, $a2, $zero
/* 0ED48C 802C8ADC 03E00008 */  jr    $ra
/* 0ED490 802C8AE0 0080102D */   daddu $v0, $a0, $zero

