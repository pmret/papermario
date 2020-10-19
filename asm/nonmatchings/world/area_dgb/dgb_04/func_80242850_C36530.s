.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242850_C38D80
/* C38D80 80242850 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C38D84 80242854 AFB1001C */  sw        $s1, 0x1c($sp)
/* C38D88 80242858 0080882D */  daddu     $s1, $a0, $zero
/* C38D8C 8024285C AFBF0020 */  sw        $ra, 0x20($sp)
/* C38D90 80242860 AFB00018 */  sw        $s0, 0x18($sp)
/* C38D94 80242864 8E30000C */  lw        $s0, 0xc($s1)
/* C38D98 80242868 8E050000 */  lw        $a1, ($s0)
/* C38D9C 8024286C 0C0B1EAF */  jal       get_variable
/* C38DA0 80242870 26100004 */   addiu    $s0, $s0, 4
/* C38DA4 80242874 0C04417A */  jal       get_entity_by_index
/* C38DA8 80242878 0040202D */   daddu    $a0, $v0, $zero
/* C38DAC 8024287C 8E100000 */  lw        $s0, ($s0)
/* C38DB0 80242880 C444004C */  lwc1      $f4, 0x4c($v0)
/* C38DB4 80242884 3C014148 */  lui       $at, 0x4148
/* C38DB8 80242888 44810000 */  mtc1      $at, $f0
/* C38DBC 8024288C 3C013F33 */  lui       $at, 0x3f33
/* C38DC0 80242890 34213333 */  ori       $at, $at, 0x3333
/* C38DC4 80242894 44811000 */  mtc1      $at, $f2
/* C38DC8 80242898 AFA00014 */  sw        $zero, 0x14($sp)
/* C38DCC 8024289C 46002100 */  add.s     $f4, $f4, $f0
/* C38DD0 802428A0 E7A20010 */  swc1      $f2, 0x10($sp)
/* C38DD4 802428A4 8C450048 */  lw        $a1, 0x48($v0)
/* C38DD8 802428A8 8C470050 */  lw        $a3, 0x50($v0)
/* C38DDC 802428AC 44062000 */  mfc1      $a2, $f4
/* C38DE0 802428B0 0C01C5D4 */  jal       func_80071750
/* C38DE4 802428B4 0000202D */   daddu    $a0, $zero, $zero
/* C38DE8 802428B8 0220202D */  daddu     $a0, $s1, $zero
/* C38DEC 802428BC 0200282D */  daddu     $a1, $s0, $zero
/* C38DF0 802428C0 0C0B2026 */  jal       set_variable
/* C38DF4 802428C4 0040302D */   daddu    $a2, $v0, $zero
/* C38DF8 802428C8 8FBF0020 */  lw        $ra, 0x20($sp)
/* C38DFC 802428CC 8FB1001C */  lw        $s1, 0x1c($sp)
/* C38E00 802428D0 8FB00018 */  lw        $s0, 0x18($sp)
/* C38E04 802428D4 24020002 */  addiu     $v0, $zero, 2
/* C38E08 802428D8 03E00008 */  jr        $ra
/* C38E0C 802428DC 27BD0028 */   addiu    $sp, $sp, 0x28
