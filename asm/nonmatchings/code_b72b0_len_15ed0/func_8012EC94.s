.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8012EC94
/* 0C5394 8012EC94 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0C5398 8012EC98 AFA7008C */  sw    $a3, 0x8c($sp)
/* 0C539C 8012EC9C 8FA70094 */  lw    $a3, 0x94($sp)
/* 0C53A0 8012ECA0 AFA60088 */  sw    $a2, 0x88($sp)
/* 0C53A4 8012ECA4 8FA60098 */  lw    $a2, 0x98($sp)
/* 0C53A8 8012ECA8 8FAC009C */  lw    $t4, 0x9c($sp)
/* 0C53AC 8012ECAC 8FA900A0 */  lw    $t1, 0xa0($sp)
/* 0C53B0 8012ECB0 8FAB00A4 */  lw    $t3, 0xa4($sp)
/* 0C53B4 8012ECB4 8FA800A8 */  lw    $t0, 0xa8($sp)
/* 0C53B8 8012ECB8 AFBE0078 */  sw    $fp, 0x78($sp)
/* 0C53BC 8012ECBC 8FBE0090 */  lw    $fp, 0x90($sp)
/* 0C53C0 8012ECC0 AFB70074 */  sw    $s7, 0x74($sp)
/* 0C53C4 8012ECC4 AFB60070 */  sw    $s6, 0x70($sp)
/* 0C53C8 8012ECC8 AFB5006C */  sw    $s5, 0x6c($sp)
/* 0C53CC 8012ECCC AFB40068 */  sw    $s4, 0x68($sp)
/* 0C53D0 8012ECD0 AFB30064 */  sw    $s3, 0x64($sp)
/* 0C53D4 8012ECD4 AFB20060 */  sw    $s2, 0x60($sp)
/* 0C53D8 8012ECD8 AFB1005C */  sw    $s1, 0x5c($sp)
/* 0C53DC 8012ECDC AFB00058 */  sw    $s0, 0x58($sp)
/* 0C53E0 8012ECE0 AFA40080 */  sw    $a0, 0x80($sp)
/* 0C53E4 8012ECE4 AFA50084 */  sw    $a1, 0x84($sp)
/* 0C53E8 8012ECE8 00E0C02D */  daddu $t8, $a3, $zero
/* 0C53EC 8012ECEC 00071C00 */  sll   $v1, $a3, 0x10
/* 0C53F0 8012ECF0 00031C03 */  sra   $v1, $v1, 0x10
/* 0C53F4 8012ECF4 A7AC0018 */  sh    $t4, 0x18($sp)
/* 0C53F8 8012ECF8 3185FFFF */  andi  $a1, $t4, 0xffff
/* 0C53FC 8012ECFC A7AB001C */  sh    $t3, 0x1c($sp)
/* 0C5400 8012ED00 3162FFFF */  andi  $v0, $t3, 0xffff
/* 0C5404 8012ED04 00A21021 */  addu  $v0, $a1, $v0
/* 0C5408 8012ED08 0062182A */  slt   $v1, $v1, $v0
/* 0C540C 8012ED0C A7A60016 */  sh    $a2, 0x16($sp)
/* 0C5410 8012ED10 A7A9001A */  sh    $t1, 0x1a($sp)
/* 0C5414 8012ED14 10600017 */  beqz  $v1, .L8012ED74
/* 0C5418 8012ED18 A7A8001E */   sh    $t0, 0x1e($sp)
/* 0C541C 8012ED1C 00061C00 */  sll   $v1, $a2, 0x10
/* 0C5420 8012ED20 00031C03 */  sra   $v1, $v1, 0x10
/* 0C5424 8012ED24 3124FFFF */  andi  $a0, $t1, 0xffff
/* 0C5428 8012ED28 3102FFFF */  andi  $v0, $t0, 0xffff
/* 0C542C 8012ED2C 00821021 */  addu  $v0, $a0, $v0
/* 0C5430 8012ED30 0062182A */  slt   $v1, $v1, $v0
/* 0C5434 8012ED34 106001E7 */  beqz  $v1, .L8012F4D4
/* 0C5438 8012ED38 0000102D */   daddu $v0, $zero, $zero
/* 0C543C 8012ED3C 8FB50084 */  lw    $s5, 0x84($sp)
/* 0C5440 8012ED40 00F51021 */  addu  $v0, $a3, $s5
/* 0C5444 8012ED44 00021400 */  sll   $v0, $v0, 0x10
/* 0C5448 8012ED48 00021403 */  sra   $v0, $v0, 0x10
/* 0C544C 8012ED4C 00A2102A */  slt   $v0, $a1, $v0
/* 0C5450 8012ED50 104001E0 */  beqz  $v0, .L8012F4D4
/* 0C5454 8012ED54 0000102D */   daddu $v0, $zero, $zero
/* 0C5458 8012ED58 8FB60088 */  lw    $s6, 0x88($sp)
/* 0C545C 8012ED5C 00D61021 */  addu  $v0, $a2, $s6
/* 0C5460 8012ED60 00021400 */  sll   $v0, $v0, 0x10
/* 0C5464 8012ED64 00021403 */  sra   $v0, $v0, 0x10
/* 0C5468 8012ED68 0082102A */  slt   $v0, $a0, $v0
/* 0C546C 8012ED6C 14400003 */  bnez  $v0, .L8012ED7C
/* 0C5470 8012ED70 0080702D */   daddu $t6, $a0, $zero
.L8012ED74:
/* 0C5474 8012ED74 0804BD35 */  j     .L8012F4D4
/* 0C5478 8012ED78 0000102D */   daddu $v0, $zero, $zero

.L8012ED7C:
/* 0C547C 8012ED7C 01284821 */  addu  $t1, $t1, $t0
/* 0C5480 8012ED80 00A0502D */  daddu $t2, $a1, $zero
/* 0C5484 8012ED84 018B6021 */  addu  $t4, $t4, $t3
/* 0C5488 8012ED88 8FB50088 */  lw    $s5, 0x88($sp)
/* 0C548C 8012ED8C 8FB60088 */  lw    $s6, 0x88($sp)
/* 0C5490 8012ED90 3C08800A */  lui   $t0, 0x800a
/* 0C5494 8012ED94 2508A66C */  addiu $t0, $t0, -0x5994
/* 0C5498 8012ED98 A3A00020 */  sb    $zero, 0x20($sp)
/* 0C549C 8012ED9C AFA90024 */  sw    $t1, 0x24($sp)
/* 0C54A0 8012EDA0 AFAC0034 */  sw    $t4, 0x34($sp)
/* 0C54A4 8012EDA4 A7A00002 */  sh    $zero, 2($sp)
/* 0C54A8 8012EDA8 A7A6000A */  sh    $a2, 0xa($sp)
/* 0C54AC 8012EDAC 26B5FFFF */  addiu $s5, $s5, -1
/* 0C54B0 8012EDB0 AFB50028 */  sw    $s5, 0x28($sp)
/* 0C54B4 8012EDB4 8FB50084 */  lw    $s5, 0x84($sp)
/* 0C54B8 8012EDB8 02C6B021 */  addu  $s6, $s6, $a2
/* 0C54BC 8012EDBC AFB6002C */  sw    $s6, 0x2c($sp)
/* 0C54C0 8012EDC0 8FB60084 */  lw    $s6, 0x84($sp)
/* 0C54C4 8012EDC4 26B5FFFF */  addiu $s5, $s5, -1
/* 0C54C8 8012EDC8 02C73821 */  addu  $a3, $s6, $a3
/* 0C54CC 8012EDCC AFB50038 */  sw    $s5, 0x38($sp)
/* 0C54D0 8012EDD0 AFA7003C */  sw    $a3, 0x3c($sp)
.L8012EDD4:
/* 0C54D4 8012EDD4 97A30002 */  lhu   $v1, 2($sp)
/* 0C54D8 8012EDD8 97A2000A */  lhu   $v0, 0xa($sp)
/* 0C54DC 8012EDDC A7A00056 */  sh    $zero, 0x56($sp)
/* 0C54E0 8012EDE0 2463001F */  addiu $v1, $v1, 0x1f
/* 0C54E4 8012EDE4 24420020 */  addiu $v0, $v0, 0x20
/* 0C54E8 8012EDE8 A7A2000E */  sh    $v0, 0xe($sp)
/* 0C54EC 8012EDEC 00021400 */  sll   $v0, $v0, 0x10
/* 0C54F0 8012EDF0 00021403 */  sra   $v0, $v0, 0x10
/* 0C54F4 8012EDF4 01C2102A */  slt   $v0, $t6, $v0
/* 0C54F8 8012EDF8 1440000E */  bnez  $v0, .L8012EE34
/* 0C54FC 8012EDFC A7A30006 */   sh    $v1, 6($sp)
.L8012EE00:
/* 0C5500 8012EE00 97A40002 */  lhu   $a0, 2($sp)
/* 0C5504 8012EE04 97A2000E */  lhu   $v0, 0xe($sp)
/* 0C5508 8012EE08 24830020 */  addiu $v1, $a0, 0x20
/* 0C550C 8012EE0C A7A2000A */  sh    $v0, 0xa($sp)
/* 0C5510 8012EE10 24420020 */  addiu $v0, $v0, 0x20
/* 0C5514 8012EE14 A7A2000E */  sh    $v0, 0xe($sp)
/* 0C5518 8012EE18 00021400 */  sll   $v0, $v0, 0x10
/* 0C551C 8012EE1C 00021403 */  sra   $v0, $v0, 0x10
/* 0C5520 8012EE20 004E102A */  slt   $v0, $v0, $t6
/* 0C5524 8012EE24 1440FFF6 */  bnez  $v0, .L8012EE00
/* 0C5528 8012EE28 A7A30002 */   sh    $v1, 2($sp)
/* 0C552C 8012EE2C 2482003F */  addiu $v0, $a0, 0x3f
/* 0C5530 8012EE30 A7A20006 */  sh    $v0, 6($sp)
.L8012EE34:
/* 0C5534 8012EE34 87A2000A */  lh    $v0, 0xa($sp)
/* 0C5538 8012EE38 004E102A */  slt   $v0, $v0, $t6
/* 0C553C 8012EE3C 1040000A */  beqz  $v0, .L8012EE68
/* 0C5540 8012EE40 00000000 */   nop   
/* 0C5544 8012EE44 97B50016 */  lhu   $s5, 0x16($sp)
/* 0C5548 8012EE48 97B6001A */  lhu   $s6, 0x1a($sp)
/* 0C554C 8012EE4C 00151400 */  sll   $v0, $s5, 0x10
/* 0C5550 8012EE50 00021403 */  sra   $v0, $v0, 0x10
/* 0C5554 8012EE54 004E1023 */  subu  $v0, $v0, $t6
/* 0C5558 8012EE58 04420001 */  bltzl $v0, .L8012EE60
/* 0C555C 8012EE5C 00021023 */   negu  $v0, $v0
.L8012EE60:
/* 0C5560 8012EE60 A7A20056 */  sh    $v0, 0x56($sp)
/* 0C5564 8012EE64 A7B6000A */  sh    $s6, 0xa($sp)
.L8012EE68:
/* 0C5568 8012EE68 97A2001E */  lhu   $v0, 0x1e($sp)
/* 0C556C 8012EE6C 87A3000E */  lh    $v1, 0xe($sp)
/* 0C5570 8012EE70 01C21021 */  addu  $v0, $t6, $v0
/* 0C5574 8012EE74 0062182A */  slt   $v1, $v1, $v0
/* 0C5578 8012EE78 14600009 */  bnez  $v1, .L8012EEA0
/* 0C557C 8012EE7C 24150001 */   addiu $s5, $zero, 1
/* 0C5580 8012EE80 8FB60024 */  lw    $s6, 0x24($sp)
/* 0C5584 8012EE84 A3B50020 */  sb    $s5, 0x20($sp)
/* 0C5588 8012EE88 97B50016 */  lhu   $s5, 0x16($sp)
/* 0C558C 8012EE8C 02D51023 */  subu  $v0, $s6, $s5
/* 0C5590 8012EE90 97B60026 */  lhu   $s6, 0x26($sp)
/* 0C5594 8012EE94 2442FFFF */  addiu $v0, $v0, -1
/* 0C5598 8012EE98 A7A20006 */  sh    $v0, 6($sp)
/* 0C559C 8012EE9C A7B6000E */  sh    $s6, 0xe($sp)
.L8012EEA0:
/* 0C55A0 8012EEA0 97A20006 */  lhu   $v0, 6($sp)
/* 0C55A4 8012EEA4 8FB50088 */  lw    $s5, 0x88($sp)
/* 0C55A8 8012EEA8 00021400 */  sll   $v0, $v0, 0x10
/* 0C55AC 8012EEAC 00021403 */  sra   $v0, $v0, 0x10
/* 0C55B0 8012EEB0 24420001 */  addiu $v0, $v0, 1
/* 0C55B4 8012EEB4 0055102B */  sltu  $v0, $v0, $s5
/* 0C55B8 8012EEB8 14400007 */  bnez  $v0, .L8012EED8
/* 0C55BC 8012EEBC 0000682D */   daddu $t5, $zero, $zero
/* 0C55C0 8012EEC0 24160001 */  addiu $s6, $zero, 1
/* 0C55C4 8012EEC4 97B5002A */  lhu   $s5, 0x2a($sp)
/* 0C55C8 8012EEC8 A3B60020 */  sb    $s6, 0x20($sp)
/* 0C55CC 8012EECC 97B6002E */  lhu   $s6, 0x2e($sp)
/* 0C55D0 8012EED0 A7B50006 */  sh    $s5, 6($sp)
/* 0C55D4 8012EED4 A7B6000E */  sh    $s6, 0xe($sp)
.L8012EED8:
/* 0C55D8 8012EED8 3C14F508 */  lui   $s4, 0xf508
/* 0C55DC 8012EEDC 3C0C0701 */  lui   $t4, 0x701
/* 0C55E0 8012EEE0 358C4060 */  ori   $t4, $t4, 0x4060
/* 0C55E4 8012EEE4 3C13E600 */  lui   $s3, 0xe600
/* 0C55E8 8012EEE8 3C12F400 */  lui   $s2, 0xf400
/* 0C55EC 8012EEEC 3C110700 */  lui   $s1, 0x700
/* 0C55F0 8012EEF0 3C10E700 */  lui   $s0, 0xe700
/* 0C55F4 8012EEF4 3C0B0001 */  lui   $t3, 1
/* 0C55F8 8012EEF8 356B4060 */  ori   $t3, $t3, 0x4060
/* 0C55FC 8012EEFC 3C19F200 */  lui   $t9, 0xf200
/* 0C5600 8012EF00 8FB5008C */  lw    $s5, 0x8c($sp)
/* 0C5604 8012EF04 8FB60038 */  lw    $s6, 0x38($sp)
/* 0C5608 8012EF08 3C17F510 */  lui   $s7, 0xf510
/* 0C560C 8012EF0C A7A00000 */  sh    $zero, ($sp)
/* 0C5610 8012EF10 A7B80008 */  sh    $t8, 8($sp)
/* 0C5614 8012EF14 32A20007 */  andi  $v0, $s5, 7
/* 0C5618 8012EF18 00024D40 */  sll   $t1, $v0, 0x15
/* 0C561C 8012EF1C 32D60FFF */  andi  $s6, $s6, 0xfff
/* 0C5620 8012EF20 3C15FD08 */  lui   $s5, 0xfd08
/* 0C5624 8012EF24 02D51025 */  or    $v0, $s6, $s5
/* 0C5628 8012EF28 01221025 */  or    $v0, $t1, $v0
/* 0C562C 8012EF2C AFB60048 */  sw    $s6, 0x48($sp)
/* 0C5630 8012EF30 AFA20040 */  sw    $v0, 0x40($sp)
.L8012EF34:
/* 0C5634 8012EF34 0000782D */  daddu $t7, $zero, $zero
/* 0C5638 8012EF38 97A30000 */  lhu   $v1, ($sp)
/* 0C563C 8012EF3C 97A20008 */  lhu   $v0, 8($sp)
/* 0C5640 8012EF40 2463003F */  addiu $v1, $v1, 0x3f
/* 0C5644 8012EF44 24420040 */  addiu $v0, $v0, 0x40
/* 0C5648 8012EF48 A7A2000C */  sh    $v0, 0xc($sp)
/* 0C564C 8012EF4C 00021400 */  sll   $v0, $v0, 0x10
/* 0C5650 8012EF50 00021403 */  sra   $v0, $v0, 0x10
/* 0C5654 8012EF54 0142102A */  slt   $v0, $t2, $v0
/* 0C5658 8012EF58 1440000E */  bnez  $v0, .L8012EF94
/* 0C565C 8012EF5C A7A30004 */   sh    $v1, 4($sp)
.L8012EF60:
/* 0C5660 8012EF60 97A40000 */  lhu   $a0, ($sp)
/* 0C5664 8012EF64 97A2000C */  lhu   $v0, 0xc($sp)
/* 0C5668 8012EF68 24830040 */  addiu $v1, $a0, 0x40
/* 0C566C 8012EF6C A7A20008 */  sh    $v0, 8($sp)
/* 0C5670 8012EF70 24420040 */  addiu $v0, $v0, 0x40
/* 0C5674 8012EF74 A7A2000C */  sh    $v0, 0xc($sp)
/* 0C5678 8012EF78 00021400 */  sll   $v0, $v0, 0x10
/* 0C567C 8012EF7C 00021403 */  sra   $v0, $v0, 0x10
/* 0C5680 8012EF80 004A102A */  slt   $v0, $v0, $t2
/* 0C5684 8012EF84 1440FFF6 */  bnez  $v0, .L8012EF60
/* 0C5688 8012EF88 A7A30000 */   sh    $v1, ($sp)
/* 0C568C 8012EF8C 2482007F */  addiu $v0, $a0, 0x7f
/* 0C5690 8012EF90 A7A20004 */  sh    $v0, 4($sp)
.L8012EF94:
/* 0C5694 8012EF94 87A20008 */  lh    $v0, 8($sp)
/* 0C5698 8012EF98 004A102A */  slt   $v0, $v0, $t2
/* 0C569C 8012EF9C 10400008 */  beqz  $v0, .L8012EFC0
/* 0C56A0 8012EFA0 00181400 */   sll   $v0, $t8, 0x10
/* 0C56A4 8012EFA4 00021403 */  sra   $v0, $v0, 0x10
/* 0C56A8 8012EFA8 004A1023 */  subu  $v0, $v0, $t2
/* 0C56AC 8012EFAC 97B60018 */  lhu   $s6, 0x18($sp)
/* 0C56B0 8012EFB0 04410002 */  bgez  $v0, .L8012EFBC
/* 0C56B4 8012EFB4 0040782D */   daddu $t7, $v0, $zero
/* 0C56B8 8012EFB8 000F7823 */  negu  $t7, $t7
.L8012EFBC:
/* 0C56BC 8012EFBC A7B60008 */  sh    $s6, 8($sp)
.L8012EFC0:
/* 0C56C0 8012EFC0 97A2001C */  lhu   $v0, 0x1c($sp)
/* 0C56C4 8012EFC4 87A3000C */  lh    $v1, 0xc($sp)
/* 0C56C8 8012EFC8 01421021 */  addu  $v0, $t2, $v0
/* 0C56CC 8012EFCC 0062182A */  slt   $v1, $v1, $v0
/* 0C56D0 8012EFD0 14600008 */  bnez  $v1, .L8012EFF4
/* 0C56D4 8012EFD4 00000000 */   nop   
/* 0C56D8 8012EFD8 240D0001 */  addiu $t5, $zero, 1
/* 0C56DC 8012EFDC 8FB50034 */  lw    $s5, 0x34($sp)
/* 0C56E0 8012EFE0 97B60036 */  lhu   $s6, 0x36($sp)
/* 0C56E4 8012EFE4 02B81023 */  subu  $v0, $s5, $t8
/* 0C56E8 8012EFE8 2442FFFF */  addiu $v0, $v0, -1
/* 0C56EC 8012EFEC A7A20004 */  sh    $v0, 4($sp)
/* 0C56F0 8012EFF0 A7B6000C */  sh    $s6, 0xc($sp)
.L8012EFF4:
/* 0C56F4 8012EFF4 97A20004 */  lhu   $v0, 4($sp)
/* 0C56F8 8012EFF8 8FB50084 */  lw    $s5, 0x84($sp)
/* 0C56FC 8012EFFC 00021400 */  sll   $v0, $v0, 0x10
/* 0C5700 8012F000 00021403 */  sra   $v0, $v0, 0x10
/* 0C5704 8012F004 24420001 */  addiu $v0, $v0, 1
/* 0C5708 8012F008 0055102B */  sltu  $v0, $v0, $s5
/* 0C570C 8012F00C 14400006 */  bnez  $v0, .L8012F028
/* 0C5710 8012F010 00000000 */   nop   
/* 0C5714 8012F014 240D0001 */  addiu $t5, $zero, 1
/* 0C5718 8012F018 97B6003A */  lhu   $s6, 0x3a($sp)
/* 0C571C 8012F01C 97B5003E */  lhu   $s5, 0x3e($sp)
/* 0C5720 8012F020 A7B60004 */  sh    $s6, 4($sp)
/* 0C5724 8012F024 A7B5000C */  sh    $s5, 0xc($sp)
.L8012F028:
/* 0C5728 8012F028 57C0004D */  bnel  $fp, $zero, .L8012F160
/* 0C572C 8012F02C 24020002 */   addiu $v0, $zero, 2
/* 0C5730 8012F030 8D050000 */  lw    $a1, ($t0)
/* 0C5734 8012F034 00A0182D */  daddu $v1, $a1, $zero
/* 0C5738 8012F038 24A50008 */  addiu $a1, $a1, 8
/* 0C573C 8012F03C AD050000 */  sw    $a1, ($t0)
/* 0C5740 8012F040 8FB60084 */  lw    $s6, 0x84($sp)
/* 0C5744 8012F044 3C15FD08 */  lui   $s5, 0xfd08
/* 0C5748 8012F048 00161042 */  srl   $v0, $s6, 1
/* 0C574C 8012F04C 2442FFFF */  addiu $v0, $v0, -1
/* 0C5750 8012F050 30420FFF */  andi  $v0, $v0, 0xfff
/* 0C5754 8012F054 00551025 */  or    $v0, $v0, $s5
/* 0C5758 8012F058 01221025 */  or    $v0, $t1, $v0
/* 0C575C 8012F05C AC620000 */  sw    $v0, ($v1)
/* 0C5760 8012F060 8FB60080 */  lw    $s6, 0x80($sp)
/* 0C5764 8012F064 AC760004 */  sw    $s6, 4($v1)
/* 0C5768 8012F068 97A20004 */  lhu   $v0, 4($sp)
/* 0C576C 8012F06C 87A40000 */  lh    $a0, ($sp)
/* 0C5770 8012F070 24A30008 */  addiu $v1, $a1, 8
/* 0C5774 8012F074 AD030000 */  sw    $v1, ($t0)
/* 0C5778 8012F078 ACAC0004 */  sw    $t4, 4($a1)
/* 0C577C 8012F07C ACB30008 */  sw    $s3, 8($a1)
/* 0C5780 8012F080 ACA0000C */  sw    $zero, 0xc($a1)
/* 0C5784 8012F084 00021400 */  sll   $v0, $v0, 0x10
/* 0C5788 8012F088 00021403 */  sra   $v0, $v0, 0x10
/* 0C578C 8012F08C 00441023 */  subu  $v0, $v0, $a0
/* 0C5790 8012F090 24420001 */  addiu $v0, $v0, 1
/* 0C5794 8012F094 00021043 */  sra   $v0, $v0, 1
/* 0C5798 8012F098 24420007 */  addiu $v0, $v0, 7
/* 0C579C 8012F09C 000210C3 */  sra   $v0, $v0, 3
/* 0C57A0 8012F0A0 304201FF */  andi  $v0, $v0, 0x1ff
/* 0C57A4 8012F0A4 00021240 */  sll   $v0, $v0, 9
/* 0C57A8 8012F0A8 00541025 */  or    $v0, $v0, $s4
/* 0C57AC 8012F0AC 01221025 */  or    $v0, $t1, $v0
/* 0C57B0 8012F0B0 ACA20000 */  sw    $v0, ($a1)
/* 0C57B4 8012F0B4 87A30000 */  lh    $v1, ($sp)
/* 0C57B8 8012F0B8 24A20010 */  addiu $v0, $a1, 0x10
/* 0C57BC 8012F0BC AD020000 */  sw    $v0, ($t0)
/* 0C57C0 8012F0C0 97A20002 */  lhu   $v0, 2($sp)
/* 0C57C4 8012F0C4 00031840 */  sll   $v1, $v1, 1
/* 0C57C8 8012F0C8 30630FFF */  andi  $v1, $v1, 0xfff
/* 0C57CC 8012F0CC 00031B00 */  sll   $v1, $v1, 0xc
/* 0C57D0 8012F0D0 00021080 */  sll   $v0, $v0, 2
/* 0C57D4 8012F0D4 30420FFC */  andi  $v0, $v0, 0xffc
/* 0C57D8 8012F0D8 00521025 */  or    $v0, $v0, $s2
/* 0C57DC 8012F0DC 00621825 */  or    $v1, $v1, $v0
/* 0C57E0 8012F0E0 ACA30010 */  sw    $v1, 0x10($a1)
/* 0C57E4 8012F0E4 97A30004 */  lhu   $v1, 4($sp)
/* 0C57E8 8012F0E8 97A40006 */  lhu   $a0, 6($sp)
/* 0C57EC 8012F0EC 24A20018 */  addiu $v0, $a1, 0x18
/* 0C57F0 8012F0F0 AD020000 */  sw    $v0, ($t0)
/* 0C57F4 8012F0F4 ACB00018 */  sw    $s0, 0x18($a1)
/* 0C57F8 8012F0F8 ACA0001C */  sw    $zero, 0x1c($a1)
/* 0C57FC 8012F0FC 00031840 */  sll   $v1, $v1, 1
/* 0C5800 8012F100 30630FFE */  andi  $v1, $v1, 0xffe
/* 0C5804 8012F104 00031B00 */  sll   $v1, $v1, 0xc
/* 0C5808 8012F108 00042080 */  sll   $a0, $a0, 2
/* 0C580C 8012F10C 30840FFC */  andi  $a0, $a0, 0xffc
/* 0C5810 8012F110 00912025 */  or    $a0, $a0, $s1
/* 0C5814 8012F114 00641825 */  or    $v1, $v1, $a0
/* 0C5818 8012F118 ACA30014 */  sw    $v1, 0x14($a1)
/* 0C581C 8012F11C 97A20004 */  lhu   $v0, 4($sp)
/* 0C5820 8012F120 87A40000 */  lh    $a0, ($sp)
/* 0C5824 8012F124 24A30020 */  addiu $v1, $a1, 0x20
/* 0C5828 8012F128 AD030000 */  sw    $v1, ($t0)
/* 0C582C 8012F12C 3C03F500 */  lui   $v1, 0xf500
/* 0C5830 8012F130 ACAB0024 */  sw    $t3, 0x24($a1)
/* 0C5834 8012F134 00021400 */  sll   $v0, $v0, 0x10
/* 0C5838 8012F138 00021403 */  sra   $v0, $v0, 0x10
/* 0C583C 8012F13C 00441023 */  subu  $v0, $v0, $a0
/* 0C5840 8012F140 24420001 */  addiu $v0, $v0, 1
/* 0C5844 8012F144 00021043 */  sra   $v0, $v0, 1
/* 0C5848 8012F148 24420007 */  addiu $v0, $v0, 7
/* 0C584C 8012F14C 000210C3 */  sra   $v0, $v0, 3
/* 0C5850 8012F150 304201FF */  andi  $v0, $v0, 0x1ff
/* 0C5854 8012F154 00021240 */  sll   $v0, $v0, 9
/* 0C5858 8012F158 0804BCE2 */  j     .L8012F388
/* 0C585C 8012F15C 00431025 */   or    $v0, $v0, $v1

.L8012F160:
/* 0C5860 8012F160 57C20047 */  bnel  $fp, $v0, .L8012F280
/* 0C5864 8012F164 24020001 */   addiu $v0, $zero, 1
/* 0C5868 8012F168 8D050000 */  lw    $a1, ($t0)
/* 0C586C 8012F16C 00A0182D */  daddu $v1, $a1, $zero
/* 0C5870 8012F170 24A50008 */  addiu $a1, $a1, 8
/* 0C5874 8012F174 AD050000 */  sw    $a1, ($t0)
/* 0C5878 8012F178 8FB50048 */  lw    $s5, 0x48($sp)
/* 0C587C 8012F17C 3C02FD10 */  lui   $v0, 0xfd10
/* 0C5880 8012F180 02A21025 */  or    $v0, $s5, $v0
/* 0C5884 8012F184 01221025 */  or    $v0, $t1, $v0
/* 0C5888 8012F188 AC620000 */  sw    $v0, ($v1)
/* 0C588C 8012F18C 8FB60080 */  lw    $s6, 0x80($sp)
/* 0C5890 8012F190 AC760004 */  sw    $s6, 4($v1)
/* 0C5894 8012F194 97A20004 */  lhu   $v0, 4($sp)
/* 0C5898 8012F198 87A40000 */  lh    $a0, ($sp)
/* 0C589C 8012F19C 24A30008 */  addiu $v1, $a1, 8
/* 0C58A0 8012F1A0 AD030000 */  sw    $v1, ($t0)
/* 0C58A4 8012F1A4 ACAC0004 */  sw    $t4, 4($a1)
/* 0C58A8 8012F1A8 ACB30008 */  sw    $s3, 8($a1)
/* 0C58AC 8012F1AC ACA0000C */  sw    $zero, 0xc($a1)
/* 0C58B0 8012F1B0 00021400 */  sll   $v0, $v0, 0x10
/* 0C58B4 8012F1B4 00021403 */  sra   $v0, $v0, 0x10
/* 0C58B8 8012F1B8 00441023 */  subu  $v0, $v0, $a0
/* 0C58BC 8012F1BC 00021040 */  sll   $v0, $v0, 1
/* 0C58C0 8012F1C0 24420009 */  addiu $v0, $v0, 9
/* 0C58C4 8012F1C4 000210C3 */  sra   $v0, $v0, 3
/* 0C58C8 8012F1C8 304201FF */  andi  $v0, $v0, 0x1ff
/* 0C58CC 8012F1CC 00021240 */  sll   $v0, $v0, 9
/* 0C58D0 8012F1D0 00571025 */  or    $v0, $v0, $s7
/* 0C58D4 8012F1D4 01221025 */  or    $v0, $t1, $v0
/* 0C58D8 8012F1D8 ACA20000 */  sw    $v0, ($a1)
/* 0C58DC 8012F1DC 87A30000 */  lh    $v1, ($sp)
/* 0C58E0 8012F1E0 24A20010 */  addiu $v0, $a1, 0x10
/* 0C58E4 8012F1E4 AD020000 */  sw    $v0, ($t0)
/* 0C58E8 8012F1E8 97A20002 */  lhu   $v0, 2($sp)
/* 0C58EC 8012F1EC 00031880 */  sll   $v1, $v1, 2
/* 0C58F0 8012F1F0 30630FFF */  andi  $v1, $v1, 0xfff
/* 0C58F4 8012F1F4 00031B00 */  sll   $v1, $v1, 0xc
/* 0C58F8 8012F1F8 00021080 */  sll   $v0, $v0, 2
/* 0C58FC 8012F1FC 30420FFC */  andi  $v0, $v0, 0xffc
/* 0C5900 8012F200 00521025 */  or    $v0, $v0, $s2
/* 0C5904 8012F204 00621825 */  or    $v1, $v1, $v0
/* 0C5908 8012F208 ACA30010 */  sw    $v1, 0x10($a1)
/* 0C590C 8012F20C 97A30004 */  lhu   $v1, 4($sp)
/* 0C5910 8012F210 97A40006 */  lhu   $a0, 6($sp)
/* 0C5914 8012F214 24A20018 */  addiu $v0, $a1, 0x18
/* 0C5918 8012F218 AD020000 */  sw    $v0, ($t0)
/* 0C591C 8012F21C ACB00018 */  sw    $s0, 0x18($a1)
/* 0C5920 8012F220 ACA0001C */  sw    $zero, 0x1c($a1)
/* 0C5924 8012F224 00031880 */  sll   $v1, $v1, 2
/* 0C5928 8012F228 30630FFC */  andi  $v1, $v1, 0xffc
/* 0C592C 8012F22C 00031B00 */  sll   $v1, $v1, 0xc
/* 0C5930 8012F230 00042080 */  sll   $a0, $a0, 2
/* 0C5934 8012F234 30840FFC */  andi  $a0, $a0, 0xffc
/* 0C5938 8012F238 00912025 */  or    $a0, $a0, $s1
/* 0C593C 8012F23C 00641825 */  or    $v1, $v1, $a0
/* 0C5940 8012F240 ACA30014 */  sw    $v1, 0x14($a1)
/* 0C5944 8012F244 97A20004 */  lhu   $v0, 4($sp)
/* 0C5948 8012F248 87A40000 */  lh    $a0, ($sp)
/* 0C594C 8012F24C 24A30020 */  addiu $v1, $a1, 0x20
/* 0C5950 8012F250 AD030000 */  sw    $v1, ($t0)
/* 0C5954 8012F254 ACAB0024 */  sw    $t3, 0x24($a1)
/* 0C5958 8012F258 00021400 */  sll   $v0, $v0, 0x10
/* 0C595C 8012F25C 00021403 */  sra   $v0, $v0, 0x10
/* 0C5960 8012F260 00441023 */  subu  $v0, $v0, $a0
/* 0C5964 8012F264 00021040 */  sll   $v0, $v0, 1
/* 0C5968 8012F268 24420009 */  addiu $v0, $v0, 9
/* 0C596C 8012F26C 000210C3 */  sra   $v0, $v0, 3
/* 0C5970 8012F270 304201FF */  andi  $v0, $v0, 0x1ff
/* 0C5974 8012F274 00021240 */  sll   $v0, $v0, 9
/* 0C5978 8012F278 0804BCE2 */  j     .L8012F388
/* 0C597C 8012F27C 00571025 */   or    $v0, $v0, $s7

.L8012F280:
/* 0C5980 8012F280 17C2005B */  bne   $fp, $v0, .L8012F3F0
/* 0C5984 8012F284 3C070400 */   lui   $a3, 0x400
/* 0C5988 8012F288 8D050000 */  lw    $a1, ($t0)
/* 0C598C 8012F28C 00A0102D */  daddu $v0, $a1, $zero
/* 0C5990 8012F290 24A50008 */  addiu $a1, $a1, 8
/* 0C5994 8012F294 AD050000 */  sw    $a1, ($t0)
/* 0C5998 8012F298 8FB50040 */  lw    $s5, 0x40($sp)
/* 0C599C 8012F29C AC550000 */  sw    $s5, ($v0)
/* 0C59A0 8012F2A0 8FB60080 */  lw    $s6, 0x80($sp)
/* 0C59A4 8012F2A4 AC560004 */  sw    $s6, 4($v0)
/* 0C59A8 8012F2A8 97A20004 */  lhu   $v0, 4($sp)
/* 0C59AC 8012F2AC 87A40000 */  lh    $a0, ($sp)
/* 0C59B0 8012F2B0 24A30008 */  addiu $v1, $a1, 8
/* 0C59B4 8012F2B4 AD030000 */  sw    $v1, ($t0)
/* 0C59B8 8012F2B8 ACAC0004 */  sw    $t4, 4($a1)
/* 0C59BC 8012F2BC ACB30008 */  sw    $s3, 8($a1)
/* 0C59C0 8012F2C0 ACA0000C */  sw    $zero, 0xc($a1)
/* 0C59C4 8012F2C4 00021400 */  sll   $v0, $v0, 0x10
/* 0C59C8 8012F2C8 00021403 */  sra   $v0, $v0, 0x10
/* 0C59CC 8012F2CC 00441023 */  subu  $v0, $v0, $a0
/* 0C59D0 8012F2D0 24420008 */  addiu $v0, $v0, 8
/* 0C59D4 8012F2D4 000210C3 */  sra   $v0, $v0, 3
/* 0C59D8 8012F2D8 304201FF */  andi  $v0, $v0, 0x1ff
/* 0C59DC 8012F2DC 00021240 */  sll   $v0, $v0, 9
/* 0C59E0 8012F2E0 00541025 */  or    $v0, $v0, $s4
/* 0C59E4 8012F2E4 01221025 */  or    $v0, $t1, $v0
/* 0C59E8 8012F2E8 ACA20000 */  sw    $v0, ($a1)
/* 0C59EC 8012F2EC 87A30000 */  lh    $v1, ($sp)
/* 0C59F0 8012F2F0 24A20010 */  addiu $v0, $a1, 0x10
/* 0C59F4 8012F2F4 AD020000 */  sw    $v0, ($t0)
/* 0C59F8 8012F2F8 97A20002 */  lhu   $v0, 2($sp)
/* 0C59FC 8012F2FC 00031880 */  sll   $v1, $v1, 2
/* 0C5A00 8012F300 30630FFF */  andi  $v1, $v1, 0xfff
/* 0C5A04 8012F304 00031B00 */  sll   $v1, $v1, 0xc
/* 0C5A08 8012F308 00021080 */  sll   $v0, $v0, 2
/* 0C5A0C 8012F30C 30420FFC */  andi  $v0, $v0, 0xffc
/* 0C5A10 8012F310 00521025 */  or    $v0, $v0, $s2
/* 0C5A14 8012F314 00621825 */  or    $v1, $v1, $v0
/* 0C5A18 8012F318 ACA30010 */  sw    $v1, 0x10($a1)
/* 0C5A1C 8012F31C 97A30004 */  lhu   $v1, 4($sp)
/* 0C5A20 8012F320 97A40006 */  lhu   $a0, 6($sp)
/* 0C5A24 8012F324 24A20018 */  addiu $v0, $a1, 0x18
/* 0C5A28 8012F328 AD020000 */  sw    $v0, ($t0)
/* 0C5A2C 8012F32C ACB00018 */  sw    $s0, 0x18($a1)
/* 0C5A30 8012F330 ACA0001C */  sw    $zero, 0x1c($a1)
/* 0C5A34 8012F334 00031880 */  sll   $v1, $v1, 2
/* 0C5A38 8012F338 30630FFC */  andi  $v1, $v1, 0xffc
/* 0C5A3C 8012F33C 00031B00 */  sll   $v1, $v1, 0xc
/* 0C5A40 8012F340 00042080 */  sll   $a0, $a0, 2
/* 0C5A44 8012F344 30840FFC */  andi  $a0, $a0, 0xffc
/* 0C5A48 8012F348 00912025 */  or    $a0, $a0, $s1
/* 0C5A4C 8012F34C 00641825 */  or    $v1, $v1, $a0
/* 0C5A50 8012F350 ACA30014 */  sw    $v1, 0x14($a1)
/* 0C5A54 8012F354 97A20004 */  lhu   $v0, 4($sp)
/* 0C5A58 8012F358 87A40000 */  lh    $a0, ($sp)
/* 0C5A5C 8012F35C 24A30020 */  addiu $v1, $a1, 0x20
/* 0C5A60 8012F360 AD030000 */  sw    $v1, ($t0)
/* 0C5A64 8012F364 ACAB0024 */  sw    $t3, 0x24($a1)
/* 0C5A68 8012F368 00021400 */  sll   $v0, $v0, 0x10
/* 0C5A6C 8012F36C 00021403 */  sra   $v0, $v0, 0x10
/* 0C5A70 8012F370 00441023 */  subu  $v0, $v0, $a0
/* 0C5A74 8012F374 24420008 */  addiu $v0, $v0, 8
/* 0C5A78 8012F378 000210C3 */  sra   $v0, $v0, 3
/* 0C5A7C 8012F37C 304201FF */  andi  $v0, $v0, 0x1ff
/* 0C5A80 8012F380 00021240 */  sll   $v0, $v0, 9
/* 0C5A84 8012F384 00541025 */  or    $v0, $v0, $s4
.L8012F388:
/* 0C5A88 8012F388 01221025 */  or    $v0, $t1, $v0
/* 0C5A8C 8012F38C ACA20020 */  sw    $v0, 0x20($a1)
/* 0C5A90 8012F390 87A30000 */  lh    $v1, ($sp)
/* 0C5A94 8012F394 24A20028 */  addiu $v0, $a1, 0x28
/* 0C5A98 8012F398 AD020000 */  sw    $v0, ($t0)
/* 0C5A9C 8012F39C 97A20002 */  lhu   $v0, 2($sp)
/* 0C5AA0 8012F3A0 00031880 */  sll   $v1, $v1, 2
/* 0C5AA4 8012F3A4 30630FFF */  andi  $v1, $v1, 0xfff
/* 0C5AA8 8012F3A8 00031B00 */  sll   $v1, $v1, 0xc
/* 0C5AAC 8012F3AC 00021080 */  sll   $v0, $v0, 2
/* 0C5AB0 8012F3B0 30420FFC */  andi  $v0, $v0, 0xffc
/* 0C5AB4 8012F3B4 00591025 */  or    $v0, $v0, $t9
/* 0C5AB8 8012F3B8 00621825 */  or    $v1, $v1, $v0
/* 0C5ABC 8012F3BC ACA30028 */  sw    $v1, 0x28($a1)
/* 0C5AC0 8012F3C0 97A30004 */  lhu   $v1, 4($sp)
/* 0C5AC4 8012F3C4 24A20030 */  addiu $v0, $a1, 0x30
/* 0C5AC8 8012F3C8 AD020000 */  sw    $v0, ($t0)
/* 0C5ACC 8012F3CC 97A20006 */  lhu   $v0, 6($sp)
/* 0C5AD0 8012F3D0 00031880 */  sll   $v1, $v1, 2
/* 0C5AD4 8012F3D4 30630FFC */  andi  $v1, $v1, 0xffc
/* 0C5AD8 8012F3D8 00031B00 */  sll   $v1, $v1, 0xc
/* 0C5ADC 8012F3DC 00021080 */  sll   $v0, $v0, 2
/* 0C5AE0 8012F3E0 30420FFC */  andi  $v0, $v0, 0xffc
/* 0C5AE4 8012F3E4 00621825 */  or    $v1, $v1, $v0
/* 0C5AE8 8012F3E8 ACA3002C */  sw    $v1, 0x2c($a1)
/* 0C5AEC 8012F3EC 3C070400 */  lui   $a3, 0x400
.L8012F3F0:
/* 0C5AF0 8012F3F0 34E70400 */  ori   $a3, $a3, 0x400
/* 0C5AF4 8012F3F4 3C03E400 */  lui   $v1, 0xe400
/* 0C5AF8 8012F3F8 8D050000 */  lw    $a1, ($t0)
/* 0C5AFC 8012F3FC 87A4000C */  lh    $a0, 0xc($sp)
/* 0C5B00 8012F400 00A0302D */  daddu $a2, $a1, $zero
/* 0C5B04 8012F404 24A50008 */  addiu $a1, $a1, 8
/* 0C5B08 8012F408 00042080 */  sll   $a0, $a0, 2
/* 0C5B0C 8012F40C 30840FFF */  andi  $a0, $a0, 0xfff
/* 0C5B10 8012F410 AD050000 */  sw    $a1, ($t0)
/* 0C5B14 8012F414 87A2000E */  lh    $v0, 0xe($sp)
/* 0C5B18 8012F418 00042300 */  sll   $a0, $a0, 0xc
/* 0C5B1C 8012F41C 00021080 */  sll   $v0, $v0, 2
/* 0C5B20 8012F420 30420FFF */  andi  $v0, $v0, 0xfff
/* 0C5B24 8012F424 00431025 */  or    $v0, $v0, $v1
/* 0C5B28 8012F428 00822025 */  or    $a0, $a0, $v0
/* 0C5B2C 8012F42C 24A20008 */  addiu $v0, $a1, 8
/* 0C5B30 8012F430 ACC40000 */  sw    $a0, ($a2)
/* 0C5B34 8012F434 AD020000 */  sw    $v0, ($t0)
/* 0C5B38 8012F438 87A30008 */  lh    $v1, 8($sp)
/* 0C5B3C 8012F43C 24A20010 */  addiu $v0, $a1, 0x10
/* 0C5B40 8012F440 AD020000 */  sw    $v0, ($t0)
/* 0C5B44 8012F444 87A2000A */  lh    $v0, 0xa($sp)
/* 0C5B48 8012F448 00031880 */  sll   $v1, $v1, 2
/* 0C5B4C 8012F44C 30630FFF */  andi  $v1, $v1, 0xfff
/* 0C5B50 8012F450 00031B00 */  sll   $v1, $v1, 0xc
/* 0C5B54 8012F454 00021080 */  sll   $v0, $v0, 2
/* 0C5B58 8012F458 30420FFF */  andi  $v0, $v0, 0xfff
/* 0C5B5C 8012F45C 00621825 */  or    $v1, $v1, $v0
/* 0C5B60 8012F460 3C02E100 */  lui   $v0, 0xe100
/* 0C5B64 8012F464 ACC30004 */  sw    $v1, 4($a2)
/* 0C5B68 8012F468 ACA20000 */  sw    $v0, ($a1)
/* 0C5B6C 8012F46C 97B50056 */  lhu   $s5, 0x56($sp)
/* 0C5B70 8012F470 000F1D40 */  sll   $v1, $t7, 0x15
/* 0C5B74 8012F474 ACA7000C */  sw    $a3, 0xc($a1)
/* 0C5B78 8012F478 00151140 */  sll   $v0, $s5, 5
/* 0C5B7C 8012F47C 3042FFE0 */  andi  $v0, $v0, 0xffe0
/* 0C5B80 8012F480 00621825 */  or    $v1, $v1, $v0
/* 0C5B84 8012F484 3C02F100 */  lui   $v0, 0xf100
/* 0C5B88 8012F488 ACA20008 */  sw    $v0, 8($a1)
/* 0C5B8C 8012F48C 31A200FF */  andi  $v0, $t5, 0xff
/* 0C5B90 8012F490 14400007 */  bnez  $v0, .L8012F4B0
/* 0C5B94 8012F494 ACA30004 */   sw    $v1, 4($a1)
/* 0C5B98 8012F498 97A20000 */  lhu   $v0, ($sp)
/* 0C5B9C 8012F49C 97A3000C */  lhu   $v1, 0xc($sp)
/* 0C5BA0 8012F4A0 24420040 */  addiu $v0, $v0, 0x40
/* 0C5BA4 8012F4A4 A7A20000 */  sh    $v0, ($sp)
/* 0C5BA8 8012F4A8 0804BBCD */  j     .L8012EF34
/* 0C5BAC 8012F4AC A7A30008 */   sh    $v1, 8($sp)

.L8012F4B0:
/* 0C5BB0 8012F4B0 93A20020 */  lbu   $v0, 0x20($sp)
/* 0C5BB4 8012F4B4 14400007 */  bnez  $v0, .L8012F4D4
/* 0C5BB8 8012F4B8 24020001 */   addiu $v0, $zero, 1
/* 0C5BBC 8012F4BC 97A20002 */  lhu   $v0, 2($sp)
/* 0C5BC0 8012F4C0 97A3000E */  lhu   $v1, 0xe($sp)
/* 0C5BC4 8012F4C4 24420020 */  addiu $v0, $v0, 0x20
/* 0C5BC8 8012F4C8 A7A20002 */  sh    $v0, 2($sp)
/* 0C5BCC 8012F4CC 0804BB75 */  j     .L8012EDD4
/* 0C5BD0 8012F4D0 A7A3000A */   sh    $v1, 0xa($sp)

.L8012F4D4:
/* 0C5BD4 8012F4D4 8FBE0078 */  lw    $fp, 0x78($sp)
/* 0C5BD8 8012F4D8 8FB70074 */  lw    $s7, 0x74($sp)
/* 0C5BDC 8012F4DC 8FB60070 */  lw    $s6, 0x70($sp)
/* 0C5BE0 8012F4E0 8FB5006C */  lw    $s5, 0x6c($sp)
/* 0C5BE4 8012F4E4 8FB40068 */  lw    $s4, 0x68($sp)
/* 0C5BE8 8012F4E8 8FB30064 */  lw    $s3, 0x64($sp)
/* 0C5BEC 8012F4EC 8FB20060 */  lw    $s2, 0x60($sp)
/* 0C5BF0 8012F4F0 8FB1005C */  lw    $s1, 0x5c($sp)
/* 0C5BF4 8012F4F4 8FB00058 */  lw    $s0, 0x58($sp)
/* 0C5BF8 8012F4F8 03E00008 */  jr    $ra
/* 0C5BFC 8012F4FC 27BD0080 */   addiu $sp, $sp, 0x80

/* 0C5C00 8012F500 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0C5C04 8012F504 C7A800A4 */  lwc1  $f8, 0xa4($sp)
/* 0C5C08 8012F508 3C018015 */  lui   $at, 0x8015
/* 0C5C0C 8012F50C D4220A40 */  ldc1  $f2, 0xa40($at)
/* 0C5C10 8012F510 8FA2008C */  lw    $v0, 0x8c($sp)
/* 0C5C14 8012F514 AFA40078 */  sw    $a0, 0x78($sp)
/* 0C5C18 8012F518 8FA40090 */  lw    $a0, 0x90($sp)
/* 0C5C1C 8012F51C C7AA00A8 */  lwc1  $f10, 0xa8($sp)
/* 0C5C20 8012F520 AFB5005C */  sw    $s5, 0x5c($sp)
/* 0C5C24 8012F524 93B5008B */  lbu   $s5, 0x8b($sp)
/* 0C5C28 8012F528 97A30096 */  lhu   $v1, 0x96($sp)
/* 0C5C2C 8012F52C 97A8009A */  lhu   $t0, 0x9a($sp)
/* 0C5C30 8012F530 A3A70027 */  sb    $a3, 0x27($sp)
/* 0C5C34 8012F534 97A700A2 */  lhu   $a3, 0xa2($sp)
/* 0C5C38 8012F538 AFB30054 */  sw    $s3, 0x54($sp)
/* 0C5C3C 8012F53C 00A0982D */  daddu $s3, $a1, $zero
/* 0C5C40 8012F540 AFBE0068 */  sw    $fp, 0x68($sp)
/* 0C5C44 8012F544 AFB70064 */  sw    $s7, 0x64($sp)
/* 0C5C48 8012F548 AFB60060 */  sw    $s6, 0x60($sp)
/* 0C5C4C 8012F54C AFB40058 */  sw    $s4, 0x58($sp)
/* 0C5C50 8012F550 AFB20050 */  sw    $s2, 0x50($sp)
/* 0C5C54 8012F554 AFB1004C */  sw    $s1, 0x4c($sp)
/* 0C5C58 8012F558 AFB00048 */  sw    $s0, 0x48($sp)
/* 0C5C5C 8012F55C F7B40070 */  sdc1  $f20, 0x70($sp)
/* 0C5C60 8012F560 AFA60080 */  sw    $a2, 0x80($sp)
/* 0C5C64 8012F564 46004021 */  cvt.d.s $f0, $f8
/* 0C5C68 8012F568 A3B50028 */  sb    $s5, 0x28($sp)
/* 0C5C6C 8012F56C 97B5009E */  lhu   $s5, 0x9e($sp)
/* 0C5C70 8012F570 4622003C */  c.lt.d $f0, $f2
/* 0C5C74 8012F574 00000000 */  nop   
/* 0C5C78 8012F578 45010046 */  bc1t  .L8012F694
/* 0C5C7C 8012F57C A7B50036 */   sh    $s5, 0x36($sp)
/* 0C5C80 8012F580 460051A1 */  cvt.d.s $f6, $f10
/* 0C5C84 8012F584 4622303C */  c.lt.d $f6, $f2
/* 0C5C88 8012F588 00000000 */  nop   
/* 0C5C8C 8012F58C 45030214 */  bc1tl .L8012FDE0
/* 0C5C90 8012F590 0000102D */   daddu $v0, $zero, $zero
/* 0C5C94 8012F594 00021400 */  sll   $v0, $v0, 0x10
/* 0C5C98 8012F598 00022C03 */  sra   $a1, $v0, 0x10
/* 0C5C9C 8012F59C 97B50036 */  lhu   $s5, 0x36($sp)
/* 0C5CA0 8012F5A0 3066FFFF */  andi  $a2, $v1, 0xffff
/* 0C5CA4 8012F5A4 02A61021 */  addu  $v0, $s5, $a2
/* 0C5CA8 8012F5A8 00A2102A */  slt   $v0, $a1, $v0
/* 0C5CAC 8012F5AC 10400039 */  beqz  $v0, .L8012F694
/* 0C5CB0 8012F5B0 00041400 */   sll   $v0, $a0, 0x10
/* 0C5CB4 8012F5B4 00022403 */  sra   $a0, $v0, 0x10
/* 0C5CB8 8012F5B8 3103FFFF */  andi  $v1, $t0, 0xffff
/* 0C5CBC 8012F5BC 00E33821 */  addu  $a3, $a3, $v1
/* 0C5CC0 8012F5C0 0087102A */  slt   $v0, $a0, $a3
/* 0C5CC4 8012F5C4 10400206 */  beqz  $v0, .L8012FDE0
/* 0C5CC8 8012F5C8 0000102D */   daddu $v0, $zero, $zero
/* 0C5CCC 8012F5CC 44931000 */  mtc1  $s3, $f2
/* 0C5CD0 8012F5D0 00000000 */  nop   
/* 0C5CD4 8012F5D4 468010A1 */  cvt.d.w $f2, $f2
/* 0C5CD8 8012F5D8 44852000 */  mtc1  $a1, $f4
/* 0C5CDC 8012F5DC 00000000 */  nop   
/* 0C5CE0 8012F5E0 46802120 */  cvt.s.w $f4, $f4
/* 0C5CE4 8012F5E4 06630007 */  bgezl $s3, .L8012F604
/* 0C5CE8 8012F5E8 46201020 */   cvt.s.d $f0, $f2
/* 0C5CEC 8012F5EC 3C0141F0 */  lui   $at, 0x41f0
/* 0C5CF0 8012F5F0 44810800 */  mtc1  $at, $f1
/* 0C5CF4 8012F5F4 44800000 */  mtc1  $zero, $f0
/* 0C5CF8 8012F5F8 00000000 */  nop   
/* 0C5CFC 8012F5FC 46201080 */  add.d $f2, $f2, $f0
/* 0C5D00 8012F600 46201020 */  cvt.s.d $f0, $f2
.L8012F604:
/* 0C5D04 8012F604 46080002 */  mul.s $f0, $f0, $f8
/* 0C5D08 8012F608 00000000 */  nop   
/* 0C5D0C 8012F60C 46002000 */  add.s $f0, $f4, $f0
/* 0C5D10 8012F610 4600050D */  trunc.w.s $f20, $f0
/* 0C5D14 8012F614 4402A000 */  mfc1  $v0, $f20
/* 0C5D18 8012F618 00000000 */  nop   
/* 0C5D1C 8012F61C 00021400 */  sll   $v0, $v0, 0x10
/* 0C5D20 8012F620 00021403 */  sra   $v0, $v0, 0x10
/* 0C5D24 8012F624 00C2102A */  slt   $v0, $a2, $v0
/* 0C5D28 8012F628 104001ED */  beqz  $v0, .L8012FDE0
/* 0C5D2C 8012F62C 0000102D */   daddu $v0, $zero, $zero
/* 0C5D30 8012F630 C7A20080 */  lwc1  $f2, 0x80($sp)
/* 0C5D34 8012F634 468010A1 */  cvt.d.w $f2, $f2
/* 0C5D38 8012F638 8FB50080 */  lw    $s5, 0x80($sp)
/* 0C5D3C 8012F63C 44842000 */  mtc1  $a0, $f4
/* 0C5D40 8012F640 00000000 */  nop   
/* 0C5D44 8012F644 46802120 */  cvt.s.w $f4, $f4
/* 0C5D48 8012F648 06A30007 */  bgezl $s5, .L8012F668
/* 0C5D4C 8012F64C 46201020 */   cvt.s.d $f0, $f2
/* 0C5D50 8012F650 3C0141F0 */  lui   $at, 0x41f0
/* 0C5D54 8012F654 44810800 */  mtc1  $at, $f1
/* 0C5D58 8012F658 44800000 */  mtc1  $zero, $f0
/* 0C5D5C 8012F65C 00000000 */  nop   
/* 0C5D60 8012F660 46201080 */  add.d $f2, $f2, $f0
/* 0C5D64 8012F664 46201020 */  cvt.s.d $f0, $f2
.L8012F668:
/* 0C5D68 8012F668 460A0002 */  mul.s $f0, $f0, $f10
/* 0C5D6C 8012F66C 00000000 */  nop   
/* 0C5D70 8012F670 46002000 */  add.s $f0, $f4, $f0
/* 0C5D74 8012F674 4600050D */  trunc.w.s $f20, $f0
/* 0C5D78 8012F678 4402A000 */  mfc1  $v0, $f20
/* 0C5D7C 8012F67C 00000000 */  nop   
/* 0C5D80 8012F680 00021400 */  sll   $v0, $v0, 0x10
/* 0C5D84 8012F684 00021403 */  sra   $v0, $v0, 0x10
/* 0C5D88 8012F688 0062102A */  slt   $v0, $v1, $v0
/* 0C5D8C 8012F68C 14400003 */  bnez  $v0, .L8012F69C
/* 0C5D90 8012F690 0000C82D */   daddu $t9, $zero, $zero
.L8012F694:
/* 0C5D94 8012F694 0804BF78 */  j     .L8012FDE0
/* 0C5D98 8012F698 0000102D */   daddu $v0, $zero, $zero

.L8012F69C:
/* 0C5D9C 8012F69C 0060702D */  daddu $t6, $v1, $zero
/* 0C5DA0 8012F6A0 0080B82D */  daddu $s7, $a0, $zero
/* 0C5DA4 8012F6A4 02EE1023 */  subu  $v0, $s7, $t6
/* 0C5DA8 8012F6A8 04420001 */  bltzl $v0, .L8012F6B0
/* 0C5DAC 8012F6AC 00021023 */   negu  $v0, $v0
.L8012F6B0:
/* 0C5DB0 8012F6B0 3C014040 */  lui   $at, 0x4040
/* 0C5DB4 8012F6B4 44812800 */  mtc1  $at, $f5
/* 0C5DB8 8012F6B8 44802000 */  mtc1  $zero, $f4
/* 0C5DBC 8012F6BC 00E0A02D */  daddu $s4, $a3, $zero
/* 0C5DC0 8012F6C0 46243102 */  mul.d $f4, $f6, $f4
/* 0C5DC4 8012F6C4 00000000 */  nop   
/* 0C5DC8 8012F6C8 00A0802D */  daddu $s0, $a1, $zero
/* 0C5DCC 8012F6CC 3C014200 */  lui   $at, 0x4200
/* 0C5DD0 8012F6D0 44817000 */  mtc1  $at, $f14
/* 0C5DD4 8012F6D4 3C013F80 */  lui   $at, 0x3f80
/* 0C5DD8 8012F6D8 44811000 */  mtc1  $at, $f2
/* 0C5DDC 8012F6DC 3C014050 */  lui   $at, 0x4050
/* 0C5DE0 8012F6E0 44819800 */  mtc1  $at, $f19
/* 0C5DE4 8012F6E4 44809000 */  mtc1  $zero, $f18
/* 0C5DE8 8012F6E8 3C018015 */  lui   $at, 0x8015
/* 0C5DEC 8012F6EC D42C0A48 */  ldc1  $f12, 0xa48($at)
/* 0C5DF0 8012F6F0 3C014480 */  lui   $at, 0x4480
/* 0C5DF4 8012F6F4 44813000 */  mtc1  $at, $f6
/* 0C5DF8 8012F6F8 46081003 */  div.s $f0, $f2, $f8
/* 0C5DFC 8012F6FC 46060002 */  mul.s $f0, $f0, $f6
/* 0C5E00 8012F700 00000000 */  nop   
/* 0C5E04 8012F704 3C014280 */  lui   $at, 0x4280
/* 0C5E08 8012F708 44818000 */  mtc1  $at, $f16
/* 0C5E0C 8012F70C 00C0502D */  daddu $t2, $a2, $zero
/* 0C5E10 8012F710 AFA2003C */  sw    $v0, 0x3c($sp)
/* 0C5E14 8012F714 460A1083 */  div.s $f2, $f2, $f10
/* 0C5E18 8012F718 46061082 */  mul.s $f2, $f2, $f6
/* 0C5E1C 8012F71C 00000000 */  nop   
/* 0C5E20 8012F720 AFA00004 */  sw    $zero, 4($sp)
/* 0C5E24 8012F724 AFB70014 */  sw    $s7, 0x14($sp)
/* 0C5E28 8012F728 4600050D */  trunc.w.s $f20, $f0
/* 0C5E2C 8012F72C E7B40038 */  swc1  $f20, 0x38($sp)
/* 0C5E30 8012F730 3C013FE0 */  lui   $at, 0x3fe0
/* 0C5E34 8012F734 44810800 */  mtc1  $at, $f1
/* 0C5E38 8012F738 44800000 */  mtc1  $zero, $f0
/* 0C5E3C 8012F73C 4600150D */  trunc.w.s $f20, $f2
/* 0C5E40 8012F740 441EA000 */  mfc1  $fp, $f20
/* 0C5E44 8012F744 46202100 */  add.d $f4, $f4, $f0
.L8012F748:
/* 0C5E48 8012F748 C7A00014 */  lwc1  $f0, 0x14($sp)
/* 0C5E4C 8012F74C 46800021 */  cvt.d.w $f0, $f0
/* 0C5E50 8012F750 8FA20004 */  lw    $v0, 4($sp)
/* 0C5E54 8012F754 46240000 */  add.d $f0, $f0, $f4
/* 0C5E58 8012F758 2442001F */  addiu $v0, $v0, 0x1f
/* 0C5E5C 8012F75C AFA2000C */  sw    $v0, 0xc($sp)
/* 0C5E60 8012F760 4620050D */  trunc.w.d $f20, $f0
/* 0C5E64 8012F764 4402A000 */  mfc1  $v0, $f20
/* 0C5E68 8012F768 00000000 */  nop   
/* 0C5E6C 8012F76C AFA2001C */  sw    $v0, 0x1c($sp)
/* 0C5E70 8012F770 01C2102A */  slt   $v0, $t6, $v0
/* 0C5E74 8012F774 14400014 */  bnez  $v0, .L8012F7C8
/* 0C5E78 8012F778 0000902D */   daddu $s2, $zero, $zero
/* 0C5E7C 8012F77C 460E5082 */  mul.s $f2, $f10, $f14
/* 0C5E80 8012F780 00000000 */  nop   
.L8012F784:
/* 0C5E84 8012F784 8FA40004 */  lw    $a0, 4($sp)
/* 0C5E88 8012F788 8FA2001C */  lw    $v0, 0x1c($sp)
/* 0C5E8C 8012F78C 24830020 */  addiu $v1, $a0, 0x20
/* 0C5E90 8012F790 44820000 */  mtc1  $v0, $f0
/* 0C5E94 8012F794 00000000 */  nop   
/* 0C5E98 8012F798 46800020 */  cvt.s.w $f0, $f0
/* 0C5E9C 8012F79C 46020000 */  add.s $f0, $f0, $f2
/* 0C5EA0 8012F7A0 AFA30004 */  sw    $v1, 4($sp)
/* 0C5EA4 8012F7A4 AFA20014 */  sw    $v0, 0x14($sp)
/* 0C5EA8 8012F7A8 4600050D */  trunc.w.s $f20, $f0
/* 0C5EAC 8012F7AC 4402A000 */  mfc1  $v0, $f20
/* 0C5EB0 8012F7B0 00000000 */  nop   
/* 0C5EB4 8012F7B4 AFA2001C */  sw    $v0, 0x1c($sp)
/* 0C5EB8 8012F7B8 004E102A */  slt   $v0, $v0, $t6
/* 0C5EBC 8012F7BC 1440FFF1 */  bnez  $v0, .L8012F784
/* 0C5EC0 8012F7C0 2482003F */   addiu $v0, $a0, 0x3f
/* 0C5EC4 8012F7C4 AFA2000C */  sw    $v0, 0xc($sp)
.L8012F7C8:
/* 0C5EC8 8012F7C8 8FA20014 */  lw    $v0, 0x14($sp)
/* 0C5ECC 8012F7CC 004E102A */  slt   $v0, $v0, $t6
/* 0C5ED0 8012F7D0 10400009 */  beqz  $v0, .L8012F7F8
/* 0C5ED4 8012F7D4 00000000 */   nop   
/* 0C5ED8 8012F7D8 C7A0003C */  lwc1  $f0, 0x3c($sp)
/* 0C5EDC 8012F7DC 46800020 */  cvt.s.w $f0, $f0
/* 0C5EE0 8012F7E0 460A0003 */  div.s $f0, $f0, $f10
/* 0C5EE4 8012F7E4 460E0002 */  mul.s $f0, $f0, $f14
/* 0C5EE8 8012F7E8 00000000 */  nop   
/* 0C5EEC 8012F7EC AFAE0014 */  sw    $t6, 0x14($sp)
/* 0C5EF0 8012F7F0 4600050D */  trunc.w.s $f20, $f0
/* 0C5EF4 8012F7F4 4412A000 */  mfc1  $s2, $f20
.L8012F7F8:
/* 0C5EF8 8012F7F8 8FA2000C */  lw    $v0, 0xc($sp)
/* 0C5EFC 8012F7FC 8FB50080 */  lw    $s5, 0x80($sp)
/* 0C5F00 8012F800 24420001 */  addiu $v0, $v0, 1
/* 0C5F04 8012F804 0055102B */  sltu  $v0, $v0, $s5
/* 0C5F08 8012F808 14400014 */  bnez  $v0, .L8012F85C
/* 0C5F0C 8012F80C 26A3FFFF */   addiu $v1, $s5, -1
/* 0C5F10 8012F810 44830000 */  mtc1  $v1, $f0
/* 0C5F14 8012F814 00000000 */  nop   
/* 0C5F18 8012F818 46800020 */  cvt.s.w $f0, $f0
/* 0C5F1C 8012F81C 460A0002 */  mul.s $f0, $f0, $f10
/* 0C5F20 8012F820 00000000 */  nop   
/* 0C5F24 8012F824 4600050D */  trunc.w.s $f20, $f0
/* 0C5F28 8012F828 4402A000 */  mfc1  $v0, $f20
/* 0C5F2C 8012F82C 00000000 */  nop   
/* 0C5F30 8012F830 00021400 */  sll   $v0, $v0, 0x10
/* 0C5F34 8012F834 00021403 */  sra   $v0, $v0, 0x10
/* 0C5F38 8012F838 02E21021 */  addu  $v0, $s7, $v0
/* 0C5F3C 8012F83C 44820000 */  mtc1  $v0, $f0
/* 0C5F40 8012F840 00000000 */  nop   
/* 0C5F44 8012F844 46800020 */  cvt.s.w $f0, $f0
/* 0C5F48 8012F848 460A0000 */  add.s $f0, $f0, $f10
/* 0C5F4C 8012F84C AFA3000C */  sw    $v1, 0xc($sp)
/* 0C5F50 8012F850 24190001 */  addiu $t9, $zero, 1
/* 0C5F54 8012F854 4600050D */  trunc.w.s $f20, $f0
/* 0C5F58 8012F858 E7B4001C */  swc1  $f20, 0x1c($sp)
.L8012F85C:
/* 0C5F5C 8012F85C 8FA2001C */  lw    $v0, 0x1c($sp)
/* 0C5F60 8012F860 0282102A */  slt   $v0, $s4, $v0
/* 0C5F64 8012F864 10400004 */  beqz  $v0, .L8012F878
/* 0C5F68 8012F868 332200FF */   andi  $v0, $t9, 0xff
/* 0C5F6C 8012F86C 14400002 */  bnez  $v0, .L8012F878
/* 0C5F70 8012F870 AFB4001C */   sw    $s4, 0x1c($sp)
/* 0C5F74 8012F874 24190001 */  addiu $t9, $zero, 1
.L8012F878:
/* 0C5F78 8012F878 0000582D */  daddu $t3, $zero, $zero
/* 0C5F7C 8012F87C 020A1023 */  subu  $v0, $s0, $t2
/* 0C5F80 8012F880 04410002 */  bgez  $v0, .L8012F88C
/* 0C5F84 8012F884 0040B02D */   daddu $s6, $v0, $zero
/* 0C5F88 8012F888 0016B023 */  negu  $s6, $s6
.L8012F88C:
/* 0C5F8C 8012F88C 3C08800A */  lui   $t0, 0x800a
/* 0C5F90 8012F890 2508A66C */  addiu $t0, $t0, -0x5994
/* 0C5F94 8012F894 46004021 */  cvt.d.s $f0, $f8
/* 0C5F98 8012F898 266CFFFF */  addiu $t4, $s3, -1
/* 0C5F9C 8012F89C 3C11F510 */  lui   $s1, 0xf510
/* 0C5FA0 8012F8A0 97A20036 */  lhu   $v0, 0x36($sp)
/* 0C5FA4 8012F8A4 93AF0028 */  lbu   $t7, 0x28($sp)
/* 0C5FA8 8012F8A8 93B50027 */  lbu   $s5, 0x27($sp)
/* 0C5FAC 8012F8AC 46320002 */  mul.d $f0, $f0, $f18
/* 0C5FB0 8012F8B0 00000000 */  nop   
/* 0C5FB4 8012F8B4 AFA00000 */  sw    $zero, ($sp)
/* 0C5FB8 8012F8B8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0C5FBC 8012F8BC 0142C021 */  addu  $t8, $t2, $v0
/* 0C5FC0 8012F8C0 32A20007 */  andi  $v0, $s5, 7
/* 0C5FC4 8012F8C4 00024D40 */  sll   $t1, $v0, 0x15
/* 0C5FC8 8012F8C8 31950FFF */  andi  $s5, $t4, 0xfff
/* 0C5FCC 8012F8CC AFB50040 */  sw    $s5, 0x40($sp)
/* 0C5FD0 8012F8D0 462C0180 */  add.d $f6, $f0, $f12
.L8012F8D4:
/* 0C5FD4 8012F8D4 C7A00010 */  lwc1  $f0, 0x10($sp)
/* 0C5FD8 8012F8D8 46800021 */  cvt.d.w $f0, $f0
/* 0C5FDC 8012F8DC 8FA20000 */  lw    $v0, ($sp)
/* 0C5FE0 8012F8E0 46260000 */  add.d $f0, $f0, $f6
/* 0C5FE4 8012F8E4 2442003F */  addiu $v0, $v0, 0x3f
/* 0C5FE8 8012F8E8 AFA20008 */  sw    $v0, 8($sp)
/* 0C5FEC 8012F8EC 4620050D */  trunc.w.d $f20, $f0
/* 0C5FF0 8012F8F0 4402A000 */  mfc1  $v0, $f20
/* 0C5FF4 8012F8F4 00000000 */  nop   
/* 0C5FF8 8012F8F8 AFA20018 */  sw    $v0, 0x18($sp)
/* 0C5FFC 8012F8FC 0142102A */  slt   $v0, $t2, $v0
/* 0C6000 8012F900 14400014 */  bnez  $v0, .L8012F954
/* 0C6004 8012F904 0000682D */   daddu $t5, $zero, $zero
/* 0C6008 8012F908 46104082 */  mul.s $f2, $f8, $f16
/* 0C600C 8012F90C 00000000 */  nop   
.L8012F910:
/* 0C6010 8012F910 8FA40000 */  lw    $a0, ($sp)
/* 0C6014 8012F914 8FA30018 */  lw    $v1, 0x18($sp)
/* 0C6018 8012F918 24820040 */  addiu $v0, $a0, 0x40
/* 0C601C 8012F91C 44830000 */  mtc1  $v1, $f0
/* 0C6020 8012F920 00000000 */  nop   
/* 0C6024 8012F924 46800020 */  cvt.s.w $f0, $f0
/* 0C6028 8012F928 46020000 */  add.s $f0, $f0, $f2
/* 0C602C 8012F92C AFA20000 */  sw    $v0, ($sp)
/* 0C6030 8012F930 AFA30010 */  sw    $v1, 0x10($sp)
/* 0C6034 8012F934 4600050D */  trunc.w.s $f20, $f0
/* 0C6038 8012F938 4402A000 */  mfc1  $v0, $f20
/* 0C603C 8012F93C 00000000 */  nop   
/* 0C6040 8012F940 AFA20018 */  sw    $v0, 0x18($sp)
/* 0C6044 8012F944 004A102A */  slt   $v0, $v0, $t2
/* 0C6048 8012F948 1440FFF1 */  bnez  $v0, .L8012F910
/* 0C604C 8012F94C 2482007F */   addiu $v0, $a0, 0x7f
/* 0C6050 8012F950 AFA20008 */  sw    $v0, 8($sp)
.L8012F954:
/* 0C6054 8012F954 8FA20010 */  lw    $v0, 0x10($sp)
/* 0C6058 8012F958 004A102A */  slt   $v0, $v0, $t2
/* 0C605C 8012F95C 1040000A */  beqz  $v0, .L8012F988
/* 0C6060 8012F960 00000000 */   nop   
/* 0C6064 8012F964 44960000 */  mtc1  $s6, $f0
/* 0C6068 8012F968 00000000 */  nop   
/* 0C606C 8012F96C 46800020 */  cvt.s.w $f0, $f0
/* 0C6070 8012F970 46080003 */  div.s $f0, $f0, $f8
/* 0C6074 8012F974 460E0002 */  mul.s $f0, $f0, $f14
/* 0C6078 8012F978 00000000 */  nop   
/* 0C607C 8012F97C AFAA0010 */  sw    $t2, 0x10($sp)
/* 0C6080 8012F980 4600050D */  trunc.w.s $f20, $f0
/* 0C6084 8012F984 440DA000 */  mfc1  $t5, $f20
.L8012F988:
/* 0C6088 8012F988 8FA20008 */  lw    $v0, 8($sp)
/* 0C608C 8012F98C 24420001 */  addiu $v0, $v0, 1
/* 0C6090 8012F990 0053102B */  sltu  $v0, $v0, $s3
/* 0C6094 8012F994 14400016 */  bnez  $v0, .L8012F9F0
/* 0C6098 8012F998 00000000 */   nop   
/* 0C609C 8012F99C 448C0000 */  mtc1  $t4, $f0
/* 0C60A0 8012F9A0 00000000 */  nop   
/* 0C60A4 8012F9A4 46800020 */  cvt.s.w $f0, $f0
/* 0C60A8 8012F9A8 46080002 */  mul.s $f0, $f0, $f8
/* 0C60AC 8012F9AC 00000000 */  nop   
/* 0C60B0 8012F9B0 4600050D */  trunc.w.s $f20, $f0
/* 0C60B4 8012F9B4 4402A000 */  mfc1  $v0, $f20
/* 0C60B8 8012F9B8 00000000 */  nop   
/* 0C60BC 8012F9BC 00021400 */  sll   $v0, $v0, 0x10
/* 0C60C0 8012F9C0 00021403 */  sra   $v0, $v0, 0x10
/* 0C60C4 8012F9C4 02021021 */  addu  $v0, $s0, $v0
/* 0C60C8 8012F9C8 44820000 */  mtc1  $v0, $f0
/* 0C60CC 8012F9CC 00000000 */  nop   
/* 0C60D0 8012F9D0 46800020 */  cvt.s.w $f0, $f0
/* 0C60D4 8012F9D4 46080000 */  add.s $f0, $f0, $f8
/* 0C60D8 8012F9D8 46000021 */  cvt.d.s $f0, $f0
/* 0C60DC 8012F9DC 462C0000 */  add.d $f0, $f0, $f12
/* 0C60E0 8012F9E0 AFAC0008 */  sw    $t4, 8($sp)
/* 0C60E4 8012F9E4 240B0001 */  addiu $t3, $zero, 1
/* 0C60E8 8012F9E8 4620050D */  trunc.w.d $f20, $f0
/* 0C60EC 8012F9EC E7B40018 */  swc1  $f20, 0x18($sp)
.L8012F9F0:
/* 0C60F0 8012F9F0 8FA20018 */  lw    $v0, 0x18($sp)
/* 0C60F4 8012F9F4 0302102A */  slt   $v0, $t8, $v0
/* 0C60F8 8012F9F8 10400003 */  beqz  $v0, .L8012FA08
/* 0C60FC 8012F9FC 24020002 */   addiu $v0, $zero, 2
/* 0C6100 8012FA00 AFB80018 */  sw    $t8, 0x18($sp)
/* 0C6104 8012FA04 240B0001 */  addiu $t3, $zero, 1
.L8012FA08:
/* 0C6108 8012FA08 15E2004F */  bne   $t7, $v0, .L8012FB48
/* 0C610C 8012FA0C 3C060701 */   lui   $a2, 0x701
/* 0C6110 8012FA10 34C64060 */  ori   $a2, $a2, 0x4060
/* 0C6114 8012FA14 8D050000 */  lw    $a1, ($t0)
/* 0C6118 8012FA18 3C070001 */  lui   $a3, 1
/* 0C611C 8012FA1C 00A0182D */  daddu $v1, $a1, $zero
/* 0C6120 8012FA20 24A50008 */  addiu $a1, $a1, 8
/* 0C6124 8012FA24 AD050000 */  sw    $a1, ($t0)
/* 0C6128 8012FA28 8FB50040 */  lw    $s5, 0x40($sp)
/* 0C612C 8012FA2C 3C02FD10 */  lui   $v0, 0xfd10
/* 0C6130 8012FA30 02A21025 */  or    $v0, $s5, $v0
/* 0C6134 8012FA34 01221025 */  or    $v0, $t1, $v0
/* 0C6138 8012FA38 AC620000 */  sw    $v0, ($v1)
/* 0C613C 8012FA3C 8FB50078 */  lw    $s5, 0x78($sp)
/* 0C6140 8012FA40 34E74060 */  ori   $a3, $a3, 0x4060
/* 0C6144 8012FA44 AC750004 */  sw    $s5, 4($v1)
/* 0C6148 8012FA48 8FA20008 */  lw    $v0, 8($sp)
/* 0C614C 8012FA4C 8FA40000 */  lw    $a0, ($sp)
/* 0C6150 8012FA50 24A30008 */  addiu $v1, $a1, 8
/* 0C6154 8012FA54 AD030000 */  sw    $v1, ($t0)
/* 0C6158 8012FA58 24A30010 */  addiu $v1, $a1, 0x10
/* 0C615C 8012FA5C ACA60004 */  sw    $a2, 4($a1)
/* 0C6160 8012FA60 AD030000 */  sw    $v1, ($t0)
/* 0C6164 8012FA64 3C03E600 */  lui   $v1, 0xe600
/* 0C6168 8012FA68 ACA30008 */  sw    $v1, 8($a1)
/* 0C616C 8012FA6C 3C03F400 */  lui   $v1, 0xf400
/* 0C6170 8012FA70 ACA0000C */  sw    $zero, 0xc($a1)
/* 0C6174 8012FA74 00441023 */  subu  $v0, $v0, $a0
/* 0C6178 8012FA78 00021040 */  sll   $v0, $v0, 1
/* 0C617C 8012FA7C 24420009 */  addiu $v0, $v0, 9
/* 0C6180 8012FA80 000210C3 */  sra   $v0, $v0, 3
/* 0C6184 8012FA84 304201FF */  andi  $v0, $v0, 0x1ff
/* 0C6188 8012FA88 00021240 */  sll   $v0, $v0, 9
/* 0C618C 8012FA8C 00511025 */  or    $v0, $v0, $s1
/* 0C6190 8012FA90 01221025 */  or    $v0, $t1, $v0
/* 0C6194 8012FA94 ACA20000 */  sw    $v0, ($a1)
/* 0C6198 8012FA98 8FA40000 */  lw    $a0, ($sp)
/* 0C619C 8012FA9C 24A20018 */  addiu $v0, $a1, 0x18
/* 0C61A0 8012FAA0 AD020000 */  sw    $v0, ($t0)
/* 0C61A4 8012FAA4 8FA20004 */  lw    $v0, 4($sp)
/* 0C61A8 8012FAA8 00042080 */  sll   $a0, $a0, 2
/* 0C61AC 8012FAAC 30840FFF */  andi  $a0, $a0, 0xfff
/* 0C61B0 8012FAB0 00042300 */  sll   $a0, $a0, 0xc
/* 0C61B4 8012FAB4 00021080 */  sll   $v0, $v0, 2
/* 0C61B8 8012FAB8 30420FFF */  andi  $v0, $v0, 0xfff
/* 0C61BC 8012FABC 00431025 */  or    $v0, $v0, $v1
/* 0C61C0 8012FAC0 00822025 */  or    $a0, $a0, $v0
/* 0C61C4 8012FAC4 ACA40010 */  sw    $a0, 0x10($a1)
/* 0C61C8 8012FAC8 8FA30008 */  lw    $v1, 8($sp)
/* 0C61CC 8012FACC 8FA4000C */  lw    $a0, 0xc($sp)
/* 0C61D0 8012FAD0 3C02E700 */  lui   $v0, 0xe700
/* 0C61D4 8012FAD4 ACA20018 */  sw    $v0, 0x18($a1)
/* 0C61D8 8012FAD8 3C020700 */  lui   $v0, 0x700
/* 0C61DC 8012FADC ACA0001C */  sw    $zero, 0x1c($a1)
/* 0C61E0 8012FAE0 00031880 */  sll   $v1, $v1, 2
/* 0C61E4 8012FAE4 30630FFF */  andi  $v1, $v1, 0xfff
/* 0C61E8 8012FAE8 00031B00 */  sll   $v1, $v1, 0xc
/* 0C61EC 8012FAEC 00042080 */  sll   $a0, $a0, 2
/* 0C61F0 8012FAF0 30840FFF */  andi  $a0, $a0, 0xfff
/* 0C61F4 8012FAF4 00822025 */  or    $a0, $a0, $v0
/* 0C61F8 8012FAF8 00641825 */  or    $v1, $v1, $a0
/* 0C61FC 8012FAFC ACA30014 */  sw    $v1, 0x14($a1)
/* 0C6200 8012FB00 8FA20008 */  lw    $v0, 8($sp)
/* 0C6204 8012FB04 8FA40000 */  lw    $a0, ($sp)
/* 0C6208 8012FB08 24A30020 */  addiu $v1, $a1, 0x20
/* 0C620C 8012FB0C AD030000 */  sw    $v1, ($t0)
/* 0C6210 8012FB10 3C03F200 */  lui   $v1, 0xf200
/* 0C6214 8012FB14 ACA70024 */  sw    $a3, 0x24($a1)
/* 0C6218 8012FB18 00441023 */  subu  $v0, $v0, $a0
/* 0C621C 8012FB1C 00021040 */  sll   $v0, $v0, 1
/* 0C6220 8012FB20 24420009 */  addiu $v0, $v0, 9
/* 0C6224 8012FB24 000210C3 */  sra   $v0, $v0, 3
/* 0C6228 8012FB28 304201FF */  andi  $v0, $v0, 0x1ff
/* 0C622C 8012FB2C 00021240 */  sll   $v0, $v0, 9
/* 0C6230 8012FB30 00511025 */  or    $v0, $v0, $s1
/* 0C6234 8012FB34 01221025 */  or    $v0, $t1, $v0
/* 0C6238 8012FB38 ACA20020 */  sw    $v0, 0x20($a1)
/* 0C623C 8012FB3C 8FA40000 */  lw    $a0, ($sp)
/* 0C6240 8012FB40 0804BF28 */  j     .L8012FCA0
/* 0C6244 8012FB44 24A20028 */   addiu $v0, $a1, 0x28

.L8012FB48:
/* 0C6248 8012FB48 15E0006B */  bnez  $t7, .L8012FCF8
/* 0C624C 8012FB4C 316700FF */   andi  $a3, $t3, 0xff
/* 0C6250 8012FB50 3C060701 */  lui   $a2, 0x701
/* 0C6254 8012FB54 34C64060 */  ori   $a2, $a2, 0x4060
/* 0C6258 8012FB58 3C070001 */  lui   $a3, 1
/* 0C625C 8012FB5C 00131042 */  srl   $v0, $s3, 1
/* 0C6260 8012FB60 2442FFFF */  addiu $v0, $v0, -1
/* 0C6264 8012FB64 30420FFF */  andi  $v0, $v0, 0xfff
/* 0C6268 8012FB68 3C03FD08 */  lui   $v1, 0xfd08
/* 0C626C 8012FB6C 00431025 */  or    $v0, $v0, $v1
/* 0C6270 8012FB70 8D050000 */  lw    $a1, ($t0)
/* 0C6274 8012FB74 01221025 */  or    $v0, $t1, $v0
/* 0C6278 8012FB78 00A0202D */  daddu $a0, $a1, $zero
/* 0C627C 8012FB7C 24A50008 */  addiu $a1, $a1, 8
/* 0C6280 8012FB80 AD050000 */  sw    $a1, ($t0)
/* 0C6284 8012FB84 AC820000 */  sw    $v0, ($a0)
/* 0C6288 8012FB88 8FB50078 */  lw    $s5, 0x78($sp)
/* 0C628C 8012FB8C 34E74060 */  ori   $a3, $a3, 0x4060
/* 0C6290 8012FB90 AC950004 */  sw    $s5, 4($a0)
/* 0C6294 8012FB94 8FA20008 */  lw    $v0, 8($sp)
/* 0C6298 8012FB98 8FA40000 */  lw    $a0, ($sp)
/* 0C629C 8012FB9C 24A30008 */  addiu $v1, $a1, 8
/* 0C62A0 8012FBA0 AD030000 */  sw    $v1, ($t0)
/* 0C62A4 8012FBA4 24A30010 */  addiu $v1, $a1, 0x10
/* 0C62A8 8012FBA8 ACA60004 */  sw    $a2, 4($a1)
/* 0C62AC 8012FBAC AD030000 */  sw    $v1, ($t0)
/* 0C62B0 8012FBB0 3C03E600 */  lui   $v1, 0xe600
/* 0C62B4 8012FBB4 ACA30008 */  sw    $v1, 8($a1)
/* 0C62B8 8012FBB8 3C03F508 */  lui   $v1, 0xf508
/* 0C62BC 8012FBBC ACA0000C */  sw    $zero, 0xc($a1)
/* 0C62C0 8012FBC0 00441023 */  subu  $v0, $v0, $a0
/* 0C62C4 8012FBC4 24420001 */  addiu $v0, $v0, 1
/* 0C62C8 8012FBC8 00021043 */  sra   $v0, $v0, 1
/* 0C62CC 8012FBCC 24420007 */  addiu $v0, $v0, 7
/* 0C62D0 8012FBD0 000210C3 */  sra   $v0, $v0, 3
/* 0C62D4 8012FBD4 304201FF */  andi  $v0, $v0, 0x1ff
/* 0C62D8 8012FBD8 00021240 */  sll   $v0, $v0, 9
/* 0C62DC 8012FBDC 00431025 */  or    $v0, $v0, $v1
/* 0C62E0 8012FBE0 01221025 */  or    $v0, $t1, $v0
/* 0C62E4 8012FBE4 ACA20000 */  sw    $v0, ($a1)
/* 0C62E8 8012FBE8 24A20018 */  addiu $v0, $a1, 0x18
/* 0C62EC 8012FBEC 8FA40000 */  lw    $a0, ($sp)
/* 0C62F0 8012FBF0 3C03F400 */  lui   $v1, 0xf400
/* 0C62F4 8012FBF4 AD020000 */  sw    $v0, ($t0)
/* 0C62F8 8012FBF8 8FA20004 */  lw    $v0, 4($sp)
/* 0C62FC 8012FBFC 00042040 */  sll   $a0, $a0, 1
/* 0C6300 8012FC00 30840FFF */  andi  $a0, $a0, 0xfff
/* 0C6304 8012FC04 00042300 */  sll   $a0, $a0, 0xc
/* 0C6308 8012FC08 00021080 */  sll   $v0, $v0, 2
/* 0C630C 8012FC0C 30420FFF */  andi  $v0, $v0, 0xfff
/* 0C6310 8012FC10 00431025 */  or    $v0, $v0, $v1
/* 0C6314 8012FC14 00822025 */  or    $a0, $a0, $v0
/* 0C6318 8012FC18 ACA40010 */  sw    $a0, 0x10($a1)
/* 0C631C 8012FC1C 8FA30008 */  lw    $v1, 8($sp)
/* 0C6320 8012FC20 8FA4000C */  lw    $a0, 0xc($sp)
/* 0C6324 8012FC24 3C02E700 */  lui   $v0, 0xe700
/* 0C6328 8012FC28 ACA20018 */  sw    $v0, 0x18($a1)
/* 0C632C 8012FC2C 3C020700 */  lui   $v0, 0x700
/* 0C6330 8012FC30 ACA0001C */  sw    $zero, 0x1c($a1)
/* 0C6334 8012FC34 00031840 */  sll   $v1, $v1, 1
/* 0C6338 8012FC38 30630FFF */  andi  $v1, $v1, 0xfff
/* 0C633C 8012FC3C 00031B00 */  sll   $v1, $v1, 0xc
/* 0C6340 8012FC40 00042080 */  sll   $a0, $a0, 2
/* 0C6344 8012FC44 30840FFF */  andi  $a0, $a0, 0xfff
/* 0C6348 8012FC48 00822025 */  or    $a0, $a0, $v0
/* 0C634C 8012FC4C 00641825 */  or    $v1, $v1, $a0
/* 0C6350 8012FC50 ACA30014 */  sw    $v1, 0x14($a1)
/* 0C6354 8012FC54 8FA20008 */  lw    $v0, 8($sp)
/* 0C6358 8012FC58 8FA40000 */  lw    $a0, ($sp)
/* 0C635C 8012FC5C 24A30020 */  addiu $v1, $a1, 0x20
/* 0C6360 8012FC60 AD030000 */  sw    $v1, ($t0)
/* 0C6364 8012FC64 3C03F500 */  lui   $v1, 0xf500
/* 0C6368 8012FC68 ACA70024 */  sw    $a3, 0x24($a1)
/* 0C636C 8012FC6C 00441023 */  subu  $v0, $v0, $a0
/* 0C6370 8012FC70 24420001 */  addiu $v0, $v0, 1
/* 0C6374 8012FC74 00021043 */  sra   $v0, $v0, 1
/* 0C6378 8012FC78 24420007 */  addiu $v0, $v0, 7
/* 0C637C 8012FC7C 000210C3 */  sra   $v0, $v0, 3
/* 0C6380 8012FC80 304201FF */  andi  $v0, $v0, 0x1ff
/* 0C6384 8012FC84 00021240 */  sll   $v0, $v0, 9
/* 0C6388 8012FC88 00431025 */  or    $v0, $v0, $v1
/* 0C638C 8012FC8C 01221025 */  or    $v0, $t1, $v0
/* 0C6390 8012FC90 ACA20020 */  sw    $v0, 0x20($a1)
/* 0C6394 8012FC94 24A20028 */  addiu $v0, $a1, 0x28
/* 0C6398 8012FC98 8FA40000 */  lw    $a0, ($sp)
/* 0C639C 8012FC9C 3C03F200 */  lui   $v1, 0xf200
.L8012FCA0:
/* 0C63A0 8012FCA0 AD020000 */  sw    $v0, ($t0)
/* 0C63A4 8012FCA4 8FA20004 */  lw    $v0, 4($sp)
/* 0C63A8 8012FCA8 00042080 */  sll   $a0, $a0, 2
/* 0C63AC 8012FCAC 30840FFF */  andi  $a0, $a0, 0xfff
/* 0C63B0 8012FCB0 00042300 */  sll   $a0, $a0, 0xc
/* 0C63B4 8012FCB4 00021080 */  sll   $v0, $v0, 2
/* 0C63B8 8012FCB8 30420FFF */  andi  $v0, $v0, 0xfff
/* 0C63BC 8012FCBC 00431025 */  or    $v0, $v0, $v1
/* 0C63C0 8012FCC0 00822025 */  or    $a0, $a0, $v0
/* 0C63C4 8012FCC4 ACA40028 */  sw    $a0, 0x28($a1)
/* 0C63C8 8012FCC8 8FA30008 */  lw    $v1, 8($sp)
/* 0C63CC 8012FCCC 24A20030 */  addiu $v0, $a1, 0x30
/* 0C63D0 8012FCD0 AD020000 */  sw    $v0, ($t0)
/* 0C63D4 8012FCD4 8FA2000C */  lw    $v0, 0xc($sp)
/* 0C63D8 8012FCD8 00031880 */  sll   $v1, $v1, 2
/* 0C63DC 8012FCDC 30630FFF */  andi  $v1, $v1, 0xfff
/* 0C63E0 8012FCE0 00031B00 */  sll   $v1, $v1, 0xc
/* 0C63E4 8012FCE4 00021080 */  sll   $v0, $v0, 2
/* 0C63E8 8012FCE8 30420FFF */  andi  $v0, $v0, 0xfff
/* 0C63EC 8012FCEC 00621825 */  or    $v1, $v1, $v0
/* 0C63F0 8012FCF0 ACA3002C */  sw    $v1, 0x2c($a1)
/* 0C63F4 8012FCF4 316700FF */  andi  $a3, $t3, 0xff
.L8012FCF8:
/* 0C63F8 8012FCF8 8D050000 */  lw    $a1, ($t0)
/* 0C63FC 8012FCFC 3C04E400 */  lui   $a0, 0xe400
/* 0C6400 8012FD00 00A0302D */  daddu $a2, $a1, $zero
/* 0C6404 8012FD04 24A50008 */  addiu $a1, $a1, 8
/* 0C6408 8012FD08 AD050000 */  sw    $a1, ($t0)
/* 0C640C 8012FD0C 8FA30018 */  lw    $v1, 0x18($sp)
/* 0C6410 8012FD10 8FA2001C */  lw    $v0, 0x1c($sp)
/* 0C6414 8012FD14 00671823 */  subu  $v1, $v1, $a3
/* 0C6418 8012FD18 00031880 */  sll   $v1, $v1, 2
/* 0C641C 8012FD1C 30630FFF */  andi  $v1, $v1, 0xfff
/* 0C6420 8012FD20 00031B00 */  sll   $v1, $v1, 0xc
/* 0C6424 8012FD24 00021080 */  sll   $v0, $v0, 2
/* 0C6428 8012FD28 30420FFF */  andi  $v0, $v0, 0xfff
/* 0C642C 8012FD2C 00441025 */  or    $v0, $v0, $a0
/* 0C6430 8012FD30 00621825 */  or    $v1, $v1, $v0
/* 0C6434 8012FD34 24A20008 */  addiu $v0, $a1, 8
/* 0C6438 8012FD38 ACC30000 */  sw    $v1, ($a2)
/* 0C643C 8012FD3C AD020000 */  sw    $v0, ($t0)
/* 0C6440 8012FD40 8FA30010 */  lw    $v1, 0x10($sp)
/* 0C6444 8012FD44 24A20010 */  addiu $v0, $a1, 0x10
/* 0C6448 8012FD48 AD020000 */  sw    $v0, ($t0)
/* 0C644C 8012FD4C 8FA20014 */  lw    $v0, 0x14($sp)
/* 0C6450 8012FD50 00031880 */  sll   $v1, $v1, 2
/* 0C6454 8012FD54 30630FFF */  andi  $v1, $v1, 0xfff
/* 0C6458 8012FD58 00031B00 */  sll   $v1, $v1, 0xc
/* 0C645C 8012FD5C 00021080 */  sll   $v0, $v0, 2
/* 0C6460 8012FD60 30420FFF */  andi  $v0, $v0, 0xfff
/* 0C6464 8012FD64 00621825 */  or    $v1, $v1, $v0
/* 0C6468 8012FD68 3C02E100 */  lui   $v0, 0xe100
/* 0C646C 8012FD6C ACC30004 */  sw    $v1, 4($a2)
/* 0C6470 8012FD70 ACA20000 */  sw    $v0, ($a1)
/* 0C6474 8012FD74 000D1400 */  sll   $v0, $t5, 0x10
/* 0C6478 8012FD78 3243FFFF */  andi  $v1, $s2, 0xffff
/* 0C647C 8012FD7C 00431025 */  or    $v0, $v0, $v1
/* 0C6480 8012FD80 ACA20004 */  sw    $v0, 4($a1)
/* 0C6484 8012FD84 3C02F100 */  lui   $v0, 0xf100
/* 0C6488 8012FD88 ACA20008 */  sw    $v0, 8($a1)
/* 0C648C 8012FD8C 8FB50038 */  lw    $s5, 0x38($sp)
/* 0C6490 8012FD90 33C3FFFF */  andi  $v1, $fp, 0xffff
/* 0C6494 8012FD94 00151400 */  sll   $v0, $s5, 0x10
/* 0C6498 8012FD98 00431025 */  or    $v0, $v0, $v1
/* 0C649C 8012FD9C 14E00007 */  bnez  $a3, .L8012FDBC
/* 0C64A0 8012FDA0 ACA2000C */   sw    $v0, 0xc($a1)
/* 0C64A4 8012FDA4 8FA20000 */  lw    $v0, ($sp)
/* 0C64A8 8012FDA8 8FA30018 */  lw    $v1, 0x18($sp)
/* 0C64AC 8012FDAC 24420040 */  addiu $v0, $v0, 0x40
/* 0C64B0 8012FDB0 AFA20000 */  sw    $v0, ($sp)
/* 0C64B4 8012FDB4 0804BE35 */  j     .L8012F8D4
/* 0C64B8 8012FDB8 AFA30010 */   sw    $v1, 0x10($sp)

.L8012FDBC:
/* 0C64BC 8012FDBC 332200FF */  andi  $v0, $t9, 0xff
/* 0C64C0 8012FDC0 14400007 */  bnez  $v0, .L8012FDE0
/* 0C64C4 8012FDC4 24020001 */   addiu $v0, $zero, 1
/* 0C64C8 8012FDC8 8FA20004 */  lw    $v0, 4($sp)
/* 0C64CC 8012FDCC 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0C64D0 8012FDD0 24420020 */  addiu $v0, $v0, 0x20
/* 0C64D4 8012FDD4 AFA20004 */  sw    $v0, 4($sp)
/* 0C64D8 8012FDD8 0804BDD2 */  j     .L8012F748
/* 0C64DC 8012FDDC AFA30014 */   sw    $v1, 0x14($sp)

.L8012FDE0:
/* 0C64E0 8012FDE0 8FBE0068 */  lw    $fp, 0x68($sp)
/* 0C64E4 8012FDE4 8FB70064 */  lw    $s7, 0x64($sp)
/* 0C64E8 8012FDE8 8FB60060 */  lw    $s6, 0x60($sp)
/* 0C64EC 8012FDEC 8FB5005C */  lw    $s5, 0x5c($sp)
/* 0C64F0 8012FDF0 8FB40058 */  lw    $s4, 0x58($sp)
/* 0C64F4 8012FDF4 8FB30054 */  lw    $s3, 0x54($sp)
/* 0C64F8 8012FDF8 8FB20050 */  lw    $s2, 0x50($sp)
/* 0C64FC 8012FDFC 8FB1004C */  lw    $s1, 0x4c($sp)
/* 0C6500 8012FE00 8FB00048 */  lw    $s0, 0x48($sp)
/* 0C6504 8012FE04 D7B40070 */  ldc1  $f20, 0x70($sp)
/* 0C6508 8012FE08 03E00008 */  jr    $ra
/* 0C650C 8012FE0C 27BD0078 */   addiu $sp, $sp, 0x78

