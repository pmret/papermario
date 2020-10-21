.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240130_B7DA50
/* B7DA50 80240130 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B7DA54 80240134 AFB10054 */  sw        $s1, 0x54($sp)
/* B7DA58 80240138 0080882D */  daddu     $s1, $a0, $zero
/* B7DA5C 8024013C AFBF005C */  sw        $ra, 0x5c($sp)
/* B7DA60 80240140 AFB20058 */  sw        $s2, 0x58($sp)
/* B7DA64 80240144 AFB00050 */  sw        $s0, 0x50($sp)
/* B7DA68 80240148 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B7DA6C 8024014C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B7DA70 80240150 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B7DA74 80240154 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B7DA78 80240158 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B7DA7C 8024015C 8E30000C */  lw        $s0, 0xc($s1)
/* B7DA80 80240160 8E050000 */  lw        $a1, ($s0)
/* B7DA84 80240164 0C0B1EAF */  jal       get_variable
/* B7DA88 80240168 26100004 */   addiu    $s0, $s0, 4
/* B7DA8C 8024016C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B7DA90 80240170 0040202D */   daddu    $a0, $v0, $zero
/* B7DA94 80240174 8E050000 */  lw        $a1, ($s0)
/* B7DA98 80240178 26100004 */  addiu     $s0, $s0, 4
/* B7DA9C 8024017C 0220202D */  daddu     $a0, $s1, $zero
/* B7DAA0 80240180 0C0B210B */  jal       get_float_variable
/* B7DAA4 80240184 0040902D */   daddu    $s2, $v0, $zero
/* B7DAA8 80240188 8E050000 */  lw        $a1, ($s0)
/* B7DAAC 8024018C 26100004 */  addiu     $s0, $s0, 4
/* B7DAB0 80240190 0220202D */  daddu     $a0, $s1, $zero
/* B7DAB4 80240194 0C0B210B */  jal       get_float_variable
/* B7DAB8 80240198 46000706 */   mov.s    $f28, $f0
/* B7DABC 8024019C 8E050000 */  lw        $a1, ($s0)
/* B7DAC0 802401A0 26100004 */  addiu     $s0, $s0, 4
/* B7DAC4 802401A4 0220202D */  daddu     $a0, $s1, $zero
/* B7DAC8 802401A8 0C0B210B */  jal       get_float_variable
/* B7DACC 802401AC 46000686 */   mov.s    $f26, $f0
/* B7DAD0 802401B0 0220202D */  daddu     $a0, $s1, $zero
/* B7DAD4 802401B4 8E050000 */  lw        $a1, ($s0)
/* B7DAD8 802401B8 0C0B210B */  jal       get_float_variable
/* B7DADC 802401BC 46000586 */   mov.s    $f22, $f0
/* B7DAE0 802401C0 0240202D */  daddu     $a0, $s2, $zero
/* B7DAE4 802401C4 0C046B4C */  jal       get_model_from_list_index
/* B7DAE8 802401C8 46000606 */   mov.s    $f24, $f0
/* B7DAEC 802401CC 0040882D */  daddu     $s1, $v0, $zero
/* B7DAF0 802401D0 96220000 */  lhu       $v0, ($s1)
/* B7DAF4 802401D4 30420400 */  andi      $v0, $v0, 0x400
/* B7DAF8 802401D8 1440001E */  bnez      $v0, .L80240254
/* B7DAFC 802401DC 26300058 */   addiu    $s0, $s1, 0x58
/* B7DB00 802401E0 4480A000 */  mtc1      $zero, $f20
/* B7DB04 802401E4 4406B000 */  mfc1      $a2, $f22
/* B7DB08 802401E8 4405A000 */  mfc1      $a1, $f20
/* B7DB0C 802401EC 4407A000 */  mfc1      $a3, $f20
/* B7DB10 802401F0 0C019E40 */  jal       guTranslateF
/* B7DB14 802401F4 0200202D */   daddu    $a0, $s0, $zero
/* B7DB18 802401F8 4405E000 */  mfc1      $a1, $f28
/* B7DB1C 802401FC 4406D000 */  mfc1      $a2, $f26
/* B7DB20 80240200 4407C000 */  mfc1      $a3, $f24
/* B7DB24 80240204 0C090030 */  jal       func_802400C0_B7D9E0
/* B7DB28 80240208 27A40010 */   addiu    $a0, $sp, 0x10
/* B7DB2C 8024020C 27A40010 */  addiu     $a0, $sp, 0x10
/* B7DB30 80240210 0200282D */  daddu     $a1, $s0, $zero
/* B7DB34 80240214 0C019D80 */  jal       guMtxCatF
/* B7DB38 80240218 0200302D */   daddu    $a2, $s0, $zero
/* B7DB3C 8024021C 27A40010 */  addiu     $a0, $sp, 0x10
/* B7DB40 80240220 4600B587 */  neg.s     $f22, $f22
/* B7DB44 80240224 4405A000 */  mfc1      $a1, $f20
/* B7DB48 80240228 4406B000 */  mfc1      $a2, $f22
/* B7DB4C 8024022C 0C019E40 */  jal       guTranslateF
/* B7DB50 80240230 00A0382D */   daddu    $a3, $a1, $zero
/* B7DB54 80240234 27A40010 */  addiu     $a0, $sp, 0x10
/* B7DB58 80240238 0200282D */  daddu     $a1, $s0, $zero
/* B7DB5C 8024023C 0C019D80 */  jal       guMtxCatF
/* B7DB60 80240240 00A0302D */   daddu    $a2, $a1, $zero
/* B7DB64 80240244 96220000 */  lhu       $v0, ($s1)
/* B7DB68 80240248 34421400 */  ori       $v0, $v0, 0x1400
/* B7DB6C 8024024C 080900B3 */  j         .L802402CC
/* B7DB70 80240250 A6220000 */   sh       $v0, ($s1)
.L80240254:
/* B7DB74 80240254 4480A000 */  mtc1      $zero, $f20
/* B7DB78 80240258 4406B000 */  mfc1      $a2, $f22
/* B7DB7C 8024025C 4405A000 */  mfc1      $a1, $f20
/* B7DB80 80240260 4407A000 */  mfc1      $a3, $f20
/* B7DB84 80240264 0C019E40 */  jal       guTranslateF
/* B7DB88 80240268 27A40010 */   addiu    $a0, $sp, 0x10
/* B7DB8C 8024026C 27A40010 */  addiu     $a0, $sp, 0x10
/* B7DB90 80240270 26300058 */  addiu     $s0, $s1, 0x58
/* B7DB94 80240274 0200282D */  daddu     $a1, $s0, $zero
/* B7DB98 80240278 0C019D80 */  jal       guMtxCatF
/* B7DB9C 8024027C 0200302D */   daddu    $a2, $s0, $zero
/* B7DBA0 80240280 4405E000 */  mfc1      $a1, $f28
/* B7DBA4 80240284 4406D000 */  mfc1      $a2, $f26
/* B7DBA8 80240288 4407C000 */  mfc1      $a3, $f24
/* B7DBAC 8024028C 0C090030 */  jal       func_802400C0_B7D9E0
/* B7DBB0 80240290 27A40010 */   addiu    $a0, $sp, 0x10
/* B7DBB4 80240294 27A40010 */  addiu     $a0, $sp, 0x10
/* B7DBB8 80240298 0200282D */  daddu     $a1, $s0, $zero
/* B7DBBC 8024029C 0C019D80 */  jal       guMtxCatF
/* B7DBC0 802402A0 0200302D */   daddu    $a2, $s0, $zero
/* B7DBC4 802402A4 27A40010 */  addiu     $a0, $sp, 0x10
/* B7DBC8 802402A8 4600B587 */  neg.s     $f22, $f22
/* B7DBCC 802402AC 4405A000 */  mfc1      $a1, $f20
/* B7DBD0 802402B0 4406B000 */  mfc1      $a2, $f22
/* B7DBD4 802402B4 0C019E40 */  jal       guTranslateF
/* B7DBD8 802402B8 00A0382D */   daddu    $a3, $a1, $zero
/* B7DBDC 802402BC 27A40010 */  addiu     $a0, $sp, 0x10
/* B7DBE0 802402C0 0200282D */  daddu     $a1, $s0, $zero
/* B7DBE4 802402C4 0C019D80 */  jal       guMtxCatF
/* B7DBE8 802402C8 00A0302D */   daddu    $a2, $a1, $zero
.L802402CC:
/* B7DBEC 802402CC 8FBF005C */  lw        $ra, 0x5c($sp)
/* B7DBF0 802402D0 8FB20058 */  lw        $s2, 0x58($sp)
/* B7DBF4 802402D4 8FB10054 */  lw        $s1, 0x54($sp)
/* B7DBF8 802402D8 8FB00050 */  lw        $s0, 0x50($sp)
/* B7DBFC 802402DC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B7DC00 802402E0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B7DC04 802402E4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B7DC08 802402E8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B7DC0C 802402EC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B7DC10 802402F0 24020002 */  addiu     $v0, $zero, 2
/* B7DC14 802402F4 03E00008 */  jr        $ra
/* B7DC18 802402F8 27BD0088 */   addiu    $sp, $sp, 0x88
/* B7DC1C 802402FC 00000000 */  nop       
