.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_98_main
/* 3CADF0 E00C4000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3CADF4 E00C4004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3CADF8 E00C4008 4485A000 */  mtc1      $a1, $f20
/* 3CADFC E00C400C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3CAE00 E00C4010 4486B000 */  mtc1      $a2, $f22
/* 3CAE04 E00C4014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3CAE08 E00C4018 0080902D */  daddu     $s2, $a0, $zero
/* 3CAE0C E00C401C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3CAE10 E00C4020 4487C000 */  mtc1      $a3, $f24
/* 3CAE14 E00C4024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3CAE18 E00C4028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3CAE1C E00C402C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3CAE20 E00C4030 3C02E00C */  lui       $v0, %hi(func_E00C4170)
/* 3CAE24 E00C4034 24424170 */  addiu     $v0, $v0, %lo(func_E00C4170)
/* 3CAE28 E00C4038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3CAE2C E00C403C 3C02E00C */  lui       $v0, %hi(func_E00C4178)
/* 3CAE30 E00C4040 24424178 */  addiu     $v0, $v0, %lo(func_E00C4178)
/* 3CAE34 E00C4044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3CAE38 E00C4048 3C02E00C */  lui       $v0, %hi(func_E00C42C4)
/* 3CAE3C E00C404C 244242C4 */  addiu     $v0, $v0, %lo(func_E00C42C4)
/* 3CAE40 E00C4050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3CAE44 E00C4054 24020062 */  addiu     $v0, $zero, 0x62
/* 3CAE48 E00C4058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3CAE4C E00C405C AFB00028 */  sw        $s0, 0x28($sp)
/* 3CAE50 E00C4060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3CAE54 E00C4064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3CAE58 E00C4068 0C080124 */  jal       shim_create_effect_instance
/* 3CAE5C E00C406C AFA20014 */   sw       $v0, 0x14($sp)
/* 3CAE60 E00C4070 24040174 */  addiu     $a0, $zero, 0x174
/* 3CAE64 E00C4074 24030001 */  addiu     $v1, $zero, 1
/* 3CAE68 E00C4078 0040802D */  daddu     $s0, $v0, $zero
/* 3CAE6C E00C407C 0C08012C */  jal       shim_general_heap_malloc
/* 3CAE70 E00C4080 AE030008 */   sw       $v1, 8($s0)
/* 3CAE74 E00C4084 0040182D */  daddu     $v1, $v0, $zero
/* 3CAE78 E00C4088 14600003 */  bnez      $v1, .LE00C4098
/* 3CAE7C E00C408C AE02000C */   sw       $v0, 0xc($s0)
.LE00C4090:
/* 3CAE80 E00C4090 08031024 */  j         .LE00C4090
/* 3CAE84 E00C4094 00000000 */   nop
.LE00C4098:
/* 3CAE88 E00C4098 AC720000 */  sw        $s2, ($v1)
/* 3CAE8C E00C409C 1E200004 */  bgtz      $s1, .LE00C40B0
/* 3CAE90 E00C40A0 AC600014 */   sw       $zero, 0x14($v1)
/* 3CAE94 E00C40A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3CAE98 E00C40A8 0803102D */  j         .LE00C40B4
/* 3CAE9C E00C40AC AC620010 */   sw       $v0, 0x10($v1)
.LE00C40B0:
/* 3CAEA0 E00C40B0 AC710010 */  sw        $s1, 0x10($v1)
.LE00C40B4:
/* 3CAEA4 E00C40B4 0000282D */  daddu     $a1, $zero, $zero
/* 3CAEA8 E00C40B8 3C04E00C */  lui       $a0, %hi(D_E00C4A10)
/* 3CAEAC E00C40BC 24844A10 */  addiu     $a0, $a0, %lo(D_E00C4A10)
/* 3CAEB0 E00C40C0 AC600024 */  sw        $zero, 0x24($v1)
/* 3CAEB4 E00C40C4 E4740004 */  swc1      $f20, 4($v1)
/* 3CAEB8 E00C40C8 E4760008 */  swc1      $f22, 8($v1)
/* 3CAEBC E00C40CC E478000C */  swc1      $f24, 0xc($v1)
/* 3CAEC0 E00C40D0 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3CAEC4 E00C40D4 24020046 */  addiu     $v0, $zero, 0x46
/* 3CAEC8 E00C40D8 AC620018 */  sw        $v0, 0x18($v1)
/* 3CAECC E00C40DC 240200B4 */  addiu     $v0, $zero, 0xb4
/* 3CAED0 E00C40E0 AC62001C */  sw        $v0, 0x1c($v1)
/* 3CAED4 E00C40E4 E4600028 */  swc1      $f0, 0x28($v1)
/* 3CAED8 E00C40E8 3C013F80 */  lui       $at, 0x3f80
/* 3CAEDC E00C40EC 44810000 */  mtc1      $at, $f0
/* 3CAEE0 E00C40F0 24020078 */  addiu     $v0, $zero, 0x78
/* 3CAEE4 E00C40F4 AC620020 */  sw        $v0, 0x20($v1)
/* 3CAEE8 E00C40F8 AC60002C */  sw        $zero, 0x2c($v1)
/* 3CAEEC E00C40FC E4600030 */  swc1      $f0, 0x30($v1)
.LE00C4100:
/* 3CAEF0 E00C4100 C4800000 */  lwc1      $f0, ($a0)
/* 3CAEF4 E00C4104 46800020 */  cvt.s.w   $f0, $f0
/* 3CAEF8 E00C4108 E4600034 */  swc1      $f0, 0x34($v1)
/* 3CAEFC E00C410C C4800004 */  lwc1      $f0, 4($a0)
/* 3CAF00 E00C4110 46800020 */  cvt.s.w   $f0, $f0
/* 3CAF04 E00C4114 E460005C */  swc1      $f0, 0x5c($v1)
/* 3CAF08 E00C4118 AC600084 */  sw        $zero, 0x84($v1)
/* 3CAF0C E00C411C AC6000AC */  sw        $zero, 0xac($v1)
/* 3CAF10 E00C4120 AC6000D4 */  sw        $zero, 0xd4($v1)
/* 3CAF14 E00C4124 AC6000FC */  sw        $zero, 0xfc($v1)
/* 3CAF18 E00C4128 AC600124 */  sw        $zero, 0x124($v1)
/* 3CAF1C E00C412C 8C820008 */  lw        $v0, 8($a0)
/* 3CAF20 E00C4130 2484000C */  addiu     $a0, $a0, 0xc
/* 3CAF24 E00C4134 24A50001 */  addiu     $a1, $a1, 1
/* 3CAF28 E00C4138 AC62014C */  sw        $v0, 0x14c($v1)
/* 3CAF2C E00C413C 28A2000A */  slti      $v0, $a1, 0xa
/* 3CAF30 E00C4140 1440FFEF */  bnez      $v0, .LE00C4100
/* 3CAF34 E00C4144 24630004 */   addiu    $v1, $v1, 4
/* 3CAF38 E00C4148 0200102D */  daddu     $v0, $s0, $zero
/* 3CAF3C E00C414C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3CAF40 E00C4150 8FB20030 */  lw        $s2, 0x30($sp)
/* 3CAF44 E00C4154 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3CAF48 E00C4158 8FB00028 */  lw        $s0, 0x28($sp)
/* 3CAF4C E00C415C D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3CAF50 E00C4160 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3CAF54 E00C4164 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3CAF58 E00C4168 03E00008 */  jr        $ra
/* 3CAF5C E00C416C 27BD0050 */   addiu    $sp, $sp, 0x50
