.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802B6E08_E25CD8
.word L802B6670_E25540, L802B6670_E25540, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6670_E25540, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6634_E25504, L802B6644_E25514, L802B6654_E25524, L802B6634_E25504, L802B6644_E25514, L802B6654_E25524, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6674_E25544, L802B6660_E25530, L802B6674_E25544, L802B6660_E25530, 0, 0

.section .text

glabel func_802B62A4_E25174
/* E25174 802B62A4 27BDFF88 */  addiu     $sp, $sp, -0x78
/* E25178 802B62A8 AFBF0048 */  sw        $ra, 0x48($sp)
/* E2517C 802B62AC AFB30044 */  sw        $s3, 0x44($sp)
/* E25180 802B62B0 AFB20040 */  sw        $s2, 0x40($sp)
/* E25184 802B62B4 AFB1003C */  sw        $s1, 0x3c($sp)
/* E25188 802B62B8 AFB00038 */  sw        $s0, 0x38($sp)
/* E2518C 802B62BC F7BC0070 */  sdc1      $f28, 0x70($sp)
/* E25190 802B62C0 F7BA0068 */  sdc1      $f26, 0x68($sp)
/* E25194 802B62C4 F7B80060 */  sdc1      $f24, 0x60($sp)
/* E25198 802B62C8 F7B60058 */  sdc1      $f22, 0x58($sp)
/* E2519C 802B62CC 0C0394D2 */  jal       func_800E5348
/* E251A0 802B62D0 F7B40050 */   sdc1     $f20, 0x50($sp)
/* E251A4 802B62D4 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* E251A8 802B62D8 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* E251AC 802B62DC 8E4400A4 */  lw        $a0, 0xa4($s2)
/* E251B0 802B62E0 0C0AD800 */  jal       func_802B6000_E24ED0
/* E251B4 802B62E4 46000586 */   mov.s    $f22, $f0
/* E251B8 802B62E8 10400030 */  beqz      $v0, .L802B63AC
/* E251BC 802B62EC 27A50020 */   addiu    $a1, $sp, 0x20
/* E251C0 802B62F0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E251C4 802B62F4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E251C8 802B62F8 3C0142B4 */  lui       $at, 0x42b4
/* E251CC 802B62FC 4481A000 */  mtc1      $at, $f20
/* E251D0 802B6300 00031080 */  sll       $v0, $v1, 2
/* E251D4 802B6304 00431021 */  addu      $v0, $v0, $v1
/* E251D8 802B6308 00021080 */  sll       $v0, $v0, 2
/* E251DC 802B630C 00431023 */  subu      $v0, $v0, $v1
/* E251E0 802B6310 000218C0 */  sll       $v1, $v0, 3
/* E251E4 802B6314 00431021 */  addu      $v0, $v0, $v1
/* E251E8 802B6318 000210C0 */  sll       $v0, $v0, 3
/* E251EC 802B631C 4614B000 */  add.s     $f0, $f22, $f20
/* E251F0 802B6320 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* E251F4 802B6324 00220821 */  addu      $at, $at, $v0
/* E251F8 802B6328 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* E251FC 802B632C 0C00A6C9 */  jal       clamp_angle
/* E25200 802B6330 460C0301 */   sub.s    $f12, $f0, $f12
/* E25204 802B6334 46000086 */  mov.s     $f2, $f0
/* E25208 802B6338 4602A03E */  c.le.s    $f20, $f2
/* E2520C 802B633C 00000000 */  nop
/* E25210 802B6340 45000015 */  bc1f      .L802B6398
/* E25214 802B6344 00000000 */   nop
/* E25218 802B6348 3C014387 */  lui       $at, 0x4387
/* E2521C 802B634C 44810000 */  mtc1      $at, $f0
/* E25220 802B6350 00000000 */  nop
/* E25224 802B6354 4600103C */  c.lt.s    $f2, $f0
/* E25228 802B6358 00000000 */  nop
/* E2522C 802B635C 4500000E */  bc1f      .L802B6398
/* E25230 802B6360 00000000 */   nop
/* E25234 802B6364 3C01C1F0 */  lui       $at, 0xc1f0
/* E25238 802B6368 44810000 */  mtc1      $at, $f0
/* E2523C 802B636C 080AD8EA */  j         .L802B63A8
/* E25240 802B6370 4600B580 */   add.s    $f22, $f22, $f0
.L802B6374:
/* E25244 802B6374 3C02802B */  lui       $v0, %hi(D_802B6DB0_E25C80)
/* E25248 802B6378 8C426DB0 */  lw        $v0, %lo(D_802B6DB0_E25C80)($v0)
/* E2524C 802B637C C7A00028 */  lwc1      $f0, 0x28($sp)
/* E25250 802B6380 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* E25254 802B6384 C7A40030 */  lwc1      $f4, 0x30($sp)
/* E25258 802B6388 E4400000 */  swc1      $f0, ($v0)
/* E2525C 802B638C E4420004 */  swc1      $f2, 4($v0)
/* E25260 802B6390 080AD919 */  j         .L802B6464
/* E25264 802B6394 E4440008 */   swc1     $f4, 8($v0)
.L802B6398:
/* E25268 802B6398 3C0141F0 */  lui       $at, 0x41f0
/* E2526C 802B639C 44810000 */  mtc1      $at, $f0
/* E25270 802B63A0 00000000 */  nop
/* E25274 802B63A4 4600B580 */  add.s     $f22, $f22, $f0
.L802B63A8:
/* E25278 802B63A8 27A50020 */  addiu     $a1, $sp, 0x20
.L802B63AC:
/* E2527C 802B63AC 3C0140C9 */  lui       $at, 0x40c9
/* E25280 802B63B0 34210FD0 */  ori       $at, $at, 0xfd0
/* E25284 802B63B4 44816000 */  mtc1      $at, $f12
/* E25288 802B63B8 27A60024 */  addiu     $a2, $sp, 0x24
/* E2528C 802B63BC 460CB302 */  mul.s     $f12, $f22, $f12
/* E25290 802B63C0 00000000 */  nop
/* E25294 802B63C4 24100001 */  addiu     $s0, $zero, 1
/* E25298 802B63C8 27B30030 */  addiu     $s3, $sp, 0x30
/* E2529C 802B63CC 3C0143B4 */  lui       $at, 0x43b4
/* E252A0 802B63D0 44810000 */  mtc1      $at, $f0
/* E252A4 802B63D4 3C014080 */  lui       $at, 0x4080
/* E252A8 802B63D8 4481A000 */  mtc1      $at, $f20
/* E252AC 802B63DC 0C00A82D */  jal       sin_cos_rad
/* E252B0 802B63E0 46006303 */   div.s    $f12, $f12, $f0
/* E252B4 802B63E4 C65C0028 */  lwc1      $f28, 0x28($s2)
/* E252B8 802B63E8 C65A002C */  lwc1      $f26, 0x2c($s2)
/* E252BC 802B63EC C6580030 */  lwc1      $f24, 0x30($s2)
.L802B63F0:
/* E252C0 802B63F0 C7A00020 */  lwc1      $f0, 0x20($sp)
/* E252C4 802B63F4 44901000 */  mtc1      $s0, $f2
/* E252C8 802B63F8 00000000 */  nop
/* E252CC 802B63FC 468010A0 */  cvt.s.w   $f2, $f2
/* E252D0 802B6400 46020002 */  mul.s     $f0, $f0, $f2
/* E252D4 802B6404 00000000 */  nop
/* E252D8 802B6408 C7A40024 */  lwc1      $f4, 0x24($sp)
/* E252DC 802B640C 46022102 */  mul.s     $f4, $f4, $f2
/* E252E0 802B6410 00000000 */  nop
/* E252E4 802B6414 24040003 */  addiu     $a0, $zero, 3
/* E252E8 802B6418 0240282D */  daddu     $a1, $s2, $zero
/* E252EC 802B641C 4600E000 */  add.s     $f0, $f28, $f0
/* E252F0 802B6420 27A60028 */  addiu     $a2, $sp, 0x28
/* E252F4 802B6424 27A7002C */  addiu     $a3, $sp, 0x2c
/* E252F8 802B6428 4604C101 */  sub.s     $f4, $f24, $f4
/* E252FC 802B642C E7BA002C */  swc1      $f26, 0x2c($sp)
/* E25300 802B6430 E7A00028 */  swc1      $f0, 0x28($sp)
/* E25304 802B6434 E7A40030 */  swc1      $f4, 0x30($sp)
/* E25308 802B6438 AFB30010 */  sw        $s3, 0x10($sp)
/* E2530C 802B643C E7B40014 */  swc1      $f20, 0x14($sp)
/* E25310 802B6440 0C037B01 */  jal       player_test_lateral_overlap
/* E25314 802B6444 E7B60018 */   swc1     $f22, 0x18($sp)
/* E25318 802B6448 0040882D */  daddu     $s1, $v0, $zero
/* E2531C 802B644C 0621FFC9 */  bgez      $s1, .L802B6374
/* E25320 802B6450 00000000 */   nop
/* E25324 802B6454 26100001 */  addiu     $s0, $s0, 1
/* E25328 802B6458 2A020010 */  slti      $v0, $s0, 0x10
/* E2532C 802B645C 1440FFE4 */  bnez      $v0, .L802B63F0
/* E25330 802B6460 00000000 */   nop
.L802B6464:
/* E25334 802B6464 2A020010 */  slti      $v0, $s0, 0x10
/* E25338 802B6468 14400061 */  bnez      $v0, .L802B65F0
/* E2533C 802B646C 00000000 */   nop
/* E25340 802B6470 0C0394D2 */  jal       func_800E5348
/* E25344 802B6474 00000000 */   nop
/* E25348 802B6478 8E4400A4 */  lw        $a0, 0xa4($s2)
/* E2534C 802B647C 0C0AD800 */  jal       func_802B6000_E24ED0
/* E25350 802B6480 46000586 */   mov.s    $f22, $f0
/* E25354 802B6484 14400030 */  bnez      $v0, .L802B6548
/* E25358 802B6488 27A50020 */   addiu    $a1, $sp, 0x20
/* E2535C 802B648C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E25360 802B6490 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E25364 802B6494 3C0142B4 */  lui       $at, 0x42b4
/* E25368 802B6498 4481A000 */  mtc1      $at, $f20
/* E2536C 802B649C 00031080 */  sll       $v0, $v1, 2
/* E25370 802B64A0 00431021 */  addu      $v0, $v0, $v1
/* E25374 802B64A4 00021080 */  sll       $v0, $v0, 2
/* E25378 802B64A8 00431023 */  subu      $v0, $v0, $v1
/* E2537C 802B64AC 000218C0 */  sll       $v1, $v0, 3
/* E25380 802B64B0 00431021 */  addu      $v0, $v0, $v1
/* E25384 802B64B4 000210C0 */  sll       $v0, $v0, 3
/* E25388 802B64B8 4614B000 */  add.s     $f0, $f22, $f20
/* E2538C 802B64BC 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* E25390 802B64C0 00220821 */  addu      $at, $at, $v0
/* E25394 802B64C4 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* E25398 802B64C8 0C00A6C9 */  jal       clamp_angle
/* E2539C 802B64CC 460C0301 */   sub.s    $f12, $f0, $f12
/* E253A0 802B64D0 46000086 */  mov.s     $f2, $f0
/* E253A4 802B64D4 4602A03E */  c.le.s    $f20, $f2
/* E253A8 802B64D8 00000000 */  nop
/* E253AC 802B64DC 45000015 */  bc1f      .L802B6534
/* E253B0 802B64E0 00000000 */   nop
/* E253B4 802B64E4 3C014387 */  lui       $at, 0x4387
/* E253B8 802B64E8 44810000 */  mtc1      $at, $f0
/* E253BC 802B64EC 00000000 */  nop
/* E253C0 802B64F0 4600103C */  c.lt.s    $f2, $f0
/* E253C4 802B64F4 00000000 */  nop
/* E253C8 802B64F8 4500000E */  bc1f      .L802B6534
/* E253CC 802B64FC 00000000 */   nop
/* E253D0 802B6500 3C014170 */  lui       $at, 0x4170
/* E253D4 802B6504 44810000 */  mtc1      $at, $f0
/* E253D8 802B6508 080AD951 */  j         .L802B6544
/* E253DC 802B650C 4600B580 */   add.s    $f22, $f22, $f0
.L802B6510:
/* E253E0 802B6510 3C02802B */  lui       $v0, %hi(D_802B6DB0_E25C80)
/* E253E4 802B6514 8C426DB0 */  lw        $v0, %lo(D_802B6DB0_E25C80)($v0)
/* E253E8 802B6518 C7A00028 */  lwc1      $f0, 0x28($sp)
/* E253EC 802B651C C7A2002C */  lwc1      $f2, 0x2c($sp)
/* E253F0 802B6520 C7A40030 */  lwc1      $f4, 0x30($sp)
/* E253F4 802B6524 E4400000 */  swc1      $f0, ($v0)
/* E253F8 802B6528 E4420004 */  swc1      $f2, 4($v0)
/* E253FC 802B652C 080AD97C */  j         .L802B65F0
/* E25400 802B6530 E4440008 */   swc1     $f4, 8($v0)
.L802B6534:
/* E25404 802B6534 3C01C170 */  lui       $at, 0xc170
/* E25408 802B6538 44810000 */  mtc1      $at, $f0
/* E2540C 802B653C 00000000 */  nop
/* E25410 802B6540 4600B580 */  add.s     $f22, $f22, $f0
.L802B6544:
/* E25414 802B6544 27A50020 */  addiu     $a1, $sp, 0x20
.L802B6548:
/* E25418 802B6548 3C0140C9 */  lui       $at, 0x40c9
/* E2541C 802B654C 34210FD0 */  ori       $at, $at, 0xfd0
/* E25420 802B6550 44816000 */  mtc1      $at, $f12
/* E25424 802B6554 27A60024 */  addiu     $a2, $sp, 0x24
/* E25428 802B6558 460CB302 */  mul.s     $f12, $f22, $f12
/* E2542C 802B655C 00000000 */  nop
/* E25430 802B6560 24100001 */  addiu     $s0, $zero, 1
/* E25434 802B6564 27B30030 */  addiu     $s3, $sp, 0x30
/* E25438 802B6568 3C0143B4 */  lui       $at, 0x43b4
/* E2543C 802B656C 44810000 */  mtc1      $at, $f0
/* E25440 802B6570 3C014080 */  lui       $at, 0x4080
/* E25444 802B6574 4481A000 */  mtc1      $at, $f20
/* E25448 802B6578 0C00A82D */  jal       sin_cos_rad
/* E2544C 802B657C 46006303 */   div.s    $f12, $f12, $f0
.L802B6580:
/* E25450 802B6580 C7A00020 */  lwc1      $f0, 0x20($sp)
/* E25454 802B6584 44901000 */  mtc1      $s0, $f2
/* E25458 802B6588 00000000 */  nop
/* E2545C 802B658C 468010A0 */  cvt.s.w   $f2, $f2
/* E25460 802B6590 46020002 */  mul.s     $f0, $f0, $f2
/* E25464 802B6594 00000000 */  nop
/* E25468 802B6598 C7A40024 */  lwc1      $f4, 0x24($sp)
/* E2546C 802B659C 46022102 */  mul.s     $f4, $f4, $f2
/* E25470 802B65A0 00000000 */  nop
/* E25474 802B65A4 24040003 */  addiu     $a0, $zero, 3
/* E25478 802B65A8 0240282D */  daddu     $a1, $s2, $zero
/* E2547C 802B65AC 4600E000 */  add.s     $f0, $f28, $f0
/* E25480 802B65B0 27A60028 */  addiu     $a2, $sp, 0x28
/* E25484 802B65B4 27A7002C */  addiu     $a3, $sp, 0x2c
/* E25488 802B65B8 4604C101 */  sub.s     $f4, $f24, $f4
/* E2548C 802B65BC E7BA002C */  swc1      $f26, 0x2c($sp)
/* E25490 802B65C0 E7A00028 */  swc1      $f0, 0x28($sp)
/* E25494 802B65C4 E7A40030 */  swc1      $f4, 0x30($sp)
/* E25498 802B65C8 AFB30010 */  sw        $s3, 0x10($sp)
/* E2549C 802B65CC E7B40014 */  swc1      $f20, 0x14($sp)
/* E254A0 802B65D0 0C037B01 */  jal       player_test_lateral_overlap
/* E254A4 802B65D4 E7B60018 */   swc1     $f22, 0x18($sp)
/* E254A8 802B65D8 0040882D */  daddu     $s1, $v0, $zero
/* E254AC 802B65DC 0621FFCC */  bgez      $s1, .L802B6510
/* E254B0 802B65E0 26100001 */   addiu    $s0, $s0, 1
/* E254B4 802B65E4 2A020010 */  slti      $v0, $s0, 0x10
/* E254B8 802B65E8 1440FFE5 */  bnez      $v0, .L802B6580
/* E254BC 802B65EC 00000000 */   nop
.L802B65F0:
/* E254C0 802B65F0 06200020 */  bltz      $s1, L802B6674_E25544
/* E254C4 802B65F4 32224000 */   andi     $v0, $s1, 0x4000
/* E254C8 802B65F8 1040001F */  beqz      $v0, .L802B6678
/* E254CC 802B65FC 0220102D */   daddu    $v0, $s1, $zero
/* E254D0 802B6600 3C108011 */  lui       $s0, %hi(gPlayerData+0x1)
/* E254D4 802B6604 8210F291 */  lb        $s0, %lo(gPlayerData+0x1)($s0)
/* E254D8 802B6608 0C0441A9 */  jal       get_entity_type
/* E254DC 802B660C 0220202D */   daddu    $a0, $s1, $zero
/* E254E0 802B6610 2443FFF9 */  addiu     $v1, $v0, -7
/* E254E4 802B6614 2C620020 */  sltiu     $v0, $v1, 0x20
/* E254E8 802B6618 10400016 */  beqz      $v0, L802B6674_E25544
/* E254EC 802B661C 00031080 */   sll      $v0, $v1, 2
/* E254F0 802B6620 3C01802B */  lui       $at, %hi(jtbl_802B6E08_E25CD8)
/* E254F4 802B6624 00220821 */  addu      $at, $at, $v0
/* E254F8 802B6628 8C226E08 */  lw        $v0, %lo(jtbl_802B6E08_E25CD8)($at)
/* E254FC 802B662C 00400008 */  jr        $v0
/* E25500 802B6630 00000000 */   nop
glabel L802B6634_E25504
/* E25504 802B6634 0603000F */  bgezl     $s0, L802B6674_E25544
/* E25508 802B6638 2411FFFF */   addiu    $s1, $zero, -1
/* E2550C 802B663C 080AD998 */  j         L802B6660_E25530
/* E25510 802B6640 00000000 */   nop
glabel L802B6644_E25514
/* E25514 802B6644 5E00000B */  bgtzl     $s0, L802B6674_E25544
/* E25518 802B6648 2411FFFF */   addiu    $s1, $zero, -1
/* E2551C 802B664C 080AD998 */  j         L802B6660_E25530
/* E25520 802B6650 00000000 */   nop
glabel L802B6654_E25524
/* E25524 802B6654 2A020002 */  slti      $v0, $s0, 2
/* E25528 802B6658 50400006 */  beql      $v0, $zero, L802B6674_E25544
/* E2552C 802B665C 2411FFFF */   addiu    $s1, $zero, -1
glabel L802B6660_E25530
/* E25530 802B6660 8E420004 */  lw        $v0, 4($s2)
/* E25534 802B6664 34420400 */  ori       $v0, $v0, 0x400
/* E25538 802B6668 080AD99D */  j         L802B6674_E25544
/* E2553C 802B666C AE420004 */   sw       $v0, 4($s2)
glabel L802B6670_E25540
/* E25540 802B6670 2411FFFF */  addiu     $s1, $zero, -1
glabel L802B6674_E25544
/* E25544 802B6674 0220102D */  daddu     $v0, $s1, $zero
.L802B6678:
/* E25548 802B6678 8FBF0048 */  lw        $ra, 0x48($sp)
/* E2554C 802B667C 8FB30044 */  lw        $s3, 0x44($sp)
/* E25550 802B6680 8FB20040 */  lw        $s2, 0x40($sp)
/* E25554 802B6684 8FB1003C */  lw        $s1, 0x3c($sp)
/* E25558 802B6688 8FB00038 */  lw        $s0, 0x38($sp)
/* E2555C 802B668C D7BC0070 */  ldc1      $f28, 0x70($sp)
/* E25560 802B6690 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* E25564 802B6694 D7B80060 */  ldc1      $f24, 0x60($sp)
/* E25568 802B6698 D7B60058 */  ldc1      $f22, 0x58($sp)
/* E2556C 802B669C D7B40050 */  ldc1      $f20, 0x50($sp)
/* E25570 802B66A0 03E00008 */  jr        $ra
/* E25574 802B66A4 27BD0078 */   addiu    $sp, $sp, 0x78
