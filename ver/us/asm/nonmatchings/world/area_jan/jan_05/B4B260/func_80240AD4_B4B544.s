.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AD4_B4B544
/* B4B544 80240AD4 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* B4B548 80240AD8 AFB3004C */  sw        $s3, 0x4c($sp)
/* B4B54C 80240ADC 0080982D */  daddu     $s3, $a0, $zero
/* B4B550 80240AE0 AFBF0054 */  sw        $ra, 0x54($sp)
/* B4B554 80240AE4 AFB40050 */  sw        $s4, 0x50($sp)
/* B4B558 80240AE8 AFB20048 */  sw        $s2, 0x48($sp)
/* B4B55C 80240AEC AFB10044 */  sw        $s1, 0x44($sp)
/* B4B560 80240AF0 AFB00040 */  sw        $s0, 0x40($sp)
/* B4B564 80240AF4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* B4B568 80240AF8 8E710148 */  lw        $s1, 0x148($s3)
/* B4B56C 80240AFC 00A0A02D */  daddu     $s4, $a1, $zero
/* B4B570 80240B00 86240008 */  lh        $a0, 8($s1)
/* B4B574 80240B04 0C00EABB */  jal       get_npc_unsafe
/* B4B578 80240B08 00C0902D */   daddu    $s2, $a2, $zero
/* B4B57C 80240B0C 8E830014 */  lw        $v1, 0x14($s4)
/* B4B580 80240B10 04600034 */  bltz      $v1, .L80240BE4
/* B4B584 80240B14 0040802D */   daddu    $s0, $v0, $zero
/* B4B588 80240B18 8E620074 */  lw        $v0, 0x74($s3)
/* B4B58C 80240B1C 1C400030 */  bgtz      $v0, .L80240BE0
/* B4B590 80240B20 2442FFFF */   addiu    $v0, $v0, -1
/* B4B594 80240B24 0240202D */  daddu     $a0, $s2, $zero
/* B4B598 80240B28 AE630074 */  sw        $v1, 0x74($s3)
/* B4B59C 80240B2C AFA00010 */  sw        $zero, 0x10($sp)
/* B4B5A0 80240B30 8E86000C */  lw        $a2, 0xc($s4)
/* B4B5A4 80240B34 8E870010 */  lw        $a3, 0x10($s4)
/* B4B5A8 80240B38 0C01242D */  jal       func_800490B4
/* B4B5AC 80240B3C 0220282D */   daddu    $a1, $s1, $zero
/* B4B5B0 80240B40 10400025 */  beqz      $v0, .L80240BD8
/* B4B5B4 80240B44 0000202D */   daddu    $a0, $zero, $zero
/* B4B5B8 80240B48 0200282D */  daddu     $a1, $s0, $zero
/* B4B5BC 80240B4C 0000302D */  daddu     $a2, $zero, $zero
/* B4B5C0 80240B50 860300A8 */  lh        $v1, 0xa8($s0)
/* B4B5C4 80240B54 3C013F80 */  lui       $at, 0x3f80
/* B4B5C8 80240B58 44810000 */  mtc1      $at, $f0
/* B4B5CC 80240B5C 3C014000 */  lui       $at, 0x4000
/* B4B5D0 80240B60 44811000 */  mtc1      $at, $f2
/* B4B5D4 80240B64 3C01C1A0 */  lui       $at, 0xc1a0
/* B4B5D8 80240B68 44812000 */  mtc1      $at, $f4
/* B4B5DC 80240B6C 2402000F */  addiu     $v0, $zero, 0xf
/* B4B5E0 80240B70 AFA2001C */  sw        $v0, 0x1c($sp)
/* B4B5E4 80240B74 44835000 */  mtc1      $v1, $f10
/* B4B5E8 80240B78 00000000 */  nop
/* B4B5EC 80240B7C 468052A0 */  cvt.s.w   $f10, $f10
/* B4B5F0 80240B80 44075000 */  mfc1      $a3, $f10
/* B4B5F4 80240B84 27A20028 */  addiu     $v0, $sp, 0x28
/* B4B5F8 80240B88 AFA20020 */  sw        $v0, 0x20($sp)
/* B4B5FC 80240B8C E7A00010 */  swc1      $f0, 0x10($sp)
/* B4B600 80240B90 E7A20014 */  swc1      $f2, 0x14($sp)
/* B4B604 80240B94 0C01BFA4 */  jal       fx_emote
/* B4B608 80240B98 E7A40018 */   swc1     $f4, 0x18($sp)
/* B4B60C 80240B9C 0200202D */  daddu     $a0, $s0, $zero
/* B4B610 80240BA0 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B4B614 80240BA4 0C012530 */  jal       ai_enemy_play_sound
/* B4B618 80240BA8 3C060020 */   lui      $a2, 0x20
/* B4B61C 80240BAC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B4B620 80240BB0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B4B624 80240BB4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B4B628 80240BB8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B4B62C 80240BBC 8C460028 */  lw        $a2, 0x28($v0)
/* B4B630 80240BC0 0C00A720 */  jal       atan2
/* B4B634 80240BC4 8C470030 */   lw       $a3, 0x30($v0)
/* B4B638 80240BC8 2402000C */  addiu     $v0, $zero, 0xc
/* B4B63C 80240BCC E600000C */  swc1      $f0, 0xc($s0)
/* B4B640 80240BD0 0809037A */  j         .L80240DE8
/* B4B644 80240BD4 AE620070 */   sw       $v0, 0x70($s3)
.L80240BD8:
/* B4B648 80240BD8 8E620074 */  lw        $v0, 0x74($s3)
/* B4B64C 80240BDC 2442FFFF */  addiu     $v0, $v0, -1
.L80240BE0:
/* B4B650 80240BE0 AE620074 */  sw        $v0, 0x74($s3)
.L80240BE4:
/* B4B654 80240BE4 C6000018 */  lwc1      $f0, 0x18($s0)
/* B4B658 80240BE8 44801000 */  mtc1      $zero, $f2
/* B4B65C 80240BEC 44801800 */  mtc1      $zero, $f3
/* B4B660 80240BF0 46000021 */  cvt.d.s   $f0, $f0
/* B4B664 80240BF4 4620103C */  c.lt.d    $f2, $f0
/* B4B668 80240BF8 00000000 */  nop
/* B4B66C 80240BFC 45000025 */  bc1f      .L80240C94
/* B4B670 80240C00 27A5002C */   addiu    $a1, $sp, 0x2c
/* B4B674 80240C04 C6000038 */  lwc1      $f0, 0x38($s0)
/* B4B678 80240C08 860200A6 */  lh        $v0, 0xa6($s0)
/* B4B67C 80240C0C 3C018024 */  lui       $at, %hi(D_80247A30_B524A0)
/* B4B680 80240C10 D4227A30 */  ldc1      $f2, %lo(D_80247A30_B524A0)($at)
/* B4B684 80240C14 27A60030 */  addiu     $a2, $sp, 0x30
/* B4B688 80240C18 E7A0002C */  swc1      $f0, 0x2c($sp)
/* B4B68C 80240C1C 44820000 */  mtc1      $v0, $f0
/* B4B690 80240C20 00000000 */  nop
/* B4B694 80240C24 46800020 */  cvt.s.w   $f0, $f0
/* B4B698 80240C28 46000021 */  cvt.d.s   $f0, $f0
/* B4B69C 80240C2C C604003C */  lwc1      $f4, 0x3c($s0)
/* B4B6A0 80240C30 C6060040 */  lwc1      $f6, 0x40($s0)
/* B4B6A4 80240C34 C6080018 */  lwc1      $f8, 0x18($s0)
/* B4B6A8 80240C38 860200A8 */  lh        $v0, 0xa8($s0)
/* B4B6AC 80240C3C 46220002 */  mul.d     $f0, $f0, $f2
/* B4B6B0 80240C40 00000000 */  nop
/* B4B6B4 80240C44 E7A40030 */  swc1      $f4, 0x30($sp)
/* B4B6B8 80240C48 E7A60034 */  swc1      $f6, 0x34($sp)
/* B4B6BC 80240C4C E7A80010 */  swc1      $f8, 0x10($sp)
/* B4B6C0 80240C50 C604000C */  lwc1      $f4, 0xc($s0)
/* B4B6C4 80240C54 44821000 */  mtc1      $v0, $f2
/* B4B6C8 80240C58 00000000 */  nop
/* B4B6CC 80240C5C 468010A0 */  cvt.s.w   $f2, $f2
/* B4B6D0 80240C60 E7A20018 */  swc1      $f2, 0x18($sp)
/* B4B6D4 80240C64 E7A40014 */  swc1      $f4, 0x14($sp)
/* B4B6D8 80240C68 46200020 */  cvt.s.d   $f0, $f0
/* B4B6DC 80240C6C E7A0001C */  swc1      $f0, 0x1c($sp)
/* B4B6E0 80240C70 8E040080 */  lw        $a0, 0x80($s0)
/* B4B6E4 80240C74 0C037711 */  jal       npc_test_move_simple_with_slipping
/* B4B6E8 80240C78 27A70034 */   addiu    $a3, $sp, 0x34
/* B4B6EC 80240C7C 54400005 */  bnel      $v0, $zero, .L80240C94
/* B4B6F0 80240C80 AE000018 */   sw       $zero, 0x18($s0)
/* B4B6F4 80240C84 8E050018 */  lw        $a1, 0x18($s0)
/* B4B6F8 80240C88 8E06000C */  lw        $a2, 0xc($s0)
/* B4B6FC 80240C8C 0C00EA95 */  jal       npc_move_heading
/* B4B700 80240C90 0200202D */   daddu    $a0, $s0, $zero
.L80240C94:
/* B4B704 80240C94 C600001C */  lwc1      $f0, 0x1c($s0)
/* B4B708 80240C98 44801000 */  mtc1      $zero, $f2
/* B4B70C 80240C9C 44801800 */  mtc1      $zero, $f3
/* B4B710 80240CA0 46000021 */  cvt.d.s   $f0, $f0
/* B4B714 80240CA4 4622003C */  c.lt.d    $f0, $f2
/* B4B718 80240CA8 00000000 */  nop
/* B4B71C 80240CAC 45000047 */  bc1f      .L80240DCC
/* B4B720 80240CB0 27A5002C */   addiu    $a1, $sp, 0x2c
/* B4B724 80240CB4 27A60030 */  addiu     $a2, $sp, 0x30
/* B4B728 80240CB8 27A20038 */  addiu     $v0, $sp, 0x38
/* B4B72C 80240CBC C602003C */  lwc1      $f2, 0x3c($s0)
/* B4B730 80240CC0 C6060038 */  lwc1      $f6, 0x38($s0)
/* B4B734 80240CC4 3C01402A */  lui       $at, 0x402a
/* B4B738 80240CC8 4481A800 */  mtc1      $at, $f21
/* B4B73C 80240CCC 4480A000 */  mtc1      $zero, $f20
/* B4B740 80240CD0 460010A1 */  cvt.d.s   $f2, $f2
/* B4B744 80240CD4 46341080 */  add.d     $f2, $f2, $f20
/* B4B748 80240CD8 C600001C */  lwc1      $f0, 0x1c($s0)
/* B4B74C 80240CDC C6040040 */  lwc1      $f4, 0x40($s0)
/* B4B750 80240CE0 46000005 */  abs.s     $f0, $f0
/* B4B754 80240CE4 E7A40034 */  swc1      $f4, 0x34($sp)
/* B4B758 80240CE8 3C014030 */  lui       $at, 0x4030
/* B4B75C 80240CEC 44812800 */  mtc1      $at, $f5
/* B4B760 80240CF0 44802000 */  mtc1      $zero, $f4
/* B4B764 80240CF4 46000021 */  cvt.d.s   $f0, $f0
/* B4B768 80240CF8 E7A6002C */  swc1      $f6, 0x2c($sp)
/* B4B76C 80240CFC 46240000 */  add.d     $f0, $f0, $f4
/* B4B770 80240D00 462010A0 */  cvt.s.d   $f2, $f2
/* B4B774 80240D04 E7A20030 */  swc1      $f2, 0x30($sp)
/* B4B778 80240D08 46200020 */  cvt.s.d   $f0, $f0
/* B4B77C 80240D0C E7A00038 */  swc1      $f0, 0x38($sp)
/* B4B780 80240D10 AFA20010 */  sw        $v0, 0x10($sp)
/* B4B784 80240D14 8E040080 */  lw        $a0, 0x80($s0)
/* B4B788 80240D18 0C0372DF */  jal       npc_raycast_down_sides
/* B4B78C 80240D1C 27A70034 */   addiu    $a3, $sp, 0x34
/* B4B790 80240D20 1040002A */  beqz      $v0, .L80240DCC
/* B4B794 80240D24 00000000 */   nop
/* B4B798 80240D28 C600001C */  lwc1      $f0, 0x1c($s0)
/* B4B79C 80240D2C C7A20038 */  lwc1      $f2, 0x38($sp)
/* B4B7A0 80240D30 46000005 */  abs.s     $f0, $f0
/* B4B7A4 80240D34 46000021 */  cvt.d.s   $f0, $f0
/* B4B7A8 80240D38 46340000 */  add.d     $f0, $f0, $f20
/* B4B7AC 80240D3C 460010A1 */  cvt.d.s   $f2, $f2
/* B4B7B0 80240D40 4620103E */  c.le.d    $f2, $f0
/* B4B7B4 80240D44 00000000 */  nop
/* B4B7B8 80240D48 45000020 */  bc1f      .L80240DCC
/* B4B7BC 80240D4C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* B4B7C0 80240D50 C7A00030 */  lwc1      $f0, 0x30($sp)
/* B4B7C4 80240D54 8E020000 */  lw        $v0, ($s0)
/* B4B7C8 80240D58 2403F7FF */  addiu     $v1, $zero, -0x801
/* B4B7CC 80240D5C AE00001C */  sw        $zero, 0x1c($s0)
/* B4B7D0 80240D60 00431024 */  and       $v0, $v0, $v1
/* B4B7D4 80240D64 AE020000 */  sw        $v0, ($s0)
/* B4B7D8 80240D68 24020002 */  addiu     $v0, $zero, 2
/* B4B7DC 80240D6C E600003C */  swc1      $f0, 0x3c($s0)
/* B4B7E0 80240D70 0C00A67F */  jal       rand_int
/* B4B7E4 80240D74 AE620070 */   sw       $v0, 0x70($s3)
/* B4B7E8 80240D78 3C035555 */  lui       $v1, 0x5555
/* B4B7EC 80240D7C 34635556 */  ori       $v1, $v1, 0x5556
/* B4B7F0 80240D80 00430018 */  mult      $v0, $v1
/* B4B7F4 80240D84 000227C3 */  sra       $a0, $v0, 0x1f
/* B4B7F8 80240D88 00004010 */  mfhi      $t0
/* B4B7FC 80240D8C 01042023 */  subu      $a0, $t0, $a0
/* B4B800 80240D90 00041840 */  sll       $v1, $a0, 1
/* B4B804 80240D94 00641821 */  addu      $v1, $v1, $a0
/* B4B808 80240D98 00431023 */  subu      $v0, $v0, $v1
/* B4B80C 80240D9C 24430002 */  addiu     $v1, $v0, 2
/* B4B810 80240DA0 AE630074 */  sw        $v1, 0x74($s3)
/* B4B814 80240DA4 8E82002C */  lw        $v0, 0x2c($s4)
/* B4B818 80240DA8 5840000F */  blezl     $v0, .L80240DE8
/* B4B81C 80240DAC AE600070 */   sw       $zero, 0x70($s3)
/* B4B820 80240DB0 8E820004 */  lw        $v0, 4($s4)
/* B4B824 80240DB4 5840000C */  blezl     $v0, .L80240DE8
/* B4B828 80240DB8 AE600070 */   sw       $zero, 0x70($s3)
/* B4B82C 80240DBC 1460000A */  bnez      $v1, .L80240DE8
/* B4B830 80240DC0 00000000 */   nop
/* B4B834 80240DC4 0809037A */  j         .L80240DE8
/* B4B838 80240DC8 AE600070 */   sw       $zero, 0x70($s3)
.L80240DCC:
/* B4B83C 80240DCC C604003C */  lwc1      $f4, 0x3c($s0)
/* B4B840 80240DD0 C600001C */  lwc1      $f0, 0x1c($s0)
/* B4B844 80240DD4 46002100 */  add.s     $f4, $f4, $f0
/* B4B848 80240DD8 C6020014 */  lwc1      $f2, 0x14($s0)
/* B4B84C 80240DDC 46020001 */  sub.s     $f0, $f0, $f2
/* B4B850 80240DE0 E604003C */  swc1      $f4, 0x3c($s0)
/* B4B854 80240DE4 E600001C */  swc1      $f0, 0x1c($s0)
.L80240DE8:
/* B4B858 80240DE8 8FBF0054 */  lw        $ra, 0x54($sp)
/* B4B85C 80240DEC 8FB40050 */  lw        $s4, 0x50($sp)
/* B4B860 80240DF0 8FB3004C */  lw        $s3, 0x4c($sp)
/* B4B864 80240DF4 8FB20048 */  lw        $s2, 0x48($sp)
/* B4B868 80240DF8 8FB10044 */  lw        $s1, 0x44($sp)
/* B4B86C 80240DFC 8FB00040 */  lw        $s0, 0x40($sp)
/* B4B870 80240E00 D7B40058 */  ldc1      $f20, 0x58($sp)
/* B4B874 80240E04 03E00008 */  jr        $ra
/* B4B878 80240E08 27BD0060 */   addiu    $sp, $sp, 0x60
