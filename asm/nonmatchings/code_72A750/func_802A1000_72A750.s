.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_72A750
/* 72A750 802A1000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 72A754 802A1004 AFB50044 */  sw        $s5, 0x44($sp)
/* 72A758 802A1008 0080A82D */  daddu     $s5, $a0, $zero
/* 72A75C 802A100C AFB10034 */  sw        $s1, 0x34($sp)
/* 72A760 802A1010 0000882D */  daddu     $s1, $zero, $zero
/* 72A764 802A1014 2405001D */  addiu     $a1, $zero, 0x1d
/* 72A768 802A1018 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 72A76C 802A101C 4480A000 */  mtc1      $zero, $f20
/* 72A770 802A1020 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 72A774 802A1024 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 72A778 802A1028 AFBF0048 */  sw        $ra, 0x48($sp)
/* 72A77C 802A102C AFB40040 */  sw        $s4, 0x40($sp)
/* 72A780 802A1030 AFB3003C */  sw        $s3, 0x3c($sp)
/* 72A784 802A1034 AFB20038 */  sw        $s2, 0x38($sp)
/* 72A788 802A1038 AFB00030 */  sw        $s0, 0x30($sp)
/* 72A78C 802A103C F7B80060 */  sdc1      $f24, 0x60($sp)
/* 72A790 802A1040 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 72A794 802A1044 8C5300D8 */  lw        $s3, 0xd8($v0)
/* 72A798 802A1048 8442017A */  lh        $v0, 0x17a($v0)
/* 72A79C 802A104C 0260202D */  daddu     $a0, $s3, $zero
/* 72A7A0 802A1050 00021140 */  sll       $v0, $v0, 5
/* 72A7A4 802A1054 3C128008 */  lui       $s2, %hi(gItemTable+0xC)
/* 72A7A8 802A1058 02429021 */  addu      $s2, $s2, $v0
/* 72A7AC 802A105C 865278EC */  lh        $s2, %lo(gItemTable+0xC)($s2)
/* 72A7B0 802A1060 92620191 */  lbu       $v0, 0x191($s3)
/* 72A7B4 802A1064 C6620148 */  lwc1      $f2, 0x148($s3)
/* 72A7B8 802A1068 44820000 */  mtc1      $v0, $f0
/* 72A7BC 802A106C 00000000 */  nop       
/* 72A7C0 802A1070 46800020 */  cvt.s.w   $f0, $f0
/* 72A7C4 802A1074 0C099CAB */  jal       heroes_is_ability_active
/* 72A7C8 802A1078 46001580 */   add.s    $f22, $f2, $f0
/* 72A7CC 802A107C 50400048 */  beql      $v0, $zero, .L802A11A0
/* 72A7D0 802A1080 AEB10084 */   sw       $s1, 0x84($s5)
/* 72A7D4 802A1084 1A400045 */  blez      $s2, .L802A119C
/* 72A7D8 802A1088 3C0451EB */   lui      $a0, 0x51eb
/* 72A7DC 802A108C 3484851F */  ori       $a0, $a0, 0x851f
/* 72A7E0 802A1090 00121880 */  sll       $v1, $s2, 2
/* 72A7E4 802A1094 00721821 */  addu      $v1, $v1, $s2
/* 72A7E8 802A1098 00031100 */  sll       $v0, $v1, 4
/* 72A7EC 802A109C 00431023 */  subu      $v0, $v0, $v1
/* 72A7F0 802A10A0 24420063 */  addiu     $v0, $v0, 0x63
/* 72A7F4 802A10A4 00440018 */  mult      $v0, $a0
/* 72A7F8 802A10A8 000217C3 */  sra       $v0, $v0, 0x1f
/* 72A7FC 802A10AC 00004010 */  mfhi      $t0
/* 72A800 802A10B0 00081943 */  sra       $v1, $t0, 5
/* 72A804 802A10B4 00629023 */  subu      $s2, $v1, $v0
/* 72A808 802A10B8 0232102A */  slt       $v0, $s1, $s2
/* 72A80C 802A10BC 10400019 */  beqz      $v0, .L802A1124
/* 72A810 802A10C0 0220802D */   daddu    $s0, $s1, $zero
/* 72A814 802A10C4 24140017 */  addiu     $s4, $zero, 0x17
/* 72A818 802A10C8 3C0141F0 */  lui       $at, 0x41f0
/* 72A81C 802A10CC 4481C000 */  mtc1      $at, $f24
/* 72A820 802A10D0 24110001 */  addiu     $s1, $zero, 1
.L802A10D4:
/* 72A824 802A10D4 C6600144 */  lwc1      $f0, 0x144($s3)
/* 72A828 802A10D8 C662014C */  lwc1      $f2, 0x14c($s3)
/* 72A82C 802A10DC 4600A10D */  trunc.w.s $f4, $f20
/* 72A830 802A10E0 E7A40018 */  swc1      $f4, 0x18($sp)
/* 72A834 802A10E4 24040157 */  addiu     $a0, $zero, 0x157
/* 72A838 802A10E8 AFB10014 */  sw        $s1, 0x14($sp)
/* 72A83C 802A10EC 26310003 */  addiu     $s1, $s1, 3
/* 72A840 802A10F0 26100001 */  addiu     $s0, $s0, 1
/* 72A844 802A10F4 4406B000 */  mfc1      $a2, $f22
/* 72A848 802A10F8 44050000 */  mfc1      $a1, $f0
/* 72A84C 802A10FC 44071000 */  mfc1      $a3, $f2
/* 72A850 802A1100 4618A500 */  add.s     $f20, $f20, $f24
/* 72A854 802A1104 AFB40010 */  sw        $s4, 0x10($sp)
/* 72A858 802A1108 0C04C4FD */  jal       make_item_entity
/* 72A85C 802A110C AFA0001C */   sw       $zero, 0x1c($sp)
/* 72A860 802A1110 0C03A830 */  jal       add_coins
/* 72A864 802A1114 24040001 */   addiu    $a0, $zero, 1
/* 72A868 802A1118 0212102A */  slt       $v0, $s0, $s2
/* 72A86C 802A111C 1440FFED */  bnez      $v0, .L802A10D4
/* 72A870 802A1120 00000000 */   nop      
.L802A1124:
/* 72A874 802A1124 00101040 */  sll       $v0, $s0, 1
/* 72A878 802A1128 00501021 */  addu      $v0, $v0, $s0
/* 72A87C 802A112C 2451001E */  addiu     $s1, $v0, 0x1e
/* 72A880 802A1130 C6600144 */  lwc1      $f0, 0x144($s3)
/* 72A884 802A1134 C6760148 */  lwc1      $f22, 0x148($s3)
/* 72A888 802A1138 C662014C */  lwc1      $f2, 0x14c($s3)
/* 72A88C 802A113C 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 72A890 802A1140 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 72A894 802A1144 27A20020 */  addiu     $v0, $sp, 0x20
/* 72A898 802A1148 AFA20010 */  sw        $v0, 0x10($sp)
/* 72A89C 802A114C 27A20024 */  addiu     $v0, $sp, 0x24
/* 72A8A0 802A1150 AFA20014 */  sw        $v0, 0x14($sp)
/* 72A8A4 802A1154 44050000 */  mfc1      $a1, $f0
/* 72A8A8 802A1158 4406B000 */  mfc1      $a2, $f22
/* 72A8AC 802A115C 44071000 */  mfc1      $a3, $f2
/* 72A8B0 802A1160 27A20028 */  addiu     $v0, $sp, 0x28
/* 72A8B4 802A1164 0C00B94E */  jal       get_screen_coords
/* 72A8B8 802A1168 AFA20018 */   sw       $v0, 0x18($sp)
/* 72A8BC 802A116C 3C048011 */  lui       $a0, %hi(D_80108A64)
/* 72A8C0 802A1170 24848A64 */  addiu     $a0, $a0, %lo(D_80108A64)
/* 72A8C4 802A1174 0C050529 */  jal       create_icon
/* 72A8C8 802A1178 00000000 */   nop      
/* 72A8CC 802A117C 8FA50020 */  lw        $a1, 0x20($sp)
/* 72A8D0 802A1180 8FA60024 */  lw        $a2, 0x24($sp)
/* 72A8D4 802A1184 0040202D */  daddu     $a0, $v0, $zero
/* 72A8D8 802A1188 3C01802A */  lui       $at, %hi(D_802A21C0)
/* 72A8DC 802A118C AC2421C0 */  sw        $a0, %lo(D_802A21C0)($at)
/* 72A8E0 802A1190 24A50024 */  addiu     $a1, $a1, 0x24
/* 72A8E4 802A1194 0C051261 */  jal       set_icon_render_pos
/* 72A8E8 802A1198 24C6FFC1 */   addiu    $a2, $a2, -0x3f
.L802A119C:
/* 72A8EC 802A119C AEB10084 */  sw        $s1, 0x84($s5)
.L802A11A0:
/* 72A8F0 802A11A0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 72A8F4 802A11A4 8FB50044 */  lw        $s5, 0x44($sp)
/* 72A8F8 802A11A8 8FB40040 */  lw        $s4, 0x40($sp)
/* 72A8FC 802A11AC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 72A900 802A11B0 8FB20038 */  lw        $s2, 0x38($sp)
/* 72A904 802A11B4 8FB10034 */  lw        $s1, 0x34($sp)
/* 72A908 802A11B8 8FB00030 */  lw        $s0, 0x30($sp)
/* 72A90C 802A11BC D7B80060 */  ldc1      $f24, 0x60($sp)
/* 72A910 802A11C0 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 72A914 802A11C4 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 72A918 802A11C8 24020002 */  addiu     $v0, $zero, 2
/* 72A91C 802A11CC 03E00008 */  jr        $ra
/* 72A920 802A11D0 27BD0068 */   addiu    $sp, $sp, 0x68
