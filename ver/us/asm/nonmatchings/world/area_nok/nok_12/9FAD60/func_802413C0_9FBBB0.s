.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245AD8_A002C8
.double 32767.0

.section .text

glabel func_802413C0_9FBBB0
/* 9FBBB0 802413C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9FBBB4 802413C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FBBB8 802413C8 0080882D */  daddu     $s1, $a0, $zero
/* 9FBBBC 802413CC AFBF001C */  sw        $ra, 0x1c($sp)
/* 9FBBC0 802413D0 AFB20018 */  sw        $s2, 0x18($sp)
/* 9FBBC4 802413D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FBBC8 802413D8 8E300148 */  lw        $s0, 0x148($s1)
/* 9FBBCC 802413DC 86040008 */  lh        $a0, 8($s0)
/* 9FBBD0 802413E0 0C00EABB */  jal       get_npc_unsafe
/* 9FBBD4 802413E4 00A0902D */   daddu    $s2, $a1, $zero
/* 9FBBD8 802413E8 8E230078 */  lw        $v1, 0x78($s1)
/* 9FBBDC 802413EC 24630001 */  addiu     $v1, $v1, 1
/* 9FBBE0 802413F0 AE230078 */  sw        $v1, 0x78($s1)
/* 9FBBE4 802413F4 8E0400D0 */  lw        $a0, 0xd0($s0)
/* 9FBBE8 802413F8 8C840000 */  lw        $a0, ($a0)
/* 9FBBEC 802413FC 0064182A */  slt       $v1, $v1, $a0
/* 9FBBF0 80241400 14600002 */  bnez      $v1, .L8024140C
/* 9FBBF4 80241404 0040282D */   daddu    $a1, $v0, $zero
/* 9FBBF8 80241408 AE200078 */  sw        $zero, 0x78($s1)
.L8024140C:
/* 9FBBFC 8024140C 8E0200CC */  lw        $v0, 0xcc($s0)
/* 9FBC00 80241410 8C420004 */  lw        $v0, 4($v0)
/* 9FBC04 80241414 ACA20028 */  sw        $v0, 0x28($a1)
/* 9FBC08 80241418 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 9FBC0C 8024141C 8C42007C */  lw        $v0, 0x7c($v0)
/* 9FBC10 80241420 04410004 */  bgez      $v0, .L80241434
/* 9FBC14 80241424 00000000 */   nop
/* 9FBC18 80241428 C6400000 */  lwc1      $f0, ($s2)
/* 9FBC1C 8024142C 08090515 */  j         .L80241454
/* 9FBC20 80241430 E4A00018 */   swc1     $f0, 0x18($a1)
.L80241434:
/* 9FBC24 80241434 3C018024 */  lui       $at, %hi(D_80245AD8_A002C8)
/* 9FBC28 80241438 D4225AD8 */  ldc1      $f2, %lo(D_80245AD8_A002C8)($at)
/* 9FBC2C 8024143C 44820000 */  mtc1      $v0, $f0
/* 9FBC30 80241440 00000000 */  nop
/* 9FBC34 80241444 46800021 */  cvt.d.w   $f0, $f0
/* 9FBC38 80241448 46220003 */  div.d     $f0, $f0, $f2
/* 9FBC3C 8024144C 46200020 */  cvt.s.d   $f0, $f0
/* 9FBC40 80241450 E4A00018 */  swc1      $f0, 0x18($a1)
.L80241454:
/* 9FBC44 80241454 24020001 */  addiu     $v0, $zero, 1
/* 9FBC48 80241458 AE220070 */  sw        $v0, 0x70($s1)
/* 9FBC4C 8024145C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9FBC50 80241460 8FB20018 */  lw        $s2, 0x18($sp)
/* 9FBC54 80241464 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FBC58 80241468 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FBC5C 8024146C 03E00008 */  jr        $ra
/* 9FBC60 80241470 27BD0020 */   addiu    $sp, $sp, 0x20
