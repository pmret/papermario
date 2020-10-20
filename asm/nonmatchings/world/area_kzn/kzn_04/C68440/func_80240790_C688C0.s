.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240790_C688C0
/* C688C0 80240790 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C688C4 80240794 AFB1001C */  sw        $s1, 0x1c($sp)
/* C688C8 80240798 0080882D */  daddu     $s1, $a0, $zero
/* C688CC 8024079C AFBF0020 */  sw        $ra, 0x20($sp)
/* C688D0 802407A0 AFB00018 */  sw        $s0, 0x18($sp)
/* C688D4 802407A4 8E30000C */  lw        $s0, 0xc($s1)
/* C688D8 802407A8 8E050000 */  lw        $a1, ($s0)
/* C688DC 802407AC 0C0B1EAF */  jal       get_variable
/* C688E0 802407B0 26100004 */   addiu    $s0, $s0, 4
/* C688E4 802407B4 0C04417A */  jal       get_entity_by_index
/* C688E8 802407B8 0040202D */   daddu    $a0, $v0, $zero
/* C688EC 802407BC 8E100000 */  lw        $s0, ($s0)
/* C688F0 802407C0 C444004C */  lwc1      $f4, 0x4c($v0)
/* C688F4 802407C4 3C014148 */  lui       $at, 0x4148
/* C688F8 802407C8 44810000 */  mtc1      $at, $f0
/* C688FC 802407CC 3C013F33 */  lui       $at, 0x3f33
/* C68900 802407D0 34213333 */  ori       $at, $at, 0x3333
/* C68904 802407D4 44811000 */  mtc1      $at, $f2
/* C68908 802407D8 AFA00014 */  sw        $zero, 0x14($sp)
/* C6890C 802407DC 46002100 */  add.s     $f4, $f4, $f0
/* C68910 802407E0 E7A20010 */  swc1      $f2, 0x10($sp)
/* C68914 802407E4 8C450048 */  lw        $a1, 0x48($v0)
/* C68918 802407E8 8C470050 */  lw        $a3, 0x50($v0)
/* C6891C 802407EC 44062000 */  mfc1      $a2, $f4
/* C68920 802407F0 0C01C5D4 */  jal       func_80071750
/* C68924 802407F4 0000202D */   daddu    $a0, $zero, $zero
/* C68928 802407F8 0220202D */  daddu     $a0, $s1, $zero
/* C6892C 802407FC 0200282D */  daddu     $a1, $s0, $zero
/* C68930 80240800 0C0B2026 */  jal       set_variable
/* C68934 80240804 0040302D */   daddu    $a2, $v0, $zero
/* C68938 80240808 8FBF0020 */  lw        $ra, 0x20($sp)
/* C6893C 8024080C 8FB1001C */  lw        $s1, 0x1c($sp)
/* C68940 80240810 8FB00018 */  lw        $s0, 0x18($sp)
/* C68944 80240814 24020002 */  addiu     $v0, $zero, 2
/* C68948 80240818 03E00008 */  jr        $ra
/* C6894C 8024081C 27BD0028 */   addiu    $sp, $sp, 0x28
