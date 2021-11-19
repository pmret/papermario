.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_63_update
/* 37F924 E007E204 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 37F928 E007E208 AFB1001C */  sw        $s1, 0x1c($sp)
/* 37F92C E007E20C 0080882D */  daddu     $s1, $a0, $zero
/* 37F930 E007E210 AFBF0020 */  sw        $ra, 0x20($sp)
/* 37F934 E007E214 AFB00018 */  sw        $s0, 0x18($sp)
/* 37F938 E007E218 8E30000C */  lw        $s0, 0xc($s1)
/* 37F93C E007E21C 8E050004 */  lw        $a1, 4($s0)
/* 37F940 E007E220 8E020044 */  lw        $v0, 0x44($s0)
/* 37F944 E007E224 8E030040 */  lw        $v1, 0x40($s0)
/* 37F948 E007E228 24420001 */  addiu     $v0, $v0, 1
/* 37F94C E007E22C 24630001 */  addiu     $v1, $v1, 1
/* 37F950 E007E230 AE020044 */  sw        $v0, 0x44($s0)
/* 37F954 E007E234 24020007 */  addiu     $v0, $zero, 7
/* 37F958 E007E238 14A20005 */  bne       $a1, $v0, .LE007E250
/* 37F95C E007E23C AE030040 */   sw       $v1, 0x40($s0)
/* 37F960 E007E240 0C080128 */  jal       shim_remove_effect
/* 37F964 E007E244 00000000 */   nop
/* 37F968 E007E248 0801F93D */  j         .LE007E4F4
/* 37F96C E007E24C 00000000 */   nop
.LE007E250:
/* 37F970 E007E250 2CA20007 */  sltiu     $v0, $a1, 7
/* 37F974 E007E254 10400075 */  beqz      $v0, .LE007E42C
/* 37F978 E007E258 00051080 */   sll      $v0, $a1, 2
/* 37F97C E007E25C 3C01E008 */  lui       $at, %hi(jtbl_E007EC48)
/* 37F980 E007E260 00220821 */  addu      $at, $at, $v0
/* 37F984 E007E264 8C22EC48 */  lw        $v0, %lo(jtbl_E007EC48)($at)
/* 37F988 E007E268 00400008 */  jr        $v0
/* 37F98C E007E26C 00000000 */   nop
dlabel LE007E270_37F990
/* 37F990 E007E270 0C080150 */  jal       shim_load_effect
/* 37F994 E007E274 2404002D */   addiu    $a0, $zero, 0x2d
/* 37F998 E007E278 C6020008 */  lwc1      $f2, 8($s0)
/* 37F99C E007E27C 3C014120 */  lui       $at, 0x4120
/* 37F9A0 E007E280 44810000 */  mtc1      $at, $f0
/* 37F9A4 E007E284 24020007 */  addiu     $v0, $zero, 7
/* 37F9A8 E007E288 AFA20010 */  sw        $v0, 0x10($sp)
/* 37F9AC E007E28C 24020014 */  addiu     $v0, $zero, 0x14
/* 37F9B0 E007E290 AFA20014 */  sw        $v0, 0x14($sp)
/* 37F9B4 E007E294 46001081 */  sub.s     $f2, $f2, $f0
/* 37F9B8 E007E298 8E06000C */  lw        $a2, 0xc($s0)
/* 37F9BC E007E29C 8E070010 */  lw        $a3, 0x10($s0)
/* 37F9C0 E007E2A0 44051000 */  mfc1      $a1, $f2
/* 37F9C4 E007E2A4 0C016800 */  jal       fx_45_main
/* 37F9C8 E007E2A8 0000202D */   daddu    $a0, $zero, $zero
/* 37F9CC E007E2AC 8E020004 */  lw        $v0, 4($s0)
/* 37F9D0 E007E2B0 AE000034 */  sw        $zero, 0x34($s0)
/* 37F9D4 E007E2B4 AE000038 */  sw        $zero, 0x38($s0)
/* 37F9D8 E007E2B8 0801F909 */  j         .LE007E424
/* 37F9DC E007E2BC AE000040 */   sw       $zero, 0x40($s0)
dlabel LE007E2C0_37F9E0
/* 37F9E0 E007E2C0 28620008 */  slti      $v0, $v1, 8
/* 37F9E4 E007E2C4 14400004 */  bnez      $v0, .LE007E2D8
/* 37F9E8 E007E2C8 00000000 */   nop
/* 37F9EC E007E2CC 8E020004 */  lw        $v0, 4($s0)
/* 37F9F0 E007E2D0 0801F909 */  j         .LE007E424
/* 37F9F4 E007E2D4 AE000040 */   sw       $zero, 0x40($s0)
.LE007E2D8:
/* 37F9F8 E007E2D8 3C02E008 */  lui       $v0, %hi(D_E007EC2F)
/* 37F9FC E007E2DC 00431021 */  addu      $v0, $v0, $v1
/* 37FA00 E007E2E0 8042EC2F */  lb        $v0, %lo(D_E007EC2F)($v0)
/* 37FA04 E007E2E4 3C01E008 */  lui       $at, %hi(D_E007EC68)
/* 37FA08 E007E2E8 D422EC68 */  ldc1      $f2, %lo(D_E007EC68)($at)
/* 37FA0C E007E2EC 44820000 */  mtc1      $v0, $f0
/* 37FA10 E007E2F0 00000000 */  nop
/* 37FA14 E007E2F4 46800021 */  cvt.d.w   $f0, $f0
/* 37FA18 E007E2F8 46220002 */  mul.d     $f0, $f0, $f2
/* 37FA1C E007E2FC 00000000 */  nop
/* 37FA20 E007E300 AE000034 */  sw        $zero, 0x34($s0)
/* 37FA24 E007E304 AE000038 */  sw        $zero, 0x38($s0)
/* 37FA28 E007E308 46200020 */  cvt.s.d   $f0, $f0
/* 37FA2C E007E30C 0801F90B */  j         .LE007E42C
/* 37FA30 E007E310 E6000030 */   swc1     $f0, 0x30($s0)
dlabel LE007E314_37FA34
/* 37FA34 E007E314 28620002 */  slti      $v0, $v1, 2
/* 37FA38 E007E318 14400004 */  bnez      $v0, .LE007E32C
/* 37FA3C E007E31C 24020001 */   addiu    $v0, $zero, 1
/* 37FA40 E007E320 8E020004 */  lw        $v0, 4($s0)
/* 37FA44 E007E324 0801F909 */  j         .LE007E424
/* 37FA48 E007E328 AE000040 */   sw       $zero, 0x40($s0)
.LE007E32C:
/* 37FA4C E007E32C 0801F90B */  j         .LE007E42C
/* 37FA50 E007E330 AE020034 */   sw       $v0, 0x34($s0)
dlabel LE007E334_37FA54
/* 37FA54 E007E334 2862000F */  slti      $v0, $v1, 0xf
/* 37FA58 E007E338 14400004 */  bnez      $v0, .LE007E34C
/* 37FA5C E007E33C 24020002 */   addiu    $v0, $zero, 2
/* 37FA60 E007E340 8E020004 */  lw        $v0, 4($s0)
/* 37FA64 E007E344 0801F909 */  j         .LE007E424
/* 37FA68 E007E348 AE000040 */   sw       $zero, 0x40($s0)
.LE007E34C:
/* 37FA6C E007E34C 0801F90B */  j         .LE007E42C
/* 37FA70 E007E350 AE020034 */   sw       $v0, 0x34($s0)
dlabel LE007E354_37FA74
/* 37FA74 E007E354 2862002D */  slti      $v0, $v1, 0x2d
/* 37FA78 E007E358 14400004 */  bnez      $v0, .LE007E36C
/* 37FA7C E007E35C 24020003 */   addiu    $v0, $zero, 3
/* 37FA80 E007E360 8E020004 */  lw        $v0, 4($s0)
/* 37FA84 E007E364 0801F909 */  j         .LE007E424
/* 37FA88 E007E368 AE000040 */   sw       $zero, 0x40($s0)
.LE007E36C:
/* 37FA8C E007E36C AE020034 */  sw        $v0, 0x34($s0)
/* 37FA90 E007E370 30620001 */  andi      $v0, $v1, 1
/* 37FA94 E007E374 10400005 */  beqz      $v0, .LE007E38C
/* 37FA98 E007E378 AE00002C */   sw       $zero, 0x2c($s0)
/* 37FA9C E007E37C 3C013F80 */  lui       $at, 0x3f80
/* 37FAA0 E007E380 44810000 */  mtc1      $at, $f0
/* 37FAA4 E007E384 0801F90B */  j         .LE007E42C
/* 37FAA8 E007E388 E6000030 */   swc1     $f0, 0x30($s0)
.LE007E38C:
/* 37FAAC E007E38C 3C013F86 */  lui       $at, 0x3f86
/* 37FAB0 E007E390 34216666 */  ori       $at, $at, 0x6666
/* 37FAB4 E007E394 44810000 */  mtc1      $at, $f0
/* 37FAB8 E007E398 0801F90B */  j         .LE007E42C
/* 37FABC E007E39C E6000030 */   swc1     $f0, 0x30($s0)
dlabel LE007E3A0_37FAC0
/* 37FAC0 E007E3A0 2862000A */  slti      $v0, $v1, 0xa
/* 37FAC4 E007E3A4 54400004 */  bnel      $v0, $zero, .LE007E3B8
/* 37FAC8 E007E3A8 AE000034 */   sw       $zero, 0x34($s0)
/* 37FACC E007E3AC 8E020004 */  lw        $v0, 4($s0)
/* 37FAD0 E007E3B0 0801F909 */  j         .LE007E424
/* 37FAD4 E007E3B4 AE000040 */   sw       $zero, 0x40($s0)
.LE007E3B8:
/* 37FAD8 E007E3B8 3C01C120 */  lui       $at, 0xc120
/* 37FADC E007E3BC 44810000 */  mtc1      $at, $f0
/* 37FAE0 E007E3C0 0801F90B */  j         .LE007E42C
/* 37FAE4 E007E3C4 E600002C */   swc1     $f0, 0x2c($s0)
dlabel LE007E3C8_37FAE8
/* 37FAE8 E007E3C8 C6040028 */  lwc1      $f4, 0x28($s0)
/* 37FAEC E007E3CC 3C014210 */  lui       $at, 0x4210
/* 37FAF0 E007E3D0 44810000 */  mtc1      $at, $f0
/* 37FAF4 E007E3D4 00000000 */  nop
/* 37FAF8 E007E3D8 46002100 */  add.s     $f4, $f4, $f0
/* 37FAFC E007E3DC 3C01E008 */  lui       $at, %hi(D_E007EC70)
/* 37FB00 E007E3E0 D422EC70 */  ldc1      $f2, %lo(D_E007EC70)($at)
/* 37FB04 E007E3E4 C600003C */  lwc1      $f0, 0x3c($s0)
/* 37FB08 E007E3E8 46800021 */  cvt.d.w   $f0, $f0
/* 37FB0C E007E3EC 46220002 */  mul.d     $f0, $f0, $f2
/* 37FB10 E007E3F0 00000000 */  nop
/* 37FB14 E007E3F4 E6040028 */  swc1      $f4, 0x28($s0)
/* 37FB18 E007E3F8 46002086 */  mov.s     $f2, $f4
/* 37FB1C E007E3FC 3C014434 */  lui       $at, 0x4434
/* 37FB20 E007E400 44812000 */  mtc1      $at, $f4
/* 37FB24 E007E404 AE000034 */  sw        $zero, 0x34($s0)
/* 37FB28 E007E408 4602203E */  c.le.s    $f4, $f2
/* 37FB2C E007E40C 4620028D */  trunc.w.d $f10, $f0
/* 37FB30 E007E410 E60A003C */  swc1      $f10, 0x3c($s0)
/* 37FB34 E007E414 45000005 */  bc1f      .LE007E42C
/* 37FB38 E007E418 00000000 */   nop
/* 37FB3C E007E41C 8E020004 */  lw        $v0, 4($s0)
/* 37FB40 E007E420 E6040028 */  swc1      $f4, 0x28($s0)
.LE007E424:
/* 37FB44 E007E424 24420001 */  addiu     $v0, $v0, 1
/* 37FB48 E007E428 AE020004 */  sw        $v0, 4($s0)
.LE007E42C:
/* 37FB4C E007E42C 8E050004 */  lw        $a1, 4($s0)
/* 37FB50 E007E430 24A2FFFC */  addiu     $v0, $a1, -4
/* 37FB54 E007E434 2C420003 */  sltiu     $v0, $v0, 3
/* 37FB58 E007E438 1040002E */  beqz      $v0, .LE007E4F4
/* 37FB5C E007E43C 2610004C */   addiu    $s0, $s0, 0x4c
/* 37FB60 E007E440 8E220008 */  lw        $v0, 8($s1)
/* 37FB64 E007E444 24040001 */  addiu     $a0, $zero, 1
/* 37FB68 E007E448 0082102A */  slt       $v0, $a0, $v0
/* 37FB6C E007E44C 10400029 */  beqz      $v0, .LE007E4F4
/* 37FB70 E007E450 00000000 */   nop
/* 37FB74 E007E454 24060004 */  addiu     $a2, $zero, 4
/* 37FB78 E007E458 3C014348 */  lui       $at, 0x4348
/* 37FB7C E007E45C 44814000 */  mtc1      $at, $f8
/* 37FB80 E007E460 26030010 */  addiu     $v1, $s0, 0x10
.LE007E464:
/* 37FB84 E007E464 8C620038 */  lw        $v0, 0x38($v1)
/* 37FB88 E007E468 18400003 */  blez      $v0, .LE007E478
/* 37FB8C E007E46C 2442FFFF */   addiu    $v0, $v0, -1
/* 37FB90 E007E470 1C40001B */  bgtz      $v0, .LE007E4E0
/* 37FB94 E007E474 AC620038 */   sw       $v0, 0x38($v1)
.LE007E478:
/* 37FB98 E007E478 C4620008 */  lwc1      $f2, 8($v1)
/* 37FB9C E007E47C C4600010 */  lwc1      $f0, 0x10($v1)
/* 37FBA0 E007E480 C466FFF8 */  lwc1      $f6, -8($v1)
/* 37FBA4 E007E484 46001080 */  add.s     $f2, $f2, $f0
/* 37FBA8 E007E488 C4600004 */  lwc1      $f0, 4($v1)
/* 37FBAC E007E48C C4640000 */  lwc1      $f4, ($v1)
/* 37FBB0 E007E490 46003180 */  add.s     $f6, $f6, $f0
/* 37FBB4 E007E494 C460000C */  lwc1      $f0, 0xc($v1)
/* 37FBB8 E007E498 46002100 */  add.s     $f4, $f4, $f0
/* 37FBBC E007E49C E4620008 */  swc1      $f2, 8($v1)
/* 37FBC0 E007E4A0 C462FFFC */  lwc1      $f2, -4($v1)
/* 37FBC4 E007E4A4 C4600008 */  lwc1      $f0, 8($v1)
/* 37FBC8 E007E4A8 46001080 */  add.s     $f2, $f2, $f0
/* 37FBCC E007E4AC E466FFF8 */  swc1      $f6, -8($v1)
/* 37FBD0 E007E4B0 E4640000 */  swc1      $f4, ($v1)
/* 37FBD4 E007E4B4 14A6000A */  bne       $a1, $a2, .LE007E4E0
/* 37FBD8 E007E4B8 E462FFFC */   swc1     $f2, -4($v1)
/* 37FBDC E007E4BC 46003006 */  mov.s     $f0, $f6
/* 37FBE0 E007E4C0 4600403C */  c.lt.s    $f8, $f0
/* 37FBE4 E007E4C4 00000000 */  nop
/* 37FBE8 E007E4C8 45020006 */  bc1fl     .LE007E4E4
/* 37FBEC E007E4CC 24840001 */   addiu    $a0, $a0, 1
/* 37FBF0 E007E4D0 AC60FFF8 */  sw        $zero, -8($v1)
/* 37FBF4 E007E4D4 AC60FFFC */  sw        $zero, -4($v1)
/* 37FBF8 E007E4D8 AC600008 */  sw        $zero, 8($v1)
/* 37FBFC E007E4DC AC600000 */  sw        $zero, ($v1)
.LE007E4E0:
/* 37FC00 E007E4E0 24840001 */  addiu     $a0, $a0, 1
.LE007E4E4:
/* 37FC04 E007E4E4 8E220008 */  lw        $v0, 8($s1)
/* 37FC08 E007E4E8 0082102A */  slt       $v0, $a0, $v0
/* 37FC0C E007E4EC 1440FFDD */  bnez      $v0, .LE007E464
/* 37FC10 E007E4F0 2463004C */   addiu    $v1, $v1, 0x4c
.LE007E4F4:
/* 37FC14 E007E4F4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 37FC18 E007E4F8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 37FC1C E007E4FC 8FB00018 */  lw        $s0, 0x18($sp)
/* 37FC20 E007E500 03E00008 */  jr        $ra
/* 37FC24 E007E504 27BD0028 */   addiu    $sp, $sp, 0x28
