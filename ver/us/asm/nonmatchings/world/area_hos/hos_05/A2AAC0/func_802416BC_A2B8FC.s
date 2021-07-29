.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8024F1E8_A39428
.double 0.2

.section .text

glabel func_802416BC_A2B8FC
/* A2B8FC 802416BC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A2B900 802416C0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A2B904 802416C4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A2B908 802416C8 3C04800B */  lui       $a0, %hi(gCameras)
/* A2B90C 802416CC 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A2B910 802416D0 AFBF0020 */  sw        $ra, 0x20($sp)
/* A2B914 802416D4 AFB3001C */  sw        $s3, 0x1c($sp)
/* A2B918 802416D8 AFB20018 */  sw        $s2, 0x18($sp)
/* A2B91C 802416DC AFB10014 */  sw        $s1, 0x14($sp)
/* A2B920 802416E0 AFB00010 */  sw        $s0, 0x10($sp)
/* A2B924 802416E4 F7B60030 */  sdc1      $f22, 0x30($sp)
/* A2B928 802416E8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A2B92C 802416EC 00031080 */  sll       $v0, $v1, 2
/* A2B930 802416F0 00431021 */  addu      $v0, $v0, $v1
/* A2B934 802416F4 00021080 */  sll       $v0, $v0, 2
/* A2B938 802416F8 00431023 */  subu      $v0, $v0, $v1
/* A2B93C 802416FC 000218C0 */  sll       $v1, $v0, 3
/* A2B940 80241700 00431021 */  addu      $v0, $v0, $v1
/* A2B944 80241704 000210C0 */  sll       $v0, $v0, 3
/* A2B948 80241708 10A00004 */  beqz      $a1, .L8024171C
/* A2B94C 8024170C 00449021 */   addu     $s2, $v0, $a0
/* A2B950 80241710 96420000 */  lhu       $v0, ($s2)
/* A2B954 80241714 34420008 */  ori       $v0, $v0, 8
/* A2B958 80241718 A6420000 */  sh        $v0, ($s2)
.L8024171C:
/* A2B95C 8024171C 3C118025 */  lui       $s1, %hi(D_80249900_A33B40)
/* A2B960 80241720 26319900 */  addiu     $s1, $s1, %lo(D_80249900_A33B40)
/* A2B964 80241724 8E230000 */  lw        $v1, ($s1)
/* A2B968 80241728 00031100 */  sll       $v0, $v1, 4
/* A2B96C 8024172C 00431023 */  subu      $v0, $v0, $v1
/* A2B970 80241730 00021080 */  sll       $v0, $v0, 2
/* A2B974 80241734 00431021 */  addu      $v0, $v0, $v1
/* A2B978 80241738 00021080 */  sll       $v0, $v0, 2
/* A2B97C 8024173C 00431023 */  subu      $v0, $v0, $v1
/* A2B980 80241740 00021040 */  sll       $v0, $v0, 1
/* A2B984 80241744 44826000 */  mtc1      $v0, $f12
/* A2B988 80241748 00000000 */  nop
/* A2B98C 8024174C 46806320 */  cvt.s.w   $f12, $f12
/* A2B990 80241750 0C00A8BB */  jal       sin_deg
/* A2B994 80241754 26530194 */   addiu    $s3, $s2, 0x194
/* A2B998 80241758 3C108025 */  lui       $s0, %hi(D_80249904_A33B44)
/* A2B99C 8024175C 26109904 */  addiu     $s0, $s0, %lo(D_80249904_A33B44)
/* A2B9A0 80241760 8E230000 */  lw        $v1, ($s1)
/* A2B9A4 80241764 C6140000 */  lwc1      $f20, ($s0)
/* A2B9A8 80241768 000311C0 */  sll       $v0, $v1, 7
/* A2B9AC 8024176C 00431023 */  subu      $v0, $v0, $v1
/* A2B9B0 80241770 00021040 */  sll       $v0, $v0, 1
/* A2B9B4 80241774 4600A502 */  mul.s     $f20, $f20, $f0
/* A2B9B8 80241778 00000000 */  nop
/* A2B9BC 8024177C 44826000 */  mtc1      $v0, $f12
/* A2B9C0 80241780 00000000 */  nop
/* A2B9C4 80241784 0C00A8D4 */  jal       cos_deg
/* A2B9C8 80241788 46806320 */   cvt.s.w  $f12, $f12
/* A2B9CC 8024178C C6020000 */  lwc1      $f2, ($s0)
/* A2B9D0 80241790 46001082 */  mul.s     $f2, $f2, $f0
/* A2B9D4 80241794 00000000 */  nop
/* A2B9D8 80241798 4480B000 */  mtc1      $zero, $f22
/* A2B9DC 8024179C 00000000 */  nop
/* A2B9E0 802417A0 4407B000 */  mfc1      $a3, $f22
/* A2B9E4 802417A4 4405A000 */  mfc1      $a1, $f20
/* A2B9E8 802417A8 44061000 */  mfc1      $a2, $f2
/* A2B9EC 802417AC 0C019E40 */  jal       guTranslateF
/* A2B9F0 802417B0 0260202D */   daddu    $a0, $s3, $zero
/* A2B9F4 802417B4 C6020000 */  lwc1      $f2, ($s0)
/* A2B9F8 802417B8 3C014140 */  lui       $at, 0x4140
/* A2B9FC 802417BC 44810000 */  mtc1      $at, $f0
/* A2BA00 802417C0 00000000 */  nop
/* A2BA04 802417C4 46020001 */  sub.s     $f0, $f0, $f2
/* A2BA08 802417C8 3C018025 */  lui       $at, %hi(D_8024F1E8_A39428)
/* A2BA0C 802417CC D424F1E8 */  ldc1      $f4, %lo(D_8024F1E8_A39428)($at)
/* A2BA10 802417D0 46000021 */  cvt.d.s   $f0, $f0
/* A2BA14 802417D4 46240002 */  mul.d     $f0, $f0, $f4
/* A2BA18 802417D8 00000000 */  nop
/* A2BA1C 802417DC 8E220000 */  lw        $v0, ($s1)
/* A2BA20 802417E0 460010A1 */  cvt.d.s   $f2, $f2
/* A2BA24 802417E4 24420001 */  addiu     $v0, $v0, 1
/* A2BA28 802417E8 46201080 */  add.d     $f2, $f2, $f0
/* A2BA2C 802417EC AE220000 */  sw        $v0, ($s1)
/* A2BA30 802417F0 28420015 */  slti      $v0, $v0, 0x15
/* A2BA34 802417F4 462010A0 */  cvt.s.d   $f2, $f2
/* A2BA38 802417F8 10400003 */  beqz      $v0, .L80241808
/* A2BA3C 802417FC E6020000 */   swc1     $f2, ($s0)
/* A2BA40 80241800 0809060B */  j         .L8024182C
/* A2BA44 80241804 0000102D */   daddu    $v0, $zero, $zero
.L80241808:
/* A2BA48 80241808 4405B000 */  mfc1      $a1, $f22
/* A2BA4C 8024180C 0260202D */  daddu     $a0, $s3, $zero
/* A2BA50 80241810 00A0302D */  daddu     $a2, $a1, $zero
/* A2BA54 80241814 0C019E40 */  jal       guTranslateF
/* A2BA58 80241818 00A0382D */   daddu    $a3, $a1, $zero
/* A2BA5C 8024181C 96430000 */  lhu       $v1, ($s2)
/* A2BA60 80241820 24020001 */  addiu     $v0, $zero, 1
/* A2BA64 80241824 3063FFF7 */  andi      $v1, $v1, 0xfff7
/* A2BA68 80241828 A6430000 */  sh        $v1, ($s2)
.L8024182C:
/* A2BA6C 8024182C 8FBF0020 */  lw        $ra, 0x20($sp)
/* A2BA70 80241830 8FB3001C */  lw        $s3, 0x1c($sp)
/* A2BA74 80241834 8FB20018 */  lw        $s2, 0x18($sp)
/* A2BA78 80241838 8FB10014 */  lw        $s1, 0x14($sp)
/* A2BA7C 8024183C 8FB00010 */  lw        $s0, 0x10($sp)
/* A2BA80 80241840 D7B60030 */  ldc1      $f22, 0x30($sp)
/* A2BA84 80241844 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A2BA88 80241848 03E00008 */  jr        $ra
/* A2BA8C 8024184C 27BD0038 */   addiu    $sp, $sp, 0x38
