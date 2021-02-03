.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240170_A9EEB0
/* A9EEB0 80240170 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A9EEB4 80240174 AFB10014 */  sw        $s1, 0x14($sp)
/* A9EEB8 80240178 0080882D */  daddu     $s1, $a0, $zero
/* A9EEBC 8024017C 3C05800B */  lui       $a1, %hi(gCameras)
/* A9EEC0 80240180 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* A9EEC4 80240184 AFBF0020 */  sw        $ra, 0x20($sp)
/* A9EEC8 80240188 AFB3001C */  sw        $s3, 0x1c($sp)
/* A9EECC 8024018C AFB20018 */  sw        $s2, 0x18($sp)
/* A9EED0 80240190 AFB00010 */  sw        $s0, 0x10($sp)
/* A9EED4 80240194 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A9EED8 80240198 8E330148 */  lw        $s3, 0x148($s1)
/* A9EEDC 8024019C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* A9EEE0 802401A0 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* A9EEE4 802401A4 8E30000C */  lw        $s0, 0xc($s1)
/* A9EEE8 802401A8 00031080 */  sll       $v0, $v1, 2
/* A9EEEC 802401AC 00431021 */  addu      $v0, $v0, $v1
/* A9EEF0 802401B0 00021080 */  sll       $v0, $v0, 2
/* A9EEF4 802401B4 00431023 */  subu      $v0, $v0, $v1
/* A9EEF8 802401B8 000218C0 */  sll       $v1, $v0, 3
/* A9EEFC 802401BC 00431021 */  addu      $v0, $v0, $v1
/* A9EF00 802401C0 000210C0 */  sll       $v0, $v0, 3
/* A9EF04 802401C4 86640008 */  lh        $a0, 8($s3)
/* A9EF08 802401C8 0C00EABB */  jal       get_npc_unsafe
/* A9EF0C 802401CC 00459021 */   addu     $s2, $v0, $a1
/* A9EF10 802401D0 0220202D */  daddu     $a0, $s1, $zero
/* A9EF14 802401D4 8E050000 */  lw        $a1, ($s0)
/* A9EF18 802401D8 0C0B1EAF */  jal       get_variable
/* A9EF1C 802401DC 0040802D */   daddu    $s0, $v0, $zero
/* A9EF20 802401E0 0260202D */  daddu     $a0, $s3, $zero
/* A9EF24 802401E4 8C460024 */  lw        $a2, 0x24($v0)
/* A9EF28 802401E8 8C470028 */  lw        $a3, 0x28($v0)
/* A9EF2C 802401EC 0C0124FB */  jal       func_800493EC
/* A9EF30 802401F0 0000282D */   daddu    $a1, $zero, $zero
/* A9EF34 802401F4 10400052 */  beqz      $v0, .L80240340
/* A9EF38 802401F8 2402FFFF */   addiu    $v0, $zero, -1
/* A9EF3C 802401FC C64C006C */  lwc1      $f12, 0x6c($s2)
/* A9EF40 80240200 C60E000C */  lwc1      $f14, 0xc($s0)
/* A9EF44 80240204 3C014387 */  lui       $at, 0x4387
/* A9EF48 80240208 4481A000 */  mtc1      $at, $f20
/* A9EF4C 8024020C 0C00A70A */  jal       get_clamped_angle_diff
/* A9EF50 80240210 00000000 */   nop
/* A9EF54 80240214 0C00A6C9 */  jal       clamp_angle
/* A9EF58 80240218 46000306 */   mov.s    $f12, $f0
/* A9EF5C 8024021C 3C018024 */  lui       $at, %hi(D_80242FE0_AA1D20)
/* A9EF60 80240220 D4222FE0 */  ldc1      $f2, %lo(D_80242FE0_AA1D20)($at)
/* A9EF64 80240224 46000021 */  cvt.d.s   $f0, $f0
/* A9EF68 80240228 4622003C */  c.lt.d    $f0, $f2
/* A9EF6C 8024022C 00000000 */  nop
/* A9EF70 80240230 45000003 */  bc1f      .L80240240
/* A9EF74 80240234 00000000 */   nop
/* A9EF78 80240238 3C0142B4 */  lui       $at, 0x42b4
/* A9EF7C 8024023C 4481A000 */  mtc1      $at, $f20
.L80240240:
/* A9EF80 80240240 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* A9EF84 80240244 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* A9EF88 80240248 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A9EF8C 8024024C 8E220000 */  lw        $v0, ($s1)
/* A9EF90 80240250 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A9EF94 80240254 8C460028 */  lw        $a2, 0x28($v0)
/* A9EF98 80240258 0C00A720 */  jal       atan2
/* A9EF9C 8024025C 8C470030 */   lw       $a3, 0x30($v0)
/* A9EFA0 80240260 4600A306 */  mov.s     $f12, $f20
/* A9EFA4 80240264 0C00A70A */  jal       get_clamped_angle_diff
/* A9EFA8 80240268 46000386 */   mov.s    $f14, $f0
/* A9EFAC 8024026C 46000005 */  abs.s     $f0, $f0
/* A9EFB0 80240270 3C018024 */  lui       $at, %hi(D_80242FE8_AA1D28)
/* A9EFB4 80240274 D4222FE8 */  ldc1      $f2, %lo(D_80242FE8_AA1D28)($at)
/* A9EFB8 80240278 46000021 */  cvt.d.s   $f0, $f0
/* A9EFBC 8024027C 4620103C */  c.lt.d    $f2, $f0
/* A9EFC0 80240280 00000000 */  nop
/* A9EFC4 80240284 4501002E */  bc1t      .L80240340
/* A9EFC8 80240288 2402FFFF */   addiu    $v0, $zero, -1
/* A9EFCC 8024028C 8E220000 */  lw        $v0, ($s1)
/* A9EFD0 80240290 C600003C */  lwc1      $f0, 0x3c($s0)
/* A9EFD4 80240294 C442002C */  lwc1      $f2, 0x2c($v0)
/* A9EFD8 80240298 860200A8 */  lh        $v0, 0xa8($s0)
/* A9EFDC 8024029C 46020001 */  sub.s     $f0, $f0, $f2
/* A9EFE0 802402A0 44821000 */  mtc1      $v0, $f2
/* A9EFE4 802402A4 00000000 */  nop
/* A9EFE8 802402A8 468010A1 */  cvt.d.w   $f2, $f2
/* A9EFEC 802402AC 46221080 */  add.d     $f2, $f2, $f2
/* A9EFF0 802402B0 46000005 */  abs.s     $f0, $f0
/* A9EFF4 802402B4 46000021 */  cvt.d.s   $f0, $f0
/* A9EFF8 802402B8 4620103E */  c.le.d    $f2, $f0
/* A9EFFC 802402BC 00000000 */  nop
/* A9F000 802402C0 4501001F */  bc1t      .L80240340
/* A9F004 802402C4 2402FFFF */   addiu    $v0, $zero, -1
/* A9F008 802402C8 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* A9F00C 802402CC 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* A9F010 802402D0 24020009 */  addiu     $v0, $zero, 9
/* A9F014 802402D4 10620019 */  beq       $v1, $v0, .L8024033C
/* A9F018 802402D8 24020007 */   addiu    $v0, $zero, 7
/* A9F01C 802402DC 14620005 */  bne       $v1, $v0, .L802402F4
/* A9F020 802402E0 2402FFFF */   addiu    $v0, $zero, -1
/* A9F024 802402E4 080900D0 */  j         .L80240340
/* A9F028 802402E8 00000000 */   nop
.L802402EC:
/* A9F02C 802402EC 080900D0 */  j         .L80240340
/* A9F030 802402F0 0240102D */   daddu    $v0, $s2, $zero
.L802402F4:
/* A9F034 802402F4 8E620078 */  lw        $v0, 0x78($s3)
/* A9F038 802402F8 18400010 */  blez      $v0, .L8024033C
/* A9F03C 802402FC 0000882D */   daddu    $s1, $zero, $zero
.L80240300:
/* A9F040 80240300 86620008 */  lh        $v0, 8($s3)
/* A9F044 80240304 00511021 */  addu      $v0, $v0, $s1
/* A9F048 80240308 24520001 */  addiu     $s2, $v0, 1
/* A9F04C 8024030C 0C00FB3A */  jal       get_enemy
/* A9F050 80240310 0240202D */   daddu    $a0, $s2, $zero
/* A9F054 80240314 0240202D */  daddu     $a0, $s2, $zero
/* A9F058 80240318 0C00EABB */  jal       get_npc_unsafe
/* A9F05C 8024031C 0040802D */   daddu    $s0, $v0, $zero
/* A9F060 80240320 8E02006C */  lw        $v0, 0x6c($s0)
/* A9F064 80240324 1040FFF1 */  beqz      $v0, .L802402EC
/* A9F068 80240328 26310001 */   addiu    $s1, $s1, 1
/* A9F06C 8024032C 8E620078 */  lw        $v0, 0x78($s3)
/* A9F070 80240330 0222102A */  slt       $v0, $s1, $v0
/* A9F074 80240334 1440FFF2 */  bnez      $v0, .L80240300
/* A9F078 80240338 00000000 */   nop
.L8024033C:
/* A9F07C 8024033C 2402FFFF */  addiu     $v0, $zero, -1
.L80240340:
/* A9F080 80240340 8FBF0020 */  lw        $ra, 0x20($sp)
/* A9F084 80240344 8FB3001C */  lw        $s3, 0x1c($sp)
/* A9F088 80240348 8FB20018 */  lw        $s2, 0x18($sp)
/* A9F08C 8024034C 8FB10014 */  lw        $s1, 0x14($sp)
/* A9F090 80240350 8FB00010 */  lw        $s0, 0x10($sp)
/* A9F094 80240354 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A9F098 80240358 03E00008 */  jr        $ra
/* A9F09C 8024035C 27BD0030 */   addiu    $sp, $sp, 0x30
