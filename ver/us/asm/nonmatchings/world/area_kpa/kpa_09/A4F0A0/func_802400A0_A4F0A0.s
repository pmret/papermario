.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802427C0_A517C0
.double 180.0

dlabel D_802427C8_A517C8
.double 75.0

.section .text

glabel func_802400A0_A4F0A0
/* A4F0A0 802400A0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A4F0A4 802400A4 AFB10014 */  sw        $s1, 0x14($sp)
/* A4F0A8 802400A8 0080882D */  daddu     $s1, $a0, $zero
/* A4F0AC 802400AC 3C05800B */  lui       $a1, %hi(gCameras)
/* A4F0B0 802400B0 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* A4F0B4 802400B4 AFBF0020 */  sw        $ra, 0x20($sp)
/* A4F0B8 802400B8 AFB3001C */  sw        $s3, 0x1c($sp)
/* A4F0BC 802400BC AFB20018 */  sw        $s2, 0x18($sp)
/* A4F0C0 802400C0 AFB00010 */  sw        $s0, 0x10($sp)
/* A4F0C4 802400C4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A4F0C8 802400C8 8E330148 */  lw        $s3, 0x148($s1)
/* A4F0CC 802400CC 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* A4F0D0 802400D0 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* A4F0D4 802400D4 8E30000C */  lw        $s0, 0xc($s1)
/* A4F0D8 802400D8 00031080 */  sll       $v0, $v1, 2
/* A4F0DC 802400DC 00431021 */  addu      $v0, $v0, $v1
/* A4F0E0 802400E0 00021080 */  sll       $v0, $v0, 2
/* A4F0E4 802400E4 00431023 */  subu      $v0, $v0, $v1
/* A4F0E8 802400E8 000218C0 */  sll       $v1, $v0, 3
/* A4F0EC 802400EC 00431021 */  addu      $v0, $v0, $v1
/* A4F0F0 802400F0 000210C0 */  sll       $v0, $v0, 3
/* A4F0F4 802400F4 86640008 */  lh        $a0, 8($s3)
/* A4F0F8 802400F8 0C00EABB */  jal       get_npc_unsafe
/* A4F0FC 802400FC 00459021 */   addu     $s2, $v0, $a1
/* A4F100 80240100 0220202D */  daddu     $a0, $s1, $zero
/* A4F104 80240104 8E050000 */  lw        $a1, ($s0)
/* A4F108 80240108 0C0B1EAF */  jal       evt_get_variable
/* A4F10C 8024010C 0040802D */   daddu    $s0, $v0, $zero
/* A4F110 80240110 0260202D */  daddu     $a0, $s3, $zero
/* A4F114 80240114 8C460024 */  lw        $a2, 0x24($v0)
/* A4F118 80240118 8C470028 */  lw        $a3, 0x28($v0)
/* A4F11C 8024011C 0C0124FB */  jal       func_800493EC
/* A4F120 80240120 0000282D */   daddu    $a1, $zero, $zero
/* A4F124 80240124 10400052 */  beqz      $v0, .L80240270
/* A4F128 80240128 2402FFFF */   addiu    $v0, $zero, -1
/* A4F12C 8024012C C64C006C */  lwc1      $f12, 0x6c($s2)
/* A4F130 80240130 C60E000C */  lwc1      $f14, 0xc($s0)
/* A4F134 80240134 3C014387 */  lui       $at, 0x4387
/* A4F138 80240138 4481A000 */  mtc1      $at, $f20
/* A4F13C 8024013C 0C00A70A */  jal       get_clamped_angle_diff
/* A4F140 80240140 00000000 */   nop
/* A4F144 80240144 0C00A6C9 */  jal       clamp_angle
/* A4F148 80240148 46000306 */   mov.s    $f12, $f0
/* A4F14C 8024014C 3C018024 */  lui       $at, %hi(D_802427C0_A517C0)
/* A4F150 80240150 D42227C0 */  ldc1      $f2, %lo(D_802427C0_A517C0)($at)
/* A4F154 80240154 46000021 */  cvt.d.s   $f0, $f0
/* A4F158 80240158 4622003C */  c.lt.d    $f0, $f2
/* A4F15C 8024015C 00000000 */  nop
/* A4F160 80240160 45000003 */  bc1f      .L80240170
/* A4F164 80240164 00000000 */   nop
/* A4F168 80240168 3C0142B4 */  lui       $at, 0x42b4
/* A4F16C 8024016C 4481A000 */  mtc1      $at, $f20
.L80240170:
/* A4F170 80240170 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* A4F174 80240174 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* A4F178 80240178 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A4F17C 8024017C 8E220000 */  lw        $v0, ($s1)
/* A4F180 80240180 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A4F184 80240184 8C460028 */  lw        $a2, 0x28($v0)
/* A4F188 80240188 0C00A720 */  jal       atan2
/* A4F18C 8024018C 8C470030 */   lw       $a3, 0x30($v0)
/* A4F190 80240190 4600A306 */  mov.s     $f12, $f20
/* A4F194 80240194 0C00A70A */  jal       get_clamped_angle_diff
/* A4F198 80240198 46000386 */   mov.s    $f14, $f0
/* A4F19C 8024019C 46000005 */  abs.s     $f0, $f0
/* A4F1A0 802401A0 3C018024 */  lui       $at, %hi(D_802427C8_A517C8)
/* A4F1A4 802401A4 D42227C8 */  ldc1      $f2, %lo(D_802427C8_A517C8)($at)
/* A4F1A8 802401A8 46000021 */  cvt.d.s   $f0, $f0
/* A4F1AC 802401AC 4620103C */  c.lt.d    $f2, $f0
/* A4F1B0 802401B0 00000000 */  nop
/* A4F1B4 802401B4 4501002E */  bc1t      .L80240270
/* A4F1B8 802401B8 2402FFFF */   addiu    $v0, $zero, -1
/* A4F1BC 802401BC 8E220000 */  lw        $v0, ($s1)
/* A4F1C0 802401C0 C600003C */  lwc1      $f0, 0x3c($s0)
/* A4F1C4 802401C4 C442002C */  lwc1      $f2, 0x2c($v0)
/* A4F1C8 802401C8 860200A8 */  lh        $v0, 0xa8($s0)
/* A4F1CC 802401CC 46020001 */  sub.s     $f0, $f0, $f2
/* A4F1D0 802401D0 44821000 */  mtc1      $v0, $f2
/* A4F1D4 802401D4 00000000 */  nop
/* A4F1D8 802401D8 468010A1 */  cvt.d.w   $f2, $f2
/* A4F1DC 802401DC 46221080 */  add.d     $f2, $f2, $f2
/* A4F1E0 802401E0 46000005 */  abs.s     $f0, $f0
/* A4F1E4 802401E4 46000021 */  cvt.d.s   $f0, $f0
/* A4F1E8 802401E8 4620103E */  c.le.d    $f2, $f0
/* A4F1EC 802401EC 00000000 */  nop
/* A4F1F0 802401F0 4501001F */  bc1t      .L80240270
/* A4F1F4 802401F4 2402FFFF */   addiu    $v0, $zero, -1
/* A4F1F8 802401F8 3C038011 */  lui       $v1, %hi(gPartnerActionStatus+0x3)
/* A4F1FC 802401FC 8063EBB3 */  lb        $v1, %lo(gPartnerActionStatus+0x3)($v1)
/* A4F200 80240200 24020009 */  addiu     $v0, $zero, 9
/* A4F204 80240204 10620019 */  beq       $v1, $v0, .L8024026C
/* A4F208 80240208 24020007 */   addiu    $v0, $zero, 7
/* A4F20C 8024020C 14620005 */  bne       $v1, $v0, .L80240224
/* A4F210 80240210 2402FFFF */   addiu    $v0, $zero, -1
/* A4F214 80240214 0809009C */  j         .L80240270
/* A4F218 80240218 00000000 */   nop
.L8024021C:
/* A4F21C 8024021C 0809009C */  j         .L80240270
/* A4F220 80240220 0240102D */   daddu    $v0, $s2, $zero
.L80240224:
/* A4F224 80240224 8E620078 */  lw        $v0, 0x78($s3)
/* A4F228 80240228 18400010 */  blez      $v0, .L8024026C
/* A4F22C 8024022C 0000882D */   daddu    $s1, $zero, $zero
.L80240230:
/* A4F230 80240230 86620008 */  lh        $v0, 8($s3)
/* A4F234 80240234 00511021 */  addu      $v0, $v0, $s1
/* A4F238 80240238 24520001 */  addiu     $s2, $v0, 1
/* A4F23C 8024023C 0C00FB3A */  jal       get_enemy
/* A4F240 80240240 0240202D */   daddu    $a0, $s2, $zero
/* A4F244 80240244 0240202D */  daddu     $a0, $s2, $zero
/* A4F248 80240248 0C00EABB */  jal       get_npc_unsafe
/* A4F24C 8024024C 0040802D */   daddu    $s0, $v0, $zero
/* A4F250 80240250 8E02006C */  lw        $v0, 0x6c($s0)
/* A4F254 80240254 1040FFF1 */  beqz      $v0, .L8024021C
/* A4F258 80240258 26310001 */   addiu    $s1, $s1, 1
/* A4F25C 8024025C 8E620078 */  lw        $v0, 0x78($s3)
/* A4F260 80240260 0222102A */  slt       $v0, $s1, $v0
/* A4F264 80240264 1440FFF2 */  bnez      $v0, .L80240230
/* A4F268 80240268 00000000 */   nop
.L8024026C:
/* A4F26C 8024026C 2402FFFF */  addiu     $v0, $zero, -1
.L80240270:
/* A4F270 80240270 8FBF0020 */  lw        $ra, 0x20($sp)
/* A4F274 80240274 8FB3001C */  lw        $s3, 0x1c($sp)
/* A4F278 80240278 8FB20018 */  lw        $s2, 0x18($sp)
/* A4F27C 8024027C 8FB10014 */  lw        $s1, 0x14($sp)
/* A4F280 80240280 8FB00010 */  lw        $s0, 0x10($sp)
/* A4F284 80240284 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A4F288 80240288 03E00008 */  jr        $ra
/* A4F28C 8024028C 27BD0030 */   addiu    $sp, $sp, 0x30
