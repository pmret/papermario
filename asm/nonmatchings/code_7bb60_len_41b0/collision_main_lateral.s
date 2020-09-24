.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel collision_main_lateral
/* 7CAEC 800E363C 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 7CAF0 800E3640 AFB1005C */  sw        $s1, 0x5c($sp)
/* 7CAF4 800E3644 3C118011 */  lui       $s1, 0x8011
/* 7CAF8 800E3648 2631EFC8 */  addiu     $s1, $s1, -0x1038
/* 7CAFC 800E364C AFB40068 */  sw        $s4, 0x68($sp)
/* 7CB00 800E3650 3C148016 */  lui       $s4, 0x8016
/* 7CB04 800E3654 2694A550 */  addiu     $s4, $s4, -0x5ab0
/* 7CB08 800E3658 AFBF006C */  sw        $ra, 0x6c($sp)
/* 7CB0C 800E365C AFB30064 */  sw        $s3, 0x64($sp)
/* 7CB10 800E3660 AFB20060 */  sw        $s2, 0x60($sp)
/* 7CB14 800E3664 AFB00058 */  sw        $s0, 0x58($sp)
/* 7CB18 800E3668 F7B60078 */  sdc1      $f22, 0x78($sp)
/* 7CB1C 800E366C F7B40070 */  sdc1      $f20, 0x70($sp)
/* 7CB20 800E3670 8E230000 */  lw        $v1, ($s1)
/* 7CB24 800E3674 2402FFFF */  addiu     $v0, $zero, -1
/* 7CB28 800E3678 A6820000 */  sh        $v0, ($s4)
/* 7CB2C 800E367C 30624000 */  andi      $v0, $v1, 0x4000
/* 7CB30 800E3680 10400012 */  beqz      $v0, .L800E36CC
/* 7CB34 800E3684 3C020004 */   lui      $v0, 4
/* 7CB38 800E3688 C6220054 */  lwc1      $f2, 0x54($s1)
/* 7CB3C 800E368C 00621024 */  and       $v0, $v1, $v0
/* 7CB40 800E3690 10400007 */  beqz      $v0, .L800E36B0
/* 7CB44 800E3694 E7A20030 */   swc1     $f2, 0x30($sp)
/* 7CB48 800E3698 3C013F00 */  lui       $at, 0x3f00
/* 7CB4C 800E369C 44810000 */  mtc1      $at, $f0
/* 7CB50 800E36A0 00000000 */  nop       
/* 7CB54 800E36A4 46001002 */  mul.s     $f0, $f2, $f0
/* 7CB58 800E36A8 00000000 */  nop       
/* 7CB5C 800E36AC E7A00030 */  swc1      $f0, 0x30($sp)
.L800E36B0:
/* 7CB60 800E36B0 26240028 */  addiu     $a0, $s1, 0x28
/* 7CB64 800E36B4 8FA60030 */  lw        $a2, 0x30($sp)
/* 7CB68 800E36B8 8E2700A0 */  lw        $a3, 0xa0($s1)
/* 7CB6C 800E36BC 0C00A7E7 */  jal       add_vec2D_polar
/* 7CB70 800E36C0 26250030 */   addiu    $a1, $s1, 0x30
/* 7CB74 800E36C4 080390B8 */  j         .L800E42E0
/* 7CB78 800E36C8 00000000 */   nop      
.L800E36CC:
/* 7CB7C 800E36CC 922200B4 */  lbu       $v0, 0xb4($s1)
/* 7CB80 800E36D0 2442FFF9 */  addiu     $v0, $v0, -7
/* 7CB84 800E36D4 00021600 */  sll       $v0, $v0, 0x18
/* 7CB88 800E36D8 00021E03 */  sra       $v1, $v0, 0x18
/* 7CB8C 800E36DC 2C620020 */  sltiu     $v0, $v1, 0x20
/* 7CB90 800E36E0 1040010D */  beqz      $v0, .L800E3B18
/* 7CB94 800E36E4 00031080 */   sll      $v0, $v1, 2
/* 7CB98 800E36E8 3C018011 */  lui       $at, 0x8011
/* 7CB9C 800E36EC 00220821 */  addu      $at, $at, $v0
/* 7CBA0 800E36F0 8C22BE58 */  lw        $v0, -0x41a8($at)
/* 7CBA4 800E36F4 00400008 */  jr        $v0
/* 7CBA8 800E36F8 00000000 */   nop      
/* 7CBAC 800E36FC 3C038007 */  lui       $v1, 0x8007
/* 7CBB0 800E3700 8C637410 */  lw        $v1, 0x7410($v1)
/* 7CBB4 800E3704 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* 7CBB8 800E3708 3C0142B4 */  lui       $at, 0x42b4
/* 7CBBC 800E370C 44810000 */  mtc1      $at, $f0
/* 7CBC0 800E3710 00031080 */  sll       $v0, $v1, 2
/* 7CBC4 800E3714 00431021 */  addu      $v0, $v0, $v1
/* 7CBC8 800E3718 00021080 */  sll       $v0, $v0, 2
/* 7CBCC 800E371C 00431023 */  subu      $v0, $v0, $v1
/* 7CBD0 800E3720 000218C0 */  sll       $v1, $v0, 3
/* 7CBD4 800E3724 00431021 */  addu      $v0, $v0, $v1
/* 7CBD8 800E3728 000210C0 */  sll       $v0, $v0, 3
/* 7CBDC 800E372C 46001081 */  sub.s     $f2, $f2, $f0
/* 7CBE0 800E3730 3C01800B */  lui       $at, 0x800b
/* 7CBE4 800E3734 00220821 */  addu      $at, $at, $v0
/* 7CBE8 800E3738 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 7CBEC 800E373C 46001080 */  add.s     $f2, $f2, $f0
/* 7CBF0 800E3740 0000202D */  daddu     $a0, $zero, $zero
/* 7CBF4 800E3744 44061000 */  mfc1      $a2, $f2
/* 7CBF8 800E3748 080390B6 */  j         .L800E42D8
/* 7CBFC 800E374C 0080282D */   daddu    $a1, $a0, $zero
/* 7CC00 800E3750 0C039422 */  jal       get_current_partner_id
/* 7CC04 800E3754 00000000 */   nop      
/* 7CC08 800E3758 00021600 */  sll       $v0, $v0, 0x18
/* 7CC0C 800E375C 00021603 */  sra       $v0, $v0, 0x18
/* 7CC10 800E3760 24030009 */  addiu     $v1, $zero, 9
/* 7CC14 800E3764 144302DE */  bne       $v0, $v1, .L800E42E0
/* 7CC18 800E3768 00000000 */   nop      
/* 7CC1C 800E376C C6260028 */  lwc1      $f6, 0x28($s1)
/* 7CC20 800E3770 C620001C */  lwc1      $f0, 0x1c($s1)
/* 7CC24 800E3774 C624002C */  lwc1      $f4, 0x2c($s1)
/* 7CC28 800E3778 C628001C */  lwc1      $f8, 0x1c($s1)
/* 7CC2C 800E377C 46003180 */  add.s     $f6, $f6, $f0
/* 7CC30 800E3780 C6200020 */  lwc1      $f0, 0x20($s1)
/* 7CC34 800E3784 44805000 */  mtc1      $zero, $f10
/* 7CC38 800E3788 46002100 */  add.s     $f4, $f4, $f0
/* 7CC3C 800E378C C6220024 */  lwc1      $f2, 0x24($s1)
/* 7CC40 800E3790 C6200030 */  lwc1      $f0, 0x30($s1)
/* 7CC44 800E3794 460A4032 */  c.eq.s    $f8, $f10
/* 7CC48 800E3798 46020000 */  add.s     $f0, $f0, $f2
/* 7CC4C 800E379C E6260028 */  swc1      $f6, 0x28($s1)
/* 7CC50 800E37A0 E624002C */  swc1      $f4, 0x2c($s1)
/* 7CC54 800E37A4 4500000A */  bc1f      .L800E37D0
/* 7CC58 800E37A8 E6200030 */   swc1     $f0, 0x30($s1)
/* 7CC5C 800E37AC C6200020 */  lwc1      $f0, 0x20($s1)
/* 7CC60 800E37B0 460A0032 */  c.eq.s    $f0, $f10
/* 7CC64 800E37B4 00000000 */  nop       
/* 7CC68 800E37B8 45000005 */  bc1f      .L800E37D0
/* 7CC6C 800E37BC 46001006 */   mov.s    $f0, $f2
/* 7CC70 800E37C0 460A0032 */  c.eq.s    $f0, $f10
/* 7CC74 800E37C4 00000000 */  nop       
/* 7CC78 800E37C8 450102C5 */  bc1t      .L800E42E0
/* 7CC7C 800E37CC 00000000 */   nop      
.L800E37D0:
/* 7CC80 800E37D0 C6200028 */  lwc1      $f0, 0x28($s1)
/* 7CC84 800E37D4 C622002C */  lwc1      $f2, 0x2c($s1)
/* 7CC88 800E37D8 C6240030 */  lwc1      $f4, 0x30($s1)
/* 7CC8C 800E37DC 3C02800B */  lui       $v0, 0x800b
/* 7CC90 800E37E0 24421D80 */  addiu     $v0, $v0, 0x1d80
/* 7CC94 800E37E4 E4400060 */  swc1      $f0, 0x60($v0)
/* 7CC98 800E37E8 E4420064 */  swc1      $f2, 0x64($v0)
/* 7CC9C 800E37EC E4440068 */  swc1      $f4, 0x68($v0)
/* 7CCA0 800E37F0 9223000E */  lbu       $v1, 0xe($s1)
/* 7CCA4 800E37F4 24020080 */  addiu     $v0, $zero, 0x80
/* 7CCA8 800E37F8 106202B9 */  beq       $v1, $v0, .L800E42E0
/* 7CCAC 800E37FC 00000000 */   nop      
/* 7CCB0 800E3800 8E26001C */  lw        $a2, 0x1c($s1)
/* 7CCB4 800E3804 44806000 */  mtc1      $zero, $f12
/* 7CCB8 800E3808 8E270024 */  lw        $a3, 0x24($s1)
/* 7CCBC 800E380C 0C00A720 */  jal       atan2
/* 7CCC0 800E3810 46006386 */   mov.s    $f14, $f12
/* 7CCC4 800E3814 0000202D */  daddu     $a0, $zero, $zero
/* 7CCC8 800E3818 44060000 */  mfc1      $a2, $f0
/* 7CCCC 800E381C 080390B6 */  j         .L800E42D8
/* 7CCD0 800E3820 0080282D */   daddu    $a1, $a0, $zero
/* 7CCD4 800E3824 C6260028 */  lwc1      $f6, 0x28($s1)
/* 7CCD8 800E3828 C620001C */  lwc1      $f0, 0x1c($s1)
/* 7CCDC 800E382C C624002C */  lwc1      $f4, 0x2c($s1)
/* 7CCE0 800E3830 C628001C */  lwc1      $f8, 0x1c($s1)
/* 7CCE4 800E3834 46003180 */  add.s     $f6, $f6, $f0
/* 7CCE8 800E3838 C6200020 */  lwc1      $f0, 0x20($s1)
/* 7CCEC 800E383C 44805000 */  mtc1      $zero, $f10
/* 7CCF0 800E3840 46002100 */  add.s     $f4, $f4, $f0
/* 7CCF4 800E3844 C6220024 */  lwc1      $f2, 0x24($s1)
/* 7CCF8 800E3848 C6200030 */  lwc1      $f0, 0x30($s1)
/* 7CCFC 800E384C 460A4032 */  c.eq.s    $f8, $f10
/* 7CD00 800E3850 46020000 */  add.s     $f0, $f0, $f2
/* 7CD04 800E3854 E6260028 */  swc1      $f6, 0x28($s1)
/* 7CD08 800E3858 E624002C */  swc1      $f4, 0x2c($s1)
/* 7CD0C 800E385C 4500000A */  bc1f      .L800E3888
/* 7CD10 800E3860 E6200030 */   swc1     $f0, 0x30($s1)
/* 7CD14 800E3864 C6200020 */  lwc1      $f0, 0x20($s1)
/* 7CD18 800E3868 460A0032 */  c.eq.s    $f0, $f10
/* 7CD1C 800E386C 00000000 */  nop       
/* 7CD20 800E3870 45000005 */  bc1f      .L800E3888
/* 7CD24 800E3874 46001006 */   mov.s    $f0, $f2
/* 7CD28 800E3878 460A0032 */  c.eq.s    $f0, $f10
/* 7CD2C 800E387C 00000000 */  nop       
/* 7CD30 800E3880 45010009 */  bc1t      .L800E38A8
/* 7CD34 800E3884 00000000 */   nop      
.L800E3888:
/* 7CD38 800E3888 C6200028 */  lwc1      $f0, 0x28($s1)
/* 7CD3C 800E388C C622002C */  lwc1      $f2, 0x2c($s1)
/* 7CD40 800E3890 C6240030 */  lwc1      $f4, 0x30($s1)
/* 7CD44 800E3894 3C02800B */  lui       $v0, 0x800b
/* 7CD48 800E3898 24421D80 */  addiu     $v0, $v0, 0x1d80
/* 7CD4C 800E389C E4400060 */  swc1      $f0, 0x60($v0)
/* 7CD50 800E38A0 E4420064 */  swc1      $f2, 0x64($v0)
/* 7CD54 800E38A4 E4440068 */  swc1      $f4, 0x68($v0)
.L800E38A8:
/* 7CD58 800E38A8 C620001C */  lwc1      $f0, 0x1c($s1)
/* 7CD5C 800E38AC 44801000 */  mtc1      $zero, $f2
/* 7CD60 800E38B0 00000000 */  nop       
/* 7CD64 800E38B4 46020032 */  c.eq.s    $f0, $f2
/* 7CD68 800E38B8 00000000 */  nop       
/* 7CD6C 800E38BC 4500000B */  bc1f      .L800E38EC
/* 7CD70 800E38C0 00000000 */   nop      
/* 7CD74 800E38C4 C6200020 */  lwc1      $f0, 0x20($s1)
/* 7CD78 800E38C8 46020032 */  c.eq.s    $f0, $f2
/* 7CD7C 800E38CC 00000000 */  nop       
/* 7CD80 800E38D0 45000006 */  bc1f      .L800E38EC
/* 7CD84 800E38D4 00000000 */   nop      
/* 7CD88 800E38D8 C6200024 */  lwc1      $f0, 0x24($s1)
/* 7CD8C 800E38DC 46020032 */  c.eq.s    $f0, $f2
/* 7CD90 800E38E0 00000000 */  nop       
/* 7CD94 800E38E4 4501027E */  bc1t      .L800E42E0
/* 7CD98 800E38E8 00000000 */   nop      
.L800E38EC:
/* 7CD9C 800E38EC 3C038007 */  lui       $v1, 0x8007
/* 7CDA0 800E38F0 8C637410 */  lw        $v1, 0x7410($v1)
/* 7CDA4 800E38F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* 7CDA8 800E38F8 3C0142B4 */  lui       $at, 0x42b4
/* 7CDAC 800E38FC 44810000 */  mtc1      $at, $f0
/* 7CDB0 800E3900 00031080 */  sll       $v0, $v1, 2
/* 7CDB4 800E3904 00431021 */  addu      $v0, $v0, $v1
/* 7CDB8 800E3908 00021080 */  sll       $v0, $v0, 2
/* 7CDBC 800E390C 00431023 */  subu      $v0, $v0, $v1
/* 7CDC0 800E3910 000218C0 */  sll       $v1, $v0, 3
/* 7CDC4 800E3914 00431021 */  addu      $v0, $v0, $v1
/* 7CDC8 800E3918 000210C0 */  sll       $v0, $v0, 3
/* 7CDCC 800E391C 46001081 */  sub.s     $f2, $f2, $f0
/* 7CDD0 800E3920 3C01800B */  lui       $at, 0x800b
/* 7CDD4 800E3924 00220821 */  addu      $at, $at, $v0
/* 7CDD8 800E3928 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 7CDDC 800E392C 46001080 */  add.s     $f2, $f2, $f0
/* 7CDE0 800E3930 0000202D */  daddu     $a0, $zero, $zero
/* 7CDE4 800E3934 44061000 */  mfc1      $a2, $f2
/* 7CDE8 800E3938 080390B6 */  j         .L800E42D8
/* 7CDEC 800E393C 0080282D */   daddu    $a1, $a0, $zero
/* 7CDF0 800E3940 C6260028 */  lwc1      $f6, 0x28($s1)
/* 7CDF4 800E3944 C620001C */  lwc1      $f0, 0x1c($s1)
/* 7CDF8 800E3948 C624002C */  lwc1      $f4, 0x2c($s1)
/* 7CDFC 800E394C C628001C */  lwc1      $f8, 0x1c($s1)
/* 7CE00 800E3950 46003180 */  add.s     $f6, $f6, $f0
/* 7CE04 800E3954 C6200020 */  lwc1      $f0, 0x20($s1)
/* 7CE08 800E3958 44805000 */  mtc1      $zero, $f10
/* 7CE0C 800E395C 46002100 */  add.s     $f4, $f4, $f0
/* 7CE10 800E3960 C6220024 */  lwc1      $f2, 0x24($s1)
/* 7CE14 800E3964 C6200030 */  lwc1      $f0, 0x30($s1)
/* 7CE18 800E3968 460A4032 */  c.eq.s    $f8, $f10
/* 7CE1C 800E396C 46020000 */  add.s     $f0, $f0, $f2
/* 7CE20 800E3970 E6260028 */  swc1      $f6, 0x28($s1)
/* 7CE24 800E3974 E624002C */  swc1      $f4, 0x2c($s1)
/* 7CE28 800E3978 4500000A */  bc1f      .L800E39A4
/* 7CE2C 800E397C E6200030 */   swc1     $f0, 0x30($s1)
/* 7CE30 800E3980 C6200020 */  lwc1      $f0, 0x20($s1)
/* 7CE34 800E3984 460A0032 */  c.eq.s    $f0, $f10
/* 7CE38 800E3988 00000000 */  nop       
/* 7CE3C 800E398C 45000005 */  bc1f      .L800E39A4
/* 7CE40 800E3990 46001006 */   mov.s    $f0, $f2
/* 7CE44 800E3994 460A0032 */  c.eq.s    $f0, $f10
/* 7CE48 800E3998 00000000 */  nop       
/* 7CE4C 800E399C 45010009 */  bc1t      .L800E39C4
/* 7CE50 800E39A0 00000000 */   nop      
.L800E39A4:
/* 7CE54 800E39A4 C6200028 */  lwc1      $f0, 0x28($s1)
/* 7CE58 800E39A8 C622002C */  lwc1      $f2, 0x2c($s1)
/* 7CE5C 800E39AC C6240030 */  lwc1      $f4, 0x30($s1)
/* 7CE60 800E39B0 3C02800B */  lui       $v0, 0x800b
/* 7CE64 800E39B4 24421D80 */  addiu     $v0, $v0, 0x1d80
/* 7CE68 800E39B8 E4400060 */  swc1      $f0, 0x60($v0)
/* 7CE6C 800E39BC E4420064 */  swc1      $f2, 0x64($v0)
/* 7CE70 800E39C0 E4440068 */  swc1      $f4, 0x68($v0)
.L800E39C4:
/* 7CE74 800E39C4 C6260028 */  lwc1      $f6, 0x28($s1)
/* 7CE78 800E39C8 C628002C */  lwc1      $f8, 0x2c($s1)
/* 7CE7C 800E39CC C6220054 */  lwc1      $f2, 0x54($s1)
/* 7CE80 800E39D0 44800000 */  mtc1      $zero, $f0
/* 7CE84 800E39D4 C6240030 */  lwc1      $f4, 0x30($s1)
/* 7CE88 800E39D8 46001032 */  c.eq.s    $f2, $f0
/* 7CE8C 800E39DC E7A60020 */  swc1      $f6, 0x20($sp)
/* 7CE90 800E39E0 E7A80024 */  swc1      $f8, 0x24($sp)
/* 7CE94 800E39E4 45010004 */  bc1t      .L800E39F8
/* 7CE98 800E39E8 E7A40028 */   swc1     $f4, 0x28($sp)
/* 7CE9C 800E39EC C6200080 */  lwc1      $f0, 0x80($s1)
/* 7CEA0 800E39F0 08038E90 */  j         .L800E3A40
/* 7CEA4 800E39F4 E7A0002C */   swc1     $f0, 0x2c($sp)
.L800E39F8:
/* 7CEA8 800E39F8 3C038007 */  lui       $v1, 0x8007
/* 7CEAC 800E39FC 8C637410 */  lw        $v1, 0x7410($v1)
/* 7CEB0 800E3A00 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* 7CEB4 800E3A04 3C0142B4 */  lui       $at, 0x42b4
/* 7CEB8 800E3A08 44811000 */  mtc1      $at, $f2
/* 7CEBC 800E3A0C 00031080 */  sll       $v0, $v1, 2
/* 7CEC0 800E3A10 00431021 */  addu      $v0, $v0, $v1
/* 7CEC4 800E3A14 00021080 */  sll       $v0, $v0, 2
/* 7CEC8 800E3A18 00431023 */  subu      $v0, $v0, $v1
/* 7CECC 800E3A1C 000218C0 */  sll       $v1, $v0, 3
/* 7CED0 800E3A20 00431021 */  addu      $v0, $v0, $v1
/* 7CED4 800E3A24 000210C0 */  sll       $v0, $v0, 3
/* 7CED8 800E3A28 46020001 */  sub.s     $f0, $f0, $f2
/* 7CEDC 800E3A2C 3C01800B */  lui       $at, 0x800b
/* 7CEE0 800E3A30 00220821 */  addu      $at, $at, $v0
/* 7CEE4 800E3A34 C4221DEC */  lwc1      $f2, 0x1dec($at)
/* 7CEE8 800E3A38 46020000 */  add.s     $f0, $f0, $f2
/* 7CEEC 800E3A3C E7A0002C */  swc1      $f0, 0x2c($sp)
.L800E3A40:
/* 7CEF0 800E3A40 862200B2 */  lh        $v0, 0xb2($s1)
/* 7CEF4 800E3A44 3C013F00 */  lui       $at, 0x3f00
/* 7CEF8 800E3A48 44811000 */  mtc1      $at, $f2
/* 7CEFC 800E3A4C 44820000 */  mtc1      $v0, $f0
/* 7CF00 800E3A50 00000000 */  nop       
/* 7CF04 800E3A54 46800020 */  cvt.s.w   $f0, $f0
/* 7CF08 800E3A58 46020002 */  mul.s     $f0, $f0, $f2
/* 7CF0C 800E3A5C 00000000 */  nop       
/* 7CF10 800E3A60 0220202D */  daddu     $a0, $s1, $zero
/* 7CF14 800E3A64 27A50020 */  addiu     $a1, $sp, 0x20
/* 7CF18 800E3A68 27A60024 */  addiu     $a2, $sp, 0x24
/* 7CF1C 800E3A6C E7A00010 */  swc1      $f0, 0x10($sp)
/* 7CF20 800E3A70 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 7CF24 800E3A74 27A70028 */  addiu     $a3, $sp, 0x28
/* 7CF28 800E3A78 0C037D18 */  jal       test_player_lateral
/* 7CF2C 800E3A7C E7A00014 */   swc1     $f0, 0x14($sp)
/* 7CF30 800E3A80 C620001C */  lwc1      $f0, 0x1c($s1)
/* 7CF34 800E3A84 44801000 */  mtc1      $zero, $f2
/* 7CF38 800E3A88 00000000 */  nop       
/* 7CF3C 800E3A8C 46020032 */  c.eq.s    $f0, $f2
/* 7CF40 800E3A90 00000000 */  nop       
/* 7CF44 800E3A94 4500000B */  bc1f      .L800E3AC4
/* 7CF48 800E3A98 A6820012 */   sh       $v0, 0x12($s4)
/* 7CF4C 800E3A9C C6200020 */  lwc1      $f0, 0x20($s1)
/* 7CF50 800E3AA0 46020032 */  c.eq.s    $f0, $f2
/* 7CF54 800E3AA4 00000000 */  nop       
/* 7CF58 800E3AA8 45000006 */  bc1f      .L800E3AC4
/* 7CF5C 800E3AAC 00000000 */   nop      
/* 7CF60 800E3AB0 C6200024 */  lwc1      $f0, 0x24($s1)
/* 7CF64 800E3AB4 46020032 */  c.eq.s    $f0, $f2
/* 7CF68 800E3AB8 00000000 */  nop       
/* 7CF6C 800E3ABC 45010208 */  bc1t      .L800E42E0
/* 7CF70 800E3AC0 00000000 */   nop      
.L800E3AC4:
/* 7CF74 800E3AC4 3C038007 */  lui       $v1, 0x8007
/* 7CF78 800E3AC8 8C637410 */  lw        $v1, 0x7410($v1)
/* 7CF7C 800E3ACC C62200A8 */  lwc1      $f2, 0xa8($s1)
/* 7CF80 800E3AD0 3C0142B4 */  lui       $at, 0x42b4
/* 7CF84 800E3AD4 44810000 */  mtc1      $at, $f0
/* 7CF88 800E3AD8 00031080 */  sll       $v0, $v1, 2
/* 7CF8C 800E3ADC 00431021 */  addu      $v0, $v0, $v1
/* 7CF90 800E3AE0 00021080 */  sll       $v0, $v0, 2
/* 7CF94 800E3AE4 00431023 */  subu      $v0, $v0, $v1
/* 7CF98 800E3AE8 000218C0 */  sll       $v1, $v0, 3
/* 7CF9C 800E3AEC 00431021 */  addu      $v0, $v0, $v1
/* 7CFA0 800E3AF0 000210C0 */  sll       $v0, $v0, 3
/* 7CFA4 800E3AF4 46001081 */  sub.s     $f2, $f2, $f0
/* 7CFA8 800E3AF8 3C01800B */  lui       $at, 0x800b
/* 7CFAC 800E3AFC 00220821 */  addu      $at, $at, $v0
/* 7CFB0 800E3B00 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 7CFB4 800E3B04 46001080 */  add.s     $f2, $f2, $f0
/* 7CFB8 800E3B08 0000202D */  daddu     $a0, $zero, $zero
/* 7CFBC 800E3B0C 44061000 */  mfc1      $a2, $f2
/* 7CFC0 800E3B10 080390B6 */  j         .L800E42D8
/* 7CFC4 800E3B14 0080282D */   daddu    $a1, $a0, $zero
.L800E3B18:
/* 7CFC8 800E3B18 8E220000 */  lw        $v0, ($s1)
/* 7CFCC 800E3B1C 30420008 */  andi      $v0, $v0, 8
/* 7CFD0 800E3B20 144001EF */  bnez      $v0, .L800E42E0
/* 7CFD4 800E3B24 3C030080 */   lui      $v1, 0x80
/* 7CFD8 800E3B28 8E220000 */  lw        $v0, ($s1)
/* 7CFDC 800E3B2C 34632000 */  ori       $v1, $v1, 0x2000
/* 7CFE0 800E3B30 00431024 */  and       $v0, $v0, $v1
/* 7CFE4 800E3B34 144000AA */  bnez      $v0, .L800E3DE0
/* 7CFE8 800E3B38 AFA00030 */   sw       $zero, 0x30($sp)
/* 7CFEC 800E3B3C 27A4002C */  addiu     $a0, $sp, 0x2c
/* 7CFF0 800E3B40 0C0388C1 */  jal       input_to_move_vector
/* 7CFF4 800E3B44 27A50030 */   addiu    $a1, $sp, 0x30
/* 7CFF8 800E3B48 8E220004 */  lw        $v0, 4($s1)
/* 7CFFC 800E3B4C 3C030001 */  lui       $v1, 1
/* 7D000 800E3B50 00431024 */  and       $v0, $v0, $v1
/* 7D004 800E3B54 1440002C */  bnez      $v0, .L800E3C08
/* 7D008 800E3B58 00000000 */   nop      
/* 7D00C 800E3B5C C7A20030 */  lwc1      $f2, 0x30($sp)
/* 7D010 800E3B60 3C013D00 */  lui       $at, 0x3d00
/* 7D014 800E3B64 44810000 */  mtc1      $at, $f0
/* 7D018 800E3B68 00000000 */  nop       
/* 7D01C 800E3B6C 46001002 */  mul.s     $f0, $f2, $f0
/* 7D020 800E3B70 00000000 */  nop       
/* 7D024 800E3B74 8E220000 */  lw        $v0, ($s1)
/* 7D028 800E3B78 30420006 */  andi      $v0, $v0, 6
/* 7D02C 800E3B7C 14400009 */  bnez      $v0, .L800E3BA4
/* 7D030 800E3B80 E7A00030 */   swc1     $f0, 0x30($sp)
/* 7D034 800E3B84 3C013FD0 */  lui       $at, 0x3fd0
/* 7D038 800E3B88 44811800 */  mtc1      $at, $f3
/* 7D03C 800E3B8C 44801000 */  mtc1      $zero, $f2
/* 7D040 800E3B90 46000021 */  cvt.d.s   $f0, $f0
/* 7D044 800E3B94 46220002 */  mul.d     $f0, $f0, $f2
/* 7D048 800E3B98 00000000 */  nop       
/* 7D04C 800E3B9C 46200020 */  cvt.s.d   $f0, $f0
/* 7D050 800E3BA0 E7A00030 */  swc1      $f0, 0x30($sp)
.L800E3BA4:
/* 7D054 800E3BA4 822300B4 */  lb        $v1, 0xb4($s1)
/* 7D058 800E3BA8 24020006 */  addiu     $v0, $zero, 6
/* 7D05C 800E3BAC 1462000A */  bne       $v1, $v0, .L800E3BD8
/* 7D060 800E3BB0 00000000 */   nop      
/* 7D064 800E3BB4 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 7D068 800E3BB8 3C013FF8 */  lui       $at, 0x3ff8
/* 7D06C 800E3BBC 44811800 */  mtc1      $at, $f3
/* 7D070 800E3BC0 44801000 */  mtc1      $zero, $f2
/* 7D074 800E3BC4 46000021 */  cvt.d.s   $f0, $f0
/* 7D078 800E3BC8 46220002 */  mul.d     $f0, $f0, $f2
/* 7D07C 800E3BCC 00000000 */  nop       
/* 7D080 800E3BD0 46200020 */  cvt.s.d   $f0, $f0
/* 7D084 800E3BD4 E7A00030 */  swc1      $f0, 0x30($sp)
.L800E3BD8:
/* 7D088 800E3BD8 8E220000 */  lw        $v0, ($s1)
/* 7D08C 800E3BDC 3C030004 */  lui       $v1, 4
/* 7D090 800E3BE0 00431024 */  and       $v0, $v0, $v1
/* 7D094 800E3BE4 10400008 */  beqz      $v0, .L800E3C08
/* 7D098 800E3BE8 00000000 */   nop      
/* 7D09C 800E3BEC C7A00030 */  lwc1      $f0, 0x30($sp)
/* 7D0A0 800E3BF0 3C013F00 */  lui       $at, 0x3f00
/* 7D0A4 800E3BF4 44811000 */  mtc1      $at, $f2
/* 7D0A8 800E3BF8 00000000 */  nop       
/* 7D0AC 800E3BFC 46020002 */  mul.s     $f0, $f0, $f2
/* 7D0B0 800E3C00 00000000 */  nop       
/* 7D0B4 800E3C04 E7A00030 */  swc1      $f0, 0x30($sp)
.L800E3C08:
/* 7D0B8 800E3C08 C7AC002C */  lwc1      $f12, 0x2c($sp)
/* 7D0BC 800E3C0C 3C0140C9 */  lui       $at, 0x40c9
/* 7D0C0 800E3C10 34210FD0 */  ori       $at, $at, 0xfd0
/* 7D0C4 800E3C14 44810000 */  mtc1      $at, $f0
/* 7D0C8 800E3C18 00000000 */  nop       
/* 7D0CC 800E3C1C 46006302 */  mul.s     $f12, $f12, $f0
/* 7D0D0 800E3C20 00000000 */  nop       
/* 7D0D4 800E3C24 27A50034 */  addiu     $a1, $sp, 0x34
/* 7D0D8 800E3C28 3C0143B4 */  lui       $at, 0x43b4
/* 7D0DC 800E3C2C 44810000 */  mtc1      $at, $f0
/* 7D0E0 800E3C30 27A60038 */  addiu     $a2, $sp, 0x38
/* 7D0E4 800E3C34 0C00A82D */  jal       sin_cos_rad
/* 7D0E8 800E3C38 46006303 */   div.s    $f12, $f12, $f0
/* 7D0EC 800E3C3C 822300B4 */  lb        $v1, 0xb4($s1)
/* 7D0F0 800E3C40 24020014 */  addiu     $v0, $zero, 0x14
/* 7D0F4 800E3C44 14620014 */  bne       $v1, $v0, .L800E3C98
/* 7D0F8 800E3C48 3C030001 */   lui      $v1, 1
/* 7D0FC 800E3C4C C7A60034 */  lwc1      $f6, 0x34($sp)
/* 7D100 800E3C50 C7A40038 */  lwc1      $f4, 0x38($sp)
/* 7D104 800E3C54 46003085 */  abs.s     $f2, $f6
/* 7D108 800E3C58 46002005 */  abs.s     $f0, $f4
/* 7D10C 800E3C5C 4602003C */  c.lt.s    $f0, $f2
/* 7D110 800E3C60 00000000 */  nop       
/* 7D114 800E3C64 45000006 */  bc1f      .L800E3C80
/* 7D118 800E3C68 00000000 */   nop      
/* 7D11C 800E3C6C C7A00030 */  lwc1      $f0, 0x30($sp)
/* 7D120 800E3C70 4480A000 */  mtc1      $zero, $f20
/* 7D124 800E3C74 46060582 */  mul.s     $f22, $f0, $f6
/* 7D128 800E3C78 08038F36 */  j         .L800E3CD8
/* 7D12C 800E3C7C 00000000 */   nop      
.L800E3C80:
/* 7D130 800E3C80 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 7D134 800E3C84 4480B000 */  mtc1      $zero, $f22
/* 7D138 800E3C88 46000007 */  neg.s     $f0, $f0
/* 7D13C 800E3C8C 46040502 */  mul.s     $f20, $f0, $f4
/* 7D140 800E3C90 08038F36 */  j         .L800E3CD8
/* 7D144 800E3C94 00000000 */   nop      
.L800E3C98:
/* 7D148 800E3C98 8E220004 */  lw        $v0, 4($s1)
/* 7D14C 800E3C9C 00431024 */  and       $v0, $v0, $v1
/* 7D150 800E3CA0 1440000A */  bnez      $v0, .L800E3CCC
/* 7D154 800E3CA4 00000000 */   nop      
/* 7D158 800E3CA8 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 7D15C 800E3CAC C7A20034 */  lwc1      $f2, 0x34($sp)
/* 7D160 800E3CB0 46020582 */  mul.s     $f22, $f0, $f2
/* 7D164 800E3CB4 00000000 */  nop       
/* 7D168 800E3CB8 C7A20038 */  lwc1      $f2, 0x38($sp)
/* 7D16C 800E3CBC 46000007 */  neg.s     $f0, $f0
/* 7D170 800E3CC0 46020502 */  mul.s     $f20, $f0, $f2
/* 7D174 800E3CC4 08038F36 */  j         .L800E3CD8
/* 7D178 800E3CC8 00000000 */   nop      
.L800E3CCC:
/* 7D17C 800E3CCC 4480A000 */  mtc1      $zero, $f20
/* 7D180 800E3CD0 00000000 */  nop       
/* 7D184 800E3CD4 4600A586 */  mov.s     $f22, $f20
.L800E3CD8:
/* 7D188 800E3CD8 C62C0080 */  lwc1      $f12, 0x80($s1)
/* 7D18C 800E3CDC 3C0140C9 */  lui       $at, 0x40c9
/* 7D190 800E3CE0 34210FD0 */  ori       $at, $at, 0xfd0
/* 7D194 800E3CE4 44810000 */  mtc1      $at, $f0
/* 7D198 800E3CE8 00000000 */  nop       
/* 7D19C 800E3CEC 46006302 */  mul.s     $f12, $f12, $f0
/* 7D1A0 800E3CF0 00000000 */  nop       
/* 7D1A4 800E3CF4 27A50034 */  addiu     $a1, $sp, 0x34
/* 7D1A8 800E3CF8 3C0143B4 */  lui       $at, 0x43b4
/* 7D1AC 800E3CFC 44810000 */  mtc1      $at, $f0
/* 7D1B0 800E3D00 27A60038 */  addiu     $a2, $sp, 0x38
/* 7D1B4 800E3D04 0C00A82D */  jal       sin_cos_rad
/* 7D1B8 800E3D08 46006303 */   div.s    $f12, $f12, $f0
/* 7D1BC 800E3D0C C6220054 */  lwc1      $f2, 0x54($s1)
/* 7D1C0 800E3D10 E7A20030 */  swc1      $f2, 0x30($sp)
/* 7D1C4 800E3D14 8E220000 */  lw        $v0, ($s1)
/* 7D1C8 800E3D18 3C030004 */  lui       $v1, 4
/* 7D1CC 800E3D1C 00431024 */  and       $v0, $v0, $v1
/* 7D1D0 800E3D20 10400007 */  beqz      $v0, .L800E3D40
/* 7D1D4 800E3D24 00000000 */   nop      
/* 7D1D8 800E3D28 3C013F00 */  lui       $at, 0x3f00
/* 7D1DC 800E3D2C 44810000 */  mtc1      $at, $f0
/* 7D1E0 800E3D30 00000000 */  nop       
/* 7D1E4 800E3D34 46001002 */  mul.s     $f0, $f2, $f0
/* 7D1E8 800E3D38 00000000 */  nop       
/* 7D1EC 800E3D3C E7A00030 */  swc1      $f0, 0x30($sp)
.L800E3D40:
/* 7D1F0 800E3D40 C7A40030 */  lwc1      $f4, 0x30($sp)
/* 7D1F4 800E3D44 C7A20034 */  lwc1      $f2, 0x34($sp)
/* 7D1F8 800E3D48 46022082 */  mul.s     $f2, $f4, $f2
/* 7D1FC 800E3D4C 00000000 */  nop       
/* 7D200 800E3D50 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 7D204 800E3D54 46002102 */  mul.s     $f4, $f4, $f0
/* 7D208 800E3D58 00000000 */  nop       
/* 7D20C 800E3D5C 4602B080 */  add.s     $f2, $f22, $f2
/* 7D210 800E3D60 4604A101 */  sub.s     $f4, $f20, $f4
/* 7D214 800E3D64 44806000 */  mtc1      $zero, $f12
/* 7D218 800E3D68 44061000 */  mfc1      $a2, $f2
/* 7D21C 800E3D6C 44072000 */  mfc1      $a3, $f4
/* 7D220 800E3D70 46006386 */  mov.s     $f14, $f12
/* 7D224 800E3D74 AFA60020 */  sw        $a2, 0x20($sp)
/* 7D228 800E3D78 0C00A720 */  jal       atan2
/* 7D22C 800E3D7C AFA70028 */   sw       $a3, 0x28($sp)
/* 7D230 800E3D80 C7A40020 */  lwc1      $f4, 0x20($sp)
/* 7D234 800E3D84 46042102 */  mul.s     $f4, $f4, $f4
/* 7D238 800E3D88 00000000 */  nop       
/* 7D23C 800E3D8C C7A20028 */  lwc1      $f2, 0x28($sp)
/* 7D240 800E3D90 46021082 */  mul.s     $f2, $f2, $f2
/* 7D244 800E3D94 00000000 */  nop       
/* 7D248 800E3D98 46022300 */  add.s     $f12, $f4, $f2
/* 7D24C 800E3D9C E7A0002C */  swc1      $f0, 0x2c($sp)
/* 7D250 800E3DA0 46006004 */  sqrt.s    $f0, $f12
/* 7D254 800E3DA4 46000032 */  c.eq.s    $f0, $f0
/* 7D258 800E3DA8 00000000 */  nop       
/* 7D25C 800E3DAC 45010003 */  bc1t      .L800E3DBC
/* 7D260 800E3DB0 00000000 */   nop      
/* 7D264 800E3DB4 0C0187BC */  jal       sqrtf
/* 7D268 800E3DB8 00000000 */   nop      
.L800E3DBC:
/* 7D26C 800E3DBC 8E220000 */  lw        $v0, ($s1)
/* 7D270 800E3DC0 30420006 */  andi      $v0, $v0, 6
/* 7D274 800E3DC4 10400006 */  beqz      $v0, .L800E3DE0
/* 7D278 800E3DC8 E7A00030 */   swc1     $f0, 0x30($sp)
/* 7D27C 800E3DCC C622005C */  lwc1      $f2, 0x5c($s1)
/* 7D280 800E3DD0 4600103C */  c.lt.s    $f2, $f0
/* 7D284 800E3DD4 00000000 */  nop       
/* 7D288 800E3DD8 45030001 */  bc1tl     .L800E3DE0
/* 7D28C 800E3DDC E7A20030 */   swc1     $f2, 0x30($sp)
.L800E3DE0:
/* 7D290 800E3DE0 C6240028 */  lwc1      $f4, 0x28($s1)
/* 7D294 800E3DE4 C620001C */  lwc1      $f0, 0x1c($s1)
/* 7D298 800E3DE8 C6220030 */  lwc1      $f2, 0x30($s1)
/* 7D29C 800E3DEC 46002100 */  add.s     $f4, $f4, $f0
/* 7D2A0 800E3DF0 C6200024 */  lwc1      $f0, 0x24($s1)
/* 7D2A4 800E3DF4 862200C0 */  lh        $v0, 0xc0($s1)
/* 7D2A8 800E3DF8 46001080 */  add.s     $f2, $f2, $f0
/* 7D2AC 800E3DFC E6240028 */  swc1      $f4, 0x28($s1)
/* 7D2B0 800E3E00 14400005 */  bnez      $v0, .L800E3E18
/* 7D2B4 800E3E04 E6220030 */   swc1     $f2, 0x30($s1)
/* 7D2B8 800E3E08 C620002C */  lwc1      $f0, 0x2c($s1)
/* 7D2BC 800E3E0C C6220020 */  lwc1      $f2, 0x20($s1)
/* 7D2C0 800E3E10 46020000 */  add.s     $f0, $f0, $f2
/* 7D2C4 800E3E14 E620002C */  swc1      $f0, 0x2c($s1)
.L800E3E18:
/* 7D2C8 800E3E18 C620001C */  lwc1      $f0, 0x1c($s1)
/* 7D2CC 800E3E1C 44801000 */  mtc1      $zero, $f2
/* 7D2D0 800E3E20 00000000 */  nop       
/* 7D2D4 800E3E24 46020032 */  c.eq.s    $f0, $f2
/* 7D2D8 800E3E28 00000000 */  nop       
/* 7D2DC 800E3E2C 4500000B */  bc1f      .L800E3E5C
/* 7D2E0 800E3E30 00000000 */   nop      
/* 7D2E4 800E3E34 C6200020 */  lwc1      $f0, 0x20($s1)
/* 7D2E8 800E3E38 46020032 */  c.eq.s    $f0, $f2
/* 7D2EC 800E3E3C 00000000 */  nop       
/* 7D2F0 800E3E40 45000006 */  bc1f      .L800E3E5C
/* 7D2F4 800E3E44 00000000 */   nop      
/* 7D2F8 800E3E48 C6200024 */  lwc1      $f0, 0x24($s1)
/* 7D2FC 800E3E4C 46020032 */  c.eq.s    $f0, $f2
/* 7D300 800E3E50 00000000 */  nop       
/* 7D304 800E3E54 4501000A */  bc1t      .L800E3E80
/* 7D308 800E3E58 0220202D */   daddu    $a0, $s1, $zero
.L800E3E5C:
/* 7D30C 800E3E5C C6200028 */  lwc1      $f0, 0x28($s1)
/* 7D310 800E3E60 C622002C */  lwc1      $f2, 0x2c($s1)
/* 7D314 800E3E64 C6240030 */  lwc1      $f4, 0x30($s1)
/* 7D318 800E3E68 3C02800B */  lui       $v0, 0x800b
/* 7D31C 800E3E6C 24421D80 */  addiu     $v0, $v0, 0x1d80
/* 7D320 800E3E70 E4400060 */  swc1      $f0, 0x60($v0)
/* 7D324 800E3E74 E4420064 */  swc1      $f2, 0x64($v0)
/* 7D328 800E3E78 E4440068 */  swc1      $f4, 0x68($v0)
/* 7D32C 800E3E7C 0220202D */  daddu     $a0, $s1, $zero
.L800E3E80:
/* 7D330 800E3E80 27B30020 */  addiu     $s3, $sp, 0x20
/* 7D334 800E3E84 0260282D */  daddu     $a1, $s3, $zero
/* 7D338 800E3E88 27B00024 */  addiu     $s0, $sp, 0x24
/* 7D33C 800E3E8C 0200302D */  daddu     $a2, $s0, $zero
/* 7D340 800E3E90 27B20028 */  addiu     $s2, $sp, 0x28
/* 7D344 800E3E94 0240382D */  daddu     $a3, $s2, $zero
/* 7D348 800E3E98 862200B2 */  lh        $v0, 0xb2($s1)
/* 7D34C 800E3E9C C6240028 */  lwc1      $f4, 0x28($s1)
/* 7D350 800E3EA0 C626002C */  lwc1      $f6, 0x2c($s1)
/* 7D354 800E3EA4 C6280030 */  lwc1      $f8, 0x30($s1)
/* 7D358 800E3EA8 3C013F00 */  lui       $at, 0x3f00
/* 7D35C 800E3EAC 4481B000 */  mtc1      $at, $f22
/* 7D360 800E3EB0 C6220080 */  lwc1      $f2, 0x80($s1)
/* 7D364 800E3EB4 44820000 */  mtc1      $v0, $f0
/* 7D368 800E3EB8 00000000 */  nop       
/* 7D36C 800E3EBC 46800020 */  cvt.s.w   $f0, $f0
/* 7D370 800E3EC0 46160002 */  mul.s     $f0, $f0, $f22
/* 7D374 800E3EC4 00000000 */  nop       
/* 7D378 800E3EC8 E7A40020 */  swc1      $f4, 0x20($sp)
/* 7D37C 800E3ECC E7A60024 */  swc1      $f6, 0x24($sp)
/* 7D380 800E3ED0 E7A80028 */  swc1      $f8, 0x28($sp)
/* 7D384 800E3ED4 E7A20014 */  swc1      $f2, 0x14($sp)
/* 7D388 800E3ED8 0C037D18 */  jal       test_player_lateral
/* 7D38C 800E3EDC E7A00010 */   swc1     $f0, 0x10($sp)
/* 7D390 800E3EE0 C7A20030 */  lwc1      $f2, 0x30($sp)
/* 7D394 800E3EE4 44800000 */  mtc1      $zero, $f0
/* 7D398 800E3EE8 00000000 */  nop       
/* 7D39C 800E3EEC 46001032 */  c.eq.s    $f2, $f0
/* 7D3A0 800E3EF0 00000000 */  nop       
/* 7D3A4 800E3EF4 45020045 */  bc1fl     .L800E400C
/* 7D3A8 800E3EF8 A6820012 */   sh       $v0, 0x12($s4)
/* 7D3AC 800E3EFC 04430043 */  bgezl     $v0, .L800E400C
/* 7D3B0 800E3F00 A6820012 */   sh       $v0, 0x12($s4)
/* 7D3B4 800E3F04 3C038007 */  lui       $v1, 0x8007
/* 7D3B8 800E3F08 8C637410 */  lw        $v1, 0x7410($v1)
/* 7D3BC 800E3F0C C62200A8 */  lwc1      $f2, 0xa8($s1)
/* 7D3C0 800E3F10 3C0142B4 */  lui       $at, 0x42b4
/* 7D3C4 800E3F14 44810000 */  mtc1      $at, $f0
/* 7D3C8 800E3F18 00031080 */  sll       $v0, $v1, 2
/* 7D3CC 800E3F1C 00431021 */  addu      $v0, $v0, $v1
/* 7D3D0 800E3F20 00021080 */  sll       $v0, $v0, 2
/* 7D3D4 800E3F24 00431023 */  subu      $v0, $v0, $v1
/* 7D3D8 800E3F28 000218C0 */  sll       $v1, $v0, 3
/* 7D3DC 800E3F2C 00431021 */  addu      $v0, $v0, $v1
/* 7D3E0 800E3F30 000210C0 */  sll       $v0, $v0, 3
/* 7D3E4 800E3F34 46001081 */  sub.s     $f2, $f2, $f0
/* 7D3E8 800E3F38 3C01800B */  lui       $at, 0x800b
/* 7D3EC 800E3F3C 00220821 */  addu      $at, $at, $v0
/* 7D3F0 800E3F40 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 7D3F4 800E3F44 46001500 */  add.s     $f20, $f2, $f0
/* 7D3F8 800E3F48 3C014334 */  lui       $at, 0x4334
/* 7D3FC 800E3F4C 44816000 */  mtc1      $at, $f12
/* 7D400 800E3F50 00000000 */  nop       
/* 7D404 800E3F54 460CA300 */  add.s     $f12, $f20, $f12
/* 7D408 800E3F58 3C0140C9 */  lui       $at, 0x40c9
/* 7D40C 800E3F5C 34210FD0 */  ori       $at, $at, 0xfd0
/* 7D410 800E3F60 44810000 */  mtc1      $at, $f0
/* 7D414 800E3F64 00000000 */  nop       
/* 7D418 800E3F68 46006302 */  mul.s     $f12, $f12, $f0
/* 7D41C 800E3F6C 00000000 */  nop       
/* 7D420 800E3F70 27A50034 */  addiu     $a1, $sp, 0x34
/* 7D424 800E3F74 3C0143B4 */  lui       $at, 0x43b4
/* 7D428 800E3F78 44810000 */  mtc1      $at, $f0
/* 7D42C 800E3F7C 27A60038 */  addiu     $a2, $sp, 0x38
/* 7D430 800E3F80 0C00A82D */  jal       sin_cos_rad
/* 7D434 800E3F84 46006303 */   div.s    $f12, $f12, $f0
/* 7D438 800E3F88 862200B2 */  lh        $v0, 0xb2($s1)
/* 7D43C 800E3F8C C7A60034 */  lwc1      $f6, 0x34($sp)
/* 7D440 800E3F90 44820000 */  mtc1      $v0, $f0
/* 7D444 800E3F94 00000000 */  nop       
/* 7D448 800E3F98 46800020 */  cvt.s.w   $f0, $f0
/* 7D44C 800E3F9C 46003182 */  mul.s     $f6, $f6, $f0
/* 7D450 800E3FA0 00000000 */  nop       
/* 7D454 800E3FA4 C7A40038 */  lwc1      $f4, 0x38($sp)
/* 7D458 800E3FA8 46002102 */  mul.s     $f4, $f4, $f0
/* 7D45C 800E3FAC 00000000 */  nop       
/* 7D460 800E3FB0 46163182 */  mul.s     $f6, $f6, $f22
/* 7D464 800E3FB4 00000000 */  nop       
/* 7D468 800E3FB8 46162102 */  mul.s     $f4, $f4, $f22
/* 7D46C 800E3FBC 00000000 */  nop       
/* 7D470 800E3FC0 0220202D */  daddu     $a0, $s1, $zero
/* 7D474 800E3FC4 0260282D */  daddu     $a1, $s3, $zero
/* 7D478 800E3FC8 C6220028 */  lwc1      $f2, 0x28($s1)
/* 7D47C 800E3FCC 0200302D */  daddu     $a2, $s0, $zero
/* 7D480 800E3FD0 46061080 */  add.s     $f2, $f2, $f6
/* 7D484 800E3FD4 C6200030 */  lwc1      $f0, 0x30($s1)
/* 7D488 800E3FD8 C626002C */  lwc1      $f6, 0x2c($s1)
/* 7D48C 800E3FDC 46040001 */  sub.s     $f0, $f0, $f4
/* 7D490 800E3FE0 0240382D */  daddu     $a3, $s2, $zero
/* 7D494 800E3FE4 E7A60024 */  swc1      $f6, 0x24($sp)
/* 7D498 800E3FE8 E7A00028 */  swc1      $f0, 0x28($sp)
/* 7D49C 800E3FEC 44820000 */  mtc1      $v0, $f0
/* 7D4A0 800E3FF0 00000000 */  nop       
/* 7D4A4 800E3FF4 46800020 */  cvt.s.w   $f0, $f0
/* 7D4A8 800E3FF8 E7A20020 */  swc1      $f2, 0x20($sp)
/* 7D4AC 800E3FFC E7A00010 */  swc1      $f0, 0x10($sp)
/* 7D4B0 800E4000 0C037D18 */  jal       test_player_lateral
/* 7D4B4 800E4004 E7B40014 */   swc1     $f20, 0x14($sp)
/* 7D4B8 800E4008 A6820012 */  sh        $v0, 0x12($s4)
.L800E400C:
/* 7D4BC 800E400C 8E220000 */  lw        $v0, ($s1)
/* 7D4C0 800E4010 3C030040 */  lui       $v1, 0x40
/* 7D4C4 800E4014 00431024 */  and       $v0, $v0, $v1
/* 7D4C8 800E4018 144000B1 */  bnez      $v0, .L800E42E0
/* 7D4CC 800E401C 24020012 */   addiu    $v0, $zero, 0x12
/* 7D4D0 800E4020 822300B4 */  lb        $v1, 0xb4($s1)
/* 7D4D4 800E4024 106200AE */  beq       $v1, $v0, .L800E42E0
/* 7D4D8 800E4028 00000000 */   nop      
/* 7D4DC 800E402C C7A60030 */  lwc1      $f6, 0x30($sp)
/* 7D4E0 800E4030 44800000 */  mtc1      $zero, $f0
/* 7D4E4 800E4034 00000000 */  nop       
/* 7D4E8 800E4038 46003032 */  c.eq.s    $f6, $f0
/* 7D4EC 800E403C 00000000 */  nop       
/* 7D4F0 800E4040 45000015 */  bc1f      .L800E4098
/* 7D4F4 800E4044 0000202D */   daddu    $a0, $zero, $zero
/* 7D4F8 800E4048 3C038007 */  lui       $v1, 0x8007
/* 7D4FC 800E404C 8C637410 */  lw        $v1, 0x7410($v1)
/* 7D500 800E4050 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* 7D504 800E4054 3C0142B4 */  lui       $at, 0x42b4
/* 7D508 800E4058 44810000 */  mtc1      $at, $f0
/* 7D50C 800E405C 00031080 */  sll       $v0, $v1, 2
/* 7D510 800E4060 00431021 */  addu      $v0, $v0, $v1
/* 7D514 800E4064 00021080 */  sll       $v0, $v0, 2
/* 7D518 800E4068 00431023 */  subu      $v0, $v0, $v1
/* 7D51C 800E406C 000218C0 */  sll       $v1, $v0, 3
/* 7D520 800E4070 00431021 */  addu      $v0, $v0, $v1
/* 7D524 800E4074 000210C0 */  sll       $v0, $v0, 3
/* 7D528 800E4078 46001081 */  sub.s     $f2, $f2, $f0
/* 7D52C 800E407C 3C01800B */  lui       $at, 0x800b
/* 7D530 800E4080 00220821 */  addu      $at, $at, $v0
/* 7D534 800E4084 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 7D538 800E4088 46001080 */  add.s     $f2, $f2, $f0
/* 7D53C 800E408C 44061000 */  mfc1      $a2, $f2
/* 7D540 800E4090 080390B6 */  j         .L800E42D8
/* 7D544 800E4094 0080282D */   daddu    $a1, $a0, $zero
.L800E4098:
/* 7D548 800E4098 C7B4002C */  lwc1      $f20, 0x2c($sp)
/* 7D54C 800E409C C6200028 */  lwc1      $f0, 0x28($s1)
/* 7D550 800E40A0 C6240030 */  lwc1      $f4, 0x30($s1)
/* 7D554 800E40A4 3C014080 */  lui       $at, 0x4080
/* 7D558 800E40A8 4481B000 */  mtc1      $at, $f22
/* 7D55C 800E40AC C622002C */  lwc1      $f2, 0x2c($s1)
/* 7D560 800E40B0 4606B03C */  c.lt.s    $f22, $f6
/* 7D564 800E40B4 E7A00020 */  swc1      $f0, 0x20($sp)
/* 7D568 800E40B8 E7A40028 */  swc1      $f4, 0x28($sp)
/* 7D56C 800E40BC 45000016 */  bc1f      .L800E4118
/* 7D570 800E40C0 E7A20024 */   swc1     $f2, 0x24($sp)
/* 7D574 800E40C4 0220202D */  daddu     $a0, $s1, $zero
/* 7D578 800E40C8 27B00020 */  addiu     $s0, $sp, 0x20
/* 7D57C 800E40CC 0200282D */  daddu     $a1, $s0, $zero
/* 7D580 800E40D0 27B20024 */  addiu     $s2, $sp, 0x24
/* 7D584 800E40D4 0240302D */  daddu     $a2, $s2, $zero
/* 7D588 800E40D8 27B30028 */  addiu     $s3, $sp, 0x28
/* 7D58C 800E40DC 0260382D */  daddu     $a3, $s3, $zero
/* 7D590 800E40E0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 7D594 800E40E4 0C037D18 */  jal       test_player_lateral
/* 7D598 800E40E8 E7B40014 */   swc1     $f20, 0x14($sp)
/* 7D59C 800E40EC 04430013 */  bgezl     $v0, .L800E413C
/* 7D5A0 800E40F0 A6820000 */   sh       $v0, ($s4)
/* 7D5A4 800E40F4 0220202D */  daddu     $a0, $s1, $zero
/* 7D5A8 800E40F8 0200282D */  daddu     $a1, $s0, $zero
/* 7D5AC 800E40FC C7A00030 */  lwc1      $f0, 0x30($sp)
/* 7D5B0 800E4100 0240302D */  daddu     $a2, $s2, $zero
/* 7D5B4 800E4104 46160001 */  sub.s     $f0, $f0, $f22
/* 7D5B8 800E4108 0260382D */  daddu     $a3, $s3, $zero
/* 7D5BC 800E410C E7B40014 */  swc1      $f20, 0x14($sp)
/* 7D5C0 800E4110 0803904C */  j         .L800E4130
/* 7D5C4 800E4114 E7A00010 */   swc1     $f0, 0x10($sp)
.L800E4118:
/* 7D5C8 800E4118 0220202D */  daddu     $a0, $s1, $zero
/* 7D5CC 800E411C 27A50020 */  addiu     $a1, $sp, 0x20
/* 7D5D0 800E4120 27A60024 */  addiu     $a2, $sp, 0x24
/* 7D5D4 800E4124 27A70028 */  addiu     $a3, $sp, 0x28
/* 7D5D8 800E4128 E7A60010 */  swc1      $f6, 0x10($sp)
/* 7D5DC 800E412C E7B40014 */  swc1      $f20, 0x14($sp)
.L800E4130:
/* 7D5E0 800E4130 0C037D18 */  jal       test_player_lateral
/* 7D5E4 800E4134 00000000 */   nop      
/* 7D5E8 800E4138 A6820000 */  sh        $v0, ($s4)
.L800E413C:
/* 7D5EC 800E413C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7D5F0 800E4140 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 7D5F4 800E4144 3C018011 */  lui       $at, 0x8011
/* 7D5F8 800E4148 D436BED8 */  ldc1      $f22, -0x4128($at)
/* 7D5FC 800E414C 4600A521 */  cvt.d.s   $f20, $f20
/* 7D600 800E4150 E7A0003C */  swc1      $f0, 0x3c($sp)
/* 7D604 800E4154 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 7D608 800E4158 4636A301 */  sub.d     $f12, $f20, $f22
/* 7D60C 800E415C E7A20040 */  swc1      $f2, 0x40($sp)
/* 7D610 800E4160 E7A00044 */  swc1      $f0, 0x44($sp)
/* 7D614 800E4164 0C00A6C9 */  jal       clamp_angle
/* 7D618 800E4168 46206320 */   cvt.s.d  $f12, $f12
/* 7D61C 800E416C 0000202D */  daddu     $a0, $zero, $zero
/* 7D620 800E4170 0220282D */  daddu     $a1, $s1, $zero
/* 7D624 800E4174 27A6003C */  addiu     $a2, $sp, 0x3c
/* 7D628 800E4178 27A70040 */  addiu     $a3, $sp, 0x40
/* 7D62C 800E417C 27A20044 */  addiu     $v0, $sp, 0x44
/* 7D630 800E4180 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 7D634 800E4184 AFA20010 */  sw        $v0, 0x10($sp)
/* 7D638 800E4188 AFA00014 */  sw        $zero, 0x14($sp)
/* 7D63C 800E418C 0C037B01 */  jal       do_lateral_collision
/* 7D640 800E4190 E7A00018 */   swc1     $f0, 0x18($sp)
/* 7D644 800E4194 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7D648 800E4198 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 7D64C 800E419C 4636A500 */  add.d     $f20, $f20, $f22
/* 7D650 800E41A0 E7A00048 */  swc1      $f0, 0x48($sp)
/* 7D654 800E41A4 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 7D658 800E41A8 0040802D */  daddu     $s0, $v0, $zero
/* 7D65C 800E41AC E7A20050 */  swc1      $f2, 0x50($sp)
/* 7D660 800E41B0 4620A320 */  cvt.s.d   $f12, $f20
/* 7D664 800E41B4 0C00A6C9 */  jal       clamp_angle
/* 7D668 800E41B8 E7A0004C */   swc1     $f0, 0x4c($sp)
/* 7D66C 800E41BC 0000202D */  daddu     $a0, $zero, $zero
/* 7D670 800E41C0 0220282D */  daddu     $a1, $s1, $zero
/* 7D674 800E41C4 27A60048 */  addiu     $a2, $sp, 0x48
/* 7D678 800E41C8 27A7004C */  addiu     $a3, $sp, 0x4c
/* 7D67C 800E41CC 27A20050 */  addiu     $v0, $sp, 0x50
/* 7D680 800E41D0 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 7D684 800E41D4 AFA20010 */  sw        $v0, 0x10($sp)
/* 7D688 800E41D8 AFA00014 */  sw        $zero, 0x14($sp)
/* 7D68C 800E41DC 0C037B01 */  jal       do_lateral_collision
/* 7D690 800E41E0 E7A00018 */   swc1     $f0, 0x18($sp)
/* 7D694 800E41E4 0601000B */  bgez      $s0, .L800E4214
/* 7D698 800E41E8 00000000 */   nop      
/* 7D69C 800E41EC 04410005 */  bgez      $v0, .L800E4204
/* 7D6A0 800E41F0 00000000 */   nop      
/* 7D6A4 800E41F4 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7D6A8 800E41F8 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 7D6AC 800E41FC 0803908A */  j         .L800E4228
/* 7D6B0 800E4200 E6200028 */   swc1     $f0, 0x28($s1)
.L800E4204:
/* 7D6B4 800E4204 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 7D6B8 800E4208 C7A20044 */  lwc1      $f2, 0x44($sp)
/* 7D6BC 800E420C 0803908A */  j         .L800E4228
/* 7D6C0 800E4210 E6200028 */   swc1     $f0, 0x28($s1)
.L800E4214:
/* 7D6C4 800E4214 04410005 */  bgez      $v0, .L800E422C
/* 7D6C8 800E4218 00000000 */   nop      
/* 7D6CC 800E421C C7A00048 */  lwc1      $f0, 0x48($sp)
/* 7D6D0 800E4220 C7A20050 */  lwc1      $f2, 0x50($sp)
/* 7D6D4 800E4224 E6200028 */  swc1      $f0, 0x28($s1)
.L800E4228:
/* 7D6D8 800E4228 E6220030 */  swc1      $f2, 0x30($s1)
.L800E422C:
/* 7D6DC 800E422C 82220014 */  lb        $v0, 0x14($s1)
/* 7D6E0 800E4230 1440002B */  bnez      $v0, .L800E42E0
/* 7D6E4 800E4234 3C030001 */   lui      $v1, 1
/* 7D6E8 800E4238 8E220004 */  lw        $v0, 4($s1)
/* 7D6EC 800E423C 00431024 */  and       $v0, $v0, $v1
/* 7D6F0 800E4240 10400004 */  beqz      $v0, .L800E4254
/* 7D6F4 800E4244 0000202D */   daddu    $a0, $zero, $zero
/* 7D6F8 800E4248 C6340080 */  lwc1      $f20, 0x80($s1)
/* 7D6FC 800E424C 080390A6 */  j         .L800E4298
/* 7D700 800E4250 00000000 */   nop      
.L800E4254:
/* 7D704 800E4254 3C038007 */  lui       $v1, 0x8007
/* 7D708 800E4258 8C637410 */  lw        $v1, 0x7410($v1)
/* 7D70C 800E425C C62200A8 */  lwc1      $f2, 0xa8($s1)
/* 7D710 800E4260 3C0142B4 */  lui       $at, 0x42b4
/* 7D714 800E4264 44810000 */  mtc1      $at, $f0
/* 7D718 800E4268 00031080 */  sll       $v0, $v1, 2
/* 7D71C 800E426C 00431021 */  addu      $v0, $v0, $v1
/* 7D720 800E4270 00021080 */  sll       $v0, $v0, 2
/* 7D724 800E4274 00431023 */  subu      $v0, $v0, $v1
/* 7D728 800E4278 000218C0 */  sll       $v1, $v0, 3
/* 7D72C 800E427C 00431021 */  addu      $v0, $v0, $v1
/* 7D730 800E4280 000210C0 */  sll       $v0, $v0, 3
/* 7D734 800E4284 46001081 */  sub.s     $f2, $f2, $f0
/* 7D738 800E4288 3C01800B */  lui       $at, 0x800b
/* 7D73C 800E428C 00220821 */  addu      $at, $at, $v0
/* 7D740 800E4290 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 7D744 800E4294 46001500 */  add.s     $f20, $f2, $f0
.L800E4298:
/* 7D748 800E4298 4406A000 */  mfc1      $a2, $f20
/* 7D74C 800E429C 0C0390C2 */  jal       collision_check_player_intersecting_world
/* 7D750 800E42A0 0080282D */   daddu    $a1, $a0, $zero
/* 7D754 800E42A4 0441000E */  bgez      $v0, .L800E42E0
/* 7D758 800E42A8 24040001 */   addiu    $a0, $zero, 1
/* 7D75C 800E42AC 862200B0 */  lh        $v0, 0xb0($s1)
/* 7D760 800E42B0 3C013F40 */  lui       $at, 0x3f40
/* 7D764 800E42B4 44811000 */  mtc1      $at, $f2
/* 7D768 800E42B8 44820000 */  mtc1      $v0, $f0
/* 7D76C 800E42BC 00000000 */  nop       
/* 7D770 800E42C0 46800020 */  cvt.s.w   $f0, $f0
/* 7D774 800E42C4 46020002 */  mul.s     $f0, $f0, $f2
/* 7D778 800E42C8 00000000 */  nop       
/* 7D77C 800E42CC 4406A000 */  mfc1      $a2, $f20
/* 7D780 800E42D0 4600040D */  trunc.w.s $f16, $f0
/* 7D784 800E42D4 44058000 */  mfc1      $a1, $f16
.L800E42D8:
/* 7D788 800E42D8 0C0390C2 */  jal       collision_check_player_intersecting_world
/* 7D78C 800E42DC 00000000 */   nop      
.L800E42E0:
/* 7D790 800E42E0 8FBF006C */  lw        $ra, 0x6c($sp)
/* 7D794 800E42E4 8FB40068 */  lw        $s4, 0x68($sp)
/* 7D798 800E42E8 8FB30064 */  lw        $s3, 0x64($sp)
/* 7D79C 800E42EC 8FB20060 */  lw        $s2, 0x60($sp)
/* 7D7A0 800E42F0 8FB1005C */  lw        $s1, 0x5c($sp)
/* 7D7A4 800E42F4 8FB00058 */  lw        $s0, 0x58($sp)
/* 7D7A8 800E42F8 D7B60078 */  ldc1      $f22, 0x78($sp)
/* 7D7AC 800E42FC D7B40070 */  ldc1      $f20, 0x70($sp)
/* 7D7B0 800E4300 03E00008 */  jr        $ra
/* 7D7B4 800E4304 27BD0080 */   addiu    $sp, $sp, 0x80
