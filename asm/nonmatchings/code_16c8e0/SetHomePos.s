.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetHomePos
/* 198BB0 8026A2D0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 198BB4 8026A2D4 AFB20018 */  sw    $s2, 0x18($sp)
/* 198BB8 8026A2D8 0080902D */  daddu $s2, $a0, $zero
/* 198BBC 8026A2DC AFBF001C */  sw    $ra, 0x1c($sp)
/* 198BC0 8026A2E0 AFB10014 */  sw    $s1, 0x14($sp)
/* 198BC4 8026A2E4 AFB00010 */  sw    $s0, 0x10($sp)
/* 198BC8 8026A2E8 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 198BCC 8026A2EC F7B60028 */  sdc1  $f22, 0x28($sp)
/* 198BD0 8026A2F0 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 198BD4 8026A2F4 8E50000C */  lw    $s0, 0xc($s2)
/* 198BD8 8026A2F8 8E050000 */  lw    $a1, ($s0)
/* 198BDC 8026A2FC 0C0B1EAF */  jal   get_variable
/* 198BE0 8026A300 26100004 */   addiu $s0, $s0, 4
/* 198BE4 8026A304 0040882D */  daddu $s1, $v0, $zero
/* 198BE8 8026A308 2402FF81 */  addiu $v0, $zero, -0x7f
/* 198BEC 8026A30C 16220002 */  bne   $s1, $v0, .L8026A318
/* 198BF0 8026A310 00000000 */   nop   
/* 198BF4 8026A314 8E510148 */  lw    $s1, 0x148($s2)
.L8026A318:
/* 198BF8 8026A318 8E050000 */  lw    $a1, ($s0)
/* 198BFC 8026A31C 26100004 */  addiu $s0, $s0, 4
/* 198C00 8026A320 0C0B1EAF */  jal   get_variable
/* 198C04 8026A324 0240202D */   daddu $a0, $s2, $zero
/* 198C08 8026A328 8E050000 */  lw    $a1, ($s0)
/* 198C0C 8026A32C 26100004 */  addiu $s0, $s0, 4
/* 198C10 8026A330 4482C000 */  mtc1  $v0, $f24
/* 198C14 8026A334 00000000 */  nop   
/* 198C18 8026A338 4680C620 */  cvt.s.w $f24, $f24
/* 198C1C 8026A33C 0C0B1EAF */  jal   get_variable
/* 198C20 8026A340 0240202D */   daddu $a0, $s2, $zero
/* 198C24 8026A344 8E050000 */  lw    $a1, ($s0)
/* 198C28 8026A348 4482B000 */  mtc1  $v0, $f22
/* 198C2C 8026A34C 00000000 */  nop   
/* 198C30 8026A350 4680B5A0 */  cvt.s.w $f22, $f22
/* 198C34 8026A354 0C0B1EAF */  jal   get_variable
/* 198C38 8026A358 0240202D */   daddu $a0, $s2, $zero
/* 198C3C 8026A35C 4482A000 */  mtc1  $v0, $f20
/* 198C40 8026A360 00000000 */  nop   
/* 198C44 8026A364 4680A520 */  cvt.s.w $f20, $f20
/* 198C48 8026A368 0C09A75B */  jal   get_actor
/* 198C4C 8026A36C 0220202D */   daddu $a0, $s1, $zero
/* 198C50 8026A370 0040182D */  daddu $v1, $v0, $zero
/* 198C54 8026A374 E4780138 */  swc1  $f24, 0x138($v1)
/* 198C58 8026A378 E476013C */  swc1  $f22, 0x13c($v1)
/* 198C5C 8026A37C E4740140 */  swc1  $f20, 0x140($v1)
/* 198C60 8026A380 8FBF001C */  lw    $ra, 0x1c($sp)
/* 198C64 8026A384 8FB20018 */  lw    $s2, 0x18($sp)
/* 198C68 8026A388 8FB10014 */  lw    $s1, 0x14($sp)
/* 198C6C 8026A38C 8FB00010 */  lw    $s0, 0x10($sp)
/* 198C70 8026A390 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 198C74 8026A394 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 198C78 8026A398 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 198C7C 8026A39C 24020002 */  addiu $v0, $zero, 2
/* 198C80 8026A3A0 03E00008 */  jr    $ra
/* 198C84 8026A3A4 27BD0038 */   addiu $sp, $sp, 0x38

