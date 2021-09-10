.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E34_991614
/* 991614 80241E34 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 991618 80241E38 AFB10014 */  sw        $s1, 0x14($sp)
/* 99161C 80241E3C 0080882D */  daddu     $s1, $a0, $zero
/* 991620 80241E40 AFBF0020 */  sw        $ra, 0x20($sp)
/* 991624 80241E44 AFB3001C */  sw        $s3, 0x1c($sp)
/* 991628 80241E48 AFB20018 */  sw        $s2, 0x18($sp)
/* 99162C 80241E4C AFB00010 */  sw        $s0, 0x10($sp)
/* 991630 80241E50 8E30000C */  lw        $s0, 0xc($s1)
/* 991634 80241E54 8E050000 */  lw        $a1, ($s0)
/* 991638 80241E58 0C0B210B */  jal       evt_get_float_variable
/* 99163C 80241E5C 26100004 */   addiu    $s0, $s0, 4
/* 991640 80241E60 8E050000 */  lw        $a1, ($s0)
/* 991644 80241E64 26100004 */  addiu     $s0, $s0, 4
/* 991648 80241E68 4600008D */  trunc.w.s $f2, $f0
/* 99164C 80241E6C 44131000 */  mfc1      $s3, $f2
/* 991650 80241E70 0C0B210B */  jal       evt_get_float_variable
/* 991654 80241E74 0220202D */   daddu    $a0, $s1, $zero
/* 991658 80241E78 8E050000 */  lw        $a1, ($s0)
/* 99165C 80241E7C 4600008D */  trunc.w.s $f2, $f0
/* 991660 80241E80 44121000 */  mfc1      $s2, $f2
/* 991664 80241E84 0C0B210B */  jal       evt_get_float_variable
/* 991668 80241E88 0220202D */   daddu    $a0, $s1, $zero
/* 99166C 80241E8C 0220202D */  daddu     $a0, $s1, $zero
/* 991670 80241E90 3C05FD05 */  lui       $a1, 0xfd05
/* 991674 80241E94 4600008D */  trunc.w.s $f2, $f0
/* 991678 80241E98 44101000 */  mfc1      $s0, $f2
/* 99167C 80241E9C 0C0B1EAF */  jal       evt_get_variable
/* 991680 80241EA0 34A50F8A */   ori      $a1, $a1, 0xf8a
/* 991684 80241EA4 0040182D */  daddu     $v1, $v0, $zero
/* 991688 80241EA8 44930000 */  mtc1      $s3, $f0
/* 99168C 80241EAC 00000000 */  nop
/* 991690 80241EB0 46800020 */  cvt.s.w   $f0, $f0
/* 991694 80241EB4 E4600020 */  swc1      $f0, 0x20($v1)
/* 991698 80241EB8 44920000 */  mtc1      $s2, $f0
/* 99169C 80241EBC 00000000 */  nop
/* 9916A0 80241EC0 46800020 */  cvt.s.w   $f0, $f0
/* 9916A4 80241EC4 E4600024 */  swc1      $f0, 0x24($v1)
/* 9916A8 80241EC8 44900000 */  mtc1      $s0, $f0
/* 9916AC 80241ECC 00000000 */  nop
/* 9916B0 80241ED0 46800020 */  cvt.s.w   $f0, $f0
/* 9916B4 80241ED4 E4600028 */  swc1      $f0, 0x28($v1)
/* 9916B8 80241ED8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9916BC 80241EDC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9916C0 80241EE0 8FB20018 */  lw        $s2, 0x18($sp)
/* 9916C4 80241EE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9916C8 80241EE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9916CC 80241EEC 24020002 */  addiu     $v0, $zero, 2
/* 9916D0 80241EF0 03E00008 */  jr        $ra
/* 9916D4 80241EF4 27BD0028 */   addiu    $sp, $sp, 0x28
