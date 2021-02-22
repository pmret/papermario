.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407D4_CCBAE4
/* CCBAE4 802407D4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* CCBAE8 802407D8 24040001 */  addiu     $a0, $zero, 1
/* CCBAEC 802407DC 27A50010 */  addiu     $a1, $sp, 0x10
/* CCBAF0 802407E0 27A60014 */  addiu     $a2, $sp, 0x14
/* CCBAF4 802407E4 AFBF0030 */  sw        $ra, 0x30($sp)
/* CCBAF8 802407E8 AFB3002C */  sw        $s3, 0x2c($sp)
/* CCBAFC 802407EC AFB20028 */  sw        $s2, 0x28($sp)
/* CCBB00 802407F0 AFB10024 */  sw        $s1, 0x24($sp)
/* CCBB04 802407F4 AFB00020 */  sw        $s0, 0x20($sp)
/* CCBB08 802407F8 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* CCBB0C 802407FC F7B80048 */  sdc1      $f24, 0x48($sp)
/* CCBB10 80240800 F7B60040 */  sdc1      $f22, 0x40($sp)
/* CCBB14 80240804 F7B40038 */  sdc1      $f20, 0x38($sp)
/* CCBB18 80240808 0C0470AC */  jal       func_8011C2B0
/* CCBB1C 8024080C 27A70018 */   addiu    $a3, $sp, 0x18
/* CCBB20 80240810 8FA20018 */  lw        $v0, 0x18($sp)
/* CCBB24 80240814 18400072 */  blez      $v0, .L802409E0
/* CCBB28 80240818 0000902D */   daddu    $s2, $zero, $zero
/* CCBB2C 8024081C 3C138024 */  lui       $s3, %hi(D_80243B18_CCEE28)
/* CCBB30 80240820 26733B18 */  addiu     $s3, $s3, %lo(D_80243B18_CCEE28)
/* CCBB34 80240824 3C014334 */  lui       $at, 0x4334
/* CCBB38 80240828 4481D000 */  mtc1      $at, $f26
/* CCBB3C 8024082C 3C018024 */  lui       $at, %hi(D_80245330_CD0640)
/* CCBB40 80240830 D4385330 */  ldc1      $f24, %lo(D_80245330_CD0640)($at)
/* CCBB44 80240834 3C018024 */  lui       $at, %hi(D_80245338_CD0648)
/* CCBB48 80240838 D4365338 */  ldc1      $f22, %lo(D_80245338_CD0648)($at)
/* CCBB4C 8024083C 00122100 */  sll       $a0, $s2, 4
.L80240840:
/* CCBB50 80240840 8FA20010 */  lw        $v0, 0x10($sp)
/* CCBB54 80240844 8FA30014 */  lw        $v1, 0x14($sp)
/* CCBB58 80240848 00448021 */  addu      $s0, $v0, $a0
/* CCBB5C 8024084C 86020000 */  lh        $v0, ($s0)
/* CCBB60 80240850 28420259 */  slti      $v0, $v0, 0x259
/* CCBB64 80240854 1040005D */  beqz      $v0, .L802409CC
/* CCBB68 80240858 00648821 */   addu     $s1, $v1, $a0
/* CCBB6C 8024085C C66C0000 */  lwc1      $f12, ($s3)
/* CCBB70 80240860 46806320 */  cvt.s.w   $f12, $f12
/* CCBB74 80240864 461A6303 */  div.s     $f12, $f12, $f26
/* CCBB78 80240868 46006321 */  cvt.d.s   $f12, $f12
/* CCBB7C 8024086C 46386302 */  mul.d     $f12, $f12, $f24
/* CCBB80 80240870 00000000 */  nop
/* CCBB84 80240874 0C00A85B */  jal       sin_rad
/* CCBB88 80240878 46206320 */   cvt.s.d  $f12, $f12
/* CCBB8C 8024087C C66C0000 */  lwc1      $f12, ($s3)
/* CCBB90 80240880 46806320 */  cvt.s.w   $f12, $f12
/* CCBB94 80240884 461A6303 */  div.s     $f12, $f12, $f26
/* CCBB98 80240888 46006321 */  cvt.d.s   $f12, $f12
/* CCBB9C 8024088C 46386302 */  mul.d     $f12, $f12, $f24
/* CCBBA0 80240890 00000000 */  nop
/* CCBBA4 80240894 3C018024 */  lui       $at, %hi(D_80245340_CD0650)
/* CCBBA8 80240898 D4225340 */  ldc1      $f2, %lo(D_80245340_CD0650)($at)
/* CCBBAC 8024089C 46000521 */  cvt.d.s   $f20, $f0
/* CCBBB0 802408A0 4622A502 */  mul.d     $f20, $f20, $f2
/* CCBBB4 802408A4 00000000 */  nop
/* CCBBB8 802408A8 3C018024 */  lui       $at, %hi(D_80245348_CD0658)
/* CCBBBC 802408AC D4205348 */  ldc1      $f0, %lo(D_80245348_CD0658)($at)
/* CCBBC0 802408B0 4620A500 */  add.d     $f20, $f20, $f0
/* CCBBC4 802408B4 46206320 */  cvt.s.d   $f12, $f12
/* CCBBC8 802408B8 0C00A85B */  jal       sin_rad
/* CCBBCC 802408BC 4620A520 */   cvt.s.d  $f20, $f20
/* CCBBD0 802408C0 46000021 */  cvt.d.s   $f0, $f0
/* CCBBD4 802408C4 46360002 */  mul.d     $f0, $f0, $f22
/* CCBBD8 802408C8 00000000 */  nop
/* CCBBDC 802408CC 86020000 */  lh        $v0, ($s0)
/* CCBBE0 802408D0 2442FD98 */  addiu     $v0, $v0, -0x268
/* CCBBE4 802408D4 44822000 */  mtc1      $v0, $f4
/* CCBBE8 802408D8 00000000 */  nop
/* CCBBEC 802408DC 46802120 */  cvt.s.w   $f4, $f4
/* CCBBF0 802408E0 46142102 */  mul.s     $f4, $f4, $f20
/* CCBBF4 802408E4 00000000 */  nop
/* CCBBF8 802408E8 4620B001 */  sub.d     $f0, $f22, $f0
/* CCBBFC 802408EC 3C01C240 */  lui       $at, 0xc240
/* CCBC00 802408F0 44813000 */  mtc1      $at, $f6
/* CCBC04 802408F4 46200020 */  cvt.s.d   $f0, $f0
/* CCBC08 802408F8 46060182 */  mul.s     $f6, $f0, $f6
/* CCBC0C 802408FC 00000000 */  nop
/* CCBC10 80240900 3C01441A */  lui       $at, 0x441a
/* CCBC14 80240904 44811000 */  mtc1      $at, $f2
/* CCBC18 80240908 00000000 */  nop
/* CCBC1C 8024090C 46022100 */  add.s     $f4, $f4, $f2
/* CCBC20 80240910 46062100 */  add.s     $f4, $f4, $f6
/* CCBC24 80240914 3C0141C8 */  lui       $at, 0x41c8
/* CCBC28 80240918 44813000 */  mtc1      $at, $f6
/* CCBC2C 8024091C 00000000 */  nop
/* CCBC30 80240920 46060182 */  mul.s     $f6, $f0, $f6
/* CCBC34 80240924 00000000 */  nop
/* CCBC38 80240928 4600220D */  trunc.w.s $f8, $f4
/* CCBC3C 8024092C 44024000 */  mfc1      $v0, $f8
/* CCBC40 80240930 00000000 */  nop
/* CCBC44 80240934 A6220000 */  sh        $v0, ($s1)
/* CCBC48 80240938 86020002 */  lh        $v0, 2($s0)
/* CCBC4C 8024093C 2442FFD4 */  addiu     $v0, $v0, -0x2c
/* CCBC50 80240940 44821000 */  mtc1      $v0, $f2
/* CCBC54 80240944 00000000 */  nop
/* CCBC58 80240948 468010A0 */  cvt.s.w   $f2, $f2
/* CCBC5C 8024094C 46141082 */  mul.s     $f2, $f2, $f20
/* CCBC60 80240950 00000000 */  nop
/* CCBC64 80240954 3C014230 */  lui       $at, 0x4230
/* CCBC68 80240958 44812000 */  mtc1      $at, $f4
/* CCBC6C 8024095C 00000000 */  nop
/* CCBC70 80240960 46041080 */  add.s     $f2, $f2, $f4
/* CCBC74 80240964 46061080 */  add.s     $f2, $f2, $f6
/* CCBC78 80240968 3C01C2AE */  lui       $at, 0xc2ae
/* CCBC7C 8024096C 44812000 */  mtc1      $at, $f4
/* CCBC80 80240970 00000000 */  nop
/* CCBC84 80240974 46040002 */  mul.s     $f0, $f0, $f4
/* CCBC88 80240978 00000000 */  nop
/* CCBC8C 8024097C 4600120D */  trunc.w.s $f8, $f2
/* CCBC90 80240980 44024000 */  mfc1      $v0, $f8
/* CCBC94 80240984 00000000 */  nop
/* CCBC98 80240988 A6220002 */  sh        $v0, 2($s1)
/* CCBC9C 8024098C 86020004 */  lh        $v0, 4($s0)
/* CCBCA0 80240990 2442FF8F */  addiu     $v0, $v0, -0x71
/* CCBCA4 80240994 44821000 */  mtc1      $v0, $f2
/* CCBCA8 80240998 00000000 */  nop
/* CCBCAC 8024099C 468010A0 */  cvt.s.w   $f2, $f2
/* CCBCB0 802409A0 46141082 */  mul.s     $f2, $f2, $f20
/* CCBCB4 802409A4 00000000 */  nop
/* CCBCB8 802409A8 3C0142E2 */  lui       $at, 0x42e2
/* CCBCBC 802409AC 44812000 */  mtc1      $at, $f4
/* CCBCC0 802409B0 00000000 */  nop
/* CCBCC4 802409B4 46041080 */  add.s     $f2, $f2, $f4
/* CCBCC8 802409B8 46001080 */  add.s     $f2, $f2, $f0
/* CCBCCC 802409BC 4600120D */  trunc.w.s $f8, $f2
/* CCBCD0 802409C0 44024000 */  mfc1      $v0, $f8
/* CCBCD4 802409C4 00000000 */  nop
/* CCBCD8 802409C8 A6220004 */  sh        $v0, 4($s1)
.L802409CC:
/* CCBCDC 802409CC 8FA20018 */  lw        $v0, 0x18($sp)
/* CCBCE0 802409D0 26520001 */  addiu     $s2, $s2, 1
/* CCBCE4 802409D4 0242102A */  slt       $v0, $s2, $v0
/* CCBCE8 802409D8 1440FF99 */  bnez      $v0, .L80240840
/* CCBCEC 802409DC 00122100 */   sll      $a0, $s2, 4
.L802409E0:
/* CCBCF0 802409E0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* CCBCF4 802409E4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* CCBCF8 802409E8 8C620000 */  lw        $v0, ($v1)
/* CCBCFC 802409EC 24040001 */  addiu     $a0, $zero, 1
/* CCBD00 802409F0 0040802D */  daddu     $s0, $v0, $zero
/* CCBD04 802409F4 24420008 */  addiu     $v0, $v0, 8
/* CCBD08 802409F8 AC620000 */  sw        $v0, ($v1)
/* CCBD0C 802409FC 3C02DE00 */  lui       $v0, 0xde00
/* CCBD10 80240A00 0C0470BB */  jal       func_8011C2EC
/* CCBD14 80240A04 AE020000 */   sw       $v0, ($s0)
/* CCBD18 80240A08 0000202D */  daddu     $a0, $zero, $zero
/* CCBD1C 80240A0C 3C05F971 */  lui       $a1, 0xf971
/* CCBD20 80240A10 34A588A4 */  ori       $a1, $a1, 0x88a4
/* CCBD24 80240A14 0C0B1EAF */  jal       get_variable
/* CCBD28 80240A18 AE020004 */   sw       $v0, 4($s0)
/* CCBD2C 80240A1C 10400017 */  beqz      $v0, .L80240A7C
/* CCBD30 80240A20 00000000 */   nop
/* CCBD34 80240A24 3C048024 */  lui       $a0, %hi(D_80243B18_CCEE28)
/* CCBD38 80240A28 24843B18 */  addiu     $a0, $a0, %lo(D_80243B18_CCEE28)
/* CCBD3C 80240A2C 8C830000 */  lw        $v1, ($a0)
/* CCBD40 80240A30 2862005B */  slti      $v0, $v1, 0x5b
/* CCBD44 80240A34 14400005 */  bnez      $v0, .L80240A4C
/* CCBD48 80240A38 2862FFA6 */   slti     $v0, $v1, -0x5a
/* CCBD4C 80240A3C 2462FE98 */  addiu     $v0, $v1, -0x168
/* CCBD50 80240A40 AC820000 */  sw        $v0, ($a0)
/* CCBD54 80240A44 8C830000 */  lw        $v1, ($a0)
/* CCBD58 80240A48 2862FFA6 */  slti      $v0, $v1, -0x5a
.L80240A4C:
/* CCBD5C 80240A4C 14400002 */  bnez      $v0, .L80240A58
/* CCBD60 80240A50 24620014 */   addiu    $v0, $v1, 0x14
/* CCBD64 80240A54 24620005 */  addiu     $v0, $v1, 5
.L80240A58:
/* CCBD68 80240A58 AC820000 */  sw        $v0, ($a0)
/* CCBD6C 80240A5C 3C038024 */  lui       $v1, %hi(D_80243B18_CCEE28)
/* CCBD70 80240A60 24633B18 */  addiu     $v1, $v1, %lo(D_80243B18_CCEE28)
/* CCBD74 80240A64 8C620000 */  lw        $v0, ($v1)
/* CCBD78 80240A68 2842005A */  slti      $v0, $v0, 0x5a
/* CCBD7C 80240A6C 14400013 */  bnez      $v0, .L80240ABC
/* CCBD80 80240A70 2402005A */   addiu    $v0, $zero, 0x5a
/* CCBD84 80240A74 080902AF */  j         .L80240ABC
/* CCBD88 80240A78 AC620000 */   sw       $v0, ($v1)
.L80240A7C:
/* CCBD8C 80240A7C 3C028024 */  lui       $v0, %hi(D_80243B18_CCEE28)
/* CCBD90 80240A80 8C423B18 */  lw        $v0, %lo(D_80243B18_CCEE28)($v0)
/* CCBD94 80240A84 2442FF73 */  addiu     $v0, $v0, -0x8d
/* CCBD98 80240A88 2C420077 */  sltiu     $v0, $v0, 0x77
/* CCBD9C 80240A8C 10400004 */  beqz      $v0, .L80240AA0
/* CCBDA0 80240A90 24020001 */   addiu    $v0, $zero, 1
/* CCBDA4 80240A94 3C018024 */  lui       $at, %hi(D_802431CC_CCE4DC)
/* CCBDA8 80240A98 080902AA */  j         .L80240AA8
/* CCBDAC 80240A9C AC2231CC */   sw       $v0, %lo(D_802431CC_CCE4DC)($at)
.L80240AA0:
/* CCBDB0 80240AA0 3C018024 */  lui       $at, %hi(D_802431CC_CCE4DC)
/* CCBDB4 80240AA4 AC2031CC */  sw        $zero, %lo(D_802431CC_CCE4DC)($at)
.L80240AA8:
/* CCBDB8 80240AA8 3C038024 */  lui       $v1, %hi(D_80243B18_CCEE28)
/* CCBDBC 80240AAC 24633B18 */  addiu     $v1, $v1, %lo(D_80243B18_CCEE28)
/* CCBDC0 80240AB0 8C620000 */  lw        $v0, ($v1)
/* CCBDC4 80240AB4 24420005 */  addiu     $v0, $v0, 5
/* CCBDC8 80240AB8 AC620000 */  sw        $v0, ($v1)
.L80240ABC:
/* CCBDCC 80240ABC 3C048024 */  lui       $a0, %hi(D_80243B18_CCEE28)
/* CCBDD0 80240AC0 24843B18 */  addiu     $a0, $a0, %lo(D_80243B18_CCEE28)
/* CCBDD4 80240AC4 8C830000 */  lw        $v1, ($a0)
/* CCBDD8 80240AC8 28620168 */  slti      $v0, $v1, 0x168
/* CCBDDC 80240ACC 14400002 */  bnez      $v0, .L80240AD8
/* CCBDE0 80240AD0 2462FE98 */   addiu    $v0, $v1, -0x168
/* CCBDE4 80240AD4 AC820000 */  sw        $v0, ($a0)
.L80240AD8:
/* CCBDE8 80240AD8 8FBF0030 */  lw        $ra, 0x30($sp)
/* CCBDEC 80240ADC 8FB3002C */  lw        $s3, 0x2c($sp)
/* CCBDF0 80240AE0 8FB20028 */  lw        $s2, 0x28($sp)
/* CCBDF4 80240AE4 8FB10024 */  lw        $s1, 0x24($sp)
/* CCBDF8 80240AE8 8FB00020 */  lw        $s0, 0x20($sp)
/* CCBDFC 80240AEC D7BA0050 */  ldc1      $f26, 0x50($sp)
/* CCBE00 80240AF0 D7B80048 */  ldc1      $f24, 0x48($sp)
/* CCBE04 80240AF4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* CCBE08 80240AF8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* CCBE0C 80240AFC 03E00008 */  jr        $ra
/* CCBE10 80240B00 27BD0058 */   addiu    $sp, $sp, 0x58
/* CCBE14 80240B04 00000000 */  nop
/* CCBE18 80240B08 00000000 */  nop
/* CCBE1C 80240B0C 00000000 */  nop
