.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetNpcAnimation
/* 0F2B10 802CE160 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F2B14 802CE164 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F2B18 802CE168 0080882D */  daddu $s1, $a0, $zero
/* 0F2B1C 802CE16C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F2B20 802CE170 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F2B24 802CE174 8E30000C */  lw    $s0, 0xc($s1)
/* 0F2B28 802CE178 8E050000 */  lw    $a1, ($s0)
/* 0F2B2C 802CE17C 0C0B1EAF */  jal   get_variable
/* 0F2B30 802CE180 26100004 */   addiu $s0, $s0, 4
/* 0F2B34 802CE184 0220202D */  daddu $a0, $s1, $zero
/* 0F2B38 802CE188 8E100000 */  lw    $s0, ($s0)
/* 0F2B3C 802CE18C 0C0B36B0 */  jal   func_802CDAC0
/* 0F2B40 802CE190 0040282D */   daddu $a1, $v0, $zero
/* 0F2B44 802CE194 10400004 */  beqz  $v0, .L802CE1A8
/* 0F2B48 802CE198 0220202D */   daddu $a0, $s1, $zero
/* 0F2B4C 802CE19C 8C460028 */  lw    $a2, 0x28($v0)
/* 0F2B50 802CE1A0 0C0B2026 */  jal   set_variable
/* 0F2B54 802CE1A4 0200282D */   daddu $a1, $s0, $zero
.L802CE1A8:
/* 0F2B58 802CE1A8 24020002 */  addiu $v0, $zero, 2
/* 0F2B5C 802CE1AC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F2B60 802CE1B0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2B64 802CE1B4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2B68 802CE1B8 03E00008 */  jr    $ra
/* 0F2B6C 802CE1BC 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F2B70 802CE1C0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F2B74 802CE1C4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F2B78 802CE1C8 0080882D */  daddu $s1, $a0, $zero
/* 0F2B7C 802CE1CC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F2B80 802CE1D0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F2B84 802CE1D4 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F2B88 802CE1D8 8E30000C */  lw    $s0, 0xc($s1)
/* 0F2B8C 802CE1DC 8E050000 */  lw    $a1, ($s0)
/* 0F2B90 802CE1E0 0C0B1EAF */  jal   get_variable
/* 0F2B94 802CE1E4 26100004 */   addiu $s0, $s0, 4
/* 0F2B98 802CE1E8 0220202D */  daddu $a0, $s1, $zero
/* 0F2B9C 802CE1EC 8E050000 */  lw    $a1, ($s0)
/* 0F2BA0 802CE1F0 0C0B210B */  jal   get_float_variable
/* 0F2BA4 802CE1F4 0040802D */   daddu $s0, $v0, $zero
/* 0F2BA8 802CE1F8 0220202D */  daddu $a0, $s1, $zero
/* 0F2BAC 802CE1FC 0200282D */  daddu $a1, $s0, $zero
/* 0F2BB0 802CE200 0C0B36B0 */  jal   func_802CDAC0
/* 0F2BB4 802CE204 46000506 */   mov.s $f20, $f0
/* 0F2BB8 802CE208 54400001 */  bnel  $v0, $zero, .L802CE210
/* 0F2BBC 802CE20C E4540030 */   swc1  $f20, 0x30($v0)
.L802CE210:
/* 0F2BC0 802CE210 24020002 */  addiu $v0, $zero, 2
/* 0F2BC4 802CE214 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F2BC8 802CE218 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2BCC 802CE21C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2BD0 802CE220 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F2BD4 802CE224 03E00008 */  jr    $ra
/* 0F2BD8 802CE228 27BD0028 */   addiu $sp, $sp, 0x28

