.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E50_CD2C80
/* CD2C80 80240E50 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CD2C84 80240E54 AFB3002C */  sw        $s3, 0x2c($sp)
/* CD2C88 80240E58 0080982D */  daddu     $s3, $a0, $zero
/* CD2C8C 80240E5C AFBF0030 */  sw        $ra, 0x30($sp)
/* CD2C90 80240E60 AFB20028 */  sw        $s2, 0x28($sp)
/* CD2C94 80240E64 AFB10024 */  sw        $s1, 0x24($sp)
/* CD2C98 80240E68 AFB00020 */  sw        $s0, 0x20($sp)
/* CD2C9C 80240E6C 8E710148 */  lw        $s1, 0x148($s3)
/* CD2CA0 80240E70 86240008 */  lh        $a0, 8($s1)
/* CD2CA4 80240E74 0C00EABB */  jal       get_npc_unsafe
/* CD2CA8 80240E78 00A0902D */   daddu    $s2, $a1, $zero
/* CD2CAC 80240E7C 8E440004 */  lw        $a0, 4($s2)
/* CD2CB0 80240E80 0040802D */  daddu     $s0, $v0, $zero
/* CD2CB4 80240E84 00041FC2 */  srl       $v1, $a0, 0x1f
/* CD2CB8 80240E88 00832021 */  addu      $a0, $a0, $v1
/* CD2CBC 80240E8C 00042043 */  sra       $a0, $a0, 1
/* CD2CC0 80240E90 0C00A67F */  jal       rand_int
/* CD2CC4 80240E94 24840001 */   addiu    $a0, $a0, 1
/* CD2CC8 80240E98 8E430004 */  lw        $v1, 4($s2)
/* CD2CCC 80240E9C 000327C2 */  srl       $a0, $v1, 0x1f
/* CD2CD0 80240EA0 00641821 */  addu      $v1, $v1, $a0
/* CD2CD4 80240EA4 00031843 */  sra       $v1, $v1, 1
/* CD2CD8 80240EA8 00621821 */  addu      $v1, $v1, $v0
/* CD2CDC 80240EAC A603008E */  sh        $v1, 0x8e($s0)
/* CD2CE0 80240EB0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CD2CE4 80240EB4 C6000040 */  lwc1      $f0, 0x40($s0)
/* CD2CE8 80240EB8 C4640000 */  lwc1      $f4, ($v1)
/* CD2CEC 80240EBC 46802120 */  cvt.s.w   $f4, $f4
/* CD2CF0 80240EC0 C4620008 */  lwc1      $f2, 8($v1)
/* CD2CF4 80240EC4 468010A0 */  cvt.s.w   $f2, $f2
/* CD2CF8 80240EC8 E7A00010 */  swc1      $f0, 0x10($sp)
/* CD2CFC 80240ECC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD2D00 80240ED0 44061000 */  mfc1      $a2, $f2
/* CD2D04 80240ED4 C440000C */  lwc1      $f0, 0xc($v0)
/* CD2D08 80240ED8 46800020 */  cvt.s.w   $f0, $f0
/* CD2D0C 80240EDC E7A00014 */  swc1      $f0, 0x14($sp)
/* CD2D10 80240EE0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD2D14 80240EE4 44052000 */  mfc1      $a1, $f4
/* CD2D18 80240EE8 C4400010 */  lwc1      $f0, 0x10($v0)
/* CD2D1C 80240EEC 46800020 */  cvt.s.w   $f0, $f0
/* CD2D20 80240EF0 E7A00018 */  swc1      $f0, 0x18($sp)
/* CD2D24 80240EF4 8C640018 */  lw        $a0, 0x18($v1)
/* CD2D28 80240EF8 0C0123F5 */  jal       is_point_within_region
/* CD2D2C 80240EFC 8E070038 */   lw       $a3, 0x38($s0)
/* CD2D30 80240F00 1040000E */  beqz      $v0, .L80240F3C
/* CD2D34 80240F04 00000000 */   nop
/* CD2D38 80240F08 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD2D3C 80240F0C C60C0038 */  lwc1      $f12, 0x38($s0)
/* CD2D40 80240F10 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CD2D44 80240F14 C4460000 */  lwc1      $f6, ($v0)
/* CD2D48 80240F18 468031A0 */  cvt.s.w   $f6, $f6
/* CD2D4C 80240F1C 44063000 */  mfc1      $a2, $f6
/* CD2D50 80240F20 C4460008 */  lwc1      $f6, 8($v0)
/* CD2D54 80240F24 468031A0 */  cvt.s.w   $f6, $f6
/* CD2D58 80240F28 44073000 */  mfc1      $a3, $f6
/* CD2D5C 80240F2C 0C00A720 */  jal       atan2
/* CD2D60 80240F30 00000000 */   nop
/* CD2D64 80240F34 080903DB */  j         .L80240F6C
/* CD2D68 80240F38 E600000C */   swc1     $f0, 0xc($s0)
.L80240F3C:
/* CD2D6C 80240F3C 0C00A67F */  jal       rand_int
/* CD2D70 80240F40 2404003C */   addiu    $a0, $zero, 0x3c
/* CD2D74 80240F44 C60C000C */  lwc1      $f12, 0xc($s0)
/* CD2D78 80240F48 44820000 */  mtc1      $v0, $f0
/* CD2D7C 80240F4C 00000000 */  nop
/* CD2D80 80240F50 46800020 */  cvt.s.w   $f0, $f0
/* CD2D84 80240F54 46006300 */  add.s     $f12, $f12, $f0
/* CD2D88 80240F58 3C0141F0 */  lui       $at, 0x41f0
/* CD2D8C 80240F5C 44810000 */  mtc1      $at, $f0
/* CD2D90 80240F60 0C00A6C9 */  jal       clamp_angle
/* CD2D94 80240F64 46006301 */   sub.s    $f12, $f12, $f0
/* CD2D98 80240F68 E600000C */  swc1      $f0, 0xc($s0)
.L80240F6C:
/* CD2D9C 80240F6C 8E2200CC */  lw        $v0, 0xcc($s1)
/* CD2DA0 80240F70 8C420004 */  lw        $v0, 4($v0)
/* CD2DA4 80240F74 AE020028 */  sw        $v0, 0x28($s0)
/* CD2DA8 80240F78 AE600074 */  sw        $zero, 0x74($s3)
/* CD2DAC 80240F7C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD2DB0 80240F80 8C420014 */  lw        $v0, 0x14($v0)
/* CD2DB4 80240F84 04410004 */  bgez      $v0, .L80240F98
/* CD2DB8 80240F88 00000000 */   nop
/* CD2DBC 80240F8C C6400000 */  lwc1      $f0, ($s2)
/* CD2DC0 80240F90 080903EE */  j         .L80240FB8
/* CD2DC4 80240F94 E6000018 */   swc1     $f0, 0x18($s0)
.L80240F98:
/* CD2DC8 80240F98 3C018024 */  lui       $at, %hi(D_802453F0)
/* CD2DCC 80240F9C D42253F0 */  ldc1      $f2, %lo(D_802453F0)($at)
/* CD2DD0 80240FA0 44820000 */  mtc1      $v0, $f0
/* CD2DD4 80240FA4 00000000 */  nop
/* CD2DD8 80240FA8 46800021 */  cvt.d.w   $f0, $f0
/* CD2DDC 80240FAC 46220003 */  div.d     $f0, $f0, $f2
/* CD2DE0 80240FB0 46200020 */  cvt.s.d   $f0, $f0
/* CD2DE4 80240FB4 E6000018 */  swc1      $f0, 0x18($s0)
.L80240FB8:
/* CD2DE8 80240FB8 C600003C */  lwc1      $f0, 0x3c($s0)
/* CD2DEC 80240FBC 3C014059 */  lui       $at, 0x4059
/* CD2DF0 80240FC0 44811800 */  mtc1      $at, $f3
/* CD2DF4 80240FC4 44801000 */  mtc1      $zero, $f2
/* CD2DF8 80240FC8 46000021 */  cvt.d.s   $f0, $f0
/* CD2DFC 80240FCC 46220002 */  mul.d     $f0, $f0, $f2
/* CD2E00 80240FD0 00000000 */  nop
/* CD2E04 80240FD4 24020001 */  addiu     $v0, $zero, 1
/* CD2E08 80240FD8 4620018D */  trunc.w.d $f6, $f0
/* CD2E0C 80240FDC E626007C */  swc1      $f6, 0x7c($s1)
/* CD2E10 80240FE0 AE620070 */  sw        $v0, 0x70($s3)
/* CD2E14 80240FE4 8FBF0030 */  lw        $ra, 0x30($sp)
/* CD2E18 80240FE8 8FB3002C */  lw        $s3, 0x2c($sp)
/* CD2E1C 80240FEC 8FB20028 */  lw        $s2, 0x28($sp)
/* CD2E20 80240FF0 8FB10024 */  lw        $s1, 0x24($sp)
/* CD2E24 80240FF4 8FB00020 */  lw        $s0, 0x20($sp)
/* CD2E28 80240FF8 03E00008 */  jr        $ra
/* CD2E2C 80240FFC 27BD0038 */   addiu    $sp, $sp, 0x38
