.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80245410_EF7A20
.word L80242968_EF4F78, L80242974_EF4F84, L80242974_EF4F84, L80242974_EF4F84, L80242974_EF4F84, L80242974_EF4F84, L80242974_EF4F84, L80242974_EF4F84, L80242968_EF4F78, L80242974_EF4F84, L80242968_EF4F78, L80242974_EF4F84, L80242968_EF4F78, L80242974_EF4F84, L80242968_EF4F78, L80242974_EF4F84, L80242974_EF4F84, L80242974_EF4F84, L80242968_EF4F78, L80242974_EF4F84, L80242968_EF4F78, 0

.section .text

glabel func_80242530_EF4B40
/* EF4B40 80242530 27BDFF90 */  addiu     $sp, $sp, -0x70
/* EF4B44 80242534 AFB3005C */  sw        $s3, 0x5c($sp)
/* EF4B48 80242538 0080982D */  daddu     $s3, $a0, $zero
/* EF4B4C 8024253C AFBF0068 */  sw        $ra, 0x68($sp)
/* EF4B50 80242540 AFB50064 */  sw        $s5, 0x64($sp)
/* EF4B54 80242544 AFB40060 */  sw        $s4, 0x60($sp)
/* EF4B58 80242548 AFB20058 */  sw        $s2, 0x58($sp)
/* EF4B5C 8024254C AFB10054 */  sw        $s1, 0x54($sp)
/* EF4B60 80242550 AFB00050 */  sw        $s0, 0x50($sp)
/* EF4B64 80242554 8E710148 */  lw        $s1, 0x148($s3)
/* EF4B68 80242558 86240008 */  lh        $a0, 8($s1)
/* EF4B6C 8024255C 0C00F92F */  jal       func_8003E4BC
/* EF4B70 80242560 00A0802D */   daddu    $s0, $a1, $zero
/* EF4B74 80242564 8E63000C */  lw        $v1, 0xc($s3)
/* EF4B78 80242568 0260202D */  daddu     $a0, $s3, $zero
/* EF4B7C 8024256C 8C650000 */  lw        $a1, ($v1)
/* EF4B80 80242570 0C0B53A3 */  jal       func_802D4E8C
/* EF4B84 80242574 0040902D */   daddu    $s2, $v0, $zero
/* EF4B88 80242578 AFA00028 */  sw        $zero, 0x28($sp)
/* EF4B8C 8024257C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EF4B90 80242580 8C630030 */  lw        $v1, 0x30($v1)
/* EF4B94 80242584 AFA3002C */  sw        $v1, 0x2c($sp)
/* EF4B98 80242588 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EF4B9C 8024258C 8C63001C */  lw        $v1, 0x1c($v1)
/* EF4BA0 80242590 AFA30030 */  sw        $v1, 0x30($sp)
/* EF4BA4 80242594 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EF4BA8 80242598 8C630024 */  lw        $v1, 0x24($v1)
/* EF4BAC 8024259C AFA30034 */  sw        $v1, 0x34($sp)
/* EF4BB0 802425A0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EF4BB4 802425A4 8C630028 */  lw        $v1, 0x28($v1)
/* EF4BB8 802425A8 AFA30038 */  sw        $v1, 0x38($sp)
/* EF4BBC 802425AC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EF4BC0 802425B0 3C0142C8 */  lui       $at, 0x42c8
/* EF4BC4 802425B4 44810000 */  mtc1      $at, $f0
/* EF4BC8 802425B8 8C63002C */  lw        $v1, 0x2c($v1)
/* EF4BCC 802425BC E7A00040 */  swc1      $f0, 0x40($sp)
/* EF4BD0 802425C0 A7A00044 */  sh        $zero, 0x44($sp)
/* EF4BD4 802425C4 AFA3003C */  sw        $v1, 0x3c($sp)
/* EF4BD8 802425C8 C6400038 */  lwc1      $f0, 0x38($s2)
/* EF4BDC 802425CC E6200108 */  swc1      $f0, 0x108($s1)
/* EF4BE0 802425D0 C640003C */  lwc1      $f0, 0x3c($s2)
/* EF4BE4 802425D4 27B50028 */  addiu     $s5, $sp, 0x28
/* EF4BE8 802425D8 E620010C */  swc1      $f0, 0x10c($s1)
/* EF4BEC 802425DC 3C013C23 */  lui       $at, 0x3c23
/* EF4BF0 802425E0 3421D70A */  ori       $at, $at, 0xd70a
/* EF4BF4 802425E4 44810000 */  mtc1      $at, $f0
/* EF4BF8 802425E8 C6420040 */  lwc1      $f2, 0x40($s2)
/* EF4BFC 802425EC 0040A02D */  daddu     $s4, $v0, $zero
/* EF4C00 802425F0 E6200114 */  swc1      $f0, 0x114($s1)
/* EF4C04 802425F4 E6200118 */  swc1      $f0, 0x118($s1)
/* EF4C08 802425F8 12000009 */  beqz      $s0, .L80242620
/* EF4C0C 802425FC E6220110 */   swc1     $f2, 0x110($s1)
/* EF4C10 80242600 864300A8 */  lh        $v1, 0xa8($s2)
/* EF4C14 80242604 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EF4C18 80242608 AE20008C */  sw        $zero, 0x8c($s1)
/* EF4C1C 8024260C A22000B5 */  sb        $zero, 0xb5($s1)
/* EF4C20 80242610 34420008 */  ori       $v0, $v0, 8
/* EF4C24 80242614 AE230084 */  sw        $v1, 0x84($s1)
/* EF4C28 80242618 0809098C */  j         .L80242630
/* EF4C2C 8024261C AE2200B0 */   sw       $v0, 0xb0($s1)
.L80242620:
/* EF4C30 80242620 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EF4C34 80242624 30420004 */  andi      $v0, $v0, 4
/* EF4C38 80242628 10400047 */  beqz      $v0, .L80242748
/* EF4C3C 8024262C 00000000 */   nop
.L80242630:
/* EF4C40 80242630 AE600070 */  sw        $zero, 0x70($s3)
/* EF4C44 80242634 A640008E */  sh        $zero, 0x8e($s2)
/* EF4C48 80242638 8E2300CC */  lw        $v1, 0xcc($s1)
/* EF4C4C 8024263C 2404F7FF */  addiu     $a0, $zero, -0x801
/* EF4C50 80242640 A2200007 */  sb        $zero, 7($s1)
/* EF4C54 80242644 8E420000 */  lw        $v0, ($s2)
/* EF4C58 80242648 8C630000 */  lw        $v1, ($v1)
/* EF4C5C 8024264C 00441024 */  and       $v0, $v0, $a0
/* EF4C60 80242650 AE420000 */  sw        $v0, ($s2)
/* EF4C64 80242654 AE430028 */  sw        $v1, 0x28($s2)
/* EF4C68 80242658 96220086 */  lhu       $v0, 0x86($s1)
/* EF4C6C 8024265C A64200A8 */  sh        $v0, 0xa8($s2)
/* EF4C70 80242660 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EF4C74 80242664 AE200090 */  sw        $zero, 0x90($s1)
/* EF4C78 80242668 8C420034 */  lw        $v0, 0x34($v0)
/* EF4C7C 8024266C 14400006 */  bnez      $v0, .L80242688
/* EF4C80 80242670 2403FDFF */   addiu    $v1, $zero, -0x201
/* EF4C84 80242674 8E420000 */  lw        $v0, ($s2)
/* EF4C88 80242678 2403FFF7 */  addiu     $v1, $zero, -9
/* EF4C8C 8024267C 34420200 */  ori       $v0, $v0, 0x200
/* EF4C90 80242680 080909A5 */  j         .L80242694
/* EF4C94 80242684 00431024 */   and      $v0, $v0, $v1
.L80242688:
/* EF4C98 80242688 8E420000 */  lw        $v0, ($s2)
/* EF4C9C 8024268C 00431024 */  and       $v0, $v0, $v1
/* EF4CA0 80242690 34420008 */  ori       $v0, $v0, 8
.L80242694:
/* EF4CA4 80242694 AE420000 */  sw        $v0, ($s2)
/* EF4CA8 80242698 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EF4CAC 8024269C 30420004 */  andi      $v0, $v0, 4
/* EF4CB0 802426A0 1040001E */  beqz      $v0, .L8024271C
/* EF4CB4 802426A4 24040002 */   addiu    $a0, $zero, 2
/* EF4CB8 802426A8 0240282D */  daddu     $a1, $s2, $zero
/* EF4CBC 802426AC 0000302D */  daddu     $a2, $zero, $zero
/* EF4CC0 802426B0 24020063 */  addiu     $v0, $zero, 0x63
/* EF4CC4 802426B4 AE620070 */  sw        $v0, 0x70($s3)
/* EF4CC8 802426B8 AE600074 */  sw        $zero, 0x74($s3)
/* EF4CCC 802426BC 864300A8 */  lh        $v1, 0xa8($s2)
/* EF4CD0 802426C0 3C013F80 */  lui       $at, 0x3f80
/* EF4CD4 802426C4 44810000 */  mtc1      $at, $f0
/* EF4CD8 802426C8 3C014000 */  lui       $at, 0x4000
/* EF4CDC 802426CC 44811000 */  mtc1      $at, $f2
/* EF4CE0 802426D0 3C01C1A0 */  lui       $at, 0xc1a0
/* EF4CE4 802426D4 44812000 */  mtc1      $at, $f4
/* EF4CE8 802426D8 24020028 */  addiu     $v0, $zero, 0x28
/* EF4CEC 802426DC AFA2001C */  sw        $v0, 0x1c($sp)
/* EF4CF0 802426E0 44833000 */  mtc1      $v1, $f6
/* EF4CF4 802426E4 00000000 */  nop
/* EF4CF8 802426E8 468031A0 */  cvt.s.w   $f6, $f6
/* EF4CFC 802426EC 44073000 */  mfc1      $a3, $f6
/* EF4D00 802426F0 27A20048 */  addiu     $v0, $sp, 0x48
/* EF4D04 802426F4 AFA20020 */  sw        $v0, 0x20($sp)
/* EF4D08 802426F8 E7A00010 */  swc1      $f0, 0x10($sp)
/* EF4D0C 802426FC E7A20014 */  swc1      $f2, 0x14($sp)
/* EF4D10 80242700 0C01D444 */  jal       func_80075110
/* EF4D14 80242704 E7A40018 */   swc1     $f4, 0x18($sp)
/* EF4D18 80242708 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EF4D1C 8024270C 2403FFFB */  addiu     $v1, $zero, -5
/* EF4D20 80242710 00431024 */  and       $v0, $v0, $v1
/* EF4D24 80242714 080909D2 */  j         .L80242748
/* EF4D28 80242718 AE2200B0 */   sw       $v0, 0xb0($s1)
.L8024271C:
/* EF4D2C 8024271C 8E220000 */  lw        $v0, ($s1)
/* EF4D30 80242720 3C034000 */  lui       $v1, 0x4000
/* EF4D34 80242724 00431024 */  and       $v0, $v0, $v1
/* EF4D38 80242728 10400007 */  beqz      $v0, .L80242748
/* EF4D3C 8024272C 3C03BFFF */   lui      $v1, 0xbfff
/* EF4D40 80242730 2402000C */  addiu     $v0, $zero, 0xc
/* EF4D44 80242734 AE620070 */  sw        $v0, 0x70($s3)
/* EF4D48 80242738 8E220000 */  lw        $v0, ($s1)
/* EF4D4C 8024273C 3463FFFF */  ori       $v1, $v1, 0xffff
/* EF4D50 80242740 00431024 */  and       $v0, $v0, $v1
/* EF4D54 80242744 AE220000 */  sw        $v0, ($s1)
.L80242748:
/* EF4D58 80242748 8E220090 */  lw        $v0, 0x90($s1)
/* EF4D5C 8024274C 1840000C */  blez      $v0, .L80242780
/* EF4D60 80242750 2442FFFF */   addiu    $v0, $v0, -1
/* EF4D64 80242754 14400087 */  bnez      $v0, L80242974_EF4F84
/* EF4D68 80242758 AE220090 */   sw       $v0, 0x90($s1)
/* EF4D6C 8024275C 3C03FFAA */  lui       $v1, 0xffaa
/* EF4D70 80242760 8E420028 */  lw        $v0, 0x28($s2)
/* EF4D74 80242764 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* EF4D78 80242768 00431021 */  addu      $v0, $v0, $v1
/* EF4D7C 8024276C 2C420002 */  sltiu     $v0, $v0, 2
/* EF4D80 80242770 10400003 */  beqz      $v0, .L80242780
/* EF4D84 80242774 3C020055 */   lui      $v0, 0x55
/* EF4D88 80242778 3442000C */  ori       $v0, $v0, 0xc
/* EF4D8C 8024277C AE420028 */  sw        $v0, 0x28($s2)
.L80242780:
/* EF4D90 80242780 8E630070 */  lw        $v1, 0x70($s3)
/* EF4D94 80242784 2402000C */  addiu     $v0, $zero, 0xc
/* EF4D98 80242788 10620048 */  beq       $v1, $v0, .L802428AC
/* EF4D9C 8024278C 2862000D */   slti     $v0, $v1, 0xd
/* EF4DA0 80242790 1040000F */  beqz      $v0, .L802427D0
/* EF4DA4 80242794 24100001 */   addiu    $s0, $zero, 1
/* EF4DA8 80242798 1070001E */  beq       $v1, $s0, .L80242814
/* EF4DAC 8024279C 28620002 */   slti     $v0, $v1, 2
/* EF4DB0 802427A0 10400005 */  beqz      $v0, .L802427B8
/* EF4DB4 802427A4 24020002 */   addiu    $v0, $zero, 2
/* EF4DB8 802427A8 10600015 */  beqz      $v1, .L80242800
/* EF4DBC 802427AC 0260202D */   daddu    $a0, $s3, $zero
/* EF4DC0 802427B0 08090A42 */  j         .L80242908
/* EF4DC4 802427B4 00000000 */   nop
.L802427B8:
/* EF4DC8 802427B8 1062001C */  beq       $v1, $v0, .L8024282C
/* EF4DCC 802427BC 24020003 */   addiu    $v0, $zero, 3
/* EF4DD0 802427C0 10620035 */  beq       $v1, $v0, .L80242898
/* EF4DD4 802427C4 0260202D */   daddu    $a0, $s3, $zero
/* EF4DD8 802427C8 08090A42 */  j         .L80242908
/* EF4DDC 802427CC 00000000 */   nop
.L802427D0:
/* EF4DE0 802427D0 2402000E */  addiu     $v0, $zero, 0xe
/* EF4DE4 802427D4 1062003F */  beq       $v1, $v0, .L802428D4
/* EF4DE8 802427D8 0062102A */   slt      $v0, $v1, $v0
/* EF4DEC 802427DC 14400038 */  bnez      $v0, .L802428C0
/* EF4DF0 802427E0 0260202D */   daddu    $a0, $s3, $zero
/* EF4DF4 802427E4 2402000F */  addiu     $v0, $zero, 0xf
/* EF4DF8 802427E8 10620040 */  beq       $v1, $v0, .L802428EC
/* EF4DFC 802427EC 24020063 */   addiu    $v0, $zero, 0x63
/* EF4E00 802427F0 10620043 */  beq       $v1, $v0, .L80242900
/* EF4E04 802427F4 00000000 */   nop
/* EF4E08 802427F8 08090A42 */  j         .L80242908
/* EF4E0C 802427FC 00000000 */   nop
.L80242800:
/* EF4E10 80242800 0280282D */  daddu     $a1, $s4, $zero
/* EF4E14 80242804 0C013670 */  jal       func_8004D9C0
/* EF4E18 80242808 02A0302D */   daddu    $a2, $s5, $zero
/* EF4E1C 8024280C 96220086 */  lhu       $v0, 0x86($s1)
/* EF4E20 80242810 A64200A8 */  sh        $v0, 0xa8($s2)
.L80242814:
/* EF4E24 80242814 0260202D */  daddu     $a0, $s3, $zero
/* EF4E28 80242818 0280282D */  daddu     $a1, $s4, $zero
/* EF4E2C 8024281C 0C0136B6 */  jal       func_8004DAD8
/* EF4E30 80242820 02A0302D */   daddu    $a2, $s5, $zero
/* EF4E34 80242824 08090A42 */  j         .L80242908
/* EF4E38 80242828 00000000 */   nop
.L8024282C:
/* EF4E3C 8024282C 0260202D */  daddu     $a0, $s3, $zero
/* EF4E40 80242830 0280282D */  daddu     $a1, $s4, $zero
/* EF4E44 80242834 0C0137D9 */  jal       func_8004DF64
/* EF4E48 80242838 02A0302D */   daddu    $a2, $s5, $zero
/* EF4E4C 8024283C 8E230088 */  lw        $v1, 0x88($s1)
/* EF4E50 80242840 24020006 */  addiu     $v0, $zero, 6
/* EF4E54 80242844 14620014 */  bne       $v1, $v0, .L80242898
/* EF4E58 80242848 0260202D */   daddu    $a0, $s3, $zero
/* EF4E5C 8024284C 0C00AB3B */  jal       func_8002ACEC
/* EF4E60 80242850 24040064 */   addiu    $a0, $zero, 0x64
/* EF4E64 80242854 28420021 */  slti      $v0, $v0, 0x21
/* EF4E68 80242858 5040000F */  beql      $v0, $zero, .L80242898
/* EF4E6C 8024285C 0260202D */   daddu    $a0, $s3, $zero
/* EF4E70 80242860 8E22008C */  lw        $v0, 0x8c($s1)
/* EF4E74 80242864 10400005 */  beqz      $v0, .L8024287C
/* EF4E78 80242868 3C020055 */   lui      $v0, 0x55
/* EF4E7C 8024286C 3442002F */  ori       $v0, $v0, 0x2f
/* EF4E80 80242870 AE20008C */  sw        $zero, 0x8c($s1)
/* EF4E84 80242874 08090A22 */  j         .L80242888
/* EF4E88 80242878 A22000B5 */   sb       $zero, 0xb5($s1)
.L8024287C:
/* EF4E8C 8024287C 3442002E */  ori       $v0, $v0, 0x2e
/* EF4E90 80242880 AE30008C */  sw        $s0, 0x8c($s1)
/* EF4E94 80242884 A23000B5 */  sb        $s0, 0xb5($s1)
.L80242888:
/* EF4E98 80242888 AE420028 */  sw        $v0, 0x28($s2)
/* EF4E9C 8024288C 24020007 */  addiu     $v0, $zero, 7
/* EF4EA0 80242890 08090A5D */  j         L80242974_EF4F84
/* EF4EA4 80242894 AE220090 */   sw       $v0, 0x90($s1)
.L80242898:
/* EF4EA8 80242898 0280282D */  daddu     $a1, $s4, $zero
/* EF4EAC 8024289C 0C013809 */  jal       func_8004E024
/* EF4EB0 802428A0 02A0302D */   daddu    $a2, $s5, $zero
/* EF4EB4 802428A4 08090A42 */  j         .L80242908
/* EF4EB8 802428A8 00000000 */   nop
.L802428AC:
/* EF4EBC 802428AC 0260202D */  daddu     $a0, $s3, $zero
/* EF4EC0 802428B0 0280282D */  daddu     $a1, $s4, $zero
/* EF4EC4 802428B4 0C090867 */  jal       func_8024219C_EF47AC
/* EF4EC8 802428B8 02A0302D */   daddu    $a2, $s5, $zero
/* EF4ECC 802428BC 0260202D */  daddu     $a0, $s3, $zero
.L802428C0:
/* EF4ED0 802428C0 0280282D */  daddu     $a1, $s4, $zero
/* EF4ED4 802428C4 0C090886 */  jal       func_80242218_EF4828
/* EF4ED8 802428C8 02A0302D */   daddu    $a2, $s5, $zero
/* EF4EDC 802428CC 08090A42 */  j         .L80242908
/* EF4EE0 802428D0 00000000 */   nop
.L802428D4:
/* EF4EE4 802428D4 0260202D */  daddu     $a0, $s3, $zero
/* EF4EE8 802428D8 0280282D */  daddu     $a1, $s4, $zero
/* EF4EEC 802428DC 0C0908D3 */  jal       func_8024234C_EF495C
/* EF4EF0 802428E0 02A0302D */   daddu    $a2, $s5, $zero
/* EF4EF4 802428E4 08090A42 */  j         .L80242908
/* EF4EF8 802428E8 00000000 */   nop
.L802428EC:
/* EF4EFC 802428EC 0280282D */  daddu     $a1, $s4, $zero
/* EF4F00 802428F0 0C09092C */  jal       func_802424B0_EF4AC0
/* EF4F04 802428F4 02A0302D */   daddu    $a2, $s5, $zero
/* EF4F08 802428F8 08090A42 */  j         .L80242908
/* EF4F0C 802428FC 00000000 */   nop
.L80242900:
/* EF4F10 80242900 0C013AE3 */  jal       func_8004EB8C
/* EF4F14 80242904 0260202D */   daddu    $a0, $s3, $zero
.L80242908:
/* EF4F18 80242908 8E230088 */  lw        $v1, 0x88($s1)
/* EF4F1C 8024290C 24020006 */  addiu     $v0, $zero, 6
/* EF4F20 80242910 14620019 */  bne       $v1, $v0, .L80242978
/* EF4F24 80242914 0000102D */   daddu    $v0, $zero, $zero
/* EF4F28 80242918 8E22008C */  lw        $v0, 0x8c($s1)
/* EF4F2C 8024291C 10400003 */  beqz      $v0, .L8024292C
/* EF4F30 80242920 24020001 */   addiu    $v0, $zero, 1
/* EF4F34 80242924 08090A4C */  j         .L80242930
/* EF4F38 80242928 A22200B5 */   sb       $v0, 0xb5($s1)
.L8024292C:
/* EF4F3C 8024292C A22000B5 */  sb        $zero, 0xb5($s1)
.L80242930:
/* EF4F40 80242930 8E22008C */  lw        $v0, 0x8c($s1)
/* EF4F44 80242934 1040000F */  beqz      $v0, L80242974_EF4F84
/* EF4F48 80242938 3C03FFAA */   lui      $v1, 0xffaa
/* EF4F4C 8024293C 8E420028 */  lw        $v0, 0x28($s2)
/* EF4F50 80242940 3463FFFC */  ori       $v1, $v1, 0xfffc
/* EF4F54 80242944 00431821 */  addu      $v1, $v0, $v1
/* EF4F58 80242948 2C620015 */  sltiu     $v0, $v1, 0x15
/* EF4F5C 8024294C 10400009 */  beqz      $v0, L80242974_EF4F84
/* EF4F60 80242950 00031080 */   sll      $v0, $v1, 2
/* EF4F64 80242954 3C018024 */  lui       $at, %hi(jtbl_80245410_EF7A20)
/* EF4F68 80242958 00220821 */  addu      $at, $at, $v0
/* EF4F6C 8024295C 8C225410 */  lw        $v0, %lo(jtbl_80245410_EF7A20)($at)
/* EF4F70 80242960 00400008 */  jr        $v0
/* EF4F74 80242964 00000000 */   nop
glabel L80242968_EF4F78
/* EF4F78 80242968 8E420028 */  lw        $v0, 0x28($s2)
/* EF4F7C 8024296C 24420001 */  addiu     $v0, $v0, 1
/* EF4F80 80242970 AE420028 */  sw        $v0, 0x28($s2)
glabel L80242974_EF4F84
/* EF4F84 80242974 0000102D */  daddu     $v0, $zero, $zero
.L80242978:
/* EF4F88 80242978 8FBF0068 */  lw        $ra, 0x68($sp)
/* EF4F8C 8024297C 8FB50064 */  lw        $s5, 0x64($sp)
/* EF4F90 80242980 8FB40060 */  lw        $s4, 0x60($sp)
/* EF4F94 80242984 8FB3005C */  lw        $s3, 0x5c($sp)
/* EF4F98 80242988 8FB20058 */  lw        $s2, 0x58($sp)
/* EF4F9C 8024298C 8FB10054 */  lw        $s1, 0x54($sp)
/* EF4FA0 80242990 8FB00050 */  lw        $s0, 0x50($sp)
/* EF4FA4 80242994 03E00008 */  jr        $ra
/* EF4FA8 80242998 27BD0070 */   addiu    $sp, $sp, 0x70
