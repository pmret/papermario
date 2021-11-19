.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80244FA0_ADAE70
.double 0.1

dlabel D_80244FA8_ADAE78
.double 1.3

dlabel D_80244FB0_ADAE80
.double 0.4

dlabel D_80244FB8_ADAE88
.double 0.2, 7.370960555125578e+228, 1.1479345603117537e+195

.section .text

glabel func_802404E0_AD63B0
/* AD63B0 802404E0 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* AD63B4 802404E4 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* AD63B8 802404E8 3C018024 */  lui       $at, %hi(D_80244FA0_ADAE70)
/* AD63BC 802404EC D43C4FA0 */  ldc1      $f28, %lo(D_80244FA0_ADAE70)($at)
/* AD63C0 802404F0 AFB20020 */  sw        $s2, 0x20($sp)
/* AD63C4 802404F4 0000902D */  daddu     $s2, $zero, $zero
/* AD63C8 802404F8 AFB30024 */  sw        $s3, 0x24($sp)
/* AD63CC 802404FC 0240982D */  daddu     $s3, $s2, $zero
/* AD63D0 80240500 AFB1001C */  sw        $s1, 0x1c($sp)
/* AD63D4 80240504 3C118024 */  lui       $s1, %hi(D_80243614_AD94E4)
/* AD63D8 80240508 26313614 */  addiu     $s1, $s1, %lo(D_80243614_AD94E4)
/* AD63DC 8024050C AFBF0028 */  sw        $ra, 0x28($sp)
/* AD63E0 80240510 AFB00018 */  sw        $s0, 0x18($sp)
/* AD63E4 80240514 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* AD63E8 80240518 F7B80040 */  sdc1      $f24, 0x40($sp)
/* AD63EC 8024051C F7B60038 */  sdc1      $f22, 0x38($sp)
/* AD63F0 80240520 F7B40030 */  sdc1      $f20, 0x30($sp)
.L80240524:
/* AD63F4 80240524 86220002 */  lh        $v0, 2($s1)
/* AD63F8 80240528 32500001 */  andi      $s0, $s2, 1
/* AD63FC 8024052C 44826000 */  mtc1      $v0, $f12
/* AD6400 80240530 00000000 */  nop
/* AD6404 80240534 46806320 */  cvt.s.w   $f12, $f12
/* AD6408 80240538 86220000 */  lh        $v0, ($s1)
/* AD640C 8024053C 4482A000 */  mtc1      $v0, $f20
/* AD6410 80240540 00000000 */  nop
/* AD6414 80240544 4680A520 */  cvt.s.w   $f20, $f20
/* AD6418 80240548 0C00A8D4 */  jal       cos_deg
/* AD641C 8024054C 26100002 */   addiu    $s0, $s0, 2
/* AD6420 80240550 4600A002 */  mul.s     $f0, $f20, $f0
/* AD6424 80240554 00000000 */  nop
/* AD6428 80240558 3C018024 */  lui       $at, %hi(D_80244FA8_ADAE78)
/* AD642C 8024055C D4224FA8 */  ldc1      $f2, %lo(D_80244FA8_ADAE78)($at)
/* AD6430 80240560 46000021 */  cvt.d.s   $f0, $f0
/* AD6434 80240564 46220002 */  mul.d     $f0, $f0, $f2
/* AD6438 80240568 00000000 */  nop
/* AD643C 8024056C 86220002 */  lh        $v0, 2($s1)
/* AD6440 80240570 44826000 */  mtc1      $v0, $f12
/* AD6444 80240574 00000000 */  nop
/* AD6448 80240578 46806320 */  cvt.s.w   $f12, $f12
/* AD644C 8024057C 0C00A8BB */  jal       sin_deg
/* AD6450 80240580 46200620 */   cvt.s.d  $f24, $f0
/* AD6454 80240584 4600A002 */  mul.s     $f0, $f20, $f0
/* AD6458 80240588 00000000 */  nop
/* AD645C 8024058C 3C013FF8 */  lui       $at, 0x3ff8
/* AD6460 80240590 44811800 */  mtc1      $at, $f3
/* AD6464 80240594 44801000 */  mtc1      $zero, $f2
/* AD6468 80240598 46000021 */  cvt.d.s   $f0, $f0
/* AD646C 8024059C 46220002 */  mul.d     $f0, $f0, $f2
/* AD6470 802405A0 00000000 */  nop
/* AD6474 802405A4 4600C0A1 */  cvt.d.s   $f2, $f24
/* AD6478 802405A8 463C1082 */  mul.d     $f2, $f2, $f28
/* AD647C 802405AC 00000000 */  nop
/* AD6480 802405B0 462006A0 */  cvt.s.d   $f26, $f0
/* AD6484 802405B4 4600D021 */  cvt.d.s   $f0, $f26
/* AD6488 802405B8 463C0002 */  mul.d     $f0, $f0, $f28
/* AD648C 802405BC 00000000 */  nop
/* AD6490 802405C0 3C014170 */  lui       $at, 0x4170
/* AD6494 802405C4 44816000 */  mtc1      $at, $f12
/* AD6498 802405C8 00000000 */  nop
/* AD649C 802405CC 460CA302 */  mul.s     $f12, $f20, $f12
/* AD64A0 802405D0 00000000 */  nop
/* AD64A4 802405D4 3C014416 */  lui       $at, 0x4416
/* AD64A8 802405D8 4481B000 */  mtc1      $at, $f22
/* AD64AC 802405DC 00000000 */  nop
/* AD64B0 802405E0 4616C580 */  add.s     $f22, $f24, $f22
/* AD64B4 802405E4 3C0142C8 */  lui       $at, 0x42c8
/* AD64B8 802405E8 4481A000 */  mtc1      $at, $f20
/* AD64BC 802405EC 46201620 */  cvt.s.d   $f24, $f2
/* AD64C0 802405F0 4614D500 */  add.s     $f20, $f26, $f20
/* AD64C4 802405F4 0C00A8D4 */  jal       cos_deg
/* AD64C8 802405F8 462006A0 */   cvt.s.d  $f26, $f0
/* AD64CC 802405FC 32420003 */  andi      $v0, $s2, 3
/* AD64D0 80240600 3C018024 */  lui       $at, %hi(D_80244FB0_ADAE80)
/* AD64D4 80240604 D4244FB0 */  ldc1      $f4, %lo(D_80244FB0_ADAE80)($at)
/* AD64D8 80240608 44821000 */  mtc1      $v0, $f2
/* AD64DC 8024060C 00000000 */  nop
/* AD64E0 80240610 468010A1 */  cvt.d.w   $f2, $f2
/* AD64E4 80240614 46241082 */  mul.d     $f2, $f2, $f4
/* AD64E8 80240618 00000000 */  nop
/* AD64EC 8024061C 3C0140A0 */  lui       $at, 0x40a0
/* AD64F0 80240620 44812000 */  mtc1      $at, $f4
/* AD64F4 80240624 00000000 */  nop
/* AD64F8 80240628 46040002 */  mul.s     $f0, $f0, $f4
/* AD64FC 8024062C 00000000 */  nop
/* AD6500 80240630 0200202D */  daddu     $a0, $s0, $zero
/* AD6504 80240634 00021080 */  sll       $v0, $v0, 2
/* AD6508 80240638 4405B000 */  mfc1      $a1, $f22
/* AD650C 8024063C 4406A000 */  mfc1      $a2, $f20
/* AD6510 80240640 4600C600 */  add.s     $f24, $f24, $f0
/* AD6514 80240644 3C013FF0 */  lui       $at, 0x3ff0
/* AD6518 80240648 44810800 */  mtc1      $at, $f1
/* AD651C 8024064C 44800000 */  mtc1      $zero, $f0
/* AD6520 80240650 3C07C316 */  lui       $a3, 0xc316
/* AD6524 80240654 46201080 */  add.d     $f2, $f2, $f0
/* AD6528 80240658 2442001E */  addiu     $v0, $v0, 0x1e
/* AD652C 8024065C AFA20014 */  sw        $v0, 0x14($sp)
/* AD6530 80240660 462010A0 */  cvt.s.d   $f2, $f2
/* AD6534 80240664 0C01C994 */  jal       playFX_7A
/* AD6538 80240668 E7A20010 */   swc1     $f2, 0x10($sp)
/* AD653C 8024066C 0040802D */  daddu     $s0, $v0, $zero
/* AD6540 80240670 8E02000C */  lw        $v0, 0xc($s0)
/* AD6544 80240674 2404000A */  addiu     $a0, $zero, 0xa
/* AD6548 80240678 0C00A67F */  jal       rand_int
/* AD654C 8024067C AC400044 */   sw       $zero, 0x44($v0)
/* AD6550 80240680 3C018024 */  lui       $at, %hi(D_80244FB8_ADAE88)
/* AD6554 80240684 D4224FB8 */  ldc1      $f2, %lo(D_80244FB8_ADAE88)($at)
/* AD6558 80240688 44820000 */  mtc1      $v0, $f0
/* AD655C 8024068C 00000000 */  nop
/* AD6560 80240690 46800021 */  cvt.d.w   $f0, $f0
/* AD6564 80240694 46220002 */  mul.d     $f0, $f0, $f2
/* AD6568 80240698 00000000 */  nop
/* AD656C 8024069C 463C0000 */  add.d     $f0, $f0, $f28
/* AD6570 802406A0 2404000A */  addiu     $a0, $zero, 0xa
/* AD6574 802406A4 8E02000C */  lw        $v0, 0xc($s0)
/* AD6578 802406A8 46200020 */  cvt.s.d   $f0, $f0
/* AD657C 802406AC E4400048 */  swc1      $f0, 0x48($v0)
/* AD6580 802406B0 8E02000C */  lw        $v0, 0xc($s0)
/* AD6584 802406B4 44930000 */  mtc1      $s3, $f0
/* AD6588 802406B8 00000000 */  nop
/* AD658C 802406BC 46800020 */  cvt.s.w   $f0, $f0
/* AD6590 802406C0 0C00A67F */  jal       rand_int
/* AD6594 802406C4 E440003C */   swc1     $f0, 0x3c($v0)
/* AD6598 802406C8 2442FFFB */  addiu     $v0, $v0, -5
/* AD659C 802406CC 8E03000C */  lw        $v1, 0xc($s0)
/* AD65A0 802406D0 44820000 */  mtc1      $v0, $f0
/* AD65A4 802406D4 00000000 */  nop
/* AD65A8 802406D8 46800020 */  cvt.s.w   $f0, $f0
/* AD65AC 802406DC E4600040 */  swc1      $f0, 0x40($v1)
/* AD65B0 802406E0 8E02000C */  lw        $v0, 0xc($s0)
/* AD65B4 802406E4 3C014000 */  lui       $at, 0x4000
/* AD65B8 802406E8 44810000 */  mtc1      $at, $f0
/* AD65BC 802406EC E458004C */  swc1      $f24, 0x4c($v0)
/* AD65C0 802406F0 8E02000C */  lw        $v0, 0xc($s0)
/* AD65C4 802406F4 26310004 */  addiu     $s1, $s1, 4
/* AD65C8 802406F8 E45A0050 */  swc1      $f26, 0x50($v0)
/* AD65CC 802406FC 8E02000C */  lw        $v0, 0xc($s0)
/* AD65D0 80240700 26520001 */  addiu     $s2, $s2, 1
/* AD65D4 80240704 E4400054 */  swc1      $f0, 0x54($v0)
/* AD65D8 80240708 8E02000C */  lw        $v0, 0xc($s0)
/* AD65DC 8024070C 3C01BDCC */  lui       $at, 0xbdcc
/* AD65E0 80240710 3421CCCD */  ori       $at, $at, 0xcccd
/* AD65E4 80240714 44810000 */  mtc1      $at, $f0
/* AD65E8 80240718 00000000 */  nop
/* AD65EC 8024071C E4400058 */  swc1      $f0, 0x58($v0)
/* AD65F0 80240720 2A42001C */  slti      $v0, $s2, 0x1c
/* AD65F4 80240724 1440FF7F */  bnez      $v0, .L80240524
/* AD65F8 80240728 26730023 */   addiu    $s3, $s3, 0x23
/* AD65FC 8024072C 8FBF0028 */  lw        $ra, 0x28($sp)
/* AD6600 80240730 8FB30024 */  lw        $s3, 0x24($sp)
/* AD6604 80240734 8FB20020 */  lw        $s2, 0x20($sp)
/* AD6608 80240738 8FB1001C */  lw        $s1, 0x1c($sp)
/* AD660C 8024073C 8FB00018 */  lw        $s0, 0x18($sp)
/* AD6610 80240740 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* AD6614 80240744 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* AD6618 80240748 D7B80040 */  ldc1      $f24, 0x40($sp)
/* AD661C 8024074C D7B60038 */  ldc1      $f22, 0x38($sp)
/* AD6620 80240750 D7B40030 */  ldc1      $f20, 0x30($sp)
/* AD6624 80240754 24020002 */  addiu     $v0, $zero, 2
/* AD6628 80240758 03E00008 */  jr        $ra
/* AD662C 8024075C 27BD0058 */   addiu    $sp, $sp, 0x58
