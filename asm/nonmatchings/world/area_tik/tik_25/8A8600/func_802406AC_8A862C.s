.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406AC_8A862C
/* 8A862C 802406AC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8A8630 802406B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 8A8634 802406B4 0080882D */  daddu     $s1, $a0, $zero
/* 8A8638 802406B8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8A863C 802406BC AFB3001C */  sw        $s3, 0x1c($sp)
/* 8A8640 802406C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 8A8644 802406C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8A8648 802406C8 8E30000C */  lw        $s0, 0xc($s1)
/* 8A864C 802406CC 8E050000 */  lw        $a1, ($s0)
/* 8A8650 802406D0 0C0B1EAF */  jal       get_variable
/* 8A8654 802406D4 26100004 */   addiu    $s0, $s0, 4
/* 8A8658 802406D8 8E050000 */  lw        $a1, ($s0)
/* 8A865C 802406DC 26100004 */  addiu     $s0, $s0, 4
/* 8A8660 802406E0 0220202D */  daddu     $a0, $s1, $zero
/* 8A8664 802406E4 0C0B1EAF */  jal       get_variable
/* 8A8668 802406E8 0040982D */   daddu    $s3, $v0, $zero
/* 8A866C 802406EC 8E050000 */  lw        $a1, ($s0)
/* 8A8670 802406F0 26100004 */  addiu     $s0, $s0, 4
/* 8A8674 802406F4 0220202D */  daddu     $a0, $s1, $zero
/* 8A8678 802406F8 0C0B1EAF */  jal       get_variable
/* 8A867C 802406FC 0040902D */   daddu    $s2, $v0, $zero
/* 8A8680 80240700 0220202D */  daddu     $a0, $s1, $zero
/* 8A8684 80240704 8E050000 */  lw        $a1, ($s0)
/* 8A8688 80240708 0C0B1EAF */  jal       get_variable
/* 8A868C 8024070C 0040882D */   daddu    $s1, $v0, $zero
/* 8A8690 80240710 0260202D */  daddu     $a0, $s3, $zero
/* 8A8694 80240714 0C04417A */  jal       get_entity_by_index
/* 8A8698 80240718 0040802D */   daddu    $s0, $v0, $zero
/* 8A869C 8024071C 0040182D */  daddu     $v1, $v0, $zero
/* 8A86A0 80240720 44920000 */  mtc1      $s2, $f0
/* 8A86A4 80240724 00000000 */  nop       
/* 8A86A8 80240728 46800020 */  cvt.s.w   $f0, $f0
/* 8A86AC 8024072C E4600048 */  swc1      $f0, 0x48($v1)
/* 8A86B0 80240730 44910000 */  mtc1      $s1, $f0
/* 8A86B4 80240734 00000000 */  nop       
/* 8A86B8 80240738 46800020 */  cvt.s.w   $f0, $f0
/* 8A86BC 8024073C E460004C */  swc1      $f0, 0x4c($v1)
/* 8A86C0 80240740 44900000 */  mtc1      $s0, $f0
/* 8A86C4 80240744 00000000 */  nop       
/* 8A86C8 80240748 46800020 */  cvt.s.w   $f0, $f0
/* 8A86CC 8024074C E4600050 */  swc1      $f0, 0x50($v1)
/* 8A86D0 80240750 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8A86D4 80240754 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8A86D8 80240758 8FB20018 */  lw        $s2, 0x18($sp)
/* 8A86DC 8024075C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8A86E0 80240760 8FB00010 */  lw        $s0, 0x10($sp)
/* 8A86E4 80240764 24020002 */  addiu     $v0, $zero, 2
/* 8A86E8 80240768 03E00008 */  jr        $ra
/* 8A86EC 8024076C 27BD0028 */   addiu    $sp, $sp, 0x28
