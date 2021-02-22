.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002F4E0
/* A8E0 8002F4E0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A8E4 8002F4E4 AFB00010 */  sw        $s0, 0x10($sp)
/* A8E8 8002F4E8 0080802D */  daddu     $s0, $a0, $zero
/* A8EC 8002F4EC AFBF0014 */  sw        $ra, 0x14($sp)
/* A8F0 8002F4F0 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* A8F4 8002F4F4 F7B80028 */  sdc1      $f24, 0x28($sp)
/* A8F8 8002F4F8 F7B60020 */  sdc1      $f22, 0x20($sp)
/* A8FC 8002F4FC F7B40018 */  sdc1      $f20, 0x18($sp)
/* A900 8002F500 86020006 */  lh        $v0, 6($s0)
/* A904 8002F504 10400011 */  beqz      $v0, .L8002F54C
/* A908 8002F508 00000000 */   nop
/* A90C 8002F50C 3C01800A */  lui       $at, %hi(D_8009A5CC)
/* A910 8002F510 C420A5CC */  lwc1      $f0, %lo(D_8009A5CC)($at)
/* A914 8002F514 3C01447A */  lui       $at, 0x447a
/* A918 8002F518 44811000 */  mtc1      $at, $f2
/* A91C 8002F51C AE000048 */  sw        $zero, 0x48($s0)
/* A920 8002F520 C6060048 */  lwc1      $f6, 0x48($s0)
/* A924 8002F524 AE00004C */  sw        $zero, 0x4c($s0)
/* A928 8002F528 C604004C */  lwc1      $f4, 0x4c($s0)
/* A92C 8002F52C AE000050 */  sw        $zero, 0x50($s0)
/* A930 8002F530 46001083 */  div.s     $f2, $f2, $f0
/* A934 8002F534 C6000050 */  lwc1      $f0, 0x50($s0)
/* A938 8002F538 A6000006 */  sh        $zero, 6($s0)
/* A93C 8002F53C 46020001 */  sub.s     $f0, $f0, $f2
/* A940 8002F540 E606003C */  swc1      $f6, 0x3c($s0)
/* A944 8002F544 E6040040 */  swc1      $f4, 0x40($s0)
/* A948 8002F548 E6000044 */  swc1      $f0, 0x44($s0)
.L8002F54C:
/* A94C 8002F54C C60C003C */  lwc1      $f12, 0x3c($s0)
/* A950 8002F550 C60E0044 */  lwc1      $f14, 0x44($s0)
/* A954 8002F554 8E060048 */  lw        $a2, 0x48($s0)
/* A958 8002F558 8E070050 */  lw        $a3, 0x50($s0)
/* A95C 8002F55C 4480C000 */  mtc1      $zero, $f24
/* A960 8002F560 0C00A710 */  jal       func_80029C40
/* A964 8002F564 00000000 */   nop
/* A968 8002F568 4600C306 */  mov.s     $f12, $f24
/* A96C 8002F56C 4600C386 */  mov.s     $f14, $f24
/* A970 8002F570 C6040048 */  lwc1      $f4, 0x48($s0)
/* A974 8002F574 C602003C */  lwc1      $f2, 0x3c($s0)
/* A978 8002F578 C6140050 */  lwc1      $f20, 0x50($s0)
/* A97C 8002F57C 46022581 */  sub.s     $f22, $f4, $f2
/* A980 8002F580 C6020044 */  lwc1      $f2, 0x44($s0)
/* A984 8002F584 C604004C */  lwc1      $f4, 0x4c($s0)
/* A988 8002F588 4602A501 */  sub.s     $f20, $f20, $f2
/* A98C 8002F58C C6020040 */  lwc1      $f2, 0x40($s0)
/* A990 8002F590 4406B000 */  mfc1      $a2, $f22
/* A994 8002F594 4407A000 */  mfc1      $a3, $f20
/* A998 8002F598 46022681 */  sub.s     $f26, $f4, $f2
/* A99C 8002F59C 0C00A710 */  jal       func_80029C40
/* A9A0 8002F5A0 E600006C */   swc1     $f0, 0x6c($s0)
/* A9A4 8002F5A4 4616B082 */  mul.s     $f2, $f22, $f22
/* A9A8 8002F5A8 00000000 */  nop
/* A9AC 8002F5AC 4614A502 */  mul.s     $f20, $f20, $f20
/* A9B0 8002F5B0 00000000 */  nop
/* A9B4 8002F5B4 46141300 */  add.s     $f12, $f2, $f20
/* A9B8 8002F5B8 46000007 */  neg.s     $f0, $f0
/* A9BC 8002F5BC E6000090 */  swc1      $f0, 0x90($s0)
/* A9C0 8002F5C0 46006004 */  sqrt.s    $f0, $f12
/* A9C4 8002F5C4 46000032 */  c.eq.s    $f0, $f0
/* A9C8 8002F5C8 00000000 */  nop
/* A9CC 8002F5CC 45030004 */  bc1tl     .L8002F5E0
/* A9D0 8002F5D0 4600C306 */   mov.s    $f12, $f24
/* A9D4 8002F5D4 0C0187B0 */  jal       func_80061EC0
/* A9D8 8002F5D8 00000000 */   nop
/* A9DC 8002F5DC 4600C306 */  mov.s     $f12, $f24
.L8002F5E0:
/* A9E0 8002F5E0 46000007 */  neg.s     $f0, $f0
/* A9E4 8002F5E4 4406D000 */  mfc1      $a2, $f26
/* A9E8 8002F5E8 44070000 */  mfc1      $a3, $f0
/* A9EC 8002F5EC 0C00A710 */  jal       func_80029C40
/* A9F0 8002F5F0 46006386 */   mov.s    $f14, $f12
/* A9F4 8002F5F4 E6000094 */  swc1      $f0, 0x94($s0)
/* A9F8 8002F5F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* A9FC 8002F5FC 8FB00010 */  lw        $s0, 0x10($sp)
/* AA00 8002F600 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* AA04 8002F604 D7B80028 */  ldc1      $f24, 0x28($sp)
/* AA08 8002F608 D7B60020 */  ldc1      $f22, 0x20($sp)
/* AA0C 8002F60C D7B40018 */  ldc1      $f20, 0x18($sp)
/* AA10 8002F610 03E00008 */  jr        $ra
/* AA14 8002F614 27BD0038 */   addiu    $sp, $sp, 0x38
/* AA18 8002F618 00000000 */  nop
/* AA1C 8002F61C 00000000 */  nop
