.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024003C_DA527C
/* DA527C 8024003C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DA5280 80240040 AFB10014 */  sw        $s1, 0x14($sp)
/* DA5284 80240044 0080882D */  daddu     $s1, $a0, $zero
/* DA5288 80240048 AFBF001C */  sw        $ra, 0x1c($sp)
/* DA528C 8024004C AFB20018 */  sw        $s2, 0x18($sp)
/* DA5290 80240050 AFB00010 */  sw        $s0, 0x10($sp)
/* DA5294 80240054 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DA5298 80240058 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DA529C 8024005C F7B40020 */  sdc1      $f20, 0x20($sp)
/* DA52A0 80240060 8E30000C */  lw        $s0, 0xc($s1)
/* DA52A4 80240064 8E120000 */  lw        $s2, ($s0)
/* DA52A8 80240068 26100004 */  addiu     $s0, $s0, 4
/* DA52AC 8024006C 8E050000 */  lw        $a1, ($s0)
/* DA52B0 80240070 0C0B210B */  jal       get_float_variable
/* DA52B4 80240074 26100004 */   addiu    $s0, $s0, 4
/* DA52B8 80240078 8E050000 */  lw        $a1, ($s0)
/* DA52BC 8024007C 26100004 */  addiu     $s0, $s0, 4
/* DA52C0 80240080 0220202D */  daddu     $a0, $s1, $zero
/* DA52C4 80240084 0C0B210B */  jal       get_float_variable
/* DA52C8 80240088 46000606 */   mov.s    $f24, $f0
/* DA52CC 8024008C 8E050000 */  lw        $a1, ($s0)
/* DA52D0 80240090 26100004 */  addiu     $s0, $s0, 4
/* DA52D4 80240094 0220202D */  daddu     $a0, $s1, $zero
/* DA52D8 80240098 0C0B210B */  jal       get_float_variable
/* DA52DC 8024009C 46000586 */   mov.s    $f22, $f0
/* DA52E0 802400A0 0220202D */  daddu     $a0, $s1, $zero
/* DA52E4 802400A4 8E050000 */  lw        $a1, ($s0)
/* DA52E8 802400A8 0C0B210B */  jal       get_float_variable
/* DA52EC 802400AC 46000506 */   mov.s    $f20, $f0
/* DA52F0 802400B0 4600C306 */  mov.s     $f12, $f24
/* DA52F4 802400B4 4406A000 */  mfc1      $a2, $f20
/* DA52F8 802400B8 44070000 */  mfc1      $a3, $f0
/* DA52FC 802400BC 0C00A720 */  jal       atan2
/* DA5300 802400C0 4600B386 */   mov.s    $f14, $f22
/* DA5304 802400C4 0C00A6C9 */  jal       clamp_angle
/* DA5308 802400C8 46000306 */   mov.s    $f12, $f0
/* DA530C 802400CC 0220202D */  daddu     $a0, $s1, $zero
/* DA5310 802400D0 44060000 */  mfc1      $a2, $f0
/* DA5314 802400D4 0C0B2190 */  jal       set_float_variable
/* DA5318 802400D8 0240282D */   daddu    $a1, $s2, $zero
/* DA531C 802400DC 8FBF001C */  lw        $ra, 0x1c($sp)
/* DA5320 802400E0 8FB20018 */  lw        $s2, 0x18($sp)
/* DA5324 802400E4 8FB10014 */  lw        $s1, 0x14($sp)
/* DA5328 802400E8 8FB00010 */  lw        $s0, 0x10($sp)
/* DA532C 802400EC D7B80030 */  ldc1      $f24, 0x30($sp)
/* DA5330 802400F0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DA5334 802400F4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DA5338 802400F8 24020002 */  addiu     $v0, $zero, 2
/* DA533C 802400FC 03E00008 */  jr        $ra
/* DA5340 80240100 27BD0038 */   addiu    $sp, $sp, 0x38
