.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nok_15_UnkFunc5
/* A08B9C 80241C9C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A08BA0 80241CA0 AFB00028 */  sw        $s0, 0x28($sp)
/* A08BA4 80241CA4 00A0802D */  daddu     $s0, $a1, $zero
/* A08BA8 80241CA8 AFB1002C */  sw        $s1, 0x2c($sp)
/* A08BAC 80241CAC 00C0882D */  daddu     $s1, $a2, $zero
/* A08BB0 80241CB0 AFBF0034 */  sw        $ra, 0x34($sp)
/* A08BB4 80241CB4 AFB20030 */  sw        $s2, 0x30($sp)
/* A08BB8 80241CB8 AE200070 */  sw        $zero, 0x70($s1)
/* A08BBC 80241CBC 8C830000 */  lw        $v1, ($a0)
/* A08BC0 80241CC0 2402FDFF */  addiu     $v0, $zero, -0x201
/* A08BC4 80241CC4 A480008E */  sh        $zero, 0x8e($a0)
/* A08BC8 80241CC8 00621824 */  and       $v1, $v1, $v0
/* A08BCC 80241CCC 34650800 */  ori       $a1, $v1, 0x800
/* A08BD0 80241CD0 AC850000 */  sw        $a1, ($a0)
/* A08BD4 80241CD4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* A08BD8 80241CD8 8C420034 */  lw        $v0, 0x34($v0)
/* A08BDC 80241CDC 10400003 */  beqz      $v0, .L80241CEC
/* A08BE0 80241CE0 00E0902D */   daddu    $s2, $a3, $zero
/* A08BE4 80241CE4 0809073D */  j         .L80241CF4
/* A08BE8 80241CE8 34620808 */   ori      $v0, $v1, 0x808
.L80241CEC:
/* A08BEC 80241CEC 2402FFF7 */  addiu     $v0, $zero, -9
/* A08BF0 80241CF0 00A21024 */  and       $v0, $a1, $v0
.L80241CF4:
/* A08BF4 80241CF4 AC820000 */  sw        $v0, ($a0)
/* A08BF8 80241CF8 27A20024 */  addiu     $v0, $sp, 0x24
/* A08BFC 80241CFC 27A50018 */  addiu     $a1, $sp, 0x18
/* A08C00 80241D00 C4800038 */  lwc1      $f0, 0x38($a0)
/* A08C04 80241D04 C482003C */  lwc1      $f2, 0x3c($a0)
/* A08C08 80241D08 C4840040 */  lwc1      $f4, 0x40($a0)
/* A08C0C 80241D0C 3C01447A */  lui       $at, 0x447a
/* A08C10 80241D10 44813000 */  mtc1      $at, $f6
/* A08C14 80241D14 27A6001C */  addiu     $a2, $sp, 0x1c
/* A08C18 80241D18 E7A00018 */  swc1      $f0, 0x18($sp)
/* A08C1C 80241D1C E7A2001C */  swc1      $f2, 0x1c($sp)
/* A08C20 80241D20 E7A40020 */  swc1      $f4, 0x20($sp)
/* A08C24 80241D24 E7A60024 */  swc1      $f6, 0x24($sp)
/* A08C28 80241D28 AFA20010 */  sw        $v0, 0x10($sp)
/* A08C2C 80241D2C 8C840080 */  lw        $a0, 0x80($a0)
/* A08C30 80241D30 0C0372DF */  jal       func_800DCB7C
/* A08C34 80241D34 27A70020 */   addiu    $a3, $sp, 0x20
/* A08C38 80241D38 C7A20024 */  lwc1      $f2, 0x24($sp)
/* A08C3C 80241D3C 3C014059 */  lui       $at, 0x4059
/* A08C40 80241D40 44812800 */  mtc1      $at, $f5
/* A08C44 80241D44 44802000 */  mtc1      $zero, $f4
/* A08C48 80241D48 460010A1 */  cvt.d.s   $f2, $f2
/* A08C4C 80241D4C 46241082 */  mul.d     $f2, $f2, $f4
/* A08C50 80241D50 00000000 */  nop
/* A08C54 80241D54 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* A08C58 80241D58 46000021 */  cvt.d.s   $f0, $f0
/* A08C5C 80241D5C 46240002 */  mul.d     $f0, $f0, $f4
/* A08C60 80241D60 00000000 */  nop
/* A08C64 80241D64 3C013FE0 */  lui       $at, 0x3fe0
/* A08C68 80241D68 44812800 */  mtc1      $at, $f5
/* A08C6C 80241D6C 44802000 */  mtc1      $zero, $f4
/* A08C70 80241D70 00000000 */  nop
/* A08C74 80241D74 46241080 */  add.d     $f2, $f2, $f4
/* A08C78 80241D78 AE000074 */  sw        $zero, 0x74($s0)
/* A08C7C 80241D7C 46240000 */  add.d     $f0, $f0, $f4
/* A08C80 80241D80 AE000090 */  sw        $zero, 0x90($s0)
/* A08C84 80241D84 4620120D */  trunc.w.d $f8, $f2
/* A08C88 80241D88 E6080078 */  swc1      $f8, 0x78($s0)
/* A08C8C 80241D8C 4620020D */  trunc.w.d $f8, $f0
/* A08C90 80241D90 E6080088 */  swc1      $f8, 0x88($s0)
/* A08C94 80241D94 8E420014 */  lw        $v0, 0x14($s2)
/* A08C98 80241D98 AE220074 */  sw        $v0, 0x74($s1)
/* A08C9C 80241D9C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* A08CA0 80241DA0 34420010 */  ori       $v0, $v0, 0x10
/* A08CA4 80241DA4 AE0200B0 */  sw        $v0, 0xb0($s0)
/* A08CA8 80241DA8 8FBF0034 */  lw        $ra, 0x34($sp)
/* A08CAC 80241DAC 8FB20030 */  lw        $s2, 0x30($sp)
/* A08CB0 80241DB0 8FB1002C */  lw        $s1, 0x2c($sp)
/* A08CB4 80241DB4 8FB00028 */  lw        $s0, 0x28($sp)
/* A08CB8 80241DB8 03E00008 */  jr        $ra
/* A08CBC 80241DBC 27BD0038 */   addiu    $sp, $sp, 0x38
