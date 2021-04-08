.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mim_08_UnkFunc5
/* BAEBC8 80241288 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* BAEBCC 8024128C AFB00028 */  sw        $s0, 0x28($sp)
/* BAEBD0 80241290 00A0802D */  daddu     $s0, $a1, $zero
/* BAEBD4 80241294 AFB1002C */  sw        $s1, 0x2c($sp)
/* BAEBD8 80241298 00C0882D */  daddu     $s1, $a2, $zero
/* BAEBDC 8024129C AFBF0034 */  sw        $ra, 0x34($sp)
/* BAEBE0 802412A0 AFB20030 */  sw        $s2, 0x30($sp)
/* BAEBE4 802412A4 AE200070 */  sw        $zero, 0x70($s1)
/* BAEBE8 802412A8 8C830000 */  lw        $v1, ($a0)
/* BAEBEC 802412AC 2402FDFF */  addiu     $v0, $zero, -0x201
/* BAEBF0 802412B0 A480008E */  sh        $zero, 0x8e($a0)
/* BAEBF4 802412B4 00621824 */  and       $v1, $v1, $v0
/* BAEBF8 802412B8 34650800 */  ori       $a1, $v1, 0x800
/* BAEBFC 802412BC AC850000 */  sw        $a1, ($a0)
/* BAEC00 802412C0 8E0200D0 */  lw        $v0, 0xd0($s0)
/* BAEC04 802412C4 8C420034 */  lw        $v0, 0x34($v0)
/* BAEC08 802412C8 10400003 */  beqz      $v0, .L802412D8
/* BAEC0C 802412CC 00E0902D */   daddu    $s2, $a3, $zero
/* BAEC10 802412D0 080904B8 */  j         .L802412E0
/* BAEC14 802412D4 34620808 */   ori      $v0, $v1, 0x808
.L802412D8:
/* BAEC18 802412D8 2402FFF7 */  addiu     $v0, $zero, -9
/* BAEC1C 802412DC 00A21024 */  and       $v0, $a1, $v0
.L802412E0:
/* BAEC20 802412E0 AC820000 */  sw        $v0, ($a0)
/* BAEC24 802412E4 27A20024 */  addiu     $v0, $sp, 0x24
/* BAEC28 802412E8 27A50018 */  addiu     $a1, $sp, 0x18
/* BAEC2C 802412EC C4800038 */  lwc1      $f0, 0x38($a0)
/* BAEC30 802412F0 C482003C */  lwc1      $f2, 0x3c($a0)
/* BAEC34 802412F4 C4840040 */  lwc1      $f4, 0x40($a0)
/* BAEC38 802412F8 3C01447A */  lui       $at, 0x447a
/* BAEC3C 802412FC 44813000 */  mtc1      $at, $f6
/* BAEC40 80241300 27A6001C */  addiu     $a2, $sp, 0x1c
/* BAEC44 80241304 E7A00018 */  swc1      $f0, 0x18($sp)
/* BAEC48 80241308 E7A2001C */  swc1      $f2, 0x1c($sp)
/* BAEC4C 8024130C E7A40020 */  swc1      $f4, 0x20($sp)
/* BAEC50 80241310 E7A60024 */  swc1      $f6, 0x24($sp)
/* BAEC54 80241314 AFA20010 */  sw        $v0, 0x10($sp)
/* BAEC58 80241318 8C840080 */  lw        $a0, 0x80($a0)
/* BAEC5C 8024131C 0C0372DF */  jal       func_800DCB7C
/* BAEC60 80241320 27A70020 */   addiu    $a3, $sp, 0x20
/* BAEC64 80241324 C7A20024 */  lwc1      $f2, 0x24($sp)
/* BAEC68 80241328 3C014059 */  lui       $at, 0x4059
/* BAEC6C 8024132C 44812800 */  mtc1      $at, $f5
/* BAEC70 80241330 44802000 */  mtc1      $zero, $f4
/* BAEC74 80241334 460010A1 */  cvt.d.s   $f2, $f2
/* BAEC78 80241338 46241082 */  mul.d     $f2, $f2, $f4
/* BAEC7C 8024133C 00000000 */  nop
/* BAEC80 80241340 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* BAEC84 80241344 46000021 */  cvt.d.s   $f0, $f0
/* BAEC88 80241348 46240002 */  mul.d     $f0, $f0, $f4
/* BAEC8C 8024134C 00000000 */  nop
/* BAEC90 80241350 3C013FE0 */  lui       $at, 0x3fe0
/* BAEC94 80241354 44812800 */  mtc1      $at, $f5
/* BAEC98 80241358 44802000 */  mtc1      $zero, $f4
/* BAEC9C 8024135C 00000000 */  nop
/* BAECA0 80241360 46241080 */  add.d     $f2, $f2, $f4
/* BAECA4 80241364 AE000074 */  sw        $zero, 0x74($s0)
/* BAECA8 80241368 46240000 */  add.d     $f0, $f0, $f4
/* BAECAC 8024136C AE000090 */  sw        $zero, 0x90($s0)
/* BAECB0 80241370 4620120D */  trunc.w.d $f8, $f2
/* BAECB4 80241374 E6080078 */  swc1      $f8, 0x78($s0)
/* BAECB8 80241378 4620020D */  trunc.w.d $f8, $f0
/* BAECBC 8024137C E6080088 */  swc1      $f8, 0x88($s0)
/* BAECC0 80241380 8E420014 */  lw        $v0, 0x14($s2)
/* BAECC4 80241384 AE220074 */  sw        $v0, 0x74($s1)
/* BAECC8 80241388 8E0200B0 */  lw        $v0, 0xb0($s0)
/* BAECCC 8024138C 34420010 */  ori       $v0, $v0, 0x10
/* BAECD0 80241390 AE0200B0 */  sw        $v0, 0xb0($s0)
/* BAECD4 80241394 8FBF0034 */  lw        $ra, 0x34($sp)
/* BAECD8 80241398 8FB20030 */  lw        $s2, 0x30($sp)
/* BAECDC 8024139C 8FB1002C */  lw        $s1, 0x2c($sp)
/* BAECE0 802413A0 8FB00028 */  lw        $s0, 0x28($sp)
/* BAECE4 802413A4 03E00008 */  jr        $ra
/* BAECE8 802413A8 27BD0038 */   addiu    $sp, $sp, 0x38
