.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_E00B6750
.double 0.01

.section .text
glabel fx_91_main
/* 3B7160 E00B6000 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 3B7164 E00B6004 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3B7168 E00B6008 4485C000 */  mtc1      $a1, $f24
/* 3B716C E00B600C F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 3B7170 E00B6010 4486D000 */  mtc1      $a2, $f26
/* 3B7174 E00B6014 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3B7178 E00B6018 0080882D */  daddu     $s1, $a0, $zero
/* 3B717C E00B601C F7BC0058 */  sdc1      $f28, 0x58($sp)
/* 3B7180 E00B6020 4487E000 */  mtc1      $a3, $f28
/* 3B7184 E00B6024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B7188 E00B6028 AFB00028 */  sw        $s0, 0x28($sp)
/* 3B718C E00B602C 8FB00074 */  lw        $s0, 0x74($sp)
/* 3B7190 E00B6030 3C02E00B */  lui       $v0, %hi(fx_91_init)
/* 3B7194 E00B6034 24426178 */  addiu     $v0, $v0, %lo(fx_91_init)
/* 3B7198 E00B6038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3B719C E00B603C 3C02E00B */  lui       $v0, %hi(fx_91_update)
/* 3B71A0 E00B6040 24426180 */  addiu     $v0, $v0, %lo(fx_91_update)
/* 3B71A4 E00B6044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B71A8 E00B6048 3C02E00B */  lui       $v0, %hi(fx_91_render)
/* 3B71AC E00B604C 2442629C */  addiu     $v0, $v0, %lo(fx_91_render)
/* 3B71B0 E00B6050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3B71B4 E00B6054 2402005B */  addiu     $v0, $zero, 0x5b
/* 3B71B8 E00B6058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3B71BC E00B605C AFB20030 */  sw        $s2, 0x30($sp)
/* 3B71C0 E00B6060 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3B71C4 E00B6064 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3B71C8 E00B6068 AFA00010 */  sw        $zero, 0x10($sp)
/* 3B71CC E00B606C AFA00024 */  sw        $zero, 0x24($sp)
/* 3B71D0 E00B6070 0C080124 */  jal       shim_create_effect_instance
/* 3B71D4 E00B6074 AFA20014 */   sw       $v0, 0x14($sp)
/* 3B71D8 E00B6078 2404008C */  addiu     $a0, $zero, 0x8c
/* 3B71DC E00B607C 24030001 */  addiu     $v1, $zero, 1
/* 3B71E0 E00B6080 0040902D */  daddu     $s2, $v0, $zero
/* 3B71E4 E00B6084 0C08012C */  jal       shim_general_heap_malloc
/* 3B71E8 E00B6088 AE430008 */   sw       $v1, 8($s2)
/* 3B71EC E00B608C 0040182D */  daddu     $v1, $v0, $zero
/* 3B71F0 E00B6090 14600003 */  bnez      $v1, .LE00B60A0
/* 3B71F4 E00B6094 AE42000C */   sw       $v0, 0xc($s2)
.LE00B6098:
/* 3B71F8 E00B6098 0802D826 */  j         .LE00B6098
/* 3B71FC E00B609C 00000000 */   nop
.LE00B60A0:
/* 3B7200 E00B60A0 AC710000 */  sw        $s1, ($v1)
/* 3B7204 E00B60A4 1E000004 */  bgtz      $s0, .LE00B60B8
/* 3B7208 E00B60A8 AC600014 */   sw       $zero, 0x14($v1)
/* 3B720C E00B60AC 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3B7210 E00B60B0 0802D82F */  j         .LE00B60BC
/* 3B7214 E00B60B4 AC620010 */   sw       $v0, 0x10($v1)
.LE00B60B8:
/* 3B7218 E00B60B8 AC700010 */  sw        $s0, 0x10($v1)
.LE00B60BC:
/* 3B721C E00B60BC 0000882D */  daddu     $s1, $zero, $zero
/* 3B7220 E00B60C0 3C01E00B */  lui       $at, %hi(D_E00B6750)
/* 3B7224 E00B60C4 D4366750 */  ldc1      $f22, %lo(D_E00B6750)($at)
/* 3B7228 E00B60C8 3C01BFF0 */  lui       $at, 0xbff0
/* 3B722C E00B60CC 4481A800 */  mtc1      $at, $f21
/* 3B7230 E00B60D0 4480A000 */  mtc1      $zero, $f20
/* 3B7234 E00B60D4 0060802D */  daddu     $s0, $v1, $zero
/* 3B7238 E00B60D8 AE000024 */  sw        $zero, 0x24($s0)
/* 3B723C E00B60DC E6180004 */  swc1      $f24, 4($s0)
/* 3B7240 E00B60E0 E61A0008 */  swc1      $f26, 8($s0)
/* 3B7244 E00B60E4 E61C000C */  swc1      $f28, 0xc($s0)
/* 3B7248 E00B60E8 C7A00070 */  lwc1      $f0, 0x70($sp)
/* 3B724C E00B60EC 24020014 */  addiu     $v0, $zero, 0x14
/* 3B7250 E00B60F0 AE020018 */  sw        $v0, 0x18($s0)
/* 3B7254 E00B60F4 24020078 */  addiu     $v0, $zero, 0x78
/* 3B7258 E00B60F8 AE02001C */  sw        $v0, 0x1c($s0)
/* 3B725C E00B60FC 240200FF */  addiu     $v0, $zero, 0xff
/* 3B7260 E00B6100 AE020020 */  sw        $v0, 0x20($s0)
/* 3B7264 E00B6104 E6000028 */  swc1      $f0, 0x28($s0)
.LE00B6108:
/* 3B7268 E00B6108 2404000A */  addiu     $a0, $zero, 0xa
/* 3B726C E00B610C 0C080138 */  jal       shim_rand_int
/* 3B7270 E00B6110 AE00002C */   sw       $zero, 0x2c($s0)
/* 3B7274 E00B6114 44820000 */  mtc1      $v0, $f0
/* 3B7278 E00B6118 00000000 */  nop
/* 3B727C E00B611C 46800020 */  cvt.s.w   $f0, $f0
/* 3B7280 E00B6120 46000021 */  cvt.d.s   $f0, $f0
/* 3B7284 E00B6124 46360002 */  mul.d     $f0, $f0, $f22
/* 3B7288 E00B6128 00000000 */  nop
/* 3B728C E00B612C 46340000 */  add.d     $f0, $f0, $f20
/* 3B7290 E00B6130 26310001 */  addiu     $s1, $s1, 1
/* 3B7294 E00B6134 2A22000C */  slti      $v0, $s1, 0xc
/* 3B7298 E00B6138 46200020 */  cvt.s.d   $f0, $f0
/* 3B729C E00B613C E600005C */  swc1      $f0, 0x5c($s0)
/* 3B72A0 E00B6140 1440FFF1 */  bnez      $v0, .LE00B6108
/* 3B72A4 E00B6144 26100004 */   addiu    $s0, $s0, 4
/* 3B72A8 E00B6148 0240102D */  daddu     $v0, $s2, $zero
/* 3B72AC E00B614C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3B72B0 E00B6150 8FB20030 */  lw        $s2, 0x30($sp)
/* 3B72B4 E00B6154 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3B72B8 E00B6158 8FB00028 */  lw        $s0, 0x28($sp)
/* 3B72BC E00B615C D7BC0058 */  ldc1      $f28, 0x58($sp)
/* 3B72C0 E00B6160 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 3B72C4 E00B6164 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3B72C8 E00B6168 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3B72CC E00B616C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3B72D0 E00B6170 03E00008 */  jr        $ra
/* 3B72D4 E00B6174 27BD0060 */   addiu    $sp, $sp, 0x60
