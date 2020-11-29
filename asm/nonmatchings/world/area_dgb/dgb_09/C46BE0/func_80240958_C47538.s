.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240958_C47538
/* C47538 80240958 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C4753C 8024095C AFB40048 */  sw        $s4, 0x48($sp)
/* C47540 80240960 0080A02D */  daddu     $s4, $a0, $zero
/* C47544 80240964 AFBF004C */  sw        $ra, 0x4c($sp)
/* C47548 80240968 AFB30044 */  sw        $s3, 0x44($sp)
/* C4754C 8024096C AFB20040 */  sw        $s2, 0x40($sp)
/* C47550 80240970 AFB1003C */  sw        $s1, 0x3c($sp)
/* C47554 80240974 AFB00038 */  sw        $s0, 0x38($sp)
/* C47558 80240978 8E930148 */  lw        $s3, 0x148($s4)
/* C4755C 8024097C 00C0802D */  daddu     $s0, $a2, $zero
/* C47560 80240980 86640008 */  lh        $a0, 8($s3)
/* C47564 80240984 0C00EABB */  jal       get_npc_unsafe
/* C47568 80240988 0000902D */   daddu    $s2, $zero, $zero
/* C4756C 8024098C 0C039D59 */  jal       get_player_data
/* C47570 80240990 0040882D */   daddu    $s1, $v0, $zero
/* C47574 80240994 0200202D */  daddu     $a0, $s0, $zero
/* C47578 80240998 0260282D */  daddu     $a1, $s3, $zero
/* C4757C 8024099C 0000382D */  daddu     $a3, $zero, $zero
/* C47580 802409A0 3C0642A0 */  lui       $a2, 0x42a0
/* C47584 802409A4 0040802D */  daddu     $s0, $v0, $zero
/* C47588 802409A8 0C01242D */  jal       func_800490B4
/* C4758C 802409AC AFA00010 */   sw       $zero, 0x10($sp)
/* C47590 802409B0 10400022 */  beqz      $v0, .L80240A3C
/* C47594 802409B4 00000000 */   nop      
/* C47598 802409B8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C4759C 802409BC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C475A0 802409C0 804300B4 */  lb        $v1, 0xb4($v0)
/* C475A4 802409C4 24020002 */  addiu     $v0, $zero, 2
/* C475A8 802409C8 10620013 */  beq       $v1, $v0, .L80240A18
/* C475AC 802409CC 2402001A */   addiu    $v0, $zero, 0x1a
/* C475B0 802409D0 10620011 */  beq       $v1, $v0, .L80240A18
/* C475B4 802409D4 24020003 */   addiu    $v0, $zero, 3
/* C475B8 802409D8 1062000F */  beq       $v1, $v0, .L80240A18
/* C475BC 802409DC 2402000E */   addiu    $v0, $zero, 0xe
/* C475C0 802409E0 1062000D */  beq       $v1, $v0, .L80240A18
/* C475C4 802409E4 24020010 */   addiu    $v0, $zero, 0x10
/* C475C8 802409E8 1062000B */  beq       $v1, $v0, .L80240A18
/* C475CC 802409EC 2402000B */   addiu    $v0, $zero, 0xb
/* C475D0 802409F0 10620009 */  beq       $v1, $v0, .L80240A18
/* C475D4 802409F4 2402000A */   addiu    $v0, $zero, 0xa
/* C475D8 802409F8 10620007 */  beq       $v1, $v0, .L80240A18
/* C475DC 802409FC 24020012 */   addiu    $v0, $zero, 0x12
/* C475E0 80240A00 10620005 */  beq       $v1, $v0, .L80240A18
/* C475E4 80240A04 24020013 */   addiu    $v0, $zero, 0x13
/* C475E8 80240A08 10620003 */  beq       $v1, $v0, .L80240A18
/* C475EC 80240A0C 24020025 */   addiu    $v0, $zero, 0x25
/* C475F0 80240A10 14620002 */  bne       $v1, $v0, .L80240A1C
/* C475F4 80240A14 00000000 */   nop      
.L80240A18:
/* C475F8 80240A18 24120001 */  addiu     $s2, $zero, 1
.L80240A1C:
/* C475FC 80240A1C 82030012 */  lb        $v1, 0x12($s0)
/* C47600 80240A20 24020002 */  addiu     $v0, $zero, 2
/* C47604 80240A24 14620007 */  bne       $v1, $v0, .L80240A44
/* C47608 80240A28 24020001 */   addiu    $v0, $zero, 1
/* C4760C 80240A2C 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C47610 80240A30 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C47614 80240A34 50430002 */  beql      $v0, $v1, .L80240A40
/* C47618 80240A38 24120001 */   addiu    $s2, $zero, 1
.L80240A3C:
/* C4761C 80240A3C 82030012 */  lb        $v1, 0x12($s0)
.L80240A40:
/* C47620 80240A40 24020001 */  addiu     $v0, $zero, 1
.L80240A44:
/* C47624 80240A44 14620006 */  bne       $v1, $v0, .L80240A60
/* C47628 80240A48 24020003 */   addiu    $v0, $zero, 3
/* C4762C 80240A4C 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C47630 80240A50 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C47634 80240A54 14400008 */  bnez      $v0, .L80240A78
/* C47638 80240A58 27A40028 */   addiu    $a0, $sp, 0x28
/* C4763C 80240A5C 24020003 */  addiu     $v0, $zero, 3
.L80240A60:
/* C47640 80240A60 1462001B */  bne       $v1, $v0, .L80240AD0
/* C47644 80240A64 24020002 */   addiu    $v0, $zero, 2
/* C47648 80240A68 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* C4764C 80240A6C 8063EBB0 */  lb        $v1, %lo(D_8010EBB0)($v1)
/* C47650 80240A70 14620017 */  bne       $v1, $v0, .L80240AD0
/* C47654 80240A74 27A40028 */   addiu    $a0, $sp, 0x28
.L80240A78:
/* C47658 80240A78 27A5002C */  addiu     $a1, $sp, 0x2c
/* C4765C 80240A7C 8E27000C */  lw        $a3, 0xc($s1)
/* C47660 80240A80 C6200038 */  lwc1      $f0, 0x38($s1)
/* C47664 80240A84 C6220040 */  lwc1      $f2, 0x40($s1)
/* C47668 80240A88 0000302D */  daddu     $a2, $zero, $zero
/* C4766C 80240A8C E7A00028 */  swc1      $f0, 0x28($sp)
/* C47670 80240A90 0C00A7E7 */  jal       add_vec2D_polar
/* C47674 80240A94 E7A2002C */   swc1     $f2, 0x2c($sp)
/* C47678 80240A98 3C028011 */  lui       $v0, %hi(D_8010C930)
/* C4767C 80240A9C 8C42C930 */  lw        $v0, %lo(D_8010C930)($v0)
/* C47680 80240AA0 C7AC0028 */  lwc1      $f12, 0x28($sp)
/* C47684 80240AA4 C7AE002C */  lwc1      $f14, 0x2c($sp)
/* C47688 80240AA8 8C460038 */  lw        $a2, 0x38($v0)
/* C4768C 80240AAC 0C00A7B5 */  jal       dist2D
/* C47690 80240AB0 8C470040 */   lw       $a3, 0x40($v0)
/* C47694 80240AB4 3C0142A0 */  lui       $at, 0x42a0
/* C47698 80240AB8 44811000 */  mtc1      $at, $f2
/* C4769C 80240ABC 00000000 */  nop       
/* C476A0 80240AC0 4602003E */  c.le.s    $f0, $f2
/* C476A4 80240AC4 00000000 */  nop       
/* C476A8 80240AC8 45030001 */  bc1tl     .L80240AD0
/* C476AC 80240ACC 24120001 */   addiu    $s2, $zero, 1
.L80240AD0:
/* C476B0 80240AD0 12400026 */  beqz      $s2, .L80240B6C
/* C476B4 80240AD4 0220202D */   daddu    $a0, $s1, $zero
/* C476B8 80240AD8 3C05B000 */  lui       $a1, 0xb000
/* C476BC 80240ADC 34A5000E */  ori       $a1, $a1, 0xe
/* C476C0 80240AE0 0C012530 */  jal       func_800494C0
/* C476C4 80240AE4 0000302D */   daddu    $a2, $zero, $zero
/* C476C8 80240AE8 0000202D */  daddu     $a0, $zero, $zero
/* C476CC 80240AEC 0220282D */  daddu     $a1, $s1, $zero
/* C476D0 80240AF0 0000302D */  daddu     $a2, $zero, $zero
/* C476D4 80240AF4 862200A8 */  lh        $v0, 0xa8($s1)
/* C476D8 80240AF8 8E6300CC */  lw        $v1, 0xcc($s3)
/* C476DC 80240AFC 3C013F80 */  lui       $at, 0x3f80
/* C476E0 80240B00 44810000 */  mtc1      $at, $f0
/* C476E4 80240B04 3C014000 */  lui       $at, 0x4000
/* C476E8 80240B08 44811000 */  mtc1      $at, $f2
/* C476EC 80240B0C 3C01C1A0 */  lui       $at, 0xc1a0
/* C476F0 80240B10 44812000 */  mtc1      $at, $f4
/* C476F4 80240B14 44823000 */  mtc1      $v0, $f6
/* C476F8 80240B18 00000000 */  nop       
/* C476FC 80240B1C 468031A0 */  cvt.s.w   $f6, $f6
/* C47700 80240B20 44073000 */  mfc1      $a3, $f6
/* C47704 80240B24 8C63002C */  lw        $v1, 0x2c($v1)
/* C47708 80240B28 2402000A */  addiu     $v0, $zero, 0xa
/* C4770C 80240B2C A622008E */  sh        $v0, 0x8e($s1)
/* C47710 80240B30 2402000F */  addiu     $v0, $zero, 0xf
/* C47714 80240B34 AE230028 */  sw        $v1, 0x28($s1)
/* C47718 80240B38 AFA2001C */  sw        $v0, 0x1c($sp)
/* C4771C 80240B3C 27A20030 */  addiu     $v0, $sp, 0x30
/* C47720 80240B40 E7A00010 */  swc1      $f0, 0x10($sp)
/* C47724 80240B44 E7A20014 */  swc1      $f2, 0x14($sp)
/* C47728 80240B48 E7A40018 */  swc1      $f4, 0x18($sp)
/* C4772C 80240B4C 0C01BFA4 */  jal       fx_emote
/* C47730 80240B50 AFA20020 */   sw       $v0, 0x20($sp)
/* C47734 80240B54 0220202D */  daddu     $a0, $s1, $zero
/* C47738 80240B58 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C4773C 80240B5C 0C012530 */  jal       func_800494C0
/* C47740 80240B60 3C060020 */   lui      $a2, 0x20
/* C47744 80240B64 24020002 */  addiu     $v0, $zero, 2
/* C47748 80240B68 AE820070 */  sw        $v0, 0x70($s4)
.L80240B6C:
/* C4774C 80240B6C 9622008E */  lhu       $v0, 0x8e($s1)
/* C47750 80240B70 24420001 */  addiu     $v0, $v0, 1
/* C47754 80240B74 A622008E */  sh        $v0, 0x8e($s1)
/* C47758 80240B78 00021400 */  sll       $v0, $v0, 0x10
/* C4775C 80240B7C 00021C03 */  sra       $v1, $v0, 0x10
/* C47760 80240B80 2402001B */  addiu     $v0, $zero, 0x1b
/* C47764 80240B84 14620005 */  bne       $v1, $v0, .L80240B9C
/* C47768 80240B88 24020039 */   addiu    $v0, $zero, 0x39
/* C4776C 80240B8C 0220202D */  daddu     $a0, $s1, $zero
/* C47770 80240B90 3C05B000 */  lui       $a1, 0xb000
/* C47774 80240B94 080902EC */  j         .L80240BB0
/* C47778 80240B98 34A5000C */   ori      $a1, $a1, 0xc
.L80240B9C:
/* C4777C 80240B9C 14620008 */  bne       $v1, $v0, .L80240BC0
/* C47780 80240BA0 2402003B */   addiu    $v0, $zero, 0x3b
/* C47784 80240BA4 0220202D */  daddu     $a0, $s1, $zero
/* C47788 80240BA8 3C05B000 */  lui       $a1, 0xb000
/* C4778C 80240BAC 34A5000D */  ori       $a1, $a1, 0xd
.L80240BB0:
/* C47790 80240BB0 0C012530 */  jal       func_800494C0
/* C47794 80240BB4 0000302D */   daddu    $a2, $zero, $zero
/* C47798 80240BB8 080902FC */  j         .L80240BF0
/* C4779C 80240BBC 00000000 */   nop      
.L80240BC0:
/* C477A0 80240BC0 14620005 */  bne       $v1, $v0, .L80240BD8
/* C477A4 80240BC4 2402003C */   addiu    $v0, $zero, 0x3c
/* C477A8 80240BC8 8E6200CC */  lw        $v0, 0xcc($s3)
/* C477AC 80240BCC 8C420030 */  lw        $v0, 0x30($v0)
/* C477B0 80240BD0 080902FC */  j         .L80240BF0
/* C477B4 80240BD4 AE220028 */   sw       $v0, 0x28($s1)
.L80240BD8:
/* C477B8 80240BD8 14620005 */  bne       $v1, $v0, .L80240BF0
/* C477BC 80240BDC 00000000 */   nop      
/* C477C0 80240BE0 8E6200CC */  lw        $v0, 0xcc($s3)
/* C477C4 80240BE4 8C420028 */  lw        $v0, 0x28($v0)
/* C477C8 80240BE8 A620008E */  sh        $zero, 0x8e($s1)
/* C477CC 80240BEC AE220028 */  sw        $v0, 0x28($s1)
.L80240BF0:
/* C477D0 80240BF0 8FBF004C */  lw        $ra, 0x4c($sp)
/* C477D4 80240BF4 8FB40048 */  lw        $s4, 0x48($sp)
/* C477D8 80240BF8 8FB30044 */  lw        $s3, 0x44($sp)
/* C477DC 80240BFC 8FB20040 */  lw        $s2, 0x40($sp)
/* C477E0 80240C00 8FB1003C */  lw        $s1, 0x3c($sp)
/* C477E4 80240C04 8FB00038 */  lw        $s0, 0x38($sp)
/* C477E8 80240C08 03E00008 */  jr        $ra
/* C477EC 80240C0C 27BD0050 */   addiu    $sp, $sp, 0x50
