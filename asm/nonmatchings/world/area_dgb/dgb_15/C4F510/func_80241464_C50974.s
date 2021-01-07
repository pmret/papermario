.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241464_C50974
/* C50974 80241464 27BDFF98 */  addiu     $sp, $sp, -0x68
/* C50978 80241468 AFB40058 */  sw        $s4, 0x58($sp)
/* C5097C 8024146C 0080A02D */  daddu     $s4, $a0, $zero
/* C50980 80241470 AFBF0060 */  sw        $ra, 0x60($sp)
/* C50984 80241474 AFB5005C */  sw        $s5, 0x5c($sp)
/* C50988 80241478 AFB30054 */  sw        $s3, 0x54($sp)
/* C5098C 8024147C AFB20050 */  sw        $s2, 0x50($sp)
/* C50990 80241480 AFB1004C */  sw        $s1, 0x4c($sp)
/* C50994 80241484 AFB00048 */  sw        $s0, 0x48($sp)
/* C50998 80241488 8E910148 */  lw        $s1, 0x148($s4)
/* C5099C 8024148C 86240008 */  lh        $a0, 8($s1)
/* C509A0 80241490 0C00EABB */  jal       get_npc_unsafe
/* C509A4 80241494 00A0802D */   daddu    $s0, $a1, $zero
/* C509A8 80241498 8E83000C */  lw        $v1, 0xc($s4)
/* C509AC 8024149C 0280202D */  daddu     $a0, $s4, $zero
/* C509B0 802414A0 8C650000 */  lw        $a1, ($v1)
/* C509B4 802414A4 0C0B1EAF */  jal       get_variable
/* C509B8 802414A8 0040902D */   daddu    $s2, $v0, $zero
/* C509BC 802414AC AFA00018 */  sw        $zero, 0x18($sp)
/* C509C0 802414B0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C509C4 802414B4 8C630094 */  lw        $v1, 0x94($v1)
/* C509C8 802414B8 AFA3001C */  sw        $v1, 0x1c($sp)
/* C509CC 802414BC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C509D0 802414C0 8C630080 */  lw        $v1, 0x80($v1)
/* C509D4 802414C4 AFA30020 */  sw        $v1, 0x20($sp)
/* C509D8 802414C8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C509DC 802414CC 8C630088 */  lw        $v1, 0x88($v1)
/* C509E0 802414D0 AFA30024 */  sw        $v1, 0x24($sp)
/* C509E4 802414D4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C509E8 802414D8 8C63008C */  lw        $v1, 0x8c($v1)
/* C509EC 802414DC 27B50018 */  addiu     $s5, $sp, 0x18
/* C509F0 802414E0 AFA30028 */  sw        $v1, 0x28($sp)
/* C509F4 802414E4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C509F8 802414E8 3C014282 */  lui       $at, 0x4282
/* C509FC 802414EC 44810000 */  mtc1      $at, $f0
/* C50A00 802414F0 8C630090 */  lw        $v1, 0x90($v1)
/* C50A04 802414F4 0040982D */  daddu     $s3, $v0, $zero
/* C50A08 802414F8 E7A00030 */  swc1      $f0, 0x30($sp)
/* C50A0C 802414FC A7A00034 */  sh        $zero, 0x34($sp)
/* C50A10 80241500 16000005 */  bnez      $s0, .L80241518
/* C50A14 80241504 AFA3002C */   sw       $v1, 0x2c($sp)
/* C50A18 80241508 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C50A1C 8024150C 30420004 */  andi      $v0, $v0, 4
/* C50A20 80241510 10400044 */  beqz      $v0, .L80241624
/* C50A24 80241514 00000000 */   nop      
.L80241518:
/* C50A28 80241518 2404F7FF */  addiu     $a0, $zero, -0x801
/* C50A2C 8024151C AE800070 */  sw        $zero, 0x70($s4)
/* C50A30 80241520 A640008E */  sh        $zero, 0x8e($s2)
/* C50A34 80241524 8E2200CC */  lw        $v0, 0xcc($s1)
/* C50A38 80241528 8E430000 */  lw        $v1, ($s2)
/* C50A3C 8024152C 8C420000 */  lw        $v0, ($v0)
/* C50A40 80241530 00641824 */  and       $v1, $v1, $a0
/* C50A44 80241534 AE430000 */  sw        $v1, ($s2)
/* C50A48 80241538 AE420028 */  sw        $v0, 0x28($s2)
/* C50A4C 8024153C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C50A50 80241540 8C420098 */  lw        $v0, 0x98($v0)
/* C50A54 80241544 54400005 */  bnel      $v0, $zero, .L8024155C
/* C50A58 80241548 2402FDFF */   addiu    $v0, $zero, -0x201
/* C50A5C 8024154C 34620200 */  ori       $v0, $v1, 0x200
/* C50A60 80241550 2403FFF7 */  addiu     $v1, $zero, -9
/* C50A64 80241554 08090559 */  j         .L80241564
/* C50A68 80241558 00431024 */   and      $v0, $v0, $v1
.L8024155C:
/* C50A6C 8024155C 00621024 */  and       $v0, $v1, $v0
/* C50A70 80241560 34420008 */  ori       $v0, $v0, 8
.L80241564:
/* C50A74 80241564 AE420000 */  sw        $v0, ($s2)
/* C50A78 80241568 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C50A7C 8024156C 30420004 */  andi      $v0, $v0, 4
/* C50A80 80241570 10400008 */  beqz      $v0, .L80241594
/* C50A84 80241574 24020063 */   addiu    $v0, $zero, 0x63
/* C50A88 80241578 AE820070 */  sw        $v0, 0x70($s4)
/* C50A8C 8024157C AE800074 */  sw        $zero, 0x74($s4)
/* C50A90 80241580 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C50A94 80241584 2403FFFB */  addiu     $v1, $zero, -5
/* C50A98 80241588 00431024 */  and       $v0, $v0, $v1
/* C50A9C 8024158C 08090570 */  j         .L802415C0
/* C50AA0 80241590 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241594:
/* C50AA4 80241594 8E220000 */  lw        $v0, ($s1)
/* C50AA8 80241598 3C034000 */  lui       $v1, 0x4000
/* C50AAC 8024159C 00431024 */  and       $v0, $v0, $v1
/* C50AB0 802415A0 10400007 */  beqz      $v0, .L802415C0
/* C50AB4 802415A4 3C03BFFF */   lui      $v1, 0xbfff
/* C50AB8 802415A8 2402000C */  addiu     $v0, $zero, 0xc
/* C50ABC 802415AC AE820070 */  sw        $v0, 0x70($s4)
/* C50AC0 802415B0 8E220000 */  lw        $v0, ($s1)
/* C50AC4 802415B4 3463FFFF */  ori       $v1, $v1, 0xffff
/* C50AC8 802415B8 00431024 */  and       $v0, $v0, $v1
/* C50ACC 802415BC AE220000 */  sw        $v0, ($s1)
.L802415C0:
/* C50AD0 802415C0 27A50038 */  addiu     $a1, $sp, 0x38
/* C50AD4 802415C4 27A6003C */  addiu     $a2, $sp, 0x3c
/* C50AD8 802415C8 C6400038 */  lwc1      $f0, 0x38($s2)
/* C50ADC 802415CC 864200A8 */  lh        $v0, 0xa8($s2)
/* C50AE0 802415D0 3C0142C8 */  lui       $at, 0x42c8
/* C50AE4 802415D4 44812000 */  mtc1      $at, $f4
/* C50AE8 802415D8 44823000 */  mtc1      $v0, $f6
/* C50AEC 802415DC 00000000 */  nop       
/* C50AF0 802415E0 468031A0 */  cvt.s.w   $f6, $f6
/* C50AF4 802415E4 27A20044 */  addiu     $v0, $sp, 0x44
/* C50AF8 802415E8 E7A00038 */  swc1      $f0, 0x38($sp)
/* C50AFC 802415EC C640003C */  lwc1      $f0, 0x3c($s2)
/* C50B00 802415F0 C6420040 */  lwc1      $f2, 0x40($s2)
/* C50B04 802415F4 46060000 */  add.s     $f0, $f0, $f6
/* C50B08 802415F8 E7A40044 */  swc1      $f4, 0x44($sp)
/* C50B0C 802415FC E7A20040 */  swc1      $f2, 0x40($sp)
/* C50B10 80241600 E7A0003C */  swc1      $f0, 0x3c($sp)
/* C50B14 80241604 AFA20010 */  sw        $v0, 0x10($sp)
/* C50B18 80241608 8E440080 */  lw        $a0, 0x80($s2)
/* C50B1C 8024160C 0C0372DF */  jal       func_800DCB7C
/* C50B20 80241610 27A70040 */   addiu    $a3, $sp, 0x40
/* C50B24 80241614 10400003 */  beqz      $v0, .L80241624
/* C50B28 80241618 00000000 */   nop      
/* C50B2C 8024161C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* C50B30 80241620 E640003C */  swc1      $f0, 0x3c($s2)
.L80241624:
/* C50B34 80241624 8E830070 */  lw        $v1, 0x70($s4)
/* C50B38 80241628 2C620064 */  sltiu     $v0, $v1, 0x64
/* C50B3C 8024162C 10400042 */  beqz      $v0, .L80241738
/* C50B40 80241630 00031080 */   sll      $v0, $v1, 2
/* C50B44 80241634 3C018024 */  lui       $at, %hi(D_80242E98)
/* C50B48 80241638 00220821 */  addu      $at, $at, $v0
/* C50B4C 8024163C 8C222E98 */  lw        $v0, %lo(D_80242E98)($at)
/* C50B50 80241640 00400008 */  jr        $v0
/* C50B54 80241644 00000000 */   nop      
/* C50B58 80241648 0280202D */  daddu     $a0, $s4, $zero
/* C50B5C 8024164C 0260282D */  daddu     $a1, $s3, $zero
/* C50B60 80241650 0C090234 */  jal       func_802408D0_C4FDE0
/* C50B64 80241654 02A0302D */   daddu    $a2, $s5, $zero
/* C50B68 80241658 0280202D */  daddu     $a0, $s4, $zero
/* C50B6C 8024165C 0260282D */  daddu     $a1, $s3, $zero
/* C50B70 80241660 0C09028A */  jal       func_80240A28_C4FF38
/* C50B74 80241664 02A0302D */   daddu    $a2, $s5, $zero
/* C50B78 80241668 080905CE */  j         .L80241738
/* C50B7C 8024166C 00000000 */   nop      
/* C50B80 80241670 0280202D */  daddu     $a0, $s4, $zero
/* C50B84 80241674 0260282D */  daddu     $a1, $s3, $zero
/* C50B88 80241678 0C090334 */  jal       dgb_15_UnkNpcAIFunc1
/* C50B8C 8024167C 02A0302D */   daddu    $a2, $s5, $zero
/* C50B90 80241680 0280202D */  daddu     $a0, $s4, $zero
/* C50B94 80241684 0260282D */  daddu     $a1, $s3, $zero
/* C50B98 80241688 0C090364 */  jal       func_80240D90_C502A0
/* C50B9C 8024168C 02A0302D */   daddu    $a2, $s5, $zero
/* C50BA0 80241690 080905CE */  j         .L80241738
/* C50BA4 80241694 00000000 */   nop      
/* C50BA8 80241698 0280202D */  daddu     $a0, $s4, $zero
/* C50BAC 8024169C 0260282D */  daddu     $a1, $s3, $zero
/* C50BB0 802416A0 0C0903D3 */  jal       func_80240F4C_C5045C
/* C50BB4 802416A4 02A0302D */   daddu    $a2, $s5, $zero
/* C50BB8 802416A8 080905CE */  j         .L80241738
/* C50BBC 802416AC 00000000 */   nop      
/* C50BC0 802416B0 0280202D */  daddu     $a0, $s4, $zero
/* C50BC4 802416B4 0260282D */  daddu     $a1, $s3, $zero
/* C50BC8 802416B8 0C090400 */  jal       dgb_15_NpcJumpFunc2
/* C50BCC 802416BC 02A0302D */   daddu    $a2, $s5, $zero
/* C50BD0 802416C0 0280202D */  daddu     $a0, $s4, $zero
/* C50BD4 802416C4 0260282D */  daddu     $a1, $s3, $zero
/* C50BD8 802416C8 0C09041D */  jal       dgb_15_NpcJumpFunc
/* C50BDC 802416CC 02A0302D */   daddu    $a2, $s5, $zero
/* C50BE0 802416D0 080905CE */  j         .L80241738
/* C50BE4 802416D4 00000000 */   nop      
/* C50BE8 802416D8 0280202D */  daddu     $a0, $s4, $zero
/* C50BEC 802416DC 0260282D */  daddu     $a1, $s3, $zero
/* C50BF0 802416E0 0C09043B */  jal       func_802410EC_C505FC
/* C50BF4 802416E4 02A0302D */   daddu    $a2, $s5, $zero
/* C50BF8 802416E8 0280202D */  daddu     $a0, $s4, $zero
/* C50BFC 802416EC 0260282D */  daddu     $a1, $s3, $zero
/* C50C00 802416F0 0C090487 */  jal       func_8024121C_C5072C
/* C50C04 802416F4 02A0302D */   daddu    $a2, $s5, $zero
/* C50C08 802416F8 080905CE */  j         .L80241738
/* C50C0C 802416FC 00000000 */   nop      
/* C50C10 80241700 0280202D */  daddu     $a0, $s4, $zero
/* C50C14 80241704 0260282D */  daddu     $a1, $s3, $zero
/* C50C18 80241708 0C0904CF */  jal       dgb_15_UnkNpcDurationFlagFunc
/* C50C1C 8024170C 02A0302D */   daddu    $a2, $s5, $zero
/* C50C20 80241710 080905CE */  j         .L80241738
/* C50C24 80241714 00000000 */   nop      
/* C50C28 80241718 0280202D */  daddu     $a0, $s4, $zero
/* C50C2C 8024171C 0260282D */  daddu     $a1, $s3, $zero
/* C50C30 80241720 0C0904E9 */  jal       func_802413A4_C508B4
/* C50C34 80241724 02A0302D */   daddu    $a2, $s5, $zero
/* C50C38 80241728 080905CE */  j         .L80241738
/* C50C3C 8024172C 00000000 */   nop      
/* C50C40 80241730 0C0129CF */  jal       func_8004A73C
/* C50C44 80241734 0280202D */   daddu    $a0, $s4, $zero
.L80241738:
/* C50C48 80241738 8FBF0060 */  lw        $ra, 0x60($sp)
/* C50C4C 8024173C 8FB5005C */  lw        $s5, 0x5c($sp)
/* C50C50 80241740 8FB40058 */  lw        $s4, 0x58($sp)
/* C50C54 80241744 8FB30054 */  lw        $s3, 0x54($sp)
/* C50C58 80241748 8FB20050 */  lw        $s2, 0x50($sp)
/* C50C5C 8024174C 8FB1004C */  lw        $s1, 0x4c($sp)
/* C50C60 80241750 8FB00048 */  lw        $s0, 0x48($sp)
/* C50C64 80241754 0000102D */  daddu     $v0, $zero, $zero
/* C50C68 80241758 03E00008 */  jr        $ra
/* C50C6C 8024175C 27BD0068 */   addiu    $sp, $sp, 0x68
