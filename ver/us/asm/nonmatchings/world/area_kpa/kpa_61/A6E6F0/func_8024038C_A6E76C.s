.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243CD0_A720B0
.double 0.8

.section .text

glabel func_8024038C_A6E76C
/* A6E76C 8024038C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A6E770 80240390 AFB3001C */  sw        $s3, 0x1c($sp)
/* A6E774 80240394 0080982D */  daddu     $s3, $a0, $zero
/* A6E778 80240398 AFBF0020 */  sw        $ra, 0x20($sp)
/* A6E77C 8024039C AFB20018 */  sw        $s2, 0x18($sp)
/* A6E780 802403A0 AFB10014 */  sw        $s1, 0x14($sp)
/* A6E784 802403A4 AFB00010 */  sw        $s0, 0x10($sp)
/* A6E788 802403A8 8E710148 */  lw        $s1, 0x148($s3)
/* A6E78C 802403AC 86240008 */  lh        $a0, 8($s1)
/* A6E790 802403B0 0C00EABB */  jal       get_npc_unsafe
/* A6E794 802403B4 00A0902D */   daddu    $s2, $a1, $zero
/* A6E798 802403B8 0040802D */  daddu     $s0, $v0, $zero
/* A6E79C 802403BC 8602008E */  lh        $v0, 0x8e($s0)
/* A6E7A0 802403C0 9603008E */  lhu       $v1, 0x8e($s0)
/* A6E7A4 802403C4 18400005 */  blez      $v0, .L802403DC
/* A6E7A8 802403C8 2462FFFF */   addiu    $v0, $v1, -1
/* A6E7AC 802403CC A602008E */  sh        $v0, 0x8e($s0)
/* A6E7B0 802403D0 00021400 */  sll       $v0, $v0, 0x10
/* A6E7B4 802403D4 1C400033 */  bgtz      $v0, .L802404A4
/* A6E7B8 802403D8 00000000 */   nop
.L802403DC:
/* A6E7BC 802403DC 8602008C */  lh        $v0, 0x8c($s0)
/* A6E7C0 802403E0 14400030 */  bnez      $v0, .L802404A4
/* A6E7C4 802403E4 00000000 */   nop
/* A6E7C8 802403E8 8E2200CC */  lw        $v0, 0xcc($s1)
/* A6E7CC 802403EC 8C420024 */  lw        $v0, 0x24($v0)
/* A6E7D0 802403F0 AE020028 */  sw        $v0, 0x28($s0)
/* A6E7D4 802403F4 C6400018 */  lwc1      $f0, 0x18($s2)
/* A6E7D8 802403F8 E6000018 */  swc1      $f0, 0x18($s0)
/* A6E7DC 802403FC 8E230088 */  lw        $v1, 0x88($s1)
/* A6E7E0 80240400 24020005 */  addiu     $v0, $zero, 5
/* A6E7E4 80240404 10620005 */  beq       $v1, $v0, .L8024041C
/* A6E7E8 80240408 00000000 */   nop
/* A6E7EC 8024040C 10600003 */  beqz      $v1, .L8024041C
/* A6E7F0 80240410 24020001 */   addiu    $v0, $zero, 1
/* A6E7F4 80240414 14620006 */  bne       $v1, $v0, .L80240430
/* A6E7F8 80240418 00000000 */   nop
.L8024041C:
/* A6E7FC 8024041C 8E220084 */  lw        $v0, 0x84($s1)
/* A6E800 80240420 00021FC2 */  srl       $v1, $v0, 0x1f
/* A6E804 80240424 00431021 */  addu      $v0, $v0, $v1
/* A6E808 80240428 00021043 */  sra       $v0, $v0, 1
/* A6E80C 8024042C A60200A8 */  sh        $v0, 0xa8($s0)
.L80240430:
/* A6E810 80240430 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A6E814 80240434 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A6E818 80240438 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A6E81C 8024043C C60E0040 */  lwc1      $f14, 0x40($s0)
/* A6E820 80240440 8C460028 */  lw        $a2, 0x28($v0)
/* A6E824 80240444 0C00A7B5 */  jal       dist2D
/* A6E828 80240448 8C470030 */   lw       $a3, 0x30($v0)
/* A6E82C 8024044C C6020018 */  lwc1      $f2, 0x18($s0)
/* A6E830 80240450 46020003 */  div.s     $f0, $f0, $f2
/* A6E834 80240454 3C018024 */  lui       $at, %hi(D_80243CD0_A720B0)
/* A6E838 80240458 D4223CD0 */  ldc1      $f2, %lo(D_80243CD0_A720B0)($at)
/* A6E83C 8024045C 46000021 */  cvt.d.s   $f0, $f0
/* A6E840 80240460 46220000 */  add.d     $f0, $f0, $f2
/* A6E844 80240464 4620010D */  trunc.w.d $f4, $f0
/* A6E848 80240468 44022000 */  mfc1      $v0, $f4
/* A6E84C 8024046C 00000000 */  nop
/* A6E850 80240470 A602008E */  sh        $v0, 0x8e($s0)
/* A6E854 80240474 00021400 */  sll       $v0, $v0, 0x10
/* A6E858 80240478 8E230078 */  lw        $v1, 0x78($s1)
/* A6E85C 8024047C 00021403 */  sra       $v0, $v0, 0x10
/* A6E860 80240480 0043102A */  slt       $v0, $v0, $v1
/* A6E864 80240484 10400003 */  beqz      $v0, .L80240494
/* A6E868 80240488 00000000 */   nop
/* A6E86C 8024048C 9622007A */  lhu       $v0, 0x7a($s1)
/* A6E870 80240490 A602008E */  sh        $v0, 0x8e($s0)
.L80240494:
/* A6E874 80240494 8602008E */  lh        $v0, 0x8e($s0)
/* A6E878 80240498 AE22007C */  sw        $v0, 0x7c($s1)
/* A6E87C 8024049C 2402000E */  addiu     $v0, $zero, 0xe
/* A6E880 802404A0 AE620070 */  sw        $v0, 0x70($s3)
.L802404A4:
/* A6E884 802404A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* A6E888 802404A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* A6E88C 802404AC 8FB20018 */  lw        $s2, 0x18($sp)
/* A6E890 802404B0 8FB10014 */  lw        $s1, 0x14($sp)
/* A6E894 802404B4 8FB00010 */  lw        $s0, 0x10($sp)
/* A6E898 802404B8 03E00008 */  jr        $ra
/* A6E89C 802404BC 27BD0028 */   addiu    $sp, $sp, 0x28
