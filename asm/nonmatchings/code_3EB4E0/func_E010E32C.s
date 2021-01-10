.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E010E32C
/* 3EB80C E010E32C 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3EB810 E010E330 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 3EB814 E010E334 4485A000 */  mtc1      $a1, $f20
/* 3EB818 E010E338 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 3EB81C E010E33C 4486B000 */  mtc1      $a2, $f22
/* 3EB820 E010E340 AFB20030 */  sw        $s2, 0x30($sp)
/* 3EB824 E010E344 0080902D */  daddu     $s2, $a0, $zero
/* 3EB828 E010E348 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3EB82C E010E34C 4487C000 */  mtc1      $a3, $f24
/* 3EB830 E010E350 27A40010 */  addiu     $a0, $sp, 0x10
/* 3EB834 E010E354 AFB30034 */  sw        $s3, 0x34($sp)
/* 3EB838 E010E358 8FB3006C */  lw        $s3, 0x6c($sp)
/* 3EB83C E010E35C 3C02E011 */  lui       $v0, %hi(func_E010E4A0)
/* 3EB840 E010E360 2442E4A0 */  addiu     $v0, $v0, %lo(func_E010E4A0)
/* 3EB844 E010E364 AFA20018 */  sw        $v0, 0x18($sp)
/* 3EB848 E010E368 3C02E011 */  lui       $v0, %hi(func_E010E4A8)
/* 3EB84C E010E36C 2442E4A8 */  addiu     $v0, $v0, %lo(func_E010E4A8)
/* 3EB850 E010E370 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3EB854 E010E374 3C02E011 */  lui       $v0, %hi(func_E010E510)
/* 3EB858 E010E378 2442E510 */  addiu     $v0, $v0, %lo(func_E010E510)
/* 3EB85C E010E37C AFA20020 */  sw        $v0, 0x20($sp)
/* 3EB860 E010E380 24020079 */  addiu     $v0, $zero, 0x79
/* 3EB864 E010E384 AFBF0038 */  sw        $ra, 0x38($sp)
/* 3EB868 E010E388 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3EB86C E010E38C AFB00028 */  sw        $s0, 0x28($sp)
/* 3EB870 E010E390 AFA00010 */  sw        $zero, 0x10($sp)
/* 3EB874 E010E394 AFA00024 */  sw        $zero, 0x24($sp)
/* 3EB878 E010E398 0C080124 */  jal       func_E0200490
/* 3EB87C E010E39C AFA20014 */   sw       $v0, 0x14($sp)
/* 3EB880 E010E3A0 24040058 */  addiu     $a0, $zero, 0x58
/* 3EB884 E010E3A4 24030001 */  addiu     $v1, $zero, 1
/* 3EB888 E010E3A8 0040882D */  daddu     $s1, $v0, $zero
/* 3EB88C E010E3AC 0C08012C */  jal       func_E02004B0
/* 3EB890 E010E3B0 AE230008 */   sw       $v1, 8($s1)
/* 3EB894 E010E3B4 0040802D */  daddu     $s0, $v0, $zero
/* 3EB898 E010E3B8 16000003 */  bnez      $s0, .LE010E3C8
/* 3EB89C E010E3BC AE22000C */   sw       $v0, 0xc($s1)
.LE010E3C0:
/* 3EB8A0 E010E3C0 080438F0 */  j         .LE010E3C0
/* 3EB8A4 E010E3C4 00000000 */   nop      
.LE010E3C8:
/* 3EB8A8 E010E3C8 AE120000 */  sw        $s2, ($s0)
/* 3EB8AC E010E3CC 1E600004 */  bgtz      $s3, .LE010E3E0
/* 3EB8B0 E010E3D0 AE00001C */   sw       $zero, 0x1c($s0)
/* 3EB8B4 E010E3D4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3EB8B8 E010E3D8 080438F9 */  j         .LE010E3E4
/* 3EB8BC E010E3DC AE020018 */   sw       $v0, 0x18($s0)
.LE010E3E0:
/* 3EB8C0 E010E3E0 AE130018 */  sw        $s3, 0x18($s0)
.LE010E3E4:
/* 3EB8C4 E010E3E4 E6140010 */  swc1      $f20, 0x10($s0)
/* 3EB8C8 E010E3E8 E6140004 */  swc1      $f20, 4($s0)
/* 3EB8CC E010E3EC E6160014 */  swc1      $f22, 0x14($s0)
/* 3EB8D0 E010E3F0 E6160008 */  swc1      $f22, 8($s0)
/* 3EB8D4 E010E3F4 E618000C */  swc1      $f24, 0xc($s0)
/* 3EB8D8 E010E3F8 C7A00068 */  lwc1      $f0, 0x68($sp)
/* 3EB8DC E010E3FC 240300FF */  addiu     $v1, $zero, 0xff
/* 3EB8E0 E010E400 AE030020 */  sw        $v1, 0x20($s0)
/* 3EB8E4 E010E404 AE030024 */  sw        $v1, 0x24($s0)
/* 3EB8E8 E010E408 AE030028 */  sw        $v1, 0x28($s0)
/* 3EB8EC E010E40C AE03002C */  sw        $v1, 0x2c($s0)
/* 3EB8F0 E010E410 AE000030 */  sw        $zero, 0x30($s0)
/* 3EB8F4 E010E414 AE000034 */  sw        $zero, 0x34($s0)
/* 3EB8F8 E010E418 AE000038 */  sw        $zero, 0x38($s0)
/* 3EB8FC E010E41C 12400005 */  beqz      $s2, .LE010E434
/* 3EB900 E010E420 E6000050 */   swc1     $f0, 0x50($s0)
/* 3EB904 E010E424 2642FFF6 */  addiu     $v0, $s2, -0xa
/* 3EB908 E010E428 2C420009 */  sltiu     $v0, $v0, 9
/* 3EB90C E010E42C 50400002 */  beql      $v0, $zero, .LE010E438
/* 3EB910 E010E430 AE03003C */   sw       $v1, 0x3c($s0)
.LE010E434:
/* 3EB914 E010E434 AE00003C */  sw        $zero, 0x3c($s0)
.LE010E438:
/* 3EB918 E010E438 00121080 */  sll       $v0, $s2, 2
/* 3EB91C E010E43C 3C01E011 */  lui       $at, %hi(D_E010E750)
/* 3EB920 E010E440 00220821 */  addu      $at, $at, $v0
/* 3EB924 E010E444 8C22E750 */  lw        $v0, %lo(D_E010E750)($at)
/* 3EB928 E010E448 0440000A */  bltz      $v0, .LE010E474
/* 3EB92C E010E44C AE020054 */   sw       $v0, 0x54($s0)
/* 3EB930 E010E450 0040202D */  daddu     $a0, $v0, $zero
/* 3EB934 E010E454 240200A0 */  addiu     $v0, $zero, 0xa0
/* 3EB938 E010E458 0000282D */  daddu     $a1, $zero, $zero
/* 3EB93C E010E45C AE020040 */  sw        $v0, 0x40($s0)
/* 3EB940 E010E460 0C080198 */  jal       func_E0200660
/* 3EB944 E010E464 AE020044 */   sw       $v0, 0x44($s0)
/* 3EB948 E010E468 AE020048 */  sw        $v0, 0x48($s0)
/* 3EB94C E010E46C 24020018 */  addiu     $v0, $zero, 0x18
/* 3EB950 E010E470 AE02004C */  sw        $v0, 0x4c($s0)
.LE010E474:
/* 3EB954 E010E474 0220102D */  daddu     $v0, $s1, $zero
/* 3EB958 E010E478 8FBF0038 */  lw        $ra, 0x38($sp)
/* 3EB95C E010E47C 8FB30034 */  lw        $s3, 0x34($sp)
/* 3EB960 E010E480 8FB20030 */  lw        $s2, 0x30($sp)
/* 3EB964 E010E484 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3EB968 E010E488 8FB00028 */  lw        $s0, 0x28($sp)
/* 3EB96C E010E48C D7B80050 */  ldc1      $f24, 0x50($sp)
/* 3EB970 E010E490 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 3EB974 E010E494 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 3EB978 E010E498 03E00008 */  jr        $ra
/* 3EB97C E010E49C 27BD0058 */   addiu    $sp, $sp, 0x58
