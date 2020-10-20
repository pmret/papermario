.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413AC_CC4BBC
/* CC4BBC 802413AC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CC4BC0 802413B0 AFB00028 */  sw        $s0, 0x28($sp)
/* CC4BC4 802413B4 00A0802D */  daddu     $s0, $a1, $zero
/* CC4BC8 802413B8 AFB1002C */  sw        $s1, 0x2c($sp)
/* CC4BCC 802413BC 00C0882D */  daddu     $s1, $a2, $zero
/* CC4BD0 802413C0 AFBF0034 */  sw        $ra, 0x34($sp)
/* CC4BD4 802413C4 AFB20030 */  sw        $s2, 0x30($sp)
/* CC4BD8 802413C8 AE200070 */  sw        $zero, 0x70($s1)
/* CC4BDC 802413CC 8C830000 */  lw        $v1, ($a0)
/* CC4BE0 802413D0 2402FDFF */  addiu     $v0, $zero, -0x201
/* CC4BE4 802413D4 A480008E */  sh        $zero, 0x8e($a0)
/* CC4BE8 802413D8 00621824 */  and       $v1, $v1, $v0
/* CC4BEC 802413DC 34650800 */  ori       $a1, $v1, 0x800
/* CC4BF0 802413E0 AC850000 */  sw        $a1, ($a0)
/* CC4BF4 802413E4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* CC4BF8 802413E8 8C420034 */  lw        $v0, 0x34($v0)
/* CC4BFC 802413EC 10400003 */  beqz      $v0, .L802413FC
/* CC4C00 802413F0 00E0902D */   daddu    $s2, $a3, $zero
/* CC4C04 802413F4 08090501 */  j         .L80241404
/* CC4C08 802413F8 34620808 */   ori      $v0, $v1, 0x808
.L802413FC:
/* CC4C0C 802413FC 2402FFF7 */  addiu     $v0, $zero, -9
/* CC4C10 80241400 00A21024 */  and       $v0, $a1, $v0
.L80241404:
/* CC4C14 80241404 AC820000 */  sw        $v0, ($a0)
/* CC4C18 80241408 27A20024 */  addiu     $v0, $sp, 0x24
/* CC4C1C 8024140C 27A50018 */  addiu     $a1, $sp, 0x18
/* CC4C20 80241410 C4800038 */  lwc1      $f0, 0x38($a0)
/* CC4C24 80241414 C482003C */  lwc1      $f2, 0x3c($a0)
/* CC4C28 80241418 C4840040 */  lwc1      $f4, 0x40($a0)
/* CC4C2C 8024141C 3C01447A */  lui       $at, 0x447a
/* CC4C30 80241420 44813000 */  mtc1      $at, $f6
/* CC4C34 80241424 27A6001C */  addiu     $a2, $sp, 0x1c
/* CC4C38 80241428 E7A00018 */  swc1      $f0, 0x18($sp)
/* CC4C3C 8024142C E7A2001C */  swc1      $f2, 0x1c($sp)
/* CC4C40 80241430 E7A40020 */  swc1      $f4, 0x20($sp)
/* CC4C44 80241434 E7A60024 */  swc1      $f6, 0x24($sp)
/* CC4C48 80241438 AFA20010 */  sw        $v0, 0x10($sp)
/* CC4C4C 8024143C 8C840080 */  lw        $a0, 0x80($a0)
/* CC4C50 80241440 0C0372DF */  jal       func_800DCB7C
/* CC4C54 80241444 27A70020 */   addiu    $a3, $sp, 0x20
/* CC4C58 80241448 C7A20024 */  lwc1      $f2, 0x24($sp)
/* CC4C5C 8024144C 3C014059 */  lui       $at, 0x4059
/* CC4C60 80241450 44812800 */  mtc1      $at, $f5
/* CC4C64 80241454 44802000 */  mtc1      $zero, $f4
/* CC4C68 80241458 460010A1 */  cvt.d.s   $f2, $f2
/* CC4C6C 8024145C 46241082 */  mul.d     $f2, $f2, $f4
/* CC4C70 80241460 00000000 */  nop       
/* CC4C74 80241464 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* CC4C78 80241468 46000021 */  cvt.d.s   $f0, $f0
/* CC4C7C 8024146C 46240002 */  mul.d     $f0, $f0, $f4
/* CC4C80 80241470 00000000 */  nop       
/* CC4C84 80241474 3C013FE0 */  lui       $at, 0x3fe0
/* CC4C88 80241478 44812800 */  mtc1      $at, $f5
/* CC4C8C 8024147C 44802000 */  mtc1      $zero, $f4
/* CC4C90 80241480 00000000 */  nop       
/* CC4C94 80241484 46241080 */  add.d     $f2, $f2, $f4
/* CC4C98 80241488 AE000074 */  sw        $zero, 0x74($s0)
/* CC4C9C 8024148C 46240000 */  add.d     $f0, $f0, $f4
/* CC4CA0 80241490 AE000090 */  sw        $zero, 0x90($s0)
/* CC4CA4 80241494 4620120D */  trunc.w.d $f8, $f2
/* CC4CA8 80241498 E6080078 */  swc1      $f8, 0x78($s0)
/* CC4CAC 8024149C 4620020D */  trunc.w.d $f8, $f0
/* CC4CB0 802414A0 E6080088 */  swc1      $f8, 0x88($s0)
/* CC4CB4 802414A4 8E420014 */  lw        $v0, 0x14($s2)
/* CC4CB8 802414A8 AE220074 */  sw        $v0, 0x74($s1)
/* CC4CBC 802414AC 8E0200B0 */  lw        $v0, 0xb0($s0)
/* CC4CC0 802414B0 34420010 */  ori       $v0, $v0, 0x10
/* CC4CC4 802414B4 AE0200B0 */  sw        $v0, 0xb0($s0)
/* CC4CC8 802414B8 8FBF0034 */  lw        $ra, 0x34($sp)
/* CC4CCC 802414BC 8FB20030 */  lw        $s2, 0x30($sp)
/* CC4CD0 802414C0 8FB1002C */  lw        $s1, 0x2c($sp)
/* CC4CD4 802414C4 8FB00028 */  lw        $s0, 0x28($sp)
/* CC4CD8 802414C8 03E00008 */  jr        $ra
/* CC4CDC 802414CC 27BD0038 */   addiu    $sp, $sp, 0x38
