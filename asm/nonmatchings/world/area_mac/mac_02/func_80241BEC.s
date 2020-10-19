.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BEC
/* 824EAC 80241BEC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 824EB0 80241BF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 824EB4 80241BF4 0080882D */  daddu     $s1, $a0, $zero
/* 824EB8 80241BF8 AFBF0024 */  sw        $ra, 0x24($sp)
/* 824EBC 80241BFC AFB40020 */  sw        $s4, 0x20($sp)
/* 824EC0 80241C00 AFB3001C */  sw        $s3, 0x1c($sp)
/* 824EC4 80241C04 AFB20018 */  sw        $s2, 0x18($sp)
/* 824EC8 80241C08 10A00033 */  beqz      $a1, .L80241CD8
/* 824ECC 80241C0C AFB00010 */   sw       $s0, 0x10($sp)
/* 824ED0 80241C10 0C04760B */  jal       func_8011D82C
/* 824ED4 80241C14 24040001 */   addiu    $a0, $zero, 1
/* 824ED8 80241C18 0000202D */  daddu     $a0, $zero, $zero
/* 824EDC 80241C1C 0080282D */  daddu     $a1, $a0, $zero
/* 824EE0 80241C20 0080302D */  daddu     $a2, $a0, $zero
/* 824EE4 80241C24 0080382D */  daddu     $a3, $a0, $zero
/* 824EE8 80241C28 0080802D */  daddu     $s0, $a0, $zero
/* 824EEC 80241C2C 2414FFFC */  addiu     $s4, $zero, -4
/* 824EF0 80241C30 2413000C */  addiu     $s3, $zero, 0xc
/* 824EF4 80241C34 3C120080 */  lui       $s2, 0x80
/* 824EF8 80241C38 3C038015 */  lui       $v1, 0x8015
/* 824EFC 80241C3C 8C6312F0 */  lw        $v1, 0x12f0($v1)
/* 824F00 80241C40 24020001 */  addiu     $v0, $zero, 1
/* 824F04 80241C44 0C046F97 */  jal       set_background_color_blend
/* 824F08 80241C48 A0620000 */   sb       $v0, ($v1)
.L80241C4C:
/* 824F0C 80241C4C 0C00E2B7 */  jal       get_npc_by_index
/* 824F10 80241C50 0200202D */   daddu    $a0, $s0, $zero
/* 824F14 80241C54 0040202D */  daddu     $a0, $v0, $zero
/* 824F18 80241C58 5080000B */  beql      $a0, $zero, .L80241C88
/* 824F1C 80241C5C 26100001 */   addiu    $s0, $s0, 1
/* 824F20 80241C60 8C820000 */  lw        $v0, ($a0)
/* 824F24 80241C64 50400008 */  beql      $v0, $zero, .L80241C88
/* 824F28 80241C68 26100001 */   addiu    $s0, $s0, 1
/* 824F2C 80241C6C 808300A4 */  lb        $v1, 0xa4($a0)
/* 824F30 80241C70 10740005 */  beq       $v1, $s4, .L80241C88
/* 824F34 80241C74 26100001 */   addiu    $s0, $s0, 1
/* 824F38 80241C78 10730003 */  beq       $v1, $s3, .L80241C88
/* 824F3C 80241C7C 00000000 */   nop      
/* 824F40 80241C80 00521025 */  or        $v0, $v0, $s2
/* 824F44 80241C84 AC820000 */  sw        $v0, ($a0)
.L80241C88:
/* 824F48 80241C88 2A020040 */  slti      $v0, $s0, 0x40
/* 824F4C 80241C8C 1440FFEF */  bnez      $v0, .L80241C4C
/* 824F50 80241C90 00000000 */   nop      
/* 824F54 80241C94 0000802D */  daddu     $s0, $zero, $zero
/* 824F58 80241C98 3C120800 */  lui       $s2, 0x800
.L80241C9C:
/* 824F5C 80241C9C 0C04C3D6 */  jal       get_item_entity
/* 824F60 80241CA0 0200202D */   daddu    $a0, $s0, $zero
/* 824F64 80241CA4 0040182D */  daddu     $v1, $v0, $zero
/* 824F68 80241CA8 10600007 */  beqz      $v1, .L80241CC8
/* 824F6C 80241CAC 26100001 */   addiu    $s0, $s0, 1
/* 824F70 80241CB0 8C640000 */  lw        $a0, ($v1)
/* 824F74 80241CB4 30820010 */  andi      $v0, $a0, 0x10
/* 824F78 80241CB8 10400003 */  beqz      $v0, .L80241CC8
/* 824F7C 80241CBC 00000000 */   nop      
/* 824F80 80241CC0 00921025 */  or        $v0, $a0, $s2
/* 824F84 80241CC4 AC620000 */  sw        $v0, ($v1)
.L80241CC8:
/* 824F88 80241CC8 2A020100 */  slti      $v0, $s0, 0x100
/* 824F8C 80241CCC 1440FFF3 */  bnez      $v0, .L80241C9C
/* 824F90 80241CD0 00000000 */   nop      
/* 824F94 80241CD4 AE200070 */  sw        $zero, 0x70($s1)
.L80241CD8:
/* 824F98 80241CD8 8E220070 */  lw        $v0, 0x70($s1)
/* 824F9C 80241CDC 24420008 */  addiu     $v0, $v0, 8
/* 824FA0 80241CE0 AE220070 */  sw        $v0, 0x70($s1)
/* 824FA4 80241CE4 28420100 */  slti      $v0, $v0, 0x100
/* 824FA8 80241CE8 14400003 */  bnez      $v0, .L80241CF8
/* 824FAC 80241CEC 0000202D */   daddu    $a0, $zero, $zero
/* 824FB0 80241CF0 240200FF */  addiu     $v0, $zero, 0xff
/* 824FB4 80241CF4 AE220070 */  sw        $v0, 0x70($s1)
.L80241CF8:
/* 824FB8 80241CF8 0080282D */  daddu     $a1, $a0, $zero
/* 824FBC 80241CFC 92270073 */  lbu       $a3, 0x73($s1)
/* 824FC0 80241D00 0C046F97 */  jal       set_background_color_blend
/* 824FC4 80241D04 0080302D */   daddu    $a2, $a0, $zero
/* 824FC8 80241D08 8E220070 */  lw        $v0, 0x70($s1)
/* 824FCC 80241D0C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 824FD0 80241D10 8FB40020 */  lw        $s4, 0x20($sp)
/* 824FD4 80241D14 8FB3001C */  lw        $s3, 0x1c($sp)
/* 824FD8 80241D18 8FB20018 */  lw        $s2, 0x18($sp)
/* 824FDC 80241D1C 8FB10014 */  lw        $s1, 0x14($sp)
/* 824FE0 80241D20 8FB00010 */  lw        $s0, 0x10($sp)
/* 824FE4 80241D24 384200FF */  xori      $v0, $v0, 0xff
/* 824FE8 80241D28 2C420001 */  sltiu     $v0, $v0, 1
/* 824FEC 80241D2C 00021040 */  sll       $v0, $v0, 1
/* 824FF0 80241D30 03E00008 */  jr        $ra
/* 824FF4 80241D34 27BD0028 */   addiu    $sp, $sp, 0x28
