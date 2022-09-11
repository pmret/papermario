.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_E0066D20
.double 0.7, 0.0

.section .text

glabel radial_shimmer_update
/* 3664C8 E0066498 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3664CC E006649C AFB1003C */  sw        $s1, 0x3c($sp)
/* 3664D0 E00664A0 0080882D */  daddu     $s1, $a0, $zero
/* 3664D4 E00664A4 AFBF0040 */  sw        $ra, 0x40($sp)
/* 3664D8 E00664A8 AFB00038 */  sw        $s0, 0x38($sp)
/* 3664DC E00664AC F7B40048 */  sdc1      $f20, 0x48($sp)
/* 3664E0 E00664B0 8E30000C */  lw        $s0, 0xc($s1)
/* 3664E4 E00664B4 8E020028 */  lw        $v0, 0x28($s0)
/* 3664E8 E00664B8 8E03002C */  lw        $v1, 0x2c($s0)
/* 3664EC E00664BC 2442FFFF */  addiu     $v0, $v0, -1
/* 3664F0 E00664C0 24630001 */  addiu     $v1, $v1, 1
/* 3664F4 E00664C4 AE020028 */  sw        $v0, 0x28($s0)
/* 3664F8 E00664C8 AE03002C */  sw        $v1, 0x2c($s0)
/* 3664FC E00664CC 8E230000 */  lw        $v1, ($s1)
/* 366500 E00664D0 30620010 */  andi      $v0, $v1, 0x10
/* 366504 E00664D4 10400005 */  beqz      $v0, .LE00664EC
/* 366508 E00664D8 2402FFEF */   addiu    $v0, $zero, -0x11
/* 36650C E00664DC 00621024 */  and       $v0, $v1, $v0
/* 366510 E00664E0 AE220000 */  sw        $v0, ($s1)
/* 366514 E00664E4 24020010 */  addiu     $v0, $zero, 0x10
/* 366518 E00664E8 AE020028 */  sw        $v0, 0x28($s0)
.LE00664EC:
/* 36651C E00664EC 8E050028 */  lw        $a1, 0x28($s0)
/* 366520 E00664F0 04A10005 */  bgez      $a1, .LE0066508
/* 366524 E00664F4 00000000 */   nop
/* 366528 E00664F8 0C080128 */  jal       shim_remove_effect
/* 36652C E00664FC 0220202D */   daddu    $a0, $s1, $zero
/* 366530 E0066500 080199C5 */  j         .LE0066714
/* 366534 E0066504 00000000 */   nop
.LE0066508:
/* 366538 E0066508 8E04002C */  lw        $a0, 0x2c($s0)
/* 36653C E006650C 2882000B */  slti      $v0, $a0, 0xb
/* 366540 E0066510 1040000A */  beqz      $v0, .LE006653C
/* 366544 E0066514 3C036666 */   lui      $v1, 0x6666
/* 366548 E0066518 34636667 */  ori       $v1, $v1, 0x6667
/* 36654C E006651C 00041200 */  sll       $v0, $a0, 8
/* 366550 E0066520 00441023 */  subu      $v0, $v0, $a0
/* 366554 E0066524 00430018 */  mult      $v0, $v1
/* 366558 E0066528 000217C3 */  sra       $v0, $v0, 0x1f
/* 36655C E006652C 00004010 */  mfhi      $t0
/* 366560 E0066530 00081883 */  sra       $v1, $t0, 2
/* 366564 E0066534 00621823 */  subu      $v1, $v1, $v0
/* 366568 E0066538 AE030024 */  sw        $v1, 0x24($s0)
.LE006653C:
/* 36656C E006653C 28A20006 */  slti      $v0, $a1, 6
/* 366570 E0066540 10400009 */  beqz      $v0, .LE0066568
/* 366574 E0066544 3C032AAA */   lui      $v1, 0x2aaa
/* 366578 E0066548 3463AAAB */  ori       $v1, $v1, 0xaaab
/* 36657C E006654C 00051200 */  sll       $v0, $a1, 8
/* 366580 E0066550 00451023 */  subu      $v0, $v0, $a1
/* 366584 E0066554 00430018 */  mult      $v0, $v1
/* 366588 E0066558 000217C3 */  sra       $v0, $v0, 0x1f
/* 36658C E006655C 00004010 */  mfhi      $t0
/* 366590 E0066560 01021023 */  subu      $v0, $t0, $v0
/* 366594 E0066564 AE020024 */  sw        $v0, 0x24($s0)
.LE0066568:
/* 366598 E0066568 28A2000A */  slti      $v0, $a1, 0xa
/* 36659C E006656C 1040000C */  beqz      $v0, .LE00665A0
/* 3665A0 E0066570 24020004 */   addiu    $v0, $zero, 4
/* 3665A4 E0066574 8E030000 */  lw        $v1, ($s0)
/* 3665A8 E0066578 14620009 */  bne       $v1, $v0, .LE00665A0
/* 3665AC E006657C 00000000 */   nop
/* 3665B0 E0066580 C600001C */  lwc1      $f0, 0x1c($s0)
/* 3665B4 E0066584 3C01E006 */  lui       $at, %hi(D_E0066D20)
/* 3665B8 E0066588 D4226D20 */  ldc1      $f2, %lo(D_E0066D20)($at)
/* 3665BC E006658C 46000021 */  cvt.d.s   $f0, $f0
/* 3665C0 E0066590 46220002 */  mul.d     $f0, $f0, $f2
/* 3665C4 E0066594 00000000 */  nop
/* 3665C8 E0066598 46200020 */  cvt.s.d   $f0, $f0
/* 3665CC E006659C E600001C */  swc1      $f0, 0x1c($s0)
.LE00665A0:
/* 3665D0 E00665A0 C6000020 */  lwc1      $f0, 0x20($s0)
/* 3665D4 E00665A4 3C013F80 */  lui       $at, 0x3f80
/* 3665D8 E00665A8 4481A000 */  mtc1      $at, $f20
/* 3665DC E00665AC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3665E0 E00665B0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3665E4 E00665B4 27A20028 */  addiu     $v0, $sp, 0x28
/* 3665E8 E00665B8 E600001C */  swc1      $f0, 0x1c($s0)
/* 3665EC E00665BC AFA20014 */  sw        $v0, 0x14($sp)
/* 3665F0 E00665C0 27A2002C */  addiu     $v0, $sp, 0x2c
/* 3665F4 E00665C4 AFA20018 */  sw        $v0, 0x18($sp)
/* 3665F8 E00665C8 27A20030 */  addiu     $v0, $sp, 0x30
/* 3665FC E00665CC AFA2001C */  sw        $v0, 0x1c($sp)
/* 366600 E00665D0 27A20034 */  addiu     $v0, $sp, 0x34
/* 366604 E00665D4 00032080 */  sll       $a0, $v1, 2
/* 366608 E00665D8 00832021 */  addu      $a0, $a0, $v1
/* 36660C E00665DC 00042080 */  sll       $a0, $a0, 2
/* 366610 E00665E0 00832023 */  subu      $a0, $a0, $v1
/* 366614 E00665E4 AFA20020 */  sw        $v0, 0x20($sp)
/* 366618 E00665E8 000410C0 */  sll       $v0, $a0, 3
/* 36661C E00665EC 00822021 */  addu      $a0, $a0, $v0
/* 366620 E00665F0 000420C0 */  sll       $a0, $a0, 3
/* 366624 E00665F4 3C02800B */  lui       $v0, %hi(gCameras+0xD4)
/* 366628 E00665F8 24421E54 */  addiu     $v0, $v0, %lo(gCameras+0xD4)
/* 36662C E00665FC E7B40010 */  swc1      $f20, 0x10($sp)
/* 366630 E0066600 8E050004 */  lw        $a1, 4($s0)
/* 366634 E0066604 8E060008 */  lw        $a2, 8($s0)
/* 366638 E0066608 8E07000C */  lw        $a3, 0xc($s0)
/* 36663C E006660C 0C080168 */  jal       shim_transform_point
/* 366640 E0066610 00822021 */   addu     $a0, $a0, $v0
/* 366644 E0066614 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 366648 E0066618 C7A40028 */  lwc1      $f4, 0x28($sp)
/* 36664C E006661C 4600A503 */  div.s     $f20, $f20, $f0
/* 366650 E0066620 46142102 */  mul.s     $f4, $f4, $f20
/* 366654 E0066624 00000000 */  nop
/* 366658 E0066628 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 36665C E006662C 46140002 */  mul.s     $f0, $f0, $f20
/* 366660 E0066630 00000000 */  nop
/* 366664 E0066634 C7A20030 */  lwc1      $f2, 0x30($sp)
/* 366668 E0066638 46141082 */  mul.s     $f2, $f2, $f20
/* 36666C E006663C 00000000 */  nop
/* 366670 E0066640 AE000018 */  sw        $zero, 0x18($s0)
/* 366674 E0066644 E6040010 */  swc1      $f4, 0x10($s0)
/* 366678 E0066648 E6000014 */  swc1      $f0, 0x14($s0)
/* 36667C E006664C 8E220008 */  lw        $v0, 8($s1)
/* 366680 E0066650 0000202D */  daddu     $a0, $zero, $zero
/* 366684 E0066654 E7B40034 */  swc1      $f20, 0x34($sp)
/* 366688 E0066658 E7A40028 */  swc1      $f4, 0x28($sp)
/* 36668C E006665C E7A0002C */  swc1      $f0, 0x2c($sp)
/* 366690 E0066660 1840002C */  blez      $v0, .LE0066714
/* 366694 E0066664 E7A20030 */   swc1     $f2, 0x30($sp)
/* 366698 E0066668 26030048 */  addiu     $v1, $s0, 0x48
/* 36669C E006666C C60E0018 */  lwc1      $f14, 0x18($s0)
/* 3666A0 E0066670 3C014400 */  lui       $at, 0x4400
/* 3666A4 E0066674 44816000 */  mtc1      $at, $f12
.LE0066678:
/* 3666A8 E0066678 C4620010 */  lwc1      $f2, 0x10($v1)
/* 3666AC E006667C C4600014 */  lwc1      $f0, 0x14($v1)
/* 3666B0 E0066680 C4680008 */  lwc1      $f8, 8($v1)
/* 3666B4 E0066684 C464FFF8 */  lwc1      $f4, -8($v1)
/* 3666B8 E0066688 46001080 */  add.s     $f2, $f2, $f0
/* 3666BC E006668C C460000C */  lwc1      $f0, 0xc($v1)
/* 3666C0 E0066690 C46AFFE8 */  lwc1      $f10, -0x18($v1)
/* 3666C4 E0066694 46004200 */  add.s     $f8, $f8, $f0
/* 3666C8 E0066698 C460FFFC */  lwc1      $f0, -4($v1)
/* 3666CC E006669C C466FFF0 */  lwc1      $f6, -0x10($v1)
/* 3666D0 E00666A0 46002100 */  add.s     $f4, $f4, $f0
/* 3666D4 E00666A4 C460FFEC */  lwc1      $f0, -0x14($v1)
/* 3666D8 E00666A8 E4620010 */  swc1      $f2, 0x10($v1)
/* 3666DC E00666AC 46005280 */  add.s     $f10, $f10, $f0
/* 3666E0 E00666B0 C462FFF4 */  lwc1      $f2, -0xc($v1)
/* 3666E4 E00666B4 46023180 */  add.s     $f6, $f6, $f2
/* 3666E8 E00666B8 C4600000 */  lwc1      $f0, ($v1)
/* 3666EC E00666BC C4620004 */  lwc1      $f2, 4($v1)
/* 3666F0 E00666C0 46020000 */  add.s     $f0, $f0, $f2
/* 3666F4 E00666C4 E4680008 */  swc1      $f8, 8($v1)
/* 3666F8 E00666C8 460E203C */  c.lt.s    $f4, $f14
/* 3666FC E00666CC E464FFF8 */  swc1      $f4, -8($v1)
/* 366700 E00666D0 E46AFFE8 */  swc1      $f10, -0x18($v1)
/* 366704 E00666D4 E466FFF0 */  swc1      $f6, -0x10($v1)
/* 366708 E00666D8 45000003 */  bc1f      .LE00666E8
/* 36670C E00666DC E4600000 */   swc1     $f0, ($v1)
/* 366710 E00666E0 460C2000 */  add.s     $f0, $f4, $f12
/* 366714 E00666E4 E460FFF8 */  swc1      $f0, -8($v1)
.LE00666E8:
/* 366718 E00666E8 C4600000 */  lwc1      $f0, ($v1)
/* 36671C E00666EC 460E003C */  c.lt.s    $f0, $f14
/* 366720 E00666F0 00000000 */  nop
/* 366724 E00666F4 45000003 */  bc1f      .LE0066704
/* 366728 E00666F8 24840001 */   addiu    $a0, $a0, 1
/* 36672C E00666FC 460C0000 */  add.s     $f0, $f0, $f12
/* 366730 E0066700 E4600000 */  swc1      $f0, ($v1)
.LE0066704:
/* 366734 E0066704 8E220008 */  lw        $v0, 8($s1)
/* 366738 E0066708 0082102A */  slt       $v0, $a0, $v0
/* 36673C E006670C 1440FFDA */  bnez      $v0, .LE0066678
/* 366740 E0066710 24630070 */   addiu    $v1, $v1, 0x70
.LE0066714:
/* 366744 E0066714 8FBF0040 */  lw        $ra, 0x40($sp)
/* 366748 E0066718 8FB1003C */  lw        $s1, 0x3c($sp)
/* 36674C E006671C 8FB00038 */  lw        $s0, 0x38($sp)
/* 366750 E0066720 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 366754 E0066724 03E00008 */  jr        $ra
/* 366758 E0066728 27BD0050 */   addiu    $sp, $sp, 0x50
