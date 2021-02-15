.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415AC_95C7AC
/* 95C7AC 802415AC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 95C7B0 802415B0 AFB10024 */  sw        $s1, 0x24($sp)
/* 95C7B4 802415B4 0080882D */  daddu     $s1, $a0, $zero
/* 95C7B8 802415B8 3C05F840 */  lui       $a1, 0xf840
/* 95C7BC 802415BC AFBF0044 */  sw        $ra, 0x44($sp)
/* 95C7C0 802415C0 AFBE0040 */  sw        $fp, 0x40($sp)
/* 95C7C4 802415C4 AFB7003C */  sw        $s7, 0x3c($sp)
/* 95C7C8 802415C8 AFB60038 */  sw        $s6, 0x38($sp)
/* 95C7CC 802415CC AFB50034 */  sw        $s5, 0x34($sp)
/* 95C7D0 802415D0 AFB40030 */  sw        $s4, 0x30($sp)
/* 95C7D4 802415D4 AFB3002C */  sw        $s3, 0x2c($sp)
/* 95C7D8 802415D8 AFB20028 */  sw        $s2, 0x28($sp)
/* 95C7DC 802415DC AFB00020 */  sw        $s0, 0x20($sp)
/* 95C7E0 802415E0 8E3E0148 */  lw        $fp, 0x148($s1)
/* 95C7E4 802415E4 0C0B1EAF */  jal       get_variable
/* 95C7E8 802415E8 34A56268 */   ori      $a1, $a1, 0x6268
/* 95C7EC 802415EC 0040802D */  daddu     $s0, $v0, $zero
/* 95C7F0 802415F0 0220202D */  daddu     $a0, $s1, $zero
/* 95C7F4 802415F4 3C05F840 */  lui       $a1, 0xf840
/* 95C7F8 802415F8 0C0B1EAF */  jal       get_variable
/* 95C7FC 802415FC 34A56269 */   ori      $a1, $a1, 0x6269
/* 95C800 80241600 0040B82D */  daddu     $s7, $v0, $zero
/* 95C804 80241604 0220202D */  daddu     $a0, $s1, $zero
/* 95C808 80241608 3C05F5DE */  lui       $a1, 0xf5de
/* 95C80C 8024160C 0C0B1EAF */  jal       get_variable
/* 95C810 80241610 34A502DE */   ori      $a1, $a1, 0x2de
/* 95C814 80241614 0040B02D */  daddu     $s6, $v0, $zero
/* 95C818 80241618 0220202D */  daddu     $a0, $s1, $zero
/* 95C81C 8024161C 3C05F5DE */  lui       $a1, 0xf5de
/* 95C820 80241620 0C0B1EAF */  jal       get_variable
/* 95C824 80241624 34A502DF */   ori      $a1, $a1, 0x2df
/* 95C828 80241628 0040A82D */  daddu     $s5, $v0, $zero
/* 95C82C 8024162C 93D3006D */  lbu       $s3, 0x6d($fp)
/* 95C830 80241630 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 95C834 80241634 A7B30010 */  sh        $s3, 0x10($sp)
/* 95C838 80241638 93D2006E */  lbu       $s2, 0x6e($fp)
/* 95C83C 8024163C 93C7006F */  lbu       $a3, 0x6f($fp)
/* 95C840 80241640 3274FFFF */  andi      $s4, $s3, 0xffff
/* 95C844 80241644 12820003 */  beq       $s4, $v0, .L80241654
/* 95C848 80241648 A7A7001E */   sh       $a3, 0x1e($sp)
/* 95C84C 8024164C 0000B82D */  daddu     $s7, $zero, $zero
/* 95C850 80241650 02E0802D */  daddu     $s0, $s7, $zero
.L80241654:
/* 95C854 80241654 3202FFFF */  andi      $v0, $s0, 0xffff
/* 95C858 80241658 14400016 */  bnez      $v0, .L802416B4
/* 95C85C 8024165C 0220202D */   daddu    $a0, $s1, $zero
/* 95C860 80241660 0C00A67F */  jal       rand_int
/* 95C864 80241664 24040064 */   addiu    $a0, $zero, 0x64
/* 95C868 80241668 2842001E */  slti      $v0, $v0, 0x1e
/* 95C86C 8024166C 10400011 */  beqz      $v0, .L802416B4
/* 95C870 80241670 0220202D */   daddu    $a0, $s1, $zero
/* 95C874 80241674 0C00A67F */  jal       rand_int
/* 95C878 80241678 2644FFFF */   addiu    $a0, $s2, -1
/* 95C87C 8024167C 0040A82D */  daddu     $s5, $v0, $zero
/* 95C880 80241680 0260B02D */  daddu     $s6, $s3, $zero
/* 95C884 80241684 0220202D */  daddu     $a0, $s1, $zero
/* 95C888 80241688 3C05F5DE */  lui       $a1, 0xf5de
/* 95C88C 8024168C 34A502DE */  ori       $a1, $a1, 0x2de
/* 95C890 80241690 0C0B2026 */  jal       set_variable
/* 95C894 80241694 0280302D */   daddu    $a2, $s4, $zero
/* 95C898 80241698 0220202D */  daddu     $a0, $s1, $zero
/* 95C89C 8024169C 3C05F5DE */  lui       $a1, 0xf5de
/* 95C8A0 802416A0 34A502DF */  ori       $a1, $a1, 0x2df
/* 95C8A4 802416A4 0C0B2026 */  jal       set_variable
/* 95C8A8 802416A8 32A6FFFF */   andi     $a2, $s5, 0xffff
/* 95C8AC 802416AC 24100001 */  addiu     $s0, $zero, 1
/* 95C8B0 802416B0 0220202D */  daddu     $a0, $s1, $zero
.L802416B4:
/* 95C8B4 802416B4 3C05F840 */  lui       $a1, 0xf840
/* 95C8B8 802416B8 34A56268 */  ori       $a1, $a1, 0x6268
/* 95C8BC 802416BC 0C0B2026 */  jal       set_variable
/* 95C8C0 802416C0 3206FFFF */   andi     $a2, $s0, 0xffff
/* 95C8C4 802416C4 0220202D */  daddu     $a0, $s1, $zero
/* 95C8C8 802416C8 3C05F840 */  lui       $a1, 0xf840
/* 95C8CC 802416CC 34A56269 */  ori       $a1, $a1, 0x6269
/* 95C8D0 802416D0 0C0B2026 */  jal       set_variable
/* 95C8D4 802416D4 32E6FFFF */   andi     $a2, $s7, 0xffff
/* 95C8D8 802416D8 0000202D */  daddu     $a0, $zero, $zero
/* 95C8DC 802416DC 3C05F5DE */  lui       $a1, 0xf5de
/* 95C8E0 802416E0 0C0B1EAF */  jal       get_variable
/* 95C8E4 802416E4 34A502E0 */   ori      $a1, $a1, 0x2e0
/* 95C8E8 802416E8 0000202D */  daddu     $a0, $zero, $zero
/* 95C8EC 802416EC 3C05F5DE */  lui       $a1, 0xf5de
/* 95C8F0 802416F0 34A50180 */  ori       $a1, $a1, 0x180
/* 95C8F4 802416F4 0C0B1EAF */  jal       get_variable
/* 95C8F8 802416F8 0040802D */   daddu    $s0, $v0, $zero
/* 95C8FC 802416FC 0040282D */  daddu     $a1, $v0, $zero
/* 95C900 80241700 0000182D */  daddu     $v1, $zero, $zero
/* 95C904 80241704 3C068024 */  lui       $a2, %hi(D_8024525C_96045C)
/* 95C908 80241708 24C6525C */  addiu     $a2, $a2, %lo(D_8024525C_96045C)
/* 95C90C 8024170C 00C0202D */  daddu     $a0, $a2, $zero
.L80241710:
/* 95C910 80241710 8C820000 */  lw        $v0, ($a0)
/* 95C914 80241714 00A2102A */  slt       $v0, $a1, $v0
/* 95C918 80241718 14400006 */  bnez      $v0, .L80241734
/* 95C91C 8024171C 000310C0 */   sll      $v0, $v1, 3
/* 95C920 80241720 24630001 */  addiu     $v1, $v1, 1
/* 95C924 80241724 28620008 */  slti      $v0, $v1, 8
/* 95C928 80241728 1440FFF9 */  bnez      $v0, .L80241710
/* 95C92C 8024172C 24840008 */   addiu    $a0, $a0, 8
/* 95C930 80241730 000310C0 */  sll       $v0, $v1, 3
.L80241734:
/* 95C934 80241734 00461021 */  addu      $v0, $v0, $a2
/* 95C938 80241738 8C420004 */  lw        $v0, 4($v0)
/* 95C93C 8024173C 97A30010 */  lhu       $v1, 0x10($sp)
/* 95C940 80241740 0202202A */  slt       $a0, $s0, $v0
/* 95C944 80241744 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 95C948 80241748 14620008 */  bne       $v1, $v0, .L8024176C
/* 95C94C 8024174C 32A2FFFF */   andi     $v0, $s5, 0xffff
/* 95C950 80241750 97A7001E */  lhu       $a3, 0x1e($sp)
/* 95C954 80241754 14E20005 */  bne       $a3, $v0, .L8024176C
/* 95C958 80241758 32E2FFFF */   andi     $v0, $s7, 0xffff
/* 95C95C 8024175C 14400003 */  bnez      $v0, .L8024176C
/* 95C960 80241760 00000000 */   nop
/* 95C964 80241764 14800008 */  bnez      $a0, .L80241788
/* 95C968 80241768 24020001 */   addiu    $v0, $zero, 1
.L8024176C:
/* 95C96C 8024176C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 95C970 80241770 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 95C974 80241774 80420075 */  lb        $v0, 0x75($v0)
/* 95C978 80241778 10400005 */  beqz      $v0, .L80241790
/* 95C97C 8024177C 00000000 */   nop
/* 95C980 80241780 10800003 */  beqz      $a0, .L80241790
/* 95C984 80241784 24020001 */   addiu    $v0, $zero, 1
.L80241788:
/* 95C988 80241788 080905E7 */  j         .L8024179C
/* 95C98C 8024178C AE220084 */   sw       $v0, 0x84($s1)
.L80241790:
/* 95C990 80241790 0C00F9EB */  jal       kill_enemy
/* 95C994 80241794 03C0202D */   daddu    $a0, $fp, $zero
/* 95C998 80241798 AE200084 */  sw        $zero, 0x84($s1)
.L8024179C:
/* 95C99C 8024179C 8FBF0044 */  lw        $ra, 0x44($sp)
/* 95C9A0 802417A0 8FBE0040 */  lw        $fp, 0x40($sp)
/* 95C9A4 802417A4 8FB7003C */  lw        $s7, 0x3c($sp)
/* 95C9A8 802417A8 8FB60038 */  lw        $s6, 0x38($sp)
/* 95C9AC 802417AC 8FB50034 */  lw        $s5, 0x34($sp)
/* 95C9B0 802417B0 8FB40030 */  lw        $s4, 0x30($sp)
/* 95C9B4 802417B4 8FB3002C */  lw        $s3, 0x2c($sp)
/* 95C9B8 802417B8 8FB20028 */  lw        $s2, 0x28($sp)
/* 95C9BC 802417BC 8FB10024 */  lw        $s1, 0x24($sp)
/* 95C9C0 802417C0 8FB00020 */  lw        $s0, 0x20($sp)
/* 95C9C4 802417C4 24020002 */  addiu     $v0, $zero, 2
/* 95C9C8 802417C8 03E00008 */  jr        $ra
/* 95C9CC 802417CC 27BD0048 */   addiu    $sp, $sp, 0x48
