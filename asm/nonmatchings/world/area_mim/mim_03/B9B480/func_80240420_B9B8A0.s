.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240420_B9B8A0
/* B9B8A0 80240420 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B9B8A4 80240424 AFB10024 */  sw        $s1, 0x24($sp)
/* B9B8A8 80240428 0080882D */  daddu     $s1, $a0, $zero
/* B9B8AC 8024042C AFBF0028 */  sw        $ra, 0x28($sp)
/* B9B8B0 80240430 AFB00020 */  sw        $s0, 0x20($sp)
/* B9B8B4 80240434 F7B60038 */  sdc1      $f22, 0x38($sp)
/* B9B8B8 80240438 F7B40030 */  sdc1      $f20, 0x30($sp)
/* B9B8BC 8024043C 8E30000C */  lw        $s0, 0xc($s1)
/* B9B8C0 80240440 8E050000 */  lw        $a1, ($s0)
/* B9B8C4 80240444 0C0B1EAF */  jal       get_variable
/* B9B8C8 80240448 26100004 */   addiu    $s0, $s0, 4
/* B9B8CC 8024044C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B9B8D0 80240450 0040202D */   daddu    $a0, $v0, $zero
/* B9B8D4 80240454 0C046B4C */  jal       get_model_from_list_index
/* B9B8D8 80240458 0040202D */   daddu    $a0, $v0, $zero
/* B9B8DC 8024045C 8C420008 */  lw        $v0, 8($v0)
/* B9B8E0 80240460 27A50010 */  addiu     $a1, $sp, 0x10
/* B9B8E4 80240464 8C420004 */  lw        $v0, 4($v0)
/* B9B8E8 80240468 27A60014 */  addiu     $a2, $sp, 0x14
/* B9B8EC 8024046C 8C440000 */  lw        $a0, ($v0)
/* B9B8F0 80240470 0C090028 */  jal       func_802400A0_B9B520
/* B9B8F4 80240474 27A70018 */   addiu    $a3, $sp, 0x18
/* B9B8F8 80240478 C7A00010 */  lwc1      $f0, 0x10($sp)
/* B9B8FC 8024047C 3C014480 */  lui       $at, 0x4480
/* B9B900 80240480 4481A000 */  mtc1      $at, $f20
/* B9B904 80240484 00000000 */  nop
/* B9B908 80240488 46140002 */  mul.s     $f0, $f0, $f20
/* B9B90C 8024048C 00000000 */  nop
/* B9B910 80240490 3C01CD5B */  lui       $at, 0xcd5b
/* B9B914 80240494 34215858 */  ori       $at, $at, 0x5858
/* B9B918 80240498 4481B000 */  mtc1      $at, $f22
/* B9B91C 8024049C 00000000 */  nop
/* B9B920 802404A0 46160000 */  add.s     $f0, $f0, $f22
/* B9B924 802404A4 8E050000 */  lw        $a1, ($s0)
/* B9B928 802404A8 4600008D */  trunc.w.s $f2, $f0
/* B9B92C 802404AC 44061000 */  mfc1      $a2, $f2
/* B9B930 802404B0 0C0B2026 */  jal       set_variable
/* B9B934 802404B4 0220202D */   daddu    $a0, $s1, $zero
/* B9B938 802404B8 C7A00014 */  lwc1      $f0, 0x14($sp)
/* B9B93C 802404BC 46140002 */  mul.s     $f0, $f0, $f20
/* B9B940 802404C0 00000000 */  nop
/* B9B944 802404C4 26100004 */  addiu     $s0, $s0, 4
/* B9B948 802404C8 46160000 */  add.s     $f0, $f0, $f22
/* B9B94C 802404CC 8E050000 */  lw        $a1, ($s0)
/* B9B950 802404D0 4600008D */  trunc.w.s $f2, $f0
/* B9B954 802404D4 44061000 */  mfc1      $a2, $f2
/* B9B958 802404D8 0C0B2026 */  jal       set_variable
/* B9B95C 802404DC 0220202D */   daddu    $a0, $s1, $zero
/* B9B960 802404E0 C7A00018 */  lwc1      $f0, 0x18($sp)
/* B9B964 802404E4 46140002 */  mul.s     $f0, $f0, $f20
/* B9B968 802404E8 00000000 */  nop
/* B9B96C 802404EC 26100004 */  addiu     $s0, $s0, 4
/* B9B970 802404F0 46160000 */  add.s     $f0, $f0, $f22
/* B9B974 802404F4 8E050000 */  lw        $a1, ($s0)
/* B9B978 802404F8 4600008D */  trunc.w.s $f2, $f0
/* B9B97C 802404FC 44061000 */  mfc1      $a2, $f2
/* B9B980 80240500 0C0B2026 */  jal       set_variable
/* B9B984 80240504 0220202D */   daddu    $a0, $s1, $zero
/* B9B988 80240508 8FBF0028 */  lw        $ra, 0x28($sp)
/* B9B98C 8024050C 8FB10024 */  lw        $s1, 0x24($sp)
/* B9B990 80240510 8FB00020 */  lw        $s0, 0x20($sp)
/* B9B994 80240514 D7B60038 */  ldc1      $f22, 0x38($sp)
/* B9B998 80240518 D7B40030 */  ldc1      $f20, 0x30($sp)
/* B9B99C 8024051C 24020002 */  addiu     $v0, $zero, 2
/* B9B9A0 80240520 03E00008 */  jr        $ra
/* B9B9A4 80240524 27BD0040 */   addiu    $sp, $sp, 0x40
/* B9B9A8 80240528 00000000 */  nop
/* B9B9AC 8024052C 00000000 */  nop
