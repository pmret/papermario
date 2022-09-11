.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80234830_6BBA30
.double 0.4

dlabel D_80234838_6BBA38
.double 90.0

dlabel D_80234840_6BBA40
.double 3.6000001430511475

dlabel D_80234848_6BBA48
.double 2.400000035762787

dlabel D_80234850_6BBA50
.double 1.8

dlabel D_80234858_6BBA58
.double 1.440000057220459

dlabel D_80234860_6BBA60
.double 0.6000000000000001

dlabel D_80234868_6BBA68
.double 0.9600000143051148

.section .text

glabel func_8021C520_6A3720
/* 6A3720 8021C520 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 6A3724 8021C524 AFB1001C */  sw        $s1, 0x1c($sp)
/* 6A3728 8021C528 0080882D */  daddu     $s1, $a0, $zero
/* 6A372C 8021C52C AFB20020 */  sw        $s2, 0x20($sp)
/* 6A3730 8021C530 AFBF002C */  sw        $ra, 0x2c($sp)
/* 6A3734 8021C534 AFB40028 */  sw        $s4, 0x28($sp)
/* 6A3738 8021C538 AFB30024 */  sw        $s3, 0x24($sp)
/* 6A373C 8021C53C AFB00018 */  sw        $s0, 0x18($sp)
/* 6A3740 8021C540 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 6A3744 8021C544 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 6A3748 8021C548 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 6A374C 8021C54C F7B40030 */  sdc1      $f20, 0x30($sp)
/* 6A3750 8021C550 8E240148 */  lw        $a0, 0x148($s1)
/* 6A3754 8021C554 8E30000C */  lw        $s0, 0xc($s1)
/* 6A3758 8021C558 0C09A75B */  jal       get_actor
/* 6A375C 8021C55C 00A0902D */   daddu    $s2, $a1, $zero
/* 6A3760 8021C560 0040A02D */  daddu     $s4, $v0, $zero
/* 6A3764 8021C564 128000F7 */  beqz      $s4, .L8021C944
/* 6A3768 8021C568 24020002 */   addiu    $v0, $zero, 2
/* 6A376C 8021C56C 12400041 */  beqz      $s2, .L8021C674
/* 6A3770 8021C570 0000982D */   daddu    $s3, $zero, $zero
/* 6A3774 8021C574 8E050000 */  lw        $a1, ($s0)
/* 6A3778 8021C578 26100004 */  addiu     $s0, $s0, 4
/* 6A377C 8021C57C 0C0B1EAF */  jal       evt_get_variable
/* 6A3780 8021C580 0220202D */   daddu    $a0, $s1, $zero
/* 6A3784 8021C584 8E050000 */  lw        $a1, ($s0)
/* 6A3788 8021C588 26100004 */  addiu     $s0, $s0, 4
/* 6A378C 8021C58C 4482D000 */  mtc1      $v0, $f26
/* 6A3790 8021C590 00000000 */  nop
/* 6A3794 8021C594 4680D6A0 */  cvt.s.w   $f26, $f26
/* 6A3798 8021C598 0C0B1EAF */  jal       evt_get_variable
/* 6A379C 8021C59C 0220202D */   daddu    $a0, $s1, $zero
/* 6A37A0 8021C5A0 8E050000 */  lw        $a1, ($s0)
/* 6A37A4 8021C5A4 26100004 */  addiu     $s0, $s0, 4
/* 6A37A8 8021C5A8 4482C000 */  mtc1      $v0, $f24
/* 6A37AC 8021C5AC 00000000 */  nop
/* 6A37B0 8021C5B0 4680C620 */  cvt.s.w   $f24, $f24
/* 6A37B4 8021C5B4 0C0B1EAF */  jal       evt_get_variable
/* 6A37B8 8021C5B8 0220202D */   daddu    $a0, $s1, $zero
/* 6A37BC 8021C5BC 8E050000 */  lw        $a1, ($s0)
/* 6A37C0 8021C5C0 4482B000 */  mtc1      $v0, $f22
/* 6A37C4 8021C5C4 00000000 */  nop
/* 6A37C8 8021C5C8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 6A37CC 8021C5CC 0C0B210B */  jal       evt_get_float_variable
/* 6A37D0 8021C5D0 0220202D */   daddu    $a0, $s1, $zero
/* 6A37D4 8021C5D4 82830210 */  lb        $v1, 0x210($s4)
/* 6A37D8 8021C5D8 2402000A */  addiu     $v0, $zero, 0xa
/* 6A37DC 8021C5DC 14620007 */  bne       $v1, $v0, .L8021C5FC
/* 6A37E0 8021C5E0 46000506 */   mov.s    $f20, $f0
/* 6A37E4 8021C5E4 3C018023 */  lui       $at, %hi(D_80234830_6BBA30)
/* 6A37E8 8021C5E8 D4224830 */  ldc1      $f2, %lo(D_80234830_6BBA30)($at)
/* 6A37EC 8021C5EC 4600A021 */  cvt.d.s   $f0, $f20
/* 6A37F0 8021C5F0 46220002 */  mul.d     $f0, $f0, $f2
/* 6A37F4 8021C5F4 00000000 */  nop
/* 6A37F8 8021C5F8 46200520 */  cvt.s.d   $f20, $f0
.L8021C5FC:
/* 6A37FC 8021C5FC 0C00AB39 */  jal       heap_malloc
/* 6A3800 8021C600 2404009C */   addiu    $a0, $zero, 0x9c
/* 6A3804 8021C604 0040882D */  daddu     $s1, $v0, $zero
/* 6A3808 8021C608 0000902D */  daddu     $s2, $zero, $zero
/* 6A380C 8021C60C 24060032 */  addiu     $a2, $zero, 0x32
/* 6A3810 8021C610 240500FF */  addiu     $a1, $zero, 0xff
/* 6A3814 8021C614 24040001 */  addiu     $a0, $zero, 1
/* 6A3818 8021C618 3C0142B4 */  lui       $at, 0x42b4
/* 6A381C 8021C61C 44810000 */  mtc1      $at, $f0
/* 6A3820 8021C620 26230030 */  addiu     $v1, $s1, 0x30
/* 6A3824 8021C624 AE910078 */  sw        $s1, 0x78($s4)
.L8021C628:
/* 6A3828 8021C628 E47AFFD4 */  swc1      $f26, -0x2c($v1)
/* 6A382C 8021C62C E478FFD8 */  swc1      $f24, -0x28($v1)
/* 6A3830 8021C630 E476FFDC */  swc1      $f22, -0x24($v1)
/* 6A3834 8021C634 E474FFE0 */  swc1      $f20, -0x20($v1)
/* 6A3838 8021C638 AC64FFE4 */  sw        $a0, -0x1c($v1)
/* 6A383C 8021C63C AC66FFE8 */  sw        $a2, -0x18($v1)
/* 6A3840 8021C640 AC65FFEC */  sw        $a1, -0x14($v1)
/* 6A3844 8021C644 AC65FFF0 */  sw        $a1, -0x10($v1)
/* 6A3848 8021C648 E460FFF4 */  swc1      $f0, -0xc($v1)
/* 6A384C 8021C64C AC60FFF8 */  sw        $zero, -8($v1)
/* 6A3850 8021C650 AC60FFFC */  sw        $zero, -4($v1)
/* 6A3854 8021C654 AC600000 */  sw        $zero, ($v1)
/* 6A3858 8021C658 24630034 */  addiu     $v1, $v1, 0x34
/* 6A385C 8021C65C 26520001 */  addiu     $s2, $s2, 1
/* 6A3860 8021C660 2A420003 */  slti      $v0, $s2, 3
/* 6A3864 8021C664 1440FFF0 */  bnez      $v0, .L8021C628
/* 6A3868 8021C668 24840010 */   addiu    $a0, $a0, 0x10
/* 6A386C 8021C66C 08087251 */  j         .L8021C944
/* 6A3870 8021C670 0000102D */   daddu    $v0, $zero, $zero
.L8021C674:
/* 6A3874 8021C674 8E910078 */  lw        $s1, 0x78($s4)
/* 6A3878 8021C678 0260902D */  daddu     $s2, $s3, $zero
/* 6A387C 8021C67C 26300030 */  addiu     $s0, $s1, 0x30
.L8021C680:
/* 6A3880 8021C680 8E02FFE4 */  lw        $v0, -0x1c($s0)
/* 6A3884 8021C684 18400019 */  blez      $v0, .L8021C6EC
/* 6A3888 8021C688 2442FFFF */   addiu    $v0, $v0, -1
/* 6A388C 8021C68C 1C4000A2 */  bgtz      $v0, .L8021C918
/* 6A3890 8021C690 AE02FFE4 */   sw       $v0, -0x1c($s0)
/* 6A3894 8021C694 C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 6A3898 8021C698 2402FFFF */  addiu     $v0, $zero, -1
/* 6A389C 8021C69C AFA20014 */  sw        $v0, 0x14($sp)
/* 6A38A0 8021C6A0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6A38A4 8021C6A4 8E05FFD4 */  lw        $a1, -0x2c($s0)
/* 6A38A8 8021C6A8 8E06FFD8 */  lw        $a2, -0x28($s0)
/* 6A38AC 8021C6AC 8E07FFDC */  lw        $a3, -0x24($s0)
/* 6A38B0 8021C6B0 0C01CA9C */  jal       fx_star_outline
/* 6A38B4 8021C6B4 0000202D */   daddu    $a0, $zero, $zero
/* 6A38B8 8021C6B8 AE220000 */  sw        $v0, ($s1)
/* 6A38BC 8021C6BC 8C42000C */  lw        $v0, 0xc($v0)
/* 6A38C0 8021C6C0 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 6A38C4 8021C6C4 E440003C */  swc1      $f0, 0x3c($v0)
/* 6A38C8 8021C6C8 8E220000 */  lw        $v0, ($s1)
/* 6A38CC 8021C6CC C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A38D0 8021C6D0 8C42000C */  lw        $v0, 0xc($v0)
/* 6A38D4 8021C6D4 E4400040 */  swc1      $f0, 0x40($v0)
/* 6A38D8 8021C6D8 8E220000 */  lw        $v0, ($s1)
/* 6A38DC 8021C6DC C600FFFC */  lwc1      $f0, -4($s0)
/* 6A38E0 8021C6E0 8C42000C */  lw        $v0, 0xc($v0)
/* 6A38E4 8021C6E4 08087246 */  j         .L8021C918
/* 6A38E8 8021C6E8 E4400044 */   swc1     $f0, 0x44($v0)
.L8021C6EC:
/* 6A38EC 8021C6EC 8E020000 */  lw        $v0, ($s0)
/* 6A38F0 8021C6F0 10400003 */  beqz      $v0, .L8021C700
/* 6A38F4 8021C6F4 2402000A */   addiu    $v0, $zero, 0xa
/* 6A38F8 8021C6F8 08087246 */  j         .L8021C918
/* 6A38FC 8021C6FC 26730001 */   addiu    $s3, $s3, 1
.L8021C700:
/* 6A3900 8021C700 82830210 */  lb        $v1, 0x210($s4)
/* 6A3904 8021C704 10620021 */  beq       $v1, $v0, .L8021C78C
/* 6A3908 8021C708 00000000 */   nop
/* 6A390C 8021C70C C602FFD8 */  lwc1      $f2, -0x28($s0)
/* 6A3910 8021C710 3C01404E */  lui       $at, 0x404e
/* 6A3914 8021C714 44810800 */  mtc1      $at, $f1
/* 6A3918 8021C718 44800000 */  mtc1      $zero, $f0
/* 6A391C 8021C71C 460010A1 */  cvt.d.s   $f2, $f2
/* 6A3920 8021C720 4620103C */  c.lt.d    $f2, $f0
/* 6A3924 8021C724 3C014012 */  lui       $at, 0x4012
/* 6A3928 8021C728 44810800 */  mtc1      $at, $f1
/* 6A392C 8021C72C 44800000 */  mtc1      $zero, $f0
/* 6A3930 8021C730 45030035 */  bc1tl     .L8021C808
/* 6A3934 8021C734 46201000 */   add.d    $f0, $f2, $f0
/* 6A3938 8021C738 3C018023 */  lui       $at, %hi(D_80234838_6BBA38)
/* 6A393C 8021C73C D4204838 */  ldc1      $f0, %lo(D_80234838_6BBA38)($at)
/* 6A3940 8021C740 4620103C */  c.lt.d    $f2, $f0
/* 6A3944 8021C744 3C018023 */  lui       $at, %hi(D_80234840_6BBA40)
/* 6A3948 8021C748 D4204840 */  ldc1      $f0, %lo(D_80234840_6BBA40)($at)
/* 6A394C 8021C74C 4503002E */  bc1tl     .L8021C808
/* 6A3950 8021C750 46201000 */   add.d    $f0, $f2, $f0
/* 6A3954 8021C754 3C01405E */  lui       $at, 0x405e
/* 6A3958 8021C758 44810800 */  mtc1      $at, $f1
/* 6A395C 8021C75C 44800000 */  mtc1      $zero, $f0
/* 6A3960 8021C760 00000000 */  nop
/* 6A3964 8021C764 4620103C */  c.lt.d    $f2, $f0
/* 6A3968 8021C768 3C018023 */  lui       $at, %hi(D_80234848_6BBA48)
/* 6A396C 8021C76C D4204848 */  ldc1      $f0, %lo(D_80234848_6BBA48)($at)
/* 6A3970 8021C770 45030025 */  bc1tl     .L8021C808
/* 6A3974 8021C774 46201000 */   add.d    $f0, $f2, $f0
/* 6A3978 8021C778 3C013FF8 */  lui       $at, 0x3ff8
/* 6A397C 8021C77C 44810800 */  mtc1      $at, $f1
/* 6A3980 8021C780 44800000 */  mtc1      $zero, $f0
/* 6A3984 8021C784 08087202 */  j         .L8021C808
/* 6A3988 8021C788 46201000 */   add.d    $f0, $f2, $f0
.L8021C78C:
/* 6A398C 8021C78C C602FFD8 */  lwc1      $f2, -0x28($s0)
/* 6A3990 8021C790 3C014038 */  lui       $at, 0x4038
/* 6A3994 8021C794 44810800 */  mtc1      $at, $f1
/* 6A3998 8021C798 44800000 */  mtc1      $zero, $f0
/* 6A399C 8021C79C 460010A1 */  cvt.d.s   $f2, $f2
/* 6A39A0 8021C7A0 4620103C */  c.lt.d    $f2, $f0
/* 6A39A4 8021C7A4 3C018023 */  lui       $at, %hi(D_80234850_6BBA50)
/* 6A39A8 8021C7A8 D4204850 */  ldc1      $f0, %lo(D_80234850_6BBA50)($at)
/* 6A39AC 8021C7AC 45030016 */  bc1tl     .L8021C808
/* 6A39B0 8021C7B0 46201000 */   add.d    $f0, $f2, $f0
/* 6A39B4 8021C7B4 3C014042 */  lui       $at, 0x4042
/* 6A39B8 8021C7B8 44810800 */  mtc1      $at, $f1
/* 6A39BC 8021C7BC 44800000 */  mtc1      $zero, $f0
/* 6A39C0 8021C7C0 00000000 */  nop
/* 6A39C4 8021C7C4 4620103C */  c.lt.d    $f2, $f0
/* 6A39C8 8021C7C8 3C018023 */  lui       $at, %hi(D_80234858_6BBA58)
/* 6A39CC 8021C7CC D4204858 */  ldc1      $f0, %lo(D_80234858_6BBA58)($at)
/* 6A39D0 8021C7D0 4503000D */  bc1tl     .L8021C808
/* 6A39D4 8021C7D4 46201000 */   add.d    $f0, $f2, $f0
/* 6A39D8 8021C7D8 3C014048 */  lui       $at, 0x4048
/* 6A39DC 8021C7DC 44810800 */  mtc1      $at, $f1
/* 6A39E0 8021C7E0 44800000 */  mtc1      $zero, $f0
/* 6A39E4 8021C7E4 00000000 */  nop
/* 6A39E8 8021C7E8 4620103C */  c.lt.d    $f2, $f0
/* 6A39EC 8021C7EC 3C018023 */  lui       $at, %hi(D_80234860_6BBA60)
/* 6A39F0 8021C7F0 D4204860 */  ldc1      $f0, %lo(D_80234860_6BBA60)($at)
/* 6A39F4 8021C7F4 45020004 */  bc1fl     .L8021C808
/* 6A39F8 8021C7F8 46201000 */   add.d    $f0, $f2, $f0
/* 6A39FC 8021C7FC 3C018023 */  lui       $at, %hi(D_80234868_6BBA68)
/* 6A3A00 8021C800 D4204868 */  ldc1      $f0, %lo(D_80234868_6BBA68)($at)
/* 6A3A04 8021C804 46201000 */  add.d     $f0, $f2, $f0
.L8021C808:
/* 6A3A08 8021C808 46200020 */  cvt.s.d   $f0, $f0
/* 6A3A0C 8021C80C E600FFD8 */  swc1      $f0, -0x28($s0)
/* 6A3A10 8021C810 C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A3A14 8021C814 3C014190 */  lui       $at, 0x4190
/* 6A3A18 8021C818 44811000 */  mtc1      $at, $f2
/* 6A3A1C 8021C81C 8E03FFE8 */  lw        $v1, -0x18($s0)
/* 6A3A20 8021C820 46020000 */  add.s     $f0, $f0, $f2
/* 6A3A24 8021C824 28620011 */  slti      $v0, $v1, 0x11
/* 6A3A28 8021C828 1040000E */  beqz      $v0, .L8021C864
/* 6A3A2C 8021C82C E600FFF8 */   swc1     $f0, -8($s0)
/* 6A3A30 8021C830 00031200 */  sll       $v0, $v1, 8
/* 6A3A34 8021C834 00431823 */  subu      $v1, $v0, $v1
/* 6A3A38 8021C838 04620001 */  bltzl     $v1, .L8021C840
/* 6A3A3C 8021C83C 2463000F */   addiu    $v1, $v1, 0xf
.L8021C840:
/* 6A3A40 8021C840 8E02FFE8 */  lw        $v0, -0x18($s0)
/* 6A3A44 8021C844 00031903 */  sra       $v1, $v1, 4
/* 6A3A48 8021C848 AE03FFEC */  sw        $v1, -0x14($s0)
/* 6A3A4C 8021C84C 00021A00 */  sll       $v1, $v0, 8
/* 6A3A50 8021C850 00621023 */  subu      $v0, $v1, $v0
/* 6A3A54 8021C854 04420001 */  bltzl     $v0, .L8021C85C
/* 6A3A58 8021C858 2442000F */   addiu    $v0, $v0, 0xf
.L8021C85C:
/* 6A3A5C 8021C85C 00021103 */  sra       $v0, $v0, 4
/* 6A3A60 8021C860 AE02FFF0 */  sw        $v0, -0x10($s0)
.L8021C864:
/* 6A3A64 8021C864 8E220000 */  lw        $v0, ($s1)
/* 6A3A68 8021C868 C600FFD4 */  lwc1      $f0, -0x2c($s0)
/* 6A3A6C 8021C86C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A3A70 8021C870 E4400004 */  swc1      $f0, 4($v0)
/* 6A3A74 8021C874 8E220000 */  lw        $v0, ($s1)
/* 6A3A78 8021C878 C600FFD8 */  lwc1      $f0, -0x28($s0)
/* 6A3A7C 8021C87C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A3A80 8021C880 E4400008 */  swc1      $f0, 8($v0)
/* 6A3A84 8021C884 8E220000 */  lw        $v0, ($s1)
/* 6A3A88 8021C888 C600FFDC */  lwc1      $f0, -0x24($s0)
/* 6A3A8C 8021C88C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A3A90 8021C890 E440000C */  swc1      $f0, 0xc($v0)
/* 6A3A94 8021C894 8E220000 */  lw        $v0, ($s1)
/* 6A3A98 8021C898 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 6A3A9C 8021C89C 8C42000C */  lw        $v0, 0xc($v0)
/* 6A3AA0 8021C8A0 E440003C */  swc1      $f0, 0x3c($v0)
/* 6A3AA4 8021C8A4 8E220000 */  lw        $v0, ($s1)
/* 6A3AA8 8021C8A8 C600FFF8 */  lwc1      $f0, -8($s0)
/* 6A3AAC 8021C8AC 8C42000C */  lw        $v0, 0xc($v0)
/* 6A3AB0 8021C8B0 E4400040 */  swc1      $f0, 0x40($v0)
/* 6A3AB4 8021C8B4 8E220000 */  lw        $v0, ($s1)
/* 6A3AB8 8021C8B8 C600FFFC */  lwc1      $f0, -4($s0)
/* 6A3ABC 8021C8BC 8C42000C */  lw        $v0, 0xc($v0)
/* 6A3AC0 8021C8C0 E4400044 */  swc1      $f0, 0x44($v0)
/* 6A3AC4 8021C8C4 8E220000 */  lw        $v0, ($s1)
/* 6A3AC8 8021C8C8 C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 6A3ACC 8021C8CC 8C42000C */  lw        $v0, 0xc($v0)
/* 6A3AD0 8021C8D0 E4400038 */  swc1      $f0, 0x38($v0)
/* 6A3AD4 8021C8D4 8E220000 */  lw        $v0, ($s1)
/* 6A3AD8 8021C8D8 8C43000C */  lw        $v1, 0xc($v0)
/* 6A3ADC 8021C8DC 8E02FFEC */  lw        $v0, -0x14($s0)
/* 6A3AE0 8021C8E0 AC620024 */  sw        $v0, 0x24($v1)
/* 6A3AE4 8021C8E4 8E220000 */  lw        $v0, ($s1)
/* 6A3AE8 8021C8E8 8C43000C */  lw        $v1, 0xc($v0)
/* 6A3AEC 8021C8EC 8E02FFF0 */  lw        $v0, -0x10($s0)
/* 6A3AF0 8021C8F0 AC620034 */  sw        $v0, 0x34($v1)
/* 6A3AF4 8021C8F4 8E02FFE8 */  lw        $v0, -0x18($s0)
/* 6A3AF8 8021C8F8 2442FFFF */  addiu     $v0, $v0, -1
/* 6A3AFC 8021C8FC 1C400006 */  bgtz      $v0, .L8021C918
/* 6A3B00 8021C900 AE02FFE8 */   sw       $v0, -0x18($s0)
/* 6A3B04 8021C904 8E240000 */  lw        $a0, ($s1)
/* 6A3B08 8021C908 0C016914 */  jal       remove_effect
/* 6A3B0C 8021C90C 00000000 */   nop
/* 6A3B10 8021C910 24020001 */  addiu     $v0, $zero, 1
/* 6A3B14 8021C914 AE020000 */  sw        $v0, ($s0)
.L8021C918:
/* 6A3B18 8021C918 26100034 */  addiu     $s0, $s0, 0x34
/* 6A3B1C 8021C91C 26520001 */  addiu     $s2, $s2, 1
/* 6A3B20 8021C920 2A420003 */  slti      $v0, $s2, 3
/* 6A3B24 8021C924 1440FF56 */  bnez      $v0, .L8021C680
/* 6A3B28 8021C928 26310034 */   addiu    $s1, $s1, 0x34
/* 6A3B2C 8021C92C 2A620003 */  slti      $v0, $s3, 3
/* 6A3B30 8021C930 14400004 */  bnez      $v0, .L8021C944
/* 6A3B34 8021C934 0000102D */   daddu    $v0, $zero, $zero
/* 6A3B38 8021C938 0C00AB4B */  jal       heap_free
/* 6A3B3C 8021C93C 0220202D */   daddu    $a0, $s1, $zero
/* 6A3B40 8021C940 24020002 */  addiu     $v0, $zero, 2
.L8021C944:
/* 6A3B44 8021C944 8FBF002C */  lw        $ra, 0x2c($sp)
/* 6A3B48 8021C948 8FB40028 */  lw        $s4, 0x28($sp)
/* 6A3B4C 8021C94C 8FB30024 */  lw        $s3, 0x24($sp)
/* 6A3B50 8021C950 8FB20020 */  lw        $s2, 0x20($sp)
/* 6A3B54 8021C954 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6A3B58 8021C958 8FB00018 */  lw        $s0, 0x18($sp)
/* 6A3B5C 8021C95C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 6A3B60 8021C960 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 6A3B64 8021C964 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 6A3B68 8021C968 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6A3B6C 8021C96C 03E00008 */  jr        $ra
/* 6A3B70 8021C970 27BD0050 */   addiu    $sp, $sp, 0x50
