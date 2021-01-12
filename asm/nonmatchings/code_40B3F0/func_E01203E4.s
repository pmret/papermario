.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E01203E4
/* 40B7D4 E01203E4 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 40B7D8 E01203E8 0080402D */  daddu     $t0, $a0, $zero
/* 40B7DC E01203EC AFBF00B8 */  sw        $ra, 0xb8($sp)
/* 40B7E0 E01203F0 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 40B7E4 E01203F4 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 40B7E8 E01203F8 AFB300AC */  sw        $s3, 0xac($sp)
/* 40B7EC E01203FC AFB200A8 */  sw        $s2, 0xa8($sp)
/* 40B7F0 E0120400 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 40B7F4 E0120404 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 40B7F8 E0120408 8D14000C */  lw        $s4, 0xc($t0)
/* 40B7FC E012040C 8E950038 */  lw        $s5, 0x38($s4)
/* 40B800 E0120410 8E870000 */  lw        $a3, ($s4)
/* 40B804 E0120414 12A000D1 */  beqz      $s5, .LE012075C
/* 40B808 E0120418 3C06DB06 */   lui      $a2, 0xdb06
/* 40B80C E012041C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 40B810 E0120420 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 40B814 E0120424 34C60024 */  ori       $a2, $a2, 0x24
/* 40B818 E0120428 8C640000 */  lw        $a0, ($v1)
/* 40B81C E012042C 3C02E700 */  lui       $v0, 0xe700
/* 40B820 E0120430 0080282D */  daddu     $a1, $a0, $zero
/* 40B824 E0120434 24840008 */  addiu     $a0, $a0, 8
/* 40B828 E0120438 AC640000 */  sw        $a0, ($v1)
/* 40B82C E012043C ACA20000 */  sw        $v0, ($a1)
/* 40B830 E0120440 ACA00004 */  sw        $zero, 4($a1)
/* 40B834 E0120444 AC860000 */  sw        $a2, ($a0)
/* 40B838 E0120448 8D050010 */  lw        $a1, 0x10($t0)
/* 40B83C E012044C 24820008 */  addiu     $v0, $a0, 8
/* 40B840 E0120450 AC620000 */  sw        $v0, ($v1)
/* 40B844 E0120454 8CA2001C */  lw        $v0, 0x1c($a1)
/* 40B848 E0120458 3C038000 */  lui       $v1, 0x8000
/* 40B84C E012045C 00431021 */  addu      $v0, $v0, $v1
/* 40B850 E0120460 14E00004 */  bnez      $a3, .LE0120474
/* 40B854 E0120464 AC820004 */   sw       $v0, 4($a0)
/* 40B858 E0120468 3C05C4C8 */  lui       $a1, 0xc4c8
/* 40B85C E012046C 0804811F */  j         .LE012047C
/* 40B860 E0120470 3C0644C8 */   lui      $a2, 0x44c8
.LE0120474:
/* 40B864 E0120474 3C0544C8 */  lui       $a1, 0x44c8
/* 40B868 E0120478 3C06C4C8 */  lui       $a2, 0xc4c8
.LE012047C:
/* 40B86C E012047C 3C07C496 */  lui       $a3, 0xc496
/* 40B870 E0120480 3C014496 */  lui       $at, 0x4496
/* 40B874 E0120484 44810000 */  mtc1      $at, $f0
/* 40B878 E0120488 3C01C2C8 */  lui       $at, 0xc2c8
/* 40B87C E012048C 44811000 */  mtc1      $at, $f2
/* 40B880 E0120490 3C0142C8 */  lui       $at, 0x42c8
/* 40B884 E0120494 44812000 */  mtc1      $at, $f4
/* 40B888 E0120498 3C013F80 */  lui       $at, 0x3f80
/* 40B88C E012049C 44813000 */  mtc1      $at, $f6
/* 40B890 E01204A0 27A40020 */  addiu     $a0, $sp, 0x20
/* 40B894 E01204A4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 40B898 E01204A8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 40B89C E01204AC E7A40018 */  swc1      $f4, 0x18($sp)
/* 40B8A0 E01204B0 0C080184 */  jal       func_E0200610
/* 40B8A4 E01204B4 E7A6001C */   swc1     $f6, 0x1c($sp)
/* 40B8A8 E01204B8 3C130001 */  lui       $s3, 1
/* 40B8AC E01204BC 36731630 */  ori       $s3, $s3, 0x1630
/* 40B8B0 E01204C0 27A40020 */  addiu     $a0, $sp, 0x20
/* 40B8B4 E01204C4 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 40B8B8 E01204C8 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 40B8BC E01204CC 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 40B8C0 E01204D0 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 40B8C4 E01204D4 96250000 */  lhu       $a1, ($s1)
/* 40B8C8 E01204D8 8E420000 */  lw        $v0, ($s2)
/* 40B8CC E01204DC 00052980 */  sll       $a1, $a1, 6
/* 40B8D0 E01204E0 00B32821 */  addu      $a1, $a1, $s3
/* 40B8D4 E01204E4 0C080118 */  jal       func_E0200460
/* 40B8D8 E01204E8 00452821 */   addu     $a1, $v0, $a1
/* 40B8DC E01204EC 3C09DA38 */  lui       $t1, 0xda38
/* 40B8E0 E01204F0 35290007 */  ori       $t1, $t1, 7
/* 40B8E4 E01204F4 27A40020 */  addiu     $a0, $sp, 0x20
/* 40B8E8 E01204F8 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 40B8EC E01204FC 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 40B8F0 E0120500 44800000 */  mtc1      $zero, $f0
/* 40B8F4 E0120504 8E030000 */  lw        $v1, ($s0)
/* 40B8F8 E0120508 96220000 */  lhu       $v0, ($s1)
/* 40B8FC E012050C 0060402D */  daddu     $t0, $v1, $zero
/* 40B900 E0120510 24630008 */  addiu     $v1, $v1, 8
/* 40B904 E0120514 AE030000 */  sw        $v1, ($s0)
/* 40B908 E0120518 24430001 */  addiu     $v1, $v0, 1
/* 40B90C E012051C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 40B910 E0120520 00021180 */  sll       $v0, $v0, 6
/* 40B914 E0120524 44050000 */  mfc1      $a1, $f0
/* 40B918 E0120528 00531021 */  addu      $v0, $v0, $s3
/* 40B91C E012052C AD090000 */  sw        $t1, ($t0)
/* 40B920 E0120530 A6230000 */  sh        $v1, ($s1)
/* 40B924 E0120534 8E430000 */  lw        $v1, ($s2)
/* 40B928 E0120538 00A0302D */  daddu     $a2, $a1, $zero
/* 40B92C E012053C 00A0382D */  daddu     $a3, $a1, $zero
/* 40B930 E0120540 00621821 */  addu      $v1, $v1, $v0
/* 40B934 E0120544 0C080108 */  jal       func_E0200420
/* 40B938 E0120548 AD030004 */   sw       $v1, 4($t0)
/* 40B93C E012054C 27A40020 */  addiu     $a0, $sp, 0x20
/* 40B940 E0120550 96250000 */  lhu       $a1, ($s1)
/* 40B944 E0120554 8E420000 */  lw        $v0, ($s2)
/* 40B948 E0120558 00052980 */  sll       $a1, $a1, 6
/* 40B94C E012055C 00B32821 */  addu      $a1, $a1, $s3
/* 40B950 E0120560 0C080118 */  jal       func_E0200460
/* 40B954 E0120564 00452821 */   addu     $a1, $v0, $a1
/* 40B958 E0120568 3C03DA38 */  lui       $v1, 0xda38
/* 40B95C E012056C 34630002 */  ori       $v1, $v1, 2
/* 40B960 E0120570 0000582D */  daddu     $t3, $zero, $zero
/* 40B964 E0120574 3C0EF200 */  lui       $t6, 0xf200
/* 40B968 E0120578 3C0C0100 */  lui       $t4, 0x100
/* 40B96C E012057C 358C007C */  ori       $t4, $t4, 0x7c
/* 40B970 E0120580 3C0DDE00 */  lui       $t5, 0xde00
/* 40B974 E0120584 3C0AE012 */  lui       $t2, %hi(D_E0120780)
/* 40B978 E0120588 254A0780 */  addiu     $t2, $t2, %lo(D_E0120780)
/* 40B97C E012058C 0160482D */  daddu     $t1, $t3, $zero
/* 40B980 E0120590 0280402D */  daddu     $t0, $s4, $zero
/* 40B984 E0120594 8E060000 */  lw        $a2, ($s0)
/* 40B988 E0120598 3C014080 */  lui       $at, 0x4080
/* 40B98C E012059C 44811000 */  mtc1      $at, $f2
/* 40B990 E01205A0 96220000 */  lhu       $v0, ($s1)
/* 40B994 E01205A4 00C0202D */  daddu     $a0, $a2, $zero
/* 40B998 E01205A8 24C60008 */  addiu     $a2, $a2, 8
/* 40B99C E01205AC AE060000 */  sw        $a2, ($s0)
/* 40B9A0 E01205B0 AC830000 */  sw        $v1, ($a0)
/* 40B9A4 E01205B4 24430001 */  addiu     $v1, $v0, 1
/* 40B9A8 E01205B8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 40B9AC E01205BC 00021180 */  sll       $v0, $v0, 6
/* 40B9B0 E01205C0 A6230000 */  sh        $v1, ($s1)
/* 40B9B4 E01205C4 8E430000 */  lw        $v1, ($s2)
/* 40B9B8 E01205C8 00531021 */  addu      $v0, $v0, $s3
/* 40B9BC E01205CC 00621821 */  addu      $v1, $v1, $v0
/* 40B9C0 E01205D0 24C20008 */  addiu     $v0, $a2, 8
/* 40B9C4 E01205D4 AC830004 */  sw        $v1, 4($a0)
/* 40B9C8 E01205D8 AE020000 */  sw        $v0, ($s0)
/* 40B9CC E01205DC 3C02FA00 */  lui       $v0, 0xfa00
/* 40B9D0 E01205E0 ACC20000 */  sw        $v0, ($a2)
/* 40B9D4 E01205E4 91030018 */  lbu       $v1, 0x18($t0)
/* 40B9D8 E01205E8 91040019 */  lbu       $a0, 0x19($t0)
/* 40B9DC E01205EC 9105001A */  lbu       $a1, 0x1a($t0)
/* 40B9E0 E01205F0 24C20010 */  addiu     $v0, $a2, 0x10
/* 40B9E4 E01205F4 AE020000 */  sw        $v0, ($s0)
/* 40B9E8 E01205F8 3C02FB00 */  lui       $v0, 0xfb00
/* 40B9EC E01205FC ACC20008 */  sw        $v0, 8($a2)
/* 40B9F0 E0120600 00151043 */  sra       $v0, $s5, 1
/* 40B9F4 E0120604 304200FF */  andi      $v0, $v0, 0xff
/* 40B9F8 E0120608 00031E00 */  sll       $v1, $v1, 0x18
/* 40B9FC E012060C 00042400 */  sll       $a0, $a0, 0x10
/* 40BA00 E0120610 00641825 */  or        $v1, $v1, $a0
/* 40BA04 E0120614 00052A00 */  sll       $a1, $a1, 8
/* 40BA08 E0120618 00651825 */  or        $v1, $v1, $a1
/* 40BA0C E012061C 00621825 */  or        $v1, $v1, $v0
/* 40BA10 E0120620 ACC30004 */  sw        $v1, 4($a2)
/* 40BA14 E0120624 9102001B */  lbu       $v0, 0x1b($t0)
/* 40BA18 E0120628 9104001C */  lbu       $a0, 0x1c($t0)
/* 40BA1C E012062C 9105001D */  lbu       $a1, 0x1d($t0)
/* 40BA20 E0120630 9107001E */  lbu       $a3, 0x1e($t0)
/* 40BA24 E0120634 01A0182D */  daddu     $v1, $t5, $zero
/* 40BA28 E0120638 ACC30010 */  sw        $v1, 0x10($a2)
/* 40BA2C E012063C 00021600 */  sll       $v0, $v0, 0x18
/* 40BA30 E0120640 00042400 */  sll       $a0, $a0, 0x10
/* 40BA34 E0120644 00441025 */  or        $v0, $v0, $a0
/* 40BA38 E0120648 00052A00 */  sll       $a1, $a1, 8
/* 40BA3C E012064C 00451025 */  or        $v0, $v0, $a1
/* 40BA40 E0120650 00471025 */  or        $v0, $v0, $a3
/* 40BA44 E0120654 ACC2000C */  sw        $v0, 0xc($a2)
/* 40BA48 E0120658 3C03E012 */  lui       $v1, %hi(D_E0120794)
/* 40BA4C E012065C 8C630794 */  lw        $v1, %lo(D_E0120794)($v1)
/* 40BA50 E0120660 24C20018 */  addiu     $v0, $a2, 0x18
/* 40BA54 E0120664 AE020000 */  sw        $v0, ($s0)
/* 40BA58 E0120668 ACC30014 */  sw        $v1, 0x14($a2)
.LE012066C:
/* 40BA5C E012066C C5000020 */  lwc1      $f0, 0x20($t0)
/* 40BA60 E0120670 25080004 */  addiu     $t0, $t0, 4
/* 40BA64 E0120674 8E040000 */  lw        $a0, ($s0)
/* 40BA68 E0120678 256B0001 */  addiu     $t3, $t3, 1
/* 40BA6C E012067C 0080282D */  daddu     $a1, $a0, $zero
/* 40BA70 E0120680 46020002 */  mul.s     $f0, $f0, $f2
/* 40BA74 E0120684 00000000 */  nop       
/* 40BA78 E0120688 24840008 */  addiu     $a0, $a0, 8
/* 40BA7C E012068C 24820008 */  addiu     $v0, $a0, 8
/* 40BA80 E0120690 AE040000 */  sw        $a0, ($s0)
/* 40BA84 E0120694 AE020000 */  sw        $v0, ($s0)
/* 40BA88 E0120698 4600020D */  trunc.w.s $f8, $f0
/* 40BA8C E012069C 44034000 */  mfc1      $v1, $f8
/* 40BA90 E01206A0 00000000 */  nop       
/* 40BA94 E01206A4 00691821 */  addu      $v1, $v1, $t1
/* 40BA98 E01206A8 30620FFF */  andi      $v0, $v1, 0xfff
/* 40BA9C E01206AC 00021300 */  sll       $v0, $v0, 0xc
/* 40BAA0 E01206B0 004E1025 */  or        $v0, $v0, $t6
/* 40BAA4 E01206B4 246300FC */  addiu     $v1, $v1, 0xfc
/* 40BAA8 E01206B8 30630FFF */  andi      $v1, $v1, 0xfff
/* 40BAAC E01206BC 00031B00 */  sll       $v1, $v1, 0xc
/* 40BAB0 E01206C0 006C1825 */  or        $v1, $v1, $t4
/* 40BAB4 E01206C4 ACA20000 */  sw        $v0, ($a1)
/* 40BAB8 E01206C8 ACA30004 */  sw        $v1, 4($a1)
/* 40BABC E01206CC AC8D0000 */  sw        $t5, ($a0)
/* 40BAC0 E01206D0 8D420000 */  lw        $v0, ($t2)
/* 40BAC4 E01206D4 254A0004 */  addiu     $t2, $t2, 4
/* 40BAC8 E01206D8 AC820004 */  sw        $v0, 4($a0)
/* 40BACC E01206DC 29620005 */  slti      $v0, $t3, 5
/* 40BAD0 E01206E0 1440FFE2 */  bnez      $v0, .LE012066C
/* 40BAD4 E01206E4 2529002C */   addiu    $t1, $t1, 0x2c
/* 40BAD8 E01206E8 3C02D838 */  lui       $v0, 0xd838
/* 40BADC E01206EC 34420002 */  ori       $v0, $v0, 2
/* 40BAE0 E01206F0 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 40BAE4 E01206F4 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 40BAE8 E01206F8 8CA40000 */  lw        $a0, ($a1)
/* 40BAEC E01206FC 3C06DA38 */  lui       $a2, 0xda38
/* 40BAF0 E0120700 0080182D */  daddu     $v1, $a0, $zero
/* 40BAF4 E0120704 24840008 */  addiu     $a0, $a0, 8
/* 40BAF8 E0120708 ACA40000 */  sw        $a0, ($a1)
/* 40BAFC E012070C AC620000 */  sw        $v0, ($v1)
/* 40BB00 E0120710 24020040 */  addiu     $v0, $zero, 0x40
/* 40BB04 E0120714 AC620004 */  sw        $v0, 4($v1)
/* 40BB08 E0120718 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 40BB0C E012071C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 40BB10 E0120720 24820008 */  addiu     $v0, $a0, 8
/* 40BB14 E0120724 ACA20000 */  sw        $v0, ($a1)
/* 40BB18 E0120728 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 40BB1C E012072C 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 40BB20 E0120730 34C60007 */  ori       $a2, $a2, 7
/* 40BB24 E0120734 AC860000 */  sw        $a2, ($a0)
/* 40BB28 E0120738 00031980 */  sll       $v1, $v1, 6
/* 40BB2C E012073C 24630030 */  addiu     $v1, $v1, 0x30
/* 40BB30 E0120740 00431021 */  addu      $v0, $v0, $v1
/* 40BB34 E0120744 AC820004 */  sw        $v0, 4($a0)
/* 40BB38 E0120748 24820010 */  addiu     $v0, $a0, 0x10
/* 40BB3C E012074C ACA20000 */  sw        $v0, ($a1)
/* 40BB40 E0120750 3C02E700 */  lui       $v0, 0xe700
/* 40BB44 E0120754 AC820008 */  sw        $v0, 8($a0)
/* 40BB48 E0120758 AC80000C */  sw        $zero, 0xc($a0)
.LE012075C:
/* 40BB4C E012075C 8FBF00B8 */  lw        $ra, 0xb8($sp)
/* 40BB50 E0120760 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 40BB54 E0120764 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 40BB58 E0120768 8FB300AC */  lw        $s3, 0xac($sp)
/* 40BB5C E012076C 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 40BB60 E0120770 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 40BB64 E0120774 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 40BB68 E0120778 03E00008 */  jr        $ra
/* 40BB6C E012077C 27BD00C0 */   addiu    $sp, $sp, 0xc0
