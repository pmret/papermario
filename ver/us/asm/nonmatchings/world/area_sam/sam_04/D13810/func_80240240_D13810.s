.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240240_D13810
/* D13810 80240240 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* D13814 80240244 AFB10014 */  sw        $s1, 0x14($sp)
/* D13818 80240248 0080882D */  daddu     $s1, $a0, $zero
/* D1381C 8024024C AFBF001C */  sw        $ra, 0x1c($sp)
/* D13820 80240250 AFB20018 */  sw        $s2, 0x18($sp)
/* D13824 80240254 AFB00010 */  sw        $s0, 0x10($sp)
/* D13828 80240258 F7B80030 */  sdc1      $f24, 0x30($sp)
/* D1382C 8024025C F7B60028 */  sdc1      $f22, 0x28($sp)
/* D13830 80240260 F7B40020 */  sdc1      $f20, 0x20($sp)
/* D13834 80240264 8E30000C */  lw        $s0, 0xc($s1)
/* D13838 80240268 8E120000 */  lw        $s2, ($s0)
/* D1383C 8024026C 26100004 */  addiu     $s0, $s0, 4
/* D13840 80240270 8E050000 */  lw        $a1, ($s0)
/* D13844 80240274 0C0B210B */  jal       evt_get_float_variable
/* D13848 80240278 26100004 */   addiu    $s0, $s0, 4
/* D1384C 8024027C 8E050000 */  lw        $a1, ($s0)
/* D13850 80240280 26100004 */  addiu     $s0, $s0, 4
/* D13854 80240284 0220202D */  daddu     $a0, $s1, $zero
/* D13858 80240288 0C0B210B */  jal       evt_get_float_variable
/* D1385C 8024028C 46000606 */   mov.s    $f24, $f0
/* D13860 80240290 8E050000 */  lw        $a1, ($s0)
/* D13864 80240294 26100004 */  addiu     $s0, $s0, 4
/* D13868 80240298 0220202D */  daddu     $a0, $s1, $zero
/* D1386C 8024029C 0C0B210B */  jal       evt_get_float_variable
/* D13870 802402A0 46000586 */   mov.s    $f22, $f0
/* D13874 802402A4 0220202D */  daddu     $a0, $s1, $zero
/* D13878 802402A8 8E050000 */  lw        $a1, ($s0)
/* D1387C 802402AC 0C0B210B */  jal       evt_get_float_variable
/* D13880 802402B0 46000506 */   mov.s    $f20, $f0
/* D13884 802402B4 4600C306 */  mov.s     $f12, $f24
/* D13888 802402B8 4406A000 */  mfc1      $a2, $f20
/* D1388C 802402BC 44070000 */  mfc1      $a3, $f0
/* D13890 802402C0 0C00A720 */  jal       atan2
/* D13894 802402C4 4600B386 */   mov.s    $f14, $f22
/* D13898 802402C8 0C00A6C9 */  jal       clamp_angle
/* D1389C 802402CC 46000306 */   mov.s    $f12, $f0
/* D138A0 802402D0 0220202D */  daddu     $a0, $s1, $zero
/* D138A4 802402D4 44060000 */  mfc1      $a2, $f0
/* D138A8 802402D8 0C0B2190 */  jal       evt_set_float_variable
/* D138AC 802402DC 0240282D */   daddu    $a1, $s2, $zero
/* D138B0 802402E0 8FBF001C */  lw        $ra, 0x1c($sp)
/* D138B4 802402E4 8FB20018 */  lw        $s2, 0x18($sp)
/* D138B8 802402E8 8FB10014 */  lw        $s1, 0x14($sp)
/* D138BC 802402EC 8FB00010 */  lw        $s0, 0x10($sp)
/* D138C0 802402F0 D7B80030 */  ldc1      $f24, 0x30($sp)
/* D138C4 802402F4 D7B60028 */  ldc1      $f22, 0x28($sp)
/* D138C8 802402F8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* D138CC 802402FC 24020002 */  addiu     $v0, $zero, 2
/* D138D0 80240300 03E00008 */  jr        $ra
/* D138D4 80240304 27BD0038 */   addiu    $sp, $sp, 0x38
/* D138D8 80240308 00000000 */  nop
/* D138DC 8024030C 00000000 */  nop
