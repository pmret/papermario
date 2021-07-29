.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011B1D8
/* B18D8 8011B1D8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* B18DC 8011B1DC AFB50024 */  sw        $s5, 0x24($sp)
/* B18E0 8011B1E0 0080A82D */  daddu     $s5, $a0, $zero
/* B18E4 8011B1E4 AFBF0030 */  sw        $ra, 0x30($sp)
/* B18E8 8011B1E8 AFB7002C */  sw        $s7, 0x2c($sp)
/* B18EC 8011B1EC AFB60028 */  sw        $s6, 0x28($sp)
/* B18F0 8011B1F0 AFB40020 */  sw        $s4, 0x20($sp)
/* B18F4 8011B1F4 AFB3001C */  sw        $s3, 0x1c($sp)
/* B18F8 8011B1F8 AFB20018 */  sw        $s2, 0x18($sp)
/* B18FC 8011B1FC AFB10014 */  sw        $s1, 0x14($sp)
/* B1900 8011B200 AFB00010 */  sw        $s0, 0x10($sp)
/* B1904 8011B204 8EA30000 */  lw        $v1, ($s5)
/* B1908 8011B208 24020002 */  addiu     $v0, $zero, 2
/* B190C 8011B20C 14620007 */  bne       $v1, $v0, .L8011B22C
/* B1910 8011B210 24020005 */   addiu    $v0, $zero, 5
/* B1914 8011B214 3C028015 */  lui       $v0, %hi(D_80153226)
/* B1918 8011B218 94423226 */  lhu       $v0, %lo(D_80153226)($v0)
/* B191C 8011B21C 3C018015 */  lui       $at, %hi(D_80153376)
/* B1920 8011B220 A4223376 */  sh        $v0, %lo(D_80153376)($at)
/* B1924 8011B224 08046CD4 */  j         .L8011B350
/* B1928 8011B228 00000000 */   nop
.L8011B22C:
/* B192C 8011B22C 14620019 */  bne       $v1, $v0, .L8011B294
/* B1930 8011B230 02A0202D */   daddu    $a0, $s5, $zero
/* B1934 8011B234 0C0456C3 */  jal       get_model_property
/* B1938 8011B238 24050060 */   addiu    $a1, $zero, 0x60
/* B193C 8011B23C 10400015 */  beqz      $v0, .L8011B294
/* B1940 8011B240 00000000 */   nop
/* B1944 8011B244 8C420008 */  lw        $v0, 8($v0)
/* B1948 8011B248 10400012 */  beqz      $v0, .L8011B294
/* B194C 8011B24C 00000000 */   nop
/* B1950 8011B250 0C04572A */  jal       mdl_get_child_count
/* B1954 8011B254 02A0202D */   daddu    $a0, $s5, $zero
/* B1958 8011B258 3C038015 */  lui       $v1, %hi(D_80153224)
/* B195C 8011B25C 24633224 */  addiu     $v1, $v1, %lo(D_80153224)
/* B1960 8011B260 8C640000 */  lw        $a0, ($v1)
/* B1964 8011B264 00822021 */  addu      $a0, $a0, $v0
/* B1968 8011B268 AC640000 */  sw        $a0, ($v1)
/* B196C 8011B26C 94620002 */  lhu       $v0, 2($v1)
/* B1970 8011B270 3C018015 */  lui       $at, %hi(D_80153376)
/* B1974 8011B274 A4223376 */  sh        $v0, %lo(D_80153376)($at)
/* B1978 8011B278 08046CD4 */  j         .L8011B350
/* B197C 8011B27C 00000000 */   nop
.L8011B280:
/* B1980 8011B280 AED00000 */  sw        $s0, ($s6)
/* B1984 8011B284 3C018015 */  lui       $at, %hi(D_80153374)
/* B1988 8011B288 A4323374 */  sh        $s2, %lo(D_80153374)($at)
/* B198C 8011B28C 08046CD4 */  j         .L8011B350
/* B1990 8011B290 00000000 */   nop
.L8011B294:
/* B1994 8011B294 8EA20010 */  lw        $v0, 0x10($s5)
/* B1998 8011B298 1040002D */  beqz      $v0, .L8011B350
/* B199C 8011B29C 00000000 */   nop
/* B19A0 8011B2A0 8C53000C */  lw        $s3, 0xc($v0)
/* B19A4 8011B2A4 1260002A */  beqz      $s3, .L8011B350
/* B19A8 8011B2A8 00000000 */   nop
/* B19AC 8011B2AC 1A600028 */  blez      $s3, .L8011B350
/* B19B0 8011B2B0 0000882D */   daddu    $s1, $zero, $zero
/* B19B4 8011B2B4 3C148015 */  lui       $s4, %hi(D_80153224)
/* B19B8 8011B2B8 26943224 */  addiu     $s4, $s4, %lo(D_80153224)
/* B19BC 8011B2BC 24170005 */  addiu     $s7, $zero, 5
/* B19C0 8011B2C0 3C168015 */  lui       $s6, %hi(D_80153370)
/* B19C4 8011B2C4 26D63370 */  addiu     $s6, $s6, %lo(D_80153370)
.L8011B2C8:
/* B19C8 8011B2C8 8EA20010 */  lw        $v0, 0x10($s5)
/* B19CC 8011B2CC 8C430010 */  lw        $v1, 0x10($v0)
/* B19D0 8011B2D0 00111080 */  sll       $v0, $s1, 2
/* B19D4 8011B2D4 00431021 */  addu      $v0, $v0, $v1
/* B19D8 8011B2D8 8C500000 */  lw        $s0, ($v0)
/* B19DC 8011B2DC 8E020000 */  lw        $v0, ($s0)
/* B19E0 8011B2E0 96920002 */  lhu       $s2, 2($s4)
/* B19E4 8011B2E4 1457000B */  bne       $v0, $s7, .L8011B314
/* B19E8 8011B2E8 0200202D */   daddu    $a0, $s0, $zero
/* B19EC 8011B2EC 0C0456C3 */  jal       get_model_property
/* B19F0 8011B2F0 24050060 */   addiu    $a1, $zero, 0x60
/* B19F4 8011B2F4 10400007 */  beqz      $v0, .L8011B314
/* B19F8 8011B2F8 00000000 */   nop
/* B19FC 8011B2FC 8C420008 */  lw        $v0, 8($v0)
/* B1A00 8011B300 10400004 */  beqz      $v0, .L8011B314
/* B1A04 8011B304 00000000 */   nop
/* B1A08 8011B308 0C04572A */  jal       mdl_get_child_count
/* B1A0C 8011B30C 0200202D */   daddu    $a0, $s0, $zero
/* B1A10 8011B310 02429021 */  addu      $s2, $s2, $v0
.L8011B314:
/* B1A14 8011B314 0C046C76 */  jal       func_8011B1D8
/* B1A18 8011B318 0200202D */   daddu    $a0, $s0, $zero
/* B1A1C 8011B31C 8EC20000 */  lw        $v0, ($s6)
/* B1A20 8011B320 1440000B */  bnez      $v0, .L8011B350
/* B1A24 8011B324 00000000 */   nop
/* B1A28 8011B328 3C028015 */  lui       $v0, %hi(D_8015336E)
/* B1A2C 8011B32C 9442336E */  lhu       $v0, %lo(D_8015336E)($v0)
/* B1A30 8011B330 8E830000 */  lw        $v1, ($s4)
/* B1A34 8011B334 1043FFD2 */  beq       $v0, $v1, .L8011B280
/* B1A38 8011B338 24620001 */   addiu    $v0, $v1, 1
/* B1A3C 8011B33C AE820000 */  sw        $v0, ($s4)
/* B1A40 8011B340 26310001 */  addiu     $s1, $s1, 1
/* B1A44 8011B344 0233102A */  slt       $v0, $s1, $s3
/* B1A48 8011B348 1440FFDF */  bnez      $v0, .L8011B2C8
/* B1A4C 8011B34C 00000000 */   nop
.L8011B350:
/* B1A50 8011B350 8FBF0030 */  lw        $ra, 0x30($sp)
/* B1A54 8011B354 8FB7002C */  lw        $s7, 0x2c($sp)
/* B1A58 8011B358 8FB60028 */  lw        $s6, 0x28($sp)
/* B1A5C 8011B35C 8FB50024 */  lw        $s5, 0x24($sp)
/* B1A60 8011B360 8FB40020 */  lw        $s4, 0x20($sp)
/* B1A64 8011B364 8FB3001C */  lw        $s3, 0x1c($sp)
/* B1A68 8011B368 8FB20018 */  lw        $s2, 0x18($sp)
/* B1A6C 8011B36C 8FB10014 */  lw        $s1, 0x14($sp)
/* B1A70 8011B370 8FB00010 */  lw        $s0, 0x10($sp)
/* B1A74 8011B374 03E00008 */  jr        $ra
/* B1A78 8011B378 27BD0038 */   addiu    $sp, $sp, 0x38
