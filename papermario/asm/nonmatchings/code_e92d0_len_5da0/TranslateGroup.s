.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel TranslateGroup
/* 0EE164 802C97B4 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0EE168 802C97B8 AFB20058 */  sw    $s2, 0x58($sp)
/* 0EE16C 802C97BC 0080902D */  daddu $s2, $a0, $zero
/* 0EE170 802C97C0 AFBF005C */  sw    $ra, 0x5c($sp)
/* 0EE174 802C97C4 AFB10054 */  sw    $s1, 0x54($sp)
/* 0EE178 802C97C8 AFB00050 */  sw    $s0, 0x50($sp)
/* 0EE17C 802C97CC F7B80070 */  sdc1  $f24, 0x70($sp)
/* 0EE180 802C97D0 F7B60068 */  sdc1  $f22, 0x68($sp)
/* 0EE184 802C97D4 F7B40060 */  sdc1  $f20, 0x60($sp)
/* 0EE188 802C97D8 8E50000C */  lw    $s0, 0xc($s2)
/* 0EE18C 802C97DC 0C0B1EAF */  jal   get_variable
/* 0EE190 802C97E0 8E050000 */   lw    $a1, ($s0)
/* 0EE194 802C97E4 0C046C24 */  jal   func_8011B090
/* 0EE198 802C97E8 0040202D */   daddu $a0, $v0, $zero
/* 0EE19C 802C97EC 0040882D */  daddu $s1, $v0, $zero
/* 0EE1A0 802C97F0 2402FFFF */  addiu $v0, $zero, -1
/* 0EE1A4 802C97F4 16220007 */  bne   $s1, $v0, .L802C9814
/* 0EE1A8 802C97F8 26100004 */   addiu $s0, $s0, 4
/* 0EE1AC 802C97FC 3C04802D */  lui   $a0, 0x802d
/* 0EE1B0 802C9800 24848B60 */  addiu $a0, $a0, -0x74a0
/* 0EE1B4 802C9804 0C0B2568 */  jal   func_802C95A0
/* 0EE1B8 802C9808 0240282D */   daddu $a1, $s2, $zero
/* 0EE1BC 802C980C 080B262D */  j     .L802C98B4
/* 0EE1C0 802C9810 24020002 */   addiu $v0, $zero, 2

.L802C9814:
/* 0EE1C4 802C9814 8E050000 */  lw    $a1, ($s0)
/* 0EE1C8 802C9818 26100004 */  addiu $s0, $s0, 4
/* 0EE1CC 802C981C 0C0B210B */  jal   get_float_variable
/* 0EE1D0 802C9820 0240202D */   daddu $a0, $s2, $zero
/* 0EE1D4 802C9824 8E050000 */  lw    $a1, ($s0)
/* 0EE1D8 802C9828 26100004 */  addiu $s0, $s0, 4
/* 0EE1DC 802C982C 0240202D */  daddu $a0, $s2, $zero
/* 0EE1E0 802C9830 0C0B210B */  jal   get_float_variable
/* 0EE1E4 802C9834 46000606 */   mov.s $f24, $f0
/* 0EE1E8 802C9838 0240202D */  daddu $a0, $s2, $zero
/* 0EE1EC 802C983C 8E050000 */  lw    $a1, ($s0)
/* 0EE1F0 802C9840 0C0B210B */  jal   get_float_variable
/* 0EE1F4 802C9844 46000586 */   mov.s $f22, $f0
/* 0EE1F8 802C9848 0220202D */  daddu $a0, $s1, $zero
/* 0EE1FC 802C984C 0C046C70 */  jal   func_8011B1C0
/* 0EE200 802C9850 46000506 */   mov.s $f20, $f0
/* 0EE204 802C9854 0040802D */  daddu $s0, $v0, $zero
/* 0EE208 802C9858 96020000 */  lhu   $v0, ($s0)
/* 0EE20C 802C985C 30420400 */  andi  $v0, $v0, 0x400
/* 0EE210 802C9860 1440000A */  bnez  $v0, .L802C988C
/* 0EE214 802C9864 00000000 */   nop   
/* 0EE218 802C9868 4405C000 */  mfc1  $a1, $f24
/* 0EE21C 802C986C 4406B000 */  mfc1  $a2, $f22
/* 0EE220 802C9870 4407A000 */  mfc1  $a3, $f20
/* 0EE224 802C9874 0C019E40 */  jal   guTranslateF
/* 0EE228 802C9878 26040050 */   addiu $a0, $s0, 0x50
/* 0EE22C 802C987C 96020000 */  lhu   $v0, ($s0)
/* 0EE230 802C9880 34421400 */  ori   $v0, $v0, 0x1400
/* 0EE234 802C9884 080B262C */  j     .L802C98B0
/* 0EE238 802C9888 A6020000 */   sh    $v0, ($s0)

.L802C988C:
/* 0EE23C 802C988C 4405C000 */  mfc1  $a1, $f24
/* 0EE240 802C9890 4406B000 */  mfc1  $a2, $f22
/* 0EE244 802C9894 4407A000 */  mfc1  $a3, $f20
/* 0EE248 802C9898 0C019E40 */  jal   guTranslateF
/* 0EE24C 802C989C 27A40010 */   addiu $a0, $sp, 0x10
/* 0EE250 802C98A0 27A40010 */  addiu $a0, $sp, 0x10
/* 0EE254 802C98A4 26050050 */  addiu $a1, $s0, 0x50
/* 0EE258 802C98A8 0C019D80 */  jal   guMtxCatF
/* 0EE25C 802C98AC 00A0302D */   daddu $a2, $a1, $zero
.L802C98B0:
/* 0EE260 802C98B0 24020002 */  addiu $v0, $zero, 2
.L802C98B4:
/* 0EE264 802C98B4 8FBF005C */  lw    $ra, 0x5c($sp)
/* 0EE268 802C98B8 8FB20058 */  lw    $s2, 0x58($sp)
/* 0EE26C 802C98BC 8FB10054 */  lw    $s1, 0x54($sp)
/* 0EE270 802C98C0 8FB00050 */  lw    $s0, 0x50($sp)
/* 0EE274 802C98C4 D7B80070 */  ldc1  $f24, 0x70($sp)
/* 0EE278 802C98C8 D7B60068 */  ldc1  $f22, 0x68($sp)
/* 0EE27C 802C98CC D7B40060 */  ldc1  $f20, 0x60($sp)
/* 0EE280 802C98D0 03E00008 */  jr    $ra
/* 0EE284 802C98D4 27BD0078 */   addiu $sp, $sp, 0x78

