.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00DC000
/* 3D7A70 E00DC000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3D7A74 E00DC004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3D7A78 E00DC008 4485A000 */  mtc1      $a1, $f20
/* 3D7A7C E00DC00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3D7A80 E00DC010 4486B000 */  mtc1      $a2, $f22
/* 3D7A84 E00DC014 AFB30034 */  sw        $s3, 0x34($sp)
/* 3D7A88 E00DC018 0080982D */  daddu     $s3, $a0, $zero
/* 3D7A8C E00DC01C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3D7A90 E00DC020 4487C000 */  mtc1      $a3, $f24
/* 3D7A94 E00DC024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D7A98 E00DC028 AFB00028 */  sw        $s0, 0x28($sp)
/* 3D7A9C E00DC02C 8FB00074 */  lw        $s0, 0x74($sp)
/* 3D7AA0 E00DC030 3C02E00E */  lui       $v0, %hi(D_E00DC190)
/* 3D7AA4 E00DC034 2442C190 */  addiu     $v0, $v0, %lo(D_E00DC190)
/* 3D7AA8 E00DC038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3D7AAC E00DC03C 3C02E00E */  lui       $v0, %hi(D_E00DC198)
/* 3D7AB0 E00DC040 2442C198 */  addiu     $v0, $v0, %lo(D_E00DC198)
/* 3D7AB4 E00DC044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D7AB8 E00DC048 3C02E00E */  lui       $v0, %hi(D_E00DC2C0)
/* 3D7ABC E00DC04C 2442C2C0 */  addiu     $v0, $v0, %lo(D_E00DC2C0)
/* 3D7AC0 E00DC050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3D7AC4 E00DC054 2402006E */  addiu     $v0, $zero, 0x6e
/* 3D7AC8 E00DC058 AFBF0038 */  sw        $ra, 0x38($sp)
/* 3D7ACC E00DC05C AFB20030 */  sw        $s2, 0x30($sp)
/* 3D7AD0 E00DC060 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3D7AD4 E00DC064 AFA00010 */  sw        $zero, 0x10($sp)
/* 3D7AD8 E00DC068 AFA00024 */  sw        $zero, 0x24($sp)
/* 3D7ADC E00DC06C 0C080124 */  jal       func_E0200490
/* 3D7AE0 E00DC070 AFA20014 */   sw       $v0, 0x14($sp)
/* 3D7AE4 E00DC074 24040050 */  addiu     $a0, $zero, 0x50
/* 3D7AE8 E00DC078 24030001 */  addiu     $v1, $zero, 1
/* 3D7AEC E00DC07C 0040902D */  daddu     $s2, $v0, $zero
/* 3D7AF0 E00DC080 0C08012C */  jal       func_E02004B0
/* 3D7AF4 E00DC084 AE430008 */   sw       $v1, 8($s2)
/* 3D7AF8 E00DC088 0040882D */  daddu     $s1, $v0, $zero
/* 3D7AFC E00DC08C 16200003 */  bnez      $s1, .LE00DC09C
/* 3D7B00 E00DC090 AE42000C */   sw       $v0, 0xc($s2)
.LE00DC094:
/* 3D7B04 E00DC094 08037025 */  j         .LE00DC094
/* 3D7B08 E00DC098 00000000 */   nop      
.LE00DC09C:
/* 3D7B0C E00DC09C AE330000 */  sw        $s3, ($s1)
/* 3D7B10 E00DC0A0 1E000004 */  bgtz      $s0, .LE00DC0B4
/* 3D7B14 E00DC0A4 AE200014 */   sw       $zero, 0x14($s1)
/* 3D7B18 E00DC0A8 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3D7B1C E00DC0AC 0803702E */  j         .LE00DC0B8
/* 3D7B20 E00DC0B0 AE220010 */   sw       $v0, 0x10($s1)
.LE00DC0B4:
/* 3D7B24 E00DC0B4 AE300010 */  sw        $s0, 0x10($s1)
.LE00DC0B8:
/* 3D7B28 E00DC0B8 241000FF */  addiu     $s0, $zero, 0xff
/* 3D7B2C E00DC0BC AE200024 */  sw        $zero, 0x24($s1)
/* 3D7B30 E00DC0C0 E6340004 */  swc1      $f20, 4($s1)
/* 3D7B34 E00DC0C4 E6360008 */  swc1      $f22, 8($s1)
/* 3D7B38 E00DC0C8 E638000C */  swc1      $f24, 0xc($s1)
/* 3D7B3C E00DC0CC C7A00070 */  lwc1      $f0, 0x70($sp)
/* 3D7B40 E00DC0D0 240200E6 */  addiu     $v0, $zero, 0xe6
/* 3D7B44 E00DC0D4 AE22002C */  sw        $v0, 0x2c($s1)
/* 3D7B48 E00DC0D8 24020032 */  addiu     $v0, $zero, 0x32
/* 3D7B4C E00DC0DC AE300018 */  sw        $s0, 0x18($s1)
/* 3D7B50 E00DC0E0 AE30001C */  sw        $s0, 0x1c($s1)
/* 3D7B54 E00DC0E4 AE300020 */  sw        $s0, 0x20($s1)
/* 3D7B58 E00DC0E8 AE300028 */  sw        $s0, 0x28($s1)
/* 3D7B5C E00DC0EC AE220030 */  sw        $v0, 0x30($s1)
/* 3D7B60 E00DC0F0 AE300034 */  sw        $s0, 0x34($s1)
/* 3D7B64 E00DC0F4 E620004C */  swc1      $f0, 0x4c($s1)
/* 3D7B68 E00DC0F8 C7A00068 */  lwc1      $f0, 0x68($sp)
/* 3D7B6C E00DC0FC AE200044 */  sw        $zero, 0x44($s1)
/* 3D7B70 E00DC100 E6200048 */  swc1      $f0, 0x48($s1)
/* 3D7B74 E00DC104 C7A0006C */  lwc1      $f0, 0x6c($sp)
/* 3D7B78 E00DC108 24040020 */  addiu     $a0, $zero, 0x20
/* 3D7B7C E00DC10C 0C080138 */  jal       func_E02004E0
/* 3D7B80 E00DC110 E620003C */   swc1     $f0, 0x3c($s1)
/* 3D7B84 E00DC114 24040010 */  addiu     $a0, $zero, 0x10
/* 3D7B88 E00DC118 44820000 */  mtc1      $v0, $f0
/* 3D7B8C E00DC11C 00000000 */  nop       
/* 3D7B90 E00DC120 46800020 */  cvt.s.w   $f0, $f0
/* 3D7B94 E00DC124 0C080138 */  jal       func_E02004E0
/* 3D7B98 E00DC128 E6200038 */   swc1     $f0, 0x38($s1)
/* 3D7B9C E00DC12C 44820000 */  mtc1      $v0, $f0
/* 3D7BA0 E00DC130 00000000 */  nop       
/* 3D7BA4 E00DC134 46800020 */  cvt.s.w   $f0, $f0
/* 3D7BA8 E00DC138 0240102D */  daddu     $v0, $s2, $zero
/* 3D7BAC E00DC13C 24030096 */  addiu     $v1, $zero, 0x96
/* 3D7BB0 E00DC140 AE230020 */  sw        $v1, 0x20($s1)
/* 3D7BB4 E00DC144 240300D7 */  addiu     $v1, $zero, 0xd7
/* 3D7BB8 E00DC148 AE230028 */  sw        $v1, 0x28($s1)
/* 3D7BBC E00DC14C 240300D2 */  addiu     $v1, $zero, 0xd2
/* 3D7BC0 E00DC150 AE23002C */  sw        $v1, 0x2c($s1)
/* 3D7BC4 E00DC154 2403000A */  addiu     $v1, $zero, 0xa
/* 3D7BC8 E00DC158 E6200040 */  swc1      $f0, 0x40($s1)
/* 3D7BCC E00DC15C AE300018 */  sw        $s0, 0x18($s1)
/* 3D7BD0 E00DC160 AE30001C */  sw        $s0, 0x1c($s1)
/* 3D7BD4 E00DC164 AE230030 */  sw        $v1, 0x30($s1)
/* 3D7BD8 E00DC168 8FBF0038 */  lw        $ra, 0x38($sp)
/* 3D7BDC E00DC16C 8FB30034 */  lw        $s3, 0x34($sp)
/* 3D7BE0 E00DC170 8FB20030 */  lw        $s2, 0x30($sp)
/* 3D7BE4 E00DC174 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3D7BE8 E00DC178 8FB00028 */  lw        $s0, 0x28($sp)
/* 3D7BEC E00DC17C D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3D7BF0 E00DC180 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3D7BF4 E00DC184 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3D7BF8 E00DC188 03E00008 */  jr        $ra
/* 3D7BFC E00DC18C 27BD0058 */   addiu    $sp, $sp, 0x58
