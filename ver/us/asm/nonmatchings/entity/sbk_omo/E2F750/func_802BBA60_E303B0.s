.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802BCB80_E314D0
.double 0.02

glabel D_802BCB88_E314D8
.double -0.02

.section .text

glabel func_802BBA60_E303B0
/* E303B0 802BBA60 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E303B4 802BBA64 AFB10014 */  sw        $s1, 0x14($sp)
/* E303B8 802BBA68 0080882D */  daddu     $s1, $a0, $zero
/* E303BC 802BBA6C AFB20018 */  sw        $s2, 0x18($sp)
/* E303C0 802BBA70 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* E303C4 802BBA74 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* E303C8 802BBA78 AFB3001C */  sw        $s3, 0x1c($sp)
/* E303CC 802BBA7C 3C138011 */  lui       $s3, %hi(gPartnerActionStatus)
/* E303D0 802BBA80 2673EBB0 */  addiu     $s3, $s3, %lo(gPartnerActionStatus)
/* E303D4 802BBA84 AFBF0020 */  sw        $ra, 0x20($sp)
/* E303D8 802BBA88 AFB00010 */  sw        $s0, 0x10($sp)
/* E303DC 802BBA8C 0C009C64 */  jal       get_time_freeze_mode
/* E303E0 802BBA90 8E300040 */   lw       $s0, 0x40($s1)
/* E303E4 802BBA94 14400017 */  bnez      $v0, .L802BBAF4
/* E303E8 802BBA98 00000000 */   nop
/* E303EC 802BBA9C 0C04D07A */  jal       is_picking_up_item
/* E303F0 802BBAA0 00000000 */   nop
/* E303F4 802BBAA4 14400013 */  bnez      $v0, .L802BBAF4
/* E303F8 802BBAA8 00000000 */   nop
/* E303FC 802BBAAC 8E420000 */  lw        $v0, ($s2)
/* E30400 802BBAB0 30420020 */  andi      $v0, $v0, 0x20
/* E30404 802BBAB4 1440000F */  bnez      $v0, .L802BBAF4
/* E30408 802BBAB8 00000000 */   nop
/* E3040C 802BBABC 3C028011 */  lui       $v0, %hi(gPlayerData)
/* E30410 802BBAC0 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* E30414 802BBAC4 80430012 */  lb        $v1, 0x12($v0)
/* E30418 802BBAC8 24020001 */  addiu     $v0, $zero, 1
/* E3041C 802BBACC 14620007 */  bne       $v1, $v0, .L802BBAEC
/* E30420 802BBAD0 00000000 */   nop
/* E30424 802BBAD4 82420015 */  lb        $v0, 0x15($s2)
/* E30428 802BBAD8 10400004 */  beqz      $v0, .L802BBAEC
/* E3042C 802BBADC 2402001F */   addiu    $v0, $zero, 0x1f
/* E30430 802BBAE0 824300B4 */  lb        $v1, 0xb4($s2)
/* E30434 802BBAE4 14620003 */  bne       $v1, $v0, .L802BBAF4
/* E30438 802BBAE8 00000000 */   nop
.L802BBAEC:
/* E3043C 802BBAEC 0C0AEE39 */  jal       func_802BB8E4_E30234
/* E30440 802BBAF0 0220202D */   daddu    $a0, $s1, $zero
.L802BBAF4:
/* E30444 802BBAF4 0C0AEDC1 */  jal       func_802BB704_E30054
/* E30448 802BBAF8 0220202D */   daddu    $a0, $s1, $zero
/* E3044C 802BBAFC 96020098 */  lhu       $v0, 0x98($s0)
/* E30450 802BBB00 24420001 */  addiu     $v0, $v0, 1
/* E30454 802BBB04 A6020098 */  sh        $v0, 0x98($s0)
/* E30458 802BBB08 00021400 */  sll       $v0, $v0, 0x10
/* E3045C 802BBB0C 00021403 */  sra       $v0, $v0, 0x10
/* E30460 802BBB10 28420064 */  slti      $v0, $v0, 0x64
/* E30464 802BBB14 1040001B */  beqz      $v0, .L802BBB84
/* E30468 802BBB18 00000000 */   nop
/* E3046C 802BBB1C 3C014060 */  lui       $at, 0x4060
/* E30470 802BBB20 44813000 */  mtc1      $at, $f6
/* E30474 802BBB24 C6080004 */  lwc1      $f8, 4($s0)
/* E30478 802BBB28 46083081 */  sub.s     $f2, $f6, $f8
/* E3047C 802BBB2C 3C0141E0 */  lui       $at, 0x41e0
/* E30480 802BBB30 44810000 */  mtc1      $at, $f0
/* E30484 802BBB34 00000000 */  nop
/* E30488 802BBB38 46001103 */  div.s     $f4, $f2, $f0
/* E3048C 802BBB3C 3C01802C */  lui       $at, %hi(D_802BCB80_E314D0)
/* E30490 802BBB40 D422CB80 */  ldc1      $f2, %lo(D_802BCB80_E314D0)($at)
/* E30494 802BBB44 46002021 */  cvt.d.s   $f0, $f4
/* E30498 802BBB48 4622003C */  c.lt.d    $f0, $f2
/* E3049C 802BBB4C 00000000 */  nop
/* E304A0 802BBB50 45020006 */  bc1fl     .L802BBB6C
/* E304A4 802BBB54 46044000 */   add.s    $f0, $f8, $f4
/* E304A8 802BBB58 3C013CA3 */  lui       $at, 0x3ca3
/* E304AC 802BBB5C 3421D70A */  ori       $at, $at, 0xd70a
/* E304B0 802BBB60 44812000 */  mtc1      $at, $f4
/* E304B4 802BBB64 00000000 */  nop
/* E304B8 802BBB68 46044000 */  add.s     $f0, $f8, $f4
.L802BBB6C:
/* E304BC 802BBB6C 4600303E */  c.le.s    $f6, $f0
/* E304C0 802BBB70 00000000 */  nop
/* E304C4 802BBB74 4500001F */  bc1f      .L802BBBF4
/* E304C8 802BBB78 E6000004 */   swc1     $f0, 4($s0)
/* E304CC 802BBB7C 080AEEFD */  j         .L802BBBF4
/* E304D0 802BBB80 E6060004 */   swc1     $f6, 4($s0)
.L802BBB84:
/* E304D4 802BBB84 3C013FA6 */  lui       $at, 0x3fa6
/* E304D8 802BBB88 34216666 */  ori       $at, $at, 0x6666
/* E304DC 802BBB8C 44813000 */  mtc1      $at, $f6
/* E304E0 802BBB90 C6080004 */  lwc1      $f8, 4($s0)
/* E304E4 802BBB94 46083081 */  sub.s     $f2, $f6, $f8
/* E304E8 802BBB98 3C013D80 */  lui       $at, 0x3d80
/* E304EC 802BBB9C 44810000 */  mtc1      $at, $f0
/* E304F0 802BBBA0 00000000 */  nop
/* E304F4 802BBBA4 46001102 */  mul.s     $f4, $f2, $f0
/* E304F8 802BBBA8 00000000 */  nop
/* E304FC 802BBBAC 3C01802C */  lui       $at, %hi(D_802BCB88_E314D8)
/* E30500 802BBBB0 D422CB88 */  ldc1      $f2, %lo(D_802BCB88_E314D8)($at)
/* E30504 802BBBB4 46002021 */  cvt.d.s   $f0, $f4
/* E30508 802BBBB8 4620103C */  c.lt.d    $f2, $f0
/* E3050C 802BBBBC 00000000 */  nop
/* E30510 802BBBC0 45020006 */  bc1fl     .L802BBBDC
/* E30514 802BBBC4 46044000 */   add.s    $f0, $f8, $f4
/* E30518 802BBBC8 3C01BCA3 */  lui       $at, 0xbca3
/* E3051C 802BBBCC 3421D70A */  ori       $at, $at, 0xd70a
/* E30520 802BBBD0 44812000 */  mtc1      $at, $f4
/* E30524 802BBBD4 00000000 */  nop
/* E30528 802BBBD8 46044000 */  add.s     $f0, $f8, $f4
.L802BBBDC:
/* E3052C 802BBBDC 4606003E */  c.le.s    $f0, $f6
/* E30530 802BBBE0 00000000 */  nop
/* E30534 802BBBE4 45000003 */  bc1f      .L802BBBF4
/* E30538 802BBBE8 E6000004 */   swc1     $f0, 4($s0)
/* E3053C 802BBBEC E6060004 */  swc1      $f6, 4($s0)
/* E30540 802BBBF0 A6000098 */  sh        $zero, 0x98($s0)
.L802BBBF4:
/* E30544 802BBBF4 C6000008 */  lwc1      $f0, 8($s0)
/* E30548 802BBBF8 C6020004 */  lwc1      $f2, 4($s0)
/* E3054C 802BBBFC 46020000 */  add.s     $f0, $f0, $f2
/* E30550 802BBC00 3C0143B4 */  lui       $at, 0x43b4
/* E30554 802BBC04 44814000 */  mtc1      $at, $f8
/* E30558 802BBC08 00000000 */  nop
/* E3055C 802BBC0C 4600403C */  c.lt.s    $f8, $f0
/* E30560 802BBC10 00000000 */  nop
/* E30564 802BBC14 45000002 */  bc1f      .L802BBC20
/* E30568 802BBC18 E6000008 */   swc1     $f0, 8($s0)
/* E3056C 802BBC1C AE000008 */  sw        $zero, 8($s0)
.L802BBC20:
/* E30570 802BBC20 C6000008 */  lwc1      $f0, 8($s0)
/* E30574 802BBC24 C606000C */  lwc1      $f6, 0xc($s0)
/* E30578 802BBC28 46060101 */  sub.s     $f4, $f0, $f6
/* E3057C 802BBC2C 44805000 */  mtc1      $zero, $f10
/* E30580 802BBC30 00000000 */  nop
/* E30584 802BBC34 460A203C */  c.lt.s    $f4, $f10
/* E30588 802BBC38 00000000 */  nop
/* E3058C 802BBC3C 45030001 */  bc1tl     .L802BBC44
/* E30590 802BBC40 46082100 */   add.s    $f4, $f4, $f8
.L802BBC44:
/* E30594 802BBC44 3C013FD0 */  lui       $at, 0x3fd0
/* E30598 802BBC48 44810800 */  mtc1      $at, $f1
/* E3059C 802BBC4C 44800000 */  mtc1      $zero, $f0
/* E305A0 802BBC50 460020A1 */  cvt.d.s   $f2, $f4
/* E305A4 802BBC54 46201082 */  mul.d     $f2, $f2, $f0
/* E305A8 802BBC58 00000000 */  nop
/* E305AC 802BBC5C 46201120 */  cvt.s.d   $f4, $f2
/* E305B0 802BBC60 46043000 */  add.s     $f0, $f6, $f4
/* E305B4 802BBC64 4600403C */  c.lt.s    $f8, $f0
/* E305B8 802BBC68 00000000 */  nop
/* E305BC 802BBC6C 45000002 */  bc1f      .L802BBC78
/* E305C0 802BBC70 E600000C */   swc1     $f0, 0xc($s0)
/* E305C4 802BBC74 E60A000C */  swc1      $f10, 0xc($s0)
.L802BBC78:
/* E305C8 802BBC78 96020090 */  lhu       $v0, 0x90($s0)
/* E305CC 802BBC7C 96030092 */  lhu       $v1, 0x92($s0)
/* E305D0 802BBC80 24420004 */  addiu     $v0, $v0, 4
/* E305D4 802BBC84 A6020090 */  sh        $v0, 0x90($s0)
/* E305D8 802BBC88 96020094 */  lhu       $v0, 0x94($s0)
/* E305DC 802BBC8C 2463FFF8 */  addiu     $v1, $v1, -8
/* E305E0 802BBC90 A6030092 */  sh        $v1, 0x92($s0)
/* E305E4 802BBC94 96030096 */  lhu       $v1, 0x96($s0)
/* E305E8 802BBC98 24420004 */  addiu     $v0, $v0, 4
/* E305EC 802BBC9C 2463FFF0 */  addiu     $v1, $v1, -0x10
/* E305F0 802BBCA0 A6020094 */  sh        $v0, 0x94($s0)
/* E305F4 802BBCA4 A6030096 */  sh        $v1, 0x96($s0)
/* E305F8 802BBCA8 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* E305FC 802BBCAC C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* E30600 802BBCB0 46000007 */  neg.s     $f0, $f0
/* E30604 802BBCB4 E6200064 */  swc1      $f0, 0x64($s1)
/* E30608 802BBCB8 82620000 */  lb        $v0, ($s3)
/* E3060C 802BBCBC 10400004 */  beqz      $v0, .L802BBCD0
/* E30610 802BBCC0 24020009 */   addiu    $v0, $zero, 9
/* E30614 802BBCC4 82630003 */  lb        $v1, 3($s3)
/* E30618 802BBCC8 10620034 */  beq       $v1, $v0, .L802BBD9C
/* E3061C 802BBCCC 00000000 */   nop
.L802BBCD0:
/* E30620 802BBCD0 824300B4 */  lb        $v1, 0xb4($s2)
/* E30624 802BBCD4 2402001F */  addiu     $v0, $zero, 0x1f
/* E30628 802BBCD8 1462000E */  bne       $v1, $v0, .L802BBD14
/* E3062C 802BBCDC 00000000 */   nop
/* E30630 802BBCE0 C62C0048 */  lwc1      $f12, 0x48($s1)
/* E30634 802BBCE4 C62E004C */  lwc1      $f14, 0x4c($s1)
/* E30638 802BBCE8 8E260050 */  lw        $a2, 0x50($s1)
/* E3063C 802BBCEC 0C00F431 */  jal       npc_find_closest_simple
/* E30640 802BBCF0 3C074248 */   lui      $a3, 0x4248
/* E30644 802BBCF4 10400007 */  beqz      $v0, .L802BBD14
/* E30648 802BBCF8 3C030400 */   lui      $v1, 0x400
/* E3064C 802BBCFC 8C420000 */  lw        $v0, ($v0)
/* E30650 802BBD00 00431024 */  and       $v0, $v0, $v1
/* E30654 802BBD04 10400003 */  beqz      $v0, .L802BBD14
/* E30658 802BBD08 00000000 */   nop
/* E3065C 802BBD0C 3C018011 */  lui       $at, %hi(D_8010C954)
/* E30660 802BBD10 AC31C954 */  sw        $s1, %lo(D_8010C954)($at)
.L802BBD14:
/* E30664 802BBD14 0C04D07A */  jal       is_picking_up_item
/* E30668 802BBD18 00000000 */   nop
/* E3066C 802BBD1C 1440001F */  bnez      $v0, .L802BBD9C
/* E30670 802BBD20 00000000 */   nop
/* E30674 802BBD24 8E420000 */  lw        $v0, ($s2)
/* E30678 802BBD28 30420020 */  andi      $v0, $v0, 0x20
/* E3067C 802BBD2C 1440001B */  bnez      $v0, .L802BBD9C
/* E30680 802BBD30 2402001F */   addiu    $v0, $zero, 0x1f
/* E30684 802BBD34 824300B4 */  lb        $v1, 0xb4($s2)
/* E30688 802BBD38 10620018 */  beq       $v1, $v0, .L802BBD9C
/* E3068C 802BBD3C 00000000 */   nop
/* E30690 802BBD40 86420010 */  lh        $v0, 0x10($s2)
/* E30694 802BBD44 14400015 */  bnez      $v0, .L802BBD9C
/* E30698 802BBD48 00000000 */   nop
/* E3069C 802BBD4C C62C0048 */  lwc1      $f12, 0x48($s1)
/* E306A0 802BBD50 C62E0050 */  lwc1      $f14, 0x50($s1)
/* E306A4 802BBD54 8E460028 */  lw        $a2, 0x28($s2)
/* E306A8 802BBD58 0C00A7B5 */  jal       dist2D
/* E306AC 802BBD5C 8E470030 */   lw       $a3, 0x30($s2)
/* E306B0 802BBD60 46000021 */  cvt.d.s   $f0, $f0
/* E306B4 802BBD64 3C014049 */  lui       $at, 0x4049
/* E306B8 802BBD68 44811800 */  mtc1      $at, $f3
/* E306BC 802BBD6C 44801000 */  mtc1      $zero, $f2
/* E306C0 802BBD70 46200005 */  abs.d     $f0, $f0
/* E306C4 802BBD74 4622003E */  c.le.d    $f0, $f2
/* E306C8 802BBD78 00000000 */  nop
/* E306CC 802BBD7C 45000007 */  bc1f      .L802BBD9C
/* E306D0 802BBD80 2404001F */   addiu    $a0, $zero, 0x1f
/* E306D4 802BBD84 8E420004 */  lw        $v0, 4($s2)
/* E306D8 802BBD88 3C018011 */  lui       $at, %hi(D_8010C934)
/* E306DC 802BBD8C AC31C934 */  sw        $s1, %lo(D_8010C934)($at)
/* E306E0 802BBD90 34420004 */  ori       $v0, $v0, 4
/* E306E4 802BBD94 0C039769 */  jal       set_action_state
/* E306E8 802BBD98 AE420004 */   sw       $v0, 4($s2)
.L802BBD9C:
/* E306EC 802BBD9C 8FBF0020 */  lw        $ra, 0x20($sp)
/* E306F0 802BBDA0 8FB3001C */  lw        $s3, 0x1c($sp)
/* E306F4 802BBDA4 8FB20018 */  lw        $s2, 0x18($sp)
/* E306F8 802BBDA8 8FB10014 */  lw        $s1, 0x14($sp)
/* E306FC 802BBDAC 8FB00010 */  lw        $s0, 0x10($sp)
/* E30700 802BBDB0 03E00008 */  jr        $ra
/* E30704 802BBDB4 27BD0028 */   addiu    $sp, $sp, 0x28
