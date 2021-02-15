.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415CC_96A78C
/* 96A78C 802415CC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 96A790 802415D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 96A794 802415D4 0080802D */  daddu     $s0, $a0, $zero
/* 96A798 802415D8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 96A79C 802415DC AFB3001C */  sw        $s3, 0x1c($sp)
/* 96A7A0 802415E0 AFB20018 */  sw        $s2, 0x18($sp)
/* 96A7A4 802415E4 10A00009 */  beqz      $a1, .L8024160C
/* 96A7A8 802415E8 AFB10014 */   sw       $s1, 0x14($sp)
/* 96A7AC 802415EC 0000202D */  daddu     $a0, $zero, $zero
/* 96A7B0 802415F0 0080282D */  daddu     $a1, $a0, $zero
/* 96A7B4 802415F4 0080302D */  daddu     $a2, $a0, $zero
/* 96A7B8 802415F8 0C046F97 */  jal       set_background_color_blend
/* 96A7BC 802415FC 240700FF */   addiu    $a3, $zero, 0xff
/* 96A7C0 80241600 240200FF */  addiu     $v0, $zero, 0xff
/* 96A7C4 80241604 AE020070 */  sw        $v0, 0x70($s0)
/* 96A7C8 80241608 AE000074 */  sw        $zero, 0x74($s0)
.L8024160C:
/* 96A7CC 8024160C 8E020070 */  lw        $v0, 0x70($s0)
/* 96A7D0 80241610 2442FFF8 */  addiu     $v0, $v0, -8
/* 96A7D4 80241614 04410002 */  bgez      $v0, .L80241620
/* 96A7D8 80241618 AE020070 */   sw       $v0, 0x70($s0)
/* 96A7DC 8024161C AE000070 */  sw        $zero, 0x70($s0)
.L80241620:
/* 96A7E0 80241620 0000202D */  daddu     $a0, $zero, $zero
/* 96A7E4 80241624 0080282D */  daddu     $a1, $a0, $zero
/* 96A7E8 80241628 92070073 */  lbu       $a3, 0x73($s0)
/* 96A7EC 8024162C 0C046F97 */  jal       set_background_color_blend
/* 96A7F0 80241630 0080302D */   daddu    $a2, $a0, $zero
/* 96A7F4 80241634 8E020070 */  lw        $v0, 0x70($s0)
/* 96A7F8 80241638 14400006 */  bnez      $v0, .L80241654
/* 96A7FC 8024163C 00000000 */   nop
/* 96A800 80241640 8E020074 */  lw        $v0, 0x74($s0)
/* 96A804 80241644 14400003 */  bnez      $v0, .L80241654
/* 96A808 80241648 24020001 */   addiu    $v0, $zero, 1
/* 96A80C 8024164C 080905B7 */  j         .L802416DC
/* 96A810 80241650 AE020074 */   sw       $v0, 0x74($s0)
.L80241654:
/* 96A814 80241654 8E030074 */  lw        $v1, 0x74($s0)
/* 96A818 80241658 24020001 */  addiu     $v0, $zero, 1
/* 96A81C 8024165C 14620020 */  bne       $v1, $v0, .L802416E0
/* 96A820 80241660 0000102D */   daddu    $v0, $zero, $zero
/* 96A824 80241664 0C04760B */  jal       func_8011D82C
/* 96A828 80241668 0000202D */   daddu    $a0, $zero, $zero
/* 96A82C 8024166C 0000802D */  daddu     $s0, $zero, $zero
/* 96A830 80241670 2413FFFC */  addiu     $s3, $zero, -4
/* 96A834 80241674 24120004 */  addiu     $s2, $zero, 4
/* 96A838 80241678 3C11FF7F */  lui       $s1, 0xff7f
/* 96A83C 8024167C 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 96A840 80241680 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 96A844 80241684 3631FFFF */  ori       $s1, $s1, 0xffff
/* 96A848 80241688 A0400000 */  sb        $zero, ($v0)
.L8024168C:
/* 96A84C 8024168C 0C00E2B7 */  jal       get_npc_by_index
/* 96A850 80241690 0200202D */   daddu    $a0, $s0, $zero
/* 96A854 80241694 0040202D */  daddu     $a0, $v0, $zero
/* 96A858 80241698 5080000B */  beql      $a0, $zero, .L802416C8
/* 96A85C 8024169C 26100001 */   addiu    $s0, $s0, 1
/* 96A860 802416A0 8C820000 */  lw        $v0, ($a0)
/* 96A864 802416A4 50400008 */  beql      $v0, $zero, .L802416C8
/* 96A868 802416A8 26100001 */   addiu    $s0, $s0, 1
/* 96A86C 802416AC 808300A4 */  lb        $v1, 0xa4($a0)
/* 96A870 802416B0 10730005 */  beq       $v1, $s3, .L802416C8
/* 96A874 802416B4 26100001 */   addiu    $s0, $s0, 1
/* 96A878 802416B8 10720003 */  beq       $v1, $s2, .L802416C8
/* 96A87C 802416BC 00000000 */   nop
/* 96A880 802416C0 00511024 */  and       $v0, $v0, $s1
/* 96A884 802416C4 AC820000 */  sw        $v0, ($a0)
.L802416C8:
/* 96A888 802416C8 2A020040 */  slti      $v0, $s0, 0x40
/* 96A88C 802416CC 1440FFEF */  bnez      $v0, .L8024168C
/* 96A890 802416D0 24020002 */   addiu    $v0, $zero, 2
/* 96A894 802416D4 080905B8 */  j         .L802416E0
/* 96A898 802416D8 00000000 */   nop
.L802416DC:
/* 96A89C 802416DC 0000102D */  daddu     $v0, $zero, $zero
.L802416E0:
/* 96A8A0 802416E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 96A8A4 802416E4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 96A8A8 802416E8 8FB20018 */  lw        $s2, 0x18($sp)
/* 96A8AC 802416EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 96A8B0 802416F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 96A8B4 802416F4 03E00008 */  jr        $ra
/* 96A8B8 802416F8 27BD0028 */   addiu    $sp, $sp, 0x28
