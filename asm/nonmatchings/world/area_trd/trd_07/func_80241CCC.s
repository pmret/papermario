.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CCC
/* 9B864C 80241CCC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 9B8650 80241CD0 AFB00028 */  sw        $s0, 0x28($sp)
/* 9B8654 80241CD4 00A0802D */  daddu     $s0, $a1, $zero
/* 9B8658 80241CD8 AFB1002C */  sw        $s1, 0x2c($sp)
/* 9B865C 80241CDC 00C0882D */  daddu     $s1, $a2, $zero
/* 9B8660 80241CE0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 9B8664 80241CE4 AFB20030 */  sw        $s2, 0x30($sp)
/* 9B8668 80241CE8 AE200070 */  sw        $zero, 0x70($s1)
/* 9B866C 80241CEC 8C830000 */  lw        $v1, ($a0)
/* 9B8670 80241CF0 2402FDFF */  addiu     $v0, $zero, -0x201
/* 9B8674 80241CF4 A480008E */  sh        $zero, 0x8e($a0)
/* 9B8678 80241CF8 00621824 */  and       $v1, $v1, $v0
/* 9B867C 80241CFC 34650800 */  ori       $a1, $v1, 0x800
/* 9B8680 80241D00 AC850000 */  sw        $a1, ($a0)
/* 9B8684 80241D04 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 9B8688 80241D08 8C420034 */  lw        $v0, 0x34($v0)
/* 9B868C 80241D0C 10400003 */  beqz      $v0, .L80241D1C
/* 9B8690 80241D10 00E0902D */   daddu    $s2, $a3, $zero
/* 9B8694 80241D14 08090749 */  j         .L80241D24
/* 9B8698 80241D18 34620808 */   ori      $v0, $v1, 0x808
.L80241D1C:
/* 9B869C 80241D1C 2402FFF7 */  addiu     $v0, $zero, -9
/* 9B86A0 80241D20 00A21024 */  and       $v0, $a1, $v0
.L80241D24:
/* 9B86A4 80241D24 AC820000 */  sw        $v0, ($a0)
/* 9B86A8 80241D28 27A20024 */  addiu     $v0, $sp, 0x24
/* 9B86AC 80241D2C 27A50018 */  addiu     $a1, $sp, 0x18
/* 9B86B0 80241D30 C4800038 */  lwc1      $f0, 0x38($a0)
/* 9B86B4 80241D34 C482003C */  lwc1      $f2, 0x3c($a0)
/* 9B86B8 80241D38 C4840040 */  lwc1      $f4, 0x40($a0)
/* 9B86BC 80241D3C 3C01447A */  lui       $at, 0x447a
/* 9B86C0 80241D40 44813000 */  mtc1      $at, $f6
/* 9B86C4 80241D44 27A6001C */  addiu     $a2, $sp, 0x1c
/* 9B86C8 80241D48 E7A00018 */  swc1      $f0, 0x18($sp)
/* 9B86CC 80241D4C E7A2001C */  swc1      $f2, 0x1c($sp)
/* 9B86D0 80241D50 E7A40020 */  swc1      $f4, 0x20($sp)
/* 9B86D4 80241D54 E7A60024 */  swc1      $f6, 0x24($sp)
/* 9B86D8 80241D58 AFA20010 */  sw        $v0, 0x10($sp)
/* 9B86DC 80241D5C 8C840080 */  lw        $a0, 0x80($a0)
/* 9B86E0 80241D60 0C0372DF */  jal       func_800DCB7C
/* 9B86E4 80241D64 27A70020 */   addiu    $a3, $sp, 0x20
/* 9B86E8 80241D68 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 9B86EC 80241D6C 3C014059 */  lui       $at, 0x4059
/* 9B86F0 80241D70 44812800 */  mtc1      $at, $f5
/* 9B86F4 80241D74 44802000 */  mtc1      $zero, $f4
/* 9B86F8 80241D78 460010A1 */  cvt.d.s   $f2, $f2
/* 9B86FC 80241D7C 46241082 */  mul.d     $f2, $f2, $f4
/* 9B8700 80241D80 00000000 */  nop       
/* 9B8704 80241D84 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 9B8708 80241D88 46000021 */  cvt.d.s   $f0, $f0
/* 9B870C 80241D8C 46240002 */  mul.d     $f0, $f0, $f4
/* 9B8710 80241D90 00000000 */  nop       
/* 9B8714 80241D94 3C013FE0 */  lui       $at, 0x3fe0
/* 9B8718 80241D98 44812800 */  mtc1      $at, $f5
/* 9B871C 80241D9C 44802000 */  mtc1      $zero, $f4
/* 9B8720 80241DA0 00000000 */  nop       
/* 9B8724 80241DA4 46241080 */  add.d     $f2, $f2, $f4
/* 9B8728 80241DA8 AE000074 */  sw        $zero, 0x74($s0)
/* 9B872C 80241DAC 46240000 */  add.d     $f0, $f0, $f4
/* 9B8730 80241DB0 AE000090 */  sw        $zero, 0x90($s0)
/* 9B8734 80241DB4 4620120D */  trunc.w.d $f8, $f2
/* 9B8738 80241DB8 E6080078 */  swc1      $f8, 0x78($s0)
/* 9B873C 80241DBC 4620020D */  trunc.w.d $f8, $f0
/* 9B8740 80241DC0 E6080088 */  swc1      $f8, 0x88($s0)
/* 9B8744 80241DC4 8E420014 */  lw        $v0, 0x14($s2)
/* 9B8748 80241DC8 AE220074 */  sw        $v0, 0x74($s1)
/* 9B874C 80241DCC 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 9B8750 80241DD0 34420010 */  ori       $v0, $v0, 0x10
/* 9B8754 80241DD4 AE0200B0 */  sw        $v0, 0xb0($s0)
/* 9B8758 80241DD8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 9B875C 80241DDC 8FB20030 */  lw        $s2, 0x30($sp)
/* 9B8760 80241DE0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 9B8764 80241DE4 8FB00028 */  lw        $s0, 0x28($sp)
/* 9B8768 80241DE8 03E00008 */  jr        $ra
/* 9B876C 80241DEC 27BD0038 */   addiu    $sp, $sp, 0x38
