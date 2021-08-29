.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80247BB8_DA5088
.double 180.0

glabel D_80247BC0_DA5090
.double 75.0

.section .text

glabel func_80241948_D9EE18
/* D9EE18 80241948 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D9EE1C 8024194C AFB10014 */  sw        $s1, 0x14($sp)
/* D9EE20 80241950 0080882D */  daddu     $s1, $a0, $zero
/* D9EE24 80241954 3C05800B */  lui       $a1, %hi(gCameras)
/* D9EE28 80241958 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* D9EE2C 8024195C AFBF0020 */  sw        $ra, 0x20($sp)
/* D9EE30 80241960 AFB3001C */  sw        $s3, 0x1c($sp)
/* D9EE34 80241964 AFB20018 */  sw        $s2, 0x18($sp)
/* D9EE38 80241968 AFB00010 */  sw        $s0, 0x10($sp)
/* D9EE3C 8024196C F7B40028 */  sdc1      $f20, 0x28($sp)
/* D9EE40 80241970 8E330148 */  lw        $s3, 0x148($s1)
/* D9EE44 80241974 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D9EE48 80241978 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D9EE4C 8024197C 8E30000C */  lw        $s0, 0xc($s1)
/* D9EE50 80241980 00031080 */  sll       $v0, $v1, 2
/* D9EE54 80241984 00431021 */  addu      $v0, $v0, $v1
/* D9EE58 80241988 00021080 */  sll       $v0, $v0, 2
/* D9EE5C 8024198C 00431023 */  subu      $v0, $v0, $v1
/* D9EE60 80241990 000218C0 */  sll       $v1, $v0, 3
/* D9EE64 80241994 00431021 */  addu      $v0, $v0, $v1
/* D9EE68 80241998 000210C0 */  sll       $v0, $v0, 3
/* D9EE6C 8024199C 86640008 */  lh        $a0, 8($s3)
/* D9EE70 802419A0 0C00EABB */  jal       get_npc_unsafe
/* D9EE74 802419A4 00459021 */   addu     $s2, $v0, $a1
/* D9EE78 802419A8 0220202D */  daddu     $a0, $s1, $zero
/* D9EE7C 802419AC 8E050000 */  lw        $a1, ($s0)
/* D9EE80 802419B0 0C0B1EAF */  jal       evt_get_variable
/* D9EE84 802419B4 0040802D */   daddu    $s0, $v0, $zero
/* D9EE88 802419B8 0260202D */  daddu     $a0, $s3, $zero
/* D9EE8C 802419BC 8C460024 */  lw        $a2, 0x24($v0)
/* D9EE90 802419C0 8C470028 */  lw        $a3, 0x28($v0)
/* D9EE94 802419C4 0C0124FB */  jal       func_800493EC
/* D9EE98 802419C8 0000282D */   daddu    $a1, $zero, $zero
/* D9EE9C 802419CC 10400052 */  beqz      $v0, .L80241B18
/* D9EEA0 802419D0 2402FFFF */   addiu    $v0, $zero, -1
/* D9EEA4 802419D4 C64C006C */  lwc1      $f12, 0x6c($s2)
/* D9EEA8 802419D8 C60E000C */  lwc1      $f14, 0xc($s0)
/* D9EEAC 802419DC 3C014387 */  lui       $at, 0x4387
/* D9EEB0 802419E0 4481A000 */  mtc1      $at, $f20
/* D9EEB4 802419E4 0C00A70A */  jal       get_clamped_angle_diff
/* D9EEB8 802419E8 00000000 */   nop
/* D9EEBC 802419EC 0C00A6C9 */  jal       clamp_angle
/* D9EEC0 802419F0 46000306 */   mov.s    $f12, $f0
/* D9EEC4 802419F4 3C018024 */  lui       $at, %hi(D_80247BB8_DA5088)
/* D9EEC8 802419F8 D4227BB8 */  ldc1      $f2, %lo(D_80247BB8_DA5088)($at)
/* D9EECC 802419FC 46000021 */  cvt.d.s   $f0, $f0
/* D9EED0 80241A00 4622003C */  c.lt.d    $f0, $f2
/* D9EED4 80241A04 00000000 */  nop
/* D9EED8 80241A08 45000003 */  bc1f      .L80241A18
/* D9EEDC 80241A0C 00000000 */   nop
/* D9EEE0 80241A10 3C0142B4 */  lui       $at, 0x42b4
/* D9EEE4 80241A14 4481A000 */  mtc1      $at, $f20
.L80241A18:
/* D9EEE8 80241A18 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* D9EEEC 80241A1C 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* D9EEF0 80241A20 C60C0038 */  lwc1      $f12, 0x38($s0)
/* D9EEF4 80241A24 8E220000 */  lw        $v0, ($s1)
/* D9EEF8 80241A28 C60E0040 */  lwc1      $f14, 0x40($s0)
/* D9EEFC 80241A2C 8C460028 */  lw        $a2, 0x28($v0)
/* D9EF00 80241A30 0C00A720 */  jal       atan2
/* D9EF04 80241A34 8C470030 */   lw       $a3, 0x30($v0)
/* D9EF08 80241A38 4600A306 */  mov.s     $f12, $f20
/* D9EF0C 80241A3C 0C00A70A */  jal       get_clamped_angle_diff
/* D9EF10 80241A40 46000386 */   mov.s    $f14, $f0
/* D9EF14 80241A44 46000005 */  abs.s     $f0, $f0
/* D9EF18 80241A48 3C018024 */  lui       $at, %hi(D_80247BC0_DA5090)
/* D9EF1C 80241A4C D4227BC0 */  ldc1      $f2, %lo(D_80247BC0_DA5090)($at)
/* D9EF20 80241A50 46000021 */  cvt.d.s   $f0, $f0
/* D9EF24 80241A54 4620103C */  c.lt.d    $f2, $f0
/* D9EF28 80241A58 00000000 */  nop
/* D9EF2C 80241A5C 4501002E */  bc1t      .L80241B18
/* D9EF30 80241A60 2402FFFF */   addiu    $v0, $zero, -1
/* D9EF34 80241A64 8E220000 */  lw        $v0, ($s1)
/* D9EF38 80241A68 C600003C */  lwc1      $f0, 0x3c($s0)
/* D9EF3C 80241A6C C442002C */  lwc1      $f2, 0x2c($v0)
/* D9EF40 80241A70 860200A8 */  lh        $v0, 0xa8($s0)
/* D9EF44 80241A74 46020001 */  sub.s     $f0, $f0, $f2
/* D9EF48 80241A78 44821000 */  mtc1      $v0, $f2
/* D9EF4C 80241A7C 00000000 */  nop
/* D9EF50 80241A80 468010A1 */  cvt.d.w   $f2, $f2
/* D9EF54 80241A84 46221080 */  add.d     $f2, $f2, $f2
/* D9EF58 80241A88 46000005 */  abs.s     $f0, $f0
/* D9EF5C 80241A8C 46000021 */  cvt.d.s   $f0, $f0
/* D9EF60 80241A90 4620103E */  c.le.d    $f2, $f0
/* D9EF64 80241A94 00000000 */  nop
/* D9EF68 80241A98 4501001F */  bc1t      .L80241B18
/* D9EF6C 80241A9C 2402FFFF */   addiu    $v0, $zero, -1
/* D9EF70 80241AA0 3C038011 */  lui       $v1, %hi(gPartnerActionStatus+0x3)
/* D9EF74 80241AA4 8063EBB3 */  lb        $v1, %lo(gPartnerActionStatus+0x3)($v1)
/* D9EF78 80241AA8 24020009 */  addiu     $v0, $zero, 9
/* D9EF7C 80241AAC 10620019 */  beq       $v1, $v0, .L80241B14
/* D9EF80 80241AB0 24020007 */   addiu    $v0, $zero, 7
/* D9EF84 80241AB4 14620005 */  bne       $v1, $v0, .L80241ACC
/* D9EF88 80241AB8 2402FFFF */   addiu    $v0, $zero, -1
/* D9EF8C 80241ABC 080906C6 */  j         .L80241B18
/* D9EF90 80241AC0 00000000 */   nop
.L80241AC4:
/* D9EF94 80241AC4 080906C6 */  j         .L80241B18
/* D9EF98 80241AC8 0240102D */   daddu    $v0, $s2, $zero
.L80241ACC:
/* D9EF9C 80241ACC 8E620078 */  lw        $v0, 0x78($s3)
/* D9EFA0 80241AD0 18400010 */  blez      $v0, .L80241B14
/* D9EFA4 80241AD4 0000882D */   daddu    $s1, $zero, $zero
.L80241AD8:
/* D9EFA8 80241AD8 86620008 */  lh        $v0, 8($s3)
/* D9EFAC 80241ADC 00511021 */  addu      $v0, $v0, $s1
/* D9EFB0 80241AE0 24520001 */  addiu     $s2, $v0, 1
/* D9EFB4 80241AE4 0C00FB3A */  jal       get_enemy
/* D9EFB8 80241AE8 0240202D */   daddu    $a0, $s2, $zero
/* D9EFBC 80241AEC 0240202D */  daddu     $a0, $s2, $zero
/* D9EFC0 80241AF0 0C00EABB */  jal       get_npc_unsafe
/* D9EFC4 80241AF4 0040802D */   daddu    $s0, $v0, $zero
/* D9EFC8 80241AF8 8E02006C */  lw        $v0, 0x6c($s0)
/* D9EFCC 80241AFC 1040FFF1 */  beqz      $v0, .L80241AC4
/* D9EFD0 80241B00 26310001 */   addiu    $s1, $s1, 1
/* D9EFD4 80241B04 8E620078 */  lw        $v0, 0x78($s3)
/* D9EFD8 80241B08 0222102A */  slt       $v0, $s1, $v0
/* D9EFDC 80241B0C 1440FFF2 */  bnez      $v0, .L80241AD8
/* D9EFE0 80241B10 00000000 */   nop
.L80241B14:
/* D9EFE4 80241B14 2402FFFF */  addiu     $v0, $zero, -1
.L80241B18:
/* D9EFE8 80241B18 8FBF0020 */  lw        $ra, 0x20($sp)
/* D9EFEC 80241B1C 8FB3001C */  lw        $s3, 0x1c($sp)
/* D9EFF0 80241B20 8FB20018 */  lw        $s2, 0x18($sp)
/* D9EFF4 80241B24 8FB10014 */  lw        $s1, 0x14($sp)
/* D9EFF8 80241B28 8FB00010 */  lw        $s0, 0x10($sp)
/* D9EFFC 80241B2C D7B40028 */  ldc1      $f20, 0x28($sp)
/* D9F000 80241B30 03E00008 */  jr        $ra
/* D9F004 80241B34 27BD0030 */   addiu    $sp, $sp, 0x30
