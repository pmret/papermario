.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024129C_D069CC
/* D069CC 8024129C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* D069D0 802412A0 AFB1001C */  sw        $s1, 0x1c($sp)
/* D069D4 802412A4 AFBF0020 */  sw        $ra, 0x20($sp)
/* D069D8 802412A8 AFB00018 */  sw        $s0, 0x18($sp)
/* D069DC 802412AC F7B60030 */  sdc1      $f22, 0x30($sp)
/* D069E0 802412B0 F7B40028 */  sdc1      $f20, 0x28($sp)
/* D069E4 802412B4 10A00060 */  beqz      $a1, .L80241438
/* D069E8 802412B8 0080882D */   daddu    $s1, $a0, $zero
/* D069EC 802412BC 3C05F4AC */  lui       $a1, 0xf4ac
/* D069F0 802412C0 0C0B1EAF */  jal       get_variable
/* D069F4 802412C4 34A5D481 */   ori      $a1, $a1, 0xd481
/* D069F8 802412C8 0220202D */  daddu     $a0, $s1, $zero
/* D069FC 802412CC 3C05F4AC */  lui       $a1, 0xf4ac
/* D06A00 802412D0 4482B000 */  mtc1      $v0, $f22
/* D06A04 802412D4 00000000 */  nop
/* D06A08 802412D8 4680B5A0 */  cvt.s.w   $f22, $f22
/* D06A0C 802412DC 0C0B1EAF */  jal       get_variable
/* D06A10 802412E0 34A5D482 */   ori      $a1, $a1, 0xd482
/* D06A14 802412E4 0220202D */  daddu     $a0, $s1, $zero
/* D06A18 802412E8 3C05F4AC */  lui       $a1, 0xf4ac
/* D06A1C 802412EC 4482A000 */  mtc1      $v0, $f20
/* D06A20 802412F0 00000000 */  nop
/* D06A24 802412F4 4680A520 */  cvt.s.w   $f20, $f20
/* D06A28 802412F8 0C0B1EAF */  jal       get_variable
/* D06A2C 802412FC 34A5D483 */   ori      $a1, $a1, 0xd483
/* D06A30 80241300 44821000 */  mtc1      $v0, $f2
/* D06A34 80241304 00000000 */  nop
/* D06A38 80241308 468010A0 */  cvt.s.w   $f2, $f2
/* D06A3C 8024130C 4405B000 */  mfc1      $a1, $f22
/* D06A40 80241310 4406A000 */  mfc1      $a2, $f20
/* D06A44 80241314 44071000 */  mfc1      $a3, $f2
/* D06A48 80241318 0C01C574 */  jal       func_800715D0
/* D06A4C 8024131C 0000202D */   daddu    $a0, $zero, $zero
/* D06A50 80241320 0220202D */  daddu     $a0, $s1, $zero
/* D06A54 80241324 3C05F4AC */  lui       $a1, 0xf4ac
/* D06A58 80241328 34A5D481 */  ori       $a1, $a1, 0xd481
/* D06A5C 8024132C 3C108025 */  lui       $s0, %hi(D_8024B9B0)
/* D06A60 80241330 2610B9B0 */  addiu     $s0, $s0, %lo(D_8024B9B0)
/* D06A64 80241334 0C0B1EAF */  jal       get_variable
/* D06A68 80241338 AE020000 */   sw       $v0, ($s0)
/* D06A6C 8024133C 0220202D */  daddu     $a0, $s1, $zero
/* D06A70 80241340 3C05F4AC */  lui       $a1, 0xf4ac
/* D06A74 80241344 4482B000 */  mtc1      $v0, $f22
/* D06A78 80241348 00000000 */  nop
/* D06A7C 8024134C 4680B5A0 */  cvt.s.w   $f22, $f22
/* D06A80 80241350 0C0B1EAF */  jal       get_variable
/* D06A84 80241354 34A5D482 */   ori      $a1, $a1, 0xd482
/* D06A88 80241358 0220202D */  daddu     $a0, $s1, $zero
/* D06A8C 8024135C 3C05F4AC */  lui       $a1, 0xf4ac
/* D06A90 80241360 4482A000 */  mtc1      $v0, $f20
/* D06A94 80241364 00000000 */  nop
/* D06A98 80241368 4680A520 */  cvt.s.w   $f20, $f20
/* D06A9C 8024136C 0C0B1EAF */  jal       get_variable
/* D06AA0 80241370 34A5D483 */   ori      $a1, $a1, 0xd483
/* D06AA4 80241374 44821000 */  mtc1      $v0, $f2
/* D06AA8 80241378 00000000 */  nop
/* D06AAC 8024137C 468010A0 */  cvt.s.w   $f2, $f2
/* D06AB0 80241380 4405B000 */  mfc1      $a1, $f22
/* D06AB4 80241384 4406A000 */  mfc1      $a2, $f20
/* D06AB8 80241388 44071000 */  mfc1      $a3, $f2
/* D06ABC 8024138C 0C01C604 */  jal       func_80071810
/* D06AC0 80241390 0000202D */   daddu    $a0, $zero, $zero
/* D06AC4 80241394 0220202D */  daddu     $a0, $s1, $zero
/* D06AC8 80241398 3C05F4AC */  lui       $a1, 0xf4ac
/* D06ACC 8024139C 3C018025 */  lui       $at, %hi(D_8024B9B4)
/* D06AD0 802413A0 AC22B9B4 */  sw        $v0, %lo(D_8024B9B4)($at)
/* D06AD4 802413A4 0C0B1EAF */  jal       get_variable
/* D06AD8 802413A8 34A5D481 */   ori      $a1, $a1, 0xd481
/* D06ADC 802413AC 0220202D */  daddu     $a0, $s1, $zero
/* D06AE0 802413B0 3C05F4AC */  lui       $a1, 0xf4ac
/* D06AE4 802413B4 4482B000 */  mtc1      $v0, $f22
/* D06AE8 802413B8 00000000 */  nop
/* D06AEC 802413BC 4680B5A0 */  cvt.s.w   $f22, $f22
/* D06AF0 802413C0 0C0B1EAF */  jal       get_variable
/* D06AF4 802413C4 34A5D482 */   ori      $a1, $a1, 0xd482
/* D06AF8 802413C8 0220202D */  daddu     $a0, $s1, $zero
/* D06AFC 802413CC 3C05F4AC */  lui       $a1, 0xf4ac
/* D06B00 802413D0 4482A000 */  mtc1      $v0, $f20
/* D06B04 802413D4 00000000 */  nop
/* D06B08 802413D8 4680A520 */  cvt.s.w   $f20, $f20
/* D06B0C 802413DC 0C0B1EAF */  jal       get_variable
/* D06B10 802413E0 34A5D483 */   ori      $a1, $a1, 0xd483
/* D06B14 802413E4 44821000 */  mtc1      $v0, $f2
/* D06B18 802413E8 00000000 */  nop
/* D06B1C 802413EC 468010A0 */  cvt.s.w   $f2, $f2
/* D06B20 802413F0 4405B000 */  mfc1      $a1, $f22
/* D06B24 802413F4 4406A000 */  mfc1      $a2, $f20
/* D06B28 802413F8 3C013F80 */  lui       $at, 0x3f80
/* D06B2C 802413FC 44810000 */  mtc1      $at, $f0
/* D06B30 80241400 44071000 */  mfc1      $a3, $f2
/* D06B34 80241404 0000202D */  daddu     $a0, $zero, $zero
/* D06B38 80241408 AFA00014 */  sw        $zero, 0x14($sp)
/* D06B3C 8024140C 0C01CA24 */  jal       func_80072890
/* D06B40 80241410 E7A00010 */   swc1     $f0, 0x10($sp)
/* D06B44 80241414 8E030000 */  lw        $v1, ($s0)
/* D06B48 80241418 8C64000C */  lw        $a0, 0xc($v1)
/* D06B4C 8024141C 3C018025 */  lui       $at, %hi(D_8024B9B8)
/* D06B50 80241420 AC22B9B8 */  sw        $v0, %lo(D_8024B9B8)($at)
/* D06B54 80241424 AC800018 */  sw        $zero, 0x18($a0)
/* D06B58 80241428 AC800020 */  sw        $zero, 0x20($a0)
/* D06B5C 8024142C AC800024 */  sw        $zero, 0x24($a0)
/* D06B60 80241430 AC800028 */  sw        $zero, 0x28($a0)
/* D06B64 80241434 AC80001C */  sw        $zero, 0x1c($a0)
.L80241438:
/* D06B68 80241438 3C028025 */  lui       $v0, %hi(D_8024B9B0)
/* D06B6C 8024143C 8C42B9B0 */  lw        $v0, %lo(D_8024B9B0)($v0)
/* D06B70 80241440 8C44000C */  lw        $a0, 0xc($v0)
/* D06B74 80241444 8C820020 */  lw        $v0, 0x20($a0)
/* D06B78 80241448 8C830028 */  lw        $v1, 0x28($a0)
/* D06B7C 8024144C 2442000A */  addiu     $v0, $v0, 0xa
/* D06B80 80241450 AC820020 */  sw        $v0, 0x20($a0)
/* D06B84 80241454 8C820024 */  lw        $v0, 0x24($a0)
/* D06B88 80241458 2463000A */  addiu     $v1, $v1, 0xa
/* D06B8C 8024145C AC830028 */  sw        $v1, 0x28($a0)
/* D06B90 80241460 8C830018 */  lw        $v1, 0x18($a0)
/* D06B94 80241464 2442000A */  addiu     $v0, $v0, 0xa
/* D06B98 80241468 AC820024 */  sw        $v0, 0x24($a0)
/* D06B9C 8024146C 8C82001C */  lw        $v0, 0x1c($a0)
/* D06BA0 80241470 2463000A */  addiu     $v1, $v1, 0xa
/* D06BA4 80241474 AC830018 */  sw        $v1, 0x18($a0)
/* D06BA8 80241478 286300FF */  slti      $v1, $v1, 0xff
/* D06BAC 8024147C 2442000A */  addiu     $v0, $v0, 0xa
/* D06BB0 80241480 AC82001C */  sw        $v0, 0x1c($a0)
/* D06BB4 80241484 14600004 */  bnez      $v1, .L80241498
/* D06BB8 80241488 0000102D */   daddu    $v0, $zero, $zero
/* D06BBC 8024148C 240200FF */  addiu     $v0, $zero, 0xff
/* D06BC0 80241490 AC820018 */  sw        $v0, 0x18($a0)
/* D06BC4 80241494 24020002 */  addiu     $v0, $zero, 2
.L80241498:
/* D06BC8 80241498 8FBF0020 */  lw        $ra, 0x20($sp)
/* D06BCC 8024149C 8FB1001C */  lw        $s1, 0x1c($sp)
/* D06BD0 802414A0 8FB00018 */  lw        $s0, 0x18($sp)
/* D06BD4 802414A4 D7B60030 */  ldc1      $f22, 0x30($sp)
/* D06BD8 802414A8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* D06BDC 802414AC 03E00008 */  jr        $ra
/* D06BE0 802414B0 27BD0038 */   addiu    $sp, $sp, 0x38
