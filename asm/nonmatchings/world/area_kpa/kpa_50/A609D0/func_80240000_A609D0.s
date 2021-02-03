.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A609D0
/* A609D0 80240000 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A609D4 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* A609D8 80240008 0080882D */  daddu     $s1, $a0, $zero
/* A609DC 8024000C 3C05800B */  lui       $a1, %hi(gCameras)
/* A609E0 80240010 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* A609E4 80240014 AFBF0020 */  sw        $ra, 0x20($sp)
/* A609E8 80240018 AFB3001C */  sw        $s3, 0x1c($sp)
/* A609EC 8024001C AFB20018 */  sw        $s2, 0x18($sp)
/* A609F0 80240020 AFB00010 */  sw        $s0, 0x10($sp)
/* A609F4 80240024 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A609F8 80240028 8E330148 */  lw        $s3, 0x148($s1)
/* A609FC 8024002C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* A60A00 80240030 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* A60A04 80240034 8E30000C */  lw        $s0, 0xc($s1)
/* A60A08 80240038 00031080 */  sll       $v0, $v1, 2
/* A60A0C 8024003C 00431021 */  addu      $v0, $v0, $v1
/* A60A10 80240040 00021080 */  sll       $v0, $v0, 2
/* A60A14 80240044 00431023 */  subu      $v0, $v0, $v1
/* A60A18 80240048 000218C0 */  sll       $v1, $v0, 3
/* A60A1C 8024004C 00431021 */  addu      $v0, $v0, $v1
/* A60A20 80240050 000210C0 */  sll       $v0, $v0, 3
/* A60A24 80240054 86640008 */  lh        $a0, 8($s3)
/* A60A28 80240058 0C00EABB */  jal       get_npc_unsafe
/* A60A2C 8024005C 00459021 */   addu     $s2, $v0, $a1
/* A60A30 80240060 0220202D */  daddu     $a0, $s1, $zero
/* A60A34 80240064 8E050000 */  lw        $a1, ($s0)
/* A60A38 80240068 0C0B1EAF */  jal       get_variable
/* A60A3C 8024006C 0040802D */   daddu    $s0, $v0, $zero
/* A60A40 80240070 0260202D */  daddu     $a0, $s3, $zero
/* A60A44 80240074 8C460024 */  lw        $a2, 0x24($v0)
/* A60A48 80240078 8C470028 */  lw        $a3, 0x28($v0)
/* A60A4C 8024007C 0C0124FB */  jal       func_800493EC
/* A60A50 80240080 0000282D */   daddu    $a1, $zero, $zero
/* A60A54 80240084 10400052 */  beqz      $v0, .L802401D0
/* A60A58 80240088 2402FFFF */   addiu    $v0, $zero, -1
/* A60A5C 8024008C C64C006C */  lwc1      $f12, 0x6c($s2)
/* A60A60 80240090 C60E000C */  lwc1      $f14, 0xc($s0)
/* A60A64 80240094 3C014387 */  lui       $at, 0x4387
/* A60A68 80240098 4481A000 */  mtc1      $at, $f20
/* A60A6C 8024009C 0C00A70A */  jal       get_clamped_angle_diff
/* A60A70 802400A0 00000000 */   nop
/* A60A74 802400A4 0C00A6C9 */  jal       clamp_angle
/* A60A78 802400A8 46000306 */   mov.s    $f12, $f0
/* A60A7C 802400AC 3C018024 */  lui       $at, %hi(D_802434A0_A63E70)
/* A60A80 802400B0 D42234A0 */  ldc1      $f2, %lo(D_802434A0_A63E70)($at)
/* A60A84 802400B4 46000021 */  cvt.d.s   $f0, $f0
/* A60A88 802400B8 4622003C */  c.lt.d    $f0, $f2
/* A60A8C 802400BC 00000000 */  nop
/* A60A90 802400C0 45000003 */  bc1f      .L802400D0
/* A60A94 802400C4 00000000 */   nop
/* A60A98 802400C8 3C0142B4 */  lui       $at, 0x42b4
/* A60A9C 802400CC 4481A000 */  mtc1      $at, $f20
.L802400D0:
/* A60AA0 802400D0 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* A60AA4 802400D4 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* A60AA8 802400D8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A60AAC 802400DC 8E220000 */  lw        $v0, ($s1)
/* A60AB0 802400E0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A60AB4 802400E4 8C460028 */  lw        $a2, 0x28($v0)
/* A60AB8 802400E8 0C00A720 */  jal       atan2
/* A60ABC 802400EC 8C470030 */   lw       $a3, 0x30($v0)
/* A60AC0 802400F0 4600A306 */  mov.s     $f12, $f20
/* A60AC4 802400F4 0C00A70A */  jal       get_clamped_angle_diff
/* A60AC8 802400F8 46000386 */   mov.s    $f14, $f0
/* A60ACC 802400FC 46000005 */  abs.s     $f0, $f0
/* A60AD0 80240100 3C018024 */  lui       $at, %hi(D_802434A8_A63E78)
/* A60AD4 80240104 D42234A8 */  ldc1      $f2, %lo(D_802434A8_A63E78)($at)
/* A60AD8 80240108 46000021 */  cvt.d.s   $f0, $f0
/* A60ADC 8024010C 4620103C */  c.lt.d    $f2, $f0
/* A60AE0 80240110 00000000 */  nop
/* A60AE4 80240114 4501002E */  bc1t      .L802401D0
/* A60AE8 80240118 2402FFFF */   addiu    $v0, $zero, -1
/* A60AEC 8024011C 8E220000 */  lw        $v0, ($s1)
/* A60AF0 80240120 C600003C */  lwc1      $f0, 0x3c($s0)
/* A60AF4 80240124 C442002C */  lwc1      $f2, 0x2c($v0)
/* A60AF8 80240128 860200A8 */  lh        $v0, 0xa8($s0)
/* A60AFC 8024012C 46020001 */  sub.s     $f0, $f0, $f2
/* A60B00 80240130 44821000 */  mtc1      $v0, $f2
/* A60B04 80240134 00000000 */  nop
/* A60B08 80240138 468010A1 */  cvt.d.w   $f2, $f2
/* A60B0C 8024013C 46221080 */  add.d     $f2, $f2, $f2
/* A60B10 80240140 46000005 */  abs.s     $f0, $f0
/* A60B14 80240144 46000021 */  cvt.d.s   $f0, $f0
/* A60B18 80240148 4620103E */  c.le.d    $f2, $f0
/* A60B1C 8024014C 00000000 */  nop
/* A60B20 80240150 4501001F */  bc1t      .L802401D0
/* A60B24 80240154 2402FFFF */   addiu    $v0, $zero, -1
/* A60B28 80240158 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* A60B2C 8024015C 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* A60B30 80240160 24020009 */  addiu     $v0, $zero, 9
/* A60B34 80240164 10620019 */  beq       $v1, $v0, .L802401CC
/* A60B38 80240168 24020007 */   addiu    $v0, $zero, 7
/* A60B3C 8024016C 14620005 */  bne       $v1, $v0, .L80240184
/* A60B40 80240170 2402FFFF */   addiu    $v0, $zero, -1
/* A60B44 80240174 08090074 */  j         .L802401D0
/* A60B48 80240178 00000000 */   nop
.L8024017C:
/* A60B4C 8024017C 08090074 */  j         .L802401D0
/* A60B50 80240180 0240102D */   daddu    $v0, $s2, $zero
.L80240184:
/* A60B54 80240184 8E620078 */  lw        $v0, 0x78($s3)
/* A60B58 80240188 18400010 */  blez      $v0, .L802401CC
/* A60B5C 8024018C 0000882D */   daddu    $s1, $zero, $zero
.L80240190:
/* A60B60 80240190 86620008 */  lh        $v0, 8($s3)
/* A60B64 80240194 00511021 */  addu      $v0, $v0, $s1
/* A60B68 80240198 24520001 */  addiu     $s2, $v0, 1
/* A60B6C 8024019C 0C00FB3A */  jal       get_enemy
/* A60B70 802401A0 0240202D */   daddu    $a0, $s2, $zero
/* A60B74 802401A4 0240202D */  daddu     $a0, $s2, $zero
/* A60B78 802401A8 0C00EABB */  jal       get_npc_unsafe
/* A60B7C 802401AC 0040802D */   daddu    $s0, $v0, $zero
/* A60B80 802401B0 8E02006C */  lw        $v0, 0x6c($s0)
/* A60B84 802401B4 1040FFF1 */  beqz      $v0, .L8024017C
/* A60B88 802401B8 26310001 */   addiu    $s1, $s1, 1
/* A60B8C 802401BC 8E620078 */  lw        $v0, 0x78($s3)
/* A60B90 802401C0 0222102A */  slt       $v0, $s1, $v0
/* A60B94 802401C4 1440FFF2 */  bnez      $v0, .L80240190
/* A60B98 802401C8 00000000 */   nop
.L802401CC:
/* A60B9C 802401CC 2402FFFF */  addiu     $v0, $zero, -1
.L802401D0:
/* A60BA0 802401D0 8FBF0020 */  lw        $ra, 0x20($sp)
/* A60BA4 802401D4 8FB3001C */  lw        $s3, 0x1c($sp)
/* A60BA8 802401D8 8FB20018 */  lw        $s2, 0x18($sp)
/* A60BAC 802401DC 8FB10014 */  lw        $s1, 0x14($sp)
/* A60BB0 802401E0 8FB00010 */  lw        $s0, 0x10($sp)
/* A60BB4 802401E4 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A60BB8 802401E8 03E00008 */  jr        $ra
/* A60BBC 802401EC 27BD0030 */   addiu    $sp, $sp, 0x30
