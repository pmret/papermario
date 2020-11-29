.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024EFE0
/* 17D8C0 8024EFE0 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 17D8C4 8024EFE4 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 17D8C8 8024EFE8 4486E000 */  mtc1      $a2, $f28
/* 17D8CC 8024EFEC F7B60048 */  sdc1      $f22, 0x48($sp)
/* 17D8D0 8024EFF0 3C013F80 */  lui       $at, 0x3f80
/* 17D8D4 8024EFF4 4481B000 */  mtc1      $at, $f22
/* 17D8D8 8024EFF8 AFB20020 */  sw        $s2, 0x20($sp)
/* 17D8DC 8024EFFC 8FB2007C */  lw        $s2, 0x7c($sp)
/* 17D8E0 8024F000 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 17D8E4 8024F004 46006606 */  mov.s     $f24, $f12
/* 17D8E8 8024F008 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 17D8EC 8024F00C 46007686 */  mov.s     $f26, $f14
/* 17D8F0 8024F010 AFB5002C */  sw        $s5, 0x2c($sp)
/* 17D8F4 8024F014 00E0A82D */  daddu     $s5, $a3, $zero
/* 17D8F8 8024F018 AFB70034 */  sw        $s7, 0x34($sp)
/* 17D8FC 8024F01C 0000B82D */  daddu     $s7, $zero, $zero
/* 17D900 8024F020 AFB1001C */  sw        $s1, 0x1c($sp)
/* 17D904 8024F024 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 17D908 8024F028 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 17D90C 8024F02C AFBF003C */  sw        $ra, 0x3c($sp)
/* 17D910 8024F030 AFBE0038 */  sw        $fp, 0x38($sp)
/* 17D914 8024F034 AFB60030 */  sw        $s6, 0x30($sp)
/* 17D918 8024F038 AFB40028 */  sw        $s4, 0x28($sp)
/* 17D91C 8024F03C AFB30024 */  sw        $s3, 0x24($sp)
/* 17D920 8024F040 AFB00018 */  sw        $s0, 0x18($sp)
/* 17D924 8024F044 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 17D928 8024F048 1EA00009 */  bgtz      $s5, .L8024F070
/* 17D92C 8024F04C 4600B506 */   mov.s    $f20, $f22
/* 17D930 8024F050 24150001 */  addiu     $s5, $zero, 1
/* 17D934 8024F054 02A0B82D */  daddu     $s7, $s5, $zero
/* 17D938 8024F058 3C013ECC */  lui       $at, 0x3ecc
/* 17D93C 8024F05C 3421CCCD */  ori       $at, $at, 0xcccd
/* 17D940 8024F060 4481B000 */  mtc1      $at, $f22
/* 17D944 8024F064 3C013F33 */  lui       $at, 0x3f33
/* 17D948 8024F068 34213333 */  ori       $at, $at, 0x3333
/* 17D94C 8024F06C 4481A000 */  mtc1      $at, $f20
.L8024F070:
/* 17D950 8024F070 8E220000 */  lw        $v0, ($s1)
/* 17D954 8024F074 30420240 */  andi      $v0, $v0, 0x240
/* 17D958 8024F078 10400004 */  beqz      $v0, .L8024F08C
/* 17D95C 8024F07C 00000000 */   nop      
/* 17D960 8024F080 4600B021 */  cvt.d.s   $f0, $f22
/* 17D964 8024F084 46200000 */  add.d     $f0, $f0, $f0
/* 17D968 8024F088 462005A0 */  cvt.s.d   $f22, $f0
.L8024F08C:
/* 17D96C 8024F08C 0C093BDA */  jal       create_popup
/* 17D970 8024F090 00000000 */   nop      
/* 17D974 8024F094 0040802D */  daddu     $s0, $v0, $zero
/* 17D978 8024F098 120000AD */  beqz      $s0, .L8024F350
/* 17D97C 8024F09C 00000000 */   nop      
/* 17D980 8024F0A0 06410003 */  bgez      $s2, .L8024F0B0
/* 17D984 8024F0A4 24140001 */   addiu    $s4, $zero, 1
/* 17D988 8024F0A8 00129023 */  negu      $s2, $s2
/* 17D98C 8024F0AC 2414FFFF */  addiu     $s4, $zero, -1
.L8024F0B0:
/* 17D990 8024F0B0 2A420006 */  slti      $v0, $s2, 6
/* 17D994 8024F0B4 14400003 */  bnez      $v0, .L8024F0C4
/* 17D998 8024F0B8 00152080 */   sll      $a0, $s5, 2
/* 17D99C 8024F0BC 08093C2C */  j         .L8024F0B0
/* 17D9A0 8024F0C0 2652FFFB */   addiu    $s2, $s2, -5
.L8024F0C4:
/* 17D9A4 8024F0C4 00952021 */  addu      $a0, $a0, $s5
/* 17D9A8 8024F0C8 00042080 */  sll       $a0, $a0, 2
/* 17D9AC 8024F0CC 00952023 */  subu      $a0, $a0, $s5
/* 17D9B0 8024F0D0 00042080 */  sll       $a0, $a0, 2
/* 17D9B4 8024F0D4 3C028025 */  lui       $v0, %hi(D_8024F394)
/* 17D9B8 8024F0D8 2442F394 */  addiu     $v0, $v0, %lo(D_8024F394)
/* 17D9BC 8024F0DC A6200090 */  sh        $zero, 0x90($s1)
/* 17D9C0 8024F0E0 AE020004 */  sw        $v0, 4($s0)
/* 17D9C4 8024F0E4 3C028025 */  lui       $v0, %hi(D_8024F5AC)
/* 17D9C8 8024F0E8 2442F5AC */  addiu     $v0, $v0, %lo(D_8024F5AC)
/* 17D9CC 8024F0EC AE020008 */  sw        $v0, 8($s0)
/* 17D9D0 8024F0F0 96020010 */  lhu       $v0, 0x10($s0)
/* 17D9D4 8024F0F4 24030001 */  addiu     $v1, $zero, 1
/* 17D9D8 8024F0F8 AE000000 */  sw        $zero, ($s0)
/* 17D9DC 8024F0FC AE00000C */  sw        $zero, 0xc($s0)
/* 17D9E0 8024F100 A6030012 */  sh        $v1, 0x12($s0)
/* 17D9E4 8024F104 34420010 */  ori       $v0, $v0, 0x10
/* 17D9E8 8024F108 0C00AB39 */  jal       heap_malloc
/* 17D9EC 8024F10C A6020010 */   sh       $v0, 0x10($s0)
/* 17D9F0 8024F110 0040982D */  daddu     $s3, $v0, $zero
/* 17D9F4 8024F114 16600003 */  bnez      $s3, .L8024F124
/* 17D9F8 8024F118 AE130018 */   sw       $s3, 0x18($s0)
.L8024F11C:
/* 17D9FC 8024F11C 08093C47 */  j         .L8024F11C
/* 17DA00 8024F120 00000000 */   nop      
.L8024F124:
/* 17DA04 8024F124 1AA0008A */  blez      $s5, .L8024F350
/* 17DA08 8024F128 0000882D */   daddu    $s1, $zero, $zero
/* 17DA0C 8024F12C 3C038028 */  lui       $v1, %hi(D_80283744)
/* 17DA10 8024F130 24633744 */  addiu     $v1, $v1, %lo(D_80283744)
/* 17DA14 8024F134 00151080 */  sll       $v0, $s5, 2
/* 17DA18 8024F138 00431021 */  addu      $v0, $v0, $v1
/* 17DA1C 8024F13C AFA20010 */  sw        $v0, 0x10($sp)
/* 17DA20 8024F140 3C168028 */  lui       $s6, %hi(D_802835DC)
/* 17DA24 8024F144 26D635DC */  addiu     $s6, $s6, %lo(D_802835DC)
/* 17DA28 8024F148 001410C0 */  sll       $v0, $s4, 3
/* 17DA2C 8024F14C 00541023 */  subu      $v0, $v0, $s4
/* 17DA30 8024F150 00021080 */  sll       $v0, $v0, 2
/* 17DA34 8024F154 00541023 */  subu      $v0, $v0, $s4
/* 17DA38 8024F158 00021080 */  sll       $v0, $v0, 2
/* 17DA3C 8024F15C 0054F023 */  subu      $fp, $v0, $s4
/* 17DA40 8024F160 26700048 */  addiu     $s0, $s3, 0x48
.L8024F164:
/* 17DA44 8024F164 24020001 */  addiu     $v0, $zero, 1
/* 17DA48 8024F168 AE620000 */  sw        $v0, ($s3)
/* 17DA4C 8024F16C 8FA80010 */  lw        $t0, 0x10($sp)
/* 17DA50 8024F170 0C048338 */  jal       load_virtual_model
/* 17DA54 8024F174 8D040000 */   lw       $a0, ($t0)
/* 17DA58 8024F178 0040202D */  daddu     $a0, $v0, $zero
/* 17DA5C 8024F17C 24050020 */  addiu     $a1, $zero, 0x20
/* 17DA60 8024F180 0C048BBA */  jal       func_80122EE8
/* 17DA64 8024F184 AE04FFBC */   sw       $a0, -0x44($s0)
/* 17DA68 8024F188 8E04FFBC */  lw        $a0, -0x44($s0)
/* 17DA6C 8024F18C 3C068025 */  lui       $a2, %hi(D_8024F768)
/* 17DA70 8024F190 24C6F768 */  addiu     $a2, $a2, %lo(D_8024F768)
/* 17DA74 8024F194 0C048BD9 */  jal       func_80122F64
/* 17DA78 8024F198 0260282D */   daddu    $a1, $s3, $zero
/* 17DA7C 8024F19C 0240102D */  daddu     $v0, $s2, $zero
/* 17DA80 8024F1A0 E618FFF0 */  swc1      $f24, -0x10($s0)
/* 17DA84 8024F1A4 E61AFFF4 */  swc1      $f26, -0xc($s0)
/* 17DA88 8024F1A8 06410002 */  bgez      $s2, .L8024F1B4
/* 17DA8C 8024F1AC E61CFFF8 */   swc1     $f28, -8($s0)
/* 17DA90 8024F1B0 26420007 */  addiu     $v0, $s2, 7
.L8024F1B4:
/* 17DA94 8024F1B4 000218C3 */  sra       $v1, $v0, 3
/* 17DA98 8024F1B8 000310C0 */  sll       $v0, $v1, 3
/* 17DA9C 8024F1BC 02421823 */  subu      $v1, $s2, $v0
/* 17DAA0 8024F1C0 00031040 */  sll       $v0, $v1, 1
/* 17DAA4 8024F1C4 00431021 */  addu      $v0, $v0, $v1
/* 17DAA8 8024F1C8 00022080 */  sll       $a0, $v0, 2
/* 17DAAC 8024F1CC 00962021 */  addu      $a0, $a0, $s6
/* 17DAB0 8024F1D0 C4800000 */  lwc1      $f0, ($a0)
/* 17DAB4 8024F1D4 46000021 */  cvt.d.s   $f0, $f0
/* 17DAB8 8024F1D8 46200000 */  add.d     $f0, $f0, $f0
/* 17DABC 8024F1DC 44941000 */  mtc1      $s4, $f2
/* 17DAC0 8024F1E0 00000000 */  nop       
/* 17DAC4 8024F1E4 468010A1 */  cvt.d.w   $f2, $f2
/* 17DAC8 8024F1E8 46220002 */  mul.d     $f0, $f0, $f2
/* 17DACC 8024F1EC 00000000 */  nop       
/* 17DAD0 8024F1F0 4600A0A1 */  cvt.d.s   $f2, $f20
/* 17DAD4 8024F1F4 46220002 */  mul.d     $f0, $f0, $f2
/* 17DAD8 8024F1F8 00000000 */  nop       
/* 17DADC 8024F1FC 24430001 */  addiu     $v1, $v0, 1
/* 17DAE0 8024F200 00031880 */  sll       $v1, $v1, 2
/* 17DAE4 8024F204 00761821 */  addu      $v1, $v1, $s6
/* 17DAE8 8024F208 46200020 */  cvt.s.d   $f0, $f0
/* 17DAEC 8024F20C E600FFCC */  swc1      $f0, -0x34($s0)
/* 17DAF0 8024F210 C4600000 */  lwc1      $f0, ($v1)
/* 17DAF4 8024F214 46000021 */  cvt.d.s   $f0, $f0
/* 17DAF8 8024F218 46200000 */  add.d     $f0, $f0, $f0
/* 17DAFC 8024F21C 46220002 */  mul.d     $f0, $f0, $f2
/* 17DB00 8024F220 00000000 */  nop       
/* 17DB04 8024F224 24420002 */  addiu     $v0, $v0, 2
/* 17DB08 8024F228 00021080 */  sll       $v0, $v0, 2
/* 17DB0C 8024F22C 00561021 */  addu      $v0, $v0, $s6
/* 17DB10 8024F230 46200020 */  cvt.s.d   $f0, $f0
/* 17DB14 8024F234 E600FFD0 */  swc1      $f0, -0x30($s0)
/* 17DB18 8024F238 C4400000 */  lwc1      $f0, ($v0)
/* 17DB1C 8024F23C 46000021 */  cvt.d.s   $f0, $f0
/* 17DB20 8024F240 46200000 */  add.d     $f0, $f0, $f0
/* 17DB24 8024F244 46220002 */  mul.d     $f0, $f0, $f2
/* 17DB28 8024F248 00000000 */  nop       
/* 17DB2C 8024F24C 46200020 */  cvt.s.d   $f0, $f0
/* 17DB30 8024F250 E600FFD4 */  swc1      $f0, -0x2c($s0)
/* 17DB34 8024F254 C4800000 */  lwc1      $f0, ($a0)
/* 17DB38 8024F258 44941000 */  mtc1      $s4, $f2
/* 17DB3C 8024F25C 00000000 */  nop       
/* 17DB40 8024F260 468010A0 */  cvt.s.w   $f2, $f2
/* 17DB44 8024F264 46020002 */  mul.s     $f0, $f0, $f2
/* 17DB48 8024F268 00000000 */  nop       
/* 17DB4C 8024F26C 46140002 */  mul.s     $f0, $f0, $f20
/* 17DB50 8024F270 00000000 */  nop       
/* 17DB54 8024F274 E600FFC0 */  swc1      $f0, -0x40($s0)
/* 17DB58 8024F278 C4600000 */  lwc1      $f0, ($v1)
/* 17DB5C 8024F27C 46140002 */  mul.s     $f0, $f0, $f20
/* 17DB60 8024F280 00000000 */  nop       
/* 17DB64 8024F284 E600FFC4 */  swc1      $f0, -0x3c($s0)
/* 17DB68 8024F288 C4400000 */  lwc1      $f0, ($v0)
/* 17DB6C 8024F28C 46140002 */  mul.s     $f0, $f0, $f20
/* 17DB70 8024F290 00000000 */  nop       
/* 17DB74 8024F294 26520001 */  addiu     $s2, $s2, 1
/* 17DB78 8024F298 0220102D */  daddu     $v0, $s1, $zero
/* 17DB7C 8024F29C 06210002 */  bgez      $s1, .L8024F2A8
/* 17DB80 8024F2A0 E600FFC8 */   swc1     $f0, -0x38($s0)
/* 17DB84 8024F2A4 26220007 */  addiu     $v0, $s1, 7
.L8024F2A8:
/* 17DB88 8024F2A8 000218C3 */  sra       $v1, $v0, 3
/* 17DB8C 8024F2AC 000310C0 */  sll       $v0, $v1, 3
/* 17DB90 8024F2B0 02221823 */  subu      $v1, $s1, $v0
/* 17DB94 8024F2B4 00031040 */  sll       $v0, $v1, 1
/* 17DB98 8024F2B8 00431021 */  addu      $v0, $v0, $v1
/* 17DB9C 8024F2BC 00021080 */  sll       $v0, $v0, 2
/* 17DBA0 8024F2C0 3C088028 */  lui       $t0, %hi(D_80283690)
/* 17DBA4 8024F2C4 25083690 */  addiu     $t0, $t0, %lo(D_80283690)
/* 17DBA8 8024F2C8 00481021 */  addu      $v0, $v0, $t0
/* 17DBAC 8024F2CC C4420000 */  lwc1      $f2, ($v0)
/* 17DBB0 8024F2D0 46161082 */  mul.s     $f2, $f2, $f22
/* 17DBB4 8024F2D4 00000000 */  nop       
/* 17DBB8 8024F2D8 3C014334 */  lui       $at, 0x4334
/* 17DBBC 8024F2DC 44816000 */  mtc1      $at, $f12
/* 17DBC0 8024F2E0 449E0000 */  mtc1      $fp, $f0
/* 17DBC4 8024F2E4 00000000 */  nop       
/* 17DBC8 8024F2E8 46800020 */  cvt.s.w   $f0, $f0
/* 17DBCC 8024F2EC AE00FFE0 */  sw        $zero, -0x20($s0)
/* 17DBD0 8024F2F0 E600FFE4 */  swc1      $f0, -0x1c($s0)
/* 17DBD4 8024F2F4 E602FFEC */  swc1      $f2, -0x14($s0)
/* 17DBD8 8024F2F8 3C01800B */  lui       $at, %hi(D_800B2344)
/* 17DBDC 8024F2FC C4202344 */  lwc1      $f0, %lo(D_800B2344)($at)
/* 17DBE0 8024F300 0C00A6C9 */  jal       clamp_angle
/* 17DBE4 8024F304 46006301 */   sub.s    $f12, $f12, $f0
/* 17DBE8 8024F308 2402000E */  addiu     $v0, $zero, 0xe
/* 17DBEC 8024F30C E600FFE8 */  swc1      $f0, -0x18($s0)
/* 17DBF0 8024F310 AE02FFD8 */  sw        $v0, -0x28($s0)
/* 17DBF4 8024F314 8FA80078 */  lw        $t0, 0x78($sp)
/* 17DBF8 8024F318 240200F0 */  addiu     $v0, $zero, 0xf0
/* 17DBFC 8024F31C AE02FFFC */  sw        $v0, -4($s0)
/* 17DC00 8024F320 12E00003 */  beqz      $s7, .L8024F330
/* 17DC04 8024F324 AE08FFDC */   sw       $t0, -0x24($s0)
/* 17DC08 8024F328 2402000A */  addiu     $v0, $zero, 0xa
/* 17DC0C 8024F32C AE02FFFC */  sw        $v0, -4($s0)
.L8024F330:
/* 17DC10 8024F330 26310001 */  addiu     $s1, $s1, 1
/* 17DC14 8024F334 2673004C */  addiu     $s3, $s3, 0x4c
/* 17DC18 8024F338 3C01437F */  lui       $at, 0x437f
/* 17DC1C 8024F33C 44810000 */  mtc1      $at, $f0
/* 17DC20 8024F340 0235102A */  slt       $v0, $s1, $s5
/* 17DC24 8024F344 E6000000 */  swc1      $f0, ($s0)
/* 17DC28 8024F348 1440FF86 */  bnez      $v0, .L8024F164
/* 17DC2C 8024F34C 2610004C */   addiu    $s0, $s0, 0x4c
.L8024F350:
/* 17DC30 8024F350 8FBF003C */  lw        $ra, 0x3c($sp)
/* 17DC34 8024F354 8FBE0038 */  lw        $fp, 0x38($sp)
/* 17DC38 8024F358 8FB70034 */  lw        $s7, 0x34($sp)
/* 17DC3C 8024F35C 8FB60030 */  lw        $s6, 0x30($sp)
/* 17DC40 8024F360 8FB5002C */  lw        $s5, 0x2c($sp)
/* 17DC44 8024F364 8FB40028 */  lw        $s4, 0x28($sp)
/* 17DC48 8024F368 8FB30024 */  lw        $s3, 0x24($sp)
/* 17DC4C 8024F36C 8FB20020 */  lw        $s2, 0x20($sp)
/* 17DC50 8024F370 8FB1001C */  lw        $s1, 0x1c($sp)
/* 17DC54 8024F374 8FB00018 */  lw        $s0, 0x18($sp)
/* 17DC58 8024F378 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 17DC5C 8024F37C D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 17DC60 8024F380 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 17DC64 8024F384 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 17DC68 8024F388 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 17DC6C 8024F38C 03E00008 */  jr        $ra
/* 17DC70 8024F390 27BD0068 */   addiu    $sp, $sp, 0x68
