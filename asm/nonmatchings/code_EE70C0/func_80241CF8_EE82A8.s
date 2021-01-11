.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CF8_EE82A8
/* EE82A8 80241CF8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* EE82AC 80241CFC AFB00028 */  sw        $s0, 0x28($sp)
/* EE82B0 80241D00 00A0802D */  daddu     $s0, $a1, $zero
/* EE82B4 80241D04 AFB1002C */  sw        $s1, 0x2c($sp)
/* EE82B8 80241D08 00C0882D */  daddu     $s1, $a2, $zero
/* EE82BC 80241D0C AFBF0034 */  sw        $ra, 0x34($sp)
/* EE82C0 80241D10 AFB20030 */  sw        $s2, 0x30($sp)
/* EE82C4 80241D14 AE200070 */  sw        $zero, 0x70($s1)
/* EE82C8 80241D18 8C830000 */  lw        $v1, ($a0)
/* EE82CC 80241D1C 2402FDFF */  addiu     $v0, $zero, -0x201
/* EE82D0 80241D20 A480008E */  sh        $zero, 0x8e($a0)
/* EE82D4 80241D24 00621824 */  and       $v1, $v1, $v0
/* EE82D8 80241D28 34650800 */  ori       $a1, $v1, 0x800
/* EE82DC 80241D2C AC850000 */  sw        $a1, ($a0)
/* EE82E0 80241D30 8E0200D0 */  lw        $v0, 0xd0($s0)
/* EE82E4 80241D34 8C420034 */  lw        $v0, 0x34($v0)
/* EE82E8 80241D38 10400003 */  beqz      $v0, .L80241D48
/* EE82EC 80241D3C 00E0902D */   daddu    $s2, $a3, $zero
/* EE82F0 80241D40 08090754 */  j         .L80241D50
/* EE82F4 80241D44 34620808 */   ori      $v0, $v1, 0x808
.L80241D48:
/* EE82F8 80241D48 2402FFF7 */  addiu     $v0, $zero, -9
/* EE82FC 80241D4C 00A21024 */  and       $v0, $a1, $v0
.L80241D50:
/* EE8300 80241D50 AC820000 */  sw        $v0, ($a0)
/* EE8304 80241D54 27A20024 */  addiu     $v0, $sp, 0x24
/* EE8308 80241D58 27A50018 */  addiu     $a1, $sp, 0x18
/* EE830C 80241D5C C4800038 */  lwc1      $f0, 0x38($a0)
/* EE8310 80241D60 C482003C */  lwc1      $f2, 0x3c($a0)
/* EE8314 80241D64 C4840040 */  lwc1      $f4, 0x40($a0)
/* EE8318 80241D68 3C01447A */  lui       $at, 0x447a
/* EE831C 80241D6C 44813000 */  mtc1      $at, $f6
/* EE8320 80241D70 27A6001C */  addiu     $a2, $sp, 0x1c
/* EE8324 80241D74 E7A00018 */  swc1      $f0, 0x18($sp)
/* EE8328 80241D78 E7A2001C */  swc1      $f2, 0x1c($sp)
/* EE832C 80241D7C E7A40020 */  swc1      $f4, 0x20($sp)
/* EE8330 80241D80 E7A60024 */  swc1      $f6, 0x24($sp)
/* EE8334 80241D84 AFA20010 */  sw        $v0, 0x10($sp)
/* EE8338 80241D88 8C840080 */  lw        $a0, 0x80($a0)
/* EE833C 80241D8C 0C03908F */  jal       func_800E423C
/* EE8340 80241D90 27A70020 */   addiu    $a3, $sp, 0x20
/* EE8344 80241D94 C7A20024 */  lwc1      $f2, 0x24($sp)
/* EE8348 80241D98 3C014059 */  lui       $at, 0x4059
/* EE834C 80241D9C 44812800 */  mtc1      $at, $f5
/* EE8350 80241DA0 44802000 */  mtc1      $zero, $f4
/* EE8354 80241DA4 460010A1 */  cvt.d.s   $f2, $f2
/* EE8358 80241DA8 46241082 */  mul.d     $f2, $f2, $f4
/* EE835C 80241DAC 00000000 */  nop       
/* EE8360 80241DB0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* EE8364 80241DB4 46000021 */  cvt.d.s   $f0, $f0
/* EE8368 80241DB8 46240002 */  mul.d     $f0, $f0, $f4
/* EE836C 80241DBC 00000000 */  nop       
/* EE8370 80241DC0 3C013FE0 */  lui       $at, 0x3fe0
/* EE8374 80241DC4 44812800 */  mtc1      $at, $f5
/* EE8378 80241DC8 44802000 */  mtc1      $zero, $f4
/* EE837C 80241DCC 00000000 */  nop       
/* EE8380 80241DD0 46241080 */  add.d     $f2, $f2, $f4
/* EE8384 80241DD4 AE000074 */  sw        $zero, 0x74($s0)
/* EE8388 80241DD8 46240000 */  add.d     $f0, $f0, $f4
/* EE838C 80241DDC AE000090 */  sw        $zero, 0x90($s0)
/* EE8390 80241DE0 4620120D */  trunc.w.d $f8, $f2
/* EE8394 80241DE4 E6080078 */  swc1      $f8, 0x78($s0)
/* EE8398 80241DE8 4620020D */  trunc.w.d $f8, $f0
/* EE839C 80241DEC E6080088 */  swc1      $f8, 0x88($s0)
/* EE83A0 80241DF0 8E420014 */  lw        $v0, 0x14($s2)
/* EE83A4 80241DF4 AE220074 */  sw        $v0, 0x74($s1)
/* EE83A8 80241DF8 8E0200B0 */  lw        $v0, 0xb0($s0)
/* EE83AC 80241DFC 34420010 */  ori       $v0, $v0, 0x10
/* EE83B0 80241E00 AE0200B0 */  sw        $v0, 0xb0($s0)
/* EE83B4 80241E04 8FBF0034 */  lw        $ra, 0x34($sp)
/* EE83B8 80241E08 8FB20030 */  lw        $s2, 0x30($sp)
/* EE83BC 80241E0C 8FB1002C */  lw        $s1, 0x2c($sp)
/* EE83C0 80241E10 8FB00028 */  lw        $s0, 0x28($sp)
/* EE83C4 80241E14 03E00008 */  jr        $ra
/* EE83C8 80241E18 27BD0038 */   addiu    $sp, $sp, 0x38
