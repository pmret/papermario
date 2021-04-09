.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel hos_03_UnkFunc29
/* A1DB1C 80242A1C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A1DB20 80242A20 AFB00010 */  sw        $s0, 0x10($sp)
/* A1DB24 80242A24 0080802D */  daddu     $s0, $a0, $zero
/* A1DB28 80242A28 AFBF0020 */  sw        $ra, 0x20($sp)
/* A1DB2C 80242A2C AFB3001C */  sw        $s3, 0x1c($sp)
/* A1DB30 80242A30 AFB20018 */  sw        $s2, 0x18($sp)
/* A1DB34 80242A34 10A00009 */  beqz      $a1, .L80242A5C
/* A1DB38 80242A38 AFB10014 */   sw       $s1, 0x14($sp)
/* A1DB3C 80242A3C 0000202D */  daddu     $a0, $zero, $zero
/* A1DB40 80242A40 0080282D */  daddu     $a1, $a0, $zero
/* A1DB44 80242A44 0080302D */  daddu     $a2, $a0, $zero
/* A1DB48 80242A48 0C046F97 */  jal       set_background_color_blend
/* A1DB4C 80242A4C 240700FF */   addiu    $a3, $zero, 0xff
/* A1DB50 80242A50 240200FF */  addiu     $v0, $zero, 0xff
/* A1DB54 80242A54 AE020070 */  sw        $v0, 0x70($s0)
/* A1DB58 80242A58 AE000074 */  sw        $zero, 0x74($s0)
.L80242A5C:
/* A1DB5C 80242A5C 8E020070 */  lw        $v0, 0x70($s0)
/* A1DB60 80242A60 2442FFF8 */  addiu     $v0, $v0, -8
/* A1DB64 80242A64 04410002 */  bgez      $v0, .L80242A70
/* A1DB68 80242A68 AE020070 */   sw       $v0, 0x70($s0)
/* A1DB6C 80242A6C AE000070 */  sw        $zero, 0x70($s0)
.L80242A70:
/* A1DB70 80242A70 0000202D */  daddu     $a0, $zero, $zero
/* A1DB74 80242A74 0080282D */  daddu     $a1, $a0, $zero
/* A1DB78 80242A78 92070073 */  lbu       $a3, 0x73($s0)
/* A1DB7C 80242A7C 0C046F97 */  jal       set_background_color_blend
/* A1DB80 80242A80 0080302D */   daddu    $a2, $a0, $zero
/* A1DB84 80242A84 8E020070 */  lw        $v0, 0x70($s0)
/* A1DB88 80242A88 14400006 */  bnez      $v0, .L80242AA4
/* A1DB8C 80242A8C 00000000 */   nop
/* A1DB90 80242A90 8E020074 */  lw        $v0, 0x74($s0)
/* A1DB94 80242A94 14400003 */  bnez      $v0, .L80242AA4
/* A1DB98 80242A98 24020001 */   addiu    $v0, $zero, 1
/* A1DB9C 80242A9C 08090ADC */  j         .L80242B70
/* A1DBA0 80242AA0 AE020074 */   sw       $v0, 0x74($s0)
.L80242AA4:
/* A1DBA4 80242AA4 8E030074 */  lw        $v1, 0x74($s0)
/* A1DBA8 80242AA8 24020001 */  addiu     $v0, $zero, 1
/* A1DBAC 80242AAC 14620031 */  bne       $v1, $v0, .L80242B74
/* A1DBB0 80242AB0 0000102D */   daddu    $v0, $zero, $zero
/* A1DBB4 80242AB4 0C04760B */  jal       func_8011D82C
/* A1DBB8 80242AB8 0000202D */   daddu    $a0, $zero, $zero
/* A1DBBC 80242ABC 0000802D */  daddu     $s0, $zero, $zero
/* A1DBC0 80242AC0 2413FFFC */  addiu     $s3, $zero, -4
/* A1DBC4 80242AC4 24120007 */  addiu     $s2, $zero, 7
/* A1DBC8 80242AC8 3C11FF7F */  lui       $s1, 0xff7f
/* A1DBCC 80242ACC 3C028015 */  lui       $v0, %hi(D_801512F0)
/* A1DBD0 80242AD0 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* A1DBD4 80242AD4 3631FFFF */  ori       $s1, $s1, 0xffff
/* A1DBD8 80242AD8 A0400000 */  sb        $zero, ($v0)
.L80242ADC:
/* A1DBDC 80242ADC 0C00E2B7 */  jal       get_npc_by_index
/* A1DBE0 80242AE0 0200202D */   daddu    $a0, $s0, $zero
/* A1DBE4 80242AE4 0040202D */  daddu     $a0, $v0, $zero
/* A1DBE8 80242AE8 5080000B */  beql      $a0, $zero, .L80242B18
/* A1DBEC 80242AEC 26100001 */   addiu    $s0, $s0, 1
/* A1DBF0 80242AF0 8C820000 */  lw        $v0, ($a0)
/* A1DBF4 80242AF4 50400008 */  beql      $v0, $zero, .L80242B18
/* A1DBF8 80242AF8 26100001 */   addiu    $s0, $s0, 1
/* A1DBFC 80242AFC 808300A4 */  lb        $v1, 0xa4($a0)
/* A1DC00 80242B00 10730005 */  beq       $v1, $s3, .L80242B18
/* A1DC04 80242B04 26100001 */   addiu    $s0, $s0, 1
/* A1DC08 80242B08 10720003 */  beq       $v1, $s2, .L80242B18
/* A1DC0C 80242B0C 00000000 */   nop
/* A1DC10 80242B10 00511024 */  and       $v0, $v0, $s1
/* A1DC14 80242B14 AC820000 */  sw        $v0, ($a0)
.L80242B18:
/* A1DC18 80242B18 2A020040 */  slti      $v0, $s0, 0x40
/* A1DC1C 80242B1C 1440FFEF */  bnez      $v0, .L80242ADC
/* A1DC20 80242B20 00000000 */   nop
/* A1DC24 80242B24 0000802D */  daddu     $s0, $zero, $zero
/* A1DC28 80242B28 3C11F7FF */  lui       $s1, 0xf7ff
/* A1DC2C 80242B2C 3631FFFF */  ori       $s1, $s1, 0xffff
.L80242B30:
/* A1DC30 80242B30 0C04C3D6 */  jal       get_item_entity
/* A1DC34 80242B34 0200202D */   daddu    $a0, $s0, $zero
/* A1DC38 80242B38 0040182D */  daddu     $v1, $v0, $zero
/* A1DC3C 80242B3C 10600007 */  beqz      $v1, .L80242B5C
/* A1DC40 80242B40 26100001 */   addiu    $s0, $s0, 1
/* A1DC44 80242B44 8C640000 */  lw        $a0, ($v1)
/* A1DC48 80242B48 30820010 */  andi      $v0, $a0, 0x10
/* A1DC4C 80242B4C 10400003 */  beqz      $v0, .L80242B5C
/* A1DC50 80242B50 00000000 */   nop
/* A1DC54 80242B54 00911024 */  and       $v0, $a0, $s1
/* A1DC58 80242B58 AC620000 */  sw        $v0, ($v1)
.L80242B5C:
/* A1DC5C 80242B5C 2A020100 */  slti      $v0, $s0, 0x100
/* A1DC60 80242B60 1440FFF3 */  bnez      $v0, .L80242B30
/* A1DC64 80242B64 24020002 */   addiu    $v0, $zero, 2
/* A1DC68 80242B68 08090ADD */  j         .L80242B74
/* A1DC6C 80242B6C 00000000 */   nop
.L80242B70:
/* A1DC70 80242B70 0000102D */  daddu     $v0, $zero, $zero
.L80242B74:
/* A1DC74 80242B74 8FBF0020 */  lw        $ra, 0x20($sp)
/* A1DC78 80242B78 8FB3001C */  lw        $s3, 0x1c($sp)
/* A1DC7C 80242B7C 8FB20018 */  lw        $s2, 0x18($sp)
/* A1DC80 80242B80 8FB10014 */  lw        $s1, 0x14($sp)
/* A1DC84 80242B84 8FB00010 */  lw        $s0, 0x10($sp)
/* A1DC88 80242B88 03E00008 */  jr        $ra
/* A1DC8C 80242B8C 27BD0028 */   addiu    $sp, $sp, 0x28
