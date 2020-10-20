.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240290_DEC160
/* DEC160 80240290 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* DEC164 80240294 AFB10014 */  sw        $s1, 0x14($sp)
/* DEC168 80240298 0080882D */  daddu     $s1, $a0, $zero
/* DEC16C 8024029C AFBF001C */  sw        $ra, 0x1c($sp)
/* DEC170 802402A0 AFB20018 */  sw        $s2, 0x18($sp)
/* DEC174 802402A4 AFB00010 */  sw        $s0, 0x10($sp)
/* DEC178 802402A8 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* DEC17C 802402AC F7B80030 */  sdc1      $f24, 0x30($sp)
/* DEC180 802402B0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DEC184 802402B4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DEC188 802402B8 8E30000C */  lw        $s0, 0xc($s1)
/* DEC18C 802402BC 8E050000 */  lw        $a1, ($s0)
/* DEC190 802402C0 0C0B1EAF */  jal       get_variable
/* DEC194 802402C4 26100004 */   addiu    $s0, $s0, 4
/* DEC198 802402C8 8E050000 */  lw        $a1, ($s0)
/* DEC19C 802402CC 26100004 */  addiu     $s0, $s0, 4
/* DEC1A0 802402D0 0220202D */  daddu     $a0, $s1, $zero
/* DEC1A4 802402D4 0C0B210B */  jal       get_float_variable
/* DEC1A8 802402D8 0040902D */   daddu    $s2, $v0, $zero
/* DEC1AC 802402DC 8E050000 */  lw        $a1, ($s0)
/* DEC1B0 802402E0 26100004 */  addiu     $s0, $s0, 4
/* DEC1B4 802402E4 0220202D */  daddu     $a0, $s1, $zero
/* DEC1B8 802402E8 0C0B210B */  jal       get_float_variable
/* DEC1BC 802402EC 46000686 */   mov.s    $f26, $f0
/* DEC1C0 802402F0 8E050000 */  lw        $a1, ($s0)
/* DEC1C4 802402F4 26100004 */  addiu     $s0, $s0, 4
/* DEC1C8 802402F8 0220202D */  daddu     $a0, $s1, $zero
/* DEC1CC 802402FC 0C0B210B */  jal       get_float_variable
/* DEC1D0 80240300 46000606 */   mov.s    $f24, $f0
/* DEC1D4 80240304 0220202D */  daddu     $a0, $s1, $zero
/* DEC1D8 80240308 8E050000 */  lw        $a1, ($s0)
/* DEC1DC 8024030C 0C0B210B */  jal       get_float_variable
/* DEC1E0 80240310 46000506 */   mov.s    $f20, $f0
/* DEC1E4 80240314 0240202D */  daddu     $a0, $s2, $zero
/* DEC1E8 80240318 0C00EAD2 */  jal       get_npc_safe
/* DEC1EC 8024031C 46000586 */   mov.s    $f22, $f0
/* DEC1F0 80240320 0040202D */  daddu     $a0, $v0, $zero
/* DEC1F4 80240324 E49A0038 */  swc1      $f26, 0x38($a0)
/* DEC1F8 80240328 4600D006 */  mov.s     $f0, $f26
/* DEC1FC 8024032C E498003C */  swc1      $f24, 0x3c($a0)
/* DEC200 80240330 4600C086 */  mov.s     $f2, $f24
/* DEC204 80240334 E4940040 */  swc1      $f20, 0x40($a0)
/* DEC208 80240338 4600A106 */  mov.s     $f4, $f20
/* DEC20C 8024033C 8C830000 */  lw        $v1, ($a0)
/* DEC210 80240340 3C050001 */  lui       $a1, 1
/* DEC214 80240344 E496000C */  swc1      $f22, 0xc($a0)
/* DEC218 80240348 E480006C */  swc1      $f0, 0x6c($a0)
/* DEC21C 8024034C E4820070 */  swc1      $f2, 0x70($a0)
/* DEC220 80240350 E4840074 */  swc1      $f4, 0x74($a0)
/* DEC224 80240354 00651825 */  or        $v1, $v1, $a1
/* DEC228 80240358 AC830000 */  sw        $v1, ($a0)
/* DEC22C 8024035C 8FBF001C */  lw        $ra, 0x1c($sp)
/* DEC230 80240360 8FB20018 */  lw        $s2, 0x18($sp)
/* DEC234 80240364 8FB10014 */  lw        $s1, 0x14($sp)
/* DEC238 80240368 8FB00010 */  lw        $s0, 0x10($sp)
/* DEC23C 8024036C D7BA0038 */  ldc1      $f26, 0x38($sp)
/* DEC240 80240370 D7B80030 */  ldc1      $f24, 0x30($sp)
/* DEC244 80240374 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DEC248 80240378 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DEC24C 8024037C 24020002 */  addiu     $v0, $zero, 2
/* DEC250 80240380 03E00008 */  jr        $ra
/* DEC254 80240384 27BD0040 */   addiu    $sp, $sp, 0x40
