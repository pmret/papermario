.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D3C_9D8D5C
/* 9D8D5C 80241D3C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9D8D60 80241D40 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D8D64 80241D44 0080882D */  daddu     $s1, $a0, $zero
/* 9D8D68 80241D48 AFBF0024 */  sw        $ra, 0x24($sp)
/* 9D8D6C 80241D4C AFB40020 */  sw        $s4, 0x20($sp)
/* 9D8D70 80241D50 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9D8D74 80241D54 AFB20018 */  sw        $s2, 0x18($sp)
/* 9D8D78 80241D58 10A00033 */  beqz      $a1, .L80241E28
/* 9D8D7C 80241D5C AFB00010 */   sw       $s0, 0x10($sp)
/* 9D8D80 80241D60 0C04760B */  jal       func_8011D82C
/* 9D8D84 80241D64 24040001 */   addiu    $a0, $zero, 1
/* 9D8D88 80241D68 0000202D */  daddu     $a0, $zero, $zero
/* 9D8D8C 80241D6C 0080282D */  daddu     $a1, $a0, $zero
/* 9D8D90 80241D70 0080302D */  daddu     $a2, $a0, $zero
/* 9D8D94 80241D74 0080382D */  daddu     $a3, $a0, $zero
/* 9D8D98 80241D78 0080802D */  daddu     $s0, $a0, $zero
/* 9D8D9C 80241D7C 2414FFFC */  addiu     $s4, $zero, -4
/* 9D8DA0 80241D80 24130013 */  addiu     $s3, $zero, 0x13
/* 9D8DA4 80241D84 3C120080 */  lui       $s2, 0x80
/* 9D8DA8 80241D88 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 9D8DAC 80241D8C 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 9D8DB0 80241D90 24020001 */  addiu     $v0, $zero, 1
/* 9D8DB4 80241D94 0C046F97 */  jal       set_background_color_blend
/* 9D8DB8 80241D98 A0620000 */   sb       $v0, ($v1)
.L80241D9C:
/* 9D8DBC 80241D9C 0C00E2B7 */  jal       get_npc_by_index
/* 9D8DC0 80241DA0 0200202D */   daddu    $a0, $s0, $zero
/* 9D8DC4 80241DA4 0040202D */  daddu     $a0, $v0, $zero
/* 9D8DC8 80241DA8 5080000B */  beql      $a0, $zero, .L80241DD8
/* 9D8DCC 80241DAC 26100001 */   addiu    $s0, $s0, 1
/* 9D8DD0 80241DB0 8C820000 */  lw        $v0, ($a0)
/* 9D8DD4 80241DB4 50400008 */  beql      $v0, $zero, .L80241DD8
/* 9D8DD8 80241DB8 26100001 */   addiu    $s0, $s0, 1
/* 9D8DDC 80241DBC 808300A4 */  lb        $v1, 0xa4($a0)
/* 9D8DE0 80241DC0 10740005 */  beq       $v1, $s4, .L80241DD8
/* 9D8DE4 80241DC4 26100001 */   addiu    $s0, $s0, 1
/* 9D8DE8 80241DC8 10730003 */  beq       $v1, $s3, .L80241DD8
/* 9D8DEC 80241DCC 00000000 */   nop      
/* 9D8DF0 80241DD0 00521025 */  or        $v0, $v0, $s2
/* 9D8DF4 80241DD4 AC820000 */  sw        $v0, ($a0)
.L80241DD8:
/* 9D8DF8 80241DD8 2A020040 */  slti      $v0, $s0, 0x40
/* 9D8DFC 80241DDC 1440FFEF */  bnez      $v0, .L80241D9C
/* 9D8E00 80241DE0 00000000 */   nop      
/* 9D8E04 80241DE4 0000802D */  daddu     $s0, $zero, $zero
/* 9D8E08 80241DE8 3C120800 */  lui       $s2, 0x800
.L80241DEC:
/* 9D8E0C 80241DEC 0C04C3D6 */  jal       get_item_entity
/* 9D8E10 80241DF0 0200202D */   daddu    $a0, $s0, $zero
/* 9D8E14 80241DF4 0040182D */  daddu     $v1, $v0, $zero
/* 9D8E18 80241DF8 10600007 */  beqz      $v1, .L80241E18
/* 9D8E1C 80241DFC 26100001 */   addiu    $s0, $s0, 1
/* 9D8E20 80241E00 8C640000 */  lw        $a0, ($v1)
/* 9D8E24 80241E04 30820010 */  andi      $v0, $a0, 0x10
/* 9D8E28 80241E08 10400003 */  beqz      $v0, .L80241E18
/* 9D8E2C 80241E0C 00000000 */   nop      
/* 9D8E30 80241E10 00921025 */  or        $v0, $a0, $s2
/* 9D8E34 80241E14 AC620000 */  sw        $v0, ($v1)
.L80241E18:
/* 9D8E38 80241E18 2A020100 */  slti      $v0, $s0, 0x100
/* 9D8E3C 80241E1C 1440FFF3 */  bnez      $v0, .L80241DEC
/* 9D8E40 80241E20 00000000 */   nop      
/* 9D8E44 80241E24 AE200070 */  sw        $zero, 0x70($s1)
.L80241E28:
/* 9D8E48 80241E28 8E220070 */  lw        $v0, 0x70($s1)
/* 9D8E4C 80241E2C 24420008 */  addiu     $v0, $v0, 8
/* 9D8E50 80241E30 AE220070 */  sw        $v0, 0x70($s1)
/* 9D8E54 80241E34 28420100 */  slti      $v0, $v0, 0x100
/* 9D8E58 80241E38 14400003 */  bnez      $v0, .L80241E48
/* 9D8E5C 80241E3C 0000202D */   daddu    $a0, $zero, $zero
/* 9D8E60 80241E40 240200FF */  addiu     $v0, $zero, 0xff
/* 9D8E64 80241E44 AE220070 */  sw        $v0, 0x70($s1)
.L80241E48:
/* 9D8E68 80241E48 0080282D */  daddu     $a1, $a0, $zero
/* 9D8E6C 80241E4C 92270073 */  lbu       $a3, 0x73($s1)
/* 9D8E70 80241E50 0C046F97 */  jal       set_background_color_blend
/* 9D8E74 80241E54 0080302D */   daddu    $a2, $a0, $zero
/* 9D8E78 80241E58 8E220070 */  lw        $v0, 0x70($s1)
/* 9D8E7C 80241E5C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 9D8E80 80241E60 8FB40020 */  lw        $s4, 0x20($sp)
/* 9D8E84 80241E64 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9D8E88 80241E68 8FB20018 */  lw        $s2, 0x18($sp)
/* 9D8E8C 80241E6C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D8E90 80241E70 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D8E94 80241E74 384200FF */  xori      $v0, $v0, 0xff
/* 9D8E98 80241E78 2C420001 */  sltiu     $v0, $v0, 1
/* 9D8E9C 80241E7C 00021040 */  sll       $v0, $v0, 1
/* 9D8EA0 80241E80 03E00008 */  jr        $ra
/* 9D8EA4 80241E84 27BD0028 */   addiu    $sp, $sp, 0x28
