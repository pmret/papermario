.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80035384
/* 10784 80035384 3C03800A */  lui       $v1, %hi(D_8009E741)
/* 10788 80035388 8063E741 */  lb        $v1, %lo(D_8009E741)($v1)
/* 1078C 8003538C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 10790 80035390 AFBF0024 */  sw        $ra, 0x24($sp)
/* 10794 80035394 AFB20020 */  sw        $s2, 0x20($sp)
/* 10798 80035398 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1079C 8003539C 2C620005 */  sltiu     $v0, $v1, 5
/* 107A0 800353A0 10400101 */  beqz      $v0, .L800357A8
/* 107A4 800353A4 AFB00018 */   sw       $s0, 0x18($sp)
/* 107A8 800353A8 00031080 */  sll       $v0, $v1, 2
/* 107AC 800353AC 3C01800A */  lui       $at, %hi(D_800982C8)
/* 107B0 800353B0 00220821 */  addu      $at, $at, $v0
/* 107B4 800353B4 8C2282C8 */  lw        $v0, %lo(D_800982C8)($at)
/* 107B8 800353B8 00400008 */  jr        $v0
/* 107BC 800353BC 00000000 */   nop
/* 107C0 800353C0 3C10800A */  lui       $s0, %hi(D_8009E742)
/* 107C4 800353C4 2610E742 */  addiu     $s0, $s0, %lo(D_8009E742)
/* 107C8 800353C8 86020000 */  lh        $v0, ($s0)
/* 107CC 800353CC 96030000 */  lhu       $v1, ($s0)
/* 107D0 800353D0 1040000F */  beqz      $v0, .L80035410
/* 107D4 800353D4 2462FFEC */   addiu    $v0, $v1, -0x14
/* 107D8 800353D8 A6020000 */  sh        $v0, ($s0)
/* 107DC 800353DC 00021400 */  sll       $v0, $v0, 0x10
/* 107E0 800353E0 04420001 */  bltzl     $v0, .L800353E8
/* 107E4 800353E4 A6000000 */   sh       $zero, ($s0)
.L800353E8:
/* 107E8 800353E8 86020000 */  lh        $v0, ($s0)
/* 107EC 800353EC 44820000 */  mtc1      $v0, $f0
/* 107F0 800353F0 00000000 */  nop
/* 107F4 800353F4 46800020 */  cvt.s.w   $f0, $f0
/* 107F8 800353F8 44050000 */  mfc1      $a1, $f0
/* 107FC 800353FC 0C04F38E */  jal       func_8013CE38
/* 10800 80035400 0000202D */   daddu    $a0, $zero, $zero
/* 10804 80035404 86020000 */  lh        $v0, ($s0)
/* 10808 80035408 144000E7 */  bnez      $v0, .L800357A8
/* 1080C 8003540C 00000000 */   nop
.L80035410:
/* 10810 80035410 24020001 */  addiu     $v0, $zero, 1
/* 10814 80035414 3C01800A */  lui       $at, %hi(D_8009E741)
/* 10818 80035418 A022E741 */  sb        $v0, %lo(D_8009E741)($at)
/* 1081C 8003541C 0800D5EA */  j         .L800357A8
/* 10820 80035420 00000000 */   nop
/* 10824 80035424 3C10800A */  lui       $s0, %hi(D_8009E742)
/* 10828 80035428 2610E742 */  addiu     $s0, $s0, %lo(D_8009E742)
/* 1082C 8003542C 241100FF */  addiu     $s1, $zero, 0xff
/* 10830 80035430 86020000 */  lh        $v0, ($s0)
/* 10834 80035434 96030000 */  lhu       $v1, ($s0)
/* 10838 80035438 10510011 */  beq       $v0, $s1, .L80035480
/* 1083C 8003543C 24620014 */   addiu    $v0, $v1, 0x14
/* 10840 80035440 A6020000 */  sh        $v0, ($s0)
/* 10844 80035444 00021400 */  sll       $v0, $v0, 0x10
/* 10848 80035448 00021403 */  sra       $v0, $v0, 0x10
/* 1084C 8003544C 28420100 */  slti      $v0, $v0, 0x100
/* 10850 80035450 50400001 */  beql      $v0, $zero, .L80035458
/* 10854 80035454 A6110000 */   sh       $s1, ($s0)
.L80035458:
/* 10858 80035458 86020000 */  lh        $v0, ($s0)
/* 1085C 8003545C 44820000 */  mtc1      $v0, $f0
/* 10860 80035460 00000000 */  nop
/* 10864 80035464 46800020 */  cvt.s.w   $f0, $f0
/* 10868 80035468 44050000 */  mfc1      $a1, $f0
/* 1086C 8003546C 0C04F38E */  jal       func_8013CE38
/* 10870 80035470 0000202D */   daddu    $a0, $zero, $zero
/* 10874 80035474 86020000 */  lh        $v0, ($s0)
/* 10878 80035478 145100CB */  bne       $v0, $s1, .L800357A8
/* 1087C 8003547C 00000000 */   nop
.L80035480:
/* 10880 80035480 24020002 */  addiu     $v0, $zero, 2
/* 10884 80035484 3C01800A */  lui       $at, %hi(D_8009E741)
/* 10888 80035488 A022E741 */  sb        $v0, %lo(D_8009E741)($at)
/* 1088C 8003548C 0800D5EA */  j         .L800357A8
/* 10890 80035490 00000000 */   nop
/* 10894 80035494 3C06800A */  lui       $a2, %hi(D_8009E740)
/* 10898 80035498 24C6E740 */  addiu     $a2, $a2, %lo(D_8009E740)
/* 1089C 8003549C 80C30000 */  lb        $v1, ($a2)
/* 108A0 800354A0 24020003 */  addiu     $v0, $zero, 3
/* 108A4 800354A4 14620006 */  bne       $v1, $v0, .L800354C0
/* 108A8 800354A8 00000000 */   nop
/* 108AC 800354AC 3C03800A */  lui       $v1, %hi(D_8009A630)
/* 108B0 800354B0 2463A630 */  addiu     $v1, $v1, %lo(D_8009A630)
/* 108B4 800354B4 8C620000 */  lw        $v0, ($v1)
/* 108B8 800354B8 34420008 */  ori       $v0, $v0, 8
/* 108BC 800354BC AC620000 */  sw        $v0, ($v1)
.L800354C0:
/* 108C0 800354C0 80C20000 */  lb        $v0, ($a2)
/* 108C4 800354C4 90C30000 */  lbu       $v1, ($a2)
/* 108C8 800354C8 044000B7 */  bltz      $v0, .L800357A8
/* 108CC 800354CC 2462FFFF */   addiu    $v0, $v1, -1
/* 108D0 800354D0 A0C20000 */  sb        $v0, ($a2)
/* 108D4 800354D4 00021600 */  sll       $v0, $v0, 0x18
/* 108D8 800354D8 14400067 */  bnez      $v0, .L80035678
/* 108DC 800354DC 24050003 */   addiu    $a1, $zero, 3
/* 108E0 800354E0 3C048007 */  lui       $a0, %hi(D_80077950)
/* 108E4 800354E4 24847950 */  addiu     $a0, $a0, %lo(D_80077950)
/* 108E8 800354E8 2402FFFF */  addiu     $v0, $zero, -1
/* 108EC 800354EC 0C017BE8 */  jal       func_8005EFA0
/* 108F0 800354F0 A0C20000 */   sb       $v0, ($a2)
/* 108F4 800354F4 0C0910B4 */  jal       func_802442D0
/* 108F8 800354F8 00000000 */   nop
/* 108FC 800354FC 3C04800A */  lui       $a0, %hi(D_8009A630)
/* 10900 80035500 2484A630 */  addiu     $a0, $a0, %lo(D_8009A630)
/* 10904 80035504 8C820000 */  lw        $v0, ($a0)
/* 10908 80035508 2403FFF7 */  addiu     $v1, $zero, -9
/* 1090C 8003550C 00431024 */  and       $v0, $v0, $v1
/* 10910 80035510 0C016A28 */  jal       func_8005A8A0
/* 10914 80035514 AC820000 */   sw       $v0, ($a0)
/* 10918 80035518 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 1091C 8003551C 2610417C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 10920 80035520 8E040000 */  lw        $a0, ($s0)
/* 10924 80035524 84830086 */  lh        $v1, 0x86($a0)
/* 10928 80035528 00031900 */  sll       $v1, $v1, 4
/* 1092C 8003552C 3C058009 */  lui       $a1, %hi(D_800934C4)
/* 10930 80035530 00A32821 */  addu      $a1, $a1, $v1
/* 10934 80035534 8CA534C4 */  lw        $a1, %lo(D_800934C4)($a1)
/* 10938 80035538 8483008C */  lh        $v1, 0x8c($a0)
/* 1093C 8003553C 0040902D */  daddu     $s2, $v0, $zero
/* 10940 80035540 A0800070 */  sb        $zero, 0x70($a0)
/* 10944 80035544 00031940 */  sll       $v1, $v1, 5
/* 10948 80035548 0C016B0D */  jal       func_8005AC34
/* 1094C 8003554C 00A38821 */   addu     $s1, $a1, $v1
/* 10950 80035550 0C00AB27 */  jal       func_8002AC9C
/* 10954 80035554 00000000 */   nop
/* 10958 80035558 0C0539C8 */  jal       func_8014E720
/* 1095C 8003555C 24040001 */   addiu    $a0, $zero, 1
/* 10960 80035560 8E020000 */  lw        $v0, ($s0)
/* 10964 80035564 0C044512 */  jal       func_80111448
/* 10968 80035568 80440084 */   lb       $a0, 0x84($v0)
/* 1096C 8003556C 0C046C7E */  jal       func_8011B1F8
/* 10970 80035570 00000000 */   nop
/* 10974 80035574 0C053468 */  jal       func_8014D1A0
/* 10978 80035578 00000000 */   nop
/* 1097C 8003557C 0C04979A */  jal       func_80125E68
/* 10980 80035580 00000000 */   nop
/* 10984 80035584 0C048D48 */  jal       func_80123520
/* 10988 80035588 00000000 */   nop
/* 1098C 8003558C 0C04A0C9 */  jal       func_80128324
/* 10990 80035590 00000000 */   nop
/* 10994 80035594 0000202D */  daddu     $a0, $zero, $zero
/* 10998 80035598 0C0528E6 */  jal       func_8014A398
/* 1099C 8003559C 0080282D */   daddu    $a1, $a0, $zero
/* 109A0 800355A0 0C0518EC */  jal       func_801463B0
/* 109A4 800355A4 00000000 */   nop
/* 109A8 800355A8 0C04D891 */  jal       func_80136244
/* 109AC 800355AC 00000000 */   nop
/* 109B0 800355B0 0C0B0CBB */  jal       func_802C32EC
/* 109B4 800355B4 00000000 */   nop
/* 109B8 800355B8 0C00E07B */  jal       func_800381EC
/* 109BC 800355BC 00000000 */   nop
/* 109C0 800355C0 0C04581A */  jal       func_80116068
/* 109C4 800355C4 00000000 */   nop
/* 109C8 800355C8 0C0529F6 */  jal       func_8014A7D8
/* 109CC 800355CC 00000000 */   nop
/* 109D0 800355D0 3C04800E */  lui       $a0, %hi(D_800D9210)
/* 109D4 800355D4 24849210 */  addiu     $a0, $a0, %lo(D_800D9210)
/* 109D8 800355D8 0C016A68 */  jal       func_8005A9A0
/* 109DC 800355DC 27A50010 */   addiu    $a1, $sp, 0x10
/* 109E0 800355E0 0040802D */  daddu     $s0, $v0, $zero
/* 109E4 800355E4 3C058021 */  lui       $a1, %hi(D_80210000)
/* 109E8 800355E8 24A50000 */  addiu     $a1, $a1, %lo(D_80210000)
/* 109EC 800355EC 0C01BB74 */  jal       func_8006EDD0
/* 109F0 800355F0 0200202D */   daddu    $a0, $s0, $zero
/* 109F4 800355F4 0C00AB0E */  jal       func_8002AC38
/* 109F8 800355F8 0200202D */   daddu    $a0, $s0, $zero
/* 109FC 800355FC 0C016B11 */  jal       func_8005AC44
/* 10A00 80035600 00000000 */   nop
/* 10A04 80035604 0C016B42 */  jal       func_8005AD08
/* 10A08 80035608 00000000 */   nop
/* 10A0C 8003560C 8E240008 */  lw        $a0, 8($s1)
/* 10A10 80035610 10800004 */  beqz      $a0, .L80035624
/* 10A14 80035614 00000000 */   nop
/* 10A18 80035618 8E25000C */  lw        $a1, 0xc($s1)
/* 10A1C 8003561C 0C00A5BF */  jal       func_800296FC
/* 10A20 80035620 8E260010 */   lw       $a2, 0x10($s1)
.L80035624:
/* 10A24 80035624 0C052B88 */  jal       func_8014AE20
/* 10A28 80035628 8E240014 */   lw       $a0, 0x14($s1)
/* 10A2C 8003562C 8E440038 */  lw        $a0, 0x38($s2)
/* 10A30 80035630 50800005 */  beql      $a0, $zero, .L80035648
/* 10A34 80035634 24040128 */   addiu    $a0, $zero, 0x128
/* 10A38 80035638 0C052BB6 */  jal       func_8014AED8
/* 10A3C 8003563C 00000000 */   nop
/* 10A40 80035640 0800D596 */  j         .L80035658
/* 10A44 80035644 00000000 */   nop
.L80035648:
/* 10A48 80035648 240500C8 */  addiu     $a1, $zero, 0xc8
/* 10A4C 8003564C 2406000C */  addiu     $a2, $zero, 0xc
/* 10A50 80035650 0C052BC8 */  jal       func_8014AF20
/* 10A54 80035654 24070014 */   addiu    $a3, $zero, 0x14
.L80035658:
/* 10A58 80035658 0C046CCF */  jal       func_8011B33C
/* 10A5C 8003565C 00000000 */   nop
/* 10A60 80035660 0C00EB9C */  jal       func_8003AE70
/* 10A64 80035664 00000000 */   nop
/* 10A68 80035668 0C03A619 */  jal       func_800E9864
/* 10A6C 8003566C 00000000 */   nop
/* 10A70 80035670 0C009C15 */  jal       func_80027054
/* 10A74 80035674 24040001 */   addiu    $a0, $zero, 1
.L80035678:
/* 10A78 80035678 0C0533DD */  jal       func_8014CF74
/* 10A7C 8003567C 0000202D */   daddu    $a0, $zero, $zero
/* 10A80 80035680 24020003 */  addiu     $v0, $zero, 3
/* 10A84 80035684 3C01800A */  lui       $at, %hi(D_8009E741)
/* 10A88 80035688 A022E741 */  sb        $v0, %lo(D_8009E741)($at)
/* 10A8C 8003568C 0C037DC8 */  jal       func_800DF720
/* 10A90 80035690 00000000 */   nop
/* 10A94 80035694 0C00E57C */  jal       func_800395F0
/* 10A98 80035698 00000000 */   nop
/* 10A9C 8003569C 0C00F879 */  jal       func_8003E1E4
/* 10AA0 800356A0 00000000 */   nop
/* 10AA4 800356A4 0C016680 */  jal       func_80059A00
/* 10AA8 800356A8 00000000 */   nop
/* 10AAC 800356AC 3C03800A */  lui       $v1, %hi(D_8009E742)
/* 10AB0 800356B0 2463E742 */  addiu     $v1, $v1, %lo(D_8009E742)
/* 10AB4 800356B4 94620000 */  lhu       $v0, ($v1)
/* 10AB8 800356B8 2442FFEC */  addiu     $v0, $v0, -0x14
/* 10ABC 800356BC A4620000 */  sh        $v0, ($v1)
/* 10AC0 800356C0 00021400 */  sll       $v0, $v0, 0x10
/* 10AC4 800356C4 04420001 */  bltzl     $v0, .L800356CC
/* 10AC8 800356C8 A4600000 */   sh       $zero, ($v1)
.L800356CC:
/* 10ACC 800356CC 84620000 */  lh        $v0, ($v1)
/* 10AD0 800356D0 44820000 */  mtc1      $v0, $f0
/* 10AD4 800356D4 00000000 */  nop
/* 10AD8 800356D8 46800020 */  cvt.s.w   $f0, $f0
/* 10ADC 800356DC 44050000 */  mfc1      $a1, $f0
/* 10AE0 800356E0 0800D5E8 */  j         .L800357A0
/* 10AE4 800356E4 0000202D */   daddu    $a0, $zero, $zero
/* 10AE8 800356E8 0C037DC8 */  jal       func_800DF720
/* 10AEC 800356EC 00000000 */   nop
/* 10AF0 800356F0 0C00E57C */  jal       func_800395F0
/* 10AF4 800356F4 00000000 */   nop
/* 10AF8 800356F8 0C00F879 */  jal       func_8003E1E4
/* 10AFC 800356FC 00000000 */   nop
/* 10B00 80035700 0C016680 */  jal       func_80059A00
/* 10B04 80035704 00000000 */   nop
/* 10B08 80035708 3C04800A */  lui       $a0, %hi(D_8009E742)
/* 10B0C 8003570C 2484E742 */  addiu     $a0, $a0, %lo(D_8009E742)
/* 10B10 80035710 84820000 */  lh        $v0, ($a0)
/* 10B14 80035714 94830000 */  lhu       $v1, ($a0)
/* 10B18 80035718 14400006 */  bnez      $v0, .L80035734
/* 10B1C 8003571C 2462FFEC */   addiu    $v0, $v1, -0x14
/* 10B20 80035720 24020004 */  addiu     $v0, $zero, 4
/* 10B24 80035724 3C01800A */  lui       $at, %hi(D_8009E741)
/* 10B28 80035728 A022E741 */  sb        $v0, %lo(D_8009E741)($at)
/* 10B2C 8003572C 0800D5EA */  j         .L800357A8
/* 10B30 80035730 00000000 */   nop
.L80035734:
/* 10B34 80035734 A4820000 */  sh        $v0, ($a0)
/* 10B38 80035738 00021400 */  sll       $v0, $v0, 0x10
/* 10B3C 8003573C 04420001 */  bltzl     $v0, .L80035744
/* 10B40 80035740 A4800000 */   sh       $zero, ($a0)
.L80035744:
/* 10B44 80035744 84820000 */  lh        $v0, ($a0)
/* 10B48 80035748 44820000 */  mtc1      $v0, $f0
/* 10B4C 8003574C 00000000 */  nop
/* 10B50 80035750 46800020 */  cvt.s.w   $f0, $f0
/* 10B54 80035754 44050000 */  mfc1      $a1, $f0
/* 10B58 80035758 0800D5E8 */  j         .L800357A0
/* 10B5C 8003575C 0000202D */   daddu    $a0, $zero, $zero
/* 10B60 80035760 0C009C15 */  jal       func_80027054
/* 10B64 80035764 0000202D */   daddu    $a0, $zero, $zero
/* 10B68 80035768 0C037DC8 */  jal       func_800DF720
/* 10B6C 8003576C 00000000 */   nop
/* 10B70 80035770 0C00E57C */  jal       func_800395F0
/* 10B74 80035774 00000000 */   nop
/* 10B78 80035778 0C00F879 */  jal       func_8003E1E4
/* 10B7C 8003577C 00000000 */   nop
/* 10B80 80035780 0C016680 */  jal       func_80059A00
/* 10B84 80035784 00000000 */   nop
/* 10B88 80035788 0C038061 */  jal       func_800E0184
/* 10B8C 8003578C 00000000 */   nop
/* 10B90 80035790 0C00CC60 */  jal       func_80033180
/* 10B94 80035794 24040004 */   addiu    $a0, $zero, 4
/* 10B98 80035798 3C05BF80 */  lui       $a1, 0xbf80
/* 10B9C 8003579C 240400FF */  addiu     $a0, $zero, 0xff
.L800357A0:
/* 10BA0 800357A0 0C04F38E */  jal       func_8013CE38
/* 10BA4 800357A4 00000000 */   nop
.L800357A8:
/* 10BA8 800357A8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 10BAC 800357AC 8FB20020 */  lw        $s2, 0x20($sp)
/* 10BB0 800357B0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 10BB4 800357B4 8FB00018 */  lw        $s0, 0x18($sp)
/* 10BB8 800357B8 03E00008 */  jr        $ra
/* 10BBC 800357BC 27BD0028 */   addiu    $sp, $sp, 0x28
