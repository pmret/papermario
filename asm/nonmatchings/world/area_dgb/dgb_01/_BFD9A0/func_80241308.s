.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241308
/* BFEB88 80241308 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* BFEB8C 8024130C AFB00028 */  sw        $s0, 0x28($sp)
/* BFEB90 80241310 00A0802D */  daddu     $s0, $a1, $zero
/* BFEB94 80241314 AFB1002C */  sw        $s1, 0x2c($sp)
/* BFEB98 80241318 00C0882D */  daddu     $s1, $a2, $zero
/* BFEB9C 8024131C AFBF0034 */  sw        $ra, 0x34($sp)
/* BFEBA0 80241320 AFB20030 */  sw        $s2, 0x30($sp)
/* BFEBA4 80241324 AE200070 */  sw        $zero, 0x70($s1)
/* BFEBA8 80241328 8C830000 */  lw        $v1, ($a0)
/* BFEBAC 8024132C 2402FDFF */  addiu     $v0, $zero, -0x201
/* BFEBB0 80241330 A480008E */  sh        $zero, 0x8e($a0)
/* BFEBB4 80241334 00621824 */  and       $v1, $v1, $v0
/* BFEBB8 80241338 34650800 */  ori       $a1, $v1, 0x800
/* BFEBBC 8024133C AC850000 */  sw        $a1, ($a0)
/* BFEBC0 80241340 8E0200D0 */  lw        $v0, 0xd0($s0)
/* BFEBC4 80241344 8C420034 */  lw        $v0, 0x34($v0)
/* BFEBC8 80241348 10400003 */  beqz      $v0, .L80241358
/* BFEBCC 8024134C 00E0902D */   daddu    $s2, $a3, $zero
/* BFEBD0 80241350 080904D8 */  j         .L80241360
/* BFEBD4 80241354 34620808 */   ori      $v0, $v1, 0x808
.L80241358:
/* BFEBD8 80241358 2402FFF7 */  addiu     $v0, $zero, -9
/* BFEBDC 8024135C 00A21024 */  and       $v0, $a1, $v0
.L80241360:
/* BFEBE0 80241360 AC820000 */  sw        $v0, ($a0)
/* BFEBE4 80241364 27A20024 */  addiu     $v0, $sp, 0x24
/* BFEBE8 80241368 27A50018 */  addiu     $a1, $sp, 0x18
/* BFEBEC 8024136C C4800038 */  lwc1      $f0, 0x38($a0)
/* BFEBF0 80241370 C482003C */  lwc1      $f2, 0x3c($a0)
/* BFEBF4 80241374 C4840040 */  lwc1      $f4, 0x40($a0)
/* BFEBF8 80241378 3C01447A */  lui       $at, 0x447a
/* BFEBFC 8024137C 44813000 */  mtc1      $at, $f6
/* BFEC00 80241380 27A6001C */  addiu     $a2, $sp, 0x1c
/* BFEC04 80241384 E7A00018 */  swc1      $f0, 0x18($sp)
/* BFEC08 80241388 E7A2001C */  swc1      $f2, 0x1c($sp)
/* BFEC0C 8024138C E7A40020 */  swc1      $f4, 0x20($sp)
/* BFEC10 80241390 E7A60024 */  swc1      $f6, 0x24($sp)
/* BFEC14 80241394 AFA20010 */  sw        $v0, 0x10($sp)
/* BFEC18 80241398 8C840080 */  lw        $a0, 0x80($a0)
/* BFEC1C 8024139C 0C0372DF */  jal       func_800DCB7C
/* BFEC20 802413A0 27A70020 */   addiu    $a3, $sp, 0x20
/* BFEC24 802413A4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* BFEC28 802413A8 3C014059 */  lui       $at, 0x4059
/* BFEC2C 802413AC 44812800 */  mtc1      $at, $f5
/* BFEC30 802413B0 44802000 */  mtc1      $zero, $f4
/* BFEC34 802413B4 460010A1 */  cvt.d.s   $f2, $f2
/* BFEC38 802413B8 46241082 */  mul.d     $f2, $f2, $f4
/* BFEC3C 802413BC 00000000 */  nop       
/* BFEC40 802413C0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* BFEC44 802413C4 46000021 */  cvt.d.s   $f0, $f0
/* BFEC48 802413C8 46240002 */  mul.d     $f0, $f0, $f4
/* BFEC4C 802413CC 00000000 */  nop       
/* BFEC50 802413D0 3C013FE0 */  lui       $at, 0x3fe0
/* BFEC54 802413D4 44812800 */  mtc1      $at, $f5
/* BFEC58 802413D8 44802000 */  mtc1      $zero, $f4
/* BFEC5C 802413DC 00000000 */  nop       
/* BFEC60 802413E0 46241080 */  add.d     $f2, $f2, $f4
/* BFEC64 802413E4 AE000074 */  sw        $zero, 0x74($s0)
/* BFEC68 802413E8 46240000 */  add.d     $f0, $f0, $f4
/* BFEC6C 802413EC AE000090 */  sw        $zero, 0x90($s0)
/* BFEC70 802413F0 4620120D */  trunc.w.d $f8, $f2
/* BFEC74 802413F4 E6080078 */  swc1      $f8, 0x78($s0)
/* BFEC78 802413F8 4620020D */  trunc.w.d $f8, $f0
/* BFEC7C 802413FC E6080088 */  swc1      $f8, 0x88($s0)
/* BFEC80 80241400 8E420014 */  lw        $v0, 0x14($s2)
/* BFEC84 80241404 AE220074 */  sw        $v0, 0x74($s1)
/* BFEC88 80241408 8E0200B0 */  lw        $v0, 0xb0($s0)
/* BFEC8C 8024140C 34420010 */  ori       $v0, $v0, 0x10
/* BFEC90 80241410 AE0200B0 */  sw        $v0, 0xb0($s0)
/* BFEC94 80241414 8FBF0034 */  lw        $ra, 0x34($sp)
/* BFEC98 80241418 8FB20030 */  lw        $s2, 0x30($sp)
/* BFEC9C 8024141C 8FB1002C */  lw        $s1, 0x2c($sp)
/* BFECA0 80241420 8FB00028 */  lw        $s0, 0x28($sp)
/* BFECA4 80241424 03E00008 */  jr        $ra
/* BFECA8 80241428 27BD0038 */   addiu    $sp, $sp, 0x38
