.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80241E20_AD5EB0
.double 90.0

glabel D_80241E28_AD5EB8
.double 270.0

.section .text

glabel func_80240070_AD4100
/* AD4100 80240070 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* AD4104 80240074 AFB3003C */  sw        $s3, 0x3c($sp)
/* AD4108 80240078 0080982D */  daddu     $s3, $a0, $zero
/* AD410C 8024007C AFBF0044 */  sw        $ra, 0x44($sp)
/* AD4110 80240080 AFB40040 */  sw        $s4, 0x40($sp)
/* AD4114 80240084 AFB20038 */  sw        $s2, 0x38($sp)
/* AD4118 80240088 AFB10034 */  sw        $s1, 0x34($sp)
/* AD411C 8024008C AFB00030 */  sw        $s0, 0x30($sp)
/* AD4120 80240090 F7B80058 */  sdc1      $f24, 0x58($sp)
/* AD4124 80240094 F7B60050 */  sdc1      $f22, 0x50($sp)
/* AD4128 80240098 F7B40048 */  sdc1      $f20, 0x48($sp)
/* AD412C 8024009C 8E620148 */  lw        $v0, 0x148($s3)
/* AD4130 802400A0 0C00EABB */  jal       get_npc_unsafe
/* AD4134 802400A4 84440008 */   lh       $a0, 8($v0)
/* AD4138 802400A8 27A40020 */  addiu     $a0, $sp, 0x20
/* AD413C 802400AC 27A50024 */  addiu     $a1, $sp, 0x24
/* AD4140 802400B0 0040802D */  daddu     $s0, $v0, $zero
/* AD4144 802400B4 8E63000C */  lw        $v1, 0xc($s3)
/* AD4148 802400B8 8E07000C */  lw        $a3, 0xc($s0)
/* AD414C 802400BC C6000038 */  lwc1      $f0, 0x38($s0)
/* AD4150 802400C0 C6020040 */  lwc1      $f2, 0x40($s0)
/* AD4154 802400C4 8C740000 */  lw        $s4, ($v1)
/* AD4158 802400C8 24630004 */  addiu     $v1, $v1, 4
/* AD415C 802400CC C4780000 */  lwc1      $f24, ($v1)
/* AD4160 802400D0 4680C620 */  cvt.s.w   $f24, $f24
/* AD4164 802400D4 24630004 */  addiu     $v1, $v1, 4
/* AD4168 802400D8 C4740000 */  lwc1      $f20, ($v1)
/* AD416C 802400DC 4680A520 */  cvt.s.w   $f20, $f20
/* AD4170 802400E0 4406A000 */  mfc1      $a2, $f20
/* AD4174 802400E4 C4760004 */  lwc1      $f22, 4($v1)
/* AD4178 802400E8 4680B5A0 */  cvt.s.w   $f22, $f22
/* AD417C 802400EC E7A00020 */  swc1      $f0, 0x20($sp)
/* AD4180 802400F0 0C00A7E7 */  jal       add_vec2D_polar
/* AD4184 802400F4 E7A20024 */   swc1     $f2, 0x24($sp)
/* AD4188 802400F8 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* AD418C 802400FC 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* AD4190 80240100 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* AD4194 80240104 4480A000 */  mtc1      $zero, $f20
/* AD4198 80240108 8E460028 */  lw        $a2, 0x28($s2)
/* AD419C 8024010C 4407A000 */  mfc1      $a3, $f20
/* AD41A0 80240110 0C00A7B5 */  jal       dist2D
/* AD41A4 80240114 4600A386 */   mov.s    $f14, $f20
/* AD41A8 80240118 4600A306 */  mov.s     $f12, $f20
/* AD41AC 8024011C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* AD41B0 80240120 44066000 */  mfc1      $a2, $f12
/* AD41B4 80240124 8E470030 */  lw        $a3, 0x30($s2)
/* AD41B8 80240128 0C00A7B5 */  jal       dist2D
/* AD41BC 8024012C 46000506 */   mov.s    $f20, $f0
/* AD41C0 80240130 C604000C */  lwc1      $f4, 0xc($s0)
/* AD41C4 80240134 3C018024 */  lui       $at, %hi(D_80241E20_AD5EB0)
/* AD41C8 80240138 D4221E20 */  ldc1      $f2, %lo(D_80241E20_AD5EB0)($at)
/* AD41CC 8024013C 46002121 */  cvt.d.s   $f4, $f4
/* AD41D0 80240140 46222032 */  c.eq.d    $f4, $f2
/* AD41D4 80240144 00000000 */  nop
/* AD41D8 80240148 45010007 */  bc1t      .L80240168
/* AD41DC 8024014C 46000086 */   mov.s    $f2, $f0
/* AD41E0 80240150 3C018024 */  lui       $at, %hi(D_80241E28_AD5EB8)
/* AD41E4 80240154 D4201E28 */  ldc1      $f0, %lo(D_80241E28_AD5EB8)($at)
/* AD41E8 80240158 46202032 */  c.eq.d    $f4, $f0
/* AD41EC 8024015C 00000000 */  nop
/* AD41F0 80240160 45000008 */  bc1f      .L80240184
/* AD41F4 80240164 00000000 */   nop
.L80240168:
/* AD41F8 80240168 4618A03E */  c.le.s    $f20, $f24
/* AD41FC 8024016C 00000000 */  nop
/* AD4200 80240170 4500000C */  bc1f      .L802401A4
/* AD4204 80240174 0000882D */   daddu    $s1, $zero, $zero
/* AD4208 80240178 4616103E */  c.le.s    $f2, $f22
/* AD420C 8024017C 08090067 */  j         .L8024019C
/* AD4210 80240180 00000000 */   nop
.L80240184:
/* AD4214 80240184 4618103E */  c.le.s    $f2, $f24
/* AD4218 80240188 00000000 */  nop
/* AD421C 8024018C 45000005 */  bc1f      .L802401A4
/* AD4220 80240190 0000882D */   daddu    $s1, $zero, $zero
/* AD4224 80240194 4616A03E */  c.le.s    $f20, $f22
/* AD4228 80240198 00000000 */  nop
.L8024019C:
/* AD422C 8024019C 45030001 */  bc1tl     .L802401A4
/* AD4230 802401A0 24110001 */   addiu    $s1, $zero, 1
.L802401A4:
/* AD4234 802401A4 12200027 */  beqz      $s1, .L80240244
/* AD4238 802401A8 0260202D */   daddu    $a0, $s3, $zero
/* AD423C 802401AC C60C0038 */  lwc1      $f12, 0x38($s0)
/* AD4240 802401B0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* AD4244 802401B4 8E460028 */  lw        $a2, 0x28($s2)
/* AD4248 802401B8 8E470030 */  lw        $a3, 0x30($s2)
/* AD424C 802401BC C602003C */  lwc1      $f2, 0x3c($s0)
/* AD4250 802401C0 46006006 */  mov.s     $f0, $f12
/* AD4254 802401C4 46007106 */  mov.s     $f4, $f14
/* AD4258 802401C8 E7A00020 */  swc1      $f0, 0x20($sp)
/* AD425C 802401CC E7A20028 */  swc1      $f2, 0x28($sp)
/* AD4260 802401D0 0C00A7B5 */  jal       dist2D
/* AD4264 802401D4 E7A40024 */   swc1     $f4, 0x24($sp)
/* AD4268 802401D8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* AD426C 802401DC C60E0040 */  lwc1      $f14, 0x40($s0)
/* AD4270 802401E0 8E460028 */  lw        $a2, 0x28($s2)
/* AD4274 802401E4 8E470030 */  lw        $a3, 0x30($s2)
/* AD4278 802401E8 0C00A720 */  jal       atan2
/* AD427C 802401EC 46000506 */   mov.s    $f20, $f0
/* AD4280 802401F0 3C040007 */  lui       $a0, 7
/* AD4284 802401F4 34848000 */  ori       $a0, $a0, 0x8000
/* AD4288 802401F8 27A50020 */  addiu     $a1, $sp, 0x20
/* AD428C 802401FC E7B40010 */  swc1      $f20, 0x10($sp)
/* AD4290 80240200 E7A00014 */  swc1      $f0, 0x14($sp)
/* AD4294 80240204 860200A6 */  lh        $v0, 0xa6($s0)
/* AD4298 80240208 27A60028 */  addiu     $a2, $sp, 0x28
/* AD429C 8024020C 44820000 */  mtc1      $v0, $f0
/* AD42A0 80240210 00000000 */  nop
/* AD42A4 80240214 46800020 */  cvt.s.w   $f0, $f0
/* AD42A8 80240218 E7A00018 */  swc1      $f0, 0x18($sp)
/* AD42AC 8024021C 860200A8 */  lh        $v0, 0xa8($s0)
/* AD42B0 80240220 27A70024 */  addiu     $a3, $sp, 0x24
/* AD42B4 80240224 44820000 */  mtc1      $v0, $f0
/* AD42B8 80240228 00000000 */  nop
/* AD42BC 8024022C 46800020 */  cvt.s.w   $f0, $f0
/* AD42C0 80240230 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* AD42C4 80240234 E7A0001C */   swc1     $f0, 0x1c($sp)
/* AD42C8 80240238 54400001 */  bnel      $v0, $zero, .L80240240
/* AD42CC 8024023C 0000882D */   daddu    $s1, $zero, $zero
.L80240240:
/* AD42D0 80240240 0260202D */  daddu     $a0, $s3, $zero
.L80240244:
/* AD42D4 80240244 0280282D */  daddu     $a1, $s4, $zero
/* AD42D8 80240248 0C0B2026 */  jal       set_variable
/* AD42DC 8024024C 0220302D */   daddu    $a2, $s1, $zero
/* AD42E0 80240250 8FBF0044 */  lw        $ra, 0x44($sp)
/* AD42E4 80240254 8FB40040 */  lw        $s4, 0x40($sp)
/* AD42E8 80240258 8FB3003C */  lw        $s3, 0x3c($sp)
/* AD42EC 8024025C 8FB20038 */  lw        $s2, 0x38($sp)
/* AD42F0 80240260 8FB10034 */  lw        $s1, 0x34($sp)
/* AD42F4 80240264 8FB00030 */  lw        $s0, 0x30($sp)
/* AD42F8 80240268 D7B80058 */  ldc1      $f24, 0x58($sp)
/* AD42FC 8024026C D7B60050 */  ldc1      $f22, 0x50($sp)
/* AD4300 80240270 D7B40048 */  ldc1      $f20, 0x48($sp)
/* AD4304 80240274 24020002 */  addiu     $v0, $zero, 2
/* AD4308 80240278 03E00008 */  jr        $ra
/* AD430C 8024027C 27BD0060 */   addiu    $sp, $sp, 0x60
