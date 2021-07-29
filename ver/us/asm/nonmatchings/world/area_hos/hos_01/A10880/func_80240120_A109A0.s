.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245970_A161F0
.double 1.570796

.section .text

glabel func_80240120_A109A0
/* A109A0 80240120 27BDFF98 */  addiu     $sp, $sp, -0x68
/* A109A4 80240124 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* A109A8 80240128 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* A109AC 8024012C C43A1DEC */  lwc1      $f26, %lo(gCameras+0x6C)($at)
/* A109B0 80240130 3C014334 */  lui       $at, 0x4334
/* A109B4 80240134 44810000 */  mtc1      $at, $f0
/* A109B8 80240138 3C014049 */  lui       $at, 0x4049
/* A109BC 8024013C 34210FD8 */  ori       $at, $at, 0xfd8
/* A109C0 80240140 44811000 */  mtc1      $at, $f2
/* A109C4 80240144 240401F4 */  addiu     $a0, $zero, 0x1f4
/* A109C8 80240148 AFBF0034 */  sw        $ra, 0x34($sp)
/* A109CC 8024014C 4600D683 */  div.s     $f26, $f26, $f0
/* A109D0 80240150 4602D682 */  mul.s     $f26, $f26, $f2
/* A109D4 80240154 00000000 */  nop
/* A109D8 80240158 AFB00030 */  sw        $s0, 0x30($sp)
/* A109DC 8024015C F7B60040 */  sdc1      $f22, 0x40($sp)
/* A109E0 80240160 F7B40038 */  sdc1      $f20, 0x38($sp)
/* A109E4 80240164 3C018024 */  lui       $at, %hi(D_80245970_A161F0)
/* A109E8 80240168 D4205970 */  ldc1      $f0, %lo(D_80245970_A161F0)($at)
/* A109EC 8024016C 4600D521 */  cvt.d.s   $f20, $f26
/* A109F0 80240170 4620A580 */  add.d     $f22, $f20, $f0
/* A109F4 80240174 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* A109F8 80240178 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* A109FC 8024017C 4620A501 */  sub.d     $f20, $f20, $f0
/* A10A00 80240180 F7B80048 */  sdc1      $f24, 0x48($sp)
/* A10A04 80240184 4620B5A0 */  cvt.s.d   $f22, $f22
/* A10A08 80240188 0C00A67F */  jal       rand_int
/* A10A0C 8024018C 4620A520 */   cvt.s.d  $f20, $f20
/* A10A10 80240190 2442FF06 */  addiu     $v0, $v0, -0xfa
/* A10A14 80240194 4482C000 */  mtc1      $v0, $f24
/* A10A18 80240198 00000000 */  nop
/* A10A1C 8024019C 4680C620 */  cvt.s.w   $f24, $f24
/* A10A20 802401A0 0C00A67F */  jal       rand_int
/* A10A24 802401A4 240401F4 */   addiu    $a0, $zero, 0x1f4
/* A10A28 802401A8 24040064 */  addiu     $a0, $zero, 0x64
/* A10A2C 802401AC 2442FF06 */  addiu     $v0, $v0, -0xfa
/* A10A30 802401B0 44822000 */  mtc1      $v0, $f4
/* A10A34 802401B4 00000000 */  nop
/* A10A38 802401B8 46802120 */  cvt.s.w   $f4, $f4
/* A10A3C 802401BC 0C00A67F */  jal       rand_int
/* A10A40 802401C0 E7A40028 */   swc1     $f4, 0x28($sp)
/* A10A44 802401C4 24420258 */  addiu     $v0, $v0, 0x258
/* A10A48 802401C8 4482E000 */  mtc1      $v0, $f28
/* A10A4C 802401CC 00000000 */  nop
/* A10A50 802401D0 4680E720 */  cvt.s.w   $f28, $f28
/* A10A54 802401D4 0C00A85B */  jal       sin_rad
/* A10A58 802401D8 4600D306 */   mov.s    $f12, $f26
/* A10A5C 802401DC 4600E002 */  mul.s     $f0, $f28, $f0
/* A10A60 802401E0 00000000 */  nop
/* A10A64 802401E4 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* A10A68 802401E8 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* A10A6C 802401EC C6020028 */  lwc1      $f2, 0x28($s0)
/* A10A70 802401F0 46001780 */  add.s     $f30, $f2, $f0
/* A10A74 802401F4 0C00A85B */  jal       sin_rad
/* A10A78 802401F8 4600B306 */   mov.s    $f12, $f22
/* A10A7C 802401FC 4600C002 */  mul.s     $f0, $f24, $f0
/* A10A80 80240200 00000000 */  nop
/* A10A84 80240204 C602002C */  lwc1      $f2, 0x2c($s0)
/* A10A88 80240208 4600F780 */  add.s     $f30, $f30, $f0
/* A10A8C 8024020C 3C014348 */  lui       $at, 0x4348
/* A10A90 80240210 44810000 */  mtc1      $at, $f0
/* A10A94 80240214 00000000 */  nop
/* A10A98 80240218 46001080 */  add.s     $f2, $f2, $f0
/* A10A9C 8024021C 4600D306 */  mov.s     $f12, $f26
/* A10AA0 80240220 E7BE0020 */  swc1      $f30, 0x20($sp)
/* A10AA4 80240224 0C00A874 */  jal       cos_rad
/* A10AA8 80240228 E7A20024 */   swc1     $f2, 0x24($sp)
/* A10AAC 8024022C 4600E002 */  mul.s     $f0, $f28, $f0
/* A10AB0 80240230 00000000 */  nop
/* A10AB4 80240234 C61E0030 */  lwc1      $f30, 0x30($s0)
/* A10AB8 80240238 4600F781 */  sub.s     $f30, $f30, $f0
/* A10ABC 8024023C 0C00A874 */  jal       cos_rad
/* A10AC0 80240240 4600B306 */   mov.s    $f12, $f22
/* A10AC4 80240244 4600C602 */  mul.s     $f24, $f24, $f0
/* A10AC8 80240248 00000000 */  nop
/* A10ACC 8024024C 4618F781 */  sub.s     $f30, $f30, $f24
/* A10AD0 80240250 0C00A85B */  jal       sin_rad
/* A10AD4 80240254 4600D306 */   mov.s    $f12, $f26
/* A10AD8 80240258 4600E002 */  mul.s     $f0, $f28, $f0
/* A10ADC 8024025C 00000000 */  nop
/* A10AE0 80240260 C6180028 */  lwc1      $f24, 0x28($s0)
/* A10AE4 80240264 4600A306 */  mov.s     $f12, $f20
/* A10AE8 80240268 0C00A85B */  jal       sin_rad
/* A10AEC 8024026C 4600C600 */   add.s    $f24, $f24, $f0
/* A10AF0 80240270 C7A40028 */  lwc1      $f4, 0x28($sp)
/* A10AF4 80240274 46002002 */  mul.s     $f0, $f4, $f0
/* A10AF8 80240278 00000000 */  nop
/* A10AFC 8024027C 4600D306 */  mov.s     $f12, $f26
/* A10B00 80240280 C61A002C */  lwc1      $f26, 0x2c($s0)
/* A10B04 80240284 0C00A874 */  jal       cos_rad
/* A10B08 80240288 4600C600 */   add.s    $f24, $f24, $f0
/* A10B0C 8024028C 4600E702 */  mul.s     $f28, $f28, $f0
/* A10B10 80240290 00000000 */  nop
/* A10B14 80240294 C6160030 */  lwc1      $f22, 0x30($s0)
/* A10B18 80240298 4600A306 */  mov.s     $f12, $f20
/* A10B1C 8024029C 0C00A874 */  jal       cos_rad
/* A10B20 802402A0 461CB581 */   sub.s    $f22, $f22, $f28
/* A10B24 802402A4 C7A40028 */  lwc1      $f4, 0x28($sp)
/* A10B28 802402A8 46002002 */  mul.s     $f0, $f4, $f0
/* A10B2C 802402AC 00000000 */  nop
/* A10B30 802402B0 2404000A */  addiu     $a0, $zero, 0xa
/* A10B34 802402B4 0C00A67F */  jal       rand_int
/* A10B38 802402B8 4600B581 */   sub.s    $f22, $f22, $f0
/* A10B3C 802402BC 0000202D */  daddu     $a0, $zero, $zero
/* A10B40 802402C0 2442000A */  addiu     $v0, $v0, 0xa
/* A10B44 802402C4 8FA50020 */  lw        $a1, 0x20($sp)
/* A10B48 802402C8 8FA60024 */  lw        $a2, 0x24($sp)
/* A10B4C 802402CC 4407F000 */  mfc1      $a3, $f30
/* A10B50 802402D0 44820000 */  mtc1      $v0, $f0
/* A10B54 802402D4 00000000 */  nop
/* A10B58 802402D8 46800020 */  cvt.s.w   $f0, $f0
/* A10B5C 802402DC E7B80010 */  swc1      $f24, 0x10($sp)
/* A10B60 802402E0 E7BA0014 */  swc1      $f26, 0x14($sp)
/* A10B64 802402E4 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A10B68 802402E8 0C01BF8C */  jal       playFX_0F
/* A10B6C 802402EC E7B60018 */   swc1     $f22, 0x18($sp)
/* A10B70 802402F0 8FBF0034 */  lw        $ra, 0x34($sp)
/* A10B74 802402F4 8FB00030 */  lw        $s0, 0x30($sp)
/* A10B78 802402F8 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* A10B7C 802402FC D7BC0058 */  ldc1      $f28, 0x58($sp)
/* A10B80 80240300 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* A10B84 80240304 D7B80048 */  ldc1      $f24, 0x48($sp)
/* A10B88 80240308 D7B60040 */  ldc1      $f22, 0x40($sp)
/* A10B8C 8024030C D7B40038 */  ldc1      $f20, 0x38($sp)
/* A10B90 80240310 24020002 */  addiu     $v0, $zero, 2
/* A10B94 80240314 03E00008 */  jr        $ra
/* A10B98 80240318 27BD0068 */   addiu    $sp, $sp, 0x68
