.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218680_4FF0D0
/* 4FF0D0 80218680 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4FF0D4 80218684 AFB10014 */  sw        $s1, 0x14($sp)
/* 4FF0D8 80218688 0080882D */  daddu     $s1, $a0, $zero
/* 4FF0DC 8021868C AFBF0024 */  sw        $ra, 0x24($sp)
/* 4FF0E0 80218690 AFB40020 */  sw        $s4, 0x20($sp)
/* 4FF0E4 80218694 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4FF0E8 80218698 AFB20018 */  sw        $s2, 0x18($sp)
/* 4FF0EC 8021869C AFB00010 */  sw        $s0, 0x10($sp)
/* 4FF0F0 802186A0 8E30000C */  lw        $s0, 0xc($s1)
/* 4FF0F4 802186A4 8E050000 */  lw        $a1, ($s0)
/* 4FF0F8 802186A8 0C0B1EAF */  jal       evt_get_variable
/* 4FF0FC 802186AC 26100004 */   addiu    $s0, $s0, 4
/* 4FF100 802186B0 8E050000 */  lw        $a1, ($s0)
/* 4FF104 802186B4 26100004 */  addiu     $s0, $s0, 4
/* 4FF108 802186B8 0220202D */  daddu     $a0, $s1, $zero
/* 4FF10C 802186BC 0C0B1EAF */  jal       evt_get_variable
/* 4FF110 802186C0 0040902D */   daddu    $s2, $v0, $zero
/* 4FF114 802186C4 8E050000 */  lw        $a1, ($s0)
/* 4FF118 802186C8 26100004 */  addiu     $s0, $s0, 4
/* 4FF11C 802186CC 0220202D */  daddu     $a0, $s1, $zero
/* 4FF120 802186D0 0C0B1EAF */  jal       evt_get_variable
/* 4FF124 802186D4 0040A02D */   daddu    $s4, $v0, $zero
/* 4FF128 802186D8 8E050000 */  lw        $a1, ($s0)
/* 4FF12C 802186DC 26100004 */  addiu     $s0, $s0, 4
/* 4FF130 802186E0 0220202D */  daddu     $a0, $s1, $zero
/* 4FF134 802186E4 0C0B1EAF */  jal       evt_get_variable
/* 4FF138 802186E8 0040982D */   daddu    $s3, $v0, $zero
/* 4FF13C 802186EC 0220202D */  daddu     $a0, $s1, $zero
/* 4FF140 802186F0 8E050000 */  lw        $a1, ($s0)
/* 4FF144 802186F4 0C0B210B */  jal       evt_get_float_variable
/* 4FF148 802186F8 0040802D */   daddu    $s0, $v0, $zero
/* 4FF14C 802186FC 8E42000C */  lw        $v0, 0xc($s2)
/* 4FF150 80218700 44941000 */  mtc1      $s4, $f2
/* 4FF154 80218704 00000000 */  nop
/* 4FF158 80218708 468010A0 */  cvt.s.w   $f2, $f2
/* 4FF15C 8021870C E4420004 */  swc1      $f2, 4($v0)
/* 4FF160 80218710 8E42000C */  lw        $v0, 0xc($s2)
/* 4FF164 80218714 44931000 */  mtc1      $s3, $f2
/* 4FF168 80218718 00000000 */  nop
/* 4FF16C 8021871C 468010A0 */  cvt.s.w   $f2, $f2
/* 4FF170 80218720 E4420008 */  swc1      $f2, 8($v0)
/* 4FF174 80218724 8E42000C */  lw        $v0, 0xc($s2)
/* 4FF178 80218728 44901000 */  mtc1      $s0, $f2
/* 4FF17C 8021872C 00000000 */  nop
/* 4FF180 80218730 468010A0 */  cvt.s.w   $f2, $f2
/* 4FF184 80218734 E442000C */  swc1      $f2, 0xc($v0)
/* 4FF188 80218738 8E43000C */  lw        $v1, 0xc($s2)
/* 4FF18C 8021873C E4600034 */  swc1      $f0, 0x34($v1)
/* 4FF190 80218740 8FBF0024 */  lw        $ra, 0x24($sp)
/* 4FF194 80218744 8FB40020 */  lw        $s4, 0x20($sp)
/* 4FF198 80218748 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4FF19C 8021874C 8FB20018 */  lw        $s2, 0x18($sp)
/* 4FF1A0 80218750 8FB10014 */  lw        $s1, 0x14($sp)
/* 4FF1A4 80218754 8FB00010 */  lw        $s0, 0x10($sp)
/* 4FF1A8 80218758 24020002 */  addiu     $v0, $zero, 2
/* 4FF1AC 8021875C 03E00008 */  jr        $ra
/* 4FF1B0 80218760 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4FF1B4 80218764 00000000 */  nop
/* 4FF1B8 80218768 00000000 */  nop
/* 4FF1BC 8021876C 00000000 */  nop
