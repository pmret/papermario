.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242590_9D95B0
/* 9D95B0 80242590 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9D95B4 80242594 AFB20018 */  sw        $s2, 0x18($sp)
/* 9D95B8 80242598 0080902D */  daddu     $s2, $a0, $zero
/* 9D95BC 8024259C AFBF0030 */  sw        $ra, 0x30($sp)
/* 9D95C0 802425A0 AFB7002C */  sw        $s7, 0x2c($sp)
/* 9D95C4 802425A4 AFB60028 */  sw        $s6, 0x28($sp)
/* 9D95C8 802425A8 AFB50024 */  sw        $s5, 0x24($sp)
/* 9D95CC 802425AC AFB40020 */  sw        $s4, 0x20($sp)
/* 9D95D0 802425B0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9D95D4 802425B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D95D8 802425B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D95DC 802425BC F7B60040 */  sdc1      $f22, 0x40($sp)
/* 9D95E0 802425C0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 9D95E4 802425C4 8E50000C */  lw        $s0, 0xc($s2)
/* 9D95E8 802425C8 8E050000 */  lw        $a1, ($s0)
/* 9D95EC 802425CC 0C0B1EAF */  jal       get_variable
/* 9D95F0 802425D0 26100004 */   addiu    $s0, $s0, 4
/* 9D95F4 802425D4 8E050000 */  lw        $a1, ($s0)
/* 9D95F8 802425D8 26100004 */  addiu     $s0, $s0, 4
/* 9D95FC 802425DC 0240202D */  daddu     $a0, $s2, $zero
/* 9D9600 802425E0 0C0B1EAF */  jal       get_variable
/* 9D9604 802425E4 0040B82D */   daddu    $s7, $v0, $zero
/* 9D9608 802425E8 8E050000 */  lw        $a1, ($s0)
/* 9D960C 802425EC 26100004 */  addiu     $s0, $s0, 4
/* 9D9610 802425F0 0240202D */  daddu     $a0, $s2, $zero
/* 9D9614 802425F4 0C0B1EAF */  jal       get_variable
/* 9D9618 802425F8 0040B02D */   daddu    $s6, $v0, $zero
/* 9D961C 802425FC 0240202D */  daddu     $a0, $s2, $zero
/* 9D9620 80242600 3C05F4AC */  lui       $a1, 0xf4ac
/* 9D9624 80242604 34A5D481 */  ori       $a1, $a1, 0xd481
/* 9D9628 80242608 3C068007 */  lui       $a2, %hi(gCurrentCameraID)
/* 9D962C 8024260C 8CC67410 */  lw        $a2, %lo(gCurrentCameraID)($a2)
/* 9D9630 80242610 8E140000 */  lw        $s4, ($s0)
/* 9D9634 80242614 00061880 */  sll       $v1, $a2, 2
/* 9D9638 80242618 00661821 */  addu      $v1, $v1, $a2
/* 9D963C 8024261C 00031880 */  sll       $v1, $v1, 2
/* 9D9640 80242620 00661823 */  subu      $v1, $v1, $a2
/* 9D9644 80242624 000330C0 */  sll       $a2, $v1, 3
/* 9D9648 80242628 00661821 */  addu      $v1, $v1, $a2
/* 9D964C 8024262C 000318C0 */  sll       $v1, $v1, 3
/* 9D9650 80242630 3C01800B */  lui       $at, 0x800b
/* 9D9654 80242634 00230821 */  addu      $at, $at, $v1
/* 9D9658 80242638 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 9D965C 8024263C 8E150004 */  lw        $s5, 4($s0)
/* 9D9660 80242640 4600010D */  trunc.w.s $f4, $f0
/* 9D9664 80242644 44112000 */  mfc1      $s1, $f4
/* 9D9668 80242648 0C0B1EAF */  jal       get_variable
/* 9D966C 8024264C 0040982D */   daddu    $s3, $v0, $zero
/* 9D9670 80242650 4491B000 */  mtc1      $s1, $f22
/* 9D9674 80242654 00000000 */  nop       
/* 9D9678 80242658 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9D967C 8024265C 4600B306 */  mov.s     $f12, $f22
/* 9D9680 80242660 0C00A8D4 */  jal       cos_deg
/* 9D9684 80242664 0040802D */   daddu    $s0, $v0, $zero
/* 9D9688 80242668 4493A000 */  mtc1      $s3, $f20
/* 9D968C 8024266C 00000000 */  nop       
/* 9D9690 80242670 4680A520 */  cvt.s.w   $f20, $f20
/* 9D9694 80242674 4600A002 */  mul.s     $f0, $f20, $f0
/* 9D9698 80242678 00000000 */  nop       
/* 9D969C 8024267C 0240202D */  daddu     $a0, $s2, $zero
/* 9D96A0 80242680 44901000 */  mtc1      $s0, $f2
/* 9D96A4 80242684 00000000 */  nop       
/* 9D96A8 80242688 468010A0 */  cvt.s.w   $f2, $f2
/* 9D96AC 8024268C 46001081 */  sub.s     $f2, $f2, $f0
/* 9D96B0 80242690 3C05F4AC */  lui       $a1, 0xf4ac
/* 9D96B4 80242694 4600110D */  trunc.w.s $f4, $f2
/* 9D96B8 80242698 44102000 */  mfc1      $s0, $f4
/* 9D96BC 8024269C 0C0B1EAF */  jal       get_variable
/* 9D96C0 802426A0 34A5D483 */   ori      $a1, $a1, 0xd483
/* 9D96C4 802426A4 4600B306 */  mov.s     $f12, $f22
/* 9D96C8 802426A8 0C00A8BB */  jal       sin_deg
/* 9D96CC 802426AC 0040882D */   daddu    $s1, $v0, $zero
/* 9D96D0 802426B0 4600A502 */  mul.s     $f20, $f20, $f0
/* 9D96D4 802426B4 00000000 */  nop       
/* 9D96D8 802426B8 0240202D */  daddu     $a0, $s2, $zero
/* 9D96DC 802426BC 44910000 */  mtc1      $s1, $f0
/* 9D96E0 802426C0 00000000 */  nop       
/* 9D96E4 802426C4 46800020 */  cvt.s.w   $f0, $f0
/* 9D96E8 802426C8 46140001 */  sub.s     $f0, $f0, $f20
/* 9D96EC 802426CC 0280282D */  daddu     $a1, $s4, $zero
/* 9D96F0 802426D0 02173023 */  subu      $a2, $s0, $s7
/* 9D96F4 802426D4 4600010D */  trunc.w.s $f4, $f0
/* 9D96F8 802426D8 44102000 */  mfc1      $s0, $f4
/* 9D96FC 802426DC 0C0B2026 */  jal       set_variable
/* 9D9700 802426E0 02168023 */   subu     $s0, $s0, $s6
/* 9D9704 802426E4 0240202D */  daddu     $a0, $s2, $zero
/* 9D9708 802426E8 02A0282D */  daddu     $a1, $s5, $zero
/* 9D970C 802426EC 0C0B2026 */  jal       set_variable
/* 9D9710 802426F0 0200302D */   daddu    $a2, $s0, $zero
/* 9D9714 802426F4 8FBF0030 */  lw        $ra, 0x30($sp)
/* 9D9718 802426F8 8FB7002C */  lw        $s7, 0x2c($sp)
/* 9D971C 802426FC 8FB60028 */  lw        $s6, 0x28($sp)
/* 9D9720 80242700 8FB50024 */  lw        $s5, 0x24($sp)
/* 9D9724 80242704 8FB40020 */  lw        $s4, 0x20($sp)
/* 9D9728 80242708 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9D972C 8024270C 8FB20018 */  lw        $s2, 0x18($sp)
/* 9D9730 80242710 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D9734 80242714 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D9738 80242718 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 9D973C 8024271C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 9D9740 80242720 24020002 */  addiu     $v0, $zero, 2
/* 9D9744 80242724 03E00008 */  jr        $ra
/* 9D9748 80242728 27BD0048 */   addiu    $sp, $sp, 0x48
