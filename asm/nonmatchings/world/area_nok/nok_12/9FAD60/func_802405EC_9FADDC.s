.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405EC_9FADDC
/* 9FADDC 802405EC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9FADE0 802405F0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9FADE4 802405F4 0080982D */  daddu     $s3, $a0, $zero
/* 9FADE8 802405F8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9FADEC 802405FC AFB20018 */  sw        $s2, 0x18($sp)
/* 9FADF0 80240600 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FADF4 80240604 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FADF8 80240608 8E710148 */  lw        $s1, 0x148($s3)
/* 9FADFC 8024060C 86240008 */  lh        $a0, 8($s1)
/* 9FAE00 80240610 0C00EABB */  jal       get_npc_unsafe
/* 9FAE04 80240614 00A0902D */   daddu    $s2, $a1, $zero
/* 9FAE08 80240618 0040802D */  daddu     $s0, $v0, $zero
/* 9FAE0C 8024061C 8602008E */  lh        $v0, 0x8e($s0)
/* 9FAE10 80240620 9603008E */  lhu       $v1, 0x8e($s0)
/* 9FAE14 80240624 18400005 */  blez      $v0, .L8024063C
/* 9FAE18 80240628 2462FFFF */   addiu    $v0, $v1, -1
/* 9FAE1C 8024062C A602008E */  sh        $v0, 0x8e($s0)
/* 9FAE20 80240630 00021400 */  sll       $v0, $v0, 0x10
/* 9FAE24 80240634 1C400033 */  bgtz      $v0, .L80240704
/* 9FAE28 80240638 00000000 */   nop      
.L8024063C:
/* 9FAE2C 8024063C 8602008C */  lh        $v0, 0x8c($s0)
/* 9FAE30 80240640 14400030 */  bnez      $v0, .L80240704
/* 9FAE34 80240644 00000000 */   nop      
/* 9FAE38 80240648 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9FAE3C 8024064C 8C420024 */  lw        $v0, 0x24($v0)
/* 9FAE40 80240650 AE020028 */  sw        $v0, 0x28($s0)
/* 9FAE44 80240654 C6400018 */  lwc1      $f0, 0x18($s2)
/* 9FAE48 80240658 E6000018 */  swc1      $f0, 0x18($s0)
/* 9FAE4C 8024065C 8E230088 */  lw        $v1, 0x88($s1)
/* 9FAE50 80240660 24020005 */  addiu     $v0, $zero, 5
/* 9FAE54 80240664 10620005 */  beq       $v1, $v0, .L8024067C
/* 9FAE58 80240668 00000000 */   nop      
/* 9FAE5C 8024066C 10600003 */  beqz      $v1, .L8024067C
/* 9FAE60 80240670 24020001 */   addiu    $v0, $zero, 1
/* 9FAE64 80240674 14620006 */  bne       $v1, $v0, .L80240690
/* 9FAE68 80240678 00000000 */   nop      
.L8024067C:
/* 9FAE6C 8024067C 8E220084 */  lw        $v0, 0x84($s1)
/* 9FAE70 80240680 00021FC2 */  srl       $v1, $v0, 0x1f
/* 9FAE74 80240684 00431021 */  addu      $v0, $v0, $v1
/* 9FAE78 80240688 00021043 */  sra       $v0, $v0, 1
/* 9FAE7C 8024068C A60200A8 */  sh        $v0, 0xa8($s0)
.L80240690:
/* 9FAE80 80240690 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9FAE84 80240694 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9FAE88 80240698 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9FAE8C 8024069C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9FAE90 802406A0 8C460028 */  lw        $a2, 0x28($v0)
/* 9FAE94 802406A4 0C00A7B5 */  jal       dist2D
/* 9FAE98 802406A8 8C470030 */   lw       $a3, 0x30($v0)
/* 9FAE9C 802406AC C6020018 */  lwc1      $f2, 0x18($s0)
/* 9FAEA0 802406B0 46020003 */  div.s     $f0, $f0, $f2
/* 9FAEA4 802406B4 3C018024 */  lui       $at, %hi(D_80245A70)
/* 9FAEA8 802406B8 D4225A70 */  ldc1      $f2, %lo(D_80245A70)($at)
/* 9FAEAC 802406BC 46000021 */  cvt.d.s   $f0, $f0
/* 9FAEB0 802406C0 46220000 */  add.d     $f0, $f0, $f2
/* 9FAEB4 802406C4 4620010D */  trunc.w.d $f4, $f0
/* 9FAEB8 802406C8 44022000 */  mfc1      $v0, $f4
/* 9FAEBC 802406CC 00000000 */  nop       
/* 9FAEC0 802406D0 A602008E */  sh        $v0, 0x8e($s0)
/* 9FAEC4 802406D4 00021400 */  sll       $v0, $v0, 0x10
/* 9FAEC8 802406D8 8E230078 */  lw        $v1, 0x78($s1)
/* 9FAECC 802406DC 00021403 */  sra       $v0, $v0, 0x10
/* 9FAED0 802406E0 0043102A */  slt       $v0, $v0, $v1
/* 9FAED4 802406E4 10400003 */  beqz      $v0, .L802406F4
/* 9FAED8 802406E8 00000000 */   nop      
/* 9FAEDC 802406EC 9622007A */  lhu       $v0, 0x7a($s1)
/* 9FAEE0 802406F0 A602008E */  sh        $v0, 0x8e($s0)
.L802406F4:
/* 9FAEE4 802406F4 8602008E */  lh        $v0, 0x8e($s0)
/* 9FAEE8 802406F8 AE22007C */  sw        $v0, 0x7c($s1)
/* 9FAEEC 802406FC 2402000E */  addiu     $v0, $zero, 0xe
/* 9FAEF0 80240700 AE620070 */  sw        $v0, 0x70($s3)
.L80240704:
/* 9FAEF4 80240704 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9FAEF8 80240708 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9FAEFC 8024070C 8FB20018 */  lw        $s2, 0x18($sp)
/* 9FAF00 80240710 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FAF04 80240714 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FAF08 80240718 03E00008 */  jr        $ra
/* 9FAF0C 8024071C 27BD0028 */   addiu    $sp, $sp, 0x28
