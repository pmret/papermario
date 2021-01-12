.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_71B1A0
/* 71B1A0 802A1000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 71B1A4 802A1004 AFB50044 */  sw        $s5, 0x44($sp)
/* 71B1A8 802A1008 0080A82D */  daddu     $s5, $a0, $zero
/* 71B1AC 802A100C AFB10034 */  sw        $s1, 0x34($sp)
/* 71B1B0 802A1010 0000882D */  daddu     $s1, $zero, $zero
/* 71B1B4 802A1014 2405001D */  addiu     $a1, $zero, 0x1d
/* 71B1B8 802A1018 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 71B1BC 802A101C 4480A000 */  mtc1      $zero, $f20
/* 71B1C0 802A1020 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 71B1C4 802A1024 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 71B1C8 802A1028 AFBF0048 */  sw        $ra, 0x48($sp)
/* 71B1CC 802A102C AFB40040 */  sw        $s4, 0x40($sp)
/* 71B1D0 802A1030 AFB3003C */  sw        $s3, 0x3c($sp)
/* 71B1D4 802A1034 AFB20038 */  sw        $s2, 0x38($sp)
/* 71B1D8 802A1038 AFB00030 */  sw        $s0, 0x30($sp)
/* 71B1DC 802A103C F7B80060 */  sdc1      $f24, 0x60($sp)
/* 71B1E0 802A1040 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 71B1E4 802A1044 8C5300D8 */  lw        $s3, 0xd8($v0)
/* 71B1E8 802A1048 8442017A */  lh        $v0, 0x17a($v0)
/* 71B1EC 802A104C 0260202D */  daddu     $a0, $s3, $zero
/* 71B1F0 802A1050 00021140 */  sll       $v0, $v0, 5
/* 71B1F4 802A1054 3C128008 */  lui       $s2, %hi(gItemTable+0xC)
/* 71B1F8 802A1058 02429021 */  addu      $s2, $s2, $v0
/* 71B1FC 802A105C 865278EC */  lh        $s2, %lo(gItemTable+0xC)($s2)
/* 71B200 802A1060 92620191 */  lbu       $v0, 0x191($s3)
/* 71B204 802A1064 C6620148 */  lwc1      $f2, 0x148($s3)
/* 71B208 802A1068 44820000 */  mtc1      $v0, $f0
/* 71B20C 802A106C 00000000 */  nop       
/* 71B210 802A1070 46800020 */  cvt.s.w   $f0, $f0
/* 71B214 802A1074 0C099CAB */  jal       heroes_is_ability_active
/* 71B218 802A1078 46001580 */   add.s    $f22, $f2, $f0
/* 71B21C 802A107C 50400048 */  beql      $v0, $zero, .L802A11A0
/* 71B220 802A1080 AEB10084 */   sw       $s1, 0x84($s5)
/* 71B224 802A1084 1A400045 */  blez      $s2, .L802A119C
/* 71B228 802A1088 3C0451EB */   lui      $a0, 0x51eb
/* 71B22C 802A108C 3484851F */  ori       $a0, $a0, 0x851f
/* 71B230 802A1090 00121880 */  sll       $v1, $s2, 2
/* 71B234 802A1094 00721821 */  addu      $v1, $v1, $s2
/* 71B238 802A1098 00031100 */  sll       $v0, $v1, 4
/* 71B23C 802A109C 00431023 */  subu      $v0, $v0, $v1
/* 71B240 802A10A0 24420063 */  addiu     $v0, $v0, 0x63
/* 71B244 802A10A4 00440018 */  mult      $v0, $a0
/* 71B248 802A10A8 000217C3 */  sra       $v0, $v0, 0x1f
/* 71B24C 802A10AC 00004010 */  mfhi      $t0
/* 71B250 802A10B0 00081943 */  sra       $v1, $t0, 5
/* 71B254 802A10B4 00629023 */  subu      $s2, $v1, $v0
/* 71B258 802A10B8 0232102A */  slt       $v0, $s1, $s2
/* 71B25C 802A10BC 10400019 */  beqz      $v0, .L802A1124
/* 71B260 802A10C0 0220802D */   daddu    $s0, $s1, $zero
/* 71B264 802A10C4 24140017 */  addiu     $s4, $zero, 0x17
/* 71B268 802A10C8 3C0141F0 */  lui       $at, 0x41f0
/* 71B26C 802A10CC 4481C000 */  mtc1      $at, $f24
/* 71B270 802A10D0 24110001 */  addiu     $s1, $zero, 1
.L802A10D4:
/* 71B274 802A10D4 C6600144 */  lwc1      $f0, 0x144($s3)
/* 71B278 802A10D8 C662014C */  lwc1      $f2, 0x14c($s3)
/* 71B27C 802A10DC 4600A10D */  trunc.w.s $f4, $f20
/* 71B280 802A10E0 E7A40018 */  swc1      $f4, 0x18($sp)
/* 71B284 802A10E4 24040157 */  addiu     $a0, $zero, 0x157
/* 71B288 802A10E8 AFB10014 */  sw        $s1, 0x14($sp)
/* 71B28C 802A10EC 26310003 */  addiu     $s1, $s1, 3
/* 71B290 802A10F0 26100001 */  addiu     $s0, $s0, 1
/* 71B294 802A10F4 4406B000 */  mfc1      $a2, $f22
/* 71B298 802A10F8 44050000 */  mfc1      $a1, $f0
/* 71B29C 802A10FC 44071000 */  mfc1      $a3, $f2
/* 71B2A0 802A1100 4618A500 */  add.s     $f20, $f20, $f24
/* 71B2A4 802A1104 AFB40010 */  sw        $s4, 0x10($sp)
/* 71B2A8 802A1108 0C04C4FD */  jal       make_item_entity
/* 71B2AC 802A110C AFA0001C */   sw       $zero, 0x1c($sp)
/* 71B2B0 802A1110 0C03A830 */  jal       add_coins
/* 71B2B4 802A1114 24040001 */   addiu    $a0, $zero, 1
/* 71B2B8 802A1118 0212102A */  slt       $v0, $s0, $s2
/* 71B2BC 802A111C 1440FFED */  bnez      $v0, .L802A10D4
/* 71B2C0 802A1120 00000000 */   nop      
.L802A1124:
/* 71B2C4 802A1124 00101040 */  sll       $v0, $s0, 1
/* 71B2C8 802A1128 00501021 */  addu      $v0, $v0, $s0
/* 71B2CC 802A112C 2451001E */  addiu     $s1, $v0, 0x1e
/* 71B2D0 802A1130 C6600144 */  lwc1      $f0, 0x144($s3)
/* 71B2D4 802A1134 C6760148 */  lwc1      $f22, 0x148($s3)
/* 71B2D8 802A1138 C662014C */  lwc1      $f2, 0x14c($s3)
/* 71B2DC 802A113C 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 71B2E0 802A1140 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 71B2E4 802A1144 27A20020 */  addiu     $v0, $sp, 0x20
/* 71B2E8 802A1148 AFA20010 */  sw        $v0, 0x10($sp)
/* 71B2EC 802A114C 27A20024 */  addiu     $v0, $sp, 0x24
/* 71B2F0 802A1150 AFA20014 */  sw        $v0, 0x14($sp)
/* 71B2F4 802A1154 44050000 */  mfc1      $a1, $f0
/* 71B2F8 802A1158 4406B000 */  mfc1      $a2, $f22
/* 71B2FC 802A115C 44071000 */  mfc1      $a3, $f2
/* 71B300 802A1160 27A20028 */  addiu     $v0, $sp, 0x28
/* 71B304 802A1164 0C00B94E */  jal       get_screen_coords
/* 71B308 802A1168 AFA20018 */   sw       $v0, 0x18($sp)
/* 71B30C 802A116C 3C048011 */  lui       $a0, %hi(D_80108A64)
/* 71B310 802A1170 24848A64 */  addiu     $a0, $a0, %lo(D_80108A64)
/* 71B314 802A1174 0C050529 */  jal       create_icon
/* 71B318 802A1178 00000000 */   nop      
/* 71B31C 802A117C 8FA50020 */  lw        $a1, 0x20($sp)
/* 71B320 802A1180 8FA60024 */  lw        $a2, 0x24($sp)
/* 71B324 802A1184 0040202D */  daddu     $a0, $v0, $zero
/* 71B328 802A1188 3C01802A */  lui       $at, %hi(D_802A1C90)
/* 71B32C 802A118C AC241C90 */  sw        $a0, %lo(D_802A1C90)($at)
/* 71B330 802A1190 24A50024 */  addiu     $a1, $a1, 0x24
/* 71B334 802A1194 0C051261 */  jal       set_icon_render_pos
/* 71B338 802A1198 24C6FFC1 */   addiu    $a2, $a2, -0x3f
.L802A119C:
/* 71B33C 802A119C AEB10084 */  sw        $s1, 0x84($s5)
.L802A11A0:
/* 71B340 802A11A0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 71B344 802A11A4 8FB50044 */  lw        $s5, 0x44($sp)
/* 71B348 802A11A8 8FB40040 */  lw        $s4, 0x40($sp)
/* 71B34C 802A11AC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 71B350 802A11B0 8FB20038 */  lw        $s2, 0x38($sp)
/* 71B354 802A11B4 8FB10034 */  lw        $s1, 0x34($sp)
/* 71B358 802A11B8 8FB00030 */  lw        $s0, 0x30($sp)
/* 71B35C 802A11BC D7B80060 */  ldc1      $f24, 0x60($sp)
/* 71B360 802A11C0 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 71B364 802A11C4 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 71B368 802A11C8 24020002 */  addiu     $v0, $zero, 2
/* 71B36C 802A11CC 03E00008 */  jr        $ra
/* 71B370 802A11D0 27BD0068 */   addiu    $sp, $sp, 0x68
