.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242704_A2C944
/* A2C944 80242704 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A2C948 80242708 24040003 */  addiu     $a0, $zero, 3
/* A2C94C 8024270C AFB1001C */  sw        $s1, 0x1c($sp)
/* A2C950 80242710 3C118025 */  lui       $s1, 0x8025
/* A2C954 80242714 26319AA4 */  addiu     $s1, $s1, -0x655c
/* A2C958 80242718 AFBF0030 */  sw        $ra, 0x30($sp)
/* A2C95C 8024271C AFB5002C */  sw        $s5, 0x2c($sp)
/* A2C960 80242720 AFB40028 */  sw        $s4, 0x28($sp)
/* A2C964 80242724 AFB30024 */  sw        $s3, 0x24($sp)
/* A2C968 80242728 AFB20020 */  sw        $s2, 0x20($sp)
/* A2C96C 8024272C AFB00018 */  sw        $s0, 0x18($sp)
/* A2C970 80242730 F7B60040 */  sdc1      $f22, 0x40($sp)
/* A2C974 80242734 F7B40038 */  sdc1      $f20, 0x38($sp)
/* A2C978 80242738 C6200000 */  lwc1      $f0, ($s1)
/* A2C97C 8024273C 46800020 */  cvt.s.w   $f0, $f0
/* A2C980 80242740 3C138025 */  lui       $s3, 0x8025
/* A2C984 80242744 26739AA0 */  addiu     $s3, $s3, -0x6560
/* A2C988 80242748 3C0541C8 */  lui       $a1, 0x41c8
/* A2C98C 8024274C 3C014348 */  lui       $at, 0x4348
/* A2C990 80242750 4481B000 */  mtc1      $at, $f22
/* A2C994 80242754 44070000 */  mfc1      $a3, $f0
/* A2C998 80242758 3C0142F0 */  lui       $at, 0x42f0
/* A2C99C 8024275C 44810000 */  mtc1      $at, $f0
/* A2C9A0 80242760 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* A2C9A4 80242764 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* A2C9A8 80242768 3C03800B */  lui       $v1, %hi(gCameras)
/* A2C9AC 8024276C 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* A2C9B0 80242770 AFB30014 */  sw        $s3, 0x14($sp)
/* A2C9B4 80242774 00028080 */  sll       $s0, $v0, 2
/* A2C9B8 80242778 02028021 */  addu      $s0, $s0, $v0
/* A2C9BC 8024277C 00108080 */  sll       $s0, $s0, 2
/* A2C9C0 80242780 02028023 */  subu      $s0, $s0, $v0
/* A2C9C4 80242784 00901004 */  sllv      $v0, $s0, $a0
/* A2C9C8 80242788 02028021 */  addu      $s0, $s0, $v0
/* A2C9CC 8024278C 00908004 */  sllv      $s0, $s0, $a0
/* A2C9D0 80242790 4406B000 */  mfc1      $a2, $f22
/* A2C9D4 80242794 02038021 */  addu      $s0, $s0, $v1
/* A2C9D8 80242798 0C090439 */  jal       func_802410E4_A2B324
/* A2C9DC 8024279C E7A00010 */   swc1     $f0, 0x10($sp)
/* A2C9E0 802427A0 C6200000 */  lwc1      $f0, ($s1)
/* A2C9E4 802427A4 46800020 */  cvt.s.w   $f0, $f0
/* A2C9E8 802427A8 24040003 */  addiu     $a0, $zero, 3
/* A2C9EC 802427AC 3C054248 */  lui       $a1, 0x4248
/* A2C9F0 802427B0 3C06420C */  lui       $a2, 0x420c
/* A2C9F4 802427B4 44070000 */  mfc1      $a3, $f0
/* A2C9F8 802427B8 3C0141F0 */  lui       $at, 0x41f0
/* A2C9FC 802427BC 4481A000 */  mtc1      $at, $f20
/* A2CA00 802427C0 3C158025 */  lui       $s5, 0x8025
/* A2CA04 802427C4 26B59A94 */  addiu     $s5, $s5, -0x656c
/* A2CA08 802427C8 AFB50014 */  sw        $s5, 0x14($sp)
/* A2CA0C 802427CC 0C090439 */  jal       func_802410E4_A2B324
/* A2CA10 802427D0 E7B40010 */   swc1     $f20, 0x10($sp)
/* A2CA14 802427D4 C6200000 */  lwc1      $f0, ($s1)
/* A2CA18 802427D8 46800020 */  cvt.s.w   $f0, $f0
/* A2CA1C 802427DC 24040003 */  addiu     $a0, $zero, 3
/* A2CA20 802427E0 3C054376 */  lui       $a1, 0x4376
/* A2CA24 802427E4 34A5199A */  ori       $a1, $a1, 0x199a
/* A2CA28 802427E8 3C064334 */  lui       $a2, 0x4334
/* A2CA2C 802427EC 44070000 */  mfc1      $a3, $f0
/* A2CA30 802427F0 3C148025 */  lui       $s4, 0x8025
/* A2CA34 802427F4 26949A98 */  addiu     $s4, $s4, -0x6568
/* A2CA38 802427F8 E7B40010 */  swc1      $f20, 0x10($sp)
/* A2CA3C 802427FC 0C090439 */  jal       func_802410E4_A2B324
/* A2CA40 80242800 AFB40014 */   sw       $s4, 0x14($sp)
/* A2CA44 80242804 C6200000 */  lwc1      $f0, ($s1)
/* A2CA48 80242808 46800020 */  cvt.s.w   $f0, $f0
/* A2CA4C 8024280C 24040003 */  addiu     $a0, $zero, 3
/* A2CA50 80242810 4405B000 */  mfc1      $a1, $f22
/* A2CA54 80242814 3C06435C */  lui       $a2, 0x435c
/* A2CA58 80242818 44070000 */  mfc1      $a3, $f0
/* A2CA5C 8024281C 3C128025 */  lui       $s2, 0x8025
/* A2CA60 80242820 26529A9C */  addiu     $s2, $s2, -0x6564
/* A2CA64 80242824 E7B40010 */  swc1      $f20, 0x10($sp)
/* A2CA68 80242828 0C090439 */  jal       func_802410E4_A2B324
/* A2CA6C 8024282C AFB20014 */   sw       $s2, 0x14($sp)
/* A2CA70 80242830 C66C0000 */  lwc1      $f12, ($s3)
/* A2CA74 80242834 3C0143FA */  lui       $at, 0x43fa
/* A2CA78 80242838 4481A000 */  mtc1      $at, $f20
/* A2CA7C 8024283C 0C00A8BB */  jal       sin_deg
/* A2CA80 80242840 00000000 */   nop      
/* A2CA84 80242844 46140002 */  mul.s     $f0, $f0, $f20
/* A2CA88 80242848 00000000 */  nop       
/* A2CA8C 8024284C C66C0000 */  lwc1      $f12, ($s3)
/* A2CA90 80242850 0C00A8D4 */  jal       cos_deg
/* A2CA94 80242854 E60004F0 */   swc1     $f0, 0x4f0($s0)
/* A2CA98 80242858 46140002 */  mul.s     $f0, $f0, $f20
/* A2CA9C 8024285C 00000000 */  nop       
/* A2CAA0 80242860 8EA50000 */  lw        $a1, ($s5)
/* A2CAA4 80242864 0000202D */  daddu     $a0, $zero, $zero
/* A2CAA8 80242868 0C090355 */  jal       func_80240D54_A2AF94
/* A2CAAC 8024286C E60004F8 */   swc1     $f0, 0x4f8($s0)
/* A2CAB0 80242870 C6800000 */  lwc1      $f0, ($s4)
/* A2CAB4 80242874 C6420000 */  lwc1      $f2, ($s2)
/* A2CAB8 80242878 8E220000 */  lw        $v0, ($s1)
/* A2CABC 8024287C 24030001 */  addiu     $v1, $zero, 1
/* A2CAC0 80242880 A6030506 */  sh        $v1, 0x506($s0)
/* A2CAC4 80242884 24420001 */  addiu     $v0, $v0, 1
/* A2CAC8 80242888 E60004DC */  swc1      $f0, 0x4dc($s0)
/* A2CACC 8024288C E60204B4 */  swc1      $f2, 0x4b4($s0)
/* A2CAD0 80242890 AE220000 */  sw        $v0, ($s1)
/* A2CAD4 80242894 28420079 */  slti      $v0, $v0, 0x79
/* A2CAD8 80242898 8FBF0030 */  lw        $ra, 0x30($sp)
/* A2CADC 8024289C 8FB5002C */  lw        $s5, 0x2c($sp)
/* A2CAE0 802428A0 8FB40028 */  lw        $s4, 0x28($sp)
/* A2CAE4 802428A4 8FB30024 */  lw        $s3, 0x24($sp)
/* A2CAE8 802428A8 8FB20020 */  lw        $s2, 0x20($sp)
/* A2CAEC 802428AC 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2CAF0 802428B0 8FB00018 */  lw        $s0, 0x18($sp)
/* A2CAF4 802428B4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* A2CAF8 802428B8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* A2CAFC 802428BC 38420001 */  xori      $v0, $v0, 1
/* A2CB00 802428C0 03E00008 */  jr        $ra
/* A2CB04 802428C4 27BD0048 */   addiu    $sp, $sp, 0x48
