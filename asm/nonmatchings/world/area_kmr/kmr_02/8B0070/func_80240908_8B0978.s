.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240908_8B0978
/* 8B0978 80240908 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8B097C 8024090C AFB00010 */  sw        $s0, 0x10($sp)
/* 8B0980 80240910 0080802D */  daddu     $s0, $a0, $zero
/* 8B0984 80240914 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8B0988 80240918 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8B098C 8024091C AFB20018 */  sw        $s2, 0x18($sp)
/* 8B0990 80240920 10A00009 */  beqz      $a1, .L80240948
/* 8B0994 80240924 AFB10014 */   sw       $s1, 0x14($sp)
/* 8B0998 80240928 0000202D */  daddu     $a0, $zero, $zero
/* 8B099C 8024092C 0080282D */  daddu     $a1, $a0, $zero
/* 8B09A0 80240930 0080302D */  daddu     $a2, $a0, $zero
/* 8B09A4 80240934 0C046F97 */  jal       set_background_color_blend
/* 8B09A8 80240938 240700FF */   addiu    $a3, $zero, 0xff
/* 8B09AC 8024093C 240200FF */  addiu     $v0, $zero, 0xff
/* 8B09B0 80240940 AE020070 */  sw        $v0, 0x70($s0)
/* 8B09B4 80240944 AE000074 */  sw        $zero, 0x74($s0)
.L80240948:
/* 8B09B8 80240948 8E020070 */  lw        $v0, 0x70($s0)
/* 8B09BC 8024094C 2442FFF8 */  addiu     $v0, $v0, -8
/* 8B09C0 80240950 04410002 */  bgez      $v0, .L8024095C
/* 8B09C4 80240954 AE020070 */   sw       $v0, 0x70($s0)
/* 8B09C8 80240958 AE000070 */  sw        $zero, 0x70($s0)
.L8024095C:
/* 8B09CC 8024095C 0000202D */  daddu     $a0, $zero, $zero
/* 8B09D0 80240960 0080282D */  daddu     $a1, $a0, $zero
/* 8B09D4 80240964 92070073 */  lbu       $a3, 0x73($s0)
/* 8B09D8 80240968 0C046F97 */  jal       set_background_color_blend
/* 8B09DC 8024096C 0080302D */   daddu    $a2, $a0, $zero
/* 8B09E0 80240970 8E020070 */  lw        $v0, 0x70($s0)
/* 8B09E4 80240974 14400006 */  bnez      $v0, .L80240990
/* 8B09E8 80240978 00000000 */   nop      
/* 8B09EC 8024097C 8E020074 */  lw        $v0, 0x74($s0)
/* 8B09F0 80240980 14400003 */  bnez      $v0, .L80240990
/* 8B09F4 80240984 24020001 */   addiu    $v0, $zero, 1
/* 8B09F8 80240988 08090297 */  j         .L80240A5C
/* 8B09FC 8024098C AE020074 */   sw       $v0, 0x74($s0)
.L80240990:
/* 8B0A00 80240990 8E030074 */  lw        $v1, 0x74($s0)
/* 8B0A04 80240994 24020001 */  addiu     $v0, $zero, 1
/* 8B0A08 80240998 14620031 */  bne       $v1, $v0, .L80240A60
/* 8B0A0C 8024099C 0000102D */   daddu    $v0, $zero, $zero
/* 8B0A10 802409A0 0C04760B */  jal       func_8011D82C
/* 8B0A14 802409A4 0000202D */   daddu    $a0, $zero, $zero
/* 8B0A18 802409A8 0000802D */  daddu     $s0, $zero, $zero
/* 8B0A1C 802409AC 2413FFFC */  addiu     $s3, $zero, -4
/* 8B0A20 802409B0 24120008 */  addiu     $s2, $zero, 8
/* 8B0A24 802409B4 3C11FF7F */  lui       $s1, 0xff7f
/* 8B0A28 802409B8 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 8B0A2C 802409BC 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 8B0A30 802409C0 3631FFFF */  ori       $s1, $s1, 0xffff
/* 8B0A34 802409C4 A0400000 */  sb        $zero, ($v0)
.L802409C8:
/* 8B0A38 802409C8 0C00E2B7 */  jal       get_npc_by_index
/* 8B0A3C 802409CC 0200202D */   daddu    $a0, $s0, $zero
/* 8B0A40 802409D0 0040202D */  daddu     $a0, $v0, $zero
/* 8B0A44 802409D4 5080000B */  beql      $a0, $zero, .L80240A04
/* 8B0A48 802409D8 26100001 */   addiu    $s0, $s0, 1
/* 8B0A4C 802409DC 8C820000 */  lw        $v0, ($a0)
/* 8B0A50 802409E0 50400008 */  beql      $v0, $zero, .L80240A04
/* 8B0A54 802409E4 26100001 */   addiu    $s0, $s0, 1
/* 8B0A58 802409E8 808300A4 */  lb        $v1, 0xa4($a0)
/* 8B0A5C 802409EC 10730005 */  beq       $v1, $s3, .L80240A04
/* 8B0A60 802409F0 26100001 */   addiu    $s0, $s0, 1
/* 8B0A64 802409F4 10720003 */  beq       $v1, $s2, .L80240A04
/* 8B0A68 802409F8 00000000 */   nop      
/* 8B0A6C 802409FC 00511024 */  and       $v0, $v0, $s1
/* 8B0A70 80240A00 AC820000 */  sw        $v0, ($a0)
.L80240A04:
/* 8B0A74 80240A04 2A020040 */  slti      $v0, $s0, 0x40
/* 8B0A78 80240A08 1440FFEF */  bnez      $v0, .L802409C8
/* 8B0A7C 80240A0C 00000000 */   nop      
/* 8B0A80 80240A10 0000802D */  daddu     $s0, $zero, $zero
/* 8B0A84 80240A14 3C11F7FF */  lui       $s1, 0xf7ff
/* 8B0A88 80240A18 3631FFFF */  ori       $s1, $s1, 0xffff
.L80240A1C:
/* 8B0A8C 80240A1C 0C04C3D6 */  jal       get_item_entity
/* 8B0A90 80240A20 0200202D */   daddu    $a0, $s0, $zero
/* 8B0A94 80240A24 0040182D */  daddu     $v1, $v0, $zero
/* 8B0A98 80240A28 10600007 */  beqz      $v1, .L80240A48
/* 8B0A9C 80240A2C 26100001 */   addiu    $s0, $s0, 1
/* 8B0AA0 80240A30 8C640000 */  lw        $a0, ($v1)
/* 8B0AA4 80240A34 30820010 */  andi      $v0, $a0, 0x10
/* 8B0AA8 80240A38 10400003 */  beqz      $v0, .L80240A48
/* 8B0AAC 80240A3C 00000000 */   nop      
/* 8B0AB0 80240A40 00911024 */  and       $v0, $a0, $s1
/* 8B0AB4 80240A44 AC620000 */  sw        $v0, ($v1)
.L80240A48:
/* 8B0AB8 80240A48 2A020100 */  slti      $v0, $s0, 0x100
/* 8B0ABC 80240A4C 1440FFF3 */  bnez      $v0, .L80240A1C
/* 8B0AC0 80240A50 24020002 */   addiu    $v0, $zero, 2
/* 8B0AC4 80240A54 08090298 */  j         .L80240A60
/* 8B0AC8 80240A58 00000000 */   nop      
.L80240A5C:
/* 8B0ACC 80240A5C 0000102D */  daddu     $v0, $zero, $zero
.L80240A60:
/* 8B0AD0 80240A60 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8B0AD4 80240A64 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8B0AD8 80240A68 8FB20018 */  lw        $s2, 0x18($sp)
/* 8B0ADC 80240A6C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B0AE0 80240A70 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B0AE4 80240A74 03E00008 */  jr        $ra
/* 8B0AE8 80240A78 27BD0028 */   addiu    $sp, $sp, 0x28
