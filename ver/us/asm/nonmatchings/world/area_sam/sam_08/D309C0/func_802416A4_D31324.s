.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416A4_D31324
/* D31324 802416A4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D31328 802416A8 AFB1001C */  sw        $s1, 0x1c($sp)
/* D3132C 802416AC 0080882D */  daddu     $s1, $a0, $zero
/* D31330 802416B0 AFBF0024 */  sw        $ra, 0x24($sp)
/* D31334 802416B4 AFB20020 */  sw        $s2, 0x20($sp)
/* D31338 802416B8 AFB00018 */  sw        $s0, 0x18($sp)
/* D3133C 802416BC 8E30000C */  lw        $s0, 0xc($s1)
/* D31340 802416C0 8E050000 */  lw        $a1, ($s0)
/* D31344 802416C4 0C0B1EAF */  jal       evt_get_variable
/* D31348 802416C8 26100004 */   addiu    $s0, $s0, 4
/* D3134C 802416CC 8E050000 */  lw        $a1, ($s0)
/* D31350 802416D0 26100004 */  addiu     $s0, $s0, 4
/* D31354 802416D4 0220202D */  daddu     $a0, $s1, $zero
/* D31358 802416D8 0C0B1EAF */  jal       evt_get_variable
/* D3135C 802416DC 0040902D */   daddu    $s2, $v0, $zero
/* D31360 802416E0 0220202D */  daddu     $a0, $s1, $zero
/* D31364 802416E4 8E050000 */  lw        $a1, ($s0)
/* D31368 802416E8 0C0B1EAF */  jal       evt_get_variable
/* D3136C 802416EC 0040802D */   daddu    $s0, $v0, $zero
/* D31370 802416F0 3C048000 */  lui       $a0, 0x8000
/* D31374 802416F4 3484006C */  ori       $a0, $a0, 0x6c
/* D31378 802416F8 0000282D */  daddu     $a1, $zero, $zero
/* D3137C 802416FC 44921000 */  mtc1      $s2, $f2
/* D31380 80241700 00000000 */  nop
/* D31384 80241704 468010A0 */  cvt.s.w   $f2, $f2
/* D31388 80241708 44061000 */  mfc1      $a2, $f2
/* D3138C 8024170C 44901000 */  mtc1      $s0, $f2
/* D31390 80241710 00000000 */  nop
/* D31394 80241714 468010A0 */  cvt.s.w   $f2, $f2
/* D31398 80241718 44071000 */  mfc1      $a3, $f2
/* D3139C 8024171C 44820000 */  mtc1      $v0, $f0
/* D313A0 80241720 00000000 */  nop
/* D313A4 80241724 46800020 */  cvt.s.w   $f0, $f0
/* D313A8 80241728 0C05267B */  jal       sfx_adjust_env_sound_pos
/* D313AC 8024172C E7A00010 */   swc1     $f0, 0x10($sp)
/* D313B0 80241730 8FBF0024 */  lw        $ra, 0x24($sp)
/* D313B4 80241734 8FB20020 */  lw        $s2, 0x20($sp)
/* D313B8 80241738 8FB1001C */  lw        $s1, 0x1c($sp)
/* D313BC 8024173C 8FB00018 */  lw        $s0, 0x18($sp)
/* D313C0 80241740 24020002 */  addiu     $v0, $zero, 2
/* D313C4 80241744 03E00008 */  jr        $ra
/* D313C8 80241748 27BD0028 */   addiu    $sp, $sp, 0x28
