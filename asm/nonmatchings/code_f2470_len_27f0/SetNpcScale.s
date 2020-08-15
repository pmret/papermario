.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetNpcScale
/* 0F2884 802CDED4 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F2888 802CDED8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F288C 802CDEDC 0080882D */  daddu $s1, $a0, $zero
/* 0F2890 802CDEE0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F2894 802CDEE4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F2898 802CDEE8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F289C 802CDEEC F7B80030 */  sdc1  $f24, 0x30($sp)
/* 0F28A0 802CDEF0 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F28A4 802CDEF4 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F28A8 802CDEF8 8E30000C */  lw    $s0, 0xc($s1)
/* 0F28AC 802CDEFC 8E050000 */  lw    $a1, ($s0)
/* 0F28B0 802CDF00 0C0B1EAF */  jal   get_variable
/* 0F28B4 802CDF04 26100004 */   addiu $s0, $s0, 4
/* 0F28B8 802CDF08 8E050000 */  lw    $a1, ($s0)
/* 0F28BC 802CDF0C 26100004 */  addiu $s0, $s0, 4
/* 0F28C0 802CDF10 0220202D */  daddu $a0, $s1, $zero
/* 0F28C4 802CDF14 0C0B210B */  jal   get_float_variable
/* 0F28C8 802CDF18 0040902D */   daddu $s2, $v0, $zero
/* 0F28CC 802CDF1C 8E050000 */  lw    $a1, ($s0)
/* 0F28D0 802CDF20 26100004 */  addiu $s0, $s0, 4
/* 0F28D4 802CDF24 0220202D */  daddu $a0, $s1, $zero
/* 0F28D8 802CDF28 0C0B210B */  jal   get_float_variable
/* 0F28DC 802CDF2C 46000606 */   mov.s $f24, $f0
/* 0F28E0 802CDF30 0220202D */  daddu $a0, $s1, $zero
/* 0F28E4 802CDF34 8E050000 */  lw    $a1, ($s0)
/* 0F28E8 802CDF38 0C0B210B */  jal   get_float_variable
/* 0F28EC 802CDF3C 46000586 */   mov.s $f22, $f0
/* 0F28F0 802CDF40 0220202D */  daddu $a0, $s1, $zero
/* 0F28F4 802CDF44 0240282D */  daddu $a1, $s2, $zero
/* 0F28F8 802CDF48 0C0B36B0 */  jal   resolve_npc
/* 0F28FC 802CDF4C 46000506 */   mov.s $f20, $f0
/* 0F2900 802CDF50 0040182D */  daddu $v1, $v0, $zero
/* 0F2904 802CDF54 10600004 */  beqz  $v1, .L802CDF68
/* 0F2908 802CDF58 24020002 */   addiu $v0, $zero, 2
/* 0F290C 802CDF5C E4780054 */  swc1  $f24, 0x54($v1)
/* 0F2910 802CDF60 E4760058 */  swc1  $f22, 0x58($v1)
/* 0F2914 802CDF64 E474005C */  swc1  $f20, 0x5c($v1)
.L802CDF68:
/* 0F2918 802CDF68 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F291C 802CDF6C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F2920 802CDF70 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2924 802CDF74 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2928 802CDF78 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 0F292C 802CDF7C D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F2930 802CDF80 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F2934 802CDF84 03E00008 */  jr    $ra
/* 0F2938 802CDF88 27BD0038 */   addiu $sp, $sp, 0x38

