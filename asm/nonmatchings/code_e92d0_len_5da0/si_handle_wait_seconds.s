.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_wait_seconds
/* 0E9568 802C4BB8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E956C 802C4BBC AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9570 802C4BC0 0080802D */  daddu $s0, $a0, $zero
/* 0E9574 802C4BC4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E9578 802C4BC8 82020005 */  lb    $v0, 5($s0)
/* 0E957C 802C4BCC 14400011 */  bnez  $v0, .L802C4C14
/* 0E9580 802C4BD0 8E05000C */   lw    $a1, 0xc($s0)
/* 0E9584 802C4BD4 0C0B210B */  jal   get_float_variable
/* 0E9588 802C4BD8 8CA50000 */   lw    $a1, ($a1)
/* 0E958C 802C4BDC 3C0141F0 */  lui   $at, 0x41f0
/* 0E9590 802C4BE0 44811000 */  mtc1  $at, $f2
/* 0E9594 802C4BE4 00000000 */  nop   
/* 0E9598 802C4BE8 46020002 */  mul.s $f0, $f0, $f2
/* 0E959C 802C4BEC 00000000 */  nop   
/* 0E95A0 802C4BF0 3C013FE0 */  lui   $at, 0x3fe0
/* 0E95A4 802C4BF4 44811800 */  mtc1  $at, $f3
/* 0E95A8 802C4BF8 44801000 */  mtc1  $zero, $f2
/* 0E95AC 802C4BFC 46000021 */  cvt.d.s $f0, $f0
/* 0E95B0 802C4C00 46220000 */  add.d $f0, $f0, $f2
/* 0E95B4 802C4C04 24020001 */  addiu $v0, $zero, 1
/* 0E95B8 802C4C08 A2020005 */  sb    $v0, 5($s0)
/* 0E95BC 802C4C0C 4620010D */  trunc.w.d $f4, $f0
/* 0E95C0 802C4C10 E6040070 */  swc1  $f4, 0x70($s0)
.L802C4C14:
/* 0E95C4 802C4C14 8E020070 */  lw    $v0, 0x70($s0)
/* 0E95C8 802C4C18 10400004 */  beqz  $v0, .L802C4C2C
/* 0E95CC 802C4C1C 2442FFFF */   addiu $v0, $v0, -1
/* 0E95D0 802C4C20 AE020070 */  sw    $v0, 0x70($s0)
/* 0E95D4 802C4C24 080B130C */  j     .L802C4C30
/* 0E95D8 802C4C28 2C420001 */   sltiu $v0, $v0, 1

.L802C4C2C:
/* 0E95DC 802C4C2C 24020002 */  addiu $v0, $zero, 2
.L802C4C30:
/* 0E95E0 802C4C30 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E95E4 802C4C34 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E95E8 802C4C38 03E00008 */  jr    $ra
/* 0E95EC 802C4C3C 27BD0018 */   addiu $sp, $sp, 0x18

