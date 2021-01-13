.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404B8_DE2948
/* DE2948 802404B8 27BDFF98 */  addiu     $sp, $sp, -0x68
/* DE294C 802404BC AFB30054 */  sw        $s3, 0x54($sp)
/* DE2950 802404C0 0080982D */  daddu     $s3, $a0, $zero
/* DE2954 802404C4 AFBF0060 */  sw        $ra, 0x60($sp)
/* DE2958 802404C8 AFB5005C */  sw        $s5, 0x5c($sp)
/* DE295C 802404CC AFB40058 */  sw        $s4, 0x58($sp)
/* DE2960 802404D0 AFB20050 */  sw        $s2, 0x50($sp)
/* DE2964 802404D4 AFB1004C */  sw        $s1, 0x4c($sp)
/* DE2968 802404D8 AFB00048 */  sw        $s0, 0x48($sp)
/* DE296C 802404DC 8E710148 */  lw        $s1, 0x148($s3)
/* DE2970 802404E0 86240008 */  lh        $a0, 8($s1)
/* DE2974 802404E4 0C00EABB */  jal       get_npc_unsafe
/* DE2978 802404E8 00A0802D */   daddu    $s0, $a1, $zero
/* DE297C 802404EC 8E63000C */  lw        $v1, 0xc($s3)
/* DE2980 802404F0 0260202D */  daddu     $a0, $s3, $zero
/* DE2984 802404F4 8C650000 */  lw        $a1, ($v1)
/* DE2988 802404F8 0C0B1EAF */  jal       get_variable
/* DE298C 802404FC 0040902D */   daddu    $s2, $v0, $zero
/* DE2990 80240500 AFA00018 */  sw        $zero, 0x18($sp)
/* DE2994 80240504 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DE2998 80240508 8C630030 */  lw        $v1, 0x30($v1)
/* DE299C 8024050C AFA3001C */  sw        $v1, 0x1c($sp)
/* DE29A0 80240510 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DE29A4 80240514 8C63001C */  lw        $v1, 0x1c($v1)
/* DE29A8 80240518 AFA30020 */  sw        $v1, 0x20($sp)
/* DE29AC 8024051C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DE29B0 80240520 8C630024 */  lw        $v1, 0x24($v1)
/* DE29B4 80240524 AFA30024 */  sw        $v1, 0x24($sp)
/* DE29B8 80240528 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DE29BC 8024052C 8C630028 */  lw        $v1, 0x28($v1)
/* DE29C0 80240530 27B50018 */  addiu     $s5, $sp, 0x18
/* DE29C4 80240534 AFA30028 */  sw        $v1, 0x28($sp)
/* DE29C8 80240538 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DE29CC 8024053C 3C014282 */  lui       $at, 0x4282
/* DE29D0 80240540 44810000 */  mtc1      $at, $f0
/* DE29D4 80240544 8C63002C */  lw        $v1, 0x2c($v1)
/* DE29D8 80240548 0040A02D */  daddu     $s4, $v0, $zero
/* DE29DC 8024054C E7A00030 */  swc1      $f0, 0x30($sp)
/* DE29E0 80240550 A7A00034 */  sh        $zero, 0x34($sp)
/* DE29E4 80240554 16000005 */  bnez      $s0, .L8024056C
/* DE29E8 80240558 AFA3002C */   sw       $v1, 0x2c($sp)
/* DE29EC 8024055C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DE29F0 80240560 30420004 */  andi      $v0, $v0, 4
/* DE29F4 80240564 10400044 */  beqz      $v0, .L80240678
/* DE29F8 80240568 00000000 */   nop
.L8024056C:
/* DE29FC 8024056C 2404F7FF */  addiu     $a0, $zero, -0x801
/* DE2A00 80240570 AE600070 */  sw        $zero, 0x70($s3)
/* DE2A04 80240574 A640008E */  sh        $zero, 0x8e($s2)
/* DE2A08 80240578 8E2200CC */  lw        $v0, 0xcc($s1)
/* DE2A0C 8024057C 8E430000 */  lw        $v1, ($s2)
/* DE2A10 80240580 8C420000 */  lw        $v0, ($v0)
/* DE2A14 80240584 00641824 */  and       $v1, $v1, $a0
/* DE2A18 80240588 AE430000 */  sw        $v1, ($s2)
/* DE2A1C 8024058C AE420028 */  sw        $v0, 0x28($s2)
/* DE2A20 80240590 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DE2A24 80240594 8C420034 */  lw        $v0, 0x34($v0)
/* DE2A28 80240598 54400005 */  bnel      $v0, $zero, .L802405B0
/* DE2A2C 8024059C 2402FDFF */   addiu    $v0, $zero, -0x201
/* DE2A30 802405A0 34620200 */  ori       $v0, $v1, 0x200
/* DE2A34 802405A4 2403FFF7 */  addiu     $v1, $zero, -9
/* DE2A38 802405A8 0809016E */  j         .L802405B8
/* DE2A3C 802405AC 00431024 */   and      $v0, $v0, $v1
.L802405B0:
/* DE2A40 802405B0 00621024 */  and       $v0, $v1, $v0
/* DE2A44 802405B4 34420008 */  ori       $v0, $v0, 8
.L802405B8:
/* DE2A48 802405B8 AE420000 */  sw        $v0, ($s2)
/* DE2A4C 802405BC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DE2A50 802405C0 30420004 */  andi      $v0, $v0, 4
/* DE2A54 802405C4 10400004 */  beqz      $v0, .L802405D8
/* DE2A58 802405C8 24020063 */   addiu    $v0, $zero, 0x63
/* DE2A5C 802405CC AE620070 */  sw        $v0, 0x70($s3)
/* DE2A60 802405D0 0809017C */  j         .L802405F0
/* DE2A64 802405D4 AE600074 */   sw       $zero, 0x74($s3)
.L802405D8:
/* DE2A68 802405D8 8E220000 */  lw        $v0, ($s1)
/* DE2A6C 802405DC 3C034000 */  lui       $v1, 0x4000
/* DE2A70 802405E0 00431024 */  and       $v0, $v0, $v1
/* DE2A74 802405E4 10400002 */  beqz      $v0, .L802405F0
/* DE2A78 802405E8 2402000C */   addiu    $v0, $zero, 0xc
/* DE2A7C 802405EC AE620070 */  sw        $v0, 0x70($s3)
.L802405F0:
/* DE2A80 802405F0 3C06BFFF */  lui       $a2, 0xbfff
/* DE2A84 802405F4 34C6FFFF */  ori       $a2, $a2, 0xffff
/* DE2A88 802405F8 27A50038 */  addiu     $a1, $sp, 0x38
/* DE2A8C 802405FC 2404FFFB */  addiu     $a0, $zero, -5
/* DE2A90 80240600 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DE2A94 80240604 8E230000 */  lw        $v1, ($s1)
/* DE2A98 80240608 3C0142C8 */  lui       $at, 0x42c8
/* DE2A9C 8024060C 44810000 */  mtc1      $at, $f0
/* DE2AA0 80240610 00441024 */  and       $v0, $v0, $a0
/* DE2AA4 80240614 00661824 */  and       $v1, $v1, $a2
/* DE2AA8 80240618 AE2200B0 */  sw        $v0, 0xb0($s1)
/* DE2AAC 8024061C AE230000 */  sw        $v1, ($s1)
/* DE2AB0 80240620 864200A8 */  lh        $v0, 0xa8($s2)
/* DE2AB4 80240624 27A70040 */  addiu     $a3, $sp, 0x40
/* DE2AB8 80240628 E7A00044 */  swc1      $f0, 0x44($sp)
/* DE2ABC 8024062C C6460038 */  lwc1      $f6, 0x38($s2)
/* DE2AC0 80240630 C640003C */  lwc1      $f0, 0x3c($s2)
/* DE2AC4 80240634 C6420040 */  lwc1      $f2, 0x40($s2)
/* DE2AC8 80240638 44822000 */  mtc1      $v0, $f4
/* DE2ACC 8024063C 00000000 */  nop
/* DE2AD0 80240640 46802120 */  cvt.s.w   $f4, $f4
/* DE2AD4 80240644 27A20044 */  addiu     $v0, $sp, 0x44
/* DE2AD8 80240648 46040000 */  add.s     $f0, $f0, $f4
/* DE2ADC 8024064C E7A60038 */  swc1      $f6, 0x38($sp)
/* DE2AE0 80240650 E7A20040 */  swc1      $f2, 0x40($sp)
/* DE2AE4 80240654 E7A0003C */  swc1      $f0, 0x3c($sp)
/* DE2AE8 80240658 AFA20010 */  sw        $v0, 0x10($sp)
/* DE2AEC 8024065C 8E440080 */  lw        $a0, 0x80($s2)
/* DE2AF0 80240660 0C0372DF */  jal       func_800DCB7C
/* DE2AF4 80240664 27A6003C */   addiu    $a2, $sp, 0x3c
/* DE2AF8 80240668 10400003 */  beqz      $v0, .L80240678
/* DE2AFC 8024066C 00000000 */   nop
/* DE2B00 80240670 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* DE2B04 80240674 E640003C */  swc1      $f0, 0x3c($s2)
.L80240678:
/* DE2B08 80240678 8E630070 */  lw        $v1, 0x70($s3)
/* DE2B0C 8024067C 2C620064 */  sltiu     $v0, $v1, 0x64
/* DE2B10 80240680 10400050 */  beqz      $v0, .L802407C4
/* DE2B14 80240684 00031080 */   sll      $v0, $v1, 2
/* DE2B18 80240688 3C018024 */  lui       $at, %hi(jtbl_80242EF0_DE5380)
/* DE2B1C 8024068C 00220821 */  addu      $at, $at, $v0
/* DE2B20 80240690 8C222EF0 */  lw        $v0, %lo(jtbl_80242EF0_DE5380)($at)
/* DE2B24 80240694 00400008 */  jr        $v0
/* DE2B28 80240698 00000000 */   nop
glabel L8024069C_DE2B2C
/* DE2B2C 8024069C 0260202D */  daddu     $a0, $s3, $zero
/* DE2B30 802406A0 0280282D */  daddu     $a1, $s4, $zero
/* DE2B34 802406A4 0C012568 */  jal       func_800495A0
/* DE2B38 802406A8 02A0302D */   daddu    $a2, $s5, $zero
glabel L802406AC_DE2B3C
/* DE2B3C 802406AC 0260202D */  daddu     $a0, $s3, $zero
/* DE2B40 802406B0 0280282D */  daddu     $a1, $s4, $zero
/* DE2B44 802406B4 0C0125AE */  jal       func_800496B8
/* DE2B48 802406B8 02A0302D */   daddu    $a2, $s5, $zero
/* DE2B4C 802406BC 080901F1 */  j         .L802407C4
/* DE2B50 802406C0 00000000 */   nop
glabel L802406C4_DE2B54
/* DE2B54 802406C4 0260202D */  daddu     $a0, $s3, $zero
/* DE2B58 802406C8 0280282D */  daddu     $a1, $s4, $zero
/* DE2B5C 802406CC 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* DE2B60 802406D0 02A0302D */   daddu    $a2, $s5, $zero
glabel L802406D4_DE2B64
/* DE2B64 802406D4 0260202D */  daddu     $a0, $s3, $zero
/* DE2B68 802406D8 0280282D */  daddu     $a1, $s4, $zero
/* DE2B6C 802406DC 0C012701 */  jal       func_80049C04
/* DE2B70 802406E0 02A0302D */   daddu    $a2, $s5, $zero
/* DE2B74 802406E4 080901F1 */  j         .L802407C4
/* DE2B78 802406E8 00000000 */   nop
glabel L802406EC_DE2B7C
/* DE2B7C 802406EC 0260202D */  daddu     $a0, $s3, $zero
/* DE2B80 802406F0 0280282D */  daddu     $a1, $s4, $zero
/* DE2B84 802406F4 0C01278F */  jal       func_80049E3C
/* DE2B88 802406F8 02A0302D */   daddu    $a2, $s5, $zero
glabel L802406FC_DE2B8C
/* DE2B8C 802406FC 0260202D */  daddu     $a0, $s3, $zero
/* DE2B90 80240700 0280282D */  daddu     $a1, $s4, $zero
/* DE2B94 80240704 0C0127B3 */  jal       func_80049ECC
/* DE2B98 80240708 02A0302D */   daddu    $a2, $s5, $zero
/* DE2B9C 8024070C 080901F1 */  j         .L802407C4
/* DE2BA0 80240710 00000000 */   nop
glabel L80240714_DE2BA4
/* DE2BA4 80240714 0260202D */  daddu     $a0, $s3, $zero
/* DE2BA8 80240718 0280282D */  daddu     $a1, $s4, $zero
/* DE2BAC 8024071C 0C0127DF */  jal       func_80049F7C
/* DE2BB0 80240720 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240724_DE2BB4
/* DE2BB4 80240724 0260202D */  daddu     $a0, $s3, $zero
/* DE2BB8 80240728 0280282D */  daddu     $a1, $s4, $zero
/* DE2BBC 8024072C 0C012849 */  jal       func_8004A124
/* DE2BC0 80240730 02A0302D */   daddu    $a2, $s5, $zero
/* DE2BC4 80240734 8E630070 */  lw        $v1, 0x70($s3)
/* DE2BC8 80240738 2402000E */  addiu     $v0, $zero, 0xe
/* DE2BCC 8024073C 14620021 */  bne       $v1, $v0, .L802407C4
/* DE2BD0 80240740 00000000 */   nop
glabel L80240744_DE2BD4
/* DE2BD4 80240744 0260202D */  daddu     $a0, $s3, $zero
/* DE2BD8 80240748 0280282D */  daddu     $a1, $s4, $zero
/* DE2BDC 8024074C 0C0900A0 */  jal       func_80240280_DE2710
/* DE2BE0 80240750 02A0302D */   daddu    $a2, $s5, $zero
/* DE2BE4 80240754 8E630070 */  lw        $v1, 0x70($s3)
/* DE2BE8 80240758 2402000F */  addiu     $v0, $zero, 0xf
/* DE2BEC 8024075C 14620019 */  bne       $v1, $v0, .L802407C4
/* DE2BF0 80240760 00000000 */   nop
glabel L80240764_DE2BF4
/* DE2BF4 80240764 0260202D */  daddu     $a0, $s3, $zero
/* DE2BF8 80240768 0280282D */  daddu     $a1, $s4, $zero
/* DE2BFC 8024076C 0C0900BC */  jal       func_802402F0_DE2780
/* DE2C00 80240770 02A0302D */   daddu    $a2, $s5, $zero
/* DE2C04 80240774 8E630070 */  lw        $v1, 0x70($s3)
/* DE2C08 80240778 24020010 */  addiu     $v0, $zero, 0x10
/* DE2C0C 8024077C 14620011 */  bne       $v1, $v0, .L802407C4
/* DE2C10 80240780 00000000 */   nop
glabel L80240784_DE2C14
/* DE2C14 80240784 0260202D */  daddu     $a0, $s3, $zero
/* DE2C18 80240788 0280282D */  daddu     $a1, $s4, $zero
/* DE2C1C 8024078C 0C0900F0 */  jal       func_802403C0_DE2850
/* DE2C20 80240790 02A0302D */   daddu    $a2, $s5, $zero
/* DE2C24 80240794 8E630070 */  lw        $v1, 0x70($s3)
/* DE2C28 80240798 24020011 */  addiu     $v0, $zero, 0x11
/* DE2C2C 8024079C 14620009 */  bne       $v1, $v0, .L802407C4
/* DE2C30 802407A0 00000000 */   nop
glabel L802407A4_DE2C34
/* DE2C34 802407A4 0260202D */  daddu     $a0, $s3, $zero
/* DE2C38 802407A8 0280282D */  daddu     $a1, $s4, $zero
/* DE2C3C 802407AC 0C090116 */  jal       func_80240458_DE28E8
/* DE2C40 802407B0 02A0302D */   daddu    $a2, $s5, $zero
/* DE2C44 802407B4 080901F1 */  j         .L802407C4
/* DE2C48 802407B8 00000000 */   nop
glabel L802407BC_DE2C4C
/* DE2C4C 802407BC 0C0129CF */  jal       func_8004A73C
/* DE2C50 802407C0 0260202D */   daddu    $a0, $s3, $zero
.L802407C4:
glabel L802407C4_DE2C54
/* DE2C54 802407C4 8FBF0060 */  lw        $ra, 0x60($sp)
/* DE2C58 802407C8 8FB5005C */  lw        $s5, 0x5c($sp)
/* DE2C5C 802407CC 8FB40058 */  lw        $s4, 0x58($sp)
/* DE2C60 802407D0 8FB30054 */  lw        $s3, 0x54($sp)
/* DE2C64 802407D4 8FB20050 */  lw        $s2, 0x50($sp)
/* DE2C68 802407D8 8FB1004C */  lw        $s1, 0x4c($sp)
/* DE2C6C 802407DC 8FB00048 */  lw        $s0, 0x48($sp)
/* DE2C70 802407E0 0000102D */  daddu     $v0, $zero, $zero
/* DE2C74 802407E4 03E00008 */  jr        $ra
/* DE2C78 802407E8 27BD0068 */   addiu    $sp, $sp, 0x68
