.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C38_C730B8
/* C730B8 80241C38 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C730BC 80241C3C AFB00028 */  sw        $s0, 0x28($sp)
/* C730C0 80241C40 00A0802D */  daddu     $s0, $a1, $zero
/* C730C4 80241C44 AFB1002C */  sw        $s1, 0x2c($sp)
/* C730C8 80241C48 00C0882D */  daddu     $s1, $a2, $zero
/* C730CC 80241C4C AFBF0034 */  sw        $ra, 0x34($sp)
/* C730D0 80241C50 AFB20030 */  sw        $s2, 0x30($sp)
/* C730D4 80241C54 AE200070 */  sw        $zero, 0x70($s1)
/* C730D8 80241C58 8C830000 */  lw        $v1, ($a0)
/* C730DC 80241C5C 2402FDFF */  addiu     $v0, $zero, -0x201
/* C730E0 80241C60 A480008E */  sh        $zero, 0x8e($a0)
/* C730E4 80241C64 00621824 */  and       $v1, $v1, $v0
/* C730E8 80241C68 34650800 */  ori       $a1, $v1, 0x800
/* C730EC 80241C6C AC850000 */  sw        $a1, ($a0)
/* C730F0 80241C70 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C730F4 80241C74 8C420034 */  lw        $v0, 0x34($v0)
/* C730F8 80241C78 10400003 */  beqz      $v0, .L80241C88
/* C730FC 80241C7C 00E0902D */   daddu    $s2, $a3, $zero
/* C73100 80241C80 08090724 */  j         .L80241C90
/* C73104 80241C84 34620808 */   ori      $v0, $v1, 0x808
.L80241C88:
/* C73108 80241C88 2402FFF7 */  addiu     $v0, $zero, -9
/* C7310C 80241C8C 00A21024 */  and       $v0, $a1, $v0
.L80241C90:
/* C73110 80241C90 AC820000 */  sw        $v0, ($a0)
/* C73114 80241C94 27A20024 */  addiu     $v0, $sp, 0x24
/* C73118 80241C98 27A50018 */  addiu     $a1, $sp, 0x18
/* C7311C 80241C9C C4800038 */  lwc1      $f0, 0x38($a0)
/* C73120 80241CA0 C482003C */  lwc1      $f2, 0x3c($a0)
/* C73124 80241CA4 C4840040 */  lwc1      $f4, 0x40($a0)
/* C73128 80241CA8 3C01447A */  lui       $at, 0x447a
/* C7312C 80241CAC 44813000 */  mtc1      $at, $f6
/* C73130 80241CB0 27A6001C */  addiu     $a2, $sp, 0x1c
/* C73134 80241CB4 E7A00018 */  swc1      $f0, 0x18($sp)
/* C73138 80241CB8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* C7313C 80241CBC E7A40020 */  swc1      $f4, 0x20($sp)
/* C73140 80241CC0 E7A60024 */  swc1      $f6, 0x24($sp)
/* C73144 80241CC4 AFA20010 */  sw        $v0, 0x10($sp)
/* C73148 80241CC8 8C840080 */  lw        $a0, 0x80($a0)
/* C7314C 80241CCC 0C0372DF */  jal       func_800DCB7C
/* C73150 80241CD0 27A70020 */   addiu    $a3, $sp, 0x20
/* C73154 80241CD4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* C73158 80241CD8 3C014059 */  lui       $at, 0x4059
/* C7315C 80241CDC 44812800 */  mtc1      $at, $f5
/* C73160 80241CE0 44802000 */  mtc1      $zero, $f4
/* C73164 80241CE4 460010A1 */  cvt.d.s   $f2, $f2
/* C73168 80241CE8 46241082 */  mul.d     $f2, $f2, $f4
/* C7316C 80241CEC 00000000 */  nop
/* C73170 80241CF0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* C73174 80241CF4 46000021 */  cvt.d.s   $f0, $f0
/* C73178 80241CF8 46240002 */  mul.d     $f0, $f0, $f4
/* C7317C 80241CFC 00000000 */  nop
/* C73180 80241D00 3C013FE0 */  lui       $at, 0x3fe0
/* C73184 80241D04 44812800 */  mtc1      $at, $f5
/* C73188 80241D08 44802000 */  mtc1      $zero, $f4
/* C7318C 80241D0C 00000000 */  nop
/* C73190 80241D10 46241080 */  add.d     $f2, $f2, $f4
/* C73194 80241D14 AE000074 */  sw        $zero, 0x74($s0)
/* C73198 80241D18 46240000 */  add.d     $f0, $f0, $f4
/* C7319C 80241D1C AE000090 */  sw        $zero, 0x90($s0)
/* C731A0 80241D20 4620120D */  trunc.w.d $f8, $f2
/* C731A4 80241D24 E6080078 */  swc1      $f8, 0x78($s0)
/* C731A8 80241D28 4620020D */  trunc.w.d $f8, $f0
/* C731AC 80241D2C E6080088 */  swc1      $f8, 0x88($s0)
/* C731B0 80241D30 8E420014 */  lw        $v0, 0x14($s2)
/* C731B4 80241D34 AE220074 */  sw        $v0, 0x74($s1)
/* C731B8 80241D38 8E0200B0 */  lw        $v0, 0xb0($s0)
/* C731BC 80241D3C 34420010 */  ori       $v0, $v0, 0x10
/* C731C0 80241D40 AE0200B0 */  sw        $v0, 0xb0($s0)
/* C731C4 80241D44 8FBF0034 */  lw        $ra, 0x34($sp)
/* C731C8 80241D48 8FB20030 */  lw        $s2, 0x30($sp)
/* C731CC 80241D4C 8FB1002C */  lw        $s1, 0x2c($sp)
/* C731D0 80241D50 8FB00028 */  lw        $s0, 0x28($sp)
/* C731D4 80241D54 03E00008 */  jr        $ra
/* C731D8 80241D58 27BD0038 */   addiu    $sp, $sp, 0x38
