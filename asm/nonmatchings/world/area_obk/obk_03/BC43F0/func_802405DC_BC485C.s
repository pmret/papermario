.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405DC_BC485C
/* BC485C 802405DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC4860 802405E0 AFB10014 */  sw        $s1, 0x14($sp)
/* BC4864 802405E4 0080882D */  daddu     $s1, $a0, $zero
/* BC4868 802405E8 AFBF0018 */  sw        $ra, 0x18($sp)
/* BC486C 802405EC AFB00010 */  sw        $s0, 0x10($sp)
/* BC4870 802405F0 8E30000C */  lw        $s0, 0xc($s1)
/* BC4874 802405F4 8E050000 */  lw        $a1, ($s0)
/* BC4878 802405F8 0C0B1EAF */  jal       get_variable
/* BC487C 802405FC 26100004 */   addiu    $s0, $s0, 4
/* BC4880 80240600 AE22008C */  sw        $v0, 0x8c($s1)
/* BC4884 80240604 8E050000 */  lw        $a1, ($s0)
/* BC4888 80240608 26100004 */  addiu     $s0, $s0, 4
/* BC488C 8024060C 0C0B1EAF */  jal       get_variable
/* BC4890 80240610 0220202D */   daddu    $a0, $s1, $zero
/* BC4894 80240614 AE220090 */  sw        $v0, 0x90($s1)
/* BC4898 80240618 8E050000 */  lw        $a1, ($s0)
/* BC489C 8024061C 26100004 */  addiu     $s0, $s0, 4
/* BC48A0 80240620 0C0B1EAF */  jal       get_variable
/* BC48A4 80240624 0220202D */   daddu    $a0, $s1, $zero
/* BC48A8 80240628 AE220094 */  sw        $v0, 0x94($s1)
/* BC48AC 8024062C 8E050000 */  lw        $a1, ($s0)
/* BC48B0 80240630 26100004 */  addiu     $s0, $s0, 4
/* BC48B4 80240634 0C0B1EAF */  jal       get_variable
/* BC48B8 80240638 0220202D */   daddu    $a0, $s1, $zero
/* BC48BC 8024063C AE220098 */  sw        $v0, 0x98($s1)
/* BC48C0 80240640 8E050000 */  lw        $a1, ($s0)
/* BC48C4 80240644 26100004 */  addiu     $s0, $s0, 4
/* BC48C8 80240648 0C0B1EAF */  jal       get_variable
/* BC48CC 8024064C 0220202D */   daddu    $a0, $s1, $zero
/* BC48D0 80240650 AE22009C */  sw        $v0, 0x9c($s1)
/* BC48D4 80240654 8E050000 */  lw        $a1, ($s0)
/* BC48D8 80240658 26100004 */  addiu     $s0, $s0, 4
/* BC48DC 8024065C 0C0B1EAF */  jal       get_variable
/* BC48E0 80240660 0220202D */   daddu    $a0, $s1, $zero
/* BC48E4 80240664 AE2200A0 */  sw        $v0, 0xa0($s1)
/* BC48E8 80240668 8E050000 */  lw        $a1, ($s0)
/* BC48EC 8024066C 26100004 */  addiu     $s0, $s0, 4
/* BC48F0 80240670 0C0B1EAF */  jal       get_variable
/* BC48F4 80240674 0220202D */   daddu    $a0, $s1, $zero
/* BC48F8 80240678 AE2200A4 */  sw        $v0, 0xa4($s1)
/* BC48FC 8024067C 8E050000 */  lw        $a1, ($s0)
/* BC4900 80240680 26100004 */  addiu     $s0, $s0, 4
/* BC4904 80240684 0C0B1EAF */  jal       get_variable
/* BC4908 80240688 0220202D */   daddu    $a0, $s1, $zero
/* BC490C 8024068C AE2200A8 */  sw        $v0, 0xa8($s1)
/* BC4910 80240690 8E050000 */  lw        $a1, ($s0)
/* BC4914 80240694 26100004 */  addiu     $s0, $s0, 4
/* BC4918 80240698 0C0B1EAF */  jal       get_variable
/* BC491C 8024069C 0220202D */   daddu    $a0, $s1, $zero
/* BC4920 802406A0 AE2200AC */  sw        $v0, 0xac($s1)
/* BC4924 802406A4 8E050000 */  lw        $a1, ($s0)
/* BC4928 802406A8 0C0B1EAF */  jal       get_variable
/* BC492C 802406AC 0220202D */   daddu    $a0, $s1, $zero
/* BC4930 802406B0 AE2200B0 */  sw        $v0, 0xb0($s1)
/* BC4934 802406B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* BC4938 802406B8 8FB10014 */  lw        $s1, 0x14($sp)
/* BC493C 802406BC 8FB00010 */  lw        $s0, 0x10($sp)
/* BC4940 802406C0 24020002 */  addiu     $v0, $zero, 2
/* BC4944 802406C4 03E00008 */  jr        $ra
/* BC4948 802406C8 27BD0020 */   addiu    $sp, $sp, 0x20
