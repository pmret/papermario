.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_image_with_clipping
/* C5394 8012EC94 27BDFF80 */  addiu     $sp, $sp, -0x80
/* C5398 8012EC98 AFA7008C */  sw        $a3, 0x8c($sp)
/* C539C 8012EC9C 8FA70094 */  lw        $a3, 0x94($sp)
/* C53A0 8012ECA0 AFA60088 */  sw        $a2, 0x88($sp)
/* C53A4 8012ECA4 8FA60098 */  lw        $a2, 0x98($sp)
/* C53A8 8012ECA8 8FAC009C */  lw        $t4, 0x9c($sp)
/* C53AC 8012ECAC 8FA900A0 */  lw        $t1, 0xa0($sp)
/* C53B0 8012ECB0 8FAB00A4 */  lw        $t3, 0xa4($sp)
/* C53B4 8012ECB4 8FA800A8 */  lw        $t0, 0xa8($sp)
/* C53B8 8012ECB8 AFBE0078 */  sw        $fp, 0x78($sp)
/* C53BC 8012ECBC 8FBE0090 */  lw        $fp, 0x90($sp)
/* C53C0 8012ECC0 AFB70074 */  sw        $s7, 0x74($sp)
/* C53C4 8012ECC4 AFB60070 */  sw        $s6, 0x70($sp)
/* C53C8 8012ECC8 AFB5006C */  sw        $s5, 0x6c($sp)
/* C53CC 8012ECCC AFB40068 */  sw        $s4, 0x68($sp)
/* C53D0 8012ECD0 AFB30064 */  sw        $s3, 0x64($sp)
/* C53D4 8012ECD4 AFB20060 */  sw        $s2, 0x60($sp)
/* C53D8 8012ECD8 AFB1005C */  sw        $s1, 0x5c($sp)
/* C53DC 8012ECDC AFB00058 */  sw        $s0, 0x58($sp)
/* C53E0 8012ECE0 AFA40080 */  sw        $a0, 0x80($sp)
/* C53E4 8012ECE4 AFA50084 */  sw        $a1, 0x84($sp)
/* C53E8 8012ECE8 00E0C02D */  daddu     $t8, $a3, $zero
/* C53EC 8012ECEC 00071C00 */  sll       $v1, $a3, 0x10
/* C53F0 8012ECF0 00031C03 */  sra       $v1, $v1, 0x10
/* C53F4 8012ECF4 A7AC0018 */  sh        $t4, 0x18($sp)
/* C53F8 8012ECF8 3185FFFF */  andi      $a1, $t4, 0xffff
/* C53FC 8012ECFC A7AB001C */  sh        $t3, 0x1c($sp)
/* C5400 8012ED00 3162FFFF */  andi      $v0, $t3, 0xffff
/* C5404 8012ED04 00A21021 */  addu      $v0, $a1, $v0
/* C5408 8012ED08 0062182A */  slt       $v1, $v1, $v0
/* C540C 8012ED0C A7A60016 */  sh        $a2, 0x16($sp)
/* C5410 8012ED10 A7A9001A */  sh        $t1, 0x1a($sp)
/* C5414 8012ED14 10600017 */  beqz      $v1, .L8012ED74
/* C5418 8012ED18 A7A8001E */   sh       $t0, 0x1e($sp)
/* C541C 8012ED1C 00061C00 */  sll       $v1, $a2, 0x10
/* C5420 8012ED20 00031C03 */  sra       $v1, $v1, 0x10
/* C5424 8012ED24 3124FFFF */  andi      $a0, $t1, 0xffff
/* C5428 8012ED28 3102FFFF */  andi      $v0, $t0, 0xffff
/* C542C 8012ED2C 00821021 */  addu      $v0, $a0, $v0
/* C5430 8012ED30 0062182A */  slt       $v1, $v1, $v0
/* C5434 8012ED34 106001E7 */  beqz      $v1, .L8012F4D4
/* C5438 8012ED38 0000102D */   daddu    $v0, $zero, $zero
/* C543C 8012ED3C 8FB50084 */  lw        $s5, 0x84($sp)
/* C5440 8012ED40 00F51021 */  addu      $v0, $a3, $s5
/* C5444 8012ED44 00021400 */  sll       $v0, $v0, 0x10
/* C5448 8012ED48 00021403 */  sra       $v0, $v0, 0x10
/* C544C 8012ED4C 00A2102A */  slt       $v0, $a1, $v0
/* C5450 8012ED50 104001E0 */  beqz      $v0, .L8012F4D4
/* C5454 8012ED54 0000102D */   daddu    $v0, $zero, $zero
/* C5458 8012ED58 8FB60088 */  lw        $s6, 0x88($sp)
/* C545C 8012ED5C 00D61021 */  addu      $v0, $a2, $s6
/* C5460 8012ED60 00021400 */  sll       $v0, $v0, 0x10
/* C5464 8012ED64 00021403 */  sra       $v0, $v0, 0x10
/* C5468 8012ED68 0082102A */  slt       $v0, $a0, $v0
/* C546C 8012ED6C 14400003 */  bnez      $v0, .L8012ED7C
/* C5470 8012ED70 0080702D */   daddu    $t6, $a0, $zero
.L8012ED74:
/* C5474 8012ED74 0804BD35 */  j         .L8012F4D4
/* C5478 8012ED78 0000102D */   daddu    $v0, $zero, $zero
.L8012ED7C:
/* C547C 8012ED7C 01284821 */  addu      $t1, $t1, $t0
/* C5480 8012ED80 00A0502D */  daddu     $t2, $a1, $zero
/* C5484 8012ED84 018B6021 */  addu      $t4, $t4, $t3
/* C5488 8012ED88 8FB50088 */  lw        $s5, 0x88($sp)
/* C548C 8012ED8C 8FB60088 */  lw        $s6, 0x88($sp)
/* C5490 8012ED90 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* C5494 8012ED94 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* C5498 8012ED98 A3A00020 */  sb        $zero, 0x20($sp)
/* C549C 8012ED9C AFA90024 */  sw        $t1, 0x24($sp)
/* C54A0 8012EDA0 AFAC0034 */  sw        $t4, 0x34($sp)
/* C54A4 8012EDA4 A7A00002 */  sh        $zero, 2($sp)
/* C54A8 8012EDA8 A7A6000A */  sh        $a2, 0xa($sp)
/* C54AC 8012EDAC 26B5FFFF */  addiu     $s5, $s5, -1
/* C54B0 8012EDB0 AFB50028 */  sw        $s5, 0x28($sp)
/* C54B4 8012EDB4 8FB50084 */  lw        $s5, 0x84($sp)
/* C54B8 8012EDB8 02C6B021 */  addu      $s6, $s6, $a2
/* C54BC 8012EDBC AFB6002C */  sw        $s6, 0x2c($sp)
/* C54C0 8012EDC0 8FB60084 */  lw        $s6, 0x84($sp)
/* C54C4 8012EDC4 26B5FFFF */  addiu     $s5, $s5, -1
/* C54C8 8012EDC8 02C73821 */  addu      $a3, $s6, $a3
/* C54CC 8012EDCC AFB50038 */  sw        $s5, 0x38($sp)
/* C54D0 8012EDD0 AFA7003C */  sw        $a3, 0x3c($sp)
.L8012EDD4:
/* C54D4 8012EDD4 97A30002 */  lhu       $v1, 2($sp)
/* C54D8 8012EDD8 97A2000A */  lhu       $v0, 0xa($sp)
/* C54DC 8012EDDC A7A00056 */  sh        $zero, 0x56($sp)
/* C54E0 8012EDE0 2463001F */  addiu     $v1, $v1, 0x1f
/* C54E4 8012EDE4 24420020 */  addiu     $v0, $v0, 0x20
/* C54E8 8012EDE8 A7A2000E */  sh        $v0, 0xe($sp)
/* C54EC 8012EDEC 00021400 */  sll       $v0, $v0, 0x10
/* C54F0 8012EDF0 00021403 */  sra       $v0, $v0, 0x10
/* C54F4 8012EDF4 01C2102A */  slt       $v0, $t6, $v0
/* C54F8 8012EDF8 1440000E */  bnez      $v0, .L8012EE34
/* C54FC 8012EDFC A7A30006 */   sh       $v1, 6($sp)
.L8012EE00:
/* C5500 8012EE00 97A40002 */  lhu       $a0, 2($sp)
/* C5504 8012EE04 97A2000E */  lhu       $v0, 0xe($sp)
/* C5508 8012EE08 24830020 */  addiu     $v1, $a0, 0x20
/* C550C 8012EE0C A7A2000A */  sh        $v0, 0xa($sp)
/* C5510 8012EE10 24420020 */  addiu     $v0, $v0, 0x20
/* C5514 8012EE14 A7A2000E */  sh        $v0, 0xe($sp)
/* C5518 8012EE18 00021400 */  sll       $v0, $v0, 0x10
/* C551C 8012EE1C 00021403 */  sra       $v0, $v0, 0x10
/* C5520 8012EE20 004E102A */  slt       $v0, $v0, $t6
/* C5524 8012EE24 1440FFF6 */  bnez      $v0, .L8012EE00
/* C5528 8012EE28 A7A30002 */   sh       $v1, 2($sp)
/* C552C 8012EE2C 2482003F */  addiu     $v0, $a0, 0x3f
/* C5530 8012EE30 A7A20006 */  sh        $v0, 6($sp)
.L8012EE34:
/* C5534 8012EE34 87A2000A */  lh        $v0, 0xa($sp)
/* C5538 8012EE38 004E102A */  slt       $v0, $v0, $t6
/* C553C 8012EE3C 1040000A */  beqz      $v0, .L8012EE68
/* C5540 8012EE40 00000000 */   nop
/* C5544 8012EE44 97B50016 */  lhu       $s5, 0x16($sp)
/* C5548 8012EE48 97B6001A */  lhu       $s6, 0x1a($sp)
/* C554C 8012EE4C 00151400 */  sll       $v0, $s5, 0x10
/* C5550 8012EE50 00021403 */  sra       $v0, $v0, 0x10
/* C5554 8012EE54 004E1023 */  subu      $v0, $v0, $t6
/* C5558 8012EE58 04420001 */  bltzl     $v0, .L8012EE60
/* C555C 8012EE5C 00021023 */   negu     $v0, $v0
.L8012EE60:
/* C5560 8012EE60 A7A20056 */  sh        $v0, 0x56($sp)
/* C5564 8012EE64 A7B6000A */  sh        $s6, 0xa($sp)
.L8012EE68:
/* C5568 8012EE68 97A2001E */  lhu       $v0, 0x1e($sp)
/* C556C 8012EE6C 87A3000E */  lh        $v1, 0xe($sp)
/* C5570 8012EE70 01C21021 */  addu      $v0, $t6, $v0
/* C5574 8012EE74 0062182A */  slt       $v1, $v1, $v0
/* C5578 8012EE78 14600009 */  bnez      $v1, .L8012EEA0
/* C557C 8012EE7C 24150001 */   addiu    $s5, $zero, 1
/* C5580 8012EE80 8FB60024 */  lw        $s6, 0x24($sp)
/* C5584 8012EE84 A3B50020 */  sb        $s5, 0x20($sp)
/* C5588 8012EE88 97B50016 */  lhu       $s5, 0x16($sp)
/* C558C 8012EE8C 02D51023 */  subu      $v0, $s6, $s5
/* C5590 8012EE90 97B60026 */  lhu       $s6, 0x26($sp)
/* C5594 8012EE94 2442FFFF */  addiu     $v0, $v0, -1
/* C5598 8012EE98 A7A20006 */  sh        $v0, 6($sp)
/* C559C 8012EE9C A7B6000E */  sh        $s6, 0xe($sp)
.L8012EEA0:
/* C55A0 8012EEA0 97A20006 */  lhu       $v0, 6($sp)
/* C55A4 8012EEA4 8FB50088 */  lw        $s5, 0x88($sp)
/* C55A8 8012EEA8 00021400 */  sll       $v0, $v0, 0x10
/* C55AC 8012EEAC 00021403 */  sra       $v0, $v0, 0x10
/* C55B0 8012EEB0 24420001 */  addiu     $v0, $v0, 1
/* C55B4 8012EEB4 0055102B */  sltu      $v0, $v0, $s5
/* C55B8 8012EEB8 14400007 */  bnez      $v0, .L8012EED8
/* C55BC 8012EEBC 0000682D */   daddu    $t5, $zero, $zero
/* C55C0 8012EEC0 24160001 */  addiu     $s6, $zero, 1
/* C55C4 8012EEC4 97B5002A */  lhu       $s5, 0x2a($sp)
/* C55C8 8012EEC8 A3B60020 */  sb        $s6, 0x20($sp)
/* C55CC 8012EECC 97B6002E */  lhu       $s6, 0x2e($sp)
/* C55D0 8012EED0 A7B50006 */  sh        $s5, 6($sp)
/* C55D4 8012EED4 A7B6000E */  sh        $s6, 0xe($sp)
.L8012EED8:
/* C55D8 8012EED8 3C14F508 */  lui       $s4, 0xf508
/* C55DC 8012EEDC 3C0C0701 */  lui       $t4, 0x701
/* C55E0 8012EEE0 358C4060 */  ori       $t4, $t4, 0x4060
/* C55E4 8012EEE4 3C13E600 */  lui       $s3, 0xe600
/* C55E8 8012EEE8 3C12F400 */  lui       $s2, 0xf400
/* C55EC 8012EEEC 3C110700 */  lui       $s1, 0x700
/* C55F0 8012EEF0 3C10E700 */  lui       $s0, 0xe700
/* C55F4 8012EEF4 3C0B0001 */  lui       $t3, 1
/* C55F8 8012EEF8 356B4060 */  ori       $t3, $t3, 0x4060
/* C55FC 8012EEFC 3C19F200 */  lui       $t9, 0xf200
/* C5600 8012EF00 8FB5008C */  lw        $s5, 0x8c($sp)
/* C5604 8012EF04 8FB60038 */  lw        $s6, 0x38($sp)
/* C5608 8012EF08 3C17F510 */  lui       $s7, 0xf510
/* C560C 8012EF0C A7A00000 */  sh        $zero, ($sp)
/* C5610 8012EF10 A7B80008 */  sh        $t8, 8($sp)
/* C5614 8012EF14 32A20007 */  andi      $v0, $s5, 7
/* C5618 8012EF18 00024D40 */  sll       $t1, $v0, 0x15
/* C561C 8012EF1C 32D60FFF */  andi      $s6, $s6, 0xfff
/* C5620 8012EF20 3C15FD08 */  lui       $s5, 0xfd08
/* C5624 8012EF24 02D51025 */  or        $v0, $s6, $s5
/* C5628 8012EF28 01221025 */  or        $v0, $t1, $v0
/* C562C 8012EF2C AFB60048 */  sw        $s6, 0x48($sp)
/* C5630 8012EF30 AFA20040 */  sw        $v0, 0x40($sp)
.L8012EF34:
/* C5634 8012EF34 0000782D */  daddu     $t7, $zero, $zero
/* C5638 8012EF38 97A30000 */  lhu       $v1, ($sp)
/* C563C 8012EF3C 97A20008 */  lhu       $v0, 8($sp)
/* C5640 8012EF40 2463003F */  addiu     $v1, $v1, 0x3f
/* C5644 8012EF44 24420040 */  addiu     $v0, $v0, 0x40
/* C5648 8012EF48 A7A2000C */  sh        $v0, 0xc($sp)
/* C564C 8012EF4C 00021400 */  sll       $v0, $v0, 0x10
/* C5650 8012EF50 00021403 */  sra       $v0, $v0, 0x10
/* C5654 8012EF54 0142102A */  slt       $v0, $t2, $v0
/* C5658 8012EF58 1440000E */  bnez      $v0, .L8012EF94
/* C565C 8012EF5C A7A30004 */   sh       $v1, 4($sp)
.L8012EF60:
/* C5660 8012EF60 97A40000 */  lhu       $a0, ($sp)
/* C5664 8012EF64 97A2000C */  lhu       $v0, 0xc($sp)
/* C5668 8012EF68 24830040 */  addiu     $v1, $a0, 0x40
/* C566C 8012EF6C A7A20008 */  sh        $v0, 8($sp)
/* C5670 8012EF70 24420040 */  addiu     $v0, $v0, 0x40
/* C5674 8012EF74 A7A2000C */  sh        $v0, 0xc($sp)
/* C5678 8012EF78 00021400 */  sll       $v0, $v0, 0x10
/* C567C 8012EF7C 00021403 */  sra       $v0, $v0, 0x10
/* C5680 8012EF80 004A102A */  slt       $v0, $v0, $t2
/* C5684 8012EF84 1440FFF6 */  bnez      $v0, .L8012EF60
/* C5688 8012EF88 A7A30000 */   sh       $v1, ($sp)
/* C568C 8012EF8C 2482007F */  addiu     $v0, $a0, 0x7f
/* C5690 8012EF90 A7A20004 */  sh        $v0, 4($sp)
.L8012EF94:
/* C5694 8012EF94 87A20008 */  lh        $v0, 8($sp)
/* C5698 8012EF98 004A102A */  slt       $v0, $v0, $t2
/* C569C 8012EF9C 10400008 */  beqz      $v0, .L8012EFC0
/* C56A0 8012EFA0 00181400 */   sll      $v0, $t8, 0x10
/* C56A4 8012EFA4 00021403 */  sra       $v0, $v0, 0x10
/* C56A8 8012EFA8 004A1023 */  subu      $v0, $v0, $t2
/* C56AC 8012EFAC 97B60018 */  lhu       $s6, 0x18($sp)
/* C56B0 8012EFB0 04410002 */  bgez      $v0, .L8012EFBC
/* C56B4 8012EFB4 0040782D */   daddu    $t7, $v0, $zero
/* C56B8 8012EFB8 000F7823 */  negu      $t7, $t7
.L8012EFBC:
/* C56BC 8012EFBC A7B60008 */  sh        $s6, 8($sp)
.L8012EFC0:
/* C56C0 8012EFC0 97A2001C */  lhu       $v0, 0x1c($sp)
/* C56C4 8012EFC4 87A3000C */  lh        $v1, 0xc($sp)
/* C56C8 8012EFC8 01421021 */  addu      $v0, $t2, $v0
/* C56CC 8012EFCC 0062182A */  slt       $v1, $v1, $v0
/* C56D0 8012EFD0 14600008 */  bnez      $v1, .L8012EFF4
/* C56D4 8012EFD4 00000000 */   nop
/* C56D8 8012EFD8 240D0001 */  addiu     $t5, $zero, 1
/* C56DC 8012EFDC 8FB50034 */  lw        $s5, 0x34($sp)
/* C56E0 8012EFE0 97B60036 */  lhu       $s6, 0x36($sp)
/* C56E4 8012EFE4 02B81023 */  subu      $v0, $s5, $t8
/* C56E8 8012EFE8 2442FFFF */  addiu     $v0, $v0, -1
/* C56EC 8012EFEC A7A20004 */  sh        $v0, 4($sp)
/* C56F0 8012EFF0 A7B6000C */  sh        $s6, 0xc($sp)
.L8012EFF4:
/* C56F4 8012EFF4 97A20004 */  lhu       $v0, 4($sp)
/* C56F8 8012EFF8 8FB50084 */  lw        $s5, 0x84($sp)
/* C56FC 8012EFFC 00021400 */  sll       $v0, $v0, 0x10
/* C5700 8012F000 00021403 */  sra       $v0, $v0, 0x10
/* C5704 8012F004 24420001 */  addiu     $v0, $v0, 1
/* C5708 8012F008 0055102B */  sltu      $v0, $v0, $s5
/* C570C 8012F00C 14400006 */  bnez      $v0, .L8012F028
/* C5710 8012F010 00000000 */   nop
/* C5714 8012F014 240D0001 */  addiu     $t5, $zero, 1
/* C5718 8012F018 97B6003A */  lhu       $s6, 0x3a($sp)
/* C571C 8012F01C 97B5003E */  lhu       $s5, 0x3e($sp)
/* C5720 8012F020 A7B60004 */  sh        $s6, 4($sp)
/* C5724 8012F024 A7B5000C */  sh        $s5, 0xc($sp)
.L8012F028:
/* C5728 8012F028 57C0004D */  bnel      $fp, $zero, .L8012F160
/* C572C 8012F02C 24020002 */   addiu    $v0, $zero, 2
/* C5730 8012F030 8D050000 */  lw        $a1, ($t0)
/* C5734 8012F034 00A0182D */  daddu     $v1, $a1, $zero
/* C5738 8012F038 24A50008 */  addiu     $a1, $a1, 8
/* C573C 8012F03C AD050000 */  sw        $a1, ($t0)
/* C5740 8012F040 8FB60084 */  lw        $s6, 0x84($sp)
/* C5744 8012F044 3C15FD08 */  lui       $s5, 0xfd08
/* C5748 8012F048 00161042 */  srl       $v0, $s6, 1
/* C574C 8012F04C 2442FFFF */  addiu     $v0, $v0, -1
/* C5750 8012F050 30420FFF */  andi      $v0, $v0, 0xfff
/* C5754 8012F054 00551025 */  or        $v0, $v0, $s5
/* C5758 8012F058 01221025 */  or        $v0, $t1, $v0
/* C575C 8012F05C AC620000 */  sw        $v0, ($v1)
/* C5760 8012F060 8FB60080 */  lw        $s6, 0x80($sp)
/* C5764 8012F064 AC760004 */  sw        $s6, 4($v1)
/* C5768 8012F068 97A20004 */  lhu       $v0, 4($sp)
/* C576C 8012F06C 87A40000 */  lh        $a0, ($sp)
/* C5770 8012F070 24A30008 */  addiu     $v1, $a1, 8
/* C5774 8012F074 AD030000 */  sw        $v1, ($t0)
/* C5778 8012F078 ACAC0004 */  sw        $t4, 4($a1)
/* C577C 8012F07C ACB30008 */  sw        $s3, 8($a1)
/* C5780 8012F080 ACA0000C */  sw        $zero, 0xc($a1)
/* C5784 8012F084 00021400 */  sll       $v0, $v0, 0x10
/* C5788 8012F088 00021403 */  sra       $v0, $v0, 0x10
/* C578C 8012F08C 00441023 */  subu      $v0, $v0, $a0
/* C5790 8012F090 24420001 */  addiu     $v0, $v0, 1
/* C5794 8012F094 00021043 */  sra       $v0, $v0, 1
/* C5798 8012F098 24420007 */  addiu     $v0, $v0, 7
/* C579C 8012F09C 000210C3 */  sra       $v0, $v0, 3
/* C57A0 8012F0A0 304201FF */  andi      $v0, $v0, 0x1ff
/* C57A4 8012F0A4 00021240 */  sll       $v0, $v0, 9
/* C57A8 8012F0A8 00541025 */  or        $v0, $v0, $s4
/* C57AC 8012F0AC 01221025 */  or        $v0, $t1, $v0
/* C57B0 8012F0B0 ACA20000 */  sw        $v0, ($a1)
/* C57B4 8012F0B4 87A30000 */  lh        $v1, ($sp)
/* C57B8 8012F0B8 24A20010 */  addiu     $v0, $a1, 0x10
/* C57BC 8012F0BC AD020000 */  sw        $v0, ($t0)
/* C57C0 8012F0C0 97A20002 */  lhu       $v0, 2($sp)
/* C57C4 8012F0C4 00031840 */  sll       $v1, $v1, 1
/* C57C8 8012F0C8 30630FFF */  andi      $v1, $v1, 0xfff
/* C57CC 8012F0CC 00031B00 */  sll       $v1, $v1, 0xc
/* C57D0 8012F0D0 00021080 */  sll       $v0, $v0, 2
/* C57D4 8012F0D4 30420FFC */  andi      $v0, $v0, 0xffc
/* C57D8 8012F0D8 00521025 */  or        $v0, $v0, $s2
/* C57DC 8012F0DC 00621825 */  or        $v1, $v1, $v0
/* C57E0 8012F0E0 ACA30010 */  sw        $v1, 0x10($a1)
/* C57E4 8012F0E4 97A30004 */  lhu       $v1, 4($sp)
/* C57E8 8012F0E8 97A40006 */  lhu       $a0, 6($sp)
/* C57EC 8012F0EC 24A20018 */  addiu     $v0, $a1, 0x18
/* C57F0 8012F0F0 AD020000 */  sw        $v0, ($t0)
/* C57F4 8012F0F4 ACB00018 */  sw        $s0, 0x18($a1)
/* C57F8 8012F0F8 ACA0001C */  sw        $zero, 0x1c($a1)
/* C57FC 8012F0FC 00031840 */  sll       $v1, $v1, 1
/* C5800 8012F100 30630FFE */  andi      $v1, $v1, 0xffe
/* C5804 8012F104 00031B00 */  sll       $v1, $v1, 0xc
/* C5808 8012F108 00042080 */  sll       $a0, $a0, 2
/* C580C 8012F10C 30840FFC */  andi      $a0, $a0, 0xffc
/* C5810 8012F110 00912025 */  or        $a0, $a0, $s1
/* C5814 8012F114 00641825 */  or        $v1, $v1, $a0
/* C5818 8012F118 ACA30014 */  sw        $v1, 0x14($a1)
/* C581C 8012F11C 97A20004 */  lhu       $v0, 4($sp)
/* C5820 8012F120 87A40000 */  lh        $a0, ($sp)
/* C5824 8012F124 24A30020 */  addiu     $v1, $a1, 0x20
/* C5828 8012F128 AD030000 */  sw        $v1, ($t0)
/* C582C 8012F12C 3C03F500 */  lui       $v1, 0xf500
/* C5830 8012F130 ACAB0024 */  sw        $t3, 0x24($a1)
/* C5834 8012F134 00021400 */  sll       $v0, $v0, 0x10
/* C5838 8012F138 00021403 */  sra       $v0, $v0, 0x10
/* C583C 8012F13C 00441023 */  subu      $v0, $v0, $a0
/* C5840 8012F140 24420001 */  addiu     $v0, $v0, 1
/* C5844 8012F144 00021043 */  sra       $v0, $v0, 1
/* C5848 8012F148 24420007 */  addiu     $v0, $v0, 7
/* C584C 8012F14C 000210C3 */  sra       $v0, $v0, 3
/* C5850 8012F150 304201FF */  andi      $v0, $v0, 0x1ff
/* C5854 8012F154 00021240 */  sll       $v0, $v0, 9
/* C5858 8012F158 0804BCE2 */  j         .L8012F388
/* C585C 8012F15C 00431025 */   or       $v0, $v0, $v1
.L8012F160:
/* C5860 8012F160 57C20047 */  bnel      $fp, $v0, .L8012F280
/* C5864 8012F164 24020001 */   addiu    $v0, $zero, 1
/* C5868 8012F168 8D050000 */  lw        $a1, ($t0)
/* C586C 8012F16C 00A0182D */  daddu     $v1, $a1, $zero
/* C5870 8012F170 24A50008 */  addiu     $a1, $a1, 8
/* C5874 8012F174 AD050000 */  sw        $a1, ($t0)
/* C5878 8012F178 8FB50048 */  lw        $s5, 0x48($sp)
/* C587C 8012F17C 3C02FD10 */  lui       $v0, 0xfd10
/* C5880 8012F180 02A21025 */  or        $v0, $s5, $v0
/* C5884 8012F184 01221025 */  or        $v0, $t1, $v0
/* C5888 8012F188 AC620000 */  sw        $v0, ($v1)
/* C588C 8012F18C 8FB60080 */  lw        $s6, 0x80($sp)
/* C5890 8012F190 AC760004 */  sw        $s6, 4($v1)
/* C5894 8012F194 97A20004 */  lhu       $v0, 4($sp)
/* C5898 8012F198 87A40000 */  lh        $a0, ($sp)
/* C589C 8012F19C 24A30008 */  addiu     $v1, $a1, 8
/* C58A0 8012F1A0 AD030000 */  sw        $v1, ($t0)
/* C58A4 8012F1A4 ACAC0004 */  sw        $t4, 4($a1)
/* C58A8 8012F1A8 ACB30008 */  sw        $s3, 8($a1)
/* C58AC 8012F1AC ACA0000C */  sw        $zero, 0xc($a1)
/* C58B0 8012F1B0 00021400 */  sll       $v0, $v0, 0x10
/* C58B4 8012F1B4 00021403 */  sra       $v0, $v0, 0x10
/* C58B8 8012F1B8 00441023 */  subu      $v0, $v0, $a0
/* C58BC 8012F1BC 00021040 */  sll       $v0, $v0, 1
/* C58C0 8012F1C0 24420009 */  addiu     $v0, $v0, 9
/* C58C4 8012F1C4 000210C3 */  sra       $v0, $v0, 3
/* C58C8 8012F1C8 304201FF */  andi      $v0, $v0, 0x1ff
/* C58CC 8012F1CC 00021240 */  sll       $v0, $v0, 9
/* C58D0 8012F1D0 00571025 */  or        $v0, $v0, $s7
/* C58D4 8012F1D4 01221025 */  or        $v0, $t1, $v0
/* C58D8 8012F1D8 ACA20000 */  sw        $v0, ($a1)
/* C58DC 8012F1DC 87A30000 */  lh        $v1, ($sp)
/* C58E0 8012F1E0 24A20010 */  addiu     $v0, $a1, 0x10
/* C58E4 8012F1E4 AD020000 */  sw        $v0, ($t0)
/* C58E8 8012F1E8 97A20002 */  lhu       $v0, 2($sp)
/* C58EC 8012F1EC 00031880 */  sll       $v1, $v1, 2
/* C58F0 8012F1F0 30630FFF */  andi      $v1, $v1, 0xfff
/* C58F4 8012F1F4 00031B00 */  sll       $v1, $v1, 0xc
/* C58F8 8012F1F8 00021080 */  sll       $v0, $v0, 2
/* C58FC 8012F1FC 30420FFC */  andi      $v0, $v0, 0xffc
/* C5900 8012F200 00521025 */  or        $v0, $v0, $s2
/* C5904 8012F204 00621825 */  or        $v1, $v1, $v0
/* C5908 8012F208 ACA30010 */  sw        $v1, 0x10($a1)
/* C590C 8012F20C 97A30004 */  lhu       $v1, 4($sp)
/* C5910 8012F210 97A40006 */  lhu       $a0, 6($sp)
/* C5914 8012F214 24A20018 */  addiu     $v0, $a1, 0x18
/* C5918 8012F218 AD020000 */  sw        $v0, ($t0)
/* C591C 8012F21C ACB00018 */  sw        $s0, 0x18($a1)
/* C5920 8012F220 ACA0001C */  sw        $zero, 0x1c($a1)
/* C5924 8012F224 00031880 */  sll       $v1, $v1, 2
/* C5928 8012F228 30630FFC */  andi      $v1, $v1, 0xffc
/* C592C 8012F22C 00031B00 */  sll       $v1, $v1, 0xc
/* C5930 8012F230 00042080 */  sll       $a0, $a0, 2
/* C5934 8012F234 30840FFC */  andi      $a0, $a0, 0xffc
/* C5938 8012F238 00912025 */  or        $a0, $a0, $s1
/* C593C 8012F23C 00641825 */  or        $v1, $v1, $a0
/* C5940 8012F240 ACA30014 */  sw        $v1, 0x14($a1)
/* C5944 8012F244 97A20004 */  lhu       $v0, 4($sp)
/* C5948 8012F248 87A40000 */  lh        $a0, ($sp)
/* C594C 8012F24C 24A30020 */  addiu     $v1, $a1, 0x20
/* C5950 8012F250 AD030000 */  sw        $v1, ($t0)
/* C5954 8012F254 ACAB0024 */  sw        $t3, 0x24($a1)
/* C5958 8012F258 00021400 */  sll       $v0, $v0, 0x10
/* C595C 8012F25C 00021403 */  sra       $v0, $v0, 0x10
/* C5960 8012F260 00441023 */  subu      $v0, $v0, $a0
/* C5964 8012F264 00021040 */  sll       $v0, $v0, 1
/* C5968 8012F268 24420009 */  addiu     $v0, $v0, 9
/* C596C 8012F26C 000210C3 */  sra       $v0, $v0, 3
/* C5970 8012F270 304201FF */  andi      $v0, $v0, 0x1ff
/* C5974 8012F274 00021240 */  sll       $v0, $v0, 9
/* C5978 8012F278 0804BCE2 */  j         .L8012F388
/* C597C 8012F27C 00571025 */   or       $v0, $v0, $s7
.L8012F280:
/* C5980 8012F280 17C2005B */  bne       $fp, $v0, .L8012F3F0
/* C5984 8012F284 3C070400 */   lui      $a3, 0x400
/* C5988 8012F288 8D050000 */  lw        $a1, ($t0)
/* C598C 8012F28C 00A0102D */  daddu     $v0, $a1, $zero
/* C5990 8012F290 24A50008 */  addiu     $a1, $a1, 8
/* C5994 8012F294 AD050000 */  sw        $a1, ($t0)
/* C5998 8012F298 8FB50040 */  lw        $s5, 0x40($sp)
/* C599C 8012F29C AC550000 */  sw        $s5, ($v0)
/* C59A0 8012F2A0 8FB60080 */  lw        $s6, 0x80($sp)
/* C59A4 8012F2A4 AC560004 */  sw        $s6, 4($v0)
/* C59A8 8012F2A8 97A20004 */  lhu       $v0, 4($sp)
/* C59AC 8012F2AC 87A40000 */  lh        $a0, ($sp)
/* C59B0 8012F2B0 24A30008 */  addiu     $v1, $a1, 8
/* C59B4 8012F2B4 AD030000 */  sw        $v1, ($t0)
/* C59B8 8012F2B8 ACAC0004 */  sw        $t4, 4($a1)
/* C59BC 8012F2BC ACB30008 */  sw        $s3, 8($a1)
/* C59C0 8012F2C0 ACA0000C */  sw        $zero, 0xc($a1)
/* C59C4 8012F2C4 00021400 */  sll       $v0, $v0, 0x10
/* C59C8 8012F2C8 00021403 */  sra       $v0, $v0, 0x10
/* C59CC 8012F2CC 00441023 */  subu      $v0, $v0, $a0
/* C59D0 8012F2D0 24420008 */  addiu     $v0, $v0, 8
/* C59D4 8012F2D4 000210C3 */  sra       $v0, $v0, 3
/* C59D8 8012F2D8 304201FF */  andi      $v0, $v0, 0x1ff
/* C59DC 8012F2DC 00021240 */  sll       $v0, $v0, 9
/* C59E0 8012F2E0 00541025 */  or        $v0, $v0, $s4
/* C59E4 8012F2E4 01221025 */  or        $v0, $t1, $v0
/* C59E8 8012F2E8 ACA20000 */  sw        $v0, ($a1)
/* C59EC 8012F2EC 87A30000 */  lh        $v1, ($sp)
/* C59F0 8012F2F0 24A20010 */  addiu     $v0, $a1, 0x10
/* C59F4 8012F2F4 AD020000 */  sw        $v0, ($t0)
/* C59F8 8012F2F8 97A20002 */  lhu       $v0, 2($sp)
/* C59FC 8012F2FC 00031880 */  sll       $v1, $v1, 2
/* C5A00 8012F300 30630FFF */  andi      $v1, $v1, 0xfff
/* C5A04 8012F304 00031B00 */  sll       $v1, $v1, 0xc
/* C5A08 8012F308 00021080 */  sll       $v0, $v0, 2
/* C5A0C 8012F30C 30420FFC */  andi      $v0, $v0, 0xffc
/* C5A10 8012F310 00521025 */  or        $v0, $v0, $s2
/* C5A14 8012F314 00621825 */  or        $v1, $v1, $v0
/* C5A18 8012F318 ACA30010 */  sw        $v1, 0x10($a1)
/* C5A1C 8012F31C 97A30004 */  lhu       $v1, 4($sp)
/* C5A20 8012F320 97A40006 */  lhu       $a0, 6($sp)
/* C5A24 8012F324 24A20018 */  addiu     $v0, $a1, 0x18
/* C5A28 8012F328 AD020000 */  sw        $v0, ($t0)
/* C5A2C 8012F32C ACB00018 */  sw        $s0, 0x18($a1)
/* C5A30 8012F330 ACA0001C */  sw        $zero, 0x1c($a1)
/* C5A34 8012F334 00031880 */  sll       $v1, $v1, 2
/* C5A38 8012F338 30630FFC */  andi      $v1, $v1, 0xffc
/* C5A3C 8012F33C 00031B00 */  sll       $v1, $v1, 0xc
/* C5A40 8012F340 00042080 */  sll       $a0, $a0, 2
/* C5A44 8012F344 30840FFC */  andi      $a0, $a0, 0xffc
/* C5A48 8012F348 00912025 */  or        $a0, $a0, $s1
/* C5A4C 8012F34C 00641825 */  or        $v1, $v1, $a0
/* C5A50 8012F350 ACA30014 */  sw        $v1, 0x14($a1)
/* C5A54 8012F354 97A20004 */  lhu       $v0, 4($sp)
/* C5A58 8012F358 87A40000 */  lh        $a0, ($sp)
/* C5A5C 8012F35C 24A30020 */  addiu     $v1, $a1, 0x20
/* C5A60 8012F360 AD030000 */  sw        $v1, ($t0)
/* C5A64 8012F364 ACAB0024 */  sw        $t3, 0x24($a1)
/* C5A68 8012F368 00021400 */  sll       $v0, $v0, 0x10
/* C5A6C 8012F36C 00021403 */  sra       $v0, $v0, 0x10
/* C5A70 8012F370 00441023 */  subu      $v0, $v0, $a0
/* C5A74 8012F374 24420008 */  addiu     $v0, $v0, 8
/* C5A78 8012F378 000210C3 */  sra       $v0, $v0, 3
/* C5A7C 8012F37C 304201FF */  andi      $v0, $v0, 0x1ff
/* C5A80 8012F380 00021240 */  sll       $v0, $v0, 9
/* C5A84 8012F384 00541025 */  or        $v0, $v0, $s4
.L8012F388:
/* C5A88 8012F388 01221025 */  or        $v0, $t1, $v0
/* C5A8C 8012F38C ACA20020 */  sw        $v0, 0x20($a1)
/* C5A90 8012F390 87A30000 */  lh        $v1, ($sp)
/* C5A94 8012F394 24A20028 */  addiu     $v0, $a1, 0x28
/* C5A98 8012F398 AD020000 */  sw        $v0, ($t0)
/* C5A9C 8012F39C 97A20002 */  lhu       $v0, 2($sp)
/* C5AA0 8012F3A0 00031880 */  sll       $v1, $v1, 2
/* C5AA4 8012F3A4 30630FFF */  andi      $v1, $v1, 0xfff
/* C5AA8 8012F3A8 00031B00 */  sll       $v1, $v1, 0xc
/* C5AAC 8012F3AC 00021080 */  sll       $v0, $v0, 2
/* C5AB0 8012F3B0 30420FFC */  andi      $v0, $v0, 0xffc
/* C5AB4 8012F3B4 00591025 */  or        $v0, $v0, $t9
/* C5AB8 8012F3B8 00621825 */  or        $v1, $v1, $v0
/* C5ABC 8012F3BC ACA30028 */  sw        $v1, 0x28($a1)
/* C5AC0 8012F3C0 97A30004 */  lhu       $v1, 4($sp)
/* C5AC4 8012F3C4 24A20030 */  addiu     $v0, $a1, 0x30
/* C5AC8 8012F3C8 AD020000 */  sw        $v0, ($t0)
/* C5ACC 8012F3CC 97A20006 */  lhu       $v0, 6($sp)
/* C5AD0 8012F3D0 00031880 */  sll       $v1, $v1, 2
/* C5AD4 8012F3D4 30630FFC */  andi      $v1, $v1, 0xffc
/* C5AD8 8012F3D8 00031B00 */  sll       $v1, $v1, 0xc
/* C5ADC 8012F3DC 00021080 */  sll       $v0, $v0, 2
/* C5AE0 8012F3E0 30420FFC */  andi      $v0, $v0, 0xffc
/* C5AE4 8012F3E4 00621825 */  or        $v1, $v1, $v0
/* C5AE8 8012F3E8 ACA3002C */  sw        $v1, 0x2c($a1)
/* C5AEC 8012F3EC 3C070400 */  lui       $a3, 0x400
.L8012F3F0:
/* C5AF0 8012F3F0 34E70400 */  ori       $a3, $a3, 0x400
/* C5AF4 8012F3F4 3C03E400 */  lui       $v1, 0xe400
/* C5AF8 8012F3F8 8D050000 */  lw        $a1, ($t0)
/* C5AFC 8012F3FC 87A4000C */  lh        $a0, 0xc($sp)
/* C5B00 8012F400 00A0302D */  daddu     $a2, $a1, $zero
/* C5B04 8012F404 24A50008 */  addiu     $a1, $a1, 8
/* C5B08 8012F408 00042080 */  sll       $a0, $a0, 2
/* C5B0C 8012F40C 30840FFF */  andi      $a0, $a0, 0xfff
/* C5B10 8012F410 AD050000 */  sw        $a1, ($t0)
/* C5B14 8012F414 87A2000E */  lh        $v0, 0xe($sp)
/* C5B18 8012F418 00042300 */  sll       $a0, $a0, 0xc
/* C5B1C 8012F41C 00021080 */  sll       $v0, $v0, 2
/* C5B20 8012F420 30420FFF */  andi      $v0, $v0, 0xfff
/* C5B24 8012F424 00431025 */  or        $v0, $v0, $v1
/* C5B28 8012F428 00822025 */  or        $a0, $a0, $v0
/* C5B2C 8012F42C 24A20008 */  addiu     $v0, $a1, 8
/* C5B30 8012F430 ACC40000 */  sw        $a0, ($a2)
/* C5B34 8012F434 AD020000 */  sw        $v0, ($t0)
/* C5B38 8012F438 87A30008 */  lh        $v1, 8($sp)
/* C5B3C 8012F43C 24A20010 */  addiu     $v0, $a1, 0x10
/* C5B40 8012F440 AD020000 */  sw        $v0, ($t0)
/* C5B44 8012F444 87A2000A */  lh        $v0, 0xa($sp)
/* C5B48 8012F448 00031880 */  sll       $v1, $v1, 2
/* C5B4C 8012F44C 30630FFF */  andi      $v1, $v1, 0xfff
/* C5B50 8012F450 00031B00 */  sll       $v1, $v1, 0xc
/* C5B54 8012F454 00021080 */  sll       $v0, $v0, 2
/* C5B58 8012F458 30420FFF */  andi      $v0, $v0, 0xfff
/* C5B5C 8012F45C 00621825 */  or        $v1, $v1, $v0
/* C5B60 8012F460 3C02E100 */  lui       $v0, 0xe100
/* C5B64 8012F464 ACC30004 */  sw        $v1, 4($a2)
/* C5B68 8012F468 ACA20000 */  sw        $v0, ($a1)
/* C5B6C 8012F46C 97B50056 */  lhu       $s5, 0x56($sp)
/* C5B70 8012F470 000F1D40 */  sll       $v1, $t7, 0x15
/* C5B74 8012F474 ACA7000C */  sw        $a3, 0xc($a1)
/* C5B78 8012F478 00151140 */  sll       $v0, $s5, 5
/* C5B7C 8012F47C 3042FFE0 */  andi      $v0, $v0, 0xffe0
/* C5B80 8012F480 00621825 */  or        $v1, $v1, $v0
/* C5B84 8012F484 3C02F100 */  lui       $v0, 0xf100
/* C5B88 8012F488 ACA20008 */  sw        $v0, 8($a1)
/* C5B8C 8012F48C 31A200FF */  andi      $v0, $t5, 0xff
/* C5B90 8012F490 14400007 */  bnez      $v0, .L8012F4B0
/* C5B94 8012F494 ACA30004 */   sw       $v1, 4($a1)
/* C5B98 8012F498 97A20000 */  lhu       $v0, ($sp)
/* C5B9C 8012F49C 97A3000C */  lhu       $v1, 0xc($sp)
/* C5BA0 8012F4A0 24420040 */  addiu     $v0, $v0, 0x40
/* C5BA4 8012F4A4 A7A20000 */  sh        $v0, ($sp)
/* C5BA8 8012F4A8 0804BBCD */  j         .L8012EF34
/* C5BAC 8012F4AC A7A30008 */   sh       $v1, 8($sp)
.L8012F4B0:
/* C5BB0 8012F4B0 93A20020 */  lbu       $v0, 0x20($sp)
/* C5BB4 8012F4B4 14400007 */  bnez      $v0, .L8012F4D4
/* C5BB8 8012F4B8 24020001 */   addiu    $v0, $zero, 1
/* C5BBC 8012F4BC 97A20002 */  lhu       $v0, 2($sp)
/* C5BC0 8012F4C0 97A3000E */  lhu       $v1, 0xe($sp)
/* C5BC4 8012F4C4 24420020 */  addiu     $v0, $v0, 0x20
/* C5BC8 8012F4C8 A7A20002 */  sh        $v0, 2($sp)
/* C5BCC 8012F4CC 0804BB75 */  j         .L8012EDD4
/* C5BD0 8012F4D0 A7A3000A */   sh       $v1, 0xa($sp)
.L8012F4D4:
/* C5BD4 8012F4D4 8FBE0078 */  lw        $fp, 0x78($sp)
/* C5BD8 8012F4D8 8FB70074 */  lw        $s7, 0x74($sp)
/* C5BDC 8012F4DC 8FB60070 */  lw        $s6, 0x70($sp)
/* C5BE0 8012F4E0 8FB5006C */  lw        $s5, 0x6c($sp)
/* C5BE4 8012F4E4 8FB40068 */  lw        $s4, 0x68($sp)
/* C5BE8 8012F4E8 8FB30064 */  lw        $s3, 0x64($sp)
/* C5BEC 8012F4EC 8FB20060 */  lw        $s2, 0x60($sp)
/* C5BF0 8012F4F0 8FB1005C */  lw        $s1, 0x5c($sp)
/* C5BF4 8012F4F4 8FB00058 */  lw        $s0, 0x58($sp)
/* C5BF8 8012F4F8 03E00008 */  jr        $ra
/* C5BFC 8012F4FC 27BD0080 */   addiu    $sp, $sp, 0x80
