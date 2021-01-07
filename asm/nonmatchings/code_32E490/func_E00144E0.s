.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00144E0
/* 32E970 E00144E0 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* 32E974 E00144E4 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 32E978 E00144E8 0080B02D */  daddu     $s6, $a0, $zero
/* 32E97C E00144EC 3C05DB06 */  lui       $a1, 0xdb06
/* 32E980 E00144F0 34A50024 */  ori       $a1, $a1, 0x24
/* 32E984 E00144F4 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 32E988 E00144F8 0000902D */  daddu     $s2, $zero, $zero
/* 32E98C E00144FC 3C06800A */  lui       $a2, %hi(D_8009A66C)
/* 32E990 E0014500 24C6A66C */  addiu     $a2, $a2, %lo(D_8009A66C)
/* 32E994 E0014504 3C02E700 */  lui       $v0, 0xe700
/* 32E998 E0014508 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 32E99C E001450C AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 32E9A0 E0014510 AFB700BC */  sw        $s7, 0xbc($sp)
/* 32E9A4 E0014514 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 32E9A8 E0014518 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 32E9AC E001451C AFB300AC */  sw        $s3, 0xac($sp)
/* 32E9B0 E0014520 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 32E9B4 E0014524 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 32E9B8 E0014528 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 32E9BC E001452C 8CC30000 */  lw        $v1, ($a2)
/* 32E9C0 E0014530 8ED1000C */  lw        $s1, 0xc($s6)
/* 32E9C4 E0014534 0060202D */  daddu     $a0, $v1, $zero
/* 32E9C8 E0014538 24630008 */  addiu     $v1, $v1, 8
/* 32E9CC E001453C ACC30000 */  sw        $v1, ($a2)
/* 32E9D0 E0014540 AC820000 */  sw        $v0, ($a0)
/* 32E9D4 E0014544 AC800004 */  sw        $zero, 4($a0)
/* 32E9D8 E0014548 AC650000 */  sw        $a1, ($v1)
/* 32E9DC E001454C 8EC40010 */  lw        $a0, 0x10($s6)
/* 32E9E0 E0014550 24620008 */  addiu     $v0, $v1, 8
/* 32E9E4 E0014554 ACC20000 */  sw        $v0, ($a2)
/* 32E9E8 E0014558 8C84001C */  lw        $a0, 0x1c($a0)
/* 32E9EC E001455C 3C02DE00 */  lui       $v0, 0xde00
/* 32E9F0 E0014560 AC620008 */  sw        $v0, 8($v1)
/* 32E9F4 E0014564 3C020900 */  lui       $v0, 0x900
/* 32E9F8 E0014568 244200E0 */  addiu     $v0, $v0, 0xe0
/* 32E9FC E001456C AC62000C */  sw        $v0, 0xc($v1)
/* 32EA00 E0014570 3C028000 */  lui       $v0, 0x8000
/* 32EA04 E0014574 00822021 */  addu      $a0, $a0, $v0
/* 32EA08 E0014578 AC640004 */  sw        $a0, 4($v1)
/* 32EA0C E001457C 8EC20008 */  lw        $v0, 8($s6)
/* 32EA10 E0014580 24630010 */  addiu     $v1, $v1, 0x10
/* 32EA14 E0014584 18400066 */  blez      $v0, .LE0014720
/* 32EA18 E0014588 ACC30000 */   sw       $v1, ($a2)
/* 32EA1C E001458C 4480A000 */  mtc1      $zero, $f20
/* 32EA20 E0014590 27B50060 */  addiu     $s5, $sp, 0x60
/* 32EA24 E0014594 3C1E800A */  lui       $fp, %hi(D_8009A674)
/* 32EA28 E0014598 27DEA674 */  addiu     $fp, $fp, %lo(D_8009A674)
/* 32EA2C E001459C 3C178007 */  lui       $s7, %hi(D_800741F0)
/* 32EA30 E00145A0 26F741F0 */  addiu     $s7, $s7, %lo(D_800741F0)
/* 32EA34 E00145A4 3C140001 */  lui       $s4, 1
/* 32EA38 E00145A8 36941630 */  ori       $s4, $s4, 0x1630
/* 32EA3C E00145AC 00C0982D */  daddu     $s3, $a2, $zero
/* 32EA40 E00145B0 26300008 */  addiu     $s0, $s1, 8
.LE00145B4:
/* 32EA44 E00145B4 8E220000 */  lw        $v0, ($s1)
/* 32EA48 E00145B8 50400054 */  beql      $v0, $zero, .LE001470C
/* 32EA4C E00145BC 26520001 */   addiu    $s2, $s2, 1
/* 32EA50 E00145C0 3C09800B */  lui       $t1, %hi(gCameras)
/* 32EA54 E00145C4 25291D80 */  addiu     $t1, $t1, %lo(gCameras)
/* 32EA58 E00145C8 4405A000 */  mfc1      $a1, $f20
/* 32EA5C E00145CC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 32EA60 E00145D0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 32EA64 E00145D4 4407A000 */  mfc1      $a3, $f20
/* 32EA68 E00145D8 3C013F80 */  lui       $at, 0x3f80
/* 32EA6C E00145DC 44810000 */  mtc1      $at, $f0
/* 32EA70 E00145E0 00031080 */  sll       $v0, $v1, 2
/* 32EA74 E00145E4 00431021 */  addu      $v0, $v0, $v1
/* 32EA78 E00145E8 00021080 */  sll       $v0, $v0, 2
/* 32EA7C E00145EC 00431023 */  subu      $v0, $v0, $v1
/* 32EA80 E00145F0 000218C0 */  sll       $v1, $v0, 3
/* 32EA84 E00145F4 00431021 */  addu      $v0, $v0, $v1
/* 32EA88 E00145F8 000210C0 */  sll       $v0, $v0, 3
/* 32EA8C E00145FC 00491021 */  addu      $v0, $v0, $t1
/* 32EA90 E0014600 C442006C */  lwc1      $f2, 0x6c($v0)
/* 32EA94 E0014604 E7A00010 */  swc1      $f0, 0x10($sp)
/* 32EA98 E0014608 C6000004 */  lwc1      $f0, 4($s0)
/* 32EA9C E001460C 46001087 */  neg.s     $f2, $f2
/* 32EAA0 E0014610 E7A00014 */  swc1      $f0, 0x14($sp)
/* 32EAA4 E0014614 C6000008 */  lwc1      $f0, 8($s0)
/* 32EAA8 E0014618 44061000 */  mfc1      $a2, $f2
/* 32EAAC E001461C E7A00018 */  swc1      $f0, 0x18($sp)
/* 32EAB0 E0014620 C600000C */  lwc1      $f0, 0xc($s0)
/* 32EAB4 E0014624 27A40020 */  addiu     $a0, $sp, 0x20
/* 32EAB8 E0014628 0C080180 */  jal       func_E0200600
/* 32EABC E001462C E7A0001C */   swc1     $f0, 0x1c($sp)
/* 32EAC0 E0014630 8E050010 */  lw        $a1, 0x10($s0)
/* 32EAC4 E0014634 8E060014 */  lw        $a2, 0x14($s0)
/* 32EAC8 E0014638 8E070018 */  lw        $a3, 0x18($s0)
/* 32EACC E001463C 0C080110 */  jal       func_E0200440
/* 32EAD0 E0014640 02A0202D */   daddu    $a0, $s5, $zero
/* 32EAD4 E0014644 02A0202D */  daddu     $a0, $s5, $zero
/* 32EAD8 E0014648 27A50020 */  addiu     $a1, $sp, 0x20
/* 32EADC E001464C 0C080114 */  jal       func_E0200450
/* 32EAE0 E0014650 00A0302D */   daddu    $a2, $a1, $zero
/* 32EAE4 E0014654 27A40020 */  addiu     $a0, $sp, 0x20
/* 32EAE8 E0014658 96E50000 */  lhu       $a1, ($s7)
/* 32EAEC E001465C 8FC20000 */  lw        $v0, ($fp)
/* 32EAF0 E0014660 00052980 */  sll       $a1, $a1, 6
/* 32EAF4 E0014664 00B42821 */  addu      $a1, $a1, $s4
/* 32EAF8 E0014668 0C080118 */  jal       func_E0200460
/* 32EAFC E001466C 00452821 */   addu     $a1, $v0, $a1
/* 32EB00 E0014670 3C077060 */  lui       $a3, 0x7060
/* 32EB04 E0014674 34E71800 */  ori       $a3, $a3, 0x1800
/* 32EB08 E0014678 3C08D838 */  lui       $t0, 0xd838
/* 32EB0C E001467C 35080002 */  ori       $t0, $t0, 2
/* 32EB10 E0014680 8E640000 */  lw        $a0, ($s3)
/* 32EB14 E0014684 3C02FA00 */  lui       $v0, 0xfa00
/* 32EB18 E0014688 0080302D */  daddu     $a2, $a0, $zero
/* 32EB1C E001468C 24840008 */  addiu     $a0, $a0, 8
/* 32EB20 E0014690 AE640000 */  sw        $a0, ($s3)
/* 32EB24 E0014694 ACC20000 */  sw        $v0, ($a2)
/* 32EB28 E0014698 92050000 */  lbu       $a1, ($s0)
/* 32EB2C E001469C 96E30000 */  lhu       $v1, ($s7)
/* 32EB30 E00146A0 24820008 */  addiu     $v0, $a0, 8
/* 32EB34 E00146A4 AE620000 */  sw        $v0, ($s3)
/* 32EB38 E00146A8 24620001 */  addiu     $v0, $v1, 1
/* 32EB3C E00146AC A6E20000 */  sh        $v0, ($s7)
/* 32EB40 E00146B0 24820010 */  addiu     $v0, $a0, 0x10
/* 32EB44 E00146B4 AE620000 */  sw        $v0, ($s3)
/* 32EB48 E00146B8 24820018 */  addiu     $v0, $a0, 0x18
/* 32EB4C E00146BC 00A72825 */  or        $a1, $a1, $a3
/* 32EB50 E00146C0 AE620000 */  sw        $v0, ($s3)
/* 32EB54 E00146C4 3C02DA38 */  lui       $v0, 0xda38
/* 32EB58 E00146C8 3063FFFF */  andi      $v1, $v1, 0xffff
/* 32EB5C E00146CC 00031980 */  sll       $v1, $v1, 6
/* 32EB60 E00146D0 ACC50004 */  sw        $a1, 4($a2)
/* 32EB64 E00146D4 AC820000 */  sw        $v0, ($a0)
/* 32EB68 E00146D8 8FC20000 */  lw        $v0, ($fp)
/* 32EB6C E00146DC 00741821 */  addu      $v1, $v1, $s4
/* 32EB70 E00146E0 AC880010 */  sw        $t0, 0x10($a0)
/* 32EB74 E00146E4 00431021 */  addu      $v0, $v0, $v1
/* 32EB78 E00146E8 AC820004 */  sw        $v0, 4($a0)
/* 32EB7C E00146EC 3C02DE00 */  lui       $v0, 0xde00
/* 32EB80 E00146F0 AC820008 */  sw        $v0, 8($a0)
/* 32EB84 E00146F4 3C020900 */  lui       $v0, 0x900
/* 32EB88 E00146F8 244201B8 */  addiu     $v0, $v0, 0x1b8
/* 32EB8C E00146FC AC82000C */  sw        $v0, 0xc($a0)
/* 32EB90 E0014700 24020040 */  addiu     $v0, $zero, 0x40
/* 32EB94 E0014704 AC820014 */  sw        $v0, 0x14($a0)
/* 32EB98 E0014708 26520001 */  addiu     $s2, $s2, 1
.LE001470C:
/* 32EB9C E001470C 2610004C */  addiu     $s0, $s0, 0x4c
/* 32EBA0 E0014710 8EC20008 */  lw        $v0, 8($s6)
/* 32EBA4 E0014714 0242102A */  slt       $v0, $s2, $v0
/* 32EBA8 E0014718 1440FFA6 */  bnez      $v0, .LE00145B4
/* 32EBAC E001471C 2631004C */   addiu    $s1, $s1, 0x4c
.LE0014720:
/* 32EBB0 E0014720 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 32EBB4 E0014724 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 32EBB8 E0014728 8C620000 */  lw        $v0, ($v1)
/* 32EBBC E001472C 0040202D */  daddu     $a0, $v0, $zero
/* 32EBC0 E0014730 24420008 */  addiu     $v0, $v0, 8
/* 32EBC4 E0014734 AC620000 */  sw        $v0, ($v1)
/* 32EBC8 E0014738 3C02E700 */  lui       $v0, 0xe700
/* 32EBCC E001473C AC820000 */  sw        $v0, ($a0)
/* 32EBD0 E0014740 AC800004 */  sw        $zero, 4($a0)
/* 32EBD4 E0014744 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 32EBD8 E0014748 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 32EBDC E001474C 8FB700BC */  lw        $s7, 0xbc($sp)
/* 32EBE0 E0014750 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 32EBE4 E0014754 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 32EBE8 E0014758 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 32EBEC E001475C 8FB300AC */  lw        $s3, 0xac($sp)
/* 32EBF0 E0014760 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 32EBF4 E0014764 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 32EBF8 E0014768 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 32EBFC E001476C D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 32EC00 E0014770 03E00008 */  jr        $ra
/* 32EC04 E0014774 27BD00D0 */   addiu    $sp, $sp, 0xd0
/* 32EC08 E0014778 00000000 */  nop       
/* 32EC0C E001477C 00000000 */  nop       
