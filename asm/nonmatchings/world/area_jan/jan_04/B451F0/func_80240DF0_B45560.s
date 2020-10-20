.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DF0_B45560
/* B45560 80240DF0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* B45564 80240DF4 AFB10054 */  sw        $s1, 0x54($sp)
/* B45568 80240DF8 0080882D */  daddu     $s1, $a0, $zero
/* B4556C 80240DFC AFBF005C */  sw        $ra, 0x5c($sp)
/* B45570 80240E00 AFB20058 */  sw        $s2, 0x58($sp)
/* B45574 80240E04 AFB00050 */  sw        $s0, 0x50($sp)
/* B45578 80240E08 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* B4557C 80240E0C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B45580 80240E10 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B45584 80240E14 F7B60068 */  sdc1      $f22, 0x68($sp)
/* B45588 80240E18 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B4558C 80240E1C 8E30000C */  lw        $s0, 0xc($s1)
/* B45590 80240E20 8E050000 */  lw        $a1, ($s0)
/* B45594 80240E24 0C0B1EAF */  jal       get_variable
/* B45598 80240E28 26100004 */   addiu    $s0, $s0, 4
/* B4559C 80240E2C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B455A0 80240E30 0040202D */   daddu    $a0, $v0, $zero
/* B455A4 80240E34 8E050000 */  lw        $a1, ($s0)
/* B455A8 80240E38 26100004 */  addiu     $s0, $s0, 4
/* B455AC 80240E3C 0220202D */  daddu     $a0, $s1, $zero
/* B455B0 80240E40 0C0B210B */  jal       get_float_variable
/* B455B4 80240E44 0040902D */   daddu    $s2, $v0, $zero
/* B455B8 80240E48 8E050000 */  lw        $a1, ($s0)
/* B455BC 80240E4C 26100004 */  addiu     $s0, $s0, 4
/* B455C0 80240E50 0220202D */  daddu     $a0, $s1, $zero
/* B455C4 80240E54 0C0B210B */  jal       get_float_variable
/* B455C8 80240E58 46000706 */   mov.s    $f28, $f0
/* B455CC 80240E5C 8E050000 */  lw        $a1, ($s0)
/* B455D0 80240E60 26100004 */  addiu     $s0, $s0, 4
/* B455D4 80240E64 0220202D */  daddu     $a0, $s1, $zero
/* B455D8 80240E68 0C0B210B */  jal       get_float_variable
/* B455DC 80240E6C 46000686 */   mov.s    $f26, $f0
/* B455E0 80240E70 0220202D */  daddu     $a0, $s1, $zero
/* B455E4 80240E74 8E050000 */  lw        $a1, ($s0)
/* B455E8 80240E78 0C0B210B */  jal       get_float_variable
/* B455EC 80240E7C 46000586 */   mov.s    $f22, $f0
/* B455F0 80240E80 0240202D */  daddu     $a0, $s2, $zero
/* B455F4 80240E84 0C046B4C */  jal       get_model_from_list_index
/* B455F8 80240E88 46000606 */   mov.s    $f24, $f0
/* B455FC 80240E8C 0040882D */  daddu     $s1, $v0, $zero
/* B45600 80240E90 96220000 */  lhu       $v0, ($s1)
/* B45604 80240E94 30420400 */  andi      $v0, $v0, 0x400
/* B45608 80240E98 1440001E */  bnez      $v0, .L80240F14
/* B4560C 80240E9C 26300058 */   addiu    $s0, $s1, 0x58
/* B45610 80240EA0 4480A000 */  mtc1      $zero, $f20
/* B45614 80240EA4 4406B000 */  mfc1      $a2, $f22
/* B45618 80240EA8 4405A000 */  mfc1      $a1, $f20
/* B4561C 80240EAC 4407A000 */  mfc1      $a3, $f20
/* B45620 80240EB0 0C019E40 */  jal       guTranslateF
/* B45624 80240EB4 0200202D */   daddu    $a0, $s0, $zero
/* B45628 80240EB8 4405E000 */  mfc1      $a1, $f28
/* B4562C 80240EBC 4406D000 */  mfc1      $a2, $f26
/* B45630 80240EC0 4407C000 */  mfc1      $a3, $f24
/* B45634 80240EC4 0C090360 */  jal       func_80240D80
/* B45638 80240EC8 27A40010 */   addiu    $a0, $sp, 0x10
/* B4563C 80240ECC 27A40010 */  addiu     $a0, $sp, 0x10
/* B45640 80240ED0 0200282D */  daddu     $a1, $s0, $zero
/* B45644 80240ED4 0C019D80 */  jal       guMtxCatF
/* B45648 80240ED8 0200302D */   daddu    $a2, $s0, $zero
/* B4564C 80240EDC 27A40010 */  addiu     $a0, $sp, 0x10
/* B45650 80240EE0 4600B587 */  neg.s     $f22, $f22
/* B45654 80240EE4 4405A000 */  mfc1      $a1, $f20
/* B45658 80240EE8 4406B000 */  mfc1      $a2, $f22
/* B4565C 80240EEC 0C019E40 */  jal       guTranslateF
/* B45660 80240EF0 00A0382D */   daddu    $a3, $a1, $zero
/* B45664 80240EF4 27A40010 */  addiu     $a0, $sp, 0x10
/* B45668 80240EF8 0200282D */  daddu     $a1, $s0, $zero
/* B4566C 80240EFC 0C019D80 */  jal       guMtxCatF
/* B45670 80240F00 00A0302D */   daddu    $a2, $a1, $zero
/* B45674 80240F04 96220000 */  lhu       $v0, ($s1)
/* B45678 80240F08 34421400 */  ori       $v0, $v0, 0x1400
/* B4567C 80240F0C 080903E3 */  j         .L80240F8C
/* B45680 80240F10 A6220000 */   sh       $v0, ($s1)
.L80240F14:
/* B45684 80240F14 4480A000 */  mtc1      $zero, $f20
/* B45688 80240F18 4406B000 */  mfc1      $a2, $f22
/* B4568C 80240F1C 4405A000 */  mfc1      $a1, $f20
/* B45690 80240F20 4407A000 */  mfc1      $a3, $f20
/* B45694 80240F24 0C019E40 */  jal       guTranslateF
/* B45698 80240F28 27A40010 */   addiu    $a0, $sp, 0x10
/* B4569C 80240F2C 27A40010 */  addiu     $a0, $sp, 0x10
/* B456A0 80240F30 26300058 */  addiu     $s0, $s1, 0x58
/* B456A4 80240F34 0200282D */  daddu     $a1, $s0, $zero
/* B456A8 80240F38 0C019D80 */  jal       guMtxCatF
/* B456AC 80240F3C 0200302D */   daddu    $a2, $s0, $zero
/* B456B0 80240F40 4405E000 */  mfc1      $a1, $f28
/* B456B4 80240F44 4406D000 */  mfc1      $a2, $f26
/* B456B8 80240F48 4407C000 */  mfc1      $a3, $f24
/* B456BC 80240F4C 0C090360 */  jal       func_80240D80
/* B456C0 80240F50 27A40010 */   addiu    $a0, $sp, 0x10
/* B456C4 80240F54 27A40010 */  addiu     $a0, $sp, 0x10
/* B456C8 80240F58 0200282D */  daddu     $a1, $s0, $zero
/* B456CC 80240F5C 0C019D80 */  jal       guMtxCatF
/* B456D0 80240F60 0200302D */   daddu    $a2, $s0, $zero
/* B456D4 80240F64 27A40010 */  addiu     $a0, $sp, 0x10
/* B456D8 80240F68 4600B587 */  neg.s     $f22, $f22
/* B456DC 80240F6C 4405A000 */  mfc1      $a1, $f20
/* B456E0 80240F70 4406B000 */  mfc1      $a2, $f22
/* B456E4 80240F74 0C019E40 */  jal       guTranslateF
/* B456E8 80240F78 00A0382D */   daddu    $a3, $a1, $zero
/* B456EC 80240F7C 27A40010 */  addiu     $a0, $sp, 0x10
/* B456F0 80240F80 0200282D */  daddu     $a1, $s0, $zero
/* B456F4 80240F84 0C019D80 */  jal       guMtxCatF
/* B456F8 80240F88 00A0302D */   daddu    $a2, $a1, $zero
.L80240F8C:
/* B456FC 80240F8C 8FBF005C */  lw        $ra, 0x5c($sp)
/* B45700 80240F90 8FB20058 */  lw        $s2, 0x58($sp)
/* B45704 80240F94 8FB10054 */  lw        $s1, 0x54($sp)
/* B45708 80240F98 8FB00050 */  lw        $s0, 0x50($sp)
/* B4570C 80240F9C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* B45710 80240FA0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B45714 80240FA4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B45718 80240FA8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* B4571C 80240FAC D7B40060 */  ldc1      $f20, 0x60($sp)
/* B45720 80240FB0 24020002 */  addiu     $v0, $zero, 2
/* B45724 80240FB4 03E00008 */  jr        $ra
/* B45728 80240FB8 27BD0088 */   addiu    $sp, $sp, 0x88
/* B4572C 80240FBC 00000000 */  nop       
