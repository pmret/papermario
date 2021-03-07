.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240958_C2F4F8
/* C2F4F8 80240958 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C2F4FC 8024095C AFB40048 */  sw        $s4, 0x48($sp)
/* C2F500 80240960 0080A02D */  daddu     $s4, $a0, $zero
/* C2F504 80240964 AFBF004C */  sw        $ra, 0x4c($sp)
/* C2F508 80240968 AFB30044 */  sw        $s3, 0x44($sp)
/* C2F50C 8024096C AFB20040 */  sw        $s2, 0x40($sp)
/* C2F510 80240970 AFB1003C */  sw        $s1, 0x3c($sp)
/* C2F514 80240974 AFB00038 */  sw        $s0, 0x38($sp)
/* C2F518 80240978 8E930148 */  lw        $s3, 0x148($s4)
/* C2F51C 8024097C 00C0802D */  daddu     $s0, $a2, $zero
/* C2F520 80240980 86640008 */  lh        $a0, 8($s3)
/* C2F524 80240984 0C00EABB */  jal       get_npc_unsafe
/* C2F528 80240988 0000902D */   daddu    $s2, $zero, $zero
/* C2F52C 8024098C 0C039D59 */  jal       get_player_data
/* C2F530 80240990 0040882D */   daddu    $s1, $v0, $zero
/* C2F534 80240994 0200202D */  daddu     $a0, $s0, $zero
/* C2F538 80240998 0260282D */  daddu     $a1, $s3, $zero
/* C2F53C 8024099C 0000382D */  daddu     $a3, $zero, $zero
/* C2F540 802409A0 3C0642A0 */  lui       $a2, 0x42a0
/* C2F544 802409A4 0040802D */  daddu     $s0, $v0, $zero
/* C2F548 802409A8 0C01242D */  jal       func_800490B4
/* C2F54C 802409AC AFA00010 */   sw       $zero, 0x10($sp)
/* C2F550 802409B0 10400022 */  beqz      $v0, .L80240A3C
/* C2F554 802409B4 00000000 */   nop
/* C2F558 802409B8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C2F55C 802409BC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C2F560 802409C0 804300B4 */  lb        $v1, 0xb4($v0)
/* C2F564 802409C4 24020002 */  addiu     $v0, $zero, 2
/* C2F568 802409C8 10620013 */  beq       $v1, $v0, .L80240A18
/* C2F56C 802409CC 2402001A */   addiu    $v0, $zero, 0x1a
/* C2F570 802409D0 10620011 */  beq       $v1, $v0, .L80240A18
/* C2F574 802409D4 24020003 */   addiu    $v0, $zero, 3
/* C2F578 802409D8 1062000F */  beq       $v1, $v0, .L80240A18
/* C2F57C 802409DC 2402000E */   addiu    $v0, $zero, 0xe
/* C2F580 802409E0 1062000D */  beq       $v1, $v0, .L80240A18
/* C2F584 802409E4 24020010 */   addiu    $v0, $zero, 0x10
/* C2F588 802409E8 1062000B */  beq       $v1, $v0, .L80240A18
/* C2F58C 802409EC 2402000B */   addiu    $v0, $zero, 0xb
/* C2F590 802409F0 10620009 */  beq       $v1, $v0, .L80240A18
/* C2F594 802409F4 2402000A */   addiu    $v0, $zero, 0xa
/* C2F598 802409F8 10620007 */  beq       $v1, $v0, .L80240A18
/* C2F59C 802409FC 24020012 */   addiu    $v0, $zero, 0x12
/* C2F5A0 80240A00 10620005 */  beq       $v1, $v0, .L80240A18
/* C2F5A4 80240A04 24020013 */   addiu    $v0, $zero, 0x13
/* C2F5A8 80240A08 10620003 */  beq       $v1, $v0, .L80240A18
/* C2F5AC 80240A0C 24020025 */   addiu    $v0, $zero, 0x25
/* C2F5B0 80240A10 14620002 */  bne       $v1, $v0, .L80240A1C
/* C2F5B4 80240A14 00000000 */   nop
.L80240A18:
/* C2F5B8 80240A18 24120001 */  addiu     $s2, $zero, 1
.L80240A1C:
/* C2F5BC 80240A1C 82030012 */  lb        $v1, 0x12($s0)
/* C2F5C0 80240A20 24020002 */  addiu     $v0, $zero, 2
/* C2F5C4 80240A24 14620007 */  bne       $v1, $v0, .L80240A44
/* C2F5C8 80240A28 24020001 */   addiu    $v0, $zero, 1
/* C2F5CC 80240A2C 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C2F5D0 80240A30 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C2F5D4 80240A34 50430002 */  beql      $v0, $v1, .L80240A40
/* C2F5D8 80240A38 24120001 */   addiu    $s2, $zero, 1
.L80240A3C:
/* C2F5DC 80240A3C 82030012 */  lb        $v1, 0x12($s0)
.L80240A40:
/* C2F5E0 80240A40 24020001 */  addiu     $v0, $zero, 1
.L80240A44:
/* C2F5E4 80240A44 14620006 */  bne       $v1, $v0, .L80240A60
/* C2F5E8 80240A48 24020003 */   addiu    $v0, $zero, 3
/* C2F5EC 80240A4C 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C2F5F0 80240A50 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C2F5F4 80240A54 14400008 */  bnez      $v0, .L80240A78
/* C2F5F8 80240A58 27A40028 */   addiu    $a0, $sp, 0x28
/* C2F5FC 80240A5C 24020003 */  addiu     $v0, $zero, 3
.L80240A60:
/* C2F600 80240A60 1462001B */  bne       $v1, $v0, .L80240AD0
/* C2F604 80240A64 24020002 */   addiu    $v0, $zero, 2
/* C2F608 80240A68 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* C2F60C 80240A6C 8063EBB0 */  lb        $v1, %lo(D_8010EBB0)($v1)
/* C2F610 80240A70 14620017 */  bne       $v1, $v0, .L80240AD0
/* C2F614 80240A74 27A40028 */   addiu    $a0, $sp, 0x28
.L80240A78:
/* C2F618 80240A78 27A5002C */  addiu     $a1, $sp, 0x2c
/* C2F61C 80240A7C 8E27000C */  lw        $a3, 0xc($s1)
/* C2F620 80240A80 C6200038 */  lwc1      $f0, 0x38($s1)
/* C2F624 80240A84 C6220040 */  lwc1      $f2, 0x40($s1)
/* C2F628 80240A88 0000302D */  daddu     $a2, $zero, $zero
/* C2F62C 80240A8C E7A00028 */  swc1      $f0, 0x28($sp)
/* C2F630 80240A90 0C00A7E7 */  jal       add_vec2D_polar
/* C2F634 80240A94 E7A2002C */   swc1     $f2, 0x2c($sp)
/* C2F638 80240A98 3C028011 */  lui       $v0, %hi(wPartnerNpc)
/* C2F63C 80240A9C 8C42C930 */  lw        $v0, %lo(wPartnerNpc)($v0)
/* C2F640 80240AA0 C7AC0028 */  lwc1      $f12, 0x28($sp)
/* C2F644 80240AA4 C7AE002C */  lwc1      $f14, 0x2c($sp)
/* C2F648 80240AA8 8C460038 */  lw        $a2, 0x38($v0)
/* C2F64C 80240AAC 0C00A7B5 */  jal       dist2D
/* C2F650 80240AB0 8C470040 */   lw       $a3, 0x40($v0)
/* C2F654 80240AB4 3C0142A0 */  lui       $at, 0x42a0
/* C2F658 80240AB8 44811000 */  mtc1      $at, $f2
/* C2F65C 80240ABC 00000000 */  nop
/* C2F660 80240AC0 4602003E */  c.le.s    $f0, $f2
/* C2F664 80240AC4 00000000 */  nop
/* C2F668 80240AC8 45030001 */  bc1tl     .L80240AD0
/* C2F66C 80240ACC 24120001 */   addiu    $s2, $zero, 1
.L80240AD0:
/* C2F670 80240AD0 12400026 */  beqz      $s2, .L80240B6C
/* C2F674 80240AD4 0220202D */   daddu    $a0, $s1, $zero
/* C2F678 80240AD8 3C05B000 */  lui       $a1, 0xb000
/* C2F67C 80240ADC 34A5000E */  ori       $a1, $a1, 0xe
/* C2F680 80240AE0 0C012530 */  jal       func_800494C0
/* C2F684 80240AE4 0000302D */   daddu    $a2, $zero, $zero
/* C2F688 80240AE8 0000202D */  daddu     $a0, $zero, $zero
/* C2F68C 80240AEC 0220282D */  daddu     $a1, $s1, $zero
/* C2F690 80240AF0 0000302D */  daddu     $a2, $zero, $zero
/* C2F694 80240AF4 862200A8 */  lh        $v0, 0xa8($s1)
/* C2F698 80240AF8 8E6300CC */  lw        $v1, 0xcc($s3)
/* C2F69C 80240AFC 3C013F80 */  lui       $at, 0x3f80
/* C2F6A0 80240B00 44810000 */  mtc1      $at, $f0
/* C2F6A4 80240B04 3C014000 */  lui       $at, 0x4000
/* C2F6A8 80240B08 44811000 */  mtc1      $at, $f2
/* C2F6AC 80240B0C 3C01C1A0 */  lui       $at, 0xc1a0
/* C2F6B0 80240B10 44812000 */  mtc1      $at, $f4
/* C2F6B4 80240B14 44823000 */  mtc1      $v0, $f6
/* C2F6B8 80240B18 00000000 */  nop
/* C2F6BC 80240B1C 468031A0 */  cvt.s.w   $f6, $f6
/* C2F6C0 80240B20 44073000 */  mfc1      $a3, $f6
/* C2F6C4 80240B24 8C63002C */  lw        $v1, 0x2c($v1)
/* C2F6C8 80240B28 2402000A */  addiu     $v0, $zero, 0xa
/* C2F6CC 80240B2C A622008E */  sh        $v0, 0x8e($s1)
/* C2F6D0 80240B30 2402000F */  addiu     $v0, $zero, 0xf
/* C2F6D4 80240B34 AE230028 */  sw        $v1, 0x28($s1)
/* C2F6D8 80240B38 AFA2001C */  sw        $v0, 0x1c($sp)
/* C2F6DC 80240B3C 27A20030 */  addiu     $v0, $sp, 0x30
/* C2F6E0 80240B40 E7A00010 */  swc1      $f0, 0x10($sp)
/* C2F6E4 80240B44 E7A20014 */  swc1      $f2, 0x14($sp)
/* C2F6E8 80240B48 E7A40018 */  swc1      $f4, 0x18($sp)
/* C2F6EC 80240B4C 0C01BFA4 */  jal       fx_emote
/* C2F6F0 80240B50 AFA20020 */   sw       $v0, 0x20($sp)
/* C2F6F4 80240B54 0220202D */  daddu     $a0, $s1, $zero
/* C2F6F8 80240B58 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C2F6FC 80240B5C 0C012530 */  jal       func_800494C0
/* C2F700 80240B60 3C060020 */   lui      $a2, 0x20
/* C2F704 80240B64 24020002 */  addiu     $v0, $zero, 2
/* C2F708 80240B68 AE820070 */  sw        $v0, 0x70($s4)
.L80240B6C:
/* C2F70C 80240B6C 9622008E */  lhu       $v0, 0x8e($s1)
/* C2F710 80240B70 24420001 */  addiu     $v0, $v0, 1
/* C2F714 80240B74 A622008E */  sh        $v0, 0x8e($s1)
/* C2F718 80240B78 00021400 */  sll       $v0, $v0, 0x10
/* C2F71C 80240B7C 00021C03 */  sra       $v1, $v0, 0x10
/* C2F720 80240B80 2402001B */  addiu     $v0, $zero, 0x1b
/* C2F724 80240B84 14620005 */  bne       $v1, $v0, .L80240B9C
/* C2F728 80240B88 24020039 */   addiu    $v0, $zero, 0x39
/* C2F72C 80240B8C 0220202D */  daddu     $a0, $s1, $zero
/* C2F730 80240B90 3C05B000 */  lui       $a1, 0xb000
/* C2F734 80240B94 080902EC */  j         .L80240BB0
/* C2F738 80240B98 34A5000C */   ori      $a1, $a1, 0xc
.L80240B9C:
/* C2F73C 80240B9C 14620008 */  bne       $v1, $v0, .L80240BC0
/* C2F740 80240BA0 2402003B */   addiu    $v0, $zero, 0x3b
/* C2F744 80240BA4 0220202D */  daddu     $a0, $s1, $zero
/* C2F748 80240BA8 3C05B000 */  lui       $a1, 0xb000
/* C2F74C 80240BAC 34A5000D */  ori       $a1, $a1, 0xd
.L80240BB0:
/* C2F750 80240BB0 0C012530 */  jal       func_800494C0
/* C2F754 80240BB4 0000302D */   daddu    $a2, $zero, $zero
/* C2F758 80240BB8 080902FC */  j         .L80240BF0
/* C2F75C 80240BBC 00000000 */   nop
.L80240BC0:
/* C2F760 80240BC0 14620005 */  bne       $v1, $v0, .L80240BD8
/* C2F764 80240BC4 2402003C */   addiu    $v0, $zero, 0x3c
/* C2F768 80240BC8 8E6200CC */  lw        $v0, 0xcc($s3)
/* C2F76C 80240BCC 8C420030 */  lw        $v0, 0x30($v0)
/* C2F770 80240BD0 080902FC */  j         .L80240BF0
/* C2F774 80240BD4 AE220028 */   sw       $v0, 0x28($s1)
.L80240BD8:
/* C2F778 80240BD8 14620005 */  bne       $v1, $v0, .L80240BF0
/* C2F77C 80240BDC 00000000 */   nop
/* C2F780 80240BE0 8E6200CC */  lw        $v0, 0xcc($s3)
/* C2F784 80240BE4 8C420028 */  lw        $v0, 0x28($v0)
/* C2F788 80240BE8 A620008E */  sh        $zero, 0x8e($s1)
/* C2F78C 80240BEC AE220028 */  sw        $v0, 0x28($s1)
.L80240BF0:
/* C2F790 80240BF0 8FBF004C */  lw        $ra, 0x4c($sp)
/* C2F794 80240BF4 8FB40048 */  lw        $s4, 0x48($sp)
/* C2F798 80240BF8 8FB30044 */  lw        $s3, 0x44($sp)
/* C2F79C 80240BFC 8FB20040 */  lw        $s2, 0x40($sp)
/* C2F7A0 80240C00 8FB1003C */  lw        $s1, 0x3c($sp)
/* C2F7A4 80240C04 8FB00038 */  lw        $s0, 0x38($sp)
/* C2F7A8 80240C08 03E00008 */  jr        $ra
/* C2F7AC 80240C0C 27BD0050 */   addiu    $sp, $sp, 0x50
