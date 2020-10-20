.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241790_C50CA0
/* C50CA0 80241790 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C50CA4 80241794 AFB20018 */  sw        $s2, 0x18($sp)
/* C50CA8 80241798 0080902D */  daddu     $s2, $a0, $zero
/* C50CAC 8024179C AFBF001C */  sw        $ra, 0x1c($sp)
/* C50CB0 802417A0 AFB10014 */  sw        $s1, 0x14($sp)
/* C50CB4 802417A4 AFB00010 */  sw        $s0, 0x10($sp)
/* C50CB8 802417A8 8E50000C */  lw        $s0, 0xc($s2)
/* C50CBC 802417AC 8E050000 */  lw        $a1, ($s0)
/* C50CC0 802417B0 0C0B1EAF */  jal       get_variable
/* C50CC4 802417B4 26100004 */   addiu    $s0, $s0, 4
/* C50CC8 802417B8 0C04417A */  jal       get_entity_by_index
/* C50CCC 802417BC 0040202D */   daddu    $a0, $v0, $zero
/* C50CD0 802417C0 8E050000 */  lw        $a1, ($s0)
/* C50CD4 802417C4 26100004 */  addiu     $s0, $s0, 4
/* C50CD8 802417C8 0040882D */  daddu     $s1, $v0, $zero
/* C50CDC 802417CC C6200048 */  lwc1      $f0, 0x48($s1)
/* C50CE0 802417D0 4600008D */  trunc.w.s $f2, $f0
/* C50CE4 802417D4 44061000 */  mfc1      $a2, $f2
/* C50CE8 802417D8 0C0B2026 */  jal       set_variable
/* C50CEC 802417DC 0240202D */   daddu    $a0, $s2, $zero
/* C50CF0 802417E0 8E050000 */  lw        $a1, ($s0)
/* C50CF4 802417E4 26100004 */  addiu     $s0, $s0, 4
/* C50CF8 802417E8 C620004C */  lwc1      $f0, 0x4c($s1)
/* C50CFC 802417EC 4600008D */  trunc.w.s $f2, $f0
/* C50D00 802417F0 44061000 */  mfc1      $a2, $f2
/* C50D04 802417F4 0C0B2026 */  jal       set_variable
/* C50D08 802417F8 0240202D */   daddu    $a0, $s2, $zero
/* C50D0C 802417FC C6200050 */  lwc1      $f0, 0x50($s1)
/* C50D10 80241800 8E050000 */  lw        $a1, ($s0)
/* C50D14 80241804 4600008D */  trunc.w.s $f2, $f0
/* C50D18 80241808 44061000 */  mfc1      $a2, $f2
/* C50D1C 8024180C 0C0B2026 */  jal       set_variable
/* C50D20 80241810 0240202D */   daddu    $a0, $s2, $zero
/* C50D24 80241814 8FBF001C */  lw        $ra, 0x1c($sp)
/* C50D28 80241818 8FB20018 */  lw        $s2, 0x18($sp)
/* C50D2C 8024181C 8FB10014 */  lw        $s1, 0x14($sp)
/* C50D30 80241820 8FB00010 */  lw        $s0, 0x10($sp)
/* C50D34 80241824 24020002 */  addiu     $v0, $zero, 2
/* C50D38 80241828 03E00008 */  jr        $ra
/* C50D3C 8024182C 27BD0020 */   addiu    $sp, $sp, 0x20
