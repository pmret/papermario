.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240290_DEF130
/* DEF130 80240290 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* DEF134 80240294 AFB10014 */  sw        $s1, 0x14($sp)
/* DEF138 80240298 0080882D */  daddu     $s1, $a0, $zero
/* DEF13C 8024029C AFBF001C */  sw        $ra, 0x1c($sp)
/* DEF140 802402A0 AFB20018 */  sw        $s2, 0x18($sp)
/* DEF144 802402A4 AFB00010 */  sw        $s0, 0x10($sp)
/* DEF148 802402A8 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* DEF14C 802402AC F7B80030 */  sdc1      $f24, 0x30($sp)
/* DEF150 802402B0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DEF154 802402B4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DEF158 802402B8 8E30000C */  lw        $s0, 0xc($s1)
/* DEF15C 802402BC 8E050000 */  lw        $a1, ($s0)
/* DEF160 802402C0 0C0B1EAF */  jal       evt_get_variable
/* DEF164 802402C4 26100004 */   addiu    $s0, $s0, 4
/* DEF168 802402C8 8E050000 */  lw        $a1, ($s0)
/* DEF16C 802402CC 26100004 */  addiu     $s0, $s0, 4
/* DEF170 802402D0 0220202D */  daddu     $a0, $s1, $zero
/* DEF174 802402D4 0C0B210B */  jal       evt_get_float_variable
/* DEF178 802402D8 0040902D */   daddu    $s2, $v0, $zero
/* DEF17C 802402DC 8E050000 */  lw        $a1, ($s0)
/* DEF180 802402E0 26100004 */  addiu     $s0, $s0, 4
/* DEF184 802402E4 0220202D */  daddu     $a0, $s1, $zero
/* DEF188 802402E8 0C0B210B */  jal       evt_get_float_variable
/* DEF18C 802402EC 46000686 */   mov.s    $f26, $f0
/* DEF190 802402F0 8E050000 */  lw        $a1, ($s0)
/* DEF194 802402F4 26100004 */  addiu     $s0, $s0, 4
/* DEF198 802402F8 0220202D */  daddu     $a0, $s1, $zero
/* DEF19C 802402FC 0C0B210B */  jal       evt_get_float_variable
/* DEF1A0 80240300 46000606 */   mov.s    $f24, $f0
/* DEF1A4 80240304 0220202D */  daddu     $a0, $s1, $zero
/* DEF1A8 80240308 8E050000 */  lw        $a1, ($s0)
/* DEF1AC 8024030C 0C0B210B */  jal       evt_get_float_variable
/* DEF1B0 80240310 46000506 */   mov.s    $f20, $f0
/* DEF1B4 80240314 0240202D */  daddu     $a0, $s2, $zero
/* DEF1B8 80240318 0C00EAD2 */  jal       get_npc_safe
/* DEF1BC 8024031C 46000586 */   mov.s    $f22, $f0
/* DEF1C0 80240320 0040202D */  daddu     $a0, $v0, $zero
/* DEF1C4 80240324 E49A0038 */  swc1      $f26, 0x38($a0)
/* DEF1C8 80240328 4600D006 */  mov.s     $f0, $f26
/* DEF1CC 8024032C E498003C */  swc1      $f24, 0x3c($a0)
/* DEF1D0 80240330 4600C086 */  mov.s     $f2, $f24
/* DEF1D4 80240334 E4940040 */  swc1      $f20, 0x40($a0)
/* DEF1D8 80240338 4600A106 */  mov.s     $f4, $f20
/* DEF1DC 8024033C 8C830000 */  lw        $v1, ($a0)
/* DEF1E0 80240340 3C050001 */  lui       $a1, 1
/* DEF1E4 80240344 E496000C */  swc1      $f22, 0xc($a0)
/* DEF1E8 80240348 E480006C */  swc1      $f0, 0x6c($a0)
/* DEF1EC 8024034C E4820070 */  swc1      $f2, 0x70($a0)
/* DEF1F0 80240350 E4840074 */  swc1      $f4, 0x74($a0)
/* DEF1F4 80240354 00651825 */  or        $v1, $v1, $a1
/* DEF1F8 80240358 AC830000 */  sw        $v1, ($a0)
/* DEF1FC 8024035C 8FBF001C */  lw        $ra, 0x1c($sp)
/* DEF200 80240360 8FB20018 */  lw        $s2, 0x18($sp)
/* DEF204 80240364 8FB10014 */  lw        $s1, 0x14($sp)
/* DEF208 80240368 8FB00010 */  lw        $s0, 0x10($sp)
/* DEF20C 8024036C D7BA0038 */  ldc1      $f26, 0x38($sp)
/* DEF210 80240370 D7B80030 */  ldc1      $f24, 0x30($sp)
/* DEF214 80240374 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DEF218 80240378 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DEF21C 8024037C 24020002 */  addiu     $v0, $zero, 2
/* DEF220 80240380 03E00008 */  jr        $ra
/* DEF224 80240384 27BD0040 */   addiu    $sp, $sp, 0x40
