.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AA0_5CF130
/* 5CF130 80218AA0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 5CF134 80218AA4 AFB10014 */  sw        $s1, 0x14($sp)
/* 5CF138 80218AA8 0080882D */  daddu     $s1, $a0, $zero
/* 5CF13C 80218AAC AFBF001C */  sw        $ra, 0x1c($sp)
/* 5CF140 80218AB0 AFB20018 */  sw        $s2, 0x18($sp)
/* 5CF144 80218AB4 AFB00010 */  sw        $s0, 0x10($sp)
/* 5CF148 80218AB8 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 5CF14C 80218ABC F7B60028 */  sdc1      $f22, 0x28($sp)
/* 5CF150 80218AC0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 5CF154 80218AC4 8E30000C */  lw        $s0, 0xc($s1)
/* 5CF158 80218AC8 8E120000 */  lw        $s2, ($s0)
/* 5CF15C 80218ACC 26100004 */  addiu     $s0, $s0, 4
/* 5CF160 80218AD0 8E050000 */  lw        $a1, ($s0)
/* 5CF164 80218AD4 0C0B210B */  jal       evt_get_float_variable
/* 5CF168 80218AD8 26100004 */   addiu    $s0, $s0, 4
/* 5CF16C 80218ADC 8E050000 */  lw        $a1, ($s0)
/* 5CF170 80218AE0 26100004 */  addiu     $s0, $s0, 4
/* 5CF174 80218AE4 0220202D */  daddu     $a0, $s1, $zero
/* 5CF178 80218AE8 0C0B210B */  jal       evt_get_float_variable
/* 5CF17C 80218AEC 46000606 */   mov.s    $f24, $f0
/* 5CF180 80218AF0 8E050000 */  lw        $a1, ($s0)
/* 5CF184 80218AF4 26100004 */  addiu     $s0, $s0, 4
/* 5CF188 80218AF8 0220202D */  daddu     $a0, $s1, $zero
/* 5CF18C 80218AFC 0C0B210B */  jal       evt_get_float_variable
/* 5CF190 80218B00 46000586 */   mov.s    $f22, $f0
/* 5CF194 80218B04 0220202D */  daddu     $a0, $s1, $zero
/* 5CF198 80218B08 8E050000 */  lw        $a1, ($s0)
/* 5CF19C 80218B0C 0C0B210B */  jal       evt_get_float_variable
/* 5CF1A0 80218B10 46000506 */   mov.s    $f20, $f0
/* 5CF1A4 80218B14 4600C306 */  mov.s     $f12, $f24
/* 5CF1A8 80218B18 4406A000 */  mfc1      $a2, $f20
/* 5CF1AC 80218B1C 44070000 */  mfc1      $a3, $f0
/* 5CF1B0 80218B20 0C00A720 */  jal       atan2
/* 5CF1B4 80218B24 4600B386 */   mov.s    $f14, $f22
/* 5CF1B8 80218B28 0220202D */  daddu     $a0, $s1, $zero
/* 5CF1BC 80218B2C 44060000 */  mfc1      $a2, $f0
/* 5CF1C0 80218B30 0C0B2190 */  jal       evt_set_float_variable
/* 5CF1C4 80218B34 0240282D */   daddu    $a1, $s2, $zero
/* 5CF1C8 80218B38 8FBF001C */  lw        $ra, 0x1c($sp)
/* 5CF1CC 80218B3C 8FB20018 */  lw        $s2, 0x18($sp)
/* 5CF1D0 80218B40 8FB10014 */  lw        $s1, 0x14($sp)
/* 5CF1D4 80218B44 8FB00010 */  lw        $s0, 0x10($sp)
/* 5CF1D8 80218B48 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 5CF1DC 80218B4C D7B60028 */  ldc1      $f22, 0x28($sp)
/* 5CF1E0 80218B50 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 5CF1E4 80218B54 24020002 */  addiu     $v0, $zero, 2
/* 5CF1E8 80218B58 03E00008 */  jr        $ra
/* 5CF1EC 80218B5C 27BD0038 */   addiu    $sp, $sp, 0x38
