.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80244B40_A10830
.double 1.570796

.section .text

glabel func_80240170_A0BE60
/* A0BE60 80240170 27BDFF98 */  addiu     $sp, $sp, -0x68
/* A0BE64 80240174 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* A0BE68 80240178 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* A0BE6C 8024017C C43A1DEC */  lwc1      $f26, %lo(gCameras+0x6C)($at)
/* A0BE70 80240180 3C014334 */  lui       $at, 0x4334
/* A0BE74 80240184 44810000 */  mtc1      $at, $f0
/* A0BE78 80240188 3C014049 */  lui       $at, 0x4049
/* A0BE7C 8024018C 34210FD8 */  ori       $at, $at, 0xfd8
/* A0BE80 80240190 44811000 */  mtc1      $at, $f2
/* A0BE84 80240194 240401F4 */  addiu     $a0, $zero, 0x1f4
/* A0BE88 80240198 AFBF0034 */  sw        $ra, 0x34($sp)
/* A0BE8C 8024019C 4600D683 */  div.s     $f26, $f26, $f0
/* A0BE90 802401A0 4602D682 */  mul.s     $f26, $f26, $f2
/* A0BE94 802401A4 00000000 */  nop
/* A0BE98 802401A8 AFB00030 */  sw        $s0, 0x30($sp)
/* A0BE9C 802401AC F7B60040 */  sdc1      $f22, 0x40($sp)
/* A0BEA0 802401B0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* A0BEA4 802401B4 3C018024 */  lui       $at, %hi(D_80244B40_A10830)
/* A0BEA8 802401B8 D4204B40 */  ldc1      $f0, %lo(D_80244B40_A10830)($at)
/* A0BEAC 802401BC 4600D521 */  cvt.d.s   $f20, $f26
/* A0BEB0 802401C0 4620A580 */  add.d     $f22, $f20, $f0
/* A0BEB4 802401C4 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* A0BEB8 802401C8 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* A0BEBC 802401CC 4620A501 */  sub.d     $f20, $f20, $f0
/* A0BEC0 802401D0 F7B80048 */  sdc1      $f24, 0x48($sp)
/* A0BEC4 802401D4 4620B5A0 */  cvt.s.d   $f22, $f22
/* A0BEC8 802401D8 0C00A67F */  jal       rand_int
/* A0BECC 802401DC 4620A520 */   cvt.s.d  $f20, $f20
/* A0BED0 802401E0 2442FF06 */  addiu     $v0, $v0, -0xfa
/* A0BED4 802401E4 4482C000 */  mtc1      $v0, $f24
/* A0BED8 802401E8 00000000 */  nop
/* A0BEDC 802401EC 4680C620 */  cvt.s.w   $f24, $f24
/* A0BEE0 802401F0 0C00A67F */  jal       rand_int
/* A0BEE4 802401F4 240401F4 */   addiu    $a0, $zero, 0x1f4
/* A0BEE8 802401F8 24040064 */  addiu     $a0, $zero, 0x64
/* A0BEEC 802401FC 2442FF06 */  addiu     $v0, $v0, -0xfa
/* A0BEF0 80240200 44822000 */  mtc1      $v0, $f4
/* A0BEF4 80240204 00000000 */  nop
/* A0BEF8 80240208 46802120 */  cvt.s.w   $f4, $f4
/* A0BEFC 8024020C 0C00A67F */  jal       rand_int
/* A0BF00 80240210 E7A40028 */   swc1     $f4, 0x28($sp)
/* A0BF04 80240214 24420258 */  addiu     $v0, $v0, 0x258
/* A0BF08 80240218 4482E000 */  mtc1      $v0, $f28
/* A0BF0C 8024021C 00000000 */  nop
/* A0BF10 80240220 4680E720 */  cvt.s.w   $f28, $f28
/* A0BF14 80240224 0C00A85B */  jal       sin_rad
/* A0BF18 80240228 4600D306 */   mov.s    $f12, $f26
/* A0BF1C 8024022C 4600E002 */  mul.s     $f0, $f28, $f0
/* A0BF20 80240230 00000000 */  nop
/* A0BF24 80240234 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* A0BF28 80240238 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* A0BF2C 8024023C C6020028 */  lwc1      $f2, 0x28($s0)
/* A0BF30 80240240 46001780 */  add.s     $f30, $f2, $f0
/* A0BF34 80240244 0C00A85B */  jal       sin_rad
/* A0BF38 80240248 4600B306 */   mov.s    $f12, $f22
/* A0BF3C 8024024C 4600C002 */  mul.s     $f0, $f24, $f0
/* A0BF40 80240250 00000000 */  nop
/* A0BF44 80240254 C602002C */  lwc1      $f2, 0x2c($s0)
/* A0BF48 80240258 4600F780 */  add.s     $f30, $f30, $f0
/* A0BF4C 8024025C 3C014348 */  lui       $at, 0x4348
/* A0BF50 80240260 44810000 */  mtc1      $at, $f0
/* A0BF54 80240264 00000000 */  nop
/* A0BF58 80240268 46001080 */  add.s     $f2, $f2, $f0
/* A0BF5C 8024026C 4600D306 */  mov.s     $f12, $f26
/* A0BF60 80240270 E7BE0020 */  swc1      $f30, 0x20($sp)
/* A0BF64 80240274 0C00A874 */  jal       cos_rad
/* A0BF68 80240278 E7A20024 */   swc1     $f2, 0x24($sp)
/* A0BF6C 8024027C 4600E002 */  mul.s     $f0, $f28, $f0
/* A0BF70 80240280 00000000 */  nop
/* A0BF74 80240284 C61E0030 */  lwc1      $f30, 0x30($s0)
/* A0BF78 80240288 4600F781 */  sub.s     $f30, $f30, $f0
/* A0BF7C 8024028C 0C00A874 */  jal       cos_rad
/* A0BF80 80240290 4600B306 */   mov.s    $f12, $f22
/* A0BF84 80240294 4600C602 */  mul.s     $f24, $f24, $f0
/* A0BF88 80240298 00000000 */  nop
/* A0BF8C 8024029C 4618F781 */  sub.s     $f30, $f30, $f24
/* A0BF90 802402A0 0C00A85B */  jal       sin_rad
/* A0BF94 802402A4 4600D306 */   mov.s    $f12, $f26
/* A0BF98 802402A8 4600E002 */  mul.s     $f0, $f28, $f0
/* A0BF9C 802402AC 00000000 */  nop
/* A0BFA0 802402B0 C6180028 */  lwc1      $f24, 0x28($s0)
/* A0BFA4 802402B4 4600A306 */  mov.s     $f12, $f20
/* A0BFA8 802402B8 0C00A85B */  jal       sin_rad
/* A0BFAC 802402BC 4600C600 */   add.s    $f24, $f24, $f0
/* A0BFB0 802402C0 C7A40028 */  lwc1      $f4, 0x28($sp)
/* A0BFB4 802402C4 46002002 */  mul.s     $f0, $f4, $f0
/* A0BFB8 802402C8 00000000 */  nop
/* A0BFBC 802402CC 4600D306 */  mov.s     $f12, $f26
/* A0BFC0 802402D0 C61A002C */  lwc1      $f26, 0x2c($s0)
/* A0BFC4 802402D4 0C00A874 */  jal       cos_rad
/* A0BFC8 802402D8 4600C600 */   add.s    $f24, $f24, $f0
/* A0BFCC 802402DC 4600E702 */  mul.s     $f28, $f28, $f0
/* A0BFD0 802402E0 00000000 */  nop
/* A0BFD4 802402E4 C6160030 */  lwc1      $f22, 0x30($s0)
/* A0BFD8 802402E8 4600A306 */  mov.s     $f12, $f20
/* A0BFDC 802402EC 0C00A874 */  jal       cos_rad
/* A0BFE0 802402F0 461CB581 */   sub.s    $f22, $f22, $f28
/* A0BFE4 802402F4 C7A40028 */  lwc1      $f4, 0x28($sp)
/* A0BFE8 802402F8 46002002 */  mul.s     $f0, $f4, $f0
/* A0BFEC 802402FC 00000000 */  nop
/* A0BFF0 80240300 2404000A */  addiu     $a0, $zero, 0xa
/* A0BFF4 80240304 0C00A67F */  jal       rand_int
/* A0BFF8 80240308 4600B581 */   sub.s    $f22, $f22, $f0
/* A0BFFC 8024030C 0000202D */  daddu     $a0, $zero, $zero
/* A0C000 80240310 2442000A */  addiu     $v0, $v0, 0xa
/* A0C004 80240314 8FA50020 */  lw        $a1, 0x20($sp)
/* A0C008 80240318 8FA60024 */  lw        $a2, 0x24($sp)
/* A0C00C 8024031C 4407F000 */  mfc1      $a3, $f30
/* A0C010 80240320 44820000 */  mtc1      $v0, $f0
/* A0C014 80240324 00000000 */  nop
/* A0C018 80240328 46800020 */  cvt.s.w   $f0, $f0
/* A0C01C 8024032C E7B80010 */  swc1      $f24, 0x10($sp)
/* A0C020 80240330 E7BA0014 */  swc1      $f26, 0x14($sp)
/* A0C024 80240334 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A0C028 80240338 0C01BF8C */  jal       playFX_0F
/* A0C02C 8024033C E7B60018 */   swc1     $f22, 0x18($sp)
/* A0C030 80240340 8FBF0034 */  lw        $ra, 0x34($sp)
/* A0C034 80240344 8FB00030 */  lw        $s0, 0x30($sp)
/* A0C038 80240348 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* A0C03C 8024034C D7BC0058 */  ldc1      $f28, 0x58($sp)
/* A0C040 80240350 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* A0C044 80240354 D7B80048 */  ldc1      $f24, 0x48($sp)
/* A0C048 80240358 D7B60040 */  ldc1      $f22, 0x40($sp)
/* A0C04C 8024035C D7B40038 */  ldc1      $f20, 0x38($sp)
/* A0C050 80240360 24020002 */  addiu     $v0, $zero, 2
/* A0C054 80240364 03E00008 */  jr        $ra
/* A0C058 80240368 27BD0068 */   addiu    $sp, $sp, 0x68
