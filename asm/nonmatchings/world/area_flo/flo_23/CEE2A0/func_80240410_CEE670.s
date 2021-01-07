.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240410_CEE670
/* CEE670 80240410 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CEE674 80240414 AFB3001C */  sw        $s3, 0x1c($sp)
/* CEE678 80240418 0080982D */  daddu     $s3, $a0, $zero
/* CEE67C 8024041C AFBF0020 */  sw        $ra, 0x20($sp)
/* CEE680 80240420 AFB20018 */  sw        $s2, 0x18($sp)
/* CEE684 80240424 AFB10014 */  sw        $s1, 0x14($sp)
/* CEE688 80240428 AFB00010 */  sw        $s0, 0x10($sp)
/* CEE68C 8024042C 8E710148 */  lw        $s1, 0x148($s3)
/* CEE690 80240430 86240008 */  lh        $a0, 8($s1)
/* CEE694 80240434 0C00EABB */  jal       get_npc_unsafe
/* CEE698 80240438 00A0902D */   daddu    $s2, $a1, $zero
/* CEE69C 8024043C 0040802D */  daddu     $s0, $v0, $zero
/* CEE6A0 80240440 8602008E */  lh        $v0, 0x8e($s0)
/* CEE6A4 80240444 9603008E */  lhu       $v1, 0x8e($s0)
/* CEE6A8 80240448 18400005 */  blez      $v0, .L80240460
/* CEE6AC 8024044C 2462FFFF */   addiu    $v0, $v1, -1
/* CEE6B0 80240450 A602008E */  sh        $v0, 0x8e($s0)
/* CEE6B4 80240454 00021400 */  sll       $v0, $v0, 0x10
/* CEE6B8 80240458 1C400033 */  bgtz      $v0, .L80240528
/* CEE6BC 8024045C 00000000 */   nop      
.L80240460:
/* CEE6C0 80240460 8602008C */  lh        $v0, 0x8c($s0)
/* CEE6C4 80240464 14400030 */  bnez      $v0, .L80240528
/* CEE6C8 80240468 00000000 */   nop      
/* CEE6CC 8024046C 8E2200CC */  lw        $v0, 0xcc($s1)
/* CEE6D0 80240470 8C420024 */  lw        $v0, 0x24($v0)
/* CEE6D4 80240474 AE020028 */  sw        $v0, 0x28($s0)
/* CEE6D8 80240478 C6400018 */  lwc1      $f0, 0x18($s2)
/* CEE6DC 8024047C E6000018 */  swc1      $f0, 0x18($s0)
/* CEE6E0 80240480 8E230088 */  lw        $v1, 0x88($s1)
/* CEE6E4 80240484 24020005 */  addiu     $v0, $zero, 5
/* CEE6E8 80240488 10620005 */  beq       $v1, $v0, .L802404A0
/* CEE6EC 8024048C 00000000 */   nop      
/* CEE6F0 80240490 10600003 */  beqz      $v1, .L802404A0
/* CEE6F4 80240494 24020001 */   addiu    $v0, $zero, 1
/* CEE6F8 80240498 14620006 */  bne       $v1, $v0, .L802404B4
/* CEE6FC 8024049C 00000000 */   nop      
.L802404A0:
/* CEE700 802404A0 8E220084 */  lw        $v0, 0x84($s1)
/* CEE704 802404A4 00021FC2 */  srl       $v1, $v0, 0x1f
/* CEE708 802404A8 00431021 */  addu      $v0, $v0, $v1
/* CEE70C 802404AC 00021043 */  sra       $v0, $v0, 1
/* CEE710 802404B0 A60200A8 */  sh        $v0, 0xa8($s0)
.L802404B4:
/* CEE714 802404B4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CEE718 802404B8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CEE71C 802404BC C60C0038 */  lwc1      $f12, 0x38($s0)
/* CEE720 802404C0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CEE724 802404C4 8C460028 */  lw        $a2, 0x28($v0)
/* CEE728 802404C8 0C00A7B5 */  jal       dist2D
/* CEE72C 802404CC 8C470030 */   lw       $a3, 0x30($v0)
/* CEE730 802404D0 C6020018 */  lwc1      $f2, 0x18($s0)
/* CEE734 802404D4 46020003 */  div.s     $f0, $f0, $f2
/* CEE738 802404D8 3C018024 */  lui       $at, %hi(D_80242680)
/* CEE73C 802404DC D4222680 */  ldc1      $f2, %lo(D_80242680)($at)
/* CEE740 802404E0 46000021 */  cvt.d.s   $f0, $f0
/* CEE744 802404E4 46220000 */  add.d     $f0, $f0, $f2
/* CEE748 802404E8 4620010D */  trunc.w.d $f4, $f0
/* CEE74C 802404EC 44022000 */  mfc1      $v0, $f4
/* CEE750 802404F0 00000000 */  nop       
/* CEE754 802404F4 A602008E */  sh        $v0, 0x8e($s0)
/* CEE758 802404F8 00021400 */  sll       $v0, $v0, 0x10
/* CEE75C 802404FC 8E230078 */  lw        $v1, 0x78($s1)
/* CEE760 80240500 00021403 */  sra       $v0, $v0, 0x10
/* CEE764 80240504 0043102A */  slt       $v0, $v0, $v1
/* CEE768 80240508 10400003 */  beqz      $v0, .L80240518
/* CEE76C 8024050C 00000000 */   nop      
/* CEE770 80240510 9622007A */  lhu       $v0, 0x7a($s1)
/* CEE774 80240514 A602008E */  sh        $v0, 0x8e($s0)
.L80240518:
/* CEE778 80240518 8602008E */  lh        $v0, 0x8e($s0)
/* CEE77C 8024051C AE22007C */  sw        $v0, 0x7c($s1)
/* CEE780 80240520 2402000E */  addiu     $v0, $zero, 0xe
/* CEE784 80240524 AE620070 */  sw        $v0, 0x70($s3)
.L80240528:
/* CEE788 80240528 8FBF0020 */  lw        $ra, 0x20($sp)
/* CEE78C 8024052C 8FB3001C */  lw        $s3, 0x1c($sp)
/* CEE790 80240530 8FB20018 */  lw        $s2, 0x18($sp)
/* CEE794 80240534 8FB10014 */  lw        $s1, 0x14($sp)
/* CEE798 80240538 8FB00010 */  lw        $s0, 0x10($sp)
/* CEE79C 8024053C 03E00008 */  jr        $ra
/* CEE7A0 80240540 27BD0028 */   addiu    $sp, $sp, 0x28
