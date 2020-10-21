.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B0_CC0EE0
/* CC0EE0 802400B0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CC0EE4 802400B4 AFB10054 */  sw        $s1, 0x54($sp)
/* CC0EE8 802400B8 0080882D */  daddu     $s1, $a0, $zero
/* CC0EEC 802400BC AFBF005C */  sw        $ra, 0x5c($sp)
/* CC0EF0 802400C0 AFB20058 */  sw        $s2, 0x58($sp)
/* CC0EF4 802400C4 AFB00050 */  sw        $s0, 0x50($sp)
/* CC0EF8 802400C8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* CC0EFC 802400CC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CC0F00 802400D0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CC0F04 802400D4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* CC0F08 802400D8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CC0F0C 802400DC 8E30000C */  lw        $s0, 0xc($s1)
/* CC0F10 802400E0 8E050000 */  lw        $a1, ($s0)
/* CC0F14 802400E4 0C0B1EAF */  jal       get_variable
/* CC0F18 802400E8 26100004 */   addiu    $s0, $s0, 4
/* CC0F1C 802400EC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* CC0F20 802400F0 0040202D */   daddu    $a0, $v0, $zero
/* CC0F24 802400F4 8E050000 */  lw        $a1, ($s0)
/* CC0F28 802400F8 26100004 */  addiu     $s0, $s0, 4
/* CC0F2C 802400FC 0220202D */  daddu     $a0, $s1, $zero
/* CC0F30 80240100 0C0B210B */  jal       get_float_variable
/* CC0F34 80240104 0040902D */   daddu    $s2, $v0, $zero
/* CC0F38 80240108 8E050000 */  lw        $a1, ($s0)
/* CC0F3C 8024010C 26100004 */  addiu     $s0, $s0, 4
/* CC0F40 80240110 0220202D */  daddu     $a0, $s1, $zero
/* CC0F44 80240114 0C0B210B */  jal       get_float_variable
/* CC0F48 80240118 46000706 */   mov.s    $f28, $f0
/* CC0F4C 8024011C 8E050000 */  lw        $a1, ($s0)
/* CC0F50 80240120 26100004 */  addiu     $s0, $s0, 4
/* CC0F54 80240124 0220202D */  daddu     $a0, $s1, $zero
/* CC0F58 80240128 0C0B210B */  jal       get_float_variable
/* CC0F5C 8024012C 46000686 */   mov.s    $f26, $f0
/* CC0F60 80240130 0220202D */  daddu     $a0, $s1, $zero
/* CC0F64 80240134 8E050000 */  lw        $a1, ($s0)
/* CC0F68 80240138 0C0B210B */  jal       get_float_variable
/* CC0F6C 8024013C 46000586 */   mov.s    $f22, $f0
/* CC0F70 80240140 0240202D */  daddu     $a0, $s2, $zero
/* CC0F74 80240144 0C046B4C */  jal       get_model_from_list_index
/* CC0F78 80240148 46000606 */   mov.s    $f24, $f0
/* CC0F7C 8024014C 0040882D */  daddu     $s1, $v0, $zero
/* CC0F80 80240150 96220000 */  lhu       $v0, ($s1)
/* CC0F84 80240154 30420400 */  andi      $v0, $v0, 0x400
/* CC0F88 80240158 1440001E */  bnez      $v0, .L802401D4
/* CC0F8C 8024015C 26300058 */   addiu    $s0, $s1, 0x58
/* CC0F90 80240160 4480A000 */  mtc1      $zero, $f20
/* CC0F94 80240164 4406B000 */  mfc1      $a2, $f22
/* CC0F98 80240168 4405A000 */  mfc1      $a1, $f20
/* CC0F9C 8024016C 4407A000 */  mfc1      $a3, $f20
/* CC0FA0 80240170 0C019E40 */  jal       guTranslateF
/* CC0FA4 80240174 0200202D */   daddu    $a0, $s0, $zero
/* CC0FA8 80240178 4405E000 */  mfc1      $a1, $f28
/* CC0FAC 8024017C 4406D000 */  mfc1      $a2, $f26
/* CC0FB0 80240180 4407C000 */  mfc1      $a3, $f24
/* CC0FB4 80240184 0C090010 */  jal       func_80240040_CC0E70
/* CC0FB8 80240188 27A40010 */   addiu    $a0, $sp, 0x10
/* CC0FBC 8024018C 27A40010 */  addiu     $a0, $sp, 0x10
/* CC0FC0 80240190 0200282D */  daddu     $a1, $s0, $zero
/* CC0FC4 80240194 0C019D80 */  jal       guMtxCatF
/* CC0FC8 80240198 0200302D */   daddu    $a2, $s0, $zero
/* CC0FCC 8024019C 27A40010 */  addiu     $a0, $sp, 0x10
/* CC0FD0 802401A0 4600B587 */  neg.s     $f22, $f22
/* CC0FD4 802401A4 4405A000 */  mfc1      $a1, $f20
/* CC0FD8 802401A8 4406B000 */  mfc1      $a2, $f22
/* CC0FDC 802401AC 0C019E40 */  jal       guTranslateF
/* CC0FE0 802401B0 00A0382D */   daddu    $a3, $a1, $zero
/* CC0FE4 802401B4 27A40010 */  addiu     $a0, $sp, 0x10
/* CC0FE8 802401B8 0200282D */  daddu     $a1, $s0, $zero
/* CC0FEC 802401BC 0C019D80 */  jal       guMtxCatF
/* CC0FF0 802401C0 00A0302D */   daddu    $a2, $a1, $zero
/* CC0FF4 802401C4 96220000 */  lhu       $v0, ($s1)
/* CC0FF8 802401C8 34421400 */  ori       $v0, $v0, 0x1400
/* CC0FFC 802401CC 08090093 */  j         .L8024024C
/* CC1000 802401D0 A6220000 */   sh       $v0, ($s1)
.L802401D4:
/* CC1004 802401D4 4480A000 */  mtc1      $zero, $f20
/* CC1008 802401D8 4406B000 */  mfc1      $a2, $f22
/* CC100C 802401DC 4405A000 */  mfc1      $a1, $f20
/* CC1010 802401E0 4407A000 */  mfc1      $a3, $f20
/* CC1014 802401E4 0C019E40 */  jal       guTranslateF
/* CC1018 802401E8 27A40010 */   addiu    $a0, $sp, 0x10
/* CC101C 802401EC 27A40010 */  addiu     $a0, $sp, 0x10
/* CC1020 802401F0 26300058 */  addiu     $s0, $s1, 0x58
/* CC1024 802401F4 0200282D */  daddu     $a1, $s0, $zero
/* CC1028 802401F8 0C019D80 */  jal       guMtxCatF
/* CC102C 802401FC 0200302D */   daddu    $a2, $s0, $zero
/* CC1030 80240200 4405E000 */  mfc1      $a1, $f28
/* CC1034 80240204 4406D000 */  mfc1      $a2, $f26
/* CC1038 80240208 4407C000 */  mfc1      $a3, $f24
/* CC103C 8024020C 0C090010 */  jal       func_80240040_CC0E70
/* CC1040 80240210 27A40010 */   addiu    $a0, $sp, 0x10
/* CC1044 80240214 27A40010 */  addiu     $a0, $sp, 0x10
/* CC1048 80240218 0200282D */  daddu     $a1, $s0, $zero
/* CC104C 8024021C 0C019D80 */  jal       guMtxCatF
/* CC1050 80240220 0200302D */   daddu    $a2, $s0, $zero
/* CC1054 80240224 27A40010 */  addiu     $a0, $sp, 0x10
/* CC1058 80240228 4600B587 */  neg.s     $f22, $f22
/* CC105C 8024022C 4405A000 */  mfc1      $a1, $f20
/* CC1060 80240230 4406B000 */  mfc1      $a2, $f22
/* CC1064 80240234 0C019E40 */  jal       guTranslateF
/* CC1068 80240238 00A0382D */   daddu    $a3, $a1, $zero
/* CC106C 8024023C 27A40010 */  addiu     $a0, $sp, 0x10
/* CC1070 80240240 0200282D */  daddu     $a1, $s0, $zero
/* CC1074 80240244 0C019D80 */  jal       guMtxCatF
/* CC1078 80240248 00A0302D */   daddu    $a2, $a1, $zero
.L8024024C:
/* CC107C 8024024C 8FBF005C */  lw        $ra, 0x5c($sp)
/* CC1080 80240250 8FB20058 */  lw        $s2, 0x58($sp)
/* CC1084 80240254 8FB10054 */  lw        $s1, 0x54($sp)
/* CC1088 80240258 8FB00050 */  lw        $s0, 0x50($sp)
/* CC108C 8024025C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* CC1090 80240260 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CC1094 80240264 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CC1098 80240268 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CC109C 8024026C D7B40060 */  ldc1      $f20, 0x60($sp)
/* CC10A0 80240270 24020002 */  addiu     $v0, $zero, 2
/* CC10A4 80240274 03E00008 */  jr        $ra
/* CC10A8 80240278 27BD0088 */   addiu    $sp, $sp, 0x88
