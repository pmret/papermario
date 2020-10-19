.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024001C_DD79CC
/* DD79CC 8024001C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DD79D0 80240020 AFB10014 */  sw        $s1, 0x14($sp)
/* DD79D4 80240024 0080882D */  daddu     $s1, $a0, $zero
/* DD79D8 80240028 AFBF001C */  sw        $ra, 0x1c($sp)
/* DD79DC 8024002C AFB20018 */  sw        $s2, 0x18($sp)
/* DD79E0 80240030 AFB00010 */  sw        $s0, 0x10($sp)
/* DD79E4 80240034 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DD79E8 80240038 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DD79EC 8024003C F7B40020 */  sdc1      $f20, 0x20($sp)
/* DD79F0 80240040 8E30000C */  lw        $s0, 0xc($s1)
/* DD79F4 80240044 8E120000 */  lw        $s2, ($s0)
/* DD79F8 80240048 26100004 */  addiu     $s0, $s0, 4
/* DD79FC 8024004C 8E050000 */  lw        $a1, ($s0)
/* DD7A00 80240050 0C0B210B */  jal       get_float_variable
/* DD7A04 80240054 26100004 */   addiu    $s0, $s0, 4
/* DD7A08 80240058 8E050000 */  lw        $a1, ($s0)
/* DD7A0C 8024005C 26100004 */  addiu     $s0, $s0, 4
/* DD7A10 80240060 0220202D */  daddu     $a0, $s1, $zero
/* DD7A14 80240064 0C0B210B */  jal       get_float_variable
/* DD7A18 80240068 46000606 */   mov.s    $f24, $f0
/* DD7A1C 8024006C 8E050000 */  lw        $a1, ($s0)
/* DD7A20 80240070 26100004 */  addiu     $s0, $s0, 4
/* DD7A24 80240074 0220202D */  daddu     $a0, $s1, $zero
/* DD7A28 80240078 0C0B210B */  jal       get_float_variable
/* DD7A2C 8024007C 46000586 */   mov.s    $f22, $f0
/* DD7A30 80240080 0220202D */  daddu     $a0, $s1, $zero
/* DD7A34 80240084 8E050000 */  lw        $a1, ($s0)
/* DD7A38 80240088 0C0B210B */  jal       get_float_variable
/* DD7A3C 8024008C 46000506 */   mov.s    $f20, $f0
/* DD7A40 80240090 4600C306 */  mov.s     $f12, $f24
/* DD7A44 80240094 4406A000 */  mfc1      $a2, $f20
/* DD7A48 80240098 44070000 */  mfc1      $a3, $f0
/* DD7A4C 8024009C 0C00A720 */  jal       atan2
/* DD7A50 802400A0 4600B386 */   mov.s    $f14, $f22
/* DD7A54 802400A4 0C00A6C9 */  jal       clamp_angle
/* DD7A58 802400A8 46000306 */   mov.s    $f12, $f0
/* DD7A5C 802400AC 0220202D */  daddu     $a0, $s1, $zero
/* DD7A60 802400B0 44060000 */  mfc1      $a2, $f0
/* DD7A64 802400B4 0C0B2190 */  jal       set_float_variable
/* DD7A68 802400B8 0240282D */   daddu    $a1, $s2, $zero
/* DD7A6C 802400BC 8FBF001C */  lw        $ra, 0x1c($sp)
/* DD7A70 802400C0 8FB20018 */  lw        $s2, 0x18($sp)
/* DD7A74 802400C4 8FB10014 */  lw        $s1, 0x14($sp)
/* DD7A78 802400C8 8FB00010 */  lw        $s0, 0x10($sp)
/* DD7A7C 802400CC D7B80030 */  ldc1      $f24, 0x30($sp)
/* DD7A80 802400D0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DD7A84 802400D4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DD7A88 802400D8 24020002 */  addiu     $v0, $zero, 2
/* DD7A8C 802400DC 03E00008 */  jr        $ra
/* DD7A90 802400E0 27BD0038 */   addiu    $sp, $sp, 0x38
