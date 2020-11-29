.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240238_DBD4E8
/* DBD4E8 80240238 27BDFF98 */  addiu     $sp, $sp, -0x68
/* DBD4EC 8024023C AFB30054 */  sw        $s3, 0x54($sp)
/* DBD4F0 80240240 0080982D */  daddu     $s3, $a0, $zero
/* DBD4F4 80240244 AFBF0060 */  sw        $ra, 0x60($sp)
/* DBD4F8 80240248 AFB5005C */  sw        $s5, 0x5c($sp)
/* DBD4FC 8024024C AFB40058 */  sw        $s4, 0x58($sp)
/* DBD500 80240250 AFB20050 */  sw        $s2, 0x50($sp)
/* DBD504 80240254 AFB1004C */  sw        $s1, 0x4c($sp)
/* DBD508 80240258 AFB00048 */  sw        $s0, 0x48($sp)
/* DBD50C 8024025C 8E710148 */  lw        $s1, 0x148($s3)
/* DBD510 80240260 86240008 */  lh        $a0, 8($s1)
/* DBD514 80240264 0C00EABB */  jal       get_npc_unsafe
/* DBD518 80240268 00A0802D */   daddu    $s0, $a1, $zero
/* DBD51C 8024026C 8E63000C */  lw        $v1, 0xc($s3)
/* DBD520 80240270 0260202D */  daddu     $a0, $s3, $zero
/* DBD524 80240274 8C650000 */  lw        $a1, ($v1)
/* DBD528 80240278 0C0B1EAF */  jal       get_variable
/* DBD52C 8024027C 0040902D */   daddu    $s2, $v0, $zero
/* DBD530 80240280 AFA00018 */  sw        $zero, 0x18($sp)
/* DBD534 80240284 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBD538 80240288 8C630030 */  lw        $v1, 0x30($v1)
/* DBD53C 8024028C AFA3001C */  sw        $v1, 0x1c($sp)
/* DBD540 80240290 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBD544 80240294 8C63001C */  lw        $v1, 0x1c($v1)
/* DBD548 80240298 AFA30020 */  sw        $v1, 0x20($sp)
/* DBD54C 8024029C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBD550 802402A0 8C630024 */  lw        $v1, 0x24($v1)
/* DBD554 802402A4 AFA30024 */  sw        $v1, 0x24($sp)
/* DBD558 802402A8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBD55C 802402AC 8C630028 */  lw        $v1, 0x28($v1)
/* DBD560 802402B0 27B50018 */  addiu     $s5, $sp, 0x18
/* DBD564 802402B4 AFA30028 */  sw        $v1, 0x28($sp)
/* DBD568 802402B8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBD56C 802402BC 3C014282 */  lui       $at, 0x4282
/* DBD570 802402C0 44810000 */  mtc1      $at, $f0
/* DBD574 802402C4 8C63002C */  lw        $v1, 0x2c($v1)
/* DBD578 802402C8 0040A02D */  daddu     $s4, $v0, $zero
/* DBD57C 802402CC E7A00030 */  swc1      $f0, 0x30($sp)
/* DBD580 802402D0 A7A00034 */  sh        $zero, 0x34($sp)
/* DBD584 802402D4 16000005 */  bnez      $s0, .L802402EC
/* DBD588 802402D8 AFA3002C */   sw       $v1, 0x2c($sp)
/* DBD58C 802402DC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DBD590 802402E0 30420004 */  andi      $v0, $v0, 4
/* DBD594 802402E4 10400044 */  beqz      $v0, .L802403F8
/* DBD598 802402E8 00000000 */   nop      
.L802402EC:
/* DBD59C 802402EC 2404F7FF */  addiu     $a0, $zero, -0x801
/* DBD5A0 802402F0 AE600070 */  sw        $zero, 0x70($s3)
/* DBD5A4 802402F4 A640008E */  sh        $zero, 0x8e($s2)
/* DBD5A8 802402F8 8E2200CC */  lw        $v0, 0xcc($s1)
/* DBD5AC 802402FC 8E430000 */  lw        $v1, ($s2)
/* DBD5B0 80240300 8C420000 */  lw        $v0, ($v0)
/* DBD5B4 80240304 00641824 */  and       $v1, $v1, $a0
/* DBD5B8 80240308 AE430000 */  sw        $v1, ($s2)
/* DBD5BC 8024030C AE420028 */  sw        $v0, 0x28($s2)
/* DBD5C0 80240310 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DBD5C4 80240314 8C420034 */  lw        $v0, 0x34($v0)
/* DBD5C8 80240318 54400005 */  bnel      $v0, $zero, .L80240330
/* DBD5CC 8024031C 2402FDFF */   addiu    $v0, $zero, -0x201
/* DBD5D0 80240320 34620200 */  ori       $v0, $v1, 0x200
/* DBD5D4 80240324 2403FFF7 */  addiu     $v1, $zero, -9
/* DBD5D8 80240328 080900CE */  j         .L80240338
/* DBD5DC 8024032C 00431024 */   and      $v0, $v0, $v1
.L80240330:
/* DBD5E0 80240330 00621024 */  and       $v0, $v1, $v0
/* DBD5E4 80240334 34420008 */  ori       $v0, $v0, 8
.L80240338:
/* DBD5E8 80240338 AE420000 */  sw        $v0, ($s2)
/* DBD5EC 8024033C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DBD5F0 80240340 30420004 */  andi      $v0, $v0, 4
/* DBD5F4 80240344 10400004 */  beqz      $v0, .L80240358
/* DBD5F8 80240348 24020063 */   addiu    $v0, $zero, 0x63
/* DBD5FC 8024034C AE620070 */  sw        $v0, 0x70($s3)
/* DBD600 80240350 080900DC */  j         .L80240370
/* DBD604 80240354 AE600074 */   sw       $zero, 0x74($s3)
.L80240358:
/* DBD608 80240358 8E220000 */  lw        $v0, ($s1)
/* DBD60C 8024035C 3C034000 */  lui       $v1, 0x4000
/* DBD610 80240360 00431024 */  and       $v0, $v0, $v1
/* DBD614 80240364 10400002 */  beqz      $v0, .L80240370
/* DBD618 80240368 2402000C */   addiu    $v0, $zero, 0xc
/* DBD61C 8024036C AE620070 */  sw        $v0, 0x70($s3)
.L80240370:
/* DBD620 80240370 3C06BFFF */  lui       $a2, 0xbfff
/* DBD624 80240374 34C6FFFF */  ori       $a2, $a2, 0xffff
/* DBD628 80240378 27A50038 */  addiu     $a1, $sp, 0x38
/* DBD62C 8024037C 2404FFFB */  addiu     $a0, $zero, -5
/* DBD630 80240380 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DBD634 80240384 8E230000 */  lw        $v1, ($s1)
/* DBD638 80240388 3C0142C8 */  lui       $at, 0x42c8
/* DBD63C 8024038C 44810000 */  mtc1      $at, $f0
/* DBD640 80240390 00441024 */  and       $v0, $v0, $a0
/* DBD644 80240394 00661824 */  and       $v1, $v1, $a2
/* DBD648 80240398 AE2200B0 */  sw        $v0, 0xb0($s1)
/* DBD64C 8024039C AE230000 */  sw        $v1, ($s1)
/* DBD650 802403A0 864200A8 */  lh        $v0, 0xa8($s2)
/* DBD654 802403A4 27A70040 */  addiu     $a3, $sp, 0x40
/* DBD658 802403A8 E7A00044 */  swc1      $f0, 0x44($sp)
/* DBD65C 802403AC C6460038 */  lwc1      $f6, 0x38($s2)
/* DBD660 802403B0 C640003C */  lwc1      $f0, 0x3c($s2)
/* DBD664 802403B4 C6420040 */  lwc1      $f2, 0x40($s2)
/* DBD668 802403B8 44822000 */  mtc1      $v0, $f4
/* DBD66C 802403BC 00000000 */  nop       
/* DBD670 802403C0 46802120 */  cvt.s.w   $f4, $f4
/* DBD674 802403C4 27A20044 */  addiu     $v0, $sp, 0x44
/* DBD678 802403C8 46040000 */  add.s     $f0, $f0, $f4
/* DBD67C 802403CC E7A60038 */  swc1      $f6, 0x38($sp)
/* DBD680 802403D0 E7A20040 */  swc1      $f2, 0x40($sp)
/* DBD684 802403D4 E7A0003C */  swc1      $f0, 0x3c($sp)
/* DBD688 802403D8 AFA20010 */  sw        $v0, 0x10($sp)
/* DBD68C 802403DC 8E440080 */  lw        $a0, 0x80($s2)
/* DBD690 802403E0 0C0372DF */  jal       func_800DCB7C
/* DBD694 802403E4 27A6003C */   addiu    $a2, $sp, 0x3c
/* DBD698 802403E8 10400003 */  beqz      $v0, .L802403F8
/* DBD69C 802403EC 00000000 */   nop      
/* DBD6A0 802403F0 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* DBD6A4 802403F4 E640003C */  swc1      $f0, 0x3c($s2)
.L802403F8:
/* DBD6A8 802403F8 8E630070 */  lw        $v1, 0x70($s3)
/* DBD6AC 802403FC 2C620064 */  sltiu     $v0, $v1, 0x64
/* DBD6B0 80240400 10400050 */  beqz      $v0, .L80240544
/* DBD6B4 80240404 00031080 */   sll      $v0, $v1, 2
/* DBD6B8 80240408 3C018024 */  lui       $at, %hi(D_80246BE0)
/* DBD6BC 8024040C 00220821 */  addu      $at, $at, $v0
/* DBD6C0 80240410 8C226BE0 */  lw        $v0, %lo(D_80246BE0)($at)
/* DBD6C4 80240414 00400008 */  jr        $v0
/* DBD6C8 80240418 00000000 */   nop      
/* DBD6CC 8024041C 0260202D */  daddu     $a0, $s3, $zero
/* DBD6D0 80240420 0280282D */  daddu     $a1, $s4, $zero
/* DBD6D4 80240424 0C012568 */  jal       func_800495A0
/* DBD6D8 80240428 02A0302D */   daddu    $a2, $s5, $zero
/* DBD6DC 8024042C 0260202D */  daddu     $a0, $s3, $zero
/* DBD6E0 80240430 0280282D */  daddu     $a1, $s4, $zero
/* DBD6E4 80240434 0C0125AE */  jal       func_800496B8
/* DBD6E8 80240438 02A0302D */   daddu    $a2, $s5, $zero
/* DBD6EC 8024043C 08090151 */  j         .L80240544
/* DBD6F0 80240440 00000000 */   nop      
/* DBD6F4 80240444 0260202D */  daddu     $a0, $s3, $zero
/* DBD6F8 80240448 0280282D */  daddu     $a1, $s4, $zero
/* DBD6FC 8024044C 0C0126D1 */  jal       func_80049B44
/* DBD700 80240450 02A0302D */   daddu    $a2, $s5, $zero
/* DBD704 80240454 0260202D */  daddu     $a0, $s3, $zero
/* DBD708 80240458 0280282D */  daddu     $a1, $s4, $zero
/* DBD70C 8024045C 0C012701 */  jal       func_80049C04
/* DBD710 80240460 02A0302D */   daddu    $a2, $s5, $zero
/* DBD714 80240464 08090151 */  j         .L80240544
/* DBD718 80240468 00000000 */   nop      
/* DBD71C 8024046C 0260202D */  daddu     $a0, $s3, $zero
/* DBD720 80240470 0280282D */  daddu     $a1, $s4, $zero
/* DBD724 80240474 0C01278F */  jal       func_80049E3C
/* DBD728 80240478 02A0302D */   daddu    $a2, $s5, $zero
/* DBD72C 8024047C 0260202D */  daddu     $a0, $s3, $zero
/* DBD730 80240480 0280282D */  daddu     $a1, $s4, $zero
/* DBD734 80240484 0C0127B3 */  jal       func_80049ECC
/* DBD738 80240488 02A0302D */   daddu    $a2, $s5, $zero
/* DBD73C 8024048C 08090151 */  j         .L80240544
/* DBD740 80240490 00000000 */   nop      
/* DBD744 80240494 0260202D */  daddu     $a0, $s3, $zero
/* DBD748 80240498 0280282D */  daddu     $a1, $s4, $zero
/* DBD74C 8024049C 0C0127DF */  jal       func_80049F7C
/* DBD750 802404A0 02A0302D */   daddu    $a2, $s5, $zero
/* DBD754 802404A4 0260202D */  daddu     $a0, $s3, $zero
/* DBD758 802404A8 0280282D */  daddu     $a1, $s4, $zero
/* DBD75C 802404AC 0C012849 */  jal       func_8004A124
/* DBD760 802404B0 02A0302D */   daddu    $a2, $s5, $zero
/* DBD764 802404B4 8E630070 */  lw        $v1, 0x70($s3)
/* DBD768 802404B8 2402000E */  addiu     $v0, $zero, 0xe
/* DBD76C 802404BC 14620021 */  bne       $v1, $v0, .L80240544
/* DBD770 802404C0 00000000 */   nop      
/* DBD774 802404C4 0260202D */  daddu     $a0, $s3, $zero
/* DBD778 802404C8 0280282D */  daddu     $a1, $s4, $zero
/* DBD77C 802404CC 0C090000 */  jal       func_80240000_DBD2B0
/* DBD780 802404D0 02A0302D */   daddu    $a2, $s5, $zero
/* DBD784 802404D4 8E630070 */  lw        $v1, 0x70($s3)
/* DBD788 802404D8 2402000F */  addiu     $v0, $zero, 0xf
/* DBD78C 802404DC 14620019 */  bne       $v1, $v0, .L80240544
/* DBD790 802404E0 00000000 */   nop      
/* DBD794 802404E4 0260202D */  daddu     $a0, $s3, $zero
/* DBD798 802404E8 0280282D */  daddu     $a1, $s4, $zero
/* DBD79C 802404EC 0C09001C */  jal       func_80240070_DBD320
/* DBD7A0 802404F0 02A0302D */   daddu    $a2, $s5, $zero
/* DBD7A4 802404F4 8E630070 */  lw        $v1, 0x70($s3)
/* DBD7A8 802404F8 24020010 */  addiu     $v0, $zero, 0x10
/* DBD7AC 802404FC 14620011 */  bne       $v1, $v0, .L80240544
/* DBD7B0 80240500 00000000 */   nop      
/* DBD7B4 80240504 0260202D */  daddu     $a0, $s3, $zero
/* DBD7B8 80240508 0280282D */  daddu     $a1, $s4, $zero
/* DBD7BC 8024050C 0C090050 */  jal       func_80240140_DBD3F0
/* DBD7C0 80240510 02A0302D */   daddu    $a2, $s5, $zero
/* DBD7C4 80240514 8E630070 */  lw        $v1, 0x70($s3)
/* DBD7C8 80240518 24020011 */  addiu     $v0, $zero, 0x11
/* DBD7CC 8024051C 14620009 */  bne       $v1, $v0, .L80240544
/* DBD7D0 80240520 00000000 */   nop      
/* DBD7D4 80240524 0260202D */  daddu     $a0, $s3, $zero
/* DBD7D8 80240528 0280282D */  daddu     $a1, $s4, $zero
/* DBD7DC 8024052C 0C090076 */  jal       func_802401D8_DBD488
/* DBD7E0 80240530 02A0302D */   daddu    $a2, $s5, $zero
/* DBD7E4 80240534 08090151 */  j         .L80240544
/* DBD7E8 80240538 00000000 */   nop      
/* DBD7EC 8024053C 0C0129CF */  jal       func_8004A73C
/* DBD7F0 80240540 0260202D */   daddu    $a0, $s3, $zero
.L80240544:
/* DBD7F4 80240544 8FBF0060 */  lw        $ra, 0x60($sp)
/* DBD7F8 80240548 8FB5005C */  lw        $s5, 0x5c($sp)
/* DBD7FC 8024054C 8FB40058 */  lw        $s4, 0x58($sp)
/* DBD800 80240550 8FB30054 */  lw        $s3, 0x54($sp)
/* DBD804 80240554 8FB20050 */  lw        $s2, 0x50($sp)
/* DBD808 80240558 8FB1004C */  lw        $s1, 0x4c($sp)
/* DBD80C 8024055C 8FB00048 */  lw        $s0, 0x48($sp)
/* DBD810 80240560 0000102D */  daddu     $v0, $zero, $zero
/* DBD814 80240564 03E00008 */  jr        $ra
/* DBD818 80240568 27BD0068 */   addiu    $sp, $sp, 0x68
