.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B0_949F10
/* 949F10 802400B0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 949F14 802400B4 AFB10054 */  sw        $s1, 0x54($sp)
/* 949F18 802400B8 0080882D */  daddu     $s1, $a0, $zero
/* 949F1C 802400BC AFBF005C */  sw        $ra, 0x5c($sp)
/* 949F20 802400C0 AFB20058 */  sw        $s2, 0x58($sp)
/* 949F24 802400C4 AFB00050 */  sw        $s0, 0x50($sp)
/* 949F28 802400C8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 949F2C 802400CC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 949F30 802400D0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 949F34 802400D4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 949F38 802400D8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 949F3C 802400DC 8E30000C */  lw        $s0, 0xc($s1)
/* 949F40 802400E0 8E050000 */  lw        $a1, ($s0)
/* 949F44 802400E4 0C0B1EAF */  jal       get_variable
/* 949F48 802400E8 26100004 */   addiu    $s0, $s0, 4
/* 949F4C 802400EC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 949F50 802400F0 0040202D */   daddu    $a0, $v0, $zero
/* 949F54 802400F4 8E050000 */  lw        $a1, ($s0)
/* 949F58 802400F8 26100004 */  addiu     $s0, $s0, 4
/* 949F5C 802400FC 0220202D */  daddu     $a0, $s1, $zero
/* 949F60 80240100 0C0B210B */  jal       get_float_variable
/* 949F64 80240104 0040902D */   daddu    $s2, $v0, $zero
/* 949F68 80240108 8E050000 */  lw        $a1, ($s0)
/* 949F6C 8024010C 26100004 */  addiu     $s0, $s0, 4
/* 949F70 80240110 0220202D */  daddu     $a0, $s1, $zero
/* 949F74 80240114 0C0B210B */  jal       get_float_variable
/* 949F78 80240118 46000706 */   mov.s    $f28, $f0
/* 949F7C 8024011C 8E050000 */  lw        $a1, ($s0)
/* 949F80 80240120 26100004 */  addiu     $s0, $s0, 4
/* 949F84 80240124 0220202D */  daddu     $a0, $s1, $zero
/* 949F88 80240128 0C0B210B */  jal       get_float_variable
/* 949F8C 8024012C 46000686 */   mov.s    $f26, $f0
/* 949F90 80240130 0220202D */  daddu     $a0, $s1, $zero
/* 949F94 80240134 8E050000 */  lw        $a1, ($s0)
/* 949F98 80240138 0C0B210B */  jal       get_float_variable
/* 949F9C 8024013C 46000586 */   mov.s    $f22, $f0
/* 949FA0 80240140 0240202D */  daddu     $a0, $s2, $zero
/* 949FA4 80240144 0C046B4C */  jal       get_model_from_list_index
/* 949FA8 80240148 46000606 */   mov.s    $f24, $f0
/* 949FAC 8024014C 0040882D */  daddu     $s1, $v0, $zero
/* 949FB0 80240150 96220000 */  lhu       $v0, ($s1)
/* 949FB4 80240154 30420400 */  andi      $v0, $v0, 0x400
/* 949FB8 80240158 1440001E */  bnez      $v0, .L802401D4
/* 949FBC 8024015C 26300058 */   addiu    $s0, $s1, 0x58
/* 949FC0 80240160 4480A000 */  mtc1      $zero, $f20
/* 949FC4 80240164 4406B000 */  mfc1      $a2, $f22
/* 949FC8 80240168 4405A000 */  mfc1      $a1, $f20
/* 949FCC 8024016C 4407A000 */  mfc1      $a3, $f20
/* 949FD0 80240170 0C019E40 */  jal       guTranslateF
/* 949FD4 80240174 0200202D */   daddu    $a0, $s0, $zero
/* 949FD8 80240178 4405E000 */  mfc1      $a1, $f28
/* 949FDC 8024017C 4406D000 */  mfc1      $a2, $f26
/* 949FE0 80240180 4407C000 */  mfc1      $a3, $f24
/* 949FE4 80240184 0C090010 */  jal       func_80240040_949EA0
/* 949FE8 80240188 27A40010 */   addiu    $a0, $sp, 0x10
/* 949FEC 8024018C 27A40010 */  addiu     $a0, $sp, 0x10
/* 949FF0 80240190 0200282D */  daddu     $a1, $s0, $zero
/* 949FF4 80240194 0C019D80 */  jal       guMtxCatF
/* 949FF8 80240198 0200302D */   daddu    $a2, $s0, $zero
/* 949FFC 8024019C 27A40010 */  addiu     $a0, $sp, 0x10
/* 94A000 802401A0 4600B587 */  neg.s     $f22, $f22
/* 94A004 802401A4 4405A000 */  mfc1      $a1, $f20
/* 94A008 802401A8 4406B000 */  mfc1      $a2, $f22
/* 94A00C 802401AC 0C019E40 */  jal       guTranslateF
/* 94A010 802401B0 00A0382D */   daddu    $a3, $a1, $zero
/* 94A014 802401B4 27A40010 */  addiu     $a0, $sp, 0x10
/* 94A018 802401B8 0200282D */  daddu     $a1, $s0, $zero
/* 94A01C 802401BC 0C019D80 */  jal       guMtxCatF
/* 94A020 802401C0 00A0302D */   daddu    $a2, $a1, $zero
/* 94A024 802401C4 96220000 */  lhu       $v0, ($s1)
/* 94A028 802401C8 34421400 */  ori       $v0, $v0, 0x1400
/* 94A02C 802401CC 08090093 */  j         .L8024024C
/* 94A030 802401D0 A6220000 */   sh       $v0, ($s1)
.L802401D4:
/* 94A034 802401D4 4480A000 */  mtc1      $zero, $f20
/* 94A038 802401D8 4406B000 */  mfc1      $a2, $f22
/* 94A03C 802401DC 4405A000 */  mfc1      $a1, $f20
/* 94A040 802401E0 4407A000 */  mfc1      $a3, $f20
/* 94A044 802401E4 0C019E40 */  jal       guTranslateF
/* 94A048 802401E8 27A40010 */   addiu    $a0, $sp, 0x10
/* 94A04C 802401EC 27A40010 */  addiu     $a0, $sp, 0x10
/* 94A050 802401F0 26300058 */  addiu     $s0, $s1, 0x58
/* 94A054 802401F4 0200282D */  daddu     $a1, $s0, $zero
/* 94A058 802401F8 0C019D80 */  jal       guMtxCatF
/* 94A05C 802401FC 0200302D */   daddu    $a2, $s0, $zero
/* 94A060 80240200 4405E000 */  mfc1      $a1, $f28
/* 94A064 80240204 4406D000 */  mfc1      $a2, $f26
/* 94A068 80240208 4407C000 */  mfc1      $a3, $f24
/* 94A06C 8024020C 0C090010 */  jal       func_80240040_949EA0
/* 94A070 80240210 27A40010 */   addiu    $a0, $sp, 0x10
/* 94A074 80240214 27A40010 */  addiu     $a0, $sp, 0x10
/* 94A078 80240218 0200282D */  daddu     $a1, $s0, $zero
/* 94A07C 8024021C 0C019D80 */  jal       guMtxCatF
/* 94A080 80240220 0200302D */   daddu    $a2, $s0, $zero
/* 94A084 80240224 27A40010 */  addiu     $a0, $sp, 0x10
/* 94A088 80240228 4600B587 */  neg.s     $f22, $f22
/* 94A08C 8024022C 4405A000 */  mfc1      $a1, $f20
/* 94A090 80240230 4406B000 */  mfc1      $a2, $f22
/* 94A094 80240234 0C019E40 */  jal       guTranslateF
/* 94A098 80240238 00A0382D */   daddu    $a3, $a1, $zero
/* 94A09C 8024023C 27A40010 */  addiu     $a0, $sp, 0x10
/* 94A0A0 80240240 0200282D */  daddu     $a1, $s0, $zero
/* 94A0A4 80240244 0C019D80 */  jal       guMtxCatF
/* 94A0A8 80240248 00A0302D */   daddu    $a2, $a1, $zero
.L8024024C:
/* 94A0AC 8024024C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 94A0B0 80240250 8FB20058 */  lw        $s2, 0x58($sp)
/* 94A0B4 80240254 8FB10054 */  lw        $s1, 0x54($sp)
/* 94A0B8 80240258 8FB00050 */  lw        $s0, 0x50($sp)
/* 94A0BC 8024025C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 94A0C0 80240260 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 94A0C4 80240264 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 94A0C8 80240268 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 94A0CC 8024026C D7B40060 */  ldc1      $f20, 0x60($sp)
/* 94A0D0 80240270 24020002 */  addiu     $v0, $zero, 2
/* 94A0D4 80240274 03E00008 */  jr        $ra
/* 94A0D8 80240278 27BD0088 */   addiu    $sp, $sp, 0x88
/* 94A0DC 8024027C 00000000 */  nop       
