.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_B52B40
/* B52B40 80240310 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B52B44 80240314 AFB1001C */  sw        $s1, 0x1c($sp)
/* B52B48 80240318 0080882D */  daddu     $s1, $a0, $zero
/* B52B4C 8024031C AFBF0020 */  sw        $ra, 0x20($sp)
/* B52B50 80240320 AFB00018 */  sw        $s0, 0x18($sp)
/* B52B54 80240324 8E30000C */  lw        $s0, 0xc($s1)
/* B52B58 80240328 8E050000 */  lw        $a1, ($s0)
/* B52B5C 8024032C 0C0B1EAF */  jal       get_variable
/* B52B60 80240330 26100004 */   addiu    $s0, $s0, 4
/* B52B64 80240334 AE220070 */  sw        $v0, 0x70($s1)
/* B52B68 80240338 8E050000 */  lw        $a1, ($s0)
/* B52B6C 8024033C 26100004 */  addiu     $s0, $s0, 4
/* B52B70 80240340 0C0B1EAF */  jal       get_variable
/* B52B74 80240344 0220202D */   daddu    $a0, $s1, $zero
/* B52B78 80240348 AE220074 */  sw        $v0, 0x74($s1)
/* B52B7C 8024034C 8E050000 */  lw        $a1, ($s0)
/* B52B80 80240350 0C0B1EAF */  jal       get_variable
/* B52B84 80240354 0220202D */   daddu    $a0, $s1, $zero
/* B52B88 80240358 2404009E */  addiu     $a0, $zero, 0x9e
/* B52B8C 8024035C 0000282D */  daddu     $a1, $zero, $zero
/* B52B90 80240360 C6200070 */  lwc1      $f0, 0x70($s1)
/* B52B94 80240364 46800020 */  cvt.s.w   $f0, $f0
/* B52B98 80240368 C6220074 */  lwc1      $f2, 0x74($s1)
/* B52B9C 8024036C 468010A0 */  cvt.s.w   $f2, $f2
/* B52BA0 80240370 44060000 */  mfc1      $a2, $f0
/* B52BA4 80240374 44071000 */  mfc1      $a3, $f2
/* B52BA8 80240378 44820000 */  mtc1      $v0, $f0
/* B52BAC 8024037C 00000000 */  nop
/* B52BB0 80240380 46800020 */  cvt.s.w   $f0, $f0
/* B52BB4 80240384 AE220078 */  sw        $v0, 0x78($s1)
/* B52BB8 80240388 0C05267B */  jal       sfx_adjust_env_sound_pos
/* B52BBC 8024038C E7A00010 */   swc1     $f0, 0x10($sp)
/* B52BC0 80240390 8FBF0020 */  lw        $ra, 0x20($sp)
/* B52BC4 80240394 8FB1001C */  lw        $s1, 0x1c($sp)
/* B52BC8 80240398 8FB00018 */  lw        $s0, 0x18($sp)
/* B52BCC 8024039C 24020002 */  addiu     $v0, $zero, 2
/* B52BD0 802403A0 03E00008 */  jr        $ra
/* B52BD4 802403A4 27BD0028 */   addiu    $sp, $sp, 0x28
/* B52BD8 802403A8 00000000 */  nop
/* B52BDC 802403AC 00000000 */  nop
