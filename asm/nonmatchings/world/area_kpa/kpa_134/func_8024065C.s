.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024065C
/* AA95FC 8024065C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AA9600 80240660 AFB20018 */  sw        $s2, 0x18($sp)
/* AA9604 80240664 0080902D */  daddu     $s2, $a0, $zero
/* AA9608 80240668 AFBF001C */  sw        $ra, 0x1c($sp)
/* AA960C 8024066C AFB10014 */  sw        $s1, 0x14($sp)
/* AA9610 80240670 AFB00010 */  sw        $s0, 0x10($sp)
/* AA9614 80240674 8E50000C */  lw        $s0, 0xc($s2)
/* AA9618 80240678 8E050000 */  lw        $a1, ($s0)
/* AA961C 8024067C 0C0B1EAF */  jal       get_variable
/* AA9620 80240680 26100004 */   addiu    $s0, $s0, 4
/* AA9624 80240684 0C04417A */  jal       get_entity_by_index
/* AA9628 80240688 0040202D */   daddu    $a0, $v0, $zero
/* AA962C 8024068C 8E050000 */  lw        $a1, ($s0)
/* AA9630 80240690 26100004 */  addiu     $s0, $s0, 4
/* AA9634 80240694 0040882D */  daddu     $s1, $v0, $zero
/* AA9638 80240698 C6200048 */  lwc1      $f0, 0x48($s1)
/* AA963C 8024069C 4600008D */  trunc.w.s $f2, $f0
/* AA9640 802406A0 44061000 */  mfc1      $a2, $f2
/* AA9644 802406A4 0C0B2026 */  jal       set_variable
/* AA9648 802406A8 0240202D */   daddu    $a0, $s2, $zero
/* AA964C 802406AC 8E050000 */  lw        $a1, ($s0)
/* AA9650 802406B0 26100004 */  addiu     $s0, $s0, 4
/* AA9654 802406B4 C620004C */  lwc1      $f0, 0x4c($s1)
/* AA9658 802406B8 4600008D */  trunc.w.s $f2, $f0
/* AA965C 802406BC 44061000 */  mfc1      $a2, $f2
/* AA9660 802406C0 0C0B2026 */  jal       set_variable
/* AA9664 802406C4 0240202D */   daddu    $a0, $s2, $zero
/* AA9668 802406C8 C6200050 */  lwc1      $f0, 0x50($s1)
/* AA966C 802406CC 8E050000 */  lw        $a1, ($s0)
/* AA9670 802406D0 4600008D */  trunc.w.s $f2, $f0
/* AA9674 802406D4 44061000 */  mfc1      $a2, $f2
/* AA9678 802406D8 0C0B2026 */  jal       set_variable
/* AA967C 802406DC 0240202D */   daddu    $a0, $s2, $zero
/* AA9680 802406E0 8FBF001C */  lw        $ra, 0x1c($sp)
/* AA9684 802406E4 8FB20018 */  lw        $s2, 0x18($sp)
/* AA9688 802406E8 8FB10014 */  lw        $s1, 0x14($sp)
/* AA968C 802406EC 8FB00010 */  lw        $s0, 0x10($sp)
/* AA9690 802406F0 24020002 */  addiu     $v0, $zero, 2
/* AA9694 802406F4 03E00008 */  jr        $ra
/* AA9698 802406F8 27BD0020 */   addiu    $sp, $sp, 0x20
/* AA969C 802406FC 00000000 */  nop       
