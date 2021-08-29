.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024001C_DEBEEC
/* DEBEEC 8024001C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DEBEF0 80240020 AFB10014 */  sw        $s1, 0x14($sp)
/* DEBEF4 80240024 0080882D */  daddu     $s1, $a0, $zero
/* DEBEF8 80240028 AFBF001C */  sw        $ra, 0x1c($sp)
/* DEBEFC 8024002C AFB20018 */  sw        $s2, 0x18($sp)
/* DEBF00 80240030 AFB00010 */  sw        $s0, 0x10($sp)
/* DEBF04 80240034 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DEBF08 80240038 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DEBF0C 8024003C F7B40020 */  sdc1      $f20, 0x20($sp)
/* DEBF10 80240040 8E30000C */  lw        $s0, 0xc($s1)
/* DEBF14 80240044 8E120000 */  lw        $s2, ($s0)
/* DEBF18 80240048 26100004 */  addiu     $s0, $s0, 4
/* DEBF1C 8024004C 8E050000 */  lw        $a1, ($s0)
/* DEBF20 80240050 0C0B210B */  jal       evt_get_float_variable
/* DEBF24 80240054 26100004 */   addiu    $s0, $s0, 4
/* DEBF28 80240058 8E050000 */  lw        $a1, ($s0)
/* DEBF2C 8024005C 26100004 */  addiu     $s0, $s0, 4
/* DEBF30 80240060 0220202D */  daddu     $a0, $s1, $zero
/* DEBF34 80240064 0C0B210B */  jal       evt_get_float_variable
/* DEBF38 80240068 46000606 */   mov.s    $f24, $f0
/* DEBF3C 8024006C 8E050000 */  lw        $a1, ($s0)
/* DEBF40 80240070 26100004 */  addiu     $s0, $s0, 4
/* DEBF44 80240074 0220202D */  daddu     $a0, $s1, $zero
/* DEBF48 80240078 0C0B210B */  jal       evt_get_float_variable
/* DEBF4C 8024007C 46000586 */   mov.s    $f22, $f0
/* DEBF50 80240080 0220202D */  daddu     $a0, $s1, $zero
/* DEBF54 80240084 8E050000 */  lw        $a1, ($s0)
/* DEBF58 80240088 0C0B210B */  jal       evt_get_float_variable
/* DEBF5C 8024008C 46000506 */   mov.s    $f20, $f0
/* DEBF60 80240090 4600C306 */  mov.s     $f12, $f24
/* DEBF64 80240094 4406A000 */  mfc1      $a2, $f20
/* DEBF68 80240098 44070000 */  mfc1      $a3, $f0
/* DEBF6C 8024009C 0C00A720 */  jal       atan2
/* DEBF70 802400A0 4600B386 */   mov.s    $f14, $f22
/* DEBF74 802400A4 0C00A6C9 */  jal       clamp_angle
/* DEBF78 802400A8 46000306 */   mov.s    $f12, $f0
/* DEBF7C 802400AC 0220202D */  daddu     $a0, $s1, $zero
/* DEBF80 802400B0 44060000 */  mfc1      $a2, $f0
/* DEBF84 802400B4 0C0B2190 */  jal       evt_set_float_variable
/* DEBF88 802400B8 0240282D */   daddu    $a1, $s2, $zero
/* DEBF8C 802400BC 8FBF001C */  lw        $ra, 0x1c($sp)
/* DEBF90 802400C0 8FB20018 */  lw        $s2, 0x18($sp)
/* DEBF94 802400C4 8FB10014 */  lw        $s1, 0x14($sp)
/* DEBF98 802400C8 8FB00010 */  lw        $s0, 0x10($sp)
/* DEBF9C 802400CC D7B80030 */  ldc1      $f24, 0x30($sp)
/* DEBFA0 802400D0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DEBFA4 802400D4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DEBFA8 802400D8 24020002 */  addiu     $v0, $zero, 2
/* DEBFAC 802400DC 03E00008 */  jr        $ra
/* DEBFB0 802400E0 27BD0038 */   addiu    $sp, $sp, 0x38
