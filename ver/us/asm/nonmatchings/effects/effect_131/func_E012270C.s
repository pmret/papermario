.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E012270C
/* 40CCAC E012270C 27BDFF70 */  addiu     $sp, $sp, -0x90
/* 40CCB0 E0122710 0080402D */  daddu     $t0, $a0, $zero
/* 40CCB4 E0122714 3C09DB06 */  lui       $t1, 0xdb06
/* 40CCB8 E0122718 35290024 */  ori       $t1, $t1, 0x24
/* 40CCBC E012271C 27A40020 */  addiu     $a0, $sp, 0x20
/* 40CCC0 E0122720 AFB00060 */  sw        $s0, 0x60($sp)
/* 40CCC4 E0122724 3C100001 */  lui       $s0, 1
/* 40CCC8 E0122728 36101630 */  ori       $s0, $s0, 0x1630
/* 40CCCC E012272C AFB40070 */  sw        $s4, 0x70($sp)
/* 40CCD0 E0122730 0000A02D */  daddu     $s4, $zero, $zero
/* 40CCD4 E0122734 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 40CCD8 E0122738 2442A674 */  addiu     $v0, $v0, %lo(gDisplayContext)
/* 40CCDC E012273C AFBE0080 */  sw        $fp, 0x80($sp)
/* 40CCE0 E0122740 0040F02D */  daddu     $fp, $v0, $zero
/* 40CCE4 E0122744 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 40CCE8 E0122748 244241F0 */  addiu     $v0, $v0, %lo(gMatrixListPos)
/* 40CCEC E012274C AFB50074 */  sw        $s5, 0x74($sp)
/* 40CCF0 E0122750 0040A82D */  daddu     $s5, $v0, $zero
/* 40CCF4 E0122754 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 40CCF8 E0122758 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 40CCFC E012275C AFB3006C */  sw        $s3, 0x6c($sp)
/* 40CD00 E0122760 0040982D */  daddu     $s3, $v0, $zero
/* 40CD04 E0122764 AFBF0084 */  sw        $ra, 0x84($sp)
/* 40CD08 E0122768 AFB7007C */  sw        $s7, 0x7c($sp)
/* 40CD0C E012276C AFB60078 */  sw        $s6, 0x78($sp)
/* 40CD10 E0122770 AFB20068 */  sw        $s2, 0x68($sp)
/* 40CD14 E0122774 AFB10064 */  sw        $s1, 0x64($sp)
/* 40CD18 E0122778 F7B40088 */  sdc1      $f20, 0x88($sp)
/* 40CD1C E012277C 8C460000 */  lw        $a2, ($v0)
/* 40CD20 E0122780 3C02E700 */  lui       $v0, 0xe700
/* 40CD24 E0122784 44800000 */  mtc1      $zero, $f0
/* 40CD28 E0122788 8D11000C */  lw        $s1, 0xc($t0)
/* 40CD2C E012278C 00C0182D */  daddu     $v1, $a2, $zero
/* 40CD30 E0122790 8E370004 */  lw        $s7, 4($s1)
/* 40CD34 E0122794 24C60008 */  addiu     $a2, $a2, 8
/* 40CD38 E0122798 AC620000 */  sw        $v0, ($v1)
/* 40CD3C E012279C AC600004 */  sw        $zero, 4($v1)
/* 40CD40 E01227A0 ACC90000 */  sw        $t1, ($a2)
/* 40CD44 E01227A4 8D020010 */  lw        $v0, 0x10($t0)
/* 40CD48 E01227A8 3C088000 */  lui       $t0, 0x8000
/* 40CD4C E01227AC 44050000 */  mfc1      $a1, $f0
/* 40CD50 E01227B0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 40CD54 E01227B4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 40CD58 E01227B8 8C42001C */  lw        $v0, 0x1c($v0)
/* 40CD5C E01227BC 4485A000 */  mtc1      $a1, $f20
/* 40CD60 E01227C0 00481021 */  addu      $v0, $v0, $t0
/* 40CD64 E01227C4 ACC20004 */  sw        $v0, 4($a2)
/* 40CD68 E01227C8 00031080 */  sll       $v0, $v1, 2
/* 40CD6C E01227CC 00431021 */  addu      $v0, $v0, $v1
/* 40CD70 E01227D0 00021080 */  sll       $v0, $v0, 2
/* 40CD74 E01227D4 00431023 */  subu      $v0, $v0, $v1
/* 40CD78 E01227D8 000218C0 */  sll       $v1, $v0, 3
/* 40CD7C E01227DC 00431021 */  addu      $v0, $v0, $v1
/* 40CD80 E01227E0 000210C0 */  sll       $v0, $v0, 3
/* 40CD84 E01227E4 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 40CD88 E01227E8 00220821 */  addu      $at, $at, $v0
/* 40CD8C E01227EC C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* 40CD90 E01227F0 C620003C */  lwc1      $f0, 0x3c($s1)
/* 40CD94 E01227F4 3C160001 */  lui       $s6, 1
/* 40CD98 E01227F8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 40CD9C E01227FC C6200008 */  lwc1      $f0, 8($s1)
/* 40CDA0 E0122800 36D61630 */  ori       $s6, $s6, 0x1630
/* 40CDA4 E0122804 AE660000 */  sw        $a2, ($s3)
/* 40CDA8 E0122808 24C60008 */  addiu     $a2, $a2, 8
/* 40CDAC E012280C E7A00014 */  swc1      $f0, 0x14($sp)
/* 40CDB0 E0122810 C620000C */  lwc1      $f0, 0xc($s1)
/* 40CDB4 E0122814 46001087 */  neg.s     $f2, $f2
/* 40CDB8 E0122818 AE660000 */  sw        $a2, ($s3)
/* 40CDBC E012281C 44061000 */  mfc1      $a2, $f2
/* 40CDC0 E0122820 0220902D */  daddu     $s2, $s1, $zero
/* 40CDC4 E0122824 E7A00018 */  swc1      $f0, 0x18($sp)
/* 40CDC8 E0122828 C6200010 */  lwc1      $f0, 0x10($s1)
/* 40CDCC E012282C 00A0382D */  daddu     $a3, $a1, $zero
/* 40CDD0 E0122830 0C080180 */  jal       shim_guPositionF
/* 40CDD4 E0122834 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 40CDD8 E0122838 27A40020 */  addiu     $a0, $sp, 0x20
/* 40CDDC E012283C 96A50000 */  lhu       $a1, ($s5)
/* 40CDE0 E0122840 8FC20000 */  lw        $v0, ($fp)
/* 40CDE4 E0122844 00052980 */  sll       $a1, $a1, 6
/* 40CDE8 E0122848 00B02821 */  addu      $a1, $a1, $s0
/* 40CDEC E012284C 0C080118 */  jal       shim_guMtxF2L
/* 40CDF0 E0122850 00452821 */   addu     $a1, $v0, $a1
/* 40CDF4 E0122854 3C03DA38 */  lui       $v1, 0xda38
/* 40CDF8 E0122858 34630002 */  ori       $v1, $v1, 2
/* 40CDFC E012285C 8E650000 */  lw        $a1, ($s3)
/* 40CE00 E0122860 96A20000 */  lhu       $v0, ($s5)
/* 40CE04 E0122864 00A0202D */  daddu     $a0, $a1, $zero
/* 40CE08 E0122868 24A50008 */  addiu     $a1, $a1, 8
/* 40CE0C E012286C AE650000 */  sw        $a1, ($s3)
/* 40CE10 E0122870 AC830000 */  sw        $v1, ($a0)
/* 40CE14 E0122874 24430001 */  addiu     $v1, $v0, 1
/* 40CE18 E0122878 3042FFFF */  andi      $v0, $v0, 0xffff
/* 40CE1C E012287C 00021180 */  sll       $v0, $v0, 6
/* 40CE20 E0122880 A6A30000 */  sh        $v1, ($s5)
/* 40CE24 E0122884 8FC30000 */  lw        $v1, ($fp)
/* 40CE28 E0122888 00501021 */  addu      $v0, $v0, $s0
/* 40CE2C E012288C 00621821 */  addu      $v1, $v1, $v0
/* 40CE30 E0122890 24A20008 */  addiu     $v0, $a1, 8
/* 40CE34 E0122894 AC830004 */  sw        $v1, 4($a0)
/* 40CE38 E0122898 AE620000 */  sw        $v0, ($s3)
/* 40CE3C E012289C 3C02DE00 */  lui       $v0, 0xde00
/* 40CE40 E01228A0 ACA20000 */  sw        $v0, ($a1)
/* 40CE44 E01228A4 24A20010 */  addiu     $v0, $a1, 0x10
/* 40CE48 E01228A8 AE620000 */  sw        $v0, ($s3)
/* 40CE4C E01228AC 3C03E012 */  lui       $v1, %hi(D_E0122BA4)
/* 40CE50 E01228B0 8C632BA4 */  lw        $v1, %lo(D_E0122BA4)($v1)
/* 40CE54 E01228B4 3C02FB00 */  lui       $v0, 0xfb00
/* 40CE58 E01228B8 ACA20008 */  sw        $v0, 8($a1)
/* 40CE5C E01228BC ACA30004 */  sw        $v1, 4($a1)
/* 40CE60 E01228C0 9222002F */  lbu       $v0, 0x2f($s1)
/* 40CE64 E01228C4 92230033 */  lbu       $v1, 0x33($s1)
/* 40CE68 E01228C8 92240037 */  lbu       $a0, 0x37($s1)
/* 40CE6C E01228CC 00021600 */  sll       $v0, $v0, 0x18
/* 40CE70 E01228D0 00031C00 */  sll       $v1, $v1, 0x10
/* 40CE74 E01228D4 00431025 */  or        $v0, $v0, $v1
/* 40CE78 E01228D8 00042200 */  sll       $a0, $a0, 8
/* 40CE7C E01228DC 9223003B */  lbu       $v1, 0x3b($s1)
/* 40CE80 E01228E0 00441025 */  or        $v0, $v0, $a0
/* 40CE84 E01228E4 00431025 */  or        $v0, $v0, $v1
/* 40CE88 E01228E8 ACA2000C */  sw        $v0, 0xc($a1)
.LE01228EC:
/* 40CE8C E01228EC 24020001 */  addiu     $v0, $zero, 1
/* 40CE90 E01228F0 16E20003 */  bne       $s7, $v0, .LE0122900
/* 40CE94 E01228F4 24020002 */   addiu    $v0, $zero, 2
/* 40CE98 E01228F8 52820047 */  beql      $s4, $v0, .LE0122A18
/* 40CE9C E01228FC 26940001 */   addiu    $s4, $s4, 1
.LE0122900:
/* 40CEA0 E0122900 C6400040 */  lwc1      $f0, 0x40($s2)
/* 40CEA4 E0122904 46140032 */  c.eq.s    $f0, $f20
/* 40CEA8 E0122908 00000000 */  nop
/* 40CEAC E012290C 45010041 */  bc1t      .LE0122A14
/* 40CEB0 E0122910 00148080 */   sll      $s0, $s4, 2
/* 40CEB4 E0122914 8E420050 */  lw        $v0, 0x50($s2)
/* 40CEB8 E0122918 5040003F */  beql      $v0, $zero, .LE0122A18
/* 40CEBC E012291C 26940001 */   addiu    $s4, $s4, 1
/* 40CEC0 E0122920 4405A000 */  mfc1      $a1, $f20
/* 40CEC4 E0122924 4406A000 */  mfc1      $a2, $f20
/* 40CEC8 E0122928 4407A000 */  mfc1      $a3, $f20
/* 40CECC E012292C 27A40020 */  addiu     $a0, $sp, 0x20
/* 40CED0 E0122930 E7A00010 */  swc1      $f0, 0x10($sp)
/* 40CED4 E0122934 E7B40014 */  swc1      $f20, 0x14($sp)
/* 40CED8 E0122938 E7B40018 */  swc1      $f20, 0x18($sp)
/* 40CEDC E012293C 0C080180 */  jal       shim_guPositionF
/* 40CEE0 E0122940 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 40CEE4 E0122944 27A40020 */  addiu     $a0, $sp, 0x20
/* 40CEE8 E0122948 96A50000 */  lhu       $a1, ($s5)
/* 40CEEC E012294C 8FC20000 */  lw        $v0, ($fp)
/* 40CEF0 E0122950 00052980 */  sll       $a1, $a1, 6
/* 40CEF4 E0122954 00B62821 */  addu      $a1, $a1, $s6
/* 40CEF8 E0122958 0C080118 */  jal       shim_guMtxF2L
/* 40CEFC E012295C 00452821 */   addu     $a1, $v0, $a1
/* 40CF00 E0122960 3C08D838 */  lui       $t0, 0xd838
/* 40CF04 E0122964 8E640000 */  lw        $a0, ($s3)
/* 40CF08 E0122968 35080002 */  ori       $t0, $t0, 2
/* 40CF0C E012296C 0080282D */  daddu     $a1, $a0, $zero
/* 40CF10 E0122970 24840008 */  addiu     $a0, $a0, 8
/* 40CF14 E0122974 AE640000 */  sw        $a0, ($s3)
/* 40CF18 E0122978 96A20000 */  lhu       $v0, ($s5)
/* 40CF1C E012297C 3C03DA38 */  lui       $v1, 0xda38
/* 40CF20 E0122980 ACA30000 */  sw        $v1, ($a1)
/* 40CF24 E0122984 24430001 */  addiu     $v1, $v0, 1
/* 40CF28 E0122988 3042FFFF */  andi      $v0, $v0, 0xffff
/* 40CF2C E012298C 00021180 */  sll       $v0, $v0, 6
/* 40CF30 E0122990 A6A30000 */  sh        $v1, ($s5)
/* 40CF34 E0122994 8FC30000 */  lw        $v1, ($fp)
/* 40CF38 E0122998 00561021 */  addu      $v0, $v0, $s6
/* 40CF3C E012299C 00621821 */  addu      $v1, $v1, $v0
/* 40CF40 E01229A0 24820008 */  addiu     $v0, $a0, 8
/* 40CF44 E01229A4 ACA30004 */  sw        $v1, 4($a1)
/* 40CF48 E01229A8 AE620000 */  sw        $v0, ($s3)
/* 40CF4C E01229AC 3C02FA00 */  lui       $v0, 0xfa00
/* 40CF50 E01229B0 AC820000 */  sw        $v0, ($a0)
/* 40CF54 E01229B4 9223001F */  lbu       $v1, 0x1f($s1)
/* 40CF58 E01229B8 92250023 */  lbu       $a1, 0x23($s1)
/* 40CF5C E01229BC 92260027 */  lbu       $a2, 0x27($s1)
/* 40CF60 E01229C0 92470053 */  lbu       $a3, 0x53($s2)
/* 40CF64 E01229C4 24820010 */  addiu     $v0, $a0, 0x10
/* 40CF68 E01229C8 AE620000 */  sw        $v0, ($s3)
/* 40CF6C E01229CC 3C02DE00 */  lui       $v0, 0xde00
/* 40CF70 E01229D0 AC820008 */  sw        $v0, 8($a0)
/* 40CF74 E01229D4 00031E00 */  sll       $v1, $v1, 0x18
/* 40CF78 E01229D8 00052C00 */  sll       $a1, $a1, 0x10
/* 40CF7C E01229DC 00651825 */  or        $v1, $v1, $a1
/* 40CF80 E01229E0 00063200 */  sll       $a2, $a2, 8
/* 40CF84 E01229E4 00661825 */  or        $v1, $v1, $a2
/* 40CF88 E01229E8 00671825 */  or        $v1, $v1, $a3
/* 40CF8C E01229EC AC830004 */  sw        $v1, 4($a0)
/* 40CF90 E01229F0 3C03E012 */  lui       $v1, %hi(D_E0122B90)
/* 40CF94 E01229F4 00701821 */  addu      $v1, $v1, $s0
/* 40CF98 E01229F8 8C632B90 */  lw        $v1, %lo(D_E0122B90)($v1)
/* 40CF9C E01229FC 24820018 */  addiu     $v0, $a0, 0x18
/* 40CFA0 E0122A00 AE620000 */  sw        $v0, ($s3)
/* 40CFA4 E0122A04 24020040 */  addiu     $v0, $zero, 0x40
/* 40CFA8 E0122A08 AC880010 */  sw        $t0, 0x10($a0)
/* 40CFAC E0122A0C AC820014 */  sw        $v0, 0x14($a0)
/* 40CFB0 E0122A10 AC83000C */  sw        $v1, 0xc($a0)
.LE0122A14:
/* 40CFB4 E0122A14 26940001 */  addiu     $s4, $s4, 1
.LE0122A18:
/* 40CFB8 E0122A18 2A820004 */  slti      $v0, $s4, 4
/* 40CFBC E0122A1C 1440FFB3 */  bnez      $v0, .LE01228EC
/* 40CFC0 E0122A20 26520004 */   addiu    $s2, $s2, 4
/* 40CFC4 E0122A24 3C05D838 */  lui       $a1, 0xd838
/* 40CFC8 E0122A28 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 40CFCC E0122A2C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 40CFD0 E0122A30 8C620000 */  lw        $v0, ($v1)
/* 40CFD4 E0122A34 34A50002 */  ori       $a1, $a1, 2
/* 40CFD8 E0122A38 0040202D */  daddu     $a0, $v0, $zero
/* 40CFDC E0122A3C 24420008 */  addiu     $v0, $v0, 8
/* 40CFE0 E0122A40 AC620000 */  sw        $v0, ($v1)
/* 40CFE4 E0122A44 24020040 */  addiu     $v0, $zero, 0x40
/* 40CFE8 E0122A48 AC820004 */  sw        $v0, 4($a0)
/* 40CFEC E0122A4C 26E2FFFE */  addiu     $v0, $s7, -2
/* 40CFF0 E0122A50 2C420002 */  sltiu     $v0, $v0, 2
/* 40CFF4 E0122A54 10400037 */  beqz      $v0, .LE0122B34
/* 40CFF8 E0122A58 AC850000 */   sw       $a1, ($a0)
/* 40CFFC E0122A5C 8E230070 */  lw        $v1, 0x70($s1)
/* 40D000 E0122A60 24020001 */  addiu     $v0, $zero, 1
/* 40D004 E0122A64 10620004 */  beq       $v1, $v0, .LE0122A78
/* 40D008 E0122A68 0000382D */   daddu    $a3, $zero, $zero
/* 40D00C E0122A6C 24020064 */  addiu     $v0, $zero, 0x64
/* 40D010 E0122A70 1462000E */  bne       $v1, $v0, .LE0122AAC
/* 40D014 E0122A74 24020005 */   addiu    $v0, $zero, 5
.LE0122A78:
/* 40D018 E0122A78 8E230074 */  lw        $v1, 0x74($s1)
/* 40D01C E0122A7C 28620003 */  slti      $v0, $v1, 3
/* 40D020 E0122A80 14400008 */  bnez      $v0, .LE0122AA4
/* 40D024 E0122A84 2862000B */   slti     $v0, $v1, 0xb
/* 40D028 E0122A88 10400006 */  beqz      $v0, .LE0122AA4
/* 40D02C E0122A8C 2462FFFE */   addiu    $v0, $v1, -2
/* 40D030 E0122A90 00021900 */  sll       $v1, $v0, 4
/* 40D034 E0122A94 00621823 */  subu      $v1, $v1, $v0
/* 40D038 E0122A98 00031840 */  sll       $v1, $v1, 1
/* 40D03C E0122A9C 240200FF */  addiu     $v0, $zero, 0xff
/* 40D040 E0122AA0 00433823 */  subu      $a3, $v0, $v1
.LE0122AA4:
/* 40D044 E0122AA4 8E230070 */  lw        $v1, 0x70($s1)
/* 40D048 E0122AA8 24020005 */  addiu     $v0, $zero, 5
.LE0122AAC:
/* 40D04C E0122AAC 1462000A */  bne       $v1, $v0, .LE0122AD8
/* 40D050 E0122AB0 00000000 */   nop
/* 40D054 E0122AB4 8E230074 */  lw        $v1, 0x74($s1)
/* 40D058 E0122AB8 18600007 */  blez      $v1, .LE0122AD8
/* 40D05C E0122ABC 28620009 */   slti     $v0, $v1, 9
/* 40D060 E0122AC0 10400005 */  beqz      $v0, .LE0122AD8
/* 40D064 E0122AC4 00031100 */   sll      $v0, $v1, 4
/* 40D068 E0122AC8 00431023 */  subu      $v0, $v0, $v1
/* 40D06C E0122ACC 00021040 */  sll       $v0, $v0, 1
/* 40D070 E0122AD0 240300FF */  addiu     $v1, $zero, 0xff
/* 40D074 E0122AD4 00623823 */  subu      $a3, $v1, $v0
.LE0122AD8:
/* 40D078 E0122AD8 18E00014 */  blez      $a3, .LE0122B2C
/* 40D07C E0122ADC 3C06D0D0 */   lui      $a2, 0xd0d0
/* 40D080 E0122AE0 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 40D084 E0122AE4 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 40D088 E0122AE8 34C6D000 */  ori       $a2, $a2, 0xd000
/* 40D08C E0122AEC 8CA30000 */  lw        $v1, ($a1)
/* 40D090 E0122AF0 3C02FA00 */  lui       $v0, 0xfa00
/* 40D094 E0122AF4 0060202D */  daddu     $a0, $v1, $zero
/* 40D098 E0122AF8 24630008 */  addiu     $v1, $v1, 8
/* 40D09C E0122AFC ACA30000 */  sw        $v1, ($a1)
/* 40D0A0 E0122B00 AC820000 */  sw        $v0, ($a0)
/* 40D0A4 E0122B04 30E200FF */  andi      $v0, $a3, 0xff
/* 40D0A8 E0122B08 00461025 */  or        $v0, $v0, $a2
/* 40D0AC E0122B0C AC820004 */  sw        $v0, 4($a0)
/* 40D0B0 E0122B10 3C02DE00 */  lui       $v0, 0xde00
/* 40D0B4 E0122B14 AC620000 */  sw        $v0, ($v1)
/* 40D0B8 E0122B18 3C04E012 */  lui       $a0, %hi(D_E0122BA0)
/* 40D0BC E0122B1C 8C842BA0 */  lw        $a0, %lo(D_E0122BA0)($a0)
/* 40D0C0 E0122B20 24620008 */  addiu     $v0, $v1, 8
/* 40D0C4 E0122B24 ACA20000 */  sw        $v0, ($a1)
/* 40D0C8 E0122B28 AC640004 */  sw        $a0, 4($v1)
.LE0122B2C:
/* 40D0CC E0122B2C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 40D0D0 E0122B30 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
.LE0122B34:
/* 40D0D4 E0122B34 8C620000 */  lw        $v0, ($v1)
/* 40D0D8 E0122B38 0040202D */  daddu     $a0, $v0, $zero
/* 40D0DC E0122B3C 24420008 */  addiu     $v0, $v0, 8
/* 40D0E0 E0122B40 AC620000 */  sw        $v0, ($v1)
/* 40D0E4 E0122B44 3C02E700 */  lui       $v0, 0xe700
/* 40D0E8 E0122B48 AC820000 */  sw        $v0, ($a0)
/* 40D0EC E0122B4C AC800004 */  sw        $zero, 4($a0)
/* 40D0F0 E0122B50 8FBF0084 */  lw        $ra, 0x84($sp)
/* 40D0F4 E0122B54 8FBE0080 */  lw        $fp, 0x80($sp)
/* 40D0F8 E0122B58 8FB7007C */  lw        $s7, 0x7c($sp)
/* 40D0FC E0122B5C 8FB60078 */  lw        $s6, 0x78($sp)
/* 40D100 E0122B60 8FB50074 */  lw        $s5, 0x74($sp)
/* 40D104 E0122B64 8FB40070 */  lw        $s4, 0x70($sp)
/* 40D108 E0122B68 8FB3006C */  lw        $s3, 0x6c($sp)
/* 40D10C E0122B6C 8FB20068 */  lw        $s2, 0x68($sp)
/* 40D110 E0122B70 8FB10064 */  lw        $s1, 0x64($sp)
/* 40D114 E0122B74 8FB00060 */  lw        $s0, 0x60($sp)
/* 40D118 E0122B78 D7B40088 */  ldc1      $f20, 0x88($sp)
/* 40D11C E0122B7C 03E00008 */  jr        $ra
/* 40D120 E0122B80 27BD0090 */   addiu    $sp, $sp, 0x90
/* 40D124 E0122B84 00000000 */  nop
/* 40D128 E0122B88 00000000 */  nop
/* 40D12C E0122B8C 00000000 */  nop
