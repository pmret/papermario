.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802428D0_A1D9D0
/* A1D9D0 802428D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A1D9D4 802428D4 AFB10014 */  sw        $s1, 0x14($sp)
/* A1D9D8 802428D8 0080882D */  daddu     $s1, $a0, $zero
/* A1D9DC 802428DC AFBF0024 */  sw        $ra, 0x24($sp)
/* A1D9E0 802428E0 AFB40020 */  sw        $s4, 0x20($sp)
/* A1D9E4 802428E4 AFB3001C */  sw        $s3, 0x1c($sp)
/* A1D9E8 802428E8 AFB20018 */  sw        $s2, 0x18($sp)
/* A1D9EC 802428EC 10A00033 */  beqz      $a1, .L802429BC
/* A1D9F0 802428F0 AFB00010 */   sw       $s0, 0x10($sp)
/* A1D9F4 802428F4 0C04760B */  jal       func_8011D82C
/* A1D9F8 802428F8 24040001 */   addiu    $a0, $zero, 1
/* A1D9FC 802428FC 0000202D */  daddu     $a0, $zero, $zero
/* A1DA00 80242900 0080282D */  daddu     $a1, $a0, $zero
/* A1DA04 80242904 0080302D */  daddu     $a2, $a0, $zero
/* A1DA08 80242908 0080382D */  daddu     $a3, $a0, $zero
/* A1DA0C 8024290C 0080802D */  daddu     $s0, $a0, $zero
/* A1DA10 80242910 2414FFFC */  addiu     $s4, $zero, -4
/* A1DA14 80242914 24130007 */  addiu     $s3, $zero, 7
/* A1DA18 80242918 3C120080 */  lui       $s2, 0x80
/* A1DA1C 8024291C 3C038015 */  lui       $v1, 0x8015
/* A1DA20 80242920 8C6312F0 */  lw        $v1, 0x12f0($v1)
/* A1DA24 80242924 24020001 */  addiu     $v0, $zero, 1
/* A1DA28 80242928 0C046F97 */  jal       set_background_color_blend
/* A1DA2C 8024292C A0620000 */   sb       $v0, ($v1)
.L80242930:
/* A1DA30 80242930 0C00E2B7 */  jal       get_npc_by_index
/* A1DA34 80242934 0200202D */   daddu    $a0, $s0, $zero
/* A1DA38 80242938 0040202D */  daddu     $a0, $v0, $zero
/* A1DA3C 8024293C 5080000B */  beql      $a0, $zero, .L8024296C
/* A1DA40 80242940 26100001 */   addiu    $s0, $s0, 1
/* A1DA44 80242944 8C820000 */  lw        $v0, ($a0)
/* A1DA48 80242948 50400008 */  beql      $v0, $zero, .L8024296C
/* A1DA4C 8024294C 26100001 */   addiu    $s0, $s0, 1
/* A1DA50 80242950 808300A4 */  lb        $v1, 0xa4($a0)
/* A1DA54 80242954 10740005 */  beq       $v1, $s4, .L8024296C
/* A1DA58 80242958 26100001 */   addiu    $s0, $s0, 1
/* A1DA5C 8024295C 10730003 */  beq       $v1, $s3, .L8024296C
/* A1DA60 80242960 00000000 */   nop      
/* A1DA64 80242964 00521025 */  or        $v0, $v0, $s2
/* A1DA68 80242968 AC820000 */  sw        $v0, ($a0)
.L8024296C:
/* A1DA6C 8024296C 2A020040 */  slti      $v0, $s0, 0x40
/* A1DA70 80242970 1440FFEF */  bnez      $v0, .L80242930
/* A1DA74 80242974 00000000 */   nop      
/* A1DA78 80242978 0000802D */  daddu     $s0, $zero, $zero
/* A1DA7C 8024297C 3C120800 */  lui       $s2, 0x800
.L80242980:
/* A1DA80 80242980 0C04C3D6 */  jal       get_item_entity
/* A1DA84 80242984 0200202D */   daddu    $a0, $s0, $zero
/* A1DA88 80242988 0040182D */  daddu     $v1, $v0, $zero
/* A1DA8C 8024298C 10600007 */  beqz      $v1, .L802429AC
/* A1DA90 80242990 26100001 */   addiu    $s0, $s0, 1
/* A1DA94 80242994 8C640000 */  lw        $a0, ($v1)
/* A1DA98 80242998 30820010 */  andi      $v0, $a0, 0x10
/* A1DA9C 8024299C 10400003 */  beqz      $v0, .L802429AC
/* A1DAA0 802429A0 00000000 */   nop      
/* A1DAA4 802429A4 00921025 */  or        $v0, $a0, $s2
/* A1DAA8 802429A8 AC620000 */  sw        $v0, ($v1)
.L802429AC:
/* A1DAAC 802429AC 2A020100 */  slti      $v0, $s0, 0x100
/* A1DAB0 802429B0 1440FFF3 */  bnez      $v0, .L80242980
/* A1DAB4 802429B4 00000000 */   nop      
/* A1DAB8 802429B8 AE200070 */  sw        $zero, 0x70($s1)
.L802429BC:
/* A1DABC 802429BC 8E220070 */  lw        $v0, 0x70($s1)
/* A1DAC0 802429C0 24420008 */  addiu     $v0, $v0, 8
/* A1DAC4 802429C4 AE220070 */  sw        $v0, 0x70($s1)
/* A1DAC8 802429C8 28420100 */  slti      $v0, $v0, 0x100
/* A1DACC 802429CC 14400003 */  bnez      $v0, .L802429DC
/* A1DAD0 802429D0 0000202D */   daddu    $a0, $zero, $zero
/* A1DAD4 802429D4 240200FF */  addiu     $v0, $zero, 0xff
/* A1DAD8 802429D8 AE220070 */  sw        $v0, 0x70($s1)
.L802429DC:
/* A1DADC 802429DC 0080282D */  daddu     $a1, $a0, $zero
/* A1DAE0 802429E0 92270073 */  lbu       $a3, 0x73($s1)
/* A1DAE4 802429E4 0C046F97 */  jal       set_background_color_blend
/* A1DAE8 802429E8 0080302D */   daddu    $a2, $a0, $zero
/* A1DAEC 802429EC 8E220070 */  lw        $v0, 0x70($s1)
/* A1DAF0 802429F0 8FBF0024 */  lw        $ra, 0x24($sp)
/* A1DAF4 802429F4 8FB40020 */  lw        $s4, 0x20($sp)
/* A1DAF8 802429F8 8FB3001C */  lw        $s3, 0x1c($sp)
/* A1DAFC 802429FC 8FB20018 */  lw        $s2, 0x18($sp)
/* A1DB00 80242A00 8FB10014 */  lw        $s1, 0x14($sp)
/* A1DB04 80242A04 8FB00010 */  lw        $s0, 0x10($sp)
/* A1DB08 80242A08 384200FF */  xori      $v0, $v0, 0xff
/* A1DB0C 80242A0C 2C420001 */  sltiu     $v0, $v0, 1
/* A1DB10 80242A10 00021040 */  sll       $v0, $v0, 1
/* A1DB14 80242A14 03E00008 */  jr        $ra
/* A1DB18 80242A18 27BD0028 */   addiu    $sp, $sp, 0x28
