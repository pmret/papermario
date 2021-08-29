.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411EC_B2172C
/* B2172C 802411EC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B21730 802411F0 AFB10014 */  sw        $s1, 0x14($sp)
/* B21734 802411F4 0080882D */  daddu     $s1, $a0, $zero
/* B21738 802411F8 AFBF0024 */  sw        $ra, 0x24($sp)
/* B2173C 802411FC AFB40020 */  sw        $s4, 0x20($sp)
/* B21740 80241200 AFB3001C */  sw        $s3, 0x1c($sp)
/* B21744 80241204 AFB20018 */  sw        $s2, 0x18($sp)
/* B21748 80241208 AFB00010 */  sw        $s0, 0x10($sp)
/* B2174C 8024120C F7B40028 */  sdc1      $f20, 0x28($sp)
/* B21750 80241210 8E30000C */  lw        $s0, 0xc($s1)
/* B21754 80241214 8E050000 */  lw        $a1, ($s0)
/* B21758 80241218 0C0B1EAF */  jal       get_variable
/* B2175C 8024121C 26100004 */   addiu    $s0, $s0, 4
/* B21760 80241220 8E120000 */  lw        $s2, ($s0)
/* B21764 80241224 26100004 */  addiu     $s0, $s0, 4
/* B21768 80241228 0220202D */  daddu     $a0, $s1, $zero
/* B2176C 8024122C 8E130000 */  lw        $s3, ($s0)
/* B21770 80241230 8E140004 */  lw        $s4, 4($s0)
/* B21774 80241234 0C090468 */  jal       func_802411A0_B216E0
/* B21778 80241238 0040282D */   daddu    $a1, $v0, $zero
/* B2177C 8024123C 0040802D */  daddu     $s0, $v0, $zero
/* B21780 80241240 12000034 */  beqz      $s0, .L80241314
/* B21784 80241244 24020002 */   addiu    $v0, $zero, 2
/* B21788 80241248 3C038024 */  lui       $v1, %hi(D_80245950_B25E90)
/* B2178C 8024124C 24635950 */  addiu     $v1, $v1, %lo(D_80245950_B25E90)
/* B21790 80241250 8C640000 */  lw        $a0, ($v1)
/* B21794 80241254 24820004 */  addiu     $v0, $a0, 4
/* B21798 80241258 AC620000 */  sw        $v0, ($v1)
/* B2179C 8024125C 2C420168 */  sltiu     $v0, $v0, 0x168
/* B217A0 80241260 14400004 */  bnez      $v0, .L80241274
/* B217A4 80241264 3C0200B6 */   lui      $v0, 0xb6
/* B217A8 80241268 2482FE9C */  addiu     $v0, $a0, -0x164
/* B217AC 8024126C AC620000 */  sw        $v0, ($v1)
/* B217B0 80241270 3C0200B6 */  lui       $v0, 0xb6
.L80241274:
/* B217B4 80241274 8E030028 */  lw        $v1, 0x28($s0)
/* B217B8 80241278 C614003C */  lwc1      $f20, 0x3c($s0)
/* B217BC 8024127C 10620009 */  beq       $v1, $v0, .L802412A4
/* B217C0 80241280 34420004 */   ori      $v0, $v0, 4
/* B217C4 80241284 10620007 */  beq       $v1, $v0, .L802412A4
/* B217C8 80241288 3C0200B6 */   lui      $v0, 0xb6
/* B217CC 8024128C 34420008 */  ori       $v0, $v0, 8
/* B217D0 80241290 10620004 */  beq       $v1, $v0, .L802412A4
/* B217D4 80241294 3C0200B6 */   lui      $v0, 0xb6
/* B217D8 80241298 3442000C */  ori       $v0, $v0, 0xc
/* B217DC 8024129C 14620011 */  bne       $v1, $v0, .L802412E4
/* B217E0 802412A0 0220202D */   daddu    $a0, $s1, $zero
.L802412A4:
/* B217E4 802412A4 3C028024 */  lui       $v0, %hi(D_80245950_B25E90)
/* B217E8 802412A8 8C425950 */  lw        $v0, %lo(D_80245950_B25E90)($v0)
/* B217EC 802412AC 44826000 */  mtc1      $v0, $f12
/* B217F0 802412B0 00000000 */  nop
/* B217F4 802412B4 04410006 */  bgez      $v0, .L802412D0
/* B217F8 802412B8 46806321 */   cvt.d.w  $f12, $f12
/* B217FC 802412BC 3C0141F0 */  lui       $at, 0x41f0
/* B21800 802412C0 44810800 */  mtc1      $at, $f1
/* B21804 802412C4 44800000 */  mtc1      $zero, $f0
/* B21808 802412C8 00000000 */  nop
/* B2180C 802412CC 46206300 */  add.d     $f12, $f12, $f0
.L802412D0:
/* B21810 802412D0 0C00A8BB */  jal       sin_deg
/* B21814 802412D4 46206320 */   cvt.s.d  $f12, $f12
/* B21818 802412D8 46000000 */  add.s     $f0, $f0, $f0
/* B2181C 802412DC 4600A500 */  add.s     $f20, $f20, $f0
/* B21820 802412E0 0220202D */  daddu     $a0, $s1, $zero
.L802412E4:
/* B21824 802412E4 8E060038 */  lw        $a2, 0x38($s0)
/* B21828 802412E8 0C0B2190 */  jal       evt_set_float_variable
/* B2182C 802412EC 0240282D */   daddu    $a1, $s2, $zero
/* B21830 802412F0 0220202D */  daddu     $a0, $s1, $zero
/* B21834 802412F4 4406A000 */  mfc1      $a2, $f20
/* B21838 802412F8 0C0B2190 */  jal       evt_set_float_variable
/* B2183C 802412FC 0260282D */   daddu    $a1, $s3, $zero
/* B21840 80241300 0220202D */  daddu     $a0, $s1, $zero
/* B21844 80241304 8E060040 */  lw        $a2, 0x40($s0)
/* B21848 80241308 0C0B2190 */  jal       evt_set_float_variable
/* B2184C 8024130C 0280282D */   daddu    $a1, $s4, $zero
/* B21850 80241310 24020002 */  addiu     $v0, $zero, 2
.L80241314:
/* B21854 80241314 8FBF0024 */  lw        $ra, 0x24($sp)
/* B21858 80241318 8FB40020 */  lw        $s4, 0x20($sp)
/* B2185C 8024131C 8FB3001C */  lw        $s3, 0x1c($sp)
/* B21860 80241320 8FB20018 */  lw        $s2, 0x18($sp)
/* B21864 80241324 8FB10014 */  lw        $s1, 0x14($sp)
/* B21868 80241328 8FB00010 */  lw        $s0, 0x10($sp)
/* B2186C 8024132C D7B40028 */  ldc1      $f20, 0x28($sp)
/* B21870 80241330 03E00008 */  jr        $ra
/* B21874 80241334 27BD0030 */   addiu    $sp, $sp, 0x30
