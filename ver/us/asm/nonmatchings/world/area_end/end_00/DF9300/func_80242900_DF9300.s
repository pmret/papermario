.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242900_DF9300
/* DF9300 80242900 27BDFF90 */  addiu     $sp, $sp, -0x70
/* DF9304 80242904 AFB10034 */  sw        $s1, 0x34($sp)
/* DF9308 80242908 0080882D */  daddu     $s1, $a0, $zero
/* DF930C 8024290C AFBF003C */  sw        $ra, 0x3c($sp)
/* DF9310 80242910 AFB20038 */  sw        $s2, 0x38($sp)
/* DF9314 80242914 AFB00030 */  sw        $s0, 0x30($sp)
/* DF9318 80242918 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* DF931C 8024291C F7BC0060 */  sdc1      $f28, 0x60($sp)
/* DF9320 80242920 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* DF9324 80242924 F7B80050 */  sdc1      $f24, 0x50($sp)
/* DF9328 80242928 F7B60048 */  sdc1      $f22, 0x48($sp)
/* DF932C 8024292C F7B40040 */  sdc1      $f20, 0x40($sp)
/* DF9330 80242930 8E30000C */  lw        $s0, 0xc($s1)
/* DF9334 80242934 8E050000 */  lw        $a1, ($s0)
/* DF9338 80242938 0C0B1EAF */  jal       get_variable
/* DF933C 8024293C 26100004 */   addiu    $s0, $s0, 4
/* DF9340 80242940 8E050000 */  lw        $a1, ($s0)
/* DF9344 80242944 26100004 */  addiu     $s0, $s0, 4
/* DF9348 80242948 0220202D */  daddu     $a0, $s1, $zero
/* DF934C 8024294C 0C0B210B */  jal       get_float_variable
/* DF9350 80242950 0040902D */   daddu    $s2, $v0, $zero
/* DF9354 80242954 8E050000 */  lw        $a1, ($s0)
/* DF9358 80242958 26100004 */  addiu     $s0, $s0, 4
/* DF935C 8024295C 0220202D */  daddu     $a0, $s1, $zero
/* DF9360 80242960 0C0B210B */  jal       get_float_variable
/* DF9364 80242964 46000706 */   mov.s    $f28, $f0
/* DF9368 80242968 8E050000 */  lw        $a1, ($s0)
/* DF936C 8024296C 26100004 */  addiu     $s0, $s0, 4
/* DF9370 80242970 0220202D */  daddu     $a0, $s1, $zero
/* DF9374 80242974 0C0B210B */  jal       get_float_variable
/* DF9378 80242978 46000786 */   mov.s    $f30, $f0
/* DF937C 8024297C 8E050000 */  lw        $a1, ($s0)
/* DF9380 80242980 26100004 */  addiu     $s0, $s0, 4
/* DF9384 80242984 0220202D */  daddu     $a0, $s1, $zero
/* DF9388 80242988 0C0B210B */  jal       get_float_variable
/* DF938C 8024298C 46000686 */   mov.s    $f26, $f0
/* DF9390 80242990 8E050000 */  lw        $a1, ($s0)
/* DF9394 80242994 26100004 */  addiu     $s0, $s0, 4
/* DF9398 80242998 0220202D */  daddu     $a0, $s1, $zero
/* DF939C 8024299C 0C0B210B */  jal       get_float_variable
/* DF93A0 802429A0 46000606 */   mov.s    $f24, $f0
/* DF93A4 802429A4 8E050000 */  lw        $a1, ($s0)
/* DF93A8 802429A8 26100004 */  addiu     $s0, $s0, 4
/* DF93AC 802429AC 0220202D */  daddu     $a0, $s1, $zero
/* DF93B0 802429B0 0C0B210B */  jal       get_float_variable
/* DF93B4 802429B4 46000586 */   mov.s    $f22, $f0
/* DF93B8 802429B8 0220202D */  daddu     $a0, $s1, $zero
/* DF93BC 802429BC 8E050000 */  lw        $a1, ($s0)
/* DF93C0 802429C0 0C0B1EAF */  jal       get_variable
/* DF93C4 802429C4 46000506 */   mov.s    $f20, $f0
/* DF93C8 802429C8 4405E000 */  mfc1      $a1, $f28
/* DF93CC 802429CC 4406F000 */  mfc1      $a2, $f30
/* DF93D0 802429D0 4407D000 */  mfc1      $a3, $f26
/* DF93D4 802429D4 0240202D */  daddu     $a0, $s2, $zero
/* DF93D8 802429D8 AFA2001C */  sw        $v0, 0x1c($sp)
/* DF93DC 802429DC 27A20028 */  addiu     $v0, $sp, 0x28
/* DF93E0 802429E0 E7B80010 */  swc1      $f24, 0x10($sp)
/* DF93E4 802429E4 E7B60014 */  swc1      $f22, 0x14($sp)
/* DF93E8 802429E8 E7B40018 */  swc1      $f20, 0x18($sp)
/* DF93EC 802429EC 0C01C3DC */  jal       playFX_3D
/* DF93F0 802429F0 AFA20020 */   sw       $v0, 0x20($sp)
/* DF93F4 802429F4 8FA30028 */  lw        $v1, 0x28($sp)
/* DF93F8 802429F8 AE230084 */  sw        $v1, 0x84($s1)
/* DF93FC 802429FC 8FBF003C */  lw        $ra, 0x3c($sp)
/* DF9400 80242A00 8FB20038 */  lw        $s2, 0x38($sp)
/* DF9404 80242A04 8FB10034 */  lw        $s1, 0x34($sp)
/* DF9408 80242A08 8FB00030 */  lw        $s0, 0x30($sp)
/* DF940C 80242A0C D7BE0068 */  ldc1      $f30, 0x68($sp)
/* DF9410 80242A10 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* DF9414 80242A14 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* DF9418 80242A18 D7B80050 */  ldc1      $f24, 0x50($sp)
/* DF941C 80242A1C D7B60048 */  ldc1      $f22, 0x48($sp)
/* DF9420 80242A20 D7B40040 */  ldc1      $f20, 0x40($sp)
/* DF9424 80242A24 24020002 */  addiu     $v0, $zero, 2
/* DF9428 80242A28 03E00008 */  jr        $ra
/* DF942C 80242A2C 27BD0070 */   addiu    $sp, $sp, 0x70
