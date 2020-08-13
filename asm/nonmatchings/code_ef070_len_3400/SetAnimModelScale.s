.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetAnimModelScale
/* 0F1C4C 802CD29C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F1C50 802CD2A0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F1C54 802CD2A4 0080902D */  daddu $s2, $a0, $zero
/* 0F1C58 802CD2A8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F1C5C 802CD2AC AFB10014 */  sw    $s1, 0x14($sp)
/* 0F1C60 802CD2B0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F1C64 802CD2B4 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F1C68 802CD2B8 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F1C6C 802CD2BC 8E50000C */  lw    $s0, 0xc($s2)
/* 0F1C70 802CD2C0 8E050000 */  lw    $a1, ($s0)
/* 0F1C74 802CD2C4 0C0B1EAF */  jal   get_variable
/* 0F1C78 802CD2C8 26100004 */   addiu $s0, $s0, 4
/* 0F1C7C 802CD2CC 8E050000 */  lw    $a1, ($s0)
/* 0F1C80 802CD2D0 26100004 */  addiu $s0, $s0, 4
/* 0F1C84 802CD2D4 0240202D */  daddu $a0, $s2, $zero
/* 0F1C88 802CD2D8 0C0B210B */  jal   get_float_variable
/* 0F1C8C 802CD2DC 0040882D */   daddu $s1, $v0, $zero
/* 0F1C90 802CD2E0 8E050000 */  lw    $a1, ($s0)
/* 0F1C94 802CD2E4 26100004 */  addiu $s0, $s0, 4
/* 0F1C98 802CD2E8 0240202D */  daddu $a0, $s2, $zero
/* 0F1C9C 802CD2EC 0C0B210B */  jal   get_float_variable
/* 0F1CA0 802CD2F0 46000586 */   mov.s $f22, $f0
/* 0F1CA4 802CD2F4 0240202D */  daddu $a0, $s2, $zero
/* 0F1CA8 802CD2F8 8E050000 */  lw    $a1, ($s0)
/* 0F1CAC 802CD2FC 0C0B210B */  jal   get_float_variable
/* 0F1CB0 802CD300 46000506 */   mov.s $f20, $f0
/* 0F1CB4 802CD304 3C02802E */  lui   $v0, 0x802e
/* 0F1CB8 802CD308 8C42AE30 */  lw    $v0, -0x51d0($v0)
/* 0F1CBC 802CD30C 00118880 */  sll   $s1, $s1, 2
/* 0F1CC0 802CD310 02228821 */  addu  $s1, $s1, $v0
/* 0F1CC4 802CD314 8E230000 */  lw    $v1, ($s1)
/* 0F1CC8 802CD318 E476001C */  swc1  $f22, 0x1c($v1)
/* 0F1CCC 802CD31C E4740020 */  swc1  $f20, 0x20($v1)
/* 0F1CD0 802CD320 E4600024 */  swc1  $f0, 0x24($v1)
/* 0F1CD4 802CD324 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F1CD8 802CD328 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F1CDC 802CD32C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F1CE0 802CD330 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F1CE4 802CD334 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F1CE8 802CD338 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F1CEC 802CD33C 24020002 */  addiu $v0, $zero, 2
/* 0F1CF0 802CD340 03E00008 */  jr    $ra
/* 0F1CF4 802CD344 27BD0030 */   addiu $sp, $sp, 0x30

/* 0F1CF8 802CD348 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F1CFC 802CD34C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F1D00 802CD350 0080882D */  daddu $s1, $a0, $zero
/* 0F1D04 802CD354 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F1D08 802CD358 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F1D0C 802CD35C 8E30000C */  lw    $s0, 0xc($s1)
/* 0F1D10 802CD360 8E050000 */  lw    $a1, ($s0)
/* 0F1D14 802CD364 0C0B1EAF */  jal   get_variable
/* 0F1D18 802CD368 26100004 */   addiu $s0, $s0, 4
/* 0F1D1C 802CD36C 0220202D */  daddu $a0, $s1, $zero
/* 0F1D20 802CD370 8E050000 */  lw    $a1, ($s0)
/* 0F1D24 802CD374 0C0B210B */  jal   get_float_variable
/* 0F1D28 802CD378 0040802D */   daddu $s0, $v0, $zero
/* 0F1D2C 802CD37C 3C02802E */  lui   $v0, 0x802e
/* 0F1D30 802CD380 8C42AE30 */  lw    $v0, -0x51d0($v0)
/* 0F1D34 802CD384 00108080 */  sll   $s0, $s0, 2
/* 0F1D38 802CD388 02028021 */  addu  $s0, $s0, $v0
/* 0F1D3C 802CD38C 8E020000 */  lw    $v0, ($s0)
/* 0F1D40 802CD390 8C440000 */  lw    $a0, ($v0)
/* 0F1D44 802CD394 4600008D */  trunc.w.s $f2, $f0
/* 0F1D48 802CD398 44101000 */  mfc1  $s0, $f2
/* 0F1D4C 802CD39C 0C047FF8 */  jal   func_8011FFE0
/* 0F1D50 802CD3A0 00000000 */   nop   
/* 0F1D54 802CD3A4 A0500004 */  sb    $s0, 4($v0)
/* 0F1D58 802CD3A8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F1D5C 802CD3AC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F1D60 802CD3B0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F1D64 802CD3B4 24020002 */  addiu $v0, $zero, 2
/* 0F1D68 802CD3B8 03E00008 */  jr    $ra
/* 0F1D6C 802CD3BC 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F1D70 802CD3C0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1D74 802CD3C4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1D78 802CD3C8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F1D7C 802CD3CC 8C82000C */  lw    $v0, 0xc($a0)
/* 0F1D80 802CD3D0 0C0B1EAF */  jal   get_variable
/* 0F1D84 802CD3D4 8C450000 */   lw    $a1, ($v0)
/* 0F1D88 802CD3D8 3C03802E */  lui   $v1, 0x802e
/* 0F1D8C 802CD3DC 8C63AE30 */  lw    $v1, -0x51d0($v1)
/* 0F1D90 802CD3E0 00021080 */  sll   $v0, $v0, 2
/* 0F1D94 802CD3E4 00431021 */  addu  $v0, $v0, $v1
/* 0F1D98 802CD3E8 8C500000 */  lw    $s0, ($v0)
/* 0F1D9C 802CD3EC 0C047FF8 */  jal   func_8011FFE0
/* 0F1DA0 802CD3F0 8E040000 */   lw    $a0, ($s0)
/* 0F1DA4 802CD3F4 0C04790E */  jal   func_8011E438
/* 0F1DA8 802CD3F8 0040202D */   daddu $a0, $v0, $zero
/* 0F1DAC 802CD3FC 2403FFFF */  addiu $v1, $zero, -1
/* 0F1DB0 802CD400 AE030000 */  sw    $v1, ($s0)
/* 0F1DB4 802CD404 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1DB8 802CD408 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F1DBC 802CD40C 24020002 */  addiu $v0, $zero, 2
/* 0F1DC0 802CD410 03E00008 */  jr    $ra
/* 0F1DC4 802CD414 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F1DC8 802CD418 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F1DCC 802CD41C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F1DD0 802CD420 0080882D */  daddu $s1, $a0, $zero
/* 0F1DD4 802CD424 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F1DD8 802CD428 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F1DDC 802CD42C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F1DE0 802CD430 8E30000C */  lw    $s0, 0xc($s1)
/* 0F1DE4 802CD434 8E050000 */  lw    $a1, ($s0)
/* 0F1DE8 802CD438 0C0B1EAF */  jal   get_variable
/* 0F1DEC 802CD43C 26100004 */   addiu $s0, $s0, 4
/* 0F1DF0 802CD440 0220202D */  daddu $a0, $s1, $zero
/* 0F1DF4 802CD444 8E050004 */  lw    $a1, 4($s0)
/* 0F1DF8 802CD448 8E120000 */  lw    $s2, ($s0)
/* 0F1DFC 802CD44C 0C0B1EAF */  jal   get_variable
/* 0F1E00 802CD450 0040882D */   daddu $s1, $v0, $zero
/* 0F1E04 802CD454 3C03802E */  lui   $v1, 0x802e
/* 0F1E08 802CD458 8C63AE30 */  lw    $v1, -0x51d0($v1)
/* 0F1E0C 802CD45C 00118880 */  sll   $s1, $s1, 2
/* 0F1E10 802CD460 02238821 */  addu  $s1, $s1, $v1
/* 0F1E14 802CD464 8E230000 */  lw    $v1, ($s1)
/* 0F1E18 802CD468 8C640000 */  lw    $a0, ($v1)
/* 0F1E1C 802CD46C 0C047FF8 */  jal   func_8011FFE0
/* 0F1E20 802CD470 0040802D */   daddu $s0, $v0, $zero
/* 0F1E24 802CD474 12000004 */  beqz  $s0, .L802CD488
/* 0F1E28 802CD478 0040202D */   daddu $a0, $v0, $zero
/* 0F1E2C 802CD47C 8C820000 */  lw    $v0, ($a0)
/* 0F1E30 802CD480 080B3525 */  j     .L802CD494
/* 0F1E34 802CD484 00521025 */   or    $v0, $v0, $s2

.L802CD488:
/* 0F1E38 802CD488 8C820000 */  lw    $v0, ($a0)
/* 0F1E3C 802CD48C 00121827 */  nor   $v1, $zero, $s2
/* 0F1E40 802CD490 00431024 */  and   $v0, $v0, $v1
.L802CD494:
/* 0F1E44 802CD494 AC820000 */  sw    $v0, ($a0)
/* 0F1E48 802CD498 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F1E4C 802CD49C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F1E50 802CD4A0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F1E54 802CD4A4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F1E58 802CD4A8 24020002 */  addiu $v0, $zero, 2
/* 0F1E5C 802CD4AC 03E00008 */  jr    $ra
/* 0F1E60 802CD4B0 27BD0020 */   addiu $sp, $sp, 0x20

