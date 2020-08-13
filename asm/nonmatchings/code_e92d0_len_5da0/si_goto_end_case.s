.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_goto_end_case
/* 0ED394 802C89E4 24050001 */  addiu $a1, $zero, 1
/* 0ED398 802C89E8 8C860008 */  lw    $a2, 8($a0)
/* 0ED39C 802C89EC 24090014 */  addiu $t1, $zero, 0x14
/* 0ED3A0 802C89F0 00A0402D */  daddu $t0, $a1, $zero
/* 0ED3A4 802C89F4 24070023 */  addiu $a3, $zero, 0x23
.L802C89F8:
/* 0ED3A8 802C89F8 00C0202D */  daddu $a0, $a2, $zero
.L802C89FC:
/* 0ED3AC 802C89FC 24860008 */  addiu $a2, $a0, 8
.L802C8A00:
/* 0ED3B0 802C8A00 8C820004 */  lw    $v0, 4($a0)
/* 0ED3B4 802C8A04 8C830000 */  lw    $v1, ($a0)
/* 0ED3B8 802C8A08 00021080 */  sll   $v0, $v0, 2
/* 0ED3BC 802C8A0C 1069000E */  beq   $v1, $t1, .L802C8A48
/* 0ED3C0 802C8A10 00C23021 */   addu  $a2, $a2, $v0
/* 0ED3C4 802C8A14 28620015 */  slti  $v0, $v1, 0x15
/* 0ED3C8 802C8A18 10400005 */  beqz  $v0, .L802C8A30
/* 0ED3CC 802C8A1C 00000000 */   nop   
/* 0ED3D0 802C8A20 10680007 */  beq   $v1, $t0, .L802C8A40
/* 0ED3D4 802C8A24 00C0202D */   daddu $a0, $a2, $zero
/* 0ED3D8 802C8A28 080B2280 */  j     .L802C8A00
/* 0ED3DC 802C8A2C 24860008 */   addiu $a2, $a0, 8

.L802C8A30:
/* 0ED3E0 802C8A30 50670007 */  beql  $v1, $a3, .L802C8A50
/* 0ED3E4 802C8A34 24A5FFFF */   addiu $a1, $a1, -1
/* 0ED3E8 802C8A38 080B227F */  j     .L802C89FC
/* 0ED3EC 802C8A3C 00C0202D */   daddu $a0, $a2, $zero

.L802C8A40:
/* 0ED3F0 802C8A40 080B2290 */  j     .L802C8A40
/* 0ED3F4 802C8A44 00000000 */   nop   

.L802C8A48:
/* 0ED3F8 802C8A48 080B227E */  j     .L802C89F8
/* 0ED3FC 802C8A4C 24A50001 */   addiu $a1, $a1, 1

.L802C8A50:
/* 0ED400 802C8A50 54A0FFEA */  bnel  $a1, $zero, .L802C89FC
/* 0ED404 802C8A54 00C0202D */   daddu $a0, $a2, $zero
/* 0ED408 802C8A58 03E00008 */  jr    $ra
/* 0ED40C 802C8A5C 0080102D */   daddu $v0, $a0, $zero

