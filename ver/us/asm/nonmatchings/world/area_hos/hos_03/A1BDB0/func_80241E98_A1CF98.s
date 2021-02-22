.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E98_A1CF98
/* A1CF98 80241E98 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A1CF9C 80241E9C AFB00028 */  sw        $s0, 0x28($sp)
/* A1CFA0 80241EA0 00A0802D */  daddu     $s0, $a1, $zero
/* A1CFA4 80241EA4 AFB1002C */  sw        $s1, 0x2c($sp)
/* A1CFA8 80241EA8 00C0882D */  daddu     $s1, $a2, $zero
/* A1CFAC 80241EAC AFBF0034 */  sw        $ra, 0x34($sp)
/* A1CFB0 80241EB0 AFB20030 */  sw        $s2, 0x30($sp)
/* A1CFB4 80241EB4 AE200070 */  sw        $zero, 0x70($s1)
/* A1CFB8 80241EB8 8C830000 */  lw        $v1, ($a0)
/* A1CFBC 80241EBC 2402FDFF */  addiu     $v0, $zero, -0x201
/* A1CFC0 80241EC0 A480008E */  sh        $zero, 0x8e($a0)
/* A1CFC4 80241EC4 00621824 */  and       $v1, $v1, $v0
/* A1CFC8 80241EC8 34650800 */  ori       $a1, $v1, 0x800
/* A1CFCC 80241ECC AC850000 */  sw        $a1, ($a0)
/* A1CFD0 80241ED0 8E0200D0 */  lw        $v0, 0xd0($s0)
/* A1CFD4 80241ED4 8C420034 */  lw        $v0, 0x34($v0)
/* A1CFD8 80241ED8 10400003 */  beqz      $v0, .L80241EE8
/* A1CFDC 80241EDC 00E0902D */   daddu    $s2, $a3, $zero
/* A1CFE0 80241EE0 080907BC */  j         .L80241EF0
/* A1CFE4 80241EE4 34620808 */   ori      $v0, $v1, 0x808
.L80241EE8:
/* A1CFE8 80241EE8 2402FFF7 */  addiu     $v0, $zero, -9
/* A1CFEC 80241EEC 00A21024 */  and       $v0, $a1, $v0
.L80241EF0:
/* A1CFF0 80241EF0 AC820000 */  sw        $v0, ($a0)
/* A1CFF4 80241EF4 27A20024 */  addiu     $v0, $sp, 0x24
/* A1CFF8 80241EF8 27A50018 */  addiu     $a1, $sp, 0x18
/* A1CFFC 80241EFC C4800038 */  lwc1      $f0, 0x38($a0)
/* A1D000 80241F00 C482003C */  lwc1      $f2, 0x3c($a0)
/* A1D004 80241F04 C4840040 */  lwc1      $f4, 0x40($a0)
/* A1D008 80241F08 3C01447A */  lui       $at, 0x447a
/* A1D00C 80241F0C 44813000 */  mtc1      $at, $f6
/* A1D010 80241F10 27A6001C */  addiu     $a2, $sp, 0x1c
/* A1D014 80241F14 E7A00018 */  swc1      $f0, 0x18($sp)
/* A1D018 80241F18 E7A2001C */  swc1      $f2, 0x1c($sp)
/* A1D01C 80241F1C E7A40020 */  swc1      $f4, 0x20($sp)
/* A1D020 80241F20 E7A60024 */  swc1      $f6, 0x24($sp)
/* A1D024 80241F24 AFA20010 */  sw        $v0, 0x10($sp)
/* A1D028 80241F28 8C840080 */  lw        $a0, 0x80($a0)
/* A1D02C 80241F2C 0C0372DF */  jal       func_800DCB7C
/* A1D030 80241F30 27A70020 */   addiu    $a3, $sp, 0x20
/* A1D034 80241F34 C7A20024 */  lwc1      $f2, 0x24($sp)
/* A1D038 80241F38 3C014059 */  lui       $at, 0x4059
/* A1D03C 80241F3C 44812800 */  mtc1      $at, $f5
/* A1D040 80241F40 44802000 */  mtc1      $zero, $f4
/* A1D044 80241F44 460010A1 */  cvt.d.s   $f2, $f2
/* A1D048 80241F48 46241082 */  mul.d     $f2, $f2, $f4
/* A1D04C 80241F4C 00000000 */  nop
/* A1D050 80241F50 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* A1D054 80241F54 46000021 */  cvt.d.s   $f0, $f0
/* A1D058 80241F58 46240002 */  mul.d     $f0, $f0, $f4
/* A1D05C 80241F5C 00000000 */  nop
/* A1D060 80241F60 3C013FE0 */  lui       $at, 0x3fe0
/* A1D064 80241F64 44812800 */  mtc1      $at, $f5
/* A1D068 80241F68 44802000 */  mtc1      $zero, $f4
/* A1D06C 80241F6C 00000000 */  nop
/* A1D070 80241F70 46241080 */  add.d     $f2, $f2, $f4
/* A1D074 80241F74 AE000074 */  sw        $zero, 0x74($s0)
/* A1D078 80241F78 46240000 */  add.d     $f0, $f0, $f4
/* A1D07C 80241F7C AE000090 */  sw        $zero, 0x90($s0)
/* A1D080 80241F80 4620120D */  trunc.w.d $f8, $f2
/* A1D084 80241F84 E6080078 */  swc1      $f8, 0x78($s0)
/* A1D088 80241F88 4620020D */  trunc.w.d $f8, $f0
/* A1D08C 80241F8C E6080088 */  swc1      $f8, 0x88($s0)
/* A1D090 80241F90 8E420014 */  lw        $v0, 0x14($s2)
/* A1D094 80241F94 AE220074 */  sw        $v0, 0x74($s1)
/* A1D098 80241F98 8E0200B0 */  lw        $v0, 0xb0($s0)
/* A1D09C 80241F9C 34420010 */  ori       $v0, $v0, 0x10
/* A1D0A0 80241FA0 AE0200B0 */  sw        $v0, 0xb0($s0)
/* A1D0A4 80241FA4 8FBF0034 */  lw        $ra, 0x34($sp)
/* A1D0A8 80241FA8 8FB20030 */  lw        $s2, 0x30($sp)
/* A1D0AC 80241FAC 8FB1002C */  lw        $s1, 0x2c($sp)
/* A1D0B0 80241FB0 8FB00028 */  lw        $s0, 0x28($sp)
/* A1D0B4 80241FB4 03E00008 */  jr        $ra
/* A1D0B8 80241FB8 27BD0038 */   addiu    $sp, $sp, 0x38
