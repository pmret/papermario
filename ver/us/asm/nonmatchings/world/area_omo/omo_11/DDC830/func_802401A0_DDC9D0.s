.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401A0_DDC9D0
/* DDC9D0 802401A0 27BDFE90 */  addiu     $sp, $sp, -0x170
/* DDC9D4 802401A4 AFB00138 */  sw        $s0, 0x138($sp)
/* DDC9D8 802401A8 00A0802D */  daddu     $s0, $a1, $zero
/* DDC9DC 802401AC AFA40170 */  sw        $a0, 0x170($sp)
/* DDC9E0 802401B0 AFBF015C */  sw        $ra, 0x15c($sp)
/* DDC9E4 802401B4 AFBE0158 */  sw        $fp, 0x158($sp)
/* DDC9E8 802401B8 AFB70154 */  sw        $s7, 0x154($sp)
/* DDC9EC 802401BC AFB60150 */  sw        $s6, 0x150($sp)
/* DDC9F0 802401C0 AFB5014C */  sw        $s5, 0x14c($sp)
/* DDC9F4 802401C4 AFB40148 */  sw        $s4, 0x148($sp)
/* DDC9F8 802401C8 AFB30144 */  sw        $s3, 0x144($sp)
/* DDC9FC 802401CC AFB20140 */  sw        $s2, 0x140($sp)
/* DDCA00 802401D0 AFB1013C */  sw        $s1, 0x13c($sp)
/* DDCA04 802401D4 F7B60168 */  sdc1      $f22, 0x168($sp)
/* DDCA08 802401D8 F7B40160 */  sdc1      $f20, 0x160($sp)
/* DDCA0C 802401DC 0C00EABB */  jal       get_npc_unsafe
/* DDCA10 802401E0 2404FFFC */   addiu    $a0, $zero, -4
/* DDCA14 802401E4 2404004A */  addiu     $a0, $zero, 0x4a
/* DDCA18 802401E8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* DDCA1C 802401EC 0040B02D */   daddu    $s6, $v0, $zero
/* DDCA20 802401F0 0C046B4C */  jal       get_model_from_list_index
/* DDCA24 802401F4 0040202D */   daddu    $a0, $v0, $zero
/* DDCA28 802401F8 2404003F */  addiu     $a0, $zero, 0x3f
/* DDCA2C 802401FC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* DDCA30 80240200 0040B82D */   daddu    $s7, $v0, $zero
/* DDCA34 80240204 0C046B4C */  jal       get_model_from_list_index
/* DDCA38 80240208 0040202D */   daddu    $a0, $v0, $zero
/* DDCA3C 8024020C 3C1E8011 */  lui       $fp, %hi(gPlayerStatus)
/* DDCA40 80240210 27DEEFC8 */  addiu     $fp, $fp, %lo(gPlayerStatus)
/* DDCA44 80240214 1200005F */  beqz      $s0, .L80240394
/* DDCA48 80240218 AFA2012C */   sw       $v0, 0x12c($sp)
/* DDCA4C 8024021C 3C048000 */  lui       $a0, 0x8000
/* DDCA50 80240220 34840016 */  ori       $a0, $a0, 0x16
/* DDCA54 80240224 0000282D */  daddu     $a1, $zero, $zero
/* DDCA58 80240228 00A0982D */  daddu     $s3, $a1, $zero
/* DDCA5C 8024022C 24150004 */  addiu     $s5, $zero, 4
/* DDCA60 80240230 3C06439D */  lui       $a2, 0x439d
/* DDCA64 80240234 34C68000 */  ori       $a2, $a2, 0x8000
/* DDCA68 80240238 3C0742FA */  lui       $a3, 0x42fa
/* DDCA6C 8024023C 3C01C2C8 */  lui       $at, 0xc2c8
/* DDCA70 80240240 44810000 */  mtc1      $at, $f0
/* DDCA74 80240244 3C148024 */  lui       $s4, %hi(D_80241760_DDDF90)
/* DDCA78 80240248 26941760 */  addiu     $s4, $s4, %lo(D_80241760_DDDF90)
/* DDCA7C 8024024C 0C052757 */  jal       play_sound_at_position
/* DDCA80 80240250 E7A00010 */   swc1     $f0, 0x10($sp)
/* DDCA84 80240254 0C00AB39 */  jal       heap_malloc
/* DDCA88 80240258 24040210 */   addiu    $a0, $zero, 0x210
/* DDCA8C 8024025C 0040902D */  daddu     $s2, $v0, $zero
/* DDCA90 80240260 8FA90170 */  lw        $t1, 0x170($sp)
/* DDCA94 80240264 26510008 */  addiu     $s1, $s2, 8
/* DDCA98 80240268 AD320070 */  sw        $s2, 0x70($t1)
/* DDCA9C 8024026C AD200074 */  sw        $zero, 0x74($t1)
.L80240270:
/* DDCAA0 80240270 0C046C04 */  jal       get_model_list_index_from_tree_index
/* DDCAA4 80240274 8E840000 */   lw       $a0, ($s4)
/* DDCAA8 80240278 0C046B4C */  jal       get_model_from_list_index
/* DDCAAC 8024027C 0040202D */   daddu    $a0, $v0, $zero
/* DDCAB0 80240280 0040802D */  daddu     $s0, $v0, $zero
/* DDCAB4 80240284 C6060098 */  lwc1      $f6, 0x98($s0)
/* DDCAB8 80240288 C6E00098 */  lwc1      $f0, 0x98($s7)
/* DDCABC 8024028C 46003181 */  sub.s     $f6, $f6, $f0
/* DDCAC0 80240290 E6460000 */  swc1      $f6, ($s2)
/* DDCAC4 80240294 C604009C */  lwc1      $f4, 0x9c($s0)
/* DDCAC8 80240298 C6E0009C */  lwc1      $f0, 0x9c($s7)
/* DDCACC 8024029C 46002101 */  sub.s     $f4, $f4, $f0
/* DDCAD0 802402A0 E624FFFC */  swc1      $f4, -4($s1)
/* DDCAD4 802402A4 C60000A0 */  lwc1      $f0, 0xa0($s0)
/* DDCAD8 802402A8 C6E200A0 */  lwc1      $f2, 0xa0($s7)
/* DDCADC 802402AC 0000302D */  daddu     $a2, $zero, $zero
/* DDCAE0 802402B0 46020001 */  sub.s     $f0, $f0, $f2
/* DDCAE4 802402B4 E7A60120 */  swc1      $f6, 0x120($sp)
/* DDCAE8 802402B8 E7A40124 */  swc1      $f4, 0x124($sp)
/* DDCAEC 802402BC E6200000 */  swc1      $f0, ($s1)
/* DDCAF0 802402C0 E7A00128 */  swc1      $f0, 0x128($sp)
/* DDCAF4 802402C4 0000282D */  daddu     $a1, $zero, $zero
.L802402C8:
/* DDCAF8 802402C8 00062100 */  sll       $a0, $a2, 4
.L802402CC:
/* DDCAFC 802402CC 02441821 */  addu      $v1, $s2, $a0
/* DDCB00 802402D0 02041021 */  addu      $v0, $s0, $a0
/* DDCB04 802402D4 24840004 */  addiu     $a0, $a0, 4
/* DDCB08 802402D8 24A50001 */  addiu     $a1, $a1, 1
/* DDCB0C 802402DC C4400058 */  lwc1      $f0, 0x58($v0)
/* DDCB10 802402E0 28A20004 */  slti      $v0, $a1, 4
/* DDCB14 802402E4 1440FFF9 */  bnez      $v0, .L802402CC
/* DDCB18 802402E8 E4600018 */   swc1     $f0, 0x18($v1)
/* DDCB1C 802402EC 24C60001 */  addiu     $a2, $a2, 1
/* DDCB20 802402F0 28C20004 */  slti      $v0, $a2, 4
/* DDCB24 802402F4 1440FFF4 */  bnez      $v0, .L802402C8
/* DDCB28 802402F8 0000282D */   daddu    $a1, $zero, $zero
/* DDCB2C 802402FC 26310058 */  addiu     $s1, $s1, 0x58
/* DDCB30 80240300 3C098024 */  lui       $t1, %hi(D_80241760_DDDF90)
/* DDCB34 80240304 25291760 */  addiu     $t1, $t1, %lo(D_80241760_DDDF90)
/* DDCB38 80240308 02A91021 */  addu      $v0, $s5, $t1
/* DDCB3C 8024030C 8C440000 */  lw        $a0, ($v0)
/* DDCB40 80240310 0C046C04 */  jal       get_model_list_index_from_tree_index
/* DDCB44 80240314 26520058 */   addiu    $s2, $s2, 0x58
/* DDCB48 80240318 0C046B4C */  jal       get_model_from_list_index
/* DDCB4C 8024031C 0040202D */   daddu    $a0, $v0, $zero
/* DDCB50 80240320 0040802D */  daddu     $s0, $v0, $zero
/* DDCB54 80240324 C7A00120 */  lwc1      $f0, 0x120($sp)
/* DDCB58 80240328 C7A20124 */  lwc1      $f2, 0x124($sp)
/* DDCB5C 8024032C C7A40128 */  lwc1      $f4, 0x128($sp)
/* DDCB60 80240330 0000302D */  daddu     $a2, $zero, $zero
/* DDCB64 80240334 E6400000 */  swc1      $f0, ($s2)
/* DDCB68 80240338 E622FFFC */  swc1      $f2, -4($s1)
/* DDCB6C 8024033C E6240000 */  swc1      $f4, ($s1)
/* DDCB70 80240340 0000282D */  daddu     $a1, $zero, $zero
.L80240344:
/* DDCB74 80240344 00062100 */  sll       $a0, $a2, 4
.L80240348:
/* DDCB78 80240348 02441821 */  addu      $v1, $s2, $a0
/* DDCB7C 8024034C 02041021 */  addu      $v0, $s0, $a0
/* DDCB80 80240350 24840004 */  addiu     $a0, $a0, 4
/* DDCB84 80240354 24A50001 */  addiu     $a1, $a1, 1
/* DDCB88 80240358 C4400058 */  lwc1      $f0, 0x58($v0)
/* DDCB8C 8024035C 28A20004 */  slti      $v0, $a1, 4
/* DDCB90 80240360 1440FFF9 */  bnez      $v0, .L80240348
/* DDCB94 80240364 E4600018 */   swc1     $f0, 0x18($v1)
/* DDCB98 80240368 24C60001 */  addiu     $a2, $a2, 1
/* DDCB9C 8024036C 28C20004 */  slti      $v0, $a2, 4
/* DDCBA0 80240370 1440FFF4 */  bnez      $v0, .L80240344
/* DDCBA4 80240374 0000282D */   daddu    $a1, $zero, $zero
/* DDCBA8 80240378 26310058 */  addiu     $s1, $s1, 0x58
/* DDCBAC 8024037C 26520058 */  addiu     $s2, $s2, 0x58
/* DDCBB0 80240380 26B50008 */  addiu     $s5, $s5, 8
/* DDCBB4 80240384 26730002 */  addiu     $s3, $s3, 2
/* DDCBB8 80240388 2E620006 */  sltiu     $v0, $s3, 6
/* DDCBBC 8024038C 1440FFB8 */  bnez      $v0, .L80240270
/* DDCBC0 80240390 26940008 */   addiu    $s4, $s4, 8
.L80240394:
/* DDCBC4 80240394 27B500A0 */  addiu     $s5, $sp, 0xa0
/* DDCBC8 80240398 27B40060 */  addiu     $s4, $sp, 0x60
/* DDCBCC 8024039C 27A900E0 */  addiu     $t1, $sp, 0xe0
/* DDCBD0 802403A0 AFA90130 */  sw        $t1, 0x130($sp)
/* DDCBD4 802403A4 8FA90170 */  lw        $t1, 0x170($sp)
/* DDCBD8 802403A8 4480A000 */  mtc1      $zero, $f20
/* DDCBDC 802403AC 3C138024 */  lui       $s3, %hi(D_80241778_DDDFA8)
/* DDCBE0 802403B0 26731778 */  addiu     $s3, $s3, %lo(D_80241778_DDDFA8)
/* DDCBE4 802403B4 AFA00134 */  sw        $zero, 0x134($sp)
/* DDCBE8 802403B8 8D320070 */  lw        $s2, 0x70($t1)
/* DDCBEC 802403BC 3C013F80 */  lui       $at, 0x3f80
/* DDCBF0 802403C0 4481B000 */  mtc1      $at, $f22
/* DDCBF4 802403C4 26510014 */  addiu     $s1, $s2, 0x14
.L802403C8:
/* DDCBF8 802403C8 8FA90134 */  lw        $t1, 0x134($sp)
/* DDCBFC 802403CC 3C048024 */  lui       $a0, %hi(D_80241760_DDDF90)
/* DDCC00 802403D0 00892021 */  addu      $a0, $a0, $t1
/* DDCC04 802403D4 0C046C04 */  jal       get_model_list_index_from_tree_index
/* DDCC08 802403D8 8C841760 */   lw       $a0, %lo(D_80241760_DDDF90)($a0)
/* DDCC0C 802403DC 0C046B4C */  jal       get_model_from_list_index
/* DDCC10 802403E0 0040202D */   daddu    $a0, $v0, $zero
/* DDCC14 802403E4 0040802D */  daddu     $s0, $v0, $zero
/* DDCC18 802403E8 0000302D */  daddu     $a2, $zero, $zero
/* DDCC1C 802403EC 0000282D */  daddu     $a1, $zero, $zero
.L802403F0:
/* DDCC20 802403F0 00062100 */  sll       $a0, $a2, 4
.L802403F4:
/* DDCC24 802403F4 02041821 */  addu      $v1, $s0, $a0
/* DDCC28 802403F8 02441021 */  addu      $v0, $s2, $a0
/* DDCC2C 802403FC 24840004 */  addiu     $a0, $a0, 4
/* DDCC30 80240400 24A50001 */  addiu     $a1, $a1, 1
/* DDCC34 80240404 C4400018 */  lwc1      $f0, 0x18($v0)
/* DDCC38 80240408 28A20004 */  slti      $v0, $a1, 4
/* DDCC3C 8024040C 1440FFF9 */  bnez      $v0, .L802403F4
/* DDCC40 80240410 E4600058 */   swc1     $f0, 0x58($v1)
/* DDCC44 80240414 24C60001 */  addiu     $a2, $a2, 1
/* DDCC48 80240418 28C20004 */  slti      $v0, $a2, 4
/* DDCC4C 8024041C 1440FFF4 */  bnez      $v0, .L802403F0
/* DDCC50 80240420 0000282D */   daddu    $a1, $zero, $zero
/* DDCC54 80240424 96020000 */  lhu       $v0, ($s0)
/* DDCC58 80240428 34421400 */  ori       $v0, $v0, 0x1400
/* DDCC5C 8024042C A6020000 */  sh        $v0, ($s0)
/* DDCC60 80240430 8E450000 */  lw        $a1, ($s2)
/* DDCC64 80240434 8E26FFF0 */  lw        $a2, -0x10($s1)
/* DDCC68 80240438 8E27FFF4 */  lw        $a3, -0xc($s1)
/* DDCC6C 8024043C 0C019E40 */  jal       guTranslateF
/* DDCC70 80240440 27A40020 */   addiu    $a0, $sp, 0x20
/* DDCC74 80240444 8FA90170 */  lw        $t1, 0x170($sp)
/* DDCC78 80240448 4406A000 */  mfc1      $a2, $f20
/* DDCC7C 8024044C 4407A000 */  mfc1      $a3, $f20
/* DDCC80 80240450 C5200074 */  lwc1      $f0, 0x74($t1)
/* DDCC84 80240454 46800020 */  cvt.s.w   $f0, $f0
/* DDCC88 80240458 44050000 */  mfc1      $a1, $f0
/* DDCC8C 8024045C 02A0202D */  daddu     $a0, $s5, $zero
/* DDCC90 80240460 0C019EC8 */  jal       guRotateF
/* DDCC94 80240464 E7B60010 */   swc1     $f22, 0x10($sp)
/* DDCC98 80240468 C6400000 */  lwc1      $f0, ($s2)
/* DDCC9C 8024046C C622FFF4 */  lwc1      $f2, -0xc($s1)
/* DDCCA0 80240470 46000007 */  neg.s     $f0, $f0
/* DDCCA4 80240474 46001087 */  neg.s     $f2, $f2
/* DDCCA8 80240478 44050000 */  mfc1      $a1, $f0
/* DDCCAC 8024047C C620FFF0 */  lwc1      $f0, -0x10($s1)
/* DDCCB0 80240480 44071000 */  mfc1      $a3, $f2
/* DDCCB4 80240484 46000007 */  neg.s     $f0, $f0
/* DDCCB8 80240488 44060000 */  mfc1      $a2, $f0
/* DDCCBC 8024048C 0C019E40 */  jal       guTranslateF
/* DDCCC0 80240490 0280202D */   daddu    $a0, $s4, $zero
/* DDCCC4 80240494 4406A000 */  mfc1      $a2, $f20
/* DDCCC8 80240498 8FA90170 */  lw        $t1, 0x170($sp)
/* DDCCCC 8024049C 4407A000 */  mfc1      $a3, $f20
/* DDCCD0 802404A0 8D220074 */  lw        $v0, 0x74($t1)
/* DDCCD4 802404A4 8FA40130 */  lw        $a0, 0x130($sp)
/* DDCCD8 802404A8 00021023 */  negu      $v0, $v0
/* DDCCDC 802404AC 44824000 */  mtc1      $v0, $f8
/* DDCCE0 802404B0 00000000 */  nop
/* DDCCE4 802404B4 46804220 */  cvt.s.w   $f8, $f8
/* DDCCE8 802404B8 44054000 */  mfc1      $a1, $f8
/* DDCCEC 802404BC 0C019EC8 */  jal       guRotateF
/* DDCCF0 802404C0 E7B60010 */   swc1     $f22, 0x10($sp)
/* DDCCF4 802404C4 27A40020 */  addiu     $a0, $sp, 0x20
/* DDCCF8 802404C8 02A0282D */  daddu     $a1, $s5, $zero
/* DDCCFC 802404CC 0C019D80 */  jal       guMtxCatF
/* DDCD00 802404D0 02A0302D */   daddu    $a2, $s5, $zero
/* DDCD04 802404D4 02A0202D */  daddu     $a0, $s5, $zero
/* DDCD08 802404D8 0280282D */  daddu     $a1, $s4, $zero
/* DDCD0C 802404DC 0C019D80 */  jal       guMtxCatF
/* DDCD10 802404E0 0280302D */   daddu    $a2, $s4, $zero
/* DDCD14 802404E4 0280282D */  daddu     $a1, $s4, $zero
/* DDCD18 802404E8 8FA40130 */  lw        $a0, 0x130($sp)
/* DDCD1C 802404EC 0C019D80 */  jal       guMtxCatF
/* DDCD20 802404F0 0280302D */   daddu    $a2, $s4, $zero
/* DDCD24 802404F4 26100058 */  addiu     $s0, $s0, 0x58
/* DDCD28 802404F8 0200202D */  daddu     $a0, $s0, $zero
/* DDCD2C 802404FC 0280282D */  daddu     $a1, $s4, $zero
/* DDCD30 80240500 0C019D80 */  jal       guMtxCatF
/* DDCD34 80240504 0200302D */   daddu    $a2, $s0, $zero
/* DDCD38 80240508 86640002 */  lh        $a0, 2($s3)
/* DDCD3C 8024050C 0C016E89 */  jal       update_collider_transform
/* DDCD40 80240510 00000000 */   nop
/* DDCD44 80240514 0200202D */  daddu     $a0, $s0, $zero
/* DDCD48 80240518 4405A000 */  mfc1      $a1, $f20
/* DDCD4C 8024051C 4406A000 */  mfc1      $a2, $f20
/* DDCD50 80240520 4407A000 */  mfc1      $a3, $f20
/* DDCD54 80240524 27A20120 */  addiu     $v0, $sp, 0x120
/* DDCD58 80240528 AFA20010 */  sw        $v0, 0x10($sp)
/* DDCD5C 8024052C 27A20124 */  addiu     $v0, $sp, 0x124
/* DDCD60 80240530 AFA20014 */  sw        $v0, 0x14($sp)
/* DDCD64 80240534 27A20128 */  addiu     $v0, $sp, 0x128
/* DDCD68 80240538 0C019E9C */  jal       guMtxXFMF
/* DDCD6C 8024053C AFA20018 */   sw       $v0, 0x18($sp)
/* DDCD70 80240540 3C028016 */  lui       $v0, %hi(gCollisionStatus+0x2)
/* DDCD74 80240544 8442A552 */  lh        $v0, %lo(gCollisionStatus+0x2)($v0)
/* DDCD78 80240548 8E630000 */  lw        $v1, ($s3)
/* DDCD7C 8024054C 10430005 */  beq       $v0, $v1, .L80240564
/* DDCD80 80240550 00000000 */   nop
/* DDCD84 80240554 3C028016 */  lui       $v0, %hi(gCollisionStatus+0x4)
/* DDCD88 80240558 8442A554 */  lh        $v0, %lo(gCollisionStatus+0x4)($v0)
/* DDCD8C 8024055C 1443000D */  bne       $v0, $v1, .L80240594
/* DDCD90 80240560 00000000 */   nop
.L80240564:
/* DDCD94 80240564 C7A00120 */  lwc1      $f0, 0x120($sp)
/* DDCD98 80240568 C622FFF8 */  lwc1      $f2, -8($s1)
/* DDCD9C 8024056C 46020001 */  sub.s     $f0, $f0, $f2
/* DDCDA0 80240570 E7C0001C */  swc1      $f0, 0x1c($fp)
/* DDCDA4 80240574 C7A00124 */  lwc1      $f0, 0x124($sp)
/* DDCDA8 80240578 C622FFFC */  lwc1      $f2, -4($s1)
/* DDCDAC 8024057C 46020001 */  sub.s     $f0, $f0, $f2
/* DDCDB0 80240580 E7C00020 */  swc1      $f0, 0x20($fp)
/* DDCDB4 80240584 C7A00128 */  lwc1      $f0, 0x128($sp)
/* DDCDB8 80240588 C6220000 */  lwc1      $f2, ($s1)
/* DDCDBC 8024058C 46020001 */  sub.s     $f0, $f0, $f2
/* DDCDC0 80240590 E7C00024 */  swc1      $f0, 0x24($fp)
.L80240594:
/* DDCDC4 80240594 86C30084 */  lh        $v1, 0x84($s6)
/* DDCDC8 80240598 8E620000 */  lw        $v0, ($s3)
/* DDCDCC 8024059C 14620013 */  bne       $v1, $v0, .L802405EC
/* DDCDD0 802405A0 26730004 */   addiu    $s3, $s3, 4
/* DDCDD4 802405A4 C7A20120 */  lwc1      $f2, 0x120($sp)
/* DDCDD8 802405A8 C620FFF8 */  lwc1      $f0, -8($s1)
/* DDCDDC 802405AC 46001081 */  sub.s     $f2, $f2, $f0
/* DDCDE0 802405B0 C6C00038 */  lwc1      $f0, 0x38($s6)
/* DDCDE4 802405B4 46020000 */  add.s     $f0, $f0, $f2
/* DDCDE8 802405B8 E6C00038 */  swc1      $f0, 0x38($s6)
/* DDCDEC 802405BC C7A20124 */  lwc1      $f2, 0x124($sp)
/* DDCDF0 802405C0 C620FFFC */  lwc1      $f0, -4($s1)
/* DDCDF4 802405C4 46001081 */  sub.s     $f2, $f2, $f0
/* DDCDF8 802405C8 C6C0003C */  lwc1      $f0, 0x3c($s6)
/* DDCDFC 802405CC 46020000 */  add.s     $f0, $f0, $f2
/* DDCE00 802405D0 E6C0003C */  swc1      $f0, 0x3c($s6)
/* DDCE04 802405D4 C7A20128 */  lwc1      $f2, 0x128($sp)
/* DDCE08 802405D8 C6200000 */  lwc1      $f0, ($s1)
/* DDCE0C 802405DC 46001081 */  sub.s     $f2, $f2, $f0
/* DDCE10 802405E0 C6C00040 */  lwc1      $f0, 0x40($s6)
/* DDCE14 802405E4 46020000 */  add.s     $f0, $f0, $f2
/* DDCE18 802405E8 E6C00040 */  swc1      $f0, 0x40($s6)
.L802405EC:
/* DDCE1C 802405EC 26520058 */  addiu     $s2, $s2, 0x58
/* DDCE20 802405F0 8FA90134 */  lw        $t1, 0x134($sp)
/* DDCE24 802405F4 C7A00120 */  lwc1      $f0, 0x120($sp)
/* DDCE28 802405F8 C7A20124 */  lwc1      $f2, 0x124($sp)
/* DDCE2C 802405FC C7A40128 */  lwc1      $f4, 0x128($sp)
/* DDCE30 80240600 25290004 */  addiu     $t1, $t1, 4
/* DDCE34 80240604 AFA90134 */  sw        $t1, 0x134($sp)
/* DDCE38 80240608 E620FFF8 */  swc1      $f0, -8($s1)
/* DDCE3C 8024060C E622FFFC */  swc1      $f2, -4($s1)
/* DDCE40 80240610 E6240000 */  swc1      $f4, ($s1)
/* DDCE44 80240614 3C098024 */  lui       $t1, %hi(D_80241778_DDDFA8)
/* DDCE48 80240618 25291778 */  addiu     $t1, $t1, %lo(D_80241778_DDDFA8)
/* DDCE4C 8024061C 25220018 */  addiu     $v0, $t1, 0x18
/* DDCE50 80240620 0262102B */  sltu      $v0, $s3, $v0
/* DDCE54 80240624 1440FF68 */  bnez      $v0, .L802403C8
/* DDCE58 80240628 26310058 */   addiu    $s1, $s1, 0x58
/* DDCE5C 8024062C 8FA90170 */  lw        $t1, 0x170($sp)
/* DDCE60 80240630 4480A000 */  mtc1      $zero, $f20
/* DDCE64 80240634 3C013F80 */  lui       $at, 0x3f80
/* DDCE68 80240638 4481B000 */  mtc1      $at, $f22
/* DDCE6C 8024063C C5200074 */  lwc1      $f0, 0x74($t1)
/* DDCE70 80240640 46800020 */  cvt.s.w   $f0, $f0
/* DDCE74 80240644 44050000 */  mfc1      $a1, $f0
/* DDCE78 80240648 4406A000 */  mfc1      $a2, $f20
/* DDCE7C 8024064C 4407A000 */  mfc1      $a3, $f20
/* DDCE80 80240650 26E40058 */  addiu     $a0, $s7, 0x58
/* DDCE84 80240654 0C019EC8 */  jal       guRotateF
/* DDCE88 80240658 E7B60010 */   swc1     $f22, 0x10($sp)
/* DDCE8C 8024065C 96E20000 */  lhu       $v0, ($s7)
/* DDCE90 80240660 24040032 */  addiu     $a0, $zero, 0x32
/* DDCE94 80240664 34421400 */  ori       $v0, $v0, 0x1400
/* DDCE98 80240668 0C016E89 */  jal       update_collider_transform
/* DDCE9C 8024066C A6E20000 */   sh       $v0, ($s7)
/* DDCEA0 80240670 8FA90170 */  lw        $t1, 0x170($sp)
/* DDCEA4 80240674 4406A000 */  mfc1      $a2, $f20
/* DDCEA8 80240678 C5200074 */  lwc1      $f0, 0x74($t1)
/* DDCEAC 8024067C 46800020 */  cvt.s.w   $f0, $f0
/* DDCEB0 80240680 44050000 */  mfc1      $a1, $f0
/* DDCEB4 80240684 8FA9012C */  lw        $t1, 0x12c($sp)
/* DDCEB8 80240688 00C0382D */  daddu     $a3, $a2, $zero
/* DDCEBC 8024068C E7B60010 */  swc1      $f22, 0x10($sp)
/* DDCEC0 80240690 0C019EC8 */  jal       guRotateF
/* DDCEC4 80240694 25240058 */   addiu    $a0, $t1, 0x58
/* DDCEC8 80240698 8FA9012C */  lw        $t1, 0x12c($sp)
/* DDCECC 8024069C 0000982D */  daddu     $s3, $zero, $zero
/* DDCED0 802406A0 95220000 */  lhu       $v0, ($t1)
/* DDCED4 802406A4 24040027 */  addiu     $a0, $zero, 0x27
/* DDCED8 802406A8 34421400 */  ori       $v0, $v0, 0x1400
/* DDCEDC 802406AC 0C016E89 */  jal       update_collider_transform
/* DDCEE0 802406B0 A5220000 */   sh       $v0, ($t1)
/* DDCEE4 802406B4 0260202D */  daddu     $a0, $s3, $zero
/* DDCEE8 802406B8 3C05800B */  lui       $a1, %hi(gCameras)
/* DDCEEC 802406BC 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* DDCEF0 802406C0 2408000E */  addiu     $t0, $zero, 0xe
/* DDCEF4 802406C4 24070010 */  addiu     $a3, $zero, 0x10
/* DDCEF8 802406C8 3C038024 */  lui       $v1, %hi(D_80241778_DDDFA8)
/* DDCEFC 802406CC 24631778 */  addiu     $v1, $v1, %lo(D_80241778_DDDFA8)
/* DDCF00 802406D0 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* DDCF04 802406D4 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
.L802406D8:
/* DDCF08 802406D8 8C620000 */  lw        $v0, ($v1)
/* DDCF0C 802406DC 54C20012 */  bnel      $a2, $v0, .L80240728
/* DDCF10 802406E0 26730001 */   addiu    $s3, $s3, 1
/* DDCF14 802406E4 8FC20000 */  lw        $v0, ($fp)
/* DDCF18 802406E8 30421000 */  andi      $v0, $v0, 0x1000
/* DDCF1C 802406EC 10400007 */  beqz      $v0, .L8024070C
/* DDCF20 802406F0 00000000 */   nop
/* DDCF24 802406F4 C7C00028 */  lwc1      $f0, 0x28($fp)
/* DDCF28 802406F8 C7C2002C */  lwc1      $f2, 0x2c($fp)
/* DDCF2C 802406FC C7C40030 */  lwc1      $f4, 0x30($fp)
/* DDCF30 80240700 E4A00060 */  swc1      $f0, 0x60($a1)
/* DDCF34 80240704 E4A20064 */  swc1      $f2, 0x64($a1)
/* DDCF38 80240708 E4A40068 */  swc1      $f4, 0x68($a1)
.L8024070C:
/* DDCF3C 8024070C 83C200B4 */  lb        $v0, 0xb4($fp)
/* DDCF40 80240710 50480004 */  beql      $v0, $t0, .L80240724
/* DDCF44 80240714 24040001 */   addiu    $a0, $zero, 1
/* DDCF48 80240718 54470003 */  bnel      $v0, $a3, .L80240728
/* DDCF4C 8024071C 26730001 */   addiu    $s3, $s3, 1
/* DDCF50 80240720 24040001 */  addiu     $a0, $zero, 1
.L80240724:
/* DDCF54 80240724 26730001 */  addiu     $s3, $s3, 1
.L80240728:
/* DDCF58 80240728 2E620006 */  sltiu     $v0, $s3, 6
/* DDCF5C 8024072C 1440FFEA */  bnez      $v0, .L802406D8
/* DDCF60 80240730 24630004 */   addiu    $v1, $v1, 4
/* DDCF64 80240734 14800005 */  bnez      $a0, .L8024074C
/* DDCF68 80240738 00000000 */   nop
/* DDCF6C 8024073C 8FA90170 */  lw        $t1, 0x170($sp)
/* DDCF70 80240740 8D220074 */  lw        $v0, 0x74($t1)
/* DDCF74 80240744 2442FFFF */  addiu     $v0, $v0, -1
/* DDCF78 80240748 AD220074 */  sw        $v0, 0x74($t1)
.L8024074C:
/* DDCF7C 8024074C 8FBF015C */  lw        $ra, 0x15c($sp)
/* DDCF80 80240750 8FBE0158 */  lw        $fp, 0x158($sp)
/* DDCF84 80240754 8FB70154 */  lw        $s7, 0x154($sp)
/* DDCF88 80240758 8FB60150 */  lw        $s6, 0x150($sp)
/* DDCF8C 8024075C 8FB5014C */  lw        $s5, 0x14c($sp)
/* DDCF90 80240760 8FB40148 */  lw        $s4, 0x148($sp)
/* DDCF94 80240764 8FB30144 */  lw        $s3, 0x144($sp)
/* DDCF98 80240768 8FB20140 */  lw        $s2, 0x140($sp)
/* DDCF9C 8024076C 8FB1013C */  lw        $s1, 0x13c($sp)
/* DDCFA0 80240770 8FB00138 */  lw        $s0, 0x138($sp)
/* DDCFA4 80240774 D7B60168 */  ldc1      $f22, 0x168($sp)
/* DDCFA8 80240778 D7B40160 */  ldc1      $f20, 0x160($sp)
/* DDCFAC 8024077C 0000102D */  daddu     $v0, $zero, $zero
/* DDCFB0 80240780 03E00008 */  jr        $ra
/* DDCFB4 80240784 27BD0170 */   addiu    $sp, $sp, 0x170
/* DDCFB8 80240788 00000000 */  nop
/* DDCFBC 8024078C 00000000 */  nop
