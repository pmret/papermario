.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008A728
/* 38CD18 E008A728 27BDFF70 */  addiu     $sp, $sp, -0x90
/* 38CD1C E008A72C AFB1006C */  sw        $s1, 0x6c($sp)
/* 38CD20 E008A730 0080882D */  daddu     $s1, $a0, $zero
/* 38CD24 E008A734 AFBF008C */  sw        $ra, 0x8c($sp)
/* 38CD28 E008A738 AFBE0088 */  sw        $fp, 0x88($sp)
/* 38CD2C E008A73C AFB70084 */  sw        $s7, 0x84($sp)
/* 38CD30 E008A740 AFB60080 */  sw        $s6, 0x80($sp)
/* 38CD34 E008A744 AFB5007C */  sw        $s5, 0x7c($sp)
/* 38CD38 E008A748 AFB40078 */  sw        $s4, 0x78($sp)
/* 38CD3C E008A74C AFB30074 */  sw        $s3, 0x74($sp)
/* 38CD40 E008A750 AFB20070 */  sw        $s2, 0x70($sp)
/* 38CD44 E008A754 AFB00068 */  sw        $s0, 0x68($sp)
/* 38CD48 E008A758 8E33000C */  lw        $s3, 0xc($s1)
/* 38CD4C E008A75C 8E620000 */  lw        $v0, ($s3)
/* 38CD50 E008A760 104000AF */  beqz      $v0, .LE008AA20
/* 38CD54 E008A764 240200FF */   addiu    $v0, $zero, 0xff
/* 38CD58 E008A768 8E690028 */  lw        $t1, 0x28($s3)
/* 38CD5C E008A76C 8E630004 */  lw        $v1, 4($s3)
/* 38CD60 E008A770 A3A20059 */  sb        $v0, 0x59($sp)
/* 38CD64 E008A774 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 38CD68 E008A778 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 38CD6C E008A77C 8E7E002C */  lw        $fp, 0x2c($s3)
/* 38CD70 E008A780 00031880 */  sll       $v1, $v1, 2
/* 38CD74 E008A784 90420000 */  lbu       $v0, ($v0)
/* 38CD78 E008A788 3C01E009 */  lui       $at, %hi(D_E008AA50)
/* 38CD7C E008A78C 00230821 */  addu      $at, $at, $v1
/* 38CD80 E008A790 8C23AA50 */  lw        $v1, %lo(D_E008AA50)($at)
/* 38CD84 E008A794 24040001 */  addiu     $a0, $zero, 1
/* 38CD88 E008A798 14440009 */  bne       $v0, $a0, .LE008A7C0
/* 38CD8C E008A79C AFA3005C */   sw       $v1, 0x5c($sp)
/* 38CD90 E008A7A0 27A40058 */  addiu     $a0, $sp, 0x58
/* 38CD94 E008A7A4 0080282D */  daddu     $a1, $a0, $zero
/* 38CD98 E008A7A8 0080302D */  daddu     $a2, $a0, $zero
/* 38CD9C E008A7AC 0C08019C */  jal       shim_get_background_color_blend
/* 38CDA0 E008A7B0 27A70059 */   addiu    $a3, $sp, 0x59
/* 38CDA4 E008A7B4 93A30059 */  lbu       $v1, 0x59($sp)
/* 38CDA8 E008A7B8 240200FF */  addiu     $v0, $zero, 0xff
/* 38CDAC E008A7BC 00434823 */  subu      $t1, $v0, $v1
.LE008A7C0:
/* 38CDB0 E008A7C0 11200097 */  beqz      $t1, .LE008AA20
/* 38CDB4 E008A7C4 3C08DB06 */   lui      $t0, 0xdb06
/* 38CDB8 E008A7C8 35080024 */  ori       $t0, $t0, 0x24
/* 38CDBC E008A7CC 27A40018 */  addiu     $a0, $sp, 0x18
/* 38CDC0 E008A7D0 3C100001 */  lui       $s0, 1
/* 38CDC4 E008A7D4 36101630 */  ori       $s0, $s0, 0x1630
/* 38CDC8 E008A7D8 3C16800A */  lui       $s6, %hi(gMasterGfxPos)
/* 38CDCC E008A7DC 26D6A66C */  addiu     $s6, $s6, %lo(gMasterGfxPos)
/* 38CDD0 E008A7E0 3C02E700 */  lui       $v0, 0xe700
/* 38CDD4 E008A7E4 8EC50000 */  lw        $a1, ($s6)
/* 38CDD8 E008A7E8 44800000 */  mtc1      $zero, $f0
/* 38CDDC E008A7EC 3C073F80 */  lui       $a3, 0x3f80
/* 38CDE0 E008A7F0 00A0182D */  daddu     $v1, $a1, $zero
/* 38CDE4 E008A7F4 44060000 */  mfc1      $a2, $f0
/* 38CDE8 E008A7F8 24A50008 */  addiu     $a1, $a1, 8
/* 38CDEC E008A7FC AEC50000 */  sw        $a1, ($s6)
/* 38CDF0 E008A800 AC620000 */  sw        $v0, ($v1)
/* 38CDF4 E008A804 24A20008 */  addiu     $v0, $a1, 8
/* 38CDF8 E008A808 AC600004 */  sw        $zero, 4($v1)
/* 38CDFC E008A80C AEC20000 */  sw        $v0, ($s6)
/* 38CE00 E008A810 ACA80000 */  sw        $t0, ($a1)
/* 38CE04 E008A814 8E230010 */  lw        $v1, 0x10($s1)
/* 38CE08 E008A818 24A20010 */  addiu     $v0, $a1, 0x10
/* 38CE0C E008A81C AEC20000 */  sw        $v0, ($s6)
/* 38CE10 E008A820 8C68001C */  lw        $t0, 0x1c($v1)
/* 38CE14 E008A824 3C02DE00 */  lui       $v0, 0xde00
/* 38CE18 E008A828 ACA20008 */  sw        $v0, 8($a1)
/* 38CE1C E008A82C 3C020900 */  lui       $v0, 0x900
/* 38CE20 E008A830 24420C00 */  addiu     $v0, $v0, 0xc00
/* 38CE24 E008A834 ACA2000C */  sw        $v0, 0xc($a1)
/* 38CE28 E008A838 3C02FA00 */  lui       $v0, 0xfa00
/* 38CE2C E008A83C ACA20010 */  sw        $v0, 0x10($a1)
/* 38CE30 E008A840 2402FF00 */  addiu     $v0, $zero, -0x100
/* 38CE34 E008A844 01221025 */  or        $v0, $t1, $v0
/* 38CE38 E008A848 ACA20014 */  sw        $v0, 0x14($a1)
/* 38CE3C E008A84C 3C028000 */  lui       $v0, 0x8000
/* 38CE40 E008A850 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 38CE44 E008A854 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 38CE48 E008A858 01024021 */  addu      $t0, $t0, $v0
/* 38CE4C E008A85C 00031080 */  sll       $v0, $v1, 2
/* 38CE50 E008A860 00431021 */  addu      $v0, $v0, $v1
/* 38CE54 E008A864 00021080 */  sll       $v0, $v0, 2
/* 38CE58 E008A868 00431023 */  subu      $v0, $v0, $v1
/* 38CE5C E008A86C 000218C0 */  sll       $v1, $v0, 3
/* 38CE60 E008A870 00431021 */  addu      $v0, $v0, $v1
/* 38CE64 E008A874 000210C0 */  sll       $v0, $v0, 3
/* 38CE68 E008A878 ACA80004 */  sw        $t0, 4($a1)
/* 38CE6C E008A87C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 38CE70 E008A880 00220821 */  addu      $at, $at, $v0
/* 38CE74 E008A884 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 38CE78 E008A888 24A50018 */  addiu     $a1, $a1, 0x18
/* 38CE7C E008A88C AEC50000 */  sw        $a1, ($s6)
/* 38CE80 E008A890 46000007 */  neg.s     $f0, $f0
/* 38CE84 E008A894 44050000 */  mfc1      $a1, $f0
/* 38CE88 E008A898 26730034 */  addiu     $s3, $s3, 0x34
/* 38CE8C E008A89C 0C080104 */  jal       shim_guRotateF
/* 38CE90 E008A8A0 AFA60010 */   sw       $a2, 0x10($sp)
/* 38CE94 E008A8A4 27A40018 */  addiu     $a0, $sp, 0x18
/* 38CE98 E008A8A8 3C128007 */  lui       $s2, %hi(gMatrixListPos)
/* 38CE9C E008A8AC 265241F0 */  addiu     $s2, $s2, %lo(gMatrixListPos)
/* 38CEA0 E008A8B0 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 38CEA4 E008A8B4 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 38CEA8 E008A8B8 96450000 */  lhu       $a1, ($s2)
/* 38CEAC E008A8BC 8E820000 */  lw        $v0, ($s4)
/* 38CEB0 E008A8C0 00052980 */  sll       $a1, $a1, 6
/* 38CEB4 E008A8C4 00B02821 */  addu      $a1, $a1, $s0
/* 38CEB8 E008A8C8 0C080118 */  jal       shim_guMtxF2L
/* 38CEBC E008A8CC 00452821 */   addu     $a1, $v0, $a1
/* 38CEC0 E008A8D0 96420000 */  lhu       $v0, ($s2)
/* 38CEC4 E008A8D4 0000882D */  daddu     $s1, $zero, $zero
/* 38CEC8 E008A8D8 24430001 */  addiu     $v1, $v0, 1
/* 38CECC E008A8DC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 38CED0 E008A8E0 00021180 */  sll       $v0, $v0, 6
/* 38CED4 E008A8E4 A6430000 */  sh        $v1, ($s2)
/* 38CED8 E008A8E8 8E830000 */  lw        $v1, ($s4)
/* 38CEDC E008A8EC 00501021 */  addu      $v0, $v0, $s0
/* 38CEE0 E008A8F0 00621821 */  addu      $v1, $v1, $v0
/* 38CEE4 E008A8F4 1BC00041 */  blez      $fp, .LE008A9FC
/* 38CEE8 E008A8F8 AFA30060 */   sw       $v1, 0x60($sp)
/* 38CEEC E008A8FC 0280B82D */  daddu     $s7, $s4, $zero
/* 38CEF0 E008A900 0240A82D */  daddu     $s5, $s2, $zero
/* 38CEF4 E008A904 3C140001 */  lui       $s4, 1
/* 38CEF8 E008A908 36941630 */  ori       $s4, $s4, 0x1630
/* 38CEFC E008A90C 02C0902D */  daddu     $s2, $s6, $zero
/* 38CF00 E008A910 26700010 */  addiu     $s0, $s3, 0x10
.LE008A914:
/* 38CF04 E008A914 8E020020 */  lw        $v0, 0x20($s0)
/* 38CF08 E008A918 5C400035 */  bgtzl     $v0, .LE008A9F0
/* 38CF0C E008A91C 26310001 */   addiu    $s1, $s1, 1
/* 38CF10 E008A920 8E020018 */  lw        $v0, 0x18($s0)
/* 38CF14 E008A924 50400032 */  beql      $v0, $zero, .LE008A9F0
/* 38CF18 E008A928 26310001 */   addiu    $s1, $s1, 1
/* 38CF1C E008A92C 8E05FFF8 */  lw        $a1, -8($s0)
/* 38CF20 E008A930 8E06FFFC */  lw        $a2, -4($s0)
/* 38CF24 E008A934 8E070000 */  lw        $a3, ($s0)
/* 38CF28 E008A938 0C080108 */  jal       shim_guTranslateF
/* 38CF2C E008A93C 27A40018 */   addiu    $a0, $sp, 0x18
/* 38CF30 E008A940 27A40018 */  addiu     $a0, $sp, 0x18
/* 38CF34 E008A944 96A50000 */  lhu       $a1, ($s5)
/* 38CF38 E008A948 8EE20000 */  lw        $v0, ($s7)
/* 38CF3C E008A94C 00052980 */  sll       $a1, $a1, 6
/* 38CF40 E008A950 00B42821 */  addu      $a1, $a1, $s4
/* 38CF44 E008A954 0C080118 */  jal       shim_guMtxF2L
/* 38CF48 E008A958 00452821 */   addu     $a1, $v0, $a1
/* 38CF4C E008A95C 3C02DA38 */  lui       $v0, 0xda38
/* 38CF50 E008A960 34420002 */  ori       $v0, $v0, 2
/* 38CF54 E008A964 3C06DA38 */  lui       $a2, 0xda38
/* 38CF58 E008A968 34C60001 */  ori       $a2, $a2, 1
/* 38CF5C E008A96C 3C07D838 */  lui       $a3, 0xd838
/* 38CF60 E008A970 34E70002 */  ori       $a3, $a3, 2
/* 38CF64 E008A974 8E440000 */  lw        $a0, ($s2)
/* 38CF68 E008A978 96A30000 */  lhu       $v1, ($s5)
/* 38CF6C E008A97C 0080282D */  daddu     $a1, $a0, $zero
/* 38CF70 E008A980 24840008 */  addiu     $a0, $a0, 8
/* 38CF74 E008A984 AE440000 */  sw        $a0, ($s2)
/* 38CF78 E008A988 ACA20000 */  sw        $v0, ($a1)
/* 38CF7C E008A98C 24620001 */  addiu     $v0, $v1, 1
/* 38CF80 E008A990 3063FFFF */  andi      $v1, $v1, 0xffff
/* 38CF84 E008A994 00031980 */  sll       $v1, $v1, 6
/* 38CF88 E008A998 A6A20000 */  sh        $v0, ($s5)
/* 38CF8C E008A99C 8EE20000 */  lw        $v0, ($s7)
/* 38CF90 E008A9A0 00741821 */  addu      $v1, $v1, $s4
/* 38CF94 E008A9A4 00431021 */  addu      $v0, $v0, $v1
/* 38CF98 E008A9A8 ACA20004 */  sw        $v0, 4($a1)
/* 38CF9C E008A9AC 24820008 */  addiu     $v0, $a0, 8
/* 38CFA0 E008A9B0 AE420000 */  sw        $v0, ($s2)
/* 38CFA4 E008A9B4 AC860000 */  sw        $a2, ($a0)
/* 38CFA8 E008A9B8 8FAA0060 */  lw        $t2, 0x60($sp)
/* 38CFAC E008A9BC 24820010 */  addiu     $v0, $a0, 0x10
/* 38CFB0 E008A9C0 AC8A0004 */  sw        $t2, 4($a0)
/* 38CFB4 E008A9C4 AE420000 */  sw        $v0, ($s2)
/* 38CFB8 E008A9C8 3C02DE00 */  lui       $v0, 0xde00
/* 38CFBC E008A9CC AC820008 */  sw        $v0, 8($a0)
/* 38CFC0 E008A9D0 8FAA005C */  lw        $t2, 0x5c($sp)
/* 38CFC4 E008A9D4 24820018 */  addiu     $v0, $a0, 0x18
/* 38CFC8 E008A9D8 AC8A000C */  sw        $t2, 0xc($a0)
/* 38CFCC E008A9DC AE420000 */  sw        $v0, ($s2)
/* 38CFD0 E008A9E0 24020040 */  addiu     $v0, $zero, 0x40
/* 38CFD4 E008A9E4 AC870010 */  sw        $a3, 0x10($a0)
/* 38CFD8 E008A9E8 AC820014 */  sw        $v0, 0x14($a0)
/* 38CFDC E008A9EC 26310001 */  addiu     $s1, $s1, 1
.LE008A9F0:
/* 38CFE0 E008A9F0 023E102A */  slt       $v0, $s1, $fp
/* 38CFE4 E008A9F4 1440FFC7 */  bnez      $v0, .LE008A914
/* 38CFE8 E008A9F8 26100034 */   addiu    $s0, $s0, 0x34
.LE008A9FC:
/* 38CFEC E008A9FC 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 38CFF0 E008AA00 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 38CFF4 E008AA04 8C620000 */  lw        $v0, ($v1)
/* 38CFF8 E008AA08 0040202D */  daddu     $a0, $v0, $zero
/* 38CFFC E008AA0C 24420008 */  addiu     $v0, $v0, 8
/* 38D000 E008AA10 AC620000 */  sw        $v0, ($v1)
/* 38D004 E008AA14 3C02E700 */  lui       $v0, 0xe700
/* 38D008 E008AA18 AC820000 */  sw        $v0, ($a0)
/* 38D00C E008AA1C AC800004 */  sw        $zero, 4($a0)
.LE008AA20:
/* 38D010 E008AA20 8FBF008C */  lw        $ra, 0x8c($sp)
/* 38D014 E008AA24 8FBE0088 */  lw        $fp, 0x88($sp)
/* 38D018 E008AA28 8FB70084 */  lw        $s7, 0x84($sp)
/* 38D01C E008AA2C 8FB60080 */  lw        $s6, 0x80($sp)
/* 38D020 E008AA30 8FB5007C */  lw        $s5, 0x7c($sp)
/* 38D024 E008AA34 8FB40078 */  lw        $s4, 0x78($sp)
/* 38D028 E008AA38 8FB30074 */  lw        $s3, 0x74($sp)
/* 38D02C E008AA3C 8FB20070 */  lw        $s2, 0x70($sp)
/* 38D030 E008AA40 8FB1006C */  lw        $s1, 0x6c($sp)
/* 38D034 E008AA44 8FB00068 */  lw        $s0, 0x68($sp)
/* 38D038 E008AA48 03E00008 */  jr        $ra
/* 38D03C E008AA4C 27BD0090 */   addiu    $sp, $sp, 0x90
