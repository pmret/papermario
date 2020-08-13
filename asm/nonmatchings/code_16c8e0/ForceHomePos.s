.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ForceHomePos
/* 198ACC 8026A1EC 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 198AD0 8026A1F0 AFB20018 */  sw    $s2, 0x18($sp)
/* 198AD4 8026A1F4 0080902D */  daddu $s2, $a0, $zero
/* 198AD8 8026A1F8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 198ADC 8026A1FC AFB10014 */  sw    $s1, 0x14($sp)
/* 198AE0 8026A200 AFB00010 */  sw    $s0, 0x10($sp)
/* 198AE4 8026A204 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 198AE8 8026A208 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 198AEC 8026A20C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 198AF0 8026A210 8E50000C */  lw    $s0, 0xc($s2)
/* 198AF4 8026A214 8E050000 */  lw    $a1, ($s0)
/* 198AF8 8026A218 0C0B1EAF */  jal   get_variable
/* 198AFC 8026A21C 26100004 */   addiu $s0, $s0, 4
/* 198B00 8026A220 0040882D */  daddu $s1, $v0, $zero
/* 198B04 8026A224 2402FF81 */  addiu $v0, $zero, -0x7f
/* 198B08 8026A228 16220002 */  bne   $s1, $v0, .L8026A234
/* 198B0C 8026A22C 00000000 */   nop   
/* 198B10 8026A230 8E510148 */  lw    $s1, 0x148($s2)
.L8026A234:
/* 198B14 8026A234 8E050000 */  lw    $a1, ($s0)
/* 198B18 8026A238 26100004 */  addiu $s0, $s0, 4
/* 198B1C 8026A23C 0C0B1EAF */  jal   get_variable
/* 198B20 8026A240 0240202D */   daddu $a0, $s2, $zero
/* 198B24 8026A244 8E050000 */  lw    $a1, ($s0)
/* 198B28 8026A248 26100004 */  addiu $s0, $s0, 4
/* 198B2C 8026A24C 4482C000 */  mtc1  $v0, $f24
/* 198B30 8026A250 00000000 */  nop   
/* 198B34 8026A254 4680C620 */  cvt.s.w $f24, $f24
/* 198B38 8026A258 0C0B1EAF */  jal   get_variable
/* 198B3C 8026A25C 0240202D */   daddu $a0, $s2, $zero
/* 198B40 8026A260 8E050000 */  lw    $a1, ($s0)
/* 198B44 8026A264 4482B000 */  mtc1  $v0, $f22
/* 198B48 8026A268 00000000 */  nop   
/* 198B4C 8026A26C 4680B5A0 */  cvt.s.w $f22, $f22
/* 198B50 8026A270 0C0B1EAF */  jal   get_variable
/* 198B54 8026A274 0240202D */   daddu $a0, $s2, $zero
/* 198B58 8026A278 4482A000 */  mtc1  $v0, $f20
/* 198B5C 8026A27C 00000000 */  nop   
/* 198B60 8026A280 4680A520 */  cvt.s.w $f20, $f20
/* 198B64 8026A284 0C09A75B */  jal   get_actor
/* 198B68 8026A288 0220202D */   daddu $a0, $s1, $zero
/* 198B6C 8026A28C 0040182D */  daddu $v1, $v0, $zero
/* 198B70 8026A290 E4780138 */  swc1  $f24, 0x138($v1)
/* 198B74 8026A294 E4780144 */  swc1  $f24, 0x144($v1)
/* 198B78 8026A298 E476013C */  swc1  $f22, 0x13c($v1)
/* 198B7C 8026A29C E4760148 */  swc1  $f22, 0x148($v1)
/* 198B80 8026A2A0 E4740140 */  swc1  $f20, 0x140($v1)
/* 198B84 8026A2A4 E474014C */  swc1  $f20, 0x14c($v1)
/* 198B88 8026A2A8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 198B8C 8026A2AC 8FB20018 */  lw    $s2, 0x18($sp)
/* 198B90 8026A2B0 8FB10014 */  lw    $s1, 0x14($sp)
/* 198B94 8026A2B4 8FB00010 */  lw    $s0, 0x10($sp)
/* 198B98 8026A2B8 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 198B9C 8026A2BC D7B60028 */  ldc1  $f22, 0x28($sp)
/* 198BA0 8026A2C0 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 198BA4 8026A2C4 24020002 */  addiu $v0, $zero, 2
/* 198BA8 8026A2C8 03E00008 */  jr    $ra
/* 198BAC 8026A2CC 27BD0038 */   addiu $sp, $sp, 0x38

