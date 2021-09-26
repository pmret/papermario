.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_103_main
/* 3D2AC0 E00CE000 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 3D2AC4 E00CE004 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 3D2AC8 E00CE008 4485E000 */  mtc1      $a1, $f28
/* 3D2ACC E00CE00C AFB20030 */  sw        $s2, 0x30($sp)
/* 3D2AD0 E00CE010 0080902D */  daddu     $s2, $a0, $zero
/* 3D2AD4 E00CE014 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* 3D2AD8 E00CE018 4486F000 */  mtc1      $a2, $f30
/* 3D2ADC E00CE01C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D2AE0 E00CE020 AFB00028 */  sw        $s0, 0x28($sp)
/* 3D2AE4 E00CE024 8FB00084 */  lw        $s0, 0x84($sp)
/* 3D2AE8 E00CE028 3C02E00D */  lui       $v0, %hi(func_E00CE21C)
/* 3D2AEC E00CE02C 2442E21C */  addiu     $v0, $v0, %lo(func_E00CE21C)
/* 3D2AF0 E00CE030 AFA20018 */  sw        $v0, 0x18($sp)
/* 3D2AF4 E00CE034 3C02E00D */  lui       $v0, %hi(func_E00CE224)
/* 3D2AF8 E00CE038 2442E224 */  addiu     $v0, $v0, %lo(func_E00CE224)
/* 3D2AFC E00CE03C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D2B00 E00CE040 3C02E00D */  lui       $v0, %hi(func_E00CE428)
/* 3D2B04 E00CE044 2442E428 */  addiu     $v0, $v0, %lo(func_E00CE428)
/* 3D2B08 E00CE048 AFA20020 */  sw        $v0, 0x20($sp)
/* 3D2B0C E00CE04C 24020067 */  addiu     $v0, $zero, 0x67
/* 3D2B10 E00CE050 AFBF0038 */  sw        $ra, 0x38($sp)
/* 3D2B14 E00CE054 AFB30034 */  sw        $s3, 0x34($sp)
/* 3D2B18 E00CE058 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3D2B1C E00CE05C F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 3D2B20 E00CE060 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3D2B24 E00CE064 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3D2B28 E00CE068 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3D2B2C E00CE06C AFA7007C */  sw        $a3, 0x7c($sp)
/* 3D2B30 E00CE070 AFA00010 */  sw        $zero, 0x10($sp)
/* 3D2B34 E00CE074 AFA00024 */  sw        $zero, 0x24($sp)
/* 3D2B38 E00CE078 0C080124 */  jal       shim_create_effect_instance
/* 3D2B3C E00CE07C AFA20014 */   sw       $v0, 0x14($sp)
/* 3D2B40 E00CE080 24040144 */  addiu     $a0, $zero, 0x144
/* 3D2B44 E00CE084 24030001 */  addiu     $v1, $zero, 1
/* 3D2B48 E00CE088 0040982D */  daddu     $s3, $v0, $zero
/* 3D2B4C E00CE08C 0C08012C */  jal       shim_general_heap_malloc
/* 3D2B50 E00CE090 AE630008 */   sw       $v1, 8($s3)
/* 3D2B54 E00CE094 0040882D */  daddu     $s1, $v0, $zero
/* 3D2B58 E00CE098 16200003 */  bnez      $s1, .LE00CE0A8
/* 3D2B5C E00CE09C AE62000C */   sw       $v0, 0xc($s3)
.LE00CE0A0:
/* 3D2B60 E00CE0A0 08033828 */  j         .LE00CE0A0
/* 3D2B64 E00CE0A4 00000000 */   nop
.LE00CE0A8:
/* 3D2B68 E00CE0A8 AE320000 */  sw        $s2, ($s1)
/* 3D2B6C E00CE0AC 1E000004 */  bgtz      $s0, .LE00CE0C0
/* 3D2B70 E00CE0B0 AE200014 */   sw       $zero, 0x14($s1)
/* 3D2B74 E00CE0B4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3D2B78 E00CE0B8 08033831 */  j         .LE00CE0C4
/* 3D2B7C E00CE0BC AE220010 */   sw       $v0, 0x10($s1)
.LE00CE0C0:
/* 3D2B80 E00CE0C0 AE300010 */  sw        $s0, 0x10($s1)
.LE00CE0C4:
/* 3D2B84 E00CE0C4 3C01E00D */  lui       $at, %hi(D_E00CEE50)
/* 3D2B88 E00CE0C8 D43AEE50 */  ldc1      $f26, %lo(D_E00CEE50)($at)
/* 3D2B8C E00CE0CC 3C013FF0 */  lui       $at, 0x3ff0
/* 3D2B90 E00CE0D0 4481C800 */  mtc1      $at, $f25
/* 3D2B94 E00CE0D4 4480C000 */  mtc1      $zero, $f24
/* 3D2B98 E00CE0D8 3C01E00D */  lui       $at, %hi(D_E00CEE58)
/* 3D2B9C E00CE0DC D434EE58 */  ldc1      $f20, %lo(D_E00CEE58)($at)
/* 3D2BA0 E00CE0E0 3C014000 */  lui       $at, 0x4000
/* 3D2BA4 E00CE0E4 4481B800 */  mtc1      $at, $f23
/* 3D2BA8 E00CE0E8 4480B000 */  mtc1      $zero, $f22
/* 3D2BAC E00CE0EC 0000902D */  daddu     $s2, $zero, $zero
/* 3D2BB0 E00CE0F0 AE200024 */  sw        $zero, 0x24($s1)
/* 3D2BB4 E00CE0F4 E63C0004 */  swc1      $f28, 4($s1)
/* 3D2BB8 E00CE0F8 E63E0008 */  swc1      $f30, 8($s1)
/* 3D2BBC E00CE0FC C7A2007C */  lwc1      $f2, 0x7c($sp)
/* 3D2BC0 E00CE100 0220802D */  daddu     $s0, $s1, $zero
/* 3D2BC4 E00CE104 E622000C */  swc1      $f2, 0xc($s1)
/* 3D2BC8 E00CE108 C7A00080 */  lwc1      $f0, 0x80($sp)
/* 3D2BCC E00CE10C 240200FF */  addiu     $v0, $zero, 0xff
/* 3D2BD0 E00CE110 AE220018 */  sw        $v0, 0x18($s1)
/* 3D2BD4 E00CE114 AE22001C */  sw        $v0, 0x1c($s1)
/* 3D2BD8 E00CE118 AE220020 */  sw        $v0, 0x20($s1)
/* 3D2BDC E00CE11C AE220028 */  sw        $v0, 0x28($s1)
/* 3D2BE0 E00CE120 AE22002C */  sw        $v0, 0x2c($s1)
/* 3D2BE4 E00CE124 240200EB */  addiu     $v0, $zero, 0xeb
/* 3D2BE8 E00CE128 AE220030 */  sw        $v0, 0x30($s1)
/* 3D2BEC E00CE12C E6200034 */  swc1      $f0, 0x34($s1)
.LE00CE130:
/* 3D2BF0 E00CE130 44920000 */  mtc1      $s2, $f0
/* 3D2BF4 E00CE134 00000000 */  nop
/* 3D2BF8 E00CE138 46800021 */  cvt.d.w   $f0, $f0
/* 3D2BFC E00CE13C 463A0002 */  mul.d     $f0, $f0, $f26
/* 3D2C00 E00CE140 00000000 */  nop
/* 3D2C04 E00CE144 E61C0038 */  swc1      $f28, 0x38($s0)
/* 3D2C08 E00CE148 E61E0058 */  swc1      $f30, 0x58($s0)
/* 3D2C0C E00CE14C C7A2007C */  lwc1      $f2, 0x7c($sp)
/* 3D2C10 E00CE150 46380000 */  add.d     $f0, $f0, $f24
/* 3D2C14 E00CE154 24040168 */  addiu     $a0, $zero, 0x168
/* 3D2C18 E00CE158 E6020078 */  swc1      $f2, 0x78($s0)
/* 3D2C1C E00CE15C 46200020 */  cvt.s.d   $f0, $f0
/* 3D2C20 E00CE160 0C080138 */  jal       shim_rand_int
/* 3D2C24 E00CE164 E6000098 */   swc1     $f0, 0x98($s0)
/* 3D2C28 E00CE168 24040064 */  addiu     $a0, $zero, 0x64
/* 3D2C2C E00CE16C 44820000 */  mtc1      $v0, $f0
/* 3D2C30 E00CE170 00000000 */  nop
/* 3D2C34 E00CE174 46800020 */  cvt.s.w   $f0, $f0
/* 3D2C38 E00CE178 0C080138 */  jal       shim_rand_int
/* 3D2C3C E00CE17C E60000B8 */   swc1     $f0, 0xb8($s0)
/* 3D2C40 E00CE180 44820000 */  mtc1      $v0, $f0
/* 3D2C44 E00CE184 00000000 */  nop
/* 3D2C48 E00CE188 46800021 */  cvt.d.w   $f0, $f0
/* 3D2C4C E00CE18C 46340002 */  mul.d     $f0, $f0, $f20
/* 3D2C50 E00CE190 00000000 */  nop
/* 3D2C54 E00CE194 46360000 */  add.d     $f0, $f0, $f22
/* 3D2C58 E00CE198 2404001E */  addiu     $a0, $zero, 0x1e
/* 3D2C5C E00CE19C 46200020 */  cvt.s.d   $f0, $f0
/* 3D2C60 E00CE1A0 0C080138 */  jal       shim_rand_int
/* 3D2C64 E00CE1A4 E60000D8 */   swc1     $f0, 0xd8($s0)
/* 3D2C68 E00CE1A8 44820000 */  mtc1      $v0, $f0
/* 3D2C6C E00CE1AC 00000000 */  nop
/* 3D2C70 E00CE1B0 46800021 */  cvt.d.w   $f0, $f0
/* 3D2C74 E00CE1B4 46340002 */  mul.d     $f0, $f0, $f20
/* 3D2C78 E00CE1B8 00000000 */  nop
/* 3D2C7C E00CE1BC 26520001 */  addiu     $s2, $s2, 1
/* 3D2C80 E00CE1C0 2A420008 */  slti      $v0, $s2, 8
/* 3D2C84 E00CE1C4 AE000118 */  sw        $zero, 0x118($s0)
/* 3D2C88 E00CE1C8 46200020 */  cvt.s.d   $f0, $f0
/* 3D2C8C E00CE1CC E60000F8 */  swc1      $f0, 0xf8($s0)
/* 3D2C90 E00CE1D0 1440FFD7 */  bnez      $v0, .LE00CE130
/* 3D2C94 E00CE1D4 26100004 */   addiu    $s0, $s0, 4
/* 3D2C98 E00CE1D8 0260102D */  daddu     $v0, $s3, $zero
/* 3D2C9C E00CE1DC AE200138 */  sw        $zero, 0x138($s1)
/* 3D2CA0 E00CE1E0 AE20013C */  sw        $zero, 0x13c($s1)
/* 3D2CA4 E00CE1E4 AE200140 */  sw        $zero, 0x140($s1)
/* 3D2CA8 E00CE1E8 8FBF0038 */  lw        $ra, 0x38($sp)
/* 3D2CAC E00CE1EC 8FB30034 */  lw        $s3, 0x34($sp)
/* 3D2CB0 E00CE1F0 8FB20030 */  lw        $s2, 0x30($sp)
/* 3D2CB4 E00CE1F4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3D2CB8 E00CE1F8 8FB00028 */  lw        $s0, 0x28($sp)
/* 3D2CBC E00CE1FC D7BE0068 */  ldc1      $f30, 0x68($sp)
/* 3D2CC0 E00CE200 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 3D2CC4 E00CE204 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 3D2CC8 E00CE208 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3D2CCC E00CE20C D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3D2CD0 E00CE210 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3D2CD4 E00CE214 03E00008 */  jr        $ra
/* 3D2CD8 E00CE218 27BD0070 */   addiu    $sp, $sp, 0x70
