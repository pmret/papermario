.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243008_A67098
.double 0.8

.section .text

glabel func_802414C8_A65558
/* A65558 802414C8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A6555C 802414CC AFB3001C */  sw        $s3, 0x1c($sp)
/* A65560 802414D0 0080982D */  daddu     $s3, $a0, $zero
/* A65564 802414D4 AFBF0020 */  sw        $ra, 0x20($sp)
/* A65568 802414D8 AFB20018 */  sw        $s2, 0x18($sp)
/* A6556C 802414DC AFB10014 */  sw        $s1, 0x14($sp)
/* A65570 802414E0 AFB00010 */  sw        $s0, 0x10($sp)
/* A65574 802414E4 8E710148 */  lw        $s1, 0x148($s3)
/* A65578 802414E8 86240008 */  lh        $a0, 8($s1)
/* A6557C 802414EC 0C00EABB */  jal       get_npc_unsafe
/* A65580 802414F0 00A0902D */   daddu    $s2, $a1, $zero
/* A65584 802414F4 0040802D */  daddu     $s0, $v0, $zero
/* A65588 802414F8 8602008E */  lh        $v0, 0x8e($s0)
/* A6558C 802414FC 9603008E */  lhu       $v1, 0x8e($s0)
/* A65590 80241500 18400005 */  blez      $v0, .L80241518
/* A65594 80241504 2462FFFF */   addiu    $v0, $v1, -1
/* A65598 80241508 A602008E */  sh        $v0, 0x8e($s0)
/* A6559C 8024150C 00021400 */  sll       $v0, $v0, 0x10
/* A655A0 80241510 1C400033 */  bgtz      $v0, .L802415E0
/* A655A4 80241514 00000000 */   nop
.L80241518:
/* A655A8 80241518 8602008C */  lh        $v0, 0x8c($s0)
/* A655AC 8024151C 14400030 */  bnez      $v0, .L802415E0
/* A655B0 80241520 00000000 */   nop
/* A655B4 80241524 8E2200CC */  lw        $v0, 0xcc($s1)
/* A655B8 80241528 8C420024 */  lw        $v0, 0x24($v0)
/* A655BC 8024152C AE020028 */  sw        $v0, 0x28($s0)
/* A655C0 80241530 C6400018 */  lwc1      $f0, 0x18($s2)
/* A655C4 80241534 E6000018 */  swc1      $f0, 0x18($s0)
/* A655C8 80241538 8E230088 */  lw        $v1, 0x88($s1)
/* A655CC 8024153C 24020005 */  addiu     $v0, $zero, 5
/* A655D0 80241540 10620005 */  beq       $v1, $v0, .L80241558
/* A655D4 80241544 00000000 */   nop
/* A655D8 80241548 10600003 */  beqz      $v1, .L80241558
/* A655DC 8024154C 24020001 */   addiu    $v0, $zero, 1
/* A655E0 80241550 14620006 */  bne       $v1, $v0, .L8024156C
/* A655E4 80241554 00000000 */   nop
.L80241558:
/* A655E8 80241558 8E220084 */  lw        $v0, 0x84($s1)
/* A655EC 8024155C 00021FC2 */  srl       $v1, $v0, 0x1f
/* A655F0 80241560 00431021 */  addu      $v0, $v0, $v1
/* A655F4 80241564 00021043 */  sra       $v0, $v0, 1
/* A655F8 80241568 A60200A8 */  sh        $v0, 0xa8($s0)
.L8024156C:
/* A655FC 8024156C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A65600 80241570 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A65604 80241574 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A65608 80241578 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A6560C 8024157C 8C460028 */  lw        $a2, 0x28($v0)
/* A65610 80241580 0C00A7B5 */  jal       dist2D
/* A65614 80241584 8C470030 */   lw       $a3, 0x30($v0)
/* A65618 80241588 C6020018 */  lwc1      $f2, 0x18($s0)
/* A6561C 8024158C 46020003 */  div.s     $f0, $f0, $f2
/* A65620 80241590 3C018024 */  lui       $at, %hi(D_80243008_A67098)
/* A65624 80241594 D4223008 */  ldc1      $f2, %lo(D_80243008_A67098)($at)
/* A65628 80241598 46000021 */  cvt.d.s   $f0, $f0
/* A6562C 8024159C 46220000 */  add.d     $f0, $f0, $f2
/* A65630 802415A0 4620010D */  trunc.w.d $f4, $f0
/* A65634 802415A4 44022000 */  mfc1      $v0, $f4
/* A65638 802415A8 00000000 */  nop
/* A6563C 802415AC A602008E */  sh        $v0, 0x8e($s0)
/* A65640 802415B0 00021400 */  sll       $v0, $v0, 0x10
/* A65644 802415B4 8E230078 */  lw        $v1, 0x78($s1)
/* A65648 802415B8 00021403 */  sra       $v0, $v0, 0x10
/* A6564C 802415BC 0043102A */  slt       $v0, $v0, $v1
/* A65650 802415C0 10400003 */  beqz      $v0, .L802415D0
/* A65654 802415C4 00000000 */   nop
/* A65658 802415C8 9622007A */  lhu       $v0, 0x7a($s1)
/* A6565C 802415CC A602008E */  sh        $v0, 0x8e($s0)
.L802415D0:
/* A65660 802415D0 8602008E */  lh        $v0, 0x8e($s0)
/* A65664 802415D4 AE22007C */  sw        $v0, 0x7c($s1)
/* A65668 802415D8 2402000E */  addiu     $v0, $zero, 0xe
/* A6566C 802415DC AE620070 */  sw        $v0, 0x70($s3)
.L802415E0:
/* A65670 802415E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* A65674 802415E4 8FB3001C */  lw        $s3, 0x1c($sp)
/* A65678 802415E8 8FB20018 */  lw        $s2, 0x18($sp)
/* A6567C 802415EC 8FB10014 */  lw        $s1, 0x14($sp)
/* A65680 802415F0 8FB00010 */  lw        $s0, 0x10($sp)
/* A65684 802415F4 03E00008 */  jr        $ra
/* A65688 802415F8 27BD0028 */   addiu    $sp, $sp, 0x28
