.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8028070C
/* 1AEFEC 8028070C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1AEFF0 80280710 AFB20018 */  sw        $s2, 0x18($sp)
/* 1AEFF4 80280714 0080902D */  daddu     $s2, $a0, $zero
/* 1AEFF8 80280718 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1AEFFC 8028071C AFB10014 */  sw        $s1, 0x14($sp)
/* 1AF000 80280720 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AF004 80280724 8E440148 */  lw        $a0, 0x148($s2)
/* 1AF008 80280728 0C09A75B */  jal       get_actor
/* 1AF00C 8028072C 8E50000C */   lw       $s0, 0xc($s2)
/* 1AF010 80280730 8E050000 */  lw        $a1, ($s0)
/* 1AF014 80280734 26100004 */  addiu     $s0, $s0, 4
/* 1AF018 80280738 0240202D */  daddu     $a0, $s2, $zero
/* 1AF01C 8028073C 0C0B1EAF */  jal       get_variable
/* 1AF020 80280740 0040882D */   daddu    $s1, $v0, $zero
/* 1AF024 80280744 0240202D */  daddu     $a0, $s2, $zero
/* 1AF028 80280748 8E050000 */  lw        $a1, ($s0)
/* 1AF02C 8028074C 0C0B1EAF */  jal       get_variable
/* 1AF030 80280750 0040802D */   daddu    $s0, $v0, $zero
/* 1AF034 80280754 0200202D */  daddu     $a0, $s0, $zero
/* 1AF038 80280758 96230428 */  lhu       $v1, 0x428($s1)
/* 1AF03C 8028075C 3C06800E */  lui       $a2, 0x800e
/* 1AF040 80280760 24C6C070 */  addiu     $a2, $a2, -0x3f90
/* 1AF044 80280764 A4C301A0 */  sh        $v1, 0x1a0($a2)
/* 1AF048 80280768 92230426 */  lbu       $v1, 0x426($s1)
/* 1AF04C 8028076C 0040282D */  daddu     $a1, $v0, $zero
/* 1AF050 80280770 0C09FEE0 */  jal       dispatch_damage_event_partner_0
/* 1AF054 80280774 A0C301A2 */   sb       $v1, 0x1a2($a2)
/* 1AF058 80280778 04420005 */  bltzl     $v0, .L80280790
/* 1AF05C 8028077C 0000102D */   daddu    $v0, $zero, $zero
/* 1AF060 80280780 0C0B1069 */  jal       does_script_exist_by_ref
/* 1AF064 80280784 0240202D */   daddu    $a0, $s2, $zero
/* 1AF068 80280788 0002102B */  sltu      $v0, $zero, $v0
/* 1AF06C 8028078C 00021040 */  sll       $v0, $v0, 1
.L80280790:
/* 1AF070 80280790 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1AF074 80280794 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AF078 80280798 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AF07C 8028079C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AF080 802807A0 03E00008 */  jr        $ra
/* 1AF084 802807A4 27BD0020 */   addiu    $sp, $sp, 0x20
