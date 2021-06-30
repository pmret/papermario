.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B5C_ACB67C
/* ACB67C 80240B5C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* ACB680 80240B60 AFB7004C */  sw        $s7, 0x4c($sp)
/* ACB684 80240B64 0080B82D */  daddu     $s7, $a0, $zero
/* ACB688 80240B68 AFBF0054 */  sw        $ra, 0x54($sp)
/* ACB68C 80240B6C AFBE0050 */  sw        $fp, 0x50($sp)
/* ACB690 80240B70 AFB60048 */  sw        $s6, 0x48($sp)
/* ACB694 80240B74 AFB50044 */  sw        $s5, 0x44($sp)
/* ACB698 80240B78 AFB40040 */  sw        $s4, 0x40($sp)
/* ACB69C 80240B7C AFB3003C */  sw        $s3, 0x3c($sp)
/* ACB6A0 80240B80 AFB20038 */  sw        $s2, 0x38($sp)
/* ACB6A4 80240B84 AFB10034 */  sw        $s1, 0x34($sp)
/* ACB6A8 80240B88 AFB00030 */  sw        $s0, 0x30($sp)
/* ACB6AC 80240B8C F7BA0070 */  sdc1      $f26, 0x70($sp)
/* ACB6B0 80240B90 F7B80068 */  sdc1      $f24, 0x68($sp)
/* ACB6B4 80240B94 F7B60060 */  sdc1      $f22, 0x60($sp)
/* ACB6B8 80240B98 F7B40058 */  sdc1      $f20, 0x58($sp)
/* ACB6BC 80240B9C 8EE20148 */  lw        $v0, 0x148($s7)
/* ACB6C0 80240BA0 0C00EABB */  jal       get_npc_unsafe
/* ACB6C4 80240BA4 84440008 */   lh       $a0, 8($v0)
/* ACB6C8 80240BA8 27B50020 */  addiu     $s5, $sp, 0x20
/* ACB6CC 80240BAC 02A0202D */  daddu     $a0, $s5, $zero
/* ACB6D0 80240BB0 0040882D */  daddu     $s1, $v0, $zero
/* ACB6D4 80240BB4 27B40024 */  addiu     $s4, $sp, 0x24
/* ACB6D8 80240BB8 8EE3000C */  lw        $v1, 0xc($s7)
/* ACB6DC 80240BBC 3C0641F0 */  lui       $a2, 0x41f0
/* ACB6E0 80240BC0 8E27000C */  lw        $a3, 0xc($s1)
/* ACB6E4 80240BC4 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACB6E8 80240BC8 C6220040 */  lwc1      $f2, 0x40($s1)
/* ACB6EC 80240BCC 8C7E0000 */  lw        $fp, ($v1)
/* ACB6F0 80240BD0 24630004 */  addiu     $v1, $v1, 4
/* ACB6F4 80240BD4 C4740000 */  lwc1      $f20, ($v1)
/* ACB6F8 80240BD8 4680A520 */  cvt.s.w   $f20, $f20
/* ACB6FC 80240BDC 24630004 */  addiu     $v1, $v1, 4
/* ACB700 80240BE0 C4760000 */  lwc1      $f22, ($v1)
/* ACB704 80240BE4 4680B5A0 */  cvt.s.w   $f22, $f22
/* ACB708 80240BE8 24630004 */  addiu     $v1, $v1, 4
/* ACB70C 80240BEC C4780000 */  lwc1      $f24, ($v1)
/* ACB710 80240BF0 4680C620 */  cvt.s.w   $f24, $f24
/* ACB714 80240BF4 24630004 */  addiu     $v1, $v1, 4
/* ACB718 80240BF8 C47A0000 */  lwc1      $f26, ($v1)
/* ACB71C 80240BFC 4680D6A0 */  cvt.s.w   $f26, $f26
/* ACB720 80240C00 24630004 */  addiu     $v1, $v1, 4
/* ACB724 80240C04 8C760000 */  lw        $s6, ($v1)
/* ACB728 80240C08 8C700004 */  lw        $s0, 4($v1)
/* ACB72C 80240C0C 0280282D */  daddu     $a1, $s4, $zero
/* ACB730 80240C10 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACB734 80240C14 0C00A7E7 */  jal       add_vec2D_polar
/* ACB738 80240C18 E7A20024 */   swc1     $f2, 0x24($sp)
/* ACB73C 80240C1C 3C038015 */  lui       $v1, %hi(D_80151328)
/* ACB740 80240C20 8C631328 */  lw        $v1, %lo(D_80151328)($v1)
/* ACB744 80240C24 C7A00020 */  lwc1      $f0, 0x20($sp)
/* ACB748 80240C28 3C0141A0 */  lui       $at, 0x41a0
/* ACB74C 80240C2C 44811000 */  mtc1      $at, $f2
/* ACB750 80240C30 00101040 */  sll       $v0, $s0, 1
/* ACB754 80240C34 00501021 */  addu      $v0, $v0, $s0
/* ACB758 80240C38 000210C0 */  sll       $v0, $v0, 3
/* ACB75C 80240C3C 24420004 */  addiu     $v0, $v0, 4
/* ACB760 80240C40 00621821 */  addu      $v1, $v1, $v0
/* ACB764 80240C44 E4600004 */  swc1      $f0, 4($v1)
/* ACB768 80240C48 C620003C */  lwc1      $f0, 0x3c($s1)
/* ACB76C 80240C4C 4406A000 */  mfc1      $a2, $f20
/* ACB770 80240C50 46020000 */  add.s     $f0, $f0, $f2
/* ACB774 80240C54 C7A20024 */  lwc1      $f2, 0x24($sp)
/* ACB778 80240C58 02A0202D */  daddu     $a0, $s5, $zero
/* ACB77C 80240C5C E462000C */  swc1      $f2, 0xc($v1)
/* ACB780 80240C60 E4600008 */  swc1      $f0, 8($v1)
/* ACB784 80240C64 8E27000C */  lw        $a3, 0xc($s1)
/* ACB788 80240C68 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACB78C 80240C6C C6220040 */  lwc1      $f2, 0x40($s1)
/* ACB790 80240C70 0280282D */  daddu     $a1, $s4, $zero
/* ACB794 80240C74 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACB798 80240C78 0C00A7E7 */  jal       add_vec2D_polar
/* ACB79C 80240C7C E7A20024 */   swc1     $f2, 0x24($sp)
/* ACB7A0 80240C80 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* ACB7A4 80240C84 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* ACB7A8 80240C88 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACB7AC 80240C8C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACB7B0 80240C90 8E460028 */  lw        $a2, 0x28($s2)
/* ACB7B4 80240C94 8E470030 */  lw        $a3, 0x30($s2)
/* ACB7B8 80240C98 0C00A7B5 */  jal       dist2D
/* ACB7BC 80240C9C 0000802D */   daddu    $s0, $zero, $zero
/* ACB7C0 80240CA0 4616003E */  c.le.s    $f0, $f22
/* ACB7C4 80240CA4 00000000 */  nop
/* ACB7C8 80240CA8 45000002 */  bc1f      .L80240CB4
/* ACB7CC 80240CAC 0240982D */   daddu    $s3, $s2, $zero
/* ACB7D0 80240CB0 24100001 */  addiu     $s0, $zero, 1
.L80240CB4:
/* ACB7D4 80240CB4 4600B021 */  cvt.d.s   $f0, $f22
/* ACB7D8 80240CB8 46200000 */  add.d     $f0, $f0, $f0
/* ACB7DC 80240CBC 3C014059 */  lui       $at, 0x4059
/* ACB7E0 80240CC0 44811800 */  mtc1      $at, $f3
/* ACB7E4 80240CC4 44801000 */  mtc1      $zero, $f2
/* ACB7E8 80240CC8 3C018024 */  lui       $at, %hi(D_80243610_ACE130)
/* ACB7EC 80240CCC D4243610 */  ldc1      $f4, %lo(D_80243610_ACE130)($at)
/* ACB7F0 80240CD0 46220003 */  div.d     $f0, $f0, $f2
/* ACB7F4 80240CD4 46240000 */  add.d     $f0, $f0, $f4
/* ACB7F8 80240CD8 C7A20020 */  lwc1      $f2, 0x20($sp)
/* ACB7FC 80240CDC C7A40024 */  lwc1      $f4, 0x24($sp)
/* ACB800 80240CE0 44051000 */  mfc1      $a1, $f2
/* ACB804 80240CE4 44072000 */  mfc1      $a3, $f4
/* ACB808 80240CE8 46200020 */  cvt.s.d   $f0, $f0
/* ACB80C 80240CEC E7A00010 */  swc1      $f0, 0x10($sp)
/* ACB810 80240CF0 8E26003C */  lw        $a2, 0x3c($s1)
/* ACB814 80240CF4 0C0902AC */  jal       func_80240AB0_ACB5D0
/* ACB818 80240CF8 02C0202D */   daddu    $a0, $s6, $zero
/* ACB81C 80240CFC 02A0202D */  daddu     $a0, $s5, $zero
/* ACB820 80240D00 4406C000 */  mfc1      $a2, $f24
/* ACB824 80240D04 8E27000C */  lw        $a3, 0xc($s1)
/* ACB828 80240D08 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACB82C 80240D0C C6220040 */  lwc1      $f2, 0x40($s1)
/* ACB830 80240D10 0280282D */  daddu     $a1, $s4, $zero
/* ACB834 80240D14 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACB838 80240D18 0C00A7E7 */  jal       add_vec2D_polar
/* ACB83C 80240D1C E7A20024 */   swc1     $f2, 0x24($sp)
/* ACB840 80240D20 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACB844 80240D24 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACB848 80240D28 8E460028 */  lw        $a2, 0x28($s2)
/* ACB84C 80240D2C 0C00A7B5 */  jal       dist2D
/* ACB850 80240D30 8E470030 */   lw       $a3, 0x30($s2)
/* ACB854 80240D34 461A003E */  c.le.s    $f0, $f26
/* ACB858 80240D38 00000000 */  nop
/* ACB85C 80240D3C 45030001 */  bc1tl     .L80240D44
/* ACB860 80240D40 36100010 */   ori      $s0, $s0, 0x10
.L80240D44:
/* ACB864 80240D44 32020001 */  andi      $v0, $s0, 1
/* ACB868 80240D48 10400026 */  beqz      $v0, .L80240DE4
/* ACB86C 80240D4C 02E0202D */   daddu    $a0, $s7, $zero
/* ACB870 80240D50 C62C0038 */  lwc1      $f12, 0x38($s1)
/* ACB874 80240D54 C62E0040 */  lwc1      $f14, 0x40($s1)
/* ACB878 80240D58 8E660028 */  lw        $a2, 0x28($s3)
/* ACB87C 80240D5C 8E670030 */  lw        $a3, 0x30($s3)
/* ACB880 80240D60 C622003C */  lwc1      $f2, 0x3c($s1)
/* ACB884 80240D64 46006006 */  mov.s     $f0, $f12
/* ACB888 80240D68 46007106 */  mov.s     $f4, $f14
/* ACB88C 80240D6C E7A00020 */  swc1      $f0, 0x20($sp)
/* ACB890 80240D70 E7A20028 */  swc1      $f2, 0x28($sp)
/* ACB894 80240D74 0C00A7B5 */  jal       dist2D
/* ACB898 80240D78 E7A40024 */   swc1     $f4, 0x24($sp)
/* ACB89C 80240D7C C62C0038 */  lwc1      $f12, 0x38($s1)
/* ACB8A0 80240D80 C62E0040 */  lwc1      $f14, 0x40($s1)
/* ACB8A4 80240D84 8E660028 */  lw        $a2, 0x28($s3)
/* ACB8A8 80240D88 8E670030 */  lw        $a3, 0x30($s3)
/* ACB8AC 80240D8C 0C00A720 */  jal       atan2
/* ACB8B0 80240D90 46000506 */   mov.s    $f20, $f0
/* ACB8B4 80240D94 0000202D */  daddu     $a0, $zero, $zero
/* ACB8B8 80240D98 02A0282D */  daddu     $a1, $s5, $zero
/* ACB8BC 80240D9C E7B40010 */  swc1      $f20, 0x10($sp)
/* ACB8C0 80240DA0 E7A00014 */  swc1      $f0, 0x14($sp)
/* ACB8C4 80240DA4 862200A6 */  lh        $v0, 0xa6($s1)
/* ACB8C8 80240DA8 27A60028 */  addiu     $a2, $sp, 0x28
/* ACB8CC 80240DAC 44820000 */  mtc1      $v0, $f0
/* ACB8D0 80240DB0 00000000 */  nop
/* ACB8D4 80240DB4 46800020 */  cvt.s.w   $f0, $f0
/* ACB8D8 80240DB8 E7A00018 */  swc1      $f0, 0x18($sp)
/* ACB8DC 80240DBC 862200A8 */  lh        $v0, 0xa8($s1)
/* ACB8E0 80240DC0 0280382D */  daddu     $a3, $s4, $zero
/* ACB8E4 80240DC4 44820000 */  mtc1      $v0, $f0
/* ACB8E8 80240DC8 00000000 */  nop
/* ACB8EC 80240DCC 46800020 */  cvt.s.w   $f0, $f0
/* ACB8F0 80240DD0 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* ACB8F4 80240DD4 E7A0001C */   swc1     $f0, 0x1c($sp)
/* ACB8F8 80240DD8 54400001 */  bnel      $v0, $zero, .L80240DE0
/* ACB8FC 80240DDC 0000802D */   daddu    $s0, $zero, $zero
.L80240DE0:
/* ACB900 80240DE0 02E0202D */  daddu     $a0, $s7, $zero
.L80240DE4:
/* ACB904 80240DE4 03C0282D */  daddu     $a1, $fp, $zero
/* ACB908 80240DE8 0C0B2026 */  jal       set_variable
/* ACB90C 80240DEC 0200302D */   daddu    $a2, $s0, $zero
/* ACB910 80240DF0 8FBF0054 */  lw        $ra, 0x54($sp)
/* ACB914 80240DF4 8FBE0050 */  lw        $fp, 0x50($sp)
/* ACB918 80240DF8 8FB7004C */  lw        $s7, 0x4c($sp)
/* ACB91C 80240DFC 8FB60048 */  lw        $s6, 0x48($sp)
/* ACB920 80240E00 8FB50044 */  lw        $s5, 0x44($sp)
/* ACB924 80240E04 8FB40040 */  lw        $s4, 0x40($sp)
/* ACB928 80240E08 8FB3003C */  lw        $s3, 0x3c($sp)
/* ACB92C 80240E0C 8FB20038 */  lw        $s2, 0x38($sp)
/* ACB930 80240E10 8FB10034 */  lw        $s1, 0x34($sp)
/* ACB934 80240E14 8FB00030 */  lw        $s0, 0x30($sp)
/* ACB938 80240E18 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* ACB93C 80240E1C D7B80068 */  ldc1      $f24, 0x68($sp)
/* ACB940 80240E20 D7B60060 */  ldc1      $f22, 0x60($sp)
/* ACB944 80240E24 D7B40058 */  ldc1      $f20, 0x58($sp)
/* ACB948 80240E28 24020002 */  addiu     $v0, $zero, 2
/* ACB94C 80240E2C 03E00008 */  jr        $ra
/* ACB950 80240E30 27BD0078 */   addiu    $sp, $sp, 0x78
