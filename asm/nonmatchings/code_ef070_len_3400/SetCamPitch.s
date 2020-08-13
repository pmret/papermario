.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetCamPitch
/* 0F04F8 802CBB48 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F04FC 802CBB4C AFB20018 */  sw    $s2, 0x18($sp)
/* 0F0500 802CBB50 0080902D */  daddu $s2, $a0, $zero
/* 0F0504 802CBB54 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F0508 802CBB58 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F050C 802CBB5C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F0510 802CBB60 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F0514 802CBB64 8E51000C */  lw    $s1, 0xc($s2)
/* 0F0518 802CBB68 8E250000 */  lw    $a1, ($s1)
/* 0F051C 802CBB6C 0C0B1EAF */  jal   get_variable
/* 0F0520 802CBB70 26310004 */   addiu $s1, $s1, 4
/* 0F0524 802CBB74 8E250000 */  lw    $a1, ($s1)
/* 0F0528 802CBB78 26310004 */  addiu $s1, $s1, 4
/* 0F052C 802CBB7C 0240202D */  daddu $a0, $s2, $zero
/* 0F0530 802CBB80 3C03800B */  lui   $v1, 0x800b
/* 0F0534 802CBB84 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F0538 802CBB88 00028080 */  sll   $s0, $v0, 2
/* 0F053C 802CBB8C 02028021 */  addu  $s0, $s0, $v0
/* 0F0540 802CBB90 00108080 */  sll   $s0, $s0, 2
/* 0F0544 802CBB94 02028023 */  subu  $s0, $s0, $v0
/* 0F0548 802CBB98 001010C0 */  sll   $v0, $s0, 3
/* 0F054C 802CBB9C 02028021 */  addu  $s0, $s0, $v0
/* 0F0550 802CBBA0 001080C0 */  sll   $s0, $s0, 3
/* 0F0554 802CBBA4 0C0B210B */  jal   get_float_variable
/* 0F0558 802CBBA8 02038021 */   addu  $s0, $s0, $v1
/* 0F055C 802CBBAC 0240202D */  daddu $a0, $s2, $zero
/* 0F0560 802CBBB0 8E250000 */  lw    $a1, ($s1)
/* 0F0564 802CBBB4 0C0B210B */  jal   get_float_variable
/* 0F0568 802CBBB8 46000506 */   mov.s $f20, $f0
/* 0F056C 802CBBBC E61404E0 */  swc1  $f20, 0x4e0($s0)
/* 0F0570 802CBBC0 E60004FC */  swc1  $f0, 0x4fc($s0)
/* 0F0574 802CBBC4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F0578 802CBBC8 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F057C 802CBBCC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0580 802CBBD0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0584 802CBBD4 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F0588 802CBBD8 24020002 */  addiu $v0, $zero, 2
/* 0F058C 802CBBDC 03E00008 */  jr    $ra
/* 0F0590 802CBBE0 27BD0028 */   addiu $sp, $sp, 0x28

