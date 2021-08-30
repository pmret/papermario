.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401CC_B7A21C
/* B7A21C 802401CC 27BDFF98 */  addiu     $sp, $sp, -0x68
/* B7A220 802401D0 AFB10054 */  sw        $s1, 0x54($sp)
/* B7A224 802401D4 0080882D */  daddu     $s1, $a0, $zero
/* B7A228 802401D8 AFBF0058 */  sw        $ra, 0x58($sp)
/* B7A22C 802401DC AFB00050 */  sw        $s0, 0x50($sp)
/* B7A230 802401E0 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B7A234 802401E4 8E30000C */  lw        $s0, 0xc($s1)
/* B7A238 802401E8 8E050000 */  lw        $a1, ($s0)
/* B7A23C 802401EC 0C0B1EAF */  jal       evt_get_variable
/* B7A240 802401F0 26100004 */   addiu    $s0, $s0, 4
/* B7A244 802401F4 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B7A248 802401F8 0040202D */   daddu    $a0, $v0, $zero
/* B7A24C 802401FC 0220202D */  daddu     $a0, $s1, $zero
/* B7A250 80240200 8E050000 */  lw        $a1, ($s0)
/* B7A254 80240204 0C0B210B */  jal       evt_get_float_variable
/* B7A258 80240208 0040802D */   daddu    $s0, $v0, $zero
/* B7A25C 8024020C 0200202D */  daddu     $a0, $s0, $zero
/* B7A260 80240210 0C046B4C */  jal       get_model_from_list_index
/* B7A264 80240214 46000506 */   mov.s    $f20, $f0
/* B7A268 80240218 0040802D */  daddu     $s0, $v0, $zero
/* B7A26C 8024021C 96020000 */  lhu       $v0, ($s0)
/* B7A270 80240220 30420400 */  andi      $v0, $v0, 0x400
/* B7A274 80240224 14400008 */  bnez      $v0, .L80240248
/* B7A278 80240228 00000000 */   nop
/* B7A27C 8024022C 4405A000 */  mfc1      $a1, $f20
/* B7A280 80240230 0C09005C */  jal       func_80240170_B7A1C0
/* B7A284 80240234 26040058 */   addiu    $a0, $s0, 0x58
/* B7A288 80240238 96020000 */  lhu       $v0, ($s0)
/* B7A28C 8024023C 34421400 */  ori       $v0, $v0, 0x1400
/* B7A290 80240240 08090099 */  j         .L80240264
/* B7A294 80240244 A6020000 */   sh       $v0, ($s0)
.L80240248:
/* B7A298 80240248 4405A000 */  mfc1      $a1, $f20
/* B7A29C 8024024C 0C09005C */  jal       func_80240170_B7A1C0
/* B7A2A0 80240250 27A40010 */   addiu    $a0, $sp, 0x10
/* B7A2A4 80240254 27A40010 */  addiu     $a0, $sp, 0x10
/* B7A2A8 80240258 26050058 */  addiu     $a1, $s0, 0x58
/* B7A2AC 8024025C 0C019D80 */  jal       guMtxCatF
/* B7A2B0 80240260 00A0302D */   daddu    $a2, $a1, $zero
.L80240264:
/* B7A2B4 80240264 8FBF0058 */  lw        $ra, 0x58($sp)
/* B7A2B8 80240268 8FB10054 */  lw        $s1, 0x54($sp)
/* B7A2BC 8024026C 8FB00050 */  lw        $s0, 0x50($sp)
/* B7A2C0 80240270 D7B40060 */  ldc1      $f20, 0x60($sp)
/* B7A2C4 80240274 24020002 */  addiu     $v0, $zero, 2
/* B7A2C8 80240278 03E00008 */  jr        $ra
/* B7A2CC 8024027C 27BD0068 */   addiu    $sp, $sp, 0x68
