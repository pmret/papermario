.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A5C
/* 7EB76C 80240A5C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7EB770 80240A60 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EB774 80240A64 0080882D */  daddu     $s1, $a0, $zero
/* 7EB778 80240A68 AFBF0024 */  sw        $ra, 0x24($sp)
/* 7EB77C 80240A6C AFB40020 */  sw        $s4, 0x20($sp)
/* 7EB780 80240A70 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7EB784 80240A74 AFB20018 */  sw        $s2, 0x18($sp)
/* 7EB788 80240A78 10A00033 */  beqz      $a1, .L80240B48
/* 7EB78C 80240A7C AFB00010 */   sw       $s0, 0x10($sp)
/* 7EB790 80240A80 0C04760B */  jal       func_8011D82C
/* 7EB794 80240A84 24040001 */   addiu    $a0, $zero, 1
/* 7EB798 80240A88 0000202D */  daddu     $a0, $zero, $zero
/* 7EB79C 80240A8C 0080282D */  daddu     $a1, $a0, $zero
/* 7EB7A0 80240A90 0080302D */  daddu     $a2, $a0, $zero
/* 7EB7A4 80240A94 0080382D */  daddu     $a3, $a0, $zero
/* 7EB7A8 80240A98 0080802D */  daddu     $s0, $a0, $zero
/* 7EB7AC 80240A9C 2414FFFC */  addiu     $s4, $zero, -4
/* 7EB7B0 80240AA0 24130006 */  addiu     $s3, $zero, 6
/* 7EB7B4 80240AA4 3C120080 */  lui       $s2, 0x80
/* 7EB7B8 80240AA8 3C038015 */  lui       $v1, 0x8015
/* 7EB7BC 80240AAC 8C6312F0 */  lw        $v1, 0x12f0($v1)
/* 7EB7C0 80240AB0 24020001 */  addiu     $v0, $zero, 1
/* 7EB7C4 80240AB4 0C046F97 */  jal       set_background_color_blend
/* 7EB7C8 80240AB8 A0620000 */   sb       $v0, ($v1)
.L80240ABC:
/* 7EB7CC 80240ABC 0C00E2B7 */  jal       get_npc_by_index
/* 7EB7D0 80240AC0 0200202D */   daddu    $a0, $s0, $zero
/* 7EB7D4 80240AC4 0040202D */  daddu     $a0, $v0, $zero
/* 7EB7D8 80240AC8 5080000B */  beql      $a0, $zero, .L80240AF8
/* 7EB7DC 80240ACC 26100001 */   addiu    $s0, $s0, 1
/* 7EB7E0 80240AD0 8C820000 */  lw        $v0, ($a0)
/* 7EB7E4 80240AD4 50400008 */  beql      $v0, $zero, .L80240AF8
/* 7EB7E8 80240AD8 26100001 */   addiu    $s0, $s0, 1
/* 7EB7EC 80240ADC 808300A4 */  lb        $v1, 0xa4($a0)
/* 7EB7F0 80240AE0 10740005 */  beq       $v1, $s4, .L80240AF8
/* 7EB7F4 80240AE4 26100001 */   addiu    $s0, $s0, 1
/* 7EB7F8 80240AE8 10730003 */  beq       $v1, $s3, .L80240AF8
/* 7EB7FC 80240AEC 00000000 */   nop      
/* 7EB800 80240AF0 00521025 */  or        $v0, $v0, $s2
/* 7EB804 80240AF4 AC820000 */  sw        $v0, ($a0)
.L80240AF8:
/* 7EB808 80240AF8 2A020040 */  slti      $v0, $s0, 0x40
/* 7EB80C 80240AFC 1440FFEF */  bnez      $v0, .L80240ABC
/* 7EB810 80240B00 00000000 */   nop      
/* 7EB814 80240B04 0000802D */  daddu     $s0, $zero, $zero
/* 7EB818 80240B08 3C120800 */  lui       $s2, 0x800
.L80240B0C:
/* 7EB81C 80240B0C 0C04C3D6 */  jal       get_item_entity
/* 7EB820 80240B10 0200202D */   daddu    $a0, $s0, $zero
/* 7EB824 80240B14 0040182D */  daddu     $v1, $v0, $zero
/* 7EB828 80240B18 10600007 */  beqz      $v1, .L80240B38
/* 7EB82C 80240B1C 26100001 */   addiu    $s0, $s0, 1
/* 7EB830 80240B20 8C640000 */  lw        $a0, ($v1)
/* 7EB834 80240B24 30820010 */  andi      $v0, $a0, 0x10
/* 7EB838 80240B28 10400003 */  beqz      $v0, .L80240B38
/* 7EB83C 80240B2C 00000000 */   nop      
/* 7EB840 80240B30 00921025 */  or        $v0, $a0, $s2
/* 7EB844 80240B34 AC620000 */  sw        $v0, ($v1)
.L80240B38:
/* 7EB848 80240B38 2A020100 */  slti      $v0, $s0, 0x100
/* 7EB84C 80240B3C 1440FFF3 */  bnez      $v0, .L80240B0C
/* 7EB850 80240B40 00000000 */   nop      
/* 7EB854 80240B44 AE200070 */  sw        $zero, 0x70($s1)
.L80240B48:
/* 7EB858 80240B48 8E220070 */  lw        $v0, 0x70($s1)
/* 7EB85C 80240B4C 24420008 */  addiu     $v0, $v0, 8
/* 7EB860 80240B50 AE220070 */  sw        $v0, 0x70($s1)
/* 7EB864 80240B54 28420100 */  slti      $v0, $v0, 0x100
/* 7EB868 80240B58 14400003 */  bnez      $v0, .L80240B68
/* 7EB86C 80240B5C 0000202D */   daddu    $a0, $zero, $zero
/* 7EB870 80240B60 240200FF */  addiu     $v0, $zero, 0xff
/* 7EB874 80240B64 AE220070 */  sw        $v0, 0x70($s1)
.L80240B68:
/* 7EB878 80240B68 0080282D */  daddu     $a1, $a0, $zero
/* 7EB87C 80240B6C 92270073 */  lbu       $a3, 0x73($s1)
/* 7EB880 80240B70 0C046F97 */  jal       set_background_color_blend
/* 7EB884 80240B74 0080302D */   daddu    $a2, $a0, $zero
/* 7EB888 80240B78 8E220070 */  lw        $v0, 0x70($s1)
/* 7EB88C 80240B7C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7EB890 80240B80 8FB40020 */  lw        $s4, 0x20($sp)
/* 7EB894 80240B84 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7EB898 80240B88 8FB20018 */  lw        $s2, 0x18($sp)
/* 7EB89C 80240B8C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EB8A0 80240B90 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EB8A4 80240B94 384200FF */  xori      $v0, $v0, 0xff
/* 7EB8A8 80240B98 2C420001 */  sltiu     $v0, $v0, 1
/* 7EB8AC 80240B9C 00021040 */  sll       $v0, $v0, 1
/* 7EB8B0 80240BA0 03E00008 */  jr        $ra
/* 7EB8B4 80240BA4 27BD0028 */   addiu    $sp, $sp, 0x28
