.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_72_main
/* 38F900 E0090000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 38F904 E0090004 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 38F908 E0090008 4485C000 */  mtc1      $a1, $f24
/* 38F90C E009000C F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 38F910 E0090010 4486D000 */  mtc1      $a2, $f26
/* 38F914 E0090014 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 38F918 E0090018 4487E000 */  mtc1      $a3, $f28
/* 38F91C E009001C AFB20030 */  sw        $s2, 0x30($sp)
/* 38F920 E0090020 0080902D */  daddu     $s2, $a0, $zero
/* 38F924 E0090024 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 38F928 E0090028 C7B60078 */  lwc1      $f22, 0x78($sp)
/* 38F92C E009002C 27A40010 */  addiu     $a0, $sp, 0x10
/* 38F930 E0090030 AFB30034 */  sw        $s3, 0x34($sp)
/* 38F934 E0090034 8FB3007C */  lw        $s3, 0x7c($sp)
/* 38F938 E0090038 3C02E009 */  lui       $v0, %hi(func_E00901C0)
/* 38F93C E009003C 244201C0 */  addiu     $v0, $v0, %lo(func_E00901C0)
/* 38F940 E0090040 AFA20018 */  sw        $v0, 0x18($sp)
/* 38F944 E0090044 3C02E009 */  lui       $v0, %hi(func_E00901C8)
/* 38F948 E0090048 244201C8 */  addiu     $v0, $v0, %lo(func_E00901C8)
/* 38F94C E009004C AFA2001C */  sw        $v0, 0x1c($sp)
/* 38F950 E0090050 3C02E009 */  lui       $v0, %hi(func_E0090420)
/* 38F954 E0090054 24420420 */  addiu     $v0, $v0, %lo(func_E0090420)
/* 38F958 E0090058 AFA20020 */  sw        $v0, 0x20($sp)
/* 38F95C E009005C 3C02E009 */  lui       $v0, %hi(func_E0090428)
/* 38F960 E0090060 24420428 */  addiu     $v0, $v0, %lo(func_E0090428)
/* 38F964 E0090064 AFA20024 */  sw        $v0, 0x24($sp)
/* 38F968 E0090068 24020048 */  addiu     $v0, $zero, 0x48
/* 38F96C E009006C AFBF0038 */  sw        $ra, 0x38($sp)
/* 38F970 E0090070 AFB1002C */  sw        $s1, 0x2c($sp)
/* 38F974 E0090074 AFB00028 */  sw        $s0, 0x28($sp)
/* 38F978 E0090078 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 38F97C E009007C AFA00010 */  sw        $zero, 0x10($sp)
/* 38F980 E0090080 0C080124 */  jal       shim_create_effect_instance
/* 38F984 E0090084 AFA20014 */   sw       $v0, 0x14($sp)
/* 38F988 E0090088 24040038 */  addiu     $a0, $zero, 0x38
/* 38F98C E009008C 24030001 */  addiu     $v1, $zero, 1
/* 38F990 E0090090 0040882D */  daddu     $s1, $v0, $zero
/* 38F994 E0090094 0C08012C */  jal       shim_general_heap_malloc
/* 38F998 E0090098 AE230008 */   sw       $v1, 8($s1)
/* 38F99C E009009C 0040802D */  daddu     $s0, $v0, $zero
/* 38F9A0 E00900A0 16000003 */  bnez      $s0, .LE00900B0
/* 38F9A4 E00900A4 AE22000C */   sw       $v0, 0xc($s1)
.LE00900A8:
/* 38F9A8 E00900A8 0802402A */  j         .LE00900A8
/* 38F9AC E00900AC 00000000 */   nop
.LE00900B0:
/* 38F9B0 E00900B0 3C036666 */  lui       $v1, 0x6666
/* 38F9B4 E00900B4 34636667 */  ori       $v1, $v1, 0x6667
/* 38F9B8 E00900B8 24020001 */  addiu     $v0, $zero, 1
/* 38F9BC E00900BC 02430018 */  mult      $s2, $v1
/* 38F9C0 E00900C0 AE020024 */  sw        $v0, 0x24($s0)
/* 38F9C4 E00900C4 AE000020 */  sw        $zero, 0x20($s0)
/* 38F9C8 E00900C8 AE120000 */  sw        $s2, ($s0)
/* 38F9CC E00900CC AE00001C */  sw        $zero, 0x1c($s0)
/* 38F9D0 E00900D0 00004010 */  mfhi      $t0
/* 38F9D4 E00900D4 00481807 */  srav      $v1, $t0, $v0
/* 38F9D8 E00900D8 001217C3 */  sra       $v0, $s2, 0x1f
/* 38F9DC E00900DC 00621823 */  subu      $v1, $v1, $v0
/* 38F9E0 E00900E0 00031080 */  sll       $v0, $v1, 2
/* 38F9E4 E00900E4 00431021 */  addu      $v0, $v0, $v1
/* 38F9E8 E00900E8 02421023 */  subu      $v0, $s2, $v0
/* 38F9EC E00900EC 1E600004 */  bgtz      $s3, .LE0090100
/* 38F9F0 E00900F0 AE020004 */   sw       $v0, 4($s0)
/* 38F9F4 E00900F4 24020064 */  addiu     $v0, $zero, 0x64
/* 38F9F8 E00900F8 08024041 */  j         .LE0090104
/* 38F9FC E00900FC AE020018 */   sw       $v0, 0x18($s0)
.LE0090100:
/* 38FA00 E0090100 AE130018 */  sw        $s3, 0x18($s0)
.LE0090104:
/* 38FA04 E0090104 240200FF */  addiu     $v0, $zero, 0xff
/* 38FA08 E0090108 AE020014 */  sw        $v0, 0x14($s0)
/* 38FA0C E009010C 2A420005 */  slti      $v0, $s2, 5
/* 38FA10 E0090110 50400014 */  beql      $v0, $zero, .LE0090164
/* 38FA14 E0090114 AE000010 */   sw       $zero, 0x10($s0)
/* 38FA18 E0090118 3C0141F0 */  lui       $at, 0x41f0
/* 38FA1C E009011C 4481A000 */  mtc1      $at, $f20
/* 38FA20 E0090120 E6180008 */  swc1      $f24, 8($s0)
/* 38FA24 E0090124 E61A000C */  swc1      $f26, 0xc($s0)
/* 38FA28 E0090128 E61C0010 */  swc1      $f28, 0x10($s0)
/* 38FA2C E009012C 0C080140 */  jal       shim_sin_deg
/* 38FA30 E0090130 4600A306 */   mov.s    $f12, $f20
/* 38FA34 E0090134 46000007 */  neg.s     $f0, $f0
/* 38FA38 E0090138 46160002 */  mul.s     $f0, $f0, $f22
/* 38FA3C E009013C 00000000 */  nop
/* 38FA40 E0090140 46000000 */  add.s     $f0, $f0, $f0
/* 38FA44 E0090144 4600A306 */  mov.s     $f12, $f20
/* 38FA48 E0090148 0C080144 */  jal       shim_cos_deg
/* 38FA4C E009014C E6000030 */   swc1     $f0, 0x30($s0)
/* 38FA50 E0090150 46160002 */  mul.s     $f0, $f0, $f22
/* 38FA54 E0090154 00000000 */  nop
/* 38FA58 E0090158 46000000 */  add.s     $f0, $f0, $f0
/* 38FA5C E009015C 08024063 */  j         .LE009018C
/* 38FA60 E0090160 E6000034 */   swc1     $f0, 0x34($s0)
.LE0090164:
/* 38FA64 E0090164 3C01C2C8 */  lui       $at, 0xc2c8
/* 38FA68 E0090168 44810000 */  mtc1      $at, $f0
/* 38FA6C E009016C 3C014220 */  lui       $at, 0x4220
/* 38FA70 E0090170 44811000 */  mtc1      $at, $f2
/* 38FA74 E0090174 3C0142E6 */  lui       $at, 0x42e6
/* 38FA78 E0090178 44812000 */  mtc1      $at, $f4
/* 38FA7C E009017C AE000034 */  sw        $zero, 0x34($s0)
/* 38FA80 E0090180 E6000008 */  swc1      $f0, 8($s0)
/* 38FA84 E0090184 E602000C */  swc1      $f2, 0xc($s0)
/* 38FA88 E0090188 E6040030 */  swc1      $f4, 0x30($s0)
.LE009018C:
/* 38FA8C E009018C 0220102D */  daddu     $v0, $s1, $zero
/* 38FA90 E0090190 8FBF0038 */  lw        $ra, 0x38($sp)
/* 38FA94 E0090194 8FB30034 */  lw        $s3, 0x34($sp)
/* 38FA98 E0090198 8FB20030 */  lw        $s2, 0x30($sp)
/* 38FA9C E009019C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 38FAA0 E00901A0 8FB00028 */  lw        $s0, 0x28($sp)
/* 38FAA4 E00901A4 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 38FAA8 E00901A8 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 38FAAC E00901AC D7B80050 */  ldc1      $f24, 0x50($sp)
/* 38FAB0 E00901B0 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 38FAB4 E00901B4 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 38FAB8 E00901B8 03E00008 */  jr        $ra
/* 38FABC E00901BC 27BD0068 */   addiu    $sp, $sp, 0x68
