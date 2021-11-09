.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024082C_E05B8C
/* E05B8C 8024082C 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* E05B90 80240830 AFB200D0 */  sw        $s2, 0xd0($sp)
/* E05B94 80240834 0080902D */  daddu     $s2, $a0, $zero
/* E05B98 80240838 AFB000C8 */  sw        $s0, 0xc8($sp)
/* E05B9C 8024083C 00A0802D */  daddu     $s0, $a1, $zero
/* E05BA0 80240840 AFBF00E0 */  sw        $ra, 0xe0($sp)
/* E05BA4 80240844 AFB500DC */  sw        $s5, 0xdc($sp)
/* E05BA8 80240848 AFB400D8 */  sw        $s4, 0xd8($sp)
/* E05BAC 8024084C AFB300D4 */  sw        $s3, 0xd4($sp)
/* E05BB0 80240850 AFB100CC */  sw        $s1, 0xcc($sp)
/* E05BB4 80240854 F7BC0108 */  sdc1      $f28, 0x108($sp)
/* E05BB8 80240858 F7BA0100 */  sdc1      $f26, 0x100($sp)
/* E05BBC 8024085C F7B800F8 */  sdc1      $f24, 0xf8($sp)
/* E05BC0 80240860 F7B600F0 */  sdc1      $f22, 0xf0($sp)
/* E05BC4 80240864 F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* E05BC8 80240868 C6180010 */  lwc1      $f24, 0x10($s0)
/* E05BCC 8024086C 4680C620 */  cvt.s.w   $f24, $f24
/* E05BD0 80240870 3C054200 */  lui       $a1, 0x4200
/* E05BD4 80240874 3C064396 */  lui       $a2, 0x4396
/* E05BD8 80240878 8E42001C */  lw        $v0, 0x1c($s2)
/* E05BDC 8024087C C61C0014 */  lwc1      $f28, 0x14($s0)
/* E05BE0 80240880 4680E720 */  cvt.s.w   $f28, $f28
/* E05BE4 80240884 AFA20010 */  sw        $v0, 0x10($sp)
/* E05BE8 80240888 8E070018 */  lw        $a3, 0x18($s0)
/* E05BEC 8024088C 0C00A8ED */  jal       update_lerp
/* E05BF0 80240890 2404000C */   addiu    $a0, $zero, 0xc
/* E05BF4 80240894 3C01437F */  lui       $at, 0x437f
/* E05BF8 80240898 44811000 */  mtc1      $at, $f2
/* E05BFC 8024089C 00000000 */  nop
/* E05C00 802408A0 4600103C */  c.lt.s    $f2, $f0
/* E05C04 802408A4 00000000 */  nop
/* E05C08 802408A8 45000002 */  bc1f      .L802408B4
/* E05C0C 802408AC 27B10038 */   addiu    $s1, $sp, 0x38
/* E05C10 802408B0 46001006 */  mov.s     $f0, $f2
.L802408B4:
/* E05C14 802408B4 4600010D */  trunc.w.s $f4, $f0
/* E05C18 802408B8 E7A40014 */  swc1      $f4, 0x14($sp)
/* E05C1C 802408BC 0000202D */  daddu     $a0, $zero, $zero
/* E05C20 802408C0 24050007 */  addiu     $a1, $zero, 7
/* E05C24 802408C4 240600FF */  addiu     $a2, $zero, 0xff
/* E05C28 802408C8 00C0382D */  daddu     $a3, $a2, $zero
/* E05C2C 802408CC 00C0A82D */  daddu     $s5, $a2, $zero
/* E05C30 802408D0 AFB50010 */  sw        $s5, 0x10($sp)
/* E05C34 802408D4 0C04EAA7 */  jal       sprfx_update
/* E05C38 802408D8 AFA00018 */   sw       $zero, 0x18($sp)
/* E05C3C 802408DC 8E42001C */  lw        $v0, 0x1c($s2)
/* E05C40 802408E0 3C05C296 */  lui       $a1, 0xc296
/* E05C44 802408E4 3C0641F0 */  lui       $a2, 0x41f0
/* E05C48 802408E8 AFA20010 */  sw        $v0, 0x10($sp)
/* E05C4C 802408EC 8E070018 */  lw        $a3, 0x18($s0)
/* E05C50 802408F0 0C00A8ED */  jal       update_lerp
/* E05C54 802408F4 0000202D */   daddu    $a0, $zero, $zero
/* E05C58 802408F8 4480B000 */  mtc1      $zero, $f22
/* E05C5C 802408FC 46000506 */  mov.s     $f20, $f0
/* E05C60 80240900 4614B03E */  c.le.s    $f22, $f20
/* E05C64 80240904 00000000 */  nop
/* E05C68 80240908 45030001 */  bc1tl     .L80240910
/* E05C6C 8024090C 4600B506 */   mov.s    $f20, $f22
.L80240910:
/* E05C70 80240910 AFB10010 */  sw        $s1, 0x10($sp)
/* E05C74 80240914 8E040004 */  lw        $a0, 4($s0)
/* E05C78 80240918 8E050008 */  lw        $a1, 8($s0)
/* E05C7C 8024091C 8E060000 */  lw        $a2, ($s0)
/* E05C80 80240920 0C04BA38 */  jal       msg_get_glyph
/* E05C84 80240924 8E07000C */   lw       $a3, 0xc($s0)
/* E05C88 80240928 93A20042 */  lbu       $v0, 0x42($sp)
/* E05C8C 8024092C 3C013FE0 */  lui       $at, 0x3fe0
/* E05C90 80240930 4481D800 */  mtc1      $at, $f27
/* E05C94 80240934 4480D000 */  mtc1      $zero, $f26
/* E05C98 80240938 44820000 */  mtc1      $v0, $f0
/* E05C9C 8024093C 00000000 */  nop
/* E05CA0 80240940 46800021 */  cvt.d.w   $f0, $f0
/* E05CA4 80240944 463A0002 */  mul.d     $f0, $f0, $f26
/* E05CA8 80240948 00000000 */  nop
/* E05CAC 8024094C 4600C0A1 */  cvt.d.s   $f2, $f24
/* E05CB0 80240950 27B40048 */  addiu     $s4, $sp, 0x48
/* E05CB4 80240954 4600E707 */  neg.s     $f28, $f28
/* E05CB8 80240958 46201080 */  add.d     $f2, $f2, $f0
/* E05CBC 8024095C 4406E000 */  mfc1      $a2, $f28
/* E05CC0 80240960 4407B000 */  mfc1      $a3, $f22
/* E05CC4 80240964 462010A0 */  cvt.s.d   $f2, $f2
/* E05CC8 80240968 44051000 */  mfc1      $a1, $f2
/* E05CCC 8024096C 0C019E40 */  jal       guTranslateF
/* E05CD0 80240970 0280202D */   daddu    $a0, $s4, $zero
/* E05CD4 80240974 4616A032 */  c.eq.s    $f20, $f22
/* E05CD8 80240978 00000000 */  nop
/* E05CDC 8024097C 4501000D */  bc1t      .L802409B4
/* E05CE0 80240980 3C130001 */   lui      $s3, 1
/* E05CE4 80240984 27B00088 */  addiu     $s0, $sp, 0x88
/* E05CE8 80240988 4405A000 */  mfc1      $a1, $f20
/* E05CEC 8024098C 4406B000 */  mfc1      $a2, $f22
/* E05CF0 80240990 3C073F80 */  lui       $a3, 0x3f80
/* E05CF4 80240994 0200202D */  daddu     $a0, $s0, $zero
/* E05CF8 80240998 0C019EC8 */  jal       guRotateF
/* E05CFC 8024099C AFA60010 */   sw       $a2, 0x10($sp)
/* E05D00 802409A0 0200202D */  daddu     $a0, $s0, $zero
/* E05D04 802409A4 0280282D */  daddu     $a1, $s4, $zero
/* E05D08 802409A8 0C019D80 */  jal       guMtxCatF
/* E05D0C 802409AC 0280302D */   daddu    $a2, $s4, $zero
/* E05D10 802409B0 3C130001 */  lui       $s3, 1
.L802409B4:
/* E05D14 802409B4 36731630 */  ori       $s3, $s3, 0x1630
/* E05D18 802409B8 0280202D */  daddu     $a0, $s4, $zero
/* E05D1C 802409BC 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* E05D20 802409C0 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* E05D24 802409C4 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* E05D28 802409C8 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* E05D2C 802409CC 96250000 */  lhu       $a1, ($s1)
/* E05D30 802409D0 8E420000 */  lw        $v0, ($s2)
/* E05D34 802409D4 00052980 */  sll       $a1, $a1, 6
/* E05D38 802409D8 00B32821 */  addu      $a1, $a1, $s3
/* E05D3C 802409DC 0C019D40 */  jal       guMtxF2L
/* E05D40 802409E0 00452821 */   addu     $a1, $v0, $a1
/* E05D44 802409E4 3C03DA38 */  lui       $v1, 0xda38
/* E05D48 802409E8 34630002 */  ori       $v1, $v1, 2
/* E05D4C 802409EC 0000202D */  daddu     $a0, $zero, $zero
/* E05D50 802409F0 27A50020 */  addiu     $a1, $sp, 0x20
/* E05D54 802409F4 3C060001 */  lui       $a2, 1
/* E05D58 802409F8 34C60040 */  ori       $a2, $a2, 0x40
/* E05D5C 802409FC 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* E05D60 80240A00 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* E05D64 80240A04 0280382D */  daddu     $a3, $s4, $zero
/* E05D68 80240A08 8E020000 */  lw        $v0, ($s0)
/* E05D6C 80240A0C 96280000 */  lhu       $t0, ($s1)
/* E05D70 80240A10 0040482D */  daddu     $t1, $v0, $zero
/* E05D74 80240A14 24420008 */  addiu     $v0, $v0, 8
/* E05D78 80240A18 AE020000 */  sw        $v0, ($s0)
/* E05D7C 80240A1C 3102FFFF */  andi      $v0, $t0, 0xffff
/* E05D80 80240A20 00021180 */  sll       $v0, $v0, 6
/* E05D84 80240A24 00531021 */  addu      $v0, $v0, $s3
/* E05D88 80240A28 AD230000 */  sw        $v1, ($t1)
/* E05D8C 80240A2C 8E430000 */  lw        $v1, ($s2)
/* E05D90 80240A30 25080001 */  addiu     $t0, $t0, 1
/* E05D94 80240A34 00621821 */  addu      $v1, $v1, $v0
/* E05D98 80240A38 3C028000 */  lui       $v0, 0x8000
/* E05D9C 80240A3C 00621821 */  addu      $v1, $v1, $v0
/* E05DA0 80240A40 AD230004 */  sw        $v1, 4($t1)
/* E05DA4 80240A44 93A20042 */  lbu       $v0, 0x42($sp)
/* E05DA8 80240A48 8FA3003C */  lw        $v1, 0x3c($sp)
/* E05DAC 80240A4C 93A90040 */  lbu       $t1, 0x40($sp)
/* E05DB0 80240A50 93AA0041 */  lbu       $t2, 0x41($sp)
/* E05DB4 80240A54 44820000 */  mtc1      $v0, $f0
/* E05DB8 80240A58 00000000 */  nop
/* E05DBC 80240A5C 46800021 */  cvt.d.w   $f0, $f0
/* E05DC0 80240A60 8FA20038 */  lw        $v0, 0x38($sp)
/* E05DC4 80240A64 463A0002 */  mul.d     $f0, $f0, $f26
/* E05DC8 80240A68 00000000 */  nop
/* E05DCC 80240A6C A6280000 */  sh        $t0, ($s1)
/* E05DD0 80240A70 A7A0002E */  sh        $zero, 0x2e($sp)
/* E05DD4 80240A74 A3B50030 */  sb        $s5, 0x30($sp)
/* E05DD8 80240A78 AFA30024 */  sw        $v1, 0x24($sp)
/* E05DDC 80240A7C A7A90028 */  sh        $t1, 0x28($sp)
/* E05DE0 80240A80 A7AA002A */  sh        $t2, 0x2a($sp)
/* E05DE4 80240A84 AFA20020 */  sw        $v0, 0x20($sp)
/* E05DE8 80240A88 46200007 */  neg.d     $f0, $f0
/* E05DEC 80240A8C 4620010D */  trunc.w.d $f4, $f0
/* E05DF0 80240A90 44022000 */  mfc1      $v0, $f4
/* E05DF4 80240A94 0C04EBDC */  jal       sprfx_appendGfx_component
/* E05DF8 80240A98 A7A2002C */   sh       $v0, 0x2c($sp)
/* E05DFC 80240A9C 3C04D838 */  lui       $a0, 0xd838
/* E05E00 80240AA0 8E020000 */  lw        $v0, ($s0)
/* E05E04 80240AA4 34840002 */  ori       $a0, $a0, 2
/* E05E08 80240AA8 0040182D */  daddu     $v1, $v0, $zero
/* E05E0C 80240AAC 24420008 */  addiu     $v0, $v0, 8
/* E05E10 80240AB0 AE020000 */  sw        $v0, ($s0)
/* E05E14 80240AB4 24020040 */  addiu     $v0, $zero, 0x40
/* E05E18 80240AB8 AC640000 */  sw        $a0, ($v1)
/* E05E1C 80240ABC AC620004 */  sw        $v0, 4($v1)
/* E05E20 80240AC0 8FBF00E0 */  lw        $ra, 0xe0($sp)
/* E05E24 80240AC4 8FB500DC */  lw        $s5, 0xdc($sp)
/* E05E28 80240AC8 8FB400D8 */  lw        $s4, 0xd8($sp)
/* E05E2C 80240ACC 8FB300D4 */  lw        $s3, 0xd4($sp)
/* E05E30 80240AD0 8FB200D0 */  lw        $s2, 0xd0($sp)
/* E05E34 80240AD4 8FB100CC */  lw        $s1, 0xcc($sp)
/* E05E38 80240AD8 8FB000C8 */  lw        $s0, 0xc8($sp)
/* E05E3C 80240ADC D7BC0108 */  ldc1      $f28, 0x108($sp)
/* E05E40 80240AE0 D7BA0100 */  ldc1      $f26, 0x100($sp)
/* E05E44 80240AE4 D7B800F8 */  ldc1      $f24, 0xf8($sp)
/* E05E48 80240AE8 D7B600F0 */  ldc1      $f22, 0xf0($sp)
/* E05E4C 80240AEC D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* E05E50 80240AF0 03E00008 */  jr        $ra
/* E05E54 80240AF4 27BD0110 */   addiu    $sp, $sp, 0x110
