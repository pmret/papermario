.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414C0
/* 96A680 802414C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 96A684 802414C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 96A688 802414C8 0080882D */  daddu     $s1, $a0, $zero
/* 96A68C 802414CC AFBF0024 */  sw        $ra, 0x24($sp)
/* 96A690 802414D0 AFB40020 */  sw        $s4, 0x20($sp)
/* 96A694 802414D4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 96A698 802414D8 AFB20018 */  sw        $s2, 0x18($sp)
/* 96A69C 802414DC 10A00023 */  beqz      $a1, .L8024156C
/* 96A6A0 802414E0 AFB00010 */   sw       $s0, 0x10($sp)
/* 96A6A4 802414E4 0C04760B */  jal       func_8011D82C
/* 96A6A8 802414E8 24040001 */   addiu    $a0, $zero, 1
/* 96A6AC 802414EC 0000202D */  daddu     $a0, $zero, $zero
/* 96A6B0 802414F0 0080282D */  daddu     $a1, $a0, $zero
/* 96A6B4 802414F4 0080302D */  daddu     $a2, $a0, $zero
/* 96A6B8 802414F8 0080382D */  daddu     $a3, $a0, $zero
/* 96A6BC 802414FC 0080802D */  daddu     $s0, $a0, $zero
/* 96A6C0 80241500 2414FFFC */  addiu     $s4, $zero, -4
/* 96A6C4 80241504 24130004 */  addiu     $s3, $zero, 4
/* 96A6C8 80241508 3C120080 */  lui       $s2, 0x80
/* 96A6CC 8024150C 3C038015 */  lui       $v1, 0x8015
/* 96A6D0 80241510 8C6312F0 */  lw        $v1, 0x12f0($v1)
/* 96A6D4 80241514 24020001 */  addiu     $v0, $zero, 1
/* 96A6D8 80241518 0C046F97 */  jal       set_background_color_blend
/* 96A6DC 8024151C A0620000 */   sb       $v0, ($v1)
.L80241520:
/* 96A6E0 80241520 0C00E2B7 */  jal       get_npc_by_index
/* 96A6E4 80241524 0200202D */   daddu    $a0, $s0, $zero
/* 96A6E8 80241528 0040202D */  daddu     $a0, $v0, $zero
/* 96A6EC 8024152C 5080000B */  beql      $a0, $zero, .L8024155C
/* 96A6F0 80241530 26100001 */   addiu    $s0, $s0, 1
/* 96A6F4 80241534 8C820000 */  lw        $v0, ($a0)
/* 96A6F8 80241538 50400008 */  beql      $v0, $zero, .L8024155C
/* 96A6FC 8024153C 26100001 */   addiu    $s0, $s0, 1
/* 96A700 80241540 808300A4 */  lb        $v1, 0xa4($a0)
/* 96A704 80241544 10740005 */  beq       $v1, $s4, .L8024155C
/* 96A708 80241548 26100001 */   addiu    $s0, $s0, 1
/* 96A70C 8024154C 10730003 */  beq       $v1, $s3, .L8024155C
/* 96A710 80241550 00000000 */   nop      
/* 96A714 80241554 00521025 */  or        $v0, $v0, $s2
/* 96A718 80241558 AC820000 */  sw        $v0, ($a0)
.L8024155C:
/* 96A71C 8024155C 2A020040 */  slti      $v0, $s0, 0x40
/* 96A720 80241560 1440FFEF */  bnez      $v0, .L80241520
/* 96A724 80241564 00000000 */   nop      
/* 96A728 80241568 AE200070 */  sw        $zero, 0x70($s1)
.L8024156C:
/* 96A72C 8024156C 8E220070 */  lw        $v0, 0x70($s1)
/* 96A730 80241570 24420008 */  addiu     $v0, $v0, 8
/* 96A734 80241574 AE220070 */  sw        $v0, 0x70($s1)
/* 96A738 80241578 28420100 */  slti      $v0, $v0, 0x100
/* 96A73C 8024157C 14400003 */  bnez      $v0, .L8024158C
/* 96A740 80241580 0000202D */   daddu    $a0, $zero, $zero
/* 96A744 80241584 240200FF */  addiu     $v0, $zero, 0xff
/* 96A748 80241588 AE220070 */  sw        $v0, 0x70($s1)
.L8024158C:
/* 96A74C 8024158C 0080282D */  daddu     $a1, $a0, $zero
/* 96A750 80241590 92270073 */  lbu       $a3, 0x73($s1)
/* 96A754 80241594 0C046F97 */  jal       set_background_color_blend
/* 96A758 80241598 0080302D */   daddu    $a2, $a0, $zero
/* 96A75C 8024159C 8E220070 */  lw        $v0, 0x70($s1)
/* 96A760 802415A0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 96A764 802415A4 8FB40020 */  lw        $s4, 0x20($sp)
/* 96A768 802415A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 96A76C 802415AC 8FB20018 */  lw        $s2, 0x18($sp)
/* 96A770 802415B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 96A774 802415B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 96A778 802415B8 384200FF */  xori      $v0, $v0, 0xff
/* 96A77C 802415BC 2C420001 */  sltiu     $v0, $v0, 1
/* 96A780 802415C0 00021040 */  sll       $v0, $v0, 1
/* 96A784 802415C4 03E00008 */  jr        $ra
/* 96A788 802415C8 27BD0028 */   addiu    $sp, $sp, 0x28
