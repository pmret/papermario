.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_21_main
/* 33E8C0 E002A000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 33E8C4 E002A004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 33E8C8 E002A008 4485A000 */  mtc1      $a1, $f20
/* 33E8CC E002A00C AFB40038 */  sw        $s4, 0x38($sp)
/* 33E8D0 E002A010 0080A02D */  daddu     $s4, $a0, $zero
/* 33E8D4 E002A014 AFB20030 */  sw        $s2, 0x30($sp)
/* 33E8D8 E002A018 24120004 */  addiu     $s2, $zero, 4
/* 33E8DC E002A01C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 33E8E0 E002A020 4486B000 */  mtc1      $a2, $f22
/* 33E8E4 E002A024 27A40010 */  addiu     $a0, $sp, 0x10
/* 33E8E8 E002A028 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 33E8EC E002A02C 4487C000 */  mtc1      $a3, $f24
/* 33E8F0 E002A030 2A820002 */  slti      $v0, $s4, 2
/* 33E8F4 E002A034 AFBF003C */  sw        $ra, 0x3c($sp)
/* 33E8F8 E002A038 AFB30034 */  sw        $s3, 0x34($sp)
/* 33E8FC E002A03C AFB1002C */  sw        $s1, 0x2c($sp)
/* 33E900 E002A040 10400002 */  beqz      $v0, .LE002A04C
/* 33E904 E002A044 AFB00028 */   sw       $s0, 0x28($sp)
/* 33E908 E002A048 24120005 */  addiu     $s2, $zero, 5
.LE002A04C:
/* 33E90C E002A04C 3C02E003 */  lui       $v0, %hi(fx_21_init)
/* 33E910 E002A050 2442A284 */  addiu     $v0, $v0, %lo(fx_21_init)
/* 33E914 E002A054 AFA20018 */  sw        $v0, 0x18($sp)
/* 33E918 E002A058 3C02E003 */  lui       $v0, %hi(fx_21_update)
/* 33E91C E002A05C 2442A28C */  addiu     $v0, $v0, %lo(fx_21_update)
/* 33E920 E002A060 AFA2001C */  sw        $v0, 0x1c($sp)
/* 33E924 E002A064 3C02E003 */  lui       $v0, %hi(fx_21_render)
/* 33E928 E002A068 2442A380 */  addiu     $v0, $v0, %lo(fx_21_render)
/* 33E92C E002A06C AFA20020 */  sw        $v0, 0x20($sp)
/* 33E930 E002A070 24020015 */  addiu     $v0, $zero, 0x15
/* 33E934 E002A074 AFA00010 */  sw        $zero, 0x10($sp)
/* 33E938 E002A078 AFA00024 */  sw        $zero, 0x24($sp)
/* 33E93C E002A07C 0C080124 */  jal       shim_create_effect_instance
/* 33E940 E002A080 AFA20014 */   sw       $v0, 0x14($sp)
/* 33E944 E002A084 001220C0 */  sll       $a0, $s2, 3
/* 33E948 E002A088 00922021 */  addu      $a0, $a0, $s2
/* 33E94C E002A08C 000420C0 */  sll       $a0, $a0, 3
/* 33E950 E002A090 0040982D */  daddu     $s3, $v0, $zero
/* 33E954 E002A094 0C08012C */  jal       shim_general_heap_malloc
/* 33E958 E002A098 AE720008 */   sw       $s2, 8($s3)
/* 33E95C E002A09C 0040202D */  daddu     $a0, $v0, $zero
/* 33E960 E002A0A0 14800003 */  bnez      $a0, .LE002A0B0
/* 33E964 E002A0A4 AE64000C */   sw       $a0, 0xc($s3)
.LE002A0A8:
/* 33E968 E002A0A8 0800A82A */  j         .LE002A0A8
/* 33E96C E002A0AC 00000000 */   nop
.LE002A0B0:
/* 33E970 E002A0B0 2403008C */  addiu     $v1, $zero, 0x8c
/* 33E974 E002A0B4 AC940000 */  sw        $s4, ($a0)
/* 33E978 E002A0B8 E4940004 */  swc1      $f20, 4($a0)
/* 33E97C E002A0BC E4960008 */  swc1      $f22, 8($a0)
/* 33E980 E002A0C0 E498000C */  swc1      $f24, 0xc($a0)
/* 33E984 E002A0C4 8FA20068 */  lw        $v0, 0x68($sp)
/* 33E988 E002A0C8 24110001 */  addiu     $s1, $zero, 1
/* 33E98C E002A0CC AC830038 */  sw        $v1, 0x38($a0)
/* 33E990 E002A0D0 AC830044 */  sw        $v1, 0x44($a0)
/* 33E994 E002A0D4 AC82002C */  sw        $v0, 0x2c($a0)
/* 33E998 E002A0D8 240200FF */  addiu     $v0, $zero, 0xff
/* 33E99C E002A0DC AC820018 */  sw        $v0, 0x18($a0)
/* 33E9A0 E002A0E0 240200A0 */  addiu     $v0, $zero, 0xa0
/* 33E9A4 E002A0E4 AC820030 */  sw        $v0, 0x30($a0)
/* 33E9A8 E002A0E8 AC820034 */  sw        $v0, 0x34($a0)
/* 33E9AC E002A0EC AC82003C */  sw        $v0, 0x3c($a0)
/* 33E9B0 E002A0F0 AC820040 */  sw        $v0, 0x40($a0)
/* 33E9B4 E002A0F4 0232102A */  slt       $v0, $s1, $s2
/* 33E9B8 E002A0F8 10400056 */  beqz      $v0, .LE002A254
/* 33E9BC E002A0FC 24840048 */   addiu    $a0, $a0, 0x48
/* 33E9C0 E002A100 24900008 */  addiu     $s0, $a0, 8
/* 33E9C4 E002A104 3C013F80 */  lui       $at, 0x3f80
/* 33E9C8 E002A108 4481C000 */  mtc1      $at, $f24
/* 33E9CC E002A10C 3C01E003 */  lui       $at, %hi(D_E002A720)
/* 33E9D0 E002A110 D434A720 */  ldc1      $f20, %lo(D_E002A720)($at)
/* 33E9D4 E002A114 3C013ECC */  lui       $at, 0x3ecc
/* 33E9D8 E002A118 3421CCCD */  ori       $at, $at, 0xcccd
/* 33E9DC E002A11C 4481B000 */  mtc1      $at, $f22
.LE002A120:
/* 33E9E0 E002A120 0C080138 */  jal       shim_rand_int
/* 33E9E4 E002A124 240400C8 */   addiu    $a0, $zero, 0xc8
/* 33E9E8 E002A128 24040032 */  addiu     $a0, $zero, 0x32
/* 33E9EC E002A12C 2442FF9C */  addiu     $v0, $v0, -0x64
/* 33E9F0 E002A130 44820000 */  mtc1      $v0, $f0
/* 33E9F4 E002A134 00000000 */  nop
/* 33E9F8 E002A138 46800020 */  cvt.s.w   $f0, $f0
/* 33E9FC E002A13C 0C080138 */  jal       shim_rand_int
/* 33EA00 E002A140 E600FFFC */   swc1     $f0, -4($s0)
/* 33EA04 E002A144 2404000A */  addiu     $a0, $zero, 0xa
/* 33EA08 E002A148 3C01BF80 */  lui       $at, 0xbf80
/* 33EA0C E002A14C 44811000 */  mtc1      $at, $f2
/* 33EA10 E002A150 44820000 */  mtc1      $v0, $f0
/* 33EA14 E002A154 00000000 */  nop
/* 33EA18 E002A158 46800020 */  cvt.s.w   $f0, $f0
/* 33EA1C E002A15C E6000000 */  swc1      $f0, ($s0)
/* 33EA20 E002A160 AE000004 */  sw        $zero, 4($s0)
/* 33EA24 E002A164 AE00000C */  sw        $zero, 0xc($s0)
/* 33EA28 E002A168 E6180014 */  swc1      $f24, 0x14($s0)
/* 33EA2C E002A16C E6180018 */  swc1      $f24, 0x18($s0)
/* 33EA30 E002A170 0C080138 */  jal       shim_rand_int
/* 33EA34 E002A174 E6020008 */   swc1     $f2, 8($s0)
/* 33EA38 E002A178 3C0351EB */  lui       $v1, 0x51eb
/* 33EA3C E002A17C 3463851F */  ori       $v1, $v1, 0x851f
/* 33EA40 E002A180 00430018 */  mult      $v0, $v1
/* 33EA44 E002A184 000217C3 */  sra       $v0, $v0, 0x1f
/* 33EA48 E002A188 00004010 */  mfhi      $t0
/* 33EA4C E002A18C 00081983 */  sra       $v1, $t0, 6
/* 33EA50 E002A190 00621823 */  subu      $v1, $v1, $v0
/* 33EA54 E002A194 44830000 */  mtc1      $v1, $f0
/* 33EA58 E002A198 00000000 */  nop
/* 33EA5C E002A19C 46800020 */  cvt.s.w   $f0, $f0
/* 33EA60 E002A1A0 12800006 */  beqz      $s4, .LE002A1BC
/* 33EA64 E002A1A4 E600001C */   swc1     $f0, 0x1c($s0)
/* 33EA68 E002A1A8 24020001 */  addiu     $v0, $zero, 1
/* 33EA6C E002A1AC 12820008 */  beq       $s4, $v0, .LE002A1D0
/* 33EA70 E002A1B0 24040028 */   addiu    $a0, $zero, 0x28
/* 33EA74 E002A1B4 0800A87C */  j         .LE002A1F0
/* 33EA78 E002A1B8 E616001C */   swc1     $f22, 0x1c($s0)
.LE002A1BC:
/* 33EA7C E002A1BC 46000021 */  cvt.d.s   $f0, $f0
/* 33EA80 E002A1C0 46340002 */  mul.d     $f0, $f0, $f20
/* 33EA84 E002A1C4 00000000 */  nop
/* 33EA88 E002A1C8 0800A87A */  j         .LE002A1E8
/* 33EA8C E002A1CC 46200020 */   cvt.s.d  $f0, $f0
.LE002A1D0:
/* 33EA90 E002A1D0 3C01E003 */  lui       $at, %hi(D_E002A728)
/* 33EA94 E002A1D4 D422A728 */  ldc1      $f2, %lo(D_E002A728)($at)
/* 33EA98 E002A1D8 46000021 */  cvt.d.s   $f0, $f0
/* 33EA9C E002A1DC 46220002 */  mul.d     $f0, $f0, $f2
/* 33EAA0 E002A1E0 00000000 */  nop
/* 33EAA4 E002A1E4 46200020 */  cvt.s.d   $f0, $f0
.LE002A1E8:
/* 33EAA8 E002A1E8 0800A891 */  j         .LE002A244
/* 33EAAC E002A1EC E6000020 */   swc1     $f0, 0x20($s0)
.LE002A1F0:
/* 33EAB0 E002A1F0 E6160020 */  swc1      $f22, 0x20($s0)
/* 33EAB4 E002A1F4 0C080138 */  jal       shim_rand_int
/* 33EAB8 E002A1F8 AE000008 */   sw       $zero, 8($s0)
/* 33EABC E002A1FC 2442FFEC */  addiu     $v0, $v0, -0x14
/* 33EAC0 E002A200 44820000 */  mtc1      $v0, $f0
/* 33EAC4 E002A204 00000000 */  nop
/* 33EAC8 E002A208 46800021 */  cvt.d.w   $f0, $f0
/* 33EACC E002A20C 46340002 */  mul.d     $f0, $f0, $f20
/* 33EAD0 E002A210 00000000 */  nop
/* 33EAD4 E002A214 24040028 */  addiu     $a0, $zero, 0x28
/* 33EAD8 E002A218 46200020 */  cvt.s.d   $f0, $f0
/* 33EADC E002A21C 0C080138 */  jal       shim_rand_int
/* 33EAE0 E002A220 E600FFFC */   swc1     $f0, -4($s0)
/* 33EAE4 E002A224 2442FFEC */  addiu     $v0, $v0, -0x14
/* 33EAE8 E002A228 44820000 */  mtc1      $v0, $f0
/* 33EAEC E002A22C 00000000 */  nop
/* 33EAF0 E002A230 46800021 */  cvt.d.w   $f0, $f0
/* 33EAF4 E002A234 46340002 */  mul.d     $f0, $f0, $f20
/* 33EAF8 E002A238 00000000 */  nop
/* 33EAFC E002A23C 46200020 */  cvt.s.d   $f0, $f0
/* 33EB00 E002A240 E6000000 */  swc1      $f0, ($s0)
.LE002A244:
/* 33EB04 E002A244 26310001 */  addiu     $s1, $s1, 1
/* 33EB08 E002A248 0232102A */  slt       $v0, $s1, $s2
/* 33EB0C E002A24C 1440FFB4 */  bnez      $v0, .LE002A120
/* 33EB10 E002A250 26100048 */   addiu    $s0, $s0, 0x48
.LE002A254:
/* 33EB14 E002A254 0260102D */  daddu     $v0, $s3, $zero
/* 33EB18 E002A258 8FBF003C */  lw        $ra, 0x3c($sp)
/* 33EB1C E002A25C 8FB40038 */  lw        $s4, 0x38($sp)
/* 33EB20 E002A260 8FB30034 */  lw        $s3, 0x34($sp)
/* 33EB24 E002A264 8FB20030 */  lw        $s2, 0x30($sp)
/* 33EB28 E002A268 8FB1002C */  lw        $s1, 0x2c($sp)
/* 33EB2C E002A26C 8FB00028 */  lw        $s0, 0x28($sp)
/* 33EB30 E002A270 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 33EB34 E002A274 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 33EB38 E002A278 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 33EB3C E002A27C 03E00008 */  jr        $ra
/* 33EB40 E002A280 27BD0058 */   addiu    $sp, $sp, 0x58
