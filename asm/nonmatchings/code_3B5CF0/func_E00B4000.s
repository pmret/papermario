.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B4000
/* 3B5CF0 E00B4000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3B5CF4 E00B4004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3B5CF8 E00B4008 4485A000 */  mtc1      $a1, $f20
/* 3B5CFC E00B400C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3B5D00 E00B4010 4486B000 */  mtc1      $a2, $f22
/* 3B5D04 E00B4014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3B5D08 E00B4018 0080902D */  daddu     $s2, $a0, $zero
/* 3B5D0C E00B401C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3B5D10 E00B4020 4487C000 */  mtc1      $a3, $f24
/* 3B5D14 E00B4024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B5D18 E00B4028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3B5D1C E00B402C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3B5D20 E00B4030 3C02E00B */  lui       $v0, %hi(func_E00B4134)
/* 3B5D24 E00B4034 24424134 */  addiu     $v0, $v0, %lo(func_E00B4134)
/* 3B5D28 E00B4038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3B5D2C E00B403C 3C02E00B */  lui       $v0, %hi(func_E00B413C)
/* 3B5D30 E00B4040 2442413C */  addiu     $v0, $v0, %lo(func_E00B413C)
/* 3B5D34 E00B4044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B5D38 E00B4048 3C02E00B */  lui       $v0, %hi(func_E00B452C)
/* 3B5D3C E00B404C 2442452C */  addiu     $v0, $v0, %lo(func_E00B452C)
/* 3B5D40 E00B4050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3B5D44 E00B4054 2402005A */  addiu     $v0, $zero, 0x5a
/* 3B5D48 E00B4058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3B5D4C E00B405C AFB00028 */  sw        $s0, 0x28($sp)
/* 3B5D50 E00B4060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3B5D54 E00B4064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3B5D58 E00B4068 0C080124 */  jal       func_E0200490
/* 3B5D5C E00B406C AFA20014 */   sw       $v0, 0x14($sp)
/* 3B5D60 E00B4070 24040098 */  addiu     $a0, $zero, 0x98
/* 3B5D64 E00B4074 24030001 */  addiu     $v1, $zero, 1
/* 3B5D68 E00B4078 0040802D */  daddu     $s0, $v0, $zero
/* 3B5D6C E00B407C 0C08012C */  jal       func_E02004B0
/* 3B5D70 E00B4080 AE030008 */   sw       $v1, 8($s0)
/* 3B5D74 E00B4084 0040182D */  daddu     $v1, $v0, $zero
/* 3B5D78 E00B4088 14600003 */  bnez      $v1, .LE00B4098
/* 3B5D7C E00B408C AE02000C */   sw       $v0, 0xc($s0)
.LE00B4090:
/* 3B5D80 E00B4090 0802D024 */  j         .LE00B4090
/* 3B5D84 E00B4094 00000000 */   nop
.LE00B4098:
/* 3B5D88 E00B4098 AC720000 */  sw        $s2, ($v1)
/* 3B5D8C E00B409C 1E200004 */  bgtz      $s1, .LE00B40B0
/* 3B5D90 E00B40A0 AC600014 */   sw       $zero, 0x14($v1)
/* 3B5D94 E00B40A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3B5D98 E00B40A8 0802D02D */  j         .LE00B40B4
/* 3B5D9C E00B40AC AC620010 */   sw       $v0, 0x10($v1)
.LE00B40B0:
/* 3B5DA0 E00B40B0 AC710010 */  sw        $s1, 0x10($v1)
.LE00B40B4:
/* 3B5DA4 E00B40B4 24060003 */  addiu     $a2, $zero, 3
/* 3B5DA8 E00B40B8 2405FFF3 */  addiu     $a1, $zero, -0xd
/* 3B5DAC E00B40BC 2464000C */  addiu     $a0, $v1, 0xc
/* 3B5DB0 E00B40C0 AC600024 */  sw        $zero, 0x24($v1)
/* 3B5DB4 E00B40C4 E4740004 */  swc1      $f20, 4($v1)
/* 3B5DB8 E00B40C8 E4760008 */  swc1      $f22, 8($v1)
/* 3B5DBC E00B40CC E478000C */  swc1      $f24, 0xc($v1)
/* 3B5DC0 E00B40D0 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3B5DC4 E00B40D4 2402002F */  addiu     $v0, $zero, 0x2f
/* 3B5DC8 E00B40D8 AC620018 */  sw        $v0, 0x18($v1)
/* 3B5DCC E00B40DC 2402007F */  addiu     $v0, $zero, 0x7f
/* 3B5DD0 E00B40E0 AC62001C */  sw        $v0, 0x1c($v1)
/* 3B5DD4 E00B40E4 240200FF */  addiu     $v0, $zero, 0xff
/* 3B5DD8 E00B40E8 AC620020 */  sw        $v0, 0x20($v1)
/* 3B5DDC E00B40EC AC600030 */  sw        $zero, 0x30($v1)
/* 3B5DE0 E00B40F0 AC600034 */  sw        $zero, 0x34($v1)
/* 3B5DE4 E00B40F4 E460002C */  swc1      $f0, 0x2c($v1)
.LE00B40F8:
/* 3B5DE8 E00B40F8 AC850088 */  sw        $a1, 0x88($a0)
/* 3B5DEC E00B40FC 24A50004 */  addiu     $a1, $a1, 4
/* 3B5DF0 E00B4100 24C6FFFF */  addiu     $a2, $a2, -1
/* 3B5DF4 E00B4104 04C1FFFC */  bgez      $a2, .LE00B40F8
/* 3B5DF8 E00B4108 2484FFFC */   addiu    $a0, $a0, -4
/* 3B5DFC E00B410C 0200102D */  daddu     $v0, $s0, $zero
/* 3B5E00 E00B4110 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3B5E04 E00B4114 8FB20030 */  lw        $s2, 0x30($sp)
/* 3B5E08 E00B4118 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3B5E0C E00B411C 8FB00028 */  lw        $s0, 0x28($sp)
/* 3B5E10 E00B4120 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3B5E14 E00B4124 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3B5E18 E00B4128 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3B5E1C E00B412C 03E00008 */  jr        $ra
/* 3B5E20 E00B4130 27BD0050 */   addiu    $sp, $sp, 0x50
