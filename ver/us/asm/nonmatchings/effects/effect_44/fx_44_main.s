.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_44_main
/* 35E920 E0058000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 35E924 E0058004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 35E928 E0058008 4485A000 */  mtc1      $a1, $f20
/* 35E92C E005800C AFB1002C */  sw        $s1, 0x2c($sp)
/* 35E930 E0058010 0080882D */  daddu     $s1, $a0, $zero
/* 35E934 E0058014 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 35E938 E0058018 4486B000 */  mtc1      $a2, $f22
/* 35E93C E005801C 27A40010 */  addiu     $a0, $sp, 0x10
/* 35E940 E0058020 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 35E944 E0058024 4487C000 */  mtc1      $a3, $f24
/* 35E948 E0058028 3C02E006 */  lui       $v0, %hi(fx_44_init)
/* 35E94C E005802C 244281AC */  addiu     $v0, $v0, %lo(fx_44_init)
/* 35E950 E0058030 AFA20018 */  sw        $v0, 0x18($sp)
/* 35E954 E0058034 3C02E006 */  lui       $v0, %hi(fx_44_update)
/* 35E958 E0058038 244281B4 */  addiu     $v0, $v0, %lo(fx_44_update)
/* 35E95C E005803C AFA2001C */  sw        $v0, 0x1c($sp)
/* 35E960 E0058040 3C02E006 */  lui       $v0, %hi(fx_44_render)
/* 35E964 E0058044 24428490 */  addiu     $v0, $v0, %lo(fx_44_render)
/* 35E968 E0058048 AFA20020 */  sw        $v0, 0x20($sp)
/* 35E96C E005804C 2402002C */  addiu     $v0, $zero, 0x2c
/* 35E970 E0058050 AFBF0038 */  sw        $ra, 0x38($sp)
/* 35E974 E0058054 AFB30034 */  sw        $s3, 0x34($sp)
/* 35E978 E0058058 AFB20030 */  sw        $s2, 0x30($sp)
/* 35E97C E005805C AFB00028 */  sw        $s0, 0x28($sp)
/* 35E980 E0058060 AFA00010 */  sw        $zero, 0x10($sp)
/* 35E984 E0058064 AFA00024 */  sw        $zero, 0x24($sp)
/* 35E988 E0058068 0C080124 */  jal       shim_create_effect_instance
/* 35E98C E005806C AFA20014 */   sw       $v0, 0x14($sp)
/* 35E990 E0058070 24040104 */  addiu     $a0, $zero, 0x104
/* 35E994 E0058074 24120005 */  addiu     $s2, $zero, 5
/* 35E998 E0058078 0040802D */  daddu     $s0, $v0, $zero
/* 35E99C E005807C 0C08012C */  jal       shim_general_heap_malloc
/* 35E9A0 E0058080 AE120008 */   sw       $s2, 8($s0)
/* 35E9A4 E0058084 0040182D */  daddu     $v1, $v0, $zero
/* 35E9A8 E0058088 14600003 */  bnez      $v1, .LE0058098
/* 35E9AC E005808C AE03000C */   sw       $v1, 0xc($s0)
.LE0058090:
/* 35E9B0 E0058090 08016024 */  j         .LE0058090
/* 35E9B4 E0058094 00000000 */   nop
.LE0058098:
/* 35E9B8 E0058098 24020064 */  addiu     $v0, $zero, 0x64
/* 35E9BC E005809C AC710000 */  sw        $s1, ($v1)
/* 35E9C0 E00580A0 E4740004 */  swc1      $f20, 4($v1)
/* 35E9C4 E00580A4 E4760008 */  swc1      $f22, 8($v1)
/* 35E9C8 E00580A8 E478000C */  swc1      $f24, 0xc($v1)
/* 35E9CC E00580AC AC620028 */  sw        $v0, 0x28($v1)
/* 35E9D0 E00580B0 AC60002C */  sw        $zero, 0x2c($v1)
/* 35E9D4 E00580B4 AC600024 */  sw        $zero, 0x24($v1)
/* 35E9D8 E00580B8 24110001 */  addiu     $s1, $zero, 1
/* 35E9DC E00580BC 0232102A */  slt       $v0, $s1, $s2
/* 35E9E0 E00580C0 10400030 */  beqz      $v0, .LE0058184
/* 35E9E4 E00580C4 24630034 */   addiu    $v1, $v1, 0x34
/* 35E9E8 E00580C8 3C136666 */  lui       $s3, 0x6666
/* 35E9EC E00580CC 36736667 */  ori       $s3, $s3, 0x6667
/* 35E9F0 E00580D0 24700014 */  addiu     $s0, $v1, 0x14
.LE00580D4:
/* 35E9F4 E00580D4 0C080138 */  jal       shim_rand_int
/* 35E9F8 E00580D8 2404001E */   addiu    $a0, $zero, 0x1e
/* 35E9FC E00580DC 2404001E */  addiu     $a0, $zero, 0x1e
/* 35EA00 E00580E0 2442FFF1 */  addiu     $v0, $v0, -0xf
/* 35EA04 E00580E4 44820000 */  mtc1      $v0, $f0
/* 35EA08 E00580E8 00000000 */  nop
/* 35EA0C E00580EC 46800020 */  cvt.s.w   $f0, $f0
/* 35EA10 E00580F0 E600FFF0 */  swc1      $f0, -0x10($s0)
/* 35EA14 E00580F4 0C080138 */  jal       shim_rand_int
/* 35EA18 E00580F8 AE00FFF4 */   sw       $zero, -0xc($s0)
/* 35EA1C E00580FC 24040168 */  addiu     $a0, $zero, 0x168
/* 35EA20 E0058100 2442FFF1 */  addiu     $v0, $v0, -0xf
/* 35EA24 E0058104 44820000 */  mtc1      $v0, $f0
/* 35EA28 E0058108 00000000 */  nop
/* 35EA2C E005810C 46800020 */  cvt.s.w   $f0, $f0
/* 35EA30 E0058110 0C080138 */  jal       shim_rand_int
/* 35EA34 E0058114 E600FFF8 */   swc1     $f0, -8($s0)
/* 35EA38 E0058118 24040168 */  addiu     $a0, $zero, 0x168
/* 35EA3C E005811C 44820000 */  mtc1      $v0, $f0
/* 35EA40 E0058120 00000000 */  nop
/* 35EA44 E0058124 46800020 */  cvt.s.w   $f0, $f0
/* 35EA48 E0058128 0C080138 */  jal       shim_rand_int
/* 35EA4C E005812C E6000004 */   swc1     $f0, 4($s0)
/* 35EA50 E0058130 24040064 */  addiu     $a0, $zero, 0x64
/* 35EA54 E0058134 44820000 */  mtc1      $v0, $f0
/* 35EA58 E0058138 00000000 */  nop
/* 35EA5C E005813C 46800020 */  cvt.s.w   $f0, $f0
/* 35EA60 E0058140 0C080138 */  jal       shim_rand_int
/* 35EA64 E0058144 E600000C */   swc1     $f0, 0xc($s0)
/* 35EA68 E0058148 00530018 */  mult      $v0, $s3
/* 35EA6C E005814C 26310001 */  addiu     $s1, $s1, 1
/* 35EA70 E0058150 000217C3 */  sra       $v0, $v0, 0x1f
/* 35EA74 E0058154 AE00FFFC */  sw        $zero, -4($s0)
/* 35EA78 E0058158 AE000000 */  sw        $zero, ($s0)
/* 35EA7C E005815C 00004010 */  mfhi      $t0
/* 35EA80 E0058160 00081883 */  sra       $v1, $t0, 2
/* 35EA84 E0058164 00621823 */  subu      $v1, $v1, $v0
/* 35EA88 E0058168 44830000 */  mtc1      $v1, $f0
/* 35EA8C E005816C 00000000 */  nop
/* 35EA90 E0058170 46800020 */  cvt.s.w   $f0, $f0
/* 35EA94 E0058174 E6000008 */  swc1      $f0, 8($s0)
/* 35EA98 E0058178 0232102A */  slt       $v0, $s1, $s2
/* 35EA9C E005817C 1440FFD5 */  bnez      $v0, .LE00580D4
/* 35EAA0 E0058180 26100034 */   addiu    $s0, $s0, 0x34
.LE0058184:
/* 35EAA4 E0058184 8FBF0038 */  lw        $ra, 0x38($sp)
/* 35EAA8 E0058188 8FB30034 */  lw        $s3, 0x34($sp)
/* 35EAAC E005818C 8FB20030 */  lw        $s2, 0x30($sp)
/* 35EAB0 E0058190 8FB1002C */  lw        $s1, 0x2c($sp)
/* 35EAB4 E0058194 8FB00028 */  lw        $s0, 0x28($sp)
/* 35EAB8 E0058198 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 35EABC E005819C D7B60048 */  ldc1      $f22, 0x48($sp)
/* 35EAC0 E00581A0 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 35EAC4 E00581A4 03E00008 */  jr        $ra
/* 35EAC8 E00581A8 27BD0058 */   addiu    $sp, $sp, 0x58
