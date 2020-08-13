.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8003AC5C
/* 01605C 8003AC5C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 016060 8003AC60 AFB00010 */  sw    $s0, 0x10($sp)
/* 016064 8003AC64 0080802D */  daddu $s0, $a0, $zero
/* 016068 8003AC68 AFB10014 */  sw    $s1, 0x14($sp)
/* 01606C 8003AC6C 00A0882D */  daddu $s1, $a1, $zero
/* 016070 8003AC70 AFB20018 */  sw    $s2, 0x18($sp)
/* 016074 8003AC74 AFBF001C */  sw    $ra, 0x1c($sp)
/* 016078 8003AC78 8E020000 */  lw    $v0, ($s0)
/* 01607C 8003AC7C 3C030100 */  lui   $v1, 0x100
/* 016080 8003AC80 00431024 */  and   $v0, $v0, $v1
/* 016084 8003AC84 14400008 */  bnez  $v0, .L8003ACA8
/* 016088 8003AC88 00C0902D */   daddu $s2, $a2, $zero
/* 01608C 8003AC8C 8E040024 */  lw    $a0, 0x24($s0)
/* 016090 8003AC90 0C0B797A */  jal   func_802DE5E8
/* 016094 8003AC94 00000000 */   nop   
/* 016098 8003AC98 10400003 */  beqz  $v0, .L8003ACA8
/* 01609C 8003AC9C 00000000 */   nop   
.L8003ACA0:
/* 0160A0 8003ACA0 0800EB28 */  j     .L8003ACA0
/* 0160A4 8003ACA4 00000000 */   nop   

.L8003ACA8:
/* 0160A8 8003ACA8 8E020000 */  lw    $v0, ($s0)
/* 0160AC 8003ACAC 3C030100 */  lui   $v1, 0x100
/* 0160B0 8003ACB0 00431024 */  and   $v0, $v0, $v1
/* 0160B4 8003ACB4 14400008 */  bnez  $v0, .L8003ACD8
/* 0160B8 8003ACB8 AE1200B0 */   sw    $s2, 0xb0($s0)
/* 0160BC 8003ACBC 0220202D */  daddu $a0, $s1, $zero
/* 0160C0 8003ACC0 0C0B783B */  jal   func_802DE0EC
/* 0160C4 8003ACC4 0240282D */   daddu $a1, $s2, $zero
/* 0160C8 8003ACC8 04410003 */  bgez  $v0, .L8003ACD8
/* 0160CC 8003ACCC AE020024 */   sw    $v0, 0x24($s0)
.L8003ACD0:
/* 0160D0 8003ACD0 0800EB34 */  j     .L8003ACD0
/* 0160D4 8003ACD4 00000000 */   nop   

.L8003ACD8:
/* 0160D8 8003ACD8 8E030000 */  lw    $v1, ($s0)
/* 0160DC 8003ACDC 3C024000 */  lui   $v0, 0x4000
/* 0160E0 8003ACE0 00621024 */  and   $v0, $v1, $v0
/* 0160E4 8003ACE4 14400009 */  bnez  $v0, .L8003AD0C
/* 0160E8 8003ACE8 AE110028 */   sw    $s1, 0x28($s0)
/* 0160EC 8003ACEC 3C020100 */  lui   $v0, 0x100
/* 0160F0 8003ACF0 00621024 */  and   $v0, $v1, $v0
/* 0160F4 8003ACF4 14400005 */  bnez  $v0, .L8003AD0C
/* 0160F8 8003ACF8 00000000 */   nop   
/* 0160FC 8003ACFC 8E040024 */  lw    $a0, 0x24($s0)
/* 016100 8003AD00 8E060030 */  lw    $a2, 0x30($s0)
/* 016104 8003AD04 0C0B78AB */  jal   func_802DE2AC
/* 016108 8003AD08 0220282D */   daddu $a1, $s1, $zero
.L8003AD0C:
/* 01610C 8003AD0C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 016110 8003AD10 8FB20018 */  lw    $s2, 0x18($sp)
/* 016114 8003AD14 8FB10014 */  lw    $s1, 0x14($sp)
/* 016118 8003AD18 8FB00010 */  lw    $s0, 0x10($sp)
/* 01611C 8003AD1C 03E00008 */  jr    $ra
/* 016120 8003AD20 27BD0020 */   addiu $sp, $sp, 0x20

