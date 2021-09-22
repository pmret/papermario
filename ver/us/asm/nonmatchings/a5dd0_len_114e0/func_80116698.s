.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80116698
/* ACD98 80116698 27BDFF20 */  addiu     $sp, $sp, -0xe0
/* ACD9C 8011669C AFB200C0 */  sw        $s2, 0xc0($sp)
/* ACDA0 801166A0 0000902D */  daddu     $s2, $zero, $zero
/* ACDA4 801166A4 AFB300C4 */  sw        $s3, 0xc4($sp)
/* ACDA8 801166A8 3C138007 */  lui       $s3, %hi(gMatrixListPos)
/* ACDAC 801166AC 267341F0 */  addiu     $s3, $s3, %lo(gMatrixListPos)
/* ACDB0 801166B0 AFB400C8 */  sw        $s4, 0xc8($sp)
/* ACDB4 801166B4 3C140001 */  lui       $s4, 1
/* ACDB8 801166B8 F7B400D8 */  sdc1      $f20, 0xd8($sp)
/* ACDBC 801166BC 3C013F00 */  lui       $at, 0x3f00
/* ACDC0 801166C0 4481A000 */  mtc1      $at, $f20
/* ACDC4 801166C4 36941630 */  ori       $s4, $s4, 0x1630
/* ACDC8 801166C8 AFBF00D0 */  sw        $ra, 0xd0($sp)
/* ACDCC 801166CC AFB500CC */  sw        $s5, 0xcc($sp)
/* ACDD0 801166D0 AFB100BC */  sw        $s1, 0xbc($sp)
/* ACDD4 801166D4 AFB000B8 */  sw        $s0, 0xb8($sp)
.L801166D8:
/* ACDD8 801166D8 3C038015 */  lui       $v1, %hi(gCurrentModels)
/* ACDDC 801166DC 8C6312CC */  lw        $v1, %lo(gCurrentModels)($v1)
/* ACDE0 801166E0 00121080 */  sll       $v0, $s2, 2
/* ACDE4 801166E4 00431021 */  addu      $v0, $v0, $v1
/* ACDE8 801166E8 8C500000 */  lw        $s0, ($v0)
/* ACDEC 801166EC 52000088 */  beql      $s0, $zero, .L80116910
/* ACDF0 801166F0 26520001 */   addiu    $s2, $s2, 1
/* ACDF4 801166F4 96030000 */  lhu       $v1, ($s0)
/* ACDF8 801166F8 50600085 */  beql      $v1, $zero, .L80116910
/* ACDFC 801166FC 26520001 */   addiu    $s2, $s2, 1
/* ACE00 80116700 30620004 */  andi      $v0, $v1, 4
/* ACE04 80116704 54400082 */  bnel      $v0, $zero, .L80116910
/* ACE08 80116708 26520001 */   addiu    $s2, $s2, 1
/* ACE0C 8011670C 30621000 */  andi      $v0, $v1, 0x1000
/* ACE10 80116710 14400034 */  bnez      $v0, .L801167E4
/* ACE14 80116714 24020002 */   addiu    $v0, $zero, 2
/* ACE18 80116718 920200A7 */  lbu       $v0, 0xa7($s0)
/* ACE1C 8011671C 1040002E */  beqz      $v0, .L801167D8
/* ACE20 80116720 2442FFFF */   addiu    $v0, $v0, -1
/* ACE24 80116724 A20200A7 */  sb        $v0, 0xa7($s0)
/* ACE28 80116728 304200FF */  andi      $v0, $v0, 0xff
/* ACE2C 8011672C 1440000F */  bnez      $v0, .L8011676C
/* ACE30 80116730 00000000 */   nop
/* ACE34 80116734 8E020010 */  lw        $v0, 0x10($s0)
/* ACE38 80116738 26030018 */  addiu     $v1, $s0, 0x18
/* ACE3C 8011673C 24440040 */  addiu     $a0, $v0, 0x40
.L80116740:
/* ACE40 80116740 8C480000 */  lw        $t0, ($v0)
/* ACE44 80116744 8C490004 */  lw        $t1, 4($v0)
/* ACE48 80116748 8C4A0008 */  lw        $t2, 8($v0)
/* ACE4C 8011674C 8C4B000C */  lw        $t3, 0xc($v0)
/* ACE50 80116750 AC680000 */  sw        $t0, ($v1)
/* ACE54 80116754 AC690004 */  sw        $t1, 4($v1)
/* ACE58 80116758 AC6A0008 */  sw        $t2, 8($v1)
/* ACE5C 8011675C AC6B000C */  sw        $t3, 0xc($v1)
/* ACE60 80116760 24420010 */  addiu     $v0, $v0, 0x10
/* ACE64 80116764 1444FFF6 */  bne       $v0, $a0, .L80116740
/* ACE68 80116768 24630010 */   addiu    $v1, $v1, 0x10
.L8011676C:
/* ACE6C 8011676C 96620000 */  lhu       $v0, ($s3)
/* ACE70 80116770 8E110010 */  lw        $s1, 0x10($s0)
/* ACE74 80116774 3C04800A */  lui       $a0, %hi(gDisplayContext)
/* ACE78 80116778 8C84A674 */  lw        $a0, %lo(gDisplayContext)($a0)
/* ACE7C 8011677C 3043FFFF */  andi      $v1, $v0, 0xffff
/* ACE80 80116780 00031980 */  sll       $v1, $v1, 6
/* ACE84 80116784 00741821 */  addu      $v1, $v1, $s4
/* ACE88 80116788 00832021 */  addu      $a0, $a0, $v1
/* ACE8C 8011678C 0080182D */  daddu     $v1, $a0, $zero
/* ACE90 80116790 0220202D */  daddu     $a0, $s1, $zero
/* ACE94 80116794 24850040 */  addiu     $a1, $a0, 0x40
/* ACE98 80116798 24420001 */  addiu     $v0, $v0, 1
/* ACE9C 8011679C A6620000 */  sh        $v0, ($s3)
/* ACEA0 801167A0 AE030010 */  sw        $v1, 0x10($s0)
.L801167A4:
/* ACEA4 801167A4 8C880000 */  lw        $t0, ($a0)
/* ACEA8 801167A8 8C890004 */  lw        $t1, 4($a0)
/* ACEAC 801167AC 8C8A0008 */  lw        $t2, 8($a0)
/* ACEB0 801167B0 8C8B000C */  lw        $t3, 0xc($a0)
/* ACEB4 801167B4 AC680000 */  sw        $t0, ($v1)
/* ACEB8 801167B8 AC690004 */  sw        $t1, 4($v1)
/* ACEBC 801167BC AC6A0008 */  sw        $t2, 8($v1)
/* ACEC0 801167C0 AC6B000C */  sw        $t3, 0xc($v1)
/* ACEC4 801167C4 24840010 */  addiu     $a0, $a0, 0x10
/* ACEC8 801167C8 1485FFF6 */  bne       $a0, $a1, .L801167A4
/* ACECC 801167CC 24630010 */   addiu    $v1, $v1, 0x10
/* ACED0 801167D0 08045A44 */  j         .L80116910
/* ACED4 801167D4 26520001 */   addiu    $s2, $s2, 1
.L801167D8:
/* ACED8 801167D8 26020018 */  addiu     $v0, $s0, 0x18
/* ACEDC 801167DC 08045A43 */  j         .L8011690C
/* ACEE0 801167E0 AE020010 */   sw       $v0, 0x10($s0)
.L801167E4:
/* ACEE4 801167E4 A20200A7 */  sb        $v0, 0xa7($s0)
/* ACEE8 801167E8 3062EFFF */  andi      $v0, $v1, 0xefff
/* ACEEC 801167EC 96640000 */  lhu       $a0, ($s3)
/* ACEF0 801167F0 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* ACEF4 801167F4 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* ACEF8 801167F8 8E050004 */  lw        $a1, 4($s0)
/* ACEFC 801167FC A6020000 */  sh        $v0, ($s0)
/* ACF00 80116800 3082FFFF */  andi      $v0, $a0, 0xffff
/* ACF04 80116804 00021180 */  sll       $v0, $v0, 6
/* ACF08 80116808 00541021 */  addu      $v0, $v0, $s4
/* ACF0C 8011680C 00628821 */  addu      $s1, $v1, $v0
/* ACF10 80116810 24840001 */  addiu     $a0, $a0, 1
/* ACF14 80116814 10A00005 */  beqz      $a1, .L8011682C
/* ACF18 80116818 A6640000 */   sh       $a0, ($s3)
/* ACF1C 8011681C 96020000 */  lhu       $v0, ($s0)
/* ACF20 80116820 30420008 */  andi      $v0, $v0, 8
/* ACF24 80116824 10400003 */  beqz      $v0, .L80116834
/* ACF28 80116828 00000000 */   nop
.L8011682C:
/* ACF2C 8011682C 08045A14 */  j         .L80116850
/* ACF30 80116830 26040058 */   addiu    $a0, $s0, 0x58
.L80116834:
/* ACF34 80116834 0C019D60 */  jal       guMtxL2F
/* ACF38 80116838 27A40020 */   addiu    $a0, $sp, 0x20
/* ACF3C 8011683C 26040058 */  addiu     $a0, $s0, 0x58
/* ACF40 80116840 27A50020 */  addiu     $a1, $sp, 0x20
/* ACF44 80116844 0C019D80 */  jal       guMtxCatF
/* ACF48 80116848 00A0302D */   daddu    $a2, $a1, $zero
/* ACF4C 8011684C 27A40020 */  addiu     $a0, $sp, 0x20
.L80116850:
/* ACF50 80116850 0C019D40 */  jal       guMtxF2L
/* ACF54 80116854 0220282D */   daddu    $a1, $s1, $zero
/* ACF58 80116858 24050061 */  addiu     $a1, $zero, 0x61
/* ACF5C 8011685C 96020000 */  lhu       $v0, ($s0)
/* ACF60 80116860 8E040008 */  lw        $a0, 8($s0)
/* ACF64 80116864 3042DFFF */  andi      $v0, $v0, 0xdfff
/* ACF68 80116868 0C0456C3 */  jal       get_model_property
/* ACF6C 8011686C A6020000 */   sh       $v0, ($s0)
/* ACF70 80116870 C4460008 */  lwc1      $f6, 8($v0)
/* ACF74 80116874 C440002C */  lwc1      $f0, 0x2c($v0)
/* ACF78 80116878 46003180 */  add.s     $f6, $f6, $f0
/* ACF7C 8011687C 46143182 */  mul.s     $f6, $f6, $f20
/* ACF80 80116880 00000000 */  nop
/* ACF84 80116884 C4440014 */  lwc1      $f4, 0x14($v0)
/* ACF88 80116888 C4400038 */  lwc1      $f0, 0x38($v0)
/* ACF8C 8011688C 46002100 */  add.s     $f4, $f4, $f0
/* ACF90 80116890 46142102 */  mul.s     $f4, $f4, $f20
/* ACF94 80116894 00000000 */  nop
/* ACF98 80116898 C4420020 */  lwc1      $f2, 0x20($v0)
/* ACF9C 8011689C C4400044 */  lwc1      $f0, 0x44($v0)
/* ACFA0 801168A0 46001080 */  add.s     $f2, $f2, $f0
/* ACFA4 801168A4 46141082 */  mul.s     $f2, $f2, $f20
/* ACFA8 801168A8 00000000 */  nop
/* ACFAC 801168AC 0220202D */  daddu     $a0, $s1, $zero
/* ACFB0 801168B0 44053000 */  mfc1      $a1, $f6
/* ACFB4 801168B4 44062000 */  mfc1      $a2, $f4
/* ACFB8 801168B8 44071000 */  mfc1      $a3, $f2
/* ACFBC 801168BC 27A200A0 */  addiu     $v0, $sp, 0xa0
/* ACFC0 801168C0 AFA500A0 */  sw        $a1, 0xa0($sp)
/* ACFC4 801168C4 AFA600A4 */  sw        $a2, 0xa4($sp)
/* ACFC8 801168C8 AFA700A8 */  sw        $a3, 0xa8($sp)
/* ACFCC 801168CC AFA20010 */  sw        $v0, 0x10($sp)
/* ACFD0 801168D0 27A200A4 */  addiu     $v0, $sp, 0xa4
/* ACFD4 801168D4 AFA20014 */  sw        $v0, 0x14($sp)
/* ACFD8 801168D8 27A200A8 */  addiu     $v0, $sp, 0xa8
/* ACFDC 801168DC 0C019E78 */  jal       guMtxXFML
/* ACFE0 801168E0 AFA20018 */   sw       $v0, 0x18($sp)
/* ACFE4 801168E4 C7A000A0 */  lwc1      $f0, 0xa0($sp)
/* ACFE8 801168E8 C7A200A4 */  lwc1      $f2, 0xa4($sp)
/* ACFEC 801168EC C7A400A8 */  lwc1      $f4, 0xa8($sp)
/* ACFF0 801168F0 96020000 */  lhu       $v0, ($s0)
/* ACFF4 801168F4 AE110010 */  sw        $s1, 0x10($s0)
/* ACFF8 801168F8 3042FDFF */  andi      $v0, $v0, 0xfdff
/* ACFFC 801168FC E6000098 */  swc1      $f0, 0x98($s0)
/* AD000 80116900 E602009C */  swc1      $f2, 0x9c($s0)
/* AD004 80116904 E60400A0 */  swc1      $f4, 0xa0($s0)
/* AD008 80116908 A6020000 */  sh        $v0, ($s0)
.L8011690C:
/* AD00C 8011690C 26520001 */  addiu     $s2, $s2, 1
.L80116910:
/* AD010 80116910 2A420100 */  slti      $v0, $s2, 0x100
/* AD014 80116914 1440FF70 */  bnez      $v0, .L801166D8
/* AD018 80116918 3C150001 */   lui      $s5, 1
/* AD01C 8011691C 0000902D */  daddu     $s2, $zero, $zero
/* AD020 80116920 3C148007 */  lui       $s4, %hi(gMatrixListPos)
/* AD024 80116924 269441F0 */  addiu     $s4, $s4, %lo(gMatrixListPos)
/* AD028 80116928 36B51630 */  ori       $s5, $s5, 0x1630
/* AD02C 8011692C 27B30060 */  addiu     $s3, $sp, 0x60
/* AD030 80116930 3C013F00 */  lui       $at, 0x3f00
/* AD034 80116934 4481A000 */  mtc1      $at, $f20
.L80116938:
/* AD038 80116938 3C038015 */  lui       $v1, %hi(gCurrentTransformGroups)
/* AD03C 8011693C 8C6312E0 */  lw        $v1, %lo(gCurrentTransformGroups)($v1)
/* AD040 80116940 00121080 */  sll       $v0, $s2, 2
/* AD044 80116944 00431021 */  addu      $v0, $v0, $v1
/* AD048 80116948 8C500000 */  lw        $s0, ($v0)
/* AD04C 8011694C 52000081 */  beql      $s0, $zero, .L80116B54
/* AD050 80116950 26520001 */   addiu    $s2, $s2, 1
/* AD054 80116954 96030000 */  lhu       $v1, ($s0)
/* AD058 80116958 5060007E */  beql      $v1, $zero, .L80116B54
/* AD05C 8011695C 26520001 */   addiu    $s2, $s2, 1
/* AD060 80116960 30620004 */  andi      $v0, $v1, 4
/* AD064 80116964 5440007B */  bnel      $v0, $zero, .L80116B54
/* AD068 80116968 26520001 */   addiu    $s2, $s2, 1
/* AD06C 8011696C 30621000 */  andi      $v0, $v1, 0x1000
/* AD070 80116970 14400034 */  bnez      $v0, .L80116A44
/* AD074 80116974 24020002 */   addiu    $v0, $zero, 2
/* AD078 80116978 9202009F */  lbu       $v0, 0x9f($s0)
/* AD07C 8011697C 1040002E */  beqz      $v0, .L80116A38
/* AD080 80116980 2442FFFF */   addiu    $v0, $v0, -1
/* AD084 80116984 A202009F */  sb        $v0, 0x9f($s0)
/* AD088 80116988 304200FF */  andi      $v0, $v0, 0xff
/* AD08C 8011698C 1440000F */  bnez      $v0, .L801169CC
/* AD090 80116990 00000000 */   nop
/* AD094 80116994 8E02000C */  lw        $v0, 0xc($s0)
/* AD098 80116998 26030010 */  addiu     $v1, $s0, 0x10
/* AD09C 8011699C 24440040 */  addiu     $a0, $v0, 0x40
.L801169A0:
/* AD0A0 801169A0 8C480000 */  lw        $t0, ($v0)
/* AD0A4 801169A4 8C490004 */  lw        $t1, 4($v0)
/* AD0A8 801169A8 8C4A0008 */  lw        $t2, 8($v0)
/* AD0AC 801169AC 8C4B000C */  lw        $t3, 0xc($v0)
/* AD0B0 801169B0 AC680000 */  sw        $t0, ($v1)
/* AD0B4 801169B4 AC690004 */  sw        $t1, 4($v1)
/* AD0B8 801169B8 AC6A0008 */  sw        $t2, 8($v1)
/* AD0BC 801169BC AC6B000C */  sw        $t3, 0xc($v1)
/* AD0C0 801169C0 24420010 */  addiu     $v0, $v0, 0x10
/* AD0C4 801169C4 1444FFF6 */  bne       $v0, $a0, .L801169A0
/* AD0C8 801169C8 24630010 */   addiu    $v1, $v1, 0x10
.L801169CC:
/* AD0CC 801169CC 96820000 */  lhu       $v0, ($s4)
/* AD0D0 801169D0 8E11000C */  lw        $s1, 0xc($s0)
/* AD0D4 801169D4 3C04800A */  lui       $a0, %hi(gDisplayContext)
/* AD0D8 801169D8 8C84A674 */  lw        $a0, %lo(gDisplayContext)($a0)
/* AD0DC 801169DC 3043FFFF */  andi      $v1, $v0, 0xffff
/* AD0E0 801169E0 00031980 */  sll       $v1, $v1, 6
/* AD0E4 801169E4 00751821 */  addu      $v1, $v1, $s5
/* AD0E8 801169E8 00832021 */  addu      $a0, $a0, $v1
/* AD0EC 801169EC 0080182D */  daddu     $v1, $a0, $zero
/* AD0F0 801169F0 0220202D */  daddu     $a0, $s1, $zero
/* AD0F4 801169F4 24850040 */  addiu     $a1, $a0, 0x40
/* AD0F8 801169F8 24420001 */  addiu     $v0, $v0, 1
/* AD0FC 801169FC A6820000 */  sh        $v0, ($s4)
/* AD100 80116A00 AE03000C */  sw        $v1, 0xc($s0)
.L80116A04:
/* AD104 80116A04 8C880000 */  lw        $t0, ($a0)
/* AD108 80116A08 8C890004 */  lw        $t1, 4($a0)
/* AD10C 80116A0C 8C8A0008 */  lw        $t2, 8($a0)
/* AD110 80116A10 8C8B000C */  lw        $t3, 0xc($a0)
/* AD114 80116A14 AC680000 */  sw        $t0, ($v1)
/* AD118 80116A18 AC690004 */  sw        $t1, 4($v1)
/* AD11C 80116A1C AC6A0008 */  sw        $t2, 8($v1)
/* AD120 80116A20 AC6B000C */  sw        $t3, 0xc($v1)
/* AD124 80116A24 24840010 */  addiu     $a0, $a0, 0x10
/* AD128 80116A28 1485FFF6 */  bne       $a0, $a1, .L80116A04
/* AD12C 80116A2C 24630010 */   addiu    $v1, $v1, 0x10
/* AD130 80116A30 08045AD5 */  j         .L80116B54
/* AD134 80116A34 26520001 */   addiu    $s2, $s2, 1
.L80116A38:
/* AD138 80116A38 26020010 */  addiu     $v0, $s0, 0x10
/* AD13C 80116A3C 08045AD4 */  j         .L80116B50
/* AD140 80116A40 AE02000C */   sw       $v0, 0xc($s0)
.L80116A44:
/* AD144 80116A44 A202009F */  sb        $v0, 0x9f($s0)
/* AD148 80116A48 3062EFFF */  andi      $v0, $v1, 0xefff
/* AD14C 80116A4C 96840000 */  lhu       $a0, ($s4)
/* AD150 80116A50 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* AD154 80116A54 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* AD158 80116A58 8E050004 */  lw        $a1, 4($s0)
/* AD15C 80116A5C A6020000 */  sh        $v0, ($s0)
/* AD160 80116A60 3082FFFF */  andi      $v0, $a0, 0xffff
/* AD164 80116A64 00021180 */  sll       $v0, $v0, 6
/* AD168 80116A68 00551021 */  addu      $v0, $v0, $s5
/* AD16C 80116A6C 00628821 */  addu      $s1, $v1, $v0
/* AD170 80116A70 24840001 */  addiu     $a0, $a0, 1
/* AD174 80116A74 14A00003 */  bnez      $a1, .L80116A84
/* AD178 80116A78 A6840000 */   sh       $a0, ($s4)
/* AD17C 80116A7C 08045AA8 */  j         .L80116AA0
/* AD180 80116A80 26040050 */   addiu    $a0, $s0, 0x50
.L80116A84:
/* AD184 80116A84 0C019D60 */  jal       guMtxL2F
/* AD188 80116A88 0260202D */   daddu    $a0, $s3, $zero
/* AD18C 80116A8C 26040050 */  addiu     $a0, $s0, 0x50
/* AD190 80116A90 0260282D */  daddu     $a1, $s3, $zero
/* AD194 80116A94 0C019D80 */  jal       guMtxCatF
/* AD198 80116A98 0260302D */   daddu    $a2, $s3, $zero
/* AD19C 80116A9C 0260202D */  daddu     $a0, $s3, $zero
.L80116AA0:
/* AD1A0 80116AA0 0C019D40 */  jal       guMtxF2L
/* AD1A4 80116AA4 0220282D */   daddu    $a1, $s1, $zero
/* AD1A8 80116AA8 24050061 */  addiu     $a1, $zero, 0x61
/* AD1AC 80116AAC 96020000 */  lhu       $v0, ($s0)
/* AD1B0 80116AB0 8E040008 */  lw        $a0, 8($s0)
/* AD1B4 80116AB4 3042DFFF */  andi      $v0, $v0, 0xdfff
/* AD1B8 80116AB8 0C0456C3 */  jal       get_model_property
/* AD1BC 80116ABC A6020000 */   sh       $v0, ($s0)
/* AD1C0 80116AC0 C4460008 */  lwc1      $f6, 8($v0)
/* AD1C4 80116AC4 C440002C */  lwc1      $f0, 0x2c($v0)
/* AD1C8 80116AC8 46003180 */  add.s     $f6, $f6, $f0
/* AD1CC 80116ACC 46143182 */  mul.s     $f6, $f6, $f20
/* AD1D0 80116AD0 00000000 */  nop
/* AD1D4 80116AD4 C4440014 */  lwc1      $f4, 0x14($v0)
/* AD1D8 80116AD8 C4400038 */  lwc1      $f0, 0x38($v0)
/* AD1DC 80116ADC 46002100 */  add.s     $f4, $f4, $f0
/* AD1E0 80116AE0 46142102 */  mul.s     $f4, $f4, $f20
/* AD1E4 80116AE4 00000000 */  nop
/* AD1E8 80116AE8 C4420020 */  lwc1      $f2, 0x20($v0)
/* AD1EC 80116AEC C4400044 */  lwc1      $f0, 0x44($v0)
/* AD1F0 80116AF0 46001080 */  add.s     $f2, $f2, $f0
/* AD1F4 80116AF4 46141082 */  mul.s     $f2, $f2, $f20
/* AD1F8 80116AF8 00000000 */  nop
/* AD1FC 80116AFC 0220202D */  daddu     $a0, $s1, $zero
/* AD200 80116B00 44053000 */  mfc1      $a1, $f6
/* AD204 80116B04 44062000 */  mfc1      $a2, $f4
/* AD208 80116B08 44071000 */  mfc1      $a3, $f2
/* AD20C 80116B0C 27A200AC */  addiu     $v0, $sp, 0xac
/* AD210 80116B10 AFA500AC */  sw        $a1, 0xac($sp)
/* AD214 80116B14 AFA600B0 */  sw        $a2, 0xb0($sp)
/* AD218 80116B18 AFA700B4 */  sw        $a3, 0xb4($sp)
/* AD21C 80116B1C AFA20010 */  sw        $v0, 0x10($sp)
/* AD220 80116B20 27A200B0 */  addiu     $v0, $sp, 0xb0
/* AD224 80116B24 AFA20014 */  sw        $v0, 0x14($sp)
/* AD228 80116B28 27A200B4 */  addiu     $v0, $sp, 0xb4
/* AD22C 80116B2C 0C019E78 */  jal       guMtxXFML
/* AD230 80116B30 AFA20018 */   sw       $v0, 0x18($sp)
/* AD234 80116B34 C7A000AC */  lwc1      $f0, 0xac($sp)
/* AD238 80116B38 C7A200B0 */  lwc1      $f2, 0xb0($sp)
/* AD23C 80116B3C C7A400B4 */  lwc1      $f4, 0xb4($sp)
/* AD240 80116B40 AE11000C */  sw        $s1, 0xc($s0)
/* AD244 80116B44 E6000090 */  swc1      $f0, 0x90($s0)
/* AD248 80116B48 E6020094 */  swc1      $f2, 0x94($s0)
/* AD24C 80116B4C E6040098 */  swc1      $f4, 0x98($s0)
.L80116B50:
/* AD250 80116B50 26520001 */  addiu     $s2, $s2, 1
.L80116B54:
/* AD254 80116B54 2A420004 */  slti      $v0, $s2, 4
/* AD258 80116B58 1440FF77 */  bnez      $v0, .L80116938
/* AD25C 80116B5C 00000000 */   nop
/* AD260 80116B60 0C046F3B */  jal       build_custom_gfx
/* AD264 80116B64 00000000 */   nop
/* AD268 80116B68 8FBF00D0 */  lw        $ra, 0xd0($sp)
/* AD26C 80116B6C 8FB500CC */  lw        $s5, 0xcc($sp)
/* AD270 80116B70 8FB400C8 */  lw        $s4, 0xc8($sp)
/* AD274 80116B74 8FB300C4 */  lw        $s3, 0xc4($sp)
/* AD278 80116B78 8FB200C0 */  lw        $s2, 0xc0($sp)
/* AD27C 80116B7C 8FB100BC */  lw        $s1, 0xbc($sp)
/* AD280 80116B80 8FB000B8 */  lw        $s0, 0xb8($sp)
/* AD284 80116B84 D7B400D8 */  ldc1      $f20, 0xd8($sp)
/* AD288 80116B88 03E00008 */  jr        $ra
/* AD28C 80116B8C 27BD00E0 */   addiu    $sp, $sp, 0xe0
