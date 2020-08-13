.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel WaitForCam
/* 0F0D04 802CC354 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F0D08 802CC358 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F0D0C 802CC35C 0080802D */  daddu $s0, $a0, $zero
/* 0F0D10 802CC360 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F0D14 802CC364 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F0D18 802CC368 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F0D1C 802CC36C 8E11000C */  lw    $s1, 0xc($s0)
/* 0F0D20 802CC370 00A0902D */  daddu $s2, $a1, $zero
/* 0F0D24 802CC374 0C0B1EAF */  jal   get_variable
/* 0F0D28 802CC378 8E250000 */   lw    $a1, ($s1)
/* 0F0D2C 802CC37C 0200202D */  daddu $a0, $s0, $zero
/* 0F0D30 802CC380 8E250004 */  lw    $a1, 4($s1)
/* 0F0D34 802CC384 0C0B210B */  jal   get_float_variable
/* 0F0D38 802CC388 0040802D */   daddu $s0, $v0, $zero
/* 0F0D3C 802CC38C 46000086 */  mov.s $f2, $f0
/* 0F0D40 802CC390 3C04800B */  lui   $a0, 0x800b
/* 0F0D44 802CC394 24841D80 */  addiu $a0, $a0, 0x1d80
/* 0F0D48 802CC398 00101080 */  sll   $v0, $s0, 2
/* 0F0D4C 802CC39C 00501021 */  addu  $v0, $v0, $s0
/* 0F0D50 802CC3A0 00021080 */  sll   $v0, $v0, 2
/* 0F0D54 802CC3A4 00501023 */  subu  $v0, $v0, $s0
/* 0F0D58 802CC3A8 000218C0 */  sll   $v1, $v0, 3
/* 0F0D5C 802CC3AC 00431021 */  addu  $v0, $v0, $v1
/* 0F0D60 802CC3B0 000210C0 */  sll   $v0, $v0, 3
/* 0F0D64 802CC3B4 16400006 */  bnez  $s2, .L802CC3D0
/* 0F0D68 802CC3B8 00441021 */   addu  $v0, $v0, $a0
/* 0F0D6C 802CC3BC C4400484 */  lwc1  $f0, 0x484($v0)
/* 0F0D70 802CC3C0 4600103E */  c.le.s $f2, $f0
/* 0F0D74 802CC3C4 00000000 */  nop   
/* 0F0D78 802CC3C8 45010002 */  bc1t  .L802CC3D4
/* 0F0D7C 802CC3CC 24020002 */   addiu $v0, $zero, 2
.L802CC3D0:
/* 0F0D80 802CC3D0 0000102D */  daddu $v0, $zero, $zero
.L802CC3D4:
/* 0F0D84 802CC3D4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F0D88 802CC3D8 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F0D8C 802CC3DC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0D90 802CC3E0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0D94 802CC3E4 03E00008 */  jr    $ra
/* 0F0D98 802CC3E8 27BD0020 */   addiu $sp, $sp, 0x20

