.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80115498
/* ABB98 80115498 27BDFF88 */  addiu     $sp, $sp, -0x78
/* ABB9C 8011549C AFB50064 */  sw        $s5, 0x64($sp)
/* ABBA0 801154A0 0080A82D */  daddu     $s5, $a0, $zero
/* ABBA4 801154A4 00A0182D */  daddu     $v1, $a1, $zero
/* ABBA8 801154A8 AFA60080 */  sw        $a2, 0x80($sp)
/* ABBAC 801154AC AFA70084 */  sw        $a3, 0x84($sp)
/* ABBB0 801154B0 00C71021 */  addu      $v0, $a2, $a3
/* ABBB4 801154B4 02A2102B */  sltu      $v0, $s5, $v0
/* ABBB8 801154B8 AFBF0074 */  sw        $ra, 0x74($sp)
/* ABBBC 801154BC AFBE0070 */  sw        $fp, 0x70($sp)
/* ABBC0 801154C0 AFB7006C */  sw        $s7, 0x6c($sp)
/* ABBC4 801154C4 AFB60068 */  sw        $s6, 0x68($sp)
/* ABBC8 801154C8 AFB40060 */  sw        $s4, 0x60($sp)
/* ABBCC 801154CC AFB3005C */  sw        $s3, 0x5c($sp)
/* ABBD0 801154D0 AFB20058 */  sw        $s2, 0x58($sp)
/* ABBD4 801154D4 AFB10054 */  sw        $s1, 0x54($sp)
/* ABBD8 801154D8 10400180 */  beqz      $v0, .L80115ADC
/* ABBDC 801154DC AFB00050 */   sw       $s0, 0x50($sp)
/* ABBE0 801154E0 27B30020 */  addiu     $s3, $sp, 0x20
/* ABBE4 801154E4 24170001 */  addiu     $s7, $zero, 1
/* ABBE8 801154E8 241E1000 */  addiu     $fp, $zero, 0x1000
/* ABBEC 801154EC 00031100 */  sll       $v0, $v1, 4
/* ABBF0 801154F0 00451021 */  addu      $v0, $v0, $a1
/* ABBF4 801154F4 0002B080 */  sll       $s6, $v0, 2
/* ABBF8 801154F8 02A0202D */  daddu     $a0, $s5, $zero
.L801154FC:
/* ABBFC 801154FC 26A50030 */  addiu     $a1, $s5, 0x30
/* ABC00 80115500 0C00A5CF */  jal       dma_copy
/* ABC04 80115504 27A60020 */   addiu    $a2, $sp, 0x20
/* ABC08 80115508 93A20048 */  lbu       $v0, 0x48($sp)
/* ABC0C 8011550C 10400173 */  beqz      $v0, .L80115ADC
/* ABC10 80115510 00000000 */   nop
/* ABC14 80115514 97A40042 */  lhu       $a0, 0x42($sp)
/* ABC18 80115518 97A20046 */  lhu       $v0, 0x46($sp)
/* ABC1C 8011551C 00820018 */  mult      $a0, $v0
/* ABC20 80115520 97A3004C */  lhu       $v1, 0x4c($sp)
/* ABC24 80115524 30630F00 */  andi      $v1, $v1, 0xf00
/* ABC28 80115528 00009012 */  mflo      $s2
/* ABC2C 8011552C 14600049 */  bnez      $v1, .L80115654
/* ABC30 80115530 24080100 */   addiu    $t0, $zero, 0x100
/* ABC34 80115534 93A20049 */  lbu       $v0, 0x49($sp)
/* ABC38 80115538 54570125 */  bnel      $v0, $s7, .L801159D0
/* ABC3C 8011553C 00129042 */   srl      $s2, $s2, 1
/* ABC40 80115540 24050002 */  addiu     $a1, $zero, 2
/* ABC44 80115544 14A00002 */  bnez      $a1, .L80115550
/* ABC48 80115548 0085001A */   div      $zero, $a0, $a1
/* ABC4C 8011554C 0007000D */  break     7
.L80115550:
/* ABC50 80115550 2401FFFF */   addiu    $at, $zero, -1
/* ABC54 80115554 14A10004 */  bne       $a1, $at, .L80115568
/* ABC58 80115558 3C018000 */   lui      $at, 0x8000
/* ABC5C 8011555C 14810002 */  bne       $a0, $at, .L80115568
/* ABC60 80115560 00000000 */   nop
/* ABC64 80115564 0006000D */  break     6
.L80115568:
/* ABC68 80115568 00001012 */   mflo     $v0
/* ABC6C 8011556C 28420010 */  slti      $v0, $v0, 0x10
/* ABC70 80115570 54400117 */  bnel      $v0, $zero, .L801159D0
/* ABC74 80115574 00129042 */   srl      $s2, $s2, 1
/* ABC78 80115578 96660026 */  lhu       $a2, 0x26($s3)
.L8011557C:
/* ABC7C 8011557C 14A00002 */  bnez      $a1, .L80115588
/* ABC80 80115580 00C5001A */   div      $zero, $a2, $a1
/* ABC84 80115584 0007000D */  break     7
.L80115588:
/* ABC88 80115588 2401FFFF */   addiu    $at, $zero, -1
/* ABC8C 8011558C 14A10004 */  bne       $a1, $at, .L801155A0
/* ABC90 80115590 3C018000 */   lui      $at, 0x8000
/* ABC94 80115594 14C10002 */  bne       $a2, $at, .L801155A0
/* ABC98 80115598 00000000 */   nop
/* ABC9C 8011559C 0006000D */  break     6
.L801155A0:
/* ABCA0 801155A0 00001012 */   mflo     $v0
/* ABCA4 801155A4 5840010A */  blezl     $v0, .L801159D0
/* ABCA8 801155A8 00129042 */   srl      $s2, $s2, 1
/* ABCAC 801155AC 96630022 */  lhu       $v1, 0x22($s3)
/* ABCB0 801155B0 14A00002 */  bnez      $a1, .L801155BC
/* ABCB4 801155B4 0065001A */   div      $zero, $v1, $a1
/* ABCB8 801155B8 0007000D */  break     7
.L801155BC:
/* ABCBC 801155BC 2401FFFF */   addiu    $at, $zero, -1
/* ABCC0 801155C0 14A10004 */  bne       $a1, $at, .L801155D4
/* ABCC4 801155C4 3C018000 */   lui      $at, 0x8000
/* ABCC8 801155C8 14610002 */  bne       $v1, $at, .L801155D4
/* ABCCC 801155CC 00000000 */   nop
/* ABCD0 801155D0 0006000D */  break     6
.L801155D4:
/* ABCD4 801155D4 00001012 */   mflo     $v0
/* ABCD8 801155D8 00000000 */  nop
/* ABCDC 801155DC 00000000 */  nop
/* ABCE0 801155E0 00460018 */  mult      $v0, $a2
/* ABCE4 801155E4 00005012 */  mflo      $t2
/* ABCE8 801155E8 00000000 */  nop
/* ABCEC 801155EC 14A00002 */  bnez      $a1, .L801155F8
/* ABCF0 801155F0 0145001A */   div      $zero, $t2, $a1
/* ABCF4 801155F4 0007000D */  break     7
.L801155F8:
/* ABCF8 801155F8 2401FFFF */   addiu    $at, $zero, -1
/* ABCFC 801155FC 14A10004 */  bne       $a1, $at, .L80115610
/* ABD00 80115600 3C018000 */   lui      $at, 0x8000
/* ABD04 80115604 15410002 */  bne       $t2, $at, .L80115610
/* ABD08 80115608 00000000 */   nop
/* ABD0C 8011560C 0006000D */  break     6
.L80115610:
/* ABD10 80115610 00002012 */   mflo     $a0
/* ABD14 80115614 00052840 */  sll       $a1, $a1, 1
/* ABD18 80115618 14A00002 */  bnez      $a1, .L80115624
/* ABD1C 8011561C 0065001A */   div      $zero, $v1, $a1
/* ABD20 80115620 0007000D */  break     7
.L80115624:
/* ABD24 80115624 2401FFFF */   addiu    $at, $zero, -1
/* ABD28 80115628 14A10004 */  bne       $a1, $at, .L8011563C
/* ABD2C 8011562C 3C018000 */   lui      $at, 0x8000
/* ABD30 80115630 14610002 */  bne       $v1, $at, .L8011563C
/* ABD34 80115634 00000000 */   nop
/* ABD38 80115638 0006000D */  break     6
.L8011563C:
/* ABD3C 8011563C 00001012 */   mflo     $v0
/* ABD40 80115640 28420010 */  slti      $v0, $v0, 0x10
/* ABD44 80115644 1040FFCD */  beqz      $v0, .L8011557C
/* ABD48 80115648 02449021 */   addu     $s2, $s2, $a0
/* ABD4C 8011564C 08045674 */  j         .L801159D0
/* ABD50 80115650 00129042 */   srl      $s2, $s2, 1
.L80115654:
/* ABD54 80115654 14680048 */  bne       $v1, $t0, .L80115778
/* ABD58 80115658 00000000 */   nop
/* ABD5C 8011565C 93A20049 */  lbu       $v0, 0x49($sp)
/* ABD60 80115660 145700DB */  bne       $v0, $s7, .L801159D0
/* ABD64 80115664 24050002 */   addiu    $a1, $zero, 2
/* ABD68 80115668 14A00002 */  bnez      $a1, .L80115674
/* ABD6C 8011566C 0085001A */   div      $zero, $a0, $a1
/* ABD70 80115670 0007000D */  break     7
.L80115674:
/* ABD74 80115674 2401FFFF */   addiu    $at, $zero, -1
/* ABD78 80115678 14A10004 */  bne       $a1, $at, .L8011568C
/* ABD7C 8011567C 3C018000 */   lui      $at, 0x8000
/* ABD80 80115680 14810002 */  bne       $a0, $at, .L8011568C
/* ABD84 80115684 00000000 */   nop
/* ABD88 80115688 0006000D */  break     6
.L8011568C:
/* ABD8C 8011568C 00001012 */   mflo     $v0
/* ABD90 80115690 28420008 */  slti      $v0, $v0, 8
/* ABD94 80115694 144000CE */  bnez      $v0, .L801159D0
/* ABD98 80115698 00000000 */   nop
/* ABD9C 8011569C 96660026 */  lhu       $a2, 0x26($s3)
.L801156A0:
/* ABDA0 801156A0 14A00002 */  bnez      $a1, .L801156AC
/* ABDA4 801156A4 00C5001A */   div      $zero, $a2, $a1
/* ABDA8 801156A8 0007000D */  break     7
.L801156AC:
/* ABDAC 801156AC 2401FFFF */   addiu    $at, $zero, -1
/* ABDB0 801156B0 14A10004 */  bne       $a1, $at, .L801156C4
/* ABDB4 801156B4 3C018000 */   lui      $at, 0x8000
/* ABDB8 801156B8 14C10002 */  bne       $a2, $at, .L801156C4
/* ABDBC 801156BC 00000000 */   nop
/* ABDC0 801156C0 0006000D */  break     6
.L801156C4:
/* ABDC4 801156C4 00001012 */   mflo     $v0
/* ABDC8 801156C8 184000C1 */  blez      $v0, .L801159D0
/* ABDCC 801156CC 00000000 */   nop
/* ABDD0 801156D0 96630022 */  lhu       $v1, 0x22($s3)
/* ABDD4 801156D4 14A00002 */  bnez      $a1, .L801156E0
/* ABDD8 801156D8 0065001A */   div      $zero, $v1, $a1
/* ABDDC 801156DC 0007000D */  break     7
.L801156E0:
/* ABDE0 801156E0 2401FFFF */   addiu    $at, $zero, -1
/* ABDE4 801156E4 14A10004 */  bne       $a1, $at, .L801156F8
/* ABDE8 801156E8 3C018000 */   lui      $at, 0x8000
/* ABDEC 801156EC 14610002 */  bne       $v1, $at, .L801156F8
/* ABDF0 801156F0 00000000 */   nop
/* ABDF4 801156F4 0006000D */  break     6
.L801156F8:
/* ABDF8 801156F8 00001012 */   mflo     $v0
/* ABDFC 801156FC 00000000 */  nop
/* ABE00 80115700 00000000 */  nop
/* ABE04 80115704 00460018 */  mult      $v0, $a2
/* ABE08 80115708 00005012 */  mflo      $t2
/* ABE0C 8011570C 00000000 */  nop
/* ABE10 80115710 14A00002 */  bnez      $a1, .L8011571C
/* ABE14 80115714 0145001A */   div      $zero, $t2, $a1
/* ABE18 80115718 0007000D */  break     7
.L8011571C:
/* ABE1C 8011571C 2401FFFF */   addiu    $at, $zero, -1
/* ABE20 80115720 14A10004 */  bne       $a1, $at, .L80115734
/* ABE24 80115724 3C018000 */   lui      $at, 0x8000
/* ABE28 80115728 15410002 */  bne       $t2, $at, .L80115734
/* ABE2C 8011572C 00000000 */   nop
/* ABE30 80115730 0006000D */  break     6
.L80115734:
/* ABE34 80115734 00002012 */   mflo     $a0
/* ABE38 80115738 00052840 */  sll       $a1, $a1, 1
/* ABE3C 8011573C 14A00002 */  bnez      $a1, .L80115748
/* ABE40 80115740 0065001A */   div      $zero, $v1, $a1
/* ABE44 80115744 0007000D */  break     7
.L80115748:
/* ABE48 80115748 2401FFFF */   addiu    $at, $zero, -1
/* ABE4C 8011574C 14A10004 */  bne       $a1, $at, .L80115760
/* ABE50 80115750 3C018000 */   lui      $at, 0x8000
/* ABE54 80115754 14610002 */  bne       $v1, $at, .L80115760
/* ABE58 80115758 00000000 */   nop
/* ABE5C 8011575C 0006000D */  break     6
.L80115760:
/* ABE60 80115760 00001012 */   mflo     $v0
/* ABE64 80115764 28420008 */  slti      $v0, $v0, 8
/* ABE68 80115768 14400099 */  bnez      $v0, .L801159D0
/* ABE6C 8011576C 02449021 */   addu     $s2, $s2, $a0
/* ABE70 80115770 080455A8 */  j         .L801156A0
/* ABE74 80115774 00000000 */   nop
.L80115778:
/* ABE78 80115778 9662002C */  lhu       $v0, 0x2c($s3)
/* ABE7C 8011577C 30430F00 */  andi      $v1, $v0, 0xf00
/* ABE80 80115780 24020200 */  addiu     $v0, $zero, 0x200
/* ABE84 80115784 14620049 */  bne       $v1, $v0, .L801158AC
/* ABE88 80115788 24020300 */   addiu    $v0, $zero, 0x300
/* ABE8C 8011578C 92620029 */  lbu       $v0, 0x29($s3)
/* ABE90 80115790 5457008F */  bnel      $v0, $s7, .L801159D0
/* ABE94 80115794 00129040 */   sll      $s2, $s2, 1
/* ABE98 80115798 96670022 */  lhu       $a3, 0x22($s3)
/* ABE9C 8011579C 24040002 */  addiu     $a0, $zero, 2
/* ABEA0 801157A0 14800002 */  bnez      $a0, .L801157AC
/* ABEA4 801157A4 00E4001A */   div      $zero, $a3, $a0
/* ABEA8 801157A8 0007000D */  break     7
.L801157AC:
/* ABEAC 801157AC 2401FFFF */   addiu    $at, $zero, -1
/* ABEB0 801157B0 14810004 */  bne       $a0, $at, .L801157C4
/* ABEB4 801157B4 3C018000 */   lui      $at, 0x8000
/* ABEB8 801157B8 14E10002 */  bne       $a3, $at, .L801157C4
/* ABEBC 801157BC 00000000 */   nop
/* ABEC0 801157C0 0006000D */  break     6
.L801157C4:
/* ABEC4 801157C4 00001012 */   mflo     $v0
/* ABEC8 801157C8 28420004 */  slti      $v0, $v0, 4
/* ABECC 801157CC 54400080 */  bnel      $v0, $zero, .L801159D0
/* ABED0 801157D0 00129040 */   sll      $s2, $s2, 1
/* ABED4 801157D4 96660026 */  lhu       $a2, 0x26($s3)
.L801157D8:
/* ABED8 801157D8 14800002 */  bnez      $a0, .L801157E4
/* ABEDC 801157DC 00C4001A */   div      $zero, $a2, $a0
/* ABEE0 801157E0 0007000D */  break     7
.L801157E4:
/* ABEE4 801157E4 2401FFFF */   addiu    $at, $zero, -1
/* ABEE8 801157E8 14810004 */  bne       $a0, $at, .L801157FC
/* ABEEC 801157EC 3C018000 */   lui      $at, 0x8000
/* ABEF0 801157F0 14C10002 */  bne       $a2, $at, .L801157FC
/* ABEF4 801157F4 00000000 */   nop
/* ABEF8 801157F8 0006000D */  break     6
.L801157FC:
/* ABEFC 801157FC 00001012 */   mflo     $v0
/* ABF00 80115800 58400073 */  blezl     $v0, .L801159D0
/* ABF04 80115804 00129040 */   sll      $s2, $s2, 1
/* ABF08 80115808 14800002 */  bnez      $a0, .L80115814
/* ABF0C 8011580C 00E4001A */   div      $zero, $a3, $a0
/* ABF10 80115810 0007000D */  break     7
.L80115814:
/* ABF14 80115814 2401FFFF */   addiu    $at, $zero, -1
/* ABF18 80115818 14810004 */  bne       $a0, $at, .L8011582C
/* ABF1C 8011581C 3C018000 */   lui      $at, 0x8000
/* ABF20 80115820 14E10002 */  bne       $a3, $at, .L8011582C
/* ABF24 80115824 00000000 */   nop
/* ABF28 80115828 0006000D */  break     6
.L8011582C:
/* ABF2C 8011582C 00001012 */   mflo     $v0
/* ABF30 80115830 00000000 */  nop
/* ABF34 80115834 00000000 */  nop
/* ABF38 80115838 00460018 */  mult      $v0, $a2
/* ABF3C 8011583C 00001812 */  mflo      $v1
/* ABF40 80115840 00000000 */  nop
/* ABF44 80115844 14800002 */  bnez      $a0, .L80115850
/* ABF48 80115848 0064001A */   div      $zero, $v1, $a0
/* ABF4C 8011584C 0007000D */  break     7
.L80115850:
/* ABF50 80115850 2401FFFF */   addiu    $at, $zero, -1
/* ABF54 80115854 14810004 */  bne       $a0, $at, .L80115868
/* ABF58 80115858 3C018000 */   lui      $at, 0x8000
/* ABF5C 8011585C 14610002 */  bne       $v1, $at, .L80115868
/* ABF60 80115860 00000000 */   nop
/* ABF64 80115864 0006000D */  break     6
.L80115868:
/* ABF68 80115868 00001812 */   mflo     $v1
/* ABF6C 8011586C 00042040 */  sll       $a0, $a0, 1
/* ABF70 80115870 14800002 */  bnez      $a0, .L8011587C
/* ABF74 80115874 00E4001A */   div      $zero, $a3, $a0
/* ABF78 80115878 0007000D */  break     7
.L8011587C:
/* ABF7C 8011587C 2401FFFF */   addiu    $at, $zero, -1
/* ABF80 80115880 14810004 */  bne       $a0, $at, .L80115894
/* ABF84 80115884 3C018000 */   lui      $at, 0x8000
/* ABF88 80115888 14E10002 */  bne       $a3, $at, .L80115894
/* ABF8C 8011588C 00000000 */   nop
/* ABF90 80115890 0006000D */  break     6
.L80115894:
/* ABF94 80115894 00001012 */   mflo     $v0
/* ABF98 80115898 28420004 */  slti      $v0, $v0, 4
/* ABF9C 8011589C 1040FFCE */  beqz      $v0, .L801157D8
/* ABFA0 801158A0 02439021 */   addu     $s2, $s2, $v1
/* ABFA4 801158A4 08045674 */  j         .L801159D0
/* ABFA8 801158A8 00129040 */   sll      $s2, $s2, 1
.L801158AC:
/* ABFAC 801158AC 14620048 */  bne       $v1, $v0, .L801159D0
/* ABFB0 801158B0 00000000 */   nop
/* ABFB4 801158B4 92620029 */  lbu       $v0, 0x29($s3)
/* ABFB8 801158B8 54570045 */  bnel      $v0, $s7, .L801159D0
/* ABFBC 801158BC 00129080 */   sll      $s2, $s2, 2
/* ABFC0 801158C0 96670022 */  lhu       $a3, 0x22($s3)
/* ABFC4 801158C4 24040002 */  addiu     $a0, $zero, 2
/* ABFC8 801158C8 14800002 */  bnez      $a0, .L801158D4
/* ABFCC 801158CC 00E4001A */   div      $zero, $a3, $a0
/* ABFD0 801158D0 0007000D */  break     7
.L801158D4:
/* ABFD4 801158D4 2401FFFF */   addiu    $at, $zero, -1
/* ABFD8 801158D8 14810004 */  bne       $a0, $at, .L801158EC
/* ABFDC 801158DC 3C018000 */   lui      $at, 0x8000
/* ABFE0 801158E0 14E10002 */  bne       $a3, $at, .L801158EC
/* ABFE4 801158E4 00000000 */   nop
/* ABFE8 801158E8 0006000D */  break     6
.L801158EC:
/* ABFEC 801158EC 00001012 */   mflo     $v0
/* ABFF0 801158F0 0044102A */  slt       $v0, $v0, $a0
/* ABFF4 801158F4 54400036 */  bnel      $v0, $zero, .L801159D0
/* ABFF8 801158F8 00129080 */   sll      $s2, $s2, 2
/* ABFFC 801158FC 96660026 */  lhu       $a2, 0x26($s3)
.L80115900:
/* AC000 80115900 14800002 */  bnez      $a0, .L8011590C
/* AC004 80115904 00C4001A */   div      $zero, $a2, $a0
/* AC008 80115908 0007000D */  break     7
.L8011590C:
/* AC00C 8011590C 2401FFFF */   addiu    $at, $zero, -1
/* AC010 80115910 14810004 */  bne       $a0, $at, .L80115924
/* AC014 80115914 3C018000 */   lui      $at, 0x8000
/* AC018 80115918 14C10002 */  bne       $a2, $at, .L80115924
/* AC01C 8011591C 00000000 */   nop
/* AC020 80115920 0006000D */  break     6
.L80115924:
/* AC024 80115924 00001012 */   mflo     $v0
/* AC028 80115928 58400029 */  blezl     $v0, .L801159D0
/* AC02C 8011592C 00129080 */   sll      $s2, $s2, 2
/* AC030 80115930 14800002 */  bnez      $a0, .L8011593C
/* AC034 80115934 00E4001A */   div      $zero, $a3, $a0
/* AC038 80115938 0007000D */  break     7
.L8011593C:
/* AC03C 8011593C 2401FFFF */   addiu    $at, $zero, -1
/* AC040 80115940 14810004 */  bne       $a0, $at, .L80115954
/* AC044 80115944 3C018000 */   lui      $at, 0x8000
/* AC048 80115948 14E10002 */  bne       $a3, $at, .L80115954
/* AC04C 8011594C 00000000 */   nop
/* AC050 80115950 0006000D */  break     6
.L80115954:
/* AC054 80115954 00001012 */   mflo     $v0
/* AC058 80115958 00000000 */  nop
/* AC05C 8011595C 00000000 */  nop
/* AC060 80115960 00460018 */  mult      $v0, $a2
/* AC064 80115964 00001812 */  mflo      $v1
/* AC068 80115968 00000000 */  nop
/* AC06C 8011596C 14800002 */  bnez      $a0, .L80115978
/* AC070 80115970 0064001A */   div      $zero, $v1, $a0
/* AC074 80115974 0007000D */  break     7
.L80115978:
/* AC078 80115978 2401FFFF */   addiu    $at, $zero, -1
/* AC07C 8011597C 14810004 */  bne       $a0, $at, .L80115990
/* AC080 80115980 3C018000 */   lui      $at, 0x8000
/* AC084 80115984 14610002 */  bne       $v1, $at, .L80115990
/* AC088 80115988 00000000 */   nop
/* AC08C 8011598C 0006000D */  break     6
.L80115990:
/* AC090 80115990 00001812 */   mflo     $v1
/* AC094 80115994 00042040 */  sll       $a0, $a0, 1
/* AC098 80115998 14800002 */  bnez      $a0, .L801159A4
/* AC09C 8011599C 00E4001A */   div      $zero, $a3, $a0
/* AC0A0 801159A0 0007000D */  break     7
.L801159A4:
/* AC0A4 801159A4 2401FFFF */   addiu    $at, $zero, -1
/* AC0A8 801159A8 14810004 */  bne       $a0, $at, .L801159BC
/* AC0AC 801159AC 3C018000 */   lui      $at, 0x8000
/* AC0B0 801159B0 14E10002 */  bne       $a3, $at, .L801159BC
/* AC0B4 801159B4 00000000 */   nop
/* AC0B8 801159B8 0006000D */  break     6
.L801159BC:
/* AC0BC 801159BC 00001012 */   mflo     $v0
/* AC0C0 801159C0 28420002 */  slti      $v0, $v0, 2
/* AC0C4 801159C4 1040FFCE */  beqz      $v0, .L80115900
/* AC0C8 801159C8 02439021 */   addu     $s2, $s2, $v1
/* AC0CC 801159CC 00129080 */  sll       $s2, $s2, 2
.L801159D0:
/* AC0D0 801159D0 9662002A */  lhu       $v0, 0x2a($s3)
/* AC0D4 801159D4 24030002 */  addiu     $v1, $zero, 2
/* AC0D8 801159D8 3042000F */  andi      $v0, $v0, 0xf
/* AC0DC 801159DC 14430007 */  bne       $v0, $v1, .L801159FC
/* AC0E0 801159E0 0000A02D */   daddu    $s4, $zero, $zero
/* AC0E4 801159E4 9662002C */  lhu       $v0, 0x2c($s3)
/* AC0E8 801159E8 24080100 */  addiu     $t0, $zero, 0x100
/* AC0EC 801159EC 30420F00 */  andi      $v0, $v0, 0xf00
/* AC0F0 801159F0 14480002 */  bne       $v0, $t0, .L801159FC
/* AC0F4 801159F4 24140020 */   addiu    $s4, $zero, 0x20
/* AC0F8 801159F8 24140200 */  addiu     $s4, $zero, 0x200
.L801159FC:
/* AC0FC 801159FC 92630029 */  lbu       $v1, 0x29($s3)
/* AC100 80115A00 24020003 */  addiu     $v0, $zero, 3
/* AC104 80115A04 1462001E */  bne       $v1, $v0, .L80115A80
/* AC108 80115A08 0000882D */   daddu    $s1, $zero, $zero
/* AC10C 80115A0C 96640020 */  lhu       $a0, 0x20($s3)
/* AC110 80115A10 96620024 */  lhu       $v0, 0x24($s3)
/* AC114 80115A14 00820018 */  mult      $a0, $v0
/* AC118 80115A18 9663002C */  lhu       $v1, 0x2c($s3)
/* AC11C 80115A1C 3063F000 */  andi      $v1, $v1, 0xf000
/* AC120 80115A20 00008012 */  mflo      $s0
/* AC124 80115A24 14600003 */  bnez      $v1, .L80115A34
/* AC128 80115A28 00000000 */   nop
/* AC12C 80115A2C 08045695 */  j         .L80115A54
/* AC130 80115A30 00108042 */   srl      $s0, $s0, 1
.L80115A34:
/* AC134 80115A34 107E0007 */  beq       $v1, $fp, .L80115A54
/* AC138 80115A38 24022000 */   addiu    $v0, $zero, 0x2000
/* AC13C 80115A3C 14620003 */  bne       $v1, $v0, .L80115A4C
/* AC140 80115A40 24023000 */   addiu    $v0, $zero, 0x3000
/* AC144 80115A44 08045695 */  j         .L80115A54
/* AC148 80115A48 00108040 */   sll      $s0, $s0, 1
.L80115A4C:
/* AC14C 80115A4C 50620001 */  beql      $v1, $v0, .L80115A54
/* AC150 80115A50 00108080 */   sll      $s0, $s0, 2
.L80115A54:
/* AC154 80115A54 9662002A */  lhu       $v0, 0x2a($s3)
/* AC158 80115A58 24030020 */  addiu     $v1, $zero, 0x20
/* AC15C 80115A5C 304200F0 */  andi      $v0, $v0, 0xf0
/* AC160 80115A60 14430008 */  bne       $v0, $v1, .L80115A84
/* AC164 80115A64 0000882D */   daddu    $s1, $zero, $zero
/* AC168 80115A68 9662002C */  lhu       $v0, 0x2c($s3)
/* AC16C 80115A6C 3042F000 */  andi      $v0, $v0, 0xf000
/* AC170 80115A70 145E0004 */  bne       $v0, $fp, .L80115A84
/* AC174 80115A74 0060882D */   daddu    $s1, $v1, $zero
/* AC178 80115A78 080456A1 */  j         .L80115A84
/* AC17C 80115A7C 24110200 */   addiu    $s1, $zero, 0x200
.L80115A80:
/* AC180 80115A80 0220802D */  daddu     $s0, $s1, $zero
.L80115A84:
/* AC184 80115A84 26D60044 */  addiu     $s6, $s6, 0x44
/* AC188 80115A88 26A40030 */  addiu     $a0, $s5, 0x30
/* AC18C 80115A8C 3C058016 */  lui       $a1, %hi(D_8015A590)
/* AC190 80115A90 24A5A590 */  addiu     $a1, $a1, %lo(D_8015A590)
/* AC194 80115A94 02C52821 */  addu      $a1, $s6, $a1
/* AC198 80115A98 0260302D */  daddu     $a2, $s3, $zero
/* AC19C 80115A9C 0240382D */  daddu     $a3, $s2, $zero
/* AC1A0 80115AA0 AFB40010 */  sw        $s4, 0x10($sp)
/* AC1A4 80115AA4 AFB00014 */  sw        $s0, 0x14($sp)
/* AC1A8 80115AA8 0C0452D6 */  jal       func_80114B58
/* AC1AC 80115AAC AFB10018 */   sw       $s1, 0x18($sp)
/* AC1B0 80115AB0 02541021 */  addu      $v0, $s2, $s4
/* AC1B4 80115AB4 24420030 */  addiu     $v0, $v0, 0x30
/* AC1B8 80115AB8 02A2A821 */  addu      $s5, $s5, $v0
/* AC1BC 80115ABC 02111021 */  addu      $v0, $s0, $s1
/* AC1C0 80115AC0 8FA80080 */  lw        $t0, 0x80($sp)
/* AC1C4 80115AC4 8FA90084 */  lw        $t1, 0x84($sp)
/* AC1C8 80115AC8 02A2A821 */  addu      $s5, $s5, $v0
/* AC1CC 80115ACC 01091021 */  addu      $v0, $t0, $t1
/* AC1D0 80115AD0 02A2102B */  sltu      $v0, $s5, $v0
/* AC1D4 80115AD4 1440FE89 */  bnez      $v0, .L801154FC
/* AC1D8 80115AD8 02A0202D */   daddu    $a0, $s5, $zero
.L80115ADC:
/* AC1DC 80115ADC 8FBF0074 */  lw        $ra, 0x74($sp)
/* AC1E0 80115AE0 8FBE0070 */  lw        $fp, 0x70($sp)
/* AC1E4 80115AE4 8FB7006C */  lw        $s7, 0x6c($sp)
/* AC1E8 80115AE8 8FB60068 */  lw        $s6, 0x68($sp)
/* AC1EC 80115AEC 8FB50064 */  lw        $s5, 0x64($sp)
/* AC1F0 80115AF0 8FB40060 */  lw        $s4, 0x60($sp)
/* AC1F4 80115AF4 8FB3005C */  lw        $s3, 0x5c($sp)
/* AC1F8 80115AF8 8FB20058 */  lw        $s2, 0x58($sp)
/* AC1FC 80115AFC 8FB10054 */  lw        $s1, 0x54($sp)
/* AC200 80115B00 8FB00050 */  lw        $s0, 0x50($sp)
/* AC204 80115B04 03E00008 */  jr        $ra
/* AC208 80115B08 27BD0078 */   addiu    $sp, $sp, 0x78
