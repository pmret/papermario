.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024262C_CC5E3C
/* CC5E3C 8024262C 27BDFF90 */  addiu     $sp, $sp, -0x70
/* CC5E40 80242630 AFB3005C */  sw        $s3, 0x5c($sp)
/* CC5E44 80242634 0080982D */  daddu     $s3, $a0, $zero
/* CC5E48 80242638 AFBF0068 */  sw        $ra, 0x68($sp)
/* CC5E4C 8024263C AFB50064 */  sw        $s5, 0x64($sp)
/* CC5E50 80242640 AFB40060 */  sw        $s4, 0x60($sp)
/* CC5E54 80242644 AFB20058 */  sw        $s2, 0x58($sp)
/* CC5E58 80242648 AFB10054 */  sw        $s1, 0x54($sp)
/* CC5E5C 8024264C AFB00050 */  sw        $s0, 0x50($sp)
/* CC5E60 80242650 8E710148 */  lw        $s1, 0x148($s3)
/* CC5E64 80242654 86240008 */  lh        $a0, 8($s1)
/* CC5E68 80242658 0C00EABB */  jal       get_npc_unsafe
/* CC5E6C 8024265C 00A0802D */   daddu    $s0, $a1, $zero
/* CC5E70 80242660 8E63000C */  lw        $v1, 0xc($s3)
/* CC5E74 80242664 0260202D */  daddu     $a0, $s3, $zero
/* CC5E78 80242668 8C650000 */  lw        $a1, ($v1)
/* CC5E7C 8024266C 0C0B1EAF */  jal       get_variable
/* CC5E80 80242670 0040902D */   daddu    $s2, $v0, $zero
/* CC5E84 80242674 AFA00028 */  sw        $zero, 0x28($sp)
/* CC5E88 80242678 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CC5E8C 8024267C 8C630030 */  lw        $v1, 0x30($v1)
/* CC5E90 80242680 AFA3002C */  sw        $v1, 0x2c($sp)
/* CC5E94 80242684 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CC5E98 80242688 8C63001C */  lw        $v1, 0x1c($v1)
/* CC5E9C 8024268C AFA30030 */  sw        $v1, 0x30($sp)
/* CC5EA0 80242690 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CC5EA4 80242694 8C630024 */  lw        $v1, 0x24($v1)
/* CC5EA8 80242698 AFA30034 */  sw        $v1, 0x34($sp)
/* CC5EAC 8024269C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CC5EB0 802426A0 8C630028 */  lw        $v1, 0x28($v1)
/* CC5EB4 802426A4 27B50028 */  addiu     $s5, $sp, 0x28
/* CC5EB8 802426A8 AFA30038 */  sw        $v1, 0x38($sp)
/* CC5EBC 802426AC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CC5EC0 802426B0 3C0142C8 */  lui       $at, 0x42c8
/* CC5EC4 802426B4 44810000 */  mtc1      $at, $f0
/* CC5EC8 802426B8 8C63002C */  lw        $v1, 0x2c($v1)
/* CC5ECC 802426BC 0040A02D */  daddu     $s4, $v0, $zero
/* CC5ED0 802426C0 E7A00040 */  swc1      $f0, 0x40($sp)
/* CC5ED4 802426C4 A7A00044 */  sh        $zero, 0x44($sp)
/* CC5ED8 802426C8 12000009 */  beqz      $s0, .L802426F0
/* CC5EDC 802426CC AFA3003C */   sw       $v1, 0x3c($sp)
/* CC5EE0 802426D0 864300A8 */  lh        $v1, 0xa8($s2)
/* CC5EE4 802426D4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CC5EE8 802426D8 AE20008C */  sw        $zero, 0x8c($s1)
/* CC5EEC 802426DC A22000B5 */  sb        $zero, 0xb5($s1)
/* CC5EF0 802426E0 34420008 */  ori       $v0, $v0, 8
/* CC5EF4 802426E4 AE230084 */  sw        $v1, 0x84($s1)
/* CC5EF8 802426E8 080909C0 */  j         .L80242700
/* CC5EFC 802426EC AE2200B0 */   sw       $v0, 0xb0($s1)
.L802426F0:
/* CC5F00 802426F0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CC5F04 802426F4 30420004 */  andi      $v0, $v0, 4
/* CC5F08 802426F8 10400047 */  beqz      $v0, .L80242818
/* CC5F0C 802426FC 00000000 */   nop
.L80242700:
/* CC5F10 80242700 AE600070 */  sw        $zero, 0x70($s3)
/* CC5F14 80242704 A640008E */  sh        $zero, 0x8e($s2)
/* CC5F18 80242708 8E2300CC */  lw        $v1, 0xcc($s1)
/* CC5F1C 8024270C 2404F7FF */  addiu     $a0, $zero, -0x801
/* CC5F20 80242710 A2200007 */  sb        $zero, 7($s1)
/* CC5F24 80242714 8E420000 */  lw        $v0, ($s2)
/* CC5F28 80242718 8C630000 */  lw        $v1, ($v1)
/* CC5F2C 8024271C 00441024 */  and       $v0, $v0, $a0
/* CC5F30 80242720 AE420000 */  sw        $v0, ($s2)
/* CC5F34 80242724 AE430028 */  sw        $v1, 0x28($s2)
/* CC5F38 80242728 96220086 */  lhu       $v0, 0x86($s1)
/* CC5F3C 8024272C A64200A8 */  sh        $v0, 0xa8($s2)
/* CC5F40 80242730 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CC5F44 80242734 AE200090 */  sw        $zero, 0x90($s1)
/* CC5F48 80242738 8C420034 */  lw        $v0, 0x34($v0)
/* CC5F4C 8024273C 14400006 */  bnez      $v0, .L80242758
/* CC5F50 80242740 2403FDFF */   addiu    $v1, $zero, -0x201
/* CC5F54 80242744 8E420000 */  lw        $v0, ($s2)
/* CC5F58 80242748 2403FFF7 */  addiu     $v1, $zero, -9
/* CC5F5C 8024274C 34420200 */  ori       $v0, $v0, 0x200
/* CC5F60 80242750 080909D9 */  j         .L80242764
/* CC5F64 80242754 00431024 */   and      $v0, $v0, $v1
.L80242758:
/* CC5F68 80242758 8E420000 */  lw        $v0, ($s2)
/* CC5F6C 8024275C 00431024 */  and       $v0, $v0, $v1
/* CC5F70 80242760 34420008 */  ori       $v0, $v0, 8
.L80242764:
/* CC5F74 80242764 AE420000 */  sw        $v0, ($s2)
/* CC5F78 80242768 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CC5F7C 8024276C 30420004 */  andi      $v0, $v0, 4
/* CC5F80 80242770 1040001E */  beqz      $v0, .L802427EC
/* CC5F84 80242774 24040002 */   addiu    $a0, $zero, 2
/* CC5F88 80242778 0240282D */  daddu     $a1, $s2, $zero
/* CC5F8C 8024277C 0000302D */  daddu     $a2, $zero, $zero
/* CC5F90 80242780 24020063 */  addiu     $v0, $zero, 0x63
/* CC5F94 80242784 AE620070 */  sw        $v0, 0x70($s3)
/* CC5F98 80242788 AE600074 */  sw        $zero, 0x74($s3)
/* CC5F9C 8024278C 864300A8 */  lh        $v1, 0xa8($s2)
/* CC5FA0 80242790 3C013F80 */  lui       $at, 0x3f80
/* CC5FA4 80242794 44810000 */  mtc1      $at, $f0
/* CC5FA8 80242798 3C014000 */  lui       $at, 0x4000
/* CC5FAC 8024279C 44811000 */  mtc1      $at, $f2
/* CC5FB0 802427A0 3C01C1A0 */  lui       $at, 0xc1a0
/* CC5FB4 802427A4 44812000 */  mtc1      $at, $f4
/* CC5FB8 802427A8 24020028 */  addiu     $v0, $zero, 0x28
/* CC5FBC 802427AC AFA2001C */  sw        $v0, 0x1c($sp)
/* CC5FC0 802427B0 44833000 */  mtc1      $v1, $f6
/* CC5FC4 802427B4 00000000 */  nop
/* CC5FC8 802427B8 468031A0 */  cvt.s.w   $f6, $f6
/* CC5FCC 802427BC 44073000 */  mfc1      $a3, $f6
/* CC5FD0 802427C0 27A20048 */  addiu     $v0, $sp, 0x48
/* CC5FD4 802427C4 AFA20020 */  sw        $v0, 0x20($sp)
/* CC5FD8 802427C8 E7A00010 */  swc1      $f0, 0x10($sp)
/* CC5FDC 802427CC E7A20014 */  swc1      $f2, 0x14($sp)
/* CC5FE0 802427D0 0C01BFA4 */  jal       fx_emote
/* CC5FE4 802427D4 E7A40018 */   swc1     $f4, 0x18($sp)
/* CC5FE8 802427D8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CC5FEC 802427DC 2403FFFB */  addiu     $v1, $zero, -5
/* CC5FF0 802427E0 00431024 */  and       $v0, $v0, $v1
/* CC5FF4 802427E4 08090A06 */  j         .L80242818
/* CC5FF8 802427E8 AE2200B0 */   sw       $v0, 0xb0($s1)
.L802427EC:
/* CC5FFC 802427EC 8E220000 */  lw        $v0, ($s1)
/* CC6000 802427F0 3C034000 */  lui       $v1, 0x4000
/* CC6004 802427F4 00431024 */  and       $v0, $v0, $v1
/* CC6008 802427F8 10400007 */  beqz      $v0, .L80242818
/* CC600C 802427FC 3C03BFFF */   lui      $v1, 0xbfff
/* CC6010 80242800 2402000C */  addiu     $v0, $zero, 0xc
/* CC6014 80242804 AE620070 */  sw        $v0, 0x70($s3)
/* CC6018 80242808 8E220000 */  lw        $v0, ($s1)
/* CC601C 8024280C 3463FFFF */  ori       $v1, $v1, 0xffff
/* CC6020 80242810 00431024 */  and       $v0, $v0, $v1
/* CC6024 80242814 AE220000 */  sw        $v0, ($s1)
.L80242818:
/* CC6028 80242818 8E220090 */  lw        $v0, 0x90($s1)
/* CC602C 8024281C 1840000C */  blez      $v0, .L80242850
/* CC6030 80242820 2442FFFF */   addiu    $v0, $v0, -1
/* CC6034 80242824 14400087 */  bnez      $v0, .L80242A44
/* CC6038 80242828 AE220090 */   sw       $v0, 0x90($s1)
/* CC603C 8024282C 3C03FFAA */  lui       $v1, 0xffaa
/* CC6040 80242830 8E420028 */  lw        $v0, 0x28($s2)
/* CC6044 80242834 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* CC6048 80242838 00431021 */  addu      $v0, $v0, $v1
/* CC604C 8024283C 2C420002 */  sltiu     $v0, $v0, 2
/* CC6050 80242840 10400003 */  beqz      $v0, .L80242850
/* CC6054 80242844 3C020055 */   lui      $v0, 0x55
/* CC6058 80242848 3442000C */  ori       $v0, $v0, 0xc
/* CC605C 8024284C AE420028 */  sw        $v0, 0x28($s2)
.L80242850:
/* CC6060 80242850 8E630070 */  lw        $v1, 0x70($s3)
/* CC6064 80242854 2402000C */  addiu     $v0, $zero, 0xc
/* CC6068 80242858 10620048 */  beq       $v1, $v0, .L8024297C
/* CC606C 8024285C 2862000D */   slti     $v0, $v1, 0xd
/* CC6070 80242860 1040000F */  beqz      $v0, .L802428A0
/* CC6074 80242864 24100001 */   addiu    $s0, $zero, 1
/* CC6078 80242868 1070001E */  beq       $v1, $s0, .L802428E4
/* CC607C 8024286C 28620002 */   slti     $v0, $v1, 2
/* CC6080 80242870 10400005 */  beqz      $v0, .L80242888
/* CC6084 80242874 24020002 */   addiu    $v0, $zero, 2
/* CC6088 80242878 10600015 */  beqz      $v1, .L802428D0
/* CC608C 8024287C 0260202D */   daddu    $a0, $s3, $zero
/* CC6090 80242880 08090A76 */  j         .L802429D8
/* CC6094 80242884 00000000 */   nop
.L80242888:
/* CC6098 80242888 1062001C */  beq       $v1, $v0, .L802428FC
/* CC609C 8024288C 24020003 */   addiu    $v0, $zero, 3
/* CC60A0 80242890 10620035 */  beq       $v1, $v0, .L80242968
/* CC60A4 80242894 0260202D */   daddu    $a0, $s3, $zero
/* CC60A8 80242898 08090A76 */  j         .L802429D8
/* CC60AC 8024289C 00000000 */   nop
.L802428A0:
/* CC60B0 802428A0 2402000E */  addiu     $v0, $zero, 0xe
/* CC60B4 802428A4 1062003F */  beq       $v1, $v0, .L802429A4
/* CC60B8 802428A8 0062102A */   slt      $v0, $v1, $v0
/* CC60BC 802428AC 14400038 */  bnez      $v0, .L80242990
/* CC60C0 802428B0 0260202D */   daddu    $a0, $s3, $zero
/* CC60C4 802428B4 2402000F */  addiu     $v0, $zero, 0xf
/* CC60C8 802428B8 10620040 */  beq       $v1, $v0, .L802429BC
/* CC60CC 802428BC 24020063 */   addiu    $v0, $zero, 0x63
/* CC60D0 802428C0 10620043 */  beq       $v1, $v0, .L802429D0
/* CC60D4 802428C4 00000000 */   nop
/* CC60D8 802428C8 08090A76 */  j         .L802429D8
/* CC60DC 802428CC 00000000 */   nop
.L802428D0:
/* CC60E0 802428D0 0280282D */  daddu     $a1, $s4, $zero
/* CC60E4 802428D4 0C012568 */  jal       func_800495A0
/* CC60E8 802428D8 02A0302D */   daddu    $a2, $s5, $zero
/* CC60EC 802428DC 96220086 */  lhu       $v0, 0x86($s1)
/* CC60F0 802428E0 A64200A8 */  sh        $v0, 0xa8($s2)
.L802428E4:
/* CC60F4 802428E4 0260202D */  daddu     $a0, $s3, $zero
/* CC60F8 802428E8 0280282D */  daddu     $a1, $s4, $zero
/* CC60FC 802428EC 0C0125AE */  jal       func_800496B8
/* CC6100 802428F0 02A0302D */   daddu    $a2, $s5, $zero
/* CC6104 802428F4 08090A76 */  j         .L802429D8
/* CC6108 802428F8 00000000 */   nop
.L802428FC:
/* CC610C 802428FC 0260202D */  daddu     $a0, $s3, $zero
/* CC6110 80242900 0280282D */  daddu     $a1, $s4, $zero
/* CC6114 80242904 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* CC6118 80242908 02A0302D */   daddu    $a2, $s5, $zero
/* CC611C 8024290C 8E230088 */  lw        $v1, 0x88($s1)
/* CC6120 80242910 24020006 */  addiu     $v0, $zero, 6
/* CC6124 80242914 14620014 */  bne       $v1, $v0, .L80242968
/* CC6128 80242918 0260202D */   daddu    $a0, $s3, $zero
/* CC612C 8024291C 0C00A67F */  jal       rand_int
/* CC6130 80242920 24040064 */   addiu    $a0, $zero, 0x64
/* CC6134 80242924 28420021 */  slti      $v0, $v0, 0x21
/* CC6138 80242928 5040000F */  beql      $v0, $zero, .L80242968
/* CC613C 8024292C 0260202D */   daddu    $a0, $s3, $zero
/* CC6140 80242930 8E22008C */  lw        $v0, 0x8c($s1)
/* CC6144 80242934 10400005 */  beqz      $v0, .L8024294C
/* CC6148 80242938 3C020055 */   lui      $v0, 0x55
/* CC614C 8024293C 3442002F */  ori       $v0, $v0, 0x2f
/* CC6150 80242940 AE20008C */  sw        $zero, 0x8c($s1)
/* CC6154 80242944 08090A56 */  j         .L80242958
/* CC6158 80242948 A22000B5 */   sb       $zero, 0xb5($s1)
.L8024294C:
/* CC615C 8024294C 3442002E */  ori       $v0, $v0, 0x2e
/* CC6160 80242950 AE30008C */  sw        $s0, 0x8c($s1)
/* CC6164 80242954 A23000B5 */  sb        $s0, 0xb5($s1)
.L80242958:
/* CC6168 80242958 AE420028 */  sw        $v0, 0x28($s2)
/* CC616C 8024295C 24020007 */  addiu     $v0, $zero, 7
/* CC6170 80242960 08090A91 */  j         .L80242A44
/* CC6174 80242964 AE220090 */   sw       $v0, 0x90($s1)
.L80242968:
/* CC6178 80242968 0280282D */  daddu     $a1, $s4, $zero
/* CC617C 8024296C 0C012701 */  jal       func_80049C04
/* CC6180 80242970 02A0302D */   daddu    $a2, $s5, $zero
/* CC6184 80242974 08090A76 */  j         .L802429D8
/* CC6188 80242978 00000000 */   nop
.L8024297C:
/* CC618C 8024297C 0260202D */  daddu     $a0, $s3, $zero
/* CC6190 80242980 0280282D */  daddu     $a1, $s4, $zero
/* CC6194 80242984 0C0908A6 */  jal       flo_13_set_script_owner_npc_anim
/* CC6198 80242988 02A0302D */   daddu    $a2, $s5, $zero
/* CC619C 8024298C 0260202D */  daddu     $a0, $s3, $zero
.L80242990:
/* CC61A0 80242990 0280282D */  daddu     $a1, $s4, $zero
/* CC61A4 80242994 0C0908C5 */  jal       func_80242314_CC5B24
/* CC61A8 80242998 02A0302D */   daddu    $a2, $s5, $zero
/* CC61AC 8024299C 08090A76 */  j         .L802429D8
/* CC61B0 802429A0 00000000 */   nop
.L802429A4:
/* CC61B4 802429A4 0260202D */  daddu     $a0, $s3, $zero
/* CC61B8 802429A8 0280282D */  daddu     $a1, $s4, $zero
/* CC61BC 802429AC 0C090912 */  jal       func_80242448_CC5C58
/* CC61C0 802429B0 02A0302D */   daddu    $a2, $s5, $zero
/* CC61C4 802429B4 08090A76 */  j         .L802429D8
/* CC61C8 802429B8 00000000 */   nop
.L802429BC:
/* CC61CC 802429BC 0280282D */  daddu     $a1, $s4, $zero
/* CC61D0 802429C0 0C09096B */  jal       func_802425AC_CC5DBC
/* CC61D4 802429C4 02A0302D */   daddu    $a2, $s5, $zero
/* CC61D8 802429C8 08090A76 */  j         .L802429D8
/* CC61DC 802429CC 00000000 */   nop
.L802429D0:
/* CC61E0 802429D0 0C0129CF */  jal       func_8004A73C
/* CC61E4 802429D4 0260202D */   daddu    $a0, $s3, $zero
.L802429D8:
/* CC61E8 802429D8 8E230088 */  lw        $v1, 0x88($s1)
/* CC61EC 802429DC 24020006 */  addiu     $v0, $zero, 6
/* CC61F0 802429E0 14620019 */  bne       $v1, $v0, .L80242A48
/* CC61F4 802429E4 0000102D */   daddu    $v0, $zero, $zero
/* CC61F8 802429E8 8E22008C */  lw        $v0, 0x8c($s1)
/* CC61FC 802429EC 10400003 */  beqz      $v0, .L802429FC
/* CC6200 802429F0 24020001 */   addiu    $v0, $zero, 1
/* CC6204 802429F4 08090A80 */  j         .L80242A00
/* CC6208 802429F8 A22200B5 */   sb       $v0, 0xb5($s1)
.L802429FC:
/* CC620C 802429FC A22000B5 */  sb        $zero, 0xb5($s1)
.L80242A00:
/* CC6210 80242A00 8E22008C */  lw        $v0, 0x8c($s1)
/* CC6214 80242A04 1040000F */  beqz      $v0, .L80242A44
/* CC6218 80242A08 3C03FFAA */   lui      $v1, 0xffaa
/* CC621C 80242A0C 8E420028 */  lw        $v0, 0x28($s2)
/* CC6220 80242A10 3463FFFC */  ori       $v1, $v1, 0xfffc
/* CC6224 80242A14 00431821 */  addu      $v1, $v0, $v1
/* CC6228 80242A18 2C620015 */  sltiu     $v0, $v1, 0x15
/* CC622C 80242A1C 10400009 */  beqz      $v0, .L80242A44
/* CC6230 80242A20 00031080 */   sll      $v0, $v1, 2
/* CC6234 80242A24 3C018024 */  lui       $at, %hi(D_80247A90)
/* CC6238 80242A28 00220821 */  addu      $at, $at, $v0
/* CC623C 80242A2C 8C227A90 */  lw        $v0, %lo(D_80247A90)($at)
/* CC6240 80242A30 00400008 */  jr        $v0
/* CC6244 80242A34 00000000 */   nop
/* CC6248 80242A38 8E420028 */  lw        $v0, 0x28($s2)
/* CC624C 80242A3C 24420001 */  addiu     $v0, $v0, 1
/* CC6250 80242A40 AE420028 */  sw        $v0, 0x28($s2)
.L80242A44:
/* CC6254 80242A44 0000102D */  daddu     $v0, $zero, $zero
.L80242A48:
/* CC6258 80242A48 8FBF0068 */  lw        $ra, 0x68($sp)
/* CC625C 80242A4C 8FB50064 */  lw        $s5, 0x64($sp)
/* CC6260 80242A50 8FB40060 */  lw        $s4, 0x60($sp)
/* CC6264 80242A54 8FB3005C */  lw        $s3, 0x5c($sp)
/* CC6268 80242A58 8FB20058 */  lw        $s2, 0x58($sp)
/* CC626C 80242A5C 8FB10054 */  lw        $s1, 0x54($sp)
/* CC6270 80242A60 8FB00050 */  lw        $s0, 0x50($sp)
/* CC6274 80242A64 03E00008 */  jr        $ra
/* CC6278 80242A68 27BD0070 */   addiu    $sp, $sp, 0x70
