.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C3C
/* DB3EFC 80241C3C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DB3F00 80241C40 AFB00028 */  sw        $s0, 0x28($sp)
/* DB3F04 80241C44 00A0802D */  daddu     $s0, $a1, $zero
/* DB3F08 80241C48 AFB1002C */  sw        $s1, 0x2c($sp)
/* DB3F0C 80241C4C 00C0882D */  daddu     $s1, $a2, $zero
/* DB3F10 80241C50 AFBF0034 */  sw        $ra, 0x34($sp)
/* DB3F14 80241C54 AFB20030 */  sw        $s2, 0x30($sp)
/* DB3F18 80241C58 AE200070 */  sw        $zero, 0x70($s1)
/* DB3F1C 80241C5C 8C830000 */  lw        $v1, ($a0)
/* DB3F20 80241C60 2402FDFF */  addiu     $v0, $zero, -0x201
/* DB3F24 80241C64 A480008E */  sh        $zero, 0x8e($a0)
/* DB3F28 80241C68 00621824 */  and       $v1, $v1, $v0
/* DB3F2C 80241C6C 34650800 */  ori       $a1, $v1, 0x800
/* DB3F30 80241C70 AC850000 */  sw        $a1, ($a0)
/* DB3F34 80241C74 8E0200D0 */  lw        $v0, 0xd0($s0)
/* DB3F38 80241C78 8C420034 */  lw        $v0, 0x34($v0)
/* DB3F3C 80241C7C 10400003 */  beqz      $v0, .L80241C8C
/* DB3F40 80241C80 00E0902D */   daddu    $s2, $a3, $zero
/* DB3F44 80241C84 08090725 */  j         .L80241C94
/* DB3F48 80241C88 34620808 */   ori      $v0, $v1, 0x808
.L80241C8C:
/* DB3F4C 80241C8C 2402FFF7 */  addiu     $v0, $zero, -9
/* DB3F50 80241C90 00A21024 */  and       $v0, $a1, $v0
.L80241C94:
/* DB3F54 80241C94 AC820000 */  sw        $v0, ($a0)
/* DB3F58 80241C98 27A20024 */  addiu     $v0, $sp, 0x24
/* DB3F5C 80241C9C 27A50018 */  addiu     $a1, $sp, 0x18
/* DB3F60 80241CA0 C4800038 */  lwc1      $f0, 0x38($a0)
/* DB3F64 80241CA4 C482003C */  lwc1      $f2, 0x3c($a0)
/* DB3F68 80241CA8 C4840040 */  lwc1      $f4, 0x40($a0)
/* DB3F6C 80241CAC 3C01447A */  lui       $at, 0x447a
/* DB3F70 80241CB0 44813000 */  mtc1      $at, $f6
/* DB3F74 80241CB4 27A6001C */  addiu     $a2, $sp, 0x1c
/* DB3F78 80241CB8 E7A00018 */  swc1      $f0, 0x18($sp)
/* DB3F7C 80241CBC E7A2001C */  swc1      $f2, 0x1c($sp)
/* DB3F80 80241CC0 E7A40020 */  swc1      $f4, 0x20($sp)
/* DB3F84 80241CC4 E7A60024 */  swc1      $f6, 0x24($sp)
/* DB3F88 80241CC8 AFA20010 */  sw        $v0, 0x10($sp)
/* DB3F8C 80241CCC 8C840080 */  lw        $a0, 0x80($a0)
/* DB3F90 80241CD0 0C0372DF */  jal       func_800DCB7C
/* DB3F94 80241CD4 27A70020 */   addiu    $a3, $sp, 0x20
/* DB3F98 80241CD8 C7A20024 */  lwc1      $f2, 0x24($sp)
/* DB3F9C 80241CDC 3C014059 */  lui       $at, 0x4059
/* DB3FA0 80241CE0 44812800 */  mtc1      $at, $f5
/* DB3FA4 80241CE4 44802000 */  mtc1      $zero, $f4
/* DB3FA8 80241CE8 460010A1 */  cvt.d.s   $f2, $f2
/* DB3FAC 80241CEC 46241082 */  mul.d     $f2, $f2, $f4
/* DB3FB0 80241CF0 00000000 */  nop       
/* DB3FB4 80241CF4 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* DB3FB8 80241CF8 46000021 */  cvt.d.s   $f0, $f0
/* DB3FBC 80241CFC 46240002 */  mul.d     $f0, $f0, $f4
/* DB3FC0 80241D00 00000000 */  nop       
/* DB3FC4 80241D04 3C013FE0 */  lui       $at, 0x3fe0
/* DB3FC8 80241D08 44812800 */  mtc1      $at, $f5
/* DB3FCC 80241D0C 44802000 */  mtc1      $zero, $f4
/* DB3FD0 80241D10 00000000 */  nop       
/* DB3FD4 80241D14 46241080 */  add.d     $f2, $f2, $f4
/* DB3FD8 80241D18 AE000074 */  sw        $zero, 0x74($s0)
/* DB3FDC 80241D1C 46240000 */  add.d     $f0, $f0, $f4
/* DB3FE0 80241D20 AE000090 */  sw        $zero, 0x90($s0)
/* DB3FE4 80241D24 4620120D */  trunc.w.d $f8, $f2
/* DB3FE8 80241D28 E6080078 */  swc1      $f8, 0x78($s0)
/* DB3FEC 80241D2C 4620020D */  trunc.w.d $f8, $f0
/* DB3FF0 80241D30 E6080088 */  swc1      $f8, 0x88($s0)
/* DB3FF4 80241D34 8E420014 */  lw        $v0, 0x14($s2)
/* DB3FF8 80241D38 AE220074 */  sw        $v0, 0x74($s1)
/* DB3FFC 80241D3C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* DB4000 80241D40 34420010 */  ori       $v0, $v0, 0x10
/* DB4004 80241D44 AE0200B0 */  sw        $v0, 0xb0($s0)
/* DB4008 80241D48 8FBF0034 */  lw        $ra, 0x34($sp)
/* DB400C 80241D4C 8FB20030 */  lw        $s2, 0x30($sp)
/* DB4010 80241D50 8FB1002C */  lw        $s1, 0x2c($sp)
/* DB4014 80241D54 8FB00028 */  lw        $s0, 0x28($sp)
/* DB4018 80241D58 03E00008 */  jr        $ra
/* DB401C 80241D5C 27BD0038 */   addiu    $sp, $sp, 0x38
