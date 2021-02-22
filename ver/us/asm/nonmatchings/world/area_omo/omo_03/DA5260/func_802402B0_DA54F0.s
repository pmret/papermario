.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402B0_DA54F0
/* DA54F0 802402B0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* DA54F4 802402B4 AFB10014 */  sw        $s1, 0x14($sp)
/* DA54F8 802402B8 0080882D */  daddu     $s1, $a0, $zero
/* DA54FC 802402BC AFBF001C */  sw        $ra, 0x1c($sp)
/* DA5500 802402C0 AFB20018 */  sw        $s2, 0x18($sp)
/* DA5504 802402C4 AFB00010 */  sw        $s0, 0x10($sp)
/* DA5508 802402C8 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* DA550C 802402CC F7B80030 */  sdc1      $f24, 0x30($sp)
/* DA5510 802402D0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DA5514 802402D4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DA5518 802402D8 8E30000C */  lw        $s0, 0xc($s1)
/* DA551C 802402DC 8E050000 */  lw        $a1, ($s0)
/* DA5520 802402E0 0C0B1EAF */  jal       get_variable
/* DA5524 802402E4 26100004 */   addiu    $s0, $s0, 4
/* DA5528 802402E8 8E050000 */  lw        $a1, ($s0)
/* DA552C 802402EC 26100004 */  addiu     $s0, $s0, 4
/* DA5530 802402F0 0220202D */  daddu     $a0, $s1, $zero
/* DA5534 802402F4 0C0B210B */  jal       get_float_variable
/* DA5538 802402F8 0040902D */   daddu    $s2, $v0, $zero
/* DA553C 802402FC 8E050000 */  lw        $a1, ($s0)
/* DA5540 80240300 26100004 */  addiu     $s0, $s0, 4
/* DA5544 80240304 0220202D */  daddu     $a0, $s1, $zero
/* DA5548 80240308 0C0B210B */  jal       get_float_variable
/* DA554C 8024030C 46000686 */   mov.s    $f26, $f0
/* DA5550 80240310 8E050000 */  lw        $a1, ($s0)
/* DA5554 80240314 26100004 */  addiu     $s0, $s0, 4
/* DA5558 80240318 0220202D */  daddu     $a0, $s1, $zero
/* DA555C 8024031C 0C0B210B */  jal       get_float_variable
/* DA5560 80240320 46000606 */   mov.s    $f24, $f0
/* DA5564 80240324 0220202D */  daddu     $a0, $s1, $zero
/* DA5568 80240328 8E050000 */  lw        $a1, ($s0)
/* DA556C 8024032C 0C0B210B */  jal       get_float_variable
/* DA5570 80240330 46000506 */   mov.s    $f20, $f0
/* DA5574 80240334 0240202D */  daddu     $a0, $s2, $zero
/* DA5578 80240338 0C00EAD2 */  jal       get_npc_safe
/* DA557C 8024033C 46000586 */   mov.s    $f22, $f0
/* DA5580 80240340 0040202D */  daddu     $a0, $v0, $zero
/* DA5584 80240344 E49A0038 */  swc1      $f26, 0x38($a0)
/* DA5588 80240348 4600D006 */  mov.s     $f0, $f26
/* DA558C 8024034C E498003C */  swc1      $f24, 0x3c($a0)
/* DA5590 80240350 4600C086 */  mov.s     $f2, $f24
/* DA5594 80240354 E4940040 */  swc1      $f20, 0x40($a0)
/* DA5598 80240358 4600A106 */  mov.s     $f4, $f20
/* DA559C 8024035C 8C830000 */  lw        $v1, ($a0)
/* DA55A0 80240360 3C050001 */  lui       $a1, 1
/* DA55A4 80240364 E496000C */  swc1      $f22, 0xc($a0)
/* DA55A8 80240368 E480006C */  swc1      $f0, 0x6c($a0)
/* DA55AC 8024036C E4820070 */  swc1      $f2, 0x70($a0)
/* DA55B0 80240370 E4840074 */  swc1      $f4, 0x74($a0)
/* DA55B4 80240374 00651825 */  or        $v1, $v1, $a1
/* DA55B8 80240378 AC830000 */  sw        $v1, ($a0)
/* DA55BC 8024037C 8FBF001C */  lw        $ra, 0x1c($sp)
/* DA55C0 80240380 8FB20018 */  lw        $s2, 0x18($sp)
/* DA55C4 80240384 8FB10014 */  lw        $s1, 0x14($sp)
/* DA55C8 80240388 8FB00010 */  lw        $s0, 0x10($sp)
/* DA55CC 8024038C D7BA0038 */  ldc1      $f26, 0x38($sp)
/* DA55D0 80240390 D7B80030 */  ldc1      $f24, 0x30($sp)
/* DA55D4 80240394 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DA55D8 80240398 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DA55DC 8024039C 24020002 */  addiu     $v0, $zero, 2
/* DA55E0 802403A0 03E00008 */  jr        $ra
/* DA55E4 802403A4 27BD0040 */   addiu    $sp, $sp, 0x40
