.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A4000
/* 3A37E0 E00A4000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3A37E4 E00A4004 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3A37E8 E00A4008 4485B000 */  mtc1      $a1, $f22
/* 3A37EC E00A400C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3A37F0 E00A4010 4486C000 */  mtc1      $a2, $f24
/* 3A37F4 E00A4014 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 3A37F8 E00A4018 4487D000 */  mtc1      $a3, $f26
/* 3A37FC E00A401C AFB1002C */  sw        $s1, 0x2c($sp)
/* 3A3800 E00A4020 0080882D */  daddu     $s1, $a0, $zero
/* 3A3804 E00A4024 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3A3808 E00A4028 C7B40068 */  lwc1      $f20, 0x68($sp)
/* 3A380C E00A402C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A3810 E00A4030 AFB20030 */  sw        $s2, 0x30($sp)
/* 3A3814 E00A4034 8FB2006C */  lw        $s2, 0x6c($sp)
/* 3A3818 E00A4038 3C02E00A */  lui       $v0, %hi(func_E00A41A4)
/* 3A381C E00A403C 244241A4 */  addiu     $v0, $v0, %lo(func_E00A41A4)
/* 3A3820 E00A4040 AFA20018 */  sw        $v0, 0x18($sp)
/* 3A3824 E00A4044 3C02E00A */  lui       $v0, %hi(func_E00A41AC)
/* 3A3828 E00A4048 244241AC */  addiu     $v0, $v0, %lo(func_E00A41AC)
/* 3A382C E00A404C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3A3830 E00A4050 3C02E00A */  lui       $v0, %hi(func_E00A45DC)
/* 3A3834 E00A4054 244245DC */  addiu     $v0, $v0, %lo(func_E00A45DC)
/* 3A3838 E00A4058 AFA20020 */  sw        $v0, 0x20($sp)
/* 3A383C E00A405C 24020052 */  addiu     $v0, $zero, 0x52
/* 3A3840 E00A4060 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3A3844 E00A4064 AFB00028 */  sw        $s0, 0x28($sp)
/* 3A3848 E00A4068 AFA00010 */  sw        $zero, 0x10($sp)
/* 3A384C E00A406C AFA00024 */  sw        $zero, 0x24($sp)
/* 3A3850 E00A4070 0C080124 */  jal       func_E0200490
/* 3A3854 E00A4074 AFA20014 */   sw       $v0, 0x14($sp)
/* 3A3858 E00A4078 24040038 */  addiu     $a0, $zero, 0x38
/* 3A385C E00A407C 24030001 */  addiu     $v1, $zero, 1
/* 3A3860 E00A4080 0040802D */  daddu     $s0, $v0, $zero
/* 3A3864 E00A4084 0C08012C */  jal       func_E02004B0
/* 3A3868 E00A4088 AE030008 */   sw       $v1, 8($s0)
/* 3A386C E00A408C 0040182D */  daddu     $v1, $v0, $zero
/* 3A3870 E00A4090 14600003 */  bnez      $v1, .LE00A40A0
/* 3A3874 E00A4094 AE02000C */   sw       $v0, 0xc($s0)
.LE00A4098:
/* 3A3878 E00A4098 08029026 */  j         .LE00A4098
/* 3A387C E00A409C 00000000 */   nop
.LE00A40A0:
/* 3A3880 E00A40A0 AC710000 */  sw        $s1, ($v1)
/* 3A3884 E00A40A4 1E400004 */  bgtz      $s2, .LE00A40B8
/* 3A3888 E00A40A8 AC600014 */   sw       $zero, 0x14($v1)
/* 3A388C E00A40AC 24020064 */  addiu     $v0, $zero, 0x64
/* 3A3890 E00A40B0 0802902F */  j         .LE00A40BC
/* 3A3894 E00A40B4 AC620010 */   sw       $v0, 0x10($v1)
.LE00A40B8:
/* 3A3898 E00A40B8 AC720010 */  sw        $s2, 0x10($v1)
.LE00A40BC:
/* 3A389C E00A40BC 2E220007 */  sltiu     $v0, $s1, 7
/* 3A38A0 E00A40C0 AC60002C */  sw        $zero, 0x2c($v1)
/* 3A38A4 E00A40C4 E4760004 */  swc1      $f22, 4($v1)
/* 3A38A8 E00A40C8 E4780008 */  swc1      $f24, 8($v1)
/* 3A38AC E00A40CC E47A000C */  swc1      $f26, 0xc($v1)
/* 3A38B0 E00A40D0 E4740030 */  swc1      $f20, 0x30($v1)
/* 3A38B4 E00A40D4 1040001B */  beqz      $v0, .LE00A4144
/* 3A38B8 E00A40D8 AC600018 */   sw       $zero, 0x18($v1)
/* 3A38BC E00A40DC 00111080 */  sll       $v0, $s1, 2
/* 3A38C0 E00A40E0 3C01E00A */  lui       $at, %hi(D_E00A4AD0)
/* 3A38C4 E00A40E4 00220821 */  addu      $at, $at, $v0
/* 3A38C8 E00A40E8 8C224AD0 */  lw        $v0, %lo(D_E00A4AD0)($at)
/* 3A38CC E00A40EC 00400008 */  jr        $v0
/* 3A38D0 E00A40F0 00000000 */   nop
/* 3A38D4 E00A40F4 0802905E */  j         .LE00A4178
/* 3A38D8 E00A40F8 AC60001C */   sw       $zero, 0x1c($v1)
/* 3A38DC E00A40FC 24020002 */  addiu     $v0, $zero, 2
/* 3A38E0 E00A4100 0802905E */  j         .LE00A4178
/* 3A38E4 E00A4104 AC62001C */   sw       $v0, 0x1c($v1)
/* 3A38E8 E00A4108 24020004 */  addiu     $v0, $zero, 4
/* 3A38EC E00A410C 0802905E */  j         .LE00A4178
/* 3A38F0 E00A4110 AC62001C */   sw       $v0, 0x1c($v1)
/* 3A38F4 E00A4114 24020006 */  addiu     $v0, $zero, 6
/* 3A38F8 E00A4118 0802905E */  j         .LE00A4178
/* 3A38FC E00A411C AC62001C */   sw       $v0, 0x1c($v1)
/* 3A3900 E00A4120 24020007 */  addiu     $v0, $zero, 7
/* 3A3904 E00A4124 0802905E */  j         .LE00A4178
/* 3A3908 E00A4128 AC62001C */   sw       $v0, 0x1c($v1)
/* 3A390C E00A412C 24020008 */  addiu     $v0, $zero, 8
/* 3A3910 E00A4130 0802905E */  j         .LE00A4178
/* 3A3914 E00A4134 AC62001C */   sw       $v0, 0x1c($v1)
/* 3A3918 E00A4138 24020009 */  addiu     $v0, $zero, 9
/* 3A391C E00A413C 0802905E */  j         .LE00A4178
/* 3A3920 E00A4140 AC62001C */   sw       $v0, 0x1c($v1)
.LE00A4144:
/* 3A3924 E00A4144 2402000A */  addiu     $v0, $zero, 0xa
/* 3A3928 E00A4148 3C01E00A */  lui       $at, %hi(D_E00A4AF0)
/* 3A392C E00A414C D4224AF0 */  ldc1      $f2, %lo(D_E00A4AF0)($at)
/* 3A3930 E00A4150 4600A021 */  cvt.d.s   $f0, $f20
/* 3A3934 E00A4154 46220001 */  sub.d     $f0, $f0, $f2
/* 3A3938 E00A4158 AC62001C */  sw        $v0, 0x1c($v1)
/* 3A393C E00A415C 44921000 */  mtc1      $s2, $f2
/* 3A3940 E00A4160 00000000 */  nop
/* 3A3944 E00A4164 468010A1 */  cvt.d.w   $f2, $f2
/* 3A3948 E00A4168 46200007 */  neg.d     $f0, $f0
/* 3A394C E00A416C 46220003 */  div.d     $f0, $f0, $f2
/* 3A3950 E00A4170 46200020 */  cvt.s.d   $f0, $f0
/* 3A3954 E00A4174 E4600034 */  swc1      $f0, 0x34($v1)
.LE00A4178:
/* 3A3958 E00A4178 0200102D */  daddu     $v0, $s0, $zero
/* 3A395C E00A417C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3A3960 E00A4180 8FB20030 */  lw        $s2, 0x30($sp)
/* 3A3964 E00A4184 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3A3968 E00A4188 8FB00028 */  lw        $s0, 0x28($sp)
/* 3A396C E00A418C D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 3A3970 E00A4190 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3A3974 E00A4194 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3A3978 E00A4198 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3A397C E00A419C 03E00008 */  jr        $ra
/* 3A3980 E00A41A0 27BD0058 */   addiu    $sp, $sp, 0x58
