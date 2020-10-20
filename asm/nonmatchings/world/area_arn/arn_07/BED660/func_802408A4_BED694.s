.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408A4_BED694
/* BED694 802408A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BED698 802408A8 AFB20018 */  sw        $s2, 0x18($sp)
/* BED69C 802408AC 0080902D */  daddu     $s2, $a0, $zero
/* BED6A0 802408B0 AFBF001C */  sw        $ra, 0x1c($sp)
/* BED6A4 802408B4 AFB10014 */  sw        $s1, 0x14($sp)
/* BED6A8 802408B8 AFB00010 */  sw        $s0, 0x10($sp)
/* BED6AC 802408BC 8E50000C */  lw        $s0, 0xc($s2)
/* BED6B0 802408C0 8E050000 */  lw        $a1, ($s0)
/* BED6B4 802408C4 0C0B1EAF */  jal       get_variable
/* BED6B8 802408C8 26100004 */   addiu    $s0, $s0, 4
/* BED6BC 802408CC 0C04417A */  jal       get_entity_by_index
/* BED6C0 802408D0 0040202D */   daddu    $a0, $v0, $zero
/* BED6C4 802408D4 8E050000 */  lw        $a1, ($s0)
/* BED6C8 802408D8 26100004 */  addiu     $s0, $s0, 4
/* BED6CC 802408DC 0040882D */  daddu     $s1, $v0, $zero
/* BED6D0 802408E0 C6200048 */  lwc1      $f0, 0x48($s1)
/* BED6D4 802408E4 4600008D */  trunc.w.s $f2, $f0
/* BED6D8 802408E8 44061000 */  mfc1      $a2, $f2
/* BED6DC 802408EC 0C0B2026 */  jal       set_variable
/* BED6E0 802408F0 0240202D */   daddu    $a0, $s2, $zero
/* BED6E4 802408F4 8E050000 */  lw        $a1, ($s0)
/* BED6E8 802408F8 26100004 */  addiu     $s0, $s0, 4
/* BED6EC 802408FC C620004C */  lwc1      $f0, 0x4c($s1)
/* BED6F0 80240900 4600008D */  trunc.w.s $f2, $f0
/* BED6F4 80240904 44061000 */  mfc1      $a2, $f2
/* BED6F8 80240908 0C0B2026 */  jal       set_variable
/* BED6FC 8024090C 0240202D */   daddu    $a0, $s2, $zero
/* BED700 80240910 C6200050 */  lwc1      $f0, 0x50($s1)
/* BED704 80240914 8E050000 */  lw        $a1, ($s0)
/* BED708 80240918 4600008D */  trunc.w.s $f2, $f0
/* BED70C 8024091C 44061000 */  mfc1      $a2, $f2
/* BED710 80240920 0C0B2026 */  jal       set_variable
/* BED714 80240924 0240202D */   daddu    $a0, $s2, $zero
/* BED718 80240928 8FBF001C */  lw        $ra, 0x1c($sp)
/* BED71C 8024092C 8FB20018 */  lw        $s2, 0x18($sp)
/* BED720 80240930 8FB10014 */  lw        $s1, 0x14($sp)
/* BED724 80240934 8FB00010 */  lw        $s0, 0x10($sp)
/* BED728 80240938 24020002 */  addiu     $v0, $zero, 2
/* BED72C 8024093C 03E00008 */  jr        $ra
/* BED730 80240940 27BD0020 */   addiu    $sp, $sp, 0x20
/* BED734 80240944 00000000 */  nop       
/* BED738 80240948 00000000 */  nop       
/* BED73C 8024094C 00000000 */  nop       
