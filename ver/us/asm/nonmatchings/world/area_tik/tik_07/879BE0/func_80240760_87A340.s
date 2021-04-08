.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_07_UnkFunc20
/* 87A340 80240760 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 87A344 80240764 AFB1001C */  sw        $s1, 0x1c($sp)
/* 87A348 80240768 0080882D */  daddu     $s1, $a0, $zero
/* 87A34C 8024076C AFBF0020 */  sw        $ra, 0x20($sp)
/* 87A350 80240770 AFB00018 */  sw        $s0, 0x18($sp)
/* 87A354 80240774 8E30000C */  lw        $s0, 0xc($s1)
/* 87A358 80240778 8E050000 */  lw        $a1, ($s0)
/* 87A35C 8024077C 0C0B1EAF */  jal       get_variable
/* 87A360 80240780 26100004 */   addiu    $s0, $s0, 4
/* 87A364 80240784 0C04417A */  jal       get_entity_by_index
/* 87A368 80240788 0040202D */   daddu    $a0, $v0, $zero
/* 87A36C 8024078C 8E100000 */  lw        $s0, ($s0)
/* 87A370 80240790 C444004C */  lwc1      $f4, 0x4c($v0)
/* 87A374 80240794 3C014148 */  lui       $at, 0x4148
/* 87A378 80240798 44810000 */  mtc1      $at, $f0
/* 87A37C 8024079C 3C013F33 */  lui       $at, 0x3f33
/* 87A380 802407A0 34213333 */  ori       $at, $at, 0x3333
/* 87A384 802407A4 44811000 */  mtc1      $at, $f2
/* 87A388 802407A8 AFA00014 */  sw        $zero, 0x14($sp)
/* 87A38C 802407AC 46002100 */  add.s     $f4, $f4, $f0
/* 87A390 802407B0 E7A20010 */  swc1      $f2, 0x10($sp)
/* 87A394 802407B4 8C450048 */  lw        $a1, 0x48($v0)
/* 87A398 802407B8 8C470050 */  lw        $a3, 0x50($v0)
/* 87A39C 802407BC 44062000 */  mfc1      $a2, $f4
/* 87A3A0 802407C0 0C01C5D4 */  jal       func_80071750
/* 87A3A4 802407C4 0000202D */   daddu    $a0, $zero, $zero
/* 87A3A8 802407C8 0220202D */  daddu     $a0, $s1, $zero
/* 87A3AC 802407CC 0200282D */  daddu     $a1, $s0, $zero
/* 87A3B0 802407D0 0C0B2026 */  jal       set_variable
/* 87A3B4 802407D4 0040302D */   daddu    $a2, $v0, $zero
/* 87A3B8 802407D8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 87A3BC 802407DC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 87A3C0 802407E0 8FB00018 */  lw        $s0, 0x18($sp)
/* 87A3C4 802407E4 24020002 */  addiu     $v0, $zero, 2
/* 87A3C8 802407E8 03E00008 */  jr        $ra
/* 87A3CC 802407EC 27BD0028 */   addiu    $sp, $sp, 0x28
