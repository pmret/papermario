.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240060_AED470
/* AED470 80240060 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* AED474 80240064 AFB3003C */  sw        $s3, 0x3c($sp)
/* AED478 80240068 0080982D */  daddu     $s3, $a0, $zero
/* AED47C 8024006C AFBF0044 */  sw        $ra, 0x44($sp)
/* AED480 80240070 AFB40040 */  sw        $s4, 0x40($sp)
/* AED484 80240074 AFB20038 */  sw        $s2, 0x38($sp)
/* AED488 80240078 AFB10034 */  sw        $s1, 0x34($sp)
/* AED48C 8024007C AFB00030 */  sw        $s0, 0x30($sp)
/* AED490 80240080 F7B80058 */  sdc1      $f24, 0x58($sp)
/* AED494 80240084 F7B60050 */  sdc1      $f22, 0x50($sp)
/* AED498 80240088 F7B40048 */  sdc1      $f20, 0x48($sp)
/* AED49C 8024008C 8E620148 */  lw        $v0, 0x148($s3)
/* AED4A0 80240090 0C00EABB */  jal       get_npc_unsafe
/* AED4A4 80240094 84440008 */   lh       $a0, 8($v0)
/* AED4A8 80240098 27A40020 */  addiu     $a0, $sp, 0x20
/* AED4AC 8024009C 27A50024 */  addiu     $a1, $sp, 0x24
/* AED4B0 802400A0 0040802D */  daddu     $s0, $v0, $zero
/* AED4B4 802400A4 8E63000C */  lw        $v1, 0xc($s3)
/* AED4B8 802400A8 8E07000C */  lw        $a3, 0xc($s0)
/* AED4BC 802400AC C6000038 */  lwc1      $f0, 0x38($s0)
/* AED4C0 802400B0 C6020040 */  lwc1      $f2, 0x40($s0)
/* AED4C4 802400B4 8C740000 */  lw        $s4, ($v1)
/* AED4C8 802400B8 24630004 */  addiu     $v1, $v1, 4
/* AED4CC 802400BC C4780000 */  lwc1      $f24, ($v1)
/* AED4D0 802400C0 4680C620 */  cvt.s.w   $f24, $f24
/* AED4D4 802400C4 24630004 */  addiu     $v1, $v1, 4
/* AED4D8 802400C8 C4740000 */  lwc1      $f20, ($v1)
/* AED4DC 802400CC 4680A520 */  cvt.s.w   $f20, $f20
/* AED4E0 802400D0 4406A000 */  mfc1      $a2, $f20
/* AED4E4 802400D4 C4760004 */  lwc1      $f22, 4($v1)
/* AED4E8 802400D8 4680B5A0 */  cvt.s.w   $f22, $f22
/* AED4EC 802400DC E7A00020 */  swc1      $f0, 0x20($sp)
/* AED4F0 802400E0 0C00A7E7 */  jal       add_vec2D_polar
/* AED4F4 802400E4 E7A20024 */   swc1     $f2, 0x24($sp)
/* AED4F8 802400E8 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* AED4FC 802400EC 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* AED500 802400F0 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* AED504 802400F4 4480A000 */  mtc1      $zero, $f20
/* AED508 802400F8 8E460028 */  lw        $a2, 0x28($s2)
/* AED50C 802400FC 4407A000 */  mfc1      $a3, $f20
/* AED510 80240100 0C00A7B5 */  jal       dist2D
/* AED514 80240104 4600A386 */   mov.s    $f14, $f20
/* AED518 80240108 4600A306 */  mov.s     $f12, $f20
/* AED51C 8024010C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* AED520 80240110 44066000 */  mfc1      $a2, $f12
/* AED524 80240114 8E470030 */  lw        $a3, 0x30($s2)
/* AED528 80240118 0C00A7B5 */  jal       dist2D
/* AED52C 8024011C 46000506 */   mov.s    $f20, $f0
/* AED530 80240120 C604000C */  lwc1      $f4, 0xc($s0)
/* AED534 80240124 3C018024 */  lui       $at, %hi(D_80244810_AF1C20)
/* AED538 80240128 D4224810 */  ldc1      $f2, %lo(D_80244810_AF1C20)($at)
/* AED53C 8024012C 46002121 */  cvt.d.s   $f4, $f4
/* AED540 80240130 46222032 */  c.eq.d    $f4, $f2
/* AED544 80240134 00000000 */  nop
/* AED548 80240138 45010007 */  bc1t      .L80240158
/* AED54C 8024013C 46000086 */   mov.s    $f2, $f0
/* AED550 80240140 3C018024 */  lui       $at, %hi(D_80244818_AF1C28)
/* AED554 80240144 D4204818 */  ldc1      $f0, %lo(D_80244818_AF1C28)($at)
/* AED558 80240148 46202032 */  c.eq.d    $f4, $f0
/* AED55C 8024014C 00000000 */  nop
/* AED560 80240150 45000008 */  bc1f      .L80240174
/* AED564 80240154 00000000 */   nop
.L80240158:
/* AED568 80240158 4618A03E */  c.le.s    $f20, $f24
/* AED56C 8024015C 00000000 */  nop
/* AED570 80240160 4500000C */  bc1f      .L80240194
/* AED574 80240164 0000882D */   daddu    $s1, $zero, $zero
/* AED578 80240168 4616103E */  c.le.s    $f2, $f22
/* AED57C 8024016C 08090063 */  j         .L8024018C
/* AED580 80240170 00000000 */   nop
.L80240174:
/* AED584 80240174 4618103E */  c.le.s    $f2, $f24
/* AED588 80240178 00000000 */  nop
/* AED58C 8024017C 45000005 */  bc1f      .L80240194
/* AED590 80240180 0000882D */   daddu    $s1, $zero, $zero
/* AED594 80240184 4616A03E */  c.le.s    $f20, $f22
/* AED598 80240188 00000000 */  nop
.L8024018C:
/* AED59C 8024018C 45030001 */  bc1tl     .L80240194
/* AED5A0 80240190 24110001 */   addiu    $s1, $zero, 1
.L80240194:
/* AED5A4 80240194 12200027 */  beqz      $s1, .L80240234
/* AED5A8 80240198 0260202D */   daddu    $a0, $s3, $zero
/* AED5AC 8024019C C60C0038 */  lwc1      $f12, 0x38($s0)
/* AED5B0 802401A0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* AED5B4 802401A4 8E460028 */  lw        $a2, 0x28($s2)
/* AED5B8 802401A8 8E470030 */  lw        $a3, 0x30($s2)
/* AED5BC 802401AC C602003C */  lwc1      $f2, 0x3c($s0)
/* AED5C0 802401B0 46006006 */  mov.s     $f0, $f12
/* AED5C4 802401B4 46007106 */  mov.s     $f4, $f14
/* AED5C8 802401B8 E7A00020 */  swc1      $f0, 0x20($sp)
/* AED5CC 802401BC E7A20028 */  swc1      $f2, 0x28($sp)
/* AED5D0 802401C0 0C00A7B5 */  jal       dist2D
/* AED5D4 802401C4 E7A40024 */   swc1     $f4, 0x24($sp)
/* AED5D8 802401C8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* AED5DC 802401CC C60E0040 */  lwc1      $f14, 0x40($s0)
/* AED5E0 802401D0 8E460028 */  lw        $a2, 0x28($s2)
/* AED5E4 802401D4 8E470030 */  lw        $a3, 0x30($s2)
/* AED5E8 802401D8 0C00A720 */  jal       atan2
/* AED5EC 802401DC 46000506 */   mov.s    $f20, $f0
/* AED5F0 802401E0 3C040007 */  lui       $a0, 7
/* AED5F4 802401E4 34848000 */  ori       $a0, $a0, 0x8000
/* AED5F8 802401E8 27A50020 */  addiu     $a1, $sp, 0x20
/* AED5FC 802401EC E7B40010 */  swc1      $f20, 0x10($sp)
/* AED600 802401F0 E7A00014 */  swc1      $f0, 0x14($sp)
/* AED604 802401F4 860200A6 */  lh        $v0, 0xa6($s0)
/* AED608 802401F8 27A60028 */  addiu     $a2, $sp, 0x28
/* AED60C 802401FC 44820000 */  mtc1      $v0, $f0
/* AED610 80240200 00000000 */  nop
/* AED614 80240204 46800020 */  cvt.s.w   $f0, $f0
/* AED618 80240208 E7A00018 */  swc1      $f0, 0x18($sp)
/* AED61C 8024020C 860200A8 */  lh        $v0, 0xa8($s0)
/* AED620 80240210 27A70024 */  addiu     $a3, $sp, 0x24
/* AED624 80240214 44820000 */  mtc1      $v0, $f0
/* AED628 80240218 00000000 */  nop
/* AED62C 8024021C 46800020 */  cvt.s.w   $f0, $f0
/* AED630 80240220 0C0376B9 */  jal       func_800DDAE4
/* AED634 80240224 E7A0001C */   swc1     $f0, 0x1c($sp)
/* AED638 80240228 54400001 */  bnel      $v0, $zero, .L80240230
/* AED63C 8024022C 0000882D */   daddu    $s1, $zero, $zero
.L80240230:
/* AED640 80240230 0260202D */  daddu     $a0, $s3, $zero
.L80240234:
/* AED644 80240234 0280282D */  daddu     $a1, $s4, $zero
/* AED648 80240238 0C0B2026 */  jal       set_variable
/* AED64C 8024023C 0220302D */   daddu    $a2, $s1, $zero
/* AED650 80240240 8FBF0044 */  lw        $ra, 0x44($sp)
/* AED654 80240244 8FB40040 */  lw        $s4, 0x40($sp)
/* AED658 80240248 8FB3003C */  lw        $s3, 0x3c($sp)
/* AED65C 8024024C 8FB20038 */  lw        $s2, 0x38($sp)
/* AED660 80240250 8FB10034 */  lw        $s1, 0x34($sp)
/* AED664 80240254 8FB00030 */  lw        $s0, 0x30($sp)
/* AED668 80240258 D7B80058 */  ldc1      $f24, 0x58($sp)
/* AED66C 8024025C D7B60050 */  ldc1      $f22, 0x50($sp)
/* AED670 80240260 D7B40048 */  ldc1      $f20, 0x48($sp)
/* AED674 80240264 24020002 */  addiu     $v0, $zero, 2
/* AED678 80240268 03E00008 */  jr        $ra
/* AED67C 8024026C 27BD0060 */   addiu    $sp, $sp, 0x60
