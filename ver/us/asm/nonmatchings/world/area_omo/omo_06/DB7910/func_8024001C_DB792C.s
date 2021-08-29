.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024001C_DB792C
/* DB792C 8024001C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DB7930 80240020 AFB10014 */  sw        $s1, 0x14($sp)
/* DB7934 80240024 0080882D */  daddu     $s1, $a0, $zero
/* DB7938 80240028 AFBF001C */  sw        $ra, 0x1c($sp)
/* DB793C 8024002C AFB20018 */  sw        $s2, 0x18($sp)
/* DB7940 80240030 AFB00010 */  sw        $s0, 0x10($sp)
/* DB7944 80240034 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DB7948 80240038 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DB794C 8024003C F7B40020 */  sdc1      $f20, 0x20($sp)
/* DB7950 80240040 8E30000C */  lw        $s0, 0xc($s1)
/* DB7954 80240044 8E120000 */  lw        $s2, ($s0)
/* DB7958 80240048 26100004 */  addiu     $s0, $s0, 4
/* DB795C 8024004C 8E050000 */  lw        $a1, ($s0)
/* DB7960 80240050 0C0B210B */  jal       evt_get_float_variable
/* DB7964 80240054 26100004 */   addiu    $s0, $s0, 4
/* DB7968 80240058 8E050000 */  lw        $a1, ($s0)
/* DB796C 8024005C 26100004 */  addiu     $s0, $s0, 4
/* DB7970 80240060 0220202D */  daddu     $a0, $s1, $zero
/* DB7974 80240064 0C0B210B */  jal       evt_get_float_variable
/* DB7978 80240068 46000606 */   mov.s    $f24, $f0
/* DB797C 8024006C 8E050000 */  lw        $a1, ($s0)
/* DB7980 80240070 26100004 */  addiu     $s0, $s0, 4
/* DB7984 80240074 0220202D */  daddu     $a0, $s1, $zero
/* DB7988 80240078 0C0B210B */  jal       evt_get_float_variable
/* DB798C 8024007C 46000586 */   mov.s    $f22, $f0
/* DB7990 80240080 0220202D */  daddu     $a0, $s1, $zero
/* DB7994 80240084 8E050000 */  lw        $a1, ($s0)
/* DB7998 80240088 0C0B210B */  jal       evt_get_float_variable
/* DB799C 8024008C 46000506 */   mov.s    $f20, $f0
/* DB79A0 80240090 4600C306 */  mov.s     $f12, $f24
/* DB79A4 80240094 4406A000 */  mfc1      $a2, $f20
/* DB79A8 80240098 44070000 */  mfc1      $a3, $f0
/* DB79AC 8024009C 0C00A720 */  jal       atan2
/* DB79B0 802400A0 4600B386 */   mov.s    $f14, $f22
/* DB79B4 802400A4 0C00A6C9 */  jal       clamp_angle
/* DB79B8 802400A8 46000306 */   mov.s    $f12, $f0
/* DB79BC 802400AC 0220202D */  daddu     $a0, $s1, $zero
/* DB79C0 802400B0 44060000 */  mfc1      $a2, $f0
/* DB79C4 802400B4 0C0B2190 */  jal       evt_set_float_variable
/* DB79C8 802400B8 0240282D */   daddu    $a1, $s2, $zero
/* DB79CC 802400BC 8FBF001C */  lw        $ra, 0x1c($sp)
/* DB79D0 802400C0 8FB20018 */  lw        $s2, 0x18($sp)
/* DB79D4 802400C4 8FB10014 */  lw        $s1, 0x14($sp)
/* DB79D8 802400C8 8FB00010 */  lw        $s0, 0x10($sp)
/* DB79DC 802400CC D7B80030 */  ldc1      $f24, 0x30($sp)
/* DB79E0 802400D0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DB79E4 802400D4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DB79E8 802400D8 24020002 */  addiu     $v0, $zero, 2
/* DB79EC 802400DC 03E00008 */  jr        $ra
/* DB79F0 802400E0 27BD0038 */   addiu    $sp, $sp, 0x38
