.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426A4_9C7A84
/* 9C7A84 802426A4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9C7A88 802426A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9C7A8C 802426AC 0080882D */  daddu     $s1, $a0, $zero
/* 9C7A90 802426B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C7A94 802426B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C7A98 802426B8 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 9C7A9C 802426BC F7B40020 */  sdc1      $f20, 0x20($sp)
/* 9C7AA0 802426C0 8E30000C */  lw        $s0, 0xc($s1)
/* 9C7AA4 802426C4 8E050000 */  lw        $a1, ($s0)
/* 9C7AA8 802426C8 0C0B1EAF */  jal       get_variable
/* 9C7AAC 802426CC 26100004 */   addiu    $s0, $s0, 4
/* 9C7AB0 802426D0 8E050000 */  lw        $a1, ($s0)
/* 9C7AB4 802426D4 26100004 */  addiu     $s0, $s0, 4
/* 9C7AB8 802426D8 4482B000 */  mtc1      $v0, $f22
/* 9C7ABC 802426DC 00000000 */  nop
/* 9C7AC0 802426E0 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9C7AC4 802426E4 0C0B1EAF */  jal       get_variable
/* 9C7AC8 802426E8 0220202D */   daddu    $a0, $s1, $zero
/* 9C7ACC 802426EC 8E050000 */  lw        $a1, ($s0)
/* 9C7AD0 802426F0 4482A000 */  mtc1      $v0, $f20
/* 9C7AD4 802426F4 00000000 */  nop
/* 9C7AD8 802426F8 4680A520 */  cvt.s.w   $f20, $f20
/* 9C7ADC 802426FC 0C0B1EAF */  jal       get_variable
/* 9C7AE0 80242700 0220202D */   daddu    $a0, $s1, $zero
/* 9C7AE4 80242704 3C014170 */  lui       $at, 0x4170
/* 9C7AE8 80242708 44810000 */  mtc1      $at, $f0
/* 9C7AEC 8024270C 44821000 */  mtc1      $v0, $f2
/* 9C7AF0 80242710 00000000 */  nop
/* 9C7AF4 80242714 468010A0 */  cvt.s.w   $f2, $f2
/* 9C7AF8 80242718 4600A500 */  add.s     $f20, $f20, $f0
/* 9C7AFC 8024271C 4405B000 */  mfc1      $a1, $f22
/* 9C7B00 80242720 44071000 */  mfc1      $a3, $f2
/* 9C7B04 80242724 4406A000 */  mfc1      $a2, $f20
/* 9C7B08 80242728 0C01C07C */  jal       playFX_19
/* 9C7B0C 8024272C 0000202D */   daddu    $a0, $zero, $zero
/* 9C7B10 80242730 0000202D */  daddu     $a0, $zero, $zero
/* 9C7B14 80242734 0080282D */  daddu     $a1, $a0, $zero
/* 9C7B18 80242738 0C0B2D5B */  jal       exec_ShakeCam1
/* 9C7B1C 8024273C 24060014 */   addiu    $a2, $zero, 0x14
/* 9C7B20 80242740 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C7B24 80242744 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C7B28 80242748 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C7B2C 8024274C D7B60028 */  ldc1      $f22, 0x28($sp)
/* 9C7B30 80242750 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 9C7B34 80242754 24020002 */  addiu     $v0, $zero, 2
/* 9C7B38 80242758 03E00008 */  jr        $ra
/* 9C7B3C 8024275C 27BD0030 */   addiu    $sp, $sp, 0x30
