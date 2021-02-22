.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F3680
/* 8CB30 800F3680 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 8CB34 800F3684 3C038011 */  lui       $v1, %hi(D_8010D640)
/* 8CB38 800F3688 8C63D640 */  lw        $v1, %lo(D_8010D640)($v1)
/* 8CB3C 800F368C 2402000A */  addiu     $v0, $zero, 0xa
/* 8CB40 800F3690 AFBF0054 */  sw        $ra, 0x54($sp)
/* 8CB44 800F3694 AFBE0050 */  sw        $fp, 0x50($sp)
/* 8CB48 800F3698 AFB7004C */  sw        $s7, 0x4c($sp)
/* 8CB4C 800F369C AFB60048 */  sw        $s6, 0x48($sp)
/* 8CB50 800F36A0 AFB50044 */  sw        $s5, 0x44($sp)
/* 8CB54 800F36A4 AFB40040 */  sw        $s4, 0x40($sp)
/* 8CB58 800F36A8 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8CB5C 800F36AC AFB20038 */  sw        $s2, 0x38($sp)
/* 8CB60 800F36B0 AFB10034 */  sw        $s1, 0x34($sp)
/* 8CB64 800F36B4 AFB00030 */  sw        $s0, 0x30($sp)
/* 8CB68 800F36B8 AFA5005C */  sw        $a1, 0x5c($sp)
/* 8CB6C 800F36BC 1062001E */  beq       $v1, $v0, .L800F3738
/* 8CB70 800F36C0 AFA60060 */   sw       $a2, 0x60($sp)
/* 8CB74 800F36C4 2862000B */  slti      $v0, $v1, 0xb
/* 8CB78 800F36C8 1040000E */  beqz      $v0, .L800F3704
/* 8CB7C 800F36CC 28620020 */   slti     $v0, $v1, 0x20
/* 8CB80 800F36D0 04610008 */  bgez      $v1, .L800F36F4
/* 8CB84 800F36D4 24020001 */   addiu    $v0, $zero, 1
/* 8CB88 800F36D8 2862FFFE */  slti      $v0, $v1, -2
/* 8CB8C 800F36DC 10400016 */  beqz      $v0, .L800F3738
/* 8CB90 800F36E0 2862FFFB */   slti     $v0, $v1, -5
/* 8CB94 800F36E4 104003CC */  beqz      $v0, .L800F4618
/* 8CB98 800F36E8 2862FFF8 */   slti     $v0, $v1, -8
/* 8CB9C 800F36EC 0803CDCC */  j         .L800F3730
/* 8CBA0 800F36F0 00000000 */   nop
.L800F36F4:
/* 8CBA4 800F36F4 10620010 */  beq       $v1, $v0, .L800F3738
/* 8CBA8 800F36F8 00000000 */   nop
/* 8CBAC 800F36FC 0803D186 */  j         .L800F4618
/* 8CBB0 800F3700 00000000 */   nop
.L800F3704:
/* 8CBB4 800F3704 10400007 */  beqz      $v0, .L800F3724
/* 8CBB8 800F3708 2862001E */   slti     $v0, $v1, 0x1e
/* 8CBBC 800F370C 1040000A */  beqz      $v0, .L800F3738
/* 8CBC0 800F3710 24020014 */   addiu    $v0, $zero, 0x14
/* 8CBC4 800F3714 10620008 */  beq       $v1, $v0, .L800F3738
/* 8CBC8 800F3718 00000000 */   nop
/* 8CBCC 800F371C 0803D186 */  j         .L800F4618
/* 8CBD0 800F3720 00000000 */   nop
.L800F3724:
/* 8CBD4 800F3724 2862006A */  slti      $v0, $v1, 0x6a
/* 8CBD8 800F3728 104003BB */  beqz      $v0, .L800F4618
/* 8CBDC 800F372C 28620064 */   slti     $v0, $v1, 0x64
.L800F3730:
/* 8CBE0 800F3730 144003B9 */  bnez      $v0, .L800F4618
/* 8CBE4 800F3734 00000000 */   nop
.L800F3738:
/* 8CBE8 800F3738 8FAA005C */  lw        $t2, 0x5c($sp)
/* 8CBEC 800F373C 8FAB0060 */  lw        $t3, 0x60($sp)
/* 8CBF0 800F3740 3C028011 */  lui       $v0, %hi(D_8010D654)
/* 8CBF4 800F3744 8042D654 */  lb        $v0, %lo(D_8010D654)($v0)
/* 8CBF8 800F3748 3C088011 */  lui       $t0, %hi(D_8010D658)
/* 8CBFC 800F374C 8508D658 */  lh        $t0, %lo(D_8010D658)($t0)
/* 8CC00 800F3750 254A0002 */  addiu     $t2, $t2, 2
/* 8CC04 800F3754 256B000F */  addiu     $t3, $t3, 0xf
/* 8CC08 800F3758 00021023 */  negu      $v0, $v0
/* 8CC0C 800F375C 00021840 */  sll       $v1, $v0, 1
/* 8CC10 800F3760 00621821 */  addu      $v1, $v1, $v0
/* 8CC14 800F3764 00031880 */  sll       $v1, $v1, 2
/* 8CC18 800F3768 00628821 */  addu      $s1, $v1, $v0
/* 8CC1C 800F376C 02282023 */  subu      $a0, $s1, $t0
/* 8CC20 800F3770 28820082 */  slti      $v0, $a0, 0x82
/* 8CC24 800F3774 AFAA005C */  sw        $t2, 0x5c($sp)
/* 8CC28 800F3778 1040000D */  beqz      $v0, .L800F37B0
/* 8CC2C 800F377C AFAB0060 */   sw       $t3, 0x60($sp)
/* 8CC30 800F3780 3C013FE0 */  lui       $at, 0x3fe0
/* 8CC34 800F3784 44811800 */  mtc1      $at, $f3
/* 8CC38 800F3788 44801000 */  mtc1      $zero, $f2
/* 8CC3C 800F378C 44840000 */  mtc1      $a0, $f0
/* 8CC40 800F3790 00000000 */  nop
/* 8CC44 800F3794 46800021 */  cvt.d.w   $f0, $f0
/* 8CC48 800F3798 46220002 */  mul.d     $f0, $f0, $f2
/* 8CC4C 800F379C 00000000 */  nop
/* 8CC50 800F37A0 4620018D */  trunc.w.d $f6, $f0
/* 8CC54 800F37A4 44043000 */  mfc1      $a0, $f6
/* 8CC58 800F37A8 0803CDF8 */  j         .L800F37E0
/* 8CC5C 800F37AC 00000000 */   nop
.L800F37B0:
/* 8CC60 800F37B0 3C031B4E */  lui       $v1, 0x1b4e
/* 8CC64 800F37B4 346381B5 */  ori       $v1, $v1, 0x81b5
/* 8CC68 800F37B8 00041040 */  sll       $v0, $a0, 1
/* 8CC6C 800F37BC 00441021 */  addu      $v0, $v0, $a0
/* 8CC70 800F37C0 000210C0 */  sll       $v0, $v0, 3
/* 8CC74 800F37C4 00441021 */  addu      $v0, $v0, $a0
/* 8CC78 800F37C8 00021080 */  sll       $v0, $v0, 2
/* 8CC7C 800F37CC 00430018 */  mult      $v0, $v1
/* 8CC80 800F37D0 000217C3 */  sra       $v0, $v0, 0x1f
/* 8CC84 800F37D4 00005010 */  mfhi      $t2
/* 8CC88 800F37D8 000A1903 */  sra       $v1, $t2, 4
/* 8CC8C 800F37DC 00622023 */  subu      $a0, $v1, $v0
.L800F37E0:
/* 8CC90 800F37E0 14800002 */  bnez      $a0, .L800F37EC
/* 8CC94 800F37E4 01044021 */   addu     $t0, $t0, $a0
/* 8CC98 800F37E8 0220402D */  daddu     $t0, $s1, $zero
.L800F37EC:
/* 8CC9C 800F37EC 3C054EC4 */  lui       $a1, 0x4ec4
/* 8CCA0 800F37F0 34A5EC4F */  ori       $a1, $a1, 0xec4f
/* 8CCA4 800F37F4 00081C00 */  sll       $v1, $t0, 0x10
/* 8CCA8 800F37F8 00031C03 */  sra       $v1, $v1, 0x10
/* 8CCAC 800F37FC 8FAB005C */  lw        $t3, 0x5c($sp)
/* 8CCB0 800F3800 8FB10060 */  lw        $s1, 0x60($sp)
/* 8CCB4 800F3804 3C048011 */  lui       $a0, %hi(D_8010D656)
/* 8CCB8 800F3808 8084D656 */  lb        $a0, %lo(D_8010D656)($a0)
/* 8CCBC 800F380C 00031823 */  negu      $v1, $v1
/* 8CCC0 800F3810 3C018011 */  lui       $at, %hi(D_8010D658)
/* 8CCC4 800F3814 A428D658 */  sh        $t0, %lo(D_8010D658)($at)
/* 8CCC8 800F3818 00041040 */  sll       $v0, $a0, 1
/* 8CCCC 800F381C 00441021 */  addu      $v0, $v0, $a0
/* 8CCD0 800F3820 00021080 */  sll       $v0, $v0, 2
/* 8CCD4 800F3824 00441021 */  addu      $v0, $v0, $a0
/* 8CCD8 800F3828 02221021 */  addu      $v0, $s1, $v0
/* 8CCDC 800F382C 24480004 */  addiu     $t0, $v0, 4
/* 8CCE0 800F3830 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8CCE4 800F3834 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8CCE8 800F3838 00650018 */  mult      $v1, $a1
/* 8CCEC 800F383C AFAB0020 */  sw        $t3, 0x20($sp)
/* 8CCF0 800F3840 8C450318 */  lw        $a1, 0x318($v0)
/* 8CCF4 800F3844 00031FC3 */  sra       $v1, $v1, 0x1f
/* 8CCF8 800F3848 2CA2000E */  sltiu     $v0, $a1, 0xe
/* 8CCFC 800F384C 00005010 */  mfhi      $t2
/* 8CD00 800F3850 000A2083 */  sra       $a0, $t2, 2
/* 8CD04 800F3854 00832023 */  subu      $a0, $a0, $v1
/* 8CD08 800F3858 10400064 */  beqz      $v0, .L800F39EC
/* 8CD0C 800F385C AFA40028 */   sw       $a0, 0x28($sp)
/* 8CD10 800F3860 00051080 */  sll       $v0, $a1, 2
/* 8CD14 800F3864 3C018011 */  lui       $at, %hi(jtbl_8010C790)
/* 8CD18 800F3868 00220821 */  addu      $at, $at, $v0
/* 8CD1C 800F386C 8C22C790 */  lw        $v0, %lo(jtbl_8010C790)($at)
/* 8CD20 800F3870 00400008 */  jr        $v0
/* 8CD24 800F3874 00000000 */   nop
glabel L800F3878_8CD28
/* 8CD28 800F3878 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 8CD2C 800F387C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 8CD30 800F3880 C7A20020 */  lwc1      $f2, 0x20($sp)
/* 8CD34 800F3884 468010A0 */  cvt.s.w   $f2, $f2
/* 8CD38 800F3888 44910000 */  mtc1      $s1, $f0
/* 8CD3C 800F388C 00000000 */  nop
/* 8CD40 800F3890 46800020 */  cvt.s.w   $f0, $f0
/* 8CD44 800F3894 3C014080 */  lui       $at, 0x4080
/* 8CD48 800F3898 44812000 */  mtc1      $at, $f4
/* 8CD4C 800F389C 8C620000 */  lw        $v0, ($v1)
/* 8CD50 800F38A0 46041082 */  mul.s     $f2, $f2, $f4
/* 8CD54 800F38A4 00000000 */  nop
/* 8CD58 800F38A8 0040282D */  daddu     $a1, $v0, $zero
/* 8CD5C 800F38AC 24420008 */  addiu     $v0, $v0, 8
/* 8CD60 800F38B0 AC620000 */  sw        $v0, ($v1)
/* 8CD64 800F38B4 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8CD68 800F38B8 46040002 */  mul.s     $f0, $f0, $f4
/* 8CD6C 800F38BC 00000000 */  nop
/* 8CD70 800F38C0 0803CE59 */  j         .L800F3964
/* 8CD74 800F38C4 25620070 */   addiu    $v0, $t3, 0x70
glabel L800F38C8_8CD78
/* 8CD78 800F38C8 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 8CD7C 800F38CC 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 8CD80 800F38D0 C7A20020 */  lwc1      $f2, 0x20($sp)
/* 8CD84 800F38D4 468010A0 */  cvt.s.w   $f2, $f2
/* 8CD88 800F38D8 44910000 */  mtc1      $s1, $f0
/* 8CD8C 800F38DC 00000000 */  nop
/* 8CD90 800F38E0 46800020 */  cvt.s.w   $f0, $f0
/* 8CD94 800F38E4 3C014080 */  lui       $at, 0x4080
/* 8CD98 800F38E8 44812000 */  mtc1      $at, $f4
/* 8CD9C 800F38EC 8C620000 */  lw        $v0, ($v1)
/* 8CDA0 800F38F0 46041082 */  mul.s     $f2, $f2, $f4
/* 8CDA4 800F38F4 00000000 */  nop
/* 8CDA8 800F38F8 0040282D */  daddu     $a1, $v0, $zero
/* 8CDAC 800F38FC 24420008 */  addiu     $v0, $v0, 8
/* 8CDB0 800F3900 AC620000 */  sw        $v0, ($v1)
/* 8CDB4 800F3904 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8CDB8 800F3908 46040002 */  mul.s     $f0, $f0, $f4
/* 8CDBC 800F390C 00000000 */  nop
/* 8CDC0 800F3910 0803CE59 */  j         .L800F3964
/* 8CDC4 800F3914 2562005A */   addiu    $v0, $t3, 0x5a
glabel L800F3918_8CDC8
/* 8CDC8 800F3918 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 8CDCC 800F391C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 8CDD0 800F3920 C7A20020 */  lwc1      $f2, 0x20($sp)
/* 8CDD4 800F3924 468010A0 */  cvt.s.w   $f2, $f2
/* 8CDD8 800F3928 44910000 */  mtc1      $s1, $f0
/* 8CDDC 800F392C 00000000 */  nop
/* 8CDE0 800F3930 46800020 */  cvt.s.w   $f0, $f0
/* 8CDE4 800F3934 3C014080 */  lui       $at, 0x4080
/* 8CDE8 800F3938 44812000 */  mtc1      $at, $f4
/* 8CDEC 800F393C 8C620000 */  lw        $v0, ($v1)
/* 8CDF0 800F3940 46041082 */  mul.s     $f2, $f2, $f4
/* 8CDF4 800F3944 00000000 */  nop
/* 8CDF8 800F3948 0040282D */  daddu     $a1, $v0, $zero
/* 8CDFC 800F394C 24420008 */  addiu     $v0, $v0, 8
/* 8CE00 800F3950 AC620000 */  sw        $v0, ($v1)
/* 8CE04 800F3954 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8CE08 800F3958 46040002 */  mul.s     $f0, $f0, $f4
/* 8CE0C 800F395C 00000000 */  nop
/* 8CE10 800F3960 256200A0 */  addiu     $v0, $t3, 0xa0
.L800F3964:
/* 8CE14 800F3964 4600118D */  trunc.w.s $f6, $f2
/* 8CE18 800F3968 44033000 */  mfc1      $v1, $f6
/* 8CE1C 800F396C 00000000 */  nop
/* 8CE20 800F3970 30630FFF */  andi      $v1, $v1, 0xfff
/* 8CE24 800F3974 00031B00 */  sll       $v1, $v1, 0xc
/* 8CE28 800F3978 4600018D */  trunc.w.s $f6, $f0
/* 8CE2C 800F397C 44043000 */  mfc1      $a0, $f6
/* 8CE30 800F3980 00000000 */  nop
/* 8CE34 800F3984 30840FFF */  andi      $a0, $a0, 0xfff
/* 8CE38 800F3988 44821000 */  mtc1      $v0, $f2
/* 8CE3C 800F398C 00000000 */  nop
/* 8CE40 800F3990 468010A0 */  cvt.s.w   $f2, $f2
/* 8CE44 800F3994 46041082 */  mul.s     $f2, $f2, $f4
/* 8CE48 800F3998 00000000 */  nop
/* 8CE4C 800F399C 3C02ED00 */  lui       $v0, 0xed00
/* 8CE50 800F39A0 00822025 */  or        $a0, $a0, $v0
/* 8CE54 800F39A4 00641825 */  or        $v1, $v1, $a0
/* 8CE58 800F39A8 44880000 */  mtc1      $t0, $f0
/* 8CE5C 800F39AC 00000000 */  nop
/* 8CE60 800F39B0 46800020 */  cvt.s.w   $f0, $f0
/* 8CE64 800F39B4 46040002 */  mul.s     $f0, $f0, $f4
/* 8CE68 800F39B8 00000000 */  nop
/* 8CE6C 800F39BC ACA30000 */  sw        $v1, ($a1)
/* 8CE70 800F39C0 4600118D */  trunc.w.s $f6, $f2
/* 8CE74 800F39C4 44023000 */  mfc1      $v0, $f6
/* 8CE78 800F39C8 00000000 */  nop
/* 8CE7C 800F39CC 30420FFF */  andi      $v0, $v0, 0xfff
/* 8CE80 800F39D0 00021300 */  sll       $v0, $v0, 0xc
/* 8CE84 800F39D4 4600018D */  trunc.w.s $f6, $f0
/* 8CE88 800F39D8 44033000 */  mfc1      $v1, $f6
/* 8CE8C 800F39DC 00000000 */  nop
/* 8CE90 800F39E0 30630FFF */  andi      $v1, $v1, 0xfff
/* 8CE94 800F39E4 00431025 */  or        $v0, $v0, $v1
/* 8CE98 800F39E8 ACA20004 */  sw        $v0, 4($a1)
.L800F39EC:
/* 8CE9C 800F39EC 3C028011 */  lui       $v0, %hi(D_8010D658)
/* 8CEA0 800F39F0 8442D658 */  lh        $v0, %lo(D_8010D658)($v0)
/* 8CEA4 800F39F4 8FAB0060 */  lw        $t3, 0x60($sp)
/* 8CEA8 800F39F8 3C128011 */  lui       $s2, %hi(D_8010D69C)
/* 8CEAC 800F39FC 2652D69C */  addiu     $s2, $s2, %lo(D_8010D69C)
/* 8CEB0 800F3A00 01621821 */  addu      $v1, $t3, $v0
/* 8CEB4 800F3A04 8E420000 */  lw        $v0, ($s2)
/* 8CEB8 800F3A08 24130002 */  addiu     $s3, $zero, 2
/* 8CEBC 800F3A0C 8C420318 */  lw        $v0, 0x318($v0)
/* 8CEC0 800F3A10 14530002 */  bne       $v0, $s3, .L800F3A1C
/* 8CEC4 800F3A14 24710008 */   addiu    $s1, $v1, 8
/* 8CEC8 800F3A18 24710015 */  addiu     $s1, $v1, 0x15
.L800F3A1C:
/* 8CECC 800F3A1C 2626FFFD */  addiu     $a2, $s1, -3
/* 8CED0 800F3A20 8FAA005C */  lw        $t2, 0x5c($sp)
/* 8CED4 800F3A24 3C108011 */  lui       $s0, %hi(D_8010D65C)
/* 8CED8 800F3A28 8E10D65C */  lw        $s0, %lo(D_8010D65C)($s0)
/* 8CEDC 800F3A2C 25450049 */  addiu     $a1, $t2, 0x49
/* 8CEE0 800F3A30 0C051261 */  jal       set_icon_render_pos
/* 8CEE4 800F3A34 0200202D */   daddu    $a0, $s0, $zero
/* 8CEE8 800F3A38 3C058011 */  lui       $a1, %hi(D_8010D650)
/* 8CEEC 800F3A3C 8CA5D650 */  lw        $a1, %lo(D_8010D650)($a1)
/* 8CEF0 800F3A40 0C0513AC */  jal       icon_set_opacity
/* 8CEF4 800F3A44 0200202D */   daddu    $a0, $s0, $zero
/* 8CEF8 800F3A48 8E420000 */  lw        $v0, ($s2)
/* 8CEFC 800F3A4C 3C038011 */  lui       $v1, %hi(D_8010D68F)
/* 8CF00 800F3A50 8063D68F */  lb        $v1, %lo(D_8010D68F)($v1)
/* 8CF04 800F3A54 8C420324 */  lw        $v0, 0x324($v0)
/* 8CF08 800F3A58 0062182A */  slt       $v1, $v1, $v0
/* 8CF0C 800F3A5C 10600003 */  beqz      $v1, .L800F3A6C
/* 8CF10 800F3A60 00000000 */   nop
/* 8CF14 800F3A64 0C0511F8 */  jal       draw_icon_2
/* 8CF18 800F3A68 0200202D */   daddu    $a0, $s0, $zero
.L800F3A6C:
/* 8CF1C 800F3A6C 8FAB005C */  lw        $t3, 0x5c($sp)
/* 8CF20 800F3A70 8FAA0060 */  lw        $t2, 0x60($sp)
/* 8CF24 800F3A74 3C038011 */  lui       $v1, %hi(D_8010D656)
/* 8CF28 800F3A78 8063D656 */  lb        $v1, %lo(D_8010D656)($v1)
/* 8CF2C 800F3A7C 25510002 */  addiu     $s1, $t2, 2
/* 8CF30 800F3A80 00031040 */  sll       $v0, $v1, 1
/* 8CF34 800F3A84 00431021 */  addu      $v0, $v0, $v1
/* 8CF38 800F3A88 00021080 */  sll       $v0, $v0, 2
/* 8CF3C 800F3A8C AFAB0020 */  sw        $t3, 0x20($sp)
/* 8CF40 800F3A90 8E440000 */  lw        $a0, ($s2)
/* 8CF44 800F3A94 00431021 */  addu      $v0, $v0, $v1
/* 8CF48 800F3A98 8C830318 */  lw        $v1, 0x318($a0)
/* 8CF4C 800F3A9C 14730008 */  bne       $v1, $s3, .L800F3AC0
/* 8CF50 800F3AA0 02224021 */   addu     $t0, $s1, $v0
/* 8CF54 800F3AA4 3C028011 */  lui       $v0, %hi(D_8010D654)
/* 8CF58 800F3AA8 8042D654 */  lb        $v0, %lo(D_8010D654)($v0)
/* 8CF5C 800F3AAC 28420002 */  slti      $v0, $v0, 2
/* 8CF60 800F3AB0 10400003 */  beqz      $v0, .L800F3AC0
/* 8CF64 800F3AB4 00000000 */   nop
/* 8CF68 800F3AB8 0140882D */  daddu     $s1, $t2, $zero
/* 8CF6C 800F3ABC 25080001 */  addiu     $t0, $t0, 1
.L800F3AC0:
/* 8CF70 800F3AC0 C7A20020 */  lwc1      $f2, 0x20($sp)
/* 8CF74 800F3AC4 468010A0 */  cvt.s.w   $f2, $f2
/* 8CF78 800F3AC8 3C014080 */  lui       $at, 0x4080
/* 8CF7C 800F3ACC 44812000 */  mtc1      $at, $f4
/* 8CF80 800F3AD0 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 8CF84 800F3AD4 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 8CF88 800F3AD8 46041082 */  mul.s     $f2, $f2, $f4
/* 8CF8C 800F3ADC 00000000 */  nop
/* 8CF90 800F3AE0 44910000 */  mtc1      $s1, $f0
/* 8CF94 800F3AE4 00000000 */  nop
/* 8CF98 800F3AE8 46800020 */  cvt.s.w   $f0, $f0
/* 8CF9C 800F3AEC 8CC50000 */  lw        $a1, ($a2)
/* 8CFA0 800F3AF0 3C04ED00 */  lui       $a0, 0xed00
/* 8CFA4 800F3AF4 00A0382D */  daddu     $a3, $a1, $zero
/* 8CFA8 800F3AF8 46040002 */  mul.s     $f0, $f0, $f4
/* 8CFAC 800F3AFC 00000000 */  nop
/* 8CFB0 800F3B00 24A50008 */  addiu     $a1, $a1, 8
/* 8CFB4 800F3B04 4600118D */  trunc.w.s $f6, $f2
/* 8CFB8 800F3B08 44023000 */  mfc1      $v0, $f6
/* 8CFBC 800F3B0C 00000000 */  nop
/* 8CFC0 800F3B10 30420FFF */  andi      $v0, $v0, 0xfff
/* 8CFC4 800F3B14 00021300 */  sll       $v0, $v0, 0xc
/* 8CFC8 800F3B18 4600018D */  trunc.w.s $f6, $f0
/* 8CFCC 800F3B1C 44033000 */  mfc1      $v1, $f6
/* 8CFD0 800F3B20 00000000 */  nop
/* 8CFD4 800F3B24 30630FFF */  andi      $v1, $v1, 0xfff
/* 8CFD8 800F3B28 00641825 */  or        $v1, $v1, $a0
/* 8CFDC 800F3B2C 00431025 */  or        $v0, $v0, $v1
/* 8CFE0 800F3B30 3C048011 */  lui       $a0, %hi(D_8010D69C)
/* 8CFE4 800F3B34 8C84D69C */  lw        $a0, %lo(D_8010D69C)($a0)
/* 8CFE8 800F3B38 44880000 */  mtc1      $t0, $f0
/* 8CFEC 800F3B3C 00000000 */  nop
/* 8CFF0 800F3B40 46800020 */  cvt.s.w   $f0, $f0
/* 8CFF4 800F3B44 ACE20000 */  sw        $v0, ($a3)
/* 8CFF8 800F3B48 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8CFFC 800F3B4C 8C820318 */  lw        $v0, 0x318($a0)
/* 8D000 800F3B50 46040002 */  mul.s     $f0, $f0, $f4
/* 8D004 800F3B54 00000000 */  nop
/* 8D008 800F3B58 AFA00024 */  sw        $zero, 0x24($sp)
/* 8D00C 800F3B5C 00021040 */  sll       $v0, $v0, 1
/* 8D010 800F3B60 3C018011 */  lui       $at, %hi(D_801098BC)
/* 8D014 800F3B64 00220821 */  addu      $at, $at, $v0
/* 8D018 800F3B68 842298BC */  lh        $v0, %lo(D_801098BC)($at)
/* 8D01C 800F3B6C 8FAA0060 */  lw        $t2, 0x60($sp)
/* 8D020 800F3B70 01621021 */  addu      $v0, $t3, $v0
/* 8D024 800F3B74 44821000 */  mtc1      $v0, $f2
/* 8D028 800F3B78 00000000 */  nop
/* 8D02C 800F3B7C 468010A0 */  cvt.s.w   $f2, $f2
/* 8D030 800F3B80 3C028011 */  lui       $v0, %hi(D_8010D658)
/* 8D034 800F3B84 8442D658 */  lh        $v0, %lo(D_8010D658)($v0)
/* 8D038 800F3B88 46041082 */  mul.s     $f2, $f2, $f4
/* 8D03C 800F3B8C 00000000 */  nop
/* 8D040 800F3B90 ACC50000 */  sw        $a1, ($a2)
/* 8D044 800F3B94 8FAB005C */  lw        $t3, 0x5c($sp)
/* 8D048 800F3B98 01424821 */  addu      $t1, $t2, $v0
/* 8D04C 800F3B9C 256B0020 */  addiu     $t3, $t3, 0x20
/* 8D050 800F3BA0 AFAB0020 */  sw        $t3, 0x20($sp)
/* 8D054 800F3BA4 4600118D */  trunc.w.s $f6, $f2
/* 8D058 800F3BA8 44023000 */  mfc1      $v0, $f6
/* 8D05C 800F3BAC 00000000 */  nop
/* 8D060 800F3BB0 30420FFF */  andi      $v0, $v0, 0xfff
/* 8D064 800F3BB4 00021300 */  sll       $v0, $v0, 0xc
/* 8D068 800F3BB8 4600018D */  trunc.w.s $f6, $f0
/* 8D06C 800F3BBC 44033000 */  mfc1      $v1, $f6
/* 8D070 800F3BC0 00000000 */  nop
/* 8D074 800F3BC4 30630FFF */  andi      $v1, $v1, 0xfff
/* 8D078 800F3BC8 00431025 */  or        $v0, $v0, $v1
/* 8D07C 800F3BCC ACE20004 */  sw        $v0, 4($a3)
/* 8D080 800F3BD0 8C830318 */  lw        $v1, 0x318($a0)
/* 8D084 800F3BD4 24020002 */  addiu     $v0, $zero, 2
/* 8D088 800F3BD8 14620004 */  bne       $v1, $v0, .L800F3BEC
/* 8D08C 800F3BDC 25310002 */   addiu    $s1, $t1, 2
/* 8D090 800F3BE0 0120882D */  daddu     $s1, $t1, $zero
/* 8D094 800F3BE4 0040582D */  daddu     $t3, $v0, $zero
/* 8D098 800F3BE8 AFAB0024 */  sw        $t3, 0x24($sp)
.L800F3BEC:
/* 8D09C 800F3BEC 8C820324 */  lw        $v0, 0x324($a0)
/* 8D0A0 800F3BF0 184000EA */  blez      $v0, .L800F3F9C
/* 8D0A4 800F3BF4 0000902D */   daddu    $s2, $zero, $zero
/* 8D0A8 800F3BF8 AFA0002C */  sw        $zero, 0x2c($sp)
.L800F3BFC:
/* 8D0AC 800F3BFC 8FAA0028 */  lw        $t2, 0x28($sp)
/* 8D0B0 800F3C00 2542FFFF */  addiu     $v0, $t2, -1
/* 8D0B4 800F3C04 0242102A */  slt       $v0, $s2, $v0
/* 8D0B8 800F3C08 14400007 */  bnez      $v0, .L800F3C28
/* 8D0BC 800F3C0C 00000000 */   nop
/* 8D0C0 800F3C10 3C028011 */  lui       $v0, %hi(D_8010D656)
/* 8D0C4 800F3C14 8042D656 */  lb        $v0, %lo(D_8010D656)($v0)
/* 8D0C8 800F3C18 01421021 */  addu      $v0, $t2, $v0
/* 8D0CC 800F3C1C 0052102A */  slt       $v0, $v0, $s2
/* 8D0D0 800F3C20 10400006 */  beqz      $v0, .L800F3C3C
/* 8D0D4 800F3C24 240A0001 */   addiu    $t2, $zero, 1
.L800F3C28:
/* 8D0D8 800F3C28 164000D3 */  bnez      $s2, .L800F3F78
/* 8D0DC 800F3C2C 2631000D */   addiu    $s1, $s1, 0xd
/* 8D0E0 800F3C30 8FAB0024 */  lw        $t3, 0x24($sp)
/* 8D0E4 800F3C34 0803CFDE */  j         .L800F3F78
/* 8D0E8 800F3C38 022B8821 */   addu     $s1, $s1, $t3
.L800F3C3C:
/* 8D0EC 800F3C3C 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D0F0 800F3C40 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D0F4 800F3C44 8C430318 */  lw        $v1, 0x318($v0)
/* 8D0F8 800F3C48 3C108011 */  lui       $s0, %hi(D_8010D690)
/* 8D0FC 800F3C4C 8210D690 */  lb        $s0, %lo(D_8010D690)($s0)
/* 8D100 800F3C50 506A0001 */  beql      $v1, $t2, .L800F3C58
/* 8D104 800F3C54 2410000A */   addiu    $s0, $zero, 0xa
.L800F3C58:
/* 8D108 800F3C58 8FAB002C */  lw        $t3, 0x2c($sp)
/* 8D10C 800F3C5C 004B1021 */  addu      $v0, $v0, $t3
/* 8D110 800F3C60 8C42018C */  lw        $v0, 0x18c($v0)
/* 8D114 800F3C64 50400001 */  beql      $v0, $zero, .L800F3C6C
/* 8D118 800F3C68 2410000B */   addiu    $s0, $zero, 0xb
.L800F3C6C:
/* 8D11C 800F3C6C 2C62000E */  sltiu     $v0, $v1, 0xe
/* 8D120 800F3C70 1040005A */  beqz      $v0, .L800F3DDC
/* 8D124 800F3C74 00031080 */   sll      $v0, $v1, 2
/* 8D128 800F3C78 3C018011 */  lui       $at, %hi(jtbl_8010C7C8)
/* 8D12C 800F3C7C 00220821 */  addu      $at, $at, $v0
/* 8D130 800F3C80 8C22C7C8 */  lw        $v0, %lo(jtbl_8010C7C8)($at)
/* 8D134 800F3C84 00400008 */  jr        $v0
/* 8D138 800F3C88 00000000 */   nop
glabel L800F3C8C_8D13C
/* 8D13C 800F3C8C 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8D140 800F3C90 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8D144 800F3C94 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D148 800F3C98 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D14C 800F3C9C 8FA50020 */  lw        $a1, 0x20($sp)
/* 8D150 800F3CA0 8FAB002C */  lw        $t3, 0x2c($sp)
/* 8D154 800F3CA4 240A0001 */  addiu     $t2, $zero, 1
/* 8D158 800F3CA8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D15C 800F3CAC AFAA0014 */  sw        $t2, 0x14($sp)
/* 8D160 800F3CB0 004B1021 */  addu      $v0, $v0, $t3
/* 8D164 800F3CB4 8C440084 */  lw        $a0, 0x84($v0)
/* 8D168 800F3CB8 0803CF75 */  j         .L800F3DD4
/* 8D16C 800F3CBC 0220302D */   daddu    $a2, $s1, $zero
glabel L800F3CC0_8D170
/* 8D170 800F3CC0 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8D174 800F3CC4 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8D178 800F3CC8 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D17C 800F3CCC 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D180 800F3CD0 8FA50020 */  lw        $a1, 0x20($sp)
/* 8D184 800F3CD4 8FAB002C */  lw        $t3, 0x2c($sp)
/* 8D188 800F3CD8 240A0001 */  addiu     $t2, $zero, 1
/* 8D18C 800F3CDC AFB00010 */  sw        $s0, 0x10($sp)
/* 8D190 800F3CE0 AFAA0014 */  sw        $t2, 0x14($sp)
/* 8D194 800F3CE4 004B1021 */  addu      $v0, $v0, $t3
/* 8D198 800F3CE8 8C440084 */  lw        $a0, 0x84($v0)
/* 8D19C 800F3CEC 0803CF75 */  j         .L800F3DD4
/* 8D1A0 800F3CF0 0220302D */   daddu    $a2, $s1, $zero
glabel L800F3CF4_8D1A4
/* 8D1A4 800F3CF4 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D1A8 800F3CF8 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D1AC 800F3CFC 8FAA002C */  lw        $t2, 0x2c($sp)
/* 8D1B0 800F3D00 004A2021 */  addu      $a0, $v0, $t2
/* 8D1B4 800F3D04 8C83018C */  lw        $v1, 0x18c($a0)
/* 8D1B8 800F3D08 24020002 */  addiu     $v0, $zero, 2
/* 8D1BC 800F3D0C 50620001 */  beql      $v1, $v0, .L800F3D14
/* 8D1C0 800F3D10 24100022 */   addiu    $s0, $zero, 0x22
.L800F3D14:
/* 8D1C4 800F3D14 8FA50020 */  lw        $a1, 0x20($sp)
/* 8D1C8 800F3D18 240B0001 */  addiu     $t3, $zero, 1
/* 8D1CC 800F3D1C AFB00010 */  sw        $s0, 0x10($sp)
/* 8D1D0 800F3D20 AFAB0014 */  sw        $t3, 0x14($sp)
/* 8D1D4 800F3D24 8C840084 */  lw        $a0, 0x84($a0)
/* 8D1D8 800F3D28 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8D1DC 800F3D2C 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8D1E0 800F3D30 0803CF75 */  j         .L800F3DD4
/* 8D1E4 800F3D34 0220302D */   daddu    $a2, $s1, $zero
glabel L800F3D38_8D1E8
/* 8D1E8 800F3D38 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D1EC 800F3D3C 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D1F0 800F3D40 8FAA002C */  lw        $t2, 0x2c($sp)
/* 8D1F4 800F3D44 004A1821 */  addu      $v1, $v0, $t2
/* 8D1F8 800F3D48 8C620210 */  lw        $v0, 0x210($v1)
/* 8D1FC 800F3D4C 10400002 */  beqz      $v0, .L800F3D58
/* 8D200 800F3D50 2410000A */   addiu    $s0, $zero, 0xa
/* 8D204 800F3D54 2410000B */  addiu     $s0, $zero, 0xb
.L800F3D58:
/* 8D208 800F3D58 8C640108 */  lw        $a0, 0x108($v1)
/* 8D20C 800F3D5C 0000282D */  daddu     $a1, $zero, $zero
/* 8D210 800F3D60 0C0496FA */  jal       set_message_value
/* 8D214 800F3D64 24840001 */   addiu    $a0, $a0, 1
/* 8D218 800F3D68 3C04001D */  lui       $a0, 0x1d
/* 8D21C 800F3D6C 348400CD */  ori       $a0, $a0, 0xcd
/* 8D220 800F3D70 0220302D */  daddu     $a2, $s1, $zero
/* 8D224 800F3D74 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8D228 800F3D78 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8D22C 800F3D7C 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8D230 800F3D80 240A0001 */  addiu     $t2, $zero, 1
/* 8D234 800F3D84 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D238 800F3D88 AFAA0014 */  sw        $t2, 0x14($sp)
/* 8D23C 800F3D8C 0803CF75 */  j         .L800F3DD4
/* 8D240 800F3D90 25650008 */   addiu    $a1, $t3, 8
glabel L800F3D94_8D244
/* 8D244 800F3D94 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D248 800F3D98 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D24C 800F3D9C 8FAB002C */  lw        $t3, 0x2c($sp)
/* 8D250 800F3DA0 004B1821 */  addu      $v1, $v0, $t3
/* 8D254 800F3DA4 8C620210 */  lw        $v0, 0x210($v1)
/* 8D258 800F3DA8 10400002 */  beqz      $v0, .L800F3DB4
/* 8D25C 800F3DAC 2410000A */   addiu    $s0, $zero, 0xa
/* 8D260 800F3DB0 2410000B */  addiu     $s0, $zero, 0xb
.L800F3DB4:
/* 8D264 800F3DB4 0220302D */  daddu     $a2, $s1, $zero
/* 8D268 800F3DB8 8FA50020 */  lw        $a1, 0x20($sp)
/* 8D26C 800F3DBC 3C078011 */  lui       $a3, %hi(D_8010D650)
/* 8D270 800F3DC0 8CE7D650 */  lw        $a3, %lo(D_8010D650)($a3)
/* 8D274 800F3DC4 8C640084 */  lw        $a0, 0x84($v1)
/* 8D278 800F3DC8 240A0001 */  addiu     $t2, $zero, 1
/* 8D27C 800F3DCC AFB00010 */  sw        $s0, 0x10($sp)
/* 8D280 800F3DD0 AFAA0014 */  sw        $t2, 0x14($sp)
.L800F3DD4:
/* 8D284 800F3DD4 0C04993B */  jal       draw_msg
/* 8D288 800F3DD8 00000000 */   nop
.L800F3DDC:
/* 8D28C 800F3DDC 3C048011 */  lui       $a0, %hi(D_8010D69C)
/* 8D290 800F3DE0 8C84D69C */  lw        $a0, %lo(D_8010D69C)($a0)
/* 8D294 800F3DE4 8C830318 */  lw        $v1, 0x318($a0)
/* 8D298 800F3DE8 240B0003 */  addiu     $t3, $zero, 3
/* 8D29C 800F3DEC 106B0045 */  beq       $v1, $t3, .L800F3F04
/* 8D2A0 800F3DF0 0220302D */   daddu    $a2, $s1, $zero
/* 8D2A4 800F3DF4 28620004 */  slti      $v0, $v1, 4
/* 8D2A8 800F3DF8 10400005 */  beqz      $v0, .L800F3E10
/* 8D2AC 800F3DFC 240A0001 */   addiu    $t2, $zero, 1
/* 8D2B0 800F3E00 106A000B */  beq       $v1, $t2, .L800F3E30
/* 8D2B4 800F3E04 0000982D */   daddu    $s3, $zero, $zero
/* 8D2B8 800F3E08 0803CFDA */  j         .L800F3F68
/* 8D2BC 800F3E0C 2631000D */   addiu    $s1, $s1, 0xd
.L800F3E10:
/* 8D2C0 800F3E10 24020004 */  addiu     $v0, $zero, 4
/* 8D2C4 800F3E14 10620005 */  beq       $v1, $v0, .L800F3E2C
/* 8D2C8 800F3E18 24020005 */   addiu    $v0, $zero, 5
/* 8D2CC 800F3E1C 10620044 */  beq       $v1, $v0, .L800F3F30
/* 8D2D0 800F3E20 0220302D */   daddu    $a2, $s1, $zero
/* 8D2D4 800F3E24 0803CFDA */  j         .L800F3F68
/* 8D2D8 800F3E28 2631000D */   addiu    $s1, $s1, 0xd
.L800F3E2C:
/* 8D2DC 800F3E2C 0000982D */  daddu     $s3, $zero, $zero
.L800F3E30:
/* 8D2E0 800F3E30 0012F080 */  sll       $fp, $s2, 2
/* 8D2E4 800F3E34 2417005B */  addiu     $s7, $zero, 0x5b
/* 8D2E8 800F3E38 24160055 */  addiu     $s6, $zero, 0x55
/* 8D2EC 800F3E3C 3C158011 */  lui       $s5, %hi(D_80109898)
/* 8D2F0 800F3E40 26B59898 */  addiu     $s5, $s5, %lo(D_80109898)
/* 8D2F4 800F3E44 3C148011 */  lui       $s4, %hi(D_80109890)
/* 8D2F8 800F3E48 26949890 */  addiu     $s4, $s4, %lo(D_80109890)
.L800F3E4C:
/* 8D2FC 800F3E4C 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D300 800F3E50 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D304 800F3E54 005E1021 */  addu      $v0, $v0, $fp
/* 8D308 800F3E58 8C42018C */  lw        $v0, 0x18c($v0)
/* 8D30C 800F3E5C 3C108011 */  lui       $s0, %hi(D_8010D668)
/* 8D310 800F3E60 8E10D668 */  lw        $s0, %lo(D_8010D668)($s0)
/* 8D314 800F3E64 10400003 */  beqz      $v0, .L800F3E74
/* 8D318 800F3E68 00000000 */   nop
/* 8D31C 800F3E6C 0803CF9E */  j         .L800F3E78
/* 8D320 800F3E70 8E850000 */   lw       $a1, ($s4)
.L800F3E74:
/* 8D324 800F3E74 8EA50000 */  lw        $a1, ($s5)
.L800F3E78:
/* 8D328 800F3E78 0C0511FF */  jal       set_menu_icon_script
/* 8D32C 800F3E7C 0200202D */   daddu    $a0, $s0, $zero
/* 8D330 800F3E80 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D334 800F3E84 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D338 800F3E88 8C420318 */  lw        $v0, 0x318($v0)
/* 8D33C 800F3E8C 240B0001 */  addiu     $t3, $zero, 1
/* 8D340 800F3E90 144B0005 */  bne       $v0, $t3, .L800F3EA8
/* 8D344 800F3E94 0200202D */   daddu    $a0, $s0, $zero
/* 8D348 800F3E98 8FAA0020 */  lw        $t2, 0x20($sp)
/* 8D34C 800F3E9C 2626000A */  addiu     $a2, $s1, 0xa
/* 8D350 800F3EA0 0803CFAD */  j         .L800F3EB4
/* 8D354 800F3EA4 01562821 */   addu     $a1, $t2, $s6
.L800F3EA8:
/* 8D358 800F3EA8 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8D35C 800F3EAC 2626000A */  addiu     $a2, $s1, 0xa
/* 8D360 800F3EB0 01772821 */  addu      $a1, $t3, $s7
.L800F3EB4:
/* 8D364 800F3EB4 0C051261 */  jal       set_icon_render_pos
/* 8D368 800F3EB8 00000000 */   nop
/* 8D36C 800F3EBC 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D370 800F3EC0 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D374 800F3EC4 005E1021 */  addu      $v0, $v0, $fp
/* 8D378 800F3EC8 8C420210 */  lw        $v0, 0x210($v0)
/* 8D37C 800F3ECC 0262102A */  slt       $v0, $s3, $v0
/* 8D380 800F3ED0 50400004 */  beql      $v0, $zero, .L800F3EE4
/* 8D384 800F3ED4 26F7000D */   addiu    $s7, $s7, 0xd
/* 8D388 800F3ED8 0C0511F1 */  jal       draw_icon_1
/* 8D38C 800F3EDC 0200202D */   daddu    $a0, $s0, $zero
/* 8D390 800F3EE0 26F7000D */  addiu     $s7, $s7, 0xd
.L800F3EE4:
/* 8D394 800F3EE4 26D6000D */  addiu     $s6, $s6, 0xd
/* 8D398 800F3EE8 26B50004 */  addiu     $s5, $s5, 4
/* 8D39C 800F3EEC 26730001 */  addiu     $s3, $s3, 1
/* 8D3A0 800F3EF0 2A620002 */  slti      $v0, $s3, 2
/* 8D3A4 800F3EF4 1440FFD5 */  bnez      $v0, .L800F3E4C
/* 8D3A8 800F3EF8 26940004 */   addiu    $s4, $s4, 4
/* 8D3AC 800F3EFC 0803CFDA */  j         .L800F3F68
/* 8D3B0 800F3F00 2631000D */   addiu    $s1, $s1, 0xd
.L800F3F04:
/* 8D3B4 800F3F04 8FAA0020 */  lw        $t2, 0x20($sp)
/* 8D3B8 800F3F08 3C028011 */  lui       $v0, %hi(D_8010D650)
/* 8D3BC 800F3F0C 8C42D650 */  lw        $v0, %lo(D_8010D650)($v0)
/* 8D3C0 800F3F10 25450073 */  addiu     $a1, $t2, 0x73
/* 8D3C4 800F3F14 8FAA002C */  lw        $t2, 0x2c($sp)
/* 8D3C8 800F3F18 240B0003 */  addiu     $t3, $zero, 3
/* 8D3CC 800F3F1C AFB00010 */  sw        $s0, 0x10($sp)
/* 8D3D0 800F3F20 AFAB0018 */  sw        $t3, 0x18($sp)
/* 8D3D4 800F3F24 AFA20014 */  sw        $v0, 0x14($sp)
/* 8D3D8 800F3F28 0803CFD6 */  j         .L800F3F58
/* 8D3DC 800F3F2C 008A1021 */   addu     $v0, $a0, $t2
.L800F3F30:
/* 8D3E0 800F3F30 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8D3E4 800F3F34 3C028011 */  lui       $v0, %hi(D_8010D650)
/* 8D3E8 800F3F38 8C42D650 */  lw        $v0, %lo(D_8010D650)($v0)
/* 8D3EC 800F3F3C 25650079 */  addiu     $a1, $t3, 0x79
/* 8D3F0 800F3F40 8FAB002C */  lw        $t3, 0x2c($sp)
/* 8D3F4 800F3F44 240A0003 */  addiu     $t2, $zero, 3
/* 8D3F8 800F3F48 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D3FC 800F3F4C AFAA0018 */  sw        $t2, 0x18($sp)
/* 8D400 800F3F50 AFA20014 */  sw        $v0, 0x14($sp)
/* 8D404 800F3F54 008B1021 */  addu      $v0, $a0, $t3
.L800F3F58:
/* 8D408 800F3F58 8C440210 */  lw        $a0, 0x210($v0)
/* 8D40C 800F3F5C 0C049DA7 */  jal       draw_number
/* 8D410 800F3F60 24070001 */   addiu    $a3, $zero, 1
/* 8D414 800F3F64 2631000D */  addiu     $s1, $s1, 0xd
.L800F3F68:
/* 8D418 800F3F68 56400004 */  bnel      $s2, $zero, .L800F3F7C
/* 8D41C 800F3F6C 26520001 */   addiu    $s2, $s2, 1
/* 8D420 800F3F70 8FAA0024 */  lw        $t2, 0x24($sp)
/* 8D424 800F3F74 022A8821 */  addu      $s1, $s1, $t2
.L800F3F78:
/* 8D428 800F3F78 26520001 */  addiu     $s2, $s2, 1
.L800F3F7C:
/* 8D42C 800F3F7C 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D430 800F3F80 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D434 800F3F84 8FAB002C */  lw        $t3, 0x2c($sp)
/* 8D438 800F3F88 8C420324 */  lw        $v0, 0x324($v0)
/* 8D43C 800F3F8C 256B0004 */  addiu     $t3, $t3, 4
/* 8D440 800F3F90 0242102A */  slt       $v0, $s2, $v0
/* 8D444 800F3F94 1440FF19 */  bnez      $v0, .L800F3BFC
/* 8D448 800F3F98 AFAB002C */   sw       $t3, 0x2c($sp)
.L800F3F9C:
/* 8D44C 800F3F9C 8FAA005C */  lw        $t2, 0x5c($sp)
/* 8D450 800F3FA0 3C028011 */  lui       $v0, %hi(D_8010D658)
/* 8D454 800F3FA4 8442D658 */  lh        $v0, %lo(D_8010D658)($v0)
/* 8D458 800F3FA8 8FAB0060 */  lw        $t3, 0x60($sp)
/* 8D45C 800F3FAC AFA00024 */  sw        $zero, 0x24($sp)
/* 8D460 800F3FB0 254A0018 */  addiu     $t2, $t2, 0x18
/* 8D464 800F3FB4 01622021 */  addu      $a0, $t3, $v0
/* 8D468 800F3FB8 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D46C 800F3FBC 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D470 800F3FC0 AFAA0020 */  sw        $t2, 0x20($sp)
/* 8D474 800F3FC4 8C430318 */  lw        $v1, 0x318($v0)
/* 8D478 800F3FC8 24020002 */  addiu     $v0, $zero, 2
/* 8D47C 800F3FCC 14620004 */  bne       $v1, $v0, .L800F3FE0
/* 8D480 800F3FD0 24910008 */   addiu    $s1, $a0, 8
/* 8D484 800F3FD4 24910006 */  addiu     $s1, $a0, 6
/* 8D488 800F3FD8 0040502D */  daddu     $t2, $v0, $zero
/* 8D48C 800F3FDC AFAA0024 */  sw        $t2, 0x24($sp)
.L800F3FE0:
/* 8D490 800F3FE0 2C62000E */  sltiu     $v0, $v1, 0xe
/* 8D494 800F3FE4 104000B2 */  beqz      $v0, .L800F42B0
/* 8D498 800F3FE8 00031080 */   sll      $v0, $v1, 2
/* 8D49C 800F3FEC 3C018011 */  lui       $at, %hi(jtbl_8010C800)
/* 8D4A0 800F3FF0 00220821 */  addu      $at, $at, $v0
/* 8D4A4 800F3FF4 8C22C800 */  lw        $v0, %lo(jtbl_8010C800)($at)
/* 8D4A8 800F3FF8 00400008 */  jr        $v0
/* 8D4AC 800F3FFC 00000000 */   nop
glabel L800F4000_8D4B0
/* 8D4B0 800F4000 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D4B4 800F4004 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D4B8 800F4008 8C420324 */  lw        $v0, 0x324($v0)
/* 8D4BC 800F400C 184000A8 */  blez      $v0, .L800F42B0
/* 8D4C0 800F4010 0000902D */   daddu    $s2, $zero, $zero
/* 8D4C4 800F4014 8FAB0028 */  lw        $t3, 0x28($sp)
/* 8D4C8 800F4018 2573FFFF */  addiu     $s3, $t3, -1
/* 8D4CC 800F401C 0253102A */  slt       $v0, $s2, $s3
.L800F4020:
/* 8D4D0 800F4020 14400008 */  bnez      $v0, .L800F4044
/* 8D4D4 800F4024 00000000 */   nop
/* 8D4D8 800F4028 3C028011 */  lui       $v0, %hi(D_8010D656)
/* 8D4DC 800F402C 8042D656 */  lb        $v0, %lo(D_8010D656)($v0)
/* 8D4E0 800F4030 8FAA0028 */  lw        $t2, 0x28($sp)
/* 8D4E4 800F4034 01421021 */  addu      $v0, $t2, $v0
/* 8D4E8 800F4038 0052102A */  slt       $v0, $v0, $s2
/* 8D4EC 800F403C 10400006 */  beqz      $v0, .L800F4058
/* 8D4F0 800F4040 00121880 */   sll      $v1, $s2, 2
.L800F4044:
/* 8D4F4 800F4044 1640001F */  bnez      $s2, .L800F40C4
/* 8D4F8 800F4048 2631000D */   addiu    $s1, $s1, 0xd
/* 8D4FC 800F404C 8FAB0024 */  lw        $t3, 0x24($sp)
/* 8D500 800F4050 0803D031 */  j         .L800F40C4
/* 8D504 800F4054 022B8821 */   addu     $s1, $s1, $t3
.L800F4058:
/* 8D508 800F4058 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D50C 800F405C 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D510 800F4060 3C108011 */  lui       $s0, %hi(D_8010D678)
/* 8D514 800F4064 8E10D678 */  lw        $s0, %lo(D_8010D678)($s0)
/* 8D518 800F4068 00431021 */  addu      $v0, $v0, $v1
/* 8D51C 800F406C 8C450000 */  lw        $a1, ($v0)
/* 8D520 800F4070 0C0511FF */  jal       set_menu_icon_script
/* 8D524 800F4074 0200202D */   daddu    $a0, $s0, $zero
/* 8D528 800F4078 0200202D */  daddu     $a0, $s0, $zero
/* 8D52C 800F407C 8FA50020 */  lw        $a1, 0x20($sp)
/* 8D530 800F4080 0C051261 */  jal       set_icon_render_pos
/* 8D534 800F4084 0220302D */   daddu    $a2, $s1, $zero
/* 8D538 800F4088 0200202D */  daddu     $a0, $s0, $zero
/* 8D53C 800F408C 3C058011 */  lui       $a1, %hi(D_8010D650)
/* 8D540 800F4090 8CA5D650 */  lw        $a1, %lo(D_8010D650)($a1)
/* 8D544 800F4094 0C0513AC */  jal       icon_set_opacity
/* 8D548 800F4098 2631000D */   addiu    $s1, $s1, 0xd
/* 8D54C 800F409C 3C053EE6 */  lui       $a1, 0x3ee6
/* 8D550 800F40A0 34A56666 */  ori       $a1, $a1, 0x6666
/* 8D554 800F40A4 0C051308 */  jal       func_80144C20
/* 8D558 800F40A8 0200202D */   daddu    $a0, $s0, $zero
/* 8D55C 800F40AC 0C0511F8 */  jal       draw_icon_2
/* 8D560 800F40B0 0200202D */   daddu    $a0, $s0, $zero
/* 8D564 800F40B4 16400003 */  bnez      $s2, .L800F40C4
/* 8D568 800F40B8 00000000 */   nop
/* 8D56C 800F40BC 8FAA0024 */  lw        $t2, 0x24($sp)
/* 8D570 800F40C0 022A8821 */  addu      $s1, $s1, $t2
.L800F40C4:
/* 8D574 800F40C4 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D578 800F40C8 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D57C 800F40CC 8C420324 */  lw        $v0, 0x324($v0)
/* 8D580 800F40D0 26520001 */  addiu     $s2, $s2, 1
/* 8D584 800F40D4 0242102A */  slt       $v0, $s2, $v0
/* 8D588 800F40D8 1440FFD1 */  bnez      $v0, .L800F4020
/* 8D58C 800F40DC 0253102A */   slt      $v0, $s2, $s3
/* 8D590 800F40E0 0803D0AC */  j         .L800F42B0
/* 8D594 800F40E4 00000000 */   nop
glabel L800F40E8_8D598
/* 8D598 800F40E8 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D59C 800F40EC 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D5A0 800F40F0 8C420324 */  lw        $v0, 0x324($v0)
/* 8D5A4 800F40F4 1840006E */  blez      $v0, .L800F42B0
/* 8D5A8 800F40F8 0000902D */   daddu    $s2, $zero, $zero
/* 8D5AC 800F40FC 8FAB0028 */  lw        $t3, 0x28($sp)
/* 8D5B0 800F4100 2573FFFF */  addiu     $s3, $t3, -1
/* 8D5B4 800F4104 0253102A */  slt       $v0, $s2, $s3
.L800F4108:
/* 8D5B8 800F4108 14400008 */  bnez      $v0, .L800F412C
/* 8D5BC 800F410C 00000000 */   nop
/* 8D5C0 800F4110 3C028011 */  lui       $v0, %hi(D_8010D656)
/* 8D5C4 800F4114 8042D656 */  lb        $v0, %lo(D_8010D656)($v0)
/* 8D5C8 800F4118 8FAA0028 */  lw        $t2, 0x28($sp)
/* 8D5CC 800F411C 01421021 */  addu      $v0, $t2, $v0
/* 8D5D0 800F4120 0052102A */  slt       $v0, $v0, $s2
/* 8D5D4 800F4124 10400006 */  beqz      $v0, .L800F4140
/* 8D5D8 800F4128 00121880 */   sll      $v1, $s2, 2
.L800F412C:
/* 8D5DC 800F412C 1640001F */  bnez      $s2, .L800F41AC
/* 8D5E0 800F4130 2631000D */   addiu    $s1, $s1, 0xd
/* 8D5E4 800F4134 8FAB0024 */  lw        $t3, 0x24($sp)
/* 8D5E8 800F4138 0803D06B */  j         .L800F41AC
/* 8D5EC 800F413C 022B8821 */   addu     $s1, $s1, $t3
.L800F4140:
/* 8D5F0 800F4140 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D5F4 800F4144 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D5F8 800F4148 3C108011 */  lui       $s0, %hi(D_8010D678)
/* 8D5FC 800F414C 8E10D678 */  lw        $s0, %lo(D_8010D678)($s0)
/* 8D600 800F4150 00431021 */  addu      $v0, $v0, $v1
/* 8D604 800F4154 8C450000 */  lw        $a1, ($v0)
/* 8D608 800F4158 0C0511FF */  jal       set_menu_icon_script
/* 8D60C 800F415C 0200202D */   daddu    $a0, $s0, $zero
/* 8D610 800F4160 0200202D */  daddu     $a0, $s0, $zero
/* 8D614 800F4164 8FA50020 */  lw        $a1, 0x20($sp)
/* 8D618 800F4168 0C051261 */  jal       set_icon_render_pos
/* 8D61C 800F416C 0220302D */   daddu    $a2, $s1, $zero
/* 8D620 800F4170 0200202D */  daddu     $a0, $s0, $zero
/* 8D624 800F4174 3C058011 */  lui       $a1, %hi(D_8010D650)
/* 8D628 800F4178 8CA5D650 */  lw        $a1, %lo(D_8010D650)($a1)
/* 8D62C 800F417C 0C0513AC */  jal       icon_set_opacity
/* 8D630 800F4180 2631000D */   addiu    $s1, $s1, 0xd
/* 8D634 800F4184 3C053EE6 */  lui       $a1, 0x3ee6
/* 8D638 800F4188 34A56666 */  ori       $a1, $a1, 0x6666
/* 8D63C 800F418C 0C051308 */  jal       func_80144C20
/* 8D640 800F4190 0200202D */   daddu    $a0, $s0, $zero
/* 8D644 800F4194 0C0511F8 */  jal       draw_icon_2
/* 8D648 800F4198 0200202D */   daddu    $a0, $s0, $zero
/* 8D64C 800F419C 16400003 */  bnez      $s2, .L800F41AC
/* 8D650 800F41A0 00000000 */   nop
/* 8D654 800F41A4 8FAA0024 */  lw        $t2, 0x24($sp)
/* 8D658 800F41A8 022A8821 */  addu      $s1, $s1, $t2
.L800F41AC:
/* 8D65C 800F41AC 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D660 800F41B0 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D664 800F41B4 8C420324 */  lw        $v0, 0x324($v0)
/* 8D668 800F41B8 26520001 */  addiu     $s2, $s2, 1
/* 8D66C 800F41BC 0242102A */  slt       $v0, $s2, $v0
/* 8D670 800F41C0 1440FFD1 */  bnez      $v0, .L800F4108
/* 8D674 800F41C4 0253102A */   slt      $v0, $s2, $s3
/* 8D678 800F41C8 0803D0AC */  j         .L800F42B0
/* 8D67C 800F41CC 00000000 */   nop
glabel L800F41D0_8D680
/* 8D680 800F41D0 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D684 800F41D4 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D688 800F41D8 8C420324 */  lw        $v0, 0x324($v0)
/* 8D68C 800F41DC 18400034 */  blez      $v0, .L800F42B0
/* 8D690 800F41E0 0000902D */   daddu    $s2, $zero, $zero
/* 8D694 800F41E4 8FAB0028 */  lw        $t3, 0x28($sp)
/* 8D698 800F41E8 2573FFFF */  addiu     $s3, $t3, -1
/* 8D69C 800F41EC 0253102A */  slt       $v0, $s2, $s3
.L800F41F0:
/* 8D6A0 800F41F0 14400008 */  bnez      $v0, .L800F4214
/* 8D6A4 800F41F4 00000000 */   nop
/* 8D6A8 800F41F8 3C028011 */  lui       $v0, %hi(D_8010D656)
/* 8D6AC 800F41FC 8042D656 */  lb        $v0, %lo(D_8010D656)($v0)
/* 8D6B0 800F4200 8FAA0028 */  lw        $t2, 0x28($sp)
/* 8D6B4 800F4204 01421021 */  addu      $v0, $t2, $v0
/* 8D6B8 800F4208 0052102A */  slt       $v0, $v0, $s2
/* 8D6BC 800F420C 10400006 */  beqz      $v0, .L800F4228
/* 8D6C0 800F4210 00121880 */   sll      $v1, $s2, 2
.L800F4214:
/* 8D6C4 800F4214 1640001F */  bnez      $s2, .L800F4294
/* 8D6C8 800F4218 2631000D */   addiu    $s1, $s1, 0xd
/* 8D6CC 800F421C 8FAB0024 */  lw        $t3, 0x24($sp)
/* 8D6D0 800F4220 0803D0A5 */  j         .L800F4294
/* 8D6D4 800F4224 022B8821 */   addu     $s1, $s1, $t3
.L800F4228:
/* 8D6D8 800F4228 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D6DC 800F422C 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D6E0 800F4230 3C108011 */  lui       $s0, %hi(D_8010D678)
/* 8D6E4 800F4234 8E10D678 */  lw        $s0, %lo(D_8010D678)($s0)
/* 8D6E8 800F4238 00431021 */  addu      $v0, $v0, $v1
/* 8D6EC 800F423C 8C450000 */  lw        $a1, ($v0)
/* 8D6F0 800F4240 0C0511FF */  jal       set_menu_icon_script
/* 8D6F4 800F4244 0200202D */   daddu    $a0, $s0, $zero
/* 8D6F8 800F4248 0200202D */  daddu     $a0, $s0, $zero
/* 8D6FC 800F424C 8FA50020 */  lw        $a1, 0x20($sp)
/* 8D700 800F4250 0C051261 */  jal       set_icon_render_pos
/* 8D704 800F4254 0220302D */   daddu    $a2, $s1, $zero
/* 8D708 800F4258 0200202D */  daddu     $a0, $s0, $zero
/* 8D70C 800F425C 3C058011 */  lui       $a1, %hi(D_8010D650)
/* 8D710 800F4260 8CA5D650 */  lw        $a1, %lo(D_8010D650)($a1)
/* 8D714 800F4264 0C0513AC */  jal       icon_set_opacity
/* 8D718 800F4268 2631000D */   addiu    $s1, $s1, 0xd
/* 8D71C 800F426C 3C053EE6 */  lui       $a1, 0x3ee6
/* 8D720 800F4270 34A56666 */  ori       $a1, $a1, 0x6666
/* 8D724 800F4274 0C051308 */  jal       func_80144C20
/* 8D728 800F4278 0200202D */   daddu    $a0, $s0, $zero
/* 8D72C 800F427C 0C0511F8 */  jal       draw_icon_2
/* 8D730 800F4280 0200202D */   daddu    $a0, $s0, $zero
/* 8D734 800F4284 16400003 */  bnez      $s2, .L800F4294
/* 8D738 800F4288 00000000 */   nop
/* 8D73C 800F428C 8FAA0024 */  lw        $t2, 0x24($sp)
/* 8D740 800F4290 022A8821 */  addu      $s1, $s1, $t2
.L800F4294:
/* 8D744 800F4294 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D748 800F4298 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D74C 800F429C 8C420324 */  lw        $v0, 0x324($v0)
/* 8D750 800F42A0 26520001 */  addiu     $s2, $s2, 1
/* 8D754 800F42A4 0242102A */  slt       $v0, $s2, $v0
/* 8D758 800F42A8 1440FFD1 */  bnez      $v0, .L800F41F0
/* 8D75C 800F42AC 0253102A */   slt      $v0, $s2, $s3
.L800F42B0:
/* 8D760 800F42B0 8FAB005C */  lw        $t3, 0x5c($sp)
/* 8D764 800F42B4 3C038011 */  lui       $v1, %hi(D_8010D654)
/* 8D768 800F42B8 8063D654 */  lb        $v1, %lo(D_8010D654)($v1)
/* 8D76C 800F42BC 3C048011 */  lui       $a0, %hi(D_8010D648)
/* 8D770 800F42C0 8C84D648 */  lw        $a0, %lo(D_8010D648)($a0)
/* 8D774 800F42C4 3C108011 */  lui       $s0, %hi(D_8010D66C)
/* 8D778 800F42C8 8E10D66C */  lw        $s0, %lo(D_8010D66C)($s0)
/* 8D77C 800F42CC 8FAA0060 */  lw        $t2, 0x60($sp)
/* 8D780 800F42D0 256B0008 */  addiu     $t3, $t3, 8
/* 8D784 800F42D4 00831823 */  subu      $v1, $a0, $v1
/* 8D788 800F42D8 00031040 */  sll       $v0, $v1, 1
/* 8D78C 800F42DC 00431021 */  addu      $v0, $v0, $v1
/* 8D790 800F42E0 00021080 */  sll       $v0, $v0, 2
/* 8D794 800F42E4 00431021 */  addu      $v0, $v0, $v1
/* 8D798 800F42E8 24420009 */  addiu     $v0, $v0, 9
/* 8D79C 800F42EC 3C038011 */  lui       $v1, %hi(D_8010D69C)
/* 8D7A0 800F42F0 8C63D69C */  lw        $v1, %lo(D_8010D69C)($v1)
/* 8D7A4 800F42F4 01428821 */  addu      $s1, $t2, $v0
/* 8D7A8 800F42F8 AFAB0020 */  sw        $t3, 0x20($sp)
/* 8D7AC 800F42FC 8C630318 */  lw        $v1, 0x318($v1)
/* 8D7B0 800F4300 24020002 */  addiu     $v0, $zero, 2
/* 8D7B4 800F4304 54620004 */  bnel      $v1, $v0, .L800F4318
/* 8D7B8 800F4308 0200202D */   daddu    $a0, $s0, $zero
/* 8D7BC 800F430C 50800001 */  beql      $a0, $zero, .L800F4314
/* 8D7C0 800F4310 2631FFFE */   addiu    $s1, $s1, -2
.L800F4314:
/* 8D7C4 800F4314 0200202D */  daddu     $a0, $s0, $zero
.L800F4318:
/* 8D7C8 800F4318 8FA50020 */  lw        $a1, 0x20($sp)
/* 8D7CC 800F431C 0C051261 */  jal       set_icon_render_pos
/* 8D7D0 800F4320 0220302D */   daddu    $a2, $s1, $zero
/* 8D7D4 800F4324 3C058011 */  lui       $a1, %hi(D_8010D650)
/* 8D7D8 800F4328 8CA5D650 */  lw        $a1, %lo(D_8010D650)($a1)
/* 8D7DC 800F432C 0C0513AC */  jal       icon_set_opacity
/* 8D7E0 800F4330 0200202D */   daddu    $a0, $s0, $zero
/* 8D7E4 800F4334 0C0511F8 */  jal       draw_icon_2
/* 8D7E8 800F4338 0200202D */   daddu    $a0, $s0, $zero
/* 8D7EC 800F433C 8FAB005C */  lw        $t3, 0x5c($sp)
/* 8D7F0 800F4340 8FAA0060 */  lw        $t2, 0x60($sp)
/* 8D7F4 800F4344 3C038011 */  lui       $v1, %hi(D_8010D656)
/* 8D7F8 800F4348 8063D656 */  lb        $v1, %lo(D_8010D656)($v1)
/* 8D7FC 800F434C 2551FFFA */  addiu     $s1, $t2, -6
/* 8D800 800F4350 00031040 */  sll       $v0, $v1, 1
/* 8D804 800F4354 00431021 */  addu      $v0, $v0, $v1
/* 8D808 800F4358 00021080 */  sll       $v0, $v0, 2
/* 8D80C 800F435C 00431021 */  addu      $v0, $v0, $v1
/* 8D810 800F4360 3C038011 */  lui       $v1, %hi(D_8010D69C)
/* 8D814 800F4364 8C63D69C */  lw        $v1, %lo(D_8010D69C)($v1)
/* 8D818 800F4368 02221021 */  addu      $v0, $s1, $v0
/* 8D81C 800F436C AFAB0020 */  sw        $t3, 0x20($sp)
/* 8D820 800F4370 8C630318 */  lw        $v1, 0x318($v1)
/* 8D824 800F4374 24480010 */  addiu     $t0, $v0, 0x10
/* 8D828 800F4378 2C62000E */  sltiu     $v0, $v1, 0xe
/* 8D82C 800F437C 1040004F */  beqz      $v0, .L800F44BC
/* 8D830 800F4380 00031080 */   sll      $v0, $v1, 2
/* 8D834 800F4384 3C018011 */  lui       $at, %hi(jtbl_8010C838)
/* 8D838 800F4388 00220821 */  addu      $at, $at, $v0
/* 8D83C 800F438C 8C22C838 */  lw        $v0, %lo(jtbl_8010C838)($at)
/* 8D840 800F4390 00400008 */  jr        $v0
/* 8D844 800F4394 00000000 */   nop
glabel L800F4398_8D848
/* 8D848 800F4398 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 8D84C 800F439C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 8D850 800F43A0 C7A20020 */  lwc1      $f2, 0x20($sp)
/* 8D854 800F43A4 468010A0 */  cvt.s.w   $f2, $f2
/* 8D858 800F43A8 44910000 */  mtc1      $s1, $f0
/* 8D85C 800F43AC 00000000 */  nop
/* 8D860 800F43B0 46800020 */  cvt.s.w   $f0, $f0
/* 8D864 800F43B4 3C014080 */  lui       $at, 0x4080
/* 8D868 800F43B8 44812000 */  mtc1      $at, $f4
/* 8D86C 800F43BC 8C620000 */  lw        $v0, ($v1)
/* 8D870 800F43C0 46041082 */  mul.s     $f2, $f2, $f4
/* 8D874 800F43C4 00000000 */  nop
/* 8D878 800F43C8 0040282D */  daddu     $a1, $v0, $zero
/* 8D87C 800F43CC 24420008 */  addiu     $v0, $v0, 8
/* 8D880 800F43D0 AC620000 */  sw        $v0, ($v1)
/* 8D884 800F43D4 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8D888 800F43D8 46040002 */  mul.s     $f0, $f0, $f4
/* 8D88C 800F43DC 00000000 */  nop
/* 8D890 800F43E0 0803D10D */  j         .L800F4434
/* 8D894 800F43E4 25620070 */   addiu    $v0, $t3, 0x70
glabel L800F43E8_8D898
/* 8D898 800F43E8 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 8D89C 800F43EC 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 8D8A0 800F43F0 C7A20020 */  lwc1      $f2, 0x20($sp)
/* 8D8A4 800F43F4 468010A0 */  cvt.s.w   $f2, $f2
/* 8D8A8 800F43F8 44910000 */  mtc1      $s1, $f0
/* 8D8AC 800F43FC 00000000 */  nop
/* 8D8B0 800F4400 46800020 */  cvt.s.w   $f0, $f0
/* 8D8B4 800F4404 3C014080 */  lui       $at, 0x4080
/* 8D8B8 800F4408 44812000 */  mtc1      $at, $f4
/* 8D8BC 800F440C 8C620000 */  lw        $v0, ($v1)
/* 8D8C0 800F4410 46041082 */  mul.s     $f2, $f2, $f4
/* 8D8C4 800F4414 00000000 */  nop
/* 8D8C8 800F4418 0040282D */  daddu     $a1, $v0, $zero
/* 8D8CC 800F441C 24420008 */  addiu     $v0, $v0, 8
/* 8D8D0 800F4420 AC620000 */  sw        $v0, ($v1)
/* 8D8D4 800F4424 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8D8D8 800F4428 46040002 */  mul.s     $f0, $f0, $f4
/* 8D8DC 800F442C 00000000 */  nop
/* 8D8E0 800F4430 25620064 */  addiu     $v0, $t3, 0x64
.L800F4434:
/* 8D8E4 800F4434 4600118D */  trunc.w.s $f6, $f2
/* 8D8E8 800F4438 44033000 */  mfc1      $v1, $f6
/* 8D8EC 800F443C 00000000 */  nop
/* 8D8F0 800F4440 30630FFF */  andi      $v1, $v1, 0xfff
/* 8D8F4 800F4444 00031B00 */  sll       $v1, $v1, 0xc
/* 8D8F8 800F4448 4600018D */  trunc.w.s $f6, $f0
/* 8D8FC 800F444C 44043000 */  mfc1      $a0, $f6
/* 8D900 800F4450 00000000 */  nop
/* 8D904 800F4454 30840FFF */  andi      $a0, $a0, 0xfff
/* 8D908 800F4458 44821000 */  mtc1      $v0, $f2
/* 8D90C 800F445C 00000000 */  nop
/* 8D910 800F4460 468010A0 */  cvt.s.w   $f2, $f2
/* 8D914 800F4464 46041082 */  mul.s     $f2, $f2, $f4
/* 8D918 800F4468 00000000 */  nop
/* 8D91C 800F446C 3C02ED00 */  lui       $v0, 0xed00
/* 8D920 800F4470 00822025 */  or        $a0, $a0, $v0
/* 8D924 800F4474 00641825 */  or        $v1, $v1, $a0
/* 8D928 800F4478 44880000 */  mtc1      $t0, $f0
/* 8D92C 800F447C 00000000 */  nop
/* 8D930 800F4480 46800020 */  cvt.s.w   $f0, $f0
/* 8D934 800F4484 46040002 */  mul.s     $f0, $f0, $f4
/* 8D938 800F4488 00000000 */  nop
/* 8D93C 800F448C ACA30000 */  sw        $v1, ($a1)
/* 8D940 800F4490 4600118D */  trunc.w.s $f6, $f2
/* 8D944 800F4494 44023000 */  mfc1      $v0, $f6
/* 8D948 800F4498 00000000 */  nop
/* 8D94C 800F449C 30420FFF */  andi      $v0, $v0, 0xfff
/* 8D950 800F44A0 00021300 */  sll       $v0, $v0, 0xc
/* 8D954 800F44A4 4600018D */  trunc.w.s $f6, $f0
/* 8D958 800F44A8 44033000 */  mfc1      $v1, $f6
/* 8D95C 800F44AC 00000000 */  nop
/* 8D960 800F44B0 30630FFF */  andi      $v1, $v1, 0xfff
/* 8D964 800F44B4 00431025 */  or        $v0, $v0, $v1
/* 8D968 800F44B8 ACA20004 */  sw        $v0, 4($a1)
.L800F44BC:
/* 8D96C 800F44BC 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8D970 800F44C0 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8D974 800F44C4 8C420318 */  lw        $v0, 0x318($v0)
/* 8D978 800F44C8 2443FFFF */  addiu     $v1, $v0, -1
/* 8D97C 800F44CC 2C62000D */  sltiu     $v0, $v1, 0xd
/* 8D980 800F44D0 10400012 */  beqz      $v0, .L800F451C
/* 8D984 800F44D4 00031080 */   sll      $v0, $v1, 2
/* 8D988 800F44D8 3C018011 */  lui       $at, %hi(jtbl_8010C870)
/* 8D98C 800F44DC 00220821 */  addu      $at, $at, $v0
/* 8D990 800F44E0 8C22C870 */  lw        $v0, %lo(jtbl_8010C870)($at)
/* 8D994 800F44E4 00400008 */  jr        $v0
/* 8D998 800F44E8 00000000 */   nop
glabel L800F44EC_8D99C
/* 8D99C 800F44EC 0803D150 */  j         .L800F4540
/* 8D9A0 800F44F0 240B0023 */   addiu    $t3, $zero, 0x23
glabel L800F44F4_8D9A4
/* 8D9A4 800F44F4 240A0023 */  addiu     $t2, $zero, 0x23
/* 8D9A8 800F44F8 0803D151 */  j         .L800F4544
/* 8D9AC 800F44FC AFAA0024 */   sw       $t2, 0x24($sp)
glabel L800F4500_8D9B0
/* 8D9B0 800F4500 0803D150 */  j         .L800F4540
/* 8D9B4 800F4504 240B001F */   addiu    $t3, $zero, 0x1f
glabel L800F4508_8D9B8
/* 8D9B8 800F4508 240A001F */  addiu     $t2, $zero, 0x1f
/* 8D9BC 800F450C 0803D151 */  j         .L800F4544
/* 8D9C0 800F4510 AFAA0024 */   sw       $t2, 0x24($sp)
glabel L800F4514_8D9C4
/* 8D9C4 800F4514 0803D150 */  j         .L800F4540
/* 8D9C8 800F4518 240B001F */   addiu    $t3, $zero, 0x1f
.L800F451C:
glabel L800F451C_8D9CC
/* 8D9CC 800F451C 240A0025 */  addiu     $t2, $zero, 0x25
/* 8D9D0 800F4520 0803D151 */  j         .L800F4544
/* 8D9D4 800F4524 AFAA0024 */   sw       $t2, 0x24($sp)
glabel L800F4528_8D9D8
/* 8D9D8 800F4528 0803D150 */  j         .L800F4540
/* 8D9DC 800F452C 240B001D */   addiu    $t3, $zero, 0x1d
glabel L800F4530_8D9E0
/* 8D9E0 800F4530 240A0015 */  addiu     $t2, $zero, 0x15
/* 8D9E4 800F4534 0803D151 */  j         .L800F4544
/* 8D9E8 800F4538 AFAA0024 */   sw       $t2, 0x24($sp)
glabel L800F453C_8D9EC
/* 8D9EC 800F453C 240B001E */  addiu     $t3, $zero, 0x1e
.L800F4540:
/* 8D9F0 800F4540 AFAB0024 */  sw        $t3, 0x24($sp)
.L800F4544:
/* 8D9F4 800F4544 3C028011 */  lui       $v0, %hi(D_8010D654)
/* 8D9F8 800F4548 8042D654 */  lb        $v0, %lo(D_8010D654)($v0)
/* 8D9FC 800F454C 18400012 */  blez      $v0, .L800F4598
/* 8DA00 800F4550 00000000 */   nop
/* 8DA04 800F4554 8FAA005C */  lw        $t2, 0x5c($sp)
/* 8DA08 800F4558 8FAB0024 */  lw        $t3, 0x24($sp)
/* 8DA0C 800F455C 3C108011 */  lui       $s0, %hi(D_8010D670)
/* 8DA10 800F4560 8E10D670 */  lw        $s0, %lo(D_8010D670)($s0)
/* 8DA14 800F4564 014B5021 */  addu      $t2, $t2, $t3
/* 8DA18 800F4568 AFAA0020 */  sw        $t2, 0x20($sp)
/* 8DA1C 800F456C 25450023 */  addiu     $a1, $t2, 0x23
/* 8DA20 800F4570 8FAA0060 */  lw        $t2, 0x60($sp)
/* 8DA24 800F4574 0200202D */  daddu     $a0, $s0, $zero
/* 8DA28 800F4578 0C051261 */  jal       set_icon_render_pos
/* 8DA2C 800F457C 2546FFFF */   addiu    $a2, $t2, -1
/* 8DA30 800F4580 3C058011 */  lui       $a1, %hi(D_8010D650)
/* 8DA34 800F4584 8CA5D650 */  lw        $a1, %lo(D_8010D650)($a1)
/* 8DA38 800F4588 0C0513AC */  jal       icon_set_opacity
/* 8DA3C 800F458C 0200202D */   daddu    $a0, $s0, $zero
/* 8DA40 800F4590 0C0511F8 */  jal       draw_icon_2
/* 8DA44 800F4594 0200202D */   daddu    $a0, $s0, $zero
.L800F4598:
/* 8DA48 800F4598 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8DA4C 800F459C 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8DA50 800F45A0 3C038011 */  lui       $v1, %hi(D_8010D655)
/* 8DA54 800F45A4 8063D655 */  lb        $v1, %lo(D_8010D655)($v1)
/* 8DA58 800F45A8 8C420324 */  lw        $v0, 0x324($v0)
/* 8DA5C 800F45AC 0062182A */  slt       $v1, $v1, $v0
/* 8DA60 800F45B0 10600019 */  beqz      $v1, .L800F4618
/* 8DA64 800F45B4 00000000 */   nop
/* 8DA68 800F45B8 8FAB005C */  lw        $t3, 0x5c($sp)
/* 8DA6C 800F45BC 8FAA0024 */  lw        $t2, 0x24($sp)
/* 8DA70 800F45C0 3C038011 */  lui       $v1, %hi(D_8010D68F)
/* 8DA74 800F45C4 8063D68F */  lb        $v1, %lo(D_8010D68F)($v1)
/* 8DA78 800F45C8 3C108011 */  lui       $s0, %hi(D_8010D674)
/* 8DA7C 800F45CC 8E10D674 */  lw        $s0, %lo(D_8010D674)($s0)
/* 8DA80 800F45D0 016A5821 */  addu      $t3, $t3, $t2
/* 8DA84 800F45D4 AFAB0020 */  sw        $t3, 0x20($sp)
/* 8DA88 800F45D8 25650023 */  addiu     $a1, $t3, 0x23
/* 8DA8C 800F45DC 00031040 */  sll       $v0, $v1, 1
/* 8DA90 800F45E0 00431021 */  addu      $v0, $v0, $v1
/* 8DA94 800F45E4 00021080 */  sll       $v0, $v0, 2
/* 8DA98 800F45E8 00431021 */  addu      $v0, $v0, $v1
/* 8DA9C 800F45EC 8FAB0060 */  lw        $t3, 0x60($sp)
/* 8DAA0 800F45F0 0200202D */  daddu     $a0, $s0, $zero
/* 8DAA4 800F45F4 01628821 */  addu      $s1, $t3, $v0
/* 8DAA8 800F45F8 0C051261 */  jal       set_icon_render_pos
/* 8DAAC 800F45FC 26260005 */   addiu    $a2, $s1, 5
/* 8DAB0 800F4600 3C058011 */  lui       $a1, %hi(D_8010D650)
/* 8DAB4 800F4604 8CA5D650 */  lw        $a1, %lo(D_8010D650)($a1)
/* 8DAB8 800F4608 0C0513AC */  jal       icon_set_opacity
/* 8DABC 800F460C 0200202D */   daddu    $a0, $s0, $zero
/* 8DAC0 800F4610 0C0511F8 */  jal       draw_icon_2
/* 8DAC4 800F4614 0200202D */   daddu    $a0, $s0, $zero
.L800F4618:
/* 8DAC8 800F4618 8FBF0054 */  lw        $ra, 0x54($sp)
/* 8DACC 800F461C 8FBE0050 */  lw        $fp, 0x50($sp)
/* 8DAD0 800F4620 8FB7004C */  lw        $s7, 0x4c($sp)
/* 8DAD4 800F4624 8FB60048 */  lw        $s6, 0x48($sp)
/* 8DAD8 800F4628 8FB50044 */  lw        $s5, 0x44($sp)
/* 8DADC 800F462C 8FB40040 */  lw        $s4, 0x40($sp)
/* 8DAE0 800F4630 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8DAE4 800F4634 8FB20038 */  lw        $s2, 0x38($sp)
/* 8DAE8 800F4638 8FB10034 */  lw        $s1, 0x34($sp)
/* 8DAEC 800F463C 8FB00030 */  lw        $s0, 0x30($sp)
/* 8DAF0 800F4640 03E00008 */  jr        $ra
/* 8DAF4 800F4644 27BD0058 */   addiu    $sp, $sp, 0x58
