.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetPlayerPos
/* 0F67AC 802D1DFC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F67B0 802D1E00 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F67B4 802D1E04 0080802D */  daddu $s0, $a0, $zero
/* 0F67B8 802D1E08 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F67BC 802D1E0C 3C118011 */  lui   $s1, 0x8011
/* 0F67C0 802D1E10 2631EFC8 */  addiu $s1, $s1, -0x1038
/* 0F67C4 802D1E14 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F67C8 802D1E18 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F67CC 802D1E1C AFB20018 */  sw    $s2, 0x18($sp)
/* 0F67D0 802D1E20 8E02000C */  lw    $v0, 0xc($s0)
/* 0F67D4 802D1E24 C6200028 */  lwc1  $f0, 0x28($s1)
/* 0F67D8 802D1E28 8C450000 */  lw    $a1, ($v0)
/* 0F67DC 802D1E2C 24420004 */  addiu $v0, $v0, 4
/* 0F67E0 802D1E30 4600008D */  trunc.w.s $f2, $f0
/* 0F67E4 802D1E34 44061000 */  mfc1  $a2, $f2
/* 0F67E8 802D1E38 8C520000 */  lw    $s2, ($v0)
/* 0F67EC 802D1E3C 0C0B2026 */  jal   set_variable
/* 0F67F0 802D1E40 8C530004 */   lw    $s3, 4($v0)
/* 0F67F4 802D1E44 0200202D */  daddu $a0, $s0, $zero
/* 0F67F8 802D1E48 C620002C */  lwc1  $f0, 0x2c($s1)
/* 0F67FC 802D1E4C 4600008D */  trunc.w.s $f2, $f0
/* 0F6800 802D1E50 44061000 */  mfc1  $a2, $f2
/* 0F6804 802D1E54 0C0B2026 */  jal   set_variable
/* 0F6808 802D1E58 0240282D */   daddu $a1, $s2, $zero
/* 0F680C 802D1E5C 0200202D */  daddu $a0, $s0, $zero
/* 0F6810 802D1E60 C6200030 */  lwc1  $f0, 0x30($s1)
/* 0F6814 802D1E64 4600008D */  trunc.w.s $f2, $f0
/* 0F6818 802D1E68 44061000 */  mfc1  $a2, $f2
/* 0F681C 802D1E6C 0C0B2026 */  jal   set_variable
/* 0F6820 802D1E70 0260282D */   daddu $a1, $s3, $zero
/* 0F6824 802D1E74 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F6828 802D1E78 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F682C 802D1E7C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F6830 802D1E80 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F6834 802D1E84 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F6838 802D1E88 24020002 */  addiu $v0, $zero, 2
/* 0F683C 802D1E8C 03E00008 */  jr    $ra
/* 0F6840 802D1E90 27BD0028 */   addiu $sp, $sp, 0x28

