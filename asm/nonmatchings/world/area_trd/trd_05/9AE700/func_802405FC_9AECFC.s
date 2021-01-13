.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405FC_9AECFC
/* 9AECFC 802405FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9AED00 80240600 AFB10014 */  sw        $s1, 0x14($sp)
/* 9AED04 80240604 0080882D */  daddu     $s1, $a0, $zero
/* 9AED08 80240608 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9AED0C 8024060C AFB3001C */  sw        $s3, 0x1c($sp)
/* 9AED10 80240610 AFB20018 */  sw        $s2, 0x18($sp)
/* 9AED14 80240614 AFB00010 */  sw        $s0, 0x10($sp)
/* 9AED18 80240618 8E30000C */  lw        $s0, 0xc($s1)
/* 9AED1C 8024061C 8E050000 */  lw        $a1, ($s0)
/* 9AED20 80240620 0C0B1EAF */  jal       get_variable
/* 9AED24 80240624 26100004 */   addiu    $s0, $s0, 4
/* 9AED28 80240628 8E050000 */  lw        $a1, ($s0)
/* 9AED2C 8024062C 26100004 */  addiu     $s0, $s0, 4
/* 9AED30 80240630 0220202D */  daddu     $a0, $s1, $zero
/* 9AED34 80240634 0C0B210B */  jal       get_float_variable
/* 9AED38 80240638 0040902D */   daddu    $s2, $v0, $zero
/* 9AED3C 8024063C 8E050000 */  lw        $a1, ($s0)
/* 9AED40 80240640 26100004 */  addiu     $s0, $s0, 4
/* 9AED44 80240644 4600020D */  trunc.w.s $f8, $f0
/* 9AED48 80240648 44134000 */  mfc1      $s3, $f8
/* 9AED4C 8024064C 0C0B210B */  jal       get_float_variable
/* 9AED50 80240650 0220202D */   daddu    $a0, $s1, $zero
/* 9AED54 80240654 8E050000 */  lw        $a1, ($s0)
/* 9AED58 80240658 4600020D */  trunc.w.s $f8, $f0
/* 9AED5C 8024065C 44104000 */  mfc1      $s0, $f8
/* 9AED60 80240660 0C0B210B */  jal       get_float_variable
/* 9AED64 80240664 0220202D */   daddu    $a0, $s1, $zero
/* 9AED68 80240668 4600020D */  trunc.w.s $f8, $f0
/* 9AED6C 8024066C 44044000 */  mfc1      $a0, $f8
/* 9AED70 80240670 3C028024 */  lui       $v0, %hi(func_80243090_8B3100)
/* 9AED74 80240674 24423090 */  addiu     $v0, $v0, %lo(func_80243090_8B3100)
/* 9AED78 80240678 1640000E */  bnez      $s2, .L802406B4
/* 9AED7C 8024067C 0040182D */   daddu    $v1, $v0, $zero
/* 9AED80 80240680 44930000 */  mtc1      $s3, $f0
/* 9AED84 80240684 00000000 */  nop
/* 9AED88 80240688 46800020 */  cvt.s.w   $f0, $f0
/* 9AED8C 8024068C E440001C */  swc1      $f0, 0x1c($v0)
/* 9AED90 80240690 44900000 */  mtc1      $s0, $f0
/* 9AED94 80240694 00000000 */  nop
/* 9AED98 80240698 46800020 */  cvt.s.w   $f0, $f0
/* 9AED9C 8024069C E4400020 */  swc1      $f0, 0x20($v0)
/* 9AEDA0 802406A0 44840000 */  mtc1      $a0, $f0
/* 9AEDA4 802406A4 00000000 */  nop
/* 9AEDA8 802406A8 46800020 */  cvt.s.w   $f0, $f0
/* 9AEDAC 802406AC 080901BF */  j         .L802406FC
/* 9AEDB0 802406B0 E4400024 */   swc1     $f0, 0x24($v0)
.L802406B4:
/* 9AEDB4 802406B4 C466001C */  lwc1      $f6, 0x1c($v1)
/* 9AEDB8 802406B8 44930000 */  mtc1      $s3, $f0
/* 9AEDBC 802406BC 00000000 */  nop
/* 9AEDC0 802406C0 46800020 */  cvt.s.w   $f0, $f0
/* 9AEDC4 802406C4 46003180 */  add.s     $f6, $f6, $f0
/* 9AEDC8 802406C8 C4640020 */  lwc1      $f4, 0x20($v1)
/* 9AEDCC 802406CC 44900000 */  mtc1      $s0, $f0
/* 9AEDD0 802406D0 00000000 */  nop
/* 9AEDD4 802406D4 46800020 */  cvt.s.w   $f0, $f0
/* 9AEDD8 802406D8 46002100 */  add.s     $f4, $f4, $f0
/* 9AEDDC 802406DC C4620024 */  lwc1      $f2, 0x24($v1)
/* 9AEDE0 802406E0 44840000 */  mtc1      $a0, $f0
/* 9AEDE4 802406E4 00000000 */  nop
/* 9AEDE8 802406E8 46800020 */  cvt.s.w   $f0, $f0
/* 9AEDEC 802406EC 46001080 */  add.s     $f2, $f2, $f0
/* 9AEDF0 802406F0 E466001C */  swc1      $f6, 0x1c($v1)
/* 9AEDF4 802406F4 E4640020 */  swc1      $f4, 0x20($v1)
/* 9AEDF8 802406F8 E4620024 */  swc1      $f2, 0x24($v1)
.L802406FC:
/* 9AEDFC 802406FC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9AEE00 80240700 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9AEE04 80240704 8FB20018 */  lw        $s2, 0x18($sp)
/* 9AEE08 80240708 8FB10014 */  lw        $s1, 0x14($sp)
/* 9AEE0C 8024070C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9AEE10 80240710 24020002 */  addiu     $v0, $zero, 2
/* 9AEE14 80240714 03E00008 */  jr        $ra
/* 9AEE18 80240718 27BD0028 */   addiu    $sp, $sp, 0x28
/* 9AEE1C 8024071C 00000000 */  nop
