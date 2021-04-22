.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1518_7957F8
/* 7957F8 802A1518 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7957FC 802A151C AFB00010 */  sw        $s0, 0x10($sp)
/* 795800 802A1520 0080802D */  daddu     $s0, $a0, $zero
/* 795804 802A1524 10A0000E */  beqz      $a1, .L802A1560
/* 795808 802A1528 AFBF0014 */   sw       $ra, 0x14($sp)
/* 79580C 802A152C 0C04760B */  jal       func_8011D82C
/* 795810 802A1530 24040001 */   addiu    $a0, $zero, 1
/* 795814 802A1534 0000202D */  daddu     $a0, $zero, $zero
/* 795818 802A1538 0080282D */  daddu     $a1, $a0, $zero
/* 79581C 802A153C 0080302D */  daddu     $a2, $a0, $zero
/* 795820 802A1540 0080382D */  daddu     $a3, $a0, $zero
/* 795824 802A1544 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 795828 802A1548 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 79582C 802A154C 24030001 */  addiu     $v1, $zero, 1
/* 795830 802A1550 0C046F97 */  jal       set_background_color_blend
/* 795834 802A1554 A0430000 */   sb       $v1, ($v0)
/* 795838 802A1558 240200C8 */  addiu     $v0, $zero, 0xc8
/* 79583C 802A155C AE020070 */  sw        $v0, 0x70($s0)
.L802A1560:
/* 795840 802A1560 0000202D */  daddu     $a0, $zero, $zero
/* 795844 802A1564 0080282D */  daddu     $a1, $a0, $zero
/* 795848 802A1568 92070073 */  lbu       $a3, 0x73($s0)
/* 79584C 802A156C 0C046F97 */  jal       set_background_color_blend
/* 795850 802A1570 0080302D */   daddu    $a2, $a0, $zero
/* 795854 802A1574 8E020070 */  lw        $v0, 0x70($s0)
/* 795858 802A1578 24420002 */  addiu     $v0, $v0, 2
/* 79585C 802A157C AE020070 */  sw        $v0, 0x70($s0)
/* 795860 802A1580 284200FE */  slti      $v0, $v0, 0xfe
/* 795864 802A1584 14400007 */  bnez      $v0, .L802A15A4
/* 795868 802A1588 0000102D */   daddu    $v0, $zero, $zero
/* 79586C 802A158C 0000202D */  daddu     $a0, $zero, $zero
/* 795870 802A1590 0080282D */  daddu     $a1, $a0, $zero
/* 795874 802A1594 0080302D */  daddu     $a2, $a0, $zero
/* 795878 802A1598 0C046F97 */  jal       set_background_color_blend
/* 79587C 802A159C 240700FE */   addiu    $a3, $zero, 0xfe
/* 795880 802A15A0 24020002 */  addiu     $v0, $zero, 2
.L802A15A4:
/* 795884 802A15A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 795888 802A15A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 79588C 802A15AC 03E00008 */  jr        $ra
/* 795890 802A15B0 27BD0018 */   addiu    $sp, $sp, 0x18
