.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_bind
/* EB0C4 802C6714 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EB0C8 802C6718 AFB3003C */  sw        $s3, 0x3c($sp)
/* EB0CC 802C671C 0080982D */  daddu     $s3, $a0, $zero
/* EB0D0 802C6720 AFBF0044 */  sw        $ra, 0x44($sp)
/* EB0D4 802C6724 AFB40040 */  sw        $s4, 0x40($sp)
/* EB0D8 802C6728 AFB20038 */  sw        $s2, 0x38($sp)
/* EB0DC 802C672C AFB10034 */  sw        $s1, 0x34($sp)
/* EB0E0 802C6730 AFB00030 */  sw        $s0, 0x30($sp)
/* EB0E4 802C6734 8E70000C */  lw        $s0, 0xc($s3)
/* EB0E8 802C6738 8E050000 */  lw        $a1, ($s0)
/* EB0EC 802C673C 0C0B1EAF */  jal       get_variable
/* EB0F0 802C6740 26100004 */   addiu    $s0, $s0, 4
/* EB0F4 802C6744 8E030000 */  lw        $v1, ($s0)
/* EB0F8 802C6748 26100004 */  addiu     $s0, $s0, 4
/* EB0FC 802C674C 8E110000 */  lw        $s1, ($s0)
/* EB100 802C6750 26100004 */  addiu     $s0, $s0, 4
/* EB104 802C6754 0260202D */  daddu     $a0, $s3, $zero
/* EB108 802C6758 3C060100 */  lui       $a2, 0x100
/* EB10C 802C675C 8E120000 */  lw        $s2, ($s0)
/* EB110 802C6760 8E140004 */  lw        $s4, 4($s0)
/* EB114 802C6764 0040802D */  daddu     $s0, $v0, $zero
/* EB118 802C6768 0220282D */  daddu     $a1, $s1, $zero
/* EB11C 802C676C 00661825 */  or        $v1, $v1, $a2
/* EB120 802C6770 0C0B1EAF */  jal       get_variable
/* EB124 802C6774 AFA30010 */   sw       $v1, 0x10($sp)
/* EB128 802C6778 0260202D */  daddu     $a0, $s3, $zero
/* EB12C 802C677C 0220282D */  daddu     $a1, $s1, $zero
/* EB130 802C6780 0C0B1F6A */  jal       get_variable_index
/* EB134 802C6784 AFA20018 */   sw       $v0, 0x18($sp)
/* EB138 802C6788 27A40010 */  addiu     $a0, $sp, 0x10
/* EB13C 802C678C A7A20014 */  sh        $v0, 0x14($sp)
/* EB140 802C6790 3C02802C */  lui       $v0, 0x802c
/* EB144 802C6794 2442667C */  addiu     $v0, $v0, 0x667c
/* EB148 802C6798 AFB20028 */  sw        $s2, 0x28($sp)
/* EB14C 802C679C AFA00024 */  sw        $zero, 0x24($sp)
/* EB150 802C67A0 0C0515DB */  jal       create_trigger
/* EB154 802C67A4 AFA2001C */   sw       $v0, 0x1c($sp)
/* EB158 802C67A8 0040882D */  daddu     $s1, $v0, $zero
/* EB15C 802C67AC AE300010 */  sw        $s0, 0x10($s1)
/* EB160 802C67B0 AE200014 */  sw        $zero, 0x14($s1)
/* EB164 802C67B4 92620003 */  lbu       $v0, 3($s3)
/* EB168 802C67B8 AE220018 */  sw        $v0, 0x18($s1)
/* EB16C 802C67BC 8E650084 */  lw        $a1, 0x84($s3)
/* EB170 802C67C0 0C0B1EAF */  jal       get_variable
/* EB174 802C67C4 0260202D */   daddu    $a0, $s3, $zero
/* EB178 802C67C8 AE22001C */  sw        $v0, 0x1c($s1)
/* EB17C 802C67CC 8E650088 */  lw        $a1, 0x88($s3)
/* EB180 802C67D0 0C0B1EAF */  jal       get_variable
/* EB184 802C67D4 0260202D */   daddu    $a0, $s3, $zero
/* EB188 802C67D8 AE220020 */  sw        $v0, 0x20($s1)
/* EB18C 802C67DC 8E65008C */  lw        $a1, 0x8c($s3)
/* EB190 802C67E0 0C0B1EAF */  jal       get_variable
/* EB194 802C67E4 0260202D */   daddu    $a0, $s3, $zero
/* EB198 802C67E8 12800005 */  beqz      $s4, .L802C6800
/* EB19C 802C67EC AE220024 */   sw       $v0, 0x24($s1)
/* EB1A0 802C67F0 0260202D */  daddu     $a0, $s3, $zero
/* EB1A4 802C67F4 0280282D */  daddu     $a1, $s4, $zero
/* EB1A8 802C67F8 0C0B2026 */  jal       set_variable
/* EB1AC 802C67FC 0220302D */   daddu    $a2, $s1, $zero
.L802C6800:
/* EB1B0 802C6800 8FBF0044 */  lw        $ra, 0x44($sp)
/* EB1B4 802C6804 8FB40040 */  lw        $s4, 0x40($sp)
/* EB1B8 802C6808 8FB3003C */  lw        $s3, 0x3c($sp)
/* EB1BC 802C680C 8FB20038 */  lw        $s2, 0x38($sp)
/* EB1C0 802C6810 8FB10034 */  lw        $s1, 0x34($sp)
/* EB1C4 802C6814 8FB00030 */  lw        $s0, 0x30($sp)
/* EB1C8 802C6818 24020002 */  addiu     $v0, $zero, 2
/* EB1CC 802C681C 03E00008 */  jr        $ra
/* EB1D0 802C6820 27BD0048 */   addiu    $sp, $sp, 0x48
