.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240504_CCB814
/* CCB814 80240504 27BDFF88 */  addiu     $sp, $sp, -0x78
/* CCB818 80240508 AFBF0064 */  sw        $ra, 0x64($sp)
/* CCB81C 8024050C AFB00060 */  sw        $s0, 0x60($sp)
/* CCB820 80240510 F7B60070 */  sdc1      $f22, 0x70($sp)
/* CCB824 80240514 F7B40068 */  sdc1      $f20, 0x68($sp)
/* CCB828 80240518 0C019D28 */  jal       guMtxIdentF
/* CCB82C 8024051C 27A40010 */   addiu    $a0, $sp, 0x10
/* CCB830 80240520 3C108024 */  lui       $s0, %hi(D_80243B14_CCEE24)
/* CCB834 80240524 26103B14 */  addiu     $s0, $s0, %lo(D_80243B14_CCEE24)
/* CCB838 80240528 C6000000 */  lwc1      $f0, ($s0)
/* CCB83C 8024052C 3C014130 */  lui       $at, 0x4130
/* CCB840 80240530 44816000 */  mtc1      $at, $f12
/* CCB844 80240534 0C00A85B */  jal       sin_rad
/* CCB848 80240538 460C0303 */   div.s    $f12, $f0, $f12
/* CCB84C 8024053C 3C018024 */  lui       $at, %hi(D_80245320_CD0630)
/* CCB850 80240540 D4345320 */  ldc1      $f20, %lo(D_80245320_CD0630)($at)
/* CCB854 80240544 46000021 */  cvt.d.s   $f0, $f0
/* CCB858 80240548 46340002 */  mul.d     $f0, $f0, $f20
/* CCB85C 8024054C 00000000 */  nop
/* CCB860 80240550 3C018024 */  lui       $at, %hi(D_80245328_CD0638)
/* CCB864 80240554 D4365328 */  ldc1      $f22, %lo(D_80245328_CD0638)($at)
/* CCB868 80240558 C6020000 */  lwc1      $f2, ($s0)
/* CCB86C 8024055C 3C014140 */  lui       $at, 0x4140
/* CCB870 80240560 44816000 */  mtc1      $at, $f12
/* CCB874 80240564 46360000 */  add.d     $f0, $f0, $f22
/* CCB878 80240568 460C1303 */  div.s     $f12, $f2, $f12
/* CCB87C 8024056C 46200020 */  cvt.s.d   $f0, $f0
/* CCB880 80240570 0C00A85B */  jal       sin_rad
/* CCB884 80240574 E7A00010 */   swc1     $f0, 0x10($sp)
/* CCB888 80240578 46000021 */  cvt.d.s   $f0, $f0
/* CCB88C 8024057C 46340002 */  mul.d     $f0, $f0, $f20
/* CCB890 80240580 00000000 */  nop
/* CCB894 80240584 C6020000 */  lwc1      $f2, ($s0)
/* CCB898 80240588 3C014150 */  lui       $at, 0x4150
/* CCB89C 8024058C 44816000 */  mtc1      $at, $f12
/* CCB8A0 80240590 00000000 */  nop
/* CCB8A4 80240594 460C1303 */  div.s     $f12, $f2, $f12
/* CCB8A8 80240598 46200020 */  cvt.s.d   $f0, $f0
/* CCB8AC 8024059C 0C00A874 */  jal       cos_rad
/* CCB8B0 802405A0 E7A00014 */   swc1     $f0, 0x14($sp)
/* CCB8B4 802405A4 46000021 */  cvt.d.s   $f0, $f0
/* CCB8B8 802405A8 46340002 */  mul.d     $f0, $f0, $f20
/* CCB8BC 802405AC 00000000 */  nop
/* CCB8C0 802405B0 C60C0000 */  lwc1      $f12, ($s0)
/* CCB8C4 802405B4 3C0140E0 */  lui       $at, 0x40e0
/* CCB8C8 802405B8 44811000 */  mtc1      $at, $f2
/* CCB8CC 802405BC 3C013F80 */  lui       $at, 0x3f80
/* CCB8D0 802405C0 44812000 */  mtc1      $at, $f4
/* CCB8D4 802405C4 46026303 */  div.s     $f12, $f12, $f2
/* CCB8D8 802405C8 46046300 */  add.s     $f12, $f12, $f4
/* CCB8DC 802405CC 46200020 */  cvt.s.d   $f0, $f0
/* CCB8E0 802405D0 0C00A85B */  jal       sin_rad
/* CCB8E4 802405D4 E7A00018 */   swc1     $f0, 0x18($sp)
/* CCB8E8 802405D8 46000021 */  cvt.d.s   $f0, $f0
/* CCB8EC 802405DC 46340002 */  mul.d     $f0, $f0, $f20
/* CCB8F0 802405E0 00000000 */  nop
/* CCB8F4 802405E4 C6020000 */  lwc1      $f2, ($s0)
/* CCB8F8 802405E8 3C014160 */  lui       $at, 0x4160
/* CCB8FC 802405EC 44816000 */  mtc1      $at, $f12
/* CCB900 802405F0 46360000 */  add.d     $f0, $f0, $f22
/* CCB904 802405F4 460C1303 */  div.s     $f12, $f2, $f12
/* CCB908 802405F8 46200020 */  cvt.s.d   $f0, $f0
/* CCB90C 802405FC 0C00A85B */  jal       sin_rad
/* CCB910 80240600 E7A00024 */   swc1     $f0, 0x24($sp)
/* CCB914 80240604 46000021 */  cvt.d.s   $f0, $f0
/* CCB918 80240608 46340002 */  mul.d     $f0, $f0, $f20
/* CCB91C 8024060C 00000000 */  nop
/* CCB920 80240610 C6020000 */  lwc1      $f2, ($s0)
/* CCB924 80240614 3C014170 */  lui       $at, 0x4170
/* CCB928 80240618 44816000 */  mtc1      $at, $f12
/* CCB92C 8024061C 00000000 */  nop
/* CCB930 80240620 460C1303 */  div.s     $f12, $f2, $f12
/* CCB934 80240624 46200020 */  cvt.s.d   $f0, $f0
/* CCB938 80240628 0C00A874 */  jal       cos_rad
/* CCB93C 8024062C E7A00020 */   swc1     $f0, 0x20($sp)
/* CCB940 80240630 46000021 */  cvt.d.s   $f0, $f0
/* CCB944 80240634 46340002 */  mul.d     $f0, $f0, $f20
/* CCB948 80240638 00000000 */  nop
/* CCB94C 8024063C C60C0000 */  lwc1      $f12, ($s0)
/* CCB950 80240640 3C013E80 */  lui       $at, 0x3e80
/* CCB954 80240644 44811000 */  mtc1      $at, $f2
/* CCB958 80240648 00000000 */  nop
/* CCB95C 8024064C 46026302 */  mul.s     $f12, $f12, $f2
/* CCB960 80240650 00000000 */  nop
/* CCB964 80240654 3C014000 */  lui       $at, 0x4000
/* CCB968 80240658 44811000 */  mtc1      $at, $f2
/* CCB96C 8024065C 00000000 */  nop
/* CCB970 80240660 46026300 */  add.s     $f12, $f12, $f2
/* CCB974 80240664 46200020 */  cvt.s.d   $f0, $f0
/* CCB978 80240668 0C00A85B */  jal       sin_rad
/* CCB97C 8024066C E7A00028 */   swc1     $f0, 0x28($sp)
/* CCB980 80240670 46000021 */  cvt.d.s   $f0, $f0
/* CCB984 80240674 46340002 */  mul.d     $f0, $f0, $f20
/* CCB988 80240678 00000000 */  nop
/* CCB98C 8024067C C6020000 */  lwc1      $f2, ($s0)
/* CCB990 80240680 3C013D80 */  lui       $at, 0x3d80
/* CCB994 80240684 44816000 */  mtc1      $at, $f12
/* CCB998 80240688 00000000 */  nop
/* CCB99C 8024068C 460C1302 */  mul.s     $f12, $f2, $f12
/* CCB9A0 80240690 00000000 */  nop
/* CCB9A4 80240694 46360000 */  add.d     $f0, $f0, $f22
/* CCB9A8 80240698 46200020 */  cvt.s.d   $f0, $f0
/* CCB9AC 8024069C 0C00A85B */  jal       sin_rad
/* CCB9B0 802406A0 E7A00038 */   swc1     $f0, 0x38($sp)
/* CCB9B4 802406A4 46000021 */  cvt.d.s   $f0, $f0
/* CCB9B8 802406A8 46340002 */  mul.d     $f0, $f0, $f20
/* CCB9BC 802406AC 00000000 */  nop
/* CCB9C0 802406B0 C6020000 */  lwc1      $f2, ($s0)
/* CCB9C4 802406B4 3C014188 */  lui       $at, 0x4188
/* CCB9C8 802406B8 44816000 */  mtc1      $at, $f12
/* CCB9CC 802406BC 00000000 */  nop
/* CCB9D0 802406C0 460C1303 */  div.s     $f12, $f2, $f12
/* CCB9D4 802406C4 46200020 */  cvt.s.d   $f0, $f0
/* CCB9D8 802406C8 0C00A874 */  jal       cos_rad
/* CCB9DC 802406CC E7A00030 */   swc1     $f0, 0x30($sp)
/* CCB9E0 802406D0 3C030001 */  lui       $v1, 1
/* CCB9E4 802406D4 46000021 */  cvt.d.s   $f0, $f0
/* CCB9E8 802406D8 46340002 */  mul.d     $f0, $f0, $f20
/* CCB9EC 802406DC 00000000 */  nop
/* CCB9F0 802406E0 34631630 */  ori       $v1, $v1, 0x1630
/* CCB9F4 802406E4 27A40010 */  addiu     $a0, $sp, 0x10
/* CCB9F8 802406E8 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* CCB9FC 802406EC 94A541F0 */  lhu       $a1, %lo(gMatrixListPos)($a1)
/* CCBA00 802406F0 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* CCBA04 802406F4 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* CCBA08 802406F8 00052980 */  sll       $a1, $a1, 6
/* CCBA0C 802406FC 00A32821 */  addu      $a1, $a1, $v1
/* CCBA10 80240700 00452821 */  addu      $a1, $v0, $a1
/* CCBA14 80240704 46200020 */  cvt.s.d   $f0, $f0
/* CCBA18 80240708 0C019D40 */  jal       guMtxF2L
/* CCBA1C 8024070C E7A00034 */   swc1     $f0, 0x34($sp)
/* CCBA20 80240710 0000202D */  daddu     $a0, $zero, $zero
/* CCBA24 80240714 27A50050 */  addiu     $a1, $sp, 0x50
/* CCBA28 80240718 27A60054 */  addiu     $a2, $sp, 0x54
/* CCBA2C 8024071C 0C0470AC */  jal       func_8011C2B0
/* CCBA30 80240720 27A70058 */   addiu    $a3, $sp, 0x58
/* CCBA34 80240724 3C03DA38 */  lui       $v1, 0xda38
/* CCBA38 80240728 34630001 */  ori       $v1, $v1, 1
/* CCBA3C 8024072C 3C080001 */  lui       $t0, 1
/* CCBA40 80240730 35081630 */  ori       $t0, $t0, 0x1630
/* CCBA44 80240734 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* CCBA48 80240738 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* CCBA4C 8024073C 0000202D */  daddu     $a0, $zero, $zero
/* CCBA50 80240740 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* CCBA54 80240744 24A541F0 */  addiu     $a1, $a1, %lo(gMatrixListPos)
/* CCBA58 80240748 8CD00000 */  lw        $s0, ($a2)
/* CCBA5C 8024074C 94A20000 */  lhu       $v0, ($a1)
/* CCBA60 80240750 0200382D */  daddu     $a3, $s0, $zero
/* CCBA64 80240754 26100008 */  addiu     $s0, $s0, 8
/* CCBA68 80240758 ACD00000 */  sw        $s0, ($a2)
/* CCBA6C 8024075C ACE30000 */  sw        $v1, ($a3)
/* CCBA70 80240760 24430001 */  addiu     $v1, $v0, 1
/* CCBA74 80240764 3042FFFF */  andi      $v0, $v0, 0xffff
/* CCBA78 80240768 00021180 */  sll       $v0, $v0, 6
/* CCBA7C 8024076C A4A30000 */  sh        $v1, ($a1)
/* CCBA80 80240770 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* CCBA84 80240774 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* CCBA88 80240778 00481021 */  addu      $v0, $v0, $t0
/* CCBA8C 8024077C 00621821 */  addu      $v1, $v1, $v0
/* CCBA90 80240780 26020008 */  addiu     $v0, $s0, 8
/* CCBA94 80240784 ACE30004 */  sw        $v1, 4($a3)
/* CCBA98 80240788 ACC20000 */  sw        $v0, ($a2)
/* CCBA9C 8024078C 3C02DE00 */  lui       $v0, 0xde00
/* CCBAA0 80240790 0C0470BB */  jal       func_8011C2EC
/* CCBAA4 80240794 AE020000 */   sw       $v0, ($s0)
/* CCBAA8 80240798 3C038024 */  lui       $v1, %hi(D_80243B14_CCEE24)
/* CCBAAC 8024079C 24633B14 */  addiu     $v1, $v1, %lo(D_80243B14_CCEE24)
/* CCBAB0 802407A0 C4600000 */  lwc1      $f0, ($v1)
/* CCBAB4 802407A4 3C013F80 */  lui       $at, 0x3f80
/* CCBAB8 802407A8 44811000 */  mtc1      $at, $f2
/* CCBABC 802407AC 00000000 */  nop
/* CCBAC0 802407B0 46020000 */  add.s     $f0, $f0, $f2
/* CCBAC4 802407B4 AE020004 */  sw        $v0, 4($s0)
/* CCBAC8 802407B8 E4600000 */  swc1      $f0, ($v1)
/* CCBACC 802407BC 8FBF0064 */  lw        $ra, 0x64($sp)
/* CCBAD0 802407C0 8FB00060 */  lw        $s0, 0x60($sp)
/* CCBAD4 802407C4 D7B60070 */  ldc1      $f22, 0x70($sp)
/* CCBAD8 802407C8 D7B40068 */  ldc1      $f20, 0x68($sp)
/* CCBADC 802407CC 03E00008 */  jr        $ra
/* CCBAE0 802407D0 27BD0078 */   addiu    $sp, $sp, 0x78
