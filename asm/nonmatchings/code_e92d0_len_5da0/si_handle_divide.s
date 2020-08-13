.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_divide
/* 0EA2E4 802C5934 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA2E8 802C5938 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA2EC 802C593C 0080882D */  daddu $s1, $a0, $zero
/* 0EA2F0 802C5940 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EA2F4 802C5944 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EA2F8 802C5948 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA2FC 802C594C 8E22000C */  lw    $v0, 0xc($s1)
/* 0EA300 802C5950 8C450004 */  lw    $a1, 4($v0)
/* 0EA304 802C5954 0C0B1EAF */  jal   get_variable
/* 0EA308 802C5958 8C520000 */   lw    $s2, ($v0)
/* 0EA30C 802C595C 0220202D */  daddu $a0, $s1, $zero
/* 0EA310 802C5960 0240282D */  daddu $a1, $s2, $zero
/* 0EA314 802C5964 0C0B1EAF */  jal   get_variable
/* 0EA318 802C5968 0040802D */   daddu $s0, $v0, $zero
/* 0EA31C 802C596C 16000002 */  bnez  $s0, .L802C5978
/* 0EA320 802C5970 0050001A */   div   $zero, $v0, $s0
/* 0EA324 802C5974 0007000D */  break 7
.L802C5978:
/* 0EA328 802C5978 2401FFFF */  addiu $at, $zero, -1
/* 0EA32C 802C597C 16010004 */  bne   $s0, $at, .L802C5990
/* 0EA330 802C5980 3C018000 */   lui   $at, 0x8000
/* 0EA334 802C5984 14410002 */  bne   $v0, $at, .L802C5990
/* 0EA338 802C5988 00000000 */   nop   
/* 0EA33C 802C598C 0006000D */  break 6
.L802C5990:
/* 0EA340 802C5990 00003012 */  mflo  $a2
/* 0EA344 802C5994 0220202D */  daddu $a0, $s1, $zero
/* 0EA348 802C5998 0C0B2026 */  jal   set_variable
/* 0EA34C 802C599C 0240282D */   daddu $a1, $s2, $zero
/* 0EA350 802C59A0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EA354 802C59A4 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EA358 802C59A8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA35C 802C59AC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA360 802C59B0 24020002 */  addiu $v0, $zero, 2
/* 0EA364 802C59B4 03E00008 */  jr    $ra
/* 0EA368 802C59B8 27BD0020 */   addiu $sp, $sp, 0x20

