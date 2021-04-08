.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_25_UnkFunc5
/* CF3DF8 80241228 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CF3DFC 8024122C AFB00028 */  sw        $s0, 0x28($sp)
/* CF3E00 80241230 00A0802D */  daddu     $s0, $a1, $zero
/* CF3E04 80241234 AFB1002C */  sw        $s1, 0x2c($sp)
/* CF3E08 80241238 00C0882D */  daddu     $s1, $a2, $zero
/* CF3E0C 8024123C AFBF0034 */  sw        $ra, 0x34($sp)
/* CF3E10 80241240 AFB20030 */  sw        $s2, 0x30($sp)
/* CF3E14 80241244 AE200070 */  sw        $zero, 0x70($s1)
/* CF3E18 80241248 8C830000 */  lw        $v1, ($a0)
/* CF3E1C 8024124C 2402FDFF */  addiu     $v0, $zero, -0x201
/* CF3E20 80241250 A480008E */  sh        $zero, 0x8e($a0)
/* CF3E24 80241254 00621824 */  and       $v1, $v1, $v0
/* CF3E28 80241258 34650800 */  ori       $a1, $v1, 0x800
/* CF3E2C 8024125C AC850000 */  sw        $a1, ($a0)
/* CF3E30 80241260 8E0200D0 */  lw        $v0, 0xd0($s0)
/* CF3E34 80241264 8C420034 */  lw        $v0, 0x34($v0)
/* CF3E38 80241268 10400003 */  beqz      $v0, .L80241278
/* CF3E3C 8024126C 00E0902D */   daddu    $s2, $a3, $zero
/* CF3E40 80241270 080904A0 */  j         .L80241280
/* CF3E44 80241274 34620808 */   ori      $v0, $v1, 0x808
.L80241278:
/* CF3E48 80241278 2402FFF7 */  addiu     $v0, $zero, -9
/* CF3E4C 8024127C 00A21024 */  and       $v0, $a1, $v0
.L80241280:
/* CF3E50 80241280 AC820000 */  sw        $v0, ($a0)
/* CF3E54 80241284 27A20024 */  addiu     $v0, $sp, 0x24
/* CF3E58 80241288 27A50018 */  addiu     $a1, $sp, 0x18
/* CF3E5C 8024128C C4800038 */  lwc1      $f0, 0x38($a0)
/* CF3E60 80241290 C482003C */  lwc1      $f2, 0x3c($a0)
/* CF3E64 80241294 C4840040 */  lwc1      $f4, 0x40($a0)
/* CF3E68 80241298 3C01447A */  lui       $at, 0x447a
/* CF3E6C 8024129C 44813000 */  mtc1      $at, $f6
/* CF3E70 802412A0 27A6001C */  addiu     $a2, $sp, 0x1c
/* CF3E74 802412A4 E7A00018 */  swc1      $f0, 0x18($sp)
/* CF3E78 802412A8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* CF3E7C 802412AC E7A40020 */  swc1      $f4, 0x20($sp)
/* CF3E80 802412B0 E7A60024 */  swc1      $f6, 0x24($sp)
/* CF3E84 802412B4 AFA20010 */  sw        $v0, 0x10($sp)
/* CF3E88 802412B8 8C840080 */  lw        $a0, 0x80($a0)
/* CF3E8C 802412BC 0C0372DF */  jal       func_800DCB7C
/* CF3E90 802412C0 27A70020 */   addiu    $a3, $sp, 0x20
/* CF3E94 802412C4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* CF3E98 802412C8 3C014059 */  lui       $at, 0x4059
/* CF3E9C 802412CC 44812800 */  mtc1      $at, $f5
/* CF3EA0 802412D0 44802000 */  mtc1      $zero, $f4
/* CF3EA4 802412D4 460010A1 */  cvt.d.s   $f2, $f2
/* CF3EA8 802412D8 46241082 */  mul.d     $f2, $f2, $f4
/* CF3EAC 802412DC 00000000 */  nop
/* CF3EB0 802412E0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* CF3EB4 802412E4 46000021 */  cvt.d.s   $f0, $f0
/* CF3EB8 802412E8 46240002 */  mul.d     $f0, $f0, $f4
/* CF3EBC 802412EC 00000000 */  nop
/* CF3EC0 802412F0 3C013FE0 */  lui       $at, 0x3fe0
/* CF3EC4 802412F4 44812800 */  mtc1      $at, $f5
/* CF3EC8 802412F8 44802000 */  mtc1      $zero, $f4
/* CF3ECC 802412FC 00000000 */  nop
/* CF3ED0 80241300 46241080 */  add.d     $f2, $f2, $f4
/* CF3ED4 80241304 AE000074 */  sw        $zero, 0x74($s0)
/* CF3ED8 80241308 46240000 */  add.d     $f0, $f0, $f4
/* CF3EDC 8024130C AE000090 */  sw        $zero, 0x90($s0)
/* CF3EE0 80241310 4620120D */  trunc.w.d $f8, $f2
/* CF3EE4 80241314 E6080078 */  swc1      $f8, 0x78($s0)
/* CF3EE8 80241318 4620020D */  trunc.w.d $f8, $f0
/* CF3EEC 8024131C E6080088 */  swc1      $f8, 0x88($s0)
/* CF3EF0 80241320 8E420014 */  lw        $v0, 0x14($s2)
/* CF3EF4 80241324 AE220074 */  sw        $v0, 0x74($s1)
/* CF3EF8 80241328 8E0200B0 */  lw        $v0, 0xb0($s0)
/* CF3EFC 8024132C 34420010 */  ori       $v0, $v0, 0x10
/* CF3F00 80241330 AE0200B0 */  sw        $v0, 0xb0($s0)
/* CF3F04 80241334 8FBF0034 */  lw        $ra, 0x34($sp)
/* CF3F08 80241338 8FB20030 */  lw        $s2, 0x30($sp)
/* CF3F0C 8024133C 8FB1002C */  lw        $s1, 0x2c($sp)
/* CF3F10 80241340 8FB00028 */  lw        $s0, 0x28($sp)
/* CF3F14 80241344 03E00008 */  jr        $ra
/* CF3F18 80241348 27BD0038 */   addiu    $sp, $sp, 0x38
