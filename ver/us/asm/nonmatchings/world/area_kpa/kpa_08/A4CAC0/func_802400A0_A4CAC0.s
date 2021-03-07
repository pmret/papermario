.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400A0_A4CAC0
/* A4CAC0 802400A0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A4CAC4 802400A4 AFB00018 */  sw        $s0, 0x18($sp)
/* A4CAC8 802400A8 AFBF0024 */  sw        $ra, 0x24($sp)
/* A4CACC 802400AC AFB20020 */  sw        $s2, 0x20($sp)
/* A4CAD0 802400B0 AFB1001C */  sw        $s1, 0x1c($sp)
/* A4CAD4 802400B4 F7B60030 */  sdc1      $f22, 0x30($sp)
/* A4CAD8 802400B8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A4CADC 802400BC 8C920148 */  lw        $s2, 0x148($a0)
/* A4CAE0 802400C0 4485A000 */  mtc1      $a1, $f20
/* A4CAE4 802400C4 86440008 */  lh        $a0, 8($s2)
/* A4CAE8 802400C8 4486B000 */  mtc1      $a2, $f22
/* A4CAEC 802400CC 0C00EABB */  jal       get_npc_unsafe
/* A4CAF0 802400D0 00E0802D */   daddu    $s0, $a3, $zero
/* A4CAF4 802400D4 0200202D */  daddu     $a0, $s0, $zero
/* A4CAF8 802400D8 0040882D */  daddu     $s1, $v0, $zero
/* A4CAFC 802400DC 4406A000 */  mfc1      $a2, $f20
/* A4CB00 802400E0 4407B000 */  mfc1      $a3, $f22
/* A4CB04 802400E4 3C03800A */  lui       $v1, %hi(D_8009A634)
/* A4CB08 802400E8 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* A4CB0C 802400EC 3C05800B */  lui       $a1, %hi(gCameras)
/* A4CB10 802400F0 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* A4CB14 802400F4 AFA00010 */  sw        $zero, 0x10($sp)
/* A4CB18 802400F8 00031080 */  sll       $v0, $v1, 2
/* A4CB1C 802400FC 00431021 */  addu      $v0, $v0, $v1
/* A4CB20 80240100 00021080 */  sll       $v0, $v0, 2
/* A4CB24 80240104 00431023 */  subu      $v0, $v0, $v1
/* A4CB28 80240108 000218C0 */  sll       $v1, $v0, 3
/* A4CB2C 8024010C 00431021 */  addu      $v0, $v0, $v1
/* A4CB30 80240110 000210C0 */  sll       $v0, $v0, 3
/* A4CB34 80240114 00458021 */  addu      $s0, $v0, $a1
/* A4CB38 80240118 0C01242D */  jal       func_800490B4
/* A4CB3C 8024011C 0240282D */   daddu    $a1, $s2, $zero
/* A4CB40 80240120 1040004B */  beqz      $v0, .L80240250
/* A4CB44 80240124 2402FFFF */   addiu    $v0, $zero, -1
/* A4CB48 80240128 C60C006C */  lwc1      $f12, 0x6c($s0)
/* A4CB4C 8024012C C62E000C */  lwc1      $f14, 0xc($s1)
/* A4CB50 80240130 3C014387 */  lui       $at, 0x4387
/* A4CB54 80240134 4481A000 */  mtc1      $at, $f20
/* A4CB58 80240138 0C00A70A */  jal       get_clamped_angle_diff
/* A4CB5C 8024013C 00000000 */   nop
/* A4CB60 80240140 0C00A6C9 */  jal       clamp_angle
/* A4CB64 80240144 46000306 */   mov.s    $f12, $f0
/* A4CB68 80240148 3C018024 */  lui       $at, %hi(D_80242520_A4EF40)
/* A4CB6C 8024014C D4222520 */  ldc1      $f2, %lo(D_80242520_A4EF40)($at)
/* A4CB70 80240150 46000021 */  cvt.d.s   $f0, $f0
/* A4CB74 80240154 4622003C */  c.lt.d    $f0, $f2
/* A4CB78 80240158 00000000 */  nop
/* A4CB7C 8024015C 45000003 */  bc1f      .L8024016C
/* A4CB80 80240160 00000000 */   nop
/* A4CB84 80240164 3C0142B4 */  lui       $at, 0x42b4
/* A4CB88 80240168 4481A000 */  mtc1      $at, $f20
.L8024016C:
/* A4CB8C 8024016C 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* A4CB90 80240170 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* A4CB94 80240174 C62C0038 */  lwc1      $f12, 0x38($s1)
/* A4CB98 80240178 8E020000 */  lw        $v0, ($s0)
/* A4CB9C 8024017C C62E0040 */  lwc1      $f14, 0x40($s1)
/* A4CBA0 80240180 8C460028 */  lw        $a2, 0x28($v0)
/* A4CBA4 80240184 0C00A720 */  jal       atan2
/* A4CBA8 80240188 8C470030 */   lw       $a3, 0x30($v0)
/* A4CBAC 8024018C 4600A306 */  mov.s     $f12, $f20
/* A4CBB0 80240190 0C00A70A */  jal       get_clamped_angle_diff
/* A4CBB4 80240194 46000386 */   mov.s    $f14, $f0
/* A4CBB8 80240198 46000005 */  abs.s     $f0, $f0
/* A4CBBC 8024019C 3C018024 */  lui       $at, %hi(D_80242528_A4EF48)
/* A4CBC0 802401A0 D4222528 */  ldc1      $f2, %lo(D_80242528_A4EF48)($at)
/* A4CBC4 802401A4 46000021 */  cvt.d.s   $f0, $f0
/* A4CBC8 802401A8 4620103C */  c.lt.d    $f2, $f0
/* A4CBCC 802401AC 00000000 */  nop
/* A4CBD0 802401B0 45010027 */  bc1t      .L80240250
/* A4CBD4 802401B4 2402FFFF */   addiu    $v0, $zero, -1
/* A4CBD8 802401B8 8E020000 */  lw        $v0, ($s0)
/* A4CBDC 802401BC C6200038 */  lwc1      $f0, 0x38($s1)
/* A4CBE0 802401C0 C4420028 */  lwc1      $f2, 0x28($v0)
/* A4CBE4 802401C4 44806000 */  mtc1      $zero, $f12
/* A4CBE8 802401C8 46020001 */  sub.s     $f0, $f0, $f2
/* A4CBEC 802401CC C62E003C */  lwc1      $f14, 0x3c($s1)
/* A4CBF0 802401D0 8C47002C */  lw        $a3, 0x2c($v0)
/* A4CBF4 802401D4 46000005 */  abs.s     $f0, $f0
/* A4CBF8 802401D8 44060000 */  mfc1      $a2, $f0
/* A4CBFC 802401DC 0C00A720 */  jal       atan2
/* A4CC00 802401E0 00000000 */   nop
/* A4CC04 802401E4 3C018024 */  lui       $at, %hi(D_80242530_A4EF50)
/* A4CC08 802401E8 D4222530 */  ldc1      $f2, %lo(D_80242530_A4EF50)($at)
/* A4CC0C 802401EC 46000021 */  cvt.d.s   $f0, $f0
/* A4CC10 802401F0 46220001 */  sub.d     $f0, $f0, $f2
/* A4CC14 802401F4 3C018024 */  lui       $at, %hi(D_80242538_A4EF58)
/* A4CC18 802401F8 D4222538 */  ldc1      $f2, %lo(D_80242538_A4EF58)($at)
/* A4CC1C 802401FC 46200020 */  cvt.s.d   $f0, $f0
/* A4CC20 80240200 46000005 */  abs.s     $f0, $f0
/* A4CC24 80240204 46000021 */  cvt.d.s   $f0, $f0
/* A4CC28 80240208 4620103C */  c.lt.d    $f2, $f0
/* A4CC2C 8024020C 00000000 */  nop
/* A4CC30 80240210 4501000F */  bc1t      .L80240250
/* A4CC34 80240214 2402FFFF */   addiu    $v0, $zero, -1
/* A4CC38 80240218 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* A4CC3C 8024021C 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* A4CC40 80240220 24020009 */  addiu     $v0, $zero, 9
/* A4CC44 80240224 10620009 */  beq       $v1, $v0, .L8024024C
/* A4CC48 80240228 24020007 */   addiu    $v0, $zero, 7
/* A4CC4C 8024022C 50620008 */  beql      $v1, $v0, .L80240250
/* A4CC50 80240230 2402FFFF */   addiu    $v0, $zero, -1
/* A4CC54 80240234 86440008 */  lh        $a0, 8($s2)
/* A4CC58 80240238 0C00FB3A */  jal       get_enemy
/* A4CC5C 8024023C 24840001 */   addiu    $a0, $a0, 1
/* A4CC60 80240240 8C43006C */  lw        $v1, 0x6c($v0)
/* A4CC64 80240244 10600002 */  beqz      $v1, .L80240250
/* A4CC68 80240248 24020001 */   addiu    $v0, $zero, 1
.L8024024C:
/* A4CC6C 8024024C 2402FFFF */  addiu     $v0, $zero, -1
.L80240250:
/* A4CC70 80240250 8FBF0024 */  lw        $ra, 0x24($sp)
/* A4CC74 80240254 8FB20020 */  lw        $s2, 0x20($sp)
/* A4CC78 80240258 8FB1001C */  lw        $s1, 0x1c($sp)
/* A4CC7C 8024025C 8FB00018 */  lw        $s0, 0x18($sp)
/* A4CC80 80240260 D7B60030 */  ldc1      $f22, 0x30($sp)
/* A4CC84 80240264 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A4CC88 80240268 03E00008 */  jr        $ra
/* A4CC8C 8024026C 27BD0038 */   addiu    $sp, $sp, 0x38
