.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetCamPosC
/* 0F0740 802CBD90 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F0744 802CBD94 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F0748 802CBD98 0080902D */  daddu $s2, $a0, $zero
/* 0F074C 802CBD9C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F0750 802CBDA0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F0754 802CBDA4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F0758 802CBDA8 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F075C 802CBDAC 8E51000C */  lw    $s1, 0xc($s2)
/* 0F0760 802CBDB0 8E250000 */  lw    $a1, ($s1)
/* 0F0764 802CBDB4 0C0B1EAF */  jal   get_variable
/* 0F0768 802CBDB8 26310004 */   addiu $s1, $s1, 4
/* 0F076C 802CBDBC 8E250000 */  lw    $a1, ($s1)
/* 0F0770 802CBDC0 26310004 */  addiu $s1, $s1, 4
/* 0F0774 802CBDC4 0240202D */  daddu $a0, $s2, $zero
/* 0F0778 802CBDC8 3C03800B */  lui   $v1, 0x800b
/* 0F077C 802CBDCC 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F0780 802CBDD0 00028080 */  sll   $s0, $v0, 2
/* 0F0784 802CBDD4 02028021 */  addu  $s0, $s0, $v0
/* 0F0788 802CBDD8 00108080 */  sll   $s0, $s0, 2
/* 0F078C 802CBDDC 02028023 */  subu  $s0, $s0, $v0
/* 0F0790 802CBDE0 001010C0 */  sll   $v0, $s0, 3
/* 0F0794 802CBDE4 02028021 */  addu  $s0, $s0, $v0
/* 0F0798 802CBDE8 001080C0 */  sll   $s0, $s0, 3
/* 0F079C 802CBDEC 0C0B210B */  jal   get_float_variable
/* 0F07A0 802CBDF0 02038021 */   addu  $s0, $s0, $v1
/* 0F07A4 802CBDF4 0240202D */  daddu $a0, $s2, $zero
/* 0F07A8 802CBDF8 8E250000 */  lw    $a1, ($s1)
/* 0F07AC 802CBDFC 0C0B210B */  jal   get_float_variable
/* 0F07B0 802CBE00 46000506 */   mov.s $f20, $f0
/* 0F07B4 802CBE04 E61404E8 */  swc1  $f20, 0x4e8($s0)
/* 0F07B8 802CBE08 E60004F4 */  swc1  $f0, 0x4f4($s0)
/* 0F07BC 802CBE0C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F07C0 802CBE10 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F07C4 802CBE14 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F07C8 802CBE18 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F07CC 802CBE1C D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F07D0 802CBE20 24020002 */  addiu $v0, $zero, 2
/* 0F07D4 802CBE24 03E00008 */  jr    $ra
/* 0F07D8 802CBE28 27BD0028 */   addiu $sp, $sp, 0x28

