.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0068234
/* 36AB04 E0068234 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 36AB08 E0068238 3C07DB06 */  lui       $a3, 0xdb06
/* 36AB0C E006823C AFB10064 */  sw        $s1, 0x64($sp)
/* 36AB10 E0068240 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 36AB14 E0068244 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 36AB18 E0068248 34E70024 */  ori       $a3, $a3, 0x24
/* 36AB1C E006824C AFB3006C */  sw        $s3, 0x6c($sp)
/* 36AB20 E0068250 3C130001 */  lui       $s3, 1
/* 36AB24 E0068254 AFBF0080 */  sw        $ra, 0x80($sp)
/* 36AB28 E0068258 AFB7007C */  sw        $s7, 0x7c($sp)
/* 36AB2C E006825C AFB60078 */  sw        $s6, 0x78($sp)
/* 36AB30 E0068260 AFB50074 */  sw        $s5, 0x74($sp)
/* 36AB34 E0068264 AFB40070 */  sw        $s4, 0x70($sp)
/* 36AB38 E0068268 AFB20068 */  sw        $s2, 0x68($sp)
/* 36AB3C E006826C AFB00060 */  sw        $s0, 0x60($sp)
/* 36AB40 E0068270 8E260000 */  lw        $a2, ($s1)
/* 36AB44 E0068274 8C94000C */  lw        $s4, 0xc($a0)
/* 36AB48 E0068278 44800000 */  mtc1      $zero, $f0
/* 36AB4C E006827C 00C0182D */  daddu     $v1, $a2, $zero
/* 36AB50 E0068280 24C60008 */  addiu     $a2, $a2, 8
/* 36AB54 E0068284 8E820000 */  lw        $v0, ($s4)
/* 36AB58 E0068288 44050000 */  mfc1      $a1, $f0
/* 36AB5C E006828C 8E960020 */  lw        $s6, 0x20($s4)
/* 36AB60 E0068290 00021080 */  sll       $v0, $v0, 2
/* 36AB64 E0068294 3C15E007 */  lui       $s5, %hi(D_E00685B0)
/* 36AB68 E0068298 02A2A821 */  addu      $s5, $s5, $v0
/* 36AB6C E006829C 8EB585B0 */  lw        $s5, %lo(D_E00685B0)($s5)
/* 36AB70 E00682A0 3C17E007 */  lui       $s7, %hi(D_E00685F4)
/* 36AB74 E00682A4 02E2B821 */  addu      $s7, $s7, $v0
/* 36AB78 E00682A8 8EF785F4 */  lw        $s7, %lo(D_E00685F4)($s7)
/* 36AB7C E00682AC 3C02E700 */  lui       $v0, 0xe700
/* 36AB80 E00682B0 AC620000 */  sw        $v0, ($v1)
/* 36AB84 E00682B4 AC600004 */  sw        $zero, 4($v1)
/* 36AB88 E00682B8 ACC70000 */  sw        $a3, ($a2)
/* 36AB8C E00682BC 8C820010 */  lw        $v0, 0x10($a0)
/* 36AB90 E00682C0 3C048000 */  lui       $a0, 0x8000
/* 36AB94 E00682C4 8C42001C */  lw        $v0, 0x1c($v0)
/* 36AB98 E00682C8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 36AB9C E00682CC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 36ABA0 E00682D0 00441021 */  addu      $v0, $v0, $a0
/* 36ABA4 E00682D4 ACC20004 */  sw        $v0, 4($a2)
/* 36ABA8 E00682D8 00031080 */  sll       $v0, $v1, 2
/* 36ABAC E00682DC 00431021 */  addu      $v0, $v0, $v1
/* 36ABB0 E00682E0 00021080 */  sll       $v0, $v0, 2
/* 36ABB4 E00682E4 00431023 */  subu      $v0, $v0, $v1
/* 36ABB8 E00682E8 000218C0 */  sll       $v1, $v0, 3
/* 36ABBC E00682EC 00431021 */  addu      $v0, $v0, $v1
/* 36ABC0 E00682F0 000210C0 */  sll       $v0, $v0, 3
/* 36ABC4 E00682F4 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 36ABC8 E00682F8 00220821 */  addu      $at, $at, $v0
/* 36ABCC E00682FC C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* 36ABD0 E0068300 C6800010 */  lwc1      $f0, 0x10($s4)
/* 36ABD4 E0068304 36731630 */  ori       $s3, $s3, 0x1630
/* 36ABD8 E0068308 E7A00010 */  swc1      $f0, 0x10($sp)
/* 36ABDC E006830C C6800004 */  lwc1      $f0, 4($s4)
/* 36ABE0 E0068310 00A0382D */  daddu     $a3, $a1, $zero
/* 36ABE4 E0068314 E7A00014 */  swc1      $f0, 0x14($sp)
/* 36ABE8 E0068318 C6800008 */  lwc1      $f0, 8($s4)
/* 36ABEC E006831C 46001087 */  neg.s     $f2, $f2
/* 36ABF0 E0068320 AE260000 */  sw        $a2, ($s1)
/* 36ABF4 E0068324 E7A00018 */  swc1      $f0, 0x18($sp)
/* 36ABF8 E0068328 C680000C */  lwc1      $f0, 0xc($s4)
/* 36ABFC E006832C 24C60008 */  addiu     $a2, $a2, 8
/* 36AC00 E0068330 AE260000 */  sw        $a2, ($s1)
/* 36AC04 E0068334 44061000 */  mfc1      $a2, $f2
/* 36AC08 E0068338 27A40020 */  addiu     $a0, $sp, 0x20
/* 36AC0C E006833C 0C080180 */  jal       shim_guPositionF
/* 36AC10 E0068340 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 36AC14 E0068344 27A40020 */  addiu     $a0, $sp, 0x20
/* 36AC18 E0068348 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 36AC1C E006834C 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 36AC20 E0068350 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 36AC24 E0068354 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 36AC28 E0068358 96050000 */  lhu       $a1, ($s0)
/* 36AC2C E006835C 8E420000 */  lw        $v0, ($s2)
/* 36AC30 E0068360 00052980 */  sll       $a1, $a1, 6
/* 36AC34 E0068364 00B32821 */  addu      $a1, $a1, $s3
/* 36AC38 E0068368 0C080118 */  jal       shim_guMtxF2L
/* 36AC3C E006836C 00452821 */   addu     $a1, $v0, $a1
/* 36AC40 E0068370 8E220000 */  lw        $v0, ($s1)
/* 36AC44 E0068374 0040202D */  daddu     $a0, $v0, $zero
/* 36AC48 E0068378 24420008 */  addiu     $v0, $v0, 8
/* 36AC4C E006837C AE220000 */  sw        $v0, ($s1)
/* 36AC50 E0068380 96020000 */  lhu       $v0, ($s0)
/* 36AC54 E0068384 3C03DA38 */  lui       $v1, 0xda38
/* 36AC58 E0068388 AC830000 */  sw        $v1, ($a0)
/* 36AC5C E006838C 24430001 */  addiu     $v1, $v0, 1
/* 36AC60 E0068390 3042FFFF */  andi      $v0, $v0, 0xffff
/* 36AC64 E0068394 00021180 */  sll       $v0, $v0, 6
/* 36AC68 E0068398 A6030000 */  sh        $v1, ($s0)
/* 36AC6C E006839C 8E430000 */  lw        $v1, ($s2)
/* 36AC70 E00683A0 00531021 */  addu      $v0, $v0, $s3
/* 36AC74 E00683A4 00621821 */  addu      $v1, $v1, $v0
/* 36AC78 E00683A8 AC830004 */  sw        $v1, 4($a0)
/* 36AC7C E00683AC C6820018 */  lwc1      $f2, 0x18($s4)
/* 36AC80 E00683B0 468010A1 */  cvt.d.w   $f2, $f2
/* 36AC84 E00683B4 32C20001 */  andi      $v0, $s6, 1
/* 36AC88 E00683B8 14400009 */  bnez      $v0, .LE00683E0
/* 36AC8C E00683BC 3C031A79 */   lui      $v1, 0x1a79
/* 36AC90 E00683C0 3C01E007 */  lui       $at, %hi(D_E0068600)
/* 36AC94 E00683C4 D4208600 */  ldc1      $f0, %lo(D_E0068600)($at)
/* 36AC98 E00683C8 46201002 */  mul.d     $f0, $f2, $f0
/* 36AC9C E00683CC 00000000 */  nop
/* 36ACA0 E00683D0 4620010D */  trunc.w.d $f4, $f0
/* 36ACA4 E00683D4 44092000 */  mfc1      $t1, $f4
/* 36ACA8 E00683D8 0801A0FB */  j         .LE00683EC
/* 36ACAC E00683DC 34631D9E */   ori      $v1, $v1, 0x1d9e
.LE00683E0:
/* 36ACB0 E00683E0 4620110D */  trunc.w.d $f4, $f2
/* 36ACB4 E00683E4 44092000 */  mfc1      $t1, $f4
/* 36ACB8 E00683E8 34631D9E */  ori       $v1, $v1, 0x1d9e
.LE00683EC:
/* 36ACBC E00683EC 3C0AE300 */  lui       $t2, 0xe300
/* 36ACC0 E00683F0 354A1801 */  ori       $t2, $t2, 0x1801
/* 36ACC4 E00683F4 3C0BE300 */  lui       $t3, 0xe300
/* 36ACC8 E00683F8 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 36ACCC E00683FC 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 36ACD0 E0068400 356B1A01 */  ori       $t3, $t3, 0x1a01
/* 36ACD4 E0068404 3C06FB00 */  lui       $a2, 0xfb00
/* 36ACD8 E0068408 240D0040 */  addiu     $t5, $zero, 0x40
/* 36ACDC E006840C 8D070000 */  lw        $a3, ($t0)
/* 36ACE0 E0068410 3C0CDE00 */  lui       $t4, 0xde00
/* 36ACE4 E0068414 00E0102D */  daddu     $v0, $a3, $zero
/* 36ACE8 E0068418 24E70008 */  addiu     $a3, $a3, 8
/* 36ACEC E006841C AD070000 */  sw        $a3, ($t0)
/* 36ACF0 E0068420 AC460000 */  sw        $a2, ($v0)
/* 36ACF4 E0068424 AC430004 */  sw        $v1, 4($v0)
/* 36ACF8 E0068428 24E20008 */  addiu     $v0, $a3, 8
/* 36ACFC E006842C AD020000 */  sw        $v0, ($t0)
/* 36AD00 E0068430 24E20010 */  addiu     $v0, $a3, 0x10
/* 36AD04 E0068434 ACEA0000 */  sw        $t2, ($a3)
/* 36AD08 E0068438 ACED0004 */  sw        $t5, 4($a3)
/* 36AD0C E006843C AD020000 */  sw        $v0, ($t0)
/* 36AD10 E0068440 24E20018 */  addiu     $v0, $a3, 0x18
/* 36AD14 E0068444 ACEB0008 */  sw        $t3, 8($a3)
/* 36AD18 E0068448 ACE0000C */  sw        $zero, 0xc($a3)
/* 36AD1C E006844C AD020000 */  sw        $v0, ($t0)
/* 36AD20 E0068450 24E20020 */  addiu     $v0, $a3, 0x20
/* 36AD24 E0068454 ACEC0010 */  sw        $t4, 0x10($a3)
/* 36AD28 E0068458 ACF70014 */  sw        $s7, 0x14($a3)
/* 36AD2C E006845C AD020000 */  sw        $v0, ($t0)
/* 36AD30 E0068460 3C02FA00 */  lui       $v0, 0xfa00
/* 36AD34 E0068464 ACE20018 */  sw        $v0, 0x18($a3)
/* 36AD38 E0068468 92820024 */  lbu       $v0, 0x24($s4)
/* 36AD3C E006846C 92840025 */  lbu       $a0, 0x25($s4)
/* 36AD40 E0068470 92850026 */  lbu       $a1, 0x26($s4)
/* 36AD44 E0068474 24E30028 */  addiu     $v1, $a3, 0x28
/* 36AD48 E0068478 AD030000 */  sw        $v1, ($t0)
/* 36AD4C E006847C 312300FF */  andi      $v1, $t1, 0xff
/* 36AD50 E0068480 ACE60020 */  sw        $a2, 0x20($a3)
/* 36AD54 E0068484 00021600 */  sll       $v0, $v0, 0x18
/* 36AD58 E0068488 00042400 */  sll       $a0, $a0, 0x10
/* 36AD5C E006848C 00441025 */  or        $v0, $v0, $a0
/* 36AD60 E0068490 00052A00 */  sll       $a1, $a1, 8
/* 36AD64 E0068494 00451025 */  or        $v0, $v0, $a1
/* 36AD68 E0068498 00431025 */  or        $v0, $v0, $v1
/* 36AD6C E006849C ACE2001C */  sw        $v0, 0x1c($a3)
/* 36AD70 E00684A0 92820027 */  lbu       $v0, 0x27($s4)
/* 36AD74 E00684A4 92840028 */  lbu       $a0, 0x28($s4)
/* 36AD78 E00684A8 92830029 */  lbu       $v1, 0x29($s4)
/* 36AD7C E00684AC 00021600 */  sll       $v0, $v0, 0x18
/* 36AD80 E00684B0 00042400 */  sll       $a0, $a0, 0x10
/* 36AD84 E00684B4 00441025 */  or        $v0, $v0, $a0
/* 36AD88 E00684B8 00031A00 */  sll       $v1, $v1, 8
/* 36AD8C E00684BC 00431025 */  or        $v0, $v0, $v1
/* 36AD90 E00684C0 ACE20024 */  sw        $v0, 0x24($a3)
/* 36AD94 E00684C4 3C020900 */  lui       $v0, 0x900
/* 36AD98 E00684C8 24421E40 */  addiu     $v0, $v0, 0x1e40
/* 36AD9C E00684CC 16A20010 */  bne       $s5, $v0, .LE0068510
/* 36ADA0 E00684D0 3C03D838 */   lui      $v1, 0xd838
/* 36ADA4 E00684D4 00161842 */  srl       $v1, $s6, 1
/* 36ADA8 E00684D8 3C029249 */  lui       $v0, 0x9249
/* 36ADAC E00684DC 34422493 */  ori       $v0, $v0, 0x2493
/* 36ADB0 E00684E0 00620019 */  multu     $v1, $v0
/* 36ADB4 E00684E4 00007010 */  mfhi      $t6
/* 36ADB8 E00684E8 000E1882 */  srl       $v1, $t6, 2
/* 36ADBC E00684EC 000310C0 */  sll       $v0, $v1, 3
/* 36ADC0 E00684F0 00431023 */  subu      $v0, $v0, $v1
/* 36ADC4 E00684F4 00021040 */  sll       $v0, $v0, 1
/* 36ADC8 E00684F8 02C21023 */  subu      $v0, $s6, $v0
/* 36ADCC E00684FC 00021080 */  sll       $v0, $v0, 2
/* 36ADD0 E0068500 3C15E007 */  lui       $s5, %hi(D_E00685BC)
/* 36ADD4 E0068504 02A2A821 */  addu      $s5, $s5, $v0
/* 36ADD8 E0068508 8EB585BC */  lw        $s5, %lo(D_E00685BC)($s5)
/* 36ADDC E006850C 3C03D838 */  lui       $v1, 0xd838
.LE0068510:
/* 36ADE0 E0068510 34630002 */  ori       $v1, $v1, 2
/* 36ADE4 E0068514 24E20030 */  addiu     $v0, $a3, 0x30
/* 36ADE8 E0068518 AD020000 */  sw        $v0, ($t0)
/* 36ADEC E006851C 24E20038 */  addiu     $v0, $a3, 0x38
/* 36ADF0 E0068520 ACEC0028 */  sw        $t4, 0x28($a3)
/* 36ADF4 E0068524 ACF5002C */  sw        $s5, 0x2c($a3)
/* 36ADF8 E0068528 AD020000 */  sw        $v0, ($t0)
/* 36ADFC E006852C 24E20040 */  addiu     $v0, $a3, 0x40
/* 36AE00 E0068530 ACE30030 */  sw        $v1, 0x30($a3)
/* 36AE04 E0068534 3C03E700 */  lui       $v1, 0xe700
/* 36AE08 E0068538 ACED0034 */  sw        $t5, 0x34($a3)
/* 36AE0C E006853C AD020000 */  sw        $v0, ($t0)
/* 36AE10 E0068540 24E20048 */  addiu     $v0, $a3, 0x48
/* 36AE14 E0068544 ACE30038 */  sw        $v1, 0x38($a3)
/* 36AE18 E0068548 ACE0003C */  sw        $zero, 0x3c($a3)
/* 36AE1C E006854C AD020000 */  sw        $v0, ($t0)
/* 36AE20 E0068550 240200C0 */  addiu     $v0, $zero, 0xc0
/* 36AE24 E0068554 ACE20044 */  sw        $v0, 0x44($a3)
/* 36AE28 E0068558 24E20050 */  addiu     $v0, $a3, 0x50
/* 36AE2C E006855C ACEA0040 */  sw        $t2, 0x40($a3)
/* 36AE30 E0068560 AD020000 */  sw        $v0, ($t0)
/* 36AE34 E0068564 24020030 */  addiu     $v0, $zero, 0x30
/* 36AE38 E0068568 ACE2004C */  sw        $v0, 0x4c($a3)
/* 36AE3C E006856C 24E20058 */  addiu     $v0, $a3, 0x58
/* 36AE40 E0068570 ACEB0048 */  sw        $t3, 0x48($a3)
/* 36AE44 E0068574 AD020000 */  sw        $v0, ($t0)
/* 36AE48 E0068578 ACE30050 */  sw        $v1, 0x50($a3)
/* 36AE4C E006857C ACE00054 */  sw        $zero, 0x54($a3)
/* 36AE50 E0068580 8FBF0080 */  lw        $ra, 0x80($sp)
/* 36AE54 E0068584 8FB7007C */  lw        $s7, 0x7c($sp)
/* 36AE58 E0068588 8FB60078 */  lw        $s6, 0x78($sp)
/* 36AE5C E006858C 8FB50074 */  lw        $s5, 0x74($sp)
/* 36AE60 E0068590 8FB40070 */  lw        $s4, 0x70($sp)
/* 36AE64 E0068594 8FB3006C */  lw        $s3, 0x6c($sp)
/* 36AE68 E0068598 8FB20068 */  lw        $s2, 0x68($sp)
/* 36AE6C E006859C 8FB10064 */  lw        $s1, 0x64($sp)
/* 36AE70 E00685A0 8FB00060 */  lw        $s0, 0x60($sp)
/* 36AE74 E00685A4 03E00008 */  jr        $ra
/* 36AE78 E00685A8 27BD0088 */   addiu    $sp, $sp, 0x88
/* 36AE7C E00685AC 00000000 */  nop
