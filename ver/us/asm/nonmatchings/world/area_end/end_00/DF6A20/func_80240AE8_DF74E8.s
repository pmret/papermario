.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AE8_DF74E8
/* DF74E8 80240AE8 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* DF74EC 80240AEC AFB000C8 */  sw        $s0, 0xc8($sp)
/* DF74F0 80240AF0 0080802D */  daddu     $s0, $a0, $zero
/* DF74F4 80240AF4 AFB100CC */  sw        $s1, 0xcc($sp)
/* DF74F8 80240AF8 00A0882D */  daddu     $s1, $a1, $zero
/* DF74FC 80240AFC AFB600E0 */  sw        $s6, 0xe0($sp)
/* DF7500 80240B00 24160040 */  addiu     $s6, $zero, 0x40
/* DF7504 80240B04 AFBF00E4 */  sw        $ra, 0xe4($sp)
/* DF7508 80240B08 AFB500DC */  sw        $s5, 0xdc($sp)
/* DF750C 80240B0C AFB400D8 */  sw        $s4, 0xd8($sp)
/* DF7510 80240B10 AFB300D4 */  sw        $s3, 0xd4($sp)
/* DF7514 80240B14 AFB200D0 */  sw        $s2, 0xd0($sp)
/* DF7518 80240B18 F7BC0108 */  sdc1      $f28, 0x108($sp)
/* DF751C 80240B1C F7BA0100 */  sdc1      $f26, 0x100($sp)
/* DF7520 80240B20 F7B800F8 */  sdc1      $f24, 0xf8($sp)
/* DF7524 80240B24 F7B600F0 */  sdc1      $f22, 0xf0($sp)
/* DF7528 80240B28 F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* DF752C 80240B2C C6200010 */  lwc1      $f0, 0x10($s1)
/* DF7530 80240B30 46800020 */  cvt.s.w   $f0, $f0
/* DF7534 80240B34 8E020068 */  lw        $v0, 0x68($s0)
/* DF7538 80240B38 8E030014 */  lw        $v1, 0x14($s0)
/* DF753C 80240B3C 44060000 */  mfc1      $a2, $f0
/* DF7540 80240B40 8E07001C */  lw        $a3, 0x1c($s0)
/* DF7544 80240B44 00431021 */  addu      $v0, $v0, $v1
/* DF7548 80240B48 2442FFF0 */  addiu     $v0, $v0, -0x10
/* DF754C 80240B4C 44822000 */  mtc1      $v0, $f4
/* DF7550 80240B50 00000000 */  nop
/* DF7554 80240B54 46802120 */  cvt.s.w   $f4, $f4
/* DF7558 80240B58 8E03006C */  lw        $v1, 0x6c($s0)
/* DF755C 80240B5C 44052000 */  mfc1      $a1, $f4
/* DF7560 80240B60 AFA70010 */  sw        $a3, 0x10($sp)
/* DF7564 80240B64 8E270018 */  lw        $a3, 0x18($s1)
/* DF7568 80240B68 2463003C */  addiu     $v1, $v1, 0x3c
/* DF756C 80240B6C 4483A000 */  mtc1      $v1, $f20
/* DF7570 80240B70 00000000 */  nop
/* DF7574 80240B74 4680A520 */  cvt.s.w   $f20, $f20
/* DF7578 80240B78 0C00A8ED */  jal       update_lerp
/* DF757C 80240B7C 2404000A */   addiu    $a0, $zero, 0xa
/* DF7580 80240B80 C6220014 */  lwc1      $f2, 0x14($s1)
/* DF7584 80240B84 468010A0 */  cvt.s.w   $f2, $f2
/* DF7588 80240B88 4405A000 */  mfc1      $a1, $f20
/* DF758C 80240B8C 44061000 */  mfc1      $a2, $f2
/* DF7590 80240B90 8E02001C */  lw        $v0, 0x1c($s0)
/* DF7594 80240B94 24040005 */  addiu     $a0, $zero, 5
/* DF7598 80240B98 AFA20010 */  sw        $v0, 0x10($sp)
/* DF759C 80240B9C 8E270018 */  lw        $a3, 0x18($s1)
/* DF75A0 80240BA0 0C00A8ED */  jal       update_lerp
/* DF75A4 80240BA4 46000506 */   mov.s    $f20, $f0
/* DF75A8 80240BA8 27B50038 */  addiu     $s5, $sp, 0x38
/* DF75AC 80240BAC 8E220018 */  lw        $v0, 0x18($s1)
/* DF75B0 80240BB0 8E03001C */  lw        $v1, 0x1c($s0)
/* DF75B4 80240BB4 14430004 */  bne       $v0, $v1, .L80240BC8
/* DF75B8 80240BB8 46000706 */   mov.s    $f28, $f0
/* DF75BC 80240BBC 4480B000 */  mtc1      $zero, $f22
/* DF75C0 80240BC0 080902F9 */  j         .L80240BE4
/* DF75C4 80240BC4 00000000 */   nop
.L80240BC8:
/* DF75C8 80240BC8 00621823 */  subu      $v1, $v1, $v0
/* DF75CC 80240BCC 00031080 */  sll       $v0, $v1, 2
/* DF75D0 80240BD0 00431021 */  addu      $v0, $v0, $v1
/* DF75D4 80240BD4 00021040 */  sll       $v0, $v0, 1
/* DF75D8 80240BD8 4482B000 */  mtc1      $v0, $f22
/* DF75DC 80240BDC 00000000 */  nop
/* DF75E0 80240BE0 4680B5A0 */  cvt.s.w   $f22, $f22
.L80240BE4:
/* DF75E4 80240BE4 8E02001C */  lw        $v0, 0x1c($s0)
/* DF75E8 80240BE8 3C054000 */  lui       $a1, 0x4000
/* DF75EC 80240BEC 3C063F80 */  lui       $a2, 0x3f80
/* DF75F0 80240BF0 AFA20010 */  sw        $v0, 0x10($sp)
/* DF75F4 80240BF4 8E270018 */  lw        $a3, 0x18($s1)
/* DF75F8 80240BF8 0C00A8ED */  jal       update_lerp
/* DF75FC 80240BFC 24040004 */   addiu    $a0, $zero, 4
/* DF7600 80240C00 8E220018 */  lw        $v0, 0x18($s1)
/* DF7604 80240C04 8E04001C */  lw        $a0, 0x1c($s0)
/* DF7608 80240C08 1444000C */  bne       $v0, $a0, .L80240C3C
/* DF760C 80240C0C 46000686 */   mov.s    $f26, $f0
/* DF7610 80240C10 0000202D */  daddu     $a0, $zero, $zero
/* DF7614 80240C14 0080282D */  daddu     $a1, $a0, $zero
/* DF7618 80240C18 0080302D */  daddu     $a2, $a0, $zero
/* DF761C 80240C1C 0080382D */  daddu     $a3, $a0, $zero
/* DF7620 80240C20 AFA00010 */  sw        $zero, 0x10($sp)
/* DF7624 80240C24 AFA00014 */  sw        $zero, 0x14($sp)
/* DF7628 80240C28 0C04EAA7 */  jal       sprfx_update
/* DF762C 80240C2C AFA00018 */   sw       $zero, 0x18($sp)
/* DF7630 80240C30 3C020001 */  lui       $v0, 1
/* DF7634 80240C34 08090326 */  j         .L80240C98
/* DF7638 80240C38 02C2B025 */   or       $s6, $s6, $v0
.L80240C3C:
/* DF763C 80240C3C 3C054180 */  lui       $a1, 0x4180
/* DF7640 80240C40 3C064396 */  lui       $a2, 0x4396
/* DF7644 80240C44 AFA40010 */  sw        $a0, 0x10($sp)
/* DF7648 80240C48 8E270018 */  lw        $a3, 0x18($s1)
/* DF764C 80240C4C 0C00A8ED */  jal       update_lerp
/* DF7650 80240C50 0000202D */   daddu    $a0, $zero, $zero
/* DF7654 80240C54 3C01437F */  lui       $at, 0x437f
/* DF7658 80240C58 44811000 */  mtc1      $at, $f2
/* DF765C 80240C5C 00000000 */  nop
/* DF7660 80240C60 4600103C */  c.lt.s    $f2, $f0
/* DF7664 80240C64 00000000 */  nop
/* DF7668 80240C68 45030001 */  bc1tl     .L80240C70
/* DF766C 80240C6C 46001006 */   mov.s    $f0, $f2
.L80240C70:
/* DF7670 80240C70 4600010D */  trunc.w.s $f4, $f0
/* DF7674 80240C74 E7A40014 */  swc1      $f4, 0x14($sp)
/* DF7678 80240C78 0000202D */  daddu     $a0, $zero, $zero
/* DF767C 80240C7C 24050007 */  addiu     $a1, $zero, 7
/* DF7680 80240C80 240600FF */  addiu     $a2, $zero, 0xff
/* DF7684 80240C84 00C0382D */  daddu     $a3, $a2, $zero
/* DF7688 80240C88 00C0102D */  daddu     $v0, $a2, $zero
/* DF768C 80240C8C AFA20010 */  sw        $v0, 0x10($sp)
/* DF7690 80240C90 0C04EAA7 */  jal       sprfx_update
/* DF7694 80240C94 AFA00018 */   sw       $zero, 0x18($sp)
.L80240C98:
/* DF7698 80240C98 AFB50010 */  sw        $s5, 0x10($sp)
/* DF769C 80240C9C 8E240004 */  lw        $a0, 4($s1)
/* DF76A0 80240CA0 8E250008 */  lw        $a1, 8($s1)
/* DF76A4 80240CA4 8E260000 */  lw        $a2, ($s1)
/* DF76A8 80240CA8 8E27000C */  lw        $a3, 0xc($s1)
/* DF76AC 80240CAC 0C04BA38 */  jal       msg_get_glyph
/* DF76B0 80240CB0 3C140001 */   lui      $s4, 1
/* DF76B4 80240CB4 92A2000A */  lbu       $v0, 0xa($s5)
/* DF76B8 80240CB8 3C013FE0 */  lui       $at, 0x3fe0
/* DF76BC 80240CBC 4481C800 */  mtc1      $at, $f25
/* DF76C0 80240CC0 4480C000 */  mtc1      $zero, $f24
/* DF76C4 80240CC4 44820000 */  mtc1      $v0, $f0
/* DF76C8 80240CC8 00000000 */  nop
/* DF76CC 80240CCC 46800021 */  cvt.d.w   $f0, $f0
/* DF76D0 80240CD0 46380002 */  mul.d     $f0, $f0, $f24
/* DF76D4 80240CD4 00000000 */  nop
/* DF76D8 80240CD8 36941630 */  ori       $s4, $s4, 0x1630
/* DF76DC 80240CDC 4600A0A1 */  cvt.d.s   $f2, $f20
/* DF76E0 80240CE0 27B10048 */  addiu     $s1, $sp, 0x48
/* DF76E4 80240CE4 4600E707 */  neg.s     $f28, $f28
/* DF76E8 80240CE8 4480A000 */  mtc1      $zero, $f20
/* DF76EC 80240CEC 46201080 */  add.d     $f2, $f2, $f0
/* DF76F0 80240CF0 4406E000 */  mfc1      $a2, $f28
/* DF76F4 80240CF4 4407A000 */  mfc1      $a3, $f20
/* DF76F8 80240CF8 462010A0 */  cvt.s.d   $f2, $f2
/* DF76FC 80240CFC 44051000 */  mfc1      $a1, $f2
/* DF7700 80240D00 0C019E40 */  jal       guTranslateF
/* DF7704 80240D04 0220202D */   daddu    $a0, $s1, $zero
/* DF7708 80240D08 27B00088 */  addiu     $s0, $sp, 0x88
/* DF770C 80240D0C 4405B000 */  mfc1      $a1, $f22
/* DF7710 80240D10 3C013F80 */  lui       $at, 0x3f80
/* DF7714 80240D14 4481B000 */  mtc1      $at, $f22
/* DF7718 80240D18 4406A000 */  mfc1      $a2, $f20
/* DF771C 80240D1C 3C013E4C */  lui       $at, 0x3e4c
/* DF7720 80240D20 3421CCCD */  ori       $at, $at, 0xcccd
/* DF7724 80240D24 44810000 */  mtc1      $at, $f0
/* DF7728 80240D28 4407B000 */  mfc1      $a3, $f22
/* DF772C 80240D2C 0200202D */  daddu     $a0, $s0, $zero
/* DF7730 80240D30 0C019EC8 */  jal       guRotateF
/* DF7734 80240D34 E7A00010 */   swc1     $f0, 0x10($sp)
/* DF7738 80240D38 0200202D */  daddu     $a0, $s0, $zero
/* DF773C 80240D3C 0220282D */  daddu     $a1, $s1, $zero
/* DF7740 80240D40 0C019D80 */  jal       guMtxCatF
/* DF7744 80240D44 0220302D */   daddu    $a2, $s1, $zero
/* DF7748 80240D48 0200202D */  daddu     $a0, $s0, $zero
/* DF774C 80240D4C 4405D000 */  mfc1      $a1, $f26
/* DF7750 80240D50 4407B000 */  mfc1      $a3, $f22
/* DF7754 80240D54 0C019DF0 */  jal       guScaleF
/* DF7758 80240D58 00A0302D */   daddu    $a2, $a1, $zero
/* DF775C 80240D5C 0200202D */  daddu     $a0, $s0, $zero
/* DF7760 80240D60 0220282D */  daddu     $a1, $s1, $zero
/* DF7764 80240D64 0C019D80 */  jal       guMtxCatF
/* DF7768 80240D68 0220302D */   daddu    $a2, $s1, $zero
/* DF776C 80240D6C 0220202D */  daddu     $a0, $s1, $zero
/* DF7770 80240D70 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* DF7774 80240D74 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* DF7778 80240D78 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* DF777C 80240D7C 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* DF7780 80240D80 96050000 */  lhu       $a1, ($s0)
/* DF7784 80240D84 8E620000 */  lw        $v0, ($s3)
/* DF7788 80240D88 00052980 */  sll       $a1, $a1, 6
/* DF778C 80240D8C 00B42821 */  addu      $a1, $a1, $s4
/* DF7790 80240D90 0C019D40 */  jal       guMtxF2L
/* DF7794 80240D94 00452821 */   addu     $a1, $v0, $a1
/* DF7798 80240D98 3C02DA38 */  lui       $v0, 0xda38
/* DF779C 80240D9C 34420002 */  ori       $v0, $v0, 2
/* DF77A0 80240DA0 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* DF77A4 80240DA4 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* DF77A8 80240DA8 8E440000 */  lw        $a0, ($s2)
/* DF77AC 80240DAC 96050000 */  lhu       $a1, ($s0)
/* DF77B0 80240DB0 0080302D */  daddu     $a2, $a0, $zero
/* DF77B4 80240DB4 ACC20000 */  sw        $v0, ($a2)
/* DF77B8 80240DB8 30A2FFFF */  andi      $v0, $a1, 0xffff
/* DF77BC 80240DBC 00021180 */  sll       $v0, $v0, 6
/* DF77C0 80240DC0 8E630000 */  lw        $v1, ($s3)
/* DF77C4 80240DC4 00541021 */  addu      $v0, $v0, $s4
/* DF77C8 80240DC8 00621821 */  addu      $v1, $v1, $v0
/* DF77CC 80240DCC 3C028000 */  lui       $v0, 0x8000
/* DF77D0 80240DD0 00621821 */  addu      $v1, $v1, $v0
/* DF77D4 80240DD4 ACC30004 */  sw        $v1, 4($a2)
/* DF77D8 80240DD8 8EA20000 */  lw        $v0, ($s5)
/* DF77DC 80240DDC 24840008 */  addiu     $a0, $a0, 8
/* DF77E0 80240DE0 AE440000 */  sw        $a0, ($s2)
/* DF77E4 80240DE4 AFA20020 */  sw        $v0, 0x20($sp)
/* DF77E8 80240DE8 8EA20004 */  lw        $v0, 4($s5)
/* DF77EC 80240DEC 24A50001 */  addiu     $a1, $a1, 1
/* DF77F0 80240DF0 A6050000 */  sh        $a1, ($s0)
/* DF77F4 80240DF4 AFA20024 */  sw        $v0, 0x24($sp)
/* DF77F8 80240DF8 92A20008 */  lbu       $v0, 8($s5)
/* DF77FC 80240DFC A7A20028 */  sh        $v0, 0x28($sp)
/* DF7800 80240E00 92A20009 */  lbu       $v0, 9($s5)
/* DF7804 80240E04 A7A2002A */  sh        $v0, 0x2a($sp)
/* DF7808 80240E08 92A2000A */  lbu       $v0, 0xa($s5)
/* DF780C 80240E0C 44820000 */  mtc1      $v0, $f0
/* DF7810 80240E10 00000000 */  nop
/* DF7814 80240E14 46800021 */  cvt.d.w   $f0, $f0
/* DF7818 80240E18 46380002 */  mul.d     $f0, $f0, $f24
/* DF781C 80240E1C 00000000 */  nop
/* DF7820 80240E20 0220382D */  daddu     $a3, $s1, $zero
/* DF7824 80240E24 0000202D */  daddu     $a0, $zero, $zero
/* DF7828 80240E28 02C0302D */  daddu     $a2, $s6, $zero
/* DF782C 80240E2C 27A50020 */  addiu     $a1, $sp, 0x20
/* DF7830 80240E30 A7A0002E */  sh        $zero, 0x2e($sp)
/* DF7834 80240E34 240200FF */  addiu     $v0, $zero, 0xff
/* DF7838 80240E38 A3A20030 */  sb        $v0, 0x30($sp)
/* DF783C 80240E3C 46200007 */  neg.d     $f0, $f0
/* DF7840 80240E40 4620010D */  trunc.w.d $f4, $f0
/* DF7844 80240E44 44022000 */  mfc1      $v0, $f4
/* DF7848 80240E48 0C04EBDC */  jal       sprfx_appendGfx_component
/* DF784C 80240E4C A7A2002C */   sh       $v0, 0x2c($sp)
/* DF7850 80240E50 3C04D838 */  lui       $a0, 0xd838
/* DF7854 80240E54 8E420000 */  lw        $v0, ($s2)
/* DF7858 80240E58 34840002 */  ori       $a0, $a0, 2
/* DF785C 80240E5C 0040182D */  daddu     $v1, $v0, $zero
/* DF7860 80240E60 24420008 */  addiu     $v0, $v0, 8
/* DF7864 80240E64 AE420000 */  sw        $v0, ($s2)
/* DF7868 80240E68 24020040 */  addiu     $v0, $zero, 0x40
/* DF786C 80240E6C AC640000 */  sw        $a0, ($v1)
/* DF7870 80240E70 AC620004 */  sw        $v0, 4($v1)
/* DF7874 80240E74 8FBF00E4 */  lw        $ra, 0xe4($sp)
/* DF7878 80240E78 8FB600E0 */  lw        $s6, 0xe0($sp)
/* DF787C 80240E7C 8FB500DC */  lw        $s5, 0xdc($sp)
/* DF7880 80240E80 8FB400D8 */  lw        $s4, 0xd8($sp)
/* DF7884 80240E84 8FB300D4 */  lw        $s3, 0xd4($sp)
/* DF7888 80240E88 8FB200D0 */  lw        $s2, 0xd0($sp)
/* DF788C 80240E8C 8FB100CC */  lw        $s1, 0xcc($sp)
/* DF7890 80240E90 8FB000C8 */  lw        $s0, 0xc8($sp)
/* DF7894 80240E94 D7BC0108 */  ldc1      $f28, 0x108($sp)
/* DF7898 80240E98 D7BA0100 */  ldc1      $f26, 0x100($sp)
/* DF789C 80240E9C D7B800F8 */  ldc1      $f24, 0xf8($sp)
/* DF78A0 80240EA0 D7B600F0 */  ldc1      $f22, 0xf0($sp)
/* DF78A4 80240EA4 D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* DF78A8 80240EA8 03E00008 */  jr        $ra
/* DF78AC 80240EAC 27BD0110 */   addiu    $sp, $sp, 0x110
