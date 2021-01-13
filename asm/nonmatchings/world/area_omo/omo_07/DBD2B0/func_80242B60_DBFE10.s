.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B60_DBFE10
/* DBFE10 80242B60 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DBFE14 80242B64 AFB00028 */  sw        $s0, 0x28($sp)
/* DBFE18 80242B68 00A0802D */  daddu     $s0, $a1, $zero
/* DBFE1C 80242B6C AFB1002C */  sw        $s1, 0x2c($sp)
/* DBFE20 80242B70 00C0882D */  daddu     $s1, $a2, $zero
/* DBFE24 80242B74 AFBF0034 */  sw        $ra, 0x34($sp)
/* DBFE28 80242B78 AFB20030 */  sw        $s2, 0x30($sp)
/* DBFE2C 80242B7C AE200070 */  sw        $zero, 0x70($s1)
/* DBFE30 80242B80 8C830000 */  lw        $v1, ($a0)
/* DBFE34 80242B84 2402FDFF */  addiu     $v0, $zero, -0x201
/* DBFE38 80242B88 A480008E */  sh        $zero, 0x8e($a0)
/* DBFE3C 80242B8C 00621824 */  and       $v1, $v1, $v0
/* DBFE40 80242B90 34650800 */  ori       $a1, $v1, 0x800
/* DBFE44 80242B94 AC850000 */  sw        $a1, ($a0)
/* DBFE48 80242B98 8E0200D0 */  lw        $v0, 0xd0($s0)
/* DBFE4C 80242B9C 8C420034 */  lw        $v0, 0x34($v0)
/* DBFE50 80242BA0 10400003 */  beqz      $v0, .L80242BB0
/* DBFE54 80242BA4 00E0902D */   daddu    $s2, $a3, $zero
/* DBFE58 80242BA8 08090AEE */  j         .L80242BB8
/* DBFE5C 80242BAC 34620808 */   ori      $v0, $v1, 0x808
.L80242BB0:
/* DBFE60 80242BB0 2402FFF7 */  addiu     $v0, $zero, -9
/* DBFE64 80242BB4 00A21024 */  and       $v0, $a1, $v0
.L80242BB8:
/* DBFE68 80242BB8 AC820000 */  sw        $v0, ($a0)
/* DBFE6C 80242BBC 27A20024 */  addiu     $v0, $sp, 0x24
/* DBFE70 80242BC0 27A50018 */  addiu     $a1, $sp, 0x18
/* DBFE74 80242BC4 C4800038 */  lwc1      $f0, 0x38($a0)
/* DBFE78 80242BC8 C482003C */  lwc1      $f2, 0x3c($a0)
/* DBFE7C 80242BCC C4840040 */  lwc1      $f4, 0x40($a0)
/* DBFE80 80242BD0 3C01447A */  lui       $at, 0x447a
/* DBFE84 80242BD4 44813000 */  mtc1      $at, $f6
/* DBFE88 80242BD8 27A6001C */  addiu     $a2, $sp, 0x1c
/* DBFE8C 80242BDC E7A00018 */  swc1      $f0, 0x18($sp)
/* DBFE90 80242BE0 E7A2001C */  swc1      $f2, 0x1c($sp)
/* DBFE94 80242BE4 E7A40020 */  swc1      $f4, 0x20($sp)
/* DBFE98 80242BE8 E7A60024 */  swc1      $f6, 0x24($sp)
/* DBFE9C 80242BEC AFA20010 */  sw        $v0, 0x10($sp)
/* DBFEA0 80242BF0 8C840080 */  lw        $a0, 0x80($a0)
/* DBFEA4 80242BF4 0C0372DF */  jal       func_800DCB7C
/* DBFEA8 80242BF8 27A70020 */   addiu    $a3, $sp, 0x20
/* DBFEAC 80242BFC C7A20024 */  lwc1      $f2, 0x24($sp)
/* DBFEB0 80242C00 3C014059 */  lui       $at, 0x4059
/* DBFEB4 80242C04 44812800 */  mtc1      $at, $f5
/* DBFEB8 80242C08 44802000 */  mtc1      $zero, $f4
/* DBFEBC 80242C0C 460010A1 */  cvt.d.s   $f2, $f2
/* DBFEC0 80242C10 46241082 */  mul.d     $f2, $f2, $f4
/* DBFEC4 80242C14 00000000 */  nop
/* DBFEC8 80242C18 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* DBFECC 80242C1C 46000021 */  cvt.d.s   $f0, $f0
/* DBFED0 80242C20 46240002 */  mul.d     $f0, $f0, $f4
/* DBFED4 80242C24 00000000 */  nop
/* DBFED8 80242C28 3C013FE0 */  lui       $at, 0x3fe0
/* DBFEDC 80242C2C 44812800 */  mtc1      $at, $f5
/* DBFEE0 80242C30 44802000 */  mtc1      $zero, $f4
/* DBFEE4 80242C34 00000000 */  nop
/* DBFEE8 80242C38 46241080 */  add.d     $f2, $f2, $f4
/* DBFEEC 80242C3C AE000074 */  sw        $zero, 0x74($s0)
/* DBFEF0 80242C40 46240000 */  add.d     $f0, $f0, $f4
/* DBFEF4 80242C44 AE000090 */  sw        $zero, 0x90($s0)
/* DBFEF8 80242C48 4620120D */  trunc.w.d $f8, $f2
/* DBFEFC 80242C4C E6080078 */  swc1      $f8, 0x78($s0)
/* DBFF00 80242C50 4620020D */  trunc.w.d $f8, $f0
/* DBFF04 80242C54 E6080088 */  swc1      $f8, 0x88($s0)
/* DBFF08 80242C58 8E420014 */  lw        $v0, 0x14($s2)
/* DBFF0C 80242C5C AE220074 */  sw        $v0, 0x74($s1)
/* DBFF10 80242C60 8E0200B0 */  lw        $v0, 0xb0($s0)
/* DBFF14 80242C64 34420010 */  ori       $v0, $v0, 0x10
/* DBFF18 80242C68 AE0200B0 */  sw        $v0, 0xb0($s0)
/* DBFF1C 80242C6C 8FBF0034 */  lw        $ra, 0x34($sp)
/* DBFF20 80242C70 8FB20030 */  lw        $s2, 0x30($sp)
/* DBFF24 80242C74 8FB1002C */  lw        $s1, 0x2c($sp)
/* DBFF28 80242C78 8FB00028 */  lw        $s0, 0x28($sp)
/* DBFF2C 80242C7C 03E00008 */  jr        $ra
/* DBFF30 80242C80 27BD0038 */   addiu    $sp, $sp, 0x38
