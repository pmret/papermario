.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80242B90_91E470
.double 180.0

glabel D_80242B98_91E478
.double 75.0

.section .text

glabel func_80240080_91B960
/* 91B960 80240080 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 91B964 80240084 AFBF001C */  sw        $ra, 0x1c($sp)
/* 91B968 80240088 AFB20018 */  sw        $s2, 0x18($sp)
/* 91B96C 8024008C AFB10014 */  sw        $s1, 0x14($sp)
/* 91B970 80240090 AFB00010 */  sw        $s0, 0x10($sp)
/* 91B974 80240094 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 91B978 80240098 8C900148 */  lw        $s0, 0x148($a0)
/* 91B97C 8024009C 86040008 */  lh        $a0, 8($s0)
/* 91B980 802400A0 3C014387 */  lui       $at, 0x4387
/* 91B984 802400A4 4481A000 */  mtc1      $at, $f20
/* 91B988 802400A8 0C00EABB */  jal       get_npc_unsafe
/* 91B98C 802400AC 00A0882D */   daddu    $s1, $a1, $zero
/* 91B990 802400B0 0200202D */  daddu     $a0, $s0, $zero
/* 91B994 802400B4 8E26000C */  lw        $a2, 0xc($s1)
/* 91B998 802400B8 8E270010 */  lw        $a3, 0x10($s1)
/* 91B99C 802400BC 0040882D */  daddu     $s1, $v0, $zero
/* 91B9A0 802400C0 3C03800B */  lui       $v1, %hi(gCameras)
/* 91B9A4 802400C4 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 91B9A8 802400C8 3C02800A */  lui       $v0, %hi(gCurrentCamID)
/* 91B9AC 802400CC 8442A634 */  lh        $v0, %lo(gCurrentCamID)($v0)
/* 91B9B0 802400D0 0000282D */  daddu     $a1, $zero, $zero
/* 91B9B4 802400D4 00028080 */  sll       $s0, $v0, 2
/* 91B9B8 802400D8 02028021 */  addu      $s0, $s0, $v0
/* 91B9BC 802400DC 00108080 */  sll       $s0, $s0, 2
/* 91B9C0 802400E0 02028023 */  subu      $s0, $s0, $v0
/* 91B9C4 802400E4 001010C0 */  sll       $v0, $s0, 3
/* 91B9C8 802400E8 02028021 */  addu      $s0, $s0, $v0
/* 91B9CC 802400EC 001080C0 */  sll       $s0, $s0, 3
/* 91B9D0 802400F0 0C0124FB */  jal       func_800493EC
/* 91B9D4 802400F4 02038021 */   addu     $s0, $s0, $v1
/* 91B9D8 802400F8 C60C006C */  lwc1      $f12, 0x6c($s0)
/* 91B9DC 802400FC C62E000C */  lwc1      $f14, 0xc($s1)
/* 91B9E0 80240100 0C00A70A */  jal       get_clamped_angle_diff
/* 91B9E4 80240104 0002802B */   sltu     $s0, $zero, $v0
/* 91B9E8 80240108 0C00A6C9 */  jal       clamp_angle
/* 91B9EC 8024010C 46000306 */   mov.s    $f12, $f0
/* 91B9F0 80240110 3C018024 */  lui       $at, %hi(D_80242B90_91E470)
/* 91B9F4 80240114 D4222B90 */  ldc1      $f2, %lo(D_80242B90_91E470)($at)
/* 91B9F8 80240118 46000021 */  cvt.d.s   $f0, $f0
/* 91B9FC 8024011C 4622003C */  c.lt.d    $f0, $f2
/* 91BA00 80240120 00000000 */  nop
/* 91BA04 80240124 45000003 */  bc1f      .L80240134
/* 91BA08 80240128 00000000 */   nop
/* 91BA0C 8024012C 3C0142B4 */  lui       $at, 0x42b4
/* 91BA10 80240130 4481A000 */  mtc1      $at, $f20
.L80240134:
/* 91BA14 80240134 3C12800F */  lui       $s2, %hi(gPlayerStatusPtr)
/* 91BA18 80240138 26527B30 */  addiu     $s2, $s2, %lo(gPlayerStatusPtr)
/* 91BA1C 8024013C C62C0038 */  lwc1      $f12, 0x38($s1)
/* 91BA20 80240140 8E420000 */  lw        $v0, ($s2)
/* 91BA24 80240144 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 91BA28 80240148 8C460028 */  lw        $a2, 0x28($v0)
/* 91BA2C 8024014C 0C00A720 */  jal       atan2
/* 91BA30 80240150 8C470030 */   lw       $a3, 0x30($v0)
/* 91BA34 80240154 4600A306 */  mov.s     $f12, $f20
/* 91BA38 80240158 0C00A70A */  jal       get_clamped_angle_diff
/* 91BA3C 8024015C 46000386 */   mov.s    $f14, $f0
/* 91BA40 80240160 46000005 */  abs.s     $f0, $f0
/* 91BA44 80240164 3C018024 */  lui       $at, %hi(D_80242B98_91E478)
/* 91BA48 80240168 D4222B98 */  ldc1      $f2, %lo(D_80242B98_91E478)($at)
/* 91BA4C 8024016C 46000021 */  cvt.d.s   $f0, $f0
/* 91BA50 80240170 4620103C */  c.lt.d    $f2, $f0
/* 91BA54 80240174 00000000 */  nop
/* 91BA58 80240178 45030001 */  bc1tl     .L80240180
/* 91BA5C 8024017C 0000802D */   daddu    $s0, $zero, $zero
.L80240180:
/* 91BA60 80240180 8E420000 */  lw        $v0, ($s2)
/* 91BA64 80240184 C620003C */  lwc1      $f0, 0x3c($s1)
/* 91BA68 80240188 C442002C */  lwc1      $f2, 0x2c($v0)
/* 91BA6C 8024018C 46020001 */  sub.s     $f0, $f0, $f2
/* 91BA70 80240190 3C014220 */  lui       $at, 0x4220
/* 91BA74 80240194 44811000 */  mtc1      $at, $f2
/* 91BA78 80240198 46000005 */  abs.s     $f0, $f0
/* 91BA7C 8024019C 4600103E */  c.le.s    $f2, $f0
/* 91BA80 802401A0 00000000 */  nop
/* 91BA84 802401A4 45030001 */  bc1tl     .L802401AC
/* 91BA88 802401A8 0000802D */   daddu    $s0, $zero, $zero
.L802401AC:
/* 91BA8C 802401AC 3C038011 */  lui       $v1, %hi(gPartnerActionStatus+0x3)
/* 91BA90 802401B0 8063EBB3 */  lb        $v1, %lo(gPartnerActionStatus+0x3)($v1)
/* 91BA94 802401B4 24020009 */  addiu     $v0, $zero, 9
/* 91BA98 802401B8 50620001 */  beql      $v1, $v0, .L802401C0
/* 91BA9C 802401BC 0000802D */   daddu    $s0, $zero, $zero
.L802401C0:
/* 91BAA0 802401C0 0200102D */  daddu     $v0, $s0, $zero
/* 91BAA4 802401C4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 91BAA8 802401C8 8FB20018 */  lw        $s2, 0x18($sp)
/* 91BAAC 802401CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 91BAB0 802401D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 91BAB4 802401D4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 91BAB8 802401D8 03E00008 */  jr        $ra
/* 91BABC 802401DC 27BD0028 */   addiu    $sp, $sp, 0x28
