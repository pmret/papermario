.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A40_B2DEB0
/* B2DEB0 80241A40 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B2DEB4 80241A44 AFB10014 */  sw        $s1, 0x14($sp)
/* B2DEB8 80241A48 0080882D */  daddu     $s1, $a0, $zero
/* B2DEBC 80241A4C AFBF0024 */  sw        $ra, 0x24($sp)
/* B2DEC0 80241A50 AFB40020 */  sw        $s4, 0x20($sp)
/* B2DEC4 80241A54 AFB3001C */  sw        $s3, 0x1c($sp)
/* B2DEC8 80241A58 AFB20018 */  sw        $s2, 0x18($sp)
/* B2DECC 80241A5C 10A00033 */  beqz      $a1, .L80241B2C
/* B2DED0 80241A60 AFB00010 */   sw       $s0, 0x10($sp)
/* B2DED4 80241A64 0C04760B */  jal       func_8011D82C
/* B2DED8 80241A68 24040001 */   addiu    $a0, $zero, 1
/* B2DEDC 80241A6C 0000202D */  daddu     $a0, $zero, $zero
/* B2DEE0 80241A70 0080282D */  daddu     $a1, $a0, $zero
/* B2DEE4 80241A74 0080302D */  daddu     $a2, $a0, $zero
/* B2DEE8 80241A78 0080382D */  daddu     $a3, $a0, $zero
/* B2DEEC 80241A7C 0080802D */  daddu     $s0, $a0, $zero
/* B2DEF0 80241A80 2414FFFC */  addiu     $s4, $zero, -4
/* B2DEF4 80241A84 24130005 */  addiu     $s3, $zero, 5
/* B2DEF8 80241A88 3C120080 */  lui       $s2, 0x80
/* B2DEFC 80241A8C 3C038015 */  lui       $v1, %hi(D_801512F0)
/* B2DF00 80241A90 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* B2DF04 80241A94 24020001 */  addiu     $v0, $zero, 1
/* B2DF08 80241A98 0C046F97 */  jal       set_background_color_blend
/* B2DF0C 80241A9C A0620000 */   sb       $v0, ($v1)
.L80241AA0:
/* B2DF10 80241AA0 0C00E2B7 */  jal       get_npc_by_index
/* B2DF14 80241AA4 0200202D */   daddu    $a0, $s0, $zero
/* B2DF18 80241AA8 0040202D */  daddu     $a0, $v0, $zero
/* B2DF1C 80241AAC 5080000B */  beql      $a0, $zero, .L80241ADC
/* B2DF20 80241AB0 26100001 */   addiu    $s0, $s0, 1
/* B2DF24 80241AB4 8C820000 */  lw        $v0, ($a0)
/* B2DF28 80241AB8 50400008 */  beql      $v0, $zero, .L80241ADC
/* B2DF2C 80241ABC 26100001 */   addiu    $s0, $s0, 1
/* B2DF30 80241AC0 808300A4 */  lb        $v1, 0xa4($a0)
/* B2DF34 80241AC4 10740005 */  beq       $v1, $s4, .L80241ADC
/* B2DF38 80241AC8 26100001 */   addiu    $s0, $s0, 1
/* B2DF3C 80241ACC 10730003 */  beq       $v1, $s3, .L80241ADC
/* B2DF40 80241AD0 00000000 */   nop      
/* B2DF44 80241AD4 00521025 */  or        $v0, $v0, $s2
/* B2DF48 80241AD8 AC820000 */  sw        $v0, ($a0)
.L80241ADC:
/* B2DF4C 80241ADC 2A020040 */  slti      $v0, $s0, 0x40
/* B2DF50 80241AE0 1440FFEF */  bnez      $v0, .L80241AA0
/* B2DF54 80241AE4 00000000 */   nop      
/* B2DF58 80241AE8 0000802D */  daddu     $s0, $zero, $zero
/* B2DF5C 80241AEC 3C120800 */  lui       $s2, 0x800
.L80241AF0:
/* B2DF60 80241AF0 0C04C3D6 */  jal       get_item_entity
/* B2DF64 80241AF4 0200202D */   daddu    $a0, $s0, $zero
/* B2DF68 80241AF8 0040182D */  daddu     $v1, $v0, $zero
/* B2DF6C 80241AFC 10600007 */  beqz      $v1, .L80241B1C
/* B2DF70 80241B00 26100001 */   addiu    $s0, $s0, 1
/* B2DF74 80241B04 8C640000 */  lw        $a0, ($v1)
/* B2DF78 80241B08 30820010 */  andi      $v0, $a0, 0x10
/* B2DF7C 80241B0C 10400003 */  beqz      $v0, .L80241B1C
/* B2DF80 80241B10 00000000 */   nop      
/* B2DF84 80241B14 00921025 */  or        $v0, $a0, $s2
/* B2DF88 80241B18 AC620000 */  sw        $v0, ($v1)
.L80241B1C:
/* B2DF8C 80241B1C 2A020100 */  slti      $v0, $s0, 0x100
/* B2DF90 80241B20 1440FFF3 */  bnez      $v0, .L80241AF0
/* B2DF94 80241B24 00000000 */   nop      
/* B2DF98 80241B28 AE200070 */  sw        $zero, 0x70($s1)
.L80241B2C:
/* B2DF9C 80241B2C 8E220070 */  lw        $v0, 0x70($s1)
/* B2DFA0 80241B30 24420008 */  addiu     $v0, $v0, 8
/* B2DFA4 80241B34 AE220070 */  sw        $v0, 0x70($s1)
/* B2DFA8 80241B38 28420100 */  slti      $v0, $v0, 0x100
/* B2DFAC 80241B3C 14400003 */  bnez      $v0, .L80241B4C
/* B2DFB0 80241B40 0000202D */   daddu    $a0, $zero, $zero
/* B2DFB4 80241B44 240200FF */  addiu     $v0, $zero, 0xff
/* B2DFB8 80241B48 AE220070 */  sw        $v0, 0x70($s1)
.L80241B4C:
/* B2DFBC 80241B4C 0080282D */  daddu     $a1, $a0, $zero
/* B2DFC0 80241B50 92270073 */  lbu       $a3, 0x73($s1)
/* B2DFC4 80241B54 0C046F97 */  jal       set_background_color_blend
/* B2DFC8 80241B58 0080302D */   daddu    $a2, $a0, $zero
/* B2DFCC 80241B5C 8E220070 */  lw        $v0, 0x70($s1)
/* B2DFD0 80241B60 8FBF0024 */  lw        $ra, 0x24($sp)
/* B2DFD4 80241B64 8FB40020 */  lw        $s4, 0x20($sp)
/* B2DFD8 80241B68 8FB3001C */  lw        $s3, 0x1c($sp)
/* B2DFDC 80241B6C 8FB20018 */  lw        $s2, 0x18($sp)
/* B2DFE0 80241B70 8FB10014 */  lw        $s1, 0x14($sp)
/* B2DFE4 80241B74 8FB00010 */  lw        $s0, 0x10($sp)
/* B2DFE8 80241B78 384200FF */  xori      $v0, $v0, 0xff
/* B2DFEC 80241B7C 2C420001 */  sltiu     $v0, $v0, 1
/* B2DFF0 80241B80 00021040 */  sll       $v0, $v0, 1
/* B2DFF4 80241B84 03E00008 */  jr        $ra
/* B2DFF8 80241B88 27BD0028 */   addiu    $sp, $sp, 0x28
