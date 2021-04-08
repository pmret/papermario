.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel iwa_10_UnkFunc20
/* 91ECE0 80240770 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 91ECE4 80240774 AFB1001C */  sw        $s1, 0x1c($sp)
/* 91ECE8 80240778 0080882D */  daddu     $s1, $a0, $zero
/* 91ECEC 8024077C AFBF0020 */  sw        $ra, 0x20($sp)
/* 91ECF0 80240780 AFB00018 */  sw        $s0, 0x18($sp)
/* 91ECF4 80240784 8E30000C */  lw        $s0, 0xc($s1)
/* 91ECF8 80240788 8E050000 */  lw        $a1, ($s0)
/* 91ECFC 8024078C 0C0B1EAF */  jal       get_variable
/* 91ED00 80240790 26100004 */   addiu    $s0, $s0, 4
/* 91ED04 80240794 0C04417A */  jal       get_entity_by_index
/* 91ED08 80240798 0040202D */   daddu    $a0, $v0, $zero
/* 91ED0C 8024079C 8E100000 */  lw        $s0, ($s0)
/* 91ED10 802407A0 C444004C */  lwc1      $f4, 0x4c($v0)
/* 91ED14 802407A4 3C014148 */  lui       $at, 0x4148
/* 91ED18 802407A8 44810000 */  mtc1      $at, $f0
/* 91ED1C 802407AC 3C013F33 */  lui       $at, 0x3f33
/* 91ED20 802407B0 34213333 */  ori       $at, $at, 0x3333
/* 91ED24 802407B4 44811000 */  mtc1      $at, $f2
/* 91ED28 802407B8 AFA00014 */  sw        $zero, 0x14($sp)
/* 91ED2C 802407BC 46002100 */  add.s     $f4, $f4, $f0
/* 91ED30 802407C0 E7A20010 */  swc1      $f2, 0x10($sp)
/* 91ED34 802407C4 8C450048 */  lw        $a1, 0x48($v0)
/* 91ED38 802407C8 8C470050 */  lw        $a3, 0x50($v0)
/* 91ED3C 802407CC 44062000 */  mfc1      $a2, $f4
/* 91ED40 802407D0 0C01C5D4 */  jal       func_80071750
/* 91ED44 802407D4 0000202D */   daddu    $a0, $zero, $zero
/* 91ED48 802407D8 0220202D */  daddu     $a0, $s1, $zero
/* 91ED4C 802407DC 0200282D */  daddu     $a1, $s0, $zero
/* 91ED50 802407E0 0C0B2026 */  jal       set_variable
/* 91ED54 802407E4 0040302D */   daddu    $a2, $v0, $zero
/* 91ED58 802407E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 91ED5C 802407EC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 91ED60 802407F0 8FB00018 */  lw        $s0, 0x18($sp)
/* 91ED64 802407F4 24020002 */  addiu     $v0, $zero, 2
/* 91ED68 802407F8 03E00008 */  jr        $ra
/* 91ED6C 802407FC 27BD0028 */   addiu    $sp, $sp, 0x28
