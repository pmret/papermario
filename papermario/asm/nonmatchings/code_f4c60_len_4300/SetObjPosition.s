.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetObjPosition
/* 0F8090 802D36E0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F8094 802D36E4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F8098 802D36E8 0080902D */  daddu $s2, $a0, $zero
/* 0F809C 802D36EC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F80A0 802D36F0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F80A4 802D36F4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F80A8 802D36F8 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F80AC 802D36FC F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F80B0 802D3700 8E50000C */  lw    $s0, 0xc($s2)
/* 0F80B4 802D3704 8E050000 */  lw    $a1, ($s0)
/* 0F80B8 802D3708 0C0B1EAF */  jal   get_variable
/* 0F80BC 802D370C 26100004 */   addiu $s0, $s0, 4
/* 0F80C0 802D3710 8E050000 */  lw    $a1, ($s0)
/* 0F80C4 802D3714 26100004 */  addiu $s0, $s0, 4
/* 0F80C8 802D3718 0240202D */  daddu $a0, $s2, $zero
/* 0F80CC 802D371C 0C0B210B */  jal   get_float_variable
/* 0F80D0 802D3720 0040882D */   daddu $s1, $v0, $zero
/* 0F80D4 802D3724 8E050000 */  lw    $a1, ($s0)
/* 0F80D8 802D3728 26100004 */  addiu $s0, $s0, 4
/* 0F80DC 802D372C 0240202D */  daddu $a0, $s2, $zero
/* 0F80E0 802D3730 0C0B210B */  jal   get_float_variable
/* 0F80E4 802D3734 46000586 */   mov.s $f22, $f0
/* 0F80E8 802D3738 0240202D */  daddu $a0, $s2, $zero
/* 0F80EC 802D373C 8E050000 */  lw    $a1, ($s0)
/* 0F80F0 802D3740 0C0B210B */  jal   get_float_variable
/* 0F80F4 802D3744 46000506 */   mov.s $f20, $f0
/* 0F80F8 802D3748 3C02802E */  lui   $v0, 0x802e
/* 0F80FC 802D374C 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F8100 802D3750 00118880 */  sll   $s1, $s1, 2
/* 0F8104 802D3754 02228821 */  addu  $s1, $s1, $v0
/* 0F8108 802D3758 8E230000 */  lw    $v1, ($s1)
/* 0F810C 802D375C E4760004 */  swc1  $f22, 4($v1)
/* 0F8110 802D3760 E4740008 */  swc1  $f20, 8($v1)
/* 0F8114 802D3764 E460000C */  swc1  $f0, 0xc($v1)
/* 0F8118 802D3768 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F811C 802D376C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F8120 802D3770 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8124 802D3774 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8128 802D3778 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F812C 802D377C D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F8130 802D3780 24020002 */  addiu $v0, $zero, 2
/* 0F8134 802D3784 03E00008 */  jr    $ra
/* 0F8138 802D3788 27BD0030 */   addiu $sp, $sp, 0x30

/* 0F813C 802D378C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F8140 802D3790 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F8144 802D3794 0080902D */  daddu $s2, $a0, $zero
/* 0F8148 802D3798 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F814C 802D379C AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F8150 802D37A0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8154 802D37A4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8158 802D37A8 8E50000C */  lw    $s0, 0xc($s2)
/* 0F815C 802D37AC 8E050000 */  lw    $a1, ($s0)
/* 0F8160 802D37B0 0C0B1EAF */  jal   get_variable
/* 0F8164 802D37B4 26100004 */   addiu $s0, $s0, 4
/* 0F8168 802D37B8 8E050000 */  lw    $a1, ($s0)
/* 0F816C 802D37BC 26100004 */  addiu $s0, $s0, 4
/* 0F8170 802D37C0 00021080 */  sll   $v0, $v0, 2
/* 0F8174 802D37C4 3C03802E */  lui   $v1, 0x802e
/* 0F8178 802D37C8 8C63B7C0 */  lw    $v1, -0x4840($v1)
/* 0F817C 802D37CC 00431021 */  addu  $v0, $v0, $v1
/* 0F8180 802D37D0 8C510000 */  lw    $s1, ($v0)
/* 0F8184 802D37D4 8E130000 */  lw    $s3, ($s0)
/* 0F8188 802D37D8 C6200004 */  lwc1  $f0, 4($s1)
/* 0F818C 802D37DC 8E100004 */  lw    $s0, 4($s0)
/* 0F8190 802D37E0 4600008D */  trunc.w.s $f2, $f0
/* 0F8194 802D37E4 44061000 */  mfc1  $a2, $f2
/* 0F8198 802D37E8 0C0B2026 */  jal   set_variable
/* 0F819C 802D37EC 0240202D */   daddu $a0, $s2, $zero
/* 0F81A0 802D37F0 0240202D */  daddu $a0, $s2, $zero
/* 0F81A4 802D37F4 C6200008 */  lwc1  $f0, 8($s1)
/* 0F81A8 802D37F8 4600008D */  trunc.w.s $f2, $f0
/* 0F81AC 802D37FC 44061000 */  mfc1  $a2, $f2
/* 0F81B0 802D3800 0C0B2026 */  jal   set_variable
/* 0F81B4 802D3804 0260282D */   daddu $a1, $s3, $zero
/* 0F81B8 802D3808 0240202D */  daddu $a0, $s2, $zero
/* 0F81BC 802D380C C620000C */  lwc1  $f0, 0xc($s1)
/* 0F81C0 802D3810 4600008D */  trunc.w.s $f2, $f0
/* 0F81C4 802D3814 44061000 */  mfc1  $a2, $f2
/* 0F81C8 802D3818 0C0B2026 */  jal   set_variable
/* 0F81CC 802D381C 0200282D */   daddu $a1, $s0, $zero
/* 0F81D0 802D3820 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F81D4 802D3824 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F81D8 802D3828 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F81DC 802D382C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F81E0 802D3830 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F81E4 802D3834 24020002 */  addiu $v0, $zero, 2
/* 0F81E8 802D3838 03E00008 */  jr    $ra
/* 0F81EC 802D383C 27BD0028 */   addiu $sp, $sp, 0x28

