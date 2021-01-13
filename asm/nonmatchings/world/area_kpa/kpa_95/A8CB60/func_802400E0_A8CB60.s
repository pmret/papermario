.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E0_A8CB60
/* A8CB60 802400E0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A8CB64 802400E4 AFB50024 */  sw        $s5, 0x24($sp)
/* A8CB68 802400E8 0080A82D */  daddu     $s5, $a0, $zero
/* A8CB6C 802400EC AFBF002C */  sw        $ra, 0x2c($sp)
/* A8CB70 802400F0 AFB60028 */  sw        $s6, 0x28($sp)
/* A8CB74 802400F4 AFB40020 */  sw        $s4, 0x20($sp)
/* A8CB78 802400F8 AFB3001C */  sw        $s3, 0x1c($sp)
/* A8CB7C 802400FC AFB20018 */  sw        $s2, 0x18($sp)
/* A8CB80 80240100 AFB10014 */  sw        $s1, 0x14($sp)
/* A8CB84 80240104 AFB00010 */  sw        $s0, 0x10($sp)
/* A8CB88 80240108 F7B80040 */  sdc1      $f24, 0x40($sp)
/* A8CB8C 8024010C F7B60038 */  sdc1      $f22, 0x38($sp)
/* A8CB90 80240110 F7B40030 */  sdc1      $f20, 0x30($sp)
/* A8CB94 80240114 8EB30148 */  lw        $s3, 0x148($s5)
/* A8CB98 80240118 86640008 */  lh        $a0, 8($s3)
/* A8CB9C 8024011C 0C00EABB */  jal       get_npc_unsafe
/* A8CBA0 80240120 00A0B02D */   daddu    $s6, $a1, $zero
/* A8CBA4 80240124 0040A02D */  daddu     $s4, $v0, $zero
/* A8CBA8 80240128 AEA00074 */  sw        $zero, 0x74($s5)
/* A8CBAC 8024012C C6980038 */  lwc1      $f24, 0x38($s4)
/* A8CBB0 80240130 C6960040 */  lwc1      $f22, 0x40($s4)
/* A8CBB4 80240134 0000902D */  daddu     $s2, $zero, $zero
/* A8CBB8 80240138 AEA00078 */  sw        $zero, 0x78($s5)
/* A8CBBC 8024013C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* A8CBC0 80240140 8C620000 */  lw        $v0, ($v1)
/* A8CBC4 80240144 3C0146FF */  lui       $at, 0x46ff
/* A8CBC8 80240148 3421FE00 */  ori       $at, $at, 0xfe00
/* A8CBCC 8024014C 4481A000 */  mtc1      $at, $f20
/* A8CBD0 80240150 18400018 */  blez      $v0, .L802401B4
/* A8CBD4 80240154 0240802D */   daddu    $s0, $s2, $zero
/* A8CBD8 80240158 0240882D */  daddu     $s1, $s2, $zero
.L8024015C:
/* A8CBDC 8024015C 02231021 */  addu      $v0, $s1, $v1
/* A8CBE0 80240160 4600C306 */  mov.s     $f12, $f24
/* A8CBE4 80240164 C4440004 */  lwc1      $f4, 4($v0)
/* A8CBE8 80240168 46802120 */  cvt.s.w   $f4, $f4
/* A8CBEC 8024016C 44062000 */  mfc1      $a2, $f4
/* A8CBF0 80240170 C444000C */  lwc1      $f4, 0xc($v0)
/* A8CBF4 80240174 46802120 */  cvt.s.w   $f4, $f4
/* A8CBF8 80240178 44072000 */  mfc1      $a3, $f4
/* A8CBFC 8024017C 0C00A7B5 */  jal       dist2D
/* A8CC00 80240180 4600B386 */   mov.s    $f14, $f22
/* A8CC04 80240184 4614003C */  c.lt.s    $f0, $f20
/* A8CC08 80240188 00000000 */  nop
/* A8CC0C 8024018C 45000003 */  bc1f      .L8024019C
/* A8CC10 80240190 2631000C */   addiu    $s1, $s1, 0xc
/* A8CC14 80240194 46000506 */  mov.s     $f20, $f0
/* A8CC18 80240198 AEB20078 */  sw        $s2, 0x78($s5)
.L8024019C:
/* A8CC1C 8024019C 8E6300D0 */  lw        $v1, 0xd0($s3)
/* A8CC20 802401A0 26100001 */  addiu     $s0, $s0, 1
/* A8CC24 802401A4 8C620000 */  lw        $v0, ($v1)
/* A8CC28 802401A8 0202102A */  slt       $v0, $s0, $v0
/* A8CC2C 802401AC 1440FFEB */  bnez      $v0, .L8024015C
/* A8CC30 802401B0 26520001 */   addiu    $s2, $s2, 1
.L802401B4:
/* A8CC34 802401B4 8E6200CC */  lw        $v0, 0xcc($s3)
/* A8CC38 802401B8 8C420004 */  lw        $v0, 4($v0)
/* A8CC3C 802401BC AE820028 */  sw        $v0, 0x28($s4)
/* A8CC40 802401C0 8E6200D0 */  lw        $v0, 0xd0($s3)
/* A8CC44 802401C4 8C42007C */  lw        $v0, 0x7c($v0)
/* A8CC48 802401C8 04410004 */  bgez      $v0, .L802401DC
/* A8CC4C 802401CC 00000000 */   nop
/* A8CC50 802401D0 C6C00000 */  lwc1      $f0, ($s6)
/* A8CC54 802401D4 0809007F */  j         .L802401FC
/* A8CC58 802401D8 E6800018 */   swc1     $f0, 0x18($s4)
.L802401DC:
/* A8CC5C 802401DC 3C018024 */  lui       $at, %hi(D_80245A00)
/* A8CC60 802401E0 D4225A00 */  ldc1      $f2, %lo(D_80245A00)($at)
/* A8CC64 802401E4 44820000 */  mtc1      $v0, $f0
/* A8CC68 802401E8 00000000 */  nop
/* A8CC6C 802401EC 46800021 */  cvt.d.w   $f0, $f0
/* A8CC70 802401F0 46220003 */  div.d     $f0, $f0, $f2
/* A8CC74 802401F4 46200020 */  cvt.s.d   $f0, $f0
/* A8CC78 802401F8 E6800018 */  swc1      $f0, 0x18($s4)
.L802401FC:
/* A8CC7C 802401FC 24020001 */  addiu     $v0, $zero, 1
/* A8CC80 80240200 AEA20070 */  sw        $v0, 0x70($s5)
/* A8CC84 80240204 8FBF002C */  lw        $ra, 0x2c($sp)
/* A8CC88 80240208 8FB60028 */  lw        $s6, 0x28($sp)
/* A8CC8C 8024020C 8FB50024 */  lw        $s5, 0x24($sp)
/* A8CC90 80240210 8FB40020 */  lw        $s4, 0x20($sp)
/* A8CC94 80240214 8FB3001C */  lw        $s3, 0x1c($sp)
/* A8CC98 80240218 8FB20018 */  lw        $s2, 0x18($sp)
/* A8CC9C 8024021C 8FB10014 */  lw        $s1, 0x14($sp)
/* A8CCA0 80240220 8FB00010 */  lw        $s0, 0x10($sp)
/* A8CCA4 80240224 D7B80040 */  ldc1      $f24, 0x40($sp)
/* A8CCA8 80240228 D7B60038 */  ldc1      $f22, 0x38($sp)
/* A8CCAC 8024022C D7B40030 */  ldc1      $f20, 0x30($sp)
/* A8CCB0 80240230 03E00008 */  jr        $ra
/* A8CCB4 80240234 27BD0048 */   addiu    $sp, $sp, 0x48
