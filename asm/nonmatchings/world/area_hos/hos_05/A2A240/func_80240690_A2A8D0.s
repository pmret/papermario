.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240690_A2A8D0
/* A2A8D0 80240690 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A2A8D4 80240694 AFB00010 */  sw        $s0, 0x10($sp)
/* A2A8D8 80240698 0080802D */  daddu     $s0, $a0, $zero
/* A2A8DC 8024069C 3C02F24A */  lui       $v0, 0xf24a
/* A2A8E0 802406A0 34427A80 */  ori       $v0, $v0, 0x7a80
/* A2A8E4 802406A4 3C03F24C */  lui       $v1, 0xf24c
/* A2A8E8 802406A8 34630A80 */  ori       $v1, $v1, 0xa80
/* A2A8EC 802406AC 2404000A */  addiu     $a0, $zero, 0xa
/* A2A8F0 802406B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* A2A8F4 802406B4 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* A2A8F8 802406B8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* A2A8FC 802406BC F7B60020 */  sdc1      $f22, 0x20($sp)
/* A2A900 802406C0 F7B40018 */  sdc1      $f20, 0x18($sp)
/* A2A904 802406C4 C61A0088 */  lwc1      $f26, 0x88($s0)
/* A2A908 802406C8 4680D6A0 */  cvt.s.w   $f26, $f26
/* A2A90C 802406CC 3C014334 */  lui       $at, 0x4334
/* A2A910 802406D0 44810000 */  mtc1      $at, $f0
/* A2A914 802406D4 3C014049 */  lui       $at, 0x4049
/* A2A918 802406D8 34210FD8 */  ori       $at, $at, 0xfd8
/* A2A91C 802406DC 44811000 */  mtc1      $at, $f2
/* A2A920 802406E0 4600D682 */  mul.s     $f26, $f26, $f0
/* A2A924 802406E4 00000000 */  nop       
/* A2A928 802406E8 C616008C */  lwc1      $f22, 0x8c($s0)
/* A2A92C 802406EC 4680B5A0 */  cvt.s.w   $f22, $f22
/* A2A930 802406F0 AE02008C */  sw        $v0, 0x8c($s0)
/* A2A934 802406F4 AE030090 */  sw        $v1, 0x90($s0)
/* A2A938 802406F8 AE020094 */  sw        $v0, 0x94($s0)
/* A2A93C 802406FC 0C00A67F */  jal       rand_int
/* A2A940 80240700 4602D683 */   div.s    $f26, $f26, $f2
/* A2A944 80240704 4482A000 */  mtc1      $v0, $f20
/* A2A948 80240708 00000000 */  nop       
/* A2A94C 8024070C 4680A520 */  cvt.s.w   $f20, $f20
/* A2A950 80240710 3C014040 */  lui       $at, 0x4040
/* A2A954 80240714 44810000 */  mtc1      $at, $f0
/* A2A958 80240718 4616A503 */  div.s     $f20, $f20, $f22
/* A2A95C 8024071C 4600A500 */  add.s     $f20, $f20, $f0
/* A2A960 80240720 0C00A874 */  jal       cos_rad
/* A2A964 80240724 4600D306 */   mov.s    $f12, $f26
/* A2A968 80240728 4600A002 */  mul.s     $f0, $f20, $f0
/* A2A96C 8024072C 00000000 */  nop       
/* A2A970 80240730 3C014480 */  lui       $at, 0x4480
/* A2A974 80240734 4481C000 */  mtc1      $at, $f24
/* A2A978 80240738 00000000 */  nop       
/* A2A97C 8024073C 46180002 */  mul.s     $f0, $f0, $f24
/* A2A980 80240740 00000000 */  nop       
/* A2A984 80240744 3C01CD5B */  lui       $at, 0xcd5b
/* A2A988 80240748 34215858 */  ori       $at, $at, 0x5858
/* A2A98C 8024074C 4481B000 */  mtc1      $at, $f22
/* A2A990 80240750 00000000 */  nop       
/* A2A994 80240754 46160000 */  add.s     $f0, $f0, $f22
/* A2A998 80240758 4600010D */  trunc.w.s $f4, $f0
/* A2A99C 8024075C E60400AC */  swc1      $f4, 0xac($s0)
/* A2A9A0 80240760 0C00A67F */  jal       rand_int
/* A2A9A4 80240764 2404000F */   addiu    $a0, $zero, 0xf
/* A2A9A8 80240768 24420005 */  addiu     $v0, $v0, 5
/* A2A9AC 8024076C 44820000 */  mtc1      $v0, $f0
/* A2A9B0 80240770 00000000 */  nop       
/* A2A9B4 80240774 46800020 */  cvt.s.w   $f0, $f0
/* A2A9B8 80240778 46180002 */  mul.s     $f0, $f0, $f24
/* A2A9BC 8024077C 00000000 */  nop       
/* A2A9C0 80240780 46160000 */  add.s     $f0, $f0, $f22
/* A2A9C4 80240784 4600010D */  trunc.w.s $f4, $f0
/* A2A9C8 80240788 E60400B0 */  swc1      $f4, 0xb0($s0)
/* A2A9CC 8024078C 0C00A85B */  jal       sin_rad
/* A2A9D0 80240790 4600D306 */   mov.s    $f12, $f26
/* A2A9D4 80240794 4600A502 */  mul.s     $f20, $f20, $f0
/* A2A9D8 80240798 00000000 */  nop       
/* A2A9DC 8024079C 4618A502 */  mul.s     $f20, $f20, $f24
/* A2A9E0 802407A0 00000000 */  nop       
/* A2A9E4 802407A4 4616A500 */  add.s     $f20, $f20, $f22
/* A2A9E8 802407A8 4600A10D */  trunc.w.s $f4, $f20
/* A2A9EC 802407AC E60400B4 */  swc1      $f4, 0xb4($s0)
/* A2A9F0 802407B0 0C00A67F */  jal       rand_int
/* A2A9F4 802407B4 2404000A */   addiu    $a0, $zero, 0xa
/* A2A9F8 802407B8 2442000A */  addiu     $v0, $v0, 0xa
/* A2A9FC 802407BC 44820000 */  mtc1      $v0, $f0
/* A2AA00 802407C0 00000000 */  nop       
/* A2AA04 802407C4 46800020 */  cvt.s.w   $f0, $f0
/* A2AA08 802407C8 3C018025 */  lui       $at, 0x8025
/* A2AA0C 802407CC D422F1D0 */  ldc1      $f2, -0xe30($at)
/* A2AA10 802407D0 46000021 */  cvt.d.s   $f0, $f0
/* A2AA14 802407D4 46220002 */  mul.d     $f0, $f0, $f2
/* A2AA18 802407D8 00000000 */  nop       
/* A2AA1C 802407DC 3C014090 */  lui       $at, 0x4090
/* A2AA20 802407E0 44811800 */  mtc1      $at, $f3
/* A2AA24 802407E4 44801000 */  mtc1      $zero, $f2
/* A2AA28 802407E8 00000000 */  nop       
/* A2AA2C 802407EC 46220002 */  mul.d     $f0, $f0, $f2
/* A2AA30 802407F0 00000000 */  nop       
/* A2AA34 802407F4 3C018025 */  lui       $at, 0x8025
/* A2AA38 802407F8 D422F1D8 */  ldc1      $f2, -0xe28($at)
/* A2AA3C 802407FC 46220000 */  add.d     $f0, $f0, $f2
/* A2AA40 80240800 4620010D */  trunc.w.d $f4, $f0
/* A2AA44 80240804 E60400B8 */  swc1      $f4, 0xb8($s0)
/* A2AA48 80240808 8FBF0014 */  lw        $ra, 0x14($sp)
/* A2AA4C 8024080C 8FB00010 */  lw        $s0, 0x10($sp)
/* A2AA50 80240810 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* A2AA54 80240814 D7B80028 */  ldc1      $f24, 0x28($sp)
/* A2AA58 80240818 D7B60020 */  ldc1      $f22, 0x20($sp)
/* A2AA5C 8024081C D7B40018 */  ldc1      $f20, 0x18($sp)
/* A2AA60 80240820 24020002 */  addiu     $v0, $zero, 2
/* A2AA64 80240824 03E00008 */  jr        $ra
/* A2AA68 80240828 27BD0038 */   addiu    $sp, $sp, 0x38
/* A2AA6C 8024082C 00000000 */  nop       
