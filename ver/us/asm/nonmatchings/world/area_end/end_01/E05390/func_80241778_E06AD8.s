.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241778_E06AD8
/* E06AD8 80241778 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* E06ADC 8024177C AFB100CC */  sw        $s1, 0xcc($sp)
/* E06AE0 80241780 0080882D */  daddu     $s1, $a0, $zero
/* E06AE4 80241784 AFB000C8 */  sw        $s0, 0xc8($sp)
/* E06AE8 80241788 00A0802D */  daddu     $s0, $a1, $zero
/* E06AEC 8024178C AFBF00E0 */  sw        $ra, 0xe0($sp)
/* E06AF0 80241790 AFB500DC */  sw        $s5, 0xdc($sp)
/* E06AF4 80241794 AFB400D8 */  sw        $s4, 0xd8($sp)
/* E06AF8 80241798 AFB300D4 */  sw        $s3, 0xd4($sp)
/* E06AFC 8024179C AFB200D0 */  sw        $s2, 0xd0($sp)
/* E06B00 802417A0 F7BC0108 */  sdc1      $f28, 0x108($sp)
/* E06B04 802417A4 F7BA0100 */  sdc1      $f26, 0x100($sp)
/* E06B08 802417A8 F7B800F8 */  sdc1      $f24, 0xf8($sp)
/* E06B0C 802417AC F7B600F0 */  sdc1      $f22, 0xf0($sp)
/* E06B10 802417B0 F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* E06B14 802417B4 C6140010 */  lwc1      $f20, 0x10($s0)
/* E06B18 802417B8 4680A520 */  cvt.s.w   $f20, $f20
/* E06B1C 802417BC 4480B000 */  mtc1      $zero, $f22
/* E06B20 802417C0 3C05437F */  lui       $a1, 0x437f
/* E06B24 802417C4 8E220050 */  lw        $v0, 0x50($s1)
/* E06B28 802417C8 4406B000 */  mfc1      $a2, $f22
/* E06B2C 802417CC C61C0014 */  lwc1      $f28, 0x14($s0)
/* E06B30 802417D0 4680E720 */  cvt.s.w   $f28, $f28
/* E06B34 802417D4 AFA20010 */  sw        $v0, 0x10($sp)
/* E06B38 802417D8 8E070018 */  lw        $a3, 0x18($s0)
/* E06B3C 802417DC 0C00A8ED */  jal       update_lerp
/* E06B40 802417E0 2404000B */   addiu    $a0, $zero, 0xb
/* E06B44 802417E4 4600008D */  trunc.w.s $f2, $f0
/* E06B48 802417E8 E7A20014 */  swc1      $f2, 0x14($sp)
/* E06B4C 802417EC 0000202D */  daddu     $a0, $zero, $zero
/* E06B50 802417F0 24050007 */  addiu     $a1, $zero, 7
/* E06B54 802417F4 240600FF */  addiu     $a2, $zero, 0xff
/* E06B58 802417F8 00C0382D */  daddu     $a3, $a2, $zero
/* E06B5C 802417FC 00C0A82D */  daddu     $s5, $a2, $zero
/* E06B60 80241800 AFB50010 */  sw        $s5, 0x10($sp)
/* E06B64 80241804 0C04EAA7 */  jal       sprfx_update
/* E06B68 80241808 AFA00018 */   sw       $zero, 0x18($sp)
/* E06B6C 8024180C 8E220050 */  lw        $v0, 0x50($s1)
/* E06B70 80241810 4405B000 */  mfc1      $a1, $f22
/* E06B74 80241814 3C064270 */  lui       $a2, 0x4270
/* E06B78 80241818 AFA20010 */  sw        $v0, 0x10($sp)
/* E06B7C 8024181C 8E070018 */  lw        $a3, 0x18($s0)
/* E06B80 80241820 0C00A8ED */  jal       update_lerp
/* E06B84 80241824 0000202D */   daddu    $a0, $zero, $zero
/* E06B88 80241828 27A20038 */  addiu     $v0, $sp, 0x38
/* E06B8C 8024182C AFA20010 */  sw        $v0, 0x10($sp)
/* E06B90 80241830 8E040004 */  lw        $a0, 4($s0)
/* E06B94 80241834 8E050008 */  lw        $a1, 8($s0)
/* E06B98 80241838 8E060000 */  lw        $a2, ($s0)
/* E06B9C 8024183C 8E07000C */  lw        $a3, 0xc($s0)
/* E06BA0 80241840 0C04BA38 */  jal       msg_get_glyph
/* E06BA4 80241844 46000606 */   mov.s    $f24, $f0
/* E06BA8 80241848 93A20042 */  lbu       $v0, 0x42($sp)
/* E06BAC 8024184C 3C013FE0 */  lui       $at, 0x3fe0
/* E06BB0 80241850 4481D800 */  mtc1      $at, $f27
/* E06BB4 80241854 4480D000 */  mtc1      $zero, $f26
/* E06BB8 80241858 44820000 */  mtc1      $v0, $f0
/* E06BBC 8024185C 00000000 */  nop
/* E06BC0 80241860 46800021 */  cvt.d.w   $f0, $f0
/* E06BC4 80241864 463A0002 */  mul.d     $f0, $f0, $f26
/* E06BC8 80241868 00000000 */  nop
/* E06BCC 8024186C 3C140001 */  lui       $s4, 1
/* E06BD0 80241870 36941630 */  ori       $s4, $s4, 0x1630
/* E06BD4 80241874 4600A521 */  cvt.d.s   $f20, $f20
/* E06BD8 80241878 27B10048 */  addiu     $s1, $sp, 0x48
/* E06BDC 8024187C 4600E707 */  neg.s     $f28, $f28
/* E06BE0 80241880 4620A500 */  add.d     $f20, $f20, $f0
/* E06BE4 80241884 4406E000 */  mfc1      $a2, $f28
/* E06BE8 80241888 4407B000 */  mfc1      $a3, $f22
/* E06BEC 8024188C 4620A520 */  cvt.s.d   $f20, $f20
/* E06BF0 80241890 4405A000 */  mfc1      $a1, $f20
/* E06BF4 80241894 0C019E40 */  jal       guTranslateF
/* E06BF8 80241898 0220202D */   daddu    $a0, $s1, $zero
/* E06BFC 8024189C 27B00088 */  addiu     $s0, $sp, 0x88
/* E06C00 802418A0 4405C000 */  mfc1      $a1, $f24
/* E06C04 802418A4 4406B000 */  mfc1      $a2, $f22
/* E06C08 802418A8 3C073F80 */  lui       $a3, 0x3f80
/* E06C0C 802418AC 0200202D */  daddu     $a0, $s0, $zero
/* E06C10 802418B0 0C019EC8 */  jal       guRotateF
/* E06C14 802418B4 AFA60010 */   sw       $a2, 0x10($sp)
/* E06C18 802418B8 0200202D */  daddu     $a0, $s0, $zero
/* E06C1C 802418BC 0220282D */  daddu     $a1, $s1, $zero
/* E06C20 802418C0 0C019D80 */  jal       guMtxCatF
/* E06C24 802418C4 0220302D */   daddu    $a2, $s1, $zero
/* E06C28 802418C8 0220202D */  daddu     $a0, $s1, $zero
/* E06C2C 802418CC 3C128007 */  lui       $s2, %hi(gMatrixListPos)
/* E06C30 802418D0 265241F0 */  addiu     $s2, $s2, %lo(gMatrixListPos)
/* E06C34 802418D4 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* E06C38 802418D8 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* E06C3C 802418DC 96450000 */  lhu       $a1, ($s2)
/* E06C40 802418E0 8E620000 */  lw        $v0, ($s3)
/* E06C44 802418E4 00052980 */  sll       $a1, $a1, 6
/* E06C48 802418E8 00B42821 */  addu      $a1, $a1, $s4
/* E06C4C 802418EC 0C019D40 */  jal       guMtxF2L
/* E06C50 802418F0 00452821 */   addu     $a1, $v0, $a1
/* E06C54 802418F4 3C03DA38 */  lui       $v1, 0xda38
/* E06C58 802418F8 34630002 */  ori       $v1, $v1, 2
/* E06C5C 802418FC 0000202D */  daddu     $a0, $zero, $zero
/* E06C60 80241900 27A50020 */  addiu     $a1, $sp, 0x20
/* E06C64 80241904 3C060001 */  lui       $a2, 1
/* E06C68 80241908 34C60040 */  ori       $a2, $a2, 0x40
/* E06C6C 8024190C 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* E06C70 80241910 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* E06C74 80241914 0220382D */  daddu     $a3, $s1, $zero
/* E06C78 80241918 8E020000 */  lw        $v0, ($s0)
/* E06C7C 8024191C 96480000 */  lhu       $t0, ($s2)
/* E06C80 80241920 0040482D */  daddu     $t1, $v0, $zero
/* E06C84 80241924 24420008 */  addiu     $v0, $v0, 8
/* E06C88 80241928 AE020000 */  sw        $v0, ($s0)
/* E06C8C 8024192C 3102FFFF */  andi      $v0, $t0, 0xffff
/* E06C90 80241930 00021180 */  sll       $v0, $v0, 6
/* E06C94 80241934 00541021 */  addu      $v0, $v0, $s4
/* E06C98 80241938 AD230000 */  sw        $v1, ($t1)
/* E06C9C 8024193C 8E630000 */  lw        $v1, ($s3)
/* E06CA0 80241940 25080001 */  addiu     $t0, $t0, 1
/* E06CA4 80241944 00621821 */  addu      $v1, $v1, $v0
/* E06CA8 80241948 3C028000 */  lui       $v0, 0x8000
/* E06CAC 8024194C 00621821 */  addu      $v1, $v1, $v0
/* E06CB0 80241950 AD230004 */  sw        $v1, 4($t1)
/* E06CB4 80241954 93A20042 */  lbu       $v0, 0x42($sp)
/* E06CB8 80241958 8FA3003C */  lw        $v1, 0x3c($sp)
/* E06CBC 8024195C 93A90040 */  lbu       $t1, 0x40($sp)
/* E06CC0 80241960 93AA0041 */  lbu       $t2, 0x41($sp)
/* E06CC4 80241964 44820000 */  mtc1      $v0, $f0
/* E06CC8 80241968 00000000 */  nop
/* E06CCC 8024196C 46800021 */  cvt.d.w   $f0, $f0
/* E06CD0 80241970 8FA20038 */  lw        $v0, 0x38($sp)
/* E06CD4 80241974 463A0002 */  mul.d     $f0, $f0, $f26
/* E06CD8 80241978 00000000 */  nop
/* E06CDC 8024197C A6480000 */  sh        $t0, ($s2)
/* E06CE0 80241980 A7A0002E */  sh        $zero, 0x2e($sp)
/* E06CE4 80241984 A3B50030 */  sb        $s5, 0x30($sp)
/* E06CE8 80241988 AFA30024 */  sw        $v1, 0x24($sp)
/* E06CEC 8024198C A7A90028 */  sh        $t1, 0x28($sp)
/* E06CF0 80241990 A7AA002A */  sh        $t2, 0x2a($sp)
/* E06CF4 80241994 AFA20020 */  sw        $v0, 0x20($sp)
/* E06CF8 80241998 46200007 */  neg.d     $f0, $f0
/* E06CFC 8024199C 4620008D */  trunc.w.d $f2, $f0
/* E06D00 802419A0 44021000 */  mfc1      $v0, $f2
/* E06D04 802419A4 0C04EBDC */  jal       sprfx_appendGfx_component
/* E06D08 802419A8 A7A2002C */   sh       $v0, 0x2c($sp)
/* E06D0C 802419AC 3C04D838 */  lui       $a0, 0xd838
/* E06D10 802419B0 8E020000 */  lw        $v0, ($s0)
/* E06D14 802419B4 34840002 */  ori       $a0, $a0, 2
/* E06D18 802419B8 0040182D */  daddu     $v1, $v0, $zero
/* E06D1C 802419BC 24420008 */  addiu     $v0, $v0, 8
/* E06D20 802419C0 AE020000 */  sw        $v0, ($s0)
/* E06D24 802419C4 24020040 */  addiu     $v0, $zero, 0x40
/* E06D28 802419C8 AC640000 */  sw        $a0, ($v1)
/* E06D2C 802419CC AC620004 */  sw        $v0, 4($v1)
/* E06D30 802419D0 8FBF00E0 */  lw        $ra, 0xe0($sp)
/* E06D34 802419D4 8FB500DC */  lw        $s5, 0xdc($sp)
/* E06D38 802419D8 8FB400D8 */  lw        $s4, 0xd8($sp)
/* E06D3C 802419DC 8FB300D4 */  lw        $s3, 0xd4($sp)
/* E06D40 802419E0 8FB200D0 */  lw        $s2, 0xd0($sp)
/* E06D44 802419E4 8FB100CC */  lw        $s1, 0xcc($sp)
/* E06D48 802419E8 8FB000C8 */  lw        $s0, 0xc8($sp)
/* E06D4C 802419EC D7BC0108 */  ldc1      $f28, 0x108($sp)
/* E06D50 802419F0 D7BA0100 */  ldc1      $f26, 0x100($sp)
/* E06D54 802419F4 D7B800F8 */  ldc1      $f24, 0xf8($sp)
/* E06D58 802419F8 D7B600F0 */  ldc1      $f22, 0xf0($sp)
/* E06D5C 802419FC D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* E06D60 80241A00 03E00008 */  jr        $ra
/* E06D64 80241A04 27BD0110 */   addiu    $sp, $sp, 0x110
