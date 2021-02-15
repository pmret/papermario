.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424D8_CD97B8
/* CD97B8 802424D8 27BDFF90 */  addiu     $sp, $sp, -0x70
/* CD97BC 802424DC AFB3005C */  sw        $s3, 0x5c($sp)
/* CD97C0 802424E0 0080982D */  daddu     $s3, $a0, $zero
/* CD97C4 802424E4 AFBF0068 */  sw        $ra, 0x68($sp)
/* CD97C8 802424E8 AFB50064 */  sw        $s5, 0x64($sp)
/* CD97CC 802424EC AFB40060 */  sw        $s4, 0x60($sp)
/* CD97D0 802424F0 AFB20058 */  sw        $s2, 0x58($sp)
/* CD97D4 802424F4 AFB10054 */  sw        $s1, 0x54($sp)
/* CD97D8 802424F8 AFB00050 */  sw        $s0, 0x50($sp)
/* CD97DC 802424FC 8E710148 */  lw        $s1, 0x148($s3)
/* CD97E0 80242500 86240008 */  lh        $a0, 8($s1)
/* CD97E4 80242504 0C00EABB */  jal       get_npc_unsafe
/* CD97E8 80242508 00A0802D */   daddu    $s0, $a1, $zero
/* CD97EC 8024250C 8E63000C */  lw        $v1, 0xc($s3)
/* CD97F0 80242510 0260202D */  daddu     $a0, $s3, $zero
/* CD97F4 80242514 8C650000 */  lw        $a1, ($v1)
/* CD97F8 80242518 0C0B1EAF */  jal       get_variable
/* CD97FC 8024251C 0040902D */   daddu    $s2, $v0, $zero
/* CD9800 80242520 AFA00028 */  sw        $zero, 0x28($sp)
/* CD9804 80242524 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CD9808 80242528 8C630030 */  lw        $v1, 0x30($v1)
/* CD980C 8024252C AFA3002C */  sw        $v1, 0x2c($sp)
/* CD9810 80242530 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CD9814 80242534 8C63001C */  lw        $v1, 0x1c($v1)
/* CD9818 80242538 AFA30030 */  sw        $v1, 0x30($sp)
/* CD981C 8024253C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CD9820 80242540 8C630024 */  lw        $v1, 0x24($v1)
/* CD9824 80242544 AFA30034 */  sw        $v1, 0x34($sp)
/* CD9828 80242548 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CD982C 8024254C 8C630028 */  lw        $v1, 0x28($v1)
/* CD9830 80242550 27B50028 */  addiu     $s5, $sp, 0x28
/* CD9834 80242554 AFA30038 */  sw        $v1, 0x38($sp)
/* CD9838 80242558 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CD983C 8024255C 3C0142C8 */  lui       $at, 0x42c8
/* CD9840 80242560 44810000 */  mtc1      $at, $f0
/* CD9844 80242564 8C63002C */  lw        $v1, 0x2c($v1)
/* CD9848 80242568 0040A02D */  daddu     $s4, $v0, $zero
/* CD984C 8024256C E7A00040 */  swc1      $f0, 0x40($sp)
/* CD9850 80242570 A7A00044 */  sh        $zero, 0x44($sp)
/* CD9854 80242574 12000009 */  beqz      $s0, .L8024259C
/* CD9858 80242578 AFA3003C */   sw       $v1, 0x3c($sp)
/* CD985C 8024257C 864300A8 */  lh        $v1, 0xa8($s2)
/* CD9860 80242580 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CD9864 80242584 AE20008C */  sw        $zero, 0x8c($s1)
/* CD9868 80242588 A22000B5 */  sb        $zero, 0xb5($s1)
/* CD986C 8024258C 34420008 */  ori       $v0, $v0, 8
/* CD9870 80242590 AE230084 */  sw        $v1, 0x84($s1)
/* CD9874 80242594 0809096B */  j         .L802425AC
/* CD9878 80242598 AE2200B0 */   sw       $v0, 0xb0($s1)
.L8024259C:
/* CD987C 8024259C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CD9880 802425A0 30420004 */  andi      $v0, $v0, 4
/* CD9884 802425A4 10400047 */  beqz      $v0, .L802426C4
/* CD9888 802425A8 00000000 */   nop
.L802425AC:
/* CD988C 802425AC AE600070 */  sw        $zero, 0x70($s3)
/* CD9890 802425B0 A640008E */  sh        $zero, 0x8e($s2)
/* CD9894 802425B4 8E2300CC */  lw        $v1, 0xcc($s1)
/* CD9898 802425B8 2404F7FF */  addiu     $a0, $zero, -0x801
/* CD989C 802425BC A2200007 */  sb        $zero, 7($s1)
/* CD98A0 802425C0 8E420000 */  lw        $v0, ($s2)
/* CD98A4 802425C4 8C630000 */  lw        $v1, ($v1)
/* CD98A8 802425C8 00441024 */  and       $v0, $v0, $a0
/* CD98AC 802425CC AE420000 */  sw        $v0, ($s2)
/* CD98B0 802425D0 AE430028 */  sw        $v1, 0x28($s2)
/* CD98B4 802425D4 96220086 */  lhu       $v0, 0x86($s1)
/* CD98B8 802425D8 A64200A8 */  sh        $v0, 0xa8($s2)
/* CD98BC 802425DC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CD98C0 802425E0 AE200090 */  sw        $zero, 0x90($s1)
/* CD98C4 802425E4 8C420034 */  lw        $v0, 0x34($v0)
/* CD98C8 802425E8 14400006 */  bnez      $v0, .L80242604
/* CD98CC 802425EC 2403FDFF */   addiu    $v1, $zero, -0x201
/* CD98D0 802425F0 8E420000 */  lw        $v0, ($s2)
/* CD98D4 802425F4 2403FFF7 */  addiu     $v1, $zero, -9
/* CD98D8 802425F8 34420200 */  ori       $v0, $v0, 0x200
/* CD98DC 802425FC 08090984 */  j         .L80242610
/* CD98E0 80242600 00431024 */   and      $v0, $v0, $v1
.L80242604:
/* CD98E4 80242604 8E420000 */  lw        $v0, ($s2)
/* CD98E8 80242608 00431024 */  and       $v0, $v0, $v1
/* CD98EC 8024260C 34420008 */  ori       $v0, $v0, 8
.L80242610:
/* CD98F0 80242610 AE420000 */  sw        $v0, ($s2)
/* CD98F4 80242614 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CD98F8 80242618 30420004 */  andi      $v0, $v0, 4
/* CD98FC 8024261C 1040001E */  beqz      $v0, .L80242698
/* CD9900 80242620 24040002 */   addiu    $a0, $zero, 2
/* CD9904 80242624 0240282D */  daddu     $a1, $s2, $zero
/* CD9908 80242628 0000302D */  daddu     $a2, $zero, $zero
/* CD990C 8024262C 24020063 */  addiu     $v0, $zero, 0x63
/* CD9910 80242630 AE620070 */  sw        $v0, 0x70($s3)
/* CD9914 80242634 AE600074 */  sw        $zero, 0x74($s3)
/* CD9918 80242638 864300A8 */  lh        $v1, 0xa8($s2)
/* CD991C 8024263C 3C013F80 */  lui       $at, 0x3f80
/* CD9920 80242640 44810000 */  mtc1      $at, $f0
/* CD9924 80242644 3C014000 */  lui       $at, 0x4000
/* CD9928 80242648 44811000 */  mtc1      $at, $f2
/* CD992C 8024264C 3C01C1A0 */  lui       $at, 0xc1a0
/* CD9930 80242650 44812000 */  mtc1      $at, $f4
/* CD9934 80242654 24020028 */  addiu     $v0, $zero, 0x28
/* CD9938 80242658 AFA2001C */  sw        $v0, 0x1c($sp)
/* CD993C 8024265C 44833000 */  mtc1      $v1, $f6
/* CD9940 80242660 00000000 */  nop
/* CD9944 80242664 468031A0 */  cvt.s.w   $f6, $f6
/* CD9948 80242668 44073000 */  mfc1      $a3, $f6
/* CD994C 8024266C 27A20048 */  addiu     $v0, $sp, 0x48
/* CD9950 80242670 AFA20020 */  sw        $v0, 0x20($sp)
/* CD9954 80242674 E7A00010 */  swc1      $f0, 0x10($sp)
/* CD9958 80242678 E7A20014 */  swc1      $f2, 0x14($sp)
/* CD995C 8024267C 0C01BFA4 */  jal       fx_emote
/* CD9960 80242680 E7A40018 */   swc1     $f4, 0x18($sp)
/* CD9964 80242684 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CD9968 80242688 2403FFFB */  addiu     $v1, $zero, -5
/* CD996C 8024268C 00431024 */  and       $v0, $v0, $v1
/* CD9970 80242690 080909B1 */  j         .L802426C4
/* CD9974 80242694 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80242698:
/* CD9978 80242698 8E220000 */  lw        $v0, ($s1)
/* CD997C 8024269C 3C034000 */  lui       $v1, 0x4000
/* CD9980 802426A0 00431024 */  and       $v0, $v0, $v1
/* CD9984 802426A4 10400007 */  beqz      $v0, .L802426C4
/* CD9988 802426A8 3C03BFFF */   lui      $v1, 0xbfff
/* CD998C 802426AC 2402000C */  addiu     $v0, $zero, 0xc
/* CD9990 802426B0 AE620070 */  sw        $v0, 0x70($s3)
/* CD9994 802426B4 8E220000 */  lw        $v0, ($s1)
/* CD9998 802426B8 3463FFFF */  ori       $v1, $v1, 0xffff
/* CD999C 802426BC 00431024 */  and       $v0, $v0, $v1
/* CD99A0 802426C0 AE220000 */  sw        $v0, ($s1)
.L802426C4:
/* CD99A4 802426C4 8E220090 */  lw        $v0, 0x90($s1)
/* CD99A8 802426C8 1840000C */  blez      $v0, .L802426FC
/* CD99AC 802426CC 2442FFFF */   addiu    $v0, $v0, -1
/* CD99B0 802426D0 14400087 */  bnez      $v0, .L802428F0
/* CD99B4 802426D4 AE220090 */   sw       $v0, 0x90($s1)
/* CD99B8 802426D8 3C03FFAA */  lui       $v1, 0xffaa
/* CD99BC 802426DC 8E420028 */  lw        $v0, 0x28($s2)
/* CD99C0 802426E0 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* CD99C4 802426E4 00431021 */  addu      $v0, $v0, $v1
/* CD99C8 802426E8 2C420002 */  sltiu     $v0, $v0, 2
/* CD99CC 802426EC 10400003 */  beqz      $v0, .L802426FC
/* CD99D0 802426F0 3C020055 */   lui      $v0, 0x55
/* CD99D4 802426F4 3442000C */  ori       $v0, $v0, 0xc
/* CD99D8 802426F8 AE420028 */  sw        $v0, 0x28($s2)
.L802426FC:
/* CD99DC 802426FC 8E630070 */  lw        $v1, 0x70($s3)
/* CD99E0 80242700 2402000C */  addiu     $v0, $zero, 0xc
/* CD99E4 80242704 10620048 */  beq       $v1, $v0, .L80242828
/* CD99E8 80242708 2862000D */   slti     $v0, $v1, 0xd
/* CD99EC 8024270C 1040000F */  beqz      $v0, .L8024274C
/* CD99F0 80242710 24100001 */   addiu    $s0, $zero, 1
/* CD99F4 80242714 1070001E */  beq       $v1, $s0, .L80242790
/* CD99F8 80242718 28620002 */   slti     $v0, $v1, 2
/* CD99FC 8024271C 10400005 */  beqz      $v0, .L80242734
/* CD9A00 80242720 24020002 */   addiu    $v0, $zero, 2
/* CD9A04 80242724 10600015 */  beqz      $v1, .L8024277C
/* CD9A08 80242728 0260202D */   daddu    $a0, $s3, $zero
/* CD9A0C 8024272C 08090A21 */  j         .L80242884
/* CD9A10 80242730 00000000 */   nop
.L80242734:
/* CD9A14 80242734 1062001C */  beq       $v1, $v0, .L802427A8
/* CD9A18 80242738 24020003 */   addiu    $v0, $zero, 3
/* CD9A1C 8024273C 10620035 */  beq       $v1, $v0, .L80242814
/* CD9A20 80242740 0260202D */   daddu    $a0, $s3, $zero
/* CD9A24 80242744 08090A21 */  j         .L80242884
/* CD9A28 80242748 00000000 */   nop
.L8024274C:
/* CD9A2C 8024274C 2402000E */  addiu     $v0, $zero, 0xe
/* CD9A30 80242750 1062003F */  beq       $v1, $v0, .L80242850
/* CD9A34 80242754 0062102A */   slt      $v0, $v1, $v0
/* CD9A38 80242758 14400038 */  bnez      $v0, .L8024283C
/* CD9A3C 8024275C 0260202D */   daddu    $a0, $s3, $zero
/* CD9A40 80242760 2402000F */  addiu     $v0, $zero, 0xf
/* CD9A44 80242764 10620040 */  beq       $v1, $v0, .L80242868
/* CD9A48 80242768 24020063 */   addiu    $v0, $zero, 0x63
/* CD9A4C 8024276C 10620043 */  beq       $v1, $v0, .L8024287C
/* CD9A50 80242770 00000000 */   nop
/* CD9A54 80242774 08090A21 */  j         .L80242884
/* CD9A58 80242778 00000000 */   nop
.L8024277C:
/* CD9A5C 8024277C 0280282D */  daddu     $a1, $s4, $zero
/* CD9A60 80242780 0C012568 */  jal       func_800495A0
/* CD9A64 80242784 02A0302D */   daddu    $a2, $s5, $zero
/* CD9A68 80242788 96220086 */  lhu       $v0, 0x86($s1)
/* CD9A6C 8024278C A64200A8 */  sh        $v0, 0xa8($s2)
.L80242790:
/* CD9A70 80242790 0260202D */  daddu     $a0, $s3, $zero
/* CD9A74 80242794 0280282D */  daddu     $a1, $s4, $zero
/* CD9A78 80242798 0C0125AE */  jal       func_800496B8
/* CD9A7C 8024279C 02A0302D */   daddu    $a2, $s5, $zero
/* CD9A80 802427A0 08090A21 */  j         .L80242884
/* CD9A84 802427A4 00000000 */   nop
.L802427A8:
/* CD9A88 802427A8 0260202D */  daddu     $a0, $s3, $zero
/* CD9A8C 802427AC 0280282D */  daddu     $a1, $s4, $zero
/* CD9A90 802427B0 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* CD9A94 802427B4 02A0302D */   daddu    $a2, $s5, $zero
/* CD9A98 802427B8 8E230088 */  lw        $v1, 0x88($s1)
/* CD9A9C 802427BC 24020006 */  addiu     $v0, $zero, 6
/* CD9AA0 802427C0 14620014 */  bne       $v1, $v0, .L80242814
/* CD9AA4 802427C4 0260202D */   daddu    $a0, $s3, $zero
/* CD9AA8 802427C8 0C00A67F */  jal       rand_int
/* CD9AAC 802427CC 24040064 */   addiu    $a0, $zero, 0x64
/* CD9AB0 802427D0 28420021 */  slti      $v0, $v0, 0x21
/* CD9AB4 802427D4 5040000F */  beql      $v0, $zero, .L80242814
/* CD9AB8 802427D8 0260202D */   daddu    $a0, $s3, $zero
/* CD9ABC 802427DC 8E22008C */  lw        $v0, 0x8c($s1)
/* CD9AC0 802427E0 10400005 */  beqz      $v0, .L802427F8
/* CD9AC4 802427E4 3C020055 */   lui      $v0, 0x55
/* CD9AC8 802427E8 3442002F */  ori       $v0, $v0, 0x2f
/* CD9ACC 802427EC AE20008C */  sw        $zero, 0x8c($s1)
/* CD9AD0 802427F0 08090A01 */  j         .L80242804
/* CD9AD4 802427F4 A22000B5 */   sb       $zero, 0xb5($s1)
.L802427F8:
/* CD9AD8 802427F8 3442002E */  ori       $v0, $v0, 0x2e
/* CD9ADC 802427FC AE30008C */  sw        $s0, 0x8c($s1)
/* CD9AE0 80242800 A23000B5 */  sb        $s0, 0xb5($s1)
.L80242804:
/* CD9AE4 80242804 AE420028 */  sw        $v0, 0x28($s2)
/* CD9AE8 80242808 24020007 */  addiu     $v0, $zero, 7
/* CD9AEC 8024280C 08090A3C */  j         .L802428F0
/* CD9AF0 80242810 AE220090 */   sw       $v0, 0x90($s1)
.L80242814:
/* CD9AF4 80242814 0280282D */  daddu     $a1, $s4, $zero
/* CD9AF8 80242818 0C012701 */  jal       func_80049C04
/* CD9AFC 8024281C 02A0302D */   daddu    $a2, $s5, $zero
/* CD9B00 80242820 08090A21 */  j         .L80242884
/* CD9B04 80242824 00000000 */   nop
.L80242828:
/* CD9B08 80242828 0260202D */  daddu     $a0, $s3, $zero
/* CD9B0C 8024282C 0280282D */  daddu     $a1, $s4, $zero
/* CD9B10 80242830 0C090851 */  jal       flo_17_set_script_owner_npc_anim
/* CD9B14 80242834 02A0302D */   daddu    $a2, $s5, $zero
/* CD9B18 80242838 0260202D */  daddu     $a0, $s3, $zero
.L8024283C:
/* CD9B1C 8024283C 0280282D */  daddu     $a1, $s4, $zero
/* CD9B20 80242840 0C090870 */  jal       func_802421C0_CD94A0
/* CD9B24 80242844 02A0302D */   daddu    $a2, $s5, $zero
/* CD9B28 80242848 08090A21 */  j         .L80242884
/* CD9B2C 8024284C 00000000 */   nop
.L80242850:
/* CD9B30 80242850 0260202D */  daddu     $a0, $s3, $zero
/* CD9B34 80242854 0280282D */  daddu     $a1, $s4, $zero
/* CD9B38 80242858 0C0908BD */  jal       flo_17_UnkNpcAIFunc12
/* CD9B3C 8024285C 02A0302D */   daddu    $a2, $s5, $zero
/* CD9B40 80242860 08090A21 */  j         .L80242884
/* CD9B44 80242864 00000000 */   nop
.L80242868:
/* CD9B48 80242868 0280282D */  daddu     $a1, $s4, $zero
/* CD9B4C 8024286C 0C090916 */  jal       flo_17_set_script_owner_npc_col_height
/* CD9B50 80242870 02A0302D */   daddu    $a2, $s5, $zero
/* CD9B54 80242874 08090A21 */  j         .L80242884
/* CD9B58 80242878 00000000 */   nop
.L8024287C:
/* CD9B5C 8024287C 0C0129CF */  jal       func_8004A73C
/* CD9B60 80242880 0260202D */   daddu    $a0, $s3, $zero
.L80242884:
/* CD9B64 80242884 8E230088 */  lw        $v1, 0x88($s1)
/* CD9B68 80242888 24020006 */  addiu     $v0, $zero, 6
/* CD9B6C 8024288C 14620019 */  bne       $v1, $v0, .L802428F4
/* CD9B70 80242890 0000102D */   daddu    $v0, $zero, $zero
/* CD9B74 80242894 8E22008C */  lw        $v0, 0x8c($s1)
/* CD9B78 80242898 10400003 */  beqz      $v0, .L802428A8
/* CD9B7C 8024289C 24020001 */   addiu    $v0, $zero, 1
/* CD9B80 802428A0 08090A2B */  j         .L802428AC
/* CD9B84 802428A4 A22200B5 */   sb       $v0, 0xb5($s1)
.L802428A8:
/* CD9B88 802428A8 A22000B5 */  sb        $zero, 0xb5($s1)
.L802428AC:
/* CD9B8C 802428AC 8E22008C */  lw        $v0, 0x8c($s1)
/* CD9B90 802428B0 1040000F */  beqz      $v0, .L802428F0
/* CD9B94 802428B4 3C03FFAA */   lui      $v1, 0xffaa
/* CD9B98 802428B8 8E420028 */  lw        $v0, 0x28($s2)
/* CD9B9C 802428BC 3463FFFC */  ori       $v1, $v1, 0xfffc
/* CD9BA0 802428C0 00431821 */  addu      $v1, $v0, $v1
/* CD9BA4 802428C4 2C620015 */  sltiu     $v0, $v1, 0x15
/* CD9BA8 802428C8 10400009 */  beqz      $v0, .L802428F0
/* CD9BAC 802428CC 00031080 */   sll      $v0, $v1, 2
/* CD9BB0 802428D0 3C018024 */  lui       $at, %hi(jtbl_80245360_CDC640)
/* CD9BB4 802428D4 00220821 */  addu      $at, $at, $v0
/* CD9BB8 802428D8 8C225360 */  lw        $v0, %lo(jtbl_80245360_CDC640)($at)
/* CD9BBC 802428DC 00400008 */  jr        $v0
/* CD9BC0 802428E0 00000000 */   nop
glabel L802428E4_CD9BC4
/* CD9BC4 802428E4 8E420028 */  lw        $v0, 0x28($s2)
/* CD9BC8 802428E8 24420001 */  addiu     $v0, $v0, 1
/* CD9BCC 802428EC AE420028 */  sw        $v0, 0x28($s2)
.L802428F0:
glabel L802428F0_CD9BD0
/* CD9BD0 802428F0 0000102D */  daddu     $v0, $zero, $zero
.L802428F4:
/* CD9BD4 802428F4 8FBF0068 */  lw        $ra, 0x68($sp)
/* CD9BD8 802428F8 8FB50064 */  lw        $s5, 0x64($sp)
/* CD9BDC 802428FC 8FB40060 */  lw        $s4, 0x60($sp)
/* CD9BE0 80242900 8FB3005C */  lw        $s3, 0x5c($sp)
/* CD9BE4 80242904 8FB20058 */  lw        $s2, 0x58($sp)
/* CD9BE8 80242908 8FB10054 */  lw        $s1, 0x54($sp)
/* CD9BEC 8024290C 8FB00050 */  lw        $s0, 0x50($sp)
/* CD9BF0 80242910 03E00008 */  jr        $ra
/* CD9BF4 80242914 27BD0070 */   addiu    $sp, $sp, 0x70
